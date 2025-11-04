

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TranslateRequestBody : NSObject

/// 输入的文本
@property (nonatomic, strong) NSString *text;

/// 翻译前语言 (zh, zh-CN两个格式都可以)
@property (nonatomic, strong) NSString *from;

/// 翻译后语言
@property (nonatomic, strong) NSString *to;

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

@end

NS_ASSUME_NONNULL_END
