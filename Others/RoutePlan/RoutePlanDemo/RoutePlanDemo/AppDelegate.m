//
//  AppDelegate.m
//  FitCloudRoutePlanDemo
//
//  Created by pcjbird on 2023-11-01.
//

#import "AppDelegate.h"
#import <FitCloudRoutePlan/FitCloudRoutePlan.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    /// You must setup this for the map
    if (@available(iOS 13.0, *)) {
        }
    else {
        self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        [self.window setBackgroundColor:[UIColor whiteColor]];
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
        [self.window setRootViewController:[storyboard instantiateInitialViewController]];
        [self.window makeKeyAndVisible];
    }
    
    /// 高德地图 (AMap)
    [FitCloudRoutePlan registerAMapApiKey:@""];
    /// 百度地图 (BaiduMap)
    [FitCloudRoutePlan registerBaiduMapApiKey:@""];
    
    //[FitCloudRoutePlan setBrandColor:[UIColor orangeColor]];
    //[FitCloudRoutePlan setBrandGradientColors:@[[UIColor orangeColor], [UIColor purpleColor]]];
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options  API_AVAILABLE(ios(13.0)){
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions  API_AVAILABLE(ios(13.0)){
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
