//
//  FitCloudWeatherObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

@interface FitCloudWeatherForecast: NSObject

/// 最低温度，单位：°C
@property(nonatomic, assign)SInt8 min;

/// 最高温度，单位：°C
@property(nonatomic, assign)SInt8 max;

/// 天气类型
@property(nonatomic, assign)Byte weatherType;

@end

/// 天气信息
@interface FitCloudWeatherObject : NSObject<FitCloudSecureCoding>

/// 温度，单位：°C
@property(nonatomic, assign)SInt8 temperature;

/// 最低温度，单位：°C
@property(nonatomic, assign)SInt8 min;

/// 最高温度，单位：°C
@property(nonatomic, assign)SInt8 max;

/// 天气类型
@property(nonatomic, assign)Byte weatherType;

/// 城市名称，最多支持64个字节，超过会被截取
@property(nonatomic, strong)NSString* city;

/// 天气更新时间，该字段仅当标志位 allowWeatherForecast 为 YES时有效
/// > see allowWeatherForecast @ FitCloudFirmwareVersionObject
@property(nonatomic, strong)NSDate* updateDate;

/// 天气预报，最多支持14天，该字段仅当标志位 allowWeatherForecast 为 YES时有效
/// > see allowWeatherForecast @ FitCloudFirmwareVersionObject
@property(nonatomic, strong) NSArray<FitCloudWeatherForecast*>* forecast;

/// 大气压强，默认单位：百帕
@property(nonatomic, assign) UInt32 pressure;

/// 风力等级
@property(nonatomic, assign) UInt8 windScale;

/// 紫外线等级
@property(nonatomic, assign) UInt8 uvIndex;

/// 能见度，最大30000米，单位：米
@property(nonatomic, assign) UInt16 visibility;

@end
