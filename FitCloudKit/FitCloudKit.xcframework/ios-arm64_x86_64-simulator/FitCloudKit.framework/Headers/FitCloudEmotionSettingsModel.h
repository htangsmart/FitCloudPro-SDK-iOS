//
//  FitCloudEmotionSettingsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 8/16/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that represents emotion monitoring settings.
@interface FitCloudEmotionSettingsModel : NSObject

/// A Boolean value that determines whether emotion monitoring is enabled.
///
/// When set to `true`, the device will monitor emotions during the specified time period.
/// When set to `false`, emotion monitoring is disabled.
@property(nonatomic, assign) BOOL enabled;

/// The start time in minutes from midnight (00:00).
///
/// This value represents the number of minutes elapsed since midnight (00:00).
/// For example:
/// - 0 represents 00:00
/// - 60 represents 01:00
/// - 720 represents 12:00
@property(nonatomic, assign) UInt16 begin;

/// The end time in minutes from midnight (00:00).
///
/// This value represents the number of minutes elapsed since midnight (00:00).
/// For example:
/// - 0 represents 00:00
/// - 60 represents 01:00
/// - 720 represents 12:00
@property(nonatomic, assign) UInt16 end;

/// A Boolean value that determines whether reminder alerts are enabled.
///
/// When set to `true`, the device will send alerts based on emotion monitoring results.
/// When set to `false`, no alerts will be sent.
@property(nonatomic, assign) BOOL remindAlertEnabled;

@end

NS_ASSUME_NONNULL_END
