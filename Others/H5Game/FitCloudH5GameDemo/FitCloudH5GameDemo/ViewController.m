//
//  ViewController.m
//  FitCloudH5GameDemo
//
//  Created by pcjbird on 2023-10-22.
//

#import "ViewController.h"
#import <FitCloudH5Game/FitCloudH5Game.h>
#import <FitCloudKit/FitCloudKit.h>

@interface ViewController ()
{
    
}

@property(nonatomic, strong) FitCloudH5GameItem *game;
@end

@implementation ViewController

-(void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [FitCloudH5Game registerApiKey:@"YourApiKey" name:@"YourName"];
    [FitCloudH5Game setGameLang:FITCLOUDH5GAMELANG_EN];
    [FitCloudH5Game setUserId:@"1000" userName:@"游戏用户" avatarUrl:@"https://img.zcool.cn/community/019fb65925bc32a801216a3ef77f7b.png"];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnOpenGSensor:) name:REQUEST_OPEN_GSENSOR_NOTIFICATION object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(OnCloseGSensor:) name:REQUEST_CLOSE_GSENSOR_NOTIFICATION object:nil];
}

-(void) OnOpenGSensor:(NSNotification*) notification
{
    FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
    FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
    if(firmware && firmware.withMotionSensingGame)
    {
        [FitCloudKit openGSensorWithBlock:^(BOOL succeed, NSError *error) {
            if([error isKindOfClass:[NSError class]])
            {
                //XLOG_ERROR(@"%@", APP_LOG_STRING(@"体感游戏开启GSensor失败，%@...", [error localizedDescription]));
                return;
            }
            //XLOG_INFO(@"%@", APP_LOG_STRING(@"体感游戏开启GSensor成功..."));
        }];
    }
}

-(void) OnCloseGSensor:(NSNotification*) notification
{
    FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
    FitCloudFirmwareVersionObject* firmware = allConfig ? allConfig.firmware : nil;
    if(firmware && firmware.withMotionSensingGame)
    {
        [FitCloudKit closeGSensorWithBlock:^(BOOL succeed, NSError *error) {
            if([error isKindOfClass:[NSError class]])
            {
                //XLOG_ERROR(@"%@", APP_LOG_STRING(@"体感游戏关闭GSensor失败，%@...", [error localizedDescription]));
                return;
            }
            //XLOG_INFO(@"%@", APP_LOG_STRING(@"体感游戏关闭GSensor成功..."));
        }];
    }
}

- (IBAction)OnFetchBanners:(id)sender {
    [FitCloudH5Game fetchBannersWithMacAddr:@"" completion:^(NSArray<FitCloudH5GameBannerItem *> *result, NSError *error) {
        NSLog(@"%@", result);
        if([result isKindOfClass:[NSArray class]])
        {
            self.game = [result firstObject].game;
        }
    }];
}

- (IBAction)OnFetchGroups:(id)sender {
    [FitCloudH5Game fetchGroupsWithMacAddr:@"" completion:^(NSArray<FitCloudH5GameGroup *> *result, NSError *error) {
        NSLog(@"%@", result);
    }];
}

- (IBAction)OnEnterGame:(id)sender {
    if([self.game isKindOfClass:[FitCloudH5GameItem class]])
    {
        [FitCloudH5Game enterGame:self.game fromVC:self completion:^(BOOL success, NSError *error) {
            
        }];
    }
}

@end
