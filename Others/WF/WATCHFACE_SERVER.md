# 自定义表盘与表盘推送 iOS 开发指南

## 1. 表盘推送

表盘推送的过程跟固件升级类似，将表盘文件通过调用 FitCloudDFUKit 推送到手表即可。在此之前你需要获得表盘文件，表盘文件可以是存储在您自己的服务器上也可以从和唐的服务器获取，这取决于您与和唐约定的合作方式。

#### 大致流程

1. 从服务器下载表盘文件。

2. 调用 FitCloudDFUKit 将表盘文件推送到手表。

#### 自己实现表盘服务器

如果您是将表盘文件存储在自己的服务器上，你可以按照自己喜欢或熟悉的方式实现，且可以随意部署您的表盘文件并获得更好的性能，这也使得你可以使用表盘生成工具为您的客户生成更具个性化的表盘部署在你的服务器上，您仅仅需要满足 App 客户端能够获得与当前手表匹配的表盘列表即可。
如何根据当前手表获得与之匹配的表盘列表，您可以参照我们的表盘服务器 API 参数信息。

#### 对接我们的表盘服务器

接口地址：http://fitcloud.hetangsmart.com/public/dial/list  
接口作用：查询匹配当前手表的表盘列表  
调用方法：POST
接口参数：

| 参数         | 类型   | 必填 | 说明                        |
| ------------ | ------ | ---- | --------------------------- |
| hardwareInfo | String | 是   | 硬件字符串                  |
| lcd          | int    | 是   | 表盘 LCD 分辨率尺寸的 ID 值 |
| toolVersion  | String | 是   | 表盘工具版本                |

返回值：

| 返回字段  | 类型   | 说明                                                                       |
| --------- | ------ | -------------------------------------------------------------------------- |
| errorCode | int    | 错误码，0 代表成功，其他数值代表失败。根据实际接口的错误类型决定失败数值。 |
| errorMsg  | String | 错误描述。errorCode 为 0 时，此字段为空。                                  |
| data      | List   | 表盘文件信息的 JSON 列表                                                   |

```
Watchface {
    int dialNum;
    int lcd;
    String toolVersion;
    String binUrl;
    long binSize;        // bin文件大小，单位byte
    int binVersion;
    String imgUrl;
    String deviceImgUrl;
    String name;
    int downloadCount;
    String type;          // basic: 第一版表盘   gui: 新版gui表盘
    int hasComponent;     // 0 无组件，1 有组件
    String previewImgUrl; // 组件预览背景图
    List<Component> components;  //组件列表
}

Component{
	int width;//从bin文件解析的组件的宽度
	int height;//从bin文件解析的组件的高度
	int positionX;//组件的x坐标
	int positionY;//组件的y坐标
	List<String> urls;//组件的图片url
}

```

示例：
![调用示例](media/api_example.png)

#### 对接获取我们的表盘服务器时所需的参数

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

#### 调用 FitCloudDFUKit 将表盘文件推送到手表

[参看 Github 上 FitCloudDFUKit 的相关文档。](https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudDFUKit/README.md)

## 2. 自定义表盘

自定义表盘允许你根据现有的表盘模版文件修改表盘的背景图/预览图/日期的位置，关于不同的日期样式，如果你集成我们表盘的服务器，我们为您提供了五种颜色和字体样式，因此，如果你需要具有更个性化的样式或更多的日期样式种类，你需要自己实现表盘服务器。
表盘模版文件可以是存储在您自己的服务器上也可以从和唐的服务器获取，这取决于您与和唐约定的合作方式。

#### 大致流程

1. 从服务器下载表盘模版文件。

2. 调用 FitCloudWFKit 修改表盘的背景图/预览图/日期的位置等，生成新的表盘文件。

3. 调用 FitCloudDFUKit 将生成的新的表盘文件推送到手表。

#### 自己实现表盘模版服务器

如果您是将表盘模版文件存储在自己的服务器上，你可以按照自己喜欢或熟悉的方式实现，且可以随意部署您的表盘模版文件并获得更好的性能，这也使得你可以使用表盘生成工具为您的客户生成更具个性化的表盘模版部署在你的服务器上，您仅仅需要满足 App 客户端能够获得与当前手表匹配的表盘模版列表即可。
如何根据当前手表获得与之匹配的表盘列表，您可以参照我们的表盘服务器 API 参数信息。

#### 对接我们的表盘模版服务器

1. 判断手表是否为新的 GUI 架构

```
BOOL isNextGUI = NO;
 FitCloudAllConfigObject *allConfig = [FitCloudKit allConfig];
if([allConfig isKindOfClass:[FitCloudAllConfigObject class]])
{
    isNextGUI = allConfig.firmware.isNewGUIArchitecture;
}
```

2. 根据 `isNextGUI` 查询匹配当前手表的表盘模版

- 不是新的 GUI 架构

接口地址：http://fitcloud.hetangsmart.com/public/dial/custom  
接口作用：查询匹配当前手表的表盘模版列表  
调用方法：POST
接口参数：

| 参数        | 类型   | 必填 | 说明                        |
| ----------- | ------ | ---- | --------------------------- |
| lcd         | int    | 是   | 表盘 LCD 分辨率尺寸的 ID 值 |
| toolVersion | String | 是   | 表盘工具版本                |

返回值：

| 返回字段  | 类型   | 说明                                                                       |
| --------- | ------ | -------------------------------------------------------------------------- |
| errorCode | int    | 错误码，0 代表成功，其他数值代表失败。根据实际接口的错误类型决定失败数值。 |
| errorMsg  | String | 错误描述。errorCode 为 0 时，此字段为空。                                  |
| data      | List   | 表盘模版样式的 JSON 列表，包含了 5 种不同日期样式的模版文件                |

```
WatchfaeTemplate {
    String binUrl;
    long binSize;  // bin文件大小，单位byte
    String styleName;  //样式名, Black/Gray/Green/White/Yellow
}
```

示例：
![调用示例](media/api_custom_example.jpg)

- 是新的 GUI 架构

接口名称：http://fitcloud.hetangsmart.com/public/dial/customgui  
接口作用：查询符合的 gui 自定义表盘
接口参数：

| 参数        | 类型   | 必填 | 说明                        |
| ----------- | ------ | ---- | --------------------------- |
| lcd         | int    | 是   | 表盘 LCD 分辨率尺寸的 ID 值 |
| toolVersion | String | 是   | 表盘工具版本                |

返回值：
|返回字段|类型|说明|
|-|-|-|
|errorCode|int|错误码，0 代表成功，其他数值代表失败。根据实际接口的错误类型决定失败数值。|
|errorMsg|String|错误描述。errorCode 为 0 时，此字段为空。|
|data|List|Dial 的 JSON 对象|

```
WatchfaeTemplate {
    String binUrl;
    long binSize;  // bin文件大小，单位byte
}
```

示例：
![调用示例](media/api_custom_nextgui_example.jpg)

#### 对接获取我们的表盘模版服务器时所需的参数

如果您是对接我们表盘服务器的客户，您可能需要从 SDK 里获得一些参数传给我们的服务器，当然获得这项能力您需要联系我们的商务。

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

#### 日期的样式

我们为您提供了五种颜色和字体样式，这是固定的几种样式，因此你无法去随意更改，如果这不能满足您的需求，您只能自己实现表盘模版服务器。
我们提供的样式如下，你可以下载下来以便在客户端合成表盘预览图，这与我们服务器上提供的五种模版文件一一对应。

| White                              | Black                              | Yellow                             | Green                              | Gray                               |
| ---------------------------------- | ---------------------------------- | ---------------------------------- | ---------------------------------- | ---------------------------------- |
| ![1](media/watchface_dtstyle1.png) | ![2](media/watchface_dtstyle2.png) | ![3](media/watchface_dtstyle3.png) | ![4](media/watchface_dtstyle4.png) | ![5](media/watchface_dtstyle5.png) |

#### 背景图与预览图

这需要您自己根据表盘的大小自己生成，特别是宽高比必须跟手表保持一致，且不要小于表盘的实际尺寸。预览图需要你自己根据背景图和日期样式合成好，这样的好处是，你可以尽可能保证你们的原始设定样式。

#### 调用 FitCloudWFKit 修改表盘的背景图/预览图/日期的位置等，生成新的表盘文件

[参看 Github 上 FitCloudWFKit 的相关文档。](https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudWFKit/README.md)

#### 调用 FitCloudWFKit 修改表盘推送到手表上的位置（可选）

如果你需要指定表盘推送到手表上的位置，你可以再次调用 FitCloudWFKit 来修改表盘文件，如果不需要直接跳到下一步。

[参看 Github 上 FitCloudWFKit 的相关文档。](https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudWFKit/README.md)

#### 调用 FitCloudDFUKit 将生成的新的表盘文件推送到手表

[参看 Github 上 FitCloudDFUKit 的相关文档。](https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudDFUKit/README.md)
