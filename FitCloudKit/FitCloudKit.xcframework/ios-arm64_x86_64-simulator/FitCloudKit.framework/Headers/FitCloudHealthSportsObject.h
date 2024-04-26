//
//  FitCloudHealthSportsObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/30.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <FitCloudKit/FitCloudKitDefines.h>

#pragma mark - 手表手动同步对象基类


@interface FitCloudManualSyncItemObject : NSObject

/**
 * @brief 采样时刻
 */
@property(nonatomic, strong) NSDate* moment;

/**
 * @brief 是否为手表手动测量
 */
@property(nonatomic, assign) BOOL manualAtWatch;

/**
 * @brief 是否为真血压
 */
@property(nonatomic, assign) BOOL baseOnPneumaticpump;

@end


/**
 * @brief 手表手动同步记录对象基类
 */
@interface FitCloudManualSyncRecordObject<__covariant ObjectType> : NSObject

/**
 * @brief 开始时间
 */
@property(nonatomic, strong) NSDate* begin;

/**
 * @brief 采样时间 (单位：秒)
 */
@property(nonatomic, assign) NSTimeInterval interval;

/**
 * @brief 详细条目
 */
@property(nonatomic, strong) NSArray<ObjectType>* items;

@end

#pragma mark - 计步

/**
 * @brief 手表计步数据条目
 */
@interface FitCloudStepItemObject : FitCloudManualSyncItemObject

/**
 * @brief 步数
 */
@property(nonatomic, assign) UInt16 steps;

/**
 * @brief 距离，单位(cm)
 * @note 该字段只有当距离&卡路里新算法时有效
 */
@property(nonatomic, assign) UInt16 distance;

/**
 * @brief 卡路里，单位(小卡 cal)
 * @note 该字段只有当距离&卡路里新算法时有效
 */
@property(nonatomic, assign) UInt16 calory;

/// 运动时长，单位：分钟
/// 该字段仅部分设备有效, @see shouldStepItemWithDuration
@property(nonatomic, assign) UInt16 duration;

@end


/**
 * @brief 手表计步数据记录
 */
@interface FitCloudStepRecordObject : FitCloudManualSyncRecordObject<FitCloudStepItemObject*>


@end

#pragma mark - 睡眠

/**
 * @brief 手表睡眠数据条目
 */
@interface FitCloudSleepItemObject : FitCloudManualSyncItemObject

/**
 * @brief 睡眠质量
 */
@property(nonatomic, assign) FITCLOUDSLEEPQUALITY quality;

@end

/**
 * @brief 手表睡眠数据记录
 */
@interface FitCloudSleepRecordObject : FitCloudManualSyncRecordObject<FitCloudSleepItemObject*>

@end

#pragma mark - 心率

/**
 * @brief 手表心率(Heart Rate)数据条目
 */
@interface FitCloudHRItemObject : FitCloudManualSyncItemObject


/**
 * @brief 心率值(次/分钟)
 */
@property(nonatomic, assign) UInt8    value;

@end

/**
 * @brief 手表心率(Heart Rate)数据记录
 */
@interface FitCloudHRRecordObject : FitCloudManualSyncRecordObject<FitCloudHRItemObject*>

@end


#pragma mark - 血压

/**
 * @brief 手表血压(Blood Pressure)数据条目
 */
@interface FitCloudBPItemObject : FitCloudManualSyncItemObject

/**
 *@brief 舒张压
 */
@property(nonatomic, assign) UInt8 diastolic;

/**
 *@brief 收缩压
 */
@property(nonatomic, assign) UInt8 systolic;

/**
 *@brief 心率，如果是真血压
 */
@property(nonatomic, assign) UInt8 heartRateIfBaseOnPneumaticpump;


@end

/**
 * @brief 手表血压(Blood Pressure)数据记录
 */
@interface FitCloudBPRecordObject : FitCloudManualSyncRecordObject<FitCloudBPItemObject*>

@end


#pragma mark - 血氧

/**
 * @brief 手表血氧(Blood Oxygen)数据条目
 */
@interface FitCloudBOItemObject : FitCloudManualSyncItemObject

/**
 * @brief 血氧值
 */
@property(nonatomic, assign) UInt8      value;

@end

/**
 * @brief 手表血氧(Blood Oxygen)数据记录
 */
@interface FitCloudBORecordObject : FitCloudManualSyncRecordObject<FitCloudBOItemObject*>

@end

#pragma mark - 心电

/**
 * @brief 手表心电数据条目
 */
@interface FitCloudECGItemObject : FitCloudManualSyncItemObject

/**
 * @brief 心电值
 */
@property(nonatomic, assign) UInt16 value;

@end

/**
 * @brief 手表心电数据记录
 */
@interface FitCloudECGRecordObject : FitCloudManualSyncRecordObject<FitCloudECGItemObject*>

@end

#pragma mark - 呼吸频率

/**
 * @brief 手表呼吸频率(Breathe Rate)数据条目
 */
@interface FitCloudBRItemObject : FitCloudManualSyncItemObject

/**
 * @brief 呼吸频率
 */
@property(nonatomic, assign) UInt8  value;

@end

/**
 * @brief 手表呼吸频率(Breathe Rate)数据记录
 */
@interface FitCloudBRRecordObject : FitCloudManualSyncRecordObject<FitCloudBRItemObject*>


@end

#pragma mark - 体温

/**
 * @brief 手表体温(Body Temperature)数据条目
 */
@interface FitCloudBTItemObject : FitCloudManualSyncItemObject

/**
 * @brief 腕温，单位：摄氏度
 */
@property(nonatomic, assign) CGFloat  wrist;

/**
 * @brief 体温，单位：摄氏度
 */
@property(nonatomic, assign) CGFloat  body;

@end

/**
 * @brief 手表体温(Body Temperature)数据记录
 */
@interface FitCloudBTRecordObject : FitCloudManualSyncRecordObject<FitCloudBTItemObject*>


@end


#pragma mark - 压力

/**
 * @brief 压力指数(Stress Index)数据条目
 */
@interface FitCloudStressIndexItemObject : FitCloudManualSyncItemObject

/**
 * @brief 压力指数
 */
@property(nonatomic, assign) UInt8  stressIndex;


@end

/**
 * @brief 手表压力指数(Stress Index)数据记录
 */
@interface FitCloudStressIndexRecordObject : FitCloudManualSyncRecordObject<FitCloudStressIndexItemObject*>


@end


#pragma mark - 游戏记录

/**
 * @brief 游戏记录数据条目
 */
@interface FitCloudGameItemObject : FitCloudManualSyncItemObject

/**
 * @brief 游戏类型
 */
@property(nonatomic, assign) FITCLOUDGAME  category;

/**
 * @brief 游戏开始时间
 */
@property(nonatomic, strong) NSDate* begin;

/**
 * @brief 游戏持续时长，单位：s
 */
@property(nonatomic, assign) NSInteger duration;

/**
 * @brief 游戏分数
 */
@property(nonatomic, assign) NSInteger score;

/**
 * @brief 等级关卡
 */
@property(nonatomic, assign) NSInteger level;


@end

/**
 * @brief 游戏记录数据
 */
@interface FitCloudGameRecordObject : FitCloudManualSyncRecordObject<FitCloudGameItemObject*>


@end

#pragma mark - 运动模式

/**
 * @brief 手表运动模式运动数据条目
 */
@interface FitCloudSportsItemObject : FitCloudManualSyncItemObject

/**
 * @brief 运动类型
 */
@property(nonatomic, assign) FITCLOUDSPORTSTYPE genre;

/**
 * @brief 运动时长(秒)
 */
@property(nonatomic, assign) UInt16  duration;

/**
 * @brief 步数
 */
@property(nonatomic, assign) UInt16 steps;

/**
 * @brief 距离(米)
 */
@property(nonatomic, assign) UInt16 distance;

/**
 * @brief 卡路里(小卡)
 */
@property(nonatomic, assign) UInt16 calory;

/**
 * @brief 配速(min/km)
 */
@property(nonatomic, assign) UInt16 pace;

/**
 * @brief 运动心率(次/min)
 */
@property(nonatomic, assign) UInt8  hr_excercise;

@end

/**
 * @brief 手表运动模式运动数据记录
 */
@interface FitCloudSportsRecordObject : FitCloudManualSyncRecordObject<FitCloudSportsItemObject*>

/**
 * @brief 手表独立GPS运动，该字段关联对应的GPS数据
 */
@property(nonatomic, strong) NSString* gpsDataAssociateKey;

/// 当手表支持独立GPS运动且支持指定展示数据是表示展示数据信息
/// the workout display configurations
///
/// @see `WORKOUTDATAITEMDISPLAY`,  if want to display `WORKOUTDATAITEMDISPLAY_DURATION` and `WORKOUTDATAITEMDISPLAY_AVG_BPM`, the displayConfig string should be `"1,2"`, and so on.
@property(nonatomic, strong) NSString* displayConfig;

@end


#pragma mark - GPS数据

/**
 * @brief 手表运动模式运动GPS数据条目
 */
@interface FitCloudGPSItemObject : FitCloudManualSyncItemObject

/**
 * @brief 经度
 */
@property(nonatomic, assign) CGFloat longitude;


/**
 * @brief 纬度
 */
@property(nonatomic, assign) CGFloat latitude;

/**
 * @brief 海拔,单位：m
 */
@property(nonatomic, assign) UInt16 altitude;


/**
 * @brief 卫星数量（个数）
 */
@property(nonatomic, assign) UInt8  satellitesCount;

/// 是否为一段的起点
@property(nonatomic, assign) BOOL   isStartingPoint;

@end

/**
 * @brief 手表运动模式运动GPS数据记录
 */
@interface FitCloudGPSRecordObject : FitCloudManualSyncRecordObject<FitCloudGPSItemObject*>

/**
 * @brief 手表独立GPS运动Key
 */
@property(nonatomic, strong) NSString* gpsDataKey;

@end

#pragma mark - 健康实时测量

/**
 * @brief 实时健康测量项定义
 */
typedef NS_OPTIONS(UInt16, FITCLOUDREALTIMEMHEALTHEASUREITEM)
{
    FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE = 0,                        //无
    FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE = 1,                   //心率
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODOXYGEN = 1 << 1,            //血氧
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE = 1 << 2,          //血压
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BREATHERATE = 1 << 3,            //呼吸频率
    FITCLOUDREALTIMEMHEALTHEASUREITEM_ECG = 1 << 4,                    //心电
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BODYTEMPERATURE = 1 << 5,        //体温
    FITCLOUDREALTIMEMHEALTHEASUREITEM_STRESSINDEX = 1 << 6,            //压力指数
};

/**
 * @brief 实时健康测量参数
 */
@interface FitCloudRealTimeHealthMeasuringParam : NSObject<NSCoding>

/**
 * @brief 测量项
 */
@property(nonatomic, assign) FITCLOUDREALTIMEMHEALTHEASUREITEM item;

/**
 * @brief 实时测量时间间隔(单位：秒)
 */
@property(nonatomic, assign) UInt8 interval;

/**
 * @brief 单次实时测量最长时间限制(单位：分钟)
 */
@property(nonatomic, assign) UInt8 maxMeasuringMinutes;

@end

/**
 * @brief 实时健康测量返回的数据
 */
@interface FitCloudRealTimeHealthMeasuringResultObject : NSObject

/**
* @brief 采样时刻
*/
@property(nonatomic, strong) NSDate* moment;

/**
 * @brief 心率
 */
@property(nonatomic, assign) UInt8 heartRate;

/**
 * @brief 血氧
 */
@property(nonatomic, assign) UInt8 bloodOxygen;

/**
 *@brief 舒张压
 */
@property(nonatomic, assign) UInt8 diastolic;

/**
 *@brief 收缩压
 */
@property(nonatomic, assign) UInt8 systolic;

/**
 * @brief 呼吸频率
 */
@property(nonatomic, assign) UInt8  breatheRate;

/**
 * @brief 体温测量状态  0:正常状态，数据正常返回中； 1:测量结束，正常结束时间结束； 2:测量结束，未佩戴手表；3:测量结束，体温过高；4:测量结束，体温过低；
 */
@property(nonatomic, assign) UInt8  temperatureFlag;

/**
 * @brief 腕温，单位：摄氏度
 */
@property(nonatomic, assign) CGFloat  wrist;

/**
 * @brief 体温，单位：摄氏度
 */
@property(nonatomic, assign) CGFloat  body;

/**
 * @brief 压力，当手表支持压力指数时有效
 */
@property(nonatomic, assign) UInt8  stressIndex;

@end

#pragma mark - 每日运动健康数据

/// 每日运动健康数据
@interface FitCloudDailyHealthAndSportsDataObject : NSObject<NSCoding>

/// 累计步数
@property(nonatomic, assign) NSUInteger steps;

/// 距离(单位：米)
@property(nonatomic, assign) NSUInteger distance;

/// 卡路里(单位：小卡)
@property(nonatomic, assign) NSUInteger calorie;

/// 深度睡眠时间(单位：分钟)
@property(nonatomic, assign) NSUInteger deepSleepInMinutes;

/// 浅度睡眠时间(单位：分钟)
@property(nonatomic, assign) NSUInteger lightSleepInMinutes;

/// 平均心率(次/分钟)
@property(nonatomic, assign) NSUInteger avgBPM;

/// 尚未保存的步数
@property(nonatomic, assign) UInt16 bufSteps;

/// 尚未保存的距离(单位：米)
@property(nonatomic, assign) UInt16 bufDistance;

/// 尚未保存的卡路里数据(单位：小卡)
@property(nonatomic, assign) UInt16 bufCalorie;

/// 运动时长(单位：分钟)
@property(nonatomic, assign) UInt16 durationInMinutes;

@end
