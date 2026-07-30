//
//  FitCloudVoiceRideHailingFinishedModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-29.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Model for ride order finished status
@interface FitCloudVoiceRideHailingFinishedModel : NSObject

/// The total price, e.g. "$15.75", with maximum length of 12 bytes
@property (nonatomic, copy) NSString *totalPrice;

/// Check if the model is valid
/// - Returns: YES if the model is valid, otherwise NO
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
