//
//  FitCloudKit.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//
//  框架名称:FitCloudKit.framework
//  框架功能:iOS framework for FitCloud Smart Bracelet, which is responsible for the communication with bracelet. FitCloud智能手表的iOS框架，负责与智能手表设备通信等功能的封装。
//  修改记录:
//     pcjbird    2020-07-18  Version:1.2.0 Build:202007180001
//                            1.支持手表通知APP退出拍照模式
//                            2.新增女性健康功能
//                            3.新增防护提醒功能
//                            4.修正匈牙利语不能同步到手环的问题
//                            5.新增设置广播数据自定义字段 key1，华盛达专用
//                            6.修正设置用户资料时年龄不正确的问题
//                            7.新增获取当天睡眠调试数据
//                            8.修正年龄设置不正确的问题
//                            9.最新的健康测量数据新增体温数据(需要手表支持体温)
//                            10.新增新的表盘尺寸的相关注释说明
//                            11.支持设置SDK定义的所有本地化语言至手表
//
//     pcjbird    2020-05-15  Version:1.1.9 Build:202005150001
//                            1.支持体温测量，仅部分手表支持
//
//     pcjbird    2020-04-25  Version:1.1.8 Build:202004250001
//                            1.修正解绑有可能出现未断开连接的问题
//                            2.修正在自动登录过程中手表断开连接有可能导致提示手表被其他手机终端绑定或已经被解绑的问题
//                            3.修正当命令执行超时的情况下会丢掉下一条待执行的命令的问题
//                            4.修正同步数据量较大的健康数据时可能导致超时的问题
//                            5.解绑后清除电量信息
//                            6.支持常用联系人，仅部分手表支持
//                            7.手表运动模式新增椭圆机/瑜伽/乒乓球/跳绳等运动
//                            8.修正心电启动失败时逻辑处理不正确的问题
//                            9.修正连接手表超时不执行连接超时逻辑的问题
//
//     pcjbird    2020-02-25  Version:1.1.7 Build:202002250001
//                            1.新增斯洛伐克语/匈牙利语
//                            2.修正手表返回的睡眠数据睡眠质量可能为非法值的情况
//                            3.取消自动解绑逻辑,新增手表被其他手机终端绑定或已经被解绑通知 @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY
//                            4.所有回调以及通知均改成在 Gloal Queue 中调用，如果要在回调或者通知中更新UI，请务必切换到主队列(Main Queue)
//                            5.外部调用 disconnect 将不会自动回连
//                            6.新增 FITCLOUDUSERBINDSTATUS_KICKEDOUT 用户绑定状态
//                            7.新增 FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY 通知
//                            8.新增支持新的睡眠格式 @see newSleepDataFormat
//                            9.日志信息支持查看较大数据包的完整数据
//                            10.手表端主动更改了开关设置(例如：抬腕唤醒开关，通知开关等)会适时更新到App端 @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY
//                            11.表盘信息获取方法修改
//                            12.其他一些改进
//
//     pcjbird    2019-11-21  Version:1.1.6 Build:201911210001
//                            1.修正表盘UI信息接口无法正确响应的问题
//                            2.解绑用户后取消当前手表连接记录的自动重连
//                            3.优化手表连接初始化过程，防止意外重连
//                            4.调整手表硬件相关信息为只读
//                            5.绑定用户的UserId由整型修改成字符串型
//                            6.新增获取手表最后一次健康测量数据(心率/血氧/血压)，仅部分手表支持，@see allowRetrieveLatestMeasurementData
//                            7.修改进入和退出固件升级模式方法，现在您在首次固件升级之前以及所有固件升级操作完成之后分别手动调用进入固件升级模式和退出固件升级模式，同时适用于普通固件升级与表盘推送
//                            8.新增DFU模式回连成功通知，这通常用于等待表盘推送/普通固件升级之后手表重启的场景
//                            9.提升SDK稳定性
//
//     pcjbird    2019-11-13  Version:1.1.5 Build:201911130001
//                            1.新增勿扰模式(仅部分手表支持 @see allowDNDMode)
//
//     pcjbird    2019-10-24  Version:1.1.4 Build:201910240001
//                            1.实时测量moment修改精确到秒
//                            2.修正同步数据moment使得不会超过当前同步时间
//
//     pcjbird    2019-10-16  Version:1.1.3 Build:201910160001
//                            1.计步数据引入距离&卡路里新算法
//                            2.新增获取用户最后绑定时间
//                            3.新增心率报警/血压报警设置
//                            4.新增Snapchat消息提醒选项
//                            5.设备扫描取消设备名称过滤
//                            6.心电实时测量新增手表主动结束逻辑
//                            7.新增获取表盘UI信息接口
//                            8.新增获取手表广播数据缓存
//                            9.新增蓝牙名称变更通知，新增蓝牙RSSI变更通知
//                            10.提升SDK稳定性
//                            11.避免歧义，+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals 修改为  +(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals
//
//     pcjbird    2019-08-19  Version:1.1.2 Build:201908190002
//                            1.修正蓝牙连接开始的通知时刻问题
//
//     pcjbird    2019-08-19  Version:1.1.1 Build:201908190001
//                            1.修正手表解绑没有清除上一次绑定手表的Mac地址的问题
//                            2.新增绑定/登录成功后需要完成一些基础准备同步操作的开始与结束通知
//                            3.修正SDK初始化选项shouldAutoConnect不起作用的问题
//
//     pcjbird    2019-08-12  Version:1.1.0 Build:201908120001
//                            1.支持后台蓝牙数据同步功能
//
//     pcjbird    2019-07-21  Version:1.0.9 Build:201907210001
//                            1.支持获取当前SDK版本信息
//
//     pcjbird    2019-07-20  Version:1.0.8 Build:201907200001
//                            1.修正iPhone日历设置成佛教日历或者日本日历的时候导致手表同步时间失败的问题
//                            2.优化手表回连机制
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
//                            1.增加手表支持的语种
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
 * @brief FitCloud健康手表iOS框架
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
 * @param callback 回调类，主要用于接受处理手表的请求命令或事件
 */
+(instancetype _Nonnull)initWithOption:(FitCloudOption* _Nullable)option callback:(id<FitCloudCallback> _Nullable)callback;

/**
 * @brief 扫描手表设备
 */
+(void)scanPeripherals;

/**
 * @brief 停止扫描手表设备
 */
+(void)stopScan;

/**
 * @brief 连接手表设备
 * @param peripheral 手表设备
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

#pragma mark 扫描到的外设(手表)列表
/**
 * @brief 扫描到的外设(手表)列表
 */
+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals;

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

#pragma mark 手表Mac地址
/**
 * @brief 手表Mac地址
 */
+(NSString*_Nullable) macAddr;

#pragma mark 手表当前所有配置信息
/**
 * @brief 手表当前所有配置信息
 */
+(FitCloudAllConfigObject*_Nullable) allConfig;


#pragma mark 手表当前电量信息
/**
 * @brief 手表当前电量信息
 */
+(FitCloudBatteryInfoObject*_Nullable) batteryInfo;

#pragma mark 手表闹钟列表
/**
 * @brief 手表闹钟列表
 */
+(NSArray<FitCloudAlarmObject*>*_Nullable) alarmlist;

#pragma mark 手表常用联系人列表
/**
 * @brief 手表常用联系人列表
 */
+(NSArray<FitCloudContactObject*>*_Nullable) favoriteContacts;

#pragma mark 最后连接的手表信息
/**
 * @brief 最后连接的手表信息
 */
+(FitCloudKitConnectRecord*_Nullable) lastConnectPeripheral;

#pragma mark 手表连接历史
/**
 * @brief 手表连接历史
 */
+(NSArray<FitCloudKitConnectRecord*>*_Nonnull) historyPeripherals;

#pragma mark 删除手表连接历史
/**
 * @brief 删除手表连接历史
 */
+(void)removePeripheralHistoryWithUUID:(NSString*_Nonnull) uuid;

#pragma mark 清除手表连接历史
/**
 * @brief 清除手表连接历史
 */
+(void)clearPeripheralHistory;

@end

/**
 * @brief FitCloud Upgrade Module
 */
@interface FitCloudKit (Upgrade)

#pragma mark 当前是否为DFU模式
/**
 * @brief 当前是否为DFU模式
 * @return 是否为DFU模式
*/
+(BOOL)  isCurrentDFUMode;

#pragma mark dfu外设
/**
 * @brief dfu外设，仅仅当处于dfu模式，且处于连接状态时有效
 * @return dfu外设
*/
+(CBPeripheral*)  dfuPeripheral;

#pragma mark 芯片提供商
/**
 * @brief 当前芯片提供商
 * @return 当前芯片提供商
*/
+(FITCLOUDCHIPVENDOR)  chipVendor;

#pragma mark 准备进入固件升级模式
/**
 * @brief 准备进入固件升级模式
 * @param block 结果回调
 */
+(void)enterDFUModeWithBlock:(FitCloudEnterDFUModeResultBlock _Nullable )block;

#pragma mark 退出固件升级模式
/**
 * @brief 退出固件升级模式
 * @param block 结果回调
 */
+(void)exitDFUModeWithBlock:(FitCloudExitDFUModeResultBlock _Nullable )block;

@end

/**
 * @brief FitCloud Setting Module
 */
@interface FitCloudKit (Setting)

#pragma mark 同步系统时间
/**
 * @brief 同步系统时间（将手表的时间同步成跟手机的系统时间一致）
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
 * @brief 设置闹钟（将手机上的闹钟列表同步到手表）
 * @param alarms 闹钟列表
 * @param block 结果回调
 */
+(void)setAlarms:(NSArray<FitCloudAlarmObject*>*_Nullable)alarms block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取闹钟列表
/**
 * @brief 获取闹钟列表（获取手表上的闹钟列表）
 * @param block 结果回调
 */
+(void)getAlarmsWithBlock:(FitCloudAlarmsResultBlock _Nullable )block;

#pragma mark 设置常用联系人
/**
* @brief 设置常用联系人（将手机上的常用联系人列表同步到手表）
* @param contacts 常用联系人列表
* @param block 结果回调
*/
+(void) setFavContacts:(NSArray<FitCloudContactObject*>*_Nullable)contacts block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取常用联系人
/**
* @brief 获取常用联系人列表（获取手表上的常用联系人列表）
* @param block 结果回调
*/
+(void) getFavContactsWithBlock:(FitCloudFavContactsResultBlock _Nullable)block;

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

#pragma mark 获取手表软硬件版本信息
/**
 * @brief 获取手表软硬件版本信息
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

#pragma mark 设置手表表盘所有功能项显示状态
/**
 * @brief 设置手表表盘所有功能项显示状态
 * @param display 手表表盘所有功能项显示状态信息
 * @param block 结果回调
 */
+(void)setScreenDisplay:(FITCLOUDSCREENDISPLAY)display block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手表表盘所有功能项显示状态
/**
 * @brief 获取手表表盘所有功能项显示状态
 * @param block 结果回调
 */
+(void)getScreenDisplaySettingWithBlock:(FitCloudSDSettingResultBlock _Nullable )block;

#pragma mark 设置手表偏好
/**
 * @brief 设置手表偏好
 * @param prefer 手表偏好
 * @param block 结果回调
 */
+(void)setFitCloudPrefer:(FITCLOUDPREFER)prefer block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手表偏好设置
/**
 * @brief 获取手表偏好设置
 * @param block 结果回调
 */
+(void)getFitCloudPreferWithBlock:(FitCloudPreferResultBlock _Nullable )block;

#pragma mark 获取手表电量以及充电状态信息
/**
 * @brief 获取手表电量以及充电状态信息
 * @param block 结果回调
 */
+(void)getBatteryInfoWithBlock:(FitCloudBatteryInfoResultBlock _Nullable )block;

#pragma mark 如果空闲则请求更新手表电量信息
/**
 * @brief 如果空闲则请求更新手表电量信息
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


#pragma mark 防护提醒设置
/**
 * @brief 防护提醒设置
 * @param prSetting 防护提醒设置
 * @param block 结果回调
 */
+(void)setProtectionRemind:(FitCloudPRObject*_Nonnull)prSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取防护提醒设置
/**
 * @brief 获取防护提醒设置
 * @param block 结果回调
 */
+(void)getProtectionRemindSettingWithBlock:(FitCloudProtectionRemindResultBlock _Nullable )block;

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

#pragma mark 心率报警设置
/**
 * @brief 心率报警设置
 * @param hrAlarmSetting 心率报警设置
 * @param block 结果回调
 */
+(void)setHRAlarm:(FitCloudHRAlarmObject* _Nonnull)hrAlarmSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取心率报警设置
/**
 * @brief 获取心率报警设置
 * @param block 结果回调
 */
+(void)getHRAlarmSettingWithBlock:(FitCloudHRAlarmResultBlock _Nullable)block;

#pragma mark 血压报警设置
/**
 * @brief 血压报警设置
 * @param bpAlarmSetting 血压报警设置
 * @param block 结果回调
 */
+(void)setBPAlarm:(FitCloudBPAlarmObject* _Nonnull)bpAlarmSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取血压报警设置
/**
 * @brief 获取血压报警设置
 * @param block 结果回调
 */
+(void)getBPAlarmSettingWithBlock:(FitCloudBPAlarmResultBlock _Nullable)block;

#pragma mark 勿扰模式设置
/**
 * @brief 勿扰模式设置
 * @param dndSetting 勿扰模式设置
 * @param block 结果回调
 */
+(void)setDND:(FitCloudDNDSetting* _Nonnull)dndSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取勿扰模式设置
/**
 * @brief 获取勿扰模式设置
 * @param block 结果回调
 */
+(void)getDNDSettingWithBlock:(FitCloudDNDSettingResultBlock _Nullable)block;

#pragma mark 获取手表UI信息
/**
 * @brief 获取手表UI信息
 * @param block 结果回调
*/
+(void)getWatchUIInformationWithBlock:(FitCloudWatchUIInfoResultBlock _Nullable)block;


#pragma mark 获取表盘UI信息
/**
 * @brief 获取表盘UI信息
 * @param block 结果回调
*/
+(void)getWatchfaceUIInformationWithBlock:(FitCloudWatchfaceUIInfoResultBlock _Nullable)block;


#pragma mark 女性健康设置
/**
 * @brief 女性健康设置
 * @param whSetting 女性健康设置信息
 * @param block 结果回调
 */
+(void)setWomenHealthConfig:(FitCloudWomenHealthSetting*_Nonnull)whSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取女性健康设置
/**
 * @brief 获取女性健康设置
 * @param block 结果回调
 */
+(void)getWomenHealthSettingWithBlock:(FitCloudWomenHealthSettingResultBlock _Nullable )block;


#pragma mark APP主动点击退出睡眠
/**
 * @brief APP主动点击退出睡眠
 * @param block 结果回调
 */
+(void)exitSleepWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 同步系统语言
/**
* @brief 同步系统语言（将手表的时间同步成跟手机的系统语言一致）
* @param block 同步结果回调
*/
+(void)syncSystemLanguageWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 查找手表 (查找成功则手表会震动或发出提醒声)
/**
 * @brief 查找手表 (查找成功则手表会震动或发出提醒声)
 * @param block 结果回调
 */
+(void)findBraceletWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 一键恢复出厂设置
/**
 * @brief 一键恢复出厂设置
 * @param block 结果回调
 */
+(void)restoreAsFactorySettingsWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 手表关机
/**
 * @brief 手表关机
 * @param block 结果回调
 */
+(void)turnOffWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 重启手表
/**
 * @brief 重启手表
 * @param block 结果回调
 */
+(void)rebootWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 设置广播数据自定义字段 key1
/**
 * @brief 设置广播数据自定义字段 key1
 * @param keyData 自定义字段的key，注意keyData必须为6个字节，且需要自己管理字节序，SDK会将设置的值直接发送给手表
 * @param block 结果回调
 */
+(void)setCustomBroadcastKey:(NSData*) keyData withBlock:(FitCloudResultBlock _Nullable )block;
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
+(BOOL) isUserAlreadyBound:(NSString*)userId;

#pragma mark 绑定用户
/**
 * @brief 绑定用户
 * @param userId 用户Id
 * @param bAbort 如果已经存在绑定用户是否终止，当为FALSE时，自动先解绑并绑定新的用户
 * @param block 结果回调
 */
+(void)bindUserObject:(NSString*)userId abortIfExist:(BOOL)bAbort block:(FitCloudResultBlock _Nullable )block;

#pragma mark 最后绑定时间
/**
 * @brief 最后绑定时间
 * @return 绑定时间
 */
+(nullable NSDate*) lastBindDate;

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

#pragma mark 请求最新的健康测量数据
/**
 * @brief 请求最新的健康测量数据
 * @param block 结果回调
 */
+(void) requestLatestHealthMeasurementDataWithBlock:(FitCloudLatestHealthMeasurementDataResultBlock _Nullable )block;

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

#pragma mark 请求当天睡眠调试数据
/**
 * @brief 请求当天睡眠调试数据
 * @param block 结果回调，代表请求是否成功，不代表数据返回成功
*/
+(void)requestSleepDebugDataWithBlock:(FitCloudResultBlock _Nullable )block;

@end

/**
 * @brief FitCloudKit RemoteCtrl Module
 */
@interface FitCloudKit (RemoteCtrl)

#pragma mark APP通知手表当前APP的相机状态（前台/后台）
/**
 * @brief APP通知手表当前APP的相机状态（前台/后台）
 * @param state APP相机状态（前台/后台）
 * @param block 结果回调
 */
+(void)notifyAppCameraState:(APPCAMERASTATE)state withBlock:(FitCloudResultBlock _Nullable )block;
@end


NS_ASSUME_NONNULL_END
