//
//  FitCloudEarbudsFindStatusInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2025-12-27.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Information model for the earbuds-find status.
@interface FitCloudEarbudsFindStatusInfoModel : NSObject

/// The find status of the left earbud.
@property(nonatomic, readonly) FitCloudEarbudFindStatus leftFindStatus;

/// The find status of the right earbud.
@property(nonatomic, readonly) FitCloudEarbudFindStatus rightFindStatus;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;

/// Unavailable class constructor.
+ (instancetype)new  NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
