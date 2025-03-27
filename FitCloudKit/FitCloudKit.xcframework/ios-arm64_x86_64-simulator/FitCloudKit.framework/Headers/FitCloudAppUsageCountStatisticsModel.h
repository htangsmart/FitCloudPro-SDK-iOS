//
//  FitCloudAppUsageCountStatisticsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 3/27/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudAppUsageCountModel.h>

NS_ASSUME_NONNULL_BEGIN

/// A model representing daily statistics for app usage counts.
///
/// This model contains information about app usage statistics for a specific date,
/// including the date and a list of individual app usage counts.
@interface FitCloudAppUsageCountDailyStatisticsModel : NSObject

/// The date of the statistics.
@property(nonatomic, strong, readonly) NSDate *date;

/// The list of application usage count models.
@property(nonatomic, strong, readonly) NSArray<FitCloudAppUsageCountModel *> *appUsageCountList;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

/// A model representing a collection of daily app usage statistics.
///
/// This model maintains an array of daily statistics, where each entry contains
/// app usage information for a specific date.
@interface FitCloudAppUsageCountStatisticsModel : NSObject

/// The list of daily statistics.
@property(nonatomic, strong, readonly) NSArray<FitCloudAppUsageCountDailyStatisticsModel *> *dailyStatisticsList;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
