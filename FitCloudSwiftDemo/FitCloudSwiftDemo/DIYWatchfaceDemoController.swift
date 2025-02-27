//
//  DIYWatchfaceDemoController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import UIKit
import FitCloudKit
import FitCloudDFUKit
import FitCloudWFKit

class DIYWatchfaceDemoController: UIViewController {

    /// Label to display upload progress
    @IBOutlet weak var labelUploadProgress: UILabel!
    /// Label to display status tips
    @IBOutlet weak var labelTips: UILabel!
    /// Button to trigger upload action
    @IBOutlet weak var btnUpload: UIButton!
    /// ImageView to display selected photo
    @IBOutlet weak var photoView: UIImageView!
    
    /// Selected DIY photo for watchface customization
    var selectedDIYPhoto: UIImage?
    
    /// Clean up when view controller is deallocated
    deinit {
        if FitCloudKit.isCurrentDFUMode() {
            FitCloudKit.exitDFUMode()
        }
    }
    
    /// View lifecycle method - called when view loads
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        FitCloudDFUKit.setDelegate(self)
        setupControls()
        registerNotifications()
    }
    
    /// Initialize and setup UI controls
    func setupControls() {
        self.labelUploadProgress.text = ""
        self.labelTips.text = ""
        self.photoView.image = UIImage(named: "test_360_bg")!
        updateButtonForStarting()
    }
    
    /// Register for DFU mode reconnection notifications
    private func registerNotifications() {
        NotificationCenter.default.addObserver(forName: .init(FITCLOUDEVENT_PERIPHERAL_RECONNECTEDWITHDFUMODE_NOTIFY),
                                            object: nil,
                                            queue: .main) { [weak self] _ in
            XLOG_INFO("Device connected in DFU mode")
            FitCloudKit.exitDFUMode()
            DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                self?.setupControls()
            }
        }
    }
    
    /// Displays tips message with optional error styling
    /// - Parameters:
    ///   - tips: The message to display
    ///   - isError: Whether to style as error (red) or normal (black)
    private func showTips(_ tips: String, _ isError: Bool = false) {
        labelTips.textColor = isError ? .red : .black
        labelTips.text = tips
    }
    
    /// Updates button state to initial starting state
    private func updateButtonForStarting() {
        btnUpload.setTitle(NSLocalizedString("Starting DIY and upload", comment: "Starting DIY and upload"), for: .normal)
        btnUpload.isUserInteractionEnabled = true
        btnUpload.alpha = 1.0
    }
    
    /// Updates button state when DIY process begins
    private func updateButtonForBeginDIY() {
        btnUpload.setTitle(NSLocalizedString("DIY the watchface in progress", comment: "DIY the watchface in progress"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    /// Updates button state when DIY process succeeds
    private func updateButtonForDIYSuccess() {
        btnUpload.setTitle(NSLocalizedString("DIY the watchface success", comment: "DIY the watchface success"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    /// Updates button state when DIY process fails
    private func updateButtonForDIYFailed() {
        btnUpload.setTitle(NSLocalizedString("DIY the watchface failed", comment: "DIY the watchface failed"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    /// Updates button state during upgrade process
    private func updateButtonForUpgrading() {
        btnUpload.setTitle(NSLocalizedString("Upload the watchface in progress", comment: "Upload the watchface in progress"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    /// Updates button state when upgrade succeeds
    private func updateButtonForUpgradeSuccess() {
        btnUpload.setTitle(NSLocalizedString("Upload the watchface success", comment: "Upload the watchface success"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    /// Updates button state when upgrade fails
    private func updateButtonForUpgradeFailed() {
        btnUpload.setTitle(NSLocalizedString("Upload the watchface failed", comment: "Upload the watchface failed"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    /// Handles the upload button click action
    /// - Parameter sender: The object that triggered the action
    @IBAction func onClickUploadButton(_ sender: Any) {
        
        /// Add a DIY watchface template file to your project, and replace the following code with your own watchface template file name.
        /// Using an incompatible watchface template file may cause the watch to malfunction.
        let template_filename = "--"  //3679a6588f34
        let line = #line
        let file = #file

        guard let path = Bundle.main.path(forResource: template_filename, ofType: "bin") else {
            let message = "Please check line \(line-1) of \(file), the DIY watchface template file should match the watch model."
            XLOG_ERROR(message)
            showTips(message, true)
            return
        }
        
        guard FileManager.default.fileExists(atPath: path) else {
            let message = "The DIY watchface template file not found at path: \(path)"
            XLOG_ERROR(message)
            showTips(message, true)
            return
        }

        guard let allConfig = FitCloudKit.allConfig(), let firmwareInfo = allConfig.firmware else {
            showTips("Device not ready", true)
            return
        }
        
        updateButtonForBeginDIY()
        
        let isNextGUI = firmwareInfo.isNewGUIArchitecture

        /// Prepare the watchface background image and preview image according to actual needs. Especially for the preview image,
        /// you need to compose an appropriate preview image based on the watchface shape, background, date/time image resources
        /// and their positions. The following example represents the composed effect, skipping the composition steps.
        /// You can directly use your watchface background and preview images.
        let bkImage = selectedDIYPhoto ?? UIImage(named: "test_360_bg")!
        let preview = selectedDIYPhoto ?? UIImage(named: "test_360_preview")!

        // Create DIY watchface with template binary file
        FitCloudWFKit.create(withTemplateBin: path, isNextGUI: isNextGUI, rewriteNextGUIWatchfaceNo: nil, bkImage: bkImage, bkCornerRadius: 0, preview: preview, dtPosition: .TOP) { progress, tips in
            // Handle DIY progress updates
            let message = "DIY watchface progress:\(progress), \(tips ?? "")"
            XLOG_INFO(message)
            DispatchQueue.main.async {  [weak self] in
                self?.showTips(message)
            }
        } logging: { level, message in
            // Handle logging messages with different severity levels
            guard let message = message else {
                return
            }
            switch level {
            case .INFO:
                XLOG_INFO(message)
            case .WARNING:
                XLOG_WARNING(message)
            case .ERROR:
                XLOG_ERROR(message)
            default:
                XLOG_DEBUG(message)
            }
        } completion: {  [weak self] success, resultFilePath, resultBKImage, resultPreview, error in
            // Handle DIY completion
            if !success {
                // Handle DIY failure
                XLOG_ERROR("DIY watchface failed: \(String(describing: error))")
                DispatchQueue.main.async {
                    self?.showTips("DIY watchface failed: \(String(describing: error))", true)
                    self?.updateButtonForDIYFailed()
                    DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                        self?.setupControls()
                    }
                }
                return
            }
            
            // Handle DIY success
            DispatchQueue.main.async { [weak self] in
                self?.showTips("DIY watchface success.")
                self?.updateButtonForDIYSuccess()
                self?.showTips("Uploading the DIY watchface to the watch device...")
                self?.updateButtonForUpgrading()
            }
            
            // Verify result file path exists
            guard let resultFilePath else {
                XLOG_ERROR("DIY watchface failed...")
                DispatchQueue.main.async {
                    self?.showTips("DIY watchface failed...", true)
                    self?.updateButtonForDIYFailed()
                    DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) { [weak self] in
                        self?.setupControls()
                    }
                }
                return
            }
            
            // Start appropriate upgrade process based on firmware
            if firmwareInfo.withNewOTA {
                self?.handleNewOTAUpgrade(resultFilePath)
            } else {
                self?.handleTraditionalDFUUpgrade(firmwareInfo, resultFilePath)
            }
        }
    }
    
    private func handleNewOTAUpgrade(_ path: String) {
        FitCloudKit.sendNewOTA(path) { [weak self] isStartSuccess, error in
            if !isStartSuccess {
                XLOG_ERROR("OTA initialization failed: \(String(describing: error))")
                DispatchQueue.main.async {
                    self?.showTips("OTA initialization failed: \(String(describing: error))", true)
                    self?.updateButtonForUpgradeFailed()
                    DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                        self?.setupControls()
                    }
                }
            }
        } progress: { [weak self] progress in
            XLOG_INFO("DFU progress: \(progress * 100)%")
            DispatchQueue.main.async {
                self?.labelUploadProgress.text = String(format: "%.1f%%", progress * 100)
            }
        } completion: { [weak self] success, speed, error in
            DispatchQueue.main.async {
                if success {
                    self?.showTips("OTA upgrade completed, speed: \(speed)KB/s")
                    self?.updateButtonForUpgradeSuccess()
                } else {
                    self?.showTips("OTA upgrade failed: \(String(describing: error))", true)
                    self?.updateButtonForUpgradeFailed()
                }
                DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                    self?.setupControls()
                }
            }
        }
    }
    
    private func handleTraditionalDFUUpgrade(_ firmwareInfo: FitCloudFirmwareVersionObject, _ path: String) {
        FitCloudKit.enterDFUMode { [weak self] succeeded, peripheral, vendor, error in
            guard succeeded, let peripheral = peripheral else {
                XLOG_ERROR("DFU mode entry failed: \(String(describing: error))")
                DispatchQueue.main.async {
                    self?.showTips("DFU mode entry failed: \(String(describing: error))", true)
                    self?.updateButtonForUpgradeFailed()
                    DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                        self?.setupControls()
                    }
                }
                return
            }
            
            let silentMode = true
            FitCloudDFUKit.start(with: peripheral,
                                firmware: path,
                                chipVendor: .REALTEK,
                                silentMode: silentMode)
        }
    }
    
    
    
    @IBAction func onChooseDIYPhoto(_ sender: Any) {
        // Create image picker controller
        let imagePickerController = UIImagePickerController()
        imagePickerController.sourceType = .photoLibrary
        imagePickerController.delegate = self
        imagePickerController.allowsEditing = true
        
        // Present image picker
        present(imagePickerController, animated: true)
    }
    
    @IBAction func onGoBack(_ sender: Any) {
        navigationController?.popViewController(animated: true)
    }
}


extension DIYWatchfaceDemoController: UIImagePickerControllerDelegate, UINavigationControllerDelegate {
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        // Get the edited image
        if let editedImage = info[.editedImage] as? UIImage {
            selectedDIYPhoto = editedImage
            self.photoView.image = editedImage
        } else if let originalImage = info[.originalImage] as? UIImage {
            selectedDIYPhoto = originalImage
            self.photoView.image = originalImage
        }
        // Close image picker
        picker.dismiss(animated: true)
    }
    
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        // Close image picker when user cancels
        picker.dismiss(animated: true)
    }
}

extension DIYWatchfaceDemoController: FitCloudDFUDelegate {
    
    func onStartDFUSuccess() {
        XLOG_INFO("DFU initialization successful")
        DispatchQueue.main.async { [weak self] in
            self?.showTips("DFU initialization successful")
        }
    }
    
    func onStartDFUFailureWithError(_ error: any Error) {
        XLOG_ERROR("DFU initialization failed: \(error)")
        DispatchQueue.main.async { [weak self] in
            self?.showTips("DFU initialization failed: \(error)", true)
            self?.updateButtonForUpgradeFailed()
            DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                self?.setupControls()
            }
        }
    }
    
    func onDFUProgress(_ progress: CGFloat, imageIndex index: Int, total: Int) {
        XLOG_INFO("DFU progress: \(progress)%")
        DispatchQueue.main.async { [weak self] in
            self?.labelUploadProgress.text = String(format: "%.1f%%", progress)
        }
    }
    
    func onAbortWithError(_ error: any Error) {
        XLOG_ERROR("DFU aborted: \(error)")
        DispatchQueue.main.async { [weak self] in
            self?.showTips("DFU aborted: \(error)", true)
            self?.updateButtonForUpgradeFailed()
            DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(5)) {
                self?.setupControls()
            }
        }
    }
    
    func onDFUFinish(withSpeed speed: CGFloat) {
        XLOG_INFO("DFU completed successfully")
        DispatchQueue.main.async { [weak self] in
            self?.showTips("DFU completed, awaiting device restart")
            self?.updateButtonForUpgradeSuccess()
        }
    }
    
    func onDFULogMessage(_ message: String, level: FCDFUKLogLevel) {
        switch level {
        case .logLevel_Info:
            XLOG_INFO(message)
        case .logLevel_Warning:
            XLOG_WARNING(message)
        case .logLevel_Error:
            XLOG_ERROR(message)
        default:
            XLOG_DEBUG(message)
        }
    }
}

