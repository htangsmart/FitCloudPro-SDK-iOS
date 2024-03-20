//
//  AliIot.h
//  AliIotSdk
//
//  Created by cookies on 2023/6/14.
//

#import <Foundation/Foundation.h>
#import <AliIotSdk/AliIotSDKProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface AliIot : NSObject <AliIotSDKProtocol,AliIotSDKMapProtocol>

@property (nonatomic, weak) id<AliIotSDKCallbackProtocol> delegate;
@property (nonatomic, weak) id<AliIotSdkMapCallbackProtocol> mapDelegate;
@property (nonatomic,assign)BOOL configSuccess;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
