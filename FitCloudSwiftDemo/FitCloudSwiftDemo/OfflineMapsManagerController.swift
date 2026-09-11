import UIKit
import FitCloudKit

/// Lists and manages files on the watch, independently of the phone's temporary download archive.
final class OfflineMapsManagerController: UITableViewController {
    private struct MapFile {
        let fileName: String
        let fileSize: Int
    }
    private var files: [MapFile] = []
    private let summaryLabel = UILabel()
    private let statusLabel = UILabel()
    private let header = UIView()
    private let headerStack = UIStackView()
    private var operationName = ""
    private lazy var moreButton = UIBarButtonItem(image: UIImage(systemName: "ellipsis.circle"), style: .plain, target: self, action: #selector(showMore))
    private var listDeviceID: UUID?
    private var requestID: UUID?
    private let emptyLabel = UILabel()
    private let activity = UIActivityIndicatorView(style: .medium)
    private var disconnectObserver: NSObjectProtocol?
    private lazy var refreshButton = UIBarButtonItem(barButtonSystemItem: .refresh, target: self, action: #selector(refreshFiles))

    init() { super.init(style: .insetGrouped) }
    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }
    deinit {
        if let observer = disconnectObserver { NotificationCenter.default.removeObserver(observer) }
    }
    private func text(_ key: String) -> String { NSLocalizedString(key, comment: "Watch map management") }

    override func viewDidLoad() {
        super.viewDidLoad()
        title = text("Watch maps")
        view.tintColor = .label
        navigationController?.navigationBar.tintColor = .label
        tableView.backgroundColor = UIColor { UIColor(white: $0.userInterfaceStyle == .dark ? 0.06 : 0.96, alpha: 1) }
        tableView.rowHeight = UITableView.automaticDimension
        tableView.estimatedRowHeight = 72
        navigationItem.leftBarButtonItem = UIBarButtonItem(title: text("Back"), style: .plain, target: self, action: #selector(close))
        navigationItem.rightBarButtonItems = [moreButton, refreshButton]
        activity.hidesWhenStopped = true
        navigationController?.setToolbarHidden(true, animated: false)
        tableView.cellLayoutMarginsFollowReadableWidth = true
        tableView.separatorStyle = .singleLine
        tableView.separatorInset = UIEdgeInsets(top: 0, left: 76, bottom: 0, right: 16)
        tableView.register(WatchMapCell.self, forCellReuseIdentifier: "map")
        configureHeader()
        refreshControl = UIRefreshControl()
        refreshControl?.addTarget(self, action: #selector(refreshFiles), for: .valueChanged)
        emptyLabel.numberOfLines = 0
        emptyLabel.textAlignment = .center
        emptyLabel.font = .preferredFont(forTextStyle: .body)
        emptyLabel.adjustsFontForContentSizeCategory = true
        emptyLabel.textColor = .secondaryLabel
        let emptyContainer = UIView()
        emptyLabel.translatesAutoresizingMaskIntoConstraints = false
        emptyContainer.addSubview(emptyLabel)
        NSLayoutConstraint.activate([
            emptyLabel.centerXAnchor.constraint(equalTo: emptyContainer.centerXAnchor),
            emptyLabel.centerYAnchor.constraint(equalTo: emptyContainer.centerYAnchor),
            emptyLabel.widthAnchor.constraint(lessThanOrEqualToConstant: 360),
            emptyLabel.leadingAnchor.constraint(greaterThanOrEqualTo: emptyContainer.leadingAnchor, constant: 32)
        ])
        tableView.backgroundView = emptyContainer
        disconnectObserver = NotificationCenter.default.addObserver(
            forName: NSNotification.Name(FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY), object: nil, queue: .main
        ) { [weak self] _ in
            guard let self = self else { return }
            self.requestID = nil
            self.files = []
            self.listDeviceID = nil
            self.emptyLabel.text = self.text("Watch disconnected. Reconnect and refresh the map list.")
            self.setStatus("Watch disconnected. Reconnect and refresh the map list.")
            self.updateControls()
            self.tableView.reloadData()
        }
        refreshFiles()
    }

    private func updateControls() {
        let busy = requestID != nil
        refreshButton.isEnabled = !busy
        moreButton.isEnabled = !busy && !files.isEmpty
        navigationItem.leftBarButtonItem?.isEnabled = !busy
        navigationController?.isModalInPresentation = busy
        if busy { activity.startAnimating() } else {
            activity.stopAnimating()
            refreshControl?.endRefreshing()
        }
        emptyLabel.isHidden = !files.isEmpty
        let total = files.reduce(Int64(0)) { sum, file in
            let (value, overflow) = sum.addingReportingOverflow(Int64(max(0, file.fileSize)))
            return overflow ? Int64.max : value
        }
        summaryLabel.text = String(format: text("%ld maps · %@"), files.count, ByteCountFormatter.string(fromByteCount: total, countStyle: .file))
        if busy { statusLabel.text = text(operationName); statusLabel.textColor = .secondaryLabel }
        resizeHeader()
    }

    private func connectedDevice() -> UUID? {
        guard FitCloudKit.isConnected(), FitCloudKit.isDeviceReady() else { return nil }
        return FitCloudKit.lastConnectPeripheral()?.uuid
    }

    private func begin(for deviceID: UUID, operation: String) -> UUID? {
        guard requestID == nil else { return nil }
        guard connectedDevice() == deviceID else {
            files = []
            listDeviceID = nil
            emptyLabel.text = text("Watch changed or disconnected. Refresh the map list.")
            setStatus("Watch changed or disconnected. Refresh the map list.")
            tableView.reloadData()
            updateControls()
            return nil
        }
        let id = UUID()
        operationName = operation
        requestID = id
        updateControls()
        return id
    }

    /// Ignore replies belonging to an earlier operation or another watch.
    private func finish(_ id: UUID, deviceID: UUID) -> Bool {
        guard requestID == id else { return false }
        requestID = nil
        guard connectedDevice() == deviceID else {
            files = []
            listDeviceID = nil
            emptyLabel.text = text("Watch changed or disconnected. Refresh the map list.")
            setStatus("Watch changed or disconnected. Refresh the map list.")
            tableView.reloadData()
            updateControls()
            return false
        }
        updateControls()
        return true
    }

    @objc private func refreshFiles() {
        guard requestID == nil else { refreshControl?.endRefreshing(); return }
        guard let deviceID = connectedDevice() else {
            files = []
            listDeviceID = nil
            emptyLabel.text = text("Connect and initialize the watch before continuing.")
            setStatus("Connect and initialize the watch before continuing.")
            updateControls()
            tableView.reloadData()
            return
        }
        if listDeviceID != deviceID { files = []; listDeviceID = nil }
        emptyLabel.text = text("Reading watch maps…")
        tableView.reloadData()
        guard let id = begin(for: deviceID, operation: "Reading watch maps…") else { return }
        FitCloudKit.fetchOfflineMapsFileList { [weak self] success, files, error in
            DispatchQueue.main.async {
                guard let self = self, self.finish(id, deviceID: deviceID) else { return }
                guard success, error == nil else {
                    self.emptyLabel.text = self.text("Unable to read watch maps. Tap refresh to retry.")
                    self.showError(error)
                    return
                }
                self.files = (files ?? []).map { MapFile(fileName: $0.fileName, fileSize: $0.fileSize) }
                self.listDeviceID = deviceID
                self.emptyLabel.text = self.text("No offline maps on this watch. Download and send a map first.")
                self.setStatus("Tap a map for actions. Swipe left to delete.")
                self.updateControls()
                self.tableView.reloadData()
            }
        }
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int { files.count }
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        files.isEmpty ? nil : text("Stored on watch")
    }
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "map", for: indexPath) as! WatchMapCell
        let file = files[indexPath.row]
        cell.configure(name: file.fileName, size: file.fileSize)
        return cell
    }
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        guard requestID == nil, files.indices.contains(indexPath.row), let deviceID = listDeviceID else { return }
        let file = files[indexPath.row]
        // The list already contains name and size. Opening actions never sends a watch command.
        let alert = UIAlertController(title: file.fileName,
            message: ByteCountFormatter.string(fromByteCount: Int64(file.fileSize), countStyle: .file), preferredStyle: .actionSheet)
        alert.addAction(UIAlertAction(title: text("Read device details"), style: .default) { [weak self] _ in
            self?.fetchDetails(fileName: file.fileName, deviceID: deviceID)
        })
        alert.addAction(UIAlertAction(title: text("Delete watch map"), style: .destructive) { [weak self] _ in
            self?.confirmDelete(fileName: file.fileName, deviceID: deviceID)
        })
        alert.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        alert.popoverPresentationController?.sourceView = tableView
        alert.popoverPresentationController?.sourceRect = tableView.rectForRow(at: indexPath)
        present(alert, animated: true)
    }
    override func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        guard requestID == nil, let deviceID = listDeviceID else { return nil }
        let fileName = files[indexPath.row].fileName
        let delete = UIContextualAction(style: .destructive, title: text("Delete watch map")) { [weak self] _, _, completion in
            completion(false)
            self?.confirmDelete(fileName: fileName, deviceID: deviceID)
        }
        delete.image = UIImage(systemName: "trash")
        let config = UISwipeActionsConfiguration(actions: [delete])
        config.performsFirstActionWithFullSwipe = false
        return config
    }

    private func fetchDetails(fileName: String, deviceID: UUID) {
        guard let id = begin(for: deviceID, operation: "Reading device details…") else { return }
        FitCloudKit.fetchOfflineMapsFileDetail(withName: fileName) { [weak self] success, detail, error in
            DispatchQueue.main.async {
                guard let self = self, self.finish(id, deviceID: deviceID) else { return }
                guard success, error == nil else { self.showError(error); return }
                guard let detail = detail else {
                    self.setStatus("This map no longer exists on the watch.")
                    self.refreshFiles()
                    return
                }
                self.setStatus("Tap a map for actions. Swipe left to delete.")
                let body = "\(self.text("Size")): \(detail.fileSize) bytes\nCRC16: \(String(format: "%04X", detail.crc))\n\(self.text("Storage index")): \(detail.fileIndex)"
                let alert = UIAlertController(title: detail.fileName, message: body, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: self.text("Got it"), style: .default))
                self.present(alert, animated: true)
            }
        }
    }

    @objc private func showMore() {
        guard requestID == nil, !files.isEmpty else { return }
        let sheet = UIAlertController(title: text("Watch maps"), message: nil, preferredStyle: .actionSheet)
        sheet.addAction(UIAlertAction(title: text("Delete all watch maps"), style: .destructive) { [weak self] _ in self?.confirmDeleteAll() })
        sheet.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        sheet.popoverPresentationController?.barButtonItem = moreButton
        present(sheet, animated: true)
    }

    private func confirmDelete(fileName: String, deviceID: UUID) {
        let alert = UIAlertController(title: text("Delete this map from the watch?"), message: fileName, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        alert.addAction(UIAlertAction(title: text("Delete watch map"), style: .destructive) { [weak self] _ in
            guard let self = self, let id = self.begin(for: deviceID, operation: "Deleting watch maps…") else { return }
            FitCloudKit.deleteOfflineMapsFile(withName: fileName) { [weak self] success, error in
                DispatchQueue.main.async { self?.deleted(id: id, deviceID: deviceID, success: success, error: error) }
            }
        })
        present(alert, animated: true)
    }
    @objc private func confirmDeleteAll() {
        guard requestID == nil, !files.isEmpty, let deviceID = listDeviceID else { return }
        let alert = UIAlertController(title: text("Delete all watch maps?"), message: text("All offline maps on this watch will be removed. Download and send them again to restore them."), preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        alert.addAction(UIAlertAction(title: text("Delete all watch maps"), style: .destructive) { [weak self] _ in
            guard let self = self, let id = self.begin(for: deviceID, operation: "Deleting watch maps…") else { return }
            FitCloudKit.deleteAllOfflineMapsFiles { [weak self] success, error in
                DispatchQueue.main.async { self?.deleted(id: id, deviceID: deviceID, success: success, error: error) }
            }
        })
        present(alert, animated: true)
    }
    private func deleted(id: UUID, deviceID: UUID, success: Bool, error: Error?) {
        guard finish(id, deviceID: deviceID) else { return }
        guard success, error == nil else { showError(error); return }
        refreshFiles()
    }
    private func showError(_ error: Error?) {
        let error = error as NSError?
        let detail = error.map { "\($0.localizedDescription) (\($0.domain)/\($0.code))" } ?? text("Watch map operation failed. Please try again.")
        statusLabel.text = text(operationName) + "\n" + detail
        statusLabel.textColor = .secondaryLabel
        if operationName == "Reading device details…" {
            statusLabel.text! += "\n" + text("Device details were not returned. You can still delete maps using the list.")
        }
        resizeHeader()
        tableView.setContentOffset(CGPoint(x: 0, y: -tableView.adjustedContentInset.top), animated: true)
    }
    private func setStatus(_ key: String) {
        statusLabel.text = text(key)
        statusLabel.textColor = .secondaryLabel
        resizeHeader()
    }
    private func configureHeader() {
        let title = UILabel()
        title.text = text("Your offline maps")
        title.font = UIFontMetrics(forTextStyle: .title1).scaledFont(for: .systemFont(ofSize: 28, weight: .bold))
        title.adjustsFontForContentSizeCategory = true
        title.numberOfLines = 0
        summaryLabel.font = .preferredFont(forTextStyle: .subheadline)
        summaryLabel.textColor = .secondaryLabel
        statusLabel.font = .preferredFont(forTextStyle: .footnote)
        statusLabel.numberOfLines = 0
        statusLabel.adjustsFontForContentSizeCategory = true
        let status = UIStackView(arrangedSubviews: [activity, statusLabel])
        status.spacing = 8
        status.alignment = .top
        headerStack.axis = .vertical
        headerStack.spacing = 8
        [title, summaryLabel, status].forEach { headerStack.addArrangedSubview($0) }
        headerStack.setCustomSpacing(18, after: summaryLabel)
        headerStack.translatesAutoresizingMaskIntoConstraints = false
        header.addSubview(headerStack)
        NSLayoutConstraint.activate([
            headerStack.topAnchor.constraint(equalTo: header.topAnchor, constant: 24),
            headerStack.bottomAnchor.constraint(equalTo: header.bottomAnchor, constant: -12),
            headerStack.leadingAnchor.constraint(equalTo: header.layoutMarginsGuide.leadingAnchor),
            headerStack.trailingAnchor.constraint(equalTo: header.layoutMarginsGuide.trailingAnchor)
        ])
        tableView.tableHeaderView = header
    }
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        resizeHeader()
    }
    private func resizeHeader() {
        guard isViewLoaded, tableView.bounds.width > 0 else { return }
        let width = tableView.bounds.width
        header.directionalLayoutMargins = tableView.directionalLayoutMargins
        let size = header.systemLayoutSizeFitting(CGSize(width: width, height: 0), withHorizontalFittingPriority: .required, verticalFittingPriority: .fittingSizeLevel)
        if abs(header.frame.height - size.height) > 0.5 || header.frame.width != width {
            header.frame = CGRect(x: 0, y: 0, width: width, height: size.height)
            tableView.tableHeaderView = header
        }
    }
    @objc private func close() {
        guard requestID == nil else { return }
        dismiss(animated: true)
    }
}


private final class WatchMapCell: UITableViewCell {
    private let nameLabel = UILabel()
    private let sizeLabel = UILabel()
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        let icon = UIImageView(image: UIImage(systemName: "map"))
        icon.contentMode = .center
        icon.tintColor = .label
        icon.backgroundColor = .tertiarySystemFill
        icon.layer.cornerRadius = 12
        icon.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 19, weight: .regular)
        NSLayoutConstraint.activate([icon.widthAnchor.constraint(equalToConstant: 44), icon.heightAnchor.constraint(equalToConstant: 44)])
        nameLabel.font = .preferredFont(forTextStyle: .body)
        nameLabel.numberOfLines = 1
        nameLabel.lineBreakMode = .byTruncatingMiddle
        nameLabel.adjustsFontForContentSizeCategory = true
        sizeLabel.font = .preferredFont(forTextStyle: .footnote)
        sizeLabel.textColor = .secondaryLabel
        let labels = UIStackView(arrangedSubviews: [nameLabel, sizeLabel])
        labels.axis = .vertical
        labels.spacing = 5
        let more = UIImageView(image: UIImage(systemName: "ellipsis"))
        more.tintColor = .tertiaryLabel
        more.contentMode = .scaleAspectFit
        more.widthAnchor.constraint(equalToConstant: 20).isActive = true
        let row = UIStackView(arrangedSubviews: [icon, labels, more])
        row.spacing = 14
        row.alignment = .center
        row.translatesAutoresizingMaskIntoConstraints = false
        contentView.addSubview(row)
        NSLayoutConstraint.activate([
            row.leadingAnchor.constraint(equalTo: contentView.layoutMarginsGuide.leadingAnchor),
            row.trailingAnchor.constraint(equalTo: contentView.layoutMarginsGuide.trailingAnchor),
            row.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 16),
            row.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -16)
        ])
        backgroundColor = .secondarySystemGroupedBackground
    }
    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }
    func configure(name: String, size: Int) {
        nameLabel.text = name
        sizeLabel.text = ByteCountFormatter.string(fromByteCount: Int64(size), countStyle: .file)
        accessibilityLabel = name + ", " + (sizeLabel.text ?? "")
        accessibilityHint = NSLocalizedString("Tap a map for actions. Swipe left to delete.", comment: "")
    }
}
