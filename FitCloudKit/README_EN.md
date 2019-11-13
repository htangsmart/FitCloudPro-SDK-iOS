# FitCloudKit iOS Development Guide

## Summary
* What is FitCloudKit?

  >###### iOS framework for FitCloud Smart Bracelet, which is responsible for the communication with bracelet.

* Scope

  ```
  Partners who need to customize their own iOS smart bracelet APP.
  ```

* Compatibility

  ###### 1. iOS 8.0 and Above；

  ###### 2. armv7/i386/x86_64/arm64 Instruction Set；

  ###### 3. Bitcode；


## Features

1. Initialize/scan/connect the bracelet;

2. Obtain/set related functions and display of the bracelet;

3. Synchronize exercise health data to APP;

4. Start/stop health real-time measurement (heart rate/blood pressure/blood oxygen/ecg, etc.);

5. Synchronize weather information;

6. Find bracelet /iOS device;

7. One-click restore factory Settings;

8. Restart/shutdown of the bracelet;

9. Safety check before entering DFU mode (ensure the bracelet has sufficient power);

## Releases

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

>Q: How to determine whether the current bracelet supports specific hardware functions, for example, how to determine whether it is a bracelet with ecg function?
>
>A: You can get the current functions supported by the bracelet according to the information provided by the firmware, such as: whether the bracelet has heart rate/blood oxygen/blood pressure/breathing frequency/weather forecast/ecg/whether it supports sports mode/whether it supports WeChat sports/whether it needs to use the new firmware upgrade platform/whether it supports dynamic heart rate, etc.
>
>Take the ecg function as an example, the code is as follows:

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];   
BOOL isECGSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_ECG));
```

<!-- more -->

>Q: When bind the user information, the bluetooth pairing request pops up. Must the user choose to pair with the bracelet?
>
>A: It is not required in theory, howerver, if you choose not to pair, the bracelet's message alert function (e.g. QQ/ WeChat /Facebook/Twitter, etc.) will not work properly.

## Technical Support

Hetang Smart.

Dai / iOS Developer
