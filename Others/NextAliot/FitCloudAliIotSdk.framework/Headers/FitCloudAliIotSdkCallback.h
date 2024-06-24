//
//  FitCloudAliIotSdkCallback.h
//  FitCloudAliIotSdk
//
//  Created by pcjbird on 6/24/24.
//

#ifndef FitCloudAliIotSdkCallback_h
#define FitCloudAliIotSdkCallback_h
#import <Foundation/Foundation.h>

@protocol FitCloudAliIotSdkCallback<NSObject>

/// On received Aliot data from server.
/// > Important: Please invoke `+(void) sendAliotData:(NSData*)aliotData withBlock:(FitCloudResultBlock _Nullable)block` to send the data to the smartwatch
/// - Parameters:
///   - aliotData: the data received from Aliot server
-(void) onReceivedCloudAliotData:(NSData*)aliotData;

/// On received netease cloud music bridge data from server.
/// > Important: Please invoke `+(void) sendNetEaseBridgeData:(NSData*)data` to send the data to the smartwatch
/// - Parameters:
///   - bridgeData: the bridge data received from server
-(void) onReceivedCloudNetEaseBridgeData:(NSData*) bridgeData;

@end

#endif /* FitCloudAliIotSdkCallback_h */
