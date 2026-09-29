//
//  FitCloudKit+UGreen.h
//  FitCloudKit
//

#ifndef FitCloudKit_UGreen_h
#define FitCloudKit_UGreen_h

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKit.h>

NS_ASSUME_NONNULL_BEGIN

/// UGREEN features.
@interface FitCloudKit (UGreen)

/// Performs a UGREEN recording action and synchronizes the App-side recording position.
/// - Parameters:
///   - action: The pause or resume action to perform.
///   - milliseconds: Current App-side recording position in milliseconds.
///   - completion: The completion handler called when the command completes.
+ (void)performUgreenRecordingAction:(FitCloudUgreenRecordingAction)action
                         milliseconds:(UInt32)milliseconds
                            completion:(FitCloudCompletionHandler _Nullable)completion;

/// Retrieves UGREEN device configuration.
/// - Parameters:
///   - completion: Called when the query completes. `config` contains the configuration returned by the device when successful; `error` describes the failure when unsuccessful.
+ (void)queryUgreenConfigWithCompletion:(void (^_Nullable)(BOOL success,
                                                            FitCloudUgreenConfig *_Nullable config,
                                                            NSError *_Nullable error))completion;

/// Updates UGREEN device configuration.
/// - Parameters:
///   - config: The complete UGREEN configuration to apply to the device.
///   - completion: The completion handler called when the command completes.
+ (void)setUgreenConfig:(FitCloudUgreenConfig *)config
             completion:(FitCloudCompletionHandler _Nullable)completion;


@end

NS_ASSUME_NONNULL_END

#endif /* FitCloudKit_UGreen_h */
