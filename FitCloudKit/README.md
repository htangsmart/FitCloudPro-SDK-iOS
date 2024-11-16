# 和唐智能手表（FitCloudKit）iOS 开发指南

## 简介 / Summary

- 什么是和唐智能手表 SDK ?

  > ###### 和唐智能手表 SDK 是提供给和唐的合作伙伴的开发套件，该开发套件负责与手表设备通信等功能的封装，旨在方便合作伙伴定制自己的智能手表应用。

- 适用范围

  ```
  需要个性化定制自己的 iOS 智能手表 APP 的合作伙伴。
  ```

- 兼容性

  ###### 1. iOS 8.0 及以上操作系统；

  ###### 2. 支持 armv7/i386/x86_64/arm64 指令集；

  ###### 3. 支持 Bitcode；

## 特性 / Features

1. 初始化/扫描/连接手表；

2. 获取/设置手表相关功能及显示；

3. 同步运动健康数据到 APP；

4. 启动/停止健康实时测量(心率/血压/血氧/心电等)；

5. 同步天气信息；

6. 查找手表/iOS 设备；

7. 一键恢复出厂设置；

8. 手表重启/关机；

9. 进入 DFU 模式前安全检查(保证手表有充足的电量)；

## 版本 / Releases

[版本更新日志](RELEASE_CN.md)

## 获取 APPID 和 APPKEY

目前尚未开放 APPID 和 APPKEY，暂时无需申请。

## 安装 / Installation

方法一：`FitCloudKit` 支持通过 CocoaPods 安装. 您只需要在您的 Podfile 文件中简单地加上下面这行:

```
pod 'FitCloudKit'
```

如果你想集成 beta 测试版，则 Podfile 文件中应该使用如下配置：

```
pod 'FitCloudKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
```

方法二：从 Github 上下载 `FitCloudKit`，手动集成到您的项目中。

1. FitCloudKit SDK 开发包含：

- FitCloudKit.xcframework 静态库，智能手表开发套件核心 framework

- FitCloudKit.bundle 智能手表开发套件核心资源包

2. 将 framework 添加到项目中;
3. 将 bundle 资源包添加到项目中;
4. 添加其他系统依赖库支持：

   - CoreGraphics.framework

   - CoreBluetooth.framework

5. 添加 `-ObjC` 链接标志
   在项目的 `Build Settings` 的 `Other Linker Flags` 中添加 `-ObjC` 链接标志，如下图所示：

   ![ObjC Other Link Flag](media/build_settings.png)

## 设置隐私权限

在项目的`Info.plist`中设置以下隐私权限使用描述，实际描述内容各项目自行设置

![蓝牙隐私权限](media/privacy_bluetooth.png)

## 设置蓝牙后台模式

![设置蓝牙后台模式](media/bluetooth_backgroundmode.png)

## 引用头文件

```objc
#import <FitCloudKit/FitCloudKit.h>
```

## 初始化 SDK

```objc
FitCloudOption *option = [FitCloudOption defaultOption];
option.debugMode = NO;
option.shouldAutoReconnectWhenAppLaunch = YES;
self.fitCloudKit = [FitCloudKit initWithOption:option callback:self];
```

## 实现 FitCloudCallback 回调协议

```objc
/**
 *@brief 手表请求查找手机
 */
-(void) OnFindiPhoneEvent
{
    //在这里实现当手机收到查找请求时你的APP响应逻辑，比如振动，播放一段音乐，或创建一个本地通知等等
}

/**
 *@brief 手表请求天气信息
 *@param block 天气信息回调
 */
-(void) OnRequestWeatherWithCallback:(FitCloudWeatherCallbackBlock)block
{
    //手表请求天气信息，您需要自行获取天气信息并回调给手表SDK，
    //但目前该方法基本不会回调（手表没有实现该逻辑），目前需要自行同步天气给手表。
    //@see syncWeather:block:
}

/**
 *@brief 实时运动健康测量数据（心电数据例外）
 *@param records 数据
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    //根据实际业务逻辑响应手表实时测量数据
}

/**
 *@brief 心电实时测量结果
 *@param ecgDataArray 数据
 *@param interval 采样间隔, 单位：毫秒(ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    //根据实际业务逻辑响应手表心电实时测量数据
}

/**
 *@brief 心电实时测量结束
 */
-(void) OnRealTimeECGStop
{
    //通知业务逻辑心电实时测量停止了
}

/**
 *@brief 手表控制手机拍照
 */
-(void)OnTakePhotoCtrl
{
    //App 可以在此实现拍照逻辑
}

/**
 *@brief 收到手表的活跃通知(当前手表与手机连接还活跃着)
 */
-(void) OnBraceletAlive
{
    //App 可以主动同步手表的运动健康数据以达到后台同步数据的功能，请根据具体项目需要添加，注意后台定期同步数据可能影响手表设备的功耗
}

/**
 *@brief 日志信息回调
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnLogMessage:(NSString*)message level:(FITCLOUDKITLOGLEVEL)level
{
    //您可以根据实际需要处理日志逻辑
}
```

## 获取蓝牙中心设备(Central)状态

```objc
FITCLOUDBLECENTRALSTATE bleState = [FitCloudKit bleState];
//蓝牙设备未处于打开状态
if(bleState != FITCLOUDBLECENTRALSTATE_POWEREDON)
{
    //蓝牙已被关闭
    if(bleState == FITCLOUDBLECENTRALSTATE_POWEREDOFF)
    {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
    }
    else
    {
        //请求打开蓝牙来允许连接到配件
        [FitCloudKit requestShowBluetoothPowerAlert];
    }
}
```

## 扫描手表

```objc

//监听扫描相关事件通知
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredUpdatedNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralScanStopNotification:) name:FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY object:nil];
//开始扫描
[FitCloudKit scanPeripherals];
```

## 连接手表

```objc
//监听连接相关事件通知
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY object:nil];

//开始连接
FitCloudPeripheral* item = [self.peripherals objectAtIndex:indexPath.row];
[FitCloudKit connect:item.peripheral];
```

## 绑定用户

```objc
//监听绑定相关事件通知
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudBindUserObjectBegin:) name:FITCLOUDEVENT_BINDUSEROBJECT_BEGIN_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudBindUserObjectResult:) name:FITCLOUDEVENT_BINDUSEROBJECT_RESULT_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudGetAllConfigBegin:) name:FITCLOUDEVENT_GETALLCONFIG_BEGIN_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudGetAllConfigResult:) name:FITCLOUDEVENT_GETALLCONFIG_RESULT_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudInitializeResult:) name:FITCLOUDEVENT_INITIALIZE_RESULT_NOTIFY object:nil];
//开始绑定
NSInteger userId = 1000;
[FitCloudKit bindUserObject:userId abortIfExist:YES block:^(BOOL succeed, NSError *error) {
}];
```

## 解绑用户

```objc
//开始解绑，解绑成功后是否需要自动断开手表连接
[FitCloudKit unbindUserObject:YES block:^(BOOL succeed, NSError *error) {
}];
```

## 手动同步历史运动健康数据

```objc
[FitCloudKit manualSyncDataWithOption:FITCLOUDDATASYNCOPTION_ALL progress:^(CGFloat progress, NSString *tip) {
    NSLog(@"同步进度：%.0f%%, %@",progress*100.0f, tip);
} block:^(BOOL succeed, NSArray<FitCloudManualSyncRecordObject*> *records, NSError *error) {
    //同步结果
}];
```

## 获取当天运动健康数据信息(综合信息, 当天运动总步数/平均心率/卡路里等)

```objc
 [FitCloudKit requestHealthAndSportsDataTodayWithBlock:^(BOOL succeed, FitCloudDailyHealthAndSportsDataObject *dataObject, NSError *error) {
}];
```

## 启动/关闭实时健康测量（心率、血氧、血压、呼吸频率、心电等）

⚠️ 注意事项：心电请勿与其他实时测量同时进行。

```objc
//设置参数
//示例：启动心率和血压测量，其他情况根据实际业务逻辑设置该参数
FITCLOUDREALTIMEMHEALTHEASUREITEM item = FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE | FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE;
/*
    //停止测量
    //FITCLOUDREALTIMEMHEALTHEASUREITEM item = FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE;
*/
FitCloudRealTimeHealthMeasuringParam *param = [FitCloudRealTimeHealthMeasuringParam new];
param.item = item;
param.interval = 5;
param.maxMeasuringMinutes = 1;

//调用SDK，启动或停止测量（取决于传入的参数）
[FitCloudKit requestRealTimeHealthMeasuring:param block:^(BOOL succeed, NSError *error) {
}];
```

实时测量结果：
@see FitCloudCallback 回调协议

```objc
/**
 *@brief 实时运动健康测量数据（心电数据例外）
 *@param records 数据
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    //根据实际业务逻辑响应手表实时测量数据
}

/**
 *@brief 心电实时测量结果
 *@param ecgDataArray 数据
 *@param interval 采样间隔, 单位：毫秒(ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    //根据实际业务逻辑响应手表心电实时测量数据
}

/**
 *@brief 心电实时测量结束
 */
-(void) OnRealTimeECGStop
{
    //通知业务逻辑心电实时测量停止了
}
```

## 常见功能

[常见功能](COMMON_FEATURES.md)

## 板球比赛

[板球比赛](../Others/CricketMatch/CRICKETMATCH.md)

## 其他设置和操作

参看`<FitCloudKit/FitCloudKit.h>`头文件中详细注释说明。

## FAQ

> Q: FitCloudKit 主干调用流程是什么？
>
> A: 如下图所示：
>
> ![invoke help cn](media/invoke_help_cn.png)

<!-- more -->

> Q: 如何判断当前手表固件是否支持特定的功能，例如：怎么判断当前手表固件是否支持勿扰模式？
>
> A: 您可以根据固件提供的信息获取当前手表所支持的功能，包含软件功能和硬件功能的部分。
>
> 以勿扰模式为例，代码如下：

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL isDNDSupported = (allConfig && allConfig.firmware && allConfig.firmware.allowDNDMode);
```

> 以上是软件功能的示例，硬件功能参看下一个 FAQ。

<!-- more -->

> Q: 如何判断当前手表是否支持特定的硬件功能，例如：怎么判断是否是具有心电功能的手表？
>
> A: 您可以根据固件提供的信息获取当前手表所支持的功能，例如：该手表是否具有心率/血氧/血压/呼吸频率/天气预报/心电/是否支持运动模式/是否支持微信运动/是否需要使用新的固件升级平台/是否支持动态心率等。
>
> 以心电功能为例，代码如下：

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL isECGSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_ECG));
```

> Q: 如何理解睡眠格式？
>
> A: 如下图所示：
>
> ![sleep data format](media/sleep_data_format.png)

<!-- more -->

> Q: 绑定用户过程中，弹出蓝牙配对请求弹窗，用户是否必须选择与手表进行配对？
>
> A: 理论上不是必须的，但是如果选择不配对的话，手表的消息提醒功能(如 QQ/微信/Facebook/Twitter 等)将不能正常工作。

<!-- more -->

> Q: 如何处理多台 iOS 设备先后绑定配对同一个手表导致的异常情况？
>
> A: 通常情况下，用户只会拿一台 iOS 设备去绑定配对手表，但仍然有少部分用户会拿多台 iOS 设备先后去绑定配对一个手表，从而导致先前连接配对的那台 iOS 设备与手表配对异常，无法重新连接手表，这是由于这些手表设备同时只能存储与一台 iOS 设备的配对信息所导致的，后面设备的配对信息覆盖了之前的配对信息，从而导致 iOS 设备上的配对信息与手表上的配对信息不匹配，请参照 FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY 通知进行处理。

## 技术支持

和唐智能

戴工 / iOS Developer
