//
//  FitCloudKit+TranssionOraimo.h
//  FitCloudKit
//
//  Created by pcjbird on 4/14/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef FitCloudKit_TranssionOraimo_h
#define FitCloudKit_TranssionOraimo_h

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKit.h>
#import <FitCloudKit/OraimoMuslimPrayerAlarmClockModel.h>
#import <FitCloudKit/OraimoMuslimPrayerSwitchSettingsModel.h>


/// Enumeration representing different Muslim prayer switches
typedef NS_ENUM(NSInteger, OraimoMuslimPrayerSwitch)
{
    /// Main switch that controls whether the Muslim prayer reminder feature is enabled
    OraimoMuslimPrayerSwitchMain = 0x0,
    
    /// Fajr (dawn) prayer reminder
    OraimoMuslimPrayerSwitchFajrReminder = 0x1,
    
    /// Dhuhr (noon) prayer reminder
    OraimoMuslimPrayerSwitchDhuhrReminder = 0x2,
    
    /// Asr (afternoon) prayer reminder
    OraimoMuslimPrayerSwitchAsrReminder = 0x3,
    
    /// Maghrib (sunset) prayer reminder
    OraimoMuslimPrayerSwitchMaghribReminder = 0x4,
    
    /// Isha (night) prayer reminder
    OraimoMuslimPrayerSwitchIshaReminder = 0x5,
};

@interface FitCloudKit (TranssionOraimo)

/// Sends Muslim prayer alarm clocks settings for today and the next 6 days to the device
/// - Parameters:
///   - alarmClocks: An array of OraimoMuslimPrayerAlarmClockModel objects containing the prayer alarm settings for 7 days (array length must be 7)
///   - completion: A completion handler called when the operation completes
///                - succeed: Boolean indicating whether the operation was successful
///                - error: Error object if the operation failed, nil otherwise
+ (void)sendOraimoMuslimPrayerFuture7DaysAlarmClocks:(NSArray<OraimoMuslimPrayerAlarmClockModel *> * _Nonnull)alarmClocks completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;


/// Sends a command to enable or disable a specific Muslim prayer switch on the device
/// - Parameters:
///   - prayerSwitch: The type of prayer switch to configure
///   - enabled: Boolean value indicating whether to enable (true) or disable (false) the switch
///   - completion: A completion handler called when the operation completes
///                - succeed: Boolean indicating whether the operation was successful
///                - error: Error object if the operation failed, nil otherwise
+ (void)sendOraimoMuslimPrayerSwitch:(OraimoMuslimPrayerSwitch)prayerSwitch enableStatus:(BOOL)enabled completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Sends Muslim prayer switch settings to the device
/// - Parameters:
///   - settings: A model object containing the Muslim prayer switch settings to be applied
///   - completion: A completion handler called when the operation completes
///                - succeed: Boolean indicating whether the operation was successful
///                - error: Error object if the operation failed, nil otherwise
+ (void)sendOraimoMuslimPrayerSwitchSettings:(OraimoMuslimPrayerSwitchSettingsModel *_Nonnull)settings completion:(void (^__nullable)(BOOL succeed, NSError *_Nullable error))completion;

/// Query the current Muslim prayer switch settings on the device
/// - Parameter completion: A completion handler called when the query completes
///                        - succeed: Boolean indicating whether the query was successful
///                        - settings: Model object containing the current Muslim prayer switch settings
///                        - error: Error object if the query failed, nil otherwise
+ (void)queryOraimoMuslimPrayerSwitchSettingsWithCompletion:(void (^__nullable)(BOOL succeed, OraimoMuslimPrayerSwitchSettingsModel *_Nullable settings, NSError *_Nullable error))completion;

@end

#endif /* FitCloudKit_TranssionOraimo_h */
