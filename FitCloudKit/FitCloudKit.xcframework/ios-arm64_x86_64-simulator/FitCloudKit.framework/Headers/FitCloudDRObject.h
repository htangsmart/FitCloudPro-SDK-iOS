//
//  FitCloudDRObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 喝水提醒设置（Drink Remind）
 */
@interface FitCloudDRObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 喝水提醒间隔时间（分钟）
 */
@property(nonatomic, assign) UInt16 interval;

/**
 * @brief 喝水提醒开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 begin;

/**
 * @brief 喝水提醒结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 end;


@end
