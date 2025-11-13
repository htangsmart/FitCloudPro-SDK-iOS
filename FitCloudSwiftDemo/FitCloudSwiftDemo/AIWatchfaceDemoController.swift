//
//  AIWatchfaceDemoController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 11/9/25.
//

import UIKit
import Zip
import FitCloudKit


class AIWatchfaceDemoController: UIViewController {

    @IBOutlet weak var photoView: UIImageView!
    @IBOutlet weak var tipsLabel: UILabel!
    @IBOutlet weak var installPositionSegmentedControl: UISegmentedControl!
    @IBOutlet weak var dateTimeColorSegmentedControl: UISegmentedControl!
    
    var aiWatchfaceBinPath: String?
    var installableWatchfaceSlotIndexArray: [NSNumber]?

    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.installPositionSegmentedControl.isHidden = true
        self.dateTimeColorSegmentedControl.isHidden = true
        self.installPositionSegmentedControl.addTarget(self, action: #selector(installPositionSegmentedControlValueChanged(_:)), for: .valueChanged)
        self.dateTimeColorSegmentedControl.addTarget(self, action: #selector(dateTimeColorSegmentedControlValueChanged(_:)), for: .valueChanged)
        let macAddress = FitCloudKit.macAddr()
        let isWatchDeviceRegisterAIServiceSuccess = FitCloudProSDK.shared.isWatchDeviceRegisterAIServiceSuccess
        let watchDeviceRegisterAIServiceError = FitCloudProSDK.shared.watchDeviceRegisterAIServiceError
        
        if isWatchDeviceRegisterAIServiceSuccess {
            showDeviceRegisterAIServiceSuccessTips(macAddress ?? "")
            fetchInstallablePositions()
            setupWithTitanDateTimeColorStyles()
        }
        else if let error = watchDeviceRegisterAIServiceError {
            showDeviceRegisterAIServiceFailedTips(macAddress ?? "", error: error)
        }
        else {
            showDeviceRegisterAIServiceFailedTips(macAddress ?? "")
        }
        
        // Do any additional setup after loading the view.
        registerNotifications()
    }

    func fetchInstallablePositions() {
        FitCloudKit.fetchInstallableWatchfaceSlotCount {[weak self] success, installableSlotCount, slotIndexArray, error in
            if success {
                guard let installableSlotCount = installableSlotCount, let slotIndexArray = slotIndexArray else {
                    return
                }
                self?.installableWatchfaceSlotIndexArray = slotIndexArray
                DispatchQueue.main.async {
                    self?.installPositionSegmentedControl.isHidden = false
                    self?.installPositionSegmentedControl.removeAllSegments()
                    for index in 0..<Int(installableSlotCount) {
                        self?.installPositionSegmentedControl.insertSegment(withTitle: "\(index + 1)", at: index, animated: false)
                    }
                    self?.installPositionSegmentedControl.selectedSegmentIndex = FitCloudProSDK.shared.aiWatchfaceInstallPostion
                    FitCloudProSDK.shared.aiWatchfaceSlotIndex = slotIndexArray[FitCloudProSDK.shared.aiWatchfaceInstallPostion].intValue
                }
            }
        }
    }

    @objc func installPositionSegmentedControlValueChanged(_ sender: UISegmentedControl) {
        let selectedIndex = sender.selectedSegmentIndex
        print("installPositionSegmentedControlValueChanged: \(selectedIndex)")
        FitCloudProSDK.shared.aiWatchfaceInstallPostion = selectedIndex
        guard let slotIndexArray = self.installableWatchfaceSlotIndexArray else {
            return
        }
        FitCloudProSDK.shared.aiWatchfaceSlotIndex = slotIndexArray[selectedIndex].intValue
    }

    func setupWithTitanDateTimeColorStyles() {
        self.dateTimeColorSegmentedControl.isHidden = false
        self.dateTimeColorSegmentedControl.removeAllSegments()
        let colors = ["Black", "White", "Green", "Gray", "Yellow"]
        for (index, color) in colors.enumerated() {
            self.dateTimeColorSegmentedControl.insertSegment(withTitle: color, at: index, animated: false)
        }
        self.dateTimeColorSegmentedControl.selectedSegmentIndex = FitCloudProSDK.shared.aiWatchfaceDateTimeColorStyle
    }

    @objc func dateTimeColorSegmentedControlValueChanged(_ sender: UISegmentedControl) {
        let selectedIndex = sender.selectedSegmentIndex
        print("dateTimeColorSegmentedControlValueChanged: \(selectedIndex)")
        FitCloudProSDK.shared.aiWatchfaceDateTimeColorStyle = selectedIndex
    }

    func showDeviceRegisterAIServiceSuccessTips(_ macAddress: String) {
        DispatchQueue.main.async {
            self.tipsLabel.text = "Successfully registered device MAC address: \(macAddress)"
        }
    }

    func showDeviceRegisterAIServiceFailedTips(_ macAddress: String, error: NSError? = nil) {
        DispatchQueue.main.async {
            
            if let error = error {
                self.tipsLabel.text = "Failed to register device MAC address: \(macAddress), error:\(error)"
            }
            else {
                self.tipsLabel.text = "Failed to register device MAC address: \(macAddress) with unknown error."
            }
        }
    }
    

    func registerNotifications() {
        NotificationCenter.default.addObserver(self, selector: #selector(aiPhotoDidChange), name: AppNotifcations.aiPhotoDidChange, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(aiWatchfaceProgressTips), name: AppNotifcations.aiWatchfaceProgressTips, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(aiWatchfaceBinDidChange), name: AppNotifcations.aiWatchfaceBinDidChange, object: nil)
    }

    @objc func aiPhotoDidChange(notification: Notification) {
        if let image = notification.object as? UIImage {
            DispatchQueue.main.async {
                self.photoView.image = image
            }
        }
    }
    
    @objc func aiWatchfaceBinDidChange(notification: Notification) {
        if let binPath = notification.object as? String {
            self.aiWatchfaceBinPath = binPath
        }
    }
    
    @objc func aiWatchfaceProgressTips(notification: Notification) {
        if let tips = notification.object as? String {
            DispatchQueue.main.async {
                self.tipsLabel.text = tips
            }
        }
    }

    @IBAction func onGoBack(_ sender: Any) {
        navigationController?.popViewController(animated: true)
    }
    
    @IBAction func onExport(_ sender: Any) {
        let documentsURL = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first!
        
        var fileArray = [URL]()

        let aigcPhotoUrl = documentsURL.appendingPathComponent("aigc_photo.jpg")
        if FileManager.default.fileExists(atPath: aigcPhotoUrl.path) {
            fileArray.append(aigcPhotoUrl)
        }

        let aigcPreviewUrl = documentsURL.appendingPathComponent("aigc_preview.jpg")
        if FileManager.default.fileExists(atPath: aigcPreviewUrl.path) {
            fileArray.append(aigcPreviewUrl)
        }

        let asrOpusVoiceUrl = documentsURL.appendingPathComponent("asr_voice.opus")
        if FileManager.default.fileExists(atPath: asrOpusVoiceUrl.path) {
            fileArray.append(asrOpusVoiceUrl)
        }
        
        let asrPcmVoiceUrl = documentsURL.appendingPathComponent("asr_voice.pcm")
        if FileManager.default.fileExists(atPath: asrPcmVoiceUrl.path) {
            fileArray.append(asrPcmVoiceUrl)
        }
        
        if let aiWatchfaceBinPath = self.aiWatchfaceBinPath {
            fileArray.append(URL(fileURLWithPath: aiWatchfaceBinPath))
        }
        
        if fileArray.isEmpty {
            print("No files to share")
            let alertController = UIAlertController(title: "No files to share", message: "Please try again.", preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
            alertController.addAction(okAction)
            self.present(alertController, animated: true, completion: nil)
            return
        }

        let cachesURL = FileManager.default.urls(for: .cachesDirectory, in: .userDomainMask).first!
            let zipURL = cachesURL.appendingPathComponent("AIWatchfaceExport.zip")
            do {
                ///如果 zipURL 存在，先删除
                if FileManager.default.fileExists(atPath: zipURL.path) {
                    try FileManager.default.removeItem(at: zipURL)
                }
                /// 显示加载提示
                let hud = MBProgressHUD.showAdded(to: self.view, animated: true)
                hud.label.text = "Packing for export..."
                
                /// 压缩成 zip
                DispatchQueue.global(qos: .userInitiated).async {
                    do {
                        try Zip.zipFiles(paths: fileArray, zipFilePath: zipURL, password: nil, progress: nil)
                        DispatchQueue.main.async {
                            hud.hide(animated: true)
                            let activityViewController = UIActivityViewController(activityItems: [zipURL], applicationActivities: nil)
                            self.present(activityViewController, animated: true, completion: nil)
                        }
                    } catch {
                        DispatchQueue.main.async {
                            hud.hide(animated: true)
                            print("Failed to package export file: \(error)")
                        }
                    }
                }
            } catch {
                print("Failed to package export file: \(error)")
            }
    }
    
}
