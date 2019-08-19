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
@property (weak, nonatomic) IBOutlet UIButton *btnRemoveDevice;
@property (weak, nonatomic) IBOutlet UIButton *btnMoreDemo;


@property (weak, nonatomic) IBOutlet UIButton *btnSearch;

- (IBAction)OnConnectDevice:(id)sender;
- (IBAction)OnRemoveDevice:(id)sender;
- (IBAction)OnMoreDemo:(id)sender;
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
    
    [self registerNotificationObsever];
    
     if([FitCloudKit lastConnectPeripheral])
     {
         self.deviceName.text = [FitCloudKit lastConnectPeripheral].name;
         if([FitCloudKit connecting])
         {
             self.indicator.hidden = self.connectStatus.hidden = FALSE;
             if(!self.indicator.isAnimating)[self.indicator startAnimating];
             self.btnConnectDevice.hidden = TRUE;
             self.btnRemoveDevice.hidden = TRUE;
             self.btnMoreDemo.hidden = TRUE;
             self.connectStatus.text = NSLocalizedString(@"Connecting...", nil);
             self.connectStatus.textColor = RGB(0x9A, 0x9A, 0x9A);
         }
         
     }
}

-(void) registerNotificationObsever
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectingNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECTING_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDisconnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripherialConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPrepareSyncWorkEndNotification:) name:FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY object:nil];
}

-(void)OnPeripheralConnectingNotification:(NSNotification *) notification
{
    self.indicator.hidden = self.connectStatus.hidden = FALSE;
    if(!self.indicator.isAnimating)[self.indicator startAnimating];
    self.btnConnectDevice.hidden = TRUE;
    self.btnRemoveDevice.hidden = TRUE;
    self.btnMoreDemo.hidden = TRUE;
    self.connectStatus.text = NSLocalizedString(@"Connecting...", nil);
    self.connectStatus.textColor = RGB(0x9A, 0x9A, 0x9A);
}

-(void)OnPeripheralConnectedNotification:(NSNotification *) notification
{
    if(self.indicator.isAnimating)[self.indicator stopAnimating];
    self.connectStatus.text = NSLocalizedString(@"Connected", nil);
    self.connectStatus.textColor = RGB(0x00, 0xB2, 0x00);
    self.btnConnectDevice.hidden = TRUE;
}

-(void)OnPeripheralDisconnectedNotification:(NSNotification *) notification
{
    if(self.indicator.isAnimating)[self.indicator stopAnimating];
    self.connectStatus.text = NSLocalizedString(@"Disconnected", nil);
    self.connectStatus.textColor = RGB(0x9A, 0x9A, 0x9A);
    self.btnConnectDevice.hidden = FALSE;
}

-(void)OnPeripherialConnectFailureNotification:(NSNotification*)notification
{
    if(self.indicator.isAnimating)[self.indicator stopAnimating];
    self.btnConnectDevice.hidden = FALSE;
    self.connectStatus.text = NSLocalizedString(@"Disconnected", nil);
    self.connectStatus.textColor = RGB(0x9A, 0x9A, 0x9A);
}

-(void)OnPrepareSyncWorkEndNotification:(NSNotification *) notification
{
    self.btnRemoveDevice.hidden = FALSE;
    self.btnMoreDemo.hidden = FALSE;
}

-(void) updateControlVisible
{
    if(![FitCloudKit lastConnectPeripheral])
    {
        self.imageSmartWatch.hidden = self.deviceName.hidden = self.indicator.hidden = self.connectStatus.hidden = self.btnConnectDevice.hidden = self.btnRemoveDevice.hidden = self.btnMoreDemo.hidden = TRUE;
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

- (IBAction)OnRemoveDevice:(id)sender {
}

- (IBAction)OnMoreDemo:(id)sender {
}
@end
