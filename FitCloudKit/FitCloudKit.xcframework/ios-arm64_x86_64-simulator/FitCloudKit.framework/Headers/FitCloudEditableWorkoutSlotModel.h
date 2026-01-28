//
//  FitCloudEditableWorkoutSlotModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-01-26.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface FitCloudEditableWorkoutSlotModel : NSObject

/// The index position of the slot
@property(nonatomic, assign) NSUInteger slotIndex;

/// The workout type identifier, if nil means the slots has no workout currently
@property(nonatomic, copy, nullable) NSNumber* workoutType;

@end

NS_ASSUME_NONNULL_END
