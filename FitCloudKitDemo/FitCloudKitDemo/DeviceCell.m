//
//  DeviceCell.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/17.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DeviceCell.h"

@interface DeviceCell()

@property (nonatomic, assign) BOOL  showStatus;
@property (nonatomic, weak) FitCloudPeripheral *peripheral;
@property (weak, nonatomic) IBOutlet UILabel *name;
@property (weak, nonatomic) IBOutlet UILabel *macAddr;
@property (weak, nonatomic) IBOutlet UILabel *rssi;
@property (weak, nonatomic) IBOutlet UILabel *status;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activity;

@end

@implementation DeviceCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    [self registerNotificationObserver];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

-(void) configWithPeripheral:(FitCloudPeripheral*)peripheral showStatus:(BOOL)showStatus
{
    self.peripheral = peripheral;
    _showStatus = showStatus;
    self.name.text = peripheral.peripheral.name == nil || peripheral.peripheral.name.length == 0 ? @"UNKNOWN" : peripheral.peripheral.name;
    if([self.name.text hasPrefix:@"H"])
    {
        self.name.text = [self.name.text substringFromIndex:1];
    }
    self.rssi.text = peripheral.paired ? @"" : [NSString stringWithFormat:@"RSSI:%@", peripheral.RSSI];
    self.macAddr.text = peripheral.paired ? NSLocalizedString(@"SYSTEM PAIRED", nil) : peripheral.macAddr;
    if(!showStatus)
    {
        if(self.activity.animating)[self.activity stopAnimating];
        self.status.hidden = self.activity.hidden = YES;
    }
    else
    {
        CBPeripheralState state = peripheral.peripheral.state;
        if(state == CBPeripheralStateConnecting || state == CBPeripheralStateDisconnecting)
        {
            self.activity.hidden = NO;
            self.status.hidden = YES;
            [self.activity startAnimating];
        }
        else
        {
            if(self.activity.animating)[self.activity stopAnimating];
            self.activity.hidden = YES;
            self.status.hidden = NO;
            if(state == CBPeripheralStateConnected && !peripheral.paired)
            {
                self.status.textColor = RGB(0x00, 0xB2, 0x00);
                self.status.text = NSLocalizedString(@"CONNECTED", nil);
            }
            else if(state == CBPeripheralStateDisconnected || peripheral.paired)
            {
                self.status.textColor = [UIColor lightGrayColor];
                self.status.text = NSLocalizedString(@"DISCONNECTED", nil);
            }
        }
    }
}


-(void) registerNotificationObserver
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDisconnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCONNECT_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY object:nil];
}


-(void)OnPeripheralConnectedNotification:(NSNotification *) notification
{
    if(!self.peripheral) return;
    CBPeripheral *peripheral = notification.object;
    if(![peripheral isKindOfClass:[CBPeripheral class]]) return;
    if(![peripheral.identifier.UUIDString isEqualToString:self.peripheral.peripheral.identifier.UUIDString]) return;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self configWithPeripheral:self.peripheral showStatus:self.showStatus];
    });
}

-(void)OnPeripheralDisconnectedNotification:(NSNotification *) notification
{
    if(!self.peripheral) return;
    CBPeripheral *peripheral = notification.object;
    if(![peripheral isKindOfClass:[CBPeripheral class]]) return;
    if(![peripheral.identifier.UUIDString isEqualToString:self.peripheral.peripheral.identifier.UUIDString]) return;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self configWithPeripheral:self.peripheral showStatus:self.showStatus];
    });
}

-(void)OnPeripheralConnectFailureNotification:(NSNotification *) notification
{
    if(!self.peripheral) return;
    CBPeripheral *peripheral = notification.object;
    if(![peripheral isKindOfClass:[CBPeripheral class]]) return;
    if(![peripheral.identifier.UUIDString isEqualToString:self.peripheral.peripheral.identifier.UUIDString]) return;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self configWithPeripheral:self.peripheral showStatus:self.showStatus];
    });
}

-(void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
