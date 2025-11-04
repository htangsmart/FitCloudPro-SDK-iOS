

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTSIntlRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 任务id,上一流程返回的tid，没有就不传
@property (nonatomic, strong, nullable) NSString *tid;

/// 文本
@property (nonatomic, strong) NSString *content;

/// content的语种，支持的语种见文档
@property (nonatomic, strong) NSString *language;

@end

NS_ASSUME_NONNULL_END
