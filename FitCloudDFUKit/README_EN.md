# FitCloudDFUKit iOS Development Guide

## Summary

- What is FitCloudKit?

  > ###### iOS framework for FitCloud Smart Bracelet, which is responsible for the upgrade of bracelet firmware.

- Scope

  ```
  Partners who need to customize their own iOS smart bracelet APP.
  ```

- Compatibility

  ###### 1. iOS 9.0 and Above；

  ###### 2. armv7/i386/x86_64/arm64 Instruction Set；

  ###### 3. Bitcode；

## Features

1. Device firmware upgrade for bracelet (excluding firmware upgrade for air and remote download);

## Releases

V1.3.0 Build202212300001

```
  Release Date：2022-12-30
  Features：
  1. Update error code localization.
  2. Upgrade the Realtek firmware upgrade program with new invoke mode.
  3. Add Vietnamese localization.
```

V1.2.9 Build202206300001

```
  Release Date：2022-06-30
  Features：
  1. Upgrade the Realtek firmware upgrade program to fix dfu still slow issue.
```

V1.2.8 Build202206060001

```
  Release Date：2022-06-06
  Features：
  1. Upgrade the Realtek firmware upgrade program to fix dfu slow issue.
```

V1.2.7 Build202206010001

```
  Release Date：2022-06-01
  Features：
  1. Fix: OnStartDFUSuccess not invoked.
```

V1.2.6 Build202201260001

```
  Release Date：2022-01-26
  Features：
  1. Upgrade the Realtek firmware upgrade program to fix dfu accidental error.
  2. Upgrade the Realtek firmware upgrade program to support the 8763E platform.
  3. Add Hindi.
```

V1.2.5 Build202112180001

```
  Release Date：2021-12-18
  Features：
  1、Upgrade the Realtek firmware upgrade program to fix dfu slow issue.
```

V1.2.4 Build202108230001

```
  Release Date：2021-08-23
  Features：
  1、Fix some dfu failure issue.
```

V1.2.3 Build202108040001

```
  Release Date：2021-08-04
  Features：
  1、Fix dfu failure issue on iOS11.4.
```

V1.2.2 Build202106040001

```
  Release Date：2021-06-04
  Features：
  1、Nordic DFU support.
```

V1.2.1 Build202102250001

```
  Release Date：2021-02-25
  Features：
  1、Upgrade the Realtek firmware upgrade program to support the 8762D platform.
```

V1.2.0 Build202009280001

```
  Release Date：2020-09-28
  Features：
  1、Turkish/Ukrainian added.
```

V1.1.9 Build202008140001

```
  Release Date：2020-08-14
  Features：
  1、 Croatian/Albanian added.
```

V1.1.8 Build202007100001

```
  Release Date：2020-07-10
  Features：
  1、 Fixed Traditional Chinese translation.
```

V1.0.7 Build201911220001

```
  Release Date：2019-11-22
  Features：
  1、 Slovak added.
```

V1.0.6 Build201911210001

```
  Release Date：2019-11-21
  Features：
  1、 Support the DFU of peripheral devices in non connected state.
  2、 Improve the reliability of the DFU process.
```

V1.0.5 Build201910180001

```
  Release Date：2019-10-18
  Features：
  1、 Fix issue that some time enter silent mode failure in watch face upgrade progress.
```

V1.0.4 Build201910160001

```
  Release Date：2019-10-16
  Features：
  1、 Fix crash bug with iOS13.
```

V1.0.3 Build201909300001

```
  Release Date：2019-09-30
  Features：
  1、 Watch face ui upgrade support now.
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

Method 1：`FitCloudDFUKit` is available through CocoaPods. To install it, simply add the following line to your Podfile:

```
pod 'FitCloudDFUKit'
```

If you want to integrate beta FitCloudDFUKit, you should use the following configuration in the podfile file:

```
pod 'FitCloudDFUKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
```

Method 2: download from making `FitCloudDFUKit`, manual integrated into your project.

1. FitCloudDFUKit SDK includes:

   - FitCloudDFUKit. Framework  
     static library, smart bracelet dfu development kit core framework
   - FitCloudDFUkit.bundle  
     smart bracelet development kit core resource package

2. Add the framework to the project;

3. Add the resource bundle to the project;

4. Add support for other system dependency libraries:

   - CoreGraphics framework
   - CoreBluetooth framework

5. Add dependency in Podfile:

   pod 'iOSDFULibrary', '4.11.0'

## Privacy Permissions

In the project `Info.Plist` set the following privacy permissions using description, the actual describe the content depends on your business.

![Bluetooth Privacy Permission](media/privacy_bluetooth_en.png)

## Import Header File

```objc
#import <FitCloudDFUKit/FitCloudDFUKit.h>
```

## Initialize the SDK

```objc
[FitCloudDFUKit setDebugMode:YES];
[FitCloudDFUKit setDelegate:self];
```

## Implement FitCloudDFUDelegate Delegate

```objc
/**
 * @brief callback when start DFU successfully
 */
-(void) OnStartDFUSuccess
{
    NSLog(@"Start DFU Successfully, Do not exit the current UI...");
}

/**
 * @brief callback when start DFU with failure
 * @param error error information
 */
-(void) OnStartDFUFailureWithError:(NSError*)error
{
    NSString *msg = APP_GET_ERROR_MSG(error);
    NSLog(@"Start DFU with failure，%@...", msg);
}

/**
 * @brief callback of DFU progress
 * @param progress percent of the progress(0~100)
 * @param index firmware image index
 * @param total total firmware image count
 */
-(void) OnDFUProgress:(CGFloat)progress imageIndex:(NSInteger)index total:(NSInteger)total
{
    NSLog(@"Current progress：%2ld%%", (long)roundf(progress));
}

/**
 * @brief callback when abort with exception occurred
 * @param error error information
 */
-(void) OnAbortWithError:(NSError*)error
{
    NSString *msg = APP_GET_ERROR_MSG(error);
    NSLog(@"DFU progress aborted with error，%@...", msg);
}

/**
 * @brief callback when the DFU complete successfully
 * @param speed average speed for device firmware upgrade
 */
-(void) OnDFUFinishWithSpeed:(CGFloat)speed
{
    NSLog(@"Device firmware upgrade success...");
}


/**
 *@brief Log message callback
 *@param message log message
 *@param level log level
 */
-(void) OnLogMessage:(NSString*)message level:(FCDFUKLogLevel)level
{
    //You can process the log message according to your actual business logic
}
```

## Start DFU

```objc
BOOL silentMode = FALSE;
if([FitCloudKit allConfig].firmware.hardwareSupported & FITCLOUDHARDWARE_DFUSHOULDSILENTMODE)
{
  silentMode = TRUE;
}
FITCLOUDDFUCHIPVENDOR chipVendor = FITCLOUDDFUCHIPVENDOR_REALTEK;
[FitCloudDFUKit startWithPeripheral:dfuPeripheral firmware:self.selectedPath chipVendor:chipVendor silentMode:silentMode];
```

## Normal DFU / UI DFU / Watchface DFU / Watch Sports DFU

**Step 1**

Check the battery level of the watch and get the dfuPeripheral. If it fails, I don’t think you should continue the next process.

```objc
[FitCloudKit enterDFUModeWithBlock:^(BOOL succeed, CBPeripheral *dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError *error) {
}
```

**Step 2**

Start the dfu, the silentMode parameters means different types of dfu.

Normal DFU:

```
BOOL silentMode = FALSE;
if([FitCloudKit allConfig].firmware.hardwareSupported & FITCLOUDHARDWARE_DFUSHOULDSILENTMODE)
{
  silentMode = TRUE;
}
```

UI DFU / Watchface DFU / Watch Sports DFU:

```
BOOL silentMode = YES;
```

then:

```objc
[FitCloudDFUKit startWithPeripheral:dfuPeripheral firmware:self.selectedPath chipVendor:chipVendor silentMode:silentMode];
```

Process the delegate and log callback information. When the upgrade succeeds or fails, you need to observe the reconnection notification in DFU mode, like this:

```objc
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnReconnectWithDFUMode:) name:FITCLOUDEVENT_PERIPHERAL_RECONNECTEDWITHDFUMODE_NOTIFY object:nil];
}

-(void)OnReconnectWithDFUMode:(NSNotification*)notification
{
    NSLog(@"%@", APP_LOG_STRING(@"The watch restarted successfully, the dfu perform %@ this time.", _lastDFUSucceed ? @"succeed" : @"failure"));
}
```

**Step 3**

When you decide not to continue with the firmware upgrade or plan to exit the DFU mode, you need to invoke the following method to return to the normal mode. Of course, the watch will be disconnected and reconnected.

```objc
[FitCloudKit exitDFUModeWithBlock:nil];
```

## Parameters required for docking to obtain our watchface server

If you are our business customers who allowed to connect our watchface server, you may need to obtain some parameters from the SDK and pass it to our server. Of course, to obtain this capability, you need to contact our business manager.

- hardwareInfo

```objc
FitCloudAllConfigObject *allConfig = [FitCloudKit allConfig];
FitCloudFirmwareVersionObject* firmware = allconfig.firmware;
NSString* hardwareInfo = [firmware description];
```

- lcd

```objc
[FitCloudKit getWatchfaceUIInformationWithBlock:^(BOOL succeed, FitCloudWatchfaceUIInfo* faceUI, NSError* error) {
    NSInteger lcd = faceUI.lcd;
}];
```

- toolVersion

```objc
[FitCloudKit getWatchfaceUIInformationWithBlock:^(BOOL succeed, FitCloudWatchfaceUIInfo* faceUI, NSError* error) {
    NSString* toolVersion = faceUI.toolVersion;
}];
```

## MUSIC PUSH

- [MUSIC PUSH](../Others/Music/MUSIC_EN.md)

## FAQ

> Q: Which chipmaker firmware updates are supported now?
>
> A: The SDK integrates `Realtek` and `Nordic` manufacturers firmware upgrade procedure, but because at present all bracelet actually uses only `Realtek` chip, therefore in the process of actual use, you can only use the `Realtek` chip firmware upgrade.

<!-- more -->

> Q: What is the difference between normal DFU and UI DFU?
>
> A: Usually, DFU without user interface named normal DFU, and DFU with user interface is UI DFU. Of course, watchface DFU is UI DFU.

## Technical Support

Hetang Smart.

Dai / iOS Developer
