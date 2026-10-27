#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Vibration intensity settings for the three levels on a Huashengda watch.
@interface FitCloudHuashengdaVibrationIntensitySetting : NSObject <NSCopying>

/// Intensity for level 1, from 1 to 100. Use 0 to leave this level unchanged.
@property(nonatomic, assign) UInt8 intensityForLevel1;

/// Intensity for level 2, from 1 to 100. Use 0 to leave this level unchanged.
@property(nonatomic, assign) UInt8 intensityForLevel2;

/// Intensity for level 3, from 1 to 100. Use 0 to leave this level unchanged.
@property(nonatomic, assign) UInt8 intensityForLevel3;

@end

NS_ASSUME_NONNULL_END
