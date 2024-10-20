//
//  FitCloudMuslimPrayerAlarmClockModel.h
//  FitCloudKit
//
//  Created by pcjbird on 10/19/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The muslim prayer alarm clock model
@interface FitCloudMuslimPrayerAlarmClockModel : NSObject

/// Dawn, time for the morning prayer
///
/// > Tips: Azan 1
@property(nonatomic, copy) NSDate* timeForFajr;
 
/// Noon, time for the midday prayer
///
/// > Tips: Azan 2
@property(nonatomic, copy) NSDate* timeForDhuhr;

/// Afternoon, time for the afternoon prayer
///
/// > Tips: Azan 3
@property(nonatomic, copy) NSDate* timeForAsr;

/// Sunset, time for the prayer after sunset
///
/// > Tips: Azan 4
@property(nonatomic, copy) NSDate* timeForMaghrib;

/// Night, time for the evening prayer
///
/// > Tips: Azan 5
@property(nonatomic, copy) NSDate* timeForIsha;

@end

NS_ASSUME_NONNULL_END
