# GPS 文件升级对接文档

GPS accelerate Development Guide

**Step 1**

使用 Cocoapods 安装。由于依赖关系复杂，且需要大量的链接库，因此不建议手动安装。

Install using Cocoapods. Due to complex dependency relationships and the need for a large number of link libraries, manual installation is not recommended.

```objc

target 'FitCloudGPSAccelerateDemo' do
  platform :ios, '10.0'
  workspace 'FitCloudGPSAccelerateDemo.xcworkspace'
  project 'FitCloudGPSAccelerateDemo.xcodeproj'
  # Uncomment this line if you're using Swift or would like to use dynamic frameworks
  use_frameworks!
  # Pods for FitCloudGPSAccelerateDemo

  pod 'FitCloudKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
  pod 'FitCloudDFUKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
  pod 'FitCloudWFKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
  pod 'FitCloudNWFKit', git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git'
  pod 'FitCloudGPSAccelerate',:path => '../'

  pod 'QuickTraceiOSLogger'
  pod 'YYCategories'
  pod 'Toast'
end

```

**Step 2**

需要为 Info.plist 额外配置以下字段

The following additional fields need to be configured for Info.plist

```
App Transport Security Settings
    Allow Arbitrary Loads                      YES
```

```
Privacy - Bluetooth Peripheral Usage Description
```

```
Privacy - Bluetooth Always Usage Description
```

**Step 3**

初始化
Initialize

```
    [FitCloudGPSAccelerate setLogProvider:self];
    [FitCloudGPSAccelerate setGPSLocationInfoRequestService:self];
```

**Step 4**

实现 FitCloudCallback 对应的方法 `- (void)OnRequestGPSData`

Implement the method `- (void)OnRequestGPSData` for FitCloudCallback

```
- (void)OnRequestGPSData
{
    [FitCloudGPSAccelerate requestCurrentLocationAndNotifyTheWatchDevice];
}
```

**Step 5**

实现获取 GPS 信息的服务

Implement the GPS location request service

```
#pragma mark - GPSLocationInfoRequestService

/// request the GPS Location
/// - Parameters:
///   - completion: the completion callback
-(void) requestGPSLocationWithCompletionHandler:(void (^ __nullable)(BOOL success, double lon, double lat, NSError* _Nullable error))completion
{
    #error "TODO 请自行实现这段代码"
    /// 请自行实现这段代码
    /*if(completion)
    {
        completion(YES, 121.449324, 31.284062, nil);
    }*/
}

```

**Step 6**

如果需要，实现下载 EPO 文件的下载服务

If needed, implement the EPO file download service

```
/// download the epo files
/// - Parameters:
///   - completion: the completion callback
-(void) downloadEPOFilesWithCompletionHandler:(void (^ __nullable)(BOOL success, NSArray<NSString*>* _Nullable epoFilePaths, NSError* _Nullable error))completion
{
    #error "TODO 请自行实现这段代码"
}
```

如果您自行实现 EPO 文件下载服务，别忘了设置到 SDK
If you implement the EPO file download service yourself, please don't forget to set it to the SDK

```
[FitCloudGPSAccelerate setEPOFilesDownloadService:self];
```

**Step 7**

在合适的时机调用启动 GPS 文件升级

Invoke and start GPS file upgrade at the appropriate time

```
[FitCloudGPSAccelerate startUpdateGPSFilesForce:NO started:^(BOOL success, NSError * _Nullable error) {
    XLOG_INFO(@"%@", APP_LOG_STRING(@"%@, %@", success ? @"成功": @"失败", error));
} progress:^(CGFloat progress) {
    XLOG_INFO(@"%@", APP_LOG_STRING(@"进度： %.2f%%", progress*100));
} waitDeviceRefresh:^{
    XLOG_INFO(@"%@", APP_LOG_STRING(@"等待设备重启"));
} completion:^(GPSACCELERATERESULT result, NSError * _Nullable error) {
    XLOG_INFO(@"%@", APP_LOG_STRING(@"%@, %@", @(result), error));
}];
```
