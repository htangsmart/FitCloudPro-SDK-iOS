//
//  WomenHealthController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 7/6/23.
//  Copyright © 2023 HetangSmart. All rights reserved.
//

#import "WomenHealthController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]
@interface WomenHealthController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WomenHealthController

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
        WOMENHEALTHMODE mode = WOMENHEALTHMODE_MENSES;
        FitCloudWomenHealthSetting *whSetting = [FitCloudWomenHealthSetting settingwithMode:mode advanceDaysToRemind:1 offsetMinutesInDayOfRemind:10*60 mensesDuration:7 menstrualCycle:28 recentMenstruationBegin:@"2023-07-01" daysOfFinishSinceMensesBegin:0 pregancyRemindType:PREGNANCYREMINDTYPE_DAYSBEFOREEDC];
        __weak typeof(self) weakSelf = self;
        [FitCloudKit setWomenHealthConfig:whSetting block:^(BOOL succeed, NSError *error) {
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
