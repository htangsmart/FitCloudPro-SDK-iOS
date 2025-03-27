//
//  FitCloudParentControlSettingsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 3/27/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that manages parental control settings for FitCloud devices.
///
/// Use this class to configure various parental control features including:
/// - Enabling/disabling parent control mode
/// - Managing time modification permissions
/// - Controlling access to watch settings
/// - Setting up game time restrictions
///
/// ## Topics
/// ### Configuring Basic Controls
/// - ``parentControlEnabled``
/// - ``allowTimeModification``
/// - ``allowWatchSettings``
/// - ``allowAlarmClockSettings``
///
/// ### Managing Game Time Controls
/// - ``gameTimeControlEnabled``
/// - ``gameTimeStartMinutes``
/// - ``gameTimeEndMinutes``
@interface FitCloudParentControlSettingsModel : NSObject

/// A Boolean value that determines whether parent control mode is enabled.
///
/// When set to `true`, parental control features become active on the device.
/// The default value is `false`.
@property(nonatomic, assign) BOOL parentControlEnabled;

/// A Boolean value that determines whether time modification is allowed.
///
/// When set to `true`, the device time can be modified.
/// Set to `false` to prevent unauthorized time changes.
@property(nonatomic, assign) BOOL allowTimeModification;

/// A Boolean value that determines whether access to watch settings interface is permitted.
///
/// Controls access to the device's settings menu:
/// - `true`: Settings menu is accessible
/// - `false`: Settings menu is locked
@property(nonatomic, assign) BOOL allowWatchSettings;

/// A Boolean value that determines whether alarm clock settings can be configured on the watch.
///
/// When enabled, allows modification of alarm settings on the device:
/// - `true`: Alarm settings can be modified
/// - `false`: Alarm settings are locked
@property(nonatomic, assign) BOOL allowAlarmClockSettings;

/// A Boolean value that determines whether game time control is enabled.
///
/// When enabled, restricts gaming to specific time periods:
/// - `true`: Game time restrictions are active
/// - `false`: No gaming time restrictions
@property(nonatomic, assign) BOOL gameTimeControlEnabled;

/// The start time of allowed gaming period in minutes from midnight (00:00).
///
/// Valid values range from 0 to 1439 (representing 23:59).
/// For example:
/// - 0 represents 00:00
/// - 480 represents 08:00
/// - 1320 represents 22:00
@property(nonatomic, assign) NSInteger gameTimeStartMinutes;

/// The end time of allowed gaming period in minutes from midnight (00:00).
///
/// Valid values range from 0 to 1439 (representing 23:59).
/// Must be greater than ``gameTimeStartMinutes``.
/// For example:
/// - 540 represents 09:00
/// - 1080 represents 18:00
/// - 1439 represents 23:59
@property(nonatomic, assign) NSInteger gameTimeEndMinutes;

@end

NS_ASSUME_NONNULL_END
