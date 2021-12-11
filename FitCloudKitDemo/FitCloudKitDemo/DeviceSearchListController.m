//
//  DeviceSearchListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/17.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DeviceSearchListController.h"
#import "DeviceCell.h"
#import "DeviceBindingController.h"

#define USER_ID @"10000"

@interface DeviceSearchListController ()

@property (nonatomic, assign) BOOL isSearching;
@property (nonatomic, strong) NSMutableArray<FitCloudPeripheral*> * peripherals;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

- (IBAction)OnGoBack:(id)sender;
@end

@implementation DeviceSearchListController

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder
{
    if(self = [super initWithCoder:aDecoder])
    {
        _isSearching = NO;
        _peripherals = [NSMutableArray<FitCloudPeripheral*> array];
    }
    return self;
}


-(void)dealloc
{
    if(self.isSearching)
    {
        [FitCloudKit stopScan];
    }
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self registerNotificationObserver];
    
    if(self.isSearching)
    {
        self.isSearching = FALSE;
        [FitCloudKit stopScan];
    }
    else
    {
        self.isSearching = TRUE;
        [self.peripherals removeAllObjects];
        [self.tableView reloadData];
        [FitCloudKit scanPeripherals];
    }
}

-(void) registerNotificationObserver
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralDiscoveredUpdatedNotification:) name:FITCLOUDEVENT_PERIPHERAL_DISCOVERED_UPDATED_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralScanStopNotification:) name:FITCLOUDEVENT_PERIPHERAL_SCANSTOP_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectedNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECTED_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnPeripheralConnectFailureNotification:) name:FITCLOUDEVENT_PERIPHERAL_CONNECT_FAILURE_NOTIFY object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnFitCloudWriteCharacteristicReady:) name:FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY object:nil];
}

-(void)OnFitCloudWriteCharacteristicReady:(NSNotification*) notification
{
    dispatch_async(dispatch_get_main_queue(), ^{
        DeviceBindingController* bindingVC = [self.storyboard instantiateViewControllerWithIdentifier:@"DeviceBindingController"];
        bindingVC.modalPresentationStyle = UIModalPresentationFullScreen;
        [self.navigationController presentViewController:bindingVC animated:NO completion:nil];
        [self.navigationController popToRootViewControllerAnimated:NO];
    });
}

-(void) OnPeripheralDiscoveredNotification:(NSNotification*)notification
{
    dispatch_async(dispatch_get_main_queue(), ^{
        if([notification.object isKindOfClass:[FitCloudPeripheral class]])
        {
            [self.peripherals addObject:notification.object];
            [self.tableView reloadData];
        }
    });
}

-(void) OnPeripheralDiscoveredUpdatedNotification:(NSNotification*)notification
{
    dispatch_async(dispatch_get_main_queue(), ^{
        if([notification.object isKindOfClass:[FitCloudPeripheral class]])
        {
            FitCloudPeripheral *fcPeripheral = notification.object;
            __weak typeof(self) weakSelf = self;
            [self.peripherals enumerateObjectsUsingBlock:^(FitCloudPeripheral * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                if(fcPeripheral == obj)
                {
                    [weakSelf.tableView beginUpdates];
                    NSMutableArray<NSIndexPath*>*array = [NSMutableArray<NSIndexPath*> array];
                    NSIndexPath *indexPath = [NSIndexPath indexPathForRow:idx inSection:0];
                    [array addObject:indexPath];
                    [weakSelf.tableView reloadRowsAtIndexPaths:array withRowAnimation:UITableViewRowAnimationAutomatic];
                    [weakSelf.tableView endUpdates];
                    *stop = YES;
                }
            }];
        }
    });
}

-(void) OnPeripheralScanStopNotification:(NSNotification*)notification
{
    if([FitCloudKit bleState] == FITCLOUDBLECENTRALSTATE_POWEREDON)
    {
        
    }
}

-(void) OnPeripheralConnectedNotification:(NSNotification*)notification
{
    
}

-(void) OnPeripheralConnectFailureNotification:(NSNotification *)notification
{
    //self.shouldHideSkipBtn = NO;
    //[self setupNaviBar];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.peripherals count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    DeviceCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DeviceCell" forIndexPath:indexPath];
    
    if ([self.peripherals isKindOfClass:[NSArray class]] && [self.peripherals count] > indexPath.row)
    {
        FitCloudPeripheral* item = [self.peripherals objectAtIndex:indexPath.row];
        if([item isKindOfClass:[FitCloudPeripheral class]])
        {
            [cell configWithPeripheral:item showStatus:YES];
        }
    }
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 72.0f;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if(indexPath.section == 0)
    {
        if ([self.peripherals isKindOfClass:[NSArray class]] && [self.peripherals count] > indexPath.row)
        {
            
            FitCloudPeripheral* item = [self.peripherals objectAtIndex:indexPath.row];
            if([item isKindOfClass:[FitCloudPeripheral class]] && item.peripheral.state != CBPeripheralStateConnecting && (item.peripheral.state != CBPeripheralStateConnected || item.paired))
            {
                [FitCloudKit connect:item.peripheral];
               
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
                });
            }
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
