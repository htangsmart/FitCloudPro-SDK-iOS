# 和唐智能手表固件升级（FitCloudDFUKit）iOS 开发指南

## 简介 / Summary

- 什么是和唐智能手环固件升级 SDK ?

  > ###### 和唐智能手环固件升级 SDK 是提供给和唐的合作伙伴的开发套件，该开发套件负责手环固件升级等功能的封装，旨在方便合作伙伴定制自己的智能手环应用。

- 适用范围

  ```
  需要个性化定制自己的 iOS 智能手环 APP 的合作伙伴。
  ```

- 兼容性

  ###### 1. iOS 9.0 及以上操作系统；

  ###### 2. 支持 armv7/i386/x86_64/arm64 指令集；

  ###### 3. 支持 Bitcode；

## 特性 / Features

1. 手环固件升级(不包括空中升级远程下载固件的部分)；

## 版本 / Releases

版本 V1.3.1 Build20240930001

```
  发布日期：2024年09月30日
  功能更新：
  1.Realtek音乐推送支持
  2.Realtek电子书/相册推送支持
  3.重命名日志回调函数
  4.新增终止固件升级功能
  5.更新Realtek固件升级SDK，支持8773型号芯片
  6.更新Realtek固件升级SDK，解决蓝牙关闭不及时回调错误的问题
  7.新增选项，支持Realtek升级程序设置回调完成前不等待断连动作，
  8.更新Realtek固件升级SDK，解决之前部分芯片平台固件升级报错的问题，并修正Realtek的版本号(原先原厂填错了版本号)
  9.Xcode 16 适配
```

版本 V1.3.0 Build202212300001

```
  发布日期：2022年12月30日
  功能更新：
  1.更新错误码翻译
  2.升级Realtek固件升级程序调用方式
  3.新增越南语
```

版本 V1.2.9 Build202206300001

```
  发布日期：2022年06月30日
  功能更新：
  1.升级Realtek固件升级程序，修复固件升级依旧慢的问题
```

版本 V1.2.8 Build202206060001

```
  发布日期：2022年06月06日
  功能更新：
  1.升级Realtek固件升级程序，修复固件升级慢的问题
```

版本 V1.2.7 Build202206010001

```
  发布日期：2022年06月01日
  功能更新：
  1. 修正OnStartDFUSuccess没有回调的问题
```

版本 V1.2.6 Build202201260001

```
  发布日期：2022年01月26日
  功能更新：
  1.升级Realtek固件升级程序，修复固件升级有可能报错的问题
  2.升级Realtek固件升级程序，支持8763E平台
  3.新增印地语
```

版本 V1.2.5 Build202112180001

```
  发布日期：2021年12月18日
  功能更新：
  1、升级Realtek固件升级程序，修复固件升级慢的问题。
```

版本 V1.2.4 Build202108230001

```
  发布日期：2021年08月23日
  功能更新：
  1、修正表盘推送可能失败的问题。
```

版本 V1.2.3 Build202108040001

```
  发布日期：2021年08月04日
  功能更新：
  1、修正iOS11.4系统固件升级失败的问题。
```

版本 V1.2.2 Build202106040001

```
  发布日期：2021年06月04日
  功能更新：
  1、Nordic固件升级支持。
```

版本 V1.2.1 Build202102250001

```
  发布日期：2021年02月25日
  功能更新：
  1、升级Realtek固件升级程序，支持8762D平台。
```

版本 V1.2.0 Build202009280001

```
  发布日期：2020年09月28日
  功能更新：
  1、新增土耳其语/乌克兰语。
```

版本 V1.1.9 Build202008140001

```
  发布日期：2020年08月14日
  功能更新：
  1、新增克罗地亚语/阿尔巴尼亚语。
```

版本 V1.1.8 Build202007100001

```
  发布日期：2020年07月10日
  功能更新：
  1、修正繁体中文翻译。
```

版本 V1.0.7 Build201911220001

```
  发布日期：2019年11月22日
  功能更新：
  1、新增斯洛伐克语。
```

版本 V1.0.6 Build201911210001

```
  发布日期：2019年11月21日
  功能更新：
  1、支持非连接状态的外设固件升级。
  2、提升升级过程可靠性。
```

版本 V1.0.5 Build201910180001

```
  发布日期：2019年10月18日
  功能更新：
  1、 修正UI文件升级过程有可能无法进入静默模式的问题。
```

版本 V1.0.4 Build201910160001

```
  发布日期：2019年10月16日
  功能更新：
  1、 修正iOS13闪退的问题。
```

版本 V1.0.3 Build201909300001

```
  发布日期：2019年09月30日
  功能更新：
  1、 支持UI文件升级。
```

版本 V1.0.0 Build201905010001

```
  发布日期：2019年05月01日
  功能更新：
  1、 首次发布SDK版本。
```

## 获取 APPID 和 APPKEY

目前尚未开放 APPID 和 APPKEY，暂时无需申请。

## 安装 / Installation

方法一：`FitCloudDFUKit` 支持通过 CocoaPods 安装. 您只需要在您的 Podfile 文件中简单地加上下面这行:

```
pod 'FitCloudDFUKit'
```

如果你想集成 beta 测试版，则 Podfile 文件中应该使用如下配置：

```
pod 'FitCloudDFUKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
```

方法二：从 Github 上下载 `FitCloudDFUKit`，手动集成到您的项目中。

1. FitCloudDFUKit SDK 开发包含：

- FitCloudDFUKit.xcframework 静态库，智能手环固件升级开发套件核心 framework

- FitCloudDFUKit.bundle 智能手环固件升级开发套件核心资源包

- RTKLEFoundation.xcframework

- RTKOTASDK.xcframework

- RTKLocalPlaybackSDK.xcframework

2. 将 framework 添加到项目中;
3. 将 bundle 资源包添加到项目中;
4. 添加其他系统依赖库支持：

   - CoreGraphics.framework

   - CoreBluetooth.framework

5. 在 Podfile 中添加

   pod 'iOSDFULibrary', '4.11.0'

## 设置隐私权限

在项目的`Info.plist`中设置以下隐私权限使用描述，实际描述内容各项目自行设置

![蓝牙隐私权限](media/privacy_bluetooth.png)

## 引用头文件

```objc
#import <FitCloudDFUKit/FitCloudDFUKit.h>
```

## 初始化 SDK

```objc
[FitCloudDFUKit setDebugMode:YES];
[FitCloudDFUKit setDelegate:self];
```

## 实现 FitCloudDFUDelegate 代理

```objc
/**
 * @brief 成功启动DFU回调
 */
-(void) OnStartDFUSuccess
{
    NSLog(@"成功进入DFU模式, 请勿退出当前界面...");
}

/**
 * @brief 启动DFU失败
 * @param error 错误信息
 */
-(void) OnStartDFUFailureWithError:(NSError*)error
{
    NSString *msg = APP_GET_ERROR_MSG(error);
    NSLog(@"固件升级失败，%@...", msg);
}

/**
 * @brief 升级进度回调
 * @param progress 升级进度百分比(0~100)
 * @param index 当前镜像索引，下标从0开始
 * @param total 所有镜像数量
 */
-(void) OnDFUProgress:(CGFloat)progress imageIndex:(NSInteger)index total:(NSInteger)total
{
    NSLog(@"当前固件升级进度：%2ld%%", (long)roundf(progress));
}

/**
 * @brief 意外终止回调
 * @param error 错误信息
 */
-(void) OnAbortWithError:(NSError*)error
{
    NSString *msg = APP_GET_ERROR_MSG(error);
    NSLog(@"固件升级终止，%@...", msg);
}

/**
 * @brief 升级完成回调
 * @param speed 速度
 */
-(void) OnDFUFinishWithSpeed:(CGFloat)speed
{
    NSLog(@"固件升级成功...");
}


/**
 *@brief 日志信息回调
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnDFULogMessage:(NSString*)message level:(FCDFUKLogLevel)level
{
    //您可以根据实际需要处理日志逻辑
}
```

## 启动固件升级

```objc
BOOL silentMode = FALSE;
if([FitCloudKit allConfig].firmware.hardwareSupported & FITCLOUDHARDWARE_DFUSHOULDSILENTMODE)
{
  silentMode = TRUE;
}
FITCLOUDDFUCHIPVENDOR chipVendor = FITCLOUDDFUCHIPVENDOR_REALTEK;
[FitCloudDFUKit startWithPeripheral:dfuPeripheral firmware:self.selectedPath chipVendor:chipVendor silentMode:silentMode];
```

## 普通固件升级/UI 固件升级/表盘推送/运动推送

**Step 1**

检查手表的电量，并获得升级的 dfuPeripheral，如果失败，我想你不应该继续接下来的流程。

```objc
[FitCloudKit enterDFUModeWithBlock:^(BOOL succeed, CBPeripheral *dfuPeripheral, FITCLOUDCHIPVENDOR chipVendor, NSError *error) {
}
```

**Step 2**

启动升级，silentMode 参数代表不同类型的升级。

普通固件升级:

```
BOOL silentMode = FALSE;
if([FitCloudKit allConfig].firmware.hardwareSupported & FITCLOUDHARDWARE_DFUSHOULDSILENTMODE)
{
  silentMode = TRUE;
}
```

UI 固件升级/表盘推送/运动推送:

```
BOOL silentMode = YES;
```

之后调用：

```objc
[FitCloudDFUKit startWithPeripheral:dfuPeripheral firmware:self.selectedPath chipVendor:chipVendor silentMode:silentMode];
```

处理 delegate 与日志回调信息。当升级成功或失败，您需要监听 DFU 模式下的回连通知，就像这样：

```objc
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnReconnectWithDFUMode:) name:FITCLOUDEVENT_PERIPHERAL_RECONNECTEDWITHDFUMODE_NOTIFY object:nil];
}

-(void)OnReconnectWithDFUMode:(NSNotification*)notification
{
    NSLog(@"%@", APP_LOG_STRING(@"手表重启成功，此次推送%@。", _lastDFUSucceed ? @"成功" : @"失败"));
}
```

**Step 3**

当您决定不再接着固件升级或者打算退出升级模式时，您需要调用以下方法，回到正常模式，当然此时会断开并重新连接手表。

```objc
[FitCloudKit exitDFUModeWithBlock:nil];
```

## 对接获取我们的表盘服务器时所需的参数

如果您是对接我们表盘服务器的客户，您可能需要从 SDK 里获得一些参数传给我们的服务器，当然获得这项能力您需要联系我们的商务。

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

- platform

```objc
NSString* platform = @"gui";
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
if(firmware && firmware.hardwareSupported & FITCLOUDHARDWARE_8773)
{
    platform = @"gui-8773";
}
else if(firmware && firmware.hardwareSupported & FITCLOUDHARDWARE_568X)
{
    platform = @"gui-5681";
}
```

## 音乐推送

- [音乐推送](../Others/Music/MUSIC.md)

## FAQ

> Q: 现在支持哪些芯片厂商的固件升级？
>
> A: SDK 已经集成了 `Realtek` 和 `Nordic` 厂商的固件升级程序，但由于目前所有手环其实只使用了 `Realtek` 的芯片，因此在实际使用过程中，您目前只会使用到 `Realtek` 芯片的固件升级。

<!-- more -->

> Q: 普通固件升级与 UI 升级有什么不同？
>
> A: 通常没有界面的固件升级称之为普通固件升级，涉及界面升级则为 UI 升级，当然推送表盘属于 UI 升级。

## 技术支持

和唐智能

戴工 / iOS Developer
