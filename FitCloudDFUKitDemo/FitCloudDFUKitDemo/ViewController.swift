//
//  ViewController.swift
//  FitCloudDFUKitDemo
//
//  Created by pcjbird on 9/12/24.
//

import UIKit
import FitCloudKit
import FitCloudDFUKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        let option = FitCloudOption()
        option.debugMode = false
        FitCloudKit.initWith(option, callback: self)
        FitCloudDFUKit.setDebugMode(true)
        FitCloudDFUKit.setDelegate(self)

        registerNotifications()

        FitCloudKit.scanPeripherals()
    }

    private func registerNotifications() {
        NotificationCenter.default.addObserver(forName: .init(FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY),
                                               object: nil,
                                               queue: .main) { notification in
            guard let device = notification.object as? FitCloudPeripheral,
                  let name = device.peripheral.name,
                  name == "Venus" else { return }

            FitCloudKit.stopScan()
            print("Connecting to \(name)")
            FitCloudKit.connect(device.peripheral)
        }

    
        NotificationCenter.default.addObserver(forName: .init(FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY),
                                               object: nil,
                                               queue: .main) { notification in
            print("Binding device")
            DispatchQueue.main.asyncAfter(deadline: .now() + 5) {
                if FitCloudKit.isUserAlreadyBound("10000") {
                    
                } else {
                    FitCloudKit.bindUserObject("10000", randomCode: nil, abortIfExist: false) { succeed, _ in
                        print("Device bind status: \(succeed ? "success": "fail")")
                    }
                }
            }
        }
        
        NotificationCenter.default.addObserver(forName: .init(FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY),
                                               object: nil,
                                               queue: .main) { notification in
            print("Update firmware")
            DispatchQueue.main.asyncAfter(deadline: .now() + 5) {
                self.updateFirmware()
            }
        }
    }

    private func updateFirmware() {
        let path = Bundle.main.path(forResource: "Your correct dfu file, if not correct may cause the smart watch dead.", ofType: "bin")!   ///app_MP_sdk###00_1.0.0.0_b389efdd-ad8edcd3f87de3fc44ecbb93f6cf110f

        
        guard let allConfig = FitCloudKit.allConfig() else {
            print("device not ready")
            return
        }
        if allConfig.firmware.withNewOTA {
            print("perform ota with new ota mode")
            FitCloudKit.sendNewOTA(path) { isStartSuccess, error in
                print("start new ota failed \(String(describing: error))")
            } progress: { progress in
                print("new ota progress: \(progress)")
            } completion: { success, speed, error in
                print("new ota result: \(success)")
            }


            return
        }
        FitCloudKit.enterDFUMode { succeeded, peripheral, vendor, error in
            guard succeeded, let peripheral = peripheral else {
                print("FW - DFU enter fail \(String(describing: error))")
                return
            }
            guard let hardwareSupported = FitCloudKit.allConfig()?.firmware.hardwareSupported else {
                return
            }
            let silentMode = hardwareSupported.contains(._DFUSHOULDSILENTMODE)
            FitCloudDFUKit.start(with: peripheral, firmware: path, chipVendor: .REALTEK, silentMode: silentMode)
        }
    }
}

// MARK: - FitCloudCallback
extension ViewController: FitCloudCallback {

}

// MARK: - FitCloudCallback
extension ViewController: FitCloudDFUDelegate {
    func onStartDFUSuccess() {
        print("FW Start success")
    }

    func onStartDFUFailureWithError(_ error: Error) {
        print("FW fail \(error)")

        DispatchQueue.main.async {
            FitCloudKit.exitDFUMode()
        }
    }

    func onDFUProgress(_ progress: CGFloat, imageIndex index: Int, total: Int) {
        print("FW progress \(progress)")
    }

    func onAbortWithError(_ error: Error) {
        print("FW abort \(error)")
        
        DispatchQueue.main.async {
            FitCloudKit.exitDFUMode()
        }
    }

    func onDFUFinish(withSpeed speed: CGFloat) {
        print("FW finish")

        DispatchQueue.main.async {
            FitCloudKit.exitDFUMode()
        }
    }
}
