//
//  FitCloudKit.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//
//  框架名称:FitCloudKit.xcframework
//  框架功能:The iOS framework for the FitCloudPro smartwatch, which is responsible for encapsulating features such as communication with the watch device.
//          FitCloudPro 智能手表的 iOS 框架，负责与手表设备通信等功能的封装。
//
//  构建版本:
//      pcjbird    2024-10-11  Version:1.3.0-beta.5 Build:20241011002


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudKit/FitCloudEvent.h>
#import <FitCloudKit/FitCloudCallback.h>
#import <FitCloudKit/FitCloudOption.h>
#import <FitCloudKit/FitCloudKitConnectRecord.h>
#import <FitCloudKit/SmartWatchOperation.h>
#import <FitCloudKit/SmartWatchOperation+Private.h>
#import <FitCloudKit/SmartWatchBackgroundOperationQueue.h>


NS_ASSUME_NONNULL_BEGIN

/// FitCloud智能手表iOS框架
@interface FitCloudKit : NSObject

#pragma mark 版本信息

/// SDK版本号
/// - Returns:
/// SDK 版本号
+(NSString*) sdkVersion;

/// SDK Build 版本号
/// - Returns:
/// SDK Build 版本号
+(NSString*) sdkBuild;


#pragma mark 初始化/扫描/连接

/// 初始化
/// - Parameters:
///   - option: 选项, 传nil则使用默认选项
///   - callback 回调类，主要用于接受处理手表的请求命令或事件
/// - Returns:
///  FitCloudKit
+(instancetype _Nonnull)initWithOption:(FitCloudOption* _Nullable)option callback:(id<FitCloudCallback> _Nullable)callback;

/// 扫描手表设备
+(void)scanPeripherals;

/// 停止扫描手表设备
+(void)stopScan;

/// 如果您使用自己的扫描方法，将您的外设转换成可连接的外设
/// - Parameters:
///   - peripheral: 您自己扫描的外设
///   - completion: 转换结果
+(void)translatePeripheral:(CBPeripheral * _Nonnull )peripheral toConnectablePeripheralCompletion:(void(^_Nullable)(BOOL success, NSError * _Nullable error, CBPeripheral * _Nullable connectablePeripheral)) completion;

/// 连接手表设备
/// - Parameters:
///   - peripheral: 手表设备
+(void)connect:(CBPeripheral * _Nonnull )peripheral;

/// 连接手表设备
/// - Parameters:
///   - peripheral: 手表设备
///   - btMode: 是否使用一键双连同时连接经典蓝牙(BT)
+(void)connect:(CBPeripheral * _Nonnull )peripheral btMode:(BOOL)btMode;

/// 连接并绑定手表设备
/// - Parameters:
///   - peripheral: 手表设备
///   - userId: 用户Id
///   - randomCode: 随机码，如果没有，则填 nil，仅部分项目有该功能
///   - btMode: 是否使用一键双连同时连接经典蓝牙(BT)
+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;

/// 尝试连接历史手表设备
/// - Parameters:
///   - record: 历史手表设备
+(void)tryConnect:(FitCloudKitConnectRecord* _Nonnull )record;

/// 断开手表设备连接
+(void)disconnect;

/// 忽略当前已连接未绑定/绑定失败的手表设备
/// - Parameters:
///   - silent: YES则不会打印相关日志
+(void)ignoreConnectedPeripheral:(BOOL)silent;


#pragma mark 请求打开蓝牙来允许连接到配件

/// 请求打开蓝牙来允许连接到配件
///
/// 仅仅当系统蓝牙关闭时有效
+(void) requestShowBluetoothPowerAlert;

#pragma mark 扫描到的外设(手表)列表

/// 扫描到的外设(手表)列表
/// - Returns:
/// 扫描到的蓝牙外设
+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals;

#pragma mark 蓝牙中心设备(Central)状态

///蓝牙中心设备(Central)状态
+(FITCLOUDBLECENTRALSTATE) bleState;

#pragma mark 蓝牙是否已连接

/// 蓝牙是否已连接
+(BOOL) connected;

#pragma mark 蓝牙是否正在连接

///蓝牙是否正在连接
+(BOOL) connecting;

#pragma mark 蓝牙外部设备是否初始化/准备完毕(是否可以执行与蓝牙外设的相关操作)

/// 蓝牙外部设备是否初始化/准备完毕(是否可以执行与蓝牙外设的相关操作)
+(BOOL) deviceReady;

#pragma mark 手表准备连接后的准备工作是否已完成

/// 手表准备连接后的准备工作是否已完成
+(BOOL) devicePrepareWorkFinished;

#pragma mark 蓝牙外部设备是否初始化/准备完毕且当前处于空闲状态(是否可以执行与蓝牙外设的相关操作)

/// 蓝牙外部设备是否初始化/准备完毕且当前处于空闲状态(是否可以执行与蓝牙外设的相关操作)
+(BOOL) deviceIdle;

#pragma mark 当前是否允许手动同步运动健康数据

/// 当前是否允许手动同步运动健康数据
+(BOOL) canSyncData;

#pragma mark 用户绑定状态

///用户绑定状态
+(FITCLOUDUSERBINDSTATUS) userBindStatus;

#pragma mark 连接标志
/// 连接标志
+(FITCLOUDWATCHCONNECTIONFLAG) connectionFlag;

#pragma mark 手表Mac地址

///手表Mac地址
+(NSString*_Nullable) macAddr;

#pragma mark 手表当前所有配置信息

/// 手表当前所有配置信息
+(FitCloudAllConfigObject*_Nullable) allConfig;

#pragma mark 手表当前电量信息

/// 手表当前电量信息
+(FitCloudBatteryInfoObject*_Nullable) batteryInfo;

#pragma mark 手表闹钟列表

/// 手表闹钟列表
+(NSArray<FitCloudAlarmObject*>*_Nullable) alarmlist;

#pragma mark 手表日程列表

/// 手表日程列表
+(NSArray<FitCloudScheduleObject*>*_Nullable) schedulelist;

#pragma mark 手表常用联系人列表

/// 手表常用联系人列表
+(NSArray<FitCloudContactObject*>*_Nullable) favoriteContacts;


#pragma mark 手表习惯养成列表

/// 手表习惯养成列表
+(NSArray<FitCloudHabitObject*>*_Nullable) habits;

#pragma mark 手表勋章列表

/// 手表勋章列表
+(NSArray<FitCloudMedal*>*_Nullable) medals;

#pragma mark 最后连接的手表信息

/// 最后连接的手表信息
+(FitCloudKitConnectRecord*_Nullable) lastConnectPeripheral;

#pragma mark 手表连接历史

/// 手表连接历史
+(NSArray<FitCloudKitConnectRecord*>*_Nonnull) historyPeripherals;

#pragma mark 删除手表连接历史

/// 删除手表连接历史
/// - Parameters:
///   - uuid: peripheral uuid
+(void)removePeripheralHistoryWithUUID:(NSString*_Nonnull) uuid;

#pragma mark 清除手表连接历史

/// 清除手表连接历史
+(void)clearPeripheralHistory;

@end

/// FitCloud Upgrade Module
@interface FitCloudKit (Upgrade)

#pragma mark 当前是否为DFU模式

/// 当前是否为DFU模式
/// - Returns:
/// 是否为DFU模式
+(BOOL)  isCurrentDFUMode;

#pragma mark dfu外设

/// dfu外设，仅仅当处于dfu模式，且处于连接状态时有效
/// - Returns:
/// dfu 外设
+(CBPeripheral* _Nullable)  dfuPeripheral;

#pragma mark 使用不进入DFU模式, 直接DFU升级, 使用该外设

/// dfu外设，仅仅需要直接DFU升级的客户使用(升级不进入DFU模式)，且处于连接状态时有效
/// - Returns:
/// dfu 外设
+(CBPeripheral* _Nullable)  directDFUPeripheral;

#pragma mark 芯片提供商

/// 当前芯片提供商
+(FITCLOUDCHIPVENDOR)  chipVendor;

#pragma mark 准备进入固件升级模式

/// 准备进入固件升级模式
/// - Parameters:
///   - block: 结果回调
+(void)enterDFUModeWithBlock:(FitCloudEnterDFUModeResultBlock _Nullable )block;

#pragma mark 退出固件升级模式

/// 退出固件升级模式
/// - Parameters:
///   - block: 结果回调
+(void)exitDFUModeWithBlock:(FitCloudExitDFUModeResultBlock _Nullable )block;

#pragma mark 判断设备是否支持指定的常用功能

/// 判断设备是否支持指定的常用功能
/// - Parameters:
///   - feature: 功能
/// - Returns:
/// 是否支持该功能
+(BOOL)isDeviceSupportFeature:(FITCLOUDDEVICEFEATURE)feature;

@end

/// FitCloud Setting Module
@interface FitCloudKit (Setting)

#pragma mark 同步系统时间

/// 同步系统时间（将手表的时间同步成跟手机的系统时间一致）
/// - Parameters:
///  - block: 同步结果回调
+(void)syncSystemTimeWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 同步指定时间到手表

///同步指定时间到手表
/// - Parameters:
///  - block: 同步结果回调
+(void)syncTimeToWatch:(NSDate*)time  block:(FitCloudResultHandler _Nullable )block;

#pragma mark 同步天气信息

/// 同步天气信息
/// - Parameters:
///  - weather: 天气信息
///  - block: 同步结果回调
+(void) syncWeather:(FitCloudWeatherObject*_Nonnull)weather block:(FitCloudResultHandler _Nullable )block;

#pragma mark 设置24小时天气信息

/// 设置24小时天气信息
/// - Parameters:
///   - weathers: 小时天气列表，从指定时间戳开始之后按顺序排列的小时天气信息
///   - timestamp: 时间戳
///   - completion: 结果回调
+(void)set24HoursWeather:(NSArray<FitCloudHourWeatherObject*>* _Nonnull)weathers timestamp:(NSDate* _Nonnull)timestamp completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark 设置闹钟列表

/// 设置闹钟（将手机上的闹钟列表同步到手表）
/// - Parameters:
///   - alarms: 闹钟列表
///   - block: 结果回调
+(void)setAlarms:(NSArray<FitCloudAlarmObject*>*_Nullable)alarms block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取闹钟列表

/// 获取闹钟列表（获取手表上的闹钟列表）
/// - Parameters:
///   - block: 结果回调
+(void)getAlarmsWithBlock:(FitCloudAlarmsResultBlock _Nullable )block;

#pragma mark 设置是否允许手表设置日程

/// 设置是否允许手表设置日程
/// - Parameters:
///  - allow: 是否允许手表设置日程
///  - block: 结果回调
+(void)setAllowWatchScheduleSettings:(BOOL)allow completion:(FitCloudResultHandler _Nullable )block;

#pragma mark 设置日程列表

/// 设置日程（将手机上的日程列表同步到手表）
/// - Parameters:
///   - schedules: 日程列表
///   - block: 结果回调
+(void)setSchedules:(NSArray<FitCloudScheduleObject*>*_Nullable)schedules block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取日程列表

/// 获取日程列表（获取手表上的日程列表）
/// - Parameters:
///   - block: 结果回调
+(void)getSchedulesWithBlock:(FitCloudSchedulesResultBlock _Nullable )block;

#pragma mark 设置常用联系人

/// 设置常用联系人（将手机上的常用联系人列表同步到手表）
/// - Parameters:
///   - contacts: 常用联系人列表
///   - block: 结果回调
+(void) setFavContacts:(NSArray<FitCloudContactObject*>*_Nullable)contacts block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取常用联系人

/// 获取常用联系人列表（获取手表上的常用联系人列表）
/// - Parameters:
///   - block: 结果回调
+(void) getFavContactsWithBlock:(FitCloudFavContactsResultBlock _Nullable)block;

#pragma mark 设置手表紧急联系人

/// 设置手表紧急联系人
/// - Parameters:
///   - contacts: 紧急联系人
///   - on: 是否启用紧急联系人
///   - completion: 结果回调
+(void) setEmergencyContacts:(NSArray<FitCloudEmergencyContactObject*>* _Nullable)contacts on:(BOOL)on completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark 获取手表紧急联系人

/// 获取手表紧急联系人
/// - Parameters:
///   - completion: 结果回调
+(void) queryEmergencyContactsWithCompletion:(FitCloudEmergencyContactsQueryCompletion _Nullable)completion;

#pragma mark 设置习惯养成列表

/// 设置习惯养成列表（将手机上的习惯养成列表同步到手表）
/// - Parameters:
///   - habits: 习惯养成列表
///   - block: 结果回调
+(void) setHabits:(NSArray<FitCloudHabitObject*>*_Nullable)habits block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取习惯养成列表

///获取习惯养成列表（获取手表上的习惯养成列表）
/// - Parameters:
///   - block: 结果回调
+(void) getHabitsWithBlock:(FitCloudHabitsResultBlock _Nullable)block;

#pragma  mark 设置User Profile

/// 设置 User Profile
/// - Parameters:
///   - profile: user profile
///   - block: 结果回调
+(void)setUserProfile:(FitCloudUserProfileObject *_Nonnull)profile block:(FitCloudResultHandler _Nullable )block;

#pragma  mark 设置自定义标签

/// 设置自定义标签
/// - Parameters:
///   - labels: 自定义标签
///   - block: 结果回调
+(void)setCustomLabels:(FitCloudCustomLabelsObject *_Nonnull)labels block:(FitCloudResultHandler _Nullable )block;

#pragma mark 设定每日运动目标

/// 设定每日运动目标
///  - Parameters:
///    - stepcount: 步数目标, 单位：步数
///    - distance: 距离目标, 单位：厘米(cm)
///    - calorie: 卡路里, 单位：小卡(cal)
///    - duration: 运动时长，单位：分钟(Min)
///    - timestamp: 时间戳，传nil，则默认为当前时间
///    - block: 结果回调
+(void)setDailyGoalWithStepCount:(UInt32) stepcount distance:(UInt32)distance calorie:(UInt32)calorie duration:(UInt16)duration timestamp:(NSDate* _Nullable )timestamp block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取每日运动目标

/// 获取每日运动目标
/// - Parameters:
///   - block: 结果回调
+(void)getDailyGoalWithBlock:(FitCloudDailyGoalResultBlock _Nullable )block;

#pragma mark 获取手表软硬件版本信息

/// 获取手表软硬件版本信息
/// - Parameters:
///   - block: 结果回调
+(void)getFirmwareVersionWithBlock:(FitCloudFirmwareVersionResultBlock _Nullable )block;

#pragma mark 设置消息通知开关

/// 设置消息通知开关
/// - Parameters:
///   - mnSetting: 消息通知设置信息
///   - block: 结果回调
+(void)setMessageNotification:(FITCLOUDMN)mnSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取消息通知开关设置

/// 获取消息通知开关设置信息
/// - Parameters:
///   - block: 结果回调
+(void)getMessageNotificationSettingWithBlock:(FitCloudMNSettingResultBlock _Nullable )block;

#pragma mark 设置手表表盘所有功能项显示状态

/// 设置手表表盘所有功能项显示状态
/// - Parameters:
///   - display: 手表表盘所有功能项显示状态信息
///   - block: 结果回调
+(void)setScreenDisplay:(FITCLOUDSCREENDISPLAY)display block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取手表表盘所有功能项显示状态

/// 获取手表表盘所有功能项显示状态
/// - Parameters:
///   - block: 结果回调
+(void)getScreenDisplaySettingWithBlock:(FitCloudSDSettingResultBlock _Nullable )block;

#pragma mark 设置手表偏好

/// 设置手表偏好
/// - Parameters:
///   - prefer: 手表偏好
///   - block: 结果回调
+(void)setFitCloudPrefer:(FITCLOUDPREFER)prefer block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取手表偏好设置

/// 获取手表偏好设置
/// - Parameters:
///   - block: 结果回调
+(void)getFitCloudPreferWithBlock:(FitCloudPreferResultBlock _Nullable )block;

#pragma mark 获取手表电量以及充电状态信息

/// 获取手表电量以及充电状态信息
/// - Parameters:
///   - block: 结果回调
+(void)getBatteryInfoWithBlock:(FitCloudBatteryInfoResultBlock _Nullable )block;

#pragma mark 如果空闲则请求更新手表电量信息

/// 如果空闲则请求更新手表电量信息
+(void) requestUpdateBatteryInfoIfIdle;

#pragma mark 健康定时监测设置

/// 健康定时监测设置
/// - Parameters:
///   - htmSetting: 健康定时监测设置
///   - block: 结果回调
+(void)setHealthTimingMonitor:(FitCloudHTMObject*_Nonnull)htmSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取健康定时监测设置

/// 获取健康定时监测设置
/// - Parameters:
///   - block: 结果回调
+(void)getHealthTimingMonitorSettingWithBlock:(FitCloudHealthTimingMonitorResultBlock _Nullable )block;

#pragma mark 健康定时监测独立设置

/// 健康定时监测独立设置
/// - Parameters:
///   - htmlSingleSettings: 健康定时监测独立设置信息，可以单个类型单独设置也可以多个类型一起设置
///   - completion: 结果回调
+(void) setSingleHealthTimingMonitoring:(NSArray<FitCloudHTMSingleObject*>*) htmSingleSettings completion:(FitCloudResultHandler _Nullable )completion;

#pragma mark 获取健康定时监测独立设置

/// 获取健康定时监测独立设置
/// - Parameters:
///   - completion: 结果回调
+(void) getSingleHealthTimingMonitoringSettingsWithCompletion:(FitCloudHealthTimingMonitoringSingleSettingsResultBlock _Nullable)completion;

#pragma mark 久坐提醒设置

/// 久坐提醒设置
/// - Parameters:
///   - lsrSetting: 久坐提醒设置
///   - block: 结果回调
+(void)setSedentaryRemind:(FitCloudLSRObject *_Nonnull)lsrSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取久坐提醒设置

/// 获取久坐提醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getSedentaryRemindSettingWithBlock:(FitCloudLongSitRemindResultBlock _Nullable )block;

#pragma mark 喝水提醒设置

/// 喝水提醒设置
/// - Parameters:
///   - drSetting: 喝水提醒设置
///   - block: 结果回调
+(void)setDrinkRemind:(FitCloudDRObject*_Nonnull)drSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取喝水提醒设置

/// 获取喝水提醒设置
/// - Parameters:
///   -  block: 结果回调
+(void)getDrinkRemindSettingWithBlock:(FitCloudDrinkRemindResultBlock _Nullable )block;

#pragma mark 个性化提醒

/// Set the personalized reminder, If the reminderId already exist, it will be replaced
/// - Parameters:
///   - remind: the remind
///   - completion: the completion callback
+(void)setPersonalizedRemind:(FitCloudPersonalizedReminderObject* _Nonnull)remind completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark 查询个性化提醒

/// Query the personalized reminders array
/// - Parameters:
///   - completion: the completion callback
+(void)queryPersonalizedRemindersWithCompletion:(FitCloudPersonalizedRemindersQueryCompletion _Nullable)completion;

#pragma mark 删除个性化提醒

/// Remove the personalized reminders with id array
/// - Parameters:
///   - idArray: the reminder id array
///   - completion: the completion callback
+(void)removePersonalizedRemindersWithIdArray:(NSArray<NSNumber*>* _Nonnull)idArray completion:(FitCloudResultHandler _Nullable)completion;

#pragma mark 防护提醒设置

/// 防护提醒设置
/// - Parameters:
///   - prSetting: 防护提醒设置
///   - block: 结果回调
+(void)setProtectionRemind:(FitCloudPRObject*_Nonnull)prSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取防护提醒设置

/// 获取防护提醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getProtectionRemindSettingWithBlock:(FitCloudProtectionRemindResultBlock _Nullable )block;

#pragma mark 洗手提醒设置

/// 洗手提醒设置
/// - Parameters:
///   - hwrSetting: 洗手提醒设置
///   - block: 结果回调
+(void)setHandWashRemind:(FitCloudHandWashRemindObject*_Nonnull)hwrSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取洗手提醒设置

/// 获取洗手提醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getHandWashRemindSettingWithBlock:(FitCloudHandWashRemindResultBlock _Nullable )block;

#pragma mark 抬腕唤醒设置

/// 抬腕唤醒设置
/// - Parameters:
///   - wwuSetting: 抬腕唤醒设置
///   - block: 结果回调
+(void)setWristWakeUp:(FitCloudWWUObject*_Nonnull)wwuSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取抬腕唤醒设置

/// 获取抬腕唤醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getWristWakeUpSettingWithBlock:(FitCloudWristWakeUpResultBlock _Nullable )block;

#pragma mark 参考血压设置

/// 参考血压设置
/// - Parameters:
///   - bprSetting: 血压参考范围设置信息
///   - block: 结果回调
+(void)setBloodPressureRefer:(FitCloudBPRObject*_Nonnull)bprSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取参考血压设置

/// 获取参考血压设置
/// - Parameters:
///   - block: 结果回调
+(void)getBloodPressureReferSettingWithBlock:(FitCloudBloodPressureReferResultBlock _Nullable )block;

#pragma mark 心率报警设置

/// 心率报警设置
/// - Parameters:
///   - hrAlarmSetting: 心率报警设置
///   - block: 结果回调
+(void)setHRAlarm:(FitCloudHRAlarmObject* _Nonnull)hrAlarmSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取心率报警设置

/// 获取心率报警设置
/// - Parameters:
///   - block: 结果回调
+(void)getHRAlarmSettingWithBlock:(FitCloudHRAlarmResultBlock _Nullable)block;

#pragma mark 血压报警设置

/// 血压报警设置
/// - Parameters:
///   - bpAlarmSetting: 血压报警设置
///   - block: 结果回调
+(void)setBPAlarm:(FitCloudBPAlarmObject* _Nonnull)bpAlarmSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取血压报警设置

/// 获取血压报警设置
/// - Parameters:
///   - block: 结果回调
+(void)getBPAlarmSettingWithBlock:(FitCloudBPAlarmResultBlock _Nullable)block;

#pragma mark 勿扰模式设置

/// 勿扰模式设置
/// - Parameters:
///   - dndSetting: 勿扰模式设置
///   - block: 结果回调
+(void)setDND:(FitCloudDNDSetting* _Nonnull)dndSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取勿扰模式设置

/// 获取勿扰模式设置
/// - Parameters:
///   - block: 结果回调
+(void)getDNDSettingWithBlock:(FitCloudDNDSettingResultBlock _Nullable)block;

#pragma mark 省电模式设置

///省电模式设置
/// - Parameters:
///   - settings: 省电模式设置
///   - block: 结果回调
+(void)setPowerSavingSettings:(FitCloudPowerSavingSetting* _Nonnull)settings block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取省电模式设置

/// 获取省电模式设置
/// - Parameters:
///   - block: 结果回调
+(void)getPowerSavingSettingWithBlock:(FitCloudPowerSavingSettingResultBlock _Nullable)block;


#pragma mark 获取手表UI信息

///获取手表UI信息
/// - Parameters:
///   - block: 结果回调
+(void)getWatchUIInformationWithBlock:(FitCloudWatchUIInfoResultBlock _Nullable)block;


#pragma mark 获取表盘UI信息

/// 获取表盘UI信息
/// - Parameters:
///   - block: 结果回调
+(void)getWatchfaceUIInformationWithBlock:(FitCloudWatchfaceUIInfoResultBlock _Nullable)block;


#pragma mark 切换表盘，并修改该表盘对应的所有模块(组件)样式

/// 切换表盘，并修改该表盘对应的所有模块(组件)样式
/// - Parameters:
///   - slotIndex: 表盘位置索引，有效值0～10，将表盘切换到该索引的位置
///   - styleArray: 模块(组件)样式数组，假设该表盘对应4个组件，则该数组包含4个元素，每个元素对应该组件要切换到的样式，样式类型对应WATCHFACEMODULESTYLE的定义，若果该参数设置为nil，则仅切换表盘位置，否则同时修改其所有组件样式
///   - completion: 结果回调
+(void)toggleWatchfaceWithSlotIndex:(NSInteger)slotIndex modulesStyleArray:(NSArray<NSNumber*>* _Nullable)styleArray completion:(FitCloudResultHandler)completion;


#pragma mark 女性健康设置

/// 女性健康设置
/// - Parameters:
///   - whSetting: 女性健康设置信息
///   - block: 结果回调
+(void)setWomenHealthConfig:(FitCloudWomenHealthSetting*_Nonnull)whSetting block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取女性健康设置

/// 获取女性健康设置
/// - Parameters:
///   - block: 结果回调
+(void)getWomenHealthSettingWithBlock:(FitCloudWomenHealthSettingResultBlock _Nullable )block;

#pragma mark 情侣功能

/// Send lovers bonding notification to the device
/// - Parameters:
///   - notification: lovers bonding notification
///   - completion: the completion callback
+(void)sendLoversBondingNotifcation:(FITCLOUDLOVERSBONDINGNOTIFICATION)notification completion:(FitCloudResultHandler _Nullable)completion;

/// Callback the lovers message send result
/// - Parameters:
///   - result: the lovers message send result
///   - completion: the completion callback
+(void)callbackLoversMessageSendResult:(FITCLOUDLOVERSMESSAGESENDRESULT)result completion:(FitCloudResultHandler _Nullable)completion;

/// Set the love memorial day
/// - Parameters:
///   - loveMemorialDay: the love memorial day
///   - completion: the completion callback
+(void)setLoveMemorialDay:(NSDate*)loveMemorialDay completion:(FitCloudResultHandler _Nullable)completion;

/// Received the lover message
/// - Parameters:
///   - message: the lover message
///   - completion: the completion callback
+(void)receivedLoverMessage:(NSString*)message completion:(FitCloudResultHandler _Nullable) completion;


#pragma mark GPS固件信息

/// Query GPS firmware information
+(void)queryGPSFirmwareInfoWithCompletion:(FitCloudGPSFirmwareInfoQueryCompletion _Nullable)completion;


#pragma mark 锁屏设置

/// 锁屏设置
/// - Parameters:
///   - lockScreenSetting: 锁屏设置
///   - block: 结果回调
+(void)setLockScreenSetting:(FitCloudLockScreenSetting* _Nonnull)lockScreenSetting block:(FitCloudResultHandler _Nullable)block;


#pragma mark APP主动点击退出睡眠

/// APP主动点击退出睡眠
/// - Parameters:
///   - block: 结果回调
+(void)exitSleepWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 同步系统语言

/// 同步系统语言，将手表的时间同步成跟手机的系统语言一致
///
/// 如果你自定义设定了手表语言将同步您的设定
/// - Parameters:
///   - block: 同步结果回调
+(void)syncSystemLanguageWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 自定义设置手表语言

/// 自定义设置手表语言
/// - Parameters:
///   - lang: 语言
///   - block: 结果回调
+(void)setSmartWatchLanguage:(FITCLOUDLANGUAGE)lang completion:(FitCloudResultHandler _Nullable )block;

#pragma mark 查询手表语言设置

/// 查询手表语言
/// - Parameters:
///   - completion: 查询结果回调
+(void)querySmartWatchLanguageWithCompletion:(FitCloudLanguageQueryCompletion _Nullable )completion;

#pragma mark 获取手表支持的游戏类型

/// 获取手表支持的游戏类型
/// - Parameters:
///   - block: 结果回调
+(void)getSupportedGamesWithBlock:(FitCloudSupportedGamesResultBlock _Nullable)block;

#pragma mark 获取游戏最高三个游戏记录

///获取游戏最高三个游戏记录
/// - Parameters:
///   - block: 结果回调
+(void)getTop3RankGameRecordsWithBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;

#pragma mark 获取单个游戏最高三个游戏记录

/// 获取单个游戏最高三个游戏记录
/// - Parameters:
///   - gameNo: 游戏编号
///   - block: 结果回调
+(void)getSingleGameTop3RankGameRecords:(NSInteger)gameNo withBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;

#pragma mark 获取手表所有游戏的皮肤信息

/// 获取手表所有游戏的皮肤信息
/// - Parameters:
///   - block: 结果回调
+(void)getAllGameSkinsWithBlock:(FitCloudAllGameSkinsResultBlock _Nullable)block;

#pragma mark 设置游戏排名趋势

/// 设置游戏排名趋势
/// - Parameters:
///   - trendsArray: 排名趋势数组，最多60
///   - block: 结果回调
+(void)setGameRankingTrendsArray:(NSArray<FitCloudGameRankingTrend*>*)trendsArray completion:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取亮屏时长、亮度、振动等信息

/// 获取亮屏时长、亮度、振动等信息
/// - Parameters:
///   - block: 结果回调
+(void)getScreenAndVibrateSettingsWithBlock:(FitCloudScreenAndVibrateSettingsResultBlock _Nullable)block;

#pragma mark 获取屏幕分辨率相关信息

/// 获取屏幕分辨率相关信息
/// - Parameters:
///   - block: 结果回调
+(void)getScreenResolutionWithBlock:(FitCloudScreenResolutionResultBlock _Nullable)block;

#pragma mark 获取相册推送功能参数信息

/// 获取相册推送功能参数信息
/// - Parameters:
///   - block: 结果回调
+(void)getPhotoPushParamsWithBlock:(FitCloudPhotoAlbumParamsResultBlock _Nullable)block;

#pragma mark 获取设备可支持的运动模式类型列表

/// 获取设备可支持的运动模式类型列表
/// - Parameters:
///   - block: 结果回调
+(void)getSupportedWatchSportsWithBlock:(FitCloudSupportedWatchSportsResultBlock _Nullable)block;

#pragma mark 获取设备当前运动模式类型列表

/// 获取设备当前运动模式类型列表
/// - Parameters:
///   - block: 结果回调
+(void)getCurrentWatchSportsWithBlock:(FitCloudCurrentWatchSportsResultBlock _Nullable)block;

#pragma mark 获取手表指定支持的收款码和名片码功能列表

/// 获取手表指定支持的收款码和名片码功能列表
/// - Parameters:
///   - block: 结果回调
+(void) getWatchSpecifiedSupportedMoneyReceiveAndBusinessQRCodeFeaturesWithBlock:(FitCloudQRCodeFeaturesResultBlock _Nullable)block;

#pragma mark 设置勋章列表

/// 设置勋章列表（将手机上的勋章列表同步到手表）
/// - Parameters:
///   - medals: 勋章列表
///   - block: 结果回调
+(void) setMedals:(NSArray<FitCloudMedal*>*_Nullable)medals block:(FitCloudResultHandler _Nullable )block;

#pragma mark 获取勋章列表

/// 获取勋章列表（获取手表上的勋章列表）
/// - Parameters:
///   - block: 结果回调
+(void) getMedalsWithBlock:(FitCloudMedalsResultBlock _Nullable)block;

#pragma mark 获取支持的日程类型列表

/// 获取支持的日程类型列表（获取手表上支持的日程类型列表）
/// - Parameters:
///   - block: 结果回调
+(void) getSupportedSchedulesWithBlock:(FitCloudSupportedSchedulesResultBlock _Nullable)block;


#pragma mark 设置亮屏时长、亮度、振动等信息

/// 设置亮屏时长、亮度、振动等信息
/// - Parameters:
///   - screenSettings: 亮屏时长、亮度等信息
///   - vibrateSettings: 马达振动信息
///   - block: 结果回调
+(void)setScreenSettings:(FitCloudScreenSetting*) screenSettings vibrateSettings:(FitCloudVibrateSetting*)vibrateSettings completion:(FitCloudResultHandler _Nullable )block;

#pragma mark 查找手表 (查找成功则手表会震动或发出提醒声)

/// 查找手表 (查找成功则手表会震动或发出提醒声)
/// - Parameters:
///   - comletion: 结果回调
+(void)findWatchWithCompletion:(FitCloudResultHandler _Nullable )comletion;

#pragma mark 停止查找手表

/// 停止查找手表
/// - Parameters:
///   - comletion: 结果回调
+(void)stopFindWatchWithCompletion:(FitCloudResultHandler _Nullable )comletion;

#pragma mark 一键恢复出厂设置

/// 一键恢复出厂设置
/// - Parameters:
///   - block: 结果回调
+(void)restoreAsFactorySettingsWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 手表关机

/// 手表关机
/// - Parameters:
///   - block: 结果回调
+(void)turnOffWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 重启手表

/// 重启手表
/// - Parameters:
///   - block: 结果回调
+(void)rebootWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 设置广播数据自定义字段 key1

/// 设置广播数据自定义字段 key1
/// - Parameters:
///   - keyData: 自定义字段的key，注意keyData必须为6个字节，且需要自己管理字节序，SDK会将设置的值直接发送给手表
///   - block: 结果回调
+(void)setCustomBroadcastKey:(NSData*) keyData withBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark APP通知手表当前APP的定位服务状态

/// APP通知手表当前APP的定位服务状态
/// - Parameters:
///   - state: APP定位服务状态
///   - block: 结果回调
+(void)notifyAppLocServiceState:(APPLOCATIONSERVICESTATE)state withBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 推送收款码或名片二维码

/// 推送收款码或名片二维码
/// - Parameters:
///   - qrcode: 类型
///   - content: 二维码内容
///   - block: 结果回调
+(void)sendQRCode:(FITCLOUDQRCODE)qrcode content:(NSString*)content withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 设置手表启动震动参数

/// 设置手表启动震动参数
/// - Parameters:
///   - param: 参数
///   - block: 结果回调
+(void)setWatchLaunchVibrateParam:(FitCloudWatchLaunchVibrateSetting*) param withBlock:(FitCloudResultHandler _Nullable)block;


#pragma mark 删除手表上存储的消息

/// 删除手表上存储的消息
/// - Parameters:
///   - deleteIndex: 删除索引 0～n-1，0代表最新的一条  当 shouldDeleteAll 为 false 时有效
///   - shouldDeleteAll: 是否应该删除所有
///   - block: 结果回调
+(void)deleteWatchMessageWithIndex:(NSInteger)deleteIndex shouldDeleteAll:(BOOL)shouldDeleteAll withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 取消手表当前消息显示

/// 取消手表当前消息显示
/// - Parameters:
///   - block: 结果回调
+(void)dismissCurrentWatchMessageWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 游戏锁设置

/// 游戏锁设置
/// - Parameters:
///   - setting: 游戏锁设置
///   - block: 结果回调
+(void)setGamePasscodeSetting:(FitCloudGamePasscodeSetting* _Nonnull)setting block:(FitCloudResultHandler _Nullable)block;

#pragma mark 通知手表查找手机响铃播放完毕

/// 通知手表查找手机响铃播放完毕
/// - Parameters:
///   - block: 结果回调
+(void) notifyAppFindiPhoneRingPlayEndWithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 发送支付宝Iot数据

/// 发送支付宝Iot数据
/// - Parameters:
///   - aliotData: 支付宝Iot数据
///   - block: 结果回调
+(void) sendAliotData:(NSData*)aliotData withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 发送网易云音乐桥接数据

/// 发送网易云音乐桥接数据
/// - Parameters:
///   - data: 网易云音乐桥接数据
+(void) sendNetEaseBridgeData:(NSData*)data;


#pragma mark 发送手表微信支付认证桥接数据

/// 发送手表微信支付认证桥接数据
/// - Parameters:
///   - data: 手表微信支付认证桥接数据
+(void) sendWPAuthBridgeData:(NSData*)data;

#pragma mark 发送创维光伏数据

/// 发送创维光伏数据
/// - Parameters:
///   - stations: 光伏电站数据，最多支持6个电站，超过的自动忽略
///   - block: 结果回调
+(void) sendSkyworthPVData:(NSArray<SkyworthPVPowerStationObject*>*)stations withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 发送即将到来的板球比赛数据

/// 发送即将到来的板球比赛数据
/// - Parameters:
///   - matches: 比赛数据，目前最多支持两个
///   - block: 结果回调
+(void) sendUpcomingCricketMatchData:(NSArray<FitCloudCricketUpcomingMatch*>*)matches withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 发送正在进行的板球比赛数据

/// 发送正在进行的板球比赛数据
/// - Parameters:
///   - matches: 比赛数据，目前最多支持两个
///   - block: 结果回调
+(void) sendLiveCricketMatchData:(NSArray<FitCloudCricketLiveMatch*>*)matches withBlock:(FitCloudResultHandler _Nullable)block;


#pragma mark 发送已经结束的板球比赛数据

/// 发送已经结束的板球比赛数据
/// - Parameters:
///   - matches: 比赛数据，目前最多支持两个
///   - block: 结果回调
+(void) sendEndedCricketMatchData:(NSArray<FitCloudCricketEndedMatch*>*)matches withBlock:(FitCloudResultHandler _Nullable)block;


#pragma mark 设置板球比分列表顺序

/// 设置板球比分列表顺序
/// - Parameters:
///   - match1order:  比赛1顺序
///   - match2order:  比赛2顺序
///   - block: 结果回调
+(void) sendCricketMatchScoreListOrderWith:(FitCloudCricketMatchScoreOrder*)match1order match2order:(FitCloudCricketMatchScoreOrder*)match2order withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 设置当前手机所在位置的GPS数据

/// 设置当前手机所在位置的GPS数据
/// - Parameters:
///   - gpsData: GPS数据
///   - block: 结果回调
+(void) sendGPSData:(FitCloudGPSData*)gpsData withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 获取手表上的GPS文件状态

/// 获取手表上的GPS文件状态
/// - Parameters:
///   - block: 结果回调
+(void) getWatchGPSFileStateWithBlock:(FitCloudWatchGPSFileStateResultBlock _Nullable)block;

#pragma mark 判断GPS文件是否过期

/// 判断GPS文件是否过期
/// - Parameters:
///   - filePath: GPS文件路径
///   - error: 错误信息
+(BOOL) gpsFileOutdated:(NSString*)filePath error:(NSError**) error;

#pragma mark 获取当前是否允许推送GPS文件

/// 获取当前是否允许推送GPS文件
/// - Parameters:
///   - block: 结果回调
+(void) getGPSFileCanPushWithBlock:(FitCloudGPSFileCanPushResultBlock _Nullable)block;

#pragma mark 准备GPS文件升级

/// 准备GPS文件升级
/// - Parameters:
///   - block: 结果回调
+(void) prepareGPSFileUpgradeWithCompletion:(FitCloudResultHandler _Nullable)block;


#pragma mark 导航信息同步

/// The navigation start callback
/// - Parameters:
///   - map: the navigation map
///   - naviType: navi type
///   - block: completion callback
+(void) onNaviStartWithMap:(FITCLOUDROUTEPLANMAPPROVIDER)map type:(FITCLOUDROUTEPLANNAVITYPE) naviType withBlock:(FitCloudResultHandler _Nullable)block;

/// The navigation guide kind callback
/// - Parameters:
///   - guideKind: the guide kind
///   - block: completion callback
+(void) onNaviGuideKind:(FITCLOUDROUTEPLANGUIDEKIND)guideKind withBlock:(FitCloudResultHandler _Nullable)block;

/// The navigation guide text callback
/// - Parameters:
///   - guideText: the guide text
///   - block: completion callback
+(void) onNaviGuideText:(NSString*)guideText withBlock:(FitCloudResultHandler _Nullable)block;

/// The remain time for navigation update callback
/// - Parameters:
///   - remainTime: the remain time in seconds
///   - block: completion callback
+(void) onNaviRemainTimeUpdate:(NSInteger)remainTime withBlock:(FitCloudResultHandler _Nullable)block;

/// The remain distance for navigation update callback
/// - Parameters:
///   - remainDistance: the remain distance in meters
///   - block: completion callback
+(void) onNaviRemainDistanceUpdate:(NSInteger)remainDistance withBlock:(FitCloudResultHandler _Nullable)block;

/// The navigation arrive destination callback
/// - Parameters:
///   - block: completion callback
+(void) onNaviArriveDestwithBlock:(FitCloudResultHandler _Nullable)block;

/// The naviagation exit callback
/// - Parameters:
///   - block: completion callback
+(void) onNaviExitwithBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark 电子卡包

/// Query the electronic cards from the smart watch
/// - Parameters:
///   - block: the electronic cards query result
+(void)getECardsWithBlock:(FitCloudECardsResultBlock _Nullable)block;

/// Set the electronic card
/// - Parameters:
///   - ecard: the electronic card
///   - block: the electronic card set response
+(void)setECard:(FitCloudECard*)ecard withBlock:(FitCloudResultHandler _Nullable)block;

/// sort the electronic cards
/// - Parameters:
///   - idArray: the electronic card id array
///   - block: the electronic cards sort response
+(void)sortECardsWithIdArray:(NSArray<NSNumber*>*) idArray withBlock:(FitCloudResultHandler _Nullable)block;

/// delete the electronic cards
/// - Parameters:
///   - idArray: the electronic card id array
///   - block: the electronic cards delete response
+(void)deleteECardsWithIdArray:(NSArray<NSNumber*>*) idArray withBlock:(FitCloudResultHandler _Nullable)block;

#pragma mark - 其他

/// 设置运动极限心率(Set maximum exercise heart rate)
/// - Parameters:
///   - value: 运动极限心率(maximum exercise heart rate)
///   - completion: the completion callback
+(void)setMaxExerciseHeartRate:(NSInteger)value withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 获取运动极限心率(Query maximum exercise heart rate)
/// - Parameters:
///   - completion: the completion callback
+(void)queryMaxExerciseHeartRateWithCompletion:(void(^_Nullable)(BOOL success, NSInteger maxExerciseHeartRate, NSError*_Nullable error))completion;

/// 查询手表上的静息心率数据
/// - Parameters:
///   - completion: 结果回调
+(void) queryRestingHRWithCompletion:(FitCloudRestingHRQueryCompletion _Nullable)completion;


#pragma mark - 耳机仓

/// 设置耳机仓歌词颜色(Set earbud case lyrics color)
/// - Parameters:
///   - lyricsColor: 歌词颜色(lyrics color)
///   - completion: the completion callback
+(void)setEarbudCaseLyricsColor:(UIColor*)lyricsColor withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 查询耳机仓歌词颜色(Query earbud case lyrics color)
/// - Parameters:
///   - completion: the completion callback
+(void)queryEarbudCaseLyricsColorWithCompletion:(void(^_Nullable)(BOOL success, UIColor*_Nullable lyricsColor, NSError*_Nullable error))completion;

/// 设置耳机仓充电壁纸是否常亮(Set earbud case charging wallpaper whether always bright)
/// - Parameters:
///   - alwaysBright: 是否常亮
///   - completion: the completion callback
+(void)setEarbudCaseChargingWallpaperAlwaysBright:(BOOL)alwaysBright withCompletion:(FitCloudResultHandler _Nullable)completion;

/// 查询耳机仓充电壁纸是否常亮(Query earbud case charging wallpaper whether always bright)
/// - Parameters:
///   - completion: the completion callback
+(void)queryEarbudCaseChargingWallpaperWhetherAlwaysBrightWithCompletion:(void(^_Nullable)(BOOL success, BOOL alwaysBright, NSError*_Nullable error))completion;

#pragma mark - 激光测量

/// 开始激光测量
/// - Parameters:
///   - durationInSeconds: 测量时长，单位：秒，时长范围1～255
///   - completion: the completion callback
///
/// >Important: the valid measurement duration is from 1s to 255s
+(void)startLaserMeasurementWithDuration:(NSInteger)durationInSeconds completion:(void (^__nullable)(BOOL succeed, NSError* error))completion;

/// 结束激光测量
/// - Parameters:
///   - completion: the completion callback
+(void)stopLaserMeasurementWithCompletion:(void (^__nullable)(BOOL succeed, NSError* error))completion;

/// 查询激光测量状态
/// - Parameters:
///   - completion: the completion callback
+(void)queryLaserMeasurementStatusWithCompletion:(void (^__nullable)(BOOL succeed, FITCLOUDWEARINGSTATUS wearingStatus, FITCLOUDLASERMEASUREMENTSTATUS measurementStatus, NSError* error))completion;

@end

/// FitCloudKit Bind Module
@interface FitCloudKit (Bind)

#pragma mark 是否已经绑定

/// 是否已经绑定
+(BOOL) alreadyBound;

#pragma mark 检查用户是否已经绑定

/// 检查用户是否已经绑定
/// - Parameters:
///   - userId: 用户Id
/// - Returns:
///  YES 已经绑定 NO 未绑定
+(BOOL) isUserAlreadyBound:(NSString*)userId;

#pragma mark 绑定用户

/// 绑定用户
/// - Parameters:
///   - userId: 用户Id
///   - randomCode: 随机码，如果没有，则填 nil，仅部分项目有该功能
///   - bAbort: 如果已经存在绑定用户是否终止，当为FALSE时，自动先解绑并绑定新的用户
///   - block: 结果回调
+(void)bindUserObject:(NSString*)userId randomCode:(NSString* _Nullable)randomCode abortIfExist:(BOOL)bAbort block:(FitCloudResultHandler _Nullable )block;

#pragma mark 最后绑定时间

/// 最后绑定时间
+(nullable NSDate*) lastBindDate;

#pragma mark 用户解绑

/// 用户解绑
/// - Parameters:
///   - shouldDisconnectIfSuccess: 解绑成功后是否需要自动断开连接
///   - block: 结果回调
+(void)unbindUserObject:(BOOL) shouldDisconnectIfSuccess block:(FitCloudResultHandler _Nullable )block;

@end

/// FitCloudKit Sports Module
@interface FitCloudKit (Sports)

#pragma mark 请求最新的健康测量数据

/// 请求最新的健康测量数据
/// - Parameters:
///   - block: 结果回调
+(void) requestLatestHealthMeasurementDataWithBlock:(FitCloudLatestHealthMeasurementDataResultBlock _Nullable )block;

#pragma mark 请求当天运动健康数据信息

/// 请求当天运动健康数据信息
/// - Parameters:
///   - block: 结果回调
+(void) requestHealthAndSportsDataTodayWithBlock:(FitCloudHealthAndSportsDataTodayResultBlock _Nullable )block;

#pragma mark 启动/停止实时健康测量（心率、血氧、血压、呼吸频率等）

/// 启动/停止实时健康测量（心率、血氧、血压、呼吸频率等）
/// - Parameters:
///   - rtmParam: 实时测量参数
///   - block: 调用结果回调
+(void) requestRealTimeHealthMeasuring:(FitCloudRealTimeHealthMeasuringParam*_Nonnull)rtmParam block:(FitCloudResultHandler _Nullable )block;

#pragma mark 手动同步历史运动健康数据

/// 手动同步历史运动健康数据
/// - Parameters:
///   - option: 选项，默认 `FITCLOUDDATASYNCOPTION_LEGACY`
///   - progress: 进度回调
///   - block: 结果回调
///   - finished: 结束回调，如果你希望在数据同步结束后执行一些其他指令，请在这里操作
+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;

#pragma mark 请求当天睡眠调试数据

/// 请求当天睡眠调试数据
/// - Parameters:
///   - block: 结果回调，代表请求是否成功，不代表数据返回成功
+(void)requestSleepDebugDataWithBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 启动/关闭手表GPS互联运动

/// 启动/关闭GPS互联运动
/// - Parameters:
///   - params: 参数
///   - block: 调用结果回调
+(void) requestRealTimeGPSConnectSports:(FitCloudSportsWithGPSActionParams*_Nonnull)params block:(FitCloudResultHandler _Nullable )block;

#pragma mark 通知手表GPS互联运动当前App端运动数据

/// 通知手表GPS互联运动当前App端运动数据
/// - Parameters:
///   - appClientData: 已运动信息
///   - block: 调用结果回调
+(void) notifyRealTimeGPSConnectSportsAppClientData:(FitCloudSportsWithGPSAppClientData*_Nonnull)appClientData block:(FitCloudResultHandler _Nullable )block;

#pragma mark 请求手表GPS互联运动当前状态

/// 请求手表GPS互联运动当前状态
/// - Parameters:
///   - block: 调用结果回调
+(void) requestRealTimeGPSConnectSportsCurrentStatusWithBlock:(FitCloudGPSConnectSportsCurrentStatusResultBlock _Nullable) block;


#pragma mark 开启GSensor

/// 开启GSensor
/// - Parameters:
///   - block: 结果回调
+(void)openGSensorWithBlock:(FitCloudOpenGSensorResultBlock _Nullable )block;

#pragma mark 关闭GSensor

///关闭GSensor
/// - Parameters:
///   - block: 结果回调
+(void)closeGSensorWithBlock:(FitCloudResultHandler _Nullable )block;

@end

/// FitCloudKit RemoteCtrl Module
@interface FitCloudKit (RemoteCtrl)

#pragma mark APP通知手表当前APP的相机状态（前台/后台）

/// APP通知手表当前APP的相机状态（前台/后台）
/// - Parameters:
///   - state: APP相机状态（前台/后台）
///   - block: 结果回调
+(void)notifyAppCameraState:(APPCAMERASTATE)state withBlock:(FitCloudResultHandler _Nullable )block;

#pragma mark 通知手表第三方外设启停操作结果

/// 通知手表第三方外设启停操作结果
/// - Parameters:
///   - result: 结果
///   - block: 结果回调
+(void)notifyThirdPartyPeripheralStartStopResult:(THIRDPARTYPERIPHERALACTIONRESULT)result withBlock:(FitCloudResultHandler)block;

#pragma mark 通知手表第三方外设数据

/// 通知手表第三方外设数据
/// - Parameters:
///   - peripheral: 外设
///   - value: 数据
///   - block: 结果回调
+(void)notifyThirdPartyPeripheral:(THIRDPARTYPERIPHERAL) peripheral value:(CGFloat)value withBlock:(FitCloudResultHandler)block;
@end

/// FitCloudKit Dump Module
@interface FitCloudKit (Dump)

#pragma mark 发送Alexa结果

/// 发送Alexa结果
/// - Parameters:
///   - text: 结果
///   - errorCode: 错误码
///   - block: 结果回调
+(void)sendAlexaResult:(NSString*)text with:(ALEXAINVOKEERROR)errorCode withBlock:(FitCloudResultHandler _Nullable )block;

@end

/// FitCloudKit DeviceLog Module
@interface FitCloudKit (DeviceLogs)

#pragma mark Request Device Debug Logs

/// Request Device Debug Logs
/// - Parameters:
///   - completion: the completion callback
+(void)requestDeviceDebugLogsDataWithCompletion:(void(^_Nullable)(BOOL success, NSData* _Nullable logsData, NSError* _Nullable error))completion;

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
+(void) sendLLMResult:(NSString*)text isEnd:(BOOL)isEnd resultType:(LLMRESULTTYPE)resultType completion:(FitCloudResultHandler _Nullable) completion;

@end

/// 拍照实时预览
@interface FitCloudKit (CameraLivePreview)

#pragma mark 发送相机实时预览图JPG图片数据

/// 发送拍照实时预览图JPG图片数据
/// - Parameters:
///   - data: 相机实时预览图JPG图片数据
+(void) sendCameraLivePreviewData:(NSData*)data;

@end

/// FitCloudKit Mockup
@interface FitCloudKit (Mockup)

#pragma mark 模拟接收到远程手表发来的指令

/// mockup remote command
/// - Parameters:
///   - hexData: 十六进制字符串，0x开头
+(void)mockupRemoteCommandWithData:(NSString*) hexData;

@end

/// 新OTA
@interface FitCloudKit (NewOTA)

#pragma mark 检查手表新OTA升级环境，比如是否有充足的电量等

/// 检查手表新OTA升级环境，比如是否有充足的电量等
/// - Parameters:
///   - completion: 结果回调
+(void)checkNewOTAEnvironmentWithCompletion:(FitCloudNewOTAEnvironmentCheckCompletion)completion;

#pragma mark 传输新OTA升级文件

/// 传输新OTA升级文件
/// 尽量在后台线程调用该方法
/// - Parameters:
///   - newOTAFilePath: 新OTA升级文件路径
///   - startConfirmResult: 升级启动结果回调，即启动OTA升级是否成功
///   - progress: 传输进度回调
///   - completion: 结果回调
+(void)sendNewOTA:(NSString*)newOTAFilePath startConfirmResult:(FitCloudNewOTAStartConfirmResultBlock _Nullable)startConfirmResult progress:(FitCloudNewOTAProgressBlock _Nullable)progress completion:(FitCloudNewOTACompletionBlock _Nullable)completion;

#pragma mark 取消传输新OTA升级文件

/// 取消传输新OTA升级文件
/// - Parameters:
///   - completion: 完成回调
+(void)cancelSendTheNewOTAIfNeededWithCompletion:(FitCloudNewOTACancelCompletionBlock _Nullable)completion;

@end

NS_ASSUME_NONNULL_END

