# RELEASES

## pcjbird 2025-12-28 Version:1.3.2-beta.32 Build:20251228001   

- Block device scanning during the connection process.
- Added `FITCLOUDEVENT_PERIPHERAL_SCANSTART_ERROR_NOTIFY` event to notify when device scan starts with error.
- Adjusted the localization of the description in the returned error userInfo to English.
- Added `Zalo` business-card definition.
- Motion-based games now support heart-rate data.
- Added more SDK debug logs to help diagnose watch-connection stability.
- Enhanced the auto-binding and login flow for improved stability and speed.
- Introduced new APIs for AI diet features.
- Introduce new sdk initialize option `onlyUsedForConnectingEarbudCase` to optimize the connection process for earbud cases.
- Added a new `desc` property to the `FitCloudTaskModel` for task-detail descriptions.
- Updated the task-sending API to `+ (void)sendTasks:(NSArray<FitCloudTaskModel *> *_Nullable)tasks totalTaskCount:(NSUInteger)totalTaskCount totalCoinsEarned:(NSUInteger)totalCoinsEarned completion:(FitCloudCompletionHandler _Nullable)completion`, enabling tasks to be sent to the watch in batches to prevent memory exhaustion caused by transmitting too much data at once.
- Introduce new API `+ (void)fetchInstallableWatchfaceSlotCountWithCompletion:(void (^_Nullable)(BOOL success, NSNumber *_Nullable slotCount, NSArray<NSNumber*>* _Nullable slotIndexArray, NSError *_Nullable error))completion` to fetch the count of watchface slots that support installing cloud or custom watchfaces.
- Modified the SDK initialization method to return a boolean indicating success instead of the FitCloudKit object.
- Introduce new sdk initialize option `logLevel` to set the minimum log level for the SDK.
- Introduce new sdk initialize option `includeTimestampInLogs` to indicate whether to include the timestamp in the log messages.
- Renamed the SDK log message callback Method from `- (void)OnLogMessage:(NSString *)message level:(FITCLOUDKITLOGLEVEL)level;` to `- (void)onLogMessage:(NSString *)message level:(FITCLOUDKITLOGLEVEL)level subsystem:(NSString *)subsystem category:(NSString *)category;`.
- Renamed other several API methods and polished the related comments.
- Added support for 128×160 square watch face size.
- Prevent auto-login when connecting to an unbound device.
- Added support for sending the last two months of menstrual-cycle data to Titan watches. See `FitCloudKit+Titan.h` for details.
- Changed the commands for sending the last two months of menstrual-cycle data to Titan watches.
- Update the definition of `LLMRESULTTYPE` to add `LLMRESULTTYPE_INTERNETCONNECTIONOFFLINE` and `LLMRESULTTYPE_UNKNOWNERROR`.
- Update the definition of `FITCLOUDAIPHOTOGENRESULT`, changing `FITCLOUDAIPHOTOGENRESULT_NETWORK_ERROR` to `FITCLOUDAIPHOTOGENRESULT_NETWORK_CONNECTION_OFFLINE`.
- Updated the ASR result-sending API: replaced `+ (void)sendASRResult:(NSString *)text completion:(FitCloudCompletionHandler _Nullable)completion` with `+ (void)sendASRResult:(nullable NSString *)text errorCode:(FitCloudASRErrorCode)errorCode completion:(FitCloudCompletionHandler _Nullable)completion`.
- Added support for 160×128 square watch face size.
- Updated the parsing logic for pre-calculated workout summary data from watch devices to accommodate the latest Bluetooth communication protocol.
- Added SDK callback `- (void)onWatchSideDidConfirmedLLMQuestion` to notify the app that the watch has confirmed the current question and will forward it to the LLM (large language model). This method is only supported on select watch models that implement LLM-question ASR-result confirmation.
- Introduced new API `+ (void)sendLLMQuestionASRResult:(nullable NSString *)text errorCode:(FitCloudASRErrorCode)errorCode completion:(FitCloudCompletionHandler _Nullable)completion` to send the ASR result of an LLM question to the watch. This method is only supported on select watch models that implement LLM-question ASR-result confirmation. Do **not** call it on unsupported devices. Always verify device capability before use.
- Fixed an issue where the app would fail to auto-reconnect to the watch in certain scenarios after exiting DFU mode.
- Added repeat options support for classroom mode settings.
- Added flag to indicate whether the watch supports ai-tranlsation feature for `蝶唯`.
- Renamed `GPay` to `Google Wallet`.
- Trying to log out a user from the watch when manually disconnect or app terminates.
- Added `hasSetFireTime` property for `FitCloudTaskModel`, indicating whether the task has set a fire time.
- Introduced new API `+ (void)redeemTaskRewardWithCompletion:(FitCloudCompletionHandler _Nullable)completion;` to redeem the total task rewards.
- Introduced new APIs for the `855A-Constellation&Fortune` product.
- Fixed an issue for task-sending API.
- Introduced new APIs for the earbuds product.
- Additional SDK stability improvements and performance optimizations.

## pcjbird 2025-10-13 Version:1.3.1 Build:20251013001

- Introduce the `withBarometricPressure` flag to indicate whether the watch device supports displaying barometric pressure.
- Added `FITCLOUDQRCODE_MONEYRECEIVE_MOMO` and `FITCLOUDQRCODE_MONEYRECEIVE_ZALO` definitions to support Momo and Zalo payment codes.
- Introduce the `allowQueryTranssionInfinixSerialNumber` flag to indicate whether supports querying EUID (Equipment Unique Identifier) for `Transsion Infinix` devices.
- Introduce the `taskId` property to `FitCloudTaskModel`.
- Introduce the `clearTranssionInfinixWatchMenstrualCorrectedDataInfoWithCompletion:` API to clear the menstrual corrected data info for `Transsion Infinix` devices.
- Added `FITCLOUDMN_DINGTALK` definition to support DingTalk notifications.
- Introduce new APIs to query and set the mouse start point preset for the earbud case.
- Changed Transsion Infinix device information query API to retrieve EUID (Equipment Unique Identifier), device model and 4G capability status.
- Introduce new APIs to allow the watch device query the app-side permissions status.
- Added support for GoMore algorithm.
- Added support for switching between different AI conversation models on the watch device.
- Added support for AI watch face related features.
- Introduced new APIs to support parental control features and functionality.
- Modified to prevent multiple initializations of FitCloudKit SDK which could lead to unpredictable results.
- Added support for maximum byte length of AI conversation response text in watch device capabilities.
- Added support for prayer reminder toggle control in Muslim prayer features.
- Added support for synchronizing `Hausa` language as watch display language.
- Added more known manufacturer identifiers.
- Modified APIs related to lover features.
- Introduce new APIs for the Transsion Oraimo Muslim prayer features, see `<FitCloudKit/FitCloudKit+TranssionOraimo.h>`.
- Added support for Xcode 16.3.
- Added support for configuring all switch settings at once for Transsion Oraimo Muslim prayer features.
- Added support for Feishu App notifications.
- Added method `+ (BOOL)isDeviceSupportAppNotification:(FITCLOUDMN) appNotification` to check if the watch device supports notifications for a specific App.
- Introduce new APIs for AI health features.
- Introduce new APIs for world clock features.
- Added support for Microsoft Teams App notifications.
- Added support for querying the supported languages for the watch device.
- Added `onWatchSideToggleTranslatedTextVoicePlayingState:` callback method to notify the watch side toggle translated text voice playing state.
- Introduced new APIs to query game playing statistics.
- Removed the `clearTranssionInfinixWatchMenstrualCorrectedDataInfoWithCompletion:` API for `Transsion Infinix` devices.
- Introduce the `clearTranssionInfinixWatchMenstrualCorrectedStartDayWithCompletion:` API to clear the menstrual corrected start day for `Transsion Infinix` devices.
- Introduce the `clearTranssionInfinixWatchMenstrualCorrectedEndDayWithCompletion:` API to clear the menstrual corrected end day for `Transsion Infinix` devices.
- Updated the GPS location data request callback API from `- (void)onRequestGPSLocationData` to `- (void)onWatchSideRequestGPSLocationDataWithPurpose:` to provide purpose information when the watch requests GPS location data.
- Fixed an issue where loading bound user information would fail.
- Watch face size support for 160x86 square.
- Introduce the `+ (void)setClassroomMode:(FitCloudClassroomModeSettingsModel *_Nonnull)classroomModeSetting completion:(FitCloudCompletionHandler _Nullable)completion` and `+ (void)queryClassroomModeSettingWithCompletion:(void (^_Nullable)(BOOL success, FitCloudClassroomModeSettingsModel *_Nullable classroomModeSetting, NSError *_Nullable error))completion` API for classroom mode settings features.
- Introduce the `+ (void)sendFestivalWishArray:(NSArray<FitCloudFestivalWishTimeModel *> *)wishArray completion:(FitCloudCompletionHandler _Nullable)completion` API for sending festival wishes to the watch device.
- Introduced new APIs for incoming call photo features.
- Added support for Google Pay/Google Drive/JioHotstar/Paytm App notifications.
- Added AQI (Air Quality Index) parameter to weather data.
- Added support for body temperature unit preference settings (Celsius/Fahrenheit).
- Added support for syncing emotion data from the watch device.
- Added support for Khmer localization.
- Watch face size support for 402x402 square.
- Added flag to indicate whether the watch device should disable wechat sports feature.
- Added flag to indicate whether the watch device should disable blood pressure private mode feature.
- Added SDK initialization option `secsPairingRequestConfirmTimeOut` to configure the timeout period for awaiting pairing confirmation from the watch device.
- Added new workout types for watch GPS interconnection: hiking, trail running, and marathon.
- Added a patch to fix an issue on iOS 26 where Realtek-based devices could not complete one-click pairing with the call audio Bluetooth.

## pcjbird 2025-01-21 Version:1.3.0 Build:20250121001

- Add events to notify changes of the workout status on the watch side.
- Fixed the issue with setting and querying the lyrics color for the earphone case.
- Resolved some issues with workout bpmDataArray.
- Rename the API `+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;` to `+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;`.
- Rename the API `+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;` to `+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;`.
- Optimize some data sync debug logs.
- Resolved some issues with querying the information of single type health automatic monitoring settings from the watch.
- Add event `FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY` to notify that the watchface corresponding to a specific watchface Id was removed on the watch side.
- Rename the `onlyDiscoverRecognizedManufacturers` property in FitCloudOption to `onlyDiscoverKnownManufacturers`.
- Optimize some logic in the watch device connection.
- When app launch, remove the invalid connect records which does not bind any account id.
- Mark that the connection record has been unbound, instead of clearing its account binding information.
- When attempting to connect to a watch device marked as unbound, a warning will be issued indicating the possibility of connection failure.
- Enhance the watch device scanning process so that even after uninstalling and reinstalling the current app, the mac address of the watch device can still be obtained during scanning if the watch device was previously connected via bluetooth broadcast scanning with the current app.
- Update the return values of the `FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY` event from the `object` parameter to the `userInfo` parameter.
- Introduce new APIs for the Muslim prayer features, including setting prayer alarm clock, providing islamic calendar events to the watch device, and configuring the kaaba data.
- The workout data of elliptical machine/rowing machine supports returning data for the maximum trigger frequency and minimum trigger frequency.
- Fix the automatic reconnect issue, when the app attemp to disconnect the watch device which is already disconnected but remains in the auto-connect pool.
- Fix some issue with parsing data synced from the watch device in some of the projects.
- Add app location permission information for Muslim prayer kaaba data.
- Introduce the new API `+(void)deleteWatchface:(NSInteger)watchfaceNo completion:(FitCloudCompletionHandler)completion` to delete the watchface on the watch side.
- Add SDK init option `secsConnectTimeOut`, when you initially attempt to manually connect to the peripheral, a connection timeout in seconds is applied. If this timeout is reached, a connection failure error will be returned. Subsequently, the SDK will attempt to reconnect silently.
- Rename the SDK init option `shouldAutoConnect` to `shouldAutoReconnectWhenAppLaunch`.
- Fix some issue with WPAuth commands.
- Introduce the new API `+(void)deleteWatchfaceWithSlotIndex:(NSInteger)slotIndex completion:(FitCloudCompletionHandler)completion` to delete the watchface with slot index on the watch side.
- Introduce the new APIs for toggling iPhone camera requests from the watch side.
- Fix some issues with historical connection records, especially when users modify their phone time.
- Introduce the new APIs for handling the map navigation snapshot request from the watch side.
- Add support for watchface size 240x320 square and 184x276 square.
- New OTA start command added information about the file type to be upgraded.
- Introduce the new API `+(void)clearWatchGPSFileWithCompletion:(FitCloudCompletionHandler _Nullable)completion` to delete the GPS epo file on the watch side.
- Support `My Task` related commands for Huashengda.
- Added `FITCLOUDMN_ZALO` notification definition.
- Add the `FITCLOUDEVENT_COMMAND_EXEC_TIMEOUT_NOTIFY` event to notify that the command execution timed out.
- Add support for translation features.
- Add the `queryOtherModulesFirmwareVersionsWithCompletion:` API to query the firmware version of other modules.
- Added the original opus voice data return for LLM voice data and translation voice data.
- Filter out known invalid GPS points at the SDK layer.
- Fixed an issue where setting favorite contacts would fail when contact names contained certain special characters.
- Introduce the API `+(void)reportDeviceMacAddressTranslateFeatureNotRegistered:(FitCloudCompletionHandler _Nullable)completion` to notify the watch device that the current MAC address is not registered with the translation service provider.
- Renamed several APIs related to language synchronization.
- Changed several APIs related to callbacks to the App when writing GPS files to the watch device during GPS file upgrade process.
- Changed the logic of querying the state of the GPS file on the watch device: If the validity period is less than 3 days, it is considered that the GPS file needs to be updated.
- Fixed a potential crash issue that could occur when client apps do not integrate the FitCloudKit.bundle resource bundle.

## pcjbird 2024-09-30 Version:1.2.9 Build:20240930001

- Added support for Skyworth PV data, @see withSkyworthPV.
- Added some debugging logs.
- Supported cricket match data commands, @see withCricketMatch.
- Added support for synchronizing specified time to the watch.
- GPS & EPO support, @see withGPSEpo.
- Supported NetEase Cloud Music.
- Watch face size support for 228x460 square.
- Added habit formation types.
- Added command to get the list of supported schedule types for the watch, @see canGetSupportedSchedules.
- Supported setting and getting the medal list, @see withMedals.
- Supported motion-sensing games, @see withMotionSensingGame.
- Modified habit formation protocol.
- Watch face size support for 390x390 circular.
- Added navigation information synchronization support, @see naviGuideSupported.
- Watch face size support for 390x450 square.
- Watch face size support for 286x240 square.
- Added support for album push, @see allowPhotoPush.
- Added support for eBook push, @see allowEBookPush.
- Added snooze support, @see withSnooze.
- Added REM sleep support, @see withREM.
- Supported more than 10 frequently used contacts, @see allowHugeCountFavContacts.
- Added e-wallet functionality.
- Watch face size support for 192x490 ellipse.
- Added indicator for whether heart rate monitoring spans across days, @see allowHeartRateMonitoringAcrossDays.
- Added support for querying device capabilities, @see allowQueryDeviceCapacities, allConfig.deviceCapacities.
- Added method to get workout display data item information, @see withDisplayConfigInWorkoutData.
- Added FitCloudOption for automatic system language synchronization, @see autoSyncSystemLang.
- New OTA upgrade support, @see withNewOTA.
- Entering DFU mode now returns error type `FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE`.
- Added independent switch settings and query functionality for health monitoring timing, @see allowSingleHTMSettings.
- Added static and dynamic heart rate low alarm functionality, @see withHRLowAlarm.
- Weather settings now include UV index functionality.
- Added customized weather types for LiSheng, @see FITCLOUDWEATHERTYPE_CLOUDYINEVENING/FITCLOUDWEATHERTYPE_CLEARINEVENING/FITCLOUDWEATHERTYPE_EVENINGSHOWERS.
- Added the number of weather types supported by the device capabilities.
- Added support for setting and querying extreme heart rates for specific projects.
- Added software version information query for LiSheng, only available for that client, version data to be parsed by the client, @see FitCloudKit+Haylou.h.
- Added support for large models, @see withLLM.
- Added query functionality for LiSheng watch SN information, only available for that client, @see FitCloudKit+Haylou.h.
- Modified binding API, added random code; if there is no random code, fill in nil.
- New binding failure error: "The watch needs to be reset to factory settings to bind."
- Added functionality to query the current language setting of the watch.
- Added notification for the watch performing the stop find watch action, @see FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY.
- Modified stop find watch API name; added stop find watch functionality.
- Daily exercise goal now includes setting exercise duration target.
- Added functionality to set emergency contacts, @see withEmergencyContact.
- Added resting heart rate query functionality, @see withRestingHR.
- Added functionality to set personalized reminders, @see withPersonalizedReminder, @see FITCLOUDDEVICECAPACITY.
- Health data and step data now include exercise duration data.
- Message notifications now include Gmail/Outlook/WhatsApp Business.
- Weather settings modified visibility precision to meters.
- Added direct DFU upgrade (DFU upgrade without entering DFU mode); directly use `[FitCloudKit directDFUPeripheral]` to pass peripherals to FitCloudDFUKit, available only for specific client watches.
- Added hardware platform flags, @see FITCLOUDHARDWARE_8773, FITCLOUDHARDWARE_568X.
- The maximum length for e-wallet names has been changed to 32 bytes.
- Corrected the vendor identifier for Transsion, supporting MAC address parsing.
- Added couple functionality, @see `[FitCloudKit isDeviceSupportFeature:FITCLOUDDEVICEFEATURE_LOVERS]`.
- Supported returning calorie data for GPS interconnected exercises.
- New OTA added frame retransmission mechanism.
- Watch face size support for 320x172 square.
- Watch face size support for 385x320 square.
- Updated new OTA error codes.
- To prevent unrealistic user data causing algorithm issues, user input will be corrected before being sent to the watch.
- Optimized switching watch faces and modifying corresponding component style APIs.
- Optimized the watch's return of watch face UI information.
- Removed exercise type definitions from SDK, to be handled at the app level; for exercise type mapping table, contact the corresponding business or product manager.
- Added support for returning REM sleep data.
- Added support for setting 24-hour weather information, only some watches support this.
- Added support for pool swimming and open water swimming exercise data synchronization.
- Watch face size support for 480x480 circular.
- Watch face size support for 194x368 square.
- Chip and object GPS support.
- ANCS notification extension.
- Headphone case project support.
- Added support for synchronizing jump rope/elliptical/rowing machine related exercise extended data.
- Added support for shielding enhanced heart rate measurement.
- Supported female health features for Transsion Infinix projects.
- Supported obtaining debugging logs from the watch, only some watches support this.
- `FitCloudKitConnectRecord` now includes MAC address.
- Introduced event “FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY,” indicating the watch has manually terminated a measurement initiated by the app.
- Exercise heart rate data is provided in a separate data list, @see bpmDataArray.
- Added callback to notify the app when the watch enters or exits large language model functionality.
- Resolved some connection issues when switching between multiple devices.
- Watch face size support for 360x360 square/296x240 square.
- Introduced new API `+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` to allow the main program to connect and bind the watch device with a single API call.
- Renamed the `time` property in FitCloudKitConnectRecord to `latestConnectTime`, and renamed the `bindTime` property to `userBindTime`.
- Added WeChat payment certification functionality for the watch.
- Added functionality to start and stop laser measurement, and to query the laser measurement status.

## pcjbird 2023-05-30 Version:1.2.8 Build:202305300001

- Watch face size support for 410x502 square/416x416 circular/240x288 square.
- Added custom label functionality, @see withCustomLabels.
- Supported Alipay IoT, @see allowAliot.
- Bluetooth connection supports setting whether to use one-click dual connection with classic Bluetooth (BT), @see allowConnectWithBT.
- Added method to obtain relevant manufacturer information and parameters through broadcast data, @see FitCloudManufacturer.
- Supported GPS data transmission for watch exercise, @see FitCloudGPSRecordObject.
- Watch face size support for 340x340 circular.
- Added specified supported payment codes and business cards; only the specified payment codes and business cards should be displayed in the App's push entrance, @see specifySupportedMoneyReceiveAndBusinessQRCode.
- Modified habit formation commands.
- Added power-saving mode settings, @see withPowerSavingMode & allowPowerSavingModePeriod.
- Added timestamp parameter for daily goal settings.
- Adjusted Alipay IoT security certification commands.
- Modified automatic login logs; userId now supports String.
- Modified command parsing for getting watch UI information, compatible with firmware versions.
- Updated and added a large number of exercise type definitions.
- Improved SDK stability.

## pcjbird 2022-12-30 Version:1.2.7 Build:202212300001

- Added functionality to disable the sleep module.
- Added nucleic acid code push functionality, @see allowNucleicAcidQRCode.
- Weather now includes atmospheric pressure/wind strength/visibility information.
- Added commands related to habit formation, @see allowHabits.
- Added payment codes: Paytm/PhonePe/Google Wallet/BHTM, added business cards: Email/Phone/LinkedIn, @see showAdditionalQRCodeTransfer.
- Added notification to the watch when phone ringing playback ends, compatible with Bluetooth call watches.
- Added command to get daily exercise goals.
- Optimized obtaining MTU values for peripherals.

## pcjbird 2022-09-20 Version:1.2.6 Build:202209200001

- Fixed GPS interconnection motion command issues.
- Added true blood pressure measurement based on barometric pump (supported by some watches).
- Manual measurement data synchronization supported by some watches.
- SOS request initiation supported by some watches.
- Added support for starting and stopping third-party peripherals.
- Added vibration parameter settings for watch startup.
- Added command to delete messages stored on the watch.
- Added command to cancel the current message display on the watch.
- Added game lock settings.
- Login/binding command added iOS system version flag.
- Added retrieval of up to three highest game records (supported by some watches).
- Fixed true blood pressure data synchronization issues.
- Modified GPS interconnection commands.
- Added game ranking trend settings (supported by some watches).
- Updated SDK alarm clock list cache when retrieving alarm clock list.
- Updated SDK error code translations.
- Handled exercise health data to prevent data loss.
- Added flag to disable modular watch face in the app @see disableWatchfaceModularInApp.
- Added watch face size support of 240x296 square.
- Improved SDK stability.

## pcjbird 2022-01-26 Version:1.2.5 Build:202201260001

- Added definitions for cricket, free exercise, strength training, indoor walking, indoor cycling, dumbbells, dancing, hula hoop, golf, long jump, sit-ups, and volleyball.
- Added watch GPS interconnection sports.
- Added wake-up APP camera function (use with caution due to defects).
- Added blood pressure and heart rate alarm function device support checks.
- Added watch preference setting for achieving exercise goals (steps/distance/calories) reminders.
- Fixed issues with large amounts of data for common contact commands.
- Fixed potential crashes when turning off Bluetooth during OTA.
- Added support for payment codes and business card QR code pushing.
- Fixed unbinding when the watch disconnects; it may reconnect when the watch is near the phone.
- Fixed issues with Bluetooth disconnect during ECG measurement possibly causing incorrect reconnections.
- Added audio Bluetooth name return when call watch binding fails.
- Added Hindi language support.

## pcjbird 2021-10-12 Version:1.2.4 Build:202110120001

- Added flag for supporting game skin push.
- Added flag for supporting notifications from Apple Music, Zoom & TikTok.
- Added flag for supporting QR code connection.
- Added hardware identifier `FITCLOUDHARDWARE_DFUSHOULDSILENTMODE`.
- Added definitions for Tetris, Sudoku, and quiz games.
- Added reasons for binding failure in QR code binding project (watch actively canceled / watch timeout).
- Added methods to get/set screen time, brightness, vibration, etc.
- Added flag to disable custom watch face functionality.
- Added callback for when the watch leaves the Find Phone feature interface.
- Added preference setting for watch vibration when Bluetooth disconnects.
- Fixed issues with synchronizing ECG data when the watch disconnects.
- Added methods to retrieve original screen resolution information (LCD width/height, circular screen, corner size, etc.), supported by some firmware.
- Expanded Nordic platform watch face numbering to 3 bytes.
- Fixed issue where only 3 game skins could be retrieved.
- Modified maximum file size calculation rules for watch faces/game skins.
- Modified weather hardware function flag definitions.
- Added flag for whether the watch supports exercise modes (DIY) firmware push.
- Added methods to get the list of supported exercise mode types for devices/current exercise mode type list, supported by some watches.

## pcjbird 2021-07-20 Version:1.2.3 Build:202107200001

- Added pressure index measurement, supported by some watches.
- Fixed issues with schedule setting commands.
- Fixed issues with lock screen password setting commands.
- Added watch face size support for 280x240 square / 200x320 square / 368x448 square / 320x390 square.
- Added modular (component-based) watch face support.
- Fixed issues with schedule retrieval commands.
- Supported custom setting of watch language. @note: If you wish to set the watch's language during SDK initialization, @see watchPreferLang for FitCloudOption. If you want to change the watch's language dynamically while the app is running, call setSmartWatchLanguage:completion:. Additionally, the original syncSystemLanguageWithBlock will also be affected; if you customize the watch language, the original syncSystemLanguageWithBlock will also sync the customized watch language setting.
- Added setting to allow watch to set schedule, only effective when the watch supports schedule functionality.
- Supported conversion of self-scanned peripherals to connectable peripherals.
- Updated GUI structure-related protocol.
- Next-generation vendor names supported, confirming that the filtering of the Bluetooth name's first letter "H" is not needed.
- Fixed issue where changing watch faces could result in the loss of watch face module information.
- Multi-watch face push supports getting each watch face's maximum push firmware size in kB.
- Supported Nordic chips.
- Added methods to get the types of games supported by the watch, supported by some watches.
- Added methods to retrieve game skin information for all games on the watch, supported by some watches.
- Added watch face size support for 172x320 square / 454x454 circular / 128x220 square.
- Added `+(void)ignoreConnectedPeripheral:(BOOL)silent;` adding silent parameter.
- Added `FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY` notification, suggesting users enter system settings to remove pairing information with the watch, kill the App process, and restart the App. Refer to its definition for specifics. @note: This notification may be sent continuously, and the application layer needs to avoid prompting users repeatedly to prevent confusion.

## pcjbird 2021-02-05 Version:1.2.2 Build:202102050001

- Added weather push switch, supported by some watches.
- Added notification for the watch APP's location service status.
- Added handwashing reminder feature.
- Added watch face size support for 240x280 square.
- Data parsing abnormal handling; entries that are too large are discarded and no longer parsed.
- Added lock screen password setting, supported by some watches.
- Added schedule reminder setting, supported by some watches.
- Added notifications for Hike and YouTube, supported by some watches.
- Added watch face size support for 348x442 square.
- Multi-watch face push information retrieval supported.
- Added definitions for exercise types.

## pcjbird 2020-10-30 Version:1.2.1 Build:202010300001

- FitCloudOption supports preferSystemLocale option; when set to TRUE, the watch will sync the iOS system language setting, otherwise, it will sync the current APP's language setting, defaulting to FALSE. @note: Due to system limitations, if you manually modify the APP's language, this option will also become ineffective.
- Fixed issues with incorrect sleep debug data responses.
- Supported setting health monitoring intervals, requires watch support, @see allowSetHealthMonitorInterval.
- Supported setting sedentary reminder intervals, requires watch support, @see allowSetLSRInterval.
- Supported setting weather forecasts, requires watch support, @see allowWeatherForecast.
- Added weather update time, adjusted maximum supported days for weather forecasts to 14 days.
- Fixed issues with incorrect health monitoring/sedentary reminder interval settings.
- Fixed issues with incorrect watch flag parsing.
- Added Albanian language support.
- Added Turkish and Ukrainian language support.
- Fixed issues with syncing Korean language to the watch.
- Patch: When allowShowAdditionalReminder flag is true, allowShowMailReminder/allowShowTelegramAndViberReminder are forced to true.

## pcjbird 2020-07-18 Version:1.2.0 Build:202007180001

- Supported notification for the watch to exit camera mode.
- Added female health feature.
- Added protective reminder feature.
- Fixed issues with Hungarian language not syncing to the watch.
- Added method to set custom field key1 for broadcast data, specific to Huashida.
- Fixed issues with incorrect age setting during user profile setup.
- Added method to retrieve today's sleep debug data.
- Fixed issues with incorrect age setting.
- Added latest health measurement data including temperature data (requires watch support for temperature).
- Added related notes on new watch face size support.
- Supported setting all localized languages defined by the SDK to the watch.

## pcjbird 2020-05-15 Version:1.1.9 Build:202005150001

- Supported temperature measurement, supported by some watches.

## pcjbird 2020-04-25 Version:1.1.8 Build:202004250001

- Fixed potential issues where unbinding might not disconnect properly.
- Fixed issues where the watch disconnecting during automatic login might lead to notifications about being bound to another phone or already unbound.
- Fixed issues where timeout during command execution could result in missing the next command.
- Fixed timeout issues when syncing large amounts of health data.
- Cleared battery information after unbinding.
- Supported common contacts, supported by some watches.
- Added exercise modes including elliptical, yoga, table tennis, and jump rope.
- Fixed issues with incorrect logic handling when ECG startup fails.
- Fixed issues where connection timeout would not execute timeout logic.

## pcjbird 2020-02-25 Version:1.1.7 Build:202002250001

- Added Slovak and Hungarian language support.
- Fixed issues with sleep data quality possibly returning illegal values.
- Canceled automatic unbinding logic, added notifications for the watch being bound by another phone or already unbound @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY.
- All callbacks and notifications are now called in the Global Queue; if you want to update the UI in the callback or notification, be sure to switch to the Main Queue.
- External calls to disconnect will not automatically reconnect.
- Added FITCLOUDUSERBINDSTATUS_KICKEDOUT user binding status.
- Added FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY notification.
- Added support for the new sleep format @see newSleepDataFormat.
- Log information supports viewing the complete data for large packets.
- The watch actively changes settings (e.g., wrist raise wake-up, notification settings, etc.) will update to the App as needed @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY.
- Modified methods for retrieving watch face information.
- Other improvements.

## pcjbird 2019-11-21 Version:1.1.6 Build:201911210001

- Fixed issues with the watch face UI information interface not responding correctly.
- After unbinding the user, canceled the automatic reconnection of the current watch connection record.
- Optimized the watch connection initialization process to prevent unexpected reconnections.
- Adjusted watch hardware-related information to be read-only.
- The UserId of the bound user has been changed from integer to string type.
- Added methods to retrieve the last health measurement data (heart rate/blood oxygen/blood pressure), supported by some watches, @see allowRetrieveLatestMeasurementData.
- Modified methods to enter and exit firmware upgrade mode; now you must manually call to enter and exit firmware upgrade mode before and after every firmware upgrade operation, applicable to both regular firmware upgrades and watch face pushes.
- Added DFU mode reconnection success notification, typically used for waiting for watch face pushes/normal firmware upgrades after the watch restarts.
- Improved SDK stability.

## pcjbird 2019-11-13 Version:1.1.5 Build:201911130001

- Added Do Not Disturb mode (supported by some watches @see allowDNDMode).

## pcjbird 2019-10-24 Version:1.1.4 Build:201910240001

- Real-time measurement moment modified to second precision.
- Fixed issues with synchronizing data moments not exceeding the current synchronization time.

## pcjbird 2019-10-16 Version:1.1.3 Build:201910160001

- Step data now incorporates distance & calorie new algorithms.
- Added methods to retrieve the last binding time of the user.
- Added settings for heart rate and blood pressure alarms.
- Added options for Snapchat message reminders.
- Device scanning cancels device name filtering.
- Real-time ECG measurement added logic for the watch to end actively.
- Added methods to retrieve watch face UI information.
- Added methods to retrieve cached broadcast data from the watch.
- Added notifications for Bluetooth name changes and Bluetooth RSSI changes.
- Improved SDK stability.
- Avoid ambiguity; `+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals` changed to `+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals`.

## pcjbird 2019-08-19 Version:1.1.2 Build:201908190002

- Fixed issues with the timing of Bluetooth connection start notifications.

## pcjbird 2019-08-19 Version:1.1.1 Build:201908190001

- Fixed issues where unbinding the watch did not clear the previous bound watch's MAC address.
- Added notifications for the start and end of basic synchronization operations after binding/login success.
- Fixed issues with SDK initialization options shouldAutoConnect not functioning.

## pcjbird 2019-08-12 Version:1.1.0 Build:201908120001

- Supported background Bluetooth data synchronization.

## pcjbird 2019-07-21 Version:1.0.9 Build:201907210001

- Supported retrieval of current SDK version information.

## pcjbird 2019-07-20 Version:1.0.8 Build:201907200001

- Fixed issues where setting the iPhone calendar to a Buddhist or Japanese calendar caused failure in syncing time with the watch.
- Optimized watch reconnection mechanism.

## pcjbird 2019-06-28 Version:1.0.7 Build:201906280001

- Fixed issues where unable to retrieve notification settings.

## pcjbird 2019-06-27 Version:1.0.6 Build:201906270001

- Added MAC address data for external devices discovered during scanning.

## pcjbird 2019-06-25 Version:1.0.5 Build:201906250001

- Modified support for setting exercise goals.

## pcjbird 2019-05-17 Version:1.0.4 Build:201905170001

- Added supported languages for the watch.

## pcjbird 2019-05-01 Version:1.0.3 Build:201905010001

- First release of the SDK version.
