//
//  FitCloudHRAlarmObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2019/9/13.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

/**
 * @brief 心率提醒设置（保留历史命名以兼容现有调用方）。
 * 支持类型以 allConfig.supportedHeartRateAlerts 为准；静息和运动各共用一个开关。
 */
@interface FitCloudHRAlarmObject : NSObject<FitCloudSecureCoding>

/**
 * @brief 静息心率报警开关是否开启
 */
@property(nonatomic, assign) BOOL normalHRAlarmOn;

/**
 * @brief 静息心率过高提醒阈值（BPM），0 表示不生效
 */
@property(nonatomic, assign) UInt8 normalHRAlarmValue;

/// 静息心率过低报警值， 有效性以 allConfig.supportedHeartRateAlerts 对应的低心率能力为准；0 表示不生效
@property(nonatomic, assign) UInt8 normalHRLowAlarmValue;

/**
 * @brief 运动时心率报警开关是否开启
 */
@property(nonatomic, assign) BOOL sportsHRAlarmOn;

/**
 * @brief 运动时心率过高提醒阈值（BPM），0 表示不生效
 */
@property(nonatomic, assign) UInt8 sportsHRAlarmValue;

/// 运动时心率过低报警值， 有效性以 allConfig.supportedHeartRateAlerts 对应的低心率能力为准；0 表示不生效
@property(nonatomic, assign) UInt8 sportsHRLowAlarmValue;
@end

