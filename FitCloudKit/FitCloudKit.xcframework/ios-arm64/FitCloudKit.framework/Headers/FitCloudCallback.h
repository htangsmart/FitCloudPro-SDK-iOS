//
//  FitCloudCallback.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/21.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#ifndef FitCloudCallback_h
#define FitCloudCallback_h
#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudAlarmObject.h>
#import <FitCloudKit/FitCloudFirmwareVersionObject.h>
#import <FitCloudKit/FitCloudBatteryInfoObject.h>
#import <FitCloudKit/FitCloudHTMObject.h>
#import <FitCloudKit/FitCloudLSRObject.h>
#import <FitCloudKit/FitCloudDRObject.h>
#import <FitCloudKit/FitCloudPRObject.h>
#import <FitCloudKit/FitCloudWWUObject.h>
#import <FitCloudKit/FitCloudBPRObject.h>
#import <FitCloudKit/FitCloudHRAlarmObject.h>
#import <FitCloudKit/FitCloudBPAlarmObject.h>
#import <FitCloudKit/FitCloudAllConfigObject.h>
#import <FitCloudKit/FitCloudDNDSetting.h>
#import <FitCloudKit/FitCloudWeatherObject.h>
#import <FitCloudKit/FitCloudUserProfileObject.h>
#import <FitCloudKit/FitCloudHealthSportsObject.h>
#import <FitCloudKit/FitCloudPeripheral.h>
#import <FitCloudKit/FitCloudWatchUIInfo.h>
#import <FitCloudKit/FitCloudWatchfaceUIInfo.h>
#import <FitCloudKit/FitCloudLatestHealthMeasurementDataObject.h>
#import <FitCloudKit/FitCloudContactObject.h>
#import <FitCloudKit/FitCloudWomenHealthSetting.h>
#import <FitCloudKit/FitCloudSleepDebugData.h>
#import <FitCloudKit/FitCloudHandWashRemindObject.h>
#import <FitCloudKit/FitCloudLockScreenSetting.h>
#import <FitCloudKit/FitCloudScheduleObject.h>
#import <FitCloudKit/FitCloudGameObject.h>
#import <FitCloudKit/FitCloudGameSkinObject.h>
#import <FitCloudKit/FitCloudScreenSetting.h>
#import <FitCloudKit/FitCloudVibrateSetting.h>
#import <FitCloudKit/FitCloudScreenResolution.h>
#import <FitCloudKit/FitCloudWatchLaunchVibrateSetting.h>
#import <FitCloudKit/FitCloudGamePasscodeSetting.h>
#import <FitCloudKit/FitCloudGameRankingTrend.h>
#import <FitCloudKit/FitCloudHabitObject.h>
#import <FitCloudKit/FitCloudDailyGoalObject.h>
#import <FitCloudKit/FitCloudCustomLabelsObject.h>
#import <FitCloudKit/FitCloudPowerSavingSetting.h>
#import <FitCloudKit/SkyworthPVPowerStationObject.h>
#import <FitCloudKit/FitCloudCricketUpcomingMatch.h>
#import <FitCloudKit/FitCloudCricketLiveMatch.h>
#import <FitCloudKit/FitCloudCricketEndedMatch.h>
#import <FitCloudKit/FitCloudLocationDataModel.h>
#import <FitCloudKit/FitCloudGPSFileExpireTimeModel.h>
#import <FitCloudKit/FitCloudCricketMatchScoreOrder.h>
#import <FitCloudKit/FitCloudMedal.h>
#import <FitCloudKit/FitCloudPhotoAlbumParams.h>
#import <FitCloudKit/FitCloudECard.h>
#import <FitCloudKit/FitCloudHTMSingleObject.h>
#import <FitCloudKit/FitCloudRestingHRValue.h>
#import <FitCloudKit/FitCloudEmergencyContactObject.h>
#import <FitCloudKit/FitCloudPersonalizedReminderObject.h>
#import <FitCloudKit/FitCloudHourWeatherObject.h>
#import <FitCloudKit/FitCloudMuslimPrayerAlarmClockModel.h>
#import <FitCloudKit/FitCloudIslamicDateModel.h>
#import <FitCloudKit/FitCloudIslamicEventModel.h>
#import <FitCloudKit/FitCloudKaabaModel.h>
#import <FitCloudKit/FitCloudTaskModel.h>
#import <FitCloudKit/FitCloudFirmwareModuleVersionModel.h>

NS_ASSUME_NONNULL_BEGIN

/// FitCloud completion handler callback
/// - Parameters:
///   - success: whether the call succeeded
///   - error: error information
typedef void (^FitCloudCompletionHandler)(BOOL success, NSError *_Nullable error);

/// Completion for an AI business coordination session initiated by the app.
/// - Parameters:
///   - success: Whether the app and device entered the coordinated feature state.
///   - failureReason: The semantic device-side failure reason when `success` is `NO` and the
///     device returned a valid start-failure response.
///   - error: Communication or SDK error. Device-side business rejection is represented by `failureReason`.
typedef void (^FitCloudAIStartCompletion)(BOOL success,
                                          FitCloudAIDeviceSideStartFailureReason failureReason,
                                          NSError *_Nullable error);

/// FitCloud progress callback
/// - Parameters:
///   - progress: progress value 0.0～1.0
typedef void (^FitCloudProgressHandler)(CGFloat progress);

/// FitCloud 调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - val: 对象值
///   - error: 错误信息
typedef void (^FitCloudObjectResultBlock)(BOOL succeed, id _Nullable val, NSError *_Nullable error);

/// FitCloud 进入 DFU 模式结果回调
/// - Parameters:
///   - succeed: 是否成功进入 DFU
///   - dfuPeripheral: dfu 蓝牙外设
///   - chipVendor:  蓝牙外设芯片供应商
///   - error: 错误信息
typedef void (^FitCloudEnterDFUModeResultBlock)(BOOL succeed, CBPeripheral *_Nullable dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError *_Nullable error);

/// FitCloud 退出 DFU 模式结果回调
/// - Parameters:
///   - succeed: 是否成功进入 DFU
///   - error: 错误信息
typedef void (^FitCloudExitDFUModeResultBlock)(BOOL succeed, NSError *_Nullable error);

/// FitCloud callback for fetching alarm clock list
/// - Parameters:
///   - success: whether fetch succeed
///   - alarmClockArray: alarm clock list
///   - error: error information
typedef void (^FitCloudAlarmClockFetchCompletion)(BOOL success, NSArray<FitCloudAlarmObject *> *_Nullable alarmClockArray, NSError *_Nullable error);

/// FitCloud 获取日程列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 日程列表
///   - error: 错误信息
typedef void (^FitCloudSchedulesResultBlock)(BOOL succeed, NSArray<FitCloudScheduleObject *> *_Nullable list, NSError *_Nullable error);

/// FitCloud 获取任务列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 任务列表
///   - totalCoinsEarned: 总金币数
///   - error: 错误信息
typedef void (^FitCloudTaskQueryCompletion)(BOOL succeed, NSArray<FitCloudTaskModel *> *_Nullable tasks, NSNumber *_Nullable totalCoinsEarned, NSError *_Nullable error);

/// FitCloud 获取常用联系人列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 常用联系人列表
///   - error: 错误信息
typedef void (^FitCloudFavContactsResultBlock)(BOOL succeed, NSArray<FitCloudContactObject *> *_Nullable list, NSError *_Nullable error);

/// FitCloud 获取习惯养成列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 习惯养成列表
///   - error: 错误信息
typedef void (^FitCloudHabitsResultBlock)(BOOL succeed, NSArray<FitCloudHabitObject *> *_Nullable list, NSError *_Nullable error);

/// FitCloud 获取手表每日运动目标调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - goal: 运动目标
///   - error: 错误信息
typedef void (^FitCloudDailyGoalResultBlock)(BOOL succeed, FitCloudDailyGoalObject *_Nullable goal, NSError *_Nullable error);

/// FitCloud 获取手表软硬件版本信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - version: 版本信息
///   - error: 错误信息
typedef void (^FitCloudFirmwareVersionResultBlock)(BOOL succeed, FitCloudFirmwareVersionObject *_Nullable version, NSError *_Nullable error);

/// FitCloud 获取手表表盘所有功能项显示状态调用结果回调
/// - Parameters:
///   - succeed 是否成功
///   - sdSetting 手表表盘所有功能项显示状态
///   - error 错误信息
typedef void (^FitCloudSDSettingResultBlock)(BOOL succeed, FITCLOUDSCREENDISPLAY sdSetting, NSError *_Nullable error);

/// FitCloud 获取手表偏好设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - prefer: 手表偏好设置信息
///   - error: 错误信息
typedef void (^FitCloudPreferResultBlock)(BOOL succeed, FITCLOUDPREFER prefer, NSError *_Nullable error);

/// FitCloud 获取手表电量和充电状态调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - batteryInfo: 手表电量和充电状态信息
///   - error: 错误信息
typedef void (^FitCloudBatteryInfoResultBlock)(BOOL succeed, FitCloudBatteryInfoObject *_Nullable batteryInfo, NSError *_Nullable error);

/// FitCloud 获取健康定时监测设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - htmSetting: 健康定时监测设置
///   - error: 错误信息
typedef void (^FitCloudHealthTimingMonitorResultBlock)(BOOL succeed, FitCloudHTMObject *_Nullable htmSetting, NSError *_Nullable error);

/// FitCloud 获取健康定时监测独立设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - htmSingleSettings: 健康定时监测独立设置信息
///   - error: 错误信息
typedef void (^FitCloudHealthTimingMonitoringSingleSettingsResultBlock)(BOOL succeed, NSArray<FitCloudHTMSingleObject *> *_Nullable htmSingleSettings, NSError *_Nullable error);

/// FitCloud 获取久坐提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - lsrSetting: 久坐提醒设置
///   - error: 错误信息
typedef void (^FitCloudLongSitRemindResultBlock)(BOOL succeed, FitCloudLSRObject *_Nullable lsrSetting, NSError *_Nullable error);

/// FitCloud 获取喝水提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - drSetting: 喝水提醒设置
///   - error: 错误信息
typedef void (^FitCloudDrinkRemindResultBlock)(BOOL succeed, FitCloudDRObject *_Nullable drSetting, NSError *_Nullable error);

/// FitCloud 获取防护提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - prSetting: 防护提醒设置
///   - error: 错误信息
typedef void (^FitCloudProtectionRemindResultBlock)(BOOL succeed, FitCloudPRObject *_Nullable prSetting, NSError *_Nullable error);

/// FitCloud 获取洗手提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - hwrSetting: 洗手提醒设置
///   - error: 错误信息
typedef void (^FitCloudHandWashRemindResultBlock)(BOOL succeed, FitCloudHandWashRemindObject *_Nullable hwrSetting, NSError *_Nullable error);

/// FitCloud 获取抬腕唤醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - wwuSetting: 抬腕唤醒设置
///   - error: 错误信息
typedef void (^FitCloudWristWakeUpResultBlock)(BOOL succeed, FitCloudWWUObject *_Nullable wwuSetting, NSError *_Nullable error);

/// FitCloud 获取血压参考范围设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - dbpSetting: 血压参考范围设置信息
///   - error: 错误信息
typedef void (^FitCloudBloodPressureReferResultBlock)(BOOL succeed, FitCloudBPRObject *_Nullable dbpSetting, NSError *_Nullable error);

/// FitCloud 获取心率报警设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - hrAlarmSetting: 心率报警设置信息
///   - error: 错误信息
typedef void (^FitCloudHRAlarmResultBlock)(BOOL succeed, FitCloudHRAlarmObject *_Nullable hrAlarmSetting, NSError *_Nullable error);

/// FitCloud 获取血压报警设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - bpAlarmSetting: 血压报警设置信息
///   - error: 错误信息
typedef void (^FitCloudBPAlarmResultBlock)(BOOL succeed, FitCloudBPAlarmObject *_Nullable bpAlarmSetting, NSError *_Nullable error);

/// FitCloud (绑定时) 获取手表所有配置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - config: (绑定时) 获取手表所有配置信息
///   - error: 错误信息
typedef void (^FitCloudAllConfigWhenBindResultBlock)(BOOL succeed, FitCloudAllConfigObject *_Nullable config, NSError *_Nullable error);

/// FitCloud 获取勿扰模式设置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - dndSetting: 勿扰模式设置信息
///   - error: 错误信息
typedef void (^FitCloudDNDSettingResultBlock)(BOOL succeed, FitCloudDNDSetting *_Nullable dndSetting, NSError *_Nullable error);

/// FitCloud 获取省电模式设置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - setting: 省电模式设置信息
///   - error: 错误信息
typedef void (^FitCloudPowerSavingSettingResultBlock)(BOOL succeed, FitCloudPowerSavingSetting *_Nullable setting, NSError *_Nullable error);

/// FitCloud 获取女性健康设置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - whSetting: 女性健康设置信息
///   - error: 错误信息
typedef void (^FitCloudWomenHealthSettingResultBlock)(BOOL succeed, FitCloudWomenHealthSetting *_Nullable whSetting, NSError *_Nullable error);

/// FitCloud 手表向 APP 请求天气信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - weather: 天气信息回调
///   - error: 错误信息
typedef void (^FitCloudWeatherCallbackBlock)(BOOL succeed, FitCloudWeatherObject *_Nullable weather, NSError *_Nullable error);

/// FitCloud 请求手表上待同步的历史运动健康数据长度总和调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - length: 数据长度（字节）
///   - error: 错误信息
typedef void (^FitCloudDataToSyncTotalLengthResultBlock)(BOOL succeed, NSUInteger length, NSError *_Nullable error);

/// FitCloud 手表历史运动健康数据手动同步进度
/// - Parameters:
///   - progress: 进度百分比
///   - tip: 进度提示
typedef void (^FitCloudDataManualSyncProgress)(CGFloat progress, NSString *_Nullable tip);

/// FitCloud 手表历史运动健康数据手动同步结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - userId: 用户 Id
///   - records: 记录集合
///   - error: 错误信息
typedef void (^FitCloudDataManualSyncResultBlock)(BOOL succeed, NSString *_Nullable userId, NSArray<FitCloudManualSyncRecordObject *> *_Nullable records, NSError *_Nullable error);

/// FitCloud 手表历史运动健康数据手动同步结束回调
typedef void (^FitCloudDataManualSyncFinishBlock)(void);

/// FitCloud 请求当日运动健康数据调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - userId: 用户 Id
///   - dataObject: 当日运动健康数据
///   - error: 错误信息
typedef void (^FitCloudHealthAndSportsDataTodayResultBlock)(BOOL succeed, NSString *_Nullable userId, FitCloudDailyHealthAndSportsDataObject *_Nullable dataObject, NSError *_Nullable error);

/// FitCloud 请求当前手表支持的游戏类型结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - games: 游戏列表
///   - error: 错误信息
typedef void (^FitCloudSupportedGamesResultBlock)(BOOL succeed, NSArray<FitCloudGameObject *> *_Nullable games, NSError *_Nullable error);

/// FitCloud 请求游戏最高三个游戏记录结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - records: 游戏记录列表
///   - error: 错误信息
typedef void (^FitCloudTop3RankGameRecordsResultBlock)(BOOL succeed, NSArray<FitCloudGameItemObject *> *_Nullable records, NSError *_Nullable error);

/// FitCloud 请求所有游戏皮肤信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - allGameSkins: 游戏皮肤信息列表
///   - error: 错误信息
typedef void (^FitCloudAllGameSkinsResultBlock)(BOOL succeed, NSArray<FitCloudGameSkinObject *> *_Nullable allGameSkins, NSError *_Nullable error);

/// FitCloud 请求亮屏时长、亮度、振动等信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - screenSettings: 亮屏时长、亮度等信息
///   - vibrateSettings: 马达振动信息
///   - error: 错误信息
typedef void (^FitCloudScreenAndVibrateSettingsResultBlock)(BOOL succeed, FitCloudScreenSetting *_Nullable screenSettings, FitCloudVibrateSetting *_Nullable vibrateSettings, NSError *_Nullable error);

/// Callback for requesting screen resolution related information
/// - Parameters:
///   - succeed: Whether the request was successful
///   - screenResolution: Screen resolution related information
///   - error: Error information if request failed
typedef void (^FitCloudScreenResolutionResultBlock)(BOOL succeed, FitCloudScreenResolution *_Nullable screenResolution, NSError *_Nullable error);

/// FitCloud 请求手表 UI 信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - watchUI: 手表 UI 信息
///   - error: 错误信息
typedef void (^FitCloudWatchUIInfoResultBlock)(BOOL succeed, FitCloudWatchUIInfo *_Nullable watchUI, NSError *_Nullable error);

/// FitCloud 请求表盘 UI 信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - faceUI: 表盘 UI 信息
///   - error: 错误信息
typedef void (^FitCloudWatchfaceUIInfoResultBlock)(BOOL succeed, FitCloudWatchfaceUIInfo *_Nullable faceUI, NSError *_Nullable error);

/// FitCloud 请求最新的测量数据结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - dataObject: 最新的测量数据
///   - error: 错误信息
typedef void (^FitCloudLatestHealthMeasurementDataResultBlock)(BOOL succeed, FitCloudLatestHealthMeasurementDataObject *_Nullable dataObject, NSError *_Nullable error);

/// FitCloud Alexa 语音开始请求回调
/// - Parameter result: 回调结果
typedef void (^FitCloudAlexaVoiceStartRequestCompletion)(ALEXAINVOKEERROR result);

/// FitCloud Alexa 语音亚马逊处理回调
/// - Parameters:
///   - result: 回调结果
///   - text: 文本回调
typedef void (^FitCloudAlexaVoiceAmazonCallback)(ALEXAINVOKEERROR result, NSString *_Nullable text);

/// FitCloud 二维码功能列表回调
/// - Parameters:
///   - succeed: 是否成功
///   - supported: 支持的二维码功能
///   - error: 错误信息
typedef void (^FitCloudQRCodeFeaturesResultBlock)(BOOL succeed, NSArray<NSNumber *> *_Nullable supported, NSError *_Nullable error);

/// FitCloud 勋章列表回调
/// - Parameters:
///   - succeed: 是否成功
///   - medals: 勋章
///   - error: 错误信息
typedef void (^FitCloudMedalsResultBlock)(BOOL succeed, NSArray<FitCloudMedal *> *_Nullable medals, NSError *_Nullable error);

/// FitCloud 相册推送功能参数回调
/// - Parameters:
///   - succeed: 是否成功
///   - params: 参数
///   - error: 错误信息
typedef void (^FitCloudPhotoAlbumParamsResultBlock)(BOOL succeed, FitCloudPhotoAlbumParams *_Nullable params, NSError *_Nullable error);

/// FitCloud 支持的日程类型回调
/// - Parameters:
///   - succeed: 是否成功
///   - supported: 支持的日程类型
///   - error: 错误信息
typedef void (^FitCloudSupportedSchedulesResultBlock)(BOOL succeed, NSArray<NSNumber *> *_Nullable supported, NSError *_Nullable error);

/// FitCloud 开启 GSensor 结果回调
/// - Parameters:
///   - succeed: 是否成功开启
///   - error: 错误信息
typedef void (^FitCloudOpenGSensorResultBlock)(BOOL succeed, NSError *_Nullable error);

/// The electronic card query result
/// - Parameters:
///   - succeed: whether succeed
///   - maxCount: the max electronic card count
///   - maxContentLen: the max  electronic card qrcode content length
///   - ecards: the electronic card list
///   - error: the error information
///
/// - Returns:
///   void
typedef void (^FitCloudECardsResultBlock)(BOOL succeed, NSInteger maxCount, NSInteger maxContentLen, NSArray<FitCloudECard *> *_Nullable ecards, NSError *_Nullable error);

/// Callback block for OTA upgrade start result
/// - Parameters:
///   - success: whether the OTA start succeeded
///   - error: error information if failed
typedef void (^FitCloudOTAStartResultHandler)(BOOL success, NSError *_Nullable error);

/// OTA upgrade progress callback
/// - Parameters:
///   - progress: progress value, range 0.0–1.0
typedef void (^FitCloudOTAProgressHandler)(CGFloat progress);

/// The OTA upgrade completion callback
/// - Parameters:
///   - success: whether upgrade success
///   - avgSpeed: the avg transfer speed, kB/s
///   - error: error information if failed
typedef void (^FitCloudOTACompletionHandler)(BOOL success, CGFloat avgSpeed, NSError *_Nullable error);

/// The OTA upgrade cancel completion callback
/// - Parameters:
///   - success: whether cancel success
///   - error: error information if failed
typedef void (^FitCloudOTACancelCompletionHandler)(BOOL success, NSError *_Nullable error);

/// The smart watch emergency contacts query completion block
/// - Parameters:
///   - success: whether query success
///   - contacts: the smart watch emergency contacts
///   - on: whether enabled
///   - error: error information
typedef void (^FitCloudEmergencyContactsQueryCompletion)(BOOL success, NSArray<FitCloudEmergencyContactObject *> *_Nullable contacts, BOOL on, NSError *_Nullable error);

/// The smart watch resting heart rate array query completion block
/// - Parameters:
///   - success: whether query success
///   - hrValuesArray: the smart watch  resting heart rate array
///   - error: error information
typedef void (^FitCloudRestingHRQueryCompletion)(BOOL success, NSArray<FitCloudRestingHRValue *> *_Nullable hrValuesArray, NSError *_Nullable error);

/// The smart watch personalized reminders array query completion block
/// - Parameters:
///   - success: whether query success
///   - reminderArray: the smart watch personalized reminders array
///   - error: error information
typedef void (^FitCloudPersonalizedRemindersQueryCompletion)(BOOL success, NSArray<FitCloudPersonalizedReminderObject *> *_Nullable reminderArray, NSError *_Nullable error);

/// FitCloud New OTA environment check completion callback
/// - Parameters:
///     - success: whether the watch device currently meets the conditions for a new OTA upgrade
///     - error: error information if check failed, or nil if successful
typedef void (^FitCloudNewOTAEnvironmentCheckCompletion)(BOOL success, NSError *_Nullable error);

/// The smart watch other modules firmware version query completion block
/// - Parameters:
///   - succeed: whether query success
///   - firmwareVersions: array of firmware module version models
///   - error: error information
typedef void (^FitCloudOtherModulesFirmwareVersionQueryCompletion)(BOOL succeed, NSArray<FitCloudFirmwareModuleVersionModel *> *_Nullable firmwareVersions, NSError *_Nullable error);

/// FitCloudKit 回调协议
@protocol FitCloudCallback <NSObject>

@optional

/// 手表请求查找手机
- (void)OnFindiPhoneEvent;

/// 手表请求查找手机停止
- (void)OnStopFindiPhoneEvent;

/// 手表请求天气信息
/// - Parameters:
///   - block: 天气信息回调
- (void)OnRequestWeatherWithCallback:(FitCloudWeatherCallbackBlock)block;

/// 实时健康测量结果
/// - Parameters:
///   - records:数据
- (void)OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject *> *)records;

/// 心电实时测量结果
/// - Parameters:
///   -  ecgDataArray: 数据
///   - interval: 采样间隔，单位：毫秒 (ms)
- (void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval;

/// 心电实时测量结束
- (void)OnRealTimeECGStop;

/// 实时数据测量错误
/// - Parameters:
///   - errorCode: 错误码
- (void)onRealTimeDataMeasurementError:(FitCloudRealTimeDataMeasurementErrorCode)errorCode;

/// 来自手表端的互联运动事件回调
/// - Parameters:
///   -  workoutEvent: 事件
- (void)onCompanionWorkoutEvent:(FitCloudCompanionWorkoutEventModel *)workoutEvent;

/// 不定期来自手表端的互联运动数据（例如每 5s 钟手表端可能发一次数据，实际多久取决于手表固件）
/// - Parameters:
///   -  periodicReportData: 数据
- (void)onCompanionWorkoutPeriodReportData:(FitCloudCompanionWorkoutDevice2AppPeriodicReportDataModel *)periodicReportData;

/// 手表控制手机拍照
- (void)OnTakePhotoCtrl;

/// 手表通知 App 退出拍照
- (void)OnExitCamera;

/// 唤醒 APP 相机功能
- (void)OnWakeUpCamera;

/// 请求拍照实时预览图
/// - Parameters:
///   - width: 宽度
///   - height: 高度
///   - rotation: 旋转角度，支持的角度有 0°，90°，180°，270°
///   - bufferSize: 图片 Buffer 大小限制
///   - divisionCount: 图片需要在垂直方向上按该数量进行等分后传给手表，有效范围：1～n
- (void)OnRequestCameraLivePreviewWithWidth:(NSInteger)width height:(NSInteger)height rotation:(CGFloat)rotation bufferSize:(NSInteger)bufferSize divisionCount:(NSInteger)divisionCount;

/// 收到手表的活跃通知 (当前手表与手机连接还活跃着)
- (void)OnBraceletAlive;

/// 收到手表 SOS 请求
- (void)OnSOS;

/// 启停第三方外设
/// - Parameters:
///   -  peripheral: 第三方外设
///   -  action: 启停操作
- (void)OnThirdPartyPeripheral:(THIRDPARTYPERIPHERAL)peripheral action:(THIRDPARTYPERIPHERALACTION)action;

/// 通知 App 收到 Alexa 语音开始请求
/// - Parameters:
///   -  completion: 结果回调
- (void)OnAlexaVoiceStartRequestWithCompletion:(FitCloudAlexaVoiceStartRequestCompletion)completion;

/// Alexa 请求的原始语音数据
/// - Parameters:
///   -  rawData: 原始数据
- (void)OnAlexaVoiceRawPartialData:(NSData *)rawData;

/// Alexa 语音原始数据传输完成
/// - Parameters:
///   -  length: 长度
///   -  crc: crc
- (void)OnAlexaVoiceFinish:(NSInteger)length crc:(NSInteger)crc;

/// Alexa 语音原始数据校验错误
/// - Parameters:
///   - error: 校验错误
- (void)OnAlexaVoiceCheckWithError:(ALEXACHECKERROR)error;

/// Alexa 语音数据接收完毕，开始解码
- (void)OnAlexaVoiceDecodeBegin;

/// Alexa 请求的语音数据，该数据已经经过解码
/// - Parameters:
///   - voiceData: 语音数据，SampleRate 16000.0f 单通道 16 位 PCM
- (void)OnAlexaVoiceDecodedWithData:(NSData *_Nullable)voiceData;

/// Notifies that incremental AIAsking voice data has been received.
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onAIAskingDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;

/// Notifies that AIAsking voice transmission has completed and returns the requested voice data after decoding.
/// The SDK considers the single-turn AIAsking voice session ended before delivering this callback.
/// - Parameters:
///   - opusVoiceData: Voice data in Opus format, 16000Hz sample rate, mono channel, 16-bit PCM
///   - voiceData: Decoded voice data, 16000Hz sample rate, mono channel, 16-bit PCM
- (void)onAIAskingVoiceDataCompletedWithOpusVoiceData:(NSData *_Nullable)opusVoiceData decodedVoiceData:(NSData *_Nullable)voiceData;

/// Notifies that the device entered the AIAsking scene.
- (void)onDeviceDidEnterAIAsking;

/// Notifies that the device exited the AIAsking scene.
- (void)onDeviceDidExitAIAsking;

/// Notifies that the device confirmed the current AIAsking input.
- (void)onDeviceDidConfirmAIAsking;

/// Notifies that the device selected an agent for subsequent single-turn AIAsking requests.
/// - Parameter agent: The selected AIAsking agent.
- (void)onDeviceDidSelectAIAskingAgent:(FitCloudAIAskingAgent)agent;

/// Notifies that the device selected an AdFlash AI agent.
/// - Parameter agent: The selected AdFlash AI agent.
- (void)onDeviceDidSelectAdFlashAIAgent:(FITCLOUDADFLASHAIAGENT)agent;

/// Notifies that incremental voice data has been received during translation
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
///   - sourceLang: The source language for translation
///   - targetLang: The target language to translate into
- (void)onTranslateDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData sourceLanguage:(FITCLOUDLANGUAGE)sourceLang targetLanguage:(FITCLOUDLANGUAGE)targetLang;

/// Notifies that voice translation has completed with decoded voice data and language settings.
/// The SDK considers this standard or conversation-translation utterance ended before delivering this callback.
/// - Parameters:
///   - opusVoiceData: The opus encoded voice data
///   - voiceData: The decoded voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
///   - sourceLang: The source language for translation
///   - targetLang: The target language to translate into
- (void)onTranslateVoiceStopWithOpusVoiceData:(NSData *_Nullable)opusVoiceData decodedVoiceData:(NSData *_Nullable)voiceData sourceLanguage:(FITCLOUDLANGUAGE)sourceLang targetLanguage:(FITCLOUDLANGUAGE)targetLang;

/// Notifies when the watch side toggles the translated text voice playing state
/// - Parameters:
///   - state: The target voice playing state
- (void)onWatchSideToggleTranslatedTextVoicePlayingState:(TranslatedTextVoicePlayingState)state;

/// Notifies that incremental AI watch-face voice data has been received.
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onAIWatchFaceDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;

/// Notifies that AI watch-face voice input has completed with decoded voice data.
/// The SDK considers the single-turn AI watch-face voice session ended before delivering this callback.
/// - Parameters:
///   - opusVoiceData: The opus encoded voice data
///   - voiceData: The decoded voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onAIWatchFaceVoiceDataCompletedWithOpusVoiceData:(NSData *_Nullable)opusVoiceData decodedVoiceData:(NSData *_Nullable)voiceData;

/// Notifies that watch requests to generate an AI watch face based on the given prompt and preview dimensions
/// - Parameters:
///   - prompt: The text prompt describing the desired watchface design
///   - width: The preview image width in pixels
///   - height: The preview image height in pixels
- (void)onRequestGenerateAIWatchFaceWithPrompt:(NSString *_Nullable)prompt previewWidth:(NSInteger)width previewHeight:(NSInteger)height;

/// Notifies whether the watch confirms to use this AI-generated watch face photo
/// - Parameters:
///   - confirmed: A Boolean value that indicates if the watch confirms to use this AI-generated watch face photo
- (void)didConfirmAIWatchFacePhoto:(BOOL)confirmed;

/// 手表发送情侣消息，通过 APP 发给对方
/// - Parameters:
///   - loverMessage: 情侣消息
- (void)OnLoverMessage:(FITCLOUDLOVERMESSAGE)loverMessage;

/// 通知 App 开始发起支付宝 Iot 认证
- (void)OnNotifyAppToAliotAuth;

/// 支付宝 Iot 数据回调
/// - Parameters:
///   - aliotData: 支付宝 Iot 数据
///   - totalPacks: 总数据包个数
///   - packIndex: 当前第几个数据包，下标从 0 开始
///   - expectedTotalBytes: 支付宝 Iot 数据总长度，即几个数据包加起来的总长度
- (void)OnAliotData:(NSData *_Nullable)aliotData totalPacks:(NSInteger)totalPacks packIndex:(NSInteger)packIndex expectedTotalBytes:(NSInteger)expectedTotalBytes;

/// 网易云音乐桥接准备完毕
- (void)OnNetEaseCloudMusicBridgeReady;

/// 网易云音乐桥接数据回调
/// - Parameters:
///   - data: 网易云音乐桥接数据
- (void)OnNetEaseCloudMusicBridgeData:(NSData *)data;

/// 通知 App 开始发起手表微信支付认证
/// - Parameters:
///   - macAddr: 手表 Mac 地址
///   - bluetoothName: 蓝牙名称
- (void)OnNotifyAppToWPAuthWithMacAddr:(NSString *)macAddr bluetoothName:(NSString *)bluetoothName;

/// 微信手表支付认证桥接数据回调
/// - Parameters:
///   - data: 微信手表支付认证桥接数据
- (void)OnWPAuthBridgeData:(NSData *)data;

/// 手表请求创维光伏数据
- (void)OnRequestSkyworthPV;

/// 手表请求板球比赛数据
- (void)OnRequestCricketMatchData;

/// 手表请求 GPS 定位数据
/// - Parameters:
///   - purpose: 定位请求目的
- (void)onRequestGPSLocationDataWithPurpose:(FitCloudDeviceSideLocationRequestPurpose)purpose;

/// Notifies the progress of writing GPS file to watch after uploading GPS file to watch during GPS file upgrade process
/// - Parameters:
///   - progress: The writing progress, ranging from 0 to 100
- (void)onWritingGPSFileToWatchProgress:(NSInteger)progress;

/// Notifies that GPS file has been successfully written to watch after uploading GPS file to watch during GPS file upgrade process
- (void)onWritingGPSFileToWatchSuccess;

/// Notifies that GPS file writing to watch has failed
- (void)onWritingGPSFileToWatchFailed;

/// GSensor 数据
/// - Parameters:
///   - xGravity: 对应 sensor 数据中的 X 轴加速度
///   - yGravity: 对应 sensor 数据中的 Y 轴加速度
///   - zGravity: 对应 sensor 数据中的 Z 轴加速度
///   - heartRate: 心率数据，仅当手表体感游戏支持心率数据时才有效，否则为 nil
- (void)onGSensorDataWithXGravity:(SInt16)xGravity yGravity:(SInt16)yGravity zGravity:(SInt16)zGravity heartRate:(NSNumber *_Nullable)heartRate;

/// 手表端通知退出导航
- (void)OnExitNaviFromWatchNotify;

/// 请求地图导航快照
/// - Parameters:
///   - width: 宽度
///   - height: 高度
///   - rotation: 旋转角度，支持的角度有 0°，90°，180°，270°
///   - bufferSize: 图片 Buffer 大小限制
///   - divisionCount: 图片需要在垂直方向上按该数量进行等分后传给手表，有效范围：1～n
- (void)OnRequestMapNavigationSnapshotWithWidth:(NSInteger)width height:(NSInteger)height rotation:(CGFloat)rotation bufferSize:(NSInteger)bufferSize divisionCount:(NSInteger)divisionCount;

/// 手表端请求当前回历节日信息
///
/// > The watch side request the current islamic events information
- (void)onRequestCurrentIslamicEvents;

/// 手表端请求克尔白数据
///
/// > The watch side request the kaaba data information
- (void)onRequestKaabaData;

/// 通知穆斯林祈祷设置已更改
///
/// > Notifies that the Muslim prayer settings have been changed on the watch side
- (void)onOraimoMuslimPrayerSettingsChanged;

/// The watch device request to toggle the iPhone camera
- (void)OnRequestToggleCamera;

/// On query the permission status of App side
- (void)onQueryAppSidePermissionStatus;

/// On query the GoMore algorithm key
/// - Parameters:
///   - deviceId: The device id
///   - version: The GoMore algorithm version
- (void)onQueryGoMoreAlgorithmKey:(NSString *)deviceId version:(FITCLOUDGOMOREALGORITHMVERSION)version;

/// Requests AI analysis report of health data
- (void)onRequestHealthDataAIAnalysisReport;

/// Requests AI health advices
- (void)onRequestAIHealthAdvices;

/// Requests AI diet advices
- (void)onRequestAIDietAdvices;

/// Requests AI fat loss diet plan
- (void)onRequestAIFatLossDietPlan;

/// The watch side request the today fortune data information
- (void)onRequestTodayFortuneData;

/// Notifies that the user shared a talisman to he or she's lover from the watch side
/// - Parameters:
///   - talisman: The talisman type shared by the user.
- (void)onShareTalismanToLover:(FitCloudTalismanType)talisman;

/// The watch side request a yoga audio
- (void)onRequestYogaAudio;

/// Notifies that the earbuds equalizer preset has changed
/// - Parameters:
///   - latestEQ: The new equalizer preset value
- (void)onEarbudsEqualizerChangedTo:(FitCloudPresetEQ)latestEQ;

/// Notifies that the earbuds noise-reduction mode has changed
/// - Parameters:
///   - latestMode: The new noise-reduction mode value
- (void)onEarbudsNoiseReductionModeChangedTo:(FitCloudNoiseReductionMode)latestMode;

/// Notifies that the earbuds low-latency mode has changed
/// - Parameters:
///   - latestMode: The new low-latency mode value
- (void)onEarbudsLowLatencyModeChangedTo:(FitCloudLowLatencyMode)latestMode;

/// Notifies that the overall earbuds status has changed
/// - Parameters:
///   - latestStatusInfo: The current earbuds status information model
- (void)onEarbudsStatusChangedTo:(FitCloudEarbudsStatusInfoModel *)latestStatusInfo;

/// Notifies that the earbuds find-my status has changed caused by a event
/// - Parameters:
///   - findEvent: The event
- (void)onEarbudsFindStatusChangedWithEvent:(FitCloudEarbudFindEvent)findEvent;

/// Notifies that the StarBurst AI bridge data has been received
/// - Parameters:
///   - data: The StarBurst AI bridge data
- (void)onStarBurstAIBridgeDataReceived:(NSData *)data;

/// Device requests the app to establish an AI chat coordination session.
/// Start the app-owned AI service, then call exactly one matching
/// AI chat `accept...` or `reject...` API. For device Opus, FitCloudKit subsequently delivers audio.
/// For SCO or phone microphone, acceptance completes the handshake and the app owns the remaining flow.
/// - Parameter audioSource: The audio source requested by the device.
- (void)onDeviceRequestStartAIChatSessionWithAudioSource:(FitCloudAIAudioSource)audioSource;

/// Notifies that the device stopped the active AI chat session.
/// The app should end its local AI chat business and must not send another stop command.
/// - Parameter reason: The semantic device-side stop reason.
- (void)onDeviceDidStopAIChatSessionWithReason:(FitCloudAIDeviceInterruptionReason)reason;

/// Device requests the app to exit the AI chat scene.
- (void)onDeviceRequestExitAIChatSession;

/// Notifies that incremental voice data has been received during ai-chat conversation
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onAIChatDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;

/// Device requests the app to establish an AI audio-recording coordination session.
/// - Parameters:
///   - scene: The requested recording scene.
///   - audioSource: The requested audio source. Start the app-owned recording business, then call
///     the matching `accept...` or `reject...` API with the same scene. Accepted non-Opus requests
///     do not create an SDK media session.
- (void)onDeviceRequestStartAIAudioRecordingWithScene:(FitCloudAIAudioRecordingScene)scene
                                          audioSource:(FitCloudAIAudioSource)audioSource;

/// Device requests the app to stop AI audio recording.
/// - Parameters:
///   - scene: The recording scene being stopped.
///   - reason: The semantic device-side interruption reason.
- (void)onDeviceRequestStopAIAudioRecordingWithScene:(FitCloudAIAudioRecordingScene)scene
                                                reason:(FitCloudAIDeviceInterruptionReason)reason;

/// Device requests the app to exit AI audio recording.
/// - Parameter scene: The recording scene being exited.
- (void)onDeviceRequestExitAIAudioRecordingWithScene:(FitCloudAIAudioRecordingScene)scene;

/// Notifies that incremental voice data has been received during AI audio recording
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onAIAudioRecordingDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;


/// Device requests the app to establish a voice ride-hailing coordination session.
/// Start the app-owned ride-hailing service, then call exactly one
/// matching `accept...` or `reject...` API.
/// - Parameter audioSource: The audio source requested by the device. Accepted non-Opus requests
///   complete only the handshake; the app owns the remaining flow.
- (void)onDeviceRequestStartVoiceRideHailingWithAudioSource:(FitCloudAIAudioSource)audioSource;

/// Notifies that an active or pending voice ride-hailing input was canceled because
/// the device is exiting the scene. This callback is delivered before the exit callback.
/// It is not emitted when a turn naturally completes with state 0x00.
/// - Parameter reason: The semantic device-side interruption reason.
- (void)onDeviceDidCancelVoiceRideHailingWithReason:(FitCloudAIDeviceInterruptionReason)reason;

/// Device requests the app to exit voice ride hailing.
- (void)onDeviceRequestExitVoiceRideHailing;

/// Device requests the app to establish a translation coordination session.
/// - Parameters:
///   - mode: The requested translation mode.
///   - audioSource: The requested audio source. Start the app-owned translation service, then call
///     the matching `accept...` or `reject...` API with the same mode. Accepted non-Opus requests
///     do not create an SDK media session.
- (void)onDeviceRequestStartTranslationVoiceSessionWithMode:(FitCloudAITranslationVoiceMode)mode
                                                 audioSource:(FitCloudAIAudioSource)audioSource;

/// Notifies that an active or pending translation input was canceled because the
/// device is exiting the scene. This callback is delivered before the exit callback.
/// It is not emitted when a turn naturally completes with state 0x00.
/// - Parameters:
///   - mode: The translation mode being canceled.
///   - reason: The semantic device-side interruption reason.
- (void)onDeviceDidCancelTranslationVoiceSessionWithMode:(FitCloudAITranslationVoiceMode)mode
                                                    reason:(FitCloudAIDeviceInterruptionReason)reason;

/// Device requests the app to exit a translation voice session.
/// - Parameter mode: The translation mode being exited.
- (void)onDeviceRequestExitTranslationVoiceSessionWithMode:(FitCloudAITranslationVoiceMode)mode;

/// Device requests the app to establish an AI watch-face coordination session.
/// Start the app-owned AI watch-face service, then call exactly one
/// matching `accept...` or `reject...` API.
/// - Parameter audioSource: The audio source requested by the device. Accepted non-Opus requests
///   complete only the handshake; the app owns the remaining flow.
- (void)onDeviceRequestStartAIWatchFaceVoiceSessionWithAudioSource:(FitCloudAIAudioSource)audioSource;

/// Notifies that an active or pending AI watch-face voice input was canceled because
/// the device is exiting the scene. This callback is delivered before the exit callback.
/// It is not emitted when a turn naturally completes with state 0x00.
/// - Parameter reason: The semantic device-side interruption reason.
- (void)onDeviceDidCancelAIWatchFaceVoiceSessionWithReason:(FitCloudAIDeviceInterruptionReason)reason;

/// Device requests the app to exit AI watch-face voice input.
- (void)onDeviceRequestExitAIWatchFaceVoiceSession;

/// Device requests the app to establish an AIAsking coordination session.
/// Start the app-owned AIAsking service, then call exactly one
/// matching `accept...` or `reject...` API.
/// - Parameter audioSource: The audio source requested by the device. Accepted non-Opus requests
///   complete only the handshake; the app owns the remaining flow.
- (void)onDeviceRequestStartAIAskingVoiceSessionWithAudioSource:(FitCloudAIAudioSource)audioSource;

/// Notifies that an active or pending AIAsking voice input was canceled because the
/// device is exiting the scene. This callback is delivered before the exit callback.
/// It is not emitted when a turn naturally completes with state 0x00.
/// - Parameter reason: The semantic device-side interruption reason.
- (void)onDeviceDidCancelAIAskingVoiceSessionWithReason:(FitCloudAIDeviceInterruptionReason)reason;

/// Device requests the app to exit AIAsking voice input.
- (void)onDeviceRequestExitAIAskingVoiceSession;

/// Notifies that incremental voice ride hailing voice data has been received
/// This method is called when the app side receives incremental voice data for voice ride hailing, which will be called multiple times during the recording process
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onReceivedVoiceRideHailingDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;

/// Notifies that voice ride hailing recording has completed with decoded voice data.
/// The SDK considers the single-turn voice session ended before delivering this callback.
/// This method is called when the app side receives the final voice data for voice ride hailing
/// - Parameters:
///   - opusVoiceData: The opus encoded voice data
///   - voiceData: The decoded voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onReceivedVoiceRideHailingOpusVoiceData:(NSData *_Nullable)opusVoiceData decodedVoiceData:(NSData *_Nullable)voiceData;



/// Notifies when the ANCS authorization status has been updated
/// - Parameters:
///   - ancsAuthorized: A Boolean value that indicates whether ANCS is currently authorized
- (void)didUpdateAncsAuthorization:(BOOL)ancsAuthorized NS_AVAILABLE_IOS(13_0);

/// 睡眠调试数据
- (void)OnSleepDebugData:(FitCloudSleepDebugData *)sleepDebugData;

/// Called when a log message is emitted.
///
/// - Parameters:
///   - message: The log message text.
///   - level: The severity level of the log entry.
///   - subsystem: The subsystem that generated the log.
///   - category: The log category within the subsystem.
- (void)onLogMessage:(NSString *)message
               level:(FITCLOUDKITLOGLEVEL)level
           subsystem:(NSString *)subsystem
            category:(NSString *)category;
@end

NS_ASSUME_NONNULL_END

#endif /* FitCloudCallback_h */
