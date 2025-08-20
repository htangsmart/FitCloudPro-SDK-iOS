//
//  FitCloudKit.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/28.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//
//  框架名称:FitCloudKit.xcframework
//  框架功能:The iOS framework for the FitCloudPro smartwatch, which is responsible for encapsulating features such as communication with the watch device.
//          FitCloudPro 智能手表的 iOS 框架，负责与手表设备通信等功能的封装。
//
//  构建版本：
//      pcjbird    2025-08-20  Version:1.3.1-beta.48 Build:20250820001

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudKit/FitCloudSecureCoding.h>
#import <FitCloudKit/FitCloudDataModels.h>
#import <FitCloudKit/FitCloudEvent.h>
#import <FitCloudKit/FitCloudCallback.h>
#import <FitCloudKit/FitCloudOption.h>
#import <FitCloudKit/FitCloudKitConnectRecord.h>
#import <FitCloudKit/SmartWatchOperation.h>
#import <FitCloudKit/SmartWatchOperation+Private.h>
#import <FitCloudKit/SmartWatchBackgroundOperationQueue.h>

NS_ASSUME_NONNULL_BEGIN

/// FitCloudPro Ble Watch SDK
@interface FitCloudKit : NSObject

#pragma mark Version

/// SDK version
/// - Returns:
/// SDK version
+ (NSString *)sdkVersion;

/// SDK build version
/// - Returns:
/// SDK build version
+ (NSString *)sdkBuild;

/// SDK release date
/// - Returns:
/// SDK release date
+ (NSString *)sdkReleaseDate;

#pragma mark Initialize/Scan/Connect

/// Initialize the SDK
/// - Parameters:
///   - option: initialize option, if nil will use the default option.
///   - callback: the sdk callback handler
/// - Returns:
///  FitCloudKit
+ (instancetype _Nonnull)initWithOption:(FitCloudOption *_Nullable)option callback:(id<FitCloudCallback> _Nullable)callback;

/// Scan the watch devices
+ (void)scanPeripherals;

/// Stop scan the watch devices
+ (void)stopScan;

/// Converts a peripheral discovered by your own scanning method into a connectable peripheral
/// - Parameters:
///   - peripheral: The peripheral discovered by your scanning
///   - completion: The completion handler called with the conversion result
+ (void)translatePeripheral:(CBPeripheral *_Nonnull)peripheral toConnectablePeripheralCompletion:(void (^_Nullable)(BOOL success, NSError *_Nullable error, CBPeripheral *_Nullable connectablePeripheral))completion;

/// Connects to a watch device
/// - Parameters:
///   - peripheral: The watch device peripheral to connect to
+ (void)connect:(CBPeripheral *_Nonnull)peripheral;

/// Connects to a watch device with optional BT mode
/// - Parameters:
///   - peripheral: The watch device peripheral to connect to
///   - btMode: Whether to simultaneously connect classic Bluetooth (BT) using one-key dual connection
+ (void)connect:(CBPeripheral *_Nonnull)peripheral btMode:(BOOL)btMode;

/// Connects and binds to a watch device
/// - Parameters:
///   - peripheral: The watch device peripheral to connect to
///   - userId: The user ID for binding
///   - randomCode: Optional random code for binding (only used in some projects, pass nil if not needed)
///   - btMode: Whether to simultaneously connect classic Bluetooth (BT) using one-key dual connection
+ (void)connectAndBind:(CBPeripheral *_Nonnull)peripheral userId:(NSString *_Nonnull)userId randomCode:(NSString *_Nullable)randomCode btMode:(BOOL)btMode;

/// Try to connect the historical watch device
/// - Parameters:
///   - record: the historical watch device
///
/// >Warning: Please do not attempt to connect the watch device which has already been unbound.
+ (void)tryConnect:(FitCloudKitConnectRecord *_Nonnull)record;

/// Disconnect the current watch device
+ (void)disconnect;

/// Ignore the currently connected but unbound/binding failed watch device
/// - Parameters:
///   - silent: If YES, related logs will not be printed
+ (void)ignoreConnectedPeripheral:(BOOL)silent;

#pragma mark Request to turn on Bluetooth to allow connection to accessories

/// Request to turn on Bluetooth to allow connection to accessories
///
/// Only valid when system Bluetooth is turned off
+ (void)requestShowBluetoothPowerAlert;

#pragma mark List of discovered peripherals (watches)

/// List of discovered peripherals (watches)
/// - Returns: Discovered Bluetooth peripherals
+ (NSArray<FitCloudPeripheral *> *_Nonnull)discoveredPeripherals;

#pragma mark Bluetooth central device state

/// Bluetooth central device state
+ (FITCLOUDBLECENTRALSTATE)bleState;

#pragma mark Whether Bluetooth is connected

/// Whether Bluetooth is connected
+ (BOOL)connected;

#pragma mark Whether Bluetooth is connecting

/// Whether Bluetooth is connecting
+ (BOOL)connecting;

#pragma mark Whether the Bluetooth peripheral device is initialized/ready (whether operations with the Bluetooth peripheral can be performed)

/// Whether the Bluetooth peripheral device is initialized/ready (whether operations with the Bluetooth peripheral can be performed)
+ (BOOL)deviceReady;

#pragma mark Whether the preparation work after watch connection is completed

/// Whether the preparation work after watch connection is completed
+ (BOOL)devicePrepareWorkFinished;

#pragma mark Whether the Bluetooth peripheral device is initialized/ready and currently idle (whether operations with the Bluetooth peripheral can be performed)

/// Whether the Bluetooth peripheral device is initialized/ready and currently idle (whether operations with the Bluetooth peripheral can be performed)
+ (BOOL)deviceIdle;

#pragma mark Whether manual synchronization of exercise and health data is currently allowed

/// Whether manual synchronization of exercise and health data is currently allowed
+ (BOOL)canSyncData;

#pragma mark User binding status

/// User binding status
+ (FITCLOUDUSERBINDSTATUS)userBindStatus;

#pragma mark Connection flag

/// Connection flag
+ (FITCLOUDWATCHCONNECTIONFLAG)connectionFlag;

#pragma mark Watch device MAC address

/// Watch device MAC address
+ (NSString *_Nullable)macAddr;

#pragma mark Firmware Version

/// Full firmware version of the watch in format XXXX.XXXX.XXX (Project.Patch.Firmware)
/// - Returns:
/// Full firmware version string, e.g. "51B2.0000.108"
+ (NSString *_Nullable)firmwareFullVersion;

/// Short firmware version of the watch in format X.XX
/// - Returns:
/// Short firmware version string, e.g. "1.08"
+ (NSString *_Nullable)firmwareShortVersion;

#pragma mark GPS Firmware Version

/// GPS Firmware Version
+ (NSString *_Nullable)gpsFirmwareVersion;

#pragma mark 4G Modem Firmware Version

/// 4G Modem Firmware Version
+ (NSString *_Nullable)modem4gFirmwareVersion;

#pragma mark Current configuration information of the watch

/// Current configuration information of the watch
+ (FitCloudAllConfigObject *_Nullable)allConfig;

#pragma mark Current battery information of the watch

/// Current battery information of the watch
+ (FitCloudBatteryInfoObject *_Nullable)batteryInfo;

#pragma mark Watch alarm list

/// Watch alarm list
+ (NSArray<FitCloudAlarmObject *> *_Nullable)alarmlist;

#pragma mark Watch schedule list

/// Watch schedule list
+ (NSArray<FitCloudScheduleObject *> *_Nullable)schedulelist;

#pragma mark Watch favorite contacts list

/// Watch favorite contacts list
+ (NSArray<FitCloudContactObject *> *_Nullable)favoriteContacts;

#pragma mark Watch habit formation list

/// Watch habit formation list
+ (NSArray<FitCloudHabitObject *> *_Nullable)habits;

#pragma mark Watch medal list

/// Watch medal list
+ (NSArray<FitCloudMedal *> *_Nullable)medals;

#pragma mark Last connected watch information

/// Last connected watch information
+ (FitCloudKitConnectRecord *_Nullable)lastConnectPeripheral;

#pragma mark Watch connection history

/// Watch connection history
+ (NSArray<FitCloudKitConnectRecord *> *_Nonnull)historyPeripherals;

#pragma mark Delete watch connection history

/// Delete watch connection history
/// - Parameters:
///   - uuid: peripheral uuid
+ (void)removePeripheralHistoryWithUUID:(NSString *_Nonnull)uuid;

#pragma mark Clear watch connection history

/// Clear watch connection history
+ (void)clearPeripheralHistory;

#pragma mark Specified AI Conversation Model

/// Get the specified AI conversation model
/// - Returns: The AI conversation model type used for watch interactions
///
/// This method returns the AI conversation model type that is currently specified for use with the watch.
/// The model determines how AI conversations are handled between the watch and connected services.
+ (FITCLOUDAICONVERSATIONMODEL)specifiedAiConversationModel;

#pragma mark Specified AdFlash AI Agent

/// Gets the specified AdFlash AI agent type
/// - Returns: The AdFlash AI agent type that is currently specified for use with the watch
///
/// This method returns the AI agent type that is currently specified for AdFlash functionality.
/// The agent type determines how AdFlash AI features are handled on the watch.
+ (FITCLOUDADFLASHAIAGENT)specifiedAdFlashAiAgent;

@end

/// FitCloud Upgrade Module
@interface FitCloudKit (Upgrade)

#pragma mark Checks if the device is currently in DFU mode

/// Checks if the device is currently in DFU mode
/// - Returns: A boolean value indicating whether the device is in DFU mode
+ (BOOL)isCurrentDFUMode;

#pragma mark DFU Peripheral

/// Gets the DFU peripheral. Only valid when in DFU mode and connected.
/// - Returns: The DFU peripheral if available, otherwise nil
+ (CBPeripheral *_Nullable)dfuPeripheral;

#pragma mark Direct DFU Peripheral

/// Gets the direct DFU peripheral for clients who need direct DFU upgrade without entering DFU mode. Only valid when connected.
/// - Returns: The direct DFU peripheral if available, otherwise nil
+ (CBPeripheral *_Nullable)directDFUPeripheral;

#pragma mark Chip Vendor

/// Gets the current chip vendor
/// - Returns: The chip vendor type
+ (FITCLOUDCHIPVENDOR)chipVendor;

#pragma mark Enter DFU Mode

/// Prepares to enter firmware upgrade (DFU) mode
/// - Parameter block: A completion handler called when the operation completes
+ (void)enterDFUModeWithBlock:(FitCloudEnterDFUModeResultBlock _Nullable)block;

#pragma mark Exit DFU Mode

/// Exits firmware upgrade (DFU) mode
/// - Parameter block: A completion handler called when the operation completes
+ (void)exitDFUModeWithBlock:(FitCloudExitDFUModeResultBlock _Nullable)block;

#pragma mark Device Feature Support

/// Checks if the device supports a specific feature
/// - Parameter feature: The feature to check for support
/// - Returns: A boolean value indicating whether the feature is supported
+ (BOOL)isDeviceSupportFeature:(FITCLOUDDEVICEFEATURE)feature;

#pragma mark App Notification Support

/// Checks if the device supports a specific app notification type
/// - Parameter appNotification: The app notification type to check for support
/// - Returns: A boolean value indicating whether the notification type is supported
+ (BOOL)isDeviceSupportAppNotification:(FITCLOUDMN) appNotification;
@end

/// FitCloud Setting Module
@interface FitCloudKit (Setting)

#pragma mark Sync System Time

/// Synchronizes the watch time with the system time
/// - Parameters:
///   - block: The completion handler called when the sync completes
+ (void)syncSystemTimeWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Sync Specific Time

/// Synchronizes a specific time to the watch
/// - Parameters:
///   - time: The time to sync
///   - block: The completion handler called when the sync completes
+ (void)syncTimeToWatch:(NSDate *)time block:(FitCloudResultHandler _Nullable)block;

#pragma mark Sync Weather

/// Synchronizes weather information to the watch
/// - Parameters:
///   - weather: The weather information
///   - block: The completion handler called when the sync completes
+ (void)syncWeather:(FitCloudWeatherObject *_Nonnull)weather block:(FitCloudResultHandler _Nullable)block;

#pragma mark Set 24-Hour Weather

/// Sets 24-hour weather forecast information
/// - Parameters:
///   - weathers: Array of hourly weather forecasts, ordered sequentially from the specified timestamp
///   - timestamp: The starting timestamp
///   - completion: The completion handler called when the operation completes
+ (void)set24HoursWeather:(NSArray<FitCloudHourWeatherObject *> *_Nonnull)weathers timestamp:(NSDate *_Nonnull)timestamp completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Set Alarms

/// Synchronizes the alarm list from phone to watch
/// - Parameters:
///   - alarms: The array of alarms
///   - block: The completion handler called when the sync completes
+ (void)setAlarms:(NSArray<FitCloudAlarmObject *> *_Nullable)alarms block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Alarms

/// Retrieves the alarm list from the watch
/// - Parameters:
///   - block: The completion handler called with the alarm list
+ (void)getAlarmsWithBlock:(FitCloudAlarmsResultBlock _Nullable)block;

#pragma mark Set Allow Watch Schedule Settings

/// Sets whether the watch is allowed to configure schedules
/// - Parameters:
///   - allow: Whether to allow watch schedule settings
///   - block: The completion handler called when the operation completes
+ (void)setAllowWatchScheduleSettings:(BOOL)allow completion:(FitCloudResultHandler _Nullable)block;

#pragma mark Set Schedules

/// Synchronizes the schedule list from phone to watch
/// - Parameters:
///   - schedules: The array of schedules
///   - block: The completion handler called when the sync completes
+ (void)setSchedules:(NSArray<FitCloudScheduleObject *> *_Nullable)schedules block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Schedules

/// Retrieves the schedule list from the watch
/// - Parameters:
///   - block: The completion handler called with the schedule list
+ (void)getSchedulesWithBlock:(FitCloudSchedulesResultBlock _Nullable)block;

#pragma mark Set Tasks

/// Synchronizes the task list from phone to watch
/// - Parameters:
///   - tasks: The array of tasks
///   - totalCoinsEarned: The total coins earned
///   - completion: The completion handler called when the sync completes
+ (void)sendTasks:(NSArray<FitCloudTaskModel *> *_Nullable)tasks totalCoinsEarned:(NSUInteger)totalCoinsEarned completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Get Tasks

/// Retrieves the task list from the watch
/// - Parameters:
///   - completion: The completion handler called with the task list
+ (void)queryTasksWithCompletion:(FitCloudTaskQueryCompletion _Nullable)completion;

#pragma mark Set Favorite Contacts

/// Synchronizes the favorite contacts list from phone to watch
/// - Parameters:
///   - contacts: The array of favorite contacts
///   - block: The completion handler called when the sync completes
+ (void)setFavContacts:(NSArray<FitCloudContactObject *> *_Nullable)contacts block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Favorite Contacts

/// Retrieves the favorite contacts list from the watch
/// - Parameters:
///   - block: The completion handler called with the contacts list
+ (void)getFavContactsWithBlock:(FitCloudFavContactsResultBlock _Nullable)block;

#pragma mark Set Emergency Contacts

/// Sets emergency contacts on the watch
/// - Parameters:
///   - contacts: The array of emergency contacts
///   - on: Whether to enable emergency contacts
///   - completion: The completion handler called when the operation completes
+ (void)setEmergencyContacts:(NSArray<FitCloudEmergencyContactObject *> *_Nullable)contacts on:(BOOL)on completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Get Emergency Contacts

/// Retrieves emergency contacts from the watch
/// - Parameters:
///   - completion: The completion handler called with the emergency contacts
+ (void)queryEmergencyContactsWithCompletion:(FitCloudEmergencyContactsQueryCompletion _Nullable)completion;

#pragma mark Set Habits

/// Synchronizes the habit list from phone to watch
/// - Parameters:
///   - habits: The array of habits
///   - block: The completion handler called when the sync completes
+ (void)setHabits:(NSArray<FitCloudHabitObject *> *_Nullable)habits block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Habits

/// Retrieves the habit list from the watch
/// - Parameters:
///   - block: The completion handler called with the habit list
+ (void)getHabitsWithBlock:(FitCloudHabitsResultBlock _Nullable)block;

#pragma mark Set User Profile

/// Sets the user profile
/// - Parameters:
///   - profile: The user profile
///   - block: The completion handler called when the operation completes
+ (void)setUserProfile:(FitCloudUserProfileObject *_Nonnull)profile block:(FitCloudResultHandler _Nullable)block;

#pragma mark Set Custom Labels

/// Sets custom labels
/// - Parameters:
///   - labels: The custom labels
///   - block: The completion handler called when the operation completes
+ (void)setCustomLabels:(FitCloudCustomLabelsObject *_Nonnull)labels block:(FitCloudResultHandler _Nullable)block;

#pragma mark Set Daily Goals

/// Sets daily fitness goals
/// - Parameters:
///   - stepcount: Step count goal in steps
///   - distance: Distance goal in centimeters
///   - calorie: Calorie goal in calories
///   - duration: Exercise duration goal in minutes
///   - timestamp: Timestamp (defaults to current time if nil)
///   - block: The completion handler called when the operation completes
+ (void)setDailyGoalWithStepCount:(UInt32)stepcount distance:(UInt32)distance calorie:(UInt32)calorie duration:(UInt16)duration timestamp:(NSDate *_Nullable)timestamp block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Daily Goals

/// Retrieves daily fitness goals
/// - Parameters:
///   - block: The completion handler called with the daily goals
+ (void)getDailyGoalWithBlock:(FitCloudDailyGoalResultBlock _Nullable)block;

#pragma mark Get Firmware Version

/// Retrieves the watch's firmware and hardware version information
/// - Parameters:
///   - block: The completion handler called with the version information
+ (void)getFirmwareVersionWithBlock:(FitCloudFirmwareVersionResultBlock _Nullable)block;

#pragma mark Set Message Notifications

/// Configures message notification settings
/// - Parameters:
///   - mnSetting: The message notification settings
///   - block: The completion handler called when the operation completes
+ (void)setMessageNotification:(FITCLOUDMN)mnSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Message Notifications

/// Retrieves message notification settings
/// - Parameters:
///   - block: The completion handler called with the notification settings
+ (void)getMessageNotificationSettingWithBlock:(FitCloudMNSettingResultBlock _Nullable)block;

#pragma mark Set Screen Display

/// Configures display settings for all watch face features
/// - Parameters:
///   - display: The screen display settings
///   - block: The completion handler called when the operation completes
+ (void)setScreenDisplay:(FITCLOUDSCREENDISPLAY)display block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Screen Display

/// Retrieves display settings for all watch face features
/// - Parameters:
///   - block: The completion handler called with the display settings
+ (void)getScreenDisplaySettingWithBlock:(FitCloudSDSettingResultBlock _Nullable)block;

#pragma mark Set Watch Preferences

/// Sets watch preferences
/// - Parameters:
///   - prefer: The watch preferences
///   - block: The completion handler called when the operation completes
+ (void)setFitCloudPrefer:(FITCLOUDPREFER)prefer block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Watch Preferences

/// Retrieves watch preferences
/// - Parameters:
///   - block: The completion handler called with the preferences
+ (void)getFitCloudPreferWithBlock:(FitCloudPreferResultBlock _Nullable)block;

#pragma mark Get Battery Info

/// Retrieves battery level and charging status information
/// - Parameters:
///   - block: The completion handler called with the battery information
+ (void)getBatteryInfoWithBlock:(FitCloudBatteryInfoResultBlock _Nullable)block;

#pragma mark Request Battery Update

/// Requests a battery information update if the device is idle
+ (void)requestUpdateBatteryInfoIfIdle;

#pragma mark Set Health Monitoring

/// Configures health timing monitor settings
/// - Parameters:
///   - htmSetting: The health timing monitor settings
///   - block: The completion handler called when the operation completes
+ (void)setHealthTimingMonitor:(FitCloudHTMObject *_Nonnull)htmSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Health Monitoring

/// Retrieves health timing monitor settings
/// - Parameters:
///   - block: The completion handler called with the monitor settings
+ (void)getHealthTimingMonitorSettingWithBlock:(FitCloudHealthTimingMonitorResultBlock _Nullable)block;

#pragma mark Set Individual Health Monitoring

/// Configures individual health timing monitor settings
/// - Parameters:
///   - htmSingleSettings: Array of individual monitor settings
///   - completion: The completion handler called when the operation completes
+ (void)setSingleHealthTimingMonitoring:(NSArray<FitCloudHTMSingleObject *> *)htmSingleSettings completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Get Individual Health Monitoring

/// Retrieves individual health timing monitor settings
/// - Parameters:
///   - completion: The completion handler called with the individual monitor settings
+ (void)getSingleHealthTimingMonitoringSettingsWithCompletion:(FitCloudHealthTimingMonitoringSingleSettingsResultBlock _Nullable)completion;

#pragma mark Set Sedentary Reminder

/// Configures sedentary reminder settings
/// - Parameters:
///   - lsrSetting: The sedentary reminder settings
///   - block: The completion handler called when the operation completes
+ (void)setSedentaryRemind:(FitCloudLSRObject *_Nonnull)lsrSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Sedentary Reminder

/// Retrieves sedentary reminder settings
/// - Parameters:
///   - block: The completion handler called with the reminder settings
+ (void)getSedentaryRemindSettingWithBlock:(FitCloudLongSitRemindResultBlock _Nullable)block;

#pragma mark Set Drink Reminder

/// Configures drink reminder settings
/// - Parameters:
///   - drSetting: The drink reminder settings
///   - block: The completion handler called when the operation completes
+ (void)setDrinkRemind:(FitCloudDRObject *_Nonnull)drSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Drink Reminder

/// Retrieves drink reminder settings
/// - Parameters:
///   - block: The completion handler called with the reminder settings
+ (void)getDrinkRemindSettingWithBlock:(FitCloudDrinkRemindResultBlock _Nullable)block;

#pragma mark Set Personalized Reminder

/// Sets a personalized reminder, replacing any existing reminder with the same ID
/// - Parameters:
///   - remind: The personalized reminder
///   - completion: The completion handler called when the operation completes
+ (void)setPersonalizedRemind:(FitCloudPersonalizedReminderObject *_Nonnull)remind completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Query Personalized Reminders

/// Retrieves all personalized reminders
/// - Parameters:
///   - completion: The completion handler called with the reminders array
+ (void)queryPersonalizedRemindersWithCompletion:(FitCloudPersonalizedRemindersQueryCompletion _Nullable)completion;

#pragma mark Remove Personalized Reminders

/// Removes personalized reminders by their IDs
/// - Parameters:
///   - idArray: Array of reminder IDs to remove
///   - completion: The completion handler called when the operation completes
+ (void)removePersonalizedRemindersWithIdArray:(NSArray<NSNumber *> *_Nonnull)idArray completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Set Protection Reminder

/// Configures protection reminder settings
/// - Parameters:
///   - prSetting: The protection reminder settings
///   - block: The completion handler called when the operation completes
+ (void)setProtectionRemind:(FitCloudPRObject *_Nonnull)prSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Protection Reminder

/// Retrieves protection reminder settings
/// - Parameters:
///   - block: The completion handler called with the reminder settings
+ (void)getProtectionRemindSettingWithBlock:(FitCloudProtectionRemindResultBlock _Nullable)block;

#pragma mark Set Hand Wash Reminder

/// Configures hand wash reminder settings
/// - Parameters:
///   - hwrSetting: The hand wash reminder settings
///   - block: The completion handler called when the operation completes
+ (void)setHandWashRemind:(FitCloudHandWashRemindObject *_Nonnull)hwrSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Hand Wash Reminder

/// Retrieves hand wash reminder settings
/// - Parameters:
///   - block: The completion handler called with the reminder settings
+ (void)getHandWashRemindSettingWithBlock:(FitCloudHandWashRemindResultBlock _Nullable)block;

#pragma mark Set Wrist Wake Up

/// Configures wrist wake up settings
/// - Parameters:
///   - wwuSetting: The wrist wake up settings
///   - block: The completion handler called when the operation completes
+ (void)setWristWakeUp:(FitCloudWWUObject *_Nonnull)wwuSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Wrist Wake Up

/// Retrieves wrist wake up settings
/// - Parameters:
///   - block: The completion handler called with the wake up settings
+ (void)getWristWakeUpSettingWithBlock:(FitCloudWristWakeUpResultBlock _Nullable)block;

#pragma mark Set Blood Pressure Reference

/// Configures blood pressure reference settings
/// - Parameters:
///   - bprSetting: The blood pressure reference settings
///   - block: The completion handler called when the operation completes
+ (void)setBloodPressureRefer:(FitCloudBPRObject *_Nonnull)bprSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Blood Pressure Reference

/// Retrieves blood pressure reference settings
/// - Parameters:
///   - block: The completion handler called with the reference settings
+ (void)getBloodPressureReferSettingWithBlock:(FitCloudBloodPressureReferResultBlock _Nullable)block;

#pragma mark Set Heart Rate Alarm

/// Configures heart rate alarm settings
/// - Parameters:
///   - hrAlarmSetting: The heart rate alarm settings
///   - block: The completion handler called when the operation completes
+ (void)setHRAlarm:(FitCloudHRAlarmObject *_Nonnull)hrAlarmSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Heart Rate Alarm

/// Retrieves heart rate alarm settings
/// - Parameters:
///   - block: The completion handler called with the alarm settings
+ (void)getHRAlarmSettingWithBlock:(FitCloudHRAlarmResultBlock _Nullable)block;

#pragma mark Set Blood Pressure Alarm

/// Configures blood pressure alarm settings
/// - Parameters:
///   - bpAlarmSetting: The blood pressure alarm settings
///   - block: The completion handler called when the operation completes
+ (void)setBPAlarm:(FitCloudBPAlarmObject *_Nonnull)bpAlarmSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Blood Pressure Alarm

/// Retrieves blood pressure alarm settings
/// - Parameters:
///   - block: The completion handler called with the alarm settings
+ (void)getBPAlarmSettingWithBlock:(FitCloudBPAlarmResultBlock _Nullable)block;

#pragma mark Set Do Not Disturb

/// Configures Do Not Disturb mode settings
/// - Parameters:
///   - dndSetting: The Do Not Disturb settings
///   - block: The completion handler called when the operation completes
+ (void)setDND:(FitCloudDNDSetting *_Nonnull)dndSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Do Not Disturb

/// Retrieves Do Not Disturb mode settings
/// - Parameters:
///   - block: The completion handler called with the DND settings
+ (void)getDNDSettingWithBlock:(FitCloudDNDSettingResultBlock _Nullable)block;

#pragma mark Set Power Saving

/// Configures power saving mode settings
/// - Parameters:
///   - settings: The power saving settings
///   - block: The completion handler called when the operation completes
+ (void)setPowerSavingSettings:(FitCloudPowerSavingSetting *_Nonnull)settings block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Power Saving

/// Retrieves power saving mode settings
/// - Parameters:
///   - block: The completion handler called with the power saving settings
+ (void)getPowerSavingSettingWithBlock:(FitCloudPowerSavingSettingResultBlock _Nullable)block;

#pragma mark Get Watch UI Information

/// Retrieves watch UI information
/// - Parameters:
///   - block: The completion handler called with the UI information
+ (void)getWatchUIInformationWithBlock:(FitCloudWatchUIInfoResultBlock _Nullable)block;

#pragma mark Get Watch Face UI Information

/// Retrieves watch face UI information
/// - Parameters:
///   - block: The completion handler called with the watch face UI information
+ (void)getWatchfaceUIInformationWithBlock:(FitCloudWatchfaceUIInfoResultBlock _Nullable)block;

#pragma mark Toggle Watch Face

/// Switches to a watch face and modifies all its module styles
/// - Parameters:
///   - slotIndex: The target slot index (0-10) to switch to
///   - styleArray: Array of module styles to apply. Pass nil to only switch watch face without modifying styles
///   - completion: The completion handler called when the operation completes
+ (void)toggleWatchfaceWithSlotIndex:(NSInteger)slotIndex modulesStyleArray:(NSArray<NSNumber *> *_Nullable)styleArray completion:(FitCloudResultHandler)completion;

#pragma mark Delete the watchface

/// Delete the watchface
/// - Parameters:
///   - watchfaceNo: the watchface No.
///   - completion: the completion callback
+ (void)deleteWatchface:(NSInteger)watchfaceNo completion:(FitCloudResultHandler)completion;

/// Delete the watchface with slot index
/// - Parameters:
///   - slotIndex: the slot index, 0～10
///   - completion: the completion callback
+ (void)deleteWatchfaceWithSlotIndex:(NSInteger)slotIndex completion:(FitCloudResultHandler)completion;

#pragma mark Women's Health Settings

/// Configures women's health settings
/// - Parameters:
///   - whSetting: The women's health settings information
///   - block: The completion handler called when the operation completes
+ (void)setWomenHealthConfig:(FitCloudWomenHealthSetting *_Nonnull)whSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Get Women's Health Settings

/// Retrieves women's health settings
/// - Parameters:
///   - block: The completion handler called with the women's health settings
+ (void)getWomenHealthSettingWithBlock:(FitCloudWomenHealthSettingResultBlock _Nullable)block;

#pragma mark Classroom Mode

/// Configures classroom mode settings
/// - Parameters:
///   - classroomModeSetting: The classroom mode settings
///   - completion: The completion handler called when the operation completes
+ (void)setClassroomMode:(FitCloudClassroomModeSettingsModel *_Nonnull)classroomModeSetting completion:(FitCloudResultHandler _Nullable)completion;

/// Retrieves classroom mode settings
/// - Parameters:
///   - completion: The completion handler called with the classroom mode settings
+ (void)queryClassroomModeSettingWithCompletion:(void (^_Nullable)(BOOL success, FitCloudClassroomModeSettingsModel *_Nullable classroomModeSetting, NSError *_Nullable error))completion;


#pragma mark Emotion Settings

/// Configures emotion monitoring settings
/// - Parameters:
///   - settings: The emotion monitoring settings
///   - completion: The completion handler called when the operation completes
+ (void)sendEmotionSettings:(FitCloudEmotionSettingsModel *_Nonnull)settings completion:(FitCloudResultHandler _Nullable)completion;

/// Retrieves emotion monitoring settings
/// - Parameters:
///   - completion: The completion handler called with the emotion monitoring settings
///     - success: Whether the operation was successful
///     - settings: The retrieved emotion monitoring settings
///     - error: Error information if operation fails, nil on success
+ (void)queryEmotionSettingsWithCompletion:(void (^_Nullable)(BOOL success, FitCloudEmotionSettingsModel *_Nullable settings, NSError *_Nullable error))completion;

#pragma mark Lovers Features

/// Send lovers bonding notification to the device
/// - Parameters:
///   - notification: lovers bonding notification
///   - completion: the completion callback
+ (void)sendLoversBondingNotifcation:(FITCLOUDLOVERSBONDINGNOTIFICATION)notification completion:(FitCloudResultHandler _Nullable)completion;

/// Callback the lovers message send result
/// - Parameters:
///   - result: the lovers message send result
///   - completion: the completion callback
+ (void)callbackLoversMessageSendResult:(FITCLOUDLOVERSMESSAGESENDRESULT)result completion:(FitCloudResultHandler _Nullable)completion;

/// Set the love memorial day
/// - Parameters:
///   - loveMemorialDay: the love memorial day
///   - completion: the completion callback
+ (void)setLoveMemorialDay:(NSDate *)loveMemorialDay completion:(FitCloudResultHandler _Nullable)completion;

/// Set love memorial day reminder settings
/// - Parameters:
///   - hour: The hour component of reminder time (0-23), default 10
///   - minute: The minute component of reminder time (0-59), default 0
///   - daysInAdvance: Number of days in advance to remind, default 0
///   - completion: A completion handler called when setting completes. Parameters:
///     - success: Whether setting was successful
///     - error: Error information if setting fails, nil on success
+ (void)sendLoveMemorialDayReminderHour:(NSNumber *_Nullable)hour
                                 minute:(NSNumber *_Nullable)minute
                          daysInAdvance:(NSNumber *_Nullable)daysInAdvance
                             completion:(FitCloudResultHandler _Nullable)completion;

/// Received the lover message
/// - Parameters:
///   - message: the lover message
///   - completion: the completion callback
+ (void)receivedLoverMessage:(NSString *)message completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Other Modules Firmware Version

/// Query other modules firmware version
/// - Parameters:
///   - completion: The completion handler called with the firmware version
+ (void)queryOtherModulesFirmwareVersionsWithCompletion:(FitCloudOtherModulesFirmwareVersionQueryCompletion _Nullable)completion;

#pragma mark Lock Screen Settings

/// Configure lock screen settings
/// - Parameters:
///   - lockScreenSetting: The lock screen settings to apply
///   - block: The completion handler called when the operation completes
+ (void)setLockScreenSetting:(FitCloudLockScreenSetting *_Nonnull)lockScreenSetting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Exit Sleep Mode

/// Actively exit sleep mode from the app
/// - Parameters:
///   - block: The completion handler called when the operation completes
+ (void)exitSleepWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Synchronize the user language to the watch device

/// Synchronize the user language to the watch device
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the sync was successful
///     - error: Error information if sync fails, nil on success
/// - Warning: This method is only available if `watchPreferLang` of the FitCloudOption is not set to a specific language (e.g. `FITCLOUDLANGUAGE_ENGLISH`) during FitCloudKit initialization.
///
/// Priority order:
///    1. `watchPreferLang` of the FitCloudOption
///    2. iOS system language, if `preferSyncSystemLang` of the FitCloudOption is YES, may not effective for Apple's Per-App Language Settings.
///    3. App language
+ (void)syncUserLanguageToWatchWithCompletion:(void (^_Nullable)(BOOL success, NSError *_Nullable error))completion;

#pragma mark Synchronize a specific language to the watch device

/// Synchronize a specific language to the watch device
/// - Parameters:
///   - lang: The language to set
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the sync was successful
///     - error: Error information if sync fails, nil on success
/// - Warning: This method will change the `watchPreferLang` of the FitCloudOption to the specified language if the language is different from the current, and then synchronize the language to the watch device.
+ (void)syncSpecificLanguageToWatch:(FITCLOUDLANGUAGE)lang completion:(void (^_Nullable)(BOOL success, NSError *_Nullable error))completion;

#pragma mark Query the current language of the watch device

/// Query the current language of the watch device
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the query was successful
///     - lang: The current language of the watch device
///     - error: Error information if query fails, nil on success
+ (void)queryWatchLanguageWithCompletion:(void (^_Nullable)(BOOL success, FITCLOUDLANGUAGE lang, NSError *_Nullable error))completion;

#pragma mark Query the supported languages of the watch device
/// Query the supported languages of the watch device
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the query was successful
///     - supportedLanguages: Array of supported languages on the watch device, array elements are of type FITCLOUDLANGUAGE
///     - error: Error information if query fails, nil on success
+ (void)queryWatchSupportedLanguagesWithCompletion:(void (^_Nullable)(BOOL success, NSArray<NSNumber *> *_Nullable supportedLanguages, NSError *_Nullable error))completion;

#pragma mark - Watch language utilities

/// Get the Chinese display name for a language
/// - Parameters:
///   - language: The watch language
/// - Returns: The Chinese display name of the language
+ (NSString *)cnDisplayNameOfWatchLanguage:(FITCLOUDLANGUAGE)language;

#pragma mark Supported Games

/// Get the list of games supported by the watch
/// - Parameters:
///   - block: The completion handler called with the supported games
+ (void)getSupportedGamesWithBlock:(FitCloudSupportedGamesResultBlock _Nullable)block;

#pragma mark Top 3 Game Records

/// Get the top 3 records across all games
/// - Parameters:
///   - block: The completion handler called with the top 3 records
+ (void)getTop3RankGameRecordsWithBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;

#pragma mark Single Game Top 3 Records

/// Get the top 3 records for a specific game
/// - Parameters:
///   - gameNo: The game number to query
///   - block: The completion handler called with the top 3 records
+ (void)getSingleGameTop3RankGameRecords:(NSInteger)gameNo withBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;

#pragma mark Game Skins

/// Get skin information for all games on the watch
/// - Parameters:
///   - block: The completion handler called with the game skin information
+ (void)getAllGameSkinsWithBlock:(FitCloudAllGameSkinsResultBlock _Nullable)block;

#pragma mark Game Ranking Trends

/// Set game ranking trends
/// - Parameters:
///   - trendsArray: Array of ranking trends, maximum 60 entries
///   - block: The completion handler called when the operation completes
+ (void)setGameRankingTrendsArray:(NSArray<FitCloudGameRankingTrend *> *)trendsArray completion:(FitCloudResultHandler _Nullable)block;

#pragma mark - Game Play Statistics

/// Query game play count statistics from the watch
/// - Parameters:
///   - completion: A completion handler called when the query completes. Parameters:
///     - succeed: Whether the query was successful
///     - statistics: The game play statistics if query successful, nil otherwise
///     - error: Error information if query fails, nil on success
+ (void)queryGamePlayCountStatisticsWithCompletion:(void (^__nullable)(BOOL succeed, FitCloudGamePlayCountStatisticsModel *_Nullable statistics, NSError *_Nullable error))completion;

#pragma mark Screen and Vibration Settings

/// Get screen duration, brightness, vibration and other settings
/// - Parameters:
///   - block: The completion handler called with the settings information
+ (void)getScreenAndVibrateSettingsWithBlock:(FitCloudScreenAndVibrateSettingsResultBlock _Nullable)block;

#pragma mark Screen Resolution

/// Get screen resolution information
/// - Parameters:
///   - block: The completion handler called with the resolution information
+ (void)getScreenResolutionWithBlock:(FitCloudScreenResolutionResultBlock _Nullable)block;

#pragma mark Photo Push Parameters

/// Get photo album push feature parameters
/// - Parameters:
///   - block: The completion handler called with the parameters
+ (void)getPhotoPushParamsWithBlock:(FitCloudPhotoAlbumParamsResultBlock _Nullable)block;

#pragma mark Query the supported workout types on the watch

/// Query the supported workout types on the watch
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the query was successful
///     - workoutTypesArray: The array of supported workout types, nil if query fails
///     - error: Error information if query fails, nil on success
+ (void)querySupportedWorkoutOnWatchWithCompletion:(void (^_Nullable)(BOOL success, NSArray<NSNumber *> *_Nullable workoutTypesArray, NSError *_Nullable error))completion;

#pragma mark Query the workout slots on the watch

/// Query the workout slots on the watch
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the query was successful
///     - workoutSlots: The array of workout slots, nil if query fails
///     - error: Error information if query fails, nil on success
+ (void)queryWorkoutSlotsOnWatchWithCompletion:(void (^_Nullable)(BOOL success, NSArray<FitCloudWorkoutSlot *> *_Nullable workoutSlots, NSError *_Nullable error))completion;

#pragma mark QR Code Features

/// Get the list of supported payment and business card QR code features
/// - Parameters:
///   - block: The completion handler called with the supported features
+ (void)getWatchSpecifiedSupportedMoneyReceiveAndBusinessQRCodeFeaturesWithBlock:(FitCloudQRCodeFeaturesResultBlock _Nullable)block;

#pragma mark Medal Management

/// Set medal list (sync medals from phone to watch)
/// - Parameters:
///   - medals: The array of medals to sync
///   - block: The completion handler called when the operation completes
+ (void)setMedals:(NSArray<FitCloudMedal *> *_Nullable)medals block:(FitCloudResultHandler _Nullable)block;

/// Get medal list from the watch
/// - Parameters:
///   - block: The completion handler called with the medal list
+ (void)getMedalsWithBlock:(FitCloudMedalsResultBlock _Nullable)block;

#pragma mark Schedule Types

/// Get supported schedule types from the watch
/// - Parameters:
///   - block: The completion handler called with the supported schedule types
+ (void)getSupportedSchedulesWithBlock:(FitCloudSupportedSchedulesResultBlock _Nullable)block;

#pragma mark Screen and Vibration Configuration

/// Configure screen duration, brightness, vibration and other settings
/// - Parameters:
///   - screenSettings: The screen settings to apply
///   - vibrateSettings: The vibration settings to apply
///   - block: The completion handler called when the operation completes
+ (void)setScreenSettings:(FitCloudScreenSetting *)screenSettings vibrateSettings:(FitCloudVibrateSetting *)vibrateSettings completion:(FitCloudResultHandler _Nullable)block;

#pragma mark Find Watch

/// Find watch (triggers vibration or sound alert on success)
/// - Parameters:
///   - comletion: The completion handler called when the operation completes
+ (void)findWatchWithCompletion:(FitCloudResultHandler _Nullable)comletion;

/// Stop finding watch
/// - Parameters:
///   - comletion: The completion handler called when the operation completes
+ (void)stopFindWatchWithCompletion:(FitCloudResultHandler _Nullable)comletion;

#pragma mark Factory Reset

/// Restore watch to factory settings
/// - Parameters:
///   - block: The completion handler called when the operation completes
+ (void)restoreAsFactorySettingsWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Power Management

/// Turn off the watch
/// - Parameters:
///   - block: The completion handler called when the operation completes
+ (void)turnOffWithBlock:(FitCloudResultHandler _Nullable)block;

/// Reboot the watch
/// - Parameters:
///   - block: The completion handler called when the operation completes
+ (void)rebootWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Custom Broadcast Key

/// Set custom broadcast data field key1
/// - Parameters:
///   - keyData: Custom key data, must be 6 bytes and byte order must be managed by caller
///   - block: The completion handler called when the operation completes
+ (void)setCustomBroadcastKey:(NSData *)keyData withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Location Services

/// Notify watch of current app location service status
/// - Parameters:
///   - state: The app location service state
///   - block: The completion handler called when the operation completes
+ (void)notifyAppLocServiceState:(APPLOCATIONSERVICESTATE)state withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark QR Code Push

/// Push payment or business card QR code
/// - Parameters:
///   - qrcode: The QR code type
///   - content: The QR code content
///   - block: The completion handler called when the operation completes
+ (void)sendQRCode:(FITCLOUDQRCODE)qrcode content:(NSString *)content withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Watch Launch Vibration

/// Set watch launch vibration parameters
/// - Parameters:
///   - param: The vibration parameters
///   - block: The completion handler called when the operation completes
+ (void)setWatchLaunchVibrateParam:(FitCloudWatchLaunchVibrateSetting *)param withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Message Management

/// Delete stored messages from watch
/// - Parameters:
///   - deleteIndex: Index to delete (0 to n-1, 0 is newest), valid when shouldDeleteAll is false
///   - shouldDeleteAll: Whether to delete all messages
///   - block: The completion handler called when the operation completes
+ (void)deleteWatchMessageWithIndex:(NSInteger)deleteIndex shouldDeleteAll:(BOOL)shouldDeleteAll withBlock:(FitCloudResultHandler _Nullable)block;

/// Dismiss current message display on watch
/// - Parameters:
///   - block: The completion handler called when the operation completes
+ (void)dismissCurrentWatchMessageWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Game Lock

/// Configure game lock settings
/// - Parameters:
///   - setting: The game lock settings to apply
///   - block: The completion handler called when the operation completes
+ (void)setGamePasscodeSetting:(FitCloudGamePasscodeSetting *_Nonnull)setting block:(FitCloudResultHandler _Nullable)block;

#pragma mark Find Phone

/// Notify watch that find phone ring playback has ended
/// - Parameters:
///   - block: The completion handler called when the operation completes
+ (void)notifyAppFindiPhoneRingPlayEndWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Third-party Integration

/// Send Alipay IoT data
/// - Parameters:
///   - aliotData: The Alipay IoT data
///   - block: The completion handler called when the operation completes
+ (void)sendAliotData:(NSData *)aliotData withBlock:(FitCloudResultHandler _Nullable)block;

/// Send NetEase Cloud Music bridge data
/// - Parameters:
///   - data: The NetEase Cloud Music bridge data
+ (void)sendNetEaseBridgeData:(NSData *)data;

/// Send WeChat Pay authentication bridge data
/// - Parameters:
///   - data: The WeChat Pay authentication bridge data
+ (void)sendWPAuthBridgeData:(NSData *)data;

/// Send Skyworth PV data
/// - Parameters:
///   - stations: PV power station data, maximum 6 stations (extras ignored)
///   - block: The completion handler called when the operation completes
+ (void)sendSkyworthPVData:(NSArray<SkyworthPVPowerStationObject *> *)stations withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark Cricket Match Data

/// Send upcoming cricket match data
/// - Parameters:
///   - matches: Match data, maximum 2 matches
///   - block: The completion handler called when the operation completes
+ (void)sendUpcomingCricketMatchData:(NSArray<FitCloudCricketUpcomingMatch *> *)matches withBlock:(FitCloudResultHandler _Nullable)block;

/// Send live cricket match data
/// - Parameters:
///   - matches: Match data, maximum 2 matches
///   - block: The completion handler called when the operation completes
+ (void)sendLiveCricketMatchData:(NSArray<FitCloudCricketLiveMatch *> *)matches withBlock:(FitCloudResultHandler _Nullable)block;

/// Send ended cricket match data
/// - Parameters:
///   - matches: Match data, maximum 2 matches
///   - block: The completion handler called when the operation completes
+ (void)sendEndedCricketMatchData:(NSArray<FitCloudCricketEndedMatch *> *)matches withBlock:(FitCloudResultHandler _Nullable)block;

/// Set cricket match score list order
/// - Parameters:
///   - match1order: Match 1 order
///   - match2order: Match 2 order
///   - block: The completion handler called when the operation completes
+ (void)sendCricketMatchScoreListOrderWith:(FitCloudCricketMatchScoreOrder *)match1order match2order:(FitCloudCricketMatchScoreOrder *)match2order withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark GPS Related Features

/// Report GPS location data to the watch
/// - Parameters:
///   - locationDataModel: The GPS location data model
///   - completion: A completion block called when the operation finishes. Parameters:
///     - succeed: Whether the operation was successful
///     - error: Error information if operation fails, nil on success
+ (void)reportGPSLocationData:(FitCloudLocationDataModel *)locationDataModel withCompletion:(void (^__nullable)(BOOL succeed, NSError *error))completion;

#pragma mark GPS File Related Features

/// GPS File refers to GPS EPO (Extended Prediction Orbit) file, which contains
/// satellite orbital data to enable faster GPS positioning and acquisition.

/// Check if the GPS file at the specified path has expired
/// - Parameters:
///   - filePath: The path to the GPS file to check
///   - error: On failure, contains error information about why the check failed
/// - Returns: `true` if the GPS file has expired, `false` if it has not expired
///
/// - Experiment: This method helps you to check the expiration status of a GPS EPO (Extended Prediction Orbit) file stored locally on the iPhone device.
+ (BOOL)isGPSFileExpired:(NSString *)filePath error:(NSError **)error;

/// Query whether the watch device currently allows GPS file upload
/// - Parameters:
///   - completion: A completion handler called with the query result. Parameters:
///     - success: Whether the query was successful
///     - allowUpload: Whether GPS file upload is currently allowed
///     - error: Error information if query fails
+ (void)queryWhetherWatchDeviceAllowsUploadGPSFileNowWithCompletion:(void (^_Nullable)(BOOL success, BOOL allowUpload, NSError *_Nullable error))completion;

/// Queries the expiration time of the GPS file on the watch device
/// - Parameters:
///   - completion: A completion handler called when the query finishes
///   - success: Whether the query was successful
///   - expireTimeModel: The expiration time model containing GPS week number and time of week, nil if query failed
///   - error: An error object that indicates why the query failed, or nil if successful
+ (void)queryGPSFileOnWatchDeviceExpireTimeWithCompletion:(void (^_Nullable)(BOOL success, FitCloudGPSFileExpireTimeModel *_Nullable expireTimeModel, NSError *_Nullable error))completion;

/// Query current GPS file state on watch device
/// - Parameters:
///   - completion: A completion handler called with the query result. Parameters:
///     - success: Whether the query was successful
///     - state: The GPS file state (unknown/not exist/good/need update/expired)
///     - error: Error information if query fails
+ (void)queryGPSFileStateOnWatchDeviceWithCompletion:(void (^_Nullable)(BOOL success, FITCLOUDWATCHGPSFILESTATE state, NSError *_Nullable error))completion;

/// Enter GPS file upload mode on the watch device
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether entering upload mode was successful
///     - error: Error information if operation fails, nil on success
+ (void)enterGPSFileUploadModeWithCompletion:(void (^_Nullable)(BOOL success, NSError *_Nullable error))completion;

/// Delete the GPS file on the watch device
/// - Parameters:
///   - completion: A completion handler called with the result. Parameters:
///     - success: Whether the operation was successful
///     - error: Error information if operation fails, nil on success
+ (void)deleteGPSFileOnWatchDeviceWithCompletion:(void (^_Nullable)(BOOL success, NSError *_Nullable error))completion;

#pragma mark Navigation

/// The navigation start callback
/// - Parameters:
///   - map: the navigation map
///   - naviType: navi type
///   - completion: completion callback
+ (void)onNaviStartWithMap:(FITCLOUDROUTEPLANMAPPROVIDER)map type:(FITCLOUDROUTEPLANNAVITYPE)naviType withCompletion:(FitCloudResultHandler _Nullable)completion;

/// The navigation guide kind callback
/// - Parameters:
///   - guideKind: the guide kind
///   - completion: completion callback
+ (void)onNaviGuideKind:(FITCLOUDROUTEPLANGUIDEKIND)guideKind withCompletion:(FitCloudResultHandler _Nullable)completion;

/// The navigation guide text callback
/// - Parameters:
///   - guideText: the guide text
///   - completion: completion callback
+ (void)onNaviGuideText:(NSString *)guideText withCompletion:(FitCloudResultHandler _Nullable)completion;

/// The remain time for navigation update callback
/// - Parameters:
///   - remainTime: the remain time in seconds
///   - completion: completion callback
+ (void)onNaviRemainTimeUpdate:(NSInteger)remainTime withCompletion:(FitCloudResultHandler _Nullable)completion;

/// The remain distance for navigation update callback
/// - Parameters:
///   - remainDistance: the remain distance in meters
///   - completion: completion callback
+ (void)onNaviRemainDistanceUpdate:(NSInteger)remainDistance withCompletion:(FitCloudResultHandler _Nullable)completion;

/// The navigation arrive destination callback
/// - Parameters:
///   - completion: completion callback
+ (void)onNaviArriveDestination:(NSString *_Nullable)destination withCompletion:(FitCloudResultHandler _Nullable)completion;

/// The naviagation exit callback
/// - Parameters:
///   - completion: completion callback
+ (void)onNaviExitWithCompletion:(FitCloudResultHandler _Nullable)completion;

#pragma mark 电子卡包

/// Query the electronic cards from the smart watch
/// - Parameters:
///   - block: the electronic cards query result
+ (void)getECardsWithBlock:(FitCloudECardsResultBlock _Nullable)block;

/// Set the electronic card
/// - Parameters:
///   - ecard: the electronic card
///   - block: the electronic card set response
+ (void)setECard:(FitCloudECard *)ecard withBlock:(FitCloudResultHandler _Nullable)block;

/// sort the electronic cards
/// - Parameters:
///   - idArray: the electronic card id array
///   - block: the electronic cards sort response
+ (void)sortECardsWithIdArray:(NSArray<NSNumber *> *)idArray withBlock:(FitCloudResultHandler _Nullable)block;

/// delete the electronic cards
/// - Parameters:
///   - idArray: the electronic card id array
///   - block: the electronic cards delete response
+ (void)deleteECardsWithIdArray:(NSArray<NSNumber *> *)idArray withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark - 其他

/// 设置运动极限心率 (Set maximum exercise heart rate)
/// - Parameters:
///   - value: 运动极限心率 (maximum exercise heart rate)
///   - completion: the completion callback
+ (void)setMaxExerciseHeartRate:(NSInteger)value withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 获取运动极限心率 (Query maximum exercise heart rate)
/// - Parameters:
///   - completion: the completion callback
+ (void)queryMaxExerciseHeartRateWithCompletion:(void (^_Nullable)(BOOL success, NSInteger maxExerciseHeartRate, NSError *_Nullable error))completion;

/// 查询手表上的静息心率数据
/// - Parameters:
///   - completion: 结果回调
+ (void)queryRestingHRWithCompletion:(FitCloudRestingHRQueryCompletion _Nullable)completion;

#pragma mark - 耳机仓

/// 设置耳机仓歌词颜色 (Set earbud case lyrics color)
/// - Parameters:
///   - lyricsColor: 歌词颜色 (lyrics color)
///   - completion: the completion callback
+ (void)setEarbudCaseLyricsColor:(UIColor *)lyricsColor withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 查询耳机仓歌词颜色 (Query earbud case lyrics color)
/// - Parameters:
///   - completion: the completion callback
+ (void)queryEarbudCaseLyricsColorWithCompletion:(void (^_Nullable)(BOOL success, UIColor *_Nullable lyricsColor, NSError *_Nullable error))completion;

/// 设置耳机仓充电壁纸是否常亮 (Set earbud case charging wallpaper whether always bright)
/// - Parameters:
///   - alwaysBright: 是否常亮
///   - completion: the completion callback
+ (void)setEarbudCaseChargingWallpaperAlwaysBright:(BOOL)alwaysBright withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 查询耳机仓充电壁纸是否常亮 (Query earbud case charging wallpaper whether always bright)
/// - Parameters:
///   - completion: the completion callback
+ (void)queryEarbudCaseChargingWallpaperWhetherAlwaysBrightWithCompletion:(void (^_Nullable)(BOOL success, BOOL alwaysBright, NSError *_Nullable error))completion;

/// 设置耳机仓鼠标起始点预设 (Set earbud case mouse start point preset)
/// - Parameters:
///   - preset: 预设，取值范围从 0 开始
///   - completion: the completion callback
+ (void)setEarbudCaseMouseStartPointPreset:(NSInteger)preset withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 查询耳机仓鼠标起始点预设 (Query earbud case mouse start point preset)
/// - Parameters:
///   - completion: the completion callback
///     - success: 是否查询成功
///     - currentPreset: 当前预设，取值范围从 0 开始
///     - totalPresetsCount: 预设总数
+ (void)queryEarbudCaseMouseStartPointPresetWithCompletion:(void (^_Nullable)(BOOL success, NSInteger currentPreset, NSInteger totalPresetsCount, NSError *_Nullable error))completion;

#pragma mark - 激光测量

/// 开始激光测量
/// - Parameters:
///   - durationInSeconds: 测量时长，单位：秒，时长范围 1～255
///   - completion: the completion callback
///
/// >Important: the valid measurement duration is from 1s to 255s
+ (void)startLaserMeasurementWithDuration:(NSInteger)durationInSeconds completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// 结束激光测量
/// - Parameters:
///   - completion: the completion callback
+ (void)stopLaserMeasurementWithCompletion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// 查询激光测量状态
/// - Parameters:
///   - completion: the completion callback
+ (void)queryLaserMeasurementStatusWithCompletion:(void (^__nullable)(BOOL succeed, FITCLOUDWEARINGSTATUS wearingStatus, FITCLOUDLASERMEASUREMENTSTATUS measurementStatus, NSError *_Nullable error))completion;

#pragma mark - Muslim prayer

/// Set the muslim prayer alarm clock
/// - Parameters:
///   - alarmClock: the alarm clock
///   - completion: the completion callback
+ (void)setMuslimPrayerAlarmClock:(FitCloudMuslimPrayerAlarmClockModel *)alarmClock completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Set the current islamic events information
/// - Parameters:
///   - events: the islamic events, with maximum 6 events
///   - completion: the completion callback
+ (void)setCurrentIslamicEvents:(NSArray<FitCloudIslamicEventModel *> *)events completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Set the kaaba data information
/// - Parameters:
///   - events: the kaaba data
///   - completion: the completion callback
+ (void)setKaabaData:(FitCloudKaabaModel *)kaabaData completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

#pragma mark - App Side Permission Status

/// Send app-side permission status array to watch
/// - Parameters:
///   - permissionStatusArray: Array of permission status models containing app-side permission information
///   - completion: A completion handler called when sending completes. Parameters:
///     - succeed: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendAppSidePermissionStatusArray:(NSArray<FitCloudAppSidePermissionStatusModel *> *)permissionStatusArray completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

#pragma mark - Go More Algorithm

/// Send GoMore algorithm key query result to watch
/// - Parameters:
///   - code: The return code indicating query result status
///   - key: The algorithm key string if query successful, nil otherwise
///   - completion: A completion handler called when sending completes. Parameters:
///     - succeed: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendGoMoreAlgorithmKeyQueryResultWithCode:(FITCLOUDGOMOREALGORITHMKEYRETURNCODE)code key:(NSString *_Nullable)key completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

#pragma mark - Parent Control

/// Send parent control settings to the watch
/// - Parameters:
///   - settings: The parent control settings model containing configuration options
///   - completion: A completion handler called when sending completes. Parameters:
///     - succeed: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendParentControlSettings:(FitCloudParentControlSettingsModel *)settings completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Query parent control settings from the watch
/// - Parameters:
///   - completion: A completion handler called when the query completes. Parameters:
///     - succeed: Whether the query was successful
///     - settings: The parent control settings if query successful, nil otherwise
///     - error: Error information if query fails, nil on success
+ (void)queryParentControlSettingsWithCompletion:(void (^__nullable)(BOOL succeed, FitCloudParentControlSettingsModel *_Nullable settings, NSError *_Nullable error))completion;

#pragma mark - App Usage Statistics

/// Query app usage count statistics from the watch
/// - Parameters:
///   - completion: A completion handler called when the query completes. Parameters:
///     - succeed: Whether the query was successful
///     - statistics: The app usage statistics if query successful, nil otherwise
///     - error: Error information if query fails, nil on success
+ (void)queryAppUsageCountStatisticsWithCompletion:(void (^__nullable)(BOOL succeed, FitCloudAppUsageCountStatisticsModel *_Nullable statistics, NSError *_Nullable error))completion;

/// Reset app usage statistics on the watch, including app usage counts and durations
/// - Parameters:
///   - completion: A completion handler called when the reset completes. Parameters:
///     - succeed: Whether the reset was successful
///     - error: Error information if reset fails, nil on success
+ (void)resetAppUsageStatisticsWithCompletion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

#pragma mark - AI Health

/// Sends an AI-generated health analysis report to the watch
/// - Parameters:
///   - report: The AI health analysis report model containing the analysis results
///   - completion: A completion handler called when sending completes. Parameters:
///     - succeed: Whether sending was successful 
///     - error: Error information if sending fails, nil on success
+ (void)sendAIHealthAnalysisReport:(FitCloudAIHealthAnalysisReportModel *)report completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Sends AI-generated health advice recommendations to the watch
/// - Parameters:
///   - advices: The AI health advice model containing the recommendations
///   - completion: A completion handler called when sending completes. Parameters:
///     - succeed: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendAIHealthAdvices:(FitCloudAIHealthAdvicesModel *)advices completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;


#pragma mark - World clock

/// Sends world clock settings to the watch
/// - Parameters:
///   - worldClockArray: Array of world clock models to sync to the watch
///   - completion: The completion handler called when sending completes
///     - succeed: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendWorldClockArray:(NSArray<FitCloudWorldClockModel *> *)worldClockArray completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Queries world clock settings from the watch
/// - Parameters:
///   - completion: The completion handler called with the query results
///     - succeed: Whether the query was successful
///     - worldClockArray: Array of world clock models retrieved from the watch, nil if query fails
///     - error: Error information if query fails, nil on success
+ (void)queryWorldClockArrayWithCompletion:(void (^__nullable)(BOOL succeed, NSArray<FitCloudWorldClockModel *> *_Nullable worldClockArray, NSError *_Nullable error))completion;

@end

/// FitCloudKit Bind Module
@interface FitCloudKit (Bind)

#pragma mark 是否已经绑定

/// 是否已经绑定
+ (BOOL)alreadyBound;

#pragma mark 检查用户是否已经绑定

/// 检查用户是否已经绑定
/// - Parameters:
///   - userId: 用户 Id
/// - Returns:
///  YES 已经绑定 NO 未绑定
+ (BOOL)isUserAlreadyBound:(NSString *)userId;

#pragma mark 绑定用户

/// 绑定用户
/// - Parameters:
///   - userId: 用户 Id
///   - randomCode: 随机码，如果没有，则填 nil，仅部分项目有该功能
///   - bAbort: 如果已经存在绑定用户是否终止，当为 FALSE 时，自动先解绑并绑定新的用户
///   - block: 结果回调
+ (void)bindUserObject:(NSString *)userId randomCode:(NSString *_Nullable)randomCode abortIfExist:(BOOL)bAbort block:(FitCloudResultHandler _Nullable)block;

#pragma mark 最后绑定时间

/// 最后绑定时间
+ (nullable NSDate *)lastBindDate;

#pragma mark 用户解绑

/// 用户解绑
/// - Parameters:
///   - shouldDisconnectWhenSuccess: 解绑成功后是否应该自动断开连接
///   - block: 结果回调
+ (void)unbindUserObject:(BOOL)shouldDisconnectWhenSuccess block:(FitCloudResultHandler _Nullable)block;

@end

/// FitCloudKit Sports Module
@interface FitCloudKit (Sports)

#pragma mark 请求最新的健康测量数据

/// 请求最新的健康测量数据
/// - Parameters:
///   - block: 结果回调
+ (void)requestLatestHealthMeasurementDataWithBlock:(FitCloudLatestHealthMeasurementDataResultBlock _Nullable)block;

#pragma mark 请求当天运动健康数据信息

/// 请求当天运动健康数据信息
/// - Parameters:
///   - block: 结果回调
+ (void)requestHealthAndSportsDataTodayWithBlock:(FitCloudHealthAndSportsDataTodayResultBlock _Nullable)block;

#pragma mark 启动/停止实时健康测量（心率、血氧、血压、呼吸频率等）

/// 启动/停止实时健康测量（心率、血氧、血压、呼吸频率等）
/// - Parameters:
///   - rtmParam: 实时测量参数
///   - block: 调用结果回调
+ (void)requestRealTimeHealthMeasuring:(FitCloudRealTimeHealthMeasuringParam *_Nonnull)rtmParam block:(FitCloudResultHandler _Nullable)block;

#pragma mark 手动同步历史运动健康数据

/// 手动同步历史运动健康数据
/// - Parameters:
///   - option: 选项，默认 `FITCLOUDDATASYNCOPTION_LEGACY`
///   - progress: 进度回调
///   - block: 结果回调
///   - finished: 结束回调，如果你希望在数据同步结束后执行一些其他指令，请在这里操作
+ (void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable)block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;

#pragma mark 请求当天睡眠调试数据

/// 请求当天睡眠调试数据
/// - Parameters:
///   - block: 结果回调，代表请求是否成功，不代表数据返回成功
+ (void)requestSleepDebugDataWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 启动/关闭手表GPS互联运动

/// 启动/关闭 GPS 互联运动
/// - Parameters:
///   - params: 参数
///   - block: 调用结果回调
+ (void)requestRealTimeGPSConnectSports:(FitCloudSportsWithGPSActionParams *_Nonnull)params block:(FitCloudResultHandler _Nullable)block;

#pragma mark 通知手表GPS互联运动当前App端运动数据

/// 通知手表 GPS 互联运动当前 App 端运动数据
/// - Parameters:
///   - appClientData: 已运动信息
///   - block: 调用结果回调
+ (void)notifyRealTimeGPSConnectSportsAppClientData:(FitCloudSportsWithGPSAppClientData *_Nonnull)appClientData block:(FitCloudResultHandler _Nullable)block;

#pragma mark 请求手表GPS互联运动当前状态

/// 请求手表 GPS 互联运动当前状态
/// - Parameters:
///   - block: 调用结果回调
+ (void)requestRealTimeGPSConnectSportsCurrentStatusWithBlock:(FitCloudGPSConnectSportsCurrentStatusResultBlock _Nullable)block;

#pragma mark 开启GSensor

/// 开启 GSensor
/// - Parameters:
///   - block: 结果回调
+ (void)openGSensorWithBlock:(FitCloudOpenGSensorResultBlock _Nullable)block;

#pragma mark 关闭GSensor

/// 关闭 GSensor
///  - Parameters:
///    - block: 结果回调
+ (void)closeGSensorWithBlock:(FitCloudResultHandler _Nullable)block;

@end

/// FitCloudKit RemoteCtrl Module
@interface FitCloudKit (RemoteCtrl)

#pragma mark APP通知手表当前APP的相机状态（前台/后台）

/// APP 通知手表当前 APP 的相机状态（前台/后台）
/// - Parameters:
///   - state: APP 相机状态（前台/后台）
///   - block: 结果回调
+ (void)notifyAppCameraState:(APPCAMERASTATE)state withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark APP通知手表切换前后摄像头是否成功

/// APP 通知手表切换前后摄像头是否成功
/// - Parameters:
///   - success: APP 切换前后摄像头是否成功
///   - completion: 结果回调
+ (void)notifyAppToggleCameraResult:(BOOL)success completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark 通知手表第三方外设启停操作结果

/// 通知手表第三方外设启停操作结果
/// - Parameters:
///   - result: 结果
///   - block: 结果回调
+ (void)notifyThirdPartyPeripheralStartStopResult:(THIRDPARTYPERIPHERALACTIONRESULT)result withBlock:(FitCloudResultHandler)block;

#pragma mark 通知手表第三方外设数据

/// 通知手表第三方外设数据
/// - Parameters:
///   - peripheral: 外设
///   - value: 数据
///   - block: 结果回调
+ (void)notifyThirdPartyPeripheral:(THIRDPARTYPERIPHERAL)peripheral value:(CGFloat)value withBlock:(FitCloudResultHandler)block;
@end

/// FitCloudKit Dump Module
@interface FitCloudKit (Dump)

#pragma mark 发送Alexa结果

/// 发送 Alexa 结果
/// - Parameters:
///   - text: 结果
///   - errorCode: 错误码
///   - block: 结果回调
+ (void)sendAlexaResult:(NSString *)text with:(ALEXAINVOKEERROR)errorCode withBlock:(FitCloudResultHandler _Nullable)block;

@end

/// FitCloudKit DeviceLog Module
@interface FitCloudKit (DeviceLogs)

#pragma mark Request Device Debug Logs

/// Request Device Debug Logs
/// - Parameters:
///   - completion: the completion callback
+ (void)requestDeviceDebugLogsDataWithCompletion:(void (^_Nullable)(BOOL success, NSData *_Nullable logsData, NSError *_Nullable error))completion;

@end

/// 大模型
@interface FitCloudKit (LLM)

#pragma mark 发送大模型结果

/// 发送大模型结果
/// - Parameters:
///   - text: 结果
///   - isEnd: 是否结束
///   - resultType: 文案类型
///   - completion: 结果回调
+ (void)sendLLMResult:(NSString *)text isEnd:(BOOL)isEnd resultType:(LLMRESULTTYPE)resultType completion:(FitCloudResultHandler _Nullable)completion;

@end

/// Translation
@interface FitCloudKit (Translate)

#pragma mark Send Translation Result

/// Send translation result
/// - Parameters:
///   - text: The translation result text
///   - isEnd: Whether this is the final result
///   - textType: The type of text content
///             - TRANSLATETEXTTYPE_ORIGINAL: Original text content
///             - TRANSLATETEXTTYPE_TRANSLATION: Translated text content
///   - completion: The completion handler called when sending completes
+ (void)sendTranslationText:(NSString *)text isEnd:(BOOL)isEnd resultType:(TRANSLATETEXTTYPE)textType completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark Report Device MAC Address Translation Feature Not Registered

/// Report to watch that current MAC address is not registered with translation service provider
/// - Parameters:
///   - completion: The completion handler
+ (void)reportDeviceMacAddressTranslateFeatureNotRegistered:(FitCloudResultHandler _Nullable)completion;

@end

@interface FitCloudKit (ASR)

/// Send ASR (Automatic Speech Recognition) result to watch
/// - Parameters:
///   - text: The ASR result text to send
///   - completion: A completion handler called when sending completes. Parameters:
///     - success: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendASRResult:(NSString *)text completion:(FitCloudResultHandler _Nullable)completion;

@end

@interface FitCloudKit (AIWatchFace)

/// Sends an AI-generated photo to the connected watch device.
///
/// Use this method to transfer an AI-generated image to the watch for display. The transfer
/// progress is reported through the progress handler, and completion status through the completion handler.
///
/// - Parameters:
///   - image: The AI-generated UIImage to send to the watch
///   - progressHandler: A closure called periodically with transfer progress updates
///     - progress: The current transfer progress from 0.0 to 1.0
///   - completion: A closure called when the transfer completes
///     - succeed: Whether the transfer completed successfully
///     - avgSpeed: The average transfer speed in bytes per second
///     - error: An error object if the transfer failed, or nil on success
+ (void)sendAIGeneratedPhoto:(UIImage *)image progress:(void (^_Nullable)(CGFloat progress))progressHandler completion:(void (^_Nullable)(BOOL succeed, CGFloat avgSpeed, NSError *_Nullable error))completion;

/// Send AI photo generation result to watch
/// - Parameters:
///   - resultCode: The result code indicating generation status
///   - completion: A completion handler called when sending completes. Parameters:
///     - success: Whether sending was successful
///     - error: Error information if sending fails, nil on success
+ (void)sendAIPhotoGenerationResult:(FITCLOUDAIPHOTOGENRESULT)resultCode completion:(FitCloudResultHandler _Nullable)completion;

@end

@interface FitCloudKit (IncomingCallPhoto)

/// Queries the suggested size for incoming call contact photos
/// - Parameters:
///   - completion: The completion handler called with the query result
///     - succeed: Whether the query was successful
///     - photoSize: An NSValue containing the suggested CGSize for photos, or nil if query failed
///     - error: An error object if the query failed, or nil on success
/// 
/// Use this method to get the recommended dimensions for contact photos that will be displayed for incoming calls on the watch.
/// The watch may have specific size requirements to optimize display and storage of these photos.
+ (void)queryIncomingCallPhotoSuggestedSizeWithCompletion:(void (^_Nullable)(BOOL succeed, NSValue*_Nullable photoSize, NSError *_Nullable error))completion;

/// Queries the available photo slots for incoming call display on the watch
/// - Parameters:
///   - completion: A block called when the query completes
///     - succeed: Whether the query was successful
///     - slots: An array of photo slot models containing information about each available slot, or nil if query failed
///     - error: Any error that occurred during the query, or nil if successful
+ (void)queryIncomingCallPhotoSlotsWithCompletion:(void (^_Nullable)(BOOL succeed, NSArray<FitCloudIncomingCallPhotoSlotModel *> *_Nullable slots, NSError *_Nullable error))completion;

/// Updates a photo slot for incoming call display on the watch
/// - Parameters:
///   - slotIndex: The index of the photo slot to update (0-based)
///   - phoneNumber: The phone number associated with this photo
///   - image: The contact photo to display for incoming calls
///   - progressHandler: A block called with progress updates during the transfer (0.0 to 1.0)
///   - completion: A block called when the update completes
///     - succeed: Whether the update was successful
///     - avgSpeed: The average transfer speed in bytes per second
///     - error: Any error that occurred during the update, or nil if successful
+ (void)updateIncomingCallPhotoSlot:(NSUInteger)slotIndex withPhoneNumber:(NSString*)phoneNumber photo:(UIImage*)image progress:(void (^_Nullable)(CGFloat progress))progressHandler completion:(void (^_Nullable)(BOOL succeed, CGFloat avgSpeed, NSError *_Nullable error))completion;

/// Clears a photo slot used for incoming call display
/// - Parameters:
///   - slotIndex: The index of the photo slot to clear (0-based)
///   - completion: A block called when the clear operation completes
+ (void)clearIncomingCallPhotoSlot:(NSUInteger)slotIndex completion:(FitCloudResultHandler _Nullable)completion;


@end

@interface FitCloudKit (FestivalWish)

/// Sends festival wishes to the watch
/// - Parameters:
///   - wishArray: An array of festival wish time models containing the festival wishes to be sent
///   - completion: the completion callback
///
/// This method allows sending festival wishes and greetings to be displayed on the watch at specified times.
/// The wishes are defined using FitCloudFestivalWishTimeModel objects that specify the content and timing.
+ (void)sendFestivalWishArray:(NSArray<FitCloudFestivalWishTimeModel *> *)wishArray completion:(FitCloudResultHandler _Nullable)completion;

@end

/// 拍照实时预览
@interface FitCloudKit (CameraLivePreview)

#pragma mark 发送相机实时预览图JPG图片数据

/// 发送拍照实时预览图 JPG 图片数据
/// - Parameters:
///   - imageDataArray: 相机实时预览图 JPG 图片数据数组，一张完整的图片需要从上到下按 n 等份切割后传输给手表
///   - userInfo: 用户附加信息
+ (void)sendCameraLivePreviewData:(NSArray<NSData *> *)imageDataArray userInfo:(NSDictionary *_Nullable)userInfo;

@end

/// 地图导航快照
@interface FitCloudKit (MapNavigationSnapshot)

#pragma mark 发送相机实时预览图JPG图片数据

/// 发送地图导航快照 JPG 图片数据
/// - Parameters:
///   - imageDataArray: 地图导航快照 JPG 图片数据数组，一张完整的图片需要从上到下按 n 等份切割后传输给手表
///   - userInfo: 用户附加信息
+ (void)sendMapNavigationSnapshotData:(NSArray<NSData *> *)imageDataArray userInfo:(NSDictionary *_Nullable)userInfo;

@end

/// FitCloudKit Mockup
@interface FitCloudKit (Mockup)

#pragma mark 模拟接收到远程手表发来的指令

/// mockup remote command
/// - Parameters:
///   - hexData: 十六进制字符串，0x 开头
+ (void)mockupRemoteCommandWithData:(NSString *)hexData;

@end

/// New OTA Module
@interface FitCloudKit (NewOTA)

#pragma mark Check Watch New OTA Environment

/// Check if the watch environment supports new OTA upgrade, such as sufficient battery level
/// - Parameters:
///   - completion: The completion handler called with the environment check result
+ (void)checkNewOTAEnvironmentWithCompletion:(FitCloudNewOTAEnvironmentCheckCompletion)completion;

#pragma mark Send New OTA File

/// Send new OTA upgrade file
/// This method should be called on a background thread if possible
/// - Parameters:
///   - newOTAFilePath: The path to the new OTA upgrade file
///   - startConfirmResult: The callback for upgrade start confirmation, indicating whether OTA upgrade started successfully
///   - progress: The callback for transfer progress updates
///   - completion: The completion handler called when the transfer completes
+ (void)sendNewOTA:(NSString *)newOTAFilePath startConfirmResult:(FitCloudNewOTAStartConfirmResultBlock _Nullable)startConfirmResult progress:(FitCloudNewOTAProgressBlock _Nullable)progress completion:(FitCloudNewOTACompletionBlock _Nullable)completion;

#pragma mark Cancel New OTA File Transfer

/// Cancel the ongoing new OTA file transfer if needed
/// - Parameters:
///   - completion: The completion handler called when the cancellation completes
+ (void)cancelSendTheNewOTAIfNeededWithCompletion:(FitCloudNewOTACancelCompletionBlock _Nullable)completion;

@end

NS_ASSUME_NONNULL_END
