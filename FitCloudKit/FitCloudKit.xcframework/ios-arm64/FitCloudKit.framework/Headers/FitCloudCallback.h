//
//  FitCloudCallback.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/21.
//  Copyright © 2018年 Zero Status. All rights reserved.
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

/// FitCloud调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - error: 错误信息
typedef void (^FitCloudResultHandler)(BOOL succeed, NSError *error);

/// FitCloud进度回调
/// - Parameters:
///   - progress: 进度 0～1
typedef void (^FitCloudProgressBlock)(CGFloat progress);

/// FitCloud调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - val: 对象值
///   - error: 错误信息
typedef void (^FitCloudObjectResultBlock)(BOOL succeed, id val, NSError *error);

/// FitCloud进入DFU模式结果回调
/// - Parameters:
///   - succeed: 是否成功进入DFU
///   - dfuPeripheral: dfu蓝牙外设
///   - chipVendor:  蓝牙外设芯片供应商
///   - error: 错误信息
typedef void (^FitCloudEnterDFUModeResultBlock)(BOOL succeed, CBPeripheral *dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError *error);

/// FitCloud退出DFU模式结果回调
/// - Parameters:
///   - succeed: 是否成功进入DFU
///   - error: 错误信息
typedef void (^FitCloudExitDFUModeResultBlock)(BOOL succeed, NSError *error);

/// FitCloud 获取闹钟列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 闹钟列表
///   - error: 错误信息
typedef void (^FitCloudAlarmsResultBlock)(BOOL succeed, NSArray<FitCloudAlarmObject *> *list, NSError *error);

/// FitCloud 获取日程列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 日程列表
///   - error: 错误信息
typedef void (^FitCloudSchedulesResultBlock)(BOOL succeed, NSArray<FitCloudScheduleObject *> *list, NSError *error);

/// FitCloud 获取任务列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 任务列表
///   - totalCoinsEarned: 总金币数
///   - error: 错误信息
typedef void (^FitCloudTaskQueryCompletion)(BOOL succeed, NSArray<FitCloudTaskModel *> *tasks, NSNumber *totalCoinsEarned, NSError *error);

/// FitCloud 获取常用联系人列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 常用联系人列表
///   - error: 错误信息
typedef void (^FitCloudFavContactsResultBlock)(BOOL succeed, NSArray<FitCloudContactObject *> *list, NSError *error);

/// FitCloud 获取习惯养成列表调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - list: 习惯养成列表
///   - error: 错误信息
typedef void (^FitCloudHabitsResultBlock)(BOOL succeed, NSArray<FitCloudHabitObject *> *list, NSError *error);

/// FitCloud 获取手表每日运动目标调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - goal: 运动目标
///   - error: 错误信息
typedef void (^FitCloudDailyGoalResultBlock)(BOOL succeed, FitCloudDailyGoalObject *goal, NSError *error);

/// FitCloud 获取手表软硬件版本信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - version: 版本信息
///   - error: 错误信息
typedef void (^FitCloudFirmwareVersionResultBlock)(BOOL succeed, FitCloudFirmwareVersionObject *version, NSError *error);

/// FitCloud 获取消息通知设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - mnSetting: 消息通知设置信息
///   - error: 错误信息
typedef void (^FitCloudMNSettingResultBlock)(BOOL succeed, FITCLOUDMN mnSetting, NSError *error);

/// FitCloud 获取手表表盘所有功能项显示状态调用结果回调
/// - Parameters:
///   - succeed 是否成功
///   - sdSetting 手表表盘所有功能项显示状态
///   - error 错误信息
typedef void (^FitCloudSDSettingResultBlock)(BOOL succeed, FITCLOUDSCREENDISPLAY sdSetting, NSError *error);

/// FitCloud 获取手表偏好设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - prefer: 手表偏好设置信息
///   - error: 错误信息
typedef void (^FitCloudPreferResultBlock)(BOOL succeed, FITCLOUDPREFER prefer, NSError *error);

/// FitCloud 获取手表电量和充电状态调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - batteryInfo: 手表电量和充电状态信息
///   - error: 错误信息
typedef void (^FitCloudBatteryInfoResultBlock)(BOOL succeed, FitCloudBatteryInfoObject *batteryInfo, NSError *error);

/// FitCloud 获取健康定时监测设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - htmSetting: 健康定时监测设置
///   - error: 错误信息
typedef void (^FitCloudHealthTimingMonitorResultBlock)(BOOL succeed, FitCloudHTMObject *htmSetting, NSError *error);

/// FitCloud 获取健康定时监测独立设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - htmSingleSettings: 健康定时监测独立设置信息
///   - error: 错误信息
typedef void (^FitCloudHealthTimingMonitoringSingleSettingsResultBlock)(BOOL succeed, NSArray<FitCloudHTMSingleObject *> *htmSingleSettings, NSError *error);

/// FitCloud 获取久坐提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - lsrSetting: 久坐提醒设置
///   - error: 错误信息
typedef void (^FitCloudLongSitRemindResultBlock)(BOOL succeed, FitCloudLSRObject *lsrSetting, NSError *error);

/// FitCloud 获取喝水提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - drSetting: 喝水提醒设置
///   - error: 错误信息
typedef void (^FitCloudDrinkRemindResultBlock)(BOOL succeed, FitCloudDRObject *drSetting, NSError *error);

/// FitCloud 获取防护提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - prSetting: 防护提醒设置
///   - error: 错误信息
typedef void (^FitCloudProtectionRemindResultBlock)(BOOL succeed, FitCloudPRObject *prSetting, NSError *error);

/// FitCloud 获取洗手提醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - hwrSetting: 洗手提醒设置
///   - error: 错误信息
typedef void (^FitCloudHandWashRemindResultBlock)(BOOL succeed, FitCloudHandWashRemindObject *hwrSetting, NSError *error);

/// FitCloud 获取抬腕唤醒设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - wwuSetting: 抬腕唤醒设置
///   - error: 错误信息
typedef void (^FitCloudWristWakeUpResultBlock)(BOOL succeed, FitCloudWWUObject *wwuSetting, NSError *error);

/// FitCloud 获取血压参考范围设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - dbpSetting: 血压参考范围设置信息
///   - error: 错误信息
typedef void (^FitCloudBloodPressureReferResultBlock)(BOOL succeed, FitCloudBPRObject *dbpSetting, NSError *error);

/// FitCloud 获取心率报警设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - hrAlarmSetting: 心率报警设置信息
///   - error: 错误信息
typedef void (^FitCloudHRAlarmResultBlock)(BOOL succeed, FitCloudHRAlarmObject *hrAlarmSetting, NSError *error);

/// FitCloud 获取血压报警设置调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - bpAlarmSetting: 血压报警设置信息
///   - error: 错误信息
typedef void (^FitCloudBPAlarmResultBlock)(BOOL succeed, FitCloudBPAlarmObject *bpAlarmSetting, NSError *error);

/// FitCloud (绑定时)获取手表所有配置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - config: (绑定时)获取手表所有配置信息
///   - error: 错误信息
typedef void (^FitCloudAllConfigWhenBindResultBlock)(BOOL succeed, FitCloudAllConfigObject *config, NSError *error);

/// FitCloud 获取勿扰模式设置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - dndSetting: 勿扰模式设置信息
///   - error: 错误信息
typedef void (^FitCloudDNDSettingResultBlock)(BOOL succeed, FitCloudDNDSetting *dndSetting, NSError *error);

/// FitCloud 获取省电模式设置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - setting: 省电模式设置信息
///   - error: 错误信息
typedef void (^FitCloudPowerSavingSettingResultBlock)(BOOL succeed, FitCloudPowerSavingSetting *setting, NSError *error);

/// FitCloud 获取女性健康设置信息调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - whSetting: 女性健康设置信息
///   - error: 错误信息
typedef void (^FitCloudWomenHealthSettingResultBlock)(BOOL succeed, FitCloudWomenHealthSetting *whSetting, NSError *error);

/// FitCloud 手表向APP请求天气信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - weather: 天气信息回调
///   - error: 错误信息
typedef void (^FitCloudWeatherCallbackBlock)(BOOL succeed, FitCloudWeatherObject *weather, NSError *error);

/// FitCloud 请求手表上待同步的历史运动健康数据长度总和调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - length: 数据长度（字节）
///   - error: 错误信息
typedef void (^FitCloudDataToSyncTotalLengthResultBlock)(BOOL succeed, NSUInteger length, NSError *error);

/// FitCloud 手表历史运动健康数据手动同步进度
/// - Parameters:
///   - progress: 进度百分比
///   - tip: 进度提示
typedef void (^FitCloudDataManualSyncProgress)(CGFloat progress, NSString *tip);

/// FitCloud 手表历史运动健康数据手动同步结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - userId: 用户Id
///   - records: 记录集合
///   - error: 错误信息
typedef void (^FitCloudDataManualSyncResultBlock)(BOOL succeed, NSString *userId, NSArray<FitCloudManualSyncRecordObject *> *records, NSError *error);

/// FitCloud 手表历史运动健康数据手动同步结束回调
typedef void (^FitCloudDataManualSyncFinishBlock)(void);

/// FitCloud 请求当日运动健康数据调用结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - userId: 用户Id
///   - dataObject: 当日运动健康数据
///   - error: 错误信息
typedef void (^FitCloudHealthAndSportsDataTodayResultBlock)(BOOL succeed, NSString *userId, FitCloudDailyHealthAndSportsDataObject *dataObject, NSError *error);

/// FitCloud 请求当前手表支持的游戏类型结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - games: 游戏列表
///   - error: 错误信息
typedef void (^FitCloudSupportedGamesResultBlock)(BOOL succeed, NSArray<FitCloudGameObject *> *games, NSError *error);

/// FitCloud 请求游戏最高三个游戏记录结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - records: 游戏记录列表
///   - error: 错误信息
typedef void (^FitCloudTop3RankGameRecordsResultBlock)(BOOL succeed, NSArray<FitCloudGameItemObject *> *records, NSError *error);

/// FitCloud 请求所有游戏皮肤信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - allGameSkins: 游戏皮肤信息列表
///   - error: 错误信息
typedef void (^FitCloudAllGameSkinsResultBlock)(BOOL succeed, NSArray<FitCloudGameSkinObject *> *allGameSkins, NSError *error);

/// FitCloud 请求亮屏时长、亮度、振动等信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - screenSettings: 亮屏时长、亮度等信息
///   - vibrateSettings: 马达振动信息
///   - error: 错误信息
typedef void (^FitCloudScreenAndVibrateSettingsResultBlock)(BOOL succeed, FitCloudScreenSetting *screenSettings, FitCloudVibrateSetting *vibrateSettings, NSError *error);

/// FitCloud 请求屏幕分辨率相关信息回调
/// - Parameters:
///   - succeed: 是否成功
///   - screenResolution: 屏幕分辨率相关信息
///   - error: 错误信息
typedef void (^FitCloudScreenResolutionResultBlock)(BOOL succeed, FitCloudScreenResolution *screenResolution, NSError *error);


/// FitCloud 请求手表UI信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - watchUI: 手表UI信息
///   - error: 错误信息
typedef void (^FitCloudWatchUIInfoResultBlock)(BOOL succeed, FitCloudWatchUIInfo *watchUI, NSError *error);

/// FitCloud 请求表盘UI信息结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - faceUI: 表盘UI信息
///   - error: 错误信息
typedef void (^FitCloudWatchfaceUIInfoResultBlock)(BOOL succeed, FitCloudWatchfaceUIInfo *faceUI, NSError *error);

/// FitCloud 请求最新的测量数据结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - dataObject: 最新的测量数据
///   - error: 错误信息
typedef void (^FitCloudLatestHealthMeasurementDataResultBlock)(BOOL succeed, FitCloudLatestHealthMeasurementDataObject *dataObject, NSError *error);

/// FitCloud 请求GPS互联当前运动状态结果回调
/// - Parameters:
///   - succeed: 是否成功
///   - currentStatus: 当前运动状态
///   - error: 错误信息
typedef void (^FitCloudGPSConnectSportsCurrentStatusResultBlock)(BOOL succeed, FitCloudSportsWithGPSCurrentStatus *currentStatus, NSError *error);

/// FitCloud Alexa语音开始请求回调
/// - Parameter result: 回调结果
typedef void (^FitCloudAlexaVoiceStartRequestCompletion)(ALEXAINVOKEERROR result);

/// FitCloud Alexa语音亚马逊处理回调
/// - Parameters:
///   - result: 回调结果
///   - text: 文本回调
typedef void (^FitCloudAlexaVoiceAmazonCallback)(ALEXAINVOKEERROR result, NSString *text);

/// FitCloud 二维码功能列表回调
/// - Parameters:
///   - succeed: 是否成功
///   - supported: 支持的二维码功能
///   - error: 错误信息
typedef void (^FitCloudQRCodeFeaturesResultBlock)(BOOL succeed, NSArray<NSNumber *> *supported, NSError *error);

/// FitCloud 勋章列表回调
/// - Parameters:
///   - succeed: 是否成功
///   - medals: 勋章
///   - error: 错误信息
typedef void (^FitCloudMedalsResultBlock)(BOOL succeed, NSArray<FitCloudMedal *> *medals, NSError *error);

/// FitCloud 相册推送功能参数回调
/// - Parameters:
///   - succeed: 是否成功
///   - params: 参数
///   - error: 错误信息
typedef void (^FitCloudPhotoAlbumParamsResultBlock)(BOOL succeed, FitCloudPhotoAlbumParams *params, NSError *error);

/// FitCloud 支持的日程类型回调
/// - Parameters:
///   - succeed: 是否成功
///   - supported: 支持的日程类型
///   - error: 错误信息
typedef void (^FitCloudSupportedSchedulesResultBlock)(BOOL succeed, NSArray<NSNumber *> *supported, NSError *error);

/// FitCloud开启GSensor结果回调
/// - Parameters:
///   - succeed: 是否成功开启
///   - error: 错误信息
typedef void (^FitCloudOpenGSensorResultBlock)(BOOL succeed, NSError *error);

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
typedef void (^FitCloudECardsResultBlock)(BOOL succeed, NSInteger maxCount, NSInteger maxContentLen, NSArray<FitCloudECard *> *ecards, NSError *error);

/// The new OTA start confirm result block
/// - Parameters:
///   - success: whether start success
///   - error: error information
typedef void (^FitCloudNewOTAStartConfirmResultBlock)(BOOL success, NSError *error);

/// The new OTA progress block
/// - Parameters:
///   - progress: the progress, range 0.0~1.0f
typedef void (^FitCloudNewOTAProgressBlock)(CGFloat progress);

/// The new OTA completion block
/// - Parameters:
///   - success: whether upgrade success
///   - avgSpeed: the avg transfer speed, kB/s
///   - error: error information
typedef void (^FitCloudNewOTACompletionBlock)(BOOL success, CGFloat avgSpeed, NSError *error);

/// The new OTA cancel completion block
/// - Parameters:
///   - success: whether cancel success
///   - error: error information
typedef void (^FitCloudNewOTACancelCompletionBlock)(BOOL success, NSError *error);

/// The smart watch emergency contacts query completion block
/// - Parameters:
///   - success: whether query success
///   - contacts: the smart watch emergency contacts
///   - on: whether enabled
///   - error: error information
typedef void (^FitCloudEmergencyContactsQueryCompletion)(BOOL success, NSArray<FitCloudEmergencyContactObject *> *contacts, BOOL on, NSError *error);

/// The smart watch resting heart rate array query completion block
/// - Parameters:
///   - success: whether query success
///   - hrValuesArray: the smart watch  resting heart rate array
///   - error: error information
typedef void (^FitCloudRestingHRQueryCompletion)(BOOL success, NSArray<FitCloudRestingHRValue *> *hrValuesArray, NSError *error);

/// The smart watch personalized reminders array query completion block
/// - Parameters:
///   - success: whether query success
///   - reminderArray: the smart watch personalized reminders array
///   - error: error information
typedef void (^FitCloudPersonalizedRemindersQueryCompletion)(BOOL success, NSArray<FitCloudPersonalizedReminderObject *> *reminderArray, NSError *error);

/// FitCloud New OTA environment check result callback
/// - Parameters:
///   - succeed: whether new ota environment is available to upgrade
///   - error: error information
typedef void (^FitCloudNewOTAEnvironmentCheckCompletion)(BOOL succeed, NSError *error);

/// The smart watch other modules firmware version query completion block
/// - Parameters:
///   - succeed: whether query success
///   - firmwareVersions: array of firmware module version models
///   - error: error information
typedef void (^FitCloudOtherModulesFirmwareVersionQueryCompletion)(BOOL succeed, NSArray<FitCloudFirmwareModuleVersionModel *> *firmwareVersions, NSError *error);

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
///   - interval: 采样间隔, 单位：毫秒(ms)
- (void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval;

/// 心电实时测量结束
- (void)OnRealTimeECGStop;

/// 手表报告GPS互联运动状态
/// - Parameters:
///   -  status: GPS互联运动状态
- (void)OnGPSConnectWatchStatus:(FitCloudSportsWithGPSActionParams *)status;

/// 手表GPS互联实时运动数据
/// - Parameters:
///   -  sportsData: 数据
- (void)OnGPSConnectSportsData:(FitCloudSportsWithGPSData *)sportsData;

/// 手表控制手机拍照
- (void)OnTakePhotoCtrl;

/// 手表通知App退出拍照
- (void)OnExitCamera;

/// 唤醒APP相机功能
- (void)OnWakeUpCamera;

/// 请求拍照实时预览图
/// - Parameters:
///   - width: 宽度
///   - height: 高度
///   - rotation: 旋转角度，支持的角度有 0°，90°，180°，270°
///   - bufferSize: 图片Buffer大小限制
///   - divisionCount: 图片需要在垂直方向上按该数量进行等分后传给手表，有效范围：1～n
- (void)OnRequestCameraLivePreviewWithWidth:(NSInteger)width height:(NSInteger)height rotation:(CGFloat)rotation bufferSize:(NSInteger)bufferSize divisionCount:(NSInteger)divisionCount;

/// 收到手表的活跃通知(当前手表与手机连接还活跃着)
- (void)OnBraceletAlive;

/// 收到手表SOS请求
- (void)OnSOS;

/// 启停第三方外设
/// - Parameters:
///   -  peripheral: 第三方外设
///   -  action: 启停操作
- (void)OnThirdPartyPeripheral:(THIRDPARTYPERIPHERAL)peripheral action:(THIRDPARTYPERIPHERALACTION)action;

/// 通知App收到Alexa语音开始请求
/// - Parameters:
///   -  completion: 结果回调
- (void)OnAlexaVoiceStartRequestWithCompletion:(FitCloudAlexaVoiceStartRequestCompletion)completion;

/// Alexa请求的原始语音数据
/// - Parameters:
///   -  rawData: 原始数据
- (void)OnAlexaVoiceRawPartialData:(NSData *)rawData;

/// Alexa语音原始数据传输完成
/// - Parameters:
///   -  length: 长度
///   -  crc: crc
- (void)OnAlexaVoiceFinish:(NSInteger)length crc:(NSInteger)crc;

/// Alexa语音原始数据校验错误
/// - Parameters:
///   - error: 校验错误
- (void)OnAlexaVoiceCheckWithError:(ALEXACHECKERROR)error;

/// Alexa语音数据接收完毕，开始解码
- (void)OnAlexaVoiceDecodeBegin;

/// Alexa请求的语音数据，该数据已经经过解码
/// - Parameters:
///   - voiceData: 语音数据，SampleRate 16000.0f 单通道 16位 PCM
- (void)OnAlexaVoiceDecodedWithData:(NSData *)voiceData;

/// 大模型语音传输开始
- (void)OnLLMVoiceBegin;

/// 大模型语音传输结束，并返回请求的语音数据，该数据已经经过解码
/// - Parameters:
///   - opusVoiceData: 语音数据，SampleRate 16000.0f 单通道 16位 PCM
///   - voiceData: 语音数据，SampleRate 16000.0f 单通道 16位 PCM
- (void)OnLLMVoiceStopWithOpusVoiceData:(NSData *)opusVoiceData decodedVoiceData:(NSData *)voiceData;

/// 手表进入大模型界面
- (void)OnWatchSideEnterLLM;

/// 手表退出大模型界面
- (void)OnWatchSideExitLLM;

/// Notifies that voice translation has started
/// - Note: Called when the watch begins recording voice for translation
- (void)onTranslateVoiceBegin;

/// Notifies that voice translation has completed with decoded voice data and language settings
/// - Parameters:
///   - opusVoiceData: The opus encoded voice data
///   - voiceData: The decoded voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
///   - sourceLang: The source language for translation
///   - targetLang: The target language to translate into
- (void)onTranslateVoiceStopWithOpusVoiceData:(NSData *)opusVoiceData decodedVoiceData:(NSData *)voiceData sourceLanguage:(FITCLOUDLANGUAGE)sourceLang targetLanguage:(FITCLOUDLANGUAGE)targetLang;

/// 手表发送情侣消息，通过APP发给对方
/// - Parameters:
///   - loverMessage: 情侣消息
- (void)OnLoverMessage:(FITCLOUDLOVERMESSAGE)loverMessage;

/// 通知App开始发起支付宝Iot认证
- (void)OnNotifyAppToAliotAuth;

/// 支付宝Iot数据回调
/// - Parameters:
///   - aliotData: 支付宝Iot数据
///   - totalPacks: 总数据包个数
///   - packIndex: 当前第几个数据包，下标从0开始
///   - expectedTotalBytes: 支付宝Iot数据总长度，即几个数据包加起来的总长度
- (void)OnAliotData:(NSData *)aliotData totalPacks:(NSInteger)totalPacks packIndex:(NSInteger)packIndex expectedTotalBytes:(NSInteger)expectedTotalBytes;

/// 网易云音乐桥接准备完毕
- (void)OnNetEaseCloudMusicBridgeReady;

/// 网易云音乐桥接数据回调
/// - Parameters:
///   - data: 网易云音乐桥接数据
- (void)OnNetEaseCloudMusicBridgeData:(NSData *)data;

/// 通知App开始发起手表微信支付认证
/// - Parameters:
///   - macAddr: 手表Mac地址
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

/// 手表请求GPS定位数据
- (void)onRequestGPSLocationData;

/// Notifies the progress of writing GPS file to watch after uploading GPS file to watch during GPS file upgrade process
/// - Parameters:
///   - progress: The writing progress, ranging from 0 to 100
- (void)onWritingGPSFileToWatchProgress:(NSInteger)progress;

/// Notifies that GPS file has been successfully written to watch after uploading GPS file to watch during GPS file upgrade process
- (void)onWritingGPSFileToWatchSuccess;

/// Notifies that GPS file writing to watch has failed
- (void)onWritingGPSFileToWatchFailed;

/// GSensor数据
/// - Parameters:
///   - xGravity: 对应sensor数据中的X轴加速度
///   - yGravity: 对应sensor数据中的Y轴加速度
///   - zGravity: 对应sensor数据中的Z轴加速度
- (void)OnGSensorDataWithXGravity:(SInt16)xGravity yGravity:(SInt16)yGravity zGravity:(SInt16)zGravity;

/// 手表端通知退出导航
- (void)OnExitNaviFromWatchNotify;

/// 请求地图导航快照
/// - Parameters:
///   - width: 宽度
///   - height: 高度
///   - rotation: 旋转角度，支持的角度有 0°，90°，180°，270°
///   - bufferSize: 图片Buffer大小限制
///   - divisionCount: 图片需要在垂直方向上按该数量进行等分后传给手表，有效范围：1～n
- (void)OnRequestMapNavigationSnapshotWithWidth:(NSInteger)width height:(NSInteger)height rotation:(CGFloat)rotation bufferSize:(NSInteger)bufferSize divisionCount:(NSInteger)divisionCount;

/// 手表端请求当前回历节日信息
///
/// > The watch side request the current islamic events information
- (void)OnRequestCurrentIslamicEvents;

/// 手表端请求克尔白数据
///
/// > The watch side request the kaaba data information
- (void)OnRequestKaabaData;

/// The watch device request to toggle the iPhone camera
- (void)OnRequestToggleCamera;

/// 睡眠调试数据
- (void)OnSleepDebugData:(FitCloudSleepDebugData *)sleepDebugData;

/// 会调日志数据
/// - Parameters:
///   - message: 日志信息
///   - level: 日志等级
- (void)OnLogMessage:(NSString *)message level:(FITCLOUDKITLOGLEVEL)level;
@end

#endif /* FitCloudCallback_h */
