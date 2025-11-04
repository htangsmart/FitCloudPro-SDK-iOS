

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MGAudioEncodingFormat) {
    MGAudioEncodingFormatPCM,   // PCM
    MGAudioEncodingFormatMP3,   // MP3
    MGAudioEncodingFormatM4A,    // M4A
};

@interface MGPCMAudioFormat : NSObject

@property (nonatomic, assign, readonly) NSInteger sampleRate;
@property (nonatomic, assign, readonly) NSInteger bitDepth;
@property (nonatomic, assign, readonly) NSInteger channels;

+ (instancetype)formatWithSampleRate:(NSUInteger)sampleRate
                            bitDepth:(NSUInteger)bitDepth
                                 channelCount:(NSUInteger)channelCount;

@end

@interface ASRIntlRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 任务id,上一流程返回的tid，没有就不传
@property (nonatomic, strong, nullable) NSString *tid;

/// 语种 支持的语种见文档
@property (nonatomic, strong) NSString *language;

/// 超时时间（单位：秒， 默认0.2s, 该值<=0 则认为不需要超时）
/// 这个逻辑是当SDK内部将所有数据发送成功并关闭流后timeout内未返回识别数据，则认为超时
/// 结果回调跟IntlAudioInput.sendFinish 间隔大概在 0.5s + timeout
@property (nonatomic, assign) float timeout;

/// 音频格式，默认pcm
@property (nonatomic, assign) MGAudioEncodingFormat encodingFormat;

/// 音频格式 (默认PCM 16000hz 16bit 1)(只在encodingFormat == pcm有效)
/// 支持8000hz 16000hz 24000hz
@property (nonatomic, strong) MGPCMAudioFormat *format;

@end



NS_ASSUME_NONNULL_END
