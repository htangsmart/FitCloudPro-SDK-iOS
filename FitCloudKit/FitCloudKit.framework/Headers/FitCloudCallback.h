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
#import <FitCloudKit/FitCloudMNDefines.h>
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
#import <FitCloudKit/FitCloudWatchSportModeObject.h>
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

/**
 *@brief FitCloud调用结果回调
 *@param succeed 是否成功
 *@param error 错误信息
 */
typedef void (^FitCloudResultBlock)(BOOL succeed, NSError* error);

/**
 *@brief FitCloud调用结果回调
 *@param succeed 是否成功
 *@param val 对象值
 *@param error 错误信息
 */
typedef void (^FitCloudObjectResultBlock)(BOOL succeed, id val, NSError* error);

/**
 *@brief FitCloud进入DFU模式结果回调
 *@param succeed 是否成功进入DFU
 *@param dfuPeripheral dfu蓝牙外设
 *@param chipVendor  蓝牙外设芯片供应商
 *@param error 错误信息
 */
typedef void (^FitCloudEnterDFUModeResultBlock)(BOOL succeed, CBPeripheral* dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError* error);

/**
 *@brief FitCloud退出DFU模式结果回调
 *@param succeed 是否成功进入DFU
 *@param error 错误信息
 */
typedef void (^FitCloudExitDFUModeResultBlock)(BOOL succeed, NSError* error);

/**
 *@brief FitCloud 获取闹钟列表调用结果回调
 *@param succeed 是否成功
 *@param list 闹钟列表
 *@param error 错误信息
 */
typedef void (^FitCloudAlarmsResultBlock)(BOOL succeed, NSArray<FitCloudAlarmObject*>*list, NSError* error);

/**
 *@brief FitCloud 获取日程列表调用结果回调
 *@param succeed 是否成功
 *@param list 日程列表
 *@param error 错误信息
 */
typedef void (^FitCloudSchedulesResultBlock)(BOOL succeed, NSArray<FitCloudScheduleObject*>*list, NSError* error);


/**
 *@brief FitCloud 获取常用联系人列表调用结果回调
 *@param succeed 是否成功
 *@param list 常用联系人列表
 *@param error 错误信息
 */
typedef void (^FitCloudFavContactsResultBlock)(BOOL succeed, NSArray<FitCloudContactObject*>*list, NSError* error);


/**
 *@brief FitCloud 获取习惯养成列表调用结果回调
 *@param succeed 是否成功
 *@param list 习惯养成列表
 *@param error 错误信息
 */
typedef void (^FitCloudHabitsResultBlock)(BOOL succeed, NSArray<FitCloudHabitObject*>*list, NSError* error);

/**
 *@brief FitCloud 获取手表每日运动目标调用结果回调
 *@param succeed 是否成功
 *@param goal 运动目标
 *@param error 错误信息
 */
typedef void (^FitCloudDailyGoalResultBlock)(BOOL succeed, FitCloudDailyGoalObject* goal, NSError* error);

/**
 *@brief FitCloud 获取手环软硬件版本信息调用结果回调
 *@param succeed 是否成功
 *@param version 版本信息
 *@param error 错误信息
 */
typedef void (^FitCloudFirmwareVersionResultBlock)(BOOL succeed, FitCloudFirmwareVersionObject* version, NSError* error);

/**
 *@brief FitCloud 获取消息通知设置调用结果回调
 *@param succeed 是否成功
 *@param mnSetting 消息通知设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudMNSettingResultBlock)(BOOL succeed, FITCLOUDMN mnSetting, NSError* error);

/**
 *@brief FitCloud 获取手环表盘所有功能项显示状态调用结果回调
 *@param succeed 是否成功
 *@param sdSetting 手环表盘所有功能项显示状态
 *@param error 错误信息
 */
typedef void (^FitCloudSDSettingResultBlock)(BOOL succeed, FITCLOUDSCREENDISPLAY sdSetting, NSError* error);

/**
 *@brief FitCloud 获取手环偏好设置调用结果回调
 *@param succeed 是否成功
 *@param prefer 手环偏好设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudPreferResultBlock)(BOOL succeed, FITCLOUDPREFER prefer, NSError* error);

/**
 *@brief FitCloud 获取手环电量和充电状态调用结果回调
 *@param succeed 是否成功
 *@param batteryInfo 手环电量和充电状态信息
 *@param error 错误信息
 */
typedef void (^FitCloudBatteryInfoResultBlock)(BOOL succeed, FitCloudBatteryInfoObject* batteryInfo, NSError* error);

/**
 *@brief FitCloud 获取健康定时监测设置调用结果回调
 *@param succeed 是否成功
 *@param htmSetting 健康定时监测设置
 *@param error 错误信息
 */
typedef void (^FitCloudHealtTimingMonitorResultBlock)(BOOL succeed, FitCloudHTMObject* htmSetting, NSError* error);

/**
 *@brief FitCloud 获取久坐提醒设置调用结果回调
 *@param succeed 是否成功
 *@param lsrSetting 久坐提醒设置
 *@param error 错误信息
 */
typedef void (^FitCloudLongSitRemindResultBlock)(BOOL succeed, FitCloudLSRObject* lsrSetting, NSError* error);

/**
 *@brief FitCloud 获取喝水提醒设置调用结果回调
 *@param succeed 是否成功
 *@param drSetting 喝水提醒设置
 *@param error 错误信息
 */
typedef void (^FitCloudDrinkRemindResultBlock)(BOOL succeed, FitCloudDRObject* drSetting, NSError* error);

/**
 *@brief FitCloud 获取防护提醒设置调用结果回调
 *@param succeed 是否成功
 *@param prSetting 防护提醒设置
 *@param error 错误信息
 */
typedef void (^FitCloudProtectionRemindResultBlock)(BOOL succeed, FitCloudPRObject* prSetting, NSError* error);

/**
 *@brief FitCloud 获取洗手提醒设置调用结果回调
 *@param succeed 是否成功
 *@param hwrSetting 洗手提醒设置
 *@param error 错误信息
 */
typedef void (^FitCloudHandWashRemindResultBlock)(BOOL succeed, FitCloudHandWashRemindObject* hwrSetting, NSError* error);

/**
 *@brief FitCloud 获取抬腕唤醒设置调用结果回调
 *@param succeed 是否成功
 *@param wwuSetting 抬腕唤醒设置
 *@param error 错误信息
 */
typedef void (^FitCloudWristWakeUpResultBlock)(BOOL succeed, FitCloudWWUObject* wwuSetting, NSError* error);

/**
 *@brief FitCloud 获取血压参考范围设置调用结果回调
 *@param succeed 是否成功
 *@param dbpSetting 血压参考范围设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudBloodPressureReferResultBlock)(BOOL succeed, FitCloudBPRObject* dbpSetting, NSError* error);

/**
 *@brief FitCloud 获取心率报警设置调用结果回调
 *@param succeed 是否成功
 *@param hrAlarmSetting 心率报警设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudHRAlarmResultBlock)(BOOL succeed, FitCloudHRAlarmObject* hrAlarmSetting, NSError* error);

/**
 *@brief FitCloud 获取血压报警设置调用结果回调
 *@param succeed 是否成功
 *@param bpAlarmSetting 血压报警设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudBPAlarmResultBlock)(BOOL succeed, FitCloudBPAlarmObject* bpAlarmSetting, NSError* error);

/**
 *@brief FitCloud (绑定时)获取手环所有配置信息调用结果回调
 *@param succeed 是否成功
 *@param config (绑定时)获取手环所有配置信息
 *@param error 错误信息
 */
typedef void (^FitCloudAllConfigWhenBindResultBlock)(BOOL succeed, FitCloudAllConfigObject* config, NSError* error);

/**
 *@brief FitCloud 获取勿扰模式设置信息调用结果回调
 *@param succeed 是否成功
 *@param dndSetting  勿扰模式设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudDNDSettingResultBlock)(BOOL succeed, FitCloudDNDSetting* dndSetting, NSError* error);


/**
 *@brief FitCloud 获取省电模式设置信息调用结果回调
 *@param succeed 是否成功
 *@param setting  省电模式设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudPowerSavingSettingResultBlock)(BOOL succeed, FitCloudPowerSavingSetting* setting, NSError* error);

/**
 *@brief FitCloud 获取女性健康设置信息调用结果回调
 *@param succeed 是否成功
 *@param whSetting  女性健康设置信息
 *@param error 错误信息
 */
typedef void (^FitCloudWomenHealthSettingResultBlock)(BOOL succeed, FitCloudWomenHealthSetting* whSetting, NSError* error);

/**
 *@brief FitCloud 手环向APP请求天气信息结果回调
 *@param succeed 是否成功
 *@param weather 天气信息回调
 *@param error 错误信息
 */
typedef void (^FitCloudWeatherCallbackBlock)(BOOL succeed, FitCloudWeatherObject* weather, NSError* error);

/**
 *@brief FitCloud 请求手环上待同步的历史运动健康数据长度总和调用结果回调
 *@param succeed 是否成功
 *@param length 数据长度（字节）
 *@param error 错误信息
 */
typedef void (^FitCloudDataToSyncTotalLengthResultBlock)(BOOL succeed, NSUInteger length, NSError* error);

/**
 *@brief FitCloud 手环历史运动健康数据手动同步进度
 *@param progress 进度百分比
 *@param tip 进度提示
 */
typedef void (^FitCloudDataManualSyncProgress)(CGFloat progress, NSString* tip);

/**
 *@brief FitCloud 手环历史运动健康数据手动同步结果回调
 *@param succeed 是否成功
 *@param userId 用户Id
 *@param records 记录集合
 *@param error 错误信息
 */
typedef void (^FitCloudDataManualSyncResultBlock)(BOOL succeed, NSString* userId, NSArray<FitCloudManualSyncRecordObject*>*records, NSError* error);

/**
 *@brief FitCloud 请求当日运动健康数据调用结果回调
 *@param succeed 是否成功
 *@param userId 用户Id
 *@param dataObject 当日运动健康数据
 *@param error 错误信息
 */
typedef void (^FitCloudHealthAndSportsDataTodayResultBlock)(BOOL succeed, NSString* userId, FitCloudDailyHealthAndSportsDataObject* dataObject, NSError* error);

/**
 *@brief FitCloud 请求当前手环支持的游戏类型结果回调
 *@param succeed 是否成功
 *@param games 游戏列表
 *@param error 错误信息
 */
typedef void (^FitCloudSupportedGamesResultBlock)(BOOL succeed, NSArray<FitCloudGameObject*>* games, NSError* error);

/**
 *@brief FitCloud 请求游戏最高三个游戏记录结果回调
 *@param succeed 是否成功
 *@param records 游戏记录列表
 *@param error 错误信息
 */
typedef void (^FitCloudTop3RankGameRecordsResultBlock)(BOOL succeed, NSArray<FitCloudGameItemObject*>* records, NSError* error);

/**
 *@brief FitCloud 请求所有游戏皮肤信息结果回调
 *@param succeed 是否成功
 *@param allGameSkins 游戏皮肤信息列表
 *@param error 错误信息
 */
typedef void (^FitCloudAllGameSkinsResultBlock)(BOOL succeed, NSArray<FitCloudGameSkinObject*>* allGameSkins, NSError* error);

/**
 *@brief FitCloud 请求亮屏时长、亮度、振动等信息结果回调
 *@param succeed 是否成功
 *@param screenSettings 亮屏时长、亮度等信息
 *@param vibrateSettings 马达振动信息
 *@param error 错误信息
 */
typedef void (^FitCloudScreenAndVibrateSettingsResultBlock)(BOOL succeed, FitCloudScreenSetting* screenSettings, FitCloudVibrateSetting* vibrateSettings, NSError* error);

/**
 *@brief FitCloud 请求屏幕分辨率相关信息回调
 *@param succeed 是否成功
 *@param screenResolution 屏幕分辨率相关信息
 *@param error 错误信息
 */
typedef void(^FitCloudScreenResolutionResultBlock)(BOOL succeed, FitCloudScreenResolution* screenResolution, NSError* error);

/**
 *@brief FitCloud 请求获取设备可支持的运动模式类型列表回调
 *@param succeed 是否成功
 *@param sports 设备可支持的运动模式类型列表
 *@param error 错误信息
 */
typedef void (^FitCloudSupportedWatchSportsResultBlock)(BOOL succeed, NSArray<NSNumber*>* sports, NSError* error);

/**
 *@brief FitCloud 请求获取设备当前运动模式类型列表回调
 *@param succeed 是否成功
 *@param sports 设备当前运动模式类型列表
 *@param error 错误信息
 */
typedef void (^FitCloudCurrentWatchSportsResultBlock)(BOOL succeed, NSArray<FitCloudWatchSportModeObject*>* sports, NSError* error);

/**
 * @brief FitCloud 请求手表UI信息结果回调
 * @param succeed 是否成功
 * @param watchUI 手表UI信息
 * @param error 错误信息
 */
typedef void (^FitCloudWatchUIInfoResultBlock)(BOOL succeed, FitCloudWatchUIInfo* watchUI, NSError* error);

/**
 * @brief FitCloud 请求表盘UI信息结果回调
 * @param succeed 是否成功
 * @param faceUI 表盘UI信息
 * @param error 错误信息
 */
typedef void (^FitCloudWatchfaceUIInfoResultBlock)(BOOL succeed, FitCloudWatchfaceUIInfo* faceUI, NSError* error);

/**
 * @brief FitCloud 请求最新的测量数据结果回调
 * @param succeed 是否成功
 * @param dataObject 最新的测量数据
 * @param error 错误信息
 */
typedef void (^FitCloudLatestHealthMeasurementDataResultBlock)(BOOL succeed, FitCloudLatestHealthMeasurementDataObject* dataObject, NSError* error);

/**
 * @brief FitCloud 请求GPS互联当前运动状态结果回调
 * @param succeed 是否成功
 * @param currentStatus 当前运动状态
 * @param error 错误信息
 */
typedef void (^FitCloudGPSConnectSportsCurrentStatusResultBlock)(BOOL succeed, FitCloudSportsWithGPSCurrentStatus* currentStatus, NSError* error);

/**
 * @brief FitCloud Alexa语音开始请求回调
 * @param result 回调结果
 */
typedef void (^FitCloudAlexaVoiceStartRequestCompletion)(ALEXAINVOKEERROR result);


/**
 * @brief FitCloud Alexa语音亚马逊处理回调
 * @param result 回调结果
 * @param text 文本回调
 */
typedef void (^FitCloudAlexaVoiceAmazonCallback)(ALEXAINVOKEERROR result, NSString* text);

/**
 * @brief FitCloud 二维码功能列表回调
 * @param supported 支持的二维码功能
 * @param error 错误信息
 */
typedef void (^FitCloudQRCodeFeaturesResultBlock)(BOOL succeed, NSArray<NSNumber*>*supported, NSError* error);

/**
 *@brief FitCloudKit 回调协议
 */
@protocol FitCloudCallback<NSObject>

@optional

/**
 *@brief 手环请求查找手机
 */
-(void) OnFindiPhoneEvent;

/**
 *@brief 手环请求查找手机停止
 */
-(void) OnStopFindiPhoneEvent;

/**
 *@brief 手环请求天气信息
 *@param block 天气信息回调
 */
-(void) OnRequestWeatherWithCallback:(FitCloudWeatherCallbackBlock)block;

/**
 *@brief 实时健康测量结果
 *@param records 数据
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records;

/**
 *@brief 心电实时测量结果
 *@param ecgDataArray 数据
 *@param interval 采样间隔, 单位：毫秒(ms)
 */
-(void) OnRealTimeECGData:(NSArray<NSNumber*>*) ecgDataArray interval:(NSInteger) interval;

/**
 *@brief 心电实时测量结束
 */
-(void) OnRealTimeECGStop;

/**
 *@brief 手表报告GPS互联运动状态
 *@param status GPS互联运动状态
 */
-(void) OnGPSConnectWatchStatus:(FitCloudSportsWithGPSActionParams*) status;

/**
 *@brief 手表GPS互联实时运动数据
 *@param sportsData 数据
 */
-(void) OnGPSConnectSportsData:(FitCloudSportsWithGPSData*)sportsData;

/**
 *@brief 手环控制手机拍照
 */
-(void)OnTakePhotoCtrl;

/**
 *@brief 手表通知App退出拍照
*/
-(void)OnExitCamera;

/**
 *@brief 唤醒APP相机功能，该功能有缺陷，慎用
 */
-(void)OnWakeUpCamera;

/**
 *@brief 收到手表的活跃通知(当前手表与手机连接还活跃着)
 */
-(void) OnBraceletAlive;

/**
 *@brief 收到手表SOS请求
 */
-(void) OnSOS;

/**
 *@brief 启停第三方外设
 *@param peripheral 第三方外设
 *@param action 启停操作
 */
-(void) OnThirdPartyPeripheral:(THIRDPARTYPERIPHERAL)peripheral action:(THIRDPARTYPERIPHERALACTION)action;

/**
 *@brief 通知App收到Alexa语音开始请求
 *@param completion 结果回调
 */
-(void) OnAlexaVoiceStartRequestWithCompletion:(FitCloudAlexaVoiceStartRequestCompletion)completion;

/**
 *@brief Alexa请求的原始语音数据
 *@param rawData 原始数据
 */
-(void) OnAlexaVoiceRawPartialData:(NSData*)rawData;

/**
 *@brief Alexa语音原始数据传输完成
 *@param length 长度
 *@param crc crc
 */
-(void) OnAlexaVoiceFinish:(NSInteger)length crc:(NSInteger) crc;

/**
 *@brief Alexa语音原始数据校验错误
 *@param error 校验错误
 */
-(void) OnAlexaVoiceCheckWithError:(ALEXACHECKERROR)error;

/**
 *@brief Alexa语音数据接收完毕，开始解码
 */
-(void) OnAlexaVoiceDecodeBegin;

/**
 *@brief Alexa请求的语音数据，该数据已经经过解码
 *@param voiceData 语音数据
 */
-(void) OnAlexaVoiceDecodedWithData:(NSData*)voiceData;

/**
 *@brief 通知App开始发起支付宝Iot认证
 */
-(void) OnNotifyAppToAliotAuth;

/**
 *@brief 支付宝Iot数据回调
 *@param aliotData 支付宝Iot数据
 *@param totalPacks 总数据包个数
 *@param packIndex 当前第几个数据包，下标从0开始
 *@param expectedTotalBytes 支付宝Iot数据总长度，即几个数据包加起来的总长度
 */
-(void) OnAliotData:(NSData*)aliotData totalPacks:(NSInteger)totalPacks packIndex:(NSInteger)packIndex expectedTotalBytes:(NSInteger)expectedTotalBytes;

/**
 * @brief 睡眠调试数据
 */
-(void) OnSleepDebugData:(FitCloudSleepDebugData*)sleepDebugData;

/**
 *@brief 记录日志数据
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnLogMessage:(NSString*)message level:(FITCLOUDKITLOGLEVEL)level;
@end

#endif /* FitCloudCallback_h */
