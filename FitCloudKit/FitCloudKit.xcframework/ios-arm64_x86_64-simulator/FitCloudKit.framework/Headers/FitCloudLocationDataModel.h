//
//  FitCloudLocationDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 7/20/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// GPS location data model
/// - Note: Represents GPS coordinates and timezone information
@interface FitCloudLocationDataModel : NSObject

/// The timezone offset from UTC
/// - Note: Positive values indicate east of UTC, negative values indicate west of UTC
/// - Example: 8 for UTC+8 (East), -8 for UTC-8 (West)
@property(nonatomic, readonly) NSInteger timezone;

/// The longitude coordinate
/// - Note: Positive values indicate east longitude, negative values indicate west longitude
@property(nonatomic, readonly) Float32 longitude;

/// The latitude coordinate
/// - Note: Positive values indicate north latitude, negative values indicate south latitude
@property(nonatomic, readonly) Float32 latitude;

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// Creates a new GPS location data model with the specified coordinates and timezone
/// - Parameters:
///   - longtitude: The longitude coordinate. Positive for east, negative for west.
///   - latitude: The latitude coordinate. Positive for north, negative for south.
///   - timezone: The timezone offset from UTC. Positive for east, negative for west.
/// - Returns: A new GPS location data model, or nil if creation fails
+ (FitCloudLocationDataModel *_Nullable)modelWithLongitude:(Float32)longtitude latitude:(Float32)latitude timezone:(NSInteger)timezone;

@end

NS_ASSUME_NONNULL_END
