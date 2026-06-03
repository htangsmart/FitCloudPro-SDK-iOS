//
//  FitCloudCompanionWorkoutDevice2AppPeriodicReportDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Companion Workouts Periodic Report Data Model (Device to App)
@interface FitCloudCompanionWorkoutDevice2AppPeriodicReportDataModel : NSObject

/// Companion Workout Start Time
@property(nonatomic, strong, readonly) NSDate *workoutStartTime;

/// Number of steps since companion workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *numberOfSteps;

/// Calories burned since companion workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *caloriesBurned;

/// Current heart rate (BPM)
@property(nonatomic, strong, readonly, nullable) NSNumber *bpmValue;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
