//
//  ViewController.m
//  FitCloudRoutePlanDemo
//
//  Created by pcjbird on 2023-11-01.
//

#import "ViewController.h"
#import <FitCloudRoutePlan/FitCloudRoutePlan.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)onBaiduMap:(id)sender {
    [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_BAIDU];
}

- (IBAction)onAMap:(id)sender {
    [FitCloudRoutePlan startRoutePlanFromVC:self withProvider:FITCLOUDROUTEPLANMAPPROVIDER_AMAP];
}
@end
