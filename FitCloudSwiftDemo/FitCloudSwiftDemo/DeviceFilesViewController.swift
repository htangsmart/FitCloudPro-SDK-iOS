//
//  DeviceFilesViewController.swift
//  FitCloudSwiftDemo
//
//  Device storage, song and audio-recording API demo.
//

import UIKit
import FitCloudKit

@objc final class DeviceFilesViewController: UIViewController {

    private enum Section: Int, CaseIterable {
        case songs
        case recordings
    }

    private let tableView = UITableView(frame: .zero, style: .insetGrouped)
    private let storageCard = StorageSummaryView()
    private let activityIndicator = UIActivityIndicatorView(style: .medium)
    private var songs: [FitCloudFileInfoModel] = []
    private var recordings: [FitCloudFileInfoModel] = []
    private var transferInProgress = false

    private lazy var uploadButton: UIButton = makeHeaderButton(
        title: text("Upload song"), symbol: "square.and.arrow.up", action: #selector(chooseSong)
    )
    private lazy var refreshButton: UIButton = makeHeaderButton(
        title: text("Refresh"), symbol: "arrow.clockwise", action: #selector(refreshAll)
    )

    override func viewDidLoad() {
        super.viewDidLoad()
        configureUI()
        refreshAll()
    }

    private func configureUI() {
        view.backgroundColor = UIColor.systemGroupedBackground

        let backButton = UIButton(type: .system)
        backButton.setImage(UIImage(systemName: "chevron.left"), for: .normal)
        backButton.setTitle(text("Back"), for: .normal)
        backButton.titleLabel?.font = .systemFont(ofSize: 16, weight: .semibold)
        backButton.addTarget(self, action: #selector(goBack), for: .touchUpInside)

        let titleLabel = UILabel()
        titleLabel.text = text("Device files")
        titleLabel.font = .systemFont(ofSize: 28, weight: .bold)
        titleLabel.textColor = .label

        let subtitleLabel = UILabel()
        subtitleLabel.text = text("Manage music and recordings on the watch")
        subtitleLabel.font = .systemFont(ofSize: 13, weight: .medium)
        subtitleLabel.textColor = .secondaryLabel

        let titleStack = UIStackView(arrangedSubviews: [titleLabel, subtitleLabel])
        titleStack.axis = .vertical
        titleStack.spacing = 3

        let header = UIView()
        [backButton, titleStack].forEach {
            $0.translatesAutoresizingMaskIntoConstraints = false
            header.addSubview($0)
        }

        tableView.dataSource = self
        tableView.delegate = self
        tableView.rowHeight = 68
        tableView.sectionHeaderHeight = 44
        tableView.estimatedSectionHeaderHeight = 44
        tableView.sectionFooterHeight = 28
        tableView.estimatedSectionFooterHeight = 28
        if #available(iOS 15.0, *) {
            tableView.sectionHeaderTopPadding = 0
        }
        tableView.backgroundColor = .clear
        tableView.register(FileCell.self, forCellReuseIdentifier: FileCell.reuseIdentifier)
        tableView.refreshControl = UIRefreshControl()
        tableView.refreshControl?.addTarget(self, action: #selector(refreshAll), for: .valueChanged)

        let actionStack = UIStackView(arrangedSubviews: [refreshButton, uploadButton])
        actionStack.axis = .horizontal
        actionStack.distribution = .fillEqually
        actionStack.spacing = 12

        activityIndicator.hidesWhenStopped = true

        [header, storageCard, actionStack, tableView, activityIndicator].forEach {
            $0.translatesAutoresizingMaskIntoConstraints = false
            view.addSubview($0)
        }

        NSLayoutConstraint.activate([
            header.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            header.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            header.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            header.heightAnchor.constraint(equalToConstant: 76),
            backButton.leadingAnchor.constraint(equalTo: header.leadingAnchor, constant: 16),
            backButton.centerYAnchor.constraint(equalTo: titleLabel.centerYAnchor),
            titleStack.leadingAnchor.constraint(equalTo: backButton.trailingAnchor, constant: 12),
            titleStack.trailingAnchor.constraint(lessThanOrEqualTo: header.trailingAnchor, constant: -20),
            titleStack.centerYAnchor.constraint(equalTo: header.centerYAnchor),

            storageCard.topAnchor.constraint(equalTo: header.bottomAnchor, constant: 4),
            storageCard.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 20),
            storageCard.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -20),
            storageCard.heightAnchor.constraint(equalToConstant: 132),

            actionStack.topAnchor.constraint(equalTo: storageCard.bottomAnchor, constant: 14),
            actionStack.leadingAnchor.constraint(equalTo: storageCard.leadingAnchor),
            actionStack.trailingAnchor.constraint(equalTo: storageCard.trailingAnchor),
            actionStack.heightAnchor.constraint(equalToConstant: 46),

            tableView.topAnchor.constraint(equalTo: actionStack.bottomAnchor, constant: 4),
            tableView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            tableView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            tableView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            activityIndicator.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            activityIndicator.centerYAnchor.constraint(equalTo: view.centerYAnchor)
        ])
    }

    private func makeHeaderButton(title: String, symbol: String, action: Selector) -> UIButton {
        let button = UIButton(type: .system)
        button.setTitle(title, for: .normal)
        button.setImage(UIImage(systemName: symbol), for: .normal)
        button.tintColor = .white
        button.setTitleColor(.white, for: .normal)
        button.titleLabel?.font = .systemFont(ofSize: 15, weight: .semibold)
        button.backgroundColor = UIColor(red: 0.18, green: 0.45, blue: 0.95, alpha: 1)
        button.layer.cornerRadius = 14
        button.imageEdgeInsets.right = 8
        button.addTarget(self, action: action, for: .touchUpInside)
        return button
    }

    @objc private func goBack() {
        navigationController?.popViewController(animated: true)
    }

    @objc private func refreshAll() {
        activityIndicator.startAnimating()
        storageCard.showLoading(supported: FitCloudKit.isExternalStorageSupported())
        let group = DispatchGroup()

        group.enter()
        FitCloudKit.fetchDeviceStorageInfo { [weak self] success, info, error in
            DispatchQueue.main.async {
                if success, let info = info {
                    self?.storageCard.update(with: info)
                } else {
                    self?.storageCard.showError(error?.localizedDescription ?? self?.text("Unavailable") ?? "")
                }
                group.leave()
            }
        }

        group.enter()
        FitCloudKit.fetchSongFileList { [weak self] success, files, error in
            DispatchQueue.main.async {
                if success { self?.songs = files ?? [] }
                else { self?.show(error: error) }
                group.leave()
            }
        }

        group.enter()
        FitCloudKit.fetchAudioRecordingFileList { [weak self] success, files, error in
            DispatchQueue.main.async {
                if success { self?.recordings = files ?? [] }
                else { self?.show(error: error) }
                group.leave()
            }
        }

        group.notify(queue: .main) { [weak self] in
            self?.activityIndicator.stopAnimating()
            self?.tableView.refreshControl?.endRefreshing()
            self?.tableView.reloadData()
        }
    }

    @objc private func chooseSong() {
        guard !transferInProgress else { return }
        let picker = UIDocumentPickerViewController(documentTypes: ["public.mp3", "public.audio"], in: .import)
        picker.delegate = self
        picker.allowsMultipleSelection = false
        present(picker, animated: true)
    }

    private func uploadSong(at url: URL) {
        setTransferState(active: true, message: text("Preparing upload…"), progress: 0)
        DispatchQueue.global(qos: .userInitiated).async { [weak self] in
            FitCloudKit.sendSongFile(url.path) { progress in
                DispatchQueue.main.async {
                    self?.setTransferState(active: true, message: self?.text("Uploading song…") ?? "", progress: progress)
                }
            } completion: { success, speed, error in
                DispatchQueue.main.async {
                    self?.setTransferState(active: false)
                    if success {
                        self?.showMessage(String(format: self?.text("Upload completed at %.1f kB/s") ?? "", speed))
                        self?.refreshAll()
                    } else {
                        self?.show(error: error)
                    }
                }
            }
        }
    }

    private func setTransferState(active: Bool, message: String = "", progress: CGFloat = 0) {
        transferInProgress = active
        uploadButton.isEnabled = !active
        uploadButton.alpha = active ? 0.55 : 1
        if active {
            storageCard.showTransfer(message: message, progress: progress) { [weak self] in self?.cancelUpload() }
        } else {
            storageCard.hideTransfer()
        }
    }

    private func cancelUpload() {
        FitCloudKit.cancelSendSongFileIfNeeded { [weak self] success, error in
            DispatchQueue.main.async {
                self?.setTransferState(active: false)
                success ? self?.showMessage(self?.text("Upload cancelled") ?? "") : self?.show(error: error)
            }
        }
    }

    private func files(in section: Int) -> [FitCloudFileInfoModel] {
        section == Section.songs.rawValue ? songs : recordings
    }

    private func showActions(for file: FitCloudFileInfoModel, section: Section, sourceView: UIView?) {
        let sheet = UIAlertController(title: file.fileName, message: ByteCountFormatter.string(fromByteCount: Int64(file.fileSize), countStyle: .file), preferredStyle: .actionSheet)
        sheet.addAction(UIAlertAction(title: text("File details"), style: .default) { [weak self] _ in self?.fetchDetails(file, section: section) })
        if section == .recordings {
            sheet.addAction(UIAlertAction(title: text("Download to app"), style: .default) { [weak self] _ in self?.downloadRecording(file) })
        }
        sheet.addAction(UIAlertAction(title: text("Delete"), style: .destructive) { [weak self] _ in self?.confirmDelete(file, section: section) })
        sheet.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        if let popover = sheet.popoverPresentationController {
            popover.sourceView = sourceView ?? view
            popover.sourceRect = sourceView?.bounds ?? CGRect(x: view.bounds.midX, y: view.bounds.midY, width: 1, height: 1)
        }
        present(sheet, animated: true)
    }

    private func fetchDetails(_ file: FitCloudFileInfoModel, section: Section) {
        activityIndicator.startAnimating()
        let completion: (Bool, FitCloudFileDetailsInfoModel?, Error?) -> Void = { [weak self] success, details, error in
            DispatchQueue.main.async {
                self?.activityIndicator.stopAnimating()
                guard success, let details = details else { self?.show(error: error); return }
                let size = ByteCountFormatter.string(fromByteCount: Int64(details.fileSize), countStyle: .file)
                let body = "\(self?.text("Size") ?? ""): \(size)\nCRC16: \(details.crc)\n\(self?.text("Storage index") ?? ""): \(details.fileIndex)"
                self?.showMessage(body, title: details.fileName)
            }
        }
        if section == .songs {
            FitCloudKit.fetchSongFileDetail(withName: file.fileName, completion: completion)
        } else {
            FitCloudKit.fetchAudioRecordingFileDetail(withName: file.fileName, completion: completion)
        }
    }

    private func downloadRecording(_ file: FitCloudFileInfoModel) {
        storageCard.showTransfer(message: text("Downloading…"), progress: 0, cancel: nil)
        let progress: (CGFloat) -> Void = { [weak self] value in
            DispatchQueue.main.async { self?.storageCard.showTransfer(message: self?.text("Downloading…") ?? "", progress: value, cancel: nil) }
        }
        let completion: (Bool, String?, Error?) -> Void = { [weak self] success, path, error in
            DispatchQueue.main.async {
                self?.storageCard.hideTransfer()
                guard success, let path = path else { self?.show(error: error); return }
                self?.presentShareSheet(path: path)
            }
        }
        FitCloudKit.fetchAudioRecordingFile(withName: file.fileName, progress: progress, completion: completion)
    }

    private func presentShareSheet(path: String) {
        let url = URL(fileURLWithPath: path)
        let controller = UIActivityViewController(activityItems: [url], applicationActivities: nil)
        controller.popoverPresentationController?.sourceView = view
        controller.popoverPresentationController?.sourceRect = CGRect(x: view.bounds.midX, y: view.bounds.midY, width: 1, height: 1)
        present(controller, animated: true)
    }

    private func confirmDelete(_ file: FitCloudFileInfoModel, section: Section) {
        confirm(title: text("Delete file?"), message: file.fileName) { [weak self] in
            let completion: (Bool, Error?) -> Void = { success, error in
                DispatchQueue.main.async { success ? self?.refreshAll() : self?.show(error: error) }
            }
            if section == .songs {
                FitCloudKit.deleteSongFile(withName: file.fileName, completion: completion)
            } else {
                FitCloudKit.deleteAudioRecordingFile(withName: file.fileName, completion: completion)
            }
        }
    }

    private func deleteAll(in section: Section) {
        let kind = section == .songs ? text("songs") : text("recordings")
        confirm(title: text("Delete all files?"), message: String(format: text("All %@ on the watch will be permanently deleted."), kind)) { [weak self] in
            let completion: (Bool, Error?) -> Void = { success, error in
                DispatchQueue.main.async { success ? self?.refreshAll() : self?.show(error: error) }
            }
            section == .songs
                ? FitCloudKit.deleteAllSongFiles(completion: completion)
                : FitCloudKit.deleteAllAudioRecordingFiles(completion: completion)
        }
    }

    private func confirm(title: String, message: String, action: @escaping () -> Void) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        alert.addAction(UIAlertAction(title: text("Delete"), style: .destructive) { _ in action() })
        present(alert, animated: true)
    }

    private func show(error: Error?) {
        showMessage(error?.localizedDescription ?? text("Operation failed"), title: text("Unable to complete"))
    }

    private func showMessage(_ message: String, title: String? = nil) {
        let alert = UIAlertController(title: title ?? text("Done"), message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("OK"), style: .default))
        present(alert, animated: true)
    }

    private func text(_ key: String) -> String { NSLocalizedString(key, comment: "Device files demo") }
}

extension DeviceFilesViewController: UITableViewDataSource, UITableViewDelegate {
    func numberOfSections(in tableView: UITableView) -> Int { Section.allCases.count }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        max(files(in: section).count, 1)
    }

    func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        let count = files(in: section).count
        return count == 0 ? nil : String(format: text("%d files · Tap a file for actions"), count)
    }

    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let header = UITableViewHeaderFooterView(reuseIdentifier: nil)
        let label = UILabel()
        label.text = section == Section.songs.rawValue ? text("Songs") : text("Audio recordings")
        label.font = .systemFont(ofSize: 15, weight: .bold)
        label.textColor = .secondaryLabel
        label.translatesAutoresizingMaskIntoConstraints = false
        header.contentView.addSubview(label)

        let button = UIButton(type: .system)
        button.setTitle(text("Delete all"), for: .normal)
        button.setTitleColor(.systemRed, for: .normal)
        button.titleLabel?.font = .systemFont(ofSize: 13, weight: .semibold)
        button.tag = section
        button.addTarget(self, action: #selector(deleteAllTapped(_:)), for: .touchUpInside)
        button.isHidden = files(in: section).isEmpty
        button.translatesAutoresizingMaskIntoConstraints = false
        header.contentView.addSubview(button)
        NSLayoutConstraint.activate([
            label.leadingAnchor.constraint(equalTo: header.contentView.leadingAnchor, constant: 18),
            label.centerYAnchor.constraint(equalTo: header.contentView.centerYAnchor),
            label.trailingAnchor.constraint(lessThanOrEqualTo: button.leadingAnchor, constant: -12),
            button.trailingAnchor.constraint(equalTo: header.contentView.trailingAnchor, constant: -18),
            button.centerYAnchor.constraint(equalTo: header.contentView.centerYAnchor)
        ])
        return header
    }

    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        44
    }

    func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        files(in: section).isEmpty ? 14 : 28
    }

    @objc private func deleteAllTapped(_ sender: UIButton) {
        guard let section = Section(rawValue: sender.tag) else { return }
        deleteAll(in: section)
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: FileCell.reuseIdentifier, for: indexPath) as! FileCell
        let sectionFiles = files(in: indexPath.section)
        guard !sectionFiles.isEmpty else {
            cell.configureEmpty(title: text("No files found"), detail: text("Pull down to refresh"))
            return cell
        }
        cell.configure(file: sectionFiles[indexPath.row], recording: indexPath.section == Section.recordings.rawValue)
        return cell
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        let sectionFiles = files(in: indexPath.section)
        guard !sectionFiles.isEmpty, let section = Section(rawValue: indexPath.section) else { return }
        showActions(for: sectionFiles[indexPath.row], section: section, sourceView: tableView.cellForRow(at: indexPath))
    }
}

extension DeviceFilesViewController: UIDocumentPickerDelegate {
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        guard let url = urls.first else { return }
        uploadSong(at: url)
    }
}

private final class FileCell: UITableViewCell {
    static let reuseIdentifier = "DeviceFileCell"

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: .subtitle, reuseIdentifier: reuseIdentifier)
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    func configure(file: FitCloudFileInfoModel, recording: Bool) {
        imageView?.image = UIImage(systemName: recording ? "waveform" : "music.note")
        imageView?.tintColor = recording ? .systemOrange : .systemBlue
        textLabel?.text = file.fileName
        textLabel?.font = .systemFont(ofSize: 15, weight: .semibold)
        textLabel?.textColor = .label
        detailTextLabel?.text = ByteCountFormatter.string(fromByteCount: Int64(file.fileSize), countStyle: .file)
        detailTextLabel?.textColor = .secondaryLabel
        accessoryType = .disclosureIndicator
        selectionStyle = .default
    }

    func configureEmpty(title: String, detail: String) {
        imageView?.image = UIImage(systemName: "tray")
        imageView?.tintColor = .tertiaryLabel
        textLabel?.text = title
        textLabel?.font = .systemFont(ofSize: 15, weight: .semibold)
        textLabel?.textColor = .secondaryLabel
        detailTextLabel?.text = detail
        detailTextLabel?.textColor = .tertiaryLabel
        accessoryType = .none
        selectionStyle = .none
    }
}

private final class StorageSummaryView: UIView {
    private let titleLabel = UILabel()
    private let capacityLabel = UILabel()
    private let detailLabel = UILabel()
    private let progressView = UIProgressView(progressViewStyle: .default)
    private let transferStack = UIStackView()
    private let transferLabel = UILabel()
    private let transferProgress = UIProgressView(progressViewStyle: .default)
    private let cancelButton = UIButton(type: .system)
    private var cancelAction: (() -> Void)?

    override init(frame: CGRect) {
        super.init(frame: frame)
        backgroundColor = UIColor(red: 0.08, green: 0.12, blue: 0.22, alpha: 1)
        layer.cornerRadius = 22
        layer.shadowColor = UIColor.black.cgColor
        layer.shadowOpacity = 0.12
        layer.shadowRadius = 12
        layer.shadowOffset = CGSize(width: 0, height: 6)

        titleLabel.font = .systemFont(ofSize: 14, weight: .semibold)
        titleLabel.textColor = UIColor.white.withAlphaComponent(0.72)
        capacityLabel.font = .monospacedDigitSystemFont(ofSize: 26, weight: .bold)
        capacityLabel.textColor = .white
        detailLabel.font = .systemFont(ofSize: 12, weight: .medium)
        detailLabel.textColor = UIColor.white.withAlphaComponent(0.7)
        progressView.trackTintColor = UIColor.white.withAlphaComponent(0.18)
        progressView.progressTintColor = UIColor(red: 0.31, green: 0.72, blue: 1, alpha: 1)

        transferLabel.font = .systemFont(ofSize: 12, weight: .semibold)
        transferLabel.textColor = .white
        transferProgress.progressTintColor = UIColor(red: 0.24, green: 0.82, blue: 0.66, alpha: 1)
        transferProgress.trackTintColor = UIColor.white.withAlphaComponent(0.18)
        cancelButton.setTitle(NSLocalizedString("Cancel", comment: ""), for: .normal)
        cancelButton.setTitleColor(.systemRed, for: .normal)
        cancelButton.titleLabel?.font = .systemFont(ofSize: 12, weight: .bold)
        cancelButton.addTarget(self, action: #selector(cancelTapped), for: .touchUpInside)
        transferStack.axis = .horizontal
        transferStack.spacing = 10
        transferStack.alignment = .center
        transferStack.addArrangedSubview(transferLabel)
        transferStack.addArrangedSubview(transferProgress)
        transferStack.addArrangedSubview(cancelButton)
        transferProgress.widthAnchor.constraint(greaterThanOrEqualToConstant: 80).isActive = true
        transferStack.isHidden = true

        let stack = UIStackView(arrangedSubviews: [titleLabel, capacityLabel, progressView, detailLabel, transferStack])
        stack.axis = .vertical
        stack.spacing = 7
        stack.translatesAutoresizingMaskIntoConstraints = false
        addSubview(stack)
        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 20),
            stack.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -20),
            stack.centerYAnchor.constraint(equalTo: centerYAnchor)
        ])
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    func showLoading(supported: Bool) {
        titleLabel.text = supported ? NSLocalizedString("External storage", comment: "") : NSLocalizedString("External storage not reported", comment: "")
        capacityLabel.text = "—"
        detailLabel.text = NSLocalizedString("Reading storage information…", comment: "")
        progressView.progress = 0
    }

    func update(with info: FitCloudStorageInfoModel) {
        titleLabel.text = info.storageType.rawValue == 1 ? NSLocalizedString("SD card", comment: "") : NSLocalizedString("Flash storage", comment: "")
        let used = max(0, info.totalSpace - info.remainingSpace)
        capacityLabel.text = "\(Self.bytes(used)) / \(Self.bytes(info.totalSpace))"
        progressView.progress = info.totalSpace > 0 ? Float(used) / Float(info.totalSpace) : 0
        detailLabel.text = String(format: NSLocalizedString("%@ available · %d songs · %d recordings", comment: ""), Self.bytes(info.remainingSpace), info.songCount, info.recordingCount)
    }

    func showError(_ message: String) {
        capacityLabel.text = "—"
        detailLabel.text = message
        progressView.progress = 0
    }

    func showTransfer(message: String, progress: CGFloat, cancel: (() -> Void)?) {
        transferLabel.text = message
        transferProgress.progress = Float(progress)
        cancelAction = cancel
        cancelButton.isHidden = cancel == nil
        transferStack.isHidden = false
    }

    func hideTransfer() {
        transferStack.isHidden = true
        cancelAction = nil
    }

    @objc private func cancelTapped() { cancelAction?() }

    private static func bytes(_ value: Int) -> String {
        ByteCountFormatter.string(fromByteCount: Int64(value), countStyle: .file)
    }
}
