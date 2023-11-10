//
//  ViewController.m
//  FitCloudRoutePlanDemo
//
//  Created by pcjbird on 2023-11-01.
//

#import "ViewController.h"
#import <FitCloudRoutePlan/FitCloudRoutePlan.h>

@interface ViewController ()<FitCloudRoutePlanDelegate>
@property (weak, nonatomic) IBOutlet UIButton *btnBaiduMap;
@property (weak, nonatomic) IBOutlet UIButton *btnAMap;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.btnBaiduMap.titleLabel.numberOfLines = 2;
    self.btnBaiduMap.titleLabel.textAlignment = NSTextAlignmentCenter;
    
    self.btnAMap.titleLabel.numberOfLines = 2;
    self.btnAMap.titleLabel.textAlignment = NSTextAlignmentCenter;
}

- (IBAction)onBaiduMap:(id)sender {
    [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_BAIDU delegate:self];
}

- (IBAction)onAMap:(id)sender {
    [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_AMAP delegate:self];
}

/// The navigation start callback
/// - Parameters:
///   - map: the navigation map
///   - naviType: navi type
-(void) onNaviStartWithMap:(FITCLOUDROUTEPLANMAPPROVIDER)map type:(FITCLOUDROUTEPLANNAVITYPE) naviType
{
    NSLog(@"onNaviStartWithMap: %@,%@", @(map), @(naviType));
}

/// The navigation guide kind callback
/// - Parameters:
///   - guideKind: the guide kind
-(void) onNaviGuideKind:(FITCLOUDROUTEPLANGUIDEKIND)guideKind
{
    NSLog(@"onNaviGuideKind: %@", @(guideKind));
}

/// The navigation guide text callback
/// - Parameters:
///   - guideText: the guide text
-(void) onNaviGuideText:(NSString*)guideText
{
    NSLog(@"onNaviGuideText: %@", guideText);
}

/// The remain time for navigation update callback
/// - Parameters:
///   - remainTime: the remain time in seconds
-(void) onNaviRemainTimeUpdate:(NSInteger)remainTime
{
    NSLog(@"onNaviRemainTimeUpdate: %@", @(remainTime));
}

/// The remain distance for navigation update callback
/// - Parameters:
///   - remainDistance: the remain distance in meters
-(void) onNaviRemainDistanceUpdate:(NSInteger)remainDistance
{
    NSLog(@"onNaviRemainDistanceUpdate: %@", @(remainDistance));
}

/// The navigation arrive destination callback
-(void) onNaviArriveDest
{
    NSLog(@"onNaviArriveDest");
}

/// The naviagation exit callback
-(void) onNaviExit
{
    NSLog(@"onNaviExit");
}
@end
