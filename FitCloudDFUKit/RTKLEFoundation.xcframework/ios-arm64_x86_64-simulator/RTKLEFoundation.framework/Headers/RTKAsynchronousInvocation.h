//
//  RTKAsynchronousInvocation.h
//  RTKLEFoundation
//
//  Created by Jerome Gu on 2024/5/15.
//  Copyright © 2024 jerome_gu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTKAsynchronousInvocation : NSObject

/// The GCD dispatch queue used to report event and internal process.
///
/// The SDK uses an internal created queue by default. You can specify a new one instead through this property.
@property (class) dispatch_queue_t dispatchQueue;

@end

NS_ASSUME_NONNULL_END
