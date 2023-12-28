//
//  RTKAccessory.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2020/3/3.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A single wrapper of EAAccessory.
 */
DEPRECATED_ATTRIBUTE
@interface RTKAccessory : NSObject

@property (nonatomic, readonly) EAAccessory *underlyingAccessory;

- (instancetype)initWithEAAccessory:(EAAccessory *)accessory;

@end

NS_ASSUME_NONNULL_END
