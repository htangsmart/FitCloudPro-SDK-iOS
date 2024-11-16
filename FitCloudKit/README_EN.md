# FitCloudKit iOS Development Guide

## Summary

- What is FitCloudKit?

  > ###### iOS framework for FitCloud smartwatch, which is responsible for the communication with watch.

- Scope

  ```
  Partners who need to customize their own iOS smartwatch APP.
  ```

- Compatibility

  ###### 1. iOS 8.0 and Above；

  ###### 2. armv7/i386/x86_64/arm64 Instruction Set；

  ###### 3. Bitcode；

## Features

1. Initialize/scan/connect the watch;

2. Obtain/set related functions and display of the watch;

3. Synchronize exercise health data to APP;

4. Start/stop health real-time measurement (heart rate/blood pressure/blood oxygen/ecg, etc.);

5. Synchronize weather information;

6. Find the smartwatch /iOS device;

7. One-click restore factory Settings;

8. Restart/shutdown of the smartwatch;

9. Safety check before entering DFU mode (ensure the smartwatch has sufficient power);

## Releases

- [RELEASES NOTES](RELEASE_EN.md)

## APPID & APPKEY

Currently, APPID and APPKEY have not been opened, so there is no need to apply for them.

## Installation

Method 1：`FitCloudKit` is available through CocoaPods. To install it, simply add the following line to your Podfile:

```
pod 'FitCloudKit'
```

If you want to integrate beta FitCloudKit, you should use the following configuration in the podfile file:

```
pod 'FitCloudKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
```

Method 2: download from making `FitCloudKit`, manual integrated into your project.

1. FitCloudKit SDK includes:

   - FitCloudKit.xcframework  
     static library, smart bracelet development kit core framework
   - FitCloudKit.bundle  
     smart bracelet development kit core resource package

2. Add the framework to the project;

3. Add the resource bundle to the project;

4. Add support for other system dependency libraries:

   - CoreGraphics framework
   - CoreBluetooth framework

5. add `-ObjC` link flag
   add`-ObjC` link flag at `Other Linker Flags` in `Build Settings` as following:

   ![ObjC Other Link Flag](media/build_settings.png)

## Privacy Permissions

In the project `Info.Plist` set the following privacy permissions using description, the actual describe the content depends on your business.

![Bluetooth Privacy Permission](media/privacy_bluetooth_en.png)

## Bluetooth Background Mode

![Bluetooth Background Mode](media/bluetooth_backgroundmode.png)

## Import Header File

```objc
#import <FitCloudKit/FitCloudKit.h>
```

## Initialize the SDK

```objc
FitCloudOption *option = [FitCloudOption defaultOption];
option.debugMode = NO;
option.shouldAutoReconnectWhenAppLaunch = YES;
self.fitCloudKit = [FitCloudKit initWithOption:option callback:self];
```

## Implement FitCloudCallback Protocol

```objc
/**
 *@brief The bracelet asks to find the phone
 */
-(void) OnFindiPhoneEvent
{
    //Implement your logic here when the app receives a phone find request event, such as vibration, playing a music, or creating a local notification, etc
}

/**
 *@brief The bracelet asks for weather information
 *@param block weather information callback
 */
-(void) OnRequestWeatherWithCallback:(FitCloudWeatherCallbackBlock)block
{
    //Weather information is requested by the bracelet. You need to get weather information by yourself and call back to the bracelet SDK.
    //However, at present, this method basically does not callback (the bracelet does not implement the logic), and it needs to synchronize the weather to the bracelet by itself.
    //@see syncWeather:block:
}

/**
 *@brief Real-time exercise health measurement data callback (ecg data exception)
 *@param records measurement data
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    //According to the actual business logic response bracelet real-time measurement data
}

/**
 *@brief Real-time ecg measurement results
 *@param ecgDataArray ecg data array
 *@param interval Sampling interval in milliseconds (ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    //According to the actual business logic response bracelet real-time ecg measurement data
}

/**
 *@brief Real-time ecg measurement stopped
 */
-(void) OnRealTimeECGStop
{
    //Notify the business logic ecg real-time measurement stopped
}

/**
 *@brief The bracelet controls the phone's camera
 */
-(void)OnTakePhotoCtrl
{
    //the App can implement photo take logic here
}

/**
 *@brief The bracelet notify the app it is alive.
 */
-(void) OnBraceletAlive
{
    //the App can actively synchronize the movement health data of the bracelet to achieve the function of background synchronization data. Please add it according to the specific project needs. Note that frequent synchronization data in the background may affect the power consumption of the bracelet device.
}

/**
 *@brief Log message callback
 *@param message log message
 *@param level log level
 */
-(void) OnLogMessage:(NSString*)message level:(FITCLOUDKITLOGLEVEL)level
{
    //You can process the log message according to your actual business logic
}
```

## Get the Status of the Bluetooth Central Device

```objc
FITCLOUDBLECENTRALSTATE bleState = [FitCloudKit bleState];
//the bluetooth Central device is not powered on
if(bleState != FITCLOUDBLECENTRALSTATE_POWEREDON)
{
    //the bluetooth Central device is powered off
    if(bleState == FITCLOUDBLECENTRALSTATE_POWEREDOFF)
    {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
    }
    else
    {
        //Request bluetooth enabled to allow connection to accessories
        [FitCloudKit requestShowBluetoothPowerAlert];
    }
}
```

## Scan the Bracelet Peripheral

```objc

//Listen for scanning related events/notifications
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredUpdatedNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralScanStopNotification:) name:FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY object:nil];
//start the scanning
[FitCloudKit scanPeripherals];
```

## Connect the Bracelet Peripheral

```objc
//Listen for connect related events/notifications
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY object:nil];

//start to connect
FitCloudPeripheral* item = [self.peripherals objectAtIndex:indexPath.row];
[FitCloudKit connect:item.peripheral];
```

## Bind User Information

```objc
//Listen for bind related events/notifications
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudBindUserObjectBegin:) name:FITCLOUDEVENT_BINDUSEROBJECT_BEGIN_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudBindUserObjectResult:) name:FITCLOUDEVENT_BINDUSEROBJECT_RESULT_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudGetAllConfigBegin:) name:FITCLOUDEVENT_GETALLCONFIG_BEGIN_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudGetAllConfigResult:) name:FITCLOUDEVENT_GETALLCONFIG_RESULT_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudInitializeResult:) name:FITCLOUDEVENT_INITIALIZE_RESULT_NOTIFY object:nil];
//start to bind
NSInteger userId = 1000;
[FitCloudKit bindUserObject:userId abortIfExist:YES block:^(BOOL succeed, NSError *error) {
}];
```

## Unbind User Information

```objc
//Start to unbind, disconnect the bracelet automatically after unbind successfully.
[FitCloudKit unbindUserObject:YES block:^(BOOL succeed, NSError *error) {
}];
```

## Manual Synchronization of Historical Exercise & Health Data

```objc
[FitCloudKit manualSyncDataWithOption:FITCLOUDDATASYNCOPTION_ALL progress:^(CGFloat progress, NSString *tip) {
    NSLog(@"Sync Progress：%.0f%%, %@",progress*100.0f, tip);
} block:^(BOOL succeed, NSArray<FitCloudManualSyncRecordObject*> *records, NSError *error) {
    //Synchronization Result
}];
```

## Obtain Today's Exercise & Health Summary Data (total steps/average heart rate/calories, etc.)

```objc
 [FitCloudKit requestHealthAndSportsDataTodayWithBlock:^(BOOL succeed, FitCloudDailyHealthAndSportsDataObject *dataObject, NSError *error) {
}];
```

## Start/Stop Real-time Health Measurements (heart rate, blood oxygen, blood pressure, respiratory rate, ecg, etc.)

⚠️Caution: ecg measurement should not be taken in conjunction with other real-time measurements.

```objc
//Set the parameters
//Example: start heart rate and blood pressure measurements, otherwise set this parameter according to the actual business logic
FITCLOUDREALTIMEMHEALTHEASUREITEM item = FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE | FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE;
/*
    //Stop the measurement
    //FITCLOUDREALTIMEMHEALTHEASUREITEM item = FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE;
*/
FitCloudRealTimeHealthMeasuringParam *param = [FitCloudRealTimeHealthMeasuringParam new];
param.item = item;
param.interval = 5;
param.maxMeasuringMinutes = 1;

//Invoke the SDK to start or stop the measurement (depending on the parameters passed in)
[FitCloudKit requestRealTimeHealthMeasuring:param block:^(BOOL succeed, NSError *error) {
}];
```

The Real-time Health Measurements results:
@see FitCloudCallback

```objc
/**
 *@brief Real-time exercise health measurement data callback (ecg data exception)
 *@param records measurement data
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    //According to the actual business logic response bracelet real-time measurement data
}

/**
 *@brief Real-time ecg measurement results
 *@param ecgDataArray ecg data array
 *@param interval Sampling interval in milliseconds (ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    //According to the actual business logic response bracelet real-time ecg measurement data
}

/**
 *@brief Real-time ecg measurement stopped
 */
-(void) OnRealTimeECGStop
{
    //Notify the business logic ecg real-time measurement stopped
}
```

## Common features

[Common features](COMMON_FEATURES.md)

## Cricket match

[Cricket match](../Others/CricketMatch/CRICKETMATCH_EN.md)

## Other Settings and Operations

see detail comments in `<FitCloudKit/FitCloudKit.h>` header file.

## FAQ

> Q: What is the FitCloudKit main invoke process？
>
> A: As the following:
>
> ![invoke help en](media/invoke_help_en.png)

<!-- more -->

> Q: How determine whether the current smartwatch supports specific features, for example, how to determine whether the smartwatch with DND feature?
>
> A: You can get the current features supported by the smartwatch according to the information provided by the firmware, such as the dnd mode feature. Software feature & hardware feature included.
>
> Take the dnd mode feature for example, the code is as follows:

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL isDNDSupported = (allConfig && allConfig.firmware && allConfig.firmware.allowDNDMode);
```

> Above is the example for the software feature, and the hardware feature see the next FAQ.

<!-- more -->

> Q: How to determine whether the current smartwatch supports specific hardware features, for example, how to determine whether the smartwatch with ecg feature?
>
> A: You can get the current features supported by the smartwatch according to the information provided by the firmware, such as: whether the smartwatch has heart rate/blood oxygen/blood pressure/breathing frequency/weather forecast/ecg/sports mode/WeChat sports/the new firmware upgrade platform/dynamic heart rate, etc.
>
> Take the ecg feature as an example, the code is as follows:

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL isECGSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_ECG));
```

<!-- more -->

> Q: When bind the user information, the bluetooth pairing request pops up. Must the user choose to pair with the bracelet?
>
> A: It is not required in theory, howerver, if you choose not to pair, the bracelet's message alert function (e.g. QQ/ WeChat /Facebook/Twitter, etc.) will not work properly.

<!-- more -->

> Q: Where is the part of getting data from self server?
>
> A: Our sdk has no communication with any server, you have to do that as yourself. Once you got data from the sdk, you may save it to your own server as you can. Our sdk always offline, we do nothing with that.

<!-- more -->

> Q: How to get sport data yesterday?
>
> A: You can get sport data by synchronize data from the smart watch with our SDK, once you synchronzied data you should save it to db by your self, or you can upload it to your server, then you can query it later. However, if you have not synchronized the data from the smart watch, you should invoke the code as follows to sychronized it:

```objc
[FitCloudKit manualSyncDataWithProgress:^(CGFloat progress, NSString *tip) {
    NSLog(@"Sync Progress:%.0f%%, %@",progress*100.0f, tip);
} block:^(BOOL succeed, NSArray<FitCloudManualSyncRecordObject*> *records, NSError *error) {
    //Synchronization Result
}];
```

> Of course, you should invoke the code when the sdk is ready.

<!-- more -->

> Q: How to get the state of every notification?
>
> A: You can invoke the following code to get the state of notification provided by the sdk, note that ‘FITCLOUDMN’ is NS_OPTIONS struct. I think you know how to use that.

```objc
[FitCloudKit getMessageNotificationSettingWithBlock:^(BOOL succeed, FITCLOUDMN mnSetting, NSError* error){
}];
```

<!-- more -->

> Q: How to get the current daily goal?
>
> A: We have not provide the api to retrieve the current daily goal, usually, the daily goal is set by the app, most of the time you may manage it by yourself at the app side. However, the following is the method to set the daily goal.

```objc
[FitCloudKit setDailyGoalWithStepCount:8000 distance:8*1000*100 calory:100*1000 block:^(BOOL succeed, NSError* error){
}];
```

<!-- more -->

> Q: The sleep data
>
> A: As the following:
>
> ![sleep data format](media/sleep_data_format.png)

<!-- more -->

> Q: How to deal with the abnormal situation caused by multiple iOS devices successively binding and pairing the same watch?
>
> A: Generally, users will only bind and pair watch with one iOS device, but a small number of users will bind and pair one watch with multiple iOS devices successively, which leads to abnormal pairing between the iOS device and the watch that was previously connected & paired, and the watch cannot be reconnected. This is due to the fact that these watch devices can only store the pairing information with one iOS device at the same time, The pairing information of the later device covers the previous pairing information, which causes the pairing information on iOS device to not match the pairing information on the watch. Please refer to FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY notification, and process in your app.

## Technical Support

Hetang Smart.

Dai / iOS Developer
