//
//  FitCloudPeripheral.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/7/31.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

/**
 * @brief FitCloud 外部设备 (通常指手环)
 */
@interface FitCloudPeripheral : NSObject

/**
 * @brief CBCentralManager
 */
@property(nonatomic, weak)CBCentralManager *central;

/**
 * @brief CBPeripheral
 */
@property(nonatomic, strong)CBPeripheral *peripheral;

/**
 * @brief advertisementData
 */
@property(nonatomic, strong)NSDictionary *advertisementData;

/**
 * @brief RSSI
 */
@property(nonatomic, strong)NSNumber *RSSI;

/**
 * @brief mac地址，如果厂商自定义了广播数据，这里返回nil
 */
@property(nonatomic, strong, readonly) NSString* macAddr;

/**
 * @brief 是否为下一代厂商名称
 */
@property(nonatomic, readonly) BOOL nextManufacturerName;

/**
 * @brief 是否允许同时连接通话蓝牙
 */
@property(nonatomic, readonly) BOOL allowConnectWithBT;

/// 厂商是否自定义了广播数据
@property(nonatomic, readonly) BOOL isCustomizedAdvData;


/**
 * @brief 是否已经跟系统配对
 */
@property(nonatomic, assign) BOOL  paired;

@end
