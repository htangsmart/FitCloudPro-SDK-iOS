//
//  AliIot.h
//  AliIotSdk
//
//  Created by cookies on 2023/6/14.
//

#import <Foundation/Foundation.h>
#import <AliIotSdk/AliIotSDKProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface AliIot : NSObject <AliIotSDKProtocol, AliIotSDKFeatureProtocol>
+ (instancetype)shareInstance;

@property (nonatomic, weak) id<AliIotSDKCallbackProtocol> delegate;
@end

NS_ASSUME_NONNULL_END
