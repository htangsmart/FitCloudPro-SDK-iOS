//
//  FitCloudCompanionWorkoutApp2DevicePeriodicReportDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Companion Workouts Periodic Report Data Model (App -> Device)
@interface FitCloudCompanionWorkoutApp2DevicePeriodicReportDataModel : NSObject

/// Companion workout start time
@property(nonatomic, strong, readonly) NSDate *workoutStartTime;

/// Companion workout duration in seconds since workout start
@property(nonatomic, strong, readonly) NSNumber *workoutDurationInSeconds;

/// Distance in centimeters since companion workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *distanceInCentimeters;

/// Calories burned since companion workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *caloriesBurned;

/// Current pace in seconds per kilometer
@property(nonatomic, strong, readonly, nullable) NSNumber *currentPace;

/// Number of steps since companion workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *numberOfSteps;

/// Companion Workouts Periodic Report Data Model (App -> Device)
/// - Parameters:
///   - workoutStartTime: The workout start time.
///   - workoutDurationInSeconds: The workout duration in seconds since workout start.
///   - distanceInCentimeters: The distance in centimeters since workout start.
///   - caloriesBurned: The calories burned since workout start.
///   - currentPace: The current pace in seconds per kilometer.
///   - numberOfSteps: The number of steps since workout start.
- (instancetype)initWithWorkoutStartTime:(NSDate *)workoutStartTime
                workoutDurationInSeconds:(NSNumber *)workoutDurationInSeconds
                   distanceInCentimeters:(NSNumber *_Nullable)distanceInCentimeters
                          caloriesBurned:(NSNumber *_Nullable)caloriesBurned
                             currentPace:(NSNumber *_Nullable)currentPace
                           numberOfSteps:(NSNumber *_Nullable)numberOfSteps;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
