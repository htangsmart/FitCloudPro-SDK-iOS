//
//  FitCloudWWUObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 抬腕唤醒设置（Wrist Wake Up）
 */
@interface FitCloudWWUObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 begin;

/**
 * @brief 结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 end;

@end
