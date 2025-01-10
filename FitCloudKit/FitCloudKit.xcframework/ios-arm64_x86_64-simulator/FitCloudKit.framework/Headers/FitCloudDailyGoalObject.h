//
//  FitCloudDailyGoalObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2022/12/15.
//  Copyright © 2022 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Daily goal object
@interface FitCloudDailyGoalObject : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// The step count goal
/// - Note: Unit is steps
@property(nonatomic, readonly) UInt32 stepCountGoal;

/// The distance goal
/// - Note: Unit is centimeters (cm)
@property(nonatomic, readonly) UInt32 distanceGoal;

/// The calorie goal
/// - Note: Unit is calories (cal)
@property(nonatomic, readonly) UInt32 calorieGoal;

/// The exercise duration goal
/// - Note: Unit is minutes
@property(nonatomic, readonly) UInt16 durationGoal;

/// The timestamp when this goal was set
@property(nonatomic, strong, readonly) NSDate *_Nullable timestamp;

@end
