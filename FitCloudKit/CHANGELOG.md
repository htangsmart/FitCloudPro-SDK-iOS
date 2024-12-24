# CHANGELOG

## 1.3.0-beta.56 build20241224001 (2024-12-24)

- Introduce the API `+(void)reportDeviceMacAddressTranslateFeatureNotRegistered:(FitCloudResultHandler _Nullable)completion` to notify the watch device that the current MAC address is not registered with the translation service provider.

## 1.3.0-beta.55 build20241223002 (2024-12-23)

- Fixed an issue where setting favorite contacts would fail when contact names contained certain special characters.

## 1.3.0-beta.54 build20241223001 (2024-12-23)

- Filter out known invalid GPS points at the SDK layer.

## 1.3.0-beta.53 build20241220003 (2024-12-20)

- Added the original opus voice data return for LLM voice data and translation voice data.

## 1.3.0-beta.52 build20241220002 (2024-12-20)

- Optimized the translation feature related log printing.

## V1.3.0-beta.51 build20241220001 (2024-12-20)

- Optimized the handling of ending reception for LLM voice data and translation voice data to prevent repeated command sending from the watch side.

## V1.3.0-beta.50 build20241217001 (2024-12-17)

- Add the `queryOtherModulesFirmwareVersionsWithCompletion:` API to query the firmware version of other modules.

## V1.3.0-beta.49 build20241212002 (2024-12-12)

- Modified command IDs related to translation functionality.

## V1.3.0-beta.48 build20241212001 (2024-12-12)

- Fixed the command ID that notifies the app when the smartwatch enters or exits the LLM functionality.

## V1.3.0-beta.47 build20241211001 (2024-12-11)

- Restored error messages for low battery OTA failures in Bulgarian, Ukrainian and Urdu languages.

## V1.3.0-beta.46 build20241209001 (2024-12-09)

- Optimized some error return information.

## V1.3.0-beta.45 build20241207002 (2024-12-07)

- Add support for translation features.

## V1.3.0-beta.44 build20241207001 (2024-12-07)

- Add the `FITCLOUDKITERROR_CONNECTIONTIMEOUT` error definition.

## V1.3.0-beta.43 build20241205002 (2024-12-05)

- Add the `FITCLOUDEVENT_COMMAND_EXEC_TIMEOUT_NOTIFY` event to notify that the command execution timed out.

## V1.3.0-beta.42 build20241205001 (2024-12-05)

- Optimized the parsing of workout BPM data.

## V1.3.0-beta.41 build20241204003 (2024-12-04)

- Fixed the issue with reading the GPS EPO upgrade file type for ICOE.

## V1.3.0-beta.40 build20241204002 (2024-12-04)

- Optimized some error description translations.

## V1.3.0-beta.39 build20241204001 (2024-12-04)

- Optimized some error description translations.

## V1.3.0-beta.38 build20241130001 (2024-11-30)

- Optimized some error description translations.

## V1.3.0-beta.37 build20241126001 (2024-11-26)

- Support `My Task` related commands for Huashengda.
- Added `FITCLOUDMN_ZALO` notification definition.
- Change the logic for parsing the new OTA module upgrade confirmation command as an error code when the data length is 1.

## V1.3.0-beta.36 build20241123002 (2024-11-23)

- Introduce the new API `+(void)clearWatchGPSFileWithCompletion:(FitCloudResultHandler _Nullable)completion` to delete the GPS epo file on the watch side.

## V1.3.0-beta.35 build20241123001 (2024-11-23)

- Fixed some issues with the watch device feature flags and capability indicators.
- Optimized some error description translations.

## V1.3.0-beta.34 build20241120001 (2024-11-20)

- New OTA start command added information about the file type to be upgraded.

## V1.3.0-beta.33 build20241119001 (2024-11-19)

- Add support for watchface size 240x320 square and 184x276 square.

## V1.3.0-beta.32 build20241116001 (2024-11-16)

- Some code and comment optimizations.

## V1.3.0-beta.31 build20241107001 (2024-11-07)

- Optimize the camera live preview and the map navigation snapshot commands.

## V1.3.0-beta.30 build20241106002 (2024-11-06)

- Change the camera live preview commands to align with the watch device side.

## V1.3.0-beta.29 build20241106001 (2024-11-06)

- Rename some map navigation APIs.
- Upon reaching the destination during navigation, now allow sending the endpoint name to the watch side.

## V1.3.0-beta.28 build20241105001 (2024-11-05)

- Introduce the new APIs for handling the map navigation snapshot request from the watch side.

## V1.3.0-beta.27 build20241030001 (2024-10-30)

- Fix some issues with historical connection records, especially when users modify their phone time.

## V1.3.0-beta.26 build20241026001 (2024-10-26)

- Introduce the new APIs for toggling iPhone camera requests from the watch side.

## V1.3.0-beta.25 build20241025001 (2024-10-25)

- Introduce the new API `+(void)deleteWatchfaceWithSlotIndex:(NSInteger)slotIndex completion:(FitCloudResultHandler)completion` to delete the watchface with slot index on the watch side.

## V1.3.0-beta.24 build20241024005 (2024-10-24)

- Fix some issue with WPAuth commands.
- Fix some issue with SDK init option `secsConnectTimeOut`.

## V1.3.0-beta.23 build20241024004 (2024-10-24)

- Optimize some logic in the watch device connection.

## V1.3.0-beta.22 build20241024003 (2024-10-24)

- Fix some issue with Muslim prayer commands.

## V1.3.0-beta.21 build20241024002 (2024-10-24)

- Add more debug logs.

## V1.3.0-beta.20 build20241024001 (2024-10-24)

- Add SDK init option `secsConnectTimeOut`, when you initially attempt to manually connect to the peripheral, a connection timeout in seconds is applied. If this timeout is reached, a connection failure error will be returned. Subsequently, the SDK will attempt to reconnect silently.
- Rename the SDK init option `shouldAutoConnect` to `shouldAutoReconnectWhenAppLaunch`.

## V1.3.0-beta.19 build20241023003 (2024-10-23)

- Add check whether the watch device support the Muslim prayer commands.
- Add check whether the watch device support the watchface deletion commands.

## V1.3.0-beta.18 build20241023002 (2024-10-23)

- Add app location permission information for Muslim prayer kaaba data.
- Introduce the new API `+(void)deleteWatchface:(NSInteger)watchfaceNo completion:(FitCloudResultHandler)completion` to delete the watchface on the watch side.

## V1.3.0-beta.17 build20241023001 (2024-10-23)

- Fix some issue with parsing data synced from the watch device in some of the projects.

## V1.3.0-beta.16 build20241021001 (2024-10-21)

- Fix the automatic reconnect issue, when the app attemp to disconnect the watch device which is already disconnected but remains in the auto-connect pool.

## V1.3.0-beta.15 build20241020002 (2024-10-20)

- The workout data of elliptical machine/rowing machine supports returning data for the maximum trigger frequency and minimum trigger frequency.

## V1.3.0-beta.14 build20241020001 (2024-10-20)

- Introduce new APIs for the Muslim prayer features, including setting prayer alarm clock, providing islamic calendar events to the watch device, and configuring the kaaba data.

## V1.3.0-beta.13 build20241019002 (2024-10-19)

- Update the return values of the `FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY` event from the `object` parameter to the `userInfo` parameter.

## V1.3.0-beta.12 build20241019001 (2024-10-19)

- Enhance the watch device scanning process so that even after uninstalling and reinstalling the current app, the mac address of the watch device can still be obtained during scanning if the watch device was previously connected via bluetooth broadcast scanning with the current app.

## V1.3.0-beta.11 build20241014002 (2024-10-14)

- When attempting to connect to a watch device marked as unbound, a warning will be issued indicating the possibility of connection failure.

## V1.3.0-beta.10 build20241014001 (2024-10-14)

- Mark that the connection record has been unbound, instead of clearing its account binding information.

## V1.3.0-beta.9 build20241013003 (2024-10-13)

- When app launch, remove the invalid connect records which does not bind any account id.

## V1.3.0-beta.8 build20241013002 (2024-10-13)

- Add more debug logs.
- Optimize some logic in the watch device connection.

## V1.3.0-beta.7 build20241013001 (2024-10-13)

- Add more debug logs.
- Rename the `onlyDiscoverRecognizedManufacturers` property in FitCloudOption to `onlyDiscoverKnownManufacturers`.

## V1.3.0-beta.6 build20241012001 (2024-10-12)

- Add event `FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY` to notify that the watchface corresponding to a specific watchface Id was removed on the watch side.

## V1.3.0-beta.5 build20241011002 (2024-10-11)

- Resolved some issues with querying the information of single type health automatic monitoring settings from the watch.

## V1.3.0-beta.4 build20241011001 (2024-10-11)

- Rename the API `+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;` to `+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;`.
- Rename the API `+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;` to `+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;`.
- Optimize some data sync debug logs.

## V1.3.0-beta.3 build20241010002 (2024-10-10)

- Resolved some issues with workout bpmDataArray.

## V1.3.0-beta.2 build20241010001 (2024-10-10)

- Fixed the issue with setting and querying the lyrics color for the earphone case.

## V1.3.0-beta.1 build20241008001 (2024-10-08)

- Add events to notify changes of the workout status on the watch side.

## V1.2.9 build20240930001 (2024-09-30)

- Release FitCloudKit V1.2.9 build20240930001.

## V1.2.9-beta.195 build20240929001 (2024-09-29)

- Correct the lcd No.32 screen's shape from square to ellipse.

## V1.2.9-beta.194 build20240928001 (2024-09-28)

- Add error codes localization in North Korean.

## V1.2.9-beta.193 build20240926001 (2024-09-26)

- Update the `mainProjNo` and `subProjNo` property in FitCloudPeripheral and FitCloudManufacturer to return uppercase string.

## V1.2.9-beta.192 build20240924002 (2024-09-24)

- Add features to start and stop laser measurements, as well as to query the status of laser measurements.

## V1.2.9-beta.191 build20240924001 (2024-09-24)

- Add customer ID information for mapping weather types when the watch device returns its configurations. If nil, `FITCLOUDWEATHERTYPE` will be used as the weather types.

## V1.2.9-beta.190 build20240923001 (2024-09-23)

- Fixed the issue with setting and querying the lyrics color for the earphone case.

## V1.2.9-beta.189 build20240921001 (2024-09-21)

- Rename the `weathertype` property in FitCloudWeatherObject, FitCloudWeatherForecast and FitCloudHourWeatherObject to `weatherType`, and change its type from `WEATHERTYPE` to `Byte`.
  Now, allow different customers to use their own weather types. And our app will utilize `FITCLOUDWEATHERTYPE` as weather types.

## V1.2.9-beta.188 build20240920005 (2024-09-20)

- Add options to discover all Bluetooth devices, including those from unknown manufacturers.

## V1.2.9-beta.187 build20240920004 (2024-09-20)

- Optimize the timing for sending the `FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY` event.

## V1.2.9-beta.186 build20240920003 (2024-09-20)

- Add more debug logs.

## V1.2.9-beta.185 build20240920002 (2024-09-20)

- Optimize the discovering priority of Bluetooth characteristics.

## V1.2.9-beta.184 build20240920001 (2024-09-20)

- Adjust the internal timing of automatic binding and login command calls within the SDK after the watch device is connected.
- Optimize the processing of the random code when binding the watch device.

## V1.2.9-beta.183 build20240918002 (2024-09-18)

- Resolved some issues with workout bpmDataArray.

## V1.2.9-beta.182 build20240918001 (2024-09-18)

- Add the `formatedProjNo`, `formatedFirmwareVersion`, `uiVersion`, `screenResolution` and `screenShape` property for FitCloudKitConnectRecord.
- Introduce the API `+(FITCLOUDWATCHCONNECTIONFLAG) connectionFlag;` to indicate whether the current connection is established when the watch device is bound or in the process of reconnecting.

## V1.2.9-beta.181 build20240914001 (2024-09-14)

- Add the `mainProjNo` and `subProjNo` property for FitCloudPeripheral and FitCloudManufacturer.

## V1.2.9-beta.180 build20240913003 (2024-09-13)

- Add WPAuth bridge data features for authenticating WeChat Pay on the watch device.

## V1.2.9-beta.179 build20240913002 (2024-09-13)

- Resolve the issue of incorrect response to obtaining independent settings commands for health periodic monitoring.

## V1.2.9-beta.178 build20240913001 (2024-09-13)

- If the alarm clock label length exceeds 32 bytes, the SDK will automatically truncate it to meet the length limit.

## V1.2.9-beta.177 build20240911001 (2024-09-11)

- When you invoke `+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` to connect and bind the watch device, if you have previously connected the watch device, the SDK will remove this historical connection record first.

## V1.2.9-beta.176 build20240910001 (2024-09-10)

- Introduce the API `+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` to allow the owner app connect and bind the watch device with just one API call.
- Rename the `time` property in FitCloudKitConnectRecord to `latestConnectTime` and the `bindTime` property to `userBindTime`.

## V1.2.9-beta.175 build20240909001 (2024-09-09)

- Resolved some issues with connections when switching between multiple devices.
- The watch face size supports 360x360 square and 296x240 square.

## V1.2.9-beta.174 build20240904002 (2024-09-04)

- Fixed crash issue when querying historical average resting heart rate in days.

## V1.2.9-beta.173 build20240904001 (2024-09-04)

- Fixed some logging print errors.

## V1.2.9-beta.172 build20240830002 (2024-08-30)

- Add callbacks to notify the app when the smartwatch enters or exits the LLM functionality.

## V1.2.9-beta.171 build20240830001 (2024-08-30)

- The exercise heart rate data is provided in a separate data list. Now `hrExcercise` has been removed from old item data model.

## V1.2.9-beta.170 build20240829001 (2024-08-29)

- Store the MAC address within `FitCloudKitConnectRecord`.
- Introduce the event `FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY` to signal that the watch side has manually terminated the measurement initialized by the app side.
