//
//  FitCloudECGMeasurementV2SummaryObject.h
//  FitCloudKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The summary produced by a completed V2 ECG measurement.
@interface FitCloudECGMeasurementV2SummaryObject : NSObject

/// The average heart rate, in beats per minute.
@property(nonatomic, assign) UInt8 averageHeartRate;
/// The maximum heart rate, in beats per minute.
@property(nonatomic, assign) UInt8 maximumHeartRate;
/// The minimum heart rate, in beats per minute.
@property(nonatomic, assign) UInt8 minimumHeartRate;
/// The valid measurement duration, in seconds.
@property(nonatomic, assign) UInt16 actualDurationInSeconds;
/// The percentage of time spent in the normal heart-rate range.
@property(nonatomic, assign) UInt8 normalHeartRatePercentage;
/// The percentage of time spent above the normal heart-rate range.
@property(nonatomic, assign) UInt8 fastHeartRatePercentage;
/// The percentage of time spent below the normal heart-rate range.
@property(nonatomic, assign) UInt8 slowHeartRatePercentage;
/// The final QTc value, in milliseconds, or nil when unavailable.
@property(nonatomic, strong, nullable) NSNumber *qtc;
/// The final RMSSD value, in milliseconds, or nil when unavailable.
@property(nonatomic, strong, nullable) NSNumber *rmssd;
/// The QRS amplitude, in millivolts, or nil when unavailable.
@property(nonatomic, strong, nullable) NSNumber *qrsAmplitude;
/// The QRS duration, in milliseconds, or nil when unavailable.
@property(nonatomic, strong, nullable) NSNumber *qrsDuration;

@end

NS_ASSUME_NONNULL_END
