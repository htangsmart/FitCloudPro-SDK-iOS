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
#import <FitCloudKit/FitCloudECGDefines.h>
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
#import <FitCloudKit/FitCloudSportsWithGPSData.h>
#import <FitCloudKit/FitCloudSportsWithGPSActionParams.h>
#import <FitCloudKit/FitCloudSportsWithGPSAppClientData.h>
#import <FitCloudKit/FitCloudSportsWithGPSCurrentStatus.h>
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

/// FitCloud 获取消息通知设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - mnSetting: 消息通知设置信息
///   - error: 错误信息
typedef void (^FitCloudMNSettingResultBlock)(BOOL succeed, FITCLOUDMN mnSetting, NSError *_Nullable error);

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

/// FitCloud 请求 GPS 互联当前运动状态结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - currentStatus: 当前运动状态
///   - error: 错误信息
typedef void (^FitCloudGPSConnectSportsCurrentStatusResultBlock)(BOOL succeed, FitCloudSportsWithGPSCurrentStatus *_Nullable currentStatus, NSError *_Nullable error);

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

/// 手表报告 GPS 互联运动状态
/// - Parameters:
///   -  status: GPS 互联运动状态
- (void)OnGPSConnectWatchStatus:(FitCloudSportsWithGPSActionParams *)status;

/// 手表 GPS 互联实时运动数据
/// - Parameters:
///   -  sportsData: 数据
- (void)OnGPSConnectSportsData:(FitCloudSportsWithGPSData *)sportsData;

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

/// Notifies that large language model voice transmission has started
- (void)onLLMVoiceBegin;

/// Notifies that incremental voice data has been received during large language model conversation
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onLLMDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;

/// Notifies that large language model voice transmission has completed and returns the requested voice data after decoding
/// - Parameters:
///   - opusVoiceData: Voice data in Opus format, 16000Hz sample rate, mono channel, 16-bit PCM
///   - voiceData: Decoded voice data, 16000Hz sample rate, mono channel, 16-bit PCM
- (void)onLLMVoiceStopWithOpusVoiceData:(NSData *_Nullable)opusVoiceData decodedVoiceData:(NSData *_Nullable)voiceData;

/// Notifies that watch has entered the large language model interface
- (void)onWatchSideEnterLLM;

/// Notifies that watch has exited the large language model interface
- (void)onWatchSideExitLLM;

/// Notifies the AI conversation model toggled from watch side
/// - Parameters:
///   - aiConversationModel: The AI conversation model type
- (void)onWatchSideToggleAiConversationModel:(FITCLOUDAICONVERSATIONMODEL)aiConversationModel;

/// Notifies the AdFlash AI agent toggled from watch side
/// - Parameters:
///   - aiAgent: The AdFlash AI agent type
- (void)onWatchSideToggleAdFlashAiAgent:(FITCLOUDADFLASHAIAGENT)aiAgent;

/// Notifies that voice translation has started
/// - Note: Called when the watch begins recording voice for translation
- (void)onTranslateVoiceBegin;

/// Notifies that incremental voice data has been received during translation
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
///   - sourceLang: The source language for translation
///   - targetLang: The target language to translate into
- (void)onTranslateDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData sourceLanguage:(FITCLOUDLANGUAGE)sourceLang targetLanguage:(FITCLOUDLANGUAGE)targetLang;

/// Notifies that voice translation has completed with decoded voice data and language settings
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

/// Notifies that ASR (Automatic Speech Recognition) voice recording has started
/// - Note: Called when the watch begins recording voice for ASR
- (void)onASRVoiceBegin;

/// Notifies that incremental ASR voice data has been received
/// - Parameters:
///   - deltaOpusVoiceData: The incremental voice data in Opus format
///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onASRDeltaOpusVoiceData:(NSData *_Nullable)deltaOpusVoiceData decodedDeltaVoiceData:(NSData *_Nullable)deltaVoiceData;

/// Notifies that ASR voice recording has completed with decoded voice data
/// - Parameters:
///   - opusVoiceData: The opus encoded voice data
///   - voiceData: The decoded voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
- (void)onASRVoiceStopWithOpusVoiceData:(NSData *_Nullable)opusVoiceData decodedVoiceData:(NSData *_Nullable)voiceData;

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
