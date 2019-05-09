# FitCloudDFUKit iOS Development Guide

## Summary
* What is FitCloudKit? 
  
  >###### iOS framework for FitCloud Smart Bracelet, which is responsible for the upgrade of bracelet firmware. 
         
* Scope

  ```
  Partners who need to customize their own iOS smart bracelet APP.
  ```

* Compatibility
  
  ###### 1. iOS 8.0 and Above；
  
  ###### 2. armv7/i386/x86_64/arm64 Instruction Set；
  
  ###### 3. Bitcode；
  
 
## Features
 
1. Device firmware upgrade for bracelet (excluding firmware upgrade for air and remote download);
 
## Releases

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

Method 2: download from making ` FitCloudDFUKit `, manual integrated into your project.

1. FitCloudDFUKit SDK includes:
    * FitCloudDFUKit. Framework  
      static library, smart bracelet dfu development kit core framework
    * FitCloudDFUkit.bundle   
      smart bracelet development kit core resource package

2. Add the framework to the project;

3. Add the resource bundle to the project;

4. Add support for other system dependency libraries:

    * CoreGraphics framework
    * CoreBluetooth framework

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
 */
-(void) OnDFUProgress:(CGFloat)progress imageIndex:(NSInteger)index
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
FITCLOUDDFUCHIPVENDOR chipVendor = FITCLOUDDFUCHIPVENDOR_REALTEK;
[FitCloudDFUKit startWithPeripheral:dfuPeripheral firmware:self.selectedPath chipVendor:chipVendor];
```

## FAQ

>Q: Which chipmaker firmware updates are supported now?
>
>A: The SDK integrates ` Realtek ` and ` Nordic ` manufacturers firmware upgrade procedure, but because at present all bracelet actually uses only ` Realtek ` chip, therefore in the process of actual use, you can only use the ` Realtek ` chip firmware upgrade.

## Technical Support

Hetang Smart.

Dai / iOS Developer



