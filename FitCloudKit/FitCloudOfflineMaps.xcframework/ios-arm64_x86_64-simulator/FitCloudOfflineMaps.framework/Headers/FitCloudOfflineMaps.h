#import <Foundation/Foundation.h>
#import <FitCloudOfflineMaps/FitCloudOfflineMapsErrors.h>

NS_ASSUME_NONNULL_BEGIN

/// Optional networking plugin discovered automatically by FitCloudKit.
/// Link this static framework with -ObjC and call FitCloudKit's offline maps download API.
@interface FitCloudOfflineMaps : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
