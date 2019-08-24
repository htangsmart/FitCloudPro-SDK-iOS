//
//  MessageReminderController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/22.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "MessageReminderController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface MessageReminderController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation MessageReminderController

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
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        BOOL bMailReminderSupport = firmware && firmware.allowShowMailReminder;
        XLOG_INFO(@"Mail reminder support: %@.", @(bMailReminderSupport));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 1)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        BOOL bTelegramAndViberReminderSupport = firmware && firmware.allowShowTelegramAndViberReminder;
        XLOG_INFO(@"Telegram & Viber reminder support: %@.", @(bTelegramAndViberReminderSupport));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 2)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        XLOG_INFO(@"Call reminder enabled: %@.", @(bCallReminder));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 3)
    {
        __weak typeof(self) weakSelf = self;
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        if(!bCallReminder)
        {
            FITCLOUDMN mnNewSetting = mnSetting;
            mnNewSetting = mnNewSetting | FITCLOUDMN_CALL;
            allConfig.mnSetting = mnNewSetting;
            [FitCloudKit setMessageNotification:mnNewSetting block:^(BOOL succeed, NSError *error) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    OpResultToastTip(weakSelf.view, succeed);
                });
                if(!succeed) {
                    allConfig.mnSetting =  mnSetting;
                }
            }];
            return;
        }
        OpResultToastTip(self.view, false);
    }
    else if(indexPath.row == 4)
    {
        __weak typeof(self) weakSelf = self;
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        if(bCallReminder)
        {
            FITCLOUDMN mnNewSetting = mnSetting;
            mnNewSetting = mnNewSetting & (~FITCLOUDMN_CALL);
            allConfig.mnSetting = mnNewSetting;
            [FitCloudKit setMessageNotification:mnNewSetting block:^(BOOL succeed, NSError *error) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    OpResultToastTip(weakSelf.view, succeed);
                });
                if(!succeed) {
                    allConfig.mnSetting = mnSetting;
                }
            }];
            return;
        }
        OpResultToastTip(self.view, false);
    }
    else if(indexPath.row == 5)
    {
        __weak typeof(self) weakSelf = self;
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        BOOL bSMSReminder = mnSetting & FITCLOUDMN_SMS;
        if(!bCallReminder || !bSMSReminder)
        {
            FITCLOUDMN mnNewSetting = mnSetting;
            mnNewSetting = mnNewSetting | FITCLOUDMN_CALL | FITCLOUDMN_SMS;
            allConfig.mnSetting = mnNewSetting;
            [FitCloudKit setMessageNotification:mnNewSetting block:^(BOOL succeed, NSError *error) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    OpResultToastTip(weakSelf.view, succeed);
                });
                if(!succeed) {
                    allConfig.mnSetting = mnSetting;
                }
            }];
            return;
        }
        OpResultToastTip(self.view, false);
    }
    else if(indexPath.row == 6)
    {
        __weak typeof(self) weakSelf = self;
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        BOOL bSMSReminder = mnSetting & FITCLOUDMN_SMS;
        if(bCallReminder || bSMSReminder)
        {
            FITCLOUDMN mnNewSetting = mnSetting;
            mnNewSetting = mnNewSetting & (~FITCLOUDMN_CALL) & (~FITCLOUDMN_SMS);
            allConfig.mnSetting = mnNewSetting;
            [FitCloudKit setMessageNotification:mnNewSetting block:^(BOOL succeed, NSError *error) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    OpResultToastTip(weakSelf.view, succeed);
                });
                if(!succeed) {
                    allConfig.mnSetting = mnSetting;
                }
            }];
            return;
        }
        OpResultToastTip(self.view, false);
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
