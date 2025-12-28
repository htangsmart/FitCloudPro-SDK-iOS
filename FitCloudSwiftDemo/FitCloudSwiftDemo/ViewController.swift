//
//  ViewController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import UIKit

class ViewController: UIViewController {
    
    
    @IBOutlet weak var imageSmartWatch: UIImageView!
    @IBOutlet weak var deviceName: UILabel!
    @IBOutlet weak var indicator: UIActivityIndicatorView!
    @IBOutlet weak var connectStatus: UILabel!
    @IBOutlet weak var btnConnectDevice: UIButton!
    @IBOutlet weak var btnRemoveDevice: UIButton!
    @IBOutlet weak var btnMoreDemo: UIButton!
    @IBOutlet weak var progressTip: UILabel!
    @IBOutlet weak var btnSearch: UIButton!
    
    @IBOutlet weak var soc: UILabel!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        do {
            btnConnectDevice.setTitle(NSLocalizedString("Connect Device", comment: ""), for: .normal)
            btnConnectDevice.layer.borderColor = UIColor.black.cgColor
            btnConnectDevice.contentEdgeInsets = UIEdgeInsets(top: 0, left: 30, bottom: 0, right: 30)
        }
        
        do {
            btnSearch.setTitle(NSLocalizedString("Search Device", comment: ""), for: .normal)
            btnSearch.layer.borderColor = UIColor.black.cgColor
            btnSearch.contentEdgeInsets = UIEdgeInsets(top: 0, left: 30, bottom: 0, right: 30)
        }
        
        do {
            btnRemoveDevice.setTitle(NSLocalizedString("Remove Device", comment: ""), for: .normal)
        }
        
        do {
            btnMoreDemo.setTitle(NSLocalizedString("More Demo >", comment: ""), for: .normal)
        }
        
        do {
            updateControlVisible()
        }
        
        registerNotificationObsever()
        
        if let lastPeripheral = FitCloudKit.lastConnectPeripheral() {
            deviceName.text = lastPeripheral.name
            if FitCloudKit.isConnecting() {
                indicator.isHidden = false
                connectStatus.isHidden = false
                if !indicator.isAnimating {
                    indicator.startAnimating()
                }
                btnConnectDevice.isHidden = true
                btnRemoveDevice.isHidden = true
                btnMoreDemo.isHidden = true
                connectStatus.text = NSLocalizedString("Connecting...", comment: "")
                connectStatus.textColor = UIColor(red: 0x9A/255.0, green: 0x9A/255.0, blue: 0x9A/255.0, alpha: 1.0)
            }
        }
    }

func registerNotificationObsever() {
    NotificationCenter.default.addObserver(self, selector: #selector(onPeripheralConnectingNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_PERIPHERAL_CONNECTING_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onPeripheralConnectedNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onPeripheralDisconnectedNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onPeripherialConnectFailureNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY), object: nil)
    
    NotificationCenter.default.addObserver(self, selector: #selector(onBatteryInfoNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_BATTERYINFO_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onFitCloudLoginUserObjectBegin(_:)), name: NSNotification.Name(FITCLOUDEVENT_LOGINUSEROBJECT_BEGIN_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onFitCloudLoginUserObjectResult(_:)), name: NSNotification.Name(FITCLOUDEVENT_LOGINUSEROBJECT_RESULT_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onFitCloudGetAllConfigBegin(_:)), name: NSNotification.Name(FITCLOUDEVENT_GETALLCONFIG_BEGIN_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onFitCloudGetAllConfigResult(_:)), name: NSNotification.Name(FITCLOUDEVENT_GETALLCONFIG_RESULT_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onPrepareSyncWorkBeginNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_PREPARESYNCWORK_BEGIN_NOTIFY), object: nil)
    NotificationCenter.default.addObserver(self, selector: #selector(onPrepareSyncWorkEndNotification(_:)), name: NSNotification.Name(FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY), object: nil)
}

@objc func onPeripheralConnectingNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        self.indicator.isHidden = false
        self.connectStatus.isHidden = false
        if !self.indicator.isAnimating {
            self.indicator.startAnimating()
        }
        self.btnConnectDevice.isHidden = true
        self.btnRemoveDevice.isHidden = true
        self.btnMoreDemo.isHidden = true
        self.connectStatus.text = NSLocalizedString("Connecting...", comment: "")
        self.connectStatus.textColor = UIColor(red: 0x9A/255.0, green: 0x9A/255.0, blue: 0x9A/255.0, alpha: 1.0)
    }
}

@objc func onPeripheralConnectedNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        if self.indicator.isAnimating {
            self.indicator.stopAnimating()
        }
        if let lastPeripheral = FitCloudKit.lastConnectPeripheral() {
            self.deviceName.text = lastPeripheral.name
        }
        self.connectStatus.text = NSLocalizedString("Connected", comment: "")
        self.connectStatus.textColor = UIColor(red: 0x00/255.0, green: 0xB2/255.0, blue: 0x00/255.0, alpha: 1.0)
        self.btnConnectDevice.isHidden = true
        self.imageSmartWatch.isHidden = false
        self.deviceName.isHidden = false
        self.btnSearch.isHidden = true
    }
}

@objc func onPeripheralDisconnectedNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        if self.indicator.isAnimating {
            self.indicator.stopAnimating()
        }
        self.connectStatus.text = NSLocalizedString("Disconnected", comment: "")
        self.connectStatus.textColor = UIColor(red: 0x9A/255.0, green: 0x9A/255.0, blue: 0x9A/255.0, alpha: 1.0)
        if FitCloudKit.lastConnectPeripheral() != nil {
            self.btnConnectDevice.isHidden = false
        }
        self.btnRemoveDevice.isHidden = false
        self.btnMoreDemo.isHidden = true
        self.soc.text = ""
    }
}

@objc func onPeripherialConnectFailureNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        if self.indicator.isAnimating {
            self.indicator.stopAnimating()
        }
        self.btnConnectDevice.isHidden = false
        self.btnRemoveDevice.isHidden = false
        self.connectStatus.text = NSLocalizedString("Disconnected", comment: "")
        self.connectStatus.textColor = UIColor(red: 0x9A/255.0, green: 0x9A/255.0, blue: 0x9A/255.0, alpha: 1.0)
    }
}

@objc func onBatteryInfoNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        if let batteryInfo = notification.object as? FitCloudBatteryInfoObject {
            DispatchQueue.main.async {
                self.soc.text = String(format: NSLocalizedString("SOC: %d%%", comment: ""), batteryInfo.percent)
            }
        }
    }
}

@objc func onFitCloudLoginUserObjectBegin(_ notification: Notification) {
    DispatchQueue.main.async {
        self.progressTip.text = NSLocalizedString("Logging On User Object", comment: "")
    }
}

@objc func onFitCloudLoginUserObjectResult(_ notification: Notification) {
    DispatchQueue.main.async {
        var result = false
        if let userInfo = notification.userInfo as? [String: Any] {
            result = userInfo["result"] as? Bool ?? false
        }
        self.progressTip.text = result ? NSLocalizedString("Login User Object Success", comment: "") : NSLocalizedString("Login User Object Failure", comment: "")
        if !result {
            self.btnRemoveDevice.isHidden = false
        }
    }
}

@objc func onFitCloudGetAllConfigBegin(_ notification: Notification) {
    DispatchQueue.main.async {
        self.progressTip.text = NSLocalizedString("Getting Smart Watch All Config", comment: "")
    }
}

@objc func onFitCloudGetAllConfigResult(_ notification: Notification) {
    DispatchQueue.main.async {
        var result = false
        if let userInfo = notification.userInfo as? [String: Any] {
            result = userInfo["result"] as? Bool ?? false
        }
        self.progressTip.text = result ? NSLocalizedString("Get Smart Watch All Config Success", comment: "") : NSLocalizedString("Get Smart Watch All Config Failure", comment: "")
    }
}

@objc func onPrepareSyncWorkBeginNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        self.progressTip.text = NSLocalizedString("Preparing Work for Smart Watch", comment: "")
    }
}

@objc func onPrepareSyncWorkEndNotification(_ notification: Notification) {
    DispatchQueue.main.async {
        self.btnRemoveDevice.isHidden = false
        self.btnMoreDemo.isHidden = false
        self.progressTip.text = NSLocalizedString("Prepare Work for Smart Watch Finished.", comment: "")
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) {
            UIView.animate(withDuration: 1.5, animations: {
                self.progressTip.alpha = 0
            }) { _ in
                self.progressTip.text = ""
                self.progressTip.alpha = 1
            }
        }
    }
}

func updateControlVisible() {
    if FitCloudKit.lastConnectPeripheral() == nil || FitCloudKit.lastConnectPeripheral()?.isAlreadyUnbind == true {
        imageSmartWatch.isHidden = true
        deviceName.isHidden = true
        indicator.isHidden = true
        connectStatus.isHidden = true
        btnConnectDevice.isHidden = true
        btnRemoveDevice.isHidden = true
        btnMoreDemo.isHidden = true
        btnSearch.isHidden = false
    } else {
        imageSmartWatch.isHidden = false
        deviceName.isHidden = false
        btnSearch.isHidden = true
    }
}

override func shouldPerformSegue(withIdentifier identifier: String, sender: Any?) -> Bool {
    #if targetEnvironment(simulator)
    return false
    #else
    if FitCloudKit.bleState() != .POWEREDON {
        if FitCloudKit.bleState() == .POWEREDOFF {
            if let url = URL(string: UIApplication.openSettingsURLString) {
                UIApplication.shared.open(url, options: [:], completionHandler: nil)
            }
        } else {
            FitCloudKit.showBluetoothPowerAlertIfPossible()
        }
        return false
    }
    return true
    #endif
}


    @IBAction func onConnectDevice(_ sender: Any) {
        indicator.isHidden = false
        connectStatus.isHidden = false
        indicator.startAnimating()
        btnConnectDevice.isHidden = true
        if let lastDevice = FitCloudKit.historyPeripherals().last {
            FitCloudKit.tryReconnect(lastDevice)
        }
    }
    
    @IBAction func onRemoveDevice(_ sender: Any) {
        weak var weakSelf = self
        FitCloudKit.unbindUserObject(true) { succeed, error in
            if let record = FitCloudKit.historyPeripherals().last, let uuid = record.uuid {
                FitCloudKit.removePeripheralHistory(withUUID: uuid.uuidString)
                DispatchQueue.main.async {
                    weakSelf?.updateControlVisible()
                }
            }
        }
    }
    
}

