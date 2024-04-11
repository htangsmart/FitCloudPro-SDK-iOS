//
//  DemoListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/20.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DemoListController.h"
#import <FitCloudGPSAccelerate/FitCloudGPSAccelerate.h>
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
        [self upgradeGPSFile];
    }
    else if(indexPath.row == 1)
    {
        [FitCloudGPSAccelerate requestCurrentLocationAndNotifyTheWatchDevice];
    }
}

-(void) upgradeGPSFile
{
    
    [FitCloudGPSAccelerate startUpdateGPSFilesForce:NO started:^(BOOL success, NSError * _Nullable error) {
        XLOG_INFO(@"%@", APP_LOG_STRING(@"%@, %@", success ? @"成功": @"失败", error));
    } progress:^(CGFloat progress) {
        XLOG_INFO(@"%@", APP_LOG_STRING(@"进度： %.2f%%", progress*100));
    } waitDeviceRefresh:^{
        XLOG_INFO(@"%@", APP_LOG_STRING(@"等待设备重启"));
    } completion:^(GPSACCELERATERESULT result, NSError * _Nullable error) {
        XLOG_INFO(@"%@", APP_LOG_STRING(@"%@, %@", @(result), error));
    }];
}


- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
