//
//  FitCloudBPAlarmObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2019/9/13.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 血压报警设置（BP Alarm）
 */
@interface FitCloudBPAlarmObject : NSObject<NSCoding>

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 *@brief 舒张压上限报警值
 */
@property(nonatomic, assign) UInt8 diastolicUpperAlarmValue;

/**
 *@brief 舒张压下限报警值
 */
@property(nonatomic, assign) UInt8 diastolicLowerAlarmValue;


/**
 *@brief 收缩压上限报警值
 */
@property(nonatomic, assign) UInt8 systolicUpperAlarmValue;

/**
 *@brief 收缩压下限报警值
 */
@property(nonatomic, assign) UInt8 systolicLowerAlarmValue;

@end


