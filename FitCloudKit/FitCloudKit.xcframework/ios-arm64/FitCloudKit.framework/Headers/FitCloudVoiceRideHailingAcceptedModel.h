//
//  FitCloudVoiceRideHailingAcceptedModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-29.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Model for ride order accepted status
@interface FitCloudVoiceRideHailingAcceptedModel : NSObject

/// The vehicle model, e.g. "Tesla Model S (White)", with maximum length of 64 bytes
@property (nonatomic, copy) NSString *vehicleModel;

/// The plate number, e.g. "CA12345", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *plateNumber;

/// The driver name, e.g. "John Doe", with maximum length of 32 bytes
@property (nonatomic, copy) NSString *driverName;

/// The driver phone number, e.g. "+1234567890", with maximum length of 16 bytes
@property (nonatomic, copy) NSString *driverPhoneNumber;

/// The pickup location, e.g. "123 Main St, Anytown, USA", with maximum length of 128 bytes
@property (nonatomic, copy) NSString *pickup;

/// The distance to pickup, e.g. "0.5km", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *distanceToPickup;

/// The estimated pickup time since now, e.g. "5 minutes", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *estimatedPickupTimeSinceNow;

/// Check if the model is valid
/// - Returns: YES if the model is valid, otherwise NO
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
