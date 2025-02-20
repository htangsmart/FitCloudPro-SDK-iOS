//
//  ScreenDispayController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/31.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "ScreenDispayController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface ScreenDispayController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation ScreenDispayController

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
        FITCLOUDSCREENDISPLAY screenDisplaySupported = firmware ? firmware.screenDisplaySupported : 0;
        XLOG_INFO(@"Supported Screen Display Items: %@.", @(screenDisplaySupported));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 1)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        FITCLOUDSCREENDISPLAY screenDisplaySupported = firmware ? firmware.screenDisplaySupported : 0;
        BOOL bSupportDisplayStepsItem = screenDisplaySupported & FITCLOUDSCREENDISPLAY_STEPS;
        XLOG_INFO(@"Support Display Steps: %@.", @(bSupportDisplayStepsItem));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 2)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        FITCLOUDSCREENDISPLAY screenDisplaySupported = firmware ? firmware.screenDisplaySupported : 0;
        BOOL bSupportDisplayStepsItem = screenDisplaySupported & FITCLOUDSCREENDISPLAY_STEPS;
        if(!bSupportDisplayStepsItem)
        {
            XLOG_INFO(@"Not Support.");
            ConsoleResultToastTip(self.view);
            return;
        }
        FITCLOUDSCREENDISPLAY screenDisplaySettings = allConfig.sdSetting;
        BOOL bStepsItemShown = screenDisplaySettings & FITCLOUDSCREENDISPLAY_STEPS;
        XLOG_INFO(@"Steps Item Current Shown: %@.", @(bStepsItemShown));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 3)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        FITCLOUDSCREENDISPLAY screenDisplaySupported = firmware ? firmware.screenDisplaySupported : 0;
        BOOL bSupportDisplayStepsItem = screenDisplaySupported & FITCLOUDSCREENDISPLAY_STEPS;
        if(!bSupportDisplayStepsItem)
        {
            XLOG_INFO(@"Not Support.");
            ConsoleResultToastTip(self.view);
            return;
        }
        FITCLOUDSCREENDISPLAY sdSetting = allConfig.sdSetting;
        BOOL bStepsItemShown = sdSetting & FITCLOUDSCREENDISPLAY_STEPS;
        if(bStepsItemShown)
        {
            OpResultToastTip(self.view, false);
            return;
        }
        __weak typeof(self) weakSelf = self;
        FITCLOUDSCREENDISPLAY sdNewSetting = sdSetting;
        sdNewSetting =  sdNewSetting & (~FITCLOUDSCREENDISPLAY_STEPS);
        allConfig.sdSetting = sdNewSetting;
        [FitCloudKit setScreenDisplay:sdNewSetting block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, succeed);
            });
            if(!succeed) {
                allConfig.sdSetting = sdSetting;
            }
        }];
    }
    else if(indexPath.row == 4)
    {
        FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
        FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
        FITCLOUDSCREENDISPLAY screenDisplaySupported = firmware ? firmware.screenDisplaySupported : 0;
        BOOL bSupportDisplayStepsItem = screenDisplaySupported & FITCLOUDSCREENDISPLAY_STEPS;
        if(!bSupportDisplayStepsItem)
        {
            XLOG_INFO(@"Not Support.");
            ConsoleResultToastTip(self.view);
            return;
        }
        FITCLOUDSCREENDISPLAY sdSetting = allConfig.sdSetting;
        BOOL bStepsItemShown = sdSetting & FITCLOUDSCREENDISPLAY_STEPS;
        if(!bStepsItemShown)
        {
            OpResultToastTip(self.view, false);
            return;
        }
        __weak typeof(self) weakSelf = self;
        FITCLOUDSCREENDISPLAY sdNewSetting = sdSetting;
        sdNewSetting =  sdNewSetting | FITCLOUDSCREENDISPLAY_STEPS;
        allConfig.sdSetting = sdNewSetting;
        [FitCloudKit setScreenDisplay:sdNewSetting block:^(BOOL succeed, NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, succeed);
            });
            if(!succeed) {
                allConfig.sdSetting = sdSetting;
            }
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
