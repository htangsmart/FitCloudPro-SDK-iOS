//
//  FitCloudAppUsageCountModel.h
//  FitCloudKit
//
//  Created by pcjbird on 3/27/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that tracks application usage statistics.
///
/// This model stores information about how many times a specific application has been used.
/// Use this class to monitor and analyze application usage patterns.
///
/// ## Overview
/// The `FitCloudAppUsageCountModel` provides two main properties:
/// - An application identifier to uniquely identify the app
/// - A counter that tracks how many times the app has been used
///
/// ## Topics
/// ### Properties
/// - ``appId``
/// - ``usageCount``
@interface FitCloudAppUsageCountModel : NSObject

/// The unique identifier for the application.
///
/// This property stores a unique numerical identifier that distinguishes
/// this application from others in the system.
@property(nonatomic, readonly) NSInteger appId;

/// The number of times the application has been used.
///
/// This counter tracks the total number of times the application
/// has been launched or accessed by the user.
@property(nonatomic, readonly) NSInteger usageCount;

/// Disable default initialization method
+ (instancetype)new NS_UNAVAILABLE;
/// Disable default initialization method
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
