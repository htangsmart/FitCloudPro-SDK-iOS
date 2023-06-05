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
 *@brief 手环请求查找手机 The bracelet asks to find the phone
 */
-(void) OnFindiPhoneEvent
{
    XLOG_INFO(@"%@", @"手环请求查找手机...");
    //Implement your logic here when the app receives a phone find request event, such as vibration, playing a music, or creating a local notification, etc
}

/**
 *@brief 手环控制手机拍照 The bracelet controls the phone's camera
 */
-(void)OnTakePhotoCtrl
{
    XLOG_INFO(@"%@", @"手环控制手机拍照...");
    //the App can implement photo take logic here
}

/**
 *@brief 实时运动健康测量数据(心电数据除外) Real-time exercise health measurement data callback (ecg data exception)
 *@param records 数据 measurement data
 */
-(void) OnRealTimeHealthMeasuringData:(NSArray<FitCloudRealTimeHealthMeasuringResultObject*>*)records
{
    XLOG_INFO(@"%@", @"实时运动健康测量数据...");
    //According to the actual business logic response bracelet real-time measurement data
}

/**
 *@brief 心电实时测量数据 Real-time ecg measurement results
 *@param ecgDataArray 数据 ecg data array
 *@param interval 采样间隔, 单位：毫秒(ms) Sampling interval in milliseconds (ms)
 */
-(void)OnRealTimeECGData:(NSArray<NSNumber *> *)ecgDataArray interval:(NSInteger)interval
{
    XLOG_INFO(@"%@", @"心电实时测量数据...");
    //According to the actual business logic response bracelet real-time ecg measurement data
}

/**
 *@brief 心电实时测量结束 Real-time ecg measurement stopped
 */
-(void) OnRealTimeECGStop
{
    XLOG_INFO(@"%@", @"心电实时测量结束...");
    //Notify the business logic ecg real-time measurement stopped
}

/**
 *@brief 收到手环的活跃通知(当前手环与手机连接还活跃着)  The bracelet notify the app it is alive.
 */
-(void) OnBraceletAlive
{
    XLOG_INFO(@"收到手环与手机连接活跃通知...");
    //the App can actively synchronize the movement health data of the bracelet to achieve the function of background synchronization data. Please add it according to the specific project needs. Note that frequent synchronization data in the background may affect the power consumption of the bracelet device.
}

/**
 *@brief 记录日志数据 Log message callback
 *@param message 日志信息 log message
 *@param level 日志等级 log level
 */
-(void) OnLogMessage:(NSString*)message level:(FITCLOUDKITLOGLEVEL)level
{
    //You can process the log message according to your actual business logic
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
