//
//  ViewController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UIImageView *imageSmartWatch;
@property (weak, nonatomic) IBOutlet UILabel *deviceName;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *indicator;
@property (weak, nonatomic) IBOutlet UILabel *connectStatus;
@property (weak, nonatomic) IBOutlet UIButton *btnConnectDevice;


@property (weak, nonatomic) IBOutlet UIButton *btnSearch;

- (IBAction)OnConnectDevice:(id)sender;
@end

@implementation ViewController

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    {
        [self.btnConnectDevice setTitle:NSLocalizedString(@"Connect Device", nil) forState:UIControlStateNormal];
        self.btnConnectDevice.layer.borderColor = UIColor.blackColor.CGColor;
        [self.btnConnectDevice setContentEdgeInsets:UIEdgeInsetsMake(0, 30, 0, 30)];
    }
    
    {
        [self.btnSearch setTitle:NSLocalizedString(@"Search Device", nil) forState:UIControlStateNormal];
        self.btnSearch.layer.borderColor = UIColor.blackColor.CGColor;
        [self.btnSearch setContentEdgeInsets:UIEdgeInsetsMake(0, 30, 0, 30)];
    }
    
    {
        [self updateControlVisible];
    }
    
     if([FitCloudKit lastConnectPeripheral])
     {
         self.indicator.hidden = self.connectStatus.hidden = FALSE;
         [self.indicator startAnimating];
         self.btnConnectDevice.hidden = TRUE;
     }
}

-(void) registerNotificationObsever
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripherialConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY object:nil];
}

-(void)OnPeripherialConnectFailureNotification:(NSNotification*)notification
{
    [self.indicator stopAnimating];
    self.connectStatus.hidden = TRUE;
    self.btnConnectDevice.hidden = FALSE;
}

-(void) updateControlVisible
{
    if(![FitCloudKit lastConnectPeripheral])
    {
        self.imageSmartWatch.hidden = self.deviceName.hidden = self.indicator.hidden = self.connectStatus.hidden = self.btnConnectDevice.hidden = TRUE;
        self.btnSearch.hidden = FALSE;
    }
    else
    {
        self.imageSmartWatch.hidden = self.deviceName.hidden = FALSE;
        self.btnSearch.hidden = TRUE;
    }
}

-(BOOL)shouldPerformSegueWithIdentifier:(NSString *)identifier sender:(id)sender
{
#if TARGET_IPHONE_SIMULATOR//模拟器
    return FALSE;
#else
    if([FitCloudKit bleState] != FITCLOUDBLECENTRALSTATE_POWEREDON)
    {
        if([FitCloudKit bleState] == FITCLOUDBLECENTRALSTATE_POWEREDOFF)
        {
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{} completionHandler:nil];
        }
        else
        {
            [FitCloudKit requestShowBluetoothPowerAlert];
        }
        return FALSE;
    }
    return TRUE;
#endif
}

- (IBAction)OnConnectDevice:(id)sender {
    self.indicator.hidden = self.connectStatus.hidden = FALSE;
    [self.indicator startAnimating];
    self.btnConnectDevice.hidden = TRUE;
    [FitCloudKit tryConnect:[[FitCloudKit historyPeripherals] lastObject]];
}
@end
