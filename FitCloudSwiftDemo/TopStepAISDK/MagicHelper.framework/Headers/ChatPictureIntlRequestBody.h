

#import <Foundation/Foundation.h>
#import "ASRIntlRequestBody.h"
#import "TTSIntlRequestBody.h"
#import "ChatPictureRequestBody.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChatPictureIntlRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

///请求tid，上一步返回的tid，有就带上，没有就不传
@property (nonatomic ,strong) NSString *tid;

/// 国际版asr业务参数
@property (nonatomic, strong) ASRIntlRequestBody *asrBody;

/// AI Image参数
@property (nonatomic, strong) ChatPictureRequestBody *aigcBody;

/// 是否需要确认文本，默认NO
/// 该字段的逻辑是当语音识别结束后，会返回识别文本，如果调用方需要对这个文本内容进行修改则设置confirmText = YES
/// sdk会等待调用aigcContinueWithQid才会去生成图片
@property (nonatomic, assign) BOOL confirmText;


/// 默认参数
+ (instancetype)defaultBody;

@end

NS_ASSUME_NONNULL_END
