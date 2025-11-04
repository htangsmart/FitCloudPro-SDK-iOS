

#import <Foundation/Foundation.h>
#import "ASRIntlRequestBody.h"
#import "TTSIntlRequestBody.h"
#import "GptIntlRequestBody.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChatIntlRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 是否要对chat返回的结果进行播报, 默认NO
@property (nonatomic, assign) BOOL needTts;

/// 国际版asr业务参数
@property (nonatomic, strong) ASRIntlRequestBody *asrBody;

/// 国际版tts业务参数
@property (nonatomic, strong) TTSIntlRequestBody *ttsBody;

/// chat参数
@property (nonatomic, strong) GptIntlRequestBody *chatBody;

+ (instancetype)defaultBody;

@end

NS_ASSUME_NONNULL_END
