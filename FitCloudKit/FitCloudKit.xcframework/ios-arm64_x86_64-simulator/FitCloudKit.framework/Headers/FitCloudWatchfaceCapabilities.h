#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

NS_ASSUME_NONNULL_BEGIN

/// 表盘扩展能力。所有属性均为 NO 不代表设备不支持普通表盘。
/// 通过 FitCloudAllConfigObject 获取设备上报的只读快照。
@interface FitCloudWatchfaceCapabilities : NSObject <FitCloudSecureCoding>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 支持多图表盘。
@property(nonatomic, readonly) BOOL supportsMultipleImages;

/// 支持 Danmaku 表盘。
@property(nonatomic, readonly) BOOL supportsDanmaku;

/// 支持视频表盘。
@property(nonatomic, readonly) BOOL supportsVideo;

@end

NS_ASSUME_NONNULL_END
