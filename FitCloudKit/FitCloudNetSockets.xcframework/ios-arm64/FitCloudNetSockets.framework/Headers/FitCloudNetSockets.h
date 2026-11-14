#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// Optional BLE socket proxy for FitCloudKit. Link the static framework with -ObjC.
/// Uses the dedicated net_sockets_service; does not intercept WPAuth or Aliot data.
/// FitCloudKit automatically manages the plugin when a supported watch connects
/// or disconnects. Apps do not need to instantiate or call this class.
@interface FitCloudNetSockets : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end
NS_ASSUME_NONNULL_END
