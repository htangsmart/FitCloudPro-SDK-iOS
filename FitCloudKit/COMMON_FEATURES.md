# COMMON FEATURES

## Determine whether the current smartwatch supports specific features

Software features

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL isDNDSupported = (allConfig && allConfig.firmware && allConfig.firmware.allowDNDMode);

// this is an example, and many other properties of the firmware object indicates whether the software feature is supported
```

Hardware features

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL isECGSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_ECG));
// this is an example, and many other options can be checked by the hardwareSupported property of the firmware object
```

## Sync the iOS system time to the watch

```objc
+(void)syncSystemTimeWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Set the weather

```objc
+(void) syncWeather:(FitCloudWeatherObject*_Nonnull)weather block:(FitCloudResultBlock _Nullable )block;
```

## Set alarms

```objc
+(void)setAlarms:(NSArray<FitCloudAlarmObject*>*_Nullable)alarms block:(FitCloudResultBlock _Nullable )block;
```

## Get alarms

```objc
+(void)getAlarmsWithBlock:(FitCloudAlarmsResultBlock _Nullable )block;
```

## Set schedules

```objc
+(void)setSchedules:(NSArray<FitCloudScheduleObject*>*_Nullable)schedules block:(FitCloudResultBlock _Nullable )block;
```

## Get schedules

```objc
+(void)getSchedulesWithBlock:(FitCloudSchedulesResultBlock _Nullable )block;
```

## Set favorite contacts

```objc
+(void) setFavContacts:(NSArray<FitCloudContactObject*>*_Nullable)contacts block:(FitCloudResultBlock _Nullable )block;
```

## Get favorite contacts

```objc
+(void) getFavContactsWithBlock:(FitCloudFavContactsResultBlock _Nullable)block;
```

## Set habits

```objc
+(void) setHabits:(NSArray<FitCloudHabitObject*>*_Nullable)habits block:(FitCloudResultBlock _Nullable )block;
```

## Get habits

```objc
+(void) getHabitsWithBlock:(FitCloudHabitsResultBlock _Nullable)block;
```

## Set the user profile

```objc
+(void)setUserProfile:(FitCloudUserProfileObject *_Nonnull)profile block:(FitCloudResultBlock _Nullable )block;
```

## Set custom labels

```objc
+(void)setCustomLabels:(FitCloudCustomLabelsObject *_Nonnull)labels block:(FitCloudResultBlock _Nullable )block;
```

## Set daily goals

```objc
+(void)setDailyGoalWithStepCount:(UInt32) stepcount distance:(UInt32)distance calory:(UInt32)calory timestamp:(NSDate* _Nullable )timestamp block:(FitCloudResultBlock _Nullable )block;
```

## Get daily goals

```objc
+(void)getDailyGoalWithBlock:(FitCloudDailyGoalResultBlock _Nullable )block;
```

## Get firmware version

```objc
+(void)getFirmwareVersionWithBlock:(FitCloudFirmwareVersionResultBlock _Nullable )block;
```

## Turn on or off APNS options

```objc
+(void)setMessageNotification:(FITCLOUDMN)mnSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get APNS options

```objc
+(void)getMessageNotificationSettingWithBlock:(FitCloudMNSettingResultBlock _Nullable )block;
```

## Set screen display options

```objc
+(void)setScreenDisplay:(FITCLOUDSCREENDISPLAY)display block:(FitCloudResultBlock _Nullable )block;
```

## Get screen display options

```objc
+(void)getScreenDisplaySettingWithBlock:(FitCloudSDSettingResultBlock _Nullable )block;
```

## Set the smart watch prefer

```objc
+(void)setFitCloudPrefer:(FITCLOUDPREFER)prefer block:(FitCloudResultBlock _Nullable )block;
```

## Get the smart watch prefer

```objc
+(void)getFitCloudPreferWithBlock:(FitCloudPreferResultBlock _Nullable )block;
```

## Get the battery level

```objc
+(void)getBatteryInfoWithBlock:(FitCloudBatteryInfoResultBlock _Nullable )block;
```

## Set the health timing monitor options

```objc
+(void)setHealthTimingMonitor:(FitCloudHTMObject*_Nonnull)htmSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the health timing monitor options

```objc
+(void)getHealthTimingMonitorSettingWithBlock:(FitCloudHealtTimingMonitorResultBlock _Nullable )block;
```

## Set the sedentary reminder options

```objc
+(void)setSedentaryRemind:(FitCloudLSRObject *_Nonnull)lsrSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the sedentary reminder options

```objc
+(void)getSedentaryRemindSettingWithBlock:(FitCloudLongSitRemindResultBlock _Nullable )block;
```

## Set the water drink reminder options

```objc
+(void)setDrinkRemind:(FitCloudDRObject*_Nonnull)drSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the water drink reminder options

```objc
+(void)getDrinkRemindSettingWithBlock:(FitCloudDrinkRemindResultBlock _Nullable )block;
```

## Set the hand wash reminder options

```objc
+(void)setHandWashRemind:(FitCloudHandWashRemindObject*_Nonnull)hwrSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the hand wash reminder options

```objc
+(void)getHandWashRemindSettingWithBlock:(FitCloudHandWashRemindResultBlock _Nullable )block;
```

## Set options for wake up the watch by lifting the wrist

```objc
+(void)setWristWakeUp:(FitCloudWWUObject*_Nonnull)wwuSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get options for wake up the watch by lifting the wrist

```objc
+(void)getWristWakeUpSettingWithBlock:(FitCloudWristWakeUpResultBlock _Nullable )block;
```

## Set the blood pressure value reference

```objc
+(void)setBloodPressureRefer:(FitCloudBPRObject*_Nonnull)bprSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the blood pressure value reference

```objc
+(void)getBloodPressureReferSettingWithBlock:(FitCloudBloodPressureReferResultBlock _Nullable )block;
```

## Set the heart rate alarm options

```objc
+(void)setHRAlarm:(FitCloudHRAlarmObject* _Nonnull)hrAlarmSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the heart rate alarm options

```objc
+(void)getHRAlarmSettingWithBlock:(FitCloudHRAlarmResultBlock _Nullable)block;
```

## Set the blood pressure alarm options

```objc
+(void)setBPAlarm:(FitCloudBPAlarmObject* _Nonnull)bpAlarmSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the blood pressure alarm options

```objc
+(void)getBPAlarmSettingWithBlock:(FitCloudBPAlarmResultBlock _Nullable)block;
```

## Set the do not disturb mode options

```objc
+(void)setDND:(FitCloudDNDSetting* _Nonnull)dndSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the do not disturb mode options

```objc
+(void)getDNDSettingWithBlock:(FitCloudDNDSettingResultBlock _Nullable)block;
```

## Set the power saving mode options

```objc
+(void)setPowerSavingSettings:(FitCloudPowerSavingSetting* _Nonnull)settings block:(FitCloudResultBlock _Nullable )block;
```

## Get the power saving mode options

```objc
+(void)getPowerSavingSettingWithBlock:(FitCloudPowerSavingSettingResultBlock _Nullable)block;
```

## Get the watch ui informations

```objc
+(void)getWatchUIInformationWithBlock:(FitCloudWatchUIInfoResultBlock _Nullable)block;
```

## Get the watchface ui informations

```objc
+(void)getWatchfaceUIInformationWithBlock:(FitCloudWatchfaceUIInfoResultBlock _Nullable)block;
```

## Set the watchface modules

```objc
+(void)setWatchfacePostion:(NSInteger) position modules:(NSArray<FitCloudWatchfaceModule*>* _Nullable)modules completion:(FitCloudResultBlock _Nullable)block;
```

## Set the women health configuration

```objc
+(void)setWomenHealthConfig:(FitCloudWomenHealthSetting*_Nonnull)whSetting block:(FitCloudResultBlock _Nullable )block;
```

## Get the women health configuration

```objc
+(void)getWomenHealthSettingWithBlock:(FitCloudWomenHealthSettingResultBlock _Nullable )block;
```

## Set the screen lock options

```objc
+(void)setLockScreenSetting:(FitCloudLockScreenSetting* _Nonnull)lockScreenSetting block:(FitCloudResultBlock _Nullable)block;
```

## Manually exit the sleep mode

```objc
+(void)exitSleepWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Set the app localization language as the smart watch language

```objc
+(void)syncSystemLanguageWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Set the smart watch language

```objc
+(void)setSmartWatchLanguage:(FITCLOUDLANGUAGE)lang completion:(FitCloudResultBlock _Nullable )block;
```

## Get supported games of the smart watch

```objc
+(void)getSupportedGamesWithBlock:(FitCloudSupportedGamesResultBlock _Nullable)block;
```

## Get the top 3 rank game records

```objc
+(void)getTop3RankGameRecordsWithBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;
```

## Get the top 3 rank game records for the game

```objc
+(void)getSingleGameTop3RankGameRecords:(NSInteger)gameNo withBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;
```

## Get game skins

```objc
+(void)getAllGameSkinsWithBlock:(FitCloudAllGameSkinsResultBlock _Nullable)block;
```

## Set the game ranking trends

```objc
+(void)setGameRankingTrendsArray:(NSArray<FitCloudGameRankingTrend*>*)trendsArray completion:(FitCloudResultBlock _Nullable )block;
```

## Set the screen and vibrate options

```objc
+(void)setScreenSettings:(FitCloudScreenSetting*) screenSettings vibrateSettings:(FitCloudVibrateSetting*)vibrateSettings completion:(FitCloudResultBlock _Nullable )block;
```

## Get the screen and vibrate settings

```objc
+(void)getScreenAndVibrateSettingsWithBlock:(FitCloudScreenAndVibrateSettingsResultBlock _Nullable)block;
```

## Get the screen resolutions

```objc
+(void)getScreenResolutionWithBlock:(FitCloudScreenResolutionResultBlock _Nullable)block;
```

## Get supported sports for the watch

```objc
+(void)getSupportedWatchSportsWithBlock:(FitCloudSupportedWatchSportsResultBlock _Nullable)block;
```

## Get current sports on the watch

```objc
+(void)getCurrentWatchSportsWithBlock:(FitCloudCurrentWatchSportsResultBlock _Nullable)block;
```

## Get the money receive and business qrcode features supported for the watch

```objc
+(void) getWatchSpecifiedSupportedMoneyReceiveAndBusinessQRCodeFeaturesWithBlock:(FitCloudQRCodeFeaturesResultBlock _Nullable)block;
```

## Find the smart watch by vibrating the smart watch

```objc
+(void)findBraceletWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Restore the smart watch as factory settings

```objc
+(void)restoreAsFactorySettingsWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Turn off the smart watch

```objc
+(void)turnOffWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Reboot the smart watch

```objc
+(void)rebootWithBlock:(FitCloudResultBlock _Nullable )block;
```

## Notify the smart watch with the app location service state

```objc
+(void)notifyAppLocServiceState:(APPLOCATIONSERVICESTATE)state withBlock:(FitCloudResultBlock _Nullable )block;
```

## Send QRCode

```objc
+(void)sendQRCode:(FITCLOUDQRCODE)qrcode content:(NSString*)content withBlock:(FitCloudResultBlock _Nullable)block;
```

## Set the vibrate param when launch for the smart watch

```objc
+(void)setWatchLaunchVibrateParam:(FitCloudWatchLaunchVibrateSetting*) param withBlock:(FitCloudResultBlock _Nullable)block;
```

## Delete the watch message

```objc
+(void)deleteWatchMessageWithIndex:(NSInteger)deleteIndex shouldDeleteAll:(BOOL)shouldDeleteAll withBlock:(FitCloudResultBlock _Nullable)block;
```

## Dismiss the watch message from the screen

```objc
+(void)dismissCurrentWatchMessageWithBlock:(FitCloudResultBlock _Nullable)block;
```

## Set the game passcode settings

```objc
+(void)setGamePasscodeSetting:(FitCloudGamePasscodeSetting* _Nonnull)setting block:(FitCloudResultBlock _Nullable)block;
```
