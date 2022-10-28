//
//  FitCloudWeatherObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 天气类型
 */
typedef NS_ENUM(Byte, WEATHERTYPE)
{
    WEATHERTYPE_SUNNY = 0x01,                   //晴天
    WEATHERTYPE_CLOUDY = 0x02,                  //多云
    WEATHERTYPE_OVERCAST = 0x03,                //阴天
    WEATHERTYPE_SHOWERS = 0x04,                 //阵雨
    WEATHERTYPE_THUNDERSHOWERSWITHHAIL = 0x05,  //雷阵雨、雷阵雨伴有冰雹
    WEATHERTYPE_LIGHTRAIN = 0x06,               //小雨
    WEATHERTYPE_MHSRAIN = 0x07,                 //中雨(moderate rain)、大雨(heavy rain)、暴雨(rainstorm)
    WEATHERTYPE_SLEET = 0x08,                   //雨夹雪、冻雨
    WEATHERTYPE_LIGHTSNOW = 0x09,               //小雪
    WEATHERTYPE_HEAVYSNOW = 0x0a,               //大雪、暴雪
    WEATHERTYPE_SANDSTORM = 0x0b,               //沙尘暴、浮沉
    WEATHERTYPE_FOGORHAZE = 0x0c,               //雾、雾霾
    WEATHERTYPE_UNKNOWN = 0xff,                 //未知天气
};

@interface FitCloudWeatherForecast: NSObject

/**
 * @brief 最低温度
 */
@property(nonatomic, assign)SInt8 min;

/**
 * @brief 最高温度
 */
@property(nonatomic, assign)SInt8 max;

/**
 * @brief 天气类型
 */
@property(nonatomic, assign)WEATHERTYPE weathertype;

@end

/**
 * @brief 天气信息
 */
@interface FitCloudWeatherObject : NSObject<NSCoding>

/**
 * @brief 温度
 */
@property(nonatomic, assign)SInt8 temperature;

/**
 * @brief 最低温度
 */
@property(nonatomic, assign)SInt8 min;

/**
 * @brief 最高温度
 */
@property(nonatomic, assign)SInt8 max;

/**
 * @brief 天气类型
 */
@property(nonatomic, assign)WEATHERTYPE weathertype;

/**
 * @brief 城市名称，最多支持64个字节，超过会被截取
 */
@property(nonatomic, strong)NSString* city;

/**
 * @brief 天气更新时间，该字段仅当标志位 allowWeatherForecast 为 YES时有效
 * @see allowWeatherForecast @ FitCloudFirmwareVersionObject
 */
@property(nonatomic, strong)NSDate* updateDate;

/**
 * @brief 天气预报，最多支持14天，该字段仅当标志位 allowWeatherForecast 为 YES时有效
 * @see allowWeatherForecast @ FitCloudFirmwareVersionObject
*/
@property(nonatomic, strong) NSArray<FitCloudWeatherForecast*>* forecast;

/**
 * @brief 大气压强，默认单位：百帕
 */
@property(nonatomic, assign) UInt32 pressure;


/**
 * @brief 风力等级
 */
@property(nonatomic, assign) UInt8 windScale;

/**
 * @brief 能见度，默认单位：公里
 */
@property(nonatomic, assign) UInt8 vis;

@end
