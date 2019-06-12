//
//  AppDelegate+FitCloudKit.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate+FitCloudKit.h"

@implementation AppDelegate (FitCloudKit)

-(void) fitCloudKitConfig
{
    if(!self.fitCloudKit)
    {
        FitCloudOption *option = [FitCloudOption defaultOption];
        option.debugMode = NO;
        option.shouldAutoConnect = YES;
        self.fitCloudKit = [FitCloudKit initWithOption:option callback:self];
    }
}

/**
 *@brief 手环请求查找手机
 */
-(void) OnFindiPhoneEvent
{
    
}

@end
