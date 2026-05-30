//
//  FitCloudGPSConnectWorkoutInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// GPS-Connect Workout Info Model
@interface FitCloudGPSConnectWorkoutInfoModel : NSObject

/// GPS-Connect Workout Start Time
@property(nonatomic, strong, readonly) NSDate *startTime;

/// GPS-Connect Workout Type
@property(nonatomic, readonly) FitCloudGPSConnectWorkoutType workoutType;

/// GPS-Connect Workout State
@property(nonatomic, readonly) FitCloudGPSConnectWorkoutState state;

/// GPS-Connect Workout Initiator
@property(nonatomic, readonly) FitCloudGPSConnectWorkoutInitiator initiator;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
