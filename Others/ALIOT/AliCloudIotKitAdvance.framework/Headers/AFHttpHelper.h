//
//  AFHttpHelper.h
//  AliCloudIotKitAdvance
//
//  Created by IYCDev on 2023/1/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AFHttpHelper : NSObject

+ (void)registerDeviceInfoToIotWithParameters:(NSDictionary *)params requestComplete:(void (^)(NSDictionary *JSON,BOOL isSuccess))requestComplete;

@end

NS_ASSUME_NONNULL_END
