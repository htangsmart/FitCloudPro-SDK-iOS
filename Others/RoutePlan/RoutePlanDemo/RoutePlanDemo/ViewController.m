//
//  ViewController.m
//  FitCloudRoutePlanDemo
//
//  Created by pcjbird on 2023-11-01.
//

#import "ViewController.h"
#import <FitCloudRoutePlan/FitCloudRoutePlan.h>

@interface ViewController ()
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
    [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_BAIDU];
}

- (IBAction)onAMap:(id)sender {
    [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_AMAP];
}
@end
