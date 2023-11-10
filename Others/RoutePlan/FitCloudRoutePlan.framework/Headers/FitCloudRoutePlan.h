//
//  FitCloudRoutePlan.h
//  FitCloudRoutePlan
//
//  Created by pcjbird on 2023-10-31.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FitCloudRoutePlan/FitCloudRoutePlanDefines.h>

//! Project version number for FitCloudRoutePlan.
FOUNDATION_EXPORT double FitCloudRoutePlanVersionNumber;

//! Project version string for FitCloudRoutePlan.
FOUNDATION_EXPORT const unsigned char FitCloudRoutePlanVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudRoutePlan/PublicHeader.h>

/// Route Plan & Navi Module Delegate
@protocol FitCloudRoutePlanDelegate<NSObject>

@optional

/// The navigation start callback
/// - Parameters:
///   - map: the navigation map
///   - naviType: navi type
-(void) onNaviStartWithMap:(FITCLOUDROUTEPLANMAPPROVIDER)map type:(FITCLOUDROUTEPLANNAVITYPE) naviType;

/// The navigation guide kind callback
/// - Parameters:
///   - guideKind: the guide kind
-(void) onNaviGuideKind:(FITCLOUDROUTEPLANGUIDEKIND)guideKind;

/// The navigation guide text callback
/// - Parameters:
///   - guideText: the guide text
-(void) onNaviGuideText:(NSString*)guideText;

/// The remain time for navigation update callback
/// - Parameters:
///   - remainTime: the remain time in seconds
-(void) onNaviRemainTimeUpdate:(NSInteger)remainTime;

/// The remain distance for navigation update callback
/// - Parameters:
///   - remainDistance: the remain distance in meters
-(void) onNaviRemainDistanceUpdate:(NSInteger)remainDistance;

/// The navigation arrive destination callback
-(void) onNaviArriveDest;

/// The naviagation exit callback
-(void) onNaviExit;

@end

/// Route Plan & Navi Module
@interface FitCloudRoutePlan: NSObject

# pragma mark SDK version

/// The sdk version
+(NSString*) sdkVersion;

/// The sdk build version
+(NSString*) sdkBuild;

# pragma mark Register

/// Register the amap api key
/// - Parameters:
///   - apikey: the api key
+ (void)registerAMapApiKey:(NSString *)apikey;

/// Register the baidu map api key
/// - Parameters:
///   - apikey: the api key
+ (void)registerBaiduMapApiKey:(NSString *)apikey;

#pragma mark Settings

/// Set the brand color
/// - Parameters:
///   - brandColor: the brand color, the default color is #3FCCE2
+ (void)setBrandColor:(UIColor*) brandColor;

/// Set the brand gradient colors
/// - Parameters:
///   - brandGradientColors: the brand gradient colors, the default colors is @[#24FFBD, #46BAFF]
+ (void)setBrandGradientColors:(NSArray<UIColor*>*)brandGradientColors;

# pragma mark Start the route plan

/// Enter the route plan module
/// - Parameters:
///   - fromVC: the from view controller
///   - mapProvider: the map provider
///   - delegate: the delegate
+(void) startRoutePlanFromVC:(UIViewController*)fromVC withProvider:(FITCLOUDROUTEPLANMAPPROVIDER)mapProvider delegate:(id<FitCloudRoutePlanDelegate>)delegate;

@end
