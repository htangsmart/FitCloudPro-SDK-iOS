//
//  AppDelegate.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate.h"
#import "AppDelegate+LoggerService.h"
#import "AppDelegate+FitCloudKit.h"
#import <FitCloudGPSAccelerate/FitCloudGPSAccelerate.h>


@interface AppDelegate ()<LoggableProtocol, GPSLocationInfoRequestService>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [FitCloudGPSAccelerate setLogProvider:self];
    [FitCloudGPSAccelerate setGPSLocationInfoRequestService:self];
    [self loggerServiceConfig];
    [self fitCloudKitConfig];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - GPSLocationInfoRequestService

/// request the GPS Location
/// - Parameters:
///   - completion: the completion callback
-(void) requestGPSLocationWithCompletionHandler:(void (^ __nullable)(BOOL success, double lon, double lat, NSError* _Nullable error))completion
{
    #error "TODO 请自行实现这段代码"
    /// 请自行实现这段代码
    /*if(completion)
    {
        completion(YES, 121.449324, 31.284062, nil);
    }*/
}

#pragma mark - LoggableProtocol

/// implement to log the message
/// - Parameters:
///   - message: the log message
///   - level: the log level
///   - subsystem: the log subsystem
///   - category: the log category
-(void) onLogMateMessage:(NSString*)message level:(LOGMATELEVEL)level subsystem:(NSString*)subsystem category:(NSString*)category
{
    message = [[message stringByReplacingOccurrencesOfString:@"<" withString:@"["] stringByReplacingOccurrencesOfString:@">" withString:@"]"];
    if(level == LOGMATELEVEL_INFO)
    {
        XLOG_INFO(@"%@", APP_LOG_STRING(@"%@",message));
    }
    else if(level == LOGMATELEVEL_WARNING)
    {
        XLOG_WARNING(@"%@", APP_LOG_STRING(@"%@",message));
    }
    else if(level == LOGMATELEVEL_ERROR)
    {
        XLOG_ERROR(@"%@", APP_LOG_STRING(@"%@",message));
    }
    else if(level == LOGMATELEVEL_VERBOSE)
    {
        XLOG_VERBOSE(@"%@", APP_LOG_STRING(@"%@",message));
    }
}

@end
