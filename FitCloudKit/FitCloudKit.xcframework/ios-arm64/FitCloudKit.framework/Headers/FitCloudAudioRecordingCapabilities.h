#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

NS_ASSUME_NONNULL_BEGIN

/// 录音扩展能力与要求。所有属性均为 NO 不代表设备不支持录音。
/// 通过 FitCloudAllConfigObject 获取设备上报的只读快照。
@interface FitCloudAudioRecordingCapabilities : NSObject <FitCloudSecureCoding>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 支持录音暂停与恢复。
@property(nonatomic, readonly) BOOL supportsPauseResume;

/// 录音业务需要 ASR 文本；不表示设备具备语音识别能力。
/// 文本的生成、传输时机及使用方式应遵循对应录音业务协议。
@property(nonatomic, readonly) BOOL requiresASRText;

@end

NS_ASSUME_NONNULL_END
