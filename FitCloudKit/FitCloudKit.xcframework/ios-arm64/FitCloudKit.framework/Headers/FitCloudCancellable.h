#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A cancellable SDK operation. Releasing the handle does not cancel the operation.
@protocol FitCloudCancellable <NSObject>
/// Cancel the operation. Safe to call repeatedly or from any thread.
- (void)cancel;
@end

NS_ASSUME_NONNULL_END
