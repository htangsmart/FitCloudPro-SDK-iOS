//
//  FitCloudPeripheral.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/7/31.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// FitCloud 外部设备 (通常指智能手表)
@interface FitCloudPeripheral : NSObject

/// CBCentralManager
@property(nonatomic, weak)CBCentralManager *central;

/// CBPeripheral
@property(nonatomic, strong)CBPeripheral *peripheral;

/// advertisementData
@property(nonatomic, strong, nullable)NSDictionary *advertisementData;

/// RSSI
@property(nonatomic, strong, nullable)NSNumber *RSSI;

/// mac地址，如果厂商自定义了广播数据，这里返回nil
@property(nonatomic, strong, readonly, nullable) NSString* macAddr;

/// 是否为下一代厂商名称
@property(nonatomic, readonly) BOOL isNextManufacturerName;

/// 是否允许同时连接通话蓝牙
@property(nonatomic, readonly) BOOL allowConnectWithBT;

/// 厂商是否自定义了广播数据
@property(nonatomic, readonly) BOOL isCustomizedAdvData;

/// 是否已经跟系统配对
@property(nonatomic, assign) BOOL  paired;

/// 主项目号
@property(nonatomic, strong, nullable) NSString* mainProjNo;

/// 子项目号
@property(nonatomic, strong, nullable) NSString* subProjNo;

@end

NS_ASSUME_NONNULL_END
