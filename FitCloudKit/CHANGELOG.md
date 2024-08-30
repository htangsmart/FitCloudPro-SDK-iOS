# CHANGELOG

## V1.2.9-beta.171 build20240830001 (2024-08-30)

1.  The exercise heart rate data is provided in a separate data list. Now `hrExcercise` has been removed from old item data model.


## V1.2.9-beta.170 build20240829001 (2024-08-29)

1. Store the MAC address within `FitCloudKitConnectRecord`.
2. Introduce the event `FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY` to signal that the watch side has manually terminated the measurement initialized by the app side.
