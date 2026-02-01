//
//  GPSAccelerateDemoController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2026-02-01.
//

import Foundation
import FitCloudKit
import FitCloudGPSAccelerate


class GPSAccelerateDemoController: UIViewController {
    
    @IBAction func onGoBack(_ sender: Any) {
        navigationController?.popViewController(animated: true)
    }
    
    // MARK: - 生命周期
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemBackground
        FitCloudGPSAccelerate.setLogService(self)
        FitCloudGPSAccelerate.setGPSLocationInfoRequestService(self)
    }
    @IBAction func onSimulateLocationRequestFromDevice(_ sender: Any) {
        FitCloudGPSAccelerate.requestCurrentLocationAndNotifyTheWatchDevice()
    }
    
    @IBAction func onStartUpgradeGPSFile(_ sender: Any) {
        FitCloudGPSAccelerate.startUpdateGPSFilesForce(true) { success, error in
            if let error = error {
                XLOG_ERROR("Start upgrading with failure:\(error)");
                return
            }
            XLOG_INFO("Start upgrading successful...")
        } progress: { progress in
            XLOG_INFO("Uploading GPS file with progress: \(progress*100)%")
        } waitDeviceRefresh: {
            XLOG_INFO("Waiting device to refresh...")
        } completion: { result, error in
            if let error = error {
                XLOG_ERROR("GPS file upload completed with error: \(error)")
                return
            }
            XLOG_INFO("GPS file uploaded completed.")
        }

    }
    
}

extension GPSAccelerateDemoController: LoggableProtocol {
    func onLogMessage(_ message: String, level: LogMateLevel, subsystem: String?, category: String?) {
        XLOG_INFO("\(message)")
    }
}

extension GPSAccelerateDemoController: GPSLocationInfoRequestService {
    func requestGPSLocation(completionHandler completion: ((Bool, Double, Double, (any Error)?) -> Void)? = nil) {
        completion?(true, 121.449324, 31.284062, nil)
    }
}
