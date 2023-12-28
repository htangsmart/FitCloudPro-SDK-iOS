//
//  FitCloudBatteryInfoObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 手环充电状态
 */
typedef NS_ENUM(Byte, BATTERYSTATE)
{
    BATTERYSTATE_NORMAL = 0,         //未充电
    BATTERYSTATE_CHARGING = 1,       //充电中
};

/**
 * @brief 手环电量以及充电状态信息
 */
@interface FitCloudBatteryInfoObject : NSObject

/**
 * @brief 手环充电状态
 */
@property(nonatomic, assign) BATTERYSTATE state;

/**
 * @brief 电量格数
 */
@property(nonatomic, assign) UInt8 value;

/**
 * @brief 电量百分比  范围：0～100
 */
@property(nonatomic, assign) UInt8 percent;
@end
