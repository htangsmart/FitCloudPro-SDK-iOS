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
@property(nonatomic, strong) NSDate* latestConnectTime;

/// 是否应该自动连接
@property(nonatomic, assign) BOOL      shouldAutoConnect;

/// 绑定的用户Id
@property(nonatomic, strong, nullable) NSString* bindUserId;

/// 用户绑定时间
@property(nonatomic, strong, nullable) NSDate*   userBindTime;


@end

NS_ASSUME_NONNULL_END
