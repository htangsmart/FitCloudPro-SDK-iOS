//
//  FitCloudHealthSportsObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/30.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudSecureCoding.h>
#import <FitCloudKit/FitCloudWorkoutSummaryDataModel.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 手表手动同步对象基类

/// 手表手动同步对象基类
@interface FitCloudManualSyncItemObject : NSObject

/// 采样时刻
@property(nonatomic, strong) NSDate *moment;

/// 是否为手表手动测量
@property(nonatomic, assign) BOOL manualAtWatch;

/// 是否为真血压
@property(nonatomic, assign) BOOL baseOnPneumaticpump;

@end

/// 手表手动同步记录对象基类
@interface FitCloudManualSyncRecordObject<__covariant ObjectType> : NSObject

/// 开始时间
@property(nonatomic, strong) NSDate *begin;

/// 采样时间
/// - Note: 单位：秒
@property(nonatomic, assign) NSTimeInterval interval;

/// 详细条目
@property(nonatomic, strong) NSArray<ObjectType> *items;

@end

#pragma mark - 计步

/// 手表计步数据条目
@interface FitCloudStepItemObject : FitCloudManualSyncItemObject

/// 步数
@property(nonatomic, assign) UInt16 steps;

/// 距离
/// - Note: 单位 (cm)，该字段只有当距离&卡路里新算法时有效
@property(nonatomic, strong, nullable) NSNumber* distance;

/// 卡路里
/// - Note: 单位 (小卡 cal)，该字段只有当距离&卡路里新算法时有效
@property(nonatomic, strong, nullable) NSNumber* calorie;

/// 运动时长
/// - Note: 单位：分钟，该字段仅部分设备有效
/// # See Also
/// ``shouldStepItemWithDuration``
@property(nonatomic, strong, nullable) NSNumber* duration;

@end

/// 手表计步数据记录
@interface FitCloudStepRecordObject : FitCloudManualSyncRecordObject <FitCloudStepItemObject *>

@end

#pragma mark - 睡眠

/// 手表睡眠数据条目
@interface FitCloudSleepItemObject : FitCloudManualSyncItemObject

/// 睡眠质量
@property(nonatomic, assign) FITCLOUDSLEEPQUALITY quality;

@end

/// 手表睡眠数据记录
@interface FitCloudSleepRecordObject : FitCloudManualSyncRecordObject <FitCloudSleepItemObject *>

@end

#pragma mark - 心率

/// 手表心率 (Heart Rate) 数据条目
@interface FitCloudHRItemObject : FitCloudManualSyncItemObject

/// 心率值
/// - Note: 单位：次/分钟
@property(nonatomic, assign) UInt8 value;

@end

/// 手表心率 (Heart Rate) 数据记录
@interface FitCloudHRRecordObject : FitCloudManualSyncRecordObject <FitCloudHRItemObject *>

@end

#pragma mark - 血压

/// 手表血压 (Blood Pressure) 数据条目
@interface FitCloudBPItemObject : FitCloudManualSyncItemObject

/// 舒张压
@property(nonatomic, assign) UInt8 diastolic;

/// 收缩压
@property(nonatomic, assign) UInt8 systolic;

/// 心率，如果是真血压
@property(nonatomic, assign) UInt8 heartRateIfBaseOnPneumaticpump;

@end

/// 手表血压 (Blood Pressure) 数据记录
@interface FitCloudBPRecordObject : FitCloudManualSyncRecordObject <FitCloudBPItemObject *>

@end

#pragma mark - 血氧

/// 手表血氧 (Blood Oxygen) 数据条目
@interface FitCloudBOItemObject : FitCloudManualSyncItemObject

/// 血氧值
@property(nonatomic, assign) UInt8 value;

@end

/// 手表血氧 (Blood Oxygen) 数据记录
@interface FitCloudBORecordObject : FitCloudManualSyncRecordObject <FitCloudBOItemObject *>

@end

#pragma mark - 心电

/// 手表心电数据条目
@interface FitCloudECGItemObject : FitCloudManualSyncItemObject

/// 心电值
@property(nonatomic, assign) UInt16 value;

@end

/// 手表心电数据记录
@interface FitCloudECGRecordObject : FitCloudManualSyncRecordObject <FitCloudECGItemObject *>

@end

#pragma mark - 呼吸频率

/// 手表呼吸频率 (Respiratory Rate) 数据条目
@interface FitCloudBRItemObject : FitCloudManualSyncItemObject

/// 呼吸频率
@property(nonatomic, assign) UInt8 value;

@end

/// 手表呼吸频率 (Respiratory Rate) 数据记录
@interface FitCloudBRRecordObject : FitCloudManualSyncRecordObject <FitCloudBRItemObject *>

@end

#pragma mark - 体温

/// 手表体温 (Body Temperature) 数据条目
@interface FitCloudBTItemObject : FitCloudManualSyncItemObject

/// 腕温
/// - Note: 单位：摄氏度
@property(nonatomic, assign) CGFloat wrist;

/// 体温
/// - Note: 单位：摄氏度
@property(nonatomic, assign) CGFloat body;

@end

/// 手表体温 (Body Temperature) 数据记录
@interface FitCloudBTRecordObject : FitCloudManualSyncRecordObject <FitCloudBTItemObject *>

@end

#pragma mark - 压力

/// 压力指数 (Stress Index) 数据条目
@interface FitCloudStressIndexItemObject : FitCloudManualSyncItemObject

/// 压力指数
@property(nonatomic, assign) UInt8 stressIndex;

@end

/// 手表压力指数 (Stress Index) 数据记录
@interface FitCloudStressIndexRecordObject : FitCloudManualSyncRecordObject <FitCloudStressIndexItemObject *>

@end

#pragma mark - 游戏记录

/// 游戏记录数据条目
@interface FitCloudGameItemObject : FitCloudManualSyncItemObject

/// 游戏类型
@property(nonatomic, assign) FITCLOUDGAME category;

/// 游戏开始时间
@property(nonatomic, strong) NSDate *begin;

/// 游戏持续时长
/// - Note: 单位：s
@property(nonatomic, assign) NSInteger duration;

/// 游戏分数
@property(nonatomic, assign) NSInteger score;

/// 等级关卡
@property(nonatomic, assign) NSInteger level;

@end

/// 游戏记录数据
@interface FitCloudGameRecordObject : FitCloudManualSyncRecordObject <FitCloudGameItemObject *>

@end

#pragma mark - 情绪

@interface FitCloudEmotionItemObject: FitCloudManualSyncItemObject

/// 情绪值：0～255
/// [0, 40) 不愉悦，[40, 70) 平静，[70, 100] 愉悦
@property(nonatomic, assign) UInt8 value;

@end

@interface FitCloudEmotionRecordObject: FitCloudManualSyncRecordObject <FitCloudEmotionItemObject *>


@end

#pragma mark - Workout

/// A class representing workout data items from the watch's sports mode
@interface FitCloudSportsItemObject : FitCloudManualSyncItemObject

/// The type of workout being performed
@property(nonatomic, assign) UInt16 workoutType;

/// Duration of the workout
/// - Note: Unit: seconds
@property(nonatomic, assign) UInt16 duration;

/// Number of steps taken during the workout
@property(nonatomic, assign) UInt16 steps;

/// Distance covered during the workout
/// - Note: Unit: meters
@property(nonatomic, assign) UInt16 distance;

/// Calories burned during the workout
/// - Note: Unit: small calories
@property(nonatomic, assign) UInt16 calorie;

/// Workout pace
/// - Note: Unit: minutes per kilometer
@property(nonatomic, assign) UInt16 pace;

/// Swimming stroke style
/// - Note: 1: Freestyle, 2: Breaststroke, 3: Backstroke, 4: Butterfly
@property(nonatomic, strong, nullable) NSNumber *swimStyle;

/// Number of swimming laps completed
@property(nonatomic, strong, nullable) NSNumber *swimLaps;

/// Number of swimming strokes
@property(nonatomic, strong, nullable) NSNumber *swimStrokes;

/// Swimming stroke frequency
@property(nonatomic, strong, nullable) NSNumber *swimStrokeFreq;

/// Swimming efficiency (SWOLF score)
@property(nonatomic, strong, nullable) NSNumber *swolf;

/// Jump rope trigger count
@property(nonatomic, strong, nullable) NSNumber *jumpRopeTriggerCount;

/// Jump rope break count
@property(nonatomic, strong, nullable) NSNumber *jumpRopeBreakCount;

/// Jump rope consecutive count
@property(nonatomic, strong, nullable) NSNumber *jumpRopeConsecutiveCount;

/// Elliptical trainer trigger count
@property(nonatomic, strong, nullable) NSNumber *ellipticalTrainerTriggerCount;

/// Elliptical trainer triggers per minute
@property(nonatomic, strong, nullable) NSNumber *ellipticalTrainerTriggersPerMinute;

/// Maximum elliptical trainer triggers per minute
@property(nonatomic, strong, nullable) NSNumber *maxEllipticalTrainerTriggersPerMinute;

/// Minimum elliptical trainer triggers per minute
@property(nonatomic, strong, nullable) NSNumber *minEllipticalTrainerTriggersPerMinute;

/// Rowing machine trigger count
@property(nonatomic, strong, nullable) NSNumber *rowingMachingTriggerCount;

/// Rowing machine triggers per minute
@property(nonatomic, strong, nullable) NSNumber *rowingMachingTriggersPerMinute;

/// Maximum rowing machine triggers per minute
@property(nonatomic, strong, nullable) NSNumber *maxRowingMachingTriggersPerMinute;

/// Minimum rowing machine triggers per minute
@property(nonatomic, strong, nullable) NSNumber *minRowingMachingTriggersPerMinute;

@end

/// Heart rate data model
@interface FitCloudBPMDataModel : NSObject

/// Sampling moment
@property(nonatomic, strong) NSDate *moment;

/// Heart rate value
/// - Note: Unit: beats/min
/// - Important: Returns nil when invalid
@property(nonatomic, strong, nullable) NSNumber *value;

@end

/// A class representing sports record data from the watch's sports mode
@interface FitCloudSportsRecordObject : FitCloudManualSyncRecordObject <FitCloudSportsItemObject *>

/// The type of workout being performed
@property(nonatomic, readonly, nullable) NSNumber *workoutType;

/// The associated GPS data key for independent GPS sports tracking on the watch
/// - Note: This key links to corresponding GPS data records
@property(nonatomic, strong, nullable) NSString *gpsDataAssociateKey;

/// Configuration string for display data when watch supports independent GPS sports
/// - Note: if want to display `WORKOUTDATAITEMDISPLAY_DURATION` and `WORKOUTDATAITEMDISPLAY_AVG_BPM`, the displayConfig string should be `"1,2"`, and so on.
@property(nonatomic, strong, nullable) NSString *displayConfig;

/// Array of heart rate data models collected during sports activity
/// - Note: Contains timestamped BPM readings throughout the workout
@property(nonatomic, strong, nullable) NSArray<FitCloudBPMDataModel *> *bpmDataArray;


/// An array of workout summary data models that were calculated on the watch device
/// - Note: This property contains workout summary statistics that were computed directly on the watch,
///         rather than being calculated on the phone
@property(nonatomic, strong, nullable) NSArray<FitCloudWorkoutSummaryDataModel*> * workoutSummaryDataCalculatedOnWatch;

@end

#pragma mark - GPS Data

/// A class representing GPS data items from the watch's sports mode
@interface FitCloudGPSItemObject : FitCloudManualSyncItemObject

/// The longitude coordinate
@property(nonatomic, assign) CGFloat longitude;

/// The latitude coordinate
@property(nonatomic, assign) CGFloat latitude;

/// The altitude measurement
/// - Note: Unit: meters
@property(nonatomic, assign) UInt16 altitude;

/// Number of satellites detected
/// - Note: Unit: count
@property(nonatomic, assign) UInt8 satellitesCount;

/// Indicates if this point is the start of a segment
@property(nonatomic, assign) BOOL isStartingPoint;

@end

/// A class representing GPS data records from the watch's sports mode
@interface FitCloudGPSRecordObject : FitCloudManualSyncRecordObject <FitCloudGPSItemObject *>

/// The unique key for independent GPS workout tracking
@property(nonatomic, strong) NSString *gpsDataKey;

@end

#pragma mark - 健康实时测量

/// 实时健康测量项定义 / Real-time health measurement items definition
typedef NS_OPTIONS(UInt16, FITCLOUDREALTIMEMHEALTHEASUREITEM) {
    /// 无 / None
    FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE = 0,
    
    /// 心率 / Heart rate
    FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE = 1,
    
    /// 血氧 / Blood oxygen
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODOXYGEN = 1 << 1,
    
    /// 血压 / Blood pressure
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE = 1 << 2,
    
    /// 呼吸频率 / Respiratory rate
    FITCLOUDREALTIMEMHEALTHEASUREITEM_RESPIRATORYRATE = 1 << 3,
    
    /// 心电 / ECG
    FITCLOUDREALTIMEMHEALTHEASUREITEM_ECG = 1 << 4,
    
    /// 体温 / Body temperature
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BODYTEMPERATURE = 1 << 5,
    
    /// 压力指数 / Stress index
    FITCLOUDREALTIMEMHEALTHEASUREITEM_STRESSINDEX = 1 << 6,
};

/// Real-time health measurement parameters / 实时健康测量参数
@interface FitCloudRealTimeHealthMeasuringParam : NSObject <FitCloudSecureCoding>

/// Measurement item / 测量项
@property(nonatomic, assign) FITCLOUDREALTIMEMHEALTHEASUREITEM item;

/// Real-time measurement interval / 实时测量时间间隔
/// - Note: Unit: seconds / 单位：秒
@property(nonatomic, assign) UInt8 interval;

/// Maximum duration limit for a single real-time measurement / 单次实时测量最长时间限制
/// - Note: Unit: minutes / 单位：分钟
@property(nonatomic, assign) UInt8 maxMeasuringMinutes;

@end

/// Real-time health measuring result data model (实时健康测量返回的数据模型)
@interface FitCloudRealTimeHealthMeasuringResultObject : NSObject

/// Sampling moment (采样时刻)
@property(nonatomic, strong) NSDate *moment;

/// Heart rate (心率)
@property(nonatomic, assign) UInt8 heartRate;

/// Blood oxygen (血氧)
@property(nonatomic, assign) UInt8 bloodOxygen;

/// Diastolic pressure (舒张压)
@property(nonatomic, assign) UInt8 diastolic;

/// Systolic pressure (收缩压)
@property(nonatomic, assign) UInt8 systolic;

/// Respiratory rate (呼吸频率)
@property(nonatomic, assign) UInt8 respiratoryRate;

/// Body temperature measurement status (体温测量状态)
/// - Note: 0: Normal status, data is being returned normally; (正常状态，数据正常返回中)
///         1: Measurement end, normal end time reached; (测量结束，正常结束时间到达)
///         2: Measurement end, watch not worn; (测量结束，未佩戴手表)
///         3: Measurement end, body temperature too high; (测量结束，体温过高)
///         4: Measurement end, body temperature too low; (测量结束，体温过低)
@property(nonatomic, assign) UInt8 temperatureFlag;

/// Wrist temperature (腕温)
/// - Note: Unit: Celsius degrees (摄氏度)
@property(nonatomic, assign) CGFloat wrist;

/// Body temperature (体温)
/// - Note: Unit: Celsius degrees (摄氏度)
@property(nonatomic, assign) CGFloat body;

/// Stress index (压力指数)
/// - Note: Valid when watch supports stress index measurement (当手表支持压力指数测量时有效)
@property(nonatomic, assign) UInt8 stressIndex;

@end

#pragma mark - 每日运动健康数据

/// 每日运动健康数据 / Daily health & sports data
@interface FitCloudDailyHealthAndSportsDataObject : NSObject <FitCloudSecureCoding>

/// 累计步数 / Total steps
@property(nonatomic, assign) NSUInteger steps;

/// 距离 (单位：米) / Distance (unit: meters)
@property(nonatomic, assign) NSUInteger distance;

/// 卡路里 (单位：小卡) / Calories (unit: small calories)
@property(nonatomic, assign) NSUInteger calorie;

/// 深度睡眠时间 (单位：分钟) / Deep-sleep duration (unit: minutes)
@property(nonatomic, assign) NSUInteger deepSleepInMinutes;

/// 浅度睡眠时间 (单位：分钟) / Light-sleep duration (unit: minutes)
@property(nonatomic, assign) NSUInteger lightSleepInMinutes;

/// 平均心率 (次/分钟) / Average heart rate (beats/min)
@property(nonatomic, assign) NSUInteger avgBPM;

/// 尚未保存的步数 / Unsaved steps
@property(nonatomic, assign) UInt16 bufSteps;

/// 尚未保存的距离 (单位：米) / Unsaved distance (unit: meters)
@property(nonatomic, assign) UInt16 bufDistance;

/// 尚未保存的卡路里数据 (单位：小卡) / Unsaved calorie data (unit: small calories)
@property(nonatomic, assign) UInt16 bufCalorie;

/// 运动时长 (单位：分钟) / Exercise duration (unit: minutes)
@property(nonatomic, assign) UInt16 durationInMinutes;

@end

NS_ASSUME_NONNULL_END
