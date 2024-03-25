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

@property (nonatomic, weak) id<AliIotSDKCallbackProtocol> delegate;/// 业务相关代码
@property (nonatomic, weak) id<AliIotSdkMapCallbackProtocol> mapDelegate;/// 地图相关代理
@property (nonatomic,assign)BOOL configSuccess;///是否初始化成功，只有初始化成功了，才可以正常通讯

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
