//
//  FitCloudCapacity.h
//  FitCloudKit
//
//  Created by pcjbird on 1/15/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Capacity
@interface FitCloudCapacity : NSObject<NSCoding,NSCopying>

/// the capacity
@property(nonatomic, readonly) FITCLOUDDEVICECAPACITY capacity;

/// the capacity max value
@property(nonatomic, readonly) NSInteger value;

@end

NS_ASSUME_NONNULL_END
