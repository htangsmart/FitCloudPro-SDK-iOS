//
//  FitCloudVoiceRideHailingConfirmModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-29.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Model for confirming ride orders
@interface FitCloudVoiceRideHailingConfirmModel : NSObject

/// The pickup location, e.g. "123 Main St, Anytown, USA", with maximum length of 128 bytes
@property (nonatomic, copy) NSString *pickup;

/// The destination, e.g. "456 Elm St, Anytown, USA", with maximum length of 128 bytes
@property (nonatomic, copy) NSString *destination;

/// The vehicle type, e.g. "Fast car", with maximum length of 32 bytes
@property (nonatomic, copy) NSString *vehicleType;

/// The estimated price, e.g. "$13.45", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *estimatedPrice;

/// The estimated wait time, e.g. "5 minutes", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *estimatedWaitTime;

/// Check if the model is valid
/// - Returns: YES if the model is valid, otherwise NO
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
