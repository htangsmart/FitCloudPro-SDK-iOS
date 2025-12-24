//
//  ConstellationFortuneController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2025-12-23.
//

import UIKit
import FitCloudKit

class ConstellationFortuneController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    
    @IBAction func onGoBack(_ sender: Any) {
        navigationController?.popViewController(animated: true)
    }
    
    func toast(_ message: String) {
        DispatchQueue.main.async {
            SwiftToast(message)
        }
    }
    
    
    @IBAction func onSendTodayFortuneData(_ sender: Any) {
        
        let todayFortuneData = FitCloudTodayFortuneDataModel()
        todayFortuneData.luckyNumber1 = 7
        todayFortuneData.luckyNumber2 = 4
        todayFortuneData.luckyNumber3 = 0
        todayFortuneData.luckyStarRating = 3
        todayFortuneData.luckyColor1 = UIColor(red: 0/255.0, green: 0/255.0, blue: 0/255.0, alpha: 1.0)
        todayFortuneData.luckyColor2 = UIColor(red: 255.0/255.0, green: 0/255.0, blue: 0/255.0, alpha: 1.0)
        todayFortuneData.luckyColor3 = UIColor(red: 0/255.0, green: 255.0/255.0, blue: 0/255.0, alpha: 1.0)
        todayFortuneData.auspiciousDirection = .east
        todayFortuneData.fortuneAdvice = "Seize the day with confidence—opportunities favor the bold."
        FitCloudKit.sendTodayFortuneData(todayFortuneData) { success, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Send today fortune data to the watch device failed: \(errorMsg)")
                self.toast("Send today fortune data to the watch device failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Send today fortune data to the watch device success")
            self.toast("Send today fortune data to the watch device success")
        }
    }
    
    @IBAction func onSendTalismanData(_ sender: Any) {
        let talismanData = FitCloudTalismanDataModel()
        talismanData.todayRecommendTalisman = .antiVillain
        talismanData.hasLover = true
        talismanData.talismanSharedByLover = NSNumber(value: FitCloudTalismanType.scholar.rawValue)
        FitCloudKit.sendTalismanData(talismanData) { success, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Send talisman data to the watch device failed: \(errorMsg)")
                self.toast("Send talisman data to the watch device failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Send talisman data to the watch device success")
            self.toast("Send talisman data to the watch device success")
        }
    }
    
    @IBAction func onQuerySelectedTalisman(_ sender: Any) {
        FitCloudKit.querySelectedTalisman { success, talisman, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Query selected talisman from the watch device failed: \(errorMsg)")
                self.toast("Query selected talisman from the watch device failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Query selected talisman from the watch device success: \(talisman)")
            self.toast("Query selected talisman from the watch device success: \(EnumUtils.talismanNameOf(talisman))")
        }
    }
    
    @IBAction func onQueryYogaAudioInfo(_ sender: Any) {
        FitCloudKit.queryYogaAudioInfo { success, yogaAudio, lastUploadDate, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Query yoga audio info from the watch device failed: \(errorMsg)")
                self.toast("Query yoga audio info from the watch device failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Query yoga audio info from the watch device success: \(yogaAudio), \(lastUploadDate?.description ?? "nil")")
            self.toast("Query yoga audio info from the watch device success: \(EnumUtils.yogaMusicNameOf(yogaAudio)), \(lastUploadDate?.description ?? "nil")")
        }
    }
    
    @IBAction func onSendYogaAudio(_ sender: Any) {
        let yogaAudioPath = Bundle.main.path(forResource: "855A_sample_yoga_audio1_mp3", ofType: "bin") ?? ""
        guard !yogaAudioPath.isEmpty else {
            XLOG_ERROR("Yoga audio file path is empty, please check if the resource exists")
            self.toast("Yoga audio file path is empty, please check if the resource exists")
            return
        }
        FitCloudKit.sendYogaAudio(yogaAudioPath) { progress in
            XLOG_INFO("Sending yogo audio, progres: \(progress * 100)%")
        } completion: { success, avgSpeed, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Send yoga audio to the watch device failed: \(errorMsg)")
                self.toast("Send yoga audio to the watch device failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Send yoga audio success, avgSpeed: \(avgSpeed)kB/s")
            self.toast("Send yoga audio success, avgSpeed: \(avgSpeed)kB/s")
        }

    }
    
    @IBAction func onCancelSendYogaAudio(_ sender: Any) {
        FitCloudKit.cancelSendYogaAudioIfNeeded { success, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Cancel send yoga audio failed: \(errorMsg)")
                self.toast("Cancel send yoga audio failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Cancel send yoga audio success.")
            self.toast("Cancel send yoga audio success.")
        }
    }
    
    
    @IBAction func onBondLover(_ sender: Any) {
        FitCloudKit.sendLoversBondingNotifcation(.BONDINGSUCCESS) { success, error in
            if !success {
                var errorMsg = "unknown error"
                if let error = error {
                    errorMsg = error.localizedDescription
                }
                XLOG_ERROR("Bond lover failed: \(errorMsg)")
                self.toast("Bond lover failed: \(errorMsg)")
                return
            }
            XLOG_INFO("Bond lover success.")
            self.toast("Bond lover success.")
        }
    }
    
}
