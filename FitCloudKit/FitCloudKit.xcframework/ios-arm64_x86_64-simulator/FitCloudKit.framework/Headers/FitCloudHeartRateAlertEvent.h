#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// An exercise or resting heart rate alert reported by the device (protocol 3.3.175).
/// The protocol does not supply a measurement timestamp.
@interface FitCloudHeartRateAlertEvent : NSObject

@property(nonatomic, readonly) FitCloudHeartRateAlertType type;
/// Current heart rate, in BPM.
@property(nonatomic, readonly) UInt8 heartRate;
/// Threshold that triggered the alert, in BPM.
@property(nonatomic, readonly) UInt8 threshold;

- (instancetype)initWithType:(FitCloudHeartRateAlertType)type
                  heartRate:(UInt8)heartRate
                  threshold:(UInt8)threshold NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
