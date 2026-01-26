//
//  FitCloudWorkoutSlotEditModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-01-26.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface FitCloudWorkoutSlotEditModel : NSObject

/// The index position of the slot
@property(nonatomic, assign) NSUInteger slotIndex;

/// The workout type identifier, if nil means will delete the workout in this slot
@property(nonatomic, copy, nullable) NSNumber* workoutType;

@end

NS_ASSUME_NONNULL_END
