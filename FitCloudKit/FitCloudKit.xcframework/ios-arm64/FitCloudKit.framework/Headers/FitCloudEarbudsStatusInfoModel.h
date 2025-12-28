//
//  FitCloudEarbudsStatusInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2025-12-27.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudEarbudBatteryInfoModel.h>

NS_ASSUME_NONNULL_BEGIN

/// A model representing the real-time status of the earbuds.
@interface FitCloudEarbudsStatusInfoModel : NSObject

/// The connection status of the left earbud.
@property (nonatomic, readonly) FitCloudEarbudConnectionStatus leftConnectionStatus;

/// The connection status of the right earbud.
@property (nonatomic, readonly) FitCloudEarbudConnectionStatus rightConnectionStatus;

/// Indicates whether the left earbud is currently placed in the charging case.
@property (nonatomic, readonly) FitCloudEarbudInCaseStatus leftInCaseStatus;

/// Indicates whether the right earbud is currently placed in the charging case.
@property (nonatomic, readonly) FitCloudEarbudInCaseStatus rightInCaseStatus;

/// Battery information for the left earbud.
@property (nonatomic, strong, readonly, nullable) FitCloudEarbudBatteryInfoModel* leftBatteryInfo;

/// Battery information for the right earbud.
@property (nonatomic, strong, readonly, nullable) FitCloudEarbudBatteryInfoModel* rightBatteryInfo;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;

/// Unavailable constructor.
+ (instancetype)new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
