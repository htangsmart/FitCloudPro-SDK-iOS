# FitCloudWFKit iOS Development Guide

## Summary
* What is FitCloudWFKit?

  >###### iOS framework help you customize watchface for fitcloud smart watch easily.

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
2. Modify watchface push index.


## Releases

V1.1.6 Build202212300001

```
  Release Date：2022-12-30
  Features：
  1、 Update error code localization.
```

V1.1.5 Build202205190001

```
  Release Date：2022-05-19
  Features：
    1、 Add Indian localiztion.
    2、 Bitcode support.
```

V1.1.4 Build202201240001

```
  Release Date：2022-01-24
  Features：
  1、 Fix issue for game skin push index.
```

V1.1.3 Build202111030001

```
  Release Date：2021-11-03
  Features：
  1、 Modify the watch sports push position/index support.
```

V1.1.2 Build202106170001

```
  Release Date：2021-06-17
  Features：
  1、 Modify game skin push position/index support.
```

V1.1.1 Build202106160001

```
  Release Date：2021-06-16
  Features：
  1、 Next GUI watchface image in bin file storage optimization.
```

V1.1.0 Build202106050001

```
  Release Date：2021-06-05
  Features：
  1、 Modify Next GUI watchface No. support.
```

V1.0.9 Build202106010001

```
  Release Date：2021-06-01
  Features：
  1、 Fix Next GUI watchface generating issue with round corner processing.
```

V1.0.8 Build202105260001

```
  Release Date：2021-05-26
  Features：
  1、 Next GUI watchface support.
```

V1.0.7 Build202102020001

```
  Release Date：2021-02-02
  Features：
  1、 Add file size log to trace creating personalized watchface.
```

V1.0.6 Build202101280002

```
  Release Date：2021-01-28
  Features：
  1、 Modify watchface push position/index support.
```

V1.0.5 Build202009280001

```
  Release Date：2020-09-28
  Features：
  1、 Turkish/Ukrainian added.
```

V1.0.4 Build202008210001

```
  Release Date：2020-08-21
  Features：
  1、 Allow to set cornerRadius for bkImage for the watchface, and the preview will be automatically scaled.
```

V1.0.3 Build202008140001

```
  Release Date：2020-08-14
  Features：
  1、 Croatian/Albanian added.
```

V1.0.2 Build202007180001

```
  Release Date：2020-07-18
  Features：
  1、 rename to FitCloudWFKit.
```

V1.0.1 Build202007160001

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

Method 1：`FitCloudWFKit` is available through CocoaPods. To install it, simply add the following line to your Podfile:

```
pod 'FitCloudWFKit'
```

If you want to integrate beta FitCloudWFKit, you should use the following configuration in the podfile file:
```
pod 'FitCloudWFKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
```

Method 2: download from making ` FitCloudWFKit `, manual integrated into your project.

1. FitCloudWFKit SDK includes:
    * FitCloudWFKit. Framework  
      static library, smart watch development kit core framework
    * FitCloudWFKit.bundle   
      smart watch development kit core resource package

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
#import <FitCloudWFKit/FitCloudWFKit.h>
```

## Create the watchface

```objc
FitCloudAllConfigObject *allConfig = [FitCloudKit allConfig];

BOOL isNextGUI = [allConfig isKindOfClass:[FitCloudAllConfigObject class]] && allConfig.firmware && allConfig.firmware.isNewGUIArchitecture;

NSString* templateBinPath = [[NSBundle mainBundle] pathForResource:@"240USER_DEFAULT_20200618142928_MP-cc0c13932ab8ca2f89301678993cfdeb" ofType:@"bin"];

[FitCloudWFKit createWithTemplateBin:templateBinPath isNextGUI:isNextGUI rewriteNextGUIWatchfaceNo:nil bkImage:resolvedBKImage bkCornerRadius:0 preview:resolvedPreviewImage dtPosition:_watchfaceStyle.dtPosition progress:^(CGFloat progress, NSString * _Nullable message) {
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

## Change the push index of the watchface
```objc
NSString* templateBinPath = [[NSBundle mainBundle] pathForResource:@"240USER_DEFAULT_20200618142928_MP-cc0c13932ab8ca2f89301678993cfdeb" ofType:@"bin"];

[FitCloudWFKit modifyWatchfaceBinPushIndexTo:1 fromTemplateBin:templateBinPath logging:^(FCWKLOGLEVEL level, NSString * _Nullable message) {
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
} completion:^(BOOL success, NSString* _Nullable resultBinPath, NSError* _Nullable error) {
    if(success)
    {
        XLOG_INFO(@"modify push index success, bin file: %@", resultBinPath);
    }
    else
    {
        XLOG_ERROR(@"modify push index failure with error: %@", error.localizedDescription);
        
    }
}];
```


## Other Settings and Operations

see detail comments in `<FitCloudWFKit/FitCloudWFKit.h>` header file.

## FAQ

>Q: What is the watchface template bin file, how to get it？
>
>A: The template Bin file is the basis of the custom watchface. Different models and sizes of watch template Bin files are different. You need to store these template Bin files on your own server, and then download the specific template Bin file according to the watch information before proceeding. Process, you can contact our business to provide follow-up support.

## Technical Support

Hetang Smart.

Dai / iOS Developer
