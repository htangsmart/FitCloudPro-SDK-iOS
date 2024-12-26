//
//  FitCloudGPSFileExpireTimeModel.h
//  FitCloudKit
//
//  Created by pcjbird on 7/21/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model representing GPS file expiration time information
@interface FitCloudGPSFileExpireTimeModel : NSObject

/// The GPS week number
/// - Note: Represents the number of weeks since January 6, 1980
@property(nonatomic, readonly) NSNumber *weekNum;

/// Time of week in seconds
/// - Note: Number of seconds since the beginning of the current GPS week
@property(nonatomic, readonly) NSNumber *timeOfWeek;

/// Creates a GPS file expiration time model from a date
/// - Parameter date: The date to create the model from
/// - Returns: A new GPS file expiration time model, or nil if creation fails
+ (FitCloudGPSFileExpireTimeModel *_Nullable)fromDate:(NSDate *_Nonnull)date;

/// Creates a GPS file expiration time model from GPS hours
/// - Parameter gpsHours: The number of GPS hours
/// - Returns: A new GPS file expiration time model, or nil if creation fails
+ (FitCloudGPSFileExpireTimeModel *_Nullable)fromGPSHours:(NSInteger)gpsHours;

/// Creates a GPS file expiration time model from a GPS file
/// - Parameter gpsFilePath: The path to the GPS file
/// - Returns: A new GPS file expiration time model, or nil if creation fails
+ (FitCloudGPSFileExpireTimeModel *_Nullable)fromGPSFile:(NSString *_Nonnull)gpsFilePath;

/// Gets the expiration date for this GPS file
/// - Returns: The date when this GPS file expires
- (NSDate *_Nonnull)expireDate;

/// Unavailable. Use factory methods instead.
+ (instancetype _Nullable)new NS_UNAVAILABLE;

/// Unavailable. Use factory methods instead.
- (instancetype _Nullable)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
