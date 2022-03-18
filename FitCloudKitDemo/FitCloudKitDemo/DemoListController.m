//
//  DemoListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/20.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DemoListController.h"
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
        
    }
}

-(void) fetchSportsDataToday
{
    __weak typeof(self) weakSelf = self;
    [FitCloudKit requestHealthAndSportsDataTodayWithBlock:^(BOOL succeed, NSString* userId, FitCloudDailyHealthAndSportsDataObject *dataObject, NSError *error) {
        if([dataObject isKindOfClass:[FitCloudDailyHealthAndSportsDataObject class]])
        {
            NSString * log = APP_LOG_STRING(@"\n今日运动数据：\n步数：%@\n距离：%@\n卡路里：%@\n深睡：%@\n浅睡：%@\n平均心率：%@", @(dataObject.steps), @(dataObject.distance), @(dataObject.calory), @(dataObject.deepSleepMinutes),@(dataObject.shallowSleepMinutes),@(dataObject.averageHeartRate));
            XLOG_INFO(@"%@", log);
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(weakSelf.view);
            });
        }
        
    }];
}

-(void) manualSyncData
{
    __weak typeof(self) weakSelf = self;
    [FitCloudKit manualSyncDataWithOption:FITCLOUDDATASYNCOPTION_ALL progress:^(CGFloat progress, NSString *tip) {
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
    }];
}

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
