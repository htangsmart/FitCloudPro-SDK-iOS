//
//  DataSyncSwiftDemo.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import UIKit
import FitCloudKit

@objc class DataSyncSwiftDemo: NSObject {
    

    @objc class func manualSyncData(withToast toast: (() -> Void)? = nil) {
        
        FitCloudKit.manualSyncData(with: .ALL, progress: { progress, tip in
            XLOG_INFO("Sync Progress: \(Int(progress*100))%%, \(String(describing: tip))")
        }, block: { succeed, userId, records, error in
            toast?()

            if !succeed {
                XLOG_WARNING("Data sync failed with error: \(String(describing: error))")
                return
            }

            guard let syncRecords = records as? [FitCloudManualSyncRecordObject] else {
                XLOG_WARNING("No data available for synchronization.")
                return
            }

            if syncRecords.isEmpty {
                XLOG_WARNING("No data available for synchronization.")
                return
            }

            XLOG_INFO("Data sync completed successfully. Total records synchronized: \(syncRecords.count)")
            #if DEBUG
                XLOG_INFO("Synchronized records details:\n \(syncRecords)")
            #endif
            
            
            /// Samples to access the bpmDataArray of the workout record
            for record in syncRecords {
                if let currentRecord = record as? FitCloudManualSyncRecordObject<FitCloudSportsItemObject>,
                   let workoutRecord = currentRecord as? FitCloudSportsRecordObject {
                    XLOG_INFO("Found workout record, BPM data: \(String(describing: workoutRecord.bpmDataArray))")
                }
            }
            
            return
        }, finished: {
            XLOG_WARNING("Data synchronization task completed.")
        })
    }
}
