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

/**
 * @brief CentralManager状态改变通知 object=>CBCentralManager
 */
extern NSString *const FITCLOUDEVENT_CENTRALMANAGER_DIDUPDATESTATE_NOTIFY;

/**
 * @brief 发现新的外设(手环)通知 object=>FitCloudPeripheral
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY;

/**
 * @brief 发现的外设(手环)更新通知 object=>FitCloudPeripheral
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY;

/**
 * @brief 外设(手环)扫描停止通知
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY;

/**
 * @brief 外设(手环)开始连接通知 object=>CBPeripheral
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECTING_NOTIFY;

/**
 * @brief 外设(手环)连接成功通知 object=>CBPeripheral
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY;

/**
 * @brief 外设(手环)连接失败通知 object=>CBPeripheral userInfo=>@{@"error" : error}
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY;

/**
 * @brief 外设(手环)断开链接通知 object=>CBPeripheral userInfo=>@{@"error" : error}
 */
extern NSString *const FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY;

/**
 * @brief 开始绑定用户通知 object => @(UserId)
 */
extern NSString *const FITCLOUDEVENT_BINDUSEROBJECT_BEGIN_NOTIFY;

/**
 * @brief 绑定用户结果通知 object => @(UserId) userInfo=>{@"result":@(YES/NO), @"error" : error}
 */
extern NSString *const FITCLOUDEVENT_BINDUSEROBJECT_RESULT_NOTIFY;

/**
 * @brief 开始解绑用户通知 object => @(UserId)
 */
extern NSString *const FITCLOUDEVENT_UNBINDUSEROBJECT_BEGIN_NOTIFY;

/**
 * @brief 解绑用户结果通知 object => @(UserId) userInfo=>{@"result":@(YES/NO), @"error" : error}
 */
extern NSString *const FITCLOUDEVENT_UNBINDUSEROBJECT_RESULT_NOTIFY;

/**
 * @brief 开始登录用户对象通知 object => @(UserId)
 */
extern NSString *const FITCLOUDEVENT_LOGINUSEROBJECT_BEGIN_NOTIFY;

/**
 * @brief 用户对象登录结果通知 object => @(UserId) userInfo=>{@"result":@(YES/NO), @"error" : error}
 */
extern NSString *const FITCLOUDEVENT_LOGINUSEROBJECT_RESULT_NOTIFY;

/**
 * @brief 开始获取手环所有配置通知
 */
extern NSString *const FITCLOUDEVENT_GETALLCONFIG_BEGIN_NOTIFY;

/**
 * @brief 获取手环所有配置结果通知 userInfo=>{@"result":@(YES/NO), @"error" : error}
 */
extern NSString *const FITCLOUDEVENT_GETALLCONFIG_RESULT_NOTIFY;

/**
 * @brief 绑定<登录>初始化(绑定<登录>/获取所有手环配置 必要流程)结果通知 userInfo=>{@"result":@(YES/NO), @"error" : error}
 */
extern NSString *const FITCLOUDEVENT_INITIALIZE_RESULT_NOTIFY;

/**
 * @brief 手环电量信息通知 userInfo=>FitCloudBatteryInfoObject
 */
extern NSString *const FTICLOUDEVENT_BATTERYINFO_NOTIFY;

/**
 * @brief 闹钟列表变化通知 userInfo=>NSArray<FitCloudAlarmObject *>
 */
extern NSString *const FITCLOUDEVENT_ALARMLIST_CHANGED_NOTIFY;

/**
 * @brief 心电检测启动成功通知  object => 采样间隔(单位毫秒) NSNumber*
 */
extern NSString *const FITCLOUDEVENT_ECG_START_SUCCEED_NOTIFY;

/**
 * @brief 心电检测启动失败通知
 */
extern NSString *const FITCLOUDEVENT_ECG_START_FAILURE_NOTIFY;

/**
 * @brief 心电检测结束通知
 */
extern NSString *const FITCLOUDEVENT_ECG_STOP_NOTIFY;

#endif /* FitCloudEvent_h */
