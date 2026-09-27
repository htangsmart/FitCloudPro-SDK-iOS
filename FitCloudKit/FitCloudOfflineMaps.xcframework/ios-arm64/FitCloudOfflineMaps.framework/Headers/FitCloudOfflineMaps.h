#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// FitCloudKit 的可选离线地图功能插件。
/// 链接此静态 Framework 并添加 `-ObjC` 后，FitCloudKit 会自动发现该插件；无需直接实例化此类。
@interface FitCloudOfflineMaps : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
