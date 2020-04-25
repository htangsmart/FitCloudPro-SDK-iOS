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
#import <FitCloudKit/FitCloudWatchfaceUIInfo.h>
#import <FitCloudKit/FitCloudLatestHealthMeasurementDataObject.h>
#import <FitCloudKit/FitCloudContactObject.h>

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
 *@brief FitCloud 获取常用联系人列表调用结果回调
 *@param succeed 是否成功
 *@param list 常用联系人列表
 *@param error 错误信息
 */
typedef void (^FitCloudFavContactsResultBlock)(BOOL succeed, NSArray<FitCloudContactObject*>*list, NSError* error);

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
 *@brief FitCloudKit 回调协议
 */
@protocol FitCloudCallback<NSObject>

@optional

/**
 *@brief 手环请求查找手机
 */
-(void) OnFindiPhoneEvent;

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
 *@brief 手环控制手机拍照
 */
-(void)OnTakePhotoCtrl;

/**
 *@brief 收到手环的活跃通知(当前手环与手机连接还活跃着)
 */
-(void) OnBraceletAlive;

/**
 *@brief 记录日志数据
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnLogMessage:(NSString*)message level:(FITCLOUDKITLOGLEVEL)level;
@end

#endif /* FitCloudCallback_h */
