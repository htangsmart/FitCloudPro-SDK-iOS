//
//  UserProfileController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "UserProfileController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface UserProfileController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation UserProfileController

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
        FitCloudUserProfileObject* profile = [FitCloudUserProfileObject new];
        profile.gender = FITCLOUDGENDER_FEMALE;
        profile.age = 29;
        profile.height = 160;
        profile.weight = 55;
         __weak typeof(self) weakSelf = self;
        [FitCloudKit setUserProfile:profile block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, succeed);
            });
        }];
    }
    else if(indexPath.row == 1)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudBPRObject *bprSetting = allConfig.bprSetting;
        bprSetting.on = TRUE;
        bprSetting.diastolic = 80;
        bprSetting.systolic = 120;
        __weak typeof(self) weakSelf = self;
        [FitCloudKit setBloodPressureRefer:bprSetting block:^(BOOL succeed, NSError *error) {
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
