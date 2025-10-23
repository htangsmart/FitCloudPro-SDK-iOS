//
//  FitCloudAliIotSdk.h
//  FitCloudAliIotSdk
//
//  Created by pcjbird on 6/24/24.
//

#import <Foundation/Foundation.h>
#import <LogMate/LogMate.h>
#import <FitCloudAliIotSdk/FitCloudAliotCallback.h>

//! Project version number for FitCloudAliIotSdk.
FOUNDATION_EXPORT double FitCloudAliIotSdkVersionNumber;

//! Project version string for FitCloudAliIotSdk.
FOUNDATION_EXPORT const unsigned char FitCloudAliIotSdkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudAliIotSdk/PublicHeader.h>


NS_ASSUME_NONNULL_BEGIN

/// The fitcloud and AliIot bridge sdk
@interface FitCloudAliIotSdk: NSObject

# pragma mark SDK version

/// The sdk version
+(NSString*) sdkVersion;

/// The sdk build version
+(NSString*) sdkBuild;

#pragma mark Settings


/// Set the log provider
/// - Parameters:
///   - loggable: the log provider
+(void)setLogProvider:(id<LoggableProtocol>)loggable;


#pragma mark Initialize

/// Initialize
/// - Parameters:
///   - customerName: customer name
///   - callback: the sdk callback receive object, which can process the sdk callback data
/// - Returns:
///  FitCloudAliIotSdk
+(instancetype _Nonnull)initWithCustomerName:(NSString* _Nonnull)customerName callback:(id<FitCloudAliotCallback> _Nonnull) callback;

#pragma mark Start the AliIot Auth

/// start the AliIot Auth
+(void) startAliotAuth;

#pragma mark Cascade the Aliot data from FitCloudKit to the sdk

/// Cascade the Aliot data from FitCloudKit to the sdk
/// - Parameters:
///   - aliotData: the Aliot data
///   - totalPacks: the total data packets count
///   - packIndex: the current data packet index, the subscript index starts from 0
///   - expectedTotalBytes: total length of the  Aliot data, which is the sum of lengths of multiple data packets
+(void) cascadeWithAliotData:(NSData*)aliotData totalPacks:(NSInteger)totalPacks packIndex:(NSInteger)packIndex expectedTotalBytes:(NSInteger)expectedTotalBytes;

#pragma mark Update the smartwatch bluetooth name

/// Update the smartwatch bluetooth name
/// - Parameters:
///   - bleName: the smartwatch bluetooth name
///
/// > Important: Please invoke this method immediately to update the smartwatch bluetooth name at any time when it changes
+(void) updateSmartWatchBluetoothNameWith:(NSString* _Nullable)bleName;

#pragma mark Notify the SDK the smartwatch disconnected

/// Notify the SDK the smartwatch disconnected
///
/// > Important: Please invoke this method immediately when the smartwatch disconnected
+(void) notifySmartWatchDisconnected;

#pragma mark Cascade that the netease cloud music bridge ready state to the sdk

/// Cascade that the netease cloud music bridge ready state to the sdk
+(void) cascadeNetEaseCloudMusicBridgeReady;

#pragma mark Cascade the netease cloud music bridge data from FitCloudKit to the sdk

/// Cascade the netease cloud music bridge data from FitCloudKit to the sdk
/// - Parameters:
///   - data: the netease cloud music bridge data
+(void) cascadeWithNetEaseCloudMusicBridgeData:(NSData*)data;


+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
