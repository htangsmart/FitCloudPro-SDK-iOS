import UIKit
import MapKit
import CoreLocation
import FitCloudKit

/// Device authorization → download/package → Bluetooth transfer.
@objc final class OfflineMapsDemoController: UIViewController {
    private enum Phase { case idle, downloading, cancelling, sending }
    private var phase: Phase = .idle { didSet { updateControls() } }
    private var operation: (any FitCloudCancellable)?
    private var archiveURL: URL?
    private var archiveDeviceUUID: UUID?
    private var previousPopGestureEnabled = true

    private let locationManager = CLLocationManager()
    private var locationPending = false
    private var locationInFlight = false
    private var locationTimeout: DispatchWorkItem?
    private let locationHint = UILabel()
    private let longitudeField = UITextField()
    private let latitudeField = UITextField()
    private let radiusField = UITextField()
    private let statusLabel = UILabel()
    private let downloadActivity = UIActivityIndicatorView(style: .medium)
    private let downloadProgress = UIProgressView(progressViewStyle: .default)
    private let sendProgress = UIProgressView(progressViewStyle: .default)
    private let backButton = UIButton(type: .system)
    private let startButton = UIButton(type: .system)
    private let retryButton = UIButton(type: .system)
    private let cancelButton = UIButton(type: .system)
    private let mapButton = UIButton(type: .system)
    private let manageMapsButton = UIButton(type: .system)

    private let accent = UIColor.label
    private let actionForeground = UIColor.systemBackground
    private let scroll = UIScrollView()
    private let content = UIStackView()
    private var tabletScrollHeight: NSLayoutConstraint?
    private let radiusStepper = UIStepper()
    private let downloadValue = UILabel()
    private let sendValue = UILabel()
    private let statusIcon = UIImageView()

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor { UIColor(white: $0.userInterfaceStyle == .dark ? 0.06 : 0.96, alpha: 1) }
        view.tintColor = accent
        scroll.keyboardDismissMode = .interactive
        scroll.alwaysBounceVertical = true

        content.axis = .vertical
        content.spacing = 18
        let footer = UIStackView()
        footer.axis = .vertical
        footer.spacing = 4
        [scroll, footer].forEach {
            $0.translatesAutoresizingMaskIntoConstraints = false
            view.addSubview($0)
        }
        content.translatesAutoresizingMaskIntoConstraints = false
        scroll.addSubview(content)
        NSLayoutConstraint.activate([
            scroll.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            scroll.bottomAnchor.constraint(equalTo: footer.topAnchor, constant: -12),
            scroll.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            scroll.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            content.topAnchor.constraint(equalTo: scroll.contentLayoutGuide.topAnchor, constant: 8),
            content.bottomAnchor.constraint(equalTo: scroll.contentLayoutGuide.bottomAnchor, constant: -12),
            content.centerXAnchor.constraint(equalTo: scroll.centerXAnchor),
            content.leadingAnchor.constraint(greaterThanOrEqualTo: scroll.frameLayoutGuide.leadingAnchor, constant: 20),
            content.widthAnchor.constraint(lessThanOrEqualToConstant: 640),
            // Explicit content width gives the scroll view an unambiguous horizontal content size.
            scroll.contentLayoutGuide.widthAnchor.constraint(equalTo: scroll.frameLayoutGuide.widthAnchor),
            footer.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            footer.widthAnchor.constraint(equalTo: content.widthAnchor),
            footer.bottomAnchor.constraint(lessThanOrEqualTo: view.safeAreaLayoutGuide.bottomAnchor, constant: -12)
        ])
        let footerBottom = footer.bottomAnchor.constraint(equalTo: view.safeAreaLayoutGuide.bottomAnchor, constant: -12)
        if traitCollection.userInterfaceIdiom == .pad {
            footerBottom.priority = .defaultLow
            let naturalHeight = scroll.heightAnchor.constraint(equalToConstant: 800)
            naturalHeight.priority = .defaultHigh
            naturalHeight.isActive = true
            tabletScrollHeight = naturalHeight
        }
        footerBottom.isActive = true
        let preferredWidth = content.widthAnchor.constraint(equalTo: scroll.frameLayoutGuide.widthAnchor, constant: -40)
        preferredWidth.priority = .defaultHigh
        preferredWidth.isActive = true

        configure(backButton, title: "Back", action: #selector(goBack))
        backButton.setImage(UIImage(systemName: "chevron.left"), for: .normal)
        backButton.contentHorizontalAlignment = .leading
        let help = UIButton(type: .system)
        help.setImage(UIImage(systemName: "info.circle"), for: .normal)
        help.accessibilityLabel = text("Map download guide")
        help.widthAnchor.constraint(equalToConstant: 44).isActive = true
        help.addTarget(self, action: #selector(showGuide), for: .touchUpInside)
        content.addArrangedSubview(UIStackView(arrangedSubviews: [backButton, UIView(), help]))
        content.setCustomSpacing(12, after: content.arrangedSubviews.last!)

        let heading = label("Offline Maps")
        heading.font = UIFontMetrics(forTextStyle: .largeTitle).scaledFont(for: .systemFont(ofSize: 30, weight: .bold))
        let subtitle = label("Take your next route offline.")
        subtitle.textColor = .secondaryLabel
        let titles = vertical([heading, subtitle], spacing: 6)
        let emblem = UIImageView(image: UIImage(systemName: "map.fill"))
        emblem.tintColor = accent
        emblem.contentMode = .center
        emblem.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 25, weight: .medium)
        emblem.backgroundColor = .tertiarySystemFill
        emblem.layer.cornerRadius = 18
        NSLayoutConstraint.activate([emblem.widthAnchor.constraint(equalToConstant: 60), emblem.heightAnchor.constraint(equalToConstant: 60)])
        let hero = UIStackView(arrangedSubviews: [titles, emblem])
        hero.spacing = 16
        hero.alignment = .center
        content.addArrangedSubview(hero)
        configure(manageMapsButton, title: "Manage watch maps", action: #selector(manageWatchMaps))
        manageMapsButton.setImage(UIImage(systemName: "map"), for: .normal)
        manageMapsButton.contentHorizontalAlignment = .leading
        content.addArrangedSubview(manageMapsButton)

        let params = vertical([], spacing: 12)
        configure(mapButton, title: "Choose on map", action: #selector(chooseOnMap))
        mapButton.setImage(UIImage(systemName: "map"), for: .normal)
        mapButton.titleLabel?.font = .preferredFont(forTextStyle: .subheadline)
        mapButton.setContentHuggingPriority(.required, for: .horizontal)
        let regionHeader = UIStackView(arrangedSubviews: [sectionTitle("Map region", symbol: "mappin.and.ellipse"), mapButton])
        regionHeader.spacing = 12
        params.addArrangedSubview(regionHeader)
        let coordinates = UIStackView(arrangedSubviews: [
            input(longitudeField, title: "Longitude", value: ""),
            input(latitudeField, title: "Latitude", value: "")
        ])
        coordinates.spacing = 12
        coordinates.distribution = .fillEqually
        params.addArrangedSubview(coordinates)
        params.addArrangedSubview(divider())
        let radius = input(radiusField, title: "Coverage radius", value: "3", suffix: "km")
        radiusStepper.minimumValue = 2
        radiusStepper.maximumValue = 25
        radiusStepper.value = 3
        radiusStepper.addTarget(self, action: #selector(changeRadius), for: .valueChanged)
        radiusField.addTarget(self, action: #selector(syncRadius), for: .editingChanged)
        let radiusRow = UIStackView(arrangedSubviews: [radius, radiusStepper])
        radiusRow.spacing = 20
        radiusRow.alignment = .bottom
        params.addArrangedSubview(radiusRow)
        let limit = label("Choose a radius between 2 and 25 km.")
        limit.font = .preferredFont(forTextStyle: .caption1)
        limit.textColor = .secondaryLabel
        params.addArrangedSubview(limit)
        params.setCustomSpacing(6, after: radiusRow)
        params.addArrangedSubview(divider())
        let note = locationHint
        note.numberOfLines = 0
        note.text = text("Locating your current position…")
        note.font = .preferredFont(forTextStyle: .caption1)
        note.textColor = .secondaryLabel
        params.addArrangedSubview(note)
        content.addArrangedSubview(card(params))

        let transfer = vertical([], spacing: 14)
        downloadActivity.hidesWhenStopped = true
        let transferHeader = UIStackView(arrangedSubviews: [sectionTitle("Transfer progress", symbol: "arrow.down.circle"), downloadActivity])
        transferHeader.spacing = 12
        transfer.addArrangedSubview(transferHeader)
        transfer.addArrangedSubview(progressRow("Download and package", number: "1", bar: downloadProgress, value: downloadValue))
        transfer.addArrangedSubview(progressRow("Send to watch", number: "2", bar: sendProgress, value: sendValue))
        transfer.addArrangedSubview(divider())
        statusLabel.numberOfLines = 0
        statusLabel.font = .preferredFont(forTextStyle: .footnote)
        statusLabel.adjustsFontForContentSizeCategory = true
        statusLabel.textColor = .secondaryLabel
        statusLabel.accessibilityIdentifier = "offlineMapsStatus"
        statusLabel.text = text("Ready to download. Sending starts automatically after download.")
        statusIcon.image = UIImage(systemName: "info.circle.fill")
        statusIcon.tintColor = accent
        statusIcon.contentMode = .scaleAspectFit
        NSLayoutConstraint.activate([statusIcon.widthAnchor.constraint(equalToConstant: 18), statusIcon.heightAnchor.constraint(equalToConstant: 20)])
        let status = UIStackView(arrangedSubviews: [statusIcon, statusLabel])
        status.spacing = 10
        status.alignment = .top
        transfer.addArrangedSubview(status)
        content.addArrangedSubview(card(transfer))

        configure(startButton, title: "Download and send to watch", action: #selector(start))
        startButton.backgroundColor = .label
        startButton.setTitleColor(actionForeground, for: .normal)
        startButton.setTitleColor(actionForeground.withAlphaComponent(0.7), for: .disabled)
        startButton.layer.cornerRadius = 16
        startButton.contentEdgeInsets = UIEdgeInsets(top: 16, left: 16, bottom: 16, right: 16)
        startButton.titleLabel?.textAlignment = .center
        startButton.titleLabel?.font = .preferredFont(forTextStyle: .headline)
        configure(cancelButton, title: "Cancel download", action: #selector(cancelDownload))
        configure(retryButton, title: "Retry sending downloaded map", action: #selector(retrySend))
        [startButton, retryButton, cancelButton].forEach { footer.addArrangedSubview($0) }
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardChanged(_:)), name: UIResponder.keyboardWillChangeFrameNotification, object: nil)
        updateControls()
        [longitudeField, latitudeField].forEach {
            $0.placeholder = text("Current location")
            $0.addTarget(self, action: #selector(coordinatesEdited), for: .editingChanged)
        }
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyHundredMeters
        locationPending = true
        resolveLocationAuthorization()
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        if let height = tabletScrollHeight, content.bounds.width > 0 {
            let fitting = content.systemLayoutSizeFitting(
                CGSize(width: content.bounds.width, height: 0),
                withHorizontalFittingPriority: .required, verticalFittingPriority: .fittingSizeLevel)
            if abs(height.constant - fitting.height - 20) > 1 { height.constant = fitting.height + 20 }
        }
    }

    private func vertical(_ views: [UIView], spacing: CGFloat) -> UIStackView {
        let stack = UIStackView(arrangedSubviews: views)
        stack.axis = .vertical
        stack.spacing = spacing
        return stack
    }

    private func card(_ content: UIStackView) -> UIView {
        content.isLayoutMarginsRelativeArrangement = true
        content.directionalLayoutMargins = NSDirectionalEdgeInsets(top: 16, leading: 16, bottom: 16, trailing: 16)
        let container = UIView()
        container.backgroundColor = UIColor { UIColor(white: $0.userInterfaceStyle == .dark ? 0.12 : 1, alpha: 1) }
        container.layer.cornerRadius = 22
        container.layer.cornerCurve = .continuous
        container.addSubview(content)
        content.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            content.topAnchor.constraint(equalTo: container.topAnchor), content.bottomAnchor.constraint(equalTo: container.bottomAnchor),
            content.leadingAnchor.constraint(equalTo: container.leadingAnchor), content.trailingAnchor.constraint(equalTo: container.trailingAnchor)
        ])
        return container
    }

    private func sectionTitle(_ title: String, symbol: String) -> UIView {
        let icon = UIImageView(image: UIImage(systemName: symbol))
        icon.tintColor = accent
        icon.contentMode = .scaleAspectFit
        icon.widthAnchor.constraint(equalToConstant: 20).isActive = true
        let title = label(title)
        title.font = .preferredFont(forTextStyle: .headline)
        let row = UIStackView(arrangedSubviews: [icon, title])
        row.spacing = 10
        return row
    }

    private func divider() -> UIView {
        let line = UIView()
        line.backgroundColor = .separator
        line.heightAnchor.constraint(equalToConstant: 1 / UIScreen.main.scale).isActive = true
        return line
    }

    private func input(_ field: UITextField, title: String, value: String, suffix: String? = nil, showTitle: Bool = true) -> UIView {
        let caption = label(title)
        caption.font = .preferredFont(forTextStyle: .footnote)
        caption.textColor = .secondaryLabel
        field.text = value
        field.font = UIFontMetrics(forTextStyle: .title3).scaledFont(for: .monospacedDigitSystemFont(ofSize: 20, weight: .medium))
        field.adjustsFontForContentSizeCategory = true
        field.borderStyle = .none
        field.backgroundColor = UIColor { UIColor(white: $0.userInterfaceStyle == .dark ? 0.18 : 0.96, alpha: 1) }
        field.layer.cornerRadius = 10
        field.accessibilityLabel = text(title)
        field.autocorrectionType = .no
        field.autocapitalizationType = .none
        field.keyboardType = .numbersAndPunctuation
        field.leftView = UIView(frame: CGRect(x: 0, y: 0, width: 12, height: 1))
        field.leftViewMode = .always
        if let suffix = suffix {
            let unit = UILabel(frame: CGRect(x: 0, y: 0, width: 36, height: 30))
            unit.text = suffix
            unit.font = .preferredFont(forTextStyle: .footnote)
            unit.textColor = .secondaryLabel
            field.rightView = unit
            field.rightViewMode = .always
        }
        field.heightAnchor.constraint(greaterThanOrEqualToConstant: 48).isActive = true
        let toolbar = UIToolbar()
        toolbar.sizeToFit()
        toolbar.items = [UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil),
                         UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(dismissKeyboard))]
        field.inputAccessoryView = toolbar
        return showTitle ? vertical([caption, field], spacing: 8) : field
    }

    private func progressRow(_ title: String, number: String, bar: UIProgressView, value: UILabel) -> UIView {
        let badge = UILabel()
        badge.text = number
        badge.textAlignment = .center
        badge.font = .monospacedDigitSystemFont(ofSize: 13, weight: .semibold)
        badge.textColor = accent
        badge.backgroundColor = .tertiarySystemFill
        badge.layer.cornerRadius = 14
        badge.clipsToBounds = true
        NSLayoutConstraint.activate([badge.widthAnchor.constraint(equalToConstant: 28), badge.heightAnchor.constraint(equalToConstant: 28)])
        let caption = label(title)
        value.font = .monospacedDigitSystemFont(ofSize: 13, weight: .medium)
        value.textColor = .secondaryLabel
        value.setContentHuggingPriority(.required, for: .horizontal)
        value.setContentCompressionResistancePriority(.required, for: .horizontal)
        let heading = UIStackView(arrangedSubviews: [caption, value])
        heading.spacing = 8
        bar.progressTintColor = accent
        bar.trackTintColor = .tertiarySystemFill
        bar.heightAnchor.constraint(equalToConstant: 4).isActive = true
        let row = UIStackView(arrangedSubviews: [badge, vertical([heading, bar], spacing: 10)])
        row.alignment = .center
        row.spacing = 12
        return row
    }

    private func stopDefaultLocation() {
        locationPending = false
        locationInFlight = false
        locationTimeout?.cancel()
        locationTimeout = nil
        locationManager.stopUpdatingLocation()
    }

    @objc private func coordinatesEdited() {
        stopDefaultLocation()
        locationHint.text = text("Using manually entered coordinates.")
    }

    private func locationFailed(_ message: String) {
        stopDefaultLocation()
        locationHint.text = text(message)
    }

    private func resolveLocationAuthorization() {
        guard locationPending, !locationInFlight else { return }
        switch CLLocationManager.authorizationStatus() {
        case .notDetermined:
            locationManager.requestWhenInUseAuthorization()
        case .authorizedWhenInUse, .authorizedAlways:
            locationInFlight = true
            locationManager.requestLocation()
            let timeout = DispatchWorkItem { [weak self] in
                guard let self = self, self.locationPending else { return }
                self.locationFailed("Unable to obtain your location. Enter coordinates or choose on the map.")
            }
            locationTimeout = timeout
            DispatchQueue.main.asyncAfter(deadline: .now() + 20, execute: timeout)
        case .denied, .restricted:
            locationFailed("Location access is unavailable. Enter coordinates or choose on the map, or enable location access in Settings.")
        @unknown default:
            locationFailed("Unable to obtain your location. Enter coordinates or choose on the map.")
        }
    }

    @objc private func manageWatchMaps() {
        guard phase == .idle else { return }
        view.endEditing(true)
        // Each presentation reads a fresh device list, including newly transferred maps.
        let navigation = UINavigationController(rootViewController: OfflineMapsManagerController())
        navigation.modalPresentationStyle = traitCollection.userInterfaceIdiom == .pad ? .formSheet : .fullScreen
        navigation.preferredContentSize = CGSize(width: 640, height: 760)
        present(navigation, animated: true)
    }

    @objc private func chooseOnMap() {
        guard phase == .idle else { return }
        view.endEditing(true)
        stopDefaultLocation()
        locationHint.text = text("Enter coordinates or choose a point on the map.")
        var center: CLLocationCoordinate2D?
        if let longitude = Double(longitudeField.text ?? ""), let latitude = Double(latitudeField.text ?? "") {
            let candidate = CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
            if CLLocationCoordinate2DIsValid(candidate) { center = candidate }
        }
        let radius = Double(radiusField.text ?? "") ?? 3
        let picker = OfflineMapPointPicker(center: center, radius: radius.isFinite ? min(25, max(2, radius)) : 3)
        picker.onSelect = { [weak self] coordinate in
            self?.locationHint.text = self?.text("Location selected on map. You can still edit the coordinates.")
            // Keep decimal points independent of the user's locale, matching Double parsing below.
            self?.longitudeField.text = String(format: "%.6f", locale: Locale(identifier: "en_US_POSIX"), coordinate.longitude)
            self?.latitudeField.text = String(format: "%.6f", locale: Locale(identifier: "en_US_POSIX"), coordinate.latitude)
        }
        let navigation = UINavigationController(rootViewController: picker)
        navigation.modalPresentationStyle = traitCollection.userInterfaceIdiom == .pad ? .formSheet : .fullScreen
        navigation.preferredContentSize = CGSize(width: 760, height: 900)
        present(navigation, animated: true)
    }

    @objc private func changeRadius() { radiusField.text = String(Int(radiusStepper.value)) }
    @objc private func syncRadius() {
        if let value = Double(radiusField.text ?? ""), value.isFinite { radiusStepper.value = min(25, max(2, value)) }
    }
    @objc private func dismissKeyboard() { view.endEditing(true) }
    @objc private func keyboardChanged(_ notification: Notification) {
        guard let frame = notification.userInfo?[UIResponder.keyboardFrameEndUserInfoKey] as? CGRect else { return }
        let overlap = scroll.frame.intersection(view.convert(frame, from: nil)).height
        scroll.contentInset.bottom = overlap > 0 ? overlap + 16 : 0
        scroll.verticalScrollIndicatorInsets.bottom = scroll.contentInset.bottom
        if let field = [longitudeField, latitudeField, radiusField].first(where: { $0.isFirstResponder }) {
            scroll.scrollRectToVisible(field.convert(field.bounds, to: scroll).insetBy(dx: 0, dy: -20), animated: true)
        }
    }
    @objc private func showGuide() {
        let message = text("Connect and initialize a supported watch first. Coordinates must use the map provider's coordinate system; no conversion is performed.") + "\n\n" + text("The SDK obtains map authorization, area and detail levels from the watch automatically.")
        let alert = UIAlertController(title: text("Map download guide"), message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: text("Got it"), style: .default))
        present(alert, animated: true)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        previousPopGestureEnabled = navigationController?.interactivePopGestureRecognizer?.isEnabled ?? true
        updateControls()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        navigationController?.interactivePopGestureRecognizer?.isEnabled = previousPopGestureEnabled
    }

    deinit {
        locationTimeout?.cancel()
        locationManager.stopUpdatingLocation()
        operation?.cancel()
        if let url = archiveURL { try? FileManager.default.removeItem(at: url) }
    }

    private func text(_ key: String) -> String { NSLocalizedString(key, comment: "Offline maps demo") }

    private func label(_ key: String) -> UILabel {
        let label = UILabel()
        label.text = text(key)
        label.numberOfLines = 0
        label.font = .preferredFont(forTextStyle: .subheadline)
        label.adjustsFontForContentSizeCategory = true
        return label
    }

    private func configure(_ button: UIButton, title: String, action: Selector) {
        button.setTitle(text(title), for: .normal)
        button.titleLabel?.numberOfLines = 0
        button.heightAnchor.constraint(greaterThanOrEqualToConstant: 44).isActive = true
        button.addTarget(self, action: action, for: .touchUpInside)
    }

    private func updateControls() {
        let idle = phase == .idle
        [longitudeField, latitudeField, radiusField].forEach { $0.isEnabled = idle }
        mapButton.isEnabled = idle
        manageMapsButton.isEnabled = idle
        radiusStepper.isEnabled = idle
        switch phase {
        case .idle:
            startButton.setTitle(text("Download and send to watch"), for: .normal)
            downloadActivity.stopAnimating()
        case .downloading:
            startButton.setTitle(text("Authorizing and downloading…"), for: .normal)
            downloadActivity.startAnimating()
        case .cancelling:
            startButton.setTitle(text("Cancelling download…"), for: .normal)
            downloadActivity.startAnimating()
        case .sending:
            startButton.setTitle(text("Sending to watch…"), for: .normal)
            downloadActivity.startAnimating()
        }
        startButton.isEnabled = idle
        startButton.alpha = idle ? 1 : 0.65
        retryButton.isHidden = !(idle && archiveURL != nil)
        cancelButton.isHidden = phase != .downloading && phase != .cancelling
        downloadValue.text = String(format: "%.0f%%", downloadProgress.progress * 100)
        sendValue.text = String(format: "%.0f%%", sendProgress.progress * 100)
        retryButton.isEnabled = idle && archiveURL != nil
        cancelButton.isEnabled = phase == .downloading
        backButton.isEnabled = idle
        navigationController?.interactivePopGestureRecognizer?.isEnabled = idle && previousPopGestureEnabled
        isModalInPresentation = !idle
    }

    private func fail(_ message: String, error: Error? = nil) {
        statusLabel.text = text(message) + (error.map { "\n\($0.localizedDescription)" } ?? "")
        phase = .idle
        statusIcon.image = UIImage(systemName: "exclamationmark.circle.fill")
        statusIcon.tintColor = .systemOrange
    }

    private func ready() -> Bool {
        guard FitCloudKit.isConnected(), FitCloudKit.isDeviceReady() else {
            fail("Connect and initialize the watch before continuing.")
            return false
        }
        return true
    }

    @objc private func start() {
        guard phase == .idle, ready() else { return }
        view.endEditing(true)
        let trim: (UITextField) -> String = { ($0.text ?? "").trimmingCharacters(in: .whitespacesAndNewlines) }
        guard let longitude = Double(trim(longitudeField)), longitude.isFinite, (-180...180).contains(longitude),
              let latitude = Double(trim(latitudeField)), latitude.isFinite, (-90...90).contains(latitude),
              let radius = UInt(trim(radiusField)), (2...25).contains(radius) else {
            fail("Enter valid coordinates and an integer radius from 2 to 25 km.")
            return
        }
        guard let uuid = FitCloudKit.lastConnectPeripheral()?.uuid else {
            fail("Unable to identify the connected watch. Reconnect and try again.")
            return
        }
        stopDefaultLocation()
        guard removeArchive() else { return }
        archiveDeviceUUID = uuid
        downloadProgress.progress = 0
        sendProgress.progress = 0
        statusIcon.image = UIImage(systemName: "info.circle.fill")
        statusIcon.tintColor = accent
        phase = .downloading
        statusLabel.text = text("Authorizing and downloading map. If authorization times out or is cancelled, reconnect the watch before retrying.")
        // FitCloudKit obtains authorization and discovers the optional plugin automatically.
        operation = FitCloudKit.downloadOfflineMaps(
            withLongitude: longitude, latitude: latitude, radius: radius,
            progress: { progress in
                self.downloadProgress.progress = Float(progress)
                self.downloadValue.text = String(format: "%.0f%%", progress * 100)
                if self.phase == .downloading {
                    self.statusLabel.text = self.text("Downloading and packaging map…") + String(format: " %.0f%%", progress * 100)
                }
            }, completion: { url, error in
                // Defer completion handling so even an immediate SDK failure cannot leave
                // a finished cancellation handle assigned after the callback clears it.
                DispatchQueue.main.async { self.finishDownload(url: url, error: error) }
            })
    }

    private func finishDownload(url: URL?, error: Error?) {
        operation = nil
        let nsError = error as NSError?
        let cancelled = phase == .cancelling ||
            (nsError?.domain == NSURLErrorDomain && nsError?.code == NSURLErrorCancelled)
        if cancelled || error != nil || url == nil {
            // Only successful archives may be offered for Bluetooth retry.
            archiveURL = url
            guard removeArchive() else { return }
            if cancelled {
                fail("Download cancelled. If cancelled during authorization, reconnect the watch before retrying.")
                statusIcon.image = UIImage(systemName: "info.circle.fill")
                statusIcon.tintColor = accent
            } else {
                fail("Map download failed. If authorization timed out, reconnect the watch before retrying.", error: error)
            }
            return
        }
        archiveURL = url
        downloadProgress.progress = 1
        downloadValue.text = "100%"
        sendArchive()
    }

    @objc private func retrySend() {
        guard phase == .idle, archiveURL != nil else { return }
        sendArchive()
    }

    private func sendArchive() {
        guard ready() else { return }
        guard let uuid = archiveDeviceUUID, FitCloudKit.lastConnectPeripheral()?.uuid == uuid else {
            fail("The connected watch differs from the download authorization. Reconnect the original watch or download again.")
            return
        }
        guard let url = archiveURL, FileManager.default.isReadableFile(atPath: url.path) else {
            archiveURL = nil
            archiveDeviceUUID = nil
            fail("The temporary map file is missing. Download it again.")
            return
        }
        phase = .sending
        sendProgress.progress = 0
        statusLabel.text = text("Sending map to watch. Keep this page open and the watch connected…")
        // SDK callbacks may arrive off the main queue. Retain this controller until transfer completes.
        FitCloudKit.sendOfflineMapsFile(url.path, progress: { progress in
            DispatchQueue.main.async {
                self.sendProgress.progress = Float(progress)
                self.sendValue.text = String(format: "%.0f%%", progress * 100)
                self.statusLabel.text = self.text("Sending map to watch. Keep this page open and the watch connected…") + String(format: " %.0f%%", progress * 100)
            }
        }, completion: { success, _, error in
            DispatchQueue.main.async {
                guard success, error == nil else {
                    self.fail("Sending failed. Keep this page open and tap retry to reuse the downloaded map.", error: error)
                    return
                }
                self.sendProgress.progress = 1
                guard self.removeArchive() else { return }
                self.statusIcon.image = UIImage(systemName: "checkmark.circle.fill")
                self.statusIcon.tintColor = self.accent
                self.statusLabel.text = self.text("Map sent successfully. Temporary file removed.")
                self.phase = .idle
            }
        })
    }

    @discardableResult private func removeArchive() -> Bool {
        if let url = archiveURL, FileManager.default.fileExists(atPath: url.path) {
            do { try FileManager.default.removeItem(at: url) }
            catch {
                fail("Unable to remove the temporary map file.", error: error)
                return false
            }
        }
        archiveURL = nil
        archiveDeviceUUID = nil
        updateControls()
        return true
    }

    @objc private func cancelDownload() {
        guard phase == .downloading else { return }
        phase = .cancelling
        statusLabel.text = text("Cancelling download…")
        operation?.cancel()
    }

    @objc private func goBack() {
        guard phase == .idle else { return }
        guard removeArchive() else { return }
        stopDefaultLocation()
        navigationController?.popViewController(animated: true)
    }
}

/// MapKit coordinates are passed through unchanged; no location permission is required to select a point.
private final class OfflineMapPointPicker: UIViewController, MKMapViewDelegate, UISearchBarDelegate {
    var onSelect: ((CLLocationCoordinate2D) -> Void)?
    private let map = MKMapView()
    private let searchBar = UISearchBar()
    private let coordinateLabel = UILabel()
    private let confirmButton = UIButton(type: .system)
    private let initialCenter: CLLocationCoordinate2D?
    private let radius: Double
    private var coverage: MKCircle?
    private var search: MKLocalSearch?
    private var searchID = UUID()

    init(center: CLLocationCoordinate2D?, radius: Double) {
        initialCenter = center
        self.radius = radius
        super.init(nibName: nil, bundle: nil)
    }
    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }
    deinit { search?.cancel() }
    private func text(_ key: String) -> String { NSLocalizedString(key, comment: "Offline map point picker") }

    override func viewDidLoad() {
        super.viewDidLoad()
        title = text("Choose on map")
        view.backgroundColor = .systemBackground
        view.tintColor = .label
        navigationController?.navigationBar.tintColor = .label
        navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .cancel, target: self, action: #selector(close))
        searchBar.placeholder = text("Search a city or place")
        searchBar.searchBarStyle = .minimal
        searchBar.delegate = self
        map.delegate = self
        map.isRotateEnabled = false
        map.isPitchEnabled = false
        map.addGestureRecognizer(UILongPressGestureRecognizer(target: self, action: #selector(longPress(_:))))
        let pin = UIImageView(image: UIImage(systemName: "mappin"))
        pin.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 36, weight: .bold)
        pin.tintColor = .label
        pin.layer.shadowColor = UIColor.white.cgColor
        pin.layer.shadowOpacity = 1
        pin.layer.shadowRadius = 3
        pin.layer.shadowOffset = .zero
        pin.isUserInteractionEnabled = false
        pin.isAccessibilityElement = false

        let hint = UILabel()
        hint.text = text("Move the map or long-press to choose the center. The circle shows the download radius.")
        hint.font = .preferredFont(forTextStyle: .footnote)
        hint.textColor = .secondaryLabel
        hint.numberOfLines = 0
        hint.adjustsFontForContentSizeCategory = true
        coordinateLabel.font = .monospacedDigitSystemFont(ofSize: 16, weight: .medium)
        coordinateLabel.numberOfLines = 0
        coordinateLabel.accessibilityIdentifier = "selectedMapCoordinate"
        confirmButton.setTitle(text("Use this location"), for: .normal)
        confirmButton.backgroundColor = .label
        confirmButton.setTitleColor(.systemBackground, for: .normal)
        confirmButton.titleLabel?.font = .preferredFont(forTextStyle: .headline)
        confirmButton.layer.cornerRadius = 14
        confirmButton.heightAnchor.constraint(greaterThanOrEqualToConstant: 52).isActive = true
        confirmButton.addTarget(self, action: #selector(confirm), for: .touchUpInside)
        let panel = UIStackView(arrangedSubviews: [coordinateLabel, hint, confirmButton])
        panel.axis = .vertical
        panel.spacing = 12
        for child in [searchBar, map, panel] {
            child.translatesAutoresizingMaskIntoConstraints = false
            view.addSubview(child)
        }
        map.addSubview(pin)
        pin.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            searchBar.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            searchBar.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 12),
            searchBar.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -12),
            map.topAnchor.constraint(equalTo: searchBar.bottomAnchor, constant: 8),
            map.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            map.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            map.bottomAnchor.constraint(equalTo: panel.topAnchor, constant: -16),
            panel.leadingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.leadingAnchor, constant: 20),
            panel.trailingAnchor.constraint(equalTo: view.safeAreaLayoutGuide.trailingAnchor, constant: -20),
            panel.bottomAnchor.constraint(equalTo: view.safeAreaLayoutGuide.bottomAnchor, constant: -16),
            pin.centerXAnchor.constraint(equalTo: map.centerXAnchor),
            pin.bottomAnchor.constraint(equalTo: map.centerYAnchor)
        ])
        if let initialCenter = initialCenter {
            map.setRegion(MKCoordinateRegion(center: initialCenter, latitudinalMeters: radius * 3200, longitudinalMeters: radius * 3200), animated: false)
        } else {
            map.setVisibleMapRect(.world, animated: false)
        }
        updateSelection()
    }

    func mapView(_ mapView: MKMapView, regionWillChangeAnimated animated: Bool) {
        confirmButton.isEnabled = false
    }
    func mapView(_ mapView: MKMapView, regionDidChangeAnimated animated: Bool) { updateSelection() }
    private func updateSelection() {
        let center = map.centerCoordinate
        confirmButton.isEnabled = CLLocationCoordinate2DIsValid(center)
        coordinateLabel.text = String(format: "%.6f, %.6f", locale: Locale(identifier: "en_US_POSIX"), center.longitude, center.latitude)
        coordinateLabel.accessibilityLabel = text("Longitude") + ", " + text("Latitude")
        if let coverage = coverage { map.removeOverlay(coverage) }
        let circle = MKCircle(center: center, radius: radius * 1000)
        coverage = circle
        map.addOverlay(circle)
    }
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        guard let circle = overlay as? MKCircle else { return MKOverlayRenderer(overlay: overlay) }
        let renderer = MKCircleRenderer(circle: circle)
        renderer.strokeColor = .label
        renderer.fillColor = UIColor.label.withAlphaComponent(0.08)
        renderer.lineWidth = 1.5
        return renderer
    }
    @objc private func longPress(_ gesture: UILongPressGestureRecognizer) {
        guard gesture.state == .began else { return }
        view.endEditing(true)
        map.setCenter(map.convert(gesture.location(in: map), toCoordinateFrom: map), animated: true)
    }
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        let query = (searchBar.text ?? "").trimmingCharacters(in: .whitespacesAndNewlines)
        guard !query.isEmpty else { return }
        searchBar.resignFirstResponder()
        search?.cancel()
        let id = UUID()
        searchID = id
        let request = MKLocalSearch.Request()
        request.naturalLanguageQuery = query
        request.region = map.region
        let task = MKLocalSearch(request: request)
        search = task
        task.start { [weak self] response, error in
            DispatchQueue.main.async {
                guard let self = self, self.searchID == id else { return }
                self.search = nil
                guard let item = response?.mapItems.first else {
                    let alert = UIAlertController(title: self.text("Place not found"), message: error?.localizedDescription ?? self.text("Try another city or place name."), preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: self.text("Got it"), style: .default))
                    self.present(alert, animated: true)
                    return
                }
                self.map.setRegion(MKCoordinateRegion(center: item.placemark.coordinate, latitudinalMeters: self.radius * 3200, longitudinalMeters: self.radius * 3200), animated: true)
            }
        }
    }
    @objc private func close() {
        searchID = UUID()
        search?.cancel()
        dismiss(animated: true)
    }
    @objc private func confirm() {
        guard CLLocationCoordinate2DIsValid(map.centerCoordinate) else { return }
        searchID = UUID()
        search?.cancel()
        onSelect?(map.centerCoordinate)
        dismiss(animated: true)
    }
}


extension OfflineMapsDemoController: CLLocationManagerDelegate {
    func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        resolveLocationAuthorization()
    }

    // iOS 13 authorization callback.
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        resolveLocationAuthorization()
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard locationPending, phase == .idle else { return }
        guard let location = locations.last(where: {
            $0.horizontalAccuracy >= 0 && abs($0.timestamp.timeIntervalSinceNow) < 60 && CLLocationCoordinate2DIsValid($0.coordinate)
        }) else {
            locationFailed("Unable to obtain your location. Enter coordinates or choose on the map.")
            return
        }
        stopDefaultLocation()
        let locale = Locale(identifier: "en_US_POSIX")
        longitudeField.text = String(format: "%.6f", locale: locale, location.coordinate.longitude)
        latitudeField.text = String(format: "%.6f", locale: locale, location.coordinate.latitude)
        locationHint.text = text("Using your current location. You can still edit it or choose on the map.")
    }

    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        guard locationPending else { return }
        locationFailed("Unable to obtain your location. Enter coordinates or choose on the map.")
    }
}
