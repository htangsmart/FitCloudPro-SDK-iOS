//
//  DataSyncSwiftDemo.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import UIKit
import FitCloudKit

@objc class DataSyncSwiftDemo: NSObject {

    @objc static func queryTodayActivitySummaryData(withToast toast: (() -> Void)? = nil) {
        FitCloudKit.requestHealthAndSportsDataToday { succeed, userId, dataObject, error in
            if let dataObject = dataObject {
                let log = String(format: "\nToday's Activity Data:\nSteps: %d\nDistance: %d\nCalories: %d\nDeep Sleep: %d\nLight Sleep: %d\nAverage Heart Rate: %d",
                               dataObject.steps,
                               dataObject.distance,
                               dataObject.calorie,
                               dataObject.deepSleepInMinutes,
                               dataObject.lightSleepInMinutes,
                               dataObject.avgBPM)
                XLOG_INFO(log)
                toast?()
            }
        }
    }
    

    @objc static func manualSyncData(withToast toast: (() -> Void)? = nil) {
        
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
                   let workoutRecord = currentRecord as? FitCloudSportsRecordObject, let workoutType = workoutRecord.workoutType {
                    
                    // Log the type of workout activity (e.g. running, walking, etc.)
                    // For detailed definitions, see: https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/Workouts.md
                    XLOG_INFO("Workout type: \(workoutType)")
                    let begin = workoutRecord.begin
                    XLOG_INFO("Workout Begin: \(begin)")
                    // Log the heart rate data array associated with this workout session
                    XLOG_INFO("Found workout record, BPM data: \(String(describing: workoutRecord.bpmDataArray))")
                    
                    // Get workout items from the record
                    let items = workoutRecord.items

                    // Verify if workout items exist
                    guard !items.isEmpty else {
                        XLOG_WARNING("No workout items found.")
                        return
                    }

                    // Get the end time of the workout from the last item
                    if let end = items.last?.moment {
                        // Calculate workout duration
                        let duration = end.timeIntervalSince(begin)
                        let hours = Int(duration) / 3600
                        let minutes = Int(duration) / 60 % 60
                        let seconds = Int(duration) % 60
                        XLOG_INFO("Workout End: \(end)")
                        XLOG_INFO("Workout Duration: \(String(format: "%02d:%02d:%02d", hours, minutes, seconds))")
                    } else {
                        XLOG_WARNING("Unable to determine workout end time.")
                    }

                    // Initialize accumulators for workout statistics
                    var workoutStats = (steps: 0, calories: 0)

                    // Calculate total steps and calories
                    items.forEach { item in
                        workoutStats.steps += Int(item.steps)
                        workoutStats.calories += Int(item.calorie)
                    }

                    // Convert calories to kilocalories (1 kcal = 1000 calories)
                    let kiloCalories = Double(workoutStats.calories) / 1000.0

                    // Log workout summary
                    XLOG_INFO("Workout Summary - Total Steps: \(workoutStats.steps), Total Calories: \(String(format: "%.2f", kiloCalories))kcal")
                    
                }
            }
            
            return
        }, finished: {
            XLOG_WARNING("Data synchronization task completed.")
        })
    }
}
