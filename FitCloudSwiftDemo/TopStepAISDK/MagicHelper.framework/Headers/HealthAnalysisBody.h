

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MHHealthData;
@class MHRunningData;

/// 分析类型
typedef NSString * MHAnalyseType NS_STRING_ENUM;
FOUNDATION_EXPORT MHAnalyseType const MHAnalyseRunningEvaluation;
FOUNDATION_EXPORT MHAnalyseType const MHAnalyseRunningHistoryAnalyse;

@interface HealthAnalysisBody : NSObject

/// 百度设备id
@property (nonatomic, strong) NSString *deviceId;

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 分析类型
@property (nonatomic, strong) MHAnalyseType analyseType;

/// 数据
@property (nonatomic, strong) MHHealthData *data;

@end

@interface MHHealthData : NSObject

@property (nonatomic, strong) NSArray<MHRunningData *> *runningDatas;

@end

@interface MHRunningData : NSObject

/// 距离 公里
@property (nonatomic, strong) NSString *distance;

/// 速度 km/h
@property (nonatomic, strong) NSString *speed;

/// 步数
@property (nonatomic, strong) NSString *steps;

/// 最大心率
@property (nonatomic, strong) NSString *maxHeartRate;

/// 最小心率
@property (nonatomic, strong) NSString *minHeartRate;

/// 平均心率
@property (nonatomic, strong) NSString *avgHeartRate;

@end

NS_ASSUME_NONNULL_END
