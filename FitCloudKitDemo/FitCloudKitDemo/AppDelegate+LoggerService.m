//
//  AppDelegate+LoggerService.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate+LoggerService.h"
#import <iOSLogBrowserSDK/iOSLogBrowserSDK.h>

@implementation AppDelegate (LoggerService)

-(void) loggerServiceConfig
{
    {
        [iOSLogBrowserSDK startWithOption:nil];
        XLOG_INFO(@"您正在使用 iOS 局域网日志查看服务！");
    }
}

@end
