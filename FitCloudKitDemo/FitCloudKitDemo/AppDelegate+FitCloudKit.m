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
    XLOG_INFO(@"%@", @"手环请求查找手机...");
}

/**
 *@brief 手环控制手机拍照
 */
-(void)OnTakePhotoCtrl
{
    XLOG_INFO(@"%@", @"手环控制手机拍照...");
}

/**
 *@brief 实时运动健康测量数据
 *@param records 数据
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    XLOG_INFO(@"%@", @"实时运动健康测量数据...");
}

/**
 *@brief 心电实时测量数据
 *@param ecgDataArray 数据
 *@param interval 采样间隔, 单位：毫秒(ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    XLOG_INFO(@"%@", @"心电实时测量数据...");
}

/**
 *@brief 心电实时测量结束
 */
-(void) OnRealTimeECGStop
{
    XLOG_INFO(@"%@", @"心电实时测量结束...");
}


/**
 *@brief 记录日志数据
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnLogMessage:(NSString*)message level:(FITCLOUDKITLOGLEVEL)level
{
    message = [[message stringByReplacingOccurrencesOfString:@"<" withString:@"["] stringByReplacingOccurrencesOfString:@">" withString:@"]"];
    if(level == FITCLOUDKITLOGLEVEL_INFO)
    {
        XLOG_INFO(@"%@", message);
    }
    else if(level == FITCLOUDKITLOGLEVEL_WARNING)
    {
        XLOG_WARNING(@"%@", message);
    }
    else if(level == FITCLOUDKITLOGLEVEL_ERROR)
    {
        XLOG_ERROR(@"%@", message);
    }
}

@end
