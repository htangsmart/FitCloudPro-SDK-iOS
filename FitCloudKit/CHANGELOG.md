# CHANGELOG

## V1.3.0-beta.1 build20241008001 (2024-10-08)
    1. Add events to notify changes of the workout status on the watch side.
    
## V1.2.9 build20240930001 (2024-09-30)
    1. Release FitCloudKit V1.2.9 build20240930001.

## V1.2.9-beta.195 build20240929001 (2024-09-29)
    1. Correct the lcd No.32 screen's shape from square to ellipse.
    
## V1.2.9-beta.194 build20240928001 (2024-09-28)
    1. Add error codes localization in North Korean.

## V1.2.9-beta.193 build20240926001 (2024-09-26)
    1. Update the `mainProjNo` and `subProjNo` property in FitCloudPeripheral and FitCloudManufacturer to return uppercase string.

## V1.2.9-beta.192 build20240924002 (2024-09-24)
    1. Add features to start and stop laser measurements, as well as to query the status of laser measurements. 

## V1.2.9-beta.191 build20240924001 (2024-09-24)
    1. Add customer ID information for mapping weather types when the watch device returns its configurations. If nil, `FITCLOUDWEATHERTYPE` will be used as the weather types.

## V1.2.9-beta.190 build20240923001 (2024-09-23)
    1. Fixed the issue with setting and querying the lyrics color for the earphone case.

## V1.2.9-beta.189 build20240921001 (2024-09-21)
    1. Rename the `weathertype` property in FitCloudWeatherObject, FitCloudWeatherForecast and FitCloudHourWeatherObject to `weatherType`, and change its type from `WEATHERTYPE` to `Byte`. 
       Now, allow different customers to use their own weather types. And our app will utilize `FITCLOUDWEATHERTYPE` as weather types.

## V1.2.9-beta.188 build20240920005 (2024-09-20)
    1. Add options to discover all Bluetooth devices, including those from unknown manufacturers.

## V1.2.9-beta.187 build20240920004 (2024-09-20)
    1. Optimize the timing for sending the `FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY` event.
                        
## V1.2.9-beta.186 build20240920003 (2024-09-20)
    1. Add more debug logs.
    
## V1.2.9-beta.185 build20240920002 (2024-09-20)
    1. Optimize the discovering priority of Bluetooth characteristics.
    
## V1.2.9-beta.184 build20240920001 (2024-09-20)
    1. Adjust the internal timing of automatic binding and login command calls within the SDK after the watch device is connected.
    2. Optimize the processing of the random code when binding the watch device.

## V1.2.9-beta.183 build20240918002 (2024-09-18)
    1. Resolved some issues with workout bpmDataArray.
    
## V1.2.9-beta.182 build20240918001 (2024-09-18)
    1. Add the `formatedProjNo`, `formatedFirmwareVersion`, `uiVersion`, `screenResolution` and `screenShape` property for FitCloudKitConnectRecord.
    2. Introduce the API `+(FITCLOUDWATCHCONNECTIONFLAG) connectionFlag;` to indicate whether the current connection is established when the watch device is bound or in the process of reconnecting.
    
## V1.2.9-beta.181 build20240914001 (2024-09-14)
    1. Add the `mainProjNo` and `subProjNo` property for FitCloudPeripheral and FitCloudManufacturer.
    
## V1.2.9-beta.180 build20240913003 (2024-09-13)
    1. Add WPAuth bridge data features for authenticating WeChat Pay on the watch device.
    
## V1.2.9-beta.179 build20240913002 (2024-09-13)
    1. Resolve the issue of incorrect response to obtaining independent settings commands for health periodic monitoring.

## V1.2.9-beta.178 build20240913001 (2024-09-13)
    1. If the alarm clock label length exceeds 32 bytes, the SDK will automatically truncate it to meet the length limit.
    
## V1.2.9-beta.177 build20240911001 (2024-09-11)
    1. When you invoke `+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` to connect and bind the watch device, if you have previously connected the watch device, the SDK will remove this historical connection record first.

## V1.2.9-beta.176 build20240910001 (2024-09-10)
    1. Introduce the API `+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` to allow the owner app connect and bind the watch device with just one API call.
    2. Rename the `time` property in FitCloudKitConnectRecord to `latestConnectTime` and the `bindTime` property to `userBindTime`.

## V1.2.9-beta.175 build20240909001 (2024-09-09)
    1. Resolved some issues with connections when switching between multiple devices.
    2. The watch face size supports 360x360 square and 296x240 square.

## V1.2.9-beta.174 build20240904002 (2024-09-04)
    1. Fixed crash issue when querying historical average resting heart rate in days.


## V1.2.9-beta.173 build20240904001 (2024-09-04)
    1. Fixed some logging print errors.

## V1.2.9-beta.172 build20240830002 (2024-08-30)
    1. Add callbacks to notify the app when the smartwatch enters or exits the LLM functionality.

## V1.2.9-beta.171 build20240830001 (2024-08-30)
    1. The exercise heart rate data is provided in a separate data list. Now `hrExcercise` has been removed from old item data model.

## V1.2.9-beta.170 build20240829001 (2024-08-29)
    1. Store the MAC address within `FitCloudKitConnectRecord`.
    2. Introduce the event `FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY` to signal that the watch side has manually terminated the measurement initialized by the app side.
