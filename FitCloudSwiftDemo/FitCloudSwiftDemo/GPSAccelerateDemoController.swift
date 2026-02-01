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
    
    @IBOutlet weak var forceSwitchCtrl: UISwitch!
    
    @IBOutlet weak var useOwnDownloadServiceSwitchCtrl: UISwitch!
    
    
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
        FitCloudGPSAccelerate.setEPOFilesDownloadService(self.useOwnDownloadServiceSwitchCtrl.isOn ? self : nil)
        FitCloudGPSAccelerate.startUpdateGPSFilesForce(self.forceSwitchCtrl.isOn) { success, error in
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

extension GPSAccelerateDemoController: EPOFilesDownloadService {
    
    func downloadEPOFiles(completionHandler completion: ((Bool, [String]?, (any Error)?) -> Void)? = nil) {
        /**
         {"errorCode":0,"errorMsg":"success","time":1769944911,"data":{"url_1":"https:\/\/api.hetangsmart.com\/\/downloads\/ephemeris\/2026-02\/2026-02-01\/20260201_ELPO_GR3_1.DAT","url_1_size":48384,"url_1_md5":"8427164b95b50022ddc9f9b43264dbf9","url_2":"https:\/\/api.hetangsmart.com\/\/downloads\/ephemeris\/2026-02\/2026-02-01\/20260201_ELPO_GR3_2.DAT","url_2_size":48384,"url_2_md5":"8462d768914af290a8622c9265057adf"}}
         */
    }
    
    func downloadICOEEPOFiles(completionHandler completion: ((Bool, [ICOEEPOFile]?, (any Error)?) -> Void)? = nil) {
        /**
         {"errorCode":0,"errorMsg":"success","time":1769944796,"data":{"GPS":"https:\/\/api.hetangsmart.com\/\/downloads\/ephemeris\/2026-02\/2026-02-01\/20260201_06_f1e1G3.pgl","BEIDOU":"https:\/\/api.hetangsmart.com\/\/downloads\/ephemeris\/2026-02\/2026-02-01\/20260201_06_f1e1C3.pgl","GALILEO":"https:\/\/api.hetangsmart.com\/\/downloads\/ephemeris\/2026-02\/2026-02-01\/20260201_06_f1e1E3.pgl","QZSS":"https:\/\/api.hetangsmart.com\/\/downloads\/ephemeris\/2026-02\/2026-02-01\/20260201_06_f1e1J3.pgl"}}
         */
        let gpsEPO = ICOEEPOFile(fileType: .GPS, filePath: Bundle.main.path(forResource: "20260201_06_f1e1G3", ofType: "pgl") ?? "")
        let beidouEPO = ICOEEPOFile(fileType: .BDS, filePath: Bundle.main.path(forResource: "20260201_06_f1e1C3", ofType: "pgl") ?? "")
        let galileoEPO = ICOEEPOFile(fileType: .GALILEO, filePath: Bundle.main.path(forResource: "20260201_06_f1e1E3", ofType: "pgl") ?? "")
        let qzssEPO = ICOEEPOFile(fileType: .QZSS, filePath: Bundle.main.path(forResource: "20260201_06_f1e1J3", ofType: "pgl") ?? "")
        let epoArray = [gpsEPO, beidouEPO, galileoEPO, qzssEPO]
        XLOG_INFO("EPO files downloaded successful: \(epoArray)")
        completion?(true, epoArray, nil)
    }
}
