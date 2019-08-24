//
//  AlarmController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/24.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AlarmController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface AlarmController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation AlarmController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        NSArray<FitCloudAlarmObject*>* alarmlist = [FitCloudKit alarmlist];
        XLOG_INFO(@"Alarm list: %@.", alarmlist);
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 1)
    {
        NSMutableArray<FitCloudAlarmObject*>* alarmlist = [NSMutableArray<FitCloudAlarmObject*> array];
        FitCloudAlarmObject *alarm = [FitCloudAlarmObject new];
        NSDateComponents* scrollTo = [NSDateComponents new];
        NSCalendar* gregorianCalendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
        NSDate* now = [NSDate date];
        scrollTo.hour = now.hour;
        scrollTo.minute = now.minute;
        alarm.fire = scrollTo;
        alarm.fire.year = [[gregorianCalendar components:NSCalendarUnitYear fromDate:now] year];
        alarm.fire.month = now.month;
        alarm.fire.day = now.day;
        alarm.fire.second = 0;
        alarm.cycle = FITCLOUDALARMCYCLE_MON;
        alarm.on = YES;
        alarm.label = @"test alarm label";
        [alarmlist addObject:alarm];
        [alarmlist addObjectsFromArray:[FitCloudKit alarmlist]];
        __weak typeof(self) weakSelf = self;
        [FitCloudKit setAlarms:alarmlist block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, succeed);
            });
        }];
    }
    else if(indexPath.row == 2)
    {
        NSArray<FitCloudAlarmObject*>* alarmlist = [FitCloudKit alarmlist];
        if([alarmlist count] == 0)
        {
            OpResultToastTip(self.view, false);
            return;
        }
        NSMutableArray<FitCloudAlarmObject*>* newAlarmlist = [NSMutableArray<FitCloudAlarmObject*> array];
        [newAlarmlist addObjectsFromArray:alarmlist];
        FitCloudAlarmObject* toEditAlarm = [alarmlist firstObject];
        [newAlarmlist removeObject:toEditAlarm];
        FitCloudAlarmObject *alarm = [FitCloudAlarmObject new];
        NSDateComponents* scrollTo = [NSDateComponents new];
        NSCalendar* gregorianCalendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
        NSDate* now = [NSDate date];
        scrollTo.hour = now.hour;
        scrollTo.minute = now.minute;
        alarm.fire = scrollTo;
        alarm.fire.year = [[gregorianCalendar components:NSCalendarUnitYear fromDate:now] year];
        alarm.fire.month = now.month;
        alarm.fire.day = now.day;
        alarm.fire.second = 0;
        alarm.cycle = FITCLOUDALARMCYCLE_MON;
        alarm.on = FALSE;
        alarm.label = @"test alarm label1";
        [newAlarmlist insertObject:alarm atIndex:0];
        __weak typeof(self) weakSelf = self;
        [FitCloudKit setAlarms:alarmlist block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, succeed);
            });
        }];
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
