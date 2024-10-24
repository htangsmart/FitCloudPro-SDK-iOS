//
//  AppDelegate+FitCloudKit.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate+FitCloudKit.h"
#import "MuslimPrayerParams.h"
#import "FitCloudKitDemo-Swift.h"
#import <FitCloudKit/FitCloudKit.h>

@implementation AppDelegate (FitCloudKit)

-(void) fitCloudKitConfig
{
    if(!self.fitCloudKit)
    {
        FitCloudOption *option = [FitCloudOption defaultOption];
        option.debugMode = NO;
        option.shouldAutoReconnectWhenAppLaunch = YES;
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

- (NSArray<FitCloudIslamicEventModel *> *)getIslamicEvents {
    // 这里可以实现你的节日逻辑，返回包含信息的 IslamicHoliday 对象的数组
    // 下面的代码仅作示例
    FitCloudIslamicEventModel *holiday1 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 1;
        islamicDate.islamicDay = 1;
        holiday1.islamicDate = islamicDate;
        holiday1.durationOfEventInDays = 3;
        holiday1.correspondingGregorianDate = [NSDate date];
    }

    FitCloudIslamicEventModel *holiday2 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 2;
        islamicDate.islamicDay = 10;
        holiday2.islamicDate = islamicDate;
        holiday2.durationOfEventInDays = 5;
        holiday2.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:30*24*60*60];
    }
    
    FitCloudIslamicEventModel *holiday3 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 4;
        islamicDate.islamicDay = 12;
        holiday3.islamicDate = islamicDate;
        holiday3.durationOfEventInDays = 8;
        holiday3.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:3*30*24*60*60];
    }
    
    
    FitCloudIslamicEventModel *holiday4 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 5;
        islamicDate.islamicDay = 15;
        holiday4.islamicDate = islamicDate;
        holiday4.durationOfEventInDays = 2;
        holiday4.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:4*30*24*60*60];
    }
    
    FitCloudIslamicEventModel *holiday5 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 7;
        islamicDate.islamicDay = 18;
        holiday5.islamicDate = islamicDate;
        holiday5.durationOfEventInDays = 6;
        holiday5.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:5*30*24*60*60];
    }
    
    FitCloudIslamicEventModel *holiday6 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 9;
        islamicDate.islamicDay = 18;
        holiday6.islamicDate = islamicDate;
        holiday6.durationOfEventInDays = 9;
        holiday6.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:8*30*24*60*60];
    }

    return @[holiday1, holiday2, holiday3, holiday4, holiday5, holiday6];
}

/// 手表端请求当前回历节日信息
///
/// > The watch side request the current islamic events information
-(void) OnRequestCurrentIslamicEvents
{
    XLOG_INFO(@"手表请求回历节日信息...");
    [FitCloudKit setCurrentIslamicEvents:[self getIslamicEvents] completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];
}

/// 手表端请求克尔白数据
///
/// > The watch side request the kaaba data information
-(void) OnRequestKaabaData
{
    XLOG_INFO(@"手表请求克尔白数据...");
    /*BACoordinates *coordinates = [[BACoordinates alloc] initWithLatitude:35.78056 longitude:-78.6389];
    BAQibla* kaaba = [[BAQibla alloc] initWithCoordinates:coordinates];
    FitCloudKaabaModel* ka = [FitCloudKaabaModel new];
    ka.locationServiceState = APPLOCATIONSERVICESTATE_AVAILABLE;
    ka.azimuthAngle = kaaba.a*/
    [FitCloudKit setKaabaData:[MuslimPrayerParams instance].kaaba completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];
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
