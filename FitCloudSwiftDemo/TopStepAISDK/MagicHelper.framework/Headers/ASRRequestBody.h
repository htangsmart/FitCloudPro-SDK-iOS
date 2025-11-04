

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASRRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
/// 如果是实时语音识别，会取第一条qid返回
@property (nonatomic, strong) NSString *qid;

/// 识别模型 (默认值：1537)
/// 这里音频文件和实时语音有点区别
///
/// 音频文件:
/// 1537 : 普通话(纯中文识别)
/// 1737 : 英语
/// 1637 : 粤语
/// 1837 : 四川话
///
/// 实时语音:
/// 1537 : 普通话，弱标点符号
/// 15372: 普通话，加强标点符号
/// 1737 : 英语
/// 17372: 英语，加强标点符号
@property (nonatomic, assign) NSInteger dev_pid;

/// 音频数据
/// 音频文件识别：data是一整个音频文件数据
/// 实时语音识别：data则是一段实时音频数据
@property (nonatomic, strong) NSData *data;

/// 实时语音识别结束包
/// 停止录音后调用该方法
+ (instancetype)finishBody;

@end

NS_ASSUME_NONNULL_END
