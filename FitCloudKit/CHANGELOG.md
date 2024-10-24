# CHANGELOG

## V1.3.0-beta.24 build20241024005 (2024-10-24)

- Fix some issue with WPAuth commands.

## V1.3.0-beta.23 build20241024004 (2024-10-24)

- Optimize some logic in the watch device connection.

## V1.3.0-beta.22 build20241024003 (2024-10-24)

- Fix some issue with Muslim prayer commands.

## V1.3.0-beta.21 build20241024002 (2024-10-24)

- Add more debug logs.

## V1.3.0-beta.20 build20241024001 (2024-10-24)

- Add the connect timeout SDK option, when you initially attempt to manually connect to the peripheral, a connection timeout in seconds is applied. If this timeout is reached, a connection failure error will be returned. Subsequently, the SDK will attempt to reconnect silently.
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
