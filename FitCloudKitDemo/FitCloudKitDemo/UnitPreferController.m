//
//  UnitPreferController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/3.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "UnitPreferController.h"
#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface UnitPreferController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation UnitPreferController

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
        
        [self braceletSyncWithLengthWeightPerfer:TRUE];
        
    }
    else if(indexPath.row == 1)
    {
        [self braceletSyncWithTemperaturePerfer:TRUE];
    }
}

-(void) braceletSyncWithLengthWeightPerfer:(BOOL)bImperial
{
    FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
    FITCLOUDPREFER newPrefer = allConfig ? allConfig.prefer : 0;
    
    newPrefer = bImperial ? (newPrefer | FITCLOUDPREFER_IMPERIALUNIT) : (newPrefer & (~FITCLOUDPREFER_IMPERIALUNIT));
    __weak typeof(self) weakSelf = self;
    [FitCloudKit setFitCloudPrefer:newPrefer block:^(BOOL succeed, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            OpResultToastTip(weakSelf.view, succeed);
        });
        if(!succeed)
        {
            return;
        }
        allConfig.prefer = newPrefer;
    }];
}

-(void) braceletSyncWithTemperaturePerfer:(BOOL)bFahrenheit
{
    FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
    FITCLOUDPREFER newPrefer = allConfig ? allConfig.prefer : 0;
    
    newPrefer = bFahrenheit ? (newPrefer | FITCLOUDPREFER_FAHRENHEIT) : (newPrefer & (~FITCLOUDPREFER_FAHRENHEIT));
    __weak typeof(self) weakSelf = self;
    [FitCloudKit setFitCloudPrefer:newPrefer block:^(BOOL succeed, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            OpResultToastTip(weakSelf.view, succeed);
        });
        if(!succeed)
        {
            return;
        }
        allConfig.prefer = newPrefer;
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
