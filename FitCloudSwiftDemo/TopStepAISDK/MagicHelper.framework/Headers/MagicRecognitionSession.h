//
//  MagicSpeechSession.h
//  MagicHelper
//
//  Created by ymz on 2025/7/16.
//

#import <Foundation/Foundation.h>
#import "MagicSmartOptionModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MagicAudioType) {
    MagicAudioTypePcm,
    MagicAudioTypeOpus
};

@protocol MagicRecognitionSessionDelegate<NSObject>

@optional
/// 意图理解回调
- (void)onIntentionAction:(NSString *)type params:(NSDictionary *)params;

/// 文本回调
- (void)onMessage:(NSDictionary *)message;
/// 文本回调结束
- (void)onMessageFinished:(NSDictionary *)message;

/// 音频数据回调
- (void)onAudioData:(NSData *)audioData;
/// 音频数据回调结束
- (void)onAudioDataFinished:(NSDictionary *)message;

/// VAD识别结束（检测到用户停止说话，建议停止发送音频）
- (void)onVADCompleted;

/// webSocket开启回调
- (void)onOpen;
/// WebSocket关闭回调
- (void)onClosed:(NSString *)reason;
/// WebSocket错误回调
- (void) onFailure:(NSString *)reason;

@end



@interface MagicRecognitionSession : NSObject

@property (nonatomic, weak) id<MagicRecognitionSessionDelegate> delegate;

/// websocket是否连接
@property (nonatomic, assign, readonly) BOOL isConnected;

/// 默认1s
@property (nonatomic, assign) NSTimeInterval vadTimeout;

/// 获取支持的configCode
- (NSArray *)getSmartConfigModels;

/// 创建会话
- (void)createSession:(nullable NSDictionary *)ext  __attribute__((deprecated("请使用 createSessionWithConfigCode:ext 替代")));

/// 创建会话
/// configCode: 控制模型，不设置使用默认的，可通过getSmartConfigModels获取
/// online_search_bailian： 带意图版本
/// online_search_bailian_no_intent：不带意图
/// ext: "{\"extKey\":\"extValue\"}" // Session级别扩展字段
- (void)createSessionWithConfigCode:(nullable NSString *)configCode ext:(nullable NSDictionary *)ext  __attribute__((deprecated("请使用 createSessionWithConfigCode:model:ext 替代")));

/// 创建会话
- (void)createSessionWithConfigCode:(nullable NSString *)configCode model:(nullable MagicSmartOptionModel *)model ext:(nullable NSDictionary *)ext;

/// 开始语音对话
- (void)startSpeech:(MagicAudioType)type;

/// 发送音频数据
- (void)sendSpeechAudioData:(NSData *)data;

/// 发送结束帧
- (void)endSpeech;

/// 中断对话
- (void)closeSpeech;

/// 关闭整个会话（WebSocket）
- (void)stopSession;

/// 主动发起图片识图/翻译等文本任务
/// type: 拍照识图、翻译(visual_qa)
/// params : {
///"prompt": "这是什么植物？",
///"images": [
///           {"type":"base64","value":"${image base64}"}
///           ]
///}
///注意： 图片要小于5M
- (void)requestToRespondWithType:(NSString *)intentType
                          params:(NSDictionary *)params;


/// 开始多模态图文输入流程（图文传输起始点）
/// 调用顺序：startMultimodalQAIput -> requestToRespondWithType -> startSpeech -> endSpeech -> commitMultimodalQAIput
- (void)startMultimodalQAIput;

/// 提交多模态图文输入（结束图文传输流程）
- (void)commitMultimodalQAIput;

/// 获取configcode列表
- (NSArray *)queryConfigCodeList;
@end

NS_ASSUME_NONNULL_END

