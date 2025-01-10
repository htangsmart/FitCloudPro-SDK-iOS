//
//  FitCloudBatteryInfoObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// The charging state of the watch
typedef NS_ENUM(Byte, BATTERYSTATE) {
    BATTERYSTATE_NORMAL = 0,   // Not charging
    BATTERYSTATE_CHARGING = 1, // Charging
};

/// Information about the watch battery level and charging status
@interface FitCloudBatteryInfoObject : NSObject <NSCopying>

/// The charging state of the watch
@property(nonatomic, assign) BATTERYSTATE state;

/// The battery level in bars/grids
@property(nonatomic, assign) UInt8 value;

/// The battery level percentage (range: 0-100)
@property(nonatomic, assign) UInt8 percent;
@end
