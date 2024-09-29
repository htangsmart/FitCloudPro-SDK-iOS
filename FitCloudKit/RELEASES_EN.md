# RELEASES

## pcjbird 2024-09-30 Version:1.2.9 Build:20240930001

    1. Added support for Skyworth PV data, @see withSkyworthPV.
    2. Added some debugging logs.
    3. Supported cricket match data commands, @see withCricketMatch.
    4. Added support for synchronizing specified time to the watch.
    5. GPS & EPO support, @see withGPSEpo.
    6. Supported NetEase Cloud Music.
    7. Watch face size support for 228x460 square.
    8. Added habit formation types.
    9. Added command to get the list of supported schedule types for the watch, @see canGetSupportedSchedules.
    10. Supported setting and getting the medal list, @see withMedals.
    11. Supported motion-sensing games, @see withMotionSensingGame.
    12. Modified habit formation protocol.
    13. Watch face size support for 390x390 circular.
    14. Added navigation information synchronization support, @see naviGuideSupported.
    15. Watch face size support for 390x450 square.
    16. Watch face size support for 286x240 square.
    17. Added support for album push, @see allowPhotoPush.
    18. Added support for eBook push, @see allowEBookPush.
    19. Added snooze support, @see withSnooze.
    20. Added REM sleep support, @see withREM.
    21. Supported more than 10 frequently used contacts, @see allowHugeCountFavContacts.
    22. Added e-wallet functionality.
    23. Watch face size support for 192x490 square.
    24. Added indicator for whether heart rate monitoring spans across days, @see allowHeartRateMonitoringAcrossDays.
    25. Added support for querying device capabilities, @see allowQueryDeviceCapacities, allConfig.deviceCapacities.
    26. Added method to get workout display data item information, @see withDisplayConfigInWorkoutData.
    27. Added FitCloudOption for automatic system language synchronization, @see autoSyncSystemLang.
    28. New OTA upgrade support, @see withNewOTA.
    29. Entering DFU mode now returns error type `FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE`.
    30. Added independent switch settings and query functionality for health monitoring timing, @see allowSingleHTMSettings.
    31. Added static and dynamic heart rate low alarm functionality, @see withHRLowAlarm.
    32. Weather settings now include UV index functionality.
    33. Added customized weather types for LiSheng, @see FITCLOUDWEATHERTYPE_CLOUDYINEVENING/FITCLOUDWEATHERTYPE_CLEARINEVENING/FITCLOUDWEATHERTYPE_EVENINGSHOWERS.
    34. Added the number of weather types supported by the device capabilities.
    35. Added support for setting and querying extreme heart rates for specific projects.
    36. Added software version information query for LiSheng, only available for that client, version data to be parsed by the client, @see FitCloudKit+Haylou.h.
    37. Added support for large models, @see withLLM.
    38. Added query functionality for LiSheng watch SN information, only available for that client, @see FitCloudKit+Haylou.h.
    39. Modified binding API, added random code; if there is no random code, fill in nil.
    40. New binding failure error: "The watch needs to be reset to factory settings to bind."
    41. Added functionality to query the current language setting of the watch.
    42. Added notification for the watch performing the stop find watch action, @see FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY.
    43. Modified stop find watch API name; added stop find watch functionality.
    44. Daily exercise goal now includes setting exercise duration target.
    45. Added functionality to set emergency contacts, @see withEmergencyContact.
    46. Added resting heart rate query functionality, @see withRestingHR.
    47. Added functionality to set personalized reminders, @see withPersonalizedReminder, @see FITCLOUDDEVICECAPACITY.
    48. Health data and step data now include exercise duration data.
    49. Message notifications now include Gmail/Outlook/WhatsApp Business.
    50. Weather settings modified visibility precision to meters.
    51. Added direct DFU upgrade (DFU upgrade without entering DFU mode); directly use `[FitCloudKit directDFUPeripheral]` to pass peripherals to FitCloudDFUKit, available only for specific client watches.
    52. Added hardware platform flags, @see FITCLOUDHARDWARE_8773, FITCLOUDHARDWARE_568X.
    53. The maximum length for e-wallet names has been changed to 32 bytes.
    54. Corrected the vendor identifier for Transsion, supporting MAC address parsing.
    55. Added couple functionality, @see `[FitCloudKit isDeviceSupportFeature:FITCLOUDDEVICEFEATURE_LOVERS]`.
    56. Supported returning calorie data for GPS interconnected exercises.
    57. New OTA added frame retransmission mechanism.
    58. Watch face size support for 320x172 square.
    59. Watch face size support for 385x320 square.
    60. Updated new OTA error codes.
    61. To prevent unrealistic user data causing algorithm issues, user input will be corrected before being sent to the watch.
    62. Optimized switching watch faces and modifying corresponding component style APIs.
    63. Optimized the watch's return of watch face UI information.
    64. Removed exercise type definitions from SDK, to be handled at the app level; for exercise type mapping table, contact the corresponding business or product manager.
    65. Added support for returning REM sleep data.
    66. Added support for setting 24-hour weather information, only some watches support this.
    67. Added support for pool swimming and open water swimming exercise data synchronization.
    68. Watch face size support for 480x480 circular.
    69. Watch face size support for 194x368 square.
    70. Chip and object GPS support.
    71. ANCS notification extension.
    72. Headphone case project support.
    73. Added support for synchronizing jump rope/elliptical/rowing machine related exercise extended data.
    74. Added support for shielding enhanced heart rate measurement.
    75. Supported female health features for Transsion Infinix projects.
    76. Supported obtaining debugging logs from the watch, only some watches support this.
    77. `FitCloudKitConnectRecord` now includes MAC address.
    78. Introduced event “FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY,” indicating the watch has manually terminated a measurement initiated by the app.
    79. Exercise heart rate data is provided in a separate data list, @see bpmDataArray.
    80. Added callback to notify the app when the watch enters or exits large language model functionality.
    81. Resolved some connection issues when switching between multiple devices.
    82. Watch face size support for 360x360 square/296x240 square.
    83. Introduced new API `+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` to allow the main program to connect and bind the watch device with a single API call.
    84. Renamed the `time` property in FitCloudKitConnectRecord to `latestConnectTime`, and renamed the `bindTime` property to `userBindTime`.
    85. Added WeChat payment certification functionality for the watch.
    86. Added functionality to start and stop laser measurement, and to query the laser measurement status.

## pcjbird 2023-05-30 Version:1.2.8 Build:202305300001

    1. Watch face size support for 410x502 square/416x416 circular/240x288 square.
    2. Added custom label functionality, @see withCustomLabels.
    3. Supported Alipay IoT, @see allowAliot.
    4. Bluetooth connection supports setting whether to use one-click dual connection with classic Bluetooth (BT), @see allowConnectWithBT.
    5. Added method to obtain relevant manufacturer information and parameters through broadcast data, @see FitCloudManufacturer.
    6. Supported GPS data transmission for watch exercise, @see FitCloudGPSRecordObject.
    7. Watch face size support for 340x340 circular.
    8. Added specified supported payment codes and business cards; only the specified payment codes and business cards should be displayed in the App's push entrance, @see specifySupportedMoneyReceiveAndBusinessQRCode.
    9. Modified habit formation commands.
    10. Added power-saving mode settings, @see withPowerSavingMode & allowPowerSavingModePeriod.
    11. Added timestamp parameter for daily goal settings.
    12. Adjusted Alipay IoT security certification commands.
    13. Modified automatic login logs; userId now supports String.
    14. Modified command parsing for getting watch UI information, compatible with firmware versions.
    15. Updated and added a large number of exercise type definitions.
    16. Improved SDK stability.

## pcjbird 2022-12-30 Version:1.2.7 Build:202212300001

    1. Added functionality to disable the sleep module.
    2. Added nucleic acid code push functionality, @see allowNucleicAcidQRCode.
    3. Weather now includes atmospheric pressure/wind strength/visibility information.
    4. Added commands related to habit formation, @see allowHabits.
    5. Added payment codes: Paytm/PhonePe/GPay/BHTM, added business cards: Email/Phone/LinkedIn, @see showAdditionalQRCodeTransfer.
    6. Added notification to the watch when phone ringing playback ends, compatible with Bluetooth call watches.
    7. Added command to get daily exercise goals.
    8. Optimized obtaining MTU values for peripherals.

## pcjbird 2022-09-20 Version:1.2.6 Build:202209200001

    1. Fixed GPS interconnection motion command issues.
    2. Added true blood pressure measurement based on barometric pump (supported by some watches).
    3. Manual measurement data synchronization supported by some watches.
    4. SOS request initiation supported by some watches.
    5. Added support for starting and stopping third-party peripherals.
    6. Added vibration parameter settings for watch startup.
    7. Added command to delete messages stored on the watch.
    8. Added command to cancel the current message display on the watch.
    9. Added game lock settings.
    10. Login/binding command added iOS system version flag.
    11. Added retrieval of up to three highest game records (supported by some watches).
    12. Fixed true blood pressure data synchronization issues.
    13. Modified GPS interconnection commands.
    14. Added game ranking trend settings (supported by some watches).
    15. Updated SDK alarm clock list cache when retrieving alarm clock list.
    16. Updated SDK error code translations.
    17. Handled exercise health data to prevent data loss.
    18. Added flag to disable modular watch face in the app @see disableWatchfaceModularInApp.
    19. Added watch face size support of 240x296 square.
    20. Improved SDK stability.

## pcjbird 2022-01-26 Version:1.2.5 Build:202201260001

    1. Added definitions for cricket, free exercise, strength training, indoor walking, indoor cycling, dumbbells, dancing, hula hoop, golf, long jump, sit-ups, and volleyball.
    2. Added watch GPS interconnection sports.
    3. Added wake-up APP camera function (use with caution due to defects).
    4. Added blood pressure and heart rate alarm function device support checks.
    5. Added watch preference setting for achieving exercise goals (steps/distance/calories) reminders.
    6. Fixed issues with large amounts of data for common contact commands.
    7. Fixed potential crashes when turning off Bluetooth during OTA.
    8. Added support for payment codes and business card QR code pushing.
    9. Fixed unbinding when the watch disconnects; it may reconnect when the watch is near the phone.
    10. Fixed issues with Bluetooth disconnect during ECG measurement possibly causing incorrect reconnections.
    11. Added audio Bluetooth name return when call watch binding fails.
    12. Added Hindi language support.

## pcjbird 2021-10-12 Version:1.2.4 Build:202110120001

    1. Added flag for supporting game skin push.
    2. Added flag for supporting notifications from Apple Music, Zoom & TikTok.
    3. Added flag for supporting QR code connection.
    4. Added hardware identifier `FITCLOUDHARDWARE_DFUSHOULDSILENTMODE`.
    5. Added definitions for Tetris, Sudoku, and quiz games.
    6. Added reasons for binding failure in QR code binding project (watch actively canceled / watch timeout).
    7. Added methods to get/set screen time, brightness, vibration, etc.
    8. Added flag to disable custom watch face functionality.
    9. Added callback for when the watch leaves the Find Phone feature interface.
    10. Added preference setting for watch vibration when Bluetooth disconnects.
    11. Fixed issues with synchronizing ECG data when the watch disconnects.
    12. Added methods to retrieve original screen resolution information (LCD width/height, circular screen, corner size, etc.), supported by some firmware.
    13. Expanded Nordic platform watch face numbering to 3 bytes.
    14. Fixed issue where only 3 game skins could be retrieved.
    15. Modified maximum file size calculation rules for watch faces/game skins.
    16. Modified weather hardware function flag definitions.
    17. Added flag for whether the watch supports exercise modes (DIY) firmware push.
    18. Added methods to get the list of supported exercise mode types for devices/current exercise mode type list, supported by some watches.

## pcjbird 2021-07-20 Version:1.2.3 Build:202107200001

    1. Added pressure index measurement, supported by some watches.
    2. Fixed issues with schedule setting commands.
    3. Fixed issues with lock screen password setting commands.
    4. Added watch face size support for 280x240 square / 200x320 square / 368x448 square / 320x390 square.
    5. Added modular (component-based) watch face support.
    6. Fixed issues with schedule retrieval commands.
    7. Supported custom setting of watch language. @note: If you wish to set the watch's language during SDK initialization, @see watchPreferLang for FitCloudOption. If you want to change the watch's language dynamically while the app is running, call setSmartWatchLanguage:completion:. Additionally, the original syncSystemLanguageWithBlock will also be affected; if you customize the watch language, the original syncSystemLanguageWithBlock will also sync the customized watch language setting.
    8. Added setting to allow watch to set schedule, only effective when the watch supports schedule functionality.
    9. Supported conversion of self-scanned peripherals to connectable peripherals.
    10. Updated GUI structure-related protocol.
    11. Next-generation vendor names supported, confirming that the filtering of the Bluetooth name's first letter "H" is not needed.
    12. Fixed issue where changing watch faces could result in the loss of watch face module information.
    13. Multi-watch face push supports getting each watch face's maximum push firmware size in kB.
    14. Supported Nordic chips.
    15. Added methods to get the types of games supported by the watch, supported by some watches.
    16. Added methods to retrieve game skin information for all games on the watch, supported by some watches.
    17. Added watch face size support for 172x320 square / 454x454 circular / 128x220 square.
    18. Added `+(void)ignoreConnectedPeripheral:(BOOL)silent;` adding silent parameter.
    19. Added `FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY` notification, suggesting users enter system settings to remove pairing information with the watch, kill the App process, and restart the App. Refer to its definition for specifics. @note: This notification may be sent continuously, and the application layer needs to avoid prompting users repeatedly to prevent confusion.

## pcjbird 2021-02-05 Version:1.2.2 Build:202102050001

    1. Added weather push switch, supported by some watches.
    2. Added notification for the watch APP's location service status.
    3. Added handwashing reminder feature.
    4. Added watch face size support for 240x280 square.
    5. Data parsing abnormal handling; entries that are too large are discarded and no longer parsed.
    6. Added lock screen password setting, supported by some watches.
    7. Added schedule reminder setting, supported by some watches.
    8. Added notifications for Hike and YouTube, supported by some watches.
    9. Added watch face size support for 348x442 square.
    10. Multi-watch face push information retrieval supported.
    11. Added definitions for exercise types.

## pcjbird 2020-10-30 Version:1.2.1 Build:202010300001

    1. FitCloudOption supports preferSystemLocale option; when set to TRUE, the watch will sync the iOS system language setting, otherwise, it will sync the current APP's language setting, defaulting to FALSE. @note: Due to system limitations, if you manually modify the APP's language, this option will also become ineffective.
    2. Fixed issues with incorrect sleep debug data responses.
    3. Supported setting health monitoring intervals, requires watch support, @see allowSetHealthMonitorInterval.
    4. Supported setting sedentary reminder intervals, requires watch support, @see allowSetLSRInterval.
    5. Supported setting weather forecasts, requires watch support, @see allowWeatherForecast.
    6. Added weather update time, adjusted maximum supported days for weather forecasts to 14 days.
    7. Fixed issues with incorrect health monitoring/sedentary reminder interval settings.
    8. Fixed issues with incorrect watch flag parsing.
    9. Added Albanian language support.
    10. Added Turkish and Ukrainian language support.
    11. Fixed issues with syncing Korean language to the watch.
    12. Patch: When allowShowAdditionalReminder flag is true, allowShowMailReminder/allowShowTelegramAndViberReminder are forced to true.

## pcjbird 2020-07-18 Version:1.2.0 Build:202007180001

    1. Supported notification for the watch to exit camera mode.
    2. Added female health feature.
    3. Added protective reminder feature.
    4. Fixed issues with Hungarian language not syncing to the watch.
    5. Added method to set custom field key1 for broadcast data, specific to Huashida.
    6. Fixed issues with incorrect age setting during user profile setup.
    7. Added method to retrieve today's sleep debug data.
    8. Fixed issues with incorrect age setting.
    9. Added latest health measurement data including temperature data (requires watch support for temperature).
    10. Added related notes on new watch face size support.
    11. Supported setting all localized languages defined by the SDK to the watch.

## pcjbird 2020-05-15 Version:1.1.9 Build:202005150001

    1. Supported temperature measurement, supported by some watches.

## pcjbird 2020-04-25 Version:1.1.8 Build:202004250001

    1. Fixed potential issues where unbinding might not disconnect properly.
    2. Fixed issues where the watch disconnecting during automatic login might lead to notifications about being bound to another phone or already unbound.
    3. Fixed issues where timeout during command execution could result in missing the next command.
    4. Fixed timeout issues when syncing large amounts of health data.
    5. Cleared battery information after unbinding.
    6. Supported common contacts, supported by some watches.
    7. Added exercise modes including elliptical, yoga, table tennis, and jump rope.
    8. Fixed issues with incorrect logic handling when ECG startup fails.
    9. Fixed issues where connection timeout would not execute timeout logic.

## pcjbird 2020-02-25 Version:1.1.7 Build:202002250001

    1. Added Slovak and Hungarian language support.
    2. Fixed issues with sleep data quality possibly returning illegal values.
    3. Canceled automatic unbinding logic, added notifications for the watch being bound by another phone or already unbound @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY.
    4. All callbacks and notifications are now called in the Global Queue; if you want to update the UI in the callback or notification, be sure to switch to the Main Queue.
    5. External calls to disconnect will not automatically reconnect.
    6. Added FITCLOUDUSERBINDSTATUS_KICKEDOUT user binding status.
    7. Added FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY notification.
    8. Added support for the new sleep format @see newSleepDataFormat.
    9. Log information supports viewing the complete data for large packets.
    10. The watch actively changes settings (e.g., wrist raise wake-up, notification settings, etc.) will update to the App as needed @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY.
    11. Modified methods for retrieving watch face information.
    12. Other improvements.

## pcjbird 2019-11-21 Version:1.1.6 Build:201911210001

    1. Fixed issues with the watch face UI information interface not responding correctly.
    2. After unbinding the user, canceled the automatic reconnection of the current watch connection record.
    3. Optimized the watch connection initialization process to prevent unexpected reconnections.
    4. Adjusted watch hardware-related information to be read-only.
    5. The UserId of the bound user has been changed from integer to string type.
    6. Added methods to retrieve the last health measurement data (heart rate/blood oxygen/blood pressure), supported by some watches, @see allowRetrieveLatestMeasurementData.
    7. Modified methods to enter and exit firmware upgrade mode; now you must manually call to enter and exit firmware upgrade mode before and after every firmware upgrade operation, applicable to both regular firmware upgrades and watch face pushes.
    8. Added DFU mode reconnection success notification, typically used for waiting for watch face pushes/normal firmware upgrades after the watch restarts.
    9. Improved SDK stability.

## pcjbird 2019-11-13 Version:1.1.5 Build:201911130001

    1. Added Do Not Disturb mode (supported by some watches @see allowDNDMode).

## pcjbird 2019-10-24 Version:1.1.4 Build:201910240001

    1. Real-time measurement moment modified to second precision.
    2. Fixed issues with synchronizing data moments not exceeding the current synchronization time.

## pcjbird 2019-10-16 Version:1.1.3 Build:201910160001

    1. Step data now incorporates distance & calorie new algorithms.
    2. Added methods to retrieve the last binding time of the user.
    3. Added settings for heart rate and blood pressure alarms.
    4. Added options for Snapchat message reminders.
    5. Device scanning cancels device name filtering.
    6. Real-time ECG measurement added logic for the watch to end actively.
    7. Added methods to retrieve watch face UI information.
    8. Added methods to retrieve cached broadcast data from the watch.
    9. Added notifications for Bluetooth name changes and Bluetooth RSSI changes.
    10. Improved SDK stability.
    11. Avoid ambiguity; `+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals` changed to `+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals`.

## pcjbird 2019-08-19 Version:1.1.2 Build:201908190002

    1. Fixed issues with the timing of Bluetooth connection start notifications.

## pcjbird 2019-08-19 Version:1.1.1 Build:201908190001

    1. Fixed issues where unbinding the watch did not clear the previous bound watch's MAC address.
    2. Added notifications for the start and end of basic synchronization operations after binding/login success.
    3. Fixed issues with SDK initialization options shouldAutoConnect not functioning.

## pcjbird 2019-08-12 Version:1.1.0 Build:201908120001

    1. Supported background Bluetooth data synchronization.

## pcjbird 2019-07-21 Version:1.0.9 Build:201907210001

    1. Supported retrieval of current SDK version information.

## pcjbird 2019-07-20 Version:1.0.8 Build:201907200001

    1. Fixed issues where setting the iPhone calendar to a Buddhist or Japanese calendar caused failure in syncing time with the watch.
    2. Optimized watch reconnection mechanism.

## pcjbird 2019-06-28 Version:1.0.7 Build:201906280001

    1. Fixed issues where unable to retrieve notification settings.

## pcjbird 2019-06-27 Version:1.0.6 Build:201906270001

    1. Added MAC address data for external devices discovered during scanning.

## pcjbird 2019-06-25 Version:1.0.5 Build:201906250001

    1. Modified support for setting exercise goals.

## pcjbird 2019-05-17 Version:1.0.4 Build:201905170001

    1. Added supported languages for the watch.

## pcjbird 2019-05-01 Version:1.0.3 Build:201905010001

    1. First release of the SDK version.
