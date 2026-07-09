//
//  FitCloudHRVDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-09.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents HRV (Heart Rate Variability) data model
@interface FitCloudHRVDataModel : NSObject

/// Average HRV value, may be nil if not available
@property(nonatomic, strong, readonly, nullable) NSNumber *averageHRV;

/// Baseline HRV value, may be nil if not available
@property(nonatomic, strong, readonly, nullable) NSNumber *baselineHRV;

/// Initialize HRV data model with HRV values
/// - Parameters:
///   - averageHRV: Average HRV value, may be nil
///   - baselineHRV: Baseline HRV value, may be nil
/// - Returns: A new instance of FitCloudHRVDataModel
- (instancetype)initWithAverageHRV:(nullable NSNumber *)averageHRV
                       baselineHRV:(nullable NSNumber *)baselineHRV;

/// Unavailable. Use designated initializer instead.
- (instancetype)init NS_UNAVAILABLE;

/// Unavailable. Use designated initializer instead.
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END