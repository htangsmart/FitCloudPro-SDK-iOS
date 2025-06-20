//
//  FitCloudGamePlayCountStatisticsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 6/20/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudGamePlayCountModel.h>

NS_ASSUME_NONNULL_BEGIN


/// A model representing daily statistics for game play counts
///
/// This model encapsulates statistics for game plays on a specific date, including:
/// - The date of the statistics
/// - A list of game play counts for different games
@interface FitCloudGamePlayCountDailyStatisticsModel : NSObject

/// The date for which these statistics apply
@property(nonatomic, strong, readonly) NSDate *date;

/// An array of game play count models for different games on this date
@property(nonatomic, strong, readonly) NSArray<FitCloudGamePlayCountModel *> *gamePlayCountList;

/// Unavailable. Use designated initializer instead.
- (instancetype)init NS_UNAVAILABLE;
/// Unavailable. Use designated initializer instead.
+ (instancetype)new NS_UNAVAILABLE;

@end

/// A model representing aggregated game play count statistics
///
/// This model provides access to:
/// - A collection of daily statistics for game plays
@interface FitCloudGamePlayCountStatisticsModel : NSObject

/// An array of daily statistics models, each containing game play counts for a specific date
@property(nonatomic, strong, readonly) NSArray<FitCloudGamePlayCountDailyStatisticsModel *> *dailyStatisticsList;

/// Unavailable. Use designated initializer instead.
- (instancetype)init NS_UNAVAILABLE;
/// Unavailable. Use designated initializer instead.
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
