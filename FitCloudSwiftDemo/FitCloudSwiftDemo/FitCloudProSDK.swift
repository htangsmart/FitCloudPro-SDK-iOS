//
//  FitCloudProSDK.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import Foundation
import FitCloudKit

class FitCloudProSDK: NSObject {
    static let shared = FitCloudProSDK()

    private override init() {

    }

    func start() {
        initFitCloudProSDKs()
    }

    /// Initializes the FitCloudPro SDKs with required configurations
    private func initFitCloudProSDKs() {
        let option = FitCloudOption()
        option.debugMode = false
        option.shouldAutoReconnectWhenAppLaunch = true
        FitCloudKit.initWith(option, callback: self)
    }

}

extension  FitCloudProSDK: FitCloudCallback {
    
    /// Called when the watch device requests to find the iPhone device
    /// This function will be triggered when user activates the find phone feature on the watch
    func onFindiPhoneEvent() {
        XLOG_INFO("The watch device requests to find the iPhone device...")
    }
    
    /// Called when the watch device sends a photo control command
    /// This function will be triggered when user wants to take a photo using the watch
    func onTakePhotoCtrl() {
        XLOG_INFO("Received photo control command from watch device")
    }
    
    /// Called when receiving real-time health measurement data from the watch
    /// - Parameter records: Array of health measurement result objects containing various health metrics
    func onRealTimeHealthMeasuringData(_ records: [FitCloudRealTimeHealthMeasuringResultObject]!) {
        XLOG_INFO("Received real-time health measurement data: \(String(describing: records))")
    }
    
    /// Called when receiving real-time ECG data from the watch
    /// - Parameters:
    ///   - ecgDataArray: Array of ECG data points
    ///   - interval: Time interval between data points in milliseconds
    func onRealTimeECGData(_ ecgDataArray: [NSNumber]!, interval: Int) {
        XLOG_INFO("Received real-time ECG data with \(ecgDataArray.count) points, interval: \(interval)ms")
    }
    
    /// Called when the real-time ECG measurement stops
    /// This function will be triggered when the ECG measurement is completed or interrupted
    func onRealTimeECGStop() {
        XLOG_INFO("Real-time ECG measurement stopped")
    }
    
    /// Called periodically to indicate that the bracelet is still connected and active
    /// This is a heartbeat function to maintain connection status
    func onBraceletAlive() {
        XLOG_INFO("Bracelet heartbeat received - device is alive")
    }
    
    func getIslamicEvents() -> [FitCloudIslamicEventModel] {
        // Here you can implement your holiday logic, return an array containing IslamicHoliday objects
        // The code below is just an example
        let holiday1 = FitCloudIslamicEventModel()
        let islamicDate1 = FitCloudIslamicDateModel()
        islamicDate1.islamicYear = 1446
        islamicDate1.islamicMonth = 1
        islamicDate1.islamicDay = 1
        holiday1.islamicDate = islamicDate1
        holiday1.durationOfEventInDays = 3
        holiday1.correspondingGregorianDate = Date()

        let holiday2 = FitCloudIslamicEventModel()
        let islamicDate2 = FitCloudIslamicDateModel()
        islamicDate2.islamicYear = 1446
        islamicDate2.islamicMonth = 2
        islamicDate2.islamicDay = 10
        holiday2.islamicDate = islamicDate2
        holiday2.durationOfEventInDays = 5
        holiday2.correspondingGregorianDate = Date().addingTimeInterval(30 * 24 * 60 * 60)

        let holiday3 = FitCloudIslamicEventModel()
        let islamicDate3 = FitCloudIslamicDateModel()
        islamicDate3.islamicYear = 1446
        islamicDate3.islamicMonth = 4
        islamicDate3.islamicDay = 12
        holiday3.islamicDate = islamicDate3
        holiday3.durationOfEventInDays = 8
        holiday3.correspondingGregorianDate = Date().addingTimeInterval(3 * 30 * 24 * 60 * 60)

        let holiday4 = FitCloudIslamicEventModel()
        let islamicDate4 = FitCloudIslamicDateModel()
        islamicDate4.islamicYear = 1446
        islamicDate4.islamicMonth = 5
        islamicDate4.islamicDay = 15
        holiday4.islamicDate = islamicDate4
        holiday4.durationOfEventInDays = 2
        holiday4.correspondingGregorianDate = Date().addingTimeInterval(4 * 30 * 24 * 60 * 60)

        let holiday5 = FitCloudIslamicEventModel()
        let islamicDate5 = FitCloudIslamicDateModel()
        islamicDate5.islamicYear = 1446
        islamicDate5.islamicMonth = 7
        islamicDate5.islamicDay = 18
        holiday5.islamicDate = islamicDate5
        holiday5.durationOfEventInDays = 6
        holiday5.correspondingGregorianDate = Date().addingTimeInterval(5 * 30 * 24 * 60 * 60)

        let holiday6 = FitCloudIslamicEventModel()
        let islamicDate6 = FitCloudIslamicDateModel()
        islamicDate6.islamicYear = 1446
        islamicDate6.islamicMonth = 9
        islamicDate6.islamicDay = 18
        holiday6.islamicDate = islamicDate6
        holiday6.durationOfEventInDays = 9
        holiday6.correspondingGregorianDate = Date().addingTimeInterval(8 * 30 * 24 * 60 * 60)

        return [holiday1, holiday2, holiday3, holiday4, holiday5, holiday6]
    }
    
    /// Called when the watch requests Islamic holiday information
    /// This function handles the request from watch for Islamic calendar events
    /// and sets the events using FitCloudKit
    func onRequestCurrentIslamicEvents() {
        XLOG_INFO("Watch requesting Islamic holiday information...") // Watch requests Islamic holiday information
        
        XLOG_INFO("Setting Islamic holiday information: \(getIslamicEvents().debugDescription)") // Setting Islamic holiday information
        FitCloudKit.setCurrentIslamicEvents(getIslamicEvents()) { succeed, error in
            
        }
    }
    
    /// Called when the watch requests Kaaba data
    /// This function handles the request from watch for Kaaba direction information
    /// and sets the Kaaba data using FitCloudKit
    func onRequestKaabaData() {
        XLOG_INFO("Watch requesting Kaaba data...")
        
        XLOG_INFO("Setting Kaaba information: \(MuslimPrayerParams.instance().kaaba.debugDescription)")
        FitCloudKit.setKaabaData(MuslimPrayerParams.instance().kaaba) { succeed, error in
            
        }
    }
    
    /// Called when there is a log message from the FitCloudKit
    /// - Parameters:
    ///   - message: The log message string
    ///   - level: The severity level of the log message
    func onLogMessage(_ message: String!, level: FITCLOUDKITLOGLEVEL) {
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
    }
}
