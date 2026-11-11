#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
/// PCM is 16 kHz mono signed Int16 little-endian. Completion may use any queue.
/// Return equal-length processed PCM, or nil to use the original recording.
/// Called off the Bluetooth/session queue. A timeout falls back to the original.
typedef void (^FitCloudWhatsAppAudioProcessor)(NSData *PCM, BOOL forTranscription,
    void (^completion)(NSData * _Nullable processedPCM));
/// FitCloudKit 的可选 WhatsApp 功能插件。
/// 链接此静态 Framework 并添加 `-ObjC` 后，FitCloudKit 会自动发现该插件；无需直接实例化此类。
@interface FitCloudWhatsApp : NSObject
/// BCP-47 App language (e.g. zh-Hans, zh-Hant, en). nil follows preferred languages.
+ (void)setAppLanguage:(nullable NSString *)language;
/// Call in the foreground to prepare system Speech permission; completion runs off main.
+ (void)requestSpeechAuthorizationWithCompletion:(void (^)(BOOL authorized))completion;
/// Optional processing before voice sending or transcription. nil disables it.
+ (void)setAudioProcessor:(nullable FitCloudWhatsAppAudioProcessor)processor;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end
NS_ASSUME_NONNULL_END
