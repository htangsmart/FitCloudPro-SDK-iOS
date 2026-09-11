import UIKit
import FitCloudKit

/// Lists and manages files on the watch, independently of the phone's temporary download archive.
final class OfflineMapsManagerController: UITableViewController {
    private var files: [FitCloudFileInfoModel] = []
    private var listDeviceID: UUID?
    private var requestID: UUID?
    private let emptyLabel = UILabel()
    private let activity = UIActivityIndicatorView(style: .medium)
    private var disconnectObserver: NSObjectProtocol?
    private lazy var refreshButton = UIBarButtonItem(barButtonSystemItem: .refresh, target: self, action: #selector(refreshFiles))
    private lazy var deleteAllButton = UIBarButtonItem(title: text("Delete all watch maps"), style: .plain, target: self, action: #selector(confirmDeleteAll))

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
        navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        navigationItem.rightBarButtonItems = [refreshButton, UIBarButtonItem(customView: activity)]
        activity.hidesWhenStopped = true
        deleteAllButton.tintColor = .systemRed
        toolbarItems = [UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), deleteAllButton,
                        UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)]
        navigationController?.setToolbarHidden(false, animated: false)
        refreshControl = UIRefreshControl()
        refreshControl?.addTarget(self, action: #selector(refreshFiles), for: .valueChanged)
        emptyLabel.numberOfLines = 0
        emptyLabel.textAlignment = .center
        emptyLabel.font = .preferredFont(forTextStyle: .body)
        emptyLabel.adjustsFontForContentSizeCategory = true
        emptyLabel.textColor = .secondaryLabel
        tableView.backgroundView = emptyLabel
        disconnectObserver = NotificationCenter.default.addObserver(
            forName: NSNotification.Name(FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY), object: nil, queue: .main
        ) { [weak self] _ in
            guard let self = self else { return }
            self.requestID = nil
            self.files = []
            self.listDeviceID = nil
            self.emptyLabel.text = self.text("Watch disconnected. Reconnect and refresh the map list.")
            self.updateControls()
            self.tableView.reloadData()
        }
        refreshFiles()
    }

    private func updateControls() {
        let busy = requestID != nil
        refreshButton.isEnabled = !busy
        deleteAllButton.isEnabled = !busy && !files.isEmpty
        navigationItem.leftBarButtonItem?.isEnabled = !busy
        navigationController?.isModalInPresentation = busy
        if busy { activity.startAnimating() } else {
            activity.stopAnimating()
            refreshControl?.endRefreshing()
        }
        emptyLabel.isHidden = !files.isEmpty
    }

    private func connectedDevice() -> UUID? {
        guard FitCloudKit.isConnected(), FitCloudKit.isDeviceReady() else { return nil }
        return FitCloudKit.lastConnectPeripheral()?.uuid
    }

    private func begin(for deviceID: UUID) -> UUID? {
        guard requestID == nil else { return nil }
        guard connectedDevice() == deviceID else {
            files = []
            listDeviceID = nil
            emptyLabel.text = text("Watch changed or disconnected. Refresh the map list.")
            tableView.reloadData()
            updateControls()
            return nil
        }
        let id = UUID()
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
            updateControls()
            tableView.reloadData()
            return
        }
        files = []
        listDeviceID = nil
        emptyLabel.text = text("Reading watch maps…")
        tableView.reloadData()
        guard let id = begin(for: deviceID) else { return }
        FitCloudKit.fetchOfflineMapsFileList { [weak self] success, files, error in
            DispatchQueue.main.async {
                guard let self = self, self.finish(id, deviceID: deviceID) else { return }
                guard success, error == nil else {
                    self.emptyLabel.text = self.text("Unable to read watch maps. Tap refresh to retry.")
                    self.showError(error)
                    return
                }
                self.files = files ?? []
                self.listDeviceID = deviceID
                self.emptyLabel.text = self.text("No offline maps on this watch. Download and send a map first.")
                self.updateControls()
                self.tableView.reloadData()
            }
        }
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int { files.count }
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        files.isEmpty ? nil : String(format: text("%ld maps on watch"), files.count)
    }
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "map") ?? UITableViewCell(style: .subtitle, reuseIdentifier: "map")
        let file = files[indexPath.row]
        cell.textLabel?.text = file.fileName
        cell.textLabel?.numberOfLines = 0
        cell.textLabel?.font = .preferredFont(forTextStyle: .body)
        cell.textLabel?.adjustsFontForContentSizeCategory = true
        cell.detailTextLabel?.text = ByteCountFormatter.string(fromByteCount: Int64(file.fileSize), countStyle: .file)
        cell.detailTextLabel?.textColor = .secondaryLabel
        cell.imageView?.image = UIImage(systemName: "map")
        cell.imageView?.tintColor = .label
        cell.accessoryType = .disclosureIndicator
        return cell
    }
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        guard requestID == nil, files.indices.contains(indexPath.row), let deviceID = listDeviceID else { return }
        let fileName = files[indexPath.row].fileName
        guard let id = begin(for: deviceID) else { return }
        FitCloudKit.fetchOfflineMapsFileDetail(withName: fileName) { [weak self] success, detail, error in
            DispatchQueue.main.async {
                guard let self = self, self.finish(id, deviceID: deviceID) else { return }
                guard success, error == nil else { self.showError(error); return }
                guard let detail = detail else {
                    self.refreshFiles()
                    self.message(self.text("This map no longer exists on the watch."))
                    return
                }
                let body = "\(self.text("Size")): \(detail.fileSize) bytes\nCRC16: \(String(format: "%04X", detail.crc))\n\(self.text("Storage index")): \(detail.fileIndex)"
                let alert = UIAlertController(title: detail.fileName, message: body, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: self.text("Delete watch map"), style: .destructive) { [weak self] _ in
                    self?.confirmDelete(fileName: fileName, deviceID: deviceID)
                })
                alert.addAction(UIAlertAction(title: self.text("Got it"), style: .cancel))
                self.present(alert, animated: true)
            }
        }
    }

    private func confirmDelete(fileName: String, deviceID: UUID) {
        let alert = UIAlertController(title: text("Delete this map from the watch?"), message: fileName, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("Cancel"), style: .cancel))
        alert.addAction(UIAlertAction(title: text("Delete watch map"), style: .destructive) { [weak self] _ in
            guard let self = self, let id = self.begin(for: deviceID) else { return }
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
            guard let self = self, let id = self.begin(for: deviceID) else { return }
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
        message(error?.localizedDescription ?? text("Watch map operation failed. Please try again."))
    }
    private func message(_ message: String) {
        let alert = UIAlertController(title: text("Watch maps"), message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("Got it"), style: .default))
        present(alert, animated: true)
    }
    @objc private func close() {
        guard requestID == nil else { return }
        dismiss(animated: true)
    }
}
