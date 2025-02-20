//
//  WristWakeUpController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/26.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "WristWakeUpController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface WristWakeUpController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation WristWakeUpController

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
        [FitCloudKit getWristWakeUpSettingWithBlock:^(BOOL succeed, FitCloudWWUObject *wwuSetting, NSError *error) {
            XLOG_INFO(@"Wrist Wake Up Settings:\nisOn:%@\nbegin:%@\nend:%@", @(wwuSetting.on), @(wwuSetting.begin), @(wwuSetting.end));
            dispatch_async(dispatch_get_main_queue(), ^{
                ConsoleResultToastTip(self.view);
            });
        }];
    }
    else if(indexPath.row == 1)
    {
        FitCloudWWUObject *settings = [FitCloudWWUObject new];
        settings.on = true;
        settings.begin = 60*9;
        settings.end = 60*20;
        [FitCloudKit setWristWakeUp:settings block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(self.view, succeed);
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
