//
//  FitCloudDailyGoalObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2022/12/15.
//  Copyright © 2022 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FitCloudDailyGoalObject : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * @brief 步数目标，单位：步数
 */
@property (nonatomic, readonly) UInt32 stepCountGoal;

/**
 * @brief 距离目标，单位：厘米(cm)
 */
@property (nonatomic, readonly) UInt32 distanceGoal;


/**
 * @brief 卡路里目标，单位：小卡(cal)
 */
@property (nonatomic, readonly) UInt32 caloryGoal;

/**
 * @brief 时间戳
 */
@property (nonatomic, strong, readonly) NSDate* _Nullable timestamp;

@end

