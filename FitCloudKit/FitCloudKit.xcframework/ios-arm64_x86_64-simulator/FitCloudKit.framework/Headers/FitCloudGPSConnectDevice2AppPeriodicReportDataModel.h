//
//  FitCloudGPSConnectDevice2AppPeriodicReportDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// GPS-Connect Workout Periodic Report Data Model (Device to App)
@interface FitCloudGPSConnectDevice2AppPeriodicReportDataModel : NSObject

/// GPS-Connect Workout Start Time
@property(nonatomic, strong, readonly) NSDate *workoutStartTime;

/// Number of steps since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *numberOfSteps;

/// Calories burned since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *caloriesBurned;

/// Average BPM since workout start
@property(nonatomic, strong, readonly, nullable) NSNumber *avgBPM;


/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
