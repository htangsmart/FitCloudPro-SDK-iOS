//
//  FitCloudScreenResolution.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/9/8.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

/// A class that represents screen resolution information for a watch device
@interface FitCloudScreenResolution : NSObject <FitCloudSecureCoding>

/// The LCD identifier value
@property(nonatomic, readonly) UInt8 lcd;

/// A boolean value indicating whether the screen shape is round
@property(nonatomic, readonly) BOOL round;

/// The width of the screen in pixels
@property(nonatomic, readonly) UInt16 width;

/// The height of the screen in pixels
@property(nonatomic, readonly) UInt16 height;

/// The corner radius of the screen
@property(nonatomic, readonly) UInt8 cornerRadius;

@end
