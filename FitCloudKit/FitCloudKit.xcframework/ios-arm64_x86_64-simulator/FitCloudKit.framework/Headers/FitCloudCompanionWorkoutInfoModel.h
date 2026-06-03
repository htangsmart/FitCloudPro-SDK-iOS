//
//  FitCloudCompanionWorkoutInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-30.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Companion workout info model
@interface FitCloudCompanionWorkoutInfoModel : NSObject

/// Companion workout start time
@property(nonatomic, strong, readonly) NSDate *startTime;

/// Companion workout type
@property(nonatomic, readonly) FitCloudWorkoutType workoutType;

/// Companion workout state
@property(nonatomic, readonly) FitCloudCompanionWorkoutState state;

/// Companion workout initiator
@property(nonatomic, readonly) FitCloudCompanionWorkoutInitiator initiator;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
