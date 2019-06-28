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
