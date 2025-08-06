//
//  FitCloudClassroomModeSettingsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 8/5/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that represents classroom mode settings for FitCloud devices.
@interface FitCloudClassroomModeSettingsModel : NSObject

/// A Boolean value that determines whether classroom mode is enabled.
@property(nonatomic, assign) BOOL enabled;

/// The start time in minutes from midnight (00:00).
@property(nonatomic, assign) UInt16 begin;

/// The end time in minutes from midnight (00:00).
@property(nonatomic, assign) UInt16 end;

@end

NS_ASSUME_NONNULL_END
