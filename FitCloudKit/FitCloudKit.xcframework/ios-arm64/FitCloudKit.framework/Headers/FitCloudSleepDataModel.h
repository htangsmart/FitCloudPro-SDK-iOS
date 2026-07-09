//
//  FitCloudSleepDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-09.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents sleep data model containing various sleep stage durations
@interface FitCloudSleepDataModel : NSObject

/// Duration of deep sleep in minutes
@property(nonatomic, assign, readonly) NSInteger deepSleepMinutes;

/// Duration of light sleep in minutes
@property(nonatomic, assign, readonly) NSInteger lightSleepMinutes;

/// Duration of awake time in minutes
@property(nonatomic, assign, readonly) NSInteger awakeMinutes;

/// Duration of rapid eye movement (REM) sleep in minutes
@property(nonatomic, assign, readonly) NSInteger remSleepMinutes;

/// Initialize sleep data model with sleep stage durations
/// - Parameters:
///   - deepSleepMinutes: Duration of deep sleep in minutes
///   - lightSleepMinutes: Duration of light sleep in minutes
///   - awakeMinutes: Duration of awake time in minutes
///   - remSleepMinutes: Duration of REM sleep in minutes
/// - Returns: A new instance of FitCloudSleepDataModel
- (instancetype)initWithDeepSleepMinutes:(NSInteger)deepSleepMinutes
                        lightSleepMinutes:(NSInteger)lightSleepMinutes
                            awakeMinutes:(NSInteger)awakeMinutes
                          remSleepMinutes:(NSInteger)remSleepMinutes;

/// Unavailable. Use designated initializer instead.
- (instancetype)init NS_UNAVAILABLE;

/// Unavailable. Use designated initializer instead.
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END