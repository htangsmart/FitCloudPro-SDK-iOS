//
//  FitCloudGPSAccelerate.h
//  FitCloudGPSAccelerate
//
//  Created by pcjbird on 4/8/24.
//

#import <Foundation/Foundation.h>
#import <LogMate/LogMate.h>
#import <FitCloudGPSAccelerate/EPOFilesDownloadService.h>
#import <FitCloudGPSAccelerate/GPSLocationInfoRequestService.h>
#import <FitCloudGPSAccelerate/FitCloudGPSAccelerateDefines.h>

//! Project version number for FitCloudGPSAccelerate.
FOUNDATION_EXPORT double FitCloudGPSAccelerateVersionNumber;

//! Project version string for FitCloudGPSAccelerate.
FOUNDATION_EXPORT const unsigned char FitCloudGPSAccelerateVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudGPSAccelerate/PublicHeader.h>

NS_ASSUME_NONNULL_BEGIN

/// to accelerate the fitcloudpro smart watch GPS start
@interface FitCloudGPSAccelerate: NSObject

# pragma mark SDK version

/// The sdk version
+(NSString*) sdkVersion;

/// The sdk build version
+(NSString*) sdkBuild;

#pragma mark Settings

/// Set the log service
/// - Parameters:
///   - logService: the log service
+(void)setLogService:(id<LoggableProtocol>)logService;

/// Set the epo files download service
///
/// Optional, if you does not set the service, the SDK will use the topstep default download service, which will download the epo dat files from topstep's server, otherwise, download epo files with your own service.
/// - Parameters:
///   - downloadService: the epo files download service
+(void)setEPOFilesDownloadService:(id<EPOFilesDownloadService> _Nullable)downloadService;

/// Set the GPS location info request service
///
/// Required, the SDK will not implement the location request service, you should implement that yourself. Maybe, when the user disabled the location service or restrict the location authorization, you need to request the location with the IP address.
/// - Parameters:
///   - locationService: the location request service
+(void)setGPSLocationInfoRequestService:(id<GPSLocationInfoRequestService>)locationService;

#pragma mark Check whether the feature supported

/// Check whether the feature supported
///
/// Should invoke when the smart watch device is ready
///
/// - Returns:
/// whether the feature supported
+(BOOL)isFeatureSupported;

#pragma mark Check whether is ICOE GPS

/// Check whether is ICOE GPS
///
/// Should invoke when the smart watch device is ready
///
/// - Returns:
/// whether is ICOE GPS
+(BOOL)isICOE;

#pragma mark Set up GPS location info

/// Request the current location and notify the watch device, you should invoke `setGPSLocationInfoRequestService:` to set the location info request service.
///
/// The method should be invoked in the method `-(void)OnRequestGPSData` of the FitCloudCallback delegate with FitCloudKit SDK.
+(void)requestCurrentLocationAndNotifyTheWatchDevice;

#pragma mark Update the smart watch GPS files

/// Update the smart watch GPS files
/// - Parameters:
///   - force: should update force
///   - started: start result callback
///   - progress: the progress callback
///   - waitDeviceRefresh: waiting for device refresh callback
///   - completion: the completion callback
+(void)startUpdateGPSFilesForce:(BOOL)force started:(void(^_Nullable)(BOOL success, NSError*_Nullable error))started progress:(void(^_Nullable)(CGFloat progress))progress waitDeviceRefresh:(void(^_Nullable)(void))waitDeviceRefresh completion:(void(^_Nullable)(GPSACCELERATERESULT result, NSError* _Nullable error))completion;



+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
