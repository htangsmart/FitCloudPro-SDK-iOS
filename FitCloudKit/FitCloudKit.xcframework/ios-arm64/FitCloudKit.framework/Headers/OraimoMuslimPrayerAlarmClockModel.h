//
//  OraimoMuslimPrayerAlarmClockModel.h
//  FitCloudKit
//
//  Created by pcjbird on 4/14/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The muslim prayer alarm clock model
@interface OraimoMuslimPrayerAlarmClockModel : NSObject

/// Dawn, time for the morning prayer
///
/// > Tips: Azan 1
@property(nonatomic, assign) NSInteger minutesFromMidnightForFajr;

/// Noon, time for the midday prayer
///
/// > Tips: Azan 2
@property(nonatomic, assign) NSInteger minutesFromMidnightForDhuhr;

/// Afternoon, time for the afternoon prayer
///
/// > Tips: Azan 3
@property(nonatomic, assign) NSInteger minutesFromMidnightForAsr;

/// Sunset, time for the prayer after sunset
///
/// > Tips: Azan 4
@property(nonatomic, assign) NSInteger minutesFromMidnightForMaghrib;

/// Night, time for the evening prayer
///
/// > Tips: Azan 5
@property(nonatomic, assign) NSInteger minutesFromMidnightForIsha;

@end

NS_ASSUME_NONNULL_END
