# 路线规划及步骑行导航对接文档

Route planning and cycling navigation Development Guide

**Step 1**
使用 Cocoapods 安装。由于依赖关系复杂，且需要大量的链接库，因此不建议手动安装。
Install using Cocoapods. Due to complex dependency relationships and the need for a large number of link libraries, manual installation is not recommended.

```objc

target 'RoutePlanDemo' do
  platform :ios, '10.0'
  workspace 'RoutePlanDemo.xcworkspace'
  project 'RoutePlanDemo.xcodeproj'
  # Uncomment this line if you're using Swift or would like to use dynamic frameworks
  use_frameworks!
  # Pods for RoutePlanDemo
  pod 'FitCloudRoutePlan',:path => '../'

end

```

**Step 2**
需要为 Info.plist 额外配置以下字段
The following additional fields need to be configured for Info.plist

```
Bundle display name
```

```
Privacy - Location Always Usage Description
```

```
Privacy - Location Always and When In Use Usage Description
```

```
Privacy - Location When In Use Usage Description
```

```
Required background modes
    App plays audio or streams audio/video using AirPlay
    App registers for location updates
```

**Step 3**
正确初始化 AppDelegate 的 UIWindow* window 成员
Initialize the UIWindow * window member of AppDelegate correctly

由于导航界面会使用到 UIWindow _mainWindow = [[UIApplication sharedApplication].delegate window]; 的 safeAreaInsets 适配刘海屏，因此必须手动初始化 window 成员，否则会导致导航界面有问题。
Due to the navigation interface using UIWindow _ mainWindow=[[UIApplication sharedApplication]. delete window]; SafeAreaInsets is compatible with the Notch screen, so it is necessary to manually initialize the window members, otherwise it will cause navigation interface issues.

![初始化UIWindow](media/window_init.png)

**Step 4**
初始化地图 APIKey
Initialize the map APIKeys

```
    /// 高德地图 (AMap)
    [FitCloudRoutePlan registerAMapApiKey:@""];
    /// 百度地图 (BaiduMap)
    [FitCloudRoutePlan registerBaiduMapApiKey:@""];
```

**Step 5**
设置主题色
Setup the brand colors

```
    //[FitCloudRoutePlan setBrandColor:[UIColor orangeColor]];
    //[FitCloudRoutePlan setBrandGradientColors:@[[UIColor orangeColor], [UIColor purpleColor]]];
```

**Step 6**
根据需要启动对应地图的路线规划界面
Show the route plan ui as your needs

```
    - (IBAction)onBaiduMap:(id)sender {
        [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_BAIDU];
    }

    - (IBAction)onAMap:(id)sender {
        [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_AMAP];
    }
```
