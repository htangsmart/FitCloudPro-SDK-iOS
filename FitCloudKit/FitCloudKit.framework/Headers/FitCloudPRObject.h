//
//  FitCloudPRObject.h
//  FitCloudKit
//
//  Created by pcjbird on 5/29/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 防护提醒设置（Protection Remind）
*/
@interface FitCloudPRObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 防护提醒间隔时间（分钟）
 */
@property(nonatomic, assign) UInt16 interval;

/**
 * @brief 防护提醒开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 begin;

/**
 * @brief 防护提醒结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 end;

@end

