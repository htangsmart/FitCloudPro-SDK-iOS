//
//  FitCloudWorkoutSlot.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/9/30.
//  Copyright © 2021 Zero Status. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/// A workout slot on the watch device
@interface FitCloudWorkoutSlot : NSObject

/// The index position of the slot
@property(nonatomic, readonly) NSUInteger slotIndex;

/// The workout type identifier
@property(nonatomic, readonly) UInt16 workoutType;

/// Whether push notifications are allowed for this slot
@property(nonatomic, readonly) BOOL allowPush;

@end
