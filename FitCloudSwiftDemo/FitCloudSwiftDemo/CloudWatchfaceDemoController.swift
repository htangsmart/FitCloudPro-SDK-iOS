//
//  CloudWatchfaceDemoController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import UIKit
import FitCloudKit
import FitCloudDFUKit

class CloudWatchfaceDemoController: UIViewController {

    @IBOutlet weak var labelUploadProgress: UILabel!
    @IBOutlet weak var labelTips: UILabel!
    @IBOutlet weak var btnUpload: UIButton!
    
    deinit {
        if FitCloudKit.isCurrentDFUMode() {
            FitCloudKit.exitDFUMode()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        FitCloudDFUKit.setDelegate(self)
        setupControls()
        registerNotifications()
    }
    
    func setupControls() {
        self.labelUploadProgress.text = ""
        self.labelTips.text = ""
        updateButtonForStarting()
    }
    
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
    
    private func showTips(_ tips: String, _ isError: Bool = false) {
        labelTips.textColor = isError ? .red : .black
        labelTips.text = tips
    }
    
    private func updateButtonForStarting() {
        btnUpload.setTitle(NSLocalizedString("Starting upload the watchface", comment: "Starting upload the watchface"), for: .normal)
        btnUpload.isUserInteractionEnabled = true
        btnUpload.alpha = 1.0
    }
    
    private func updateButtonForUpgrading() {
        btnUpload.setTitle(NSLocalizedString("Upload the watchface in progress", comment: "Upload the watchface in progress"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    private func updateButtonForUpgradeSuccess() {
        btnUpload.setTitle(NSLocalizedString("Upload the watchface success", comment: "Upload the watchface success"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    private func updateButtonForUpgradeFailed() {
        btnUpload.setTitle(NSLocalizedString("Upload the watchface failed", comment: "Upload the watchface failed"), for: .normal)
        btnUpload.isUserInteractionEnabled = false
        btnUpload.alpha = 0.5
    }
    
    @IBAction func onClickUploadButton(_ sender: Any) {
        
        /// Add a cloud watchface file to your project, and replace the following code with your own watchface file name.
        /// Using an incompatible watchface file may cause the watch to malfunction.
        let filename = "--"  //5140b9f6ad95
        let line = #line
        let file = #file

        guard let path = Bundle.main.path(forResource: filename, ofType: "bin") else {
            let message = "Please check line \(line-1) of \(file), the cloud watchface file should match the watch model."
            XLOG_ERROR(message)
            showTips(message, true)
            return
        }
        
        guard FileManager.default.fileExists(atPath: path) else {
            let message = "The watchface file not found at path: \(path)"
            XLOG_ERROR(message)
            showTips(message, true)
            return
        }

        guard let allConfig = FitCloudKit.allConfig(), let firmwareInfo = allConfig.firmware else {
            showTips("Device not ready", true)
            return
        }
        
        updateButtonForUpgrading()
        
        if firmwareInfo.withNewOTA {
            handleNewOTAUpgrade(path)
        } else {
            handleTraditionalDFUUpgrade(firmwareInfo, path)
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
            
            let silentMode = firmwareInfo.hardwareSupported.contains(._DFUSHOULDSILENTMODE)
            FitCloudDFUKit.start(with: peripheral,
                                firmware: path,
                                chipVendor: .REALTEK,
                                silentMode: silentMode)
        }
    }
    
    @IBAction func onGoBack(_ sender: Any) {
        navigationController?.popViewController(animated: true)
    }
}

extension CloudWatchfaceDemoController: FitCloudDFUDelegate {
    
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
