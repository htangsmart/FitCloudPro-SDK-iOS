//
//  FitCloudKitConnectRecord.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/8/2.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// FitCloudKit 手表连接配对记录
@interface FitCloudKitConnectRecord : NSObject<NSCoding>

/// The name of the watch
@property(nonatomic, strong) NSString* name;

/// 是否为下一代厂商名称
@property(nonatomic, assign) BOOL isNextManufacturerName;

/// 是否允许同时连接通话蓝牙
@property(nonatomic, assign) BOOL allowConnectWithBT;

/// UUID
@property(nonatomic, strong, nullable) NSUUID* uuid;

/// Mac addr，如果厂商自定义了广播数据，这里返回nil
@property(nonatomic, strong, nullable) NSString* macAddr;

/// 最后连接时间
@property(nonatomic, strong) NSDate* lastConnectTime;

/// 是否应该自动回连
@property(nonatomic, assign) BOOL      shouldAutoReconnect;

/// 绑定的用户Id
@property(nonatomic, strong, nullable) NSString* bindUserId;

/// 用户绑定时间
@property(nonatomic, strong, nullable) NSDate*   userBindTime;

/// 是否已经解绑
@property(nonatomic, assign) BOOL      isAlreadyUnbind;

/// 项目号
@property(nonatomic, strong, nullable) NSString* formatedProjNo;

/// 固件版本号
@property(nonatomic, strong, nullable) NSString* formatedFirmwareVersion;

/// UI版本
@property(nonatomic, strong, nullable) NSString* uiVersion;

/// 屏幕分辨率
@property(nonatomic, strong, nullable) NSValue* screenResolution;

/// 屏幕形状，0：方形  1: 圆形  nil:未知
@property(nonatomic, strong, nullable) NSNumber* screenShape;

/// 广播数据厂商数据
@property(nonatomic, strong, nullable) NSString* advDataManufacturerData;

/// 广播数据
@property(nonatomic, strong, nullable) NSString* advData;

@end

NS_ASSUME_NONNULL_END
