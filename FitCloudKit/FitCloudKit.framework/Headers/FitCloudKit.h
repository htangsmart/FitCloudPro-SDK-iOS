//
//  FitCloudKit.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//
//  框架名称:FitCloudKit.framework
//  框架功能:iOS framework for FitCloud Smart Bracelet, which is responsible for the communication with bracelet. FitCloud智能手环的iOS框架，负责与手环设备通信等功能的封装。
//  修改记录:
//     pcjbird    2019-07-21  Version:1.0.9 Build:201907210001
//                            1.支持获取当前SDK版本信息
//
//     pcjbird    2019-07-20  Version:1.0.8 Build:201907200001
//                            1.修正iPhone日历设置成佛教日历或者日本日历的时候导致手环同步时间失败的问题
//                            2.优化手环回连机制
//
//     pcjbird    2019-06-28  Version:1.0.7 Build:201906280001
//                            1.修正无法获取消息通知设置的一些问题
//
//     pcjbird    2019-06-27  Version:1.0.6 Build:201906270001
//                            1.扫描到的外部设备新增mac地址数据
//
//     pcjbird    2019-06-25  Version:1.0.5 Build:201906250001
//                            1.修改支持设置运动目标
//
//     pcjbird    2019-05-17  Version:1.0.4 Build:201905170001
//                            1.增加手环支持的语种
//
//     pcjbird    2019-05-01  Version:1.0.3 Build:201905010001
//                            1.首次发布SDK版本
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudKit/FitCloudEvent.h>
#import <FitCloudKit/FitCloudCallback.h>
#import <FitCloudKit/FitCloudOption.h>
#import <FitCloudKit/FitCloudKitConnectRecord.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * @brief FitCloud健康手环iOS框架
 */
@interface FitCloudKit : NSObject

#pragma mark 版本信息

/**
 * @brief SDK版本号
 */
+(NSString*) sdkVersion;

/**
 * @brief SDK Build 版本号
 */
+(NSString*) sdkBuild;


#pragma mark 初始化/扫描/连接

/**
 * @brief 初始化
 * @param option 选项, 传nil则使用默认选项
 * @param callback 回调类，主要用于接受处理手环的请求命令或事件
 */
+(instancetype _Nonnull)initWithOption:(FitCloudOption* _Nullable)option callback:(id<FitCloudCallback> _Nullable)callback;

/**
 * @brief 扫描手环设备
 */
+(void)scanPeripherals;

/**
 * @brief 停止扫描手环设备
 */
+(void)stopScan;

/**
 * @brief 连接手环设备
 * @param peripheral 手环设备
 */
+(void)connect:(CBPeripheral * _Nonnull )peripheral;

/**
 * @brief 尝试连接已知的外部设备
 * @param record 已知的外部设备
 */
+(void)tryConnect:(FitCloudKitConnectRecord* _Nonnull )record;

/**
 * @brief 断开外部设备连接
 */
+(void)disconnect;

/**
 * @brief 忽略当前已连接未绑定/绑定失败的设备
 */
+(void)ignoreConnectedPeripheral;


#pragma mark 请求打开蓝牙来允许连接到配件
/**
 * @brief 请求打开蓝牙来允许连接到配件
 * @note 仅仅当系统蓝牙关闭时有效
 */
+(void) requestShowBluetoothPowerAlert;

#pragma mark 外设(手环)列表
/**
 * @brief 外设(手环)列表
 */
+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals;

#pragma mark 蓝牙中心设备(Central)状态
/**
 * @brief 蓝牙中心设备(Central)状态
 */
+(FITCLOUDBLECENTRALSTATE) bleState;

#pragma mark 蓝牙是否已连接
/**
 * @brief 蓝牙是否已连接
 */
+(BOOL) connected;

#pragma mark 蓝牙是否正在连接
/**
 * @brief 蓝牙是否正在连接
 */
+(BOOL) connecting;

#pragma mark 蓝牙外部设备是否初始化/准备完毕(是否可以执行与蓝牙外设的相关操作)
/**
 * @brief 蓝牙外部设备是否初始化/准备完毕(是否可以执行与蓝牙外设的相关操作)
 */
+(BOOL) deviceReady;

#pragma mark 蓝牙外部设备是否初始化/准备完毕且当前处于空闲状态(是否可以执行与蓝牙外设的相关操作)
/**
 * @brief 蓝牙外部设备是否初始化/准备完毕且当前处于空闲状态(是否可以执行与蓝牙外设的相关操作)
 */
+(BOOL) deviceIdle;

#pragma mark 当前是否允许手动同步运动健康数据
/**
 * @brief 当前是否允许手动同步运动健康数据
 */
+(BOOL) canSyncData;

#pragma mark 用户绑定状态
/**
 * @brief 用户绑定状态
 */
+(FITCLOUDUSERBINDSTATUS) userBindStatus;

#pragma mark 手环Mac地址
/**
 * @brief 手环Mac地址
 */
+(NSString*_Nullable) macAddr;

#pragma mark 手环当前所有配置信息
/**
 * @brief 手环当前所有配置信息
 */
+(FitCloudAllConfigObject*_Nullable) allConfig;


#pragma mark 手环当前电量信息
/**
 * @brief 手环当前电量信息
 */
+(FitCloudBatteryInfoObject*_Nullable) batteryInfo;

#pragma mark 手环闹钟列表
/**
 * @brief 手环闹钟列表
 */
+(NSArray<FitCloudAlarmObject*>*_Nullable) alarmlist;

#pragma mark 最后连接的手环信息
/**
 * @brief 最后连接的手环信息
 */
+(FitCloudKitConnectRecord*_Nullable) lastConnectPeripheral;

#pragma mark 手环连接历史
/**
 * @brief 手环连接历史
 */
+(NSArray<FitCloudKitConnectRecord*>*_Nonnull) historyPeripherals;

#pragma mark 删除手环连接历史
/**
 * @brief 删除手环连接历史
 */
+(void)removePeripheralHistoryWithUUID:(NSString*_Nonnull) uuid;

#pragma mark 清除手环连接历史
/**
 * @brief 清除手环连接历史
 */
+(void)clearPeripheralHistory;

@end

/**
 * @brief FitCloud Upgrade Module
 */
@interface FitCloudKit (Upgrade)

#pragma mark 准备进入固件升级模式
/**
 * @brief 准备进入固件升级模式
 * @param block 结果回调
 */
+(void)prepareDFUWithBlock:(FitCloudDFUPrepareResultBlock _Nullable )block;

#pragma mark 取消固件升级Pending模式
/**
 * @brief 取消固件升级Pending模式
 */
+(void)cancelDFUPendingMode;

@end

/**
 * @brief FitCloud Setting Module
 */
@interface FitCloudKit (Setting)

#pragma mark 同步系统时间
/**
 * @brief 同步系统时间（将手环的时间同步成跟手机的系统时间一致）
 * @param block 同步结果回调
 */
+(void)syncSystemTimeWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 同步天气信息
/**
 * @brief 同步天气信息
 * @param weather 天气信息
 * @param block 同步结果回调
 */
+(void) syncWeather:(FitCloudWeatherObject*_Nonnull)weather block:(FitCloudResultBlock _Nullable )block;

#pragma mark 设置闹钟列表
/**
 * @brief 设置闹钟（将手机上的闹钟列表同步到手环）
 * @param alarms 闹钟列表
 * @param block 结果回调
 */
+(void)setAlarms:(NSArray<FitCloudAlarmObject*>*_Nullable)alarms block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取闹钟列表
/**
 * @brief 获取闹钟列表（获取手环上的闹钟列表）
 * @param block 结果回调
 */
+(void)getAlarmsWithBlock:(FitCloudAlarmsResultBlock _Nullable )block;

#pragma  mark 设置User Profile
/**
 * @brief 设置 User Profile
 * @param profile user profile
 * @param block 结果回调
 */
+(void)setUserProfile:(FitCloudUserProfileObject *_Nonnull)profile block:(FitCloudResultBlock _Nullable )block;

#pragma mark 设定每日运动目标

/**
 * @brief 设定每日运动目标
 * @param stepcount 步数目标, 单位：步数
 * @param distance 距离目标, 单位：厘米(cm)
 * @param calory 卡路里, 单位：小卡(cal)
 * @param block 结果回调
 */
+(void)setDailyGoalWithStepCount:(UInt32) stepcount distance:(UInt32)distance calory:(UInt32)calory block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手环软硬件版本信息
/**
 * @brief 获取手环软硬件版本信息
 * @param block 结果回调
 */
+(void)getFirmwareVersionWithBlock:(FitCloudFirmwareVersionResultBlock _Nullable )block;

#pragma mark 设置消息通知开关
/**
 * @brief 设置消息通知开关
 * @param mnSetting 消息通知设置信息
 * @param block 结果回调
 */
+(void)setMessageNotification:(FITCLOUDMN)mnSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取消息通知开关设置
/**
 * @brief 获取消息通知开关设置信息
 * @param block 结果回调
 */
+(void)getMessageNotificationSettingWithBlock:(FitCloudMNSettingResultBlock _Nullable )block;

#pragma mark 设置手环表盘所有功能项显示状态
/**
 * @brief 设置手环表盘所有功能项显示状态
 * @param display 手环表盘所有功能项显示状态信息
 * @param block 结果回调
 */
+(void)setScreenDisplay:(FITCLOUDSCREENDISPLAY)display block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手环表盘所有功能项显示状态
/**
 * @brief 获取手环表盘所有功能项显示状态
 * @param block 结果回调
 */
+(void)getScreenDisplaySettingWithBlock:(FitCloudSDSettingResultBlock _Nullable )block;

#pragma mark 设置手环偏好
/**
 * @brief 设置手环偏好
 * @param prefer 手环偏好
 * @param block 结果回调
 */
+(void)setFitCloudPrefer:(FITCLOUDPREFER)prefer block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手环偏好设置
/**
 * @brief 获取手环偏好设置
 * @param block 结果回调
 */
+(void)getFitCloudPreferWithBlock:(FitCloudPreferResultBlock _Nullable )block;

#pragma mark 获取手环电量以及充电状态信息
/**
 * @brief 获取手环电量以及充电状态信息
 * @param block 结果回调
 */
+(void)getBatteryInfoWithBlock:(FitCloudBatteryInfoResultBlock _Nullable )block;

#pragma mark 如果空闲则请求更新手环电量信息
/**
 * @brief 如果空闲则请求更新手环电量信息
 */
+(void) requestUpdateBatteryInfoIfIdle;

#pragma mark 健康定时监测设置
/**
 * @brief 健康定时监测设置
 * @param htmSetting 健康定时监测设置
 * @param block 结果回调
 */
+(void)setHealthTimingMonitor:(FitCloudHTMObject*_Nonnull)htmSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取健康定时监测设置
/**
 * @brief 获取健康定时监测设置
 * @param block 结果回调
 */
+(void)getHealthTimingMonitorSettingWithBlock:(FitCloudHealtTimingMonitorResultBlock _Nullable )block;

#pragma mark 久坐提醒设置
/**
 * @brief 久坐提醒设置
 * @param lsrSetting 久坐提醒设置
 * @param block 结果回调
 */
+(void)setSedentaryRemind:(FitCloudLSRObject *_Nonnull)lsrSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取久坐提醒设置
/**
 * @brief 获取久坐提醒设置
 * @param block 结果回调
 */
+(void)getSedentaryRemindSettingWithBlock:(FitCloudLongSitRemindResultBlock _Nullable )block;

#pragma mark 喝水提醒设置
/**
 * @brief 喝水提醒设置
 * @param drSetting 喝水提醒设置
 * @param block 结果回调
 */
+(void)setDrinkRemind:(FitCloudDRObject*_Nonnull)drSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取喝水提醒设置
/**
 * @brief 获取喝水提醒设置
 * @param block 结果回调
 */
+(void)getDrinkRemindSettingWithBlock:(FitCloudDrinkRemindResultBlock _Nullable )block;

#pragma mark 抬腕唤醒设置
/**
 * @brief 抬腕唤醒设置
 * @param wwuSetting 抬腕唤醒设置
 * @param block 结果回调
 */
+(void)setWristWakeUp:(FitCloudWWUObject*_Nonnull)wwuSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取抬腕唤醒设置
/**
 * @brief 获取抬腕唤醒设置
 * @param block 结果回调
 */
+(void)getWristWakeUpSettingWithBlock:(FitCloudWristWakeUpResultBlock _Nullable )block;

#pragma mark 参考血压设置
/**
 * @brief 参考血压设置
 * @param bprSetting 血压参考范围设置信息
 * @param block 结果回调
 */
+(void)setBloodPressureRefer:(FitCloudBPRObject*_Nonnull)bprSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取参考血压设置
/**
 * @brief 获取参考血压设置
 * @param block 结果回调
 */
+(void)getBloodPressureReferSettingWithBlock:(FitCloudBloodPressureReferResultBlock _Nullable )block;


#pragma mark APP主动点击退出睡眠
/**
 * @brief APP主动点击退出睡眠
 * @param block 结果回调
 */
+(void)exitSleepWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 同步系统语言
/**
* @brief 同步系统语言（将手环的时间同步成跟手机的系统语言一致）
* @param block 同步结果回调
*/
+(void)syncSystemLanguageWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 查找手环 (查找成功则手环会震动或发出提醒声)
/**
 * @brief 查找手环 (查找成功则手环会震动或发出提醒声)
 * @param block 结果回调
 */
+(void)findBraceletWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 一键恢复出厂设置
/**
 * @brief 一键恢复出厂设置
 * @param block 结果回调
 */
+(void)restoreAsFactorySettingsWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 手环关机
/**
 * @brief 手环关机
 * @param block 结果回调
 */
+(void)turnOffWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 重启手环
/**
 * @brief 重启手环
 * @param block 结果回调
 */
+(void)rebootWithBlock:(FitCloudResultBlock _Nullable )block;

@end

/**
 * @brief FitCloudKit Bind Module
 */
@interface FitCloudKit (Bind)

#pragma mark 是否已经绑定
/**
 * @brief 是否已经绑定
 */
+(BOOL) alreadyBound;

#pragma mark 检查用户是否已经绑定
/**
 * @brief 检查用户是否已经绑定
 * @param userId 用户Id
 * @return YES 已经绑定 NO 未绑定
 */
+(BOOL) isUserAlreadyBound:(NSInteger)userId;

#pragma mark 绑定用户
/**
 * @brief 绑定用户
 * @param userId 用户Id
 * @param bAbort 如果已经存在绑定用户是否终止，当为FALSE时，自动先解绑并绑定新的用户
 * @param block 结果回调
 */
+(void)bindUserObject:(NSInteger)userId abortIfExist:(BOOL)bAbort block:(FitCloudResultBlock _Nullable )block;

#pragma mark 用户解绑
/**
 * @brief 用户解绑
 * @param shouldDisconnectIfSuccess 解绑成功后是否需要自动断开连接
 * @param block 结果回调
 */
+(void)unbindUserObject:(BOOL) shouldDisconnectIfSuccess block:(FitCloudResultBlock _Nullable )block;

@end

/**
 * @brief FitCloudKit Sports Module
 */
@interface FitCloudKit (Sports)

#pragma mark 请求当天运动健康数据信息
/**
 * @brief 请求当天运动健康数据信息
 * @param block 结果回调
 */
+(void) requestHealthAndSportsDataTodayWithBlock:(FitCloudHealthAndSportsDataTodayResultBlock _Nullable )block;

#pragma mark 启动/关闭实时健康测量（心率、血氧、血压、呼吸频率等）
/**
 * @brief 启动/关闭实时健康测量（心率、血氧、血压、呼吸频率等）
 * @param rtmParam 实时测量参数
 * @param block 调用结果回调
 */
+(void) requestRealTimeHealthMeasuring:(FitCloudRealTimeHealthMeasuringParam*_Nonnull)rtmParam block:(FitCloudResultBlock _Nullable )block;

#pragma mark 手动同步历史运动健康数据
/**
 * @brief 手动同步历史运动健康数据
 * @param progress 进度回调
 * @param block 结果回调
 */
+(void)manualSyncDataWithProgress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;

@end

/**
 * @brief FitCloudKit RemoteCtrl Module
 */
@interface FitCloudKit (RemoteCtrl)

#pragma mark APP通知手环当前APP的相机状态（前台/后台）
/**
 * @brief APP通知手环当前APP的相机状态（前台/后台）
 * @param state APP相机状态（前台/后台）
 * @param block 结果回调
 */
+(void)notifyAppCameraState:(APPCAMERASTATE)state withBlock:(FitCloudResultBlock _Nullable )block;
@end


NS_ASSUME_NONNULL_END
