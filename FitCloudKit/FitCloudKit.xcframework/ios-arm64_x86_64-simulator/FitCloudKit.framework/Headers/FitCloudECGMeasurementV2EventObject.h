//
//  FitCloudECGMeasurementV2EventObject.h
//  FitCloudKit
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudECGMeasurementV2SummaryObject.h>

NS_ASSUME_NONNULL_BEGIN

/// An event produced during V2 ECG measurement.
///
/// Read the properties associated with ``type``. Unrelated properties contain
/// their default value or nil.
@interface FitCloudECGMeasurementV2EventObject : NSObject

/// The event type that determines which associated properties are valid.
@property(nonatomic, assign) FitCloudECGMeasurementV2EventType type;
/// Started: The sampling rate selected by the device, in hertz.
@property(nonatomic, assign) UInt16 samplingRate;
/// Started: The expected measurement duration, in seconds.
@property(nonatomic, assign) UInt16 expectedDurationInSeconds;
/// Waveform, LeadContact, or Metrics: The corresponding global sample index.
@property(nonatomic, assign) UInt32 sampleIndex;
/// Waveform: Signed ECG samples, in microvolts.
@property(nonatomic, copy, nullable) NSArray<NSNumber *> *samples;
/// LeadContact: YES when contact is detected; otherwise NO.
@property(nonatomic, assign) BOOL leadContacted;
/// Metrics: The current heart rate, in beats per minute. Nil means unchanged; 0 means unavailable.
@property(nonatomic, strong, nullable) NSNumber *heartRate;
/// Metrics: The current QTc value, in milliseconds. Nil means unchanged; 0 means unavailable.
@property(nonatomic, strong, nullable) NSNumber *qtc;
/// Metrics: The current RMSSD value, in milliseconds. Nil means unchanged; 0 means unavailable.
@property(nonatomic, strong, nullable) NSNumber *rmssd;
/// Progress: A value from 0 through 100.
@property(nonatomic, assign) UInt8 progress;
/// Completed: The final measurement summary.
@property(nonatomic, strong, nullable) FitCloudECGMeasurementV2SummaryObject *summary;
/// Failed: The device-provided reason code, or nil when unavailable.
@property(nonatomic, strong, nullable) NSNumber *reasonCode;

@end

NS_ASSUME_NONNULL_END
