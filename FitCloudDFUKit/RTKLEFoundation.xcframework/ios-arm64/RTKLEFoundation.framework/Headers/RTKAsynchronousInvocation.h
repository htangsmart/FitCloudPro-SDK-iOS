//
//  RTKAsynchronousInvocation.h
//  RTKLEFoundation
//
//  Created by Jerome Gu on 2024/5/15.
//  Copyright © 2024 jerome_gu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// APIs can be used to customize asynchronous dispatch behaviour.
@interface RTKAsynchronousInvocation : NSObject

/// The GCD dispatch queue used to report events and internal process.
///
/// The SDK uses an internal queue by default. You can specify an other one instead through this property.
@property (class) dispatch_queue_t dispatchQueue;

@end

NS_ASSUME_NONNULL_END
