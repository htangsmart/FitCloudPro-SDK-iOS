//
//  FitCloudEvent.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/30.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#ifndef FitCloudEvent_h
#define FitCloudEvent_h
#import <Foundation/Foundation.h>

#pragma mark - FitCloud Event Definitions

/// Notification when CentralManager state changes
///
/// - Parameter object: CBCentralManager instance
extern NSString *const FITCLOUDEVENT_CENTRALMANAGER_DIDUPDATESTATE_NOTIFY;

/// Notification when a new peripheral (watch) is discovered
///
/// - Parameter object: FitCloudPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY;

/// Notification when a discovered peripheral (watch) is updated
///
/// - Parameter object: FitCloudPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY;

/// Notification when peripheral (watch) scanning stops
extern NSString *const FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY;

/// Notification when peripheral (watch) starts connecting
///
/// - Parameter object: CBPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECTING_NOTIFY;

/// Notification when peripheral (watch) connection succeeds
///
/// - Parameter object: CBPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY;

/// Notification when peripheral (watch) reconnects in DFU mode
///
/// - Parameter object: CBPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_RECONNECTEDWITHDFUMODE_NOTIFY;

/// Notification when peripheral (watch) connection fails
///
/// - Parameters:
///   - object: CBPeripheral instance
///   - userInfo: Dictionary containing error information {@"error" : error}
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY;

/// Notification when peripheral (watch) disconnects
///
/// - Parameters:
///   - object: CBPeripheral instance
///   - userInfo: Dictionary containing error information {@"error" : error}
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY;

/// Notification when peripheral (watch) name updates
///
/// - Parameter object: CBPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DIDUPDATENAME_NOTIFIY;

/// Notification when peripheral (watch) RSSI updates
///
/// - Parameters:
///   - object: CBPeripheral instance
///   - userInfo: Dictionary containing RSSI and error information {@"RSSI":rssi, @"error" : error}
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DIDUPDATERSSI_NOTIFIY;

/// Notification when peripheral (watch) write characteristic is ready
///
/// - Parameter object: CBPeripheral instance
extern NSString *const FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY;

/// Notification when user binding starts
///
/// - Parameter object: UserId as NSNumber
extern NSString *const FITCLOUDEVENT_BINDUSEROBJECT_BEGIN_NOTIFY;

/// Notification of user binding result
///
/// - Parameters:
///   - object: UserId as NSNumber
///   - userInfo: Dictionary containing result, error and bluetooth info {@"result":@(YES/NO), @"error" : error, @"audioBluetooth": bluetoothName}
extern NSString *const FITCLOUDEVENT_BINDUSEROBJECT_RESULT_NOTIFY;

/// Notification when user unbinding starts
///
/// - Parameter object: UserId as NSNumber
extern NSString *const FITCLOUDEVENT_UNBINDUSEROBJECT_BEGIN_NOTIFY;

/// Notification of user unbinding result
///
/// - Parameters:
///   - object: UserId as NSNumber
///   - userInfo: Dictionary containing result and error information {@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_UNBINDUSEROBJECT_RESULT_NOTIFY;

/// Notification when user login starts
///
/// - Parameter object: UserId as NSNumber
extern NSString *const FITCLOUDEVENT_LOGINUSEROBJECT_BEGIN_NOTIFY;

/// Notification of user login result
///
/// - Parameters:
///   - object: UserId as NSNumber
///   - userInfo: Dictionary containing result and error information {@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_LOGINUSEROBJECT_RESULT_NOTIFY;

/// Notification when watch is bound by another phone or unbound
extern NSString *const FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY;

/// Notification when fetching all watch configurations starts
extern NSString *const FITCLOUDEVENT_GETALLCONFIG_BEGIN_NOTIFY;

/// Notification of fetching all watch configurations result
///
/// - Parameter userInfo: Dictionary containing result and error information {@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_GETALLCONFIG_RESULT_NOTIFY;

/// Notification of binding/login initialization result
///
/// - Parameters:
///   - object: nil
///   - userInfo: Dictionary containing result and error information {@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_INITIALIZE_RESULT_NOTIFY;

/// Notification when preparation sync work begins after successful binding/login initialization
extern NSString *const FITCLOUDEVENT_PREPARESYNCWORK_BEGIN_NOTIFY;

/// Notification when preparation sync work ends after successful binding/login initialization
///
/// - Parameters:
///   - object: error info if exist
extern NSString *const FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY;

/// Notification of watch battery information
///
/// - Parameter object: FitCloudBatteryInfoObject instance
extern NSString *const FITCLOUDEVENT_BATTERYINFO_NOTIFY;

/// Notification when alarm list changes
///
/// - Parameter userInfo: Array of FitCloudAlarmObject instances
extern NSString *const FITCLOUDEVENT_ALARMLIST_CHANGED_NOTIFY;

/// Notification when schedule list changes
///
/// - Parameter userInfo: Array of FitCloudScheduleObject instances
extern NSString *const FITCLOUDEVENT_SCHEDULELIST_CHANGED_NOTIFY;

/// Notification when favorite contacts list changes
///
/// - Parameter userInfo: Array of FitCloudContactObject instances
extern NSString *const FITCLOUDEVENT_FAVCONTACTS_CHANGED_NOTIFY;

/// Notification when habits list changes
///
/// - Parameter userInfo: Array of FitCloudHabitObject instances
extern NSString *const FITCLOUDEVENT_HABITS_CHANGED_NOTIFY;

/// Notification when ECG detection starts successfully
///
/// - Parameter object: Sampling interval in milliseconds as NSNumber
extern NSString *const FITCLOUDEVENT_ECG_START_SUCCEED_NOTIFY;

/// Notification when ECG detection fails to start
extern NSString *const FITCLOUDEVENT_ECG_START_FAILURE_NOTIFY;

/// Notification when ECG detection stops
extern NSString *const FITCLOUDEVENT_ECG_STOP_NOTIFY;

/// Notification when watch configuration is manually changed on device
extern NSString *const FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY;

/// Notification when watch pairing information is lost or mismatched
///
/// Note: This notification may be sent repeatedly. Applications should avoid showing repeated alerts to users.
extern NSString *const FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY;

/// Notification when medal list changes
///
/// - Parameter userInfo: Array of FitCloudMedal instances
extern NSString *const FITCLOUDEVENT_MEDALLIST_CHANGED_NOTIFY;

/// Notification when workout ends on watch
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WORKOUT_END_NOTIFY;

/// Notification when workout is paused on watch
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WORKOUT_PAUSED_NOTIFY;

/// Notification when workout starts or resumes on watch
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WORKOUT_STARTED_OR_RESUMED_NOTIFY;

/// Notification when watch face is toggled
extern NSString *const FITCLOUDEVENT_WATCHFACE_TOGGLED_NOTIFY;

/// Notification of heart rate measurement result
///
/// - Parameter userInfo: Dictionary containing timestamp and heart rate value
///   - timestamp: NSDate instance
///   - hrValue: Heart rate value as NSInteger
extern NSString *const FITCLOUDEVENT_WATCHSIDE_HEARTRATE_MEASURE_RESULT_NOTIFY;

/// Notification when watch initiates stop finding watch action
extern NSString *const FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY;

/// Notification when watch terminates measurement initialized by app
extern NSString *const FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY;

/// Notification when watch face is removed
///
/// - Parameter userInfo: Dictionary containing watch face information
///   - watchfaceNo: Watch face number as NSInteger
///   - slotIndex: Slot index as NSInteger (0-7)
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY;

/// Notification when command execution times out
///
/// - Parameter userInfo: Dictionary containing command information
///   - cmd: Command as NSInteger
///   - key: Key as NSInteger
extern NSString *const FITCLOUDEVENT_COMMAND_EXEC_TIMEOUT_NOTIFY;

#endif /* FitCloudEvent_h */
