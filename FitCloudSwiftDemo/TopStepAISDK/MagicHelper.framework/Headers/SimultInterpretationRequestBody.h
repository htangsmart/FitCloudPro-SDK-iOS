//
//  SimultInterpretationRequestBody.h
//  MagicHelper
//
//  Created by ymz on 2025/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SimultInterpretationRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;
/// 源语言
@property (nonatomic, strong) NSString *sourceLanguage;
/// 目标语言
@property (nonatomic, strong) NSString *targetLanguage;
/// 是否需要tts，默认NO
@property (nonatomic, assign) BOOL enableTts;

/// tts配置
/// 语速百分比或关键词（范围约 -100% ~ +200%，可用 @"x-slow"、@"slow"、@"medium"、@"fast"、@"x-fast"）
/// 默认 @"0%" 表示正常语速
@property (nonatomic, strong) NSString *rate;

/// 音调百分比或关键词（范围约 -50% ~ +50%，可用 @"x-low"、@"low"、@"medium"、@"high"、@"x-high"）
/// 默认 @"0%" 表示原音调
@property (nonatomic, strong) NSString *pitch;

/// 音量百分比或关键词（范围约 0% ~ 100%，也可用 @"silent"、@"x-soft"、@"soft"、@"medium"、@"loud"、@"x-loud"）
/// 默认 @"100%" 表示原音量
@property (nonatomic, strong) NSString *volume;

@end

NS_ASSUME_NONNULL_END
