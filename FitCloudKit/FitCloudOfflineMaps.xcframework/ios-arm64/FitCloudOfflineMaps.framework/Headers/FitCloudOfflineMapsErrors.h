#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Error domain for offline map operations.
FOUNDATION_EXPORT NSString *const FitCloudOfflineMapsErrorDomain;
typedef NS_ENUM(NSInteger, FitCloudOfflineMapsErrorCode) {
    /// Invalid input or unsupported map options.
    FitCloudOfflineMapsErrorInvalidParameter = 1,
    /// The download or query could not complete successfully.
    FitCloudOfflineMapsErrorNetwork,
    /// The map provider rejected the operation.
    FitCloudOfflineMapsErrorService,
    /// The returned map information or file is invalid.
    FitCloudOfflineMapsErrorInvalidResponse,
    /// Map files could not be packaged into a tar archive.
    FitCloudOfflineMapsErrorArchive,
};

NS_ASSUME_NONNULL_END
