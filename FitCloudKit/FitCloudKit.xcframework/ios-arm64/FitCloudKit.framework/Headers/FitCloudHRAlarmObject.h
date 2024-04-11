//
//  FitCloudHRAlarmObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2019/9/13.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 心率报警设置（HR Alarm）
 */
@interface FitCloudHRAlarmObject : NSObject<NSCoding>

/**
 * @brief 静态心率报警开关是否开启
 */
@property(nonatomic, assign) BOOL normalHRAlarmOn;

/**
 * @brief 静态心率报警值
 */
@property(nonatomic, assign) UInt8 normalHRAlarmValue;

/// 静态心率过低报警值， 仅当 withHRLowAlarm 标识位 为 YES 时有效
@property(nonatomic, assign) UInt8 normalHRLowAlarmValue;

/**
 * @brief 动态心率报警开关是否开启
 */
@property(nonatomic, assign) BOOL sportsHRAlarmOn;

/**
 * @brief 动态心率报警值
 */
@property(nonatomic, assign) UInt8 sportsHRAlarmValue;

/// 动态心率过低报警值， 仅当 withHRLowAlarm 标识位 为 YES 时有效
@property(nonatomic, assign) UInt8 sportsHRLowAlarmValue;
@end

