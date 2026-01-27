//
//  DemoListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/20.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DemoListController.h"
#import "FitCloudSwiftDemo-Swift.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]

@interface DemoListController ()

- (IBAction)OnGoBack:(id)sender;
@end

@implementation DemoListController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        [self fetchSportsDataToday];
    }
    else if(indexPath.row == 1)
    {
        [self manualSyncData];
    }
    else if(indexPath.row == 2)
    {
        [self sendFuture100HourlyWeather];
    }
}


-(void) sendFuture100HourlyWeather
{
    NSMutableArray* hourlyWeatherArray = [NSMutableArray array];
    NSDate* now = [NSDate date];
    for(NSInteger index = 0; index < 100; index++)
    {
        FitCloudHourlyWeatherModel* model = [FitCloudHourlyWeatherModel new];
        model.timestamp = [now dateByAddingTimeInterval:index*3600];
        // 随机生成天气数据
        model.weatherType = arc4random_uniform(10); // 0~9 共 10 种天气类型
        model.temperature = -20 + arc4random_uniform(61); // -20~40 °C
        model.windScale = arc4random_uniform(13); // 0~12 级风力
        model.uvIndex = arc4random_uniform(12); // 0~11 UV 指数
        model.visibility = 100 + arc4random_uniform(30000-200); // 100~30000 米，避开 0
        model.airQualityIndex = arc4random_uniform(380); // 0~400 空气质量指数
        [hourlyWeatherArray addObject:model];
    }
    __weak typeof(self) weakSelf = self;
    [FitCloudKit sendFutureHourlyWeathers:hourlyWeatherArray completion:^(BOOL success, NSError * _Nullable error) {
        if ([error isKindOfClass:[NSError class]]) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [weakSelf.view makeToast:error.localizedDescription duration:3.0f position:CSToastPositionTop];
            });
            return;
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf.view makeToast:@"Send success." duration:3.0f position:CSToastPositionTop];
        });
    }];
}

-(void) fetchSportsDataToday
{
    __weak typeof(self) weakSelf = self;
    /*[FitCloudKit requestHealthAndSportsDataTodayWithBlock:^(BOOL succeed, NSString* userId, FitCloudDailyHealthAndSportsDataObject *dataObject, NSError *error) {
        if([dataObject isKindOfClass:[FitCloudDailyHealthAndSportsDataObject class]])
        {
            NSString * log = APP_LOG_STRING(@"\n今日运动数据：\n步数：%@\n距离：%@\n卡路里：%@\n深睡：%@\n浅睡：%@\n平均心率：%@", @(dataObject.steps), @(dataObject.distance), @(dataObject.calorie), @(dataObject.deepSleepInMinutes),@(dataObject.lightSleepInMinutes),@(dataObject.avgBPM));
            XLOG_INFO(@"%@", log);
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }
        
    }];*/
    [DataSyncSwiftDemo queryTodayActivitySummaryDataWithToast:^{
        dispatch_async(dispatch_get_main_queue(), ^{
            ConsoleResultToastTip(weakSelf.view);
        });
    }];
}

-(void) manualSyncData
{
    __weak typeof(self) weakSelf = self;
    /*[FitCloudKit manualSyncDataWithOption:FITCLOUDDATASYNCOPTION_ALL progress:^(CGFloat progress, NSString *tip) {
        XLOG_INFO(@"%@", APP_LOG_STRING(@"同步进度：%.0f%%, %@",progress*100.0f, tip));
    } block:^(BOOL succeed, NSString* userId, NSArray<FitCloudManualSyncRecordObject*> *records, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            ConsoleResultToastTip(weakSelf.view);
        });
        BOOL hasRecords = [records isKindOfClass:[NSArray class]] && [records count] > 0;
        if(succeed && hasRecords)
        {
            XLOG_INFO(@"%@", APP_LOG_STRING(@"数据同步成功，共同步到%@条记录。", @([records count])));
#if DEBUG
            XLOG_INFO(@"同步到的记录详情：\n %@", records);
#endif
            return;
        }
        if(!succeed)
        {
            XLOG_WARNING(@"%@", APP_LOG_STRING(@"数据同步失败，发生错误：%@。", error));
            return;
        }
        XLOG_WARNING(@"%@", APP_LOG_STRING(@"当前没有可同步的数据。"));
    } finished:^{
        XLOG_WARNING(@"%@", APP_LOG_STRING(@"数据同步任务已结束。"));
    }];*/
    [DataSyncSwiftDemo manualSyncDataWithToast:^{
        dispatch_async(dispatch_get_main_queue(), ^{
            ConsoleResultToastTip(weakSelf.view);
        });
    }];
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
