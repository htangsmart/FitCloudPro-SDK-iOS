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

#pragma mark - FitCloud 事件定义

/// CentralManager状态改变通知 
///
/// object=>CBCentralManager
extern NSString *const FITCLOUDEVENT_CENTRALMANAGER_DIDUPDATESTATE_NOTIFY;

/// 发现新的外设(手表)通知 
///
/// object=>FitCloudPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY;

/// 发现的外设(手表)更新通知 
///
/// object=>FitCloudPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY;

/// 外设(手表)扫描停止通知
extern NSString *const FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY;

/// 外设(手表)开始连接通知 
///
/// object=>CBPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECTING_NOTIFY;

/// 外设(手表)连接成功通知 
///
/// object=>CBPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY;

/// 外设(手表)DFU模式回连成功通知 
///
/// object=>CBPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_RECONNECTEDWITHDFUMODE_NOTIFY;

/// 外设(手表)连接失败通知 
///
/// object=>CBPeripheral userInfo=>@{@"error" : error}
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY;

/// 外设(手表)断开连接通知 
///
/// object=>CBPeripheral userInfo=>@{@"error" : error}
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY;

/// 外设(手表)更新名称通知 
///
/// object=>CBPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DIDUPDATENAME_NOTIFIY;

/// 外设(手表)更新RSSI通知 
///
/// object=>CBPeripheral userInfo=>@{@"RSSI":rssi, @"error" : error}
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DIDUPDATERSSI_NOTIFIY;

/// 外设(手表)写特征准备就绪通知 
///
/// object=>CBPeripheral
extern NSString *const FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY;

/// 开始绑定用户通知 
///
/// object => @(UserId)
extern NSString *const FITCLOUDEVENT_BINDUSEROBJECT_BEGIN_NOTIFY;

/// 绑定用户结果通知 
///
/// object => @(UserId) 
/// userInfo=>{@"result":@(YES/NO), @"error" : error, @"audioBluetooth": bluetoothName}
extern NSString *const FITCLOUDEVENT_BINDUSEROBJECT_RESULT_NOTIFY;

/// 开始解绑用户通知 
///
/// object => @(UserId)
extern NSString *const FITCLOUDEVENT_UNBINDUSEROBJECT_BEGIN_NOTIFY;

/// 解绑用户结果通知 
///
/// object => @(UserId) 
/// userInfo=>{@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_UNBINDUSEROBJECT_RESULT_NOTIFY;

/// 开始登录用户对象通知 
///
/// object => @(UserId)
extern NSString *const FITCLOUDEVENT_LOGINUSEROBJECT_BEGIN_NOTIFY;

/// 用户对象登录结果通知 
///
/// object => @(UserId) 
/// userInfo=>{@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_LOGINUSEROBJECT_RESULT_NOTIFY;

/// 手表被其他手机绑定或者已被解绑通知(maybe bound by different userid)
extern NSString *const FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY;

/// 开始获取手表所有配置通知
extern NSString *const FITCLOUDEVENT_GETALLCONFIG_BEGIN_NOTIFY;

/// 获取手表所有配置结果通知 
///
/// userInfo=>{@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_GETALLCONFIG_RESULT_NOTIFY;

/// 绑定<登录>初始化(绑定<登录>/获取所有手表配置 必要流程)结果通知 
///
/// userInfo=>{@"result":@(YES/NO), @"error" : error}
extern NSString *const FITCLOUDEVENT_INITIALIZE_RESULT_NOTIFY;

/// 绑定<登录>初始化成功后手表开始完成一些准备同步操作开始通知
extern NSString *const FITCLOUDEVENT_PREPARESYNCWORK_BEGIN_NOTIFY;

/// 绑定<登录>初始化成功后手表开始完成一些准备同步操作结束通知
extern NSString *const FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY;

/// 手表电量信息通知 
///
/// object=>FitCloudBatteryInfoObject
extern NSString *const FITCLOUDEVENT_BATTERYINFO_NOTIFY;

/// 闹钟列表变化通知 
///
/// userInfo=>NSArray<FitCloudAlarmObject *>
extern NSString *const FITCLOUDEVENT_ALARMLIST_CHANGED_NOTIFY;

/// 日程列表变化通知 
///
/// userInfo=>NSArray<FitCloudScheduleObject *>
extern NSString *const FITCLOUDEVENT_SCHEDULELIST_CHANGED_NOTIFY;

/// 常用联系人列表变化通知 
///
/// userInfo=>NSArray<FitCloudContactObject *>
extern NSString *const FITCLOUDEVENT_FAVCONTACTS_CHANGED_NOTIFY;

/// 习惯养成列表变化通知 
///
/// userInfo=>NSArray<FitCloudHabitObject *>
extern NSString *const FITCLOUDEVENT_HABITS_CHANGED_NOTIFY;

/// 心电检测启动成功通知  
///
/// object => 采样间隔(单位毫秒) NSNumber*
extern NSString *const FITCLOUDEVENT_ECG_START_SUCCEED_NOTIFY;

/// 心电检测启动失败通知
extern NSString *const FITCLOUDEVENT_ECG_START_FAILURE_NOTIFY;

/// 心电检测结束通知
extern NSString *const FITCLOUDEVENT_ECG_STOP_NOTIFY;

/// 手表端人为更改配置（例如：抬腕唤醒开关，通知开关等）通知
extern NSString *const FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY;

/// 手表上的配对信息丢失或与iOS系统上的配对信息不匹配通知，建议用户进入系统设置解除与该手表的配对信息，杀死App进程并重新启动App。
///
/// 该通知可能连续发送，应用层需要避免重复提示用户，给用户造成困扰
extern NSString *const FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY;

/// 勋章列表变化通知 
///
/// userInfo=>NSArray<FitCloudMedal *>
extern NSString *const FITCLOUDEVENT_MEDALLIST_CHANGED_NOTIFY;

/// 手表端运动结束通知
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WORKOUT_END_NOTIFY;

/// 手表端运动已暂停通知
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WORKOUT_PAUSED_NOTIFY;

/// 手表端运动已开始或已恢复通知
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WORKOUT_STARTED_OR_RESUMED_NOTIFY;

/// 手表表盘切换通知
extern NSString *const FITCLOUDEVENT_WATCHFACE_TOGGLED_NOTIFY;

/// 手表心率测量结果通知
///
/// userInfo=>{@"timestamp":timestamp, @"hrValue" : @(hrValue)}
/// - timestamp 类型 NSDate
/// - hrValue 类型 NSInteger
extern NSString *const FITCLOUDEVENT_WATCHSIDE_HEARTRATE_MEASURE_RESULT_NOTIFY;

/// 手表端主动通知停止查找手表
extern NSString *const FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY;

/// 手表端提前结束由APP端启动的测量(实时测量)
extern NSString *const FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY;

/// 手表表盘删除通知
///
/// userInfo=>{@"watchfaceNo":@(watchfaceNo), @"slotIndex" : @(slotIndex)}
/// - watchfaceNo 类型 NSInteger
/// - slotIndex 类型 NSInteger, from 0~7
extern NSString *const FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY;

#endif /* FitCloudEvent_h */
