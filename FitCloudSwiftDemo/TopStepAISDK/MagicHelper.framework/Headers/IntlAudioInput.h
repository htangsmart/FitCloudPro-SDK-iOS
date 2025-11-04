


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IntlAudioInput : NSObject

/// 请求id，跟ASRIntlRequestBody.qid相对应
@property (nonatomic, strong, readonly) NSString *qid;

/// 传输音频数据
- (void)sendAudioData:(NSData *)data;

/// 录音结束调用
- (void)sendFinish;

@end

NS_ASSUME_NONNULL_END
