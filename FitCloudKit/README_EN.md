# FitCloudKit iOS Development Guide

## Summary
* What is FitCloudKit?

  >###### iOS framework for FitCloud smartwatch, which is responsible for the communication with watch.

* Scope

  ```
  Partners who need to customize their own iOS smartwatch APP.
  ```

* Compatibility

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

V1.2.1 Build202010300001

```
  Release Date：2020-10-30
  Features：
  1. preferSystemLocale option support for FitCloudOption, When the option is set to true, the language settings of IOS system will be synchronized with the watch. Otherwise, the current app language settings will be synchronized with the watch. The default is false.
    @note: Due to system limitations, if you manually change the language of the app, this option will also be invalid.
  2. Fixed incorrect response of sleep debug data.
  3. Interval set for auto health monitor support, only for some of the watches, @see allowSetHealthMonitorInterval
  4. Interval set for long sit reminder support, only for some of the watches, @see allowSetLSRInterval
  5. Add weather forecast, only for some of the watches, @see allowWeatherForecast
  6. The latest weather update date added, and adjust weather forecast days to 14 days.
  7. Fix problem of interval set for auto health monitor/long sit reminder.
  8. Fix some hardware flags parser problem.
  9. Albanian added.
  10. Turkish / Ukrainian added.
  11. Fixed the problem of korean language sync with the watch.
  12. Patch: when allowShowAdditionalReminder flag set to be true，allowShowMailReminder/allowShowTelegramAndViberReminder will be forced to be set as true.
```

V1.2.0 Build202007180001

```
  Release Date：2020-07-18
  Features：
  1. The smart watch can now notify app to quit the photo taking mode.
  2. Add women health settings.
  3. Add virus protection reminder settings.
  4. Fixed the Hungarian language synchronize problem.
  5. User-defined broadcast field key1 for our business partner Huashengda.
  6. Fixed incorrect age problem for setting user profile.
  7. Sleep debugging data support.
  8. Fix age setting problems.
  9. Add body temperature data for latest health measurement data.  (the watch should support body temperature)
  10. New watchface screensolution.
  11. Support synchronize all localized languages defined by SDK to the smart watch.
```

V1.1.9 Build202005150001

```
  Release Date：2020-05-15
  Features：
  1. Body temperature measurement, only for some watches.
```

V1.1.8 Build202004250001

```
  Release Date：2020-04-25
  Features：
  1. Fix the problem that may not be disconnected when unpaired the smart watch.
  2. Correct the problem that the watch disconnection may cause the prompt that the watch is paired by other mobile device or already unpaired.
  3. Fix the problem that the next command to be executed will be lost when the command is executed overtime.
  4. Fix the timeout problem with large amount of synchronous data.
  5. Clear the cache battery level of the smart watch after unpaired.
  6. Favorite contacts support, only for some of the watches.
  7. Add elliptical machine / Yoga / table tennis / rope skipping and other sports in watch sports mode.
  8. Correct the problem of incorrect logic processing when the ECG fails to start.
  9. Fixed the problem of not executing the connection timeout logic when connecting the watch.
```

V1.1.7 Build202002250001

```
  Release Date：2020-02-25
  Features：
  1. New language Slovak supported for the smart watch.
  2. Correct the sleep quality data returned by the smart watch which may be illegal.
  3. Cancel automatic unbinding from the smart watch, and add new notification of bound by other mobile phone or the smart watch already unbinded, @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY.
  4. All blocks or callbacks now are changed to be invoked at Global Queue. If you'd like to update UI at the blocks or callbacks, make sure to switch to the main queue (Main Queue).
  5. The smart watch disconnect invoked by the app now will not automatically reconnect back.
  6. Add new user bind status FITCLOUDUSERBINDSTATUS_KICKEDOUT.
  7. Add new notification of FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY.
  8. Add new sleep data format, @see newSleepDataFormat.
  9. Log data information improvment.
  10.Add new notification of FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY.
  11.The smart watch dial info retrieve invoke method changed now.
  12.Other improvements.
```

V1.1.6 Build201911210001

```
  Release Date：2019-11-21
  Features：
  1. Correct the problem that the UI information interface of the watchface does not respond correctly.
  2. After unbinding the user object, cancel the automatic reconnection of the current Bracelet connection record.
  3. Optimize the initialization process of bracelet connection to prevent accidental reconnection.
  4. Adjust the information related to the bracelet firmware to read-only.
  5. The userid of the bound user is changed from integer type to string type.
  6. Add method to obtain the lastest health measurement data (bpm / SpO2 / BP), which is only supported by some of the bracelets, @ see allowRetrieveLatestMeasurementData
  7. Modify the method of entering and exiting the DFU mode. Now you should manually invoke entering and exiting the DFU mode before the first DFU also after all the DFU operations completed. It is also applicable to common DFU and watchface push.
  8. Add reconnection notification in DFU Mode, which is usually used in the scenario of waiting for the bracelet to restart after the watchface push / common DFU.
  9. Improve SDK stability
```

V1.1.5 Build201911130001

```
  Release Date：2019-11-13
  Features：
  1. Do Not Disturb Mode support. (only available for some of the smart watches @see allowDNDMode)
```

V1.1.4 Build201910240001

```
  Release Date：2019-10-24
  Features：
  1. Real-time measurement moment modification accurate to seconds
  2. Correct synchronization data moment so that the current synchronization time cannot be exceeded
```

V1.1.3 Build201910160001

```
  Release Date：2019-10-16
  Features：
  1. New distance-calorie algorithm into the step-counting data.
  2. Obtain the last binding time of the user support.
  3. Settings of heart rate /blood pressure alarm value support.
  4. Add Snapchat message reminder.
  5. Device scanning removes device name filtering.
  6. Real-time ecg measurement can be abort by bracelet now.
  7. Obtain watch face ui information support now.
  8. Add peripheral broadcast data cache, as a result, you may retrieve mac addr if you once connect the peripheral.
  9. Add notify for peripheral name and rssi change.
  10. Improve SDK stability.
  11. Avoid ambiguity, rename function '+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals' to '+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals'.
```

V1.1.3-beta.9 Build201909300001

```
  Release Date：2019-09-30
  Features：
  1. New distance-calorie algorithm into the step-counting data.
  2. Obtain the last binding time of the user support.
  3. Settings of heart rate /blood pressure alarm value support.
  4. Add Snapchat message reminder.
  5. Device scanning removes device name filtering.
  6. Real-time ecg measurement can be abort by bracelet now.
  7. Obtain watch face ui information support now.
  8. Improve SDK stability.
```

V1.1.2 Build201908190002

```
  Release Date：2019-08-19
  Features：
  1、 Fixed problem with notification moment when bluetooth connection begin.  
```

V1.1.1 Build201908190001

```
  Release Date：2019-08-19
  Features：
  1、 Fixed the problem that the last binding Mac address of the bracelet was not cleared when the bracelet was unbound.
  2、 Add begin/end notification for prepare sync work when bind or login bracelet succeed.
  3、 Fix the problem that shouldAutoConnect attribute does not work for the SDK initialization option.  
```

V1.1.0 Build201908120001

```
  Release Date：2019-08-12
  Features：
  1、 Background bluetooth data synchronization support.
```

V1.0.9 Build201907210001

```
  Release Date：2019-07-21
  Features：
  1、 SDK version query support.
```

V1.0.8 Build201907200001

```
  Release Date：2019-07-20
  Features：
  1、 Fixed an issue failed to synchronize system time for the iPhone calendar settings to be a buddhist or Japanese calendar.
  2、 Optimize the reconnection mechanism with bracelet.
```

V1.0.7 Build201906280001

```
  Release Date：2019-06-28
  Features：
  1、 Fix some problems with retrieving notification remind configuration.
```

V1.0.6 Build201906270001

```
  Release Date：2019-06-27
  Features：
  1、 Add mac address for peripheral when scanned.
```

V1.0.5 Build201906250001

```
  Release Date：2019-06-25
  Features：
  1、 You can set more daily sports goal now.
```

V1.0.4 Build201906110001

```
  Release Date：2019-06-11
  Features：
  1、 More languages are supported for the bracelet.
  2、 Fix some problems of synchronization.
```

V1.0.0 Build201905010001

```
  Release Date：2019-05-01
  Features：
  1、 First SDK release.
```

## APPID & APPKEY

Currently, APPID and APPKEY have not been opened, so there is no need to apply for them.

## Installation

Method 1：`FitCloudKit` is available through CocoaPods. To install it, simply add the following line to your Podfile:

```
pod 'FitCloudKit'
```

Method 2: download from making ` FitCloudKit `, manual integrated into your project.

1. FitCloudKit SDK includes:
    * FitCloudKit. Framework  
      static library, smart bracelet development kit core framework
    * FitCloudKit.bundle   
      smart bracelet development kit core resource package

2. Add the framework to the project;

3. Add the resource bundle to the project;

4. Add support for other system dependency libraries:

    * CoreGraphics framework
    * CoreBluetooth framework
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
option.shouldAutoConnect = YES;
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
[FitCloudKit manualSyncDataWithProgress:^(CGFloat progress, NSString *tip) {
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

## Other Settings and Operations

see detail comments in `<FitCloudKit/FitCloudKit.h>` header file.

## FAQ

>Q: What is the FitCloudKit main invoke process？
>
>A: As the following:
>
![invoke help en](media/invoke_help_en.png)

<!-- more -->

>Q: How to determine whether the current bracelet supports specific hardware functions, for example, how to determine whether it is a bracelet with ecg function?
>
>A: You can get the current functions supported by the bracelet according to the information provided by the firmware, such as: whether the bracelet has heart rate/blood oxygen/blood pressure/breathing frequency/weather forecast/ecg/whether it supports sports mode/whether it supports WeChat sports/whether it needs to use the new firmware upgrade platform/whether it supports dynamic heart rate, etc.
>
>Take the ecg function as an example, the code is as follows:
>
```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];   
BOOL isECGSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_ECG));
```

<!-- more -->

>Q: When bind the user information, the bluetooth pairing request pops up. Must the user choose to pair with the bracelet?
>
>A: It is not required in theory, howerver, if you choose not to pair, the bracelet's message alert function (e.g. QQ/ WeChat /Facebook/Twitter, etc.) will not work properly.

<!-- more -->

>Q: Where is the part of getting data from self server?
>
>A: Our sdk has no communication with any server, you have to do that as yourself. Once you got data from the sdk, you may save it to your own server as you can. Our sdk always offline, we do nothing with that.

<!-- more -->

>Q: How to get sport data yesterday?
>
>A: You can get sport data by synchronize data from the smart watch with our SDK, once you synchronzied data you should save it to db by your self, or you can upload it to your server, then you can query it later. However, if you have not synchronized the data from the smart watch, you should invoke the code as follows to sychronized it:
>
```objc
[FitCloudKit manualSyncDataWithProgress:^(CGFloat progress, NSString *tip) { 
    NSLog(@"Sync Progress:%.0f%%, %@",progress*100.0f, tip);
} block:^(BOOL succeed, NSArray<FitCloudManualSyncRecordObject*> *records, NSError *error) {
    //Synchronization Result
}];
```
>
>Of course, you should invoke the code when the sdk is ready.

<!-- more -->

>Q: How to get the state of every notification?
>
>A: You can invoke the following code to get the state of notification provided by the sdk, note that ‘FITCLOUDMN’ is NS_OPTION struct. I think you know how to use that.
>
```objc
[FitCloudKit getMessageNotificationSettingWithBlock:^(BOOL succeed, FITCLOUDMN mnSetting, NSError* error){
}];
```

<!-- more -->

>Q: How to get the current daily goal?
>
>A: We have not provide the api to retrieve the current daily goal, usually, the daily goal is set by the app, most of the time you may manage it by yourself at the app side. However, the following is the method to set the daily goal.
>
```objc
[FitCloudKit setDailyGoalWithStepCount:8000 distance:8*1000*100 calory:100*1000 block:^(BOOL succeed, NSError* error){
}];
```


## Technical Support

Hetang Smart.

Dai / iOS Developer


