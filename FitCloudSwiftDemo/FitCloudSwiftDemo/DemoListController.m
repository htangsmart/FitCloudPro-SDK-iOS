//
//  DemoListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/20.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DemoListController.h"
#import "CompanionWorkoutDisplayConfigDemoController.h"
#import "PCMAudioStreamingController.h"
#import "FitCloudSwiftDemo-Swift.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface DemoListController ()

- (IBAction)OnGoBack:(id)sender;
- (void)confirmRestoreFactorySettings;
- (void)confirmTurnOffWatch;
- (void)confirmRebootWatch;
- (void)confirmWatchOperationWithTitle:(NSString *)title
                               message:(NSString *)message
                          confirmTitle:(NSString *)confirmTitle
                             operation:(void (^)(FitCloudCompletionHandler completion))operation;
@end

@implementation DemoListController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)openPCMAudioStreamingDemo
{
    PCMAudioStreamingController *controller = [[PCMAudioStreamingController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}

- (void)openDeviceFilesDemo
{
    DeviceFilesViewController *controller = [[DeviceFilesViewController alloc] init];
    [self.navigationController pushViewController:controller animated:YES];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *reuseIdentifier = [tableView cellForRowAtIndexPath:indexPath].reuseIdentifier;
    if ([reuseIdentifier isEqualToString:@"DeviceFilesDemoCell"])
    {
        [self openDeviceFilesDemo];
    }
    else if ([reuseIdentifier isEqualToString:@"OfflineMapsDemoCell"])
    {
        [self.navigationController pushViewController:[[OfflineMapsDemoController alloc] init] animated:YES];
    }
    else if ([reuseIdentifier isEqualToString:@"PCMAudioStreamingDemoCell"])
    {
        [self openPCMAudioStreamingDemo];
    }
    else if ([reuseIdentifier isEqualToString:@"CompanionWorkoutDisplayConfigDemoCell"])
    {
        CompanionWorkoutDisplayConfigDemoController *controller = [[CompanionWorkoutDisplayConfigDemoController alloc] init];
        [self.navigationController pushViewController:controller animated:YES];
    }
    else if ([reuseIdentifier isEqualToString:@"RestoreFactorySettingsDemoCell"])
    {
        [self confirmRestoreFactorySettings];
    }
    else if ([reuseIdentifier isEqualToString:@"TurnOffWatchDemoCell"])
    {
        [self confirmTurnOffWatch];
    }
    else if ([reuseIdentifier isEqualToString:@"RebootWatchDemoCell"])
    {
        [self confirmRebootWatch];
    }
    else if(indexPath.row == 0)
    {
        [self fetchSportsDataToday];
    }
    else if(indexPath.row == 1)
    {
        [self manualSyncData];
    }
    // row 2 ("Send Hourly Weather (100 Hr)") now segues to
    // FutureHourlyWeatherController in the storyboard; see that controller for
    // randomize + preview + send.
}

- (void)confirmRestoreFactorySettings
{
    [self confirmWatchOperationWithTitle:NSLocalizedString(@"Restore Factory Settings", nil)
                                 message:NSLocalizedString(@"All data and settings on the watch will be erased. Continue?", nil)
                            confirmTitle:NSLocalizedString(@"Restore", nil)
                                operation:^(FitCloudCompletionHandler completion) {
        [FitCloudKit restoreAsFactorySettingsWithBlock:completion];
    }];
}

- (void)confirmTurnOffWatch
{
    [self confirmWatchOperationWithTitle:NSLocalizedString(@"Turn Off Watch", nil)
                                 message:NSLocalizedString(@"The watch will turn off and disconnect from the phone. Continue?", nil)
                            confirmTitle:NSLocalizedString(@"Turn Off", nil)
                                operation:^(FitCloudCompletionHandler completion) {
        [FitCloudKit turnOffWithBlock:completion];
    }];
}

- (void)confirmRebootWatch
{
    [self confirmWatchOperationWithTitle:NSLocalizedString(@"Reboot Watch", nil)
                                 message:NSLocalizedString(@"The watch will restart and temporarily disconnect from the phone. Continue?", nil)
                            confirmTitle:NSLocalizedString(@"Reboot", nil)
                                operation:^(FitCloudCompletionHandler completion) {
        [FitCloudKit rebootWithBlock:completion];
    }];
}

- (void)confirmWatchOperationWithTitle:(NSString *)title
                               message:(NSString *)message
                          confirmTitle:(NSString *)confirmTitle
                             operation:(void (^)(FitCloudCompletionHandler completion))operation
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:title
                                                                   message:message
                                                            preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"Cancel", nil)
                                              style:UIAlertActionStyleCancel
                                            handler:nil]];

    __weak typeof(self) weakSelf = self;
    [alert addAction:[UIAlertAction actionWithTitle:confirmTitle
                                              style:UIAlertActionStyleDestructive
                                            handler:^(__unused UIAlertAction *action) {
        operation(^(BOOL succeed, NSError *error) {
            XLOG_INFO(@"%@", APP_LOG_STRING(@"%@：%@%@", title,
                                             succeed ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil),
                                             error ? [NSString stringWithFormat:@" %@", error] : @""));
            dispatch_async(dispatch_get_main_queue(), ^{
                __strong typeof(weakSelf) strongSelf = weakSelf;
                if (strongSelf) {
                    OpResultToastTip(strongSelf.view, succeed);
                }
            });
        });
    }]];
    [self presentViewController:alert animated:YES completion:nil];
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
