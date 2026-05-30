//
//  FitCloudGPSConnectApp2DevicePeriodicReportDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// GPS-Connect Workout Periodic Report Data Model (App -> Device)
@interface FitCloudGPSConnectApp2DevicePeriodicReportDataModel : NSObject

/// GPS-Connect Workout Start Time
@property(nonatomic, strong, readonly) NSDate *workoutStartTime;

/// Workout duration in seconds since workout start
@property(nonatomic, strong, readonly) NSNumber *workoutDurationInSeconds;

/// Distance in centimeters since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *distanceInCentimeters;

/// Calories burned since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *caloriesBurned;

/// Average pace in seconds per kilometer since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *avgPace;

/// Number of steps since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *numberOfSteps;

/// GPS-Connect Workout Periodic Report Data Model (App -> Device)
/// - Parameters:
///   - workoutStartTime: The workout start time.
///   - workoutDurationInSeconds: The workout duration in seconds since workout start.
///   - distanceInCentimeters: The distance in centimeters since workout start.
///   - caloriesBurned: The calories burned since workout start.
///   - avgPace: The average pace in seconds per kilometer since workout start.
///   - numberOfSteps: The number of steps since workout start.
- (instancetype)initWithWorkoutStartTime:(NSDate *)workoutStartTime
                workoutDurationInSeconds:(NSNumber *)workoutDurationInSeconds
                   distanceInCentimeters:(NSNumber *_Nullable)distanceInCentimeters
                          caloriesBurned:(NSNumber *_Nullable)caloriesBurned
                                 avgPace:(NSNumber *_Nullable)avgPace
                           numberOfSteps:(NSNumber *_Nullable)numberOfSteps;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
