# 和唐智能手表自定义表盘（FitCloudWFKit）iOS开发指南

## 简介 / Summary
* 什么是和唐智能手表自定义表盘 SDK ?

  >###### 和唐智能手表自定义表盘 SDK 是提供给和唐的合作伙伴的开发套件，该开发套件旨在帮助您轻松创建属于您自己的表盘文件。       


* 适用范围

  ```
  需要个性化定制自己的 iOS 智能手表 APP 的合作伙伴。
  ```

* 兼容性

  ###### 1. iOS 8.0及以上操作系统；

  ###### 2. 支持armv7/i386/x86_64/arm64指令集；

  ###### 3. 支持Bitcode；


## 特性 / Features

1. 根据模版Bin文件生成新的自定义表盘Bin文件；

## 版本 / Releases

版本V1.0.2 Build202007180001

```
  发布日期：2020年07月18日
  功能更新：
  1、 rename to FitCloudWFKit。
```

版本V1.0.1 Build202007160001

```
  发布日期：2020年07月16日
  功能更新：
  1、 自动裁剪背景图/预览图。
```

版本V1.0.0 Build202007100001

```
  发布日期：2020年07月10日
  功能更新：
  1、 首次发布SDK版本。
```

## 获取 APPID 和 APPKEY

目前尚未开放 APPID 和 APPKEY，暂时无需申请。

## 安装 / Installation

方法一：`FitCloudWFKit` 支持通过 CocoaPods 安装. 您只需要在您的 Podfile 文件中简单地加上下面这行:

```
pod 'FitCloudWFKit'
```

方法二：从 Github 上下载 `FitCloudWFKit`，手动集成到您的项目中。

1. FitCloudWFKit SDK开发包含：

  * FitCloudWFKit.framework   静态库，智能手表开发套件核心framework

  * FitCloudWFKit.bundle     智能手环开发套件核心资源包

2. 将framework添加到项目中;
3. 将bundle资源包添加到项目中;
4. 添加其他系统依赖库支持：

    * CoreGraphics.framework

    * CoreBluetooth.framework

    * UIKit.framework

    * Accelerate.framework
5. 添加 `-ObjC` 链接标志
   在项目的 `Build Settings` 的 `Other Linker Flags` 中添加 `-ObjC` 链接标志，如下图所示：

   ![ObjC Other Link Flag](media/build_settings.png)


## 引用头文件

```objc
#import <FitCloudWFKit/FitCloudWFKit.h>
```

## 生成自定义表盘

```objc
NSString* templateBinPath = [[NSBundle mainBundle] pathForResource:@"240USER_DEFAULT_20200618142928_MP-cc0c13932ab8ca2f89301678993cfdeb" ofType:@"bin"];

[FitCloudWFKit createWithTemplateBin:templateBinPath bkImage:resolvedBKImage preview:resolvedPreviewImage dtPosition:_watchfaceStyle.dtPosition progress:^(CGFloat progress, NSString * _Nullable message) {
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


## 其他设置和操作

参看`<FitCloudWFKit/FitCloudWFKit.h>`头文件中详细注释说明。

## FAQ

>Q: 什么是模版Bin文件，在什么地方获取？
>
>A: 模版Bin文件是自定义表盘的基础，不同型号不同尺寸的手表模版Bin文件都不相同，您需要在自己的服务器上存放这些模版Bin文件，然后根据手表信息下载特定的模版Bin文件后再进行后续流程，您可以联系我们的商务提供后续的支持。



## 技术支持

和唐智能

戴工 / iOS Developer
