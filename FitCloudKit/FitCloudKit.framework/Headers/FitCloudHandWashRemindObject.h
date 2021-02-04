//
//  FitCloudHandWashRemindObject.h
//  FitCloudKit
//
//  Created by pcjbird on 11/19/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 洗手提醒设置（Hand Wash Remind）
*/
@interface FitCloudHandWashRemindObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 洗手提醒间隔时间（分钟）
 */
@property(nonatomic, assign) UInt16 interval;

/**
 * @brief 洗手提醒开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 begin;

/**
 * @brief 洗手提醒结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 end;

@end

