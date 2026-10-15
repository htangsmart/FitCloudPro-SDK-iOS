//
//  ScheduleV2DemoViewController.swift
//  FitCloudSwiftDemo
//
//  V2 schedule demo built with SwiftUI and hosted by the existing UIKit demo.
//

import SwiftUI
import UIKit

@objc(ScheduleV2DemoViewController)
final class ScheduleV2DemoViewController: UIViewController {
    private let store = ScheduleV2Store()

    override func viewDidLoad() {
        super.viewDidLoad()

        let rootView = ScheduleV2ListView(store: store) { [weak self] in
            self?.navigationController?.popViewController(animated: true)
        }
        let hostingController = UIHostingController(rootView: rootView)
        addChild(hostingController)
        hostingController.view.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(hostingController.view)
        NSLayoutConstraint.activate([
            hostingController.view.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            hostingController.view.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            hostingController.view.topAnchor.constraint(equalTo: view.topAnchor),
            hostingController.view.bottomAnchor.constraint(equalTo: view.bottomAnchor)
        ])
        hostingController.didMove(toParent: self)
    }
}

private struct ScheduleV2Item: Identifiable, Equatable {
    let id: UInt8
    var isOn: Bool
    var fireDate: Date
    var repeatDays: UInt8
    var aheadMinutes: UInt8
    var title: String
    var content: String

    var isExpired: Bool {
        repeatDays == 0 && fireDate < Date()
    }

    init(object: FitCloudScheduleV2Object) {
        id = object.scheduleId
        isOn = object.isOn
        repeatDays = object.cycle.rawValue
        aheadMinutes = object.aheadRemindInMinute
        title = object.title
        content = object.content
        fireDate = Calendar.current.date(from: object.fire) ?? Date()
    }

    init(id: UInt8, date: Date) {
        self.id = id
        isOn = true
        fireDate = date
        repeatDays = 0
        aheadMinutes = 0
        title = ""
        content = ""
    }

    func sdkObject() -> FitCloudScheduleV2Object {
        let object = FitCloudScheduleV2Object()
        object.scheduleId = id
        object.isOn = isOn
        var components = Calendar.current.dateComponents(
            [.year, .month, .day, .hour, .minute, .second],
            from: fireDate
        )
        components.second = 0
        object.fire = components
        object.cycle = FITCLOUDSCHEDULECYCLE(rawValue: repeatDays)
        object.aheadRemindInMinute = aheadMinutes
        object.title = title
        object.content = content
        return object
    }
}

private struct ScheduleEditorRoute: Identifiable {
    let id = UUID()
    let item: ScheduleV2Item
    let isNew: Bool
}

@MainActor
private final class ScheduleV2Store: ObservableObject {
    @Published private(set) var items: [ScheduleV2Item] = []
    @Published private(set) var isLoading = false
    @Published private(set) var isSaving = false
    @Published var isManaging = false
    @Published var selectedIDs: Set<UInt8> = []
    @Published var editorRoute: ScheduleEditorRoute?
    @Published var alertMessage: String?

    private var observer: NSObjectProtocol?

    init() {
        apply(FitCloudKit.scheduleV2List() ?? [])
        observer = NotificationCenter.default.addObserver(
            forName: Notification.Name(FITCLOUDEVENT_SCHEDULEV2LIST_CHANGED_NOTIFY),
            object: nil,
            queue: .main
        ) { [weak self] notification in
            guard let schedules = notification.object as? [FitCloudScheduleV2Object] else { return }
            Task { @MainActor in self?.apply(schedules) }
        }
    }

    deinit {
        if let observer { NotificationCenter.default.removeObserver(observer) }
    }

    var maximumCount: Int {
        let capacity = FitCloudKit.allConfig()?.deviceCapacities?.first {
            $0.capacity.rawValue == 0x31
        }?.value ?? 0
        return capacity > 0 ? capacity : 20
    }

    var activeItems: [ScheduleV2Item] {
        items.filter { !$0.isExpired }.sorted { $0.fireDate < $1.fireDate }
    }

    var expiredItems: [ScheduleV2Item] {
        items.filter(\.isExpired).sorted { $0.fireDate > $1.fireDate }
    }

    func load() {
        guard !isLoading else { return }
        isLoading = true
        FitCloudKit.getSchedulesV2 { [weak self] succeed, list, error in
            DispatchQueue.main.async {
                guard let self else { return }
                self.isLoading = false
                if succeed {
                    self.apply(list ?? [])
                } else {
                    self.alertMessage = error?.localizedDescription
                        ?? NSLocalizedString("Unable to read schedules from the watch.", comment: "")
                }
            }
        }
    }

    func beginAdding() {
        guard items.count < maximumCount else {
            alertMessage = String(
                format: NSLocalizedString("The watch supports up to %d schedules.", comment: ""),
                maximumCount
            )
            return
        }
        let used = Set(items.map(\.id))
        guard let scheduleID = (0...127).compactMap({ UInt8($0) }).first(where: { !used.contains($0) }) else {
            alertMessage = NSLocalizedString("No schedule identifier is available.", comment: "")
            return
        }
        let date = Calendar.current.date(byAdding: .hour, value: 1, to: Date()) ?? Date()
        editorRoute = ScheduleEditorRoute(item: ScheduleV2Item(id: scheduleID, date: date), isNew: true)
    }

    func beginEditing(_ item: ScheduleV2Item) {
        guard !isManaging else {
            toggleSelection(item.id)
            return
        }
        editorRoute = ScheduleEditorRoute(item: item, isNew: false)
    }

    func toggleSelection(_ id: UInt8) {
        if selectedIDs.contains(id) {
            selectedIDs.remove(id)
        } else {
            selectedIDs.insert(id)
        }
    }

    func setManaging(_ managing: Bool) {
        withAnimation(.easeInOut(duration: 0.2)) {
            isManaging = managing
            if !managing { selectedIDs.removeAll() }
        }
    }

    func selectAll() {
        selectedIDs = selectedIDs.count == items.count ? [] : Set(items.map(\.id))
    }

    func save(_ item: ScheduleV2Item) {
        var updated = items
        if let index = updated.firstIndex(where: { $0.id == item.id }) {
            updated[index] = item
        } else {
            updated.append(item)
        }
        editorRoute = nil
        sync(updated)
    }

    func deleteSelected() {
        let remaining = items.filter { !selectedIDs.contains($0.id) }
        sync(remaining) { [weak self] in self?.setManaging(false) }
    }

    private func sync(_ newItems: [ScheduleV2Item], completion: (() -> Void)? = nil) {
        guard !isSaving else { return }
        isSaving = true
        let objects = newItems.map { $0.sdkObject() }
        FitCloudKit.setSchedulesV2(objects) { [weak self] succeed, error in
            DispatchQueue.main.async {
                guard let self else { return }
                self.isSaving = false
                if succeed {
                    self.items = newItems
                    completion?()
                } else {
                    self.alertMessage = error?.localizedDescription
                        ?? NSLocalizedString("Unable to sync schedules to the watch.", comment: "")
                }
            }
        }
    }

    private func apply(_ schedules: [FitCloudScheduleV2Object]) {
        items = schedules.map(ScheduleV2Item.init)
    }
}

private struct ScheduleV2ListView: View {
    @ObservedObject var store: ScheduleV2Store
    let onBack: () -> Void

    var body: some View {
        ZStack(alignment: .bottom) {
            Color(.systemGroupedBackground).ignoresSafeArea()

            VStack(spacing: 0) {
                header
                content
            }

            if store.isManaging {
                deleteBar
                    .transition(.move(edge: .bottom).combined(with: .opacity))
            }

            if store.isSaving {
                savingOverlay
            }
        }
        .ignoresSafeArea(edges: .top)
        .sheet(item: $store.editorRoute) { route in
            ScheduleV2EditorView(item: route.item, isNew: route.isNew) { item in
                store.save(item)
            }
        }
        .alert(
            NSLocalizedString("Schedule Reminder", comment: ""),
            isPresented: Binding(
                get: { store.alertMessage != nil },
                set: { if !$0 { store.alertMessage = nil } }
            )
        ) {
            Button(NSLocalizedString("OK", comment: ""), role: .cancel) {}
        } message: {
            Text(store.alertMessage ?? "")
        }
        .onAppear { store.load() }
    }

    private var header: some View {
        VStack(spacing: 0) {
            Color.clear.frame(height: topInset)
            ZStack {
                Text(store.isManaging
                     ? String(format: NSLocalizedString("Selected %d", comment: ""), store.selectedIDs.count)
                     : NSLocalizedString("Schedule Reminder", comment: ""))
                    .font(.system(size: 18, weight: .bold))

                HStack {
                    Button(action: store.isManaging ? { store.setManaging(false) } : onBack) {
                        Image(systemName: store.isManaging ? "xmark" : "chevron.left")
                            .font(.system(size: 18, weight: .semibold))
                            .frame(width: 44, height: 44)
                    }
                    Spacer()
                    if store.isManaging {
                        Button(action: store.selectAll) {
                            Image(systemName: store.selectedIDs.count == store.items.count && !store.items.isEmpty
                                  ? "checklist.checked" : "checklist")
                                .font(.system(size: 20, weight: .semibold))
                                .frame(width: 44, height: 44)
                        }
                    } else {
                        HStack(spacing: 0) {
                            Button { store.setManaging(true) } label: {
                                Image(systemName: "checklist")
                                    .font(.system(size: 18, weight: .semibold))
                                    .frame(width: 40, height: 44)
                            }
                            .accessibilityLabel(NSLocalizedString("Manage", comment: ""))
                            Button(action: store.beginAdding) {
                                Image(systemName: "plus")
                                    .font(.system(size: 22, weight: .semibold))
                                    .frame(width: 40, height: 44)
                            }
                            .accessibilityLabel(NSLocalizedString("New Schedule", comment: ""))
                        }
                    }
                }
                .foregroundColor(.accentColor)
                .padding(.horizontal, 6)
            }
            .frame(height: 54)
            .background(.regularMaterial)
            Divider()
        }
    }

    @ViewBuilder
    private var content: some View {
        if store.isLoading && store.items.isEmpty {
            VStack(spacing: 14) {
                ProgressView()
                Text(NSLocalizedString("Reading schedules…", comment: ""))
                    .foregroundColor(.secondary)
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
        } else if store.items.isEmpty {
            emptyState
        } else {
            ScrollView {
                LazyVStack(spacing: 14, pinnedViews: .sectionHeaders) {
                    scheduleSection(
                        title: NSLocalizedString("Upcoming", comment: ""),
                        items: store.activeItems,
                        dimmed: false
                    )
                    if !store.expiredItems.isEmpty {
                        scheduleSection(
                            title: NSLocalizedString("Expired", comment: ""),
                            items: store.expiredItems,
                            dimmed: true
                        )
                    }
                }
                .padding(.horizontal, 16)
                .padding(.top, 16)
                .padding(.bottom, store.isManaging ? 94 : 30)
            }
            .refreshable { store.load() }
        }
    }

    private var emptyState: some View {
        VStack(spacing: 18) {
            ZStack {
                Circle().fill(Color.accentColor.opacity(0.1)).frame(width: 92, height: 92)
                Image(systemName: "calendar.badge.clock")
                    .font(.system(size: 40, weight: .light))
                    .foregroundColor(.accentColor)
            }
            Text(NSLocalizedString("No schedules", comment: ""))
                .font(.title3.bold())
            Text(NSLocalizedString("Add a reminder and sync it to the connected watch.", comment: ""))
                .font(.subheadline)
                .foregroundColor(.secondary)
                .multilineTextAlignment(.center)
            Button(action: store.beginAdding) {
                Label(NSLocalizedString("New Schedule", comment: ""), systemImage: "plus")
                    .font(.headline)
                    .foregroundColor(.white)
                    .padding(.horizontal, 22)
                    .frame(height: 46)
                    .background(Color.accentColor, in: Capsule())
            }
        }
        .padding(32)
        .frame(maxWidth: .infinity, maxHeight: .infinity)
    }

    @ViewBuilder
    private func scheduleSection(title: String, items: [ScheduleV2Item], dimmed: Bool) -> some View {
        if !items.isEmpty {
            Section {
                ForEach(items) { item in
                    ScheduleV2Row(
                        item: item,
                        isManaging: store.isManaging,
                        isSelected: store.selectedIDs.contains(item.id),
                        dimmed: dimmed
                    ) {
                        store.beginEditing(item)
                    }
                    .contextMenu {
                        Button {
                            store.setManaging(true)
                            store.toggleSelection(item.id)
                        } label: {
                            Label(NSLocalizedString("Select", comment: ""), systemImage: "checkmark.circle")
                        }
                    }
                }
            } header: {
                HStack {
                    Text(title).font(.subheadline.weight(.semibold)).foregroundColor(.secondary)
                    Spacer()
                    Text("\(items.count)").font(.caption.weight(.bold)).foregroundColor(.secondary)
                }
                .padding(.horizontal, 4)
                .padding(.vertical, 4)
                .background(Color(.systemGroupedBackground))
            }
        }
    }

    private var deleteBar: some View {
        VStack(spacing: 0) {
            Divider()
            Button(action: store.deleteSelected) {
                Label(
                    store.selectedIDs.isEmpty
                        ? NSLocalizedString("Delete", comment: "")
                        : String(format: NSLocalizedString("Delete %d schedules", comment: ""), store.selectedIDs.count),
                    systemImage: "trash"
                )
                .font(.headline)
                .foregroundColor(store.selectedIDs.isEmpty ? .secondary : .red)
                .frame(maxWidth: .infinity, minHeight: 58)
            }
            .disabled(store.selectedIDs.isEmpty)
        }
        .padding(.bottom, bottomInset)
        .background(.regularMaterial)
    }

    private var savingOverlay: some View {
        ZStack {
            Color.black.opacity(0.18).ignoresSafeArea()
            HStack(spacing: 12) {
                ProgressView().tint(.white)
                Text(NSLocalizedString("Syncing to watch…", comment: ""))
                    .font(.subheadline.weight(.semibold))
            }
            .foregroundColor(.white)
            .padding(.horizontal, 20)
            .padding(.vertical, 14)
            .background(Color.black.opacity(0.78), in: Capsule())
        }
    }

    private var topInset: CGFloat {
        getMainWindow().safeAreaInsets.top
    }

    private var bottomInset: CGFloat {
        getMainWindow().safeAreaInsets.bottom
    }
}

private struct ScheduleV2Row: View {
    let item: ScheduleV2Item
    let isManaging: Bool
    let isSelected: Bool
    let dimmed: Bool
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            HStack(spacing: 13) {
                if isManaging {
                    Image(systemName: isSelected ? "checkmark.circle.fill" : "circle")
                        .font(.system(size: 24))
                        .foregroundColor(isSelected ? .accentColor : Color(.tertiaryLabel))
                } else {
                    RoundedRectangle(cornerRadius: 12, style: .continuous)
                        .fill(iconColor.opacity(0.12))
                        .frame(width: 46, height: 46)
                        .overlay {
                            Image(systemName: "calendar.badge.clock")
                                .font(.system(size: 20, weight: .medium))
                                .foregroundColor(iconColor)
                        }
                }

                VStack(alignment: .leading, spacing: 7) {
                    HStack(spacing: 7) {
                        Text(item.title)
                            .font(.system(size: 17, weight: .semibold))
                            .foregroundColor(.primary)
                            .lineLimit(1)
                        if !item.isOn {
                            Text(NSLocalizedString("Off", comment: ""))
                                .font(.caption2.weight(.bold))
                                .foregroundColor(.secondary)
                                .padding(.horizontal, 6)
                                .padding(.vertical, 3)
                                .background(Color(.tertiarySystemFill), in: Capsule())
                        }
                    }

                    HStack(spacing: 8) {
                        Text(ScheduleV2Formatting.dateTime(item.fireDate))
                            .foregroundColor(.secondary)
                        if item.repeatDays != 0 {
                            Text(ScheduleV2Formatting.repeatText(item.repeatDays))
                                .foregroundColor(.accentColor)
                                .lineLimit(1)
                                .padding(.horizontal, 8)
                                .padding(.vertical, 4)
                                .background(Color.accentColor.opacity(0.1), in: Capsule())
                        }
                    }
                    .font(.subheadline)

                    if !item.content.isEmpty {
                        Text(item.content)
                            .font(.caption)
                            .foregroundColor(.secondary)
                            .lineLimit(1)
                    }
                }
                Spacer(minLength: 4)
                if !isManaging {
                    Image(systemName: "chevron.right")
                        .font(.caption.bold())
                        .foregroundColor(Color(.tertiaryLabel))
                }
            }
            .padding(14)
            .frame(maxWidth: .infinity, alignment: .leading)
            .background(Color(.secondarySystemGroupedBackground), in: RoundedRectangle(cornerRadius: 18, style: .continuous))
            .overlay {
                RoundedRectangle(cornerRadius: 18, style: .continuous)
                    .stroke(Color(.separator).opacity(0.18), lineWidth: 0.5)
            }
            .opacity(dimmed ? 0.5 : 1)
        }
        .buttonStyle(.plain)
        .accessibilityElement(children: .combine)
        .accessibilityHint(isManaging
                           ? NSLocalizedString("Double tap to select this schedule.", comment: "")
                           : NSLocalizedString("Double tap to edit this schedule.", comment: ""))
    }

    private var iconColor: Color {
        dimmed || !item.isOn ? .secondary : .accentColor
    }
}

private struct ScheduleV2EditorView: View {
    @Environment(\.dismiss) private var dismiss
    @State private var item: ScheduleV2Item
    @State private var showRepeatPicker = false
    @FocusState private var focusedField: Field?

    let isNew: Bool
    let onSave: (ScheduleV2Item) -> Void

    private enum Field { case title, content }

    init(item: ScheduleV2Item, isNew: Bool, onSave: @escaping (ScheduleV2Item) -> Void) {
        _item = State(initialValue: item)
        self.isNew = isNew
        self.onSave = onSave
    }

    var body: some View {
        NavigationView {
            Form {
                Section {
                    VStack(alignment: .trailing, spacing: 8) {
                        TextField(NSLocalizedString("Schedule title", comment: ""), text: $item.title)
                            .focused($focusedField, equals: .title)
                            .font(.headline)
                            .onChange(of: item.title) { item.title = $0.utf8Limited(to: 60) }
                        byteCounter(item.title, limit: 60)
                    }
                    .padding(.vertical, 6)

                    VStack(alignment: .trailing, spacing: 8) {
                        ZStack(alignment: .topLeading) {
                            if item.content.isEmpty {
                                Text(NSLocalizedString("Schedule content (optional)", comment: ""))
                                    .foregroundColor(Color(.placeholderText))
                                    .padding(.top, 8)
                                    .padding(.leading, 4)
                            }
                            TextEditor(text: $item.content)
                                .focused($focusedField, equals: .content)
                                .frame(minHeight: 100)
                                .onChange(of: item.content) { item.content = $0.utf8Limited(to: 300) }
                        }
                        byteCounter(item.content, limit: 300)
                    }
                } header: {
                    Label(NSLocalizedString("Details", comment: ""), systemImage: "text.alignleft")
                } footer: {
                    Text(NSLocalizedString("Limits are measured in UTF-8 bytes to match the watch protocol.", comment: ""))
                }

                Section {
                    Toggle(NSLocalizedString("Enabled", comment: ""), isOn: $item.isOn)
                    DatePicker(
                        NSLocalizedString("Reminder date", comment: ""),
                        selection: $item.fireDate,
                        in: ScheduleV2Formatting.supportedDateRange,
                        displayedComponents: .date
                    )
                    DatePicker(
                        NSLocalizedString("Reminder time", comment: ""),
                        selection: $item.fireDate,
                        displayedComponents: .hourAndMinute
                    )
                    Button { showRepeatPicker = true } label: {
                        editorRow(
                            NSLocalizedString("Repeat", comment: ""),
                            value: ScheduleV2Formatting.repeatText(item.repeatDays)
                        )
                    }
                    Picker(NSLocalizedString("Remind before", comment: ""), selection: $item.aheadMinutes) {
                        ForEach(ScheduleV2Formatting.aheadOptions, id: \.self) { minutes in
                            Text(ScheduleV2Formatting.aheadText(minutes)).tag(minutes)
                        }
                    }
                } header: {
                    Label(NSLocalizedString("Reminder", comment: ""), systemImage: "bell")
                }

                Section {
                    HStack {
                        Text(NSLocalizedString("Schedule ID", comment: ""))
                        Spacer()
                        Text("\(item.id)").foregroundColor(.secondary)
                    }
                } footer: {
                    Text(NSLocalizedString("Saving synchronizes the complete V2 schedule list to the watch.", comment: ""))
                }
            }
            .navigationTitle(isNew
                             ? NSLocalizedString("New Schedule", comment: "")
                             : NSLocalizedString("Edit Schedule", comment: ""))
            .navigationBarTitleDisplayMode(.inline)
            .toolbar {
                ToolbarItem(placement: .cancellationAction) {
                    Button(NSLocalizedString("Cancel", comment: "")) { dismiss() }
                }
                ToolbarItem(placement: .confirmationAction) {
                    Button(NSLocalizedString("Save", comment: "")) { onSave(item) }
                        .font(.body.weight(.semibold))
                        .disabled(item.title.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty)
                }
                ToolbarItemGroup(placement: .keyboard) {
                    Spacer()
                    Button(NSLocalizedString("Done", comment: "")) { focusedField = nil }
                }
            }
            .sheet(isPresented: $showRepeatPicker) {
                ScheduleV2RepeatPicker(selection: $item.repeatDays)
            }
        }
        .navigationViewStyle(.stack)
    }

    private func byteCounter(_ value: String, limit: Int) -> some View {
        Text("\(value.lengthOfBytes(using: .utf8))/\(limit)")
            .font(.caption.monospacedDigit())
            .foregroundColor(.secondary)
    }

    private func editorRow(_ title: String, value: String) -> some View {
        HStack {
            Text(title).foregroundColor(.primary)
            Spacer()
            Text(value).foregroundColor(.secondary).lineLimit(1)
            Image(systemName: "chevron.right").font(.caption.bold()).foregroundColor(Color(.tertiaryLabel))
        }
    }
}

private struct ScheduleV2RepeatPicker: View {
    @Environment(\.dismiss) private var dismiss
    @Binding var selection: UInt8

    var body: some View {
        NavigationView {
            List {
                Button {
                    selection = 0
                } label: {
                    selectableRow(NSLocalizedString("Never", comment: ""), selected: selection == 0)
                }
                Section(NSLocalizedString("Repeat on", comment: "")) {
                    ForEach(Array(ScheduleV2Formatting.weekdays.enumerated()), id: \.offset) { index, name in
                        Button {
                            selection ^= UInt8(1 << index)
                        } label: {
                            selectableRow(name, selected: selection & UInt8(1 << index) != 0)
                        }
                    }
                }
            }
            .navigationTitle(NSLocalizedString("Repeat", comment: ""))
            .navigationBarTitleDisplayMode(.inline)
            .toolbar {
                ToolbarItem(placement: .confirmationAction) {
                    Button(NSLocalizedString("Done", comment: "")) { dismiss() }
                }
            }
        }
        .navigationViewStyle(.stack)
    }

    private func selectableRow(_ title: String, selected: Bool) -> some View {
        HStack {
            Text(title).foregroundColor(.primary)
            Spacer()
            if selected {
                Image(systemName: "checkmark")
                    .font(.body.weight(.semibold))
                    .foregroundColor(.accentColor)
            }
        }
    }
}

private enum ScheduleV2Formatting {
    static let weekdays: [String] = [
        NSLocalizedString("Monday", comment: ""),
        NSLocalizedString("Tuesday", comment: ""),
        NSLocalizedString("Wednesday", comment: ""),
        NSLocalizedString("Thursday", comment: ""),
        NSLocalizedString("Friday", comment: ""),
        NSLocalizedString("Saturday", comment: ""),
        NSLocalizedString("Sunday", comment: "")
    ]

    static let aheadOptions: [UInt8] = [0, 5, 10, 15, 30, 60]

    static var supportedDateRange: ClosedRange<Date> {
        let calendar = Calendar.current
        let lower = calendar.date(from: DateComponents(year: 2000, month: 1, day: 1)) ?? Date.distantPast
        let upper = calendar.date(from: DateComponents(year: 2063, month: 12, day: 31, hour: 23, minute: 59)) ?? Date.distantFuture
        return lower...upper
    }

    static func dateTime(_ date: Date) -> String {
        let formatter = DateFormatter()
        formatter.locale = .current
        formatter.setLocalizedDateFormatFromTemplate("MMMd HHmm")
        return formatter.string(from: date)
    }

    static func repeatText(_ rawValue: UInt8) -> String {
        if rawValue == 0 { return NSLocalizedString("Never", comment: "") }
        if rawValue == 0x7F { return NSLocalizedString("Every day", comment: "") }
        if rawValue == 0x1F { return NSLocalizedString("Weekdays", comment: "") }
        if rawValue == 0x60 { return NSLocalizedString("Weekends", comment: "") }
        let shortSymbols = Calendar.current.shortWeekdaySymbols
        let mondayFirst = Array(shortSymbols.dropFirst()) + [shortSymbols[0]]
        return mondayFirst.enumerated()
            .filter { rawValue & UInt8(1 << $0.offset) != 0 }
            .map(\.element)
            .joined(separator: " ")
    }

    static func aheadText(_ minutes: UInt8) -> String {
        guard minutes > 0 else { return NSLocalizedString("None", comment: "") }
        if minutes == 60 { return NSLocalizedString("1 hour before", comment: "") }
        return String(format: NSLocalizedString("%d minutes before", comment: ""), minutes)
    }
}

private extension String {
    func utf8Limited(to maximumBytes: Int) -> String {
        guard lengthOfBytes(using: .utf8) > maximumBytes else { return self }
        var result = self
        while result.lengthOfBytes(using: .utf8) > maximumBytes { result.removeLast() }
        return result
    }
}
