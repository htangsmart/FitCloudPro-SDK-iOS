//
//  FitCloudHourlyWeatherModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-01-26.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FitCloudHourlyWeatherModel : NSObject

/// the datetime of the hour
@property(nonatomic, copy) NSDate* timestamp;


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

/// the air quality index (0~400)
@property(nonatomic, assign) UInt16 airQualityIndex;

/// Check if the weather data is valid
-(BOOL) isValid;


@end

NS_ASSUME_NONNULL_END
