//
//  FitCloudGPSConnectWorkoutEventModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// GPS-Connect Workout Event Model
@interface FitCloudGPSConnectWorkoutEventModel : NSObject

/// GPS-Connect Workout Event
@property(nonatomic, readonly) FitCloudGPSConnectWorkoutEvent event;

/// GPS-Connect Workout Start Time
@property(nonatomic, strong, readonly) NSDate *workoutStartTime;

/// GPS-Connect Workout Type
@property(nonatomic, readonly) FitCloudGPSConnectWorkoutType workoutType;

/// GPS-Connect Workout Duration In Seconds
@property(nonatomic, readonly) NSInteger workoutDurationInSeconds;

/// GPS-Connect Workout Event Model
/// - Parameters:
///   - event: GPS-Connect Workout Event
///   - workoutStartTime: GPS-Connect Workout Start Time
///   - workoutType: GPS-Connect Workout Type
///   - workoutDurationInSeconds: GPS-Connect Workout Duration In Seconds
- (instancetype)initWithEvent:(FitCloudGPSConnectWorkoutEvent)event
             workoutStartTime:(NSDate *)workoutStartTime
                  workoutType:(FitCloudGPSConnectWorkoutType)workoutType
     workoutDurationInSeconds:(NSInteger)workoutDurationInSeconds;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
