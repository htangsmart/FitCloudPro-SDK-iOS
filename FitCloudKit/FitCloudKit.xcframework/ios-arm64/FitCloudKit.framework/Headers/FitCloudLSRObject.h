//
//  FitCloudLSRObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 久坐提醒设置（Long Sit Remind）
 */
@interface FitCloudLSRObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 是否午休免打扰
 */
@property(nonatomic, assign) BOOL offWhenLunchBreak;

/**
 * @brief 久坐提醒开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 begin;

/**
 * @brief 久坐提醒结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 end;

/**
 * @brief 提醒间隔，单位：分钟，该字段仅当标志位 allowSetLSRInterval 为 YES时有效
 * @see allowSetLSRInterval @ FitCloudFirmwareVersionObject
*/
@property(nonatomic, assign) UInt16 interval;

@end
