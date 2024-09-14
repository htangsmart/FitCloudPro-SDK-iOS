# CHANGELOG

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
