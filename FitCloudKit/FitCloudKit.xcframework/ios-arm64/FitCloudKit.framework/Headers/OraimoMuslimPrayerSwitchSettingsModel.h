//
//  OraimoMuslimPrayerSwitchSettingsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 4/14/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class representing Muslim prayer switch settings for Oraimo devices
@interface OraimoMuslimPrayerSwitchSettingsModel : NSObject

/// A boolean value indicating whether Muslim prayer features are enabled
@property(nonatomic, assign) BOOL mainSwitchEnabled;

/// A boolean value indicating whether Fajr (dawn) prayer reminder is enabled
@property(nonatomic, assign) BOOL fajrReminderEnabled;

/// A boolean value indicating whether Dhuhr (noon) prayer reminder is enabled
@property(nonatomic, assign) BOOL dhuhrReminderEnabled;

/// A boolean value indicating whether Asr (afternoon) prayer reminder is enabled
@property(nonatomic, assign) BOOL asrReminderEnabled;

/// A boolean value indicating whether Maghrib (sunset) prayer reminder is enabled
@property(nonatomic, assign) BOOL maghribReminderEnabled;

/// A boolean value indicating whether Isha (night) prayer reminder is enabled
@property(nonatomic, assign) BOOL ishaReminderEnabled;     

@end

NS_ASSUME_NONNULL_END
