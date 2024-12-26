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
/// - Note: 单位(cm)，该字段只有当距离&卡路里新算法时有效
@property(nonatomic, assign) UInt16 distance;

/// 卡路里
/// - Note: 单位(小卡 cal)，该字段只有当距离&卡路里新算法时有效
@property(nonatomic, assign) UInt16 calory;

/// 运动时长
/// - Note: 单位：分钟，该字段仅部分设备有效
/// # See Also
/// ``shouldStepItemWithDuration``
@property(nonatomic, assign) UInt16 duration;

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

/// 手表心率(Heart Rate)数据条目
@interface FitCloudHRItemObject : FitCloudManualSyncItemObject

/// 心率值
/// - Note: 单位：次/分钟
@property(nonatomic, assign) UInt8 value;

@end

/// 手表心率(Heart Rate)数据记录
@interface FitCloudHRRecordObject : FitCloudManualSyncRecordObject <FitCloudHRItemObject *>

@end

#pragma mark - 血压

/// 手表血压(Blood Pressure)数据条目
@interface FitCloudBPItemObject : FitCloudManualSyncItemObject

/// 舒张压
@property(nonatomic, assign) UInt8 diastolic;

/// 收缩压
@property(nonatomic, assign) UInt8 systolic;

/// 心率，如果是真血压
@property(nonatomic, assign) UInt8 heartRateIfBaseOnPneumaticpump;

@end

/// 手表血压(Blood Pressure)数据记录
@interface FitCloudBPRecordObject : FitCloudManualSyncRecordObject <FitCloudBPItemObject *>

@end

#pragma mark - 血氧

/// 手表血氧(Blood Oxygen)数据条目
@interface FitCloudBOItemObject : FitCloudManualSyncItemObject

/// 血氧值
@property(nonatomic, assign) UInt8 value;

@end

/// 手表血氧(Blood Oxygen)数据记录
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

/// 手表呼吸频率(Breathe Rate)数据条目
@interface FitCloudBRItemObject : FitCloudManualSyncItemObject

/// 呼吸频率
@property(nonatomic, assign) UInt8 value;

@end

/// 手表呼吸频率(Breathe Rate)数据记录
@interface FitCloudBRRecordObject : FitCloudManualSyncRecordObject <FitCloudBRItemObject *>

@end

#pragma mark - 体温

/// 手表体温(Body Temperature)数据条目
@interface FitCloudBTItemObject : FitCloudManualSyncItemObject

/// 腕温
/// - Note: 单位：摄氏度
@property(nonatomic, assign) CGFloat wrist;

/// 体温
/// - Note: 单位：摄氏度
@property(nonatomic, assign) CGFloat body;

@end

/// 手表体温(Body Temperature)数据记录
@interface FitCloudBTRecordObject : FitCloudManualSyncRecordObject <FitCloudBTItemObject *>

@end

#pragma mark - 压力

/// 压力指数(Stress Index)数据条目
@interface FitCloudStressIndexItemObject : FitCloudManualSyncItemObject

/// 压力指数
@property(nonatomic, assign) UInt8 stressIndex;

@end

/// 手表压力指数(Stress Index)数据记录
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

#pragma mark - 运动模式

/// 手表运动模式运动数据条目
@interface FitCloudSportsItemObject : FitCloudManualSyncItemObject

/// 运动类型
@property(nonatomic, assign) UInt16 workoutType;

/// 运动时长
/// - Note: 单位：秒
@property(nonatomic, assign) UInt16 duration;

/// 步数
@property(nonatomic, assign) UInt16 steps;

/// 距离
/// - Note: 单位：米
@property(nonatomic, assign) UInt16 distance;

/// 卡路里
/// - Note: 单位：小卡
@property(nonatomic, assign) UInt16 calorie;

/// 配速
/// - Note: 单位：min/km
@property(nonatomic, assign) UInt16 pace;

/// 泳姿
/// - Note: 1: 自由泳 2:蛙泳 3:仰泳 4:蝶泳
@property(nonatomic, strong, nullable) NSNumber *swimStyle;

/// 游泳趟数
@property(nonatomic, strong, nullable) NSNumber *swimLaps;

/// 游泳划水次数
@property(nonatomic, strong, nullable) NSNumber *swimStrokes;

/// 游泳划水频率
@property(nonatomic, strong, nullable) NSNumber *swimStrokeFreq;

/// 游泳效率
@property(nonatomic, strong, nullable) NSNumber *swolf;

/// 跳绳-触发次数
@property(nonatomic, strong, nullable) NSNumber *jumpRopeTriggerCount;

/// 跳绳-中断次数
@property(nonatomic, strong, nullable) NSNumber *jumpRopeBreakCount;

/// 跳绳-连续次数
@property(nonatomic, strong, nullable) NSNumber *jumpRopeConsecutiveCount;

/// 椭圆机-触发次数
@property(nonatomic, strong, nullable) NSNumber *ellipticalTrainerTriggerCount;

/// 椭圆机-触发频率
@property(nonatomic, strong, nullable) NSNumber *ellipticalTrainerTriggersPerMinute;

/// 椭圆机-最大触发频率
@property(nonatomic, strong, nullable) NSNumber *maxEllipticalTrainerTriggersPerMinute;

/// 椭圆机-最小触发频率
@property(nonatomic, strong, nullable) NSNumber *minEllipticalTrainerTriggersPerMinute;

/// 划船机-触发次数
@property(nonatomic, strong, nullable) NSNumber *rowingMachingTriggerCount;

/// 划船机-触发频率
@property(nonatomic, strong, nullable) NSNumber *rowingMachingTriggersPerMinute;

/// 划船机-最大触发频率
@property(nonatomic, strong, nullable) NSNumber *maxRowingMachingTriggersPerMinute;

/// 划船机-最小触发频率
@property(nonatomic, strong, nullable) NSNumber *minRowingMachingTriggersPerMinute;

@end

/// 心率数据模型
@interface FitCloudBPMDataModel : NSObject

/// 采样时刻
@property(nonatomic, strong) NSDate *moment;

/// 心率
/// - Note: 单位：次/min
/// - Important: Returns nil when invalid
@property(nonatomic, strong, nullable) NSNumber *value;

@end

/// 手表运动模式运动数据记录
@interface FitCloudSportsRecordObject : FitCloudManualSyncRecordObject <FitCloudSportsItemObject *>

/// 手表独立GPS运动，该字段关联对应的GPS数据
@property(nonatomic, strong, nullable) NSString *gpsDataAssociateKey;

/// 当手表支持独立GPS运动且支持指定展示数据是表示展示数据信息
/// - Note: if want to display `WORKOUTDATAITEMDISPLAY_DURATION` and `WORKOUTDATAITEMDISPLAY_AVG_BPM`, the displayConfig string should be `"1,2"`, and so on.
@property(nonatomic, strong, nullable) NSString *displayConfig;

/// 运动心率数据
@property(nonatomic, strong, nullable) NSArray<FitCloudBPMDataModel *> *bpmDataArray;

@end

#pragma mark - GPS数据

/// 手表运动模式运动GPS数据条目
@interface FitCloudGPSItemObject : FitCloudManualSyncItemObject

/// 经度
@property(nonatomic, assign) CGFloat longitude;

/// 纬度
@property(nonatomic, assign) CGFloat latitude;

/// 海拔
/// - Note: 单位：m
@property(nonatomic, assign) UInt16 altitude;

/// 卫星数量
/// - Note: 单位：个数
@property(nonatomic, assign) UInt8 satellitesCount;

/// 是否为一段的起点
@property(nonatomic, assign) BOOL isStartingPoint;

@end

/// 手表运动模式运动GPS数据记录
@interface FitCloudGPSRecordObject : FitCloudManualSyncRecordObject <FitCloudGPSItemObject *>

/// 手表独立GPS运动Key
@property(nonatomic, strong) NSString *gpsDataKey;

@end

#pragma mark - 健康实时测量

/// 实时健康测量项定义
typedef NS_OPTIONS(UInt16, FITCLOUDREALTIMEMHEALTHEASUREITEM) {
    FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE = 0,                 // 无
    FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE = 1,            // 心率
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODOXYGEN = 1 << 1,     // 血氧
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE = 1 << 2,   // 血压
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BREATHERATE = 1 << 3,     // 呼吸频率
    FITCLOUDREALTIMEMHEALTHEASUREITEM_ECG = 1 << 4,             // 心电
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BODYTEMPERATURE = 1 << 5, // 体温
    FITCLOUDREALTIMEMHEALTHEASUREITEM_STRESSINDEX = 1 << 6,     // 压力指数
};

/// 实时健康测量参数
@interface FitCloudRealTimeHealthMeasuringParam : NSObject <NSCoding>

/// 测量项
@property(nonatomic, assign) FITCLOUDREALTIMEMHEALTHEASUREITEM item;

/// 实时测量时间间隔
/// - Note: 单位：秒
@property(nonatomic, assign) UInt8 interval;

/// 单次实时测量最长时间限制
/// - Note: 单位：分钟
@property(nonatomic, assign) UInt8 maxMeasuringMinutes;

@end

/// 实时健康测量返回的数据
@interface FitCloudRealTimeHealthMeasuringResultObject : NSObject

/// 采样时刻
@property(nonatomic, strong) NSDate *moment;

/// 心率
@property(nonatomic, assign) UInt8 heartRate;

/// 血氧
@property(nonatomic, assign) UInt8 bloodOxygen;

/// 舒张压
@property(nonatomic, assign) UInt8 diastolic;

/// 收缩压
@property(nonatomic, assign) UInt8 systolic;

/// 呼吸频率
@property(nonatomic, assign) UInt8 breatheRate;

/// 体温测量状态
/// - Note: 0:正常状态，数据正常返回中； 1:测量结束，正常结束时间结束； 2:测量结束，未佩戴手表；3:测量结束，体温过高；4:测量结束，体温过低；
@property(nonatomic, assign) UInt8 temperatureFlag;

/// 腕温
/// - Note: 单位：摄氏度
@property(nonatomic, assign) CGFloat wrist;

/// 体温
/// - Note: 单位：摄氏度
@property(nonatomic, assign) CGFloat body;

/// 压力
/// - Note: 当手表支持压力指数时有效
@property(nonatomic, assign) UInt8 stressIndex;

@end

#pragma mark - 每日运动健康数据

/// 每日运动健康数据
@interface FitCloudDailyHealthAndSportsDataObject : NSObject <NSCoding>

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

NS_ASSUME_NONNULL_END
