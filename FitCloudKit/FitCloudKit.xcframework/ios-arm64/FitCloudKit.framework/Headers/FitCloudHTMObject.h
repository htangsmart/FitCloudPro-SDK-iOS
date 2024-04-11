//
//  FitCloudHTMObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 健康定时监测设置（Health Timing Monitoring）
 */
@interface FitCloudHTMObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 监测开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 begin;

/**
 * @brief 监测结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 end;

/**
 * @brief 监测间隔，单位：分钟，该字段仅当标志位 allowSetHealthMonitorInterval 为 YES时有效
 * @see allowSetHealthMonitorInterval @ FitCloudFirmwareVersionObject
*/
@property(nonatomic, assign) UInt16 interval;

@end
