

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthQABody : NSObject

/// 百度设备id
@property (nonatomic, strong) NSString *deviceId;

/// 用户提问
@property (nonatomic, strong) NSString *query;

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

@end

NS_ASSUME_NONNULL_END
