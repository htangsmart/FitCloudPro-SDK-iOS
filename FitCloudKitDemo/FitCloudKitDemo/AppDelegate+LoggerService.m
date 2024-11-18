//
//  AppDelegate+LoggerService.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate+LoggerService.h"
#import <XLFacility/XLFacilityMacros.h>
#import <iOSLogBrowserSDK/iOSLogBrowserSDK.h>

@implementation AppDelegate (LoggerService)

-(void) loggerServiceConfig
{
    //⚠重要提醒：如果您在iOS设备上无法使用局域网日志查看服务，很可能是因为您的App没有访问本地WiFi的权限。
    //建议使用Reachability获取相关权限，详细使用方法请参考iOSLogBrowserSDK文档：
    //https://github.com/pcjbird/iOSLogBrowserSDK
    
    {
        [iOSLogBrowserSDK startWithOption:nil];
        XLOG_INFO(@"您正在使用 iOS 局域网日志查看服务！");
    }
}

@end
