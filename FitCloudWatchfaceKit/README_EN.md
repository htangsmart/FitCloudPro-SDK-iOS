# FitCloudWatchfaceKit iOS Development Guide

## Summary
* What is FitCloudWatchfaceKit?

  >###### iOS framework help you creating customized watchface for fitcloud smart watch easily.

* Scope

  ```
  Partners who need to customize their own iOS smartwatch APP.
  ```

* Compatibility

  ###### 1. iOS 8.0 and Above；

  ###### 2. armv7/i386/x86_64/arm64 Instruction Set；

  ###### 3. Bitcode；


## Features

1. Create customized watchface bin file base the template one;


## Releases

V1.0.0 Build202007160001

```
  Release Date：2020-07-16
  Features：
  1、 Auto clip bkimage & preview image.
```

V1.0.0 Build202007100001

```
  Release Date：2020-07-10
  Features：
  1、 First SDK release.
```

## APPID & APPKEY

Currently, APPID and APPKEY have not been opened, so there is no need to apply for them.

## Installation

Method 1：`FitCloudWatchfaceKit` is available through CocoaPods. To install it, simply add the following line to your Podfile:

```
pod 'FitCloudWatchfaceKit'
```

Method 2: download from making ` FitCloudWatchfaceKit `, manual integrated into your project.

1. FitCloudWatchfaceKit SDK includes:
    * FitCloudWatchfaceKit. Framework  
      static library, smart bracelet development kit core framework
    * FitCloudWatchfaceKit.bundle   
      smart bracelet development kit core resource package

2. Add the framework to the project;

3. Add the resource bundle to the project;

4. Add support for other system dependency libraries:

    * CoreGraphics framework
    * CoreBluetooth framework
    * UIKit framework
    * Accelerate framework
5. add `-ObjC` link flag
   add`-ObjC` link flag at `Other Linker Flags` in `Build Settings` as following:


   ![ObjC Other Link Flag](media/build_settings.png)


## Import Header File

```objc
#import <FitCloudWatchfaceKit/FitCloudWatchfaceKit.h>
```

## Create the watchface

```objc
NSString* templateBinPath = [[NSBundle mainBundle] pathForResource:@"240USER_DEFAULT_20200618142928_MP-cc0c13932ab8ca2f89301678993cfdeb" ofType:@"bin"];

[FitCloudWatchfaceKit createWithTemplateBin:templateBinPath bkImage:resolvedBKImage preview:resolvedPreviewImage dtPosition:_watchfaceStyle.dtPosition progress:^(CGFloat progress, NSString * _Nullable message) {
    XLOG_INFO(@"progress:%@%%, tip:%@", [NumberFormatUtil roundString:@(progress*100) withMaximumFractionDigits:1], message);
    
} logging:^(FCWKLOGLEVEL level, NSString * _Nullable message) {
    message = [[message stringByReplacingOccurrencesOfString:@"<" withString:@"["] stringByReplacingOccurrencesOfString:@">" withString:@"]"];
    if(level == FCWKLOGLEVEL_INFO)
    {
        XLOG_INFO(@"%@", message);
    }
    else if(level == FCWKLOGLEVEL_WARNING)
    {
        XLOG_WARNING(@"%@", message);
    }
    else if(level == FCWKLOGLEVEL_ERROR)
    {
        XLOG_ERROR(@"%@", message);
    }
} completion:^(BOOL success, NSString * _Nullable resultBinPath, UIImage * _Nullable resultBkImage, UIImage * _Nullable resultPreview, NSError * _Nullable error) {
    if(success)
    {
        XLOG_INFO(@"create watchface success, bin file: %@", resultBinPath);
    }
    else
    {
        XLOG_ERROR(@"create watchface failure with error: %@", error.localizedDescription);
        
    }
}];
```


## Other Settings and Operations

see detail comments in `<FitCloudWatchfaceKit/FitCloudWatchfaceKit.h>` header file.

## FAQ

>Q: What is the watchface template bin file, how to get it？
>
>A: The template Bin file is the basis of the custom watchface. Different models and sizes of watch template Bin files are different. You need to store these template Bin files on your own server, and then download the specific template Bin file according to the watch information before proceeding. Process, you can contact our business to provide follow-up support.

## Technical Support

Hetang Smart.

Dai / iOS Developer
