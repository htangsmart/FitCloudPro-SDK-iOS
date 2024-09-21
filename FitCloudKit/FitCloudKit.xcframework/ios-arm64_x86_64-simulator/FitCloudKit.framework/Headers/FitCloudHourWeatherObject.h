//
//  FitCloudHourWeatherObject.h
//  FitCloudKit
//
//  Created by pcjbird on 7/1/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// the hour weather information
@interface FitCloudHourWeatherObject : NSObject

/// the weather type
@property(nonatomic, assign)Byte weatherType;

/// the temperature，unit: °C
@property(nonatomic, assign)SInt8 temperature;

/// the wind scale
@property(nonatomic, assign) UInt8 windScale;

/// the UV index
@property(nonatomic, assign) UInt8 uvIndex;

/// the visibility in meters
/// > Warning: the maximum visibility is 30000 meters
@property(nonatomic, assign) UInt16 visibility;

@end

NS_ASSUME_NONNULL_END
