# CHANGELOG

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
