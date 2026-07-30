//
//  FitCloudVoiceRideHailingOnTripModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-29.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Model for ride order on trip status
@interface FitCloudVoiceRideHailingOnTripModel : NSObject

/// The remaining distance, e.g. "2.5km", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *remainingDistance;

/// The estimated time to destination, e.g. "15 minutes", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *estimatedTimeToDestination;

/// The estimated total price, e.g. "$15.75", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *estimatedTotalPrice;

/// Check if the model is valid
/// - Returns: YES if the model is valid, otherwise NO
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
