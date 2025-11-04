

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AIMusicRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 提示语
@property (nonatomic, strong) NSString *content;

@end

NS_ASSUME_NONNULL_END

