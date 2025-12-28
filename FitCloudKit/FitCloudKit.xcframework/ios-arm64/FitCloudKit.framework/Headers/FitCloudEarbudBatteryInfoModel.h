//
//  FitCloudEarbudBatteryInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2025-12-27.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///
///  Model representing the battery status of an earbud.
///
///  This model provides read-only information about the earbud's charging state and battery level.
///
@interface FitCloudEarbudBatteryInfoModel : NSObject

///
///  Indicates whether the earbud is currently charging.
///
///  @returns `YES` if the earbud is charging, `NO` otherwise.
///
@property (nonatomic, readonly) BOOL charging;

///
///  The current battery level of the earbud.
///
///  @returns An integer value between 0 and 100 representing the battery percentage.
///
@property (nonatomic, readonly) NSInteger batteryLevel;


- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
