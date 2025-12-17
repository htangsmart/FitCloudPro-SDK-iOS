//
//  FitCloudTaskModel.h
//  FitCloudKit
//
//  Created by pcjbird on 11/19/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

NS_ASSUME_NONNULL_BEGIN

/// A model representing a task in FitCloud
@interface FitCloudTaskModel : NSObject

/// The task Id
@property(nonatomic, assign) UInt8 taskId;

/// The type of task
/// - Note: See ``FITCLOUDTASK`` for available task types
@property(nonatomic, assign) FITCLOUDTASK taskType;

/// The time components when the task should fire
@property(nonatomic, strong) NSDateComponents *fire;

/// The cycle pattern for task repetition
/// - Note: See ``FITCLOUDTASKCYCLE`` for available cycle options
@property(nonatomic, assign) FITCLOUDTASKCYCLE cycle;

/// The current status of the task
/// - Note: See ``FITCLOUDTASKSTATUS`` for possible status values
@property(nonatomic, assign) FITCLOUDTASKSTATUS status;

/// The number of coins rewarded after completing the task
@property(nonatomic, assign) Byte rewardCoins;

/// The display label for the task
@property(nonatomic, strong) NSString *label;

/// The details description for the task
@property(nonatomic, strong) NSString *desc;

/// Whether the task is enabled.
/// `YES`: enabled, `NO`: disabled
@property(nonatomic, assign) BOOL enabled;

/// Whether the task file time has been set.
/// `YES`: already set, `NO`:  not set
@property(nonatomic, assign) BOOL hasSetFireTime;

@end

NS_ASSUME_NONNULL_END
