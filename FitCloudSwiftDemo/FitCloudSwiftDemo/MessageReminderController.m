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
- (void)queryWhetherNotificationAppEnabled:(FitCloudNotificationApp)app displayName:(NSString *)displayName;
- (void)updateNotificationAppsByAdding:(NSSet<FitCloudNotificationApp> *)appsToAdd
                               removing:(NSSet<FitCloudNotificationApp> *)appsToRemove;
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
        BOOL bMailReminderSupport = [FitCloudKit isDeviceSupportNotificationApp:FitCloudNotificationAppMail];
        XLOG_INFO(@"Mail reminder support: %@.", @(bMailReminderSupport));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 1)
    {
        BOOL bTelegramReminderSupport = [FitCloudKit isDeviceSupportNotificationApp:FitCloudNotificationAppTelegram];
        BOOL bViberReminderSupport = [FitCloudKit isDeviceSupportNotificationApp:FitCloudNotificationAppViber];
        XLOG_INFO(@"Telegram reminder support: %@, Viber reminder support: %@.",
                  @(bTelegramReminderSupport), @(bViberReminderSupport));
        ConsoleResultToastTip(self.view);
    }
    else if(indexPath.row == 2)
    {
        [self queryWhetherNotificationAppEnabled:FitCloudNotificationAppCall displayName:@"Call"];
    }
    else if(indexPath.row == 3)
    {
        [self updateNotificationAppsByAdding:[NSSet setWithObject:FitCloudNotificationAppCall]
                                    removing:[NSSet set]];
    }
    else if(indexPath.row == 4)
    {
        [self updateNotificationAppsByAdding:[NSSet set]
                                    removing:[NSSet setWithObject:FitCloudNotificationAppCall]];
    }
    else if(indexPath.row == 5)
    {
        [self updateNotificationAppsByAdding:[NSSet setWithObjects:FitCloudNotificationAppCall,
                                                                   FitCloudNotificationAppSMS, nil]
                                    removing:[NSSet set]];
    }
    else if(indexPath.row == 6)
    {
        [self updateNotificationAppsByAdding:[NSSet set]
                                    removing:[NSSet setWithObjects:FitCloudNotificationAppCall,
                                                                       FitCloudNotificationAppSMS, nil]];
    }
}

- (void)queryWhetherNotificationAppEnabled:(FitCloudNotificationApp)app displayName:(NSString *)displayName
{
    __weak typeof(self) weakSelf = self;
    [FitCloudKit getEnabledNotificationAppsWithCompletion:^(BOOL succeed,
                                                             NSSet<FitCloudNotificationApp> *apps,
                                                             NSError *error) {
        if (succeed) {
            XLOG_INFO(@"%@ reminder enabled: %@.", displayName, @([apps containsObject:app]));
        } else {
            XLOG_ERROR(@"Failed to get enabled notification apps: %@.", error);
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            if (succeed) {
                ConsoleResultToastTip(weakSelf.view);
            } else {
                OpResultToastTip(weakSelf.view, false);
            }
        });
    }];
}

- (void)updateNotificationAppsByAdding:(NSSet<FitCloudNotificationApp> *)appsToAdd
                               removing:(NSSet<FitCloudNotificationApp> *)appsToRemove
{
    __weak typeof(self) weakSelf = self;
    [FitCloudKit getEnabledNotificationAppsWithCompletion:^(BOOL succeed,
                                                             NSSet<FitCloudNotificationApp> *enabledApps,
                                                             NSError *error) {
        if (!succeed) {
            XLOG_ERROR(@"Failed to get enabled notification apps before updating: %@.", error);
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, false);
            });
            return;
        }

        NSMutableSet<FitCloudNotificationApp> *updatedApps = enabledApps
            ? [enabledApps mutableCopy]
            : [NSMutableSet set];
        [updatedApps minusSet:appsToRemove];

        for (FitCloudNotificationApp app in appsToAdd) {
            if ([FitCloudKit isDeviceSupportNotificationApp:app]) {
                [updatedApps addObject:app];
            } else {
                XLOG_WARNING(@"The device does not support notification app: %@.", app);
            }
        }

        [FitCloudKit setEnabledNotificationApps:updatedApps completion:^(BOOL setSucceed, NSError *setError) {
            if (!setSucceed) {
                XLOG_ERROR(@"Failed to set enabled notification apps: %@.", setError);
            } else {
                XLOG_INFO(@"Enabled notification apps updated: %@.", updatedApps);
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                OpResultToastTip(weakSelf.view, setSucceed);
            });
        }];
    }];
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
