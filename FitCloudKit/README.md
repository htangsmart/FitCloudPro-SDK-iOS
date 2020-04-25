# 和唐智能手表（FitCloudKit）iOS开发指南

## 简介 / Summary
* 什么是和唐智能手表 SDK ?

  >###### 和唐智能手表 SDK 是提供给和唐的合作伙伴的开发套件，该开发套件负责与手环设备通信等功能的封装，旨在方便合作伙伴定制自己的智能手环应用。       


* 适用范围

  ```
  需要个性化定制自己的 iOS 智能手表 APP 的合作伙伴。
  ```

* 兼容性

  ###### 1. iOS 8.0及以上操作系统；

  ###### 2. 支持armv7/i386/x86_64/arm64指令集；

  ###### 3. 支持Bitcode；


## 特性 / Features

1. 初始化/扫描/连接手表；

2. 获取/设置手表相关功能及显示；

3. 同步运动健康数据到 APP；

4. 启动/停止健康实时测量(心率/血压/血氧/心电等)；

5. 同步天气信息；

6. 查找手表/iOS设备；

7. 一键恢复出厂设置；

8. 手表重启/关机；

9. 进入 DFU 模式前安全检查(保证手表有充足的电量)；

## 版本 / Releases

版本V1.1.8 Build202004250001

```
  发布日期：2020年04月25日
  功能更新：
  1.修正解绑有可能出现未断开连接的问题
  2.修正在自动登录过程中手表断开连接有可能导致提示手表被其他手机终端绑定或已经被解绑的问题
  3.修正当命令执行超时的情况下会丢掉下一条待执行的命令的问题
  4.修正同步数据量较大的健康数据时可能导致超时的问题
  5.解绑后清除电量信息
  6.支持常用联系人，仅部分手表支持
  7.手表运动模式新增椭圆机/瑜伽/乒乓球/跳绳等运动
  8.修正心电启动失败时逻辑处理不正确的问题
  9.修正连接手表超时不执行连接超时逻辑的问题
```

版本V1.1.7 Build202002250001

```
  发布日期：2020年02月25日
  功能更新：
  1.新增斯洛伐克语
  2.修正手表返回的睡眠数据睡眠质量可能为非法值的情况
  3.取消自动解绑逻辑,新增手表被其他手机终端绑定或已经被解绑通知 @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY
  4.所有回调以及通知均改成在 Gloal Queue 中调用，如果要在回调或者通知中更新UI，请务必切换到主队列(Main Queue)
  5.外部调用 disconnect 将不会自动回连
  6.新增 FITCLOUDUSERBINDSTATUS_KICKEDOUT 用户绑定状态
  7.新增 FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY 通知
  8.新增支持新的睡眠格式 @see newSleepDataFormat
  9.日志信息支持查看较大数据包的完整数据
  10.手表端主动更改了开关设置(例如：抬腕唤醒开关，通知开关等)会适时更新到App端 @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY
  11.表盘信息获取方法修改
  12.其他一些改进
```

版本V1.1.6 Build201911210001

```
  发布日期：2019年11月21日
  功能更新：
  1.修正表盘UI信息接口无法正确响应的问题
  2.解绑用户后取消当前手环连接记录的自动重连
  3.优化手环连接初始化过程，防止意外重连
  4.调整手环硬件相关信息为只读
  5.绑定用户的UserId由整型修改成字符串型
  6.新增获取手环最后一次健康测量数据(心率/血氧/血压)，仅部分手环支持，@see allowRetrieveLatestMeasurementData
  7.修改进入和退出固件升级模式方法，现在您在首次固件升级之前以及所有固件升级操作完成之后分别手动调用进入固件升级模式和退出固件升级模式，同时适用于普通固件升级与表盘推送
  8.新增DFU模式回连成功通知，这通常用于等待表盘推送/普通固件升级之后手环重启的场景
  9.提升SDK稳定性
```

版本V1.1.5 Build201911130001

```
  发布日期：2019年11月13日
  功能更新：
  1.新增勿扰模式(仅部分手环支持 @see allowDNDMode)
```

版本V1.1.4 Build201910240001

```
  发布日期：2019年10月24日
  功能更新：
  1.实时测量moment修改精确到秒
  2.修正同步数据moment使得不会超过当前同步时间
```

版本V1.1.3 Build201910160001

```
  发布日期：2019年10月16日
  功能更新：
  1.计步数据引入距离&卡路里新算法
  2.新增获取用户最后绑定时间
  3.新增心率报警/血压报警设置
  4.新增Snapchat消息提醒选项
  5.设备扫描取消设备名称过滤
  6.心电实时测量新增手环主动结束逻辑
  7.新增获取表盘UI信息接口
  8.新增获取手环广播数据缓存,因此现在您可以获取到曾经连接过的手环的Mac地址
  9.新增蓝牙名称变更通知，新增蓝牙RSSI变更通知
  10.提升SDK稳定性
  11.避免歧义，+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals 修改为  +(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals
```

版本V1.1.3-beta.9 Build201909300001

```
  发布日期：2019年09月30日
  功能更新：
  1.计步数据引入距离&卡路里新算法
  2.新增获取用户最后绑定时间
  3.新增心率报警/血压报警设置
  4.新增Snapchat消息提醒选项
  5.设备扫描取消设备名称过滤
  6.心电实时测量新增手环主动结束逻辑
  7.新增获取表盘UI信息接口
  8.提升SDK稳定性
```

版本V1.1.2 Build201908190002

```
  发布日期：2019年08月19日
  功能更新：
  1.修正蓝牙连接开始的通知时刻问题
```

版本V1.1.1 Build201908190001

```
  发布日期：2019年08月19日
  功能更新：
  1.修正手环解绑没有清除上一次绑定手环的Mac地址的问题
  2.新增绑定/登录成功后需要完成一些基础准备同步操作的开始与结束通知
  3.修正SDK初始化选项shouldAutoConnect不起作用的问题
```

版本V1.1.0 Build201908120001

```
  发布日期：2019年08月12日
  功能更新：
  1、 支持后台蓝牙数据同步功能
```

版本V1.0.9 Build201907210001

```
  发布日期：2019年07月21日
  功能更新：
  1、 支持获取当前SDK版本信息
```

版本V1.0.8 Build201907200001

```
  发布日期：2019年07月20日
  功能更新：
  1、 修正iPhone日历设置成佛教日历或者日本日历的时候导致手环同步时间失败的问题
  2、 优化手环回连机制
```

版本V1.0.7 Build201906280001

```
  发布日期：2019年06月28日
  功能更新：
  1、 修正无法获取消息通知设置的一些问题
```

版本V1.0.6 Build201906270001

```
  发布日期：2019年06月27日
  功能更新：
  1、 扫描到的外部设备新增mac地址数据
```

版本V1.0.5 Build201906250001

```
  发布日期：2019年06月25日
  功能更新：
  1、 修改支持设置运动目标
```

版本V1.0.4 Build201906110001

```
  发布日期：2019年06月11日
  功能更新：
  1、 支持手环设置更多语言。
  2、 修复了手环同步的一些问题。
```

版本V1.0.0 Build201905010001

```
  发布日期：2019年05月01日
  功能更新：
  1、 首次发布SDK版本。
```

## 获取 APPID 和 APPKEY

目前尚未开放 APPID 和 APPKEY，暂时无需申请。

## 安装 / Installation

方法一：`FitCloudKit` 支持通过 CocoaPods 安装. 您只需要在您的 Podfile 文件中简单地加上下面这行:

```
pod 'FitCloudKit'
```

方法二：从 Github 上下载 `FitCloudKit`，手动集成到您的项目中。

1. FitCloudKit SDK开发包含：

  * FitCloudKit.framework   静态库，智能手环开发套件核心framework

  * FitCloudKit.bundle     智能手环开发套件核心资源包

2. 将framework添加到项目中;
3. 将bundle资源包添加到项目中;
4. 添加其他系统依赖库支持：

    * CoreGraphics.framework

    * CoreBluetooth.framework
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

## 初始化SDK

```objc
FitCloudOption *option = [FitCloudOption defaultOption];
option.debugMode = NO;
option.shouldAutoConnect = YES;
self.fitCloudKit = [FitCloudKit initWithOption:option callback:self];
```

## 实现 FitCloudCallback 回调协议

```objc
/**
 *@brief 手环请求查找手机
 */
-(void) OnFindiPhoneEvent
{
    //在这里实现当手机收到查找请求时你的APP响应逻辑，比如振动，播放一段音乐，或创建一个本地通知等等
}

/**
 *@brief 手环请求天气信息
 *@param block 天气信息回调
 */
-(void) OnRequestWeatherWithCallback:(FitCloudWeatherCallbackBlock)block
{
    //手环请求天气信息，您需要自行获取天气信息并回调给手环SDK，
    //但目前该方法基本不会回调（手环没有实现该逻辑），目前需要自行同步天气给手环。
    //@see syncWeather:block:
}

/**
 *@brief 实时运动健康测量数据（心电数据例外）
 *@param records 数据
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    //根据实际业务逻辑响应手环实时测量数据
}

/**
 *@brief 心电实时测量结果
 *@param ecgDataArray 数据
 *@param interval 采样间隔, 单位：毫秒(ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    //根据实际业务逻辑响应手环心电实时测量数据
}

/**
 *@brief 心电实时测量结束
 */
-(void) OnRealTimeECGStop
{
    //通知业务逻辑心电实时测量停止了
}

/**
 *@brief 手环控制手机拍照
 */
-(void)OnTakePhotoCtrl
{
    //App 可以在此实现拍照逻辑
}

/**
 *@brief 收到手环的活跃通知(当前手环与手机连接还活跃着)
 */
-(void) OnBraceletAlive
{
    //App 可以主动同步手环的运动健康数据以达到后台同步数据的功能，请根据具体项目需要添加，注意后台定期同步数据可能影响手环设备的功耗
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

## 扫描手环

```objc

//监听扫描相关事件通知
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredUpdatedNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralScanStopNotification:) name:FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY object:nil];
//开始扫描
[FitCloudKit scanPeripherals];
```

## 连接手环

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
//开始解绑，解绑成功后是否需要自动断开手环连接
[FitCloudKit unbindUserObject:YES block:^(BOOL succeed, NSError *error) {
}];
```

## 手动同步历史运动健康数据

```objc
[FitCloudKit manualSyncDataWithProgress:^(CGFloat progress, NSString *tip) {
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
⚠️注意事项：心电请勿与其他实时测量同时进行。

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

## 其他设置和操作

参看`<FitCloudKit/FitCloudKit.h>`头文件中详细注释说明。

## FAQ

>Q: FitCloudKit 主干调用流程是什么？
>
>A: 如下图所示：

![invoke help cn](media/invoke_help_cn.png)

>Q: 如何判断当前手环是否支持特定的硬件功能，例如：怎么判断是否是具有心电功能的手环？
>
>A: 您可以根据固件提供的信息获取当前手环所支持的功能，例如：该手环是否具有心率/血氧/血压/呼吸频率/天气预报/心电/是否支持运动模式/是否支持微信运动/是否需要使用新的固件升级平台/是否支持动态心率等。
>
>以心电功能为例，代码如下：

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];   
BOOL isECGSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_ECG));
```

<!-- more -->

>Q: 绑定用户过程中，弹出蓝牙配对请求弹窗，用户是否必须选择与手环进行配对？
>
>A: 理论上不是必须的，但是如果选择不配对的话，手环的消息提醒功能(如QQ/微信/Facebook/Twitter等)将不能正常工作。

## 技术支持

和唐智能

戴工 / iOS Developer
