//
//  FitCloudCompanionWorkoutEventModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Companion Workouts Event Model
@interface FitCloudCompanionWorkoutEventModel : NSObject

/// Companion workout event
@property(nonatomic, readonly) FitCloudCompanionWorkoutEvent event;

/// Companion workout start time
@property(nonatomic, strong, readonly) NSDate *workoutStartTime;

/// Companion workout type
@property(nonatomic, readonly) FitCloudWorkoutType workoutType;

/// Companion workout duration in seconds since workout start
@property(nonatomic, readonly) NSInteger workoutDurationInSeconds;

/// Companion workout Event Model
/// - Parameters:
///   - event: Companion workout Event
///   - workoutStartTime: Companion workout Start Time
///   - workoutType: Companion workout Type
///   - workoutDurationInSeconds: Companion workout Duration In
- (instancetype)initWithEvent:(FitCloudCompanionWorkoutEvent)event
             workoutStartTime:(NSDate *)workoutStartTime
                  workoutType:(FitCloudWorkoutType)workoutType
     workoutDurationInSeconds:(NSInteger)workoutDurationInSeconds;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
