//
//  MessageReminderController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/22.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "MessageReminderController.h"

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
    }
    else if(indexPath.row == 1)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        BOOL bTelegramAndViberReminderSupport = firmware && firmware.allowShowTelegramAndViberReminder;
        XLOG_INFO(@"Telegram & Viber reminder support: %@.", @(bTelegramAndViberReminderSupport));
    }
    else if(indexPath.row == 2)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        XLOG_INFO(@"Call reminder enabled: %@.", @(bCallReminder));
    }
    else if(indexPath.row == 3)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        if(!bCallReminder)
        {
            FITCLOUDMN mnNewSetting = mnSetting;
            mnNewSetting = mnNewSetting | FITCLOUDMN_CALL;
            allConfig.mnSetting = mnNewSetting;
            [FitCloudKit setMessageNotification:mnNewSetting block:^(BOOL succeed, NSError *error) {
                if(!succeed) {
                    allConfig.mnSetting =  mnSetting;
                }
            }];
        }
    }
    else if(indexPath.row == 4)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FITCLOUDMN mnSetting = allConfig ? allConfig.mnSetting : 0;
        BOOL bCallReminder = mnSetting & FITCLOUDMN_CALL;
        if(bCallReminder)
        {
            FITCLOUDMN mnNewSetting = mnSetting;
            mnNewSetting = mnNewSetting & (~FITCLOUDMN_CALL);
            allConfig.mnSetting = mnNewSetting;
            [FitCloudKit setMessageNotification:mnNewSetting block:^(BOOL succeed, NSError *error) {
                if(!succeed) {
                    allConfig.mnSetting = mnSetting;
                }
            }];
        }
    }
    else if(indexPath.row == 5)
    {
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
                if(!succeed) {
                    allConfig.mnSetting = mnSetting;
                }
            }];
        }
    }
    else if(indexPath.row == 6)
    {
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
                if(!succeed) {
                    allConfig.mnSetting = mnSetting;
                }
            }];
        }
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
