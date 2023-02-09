//
//  MqttManagerHeader.h
//  AliCloudIotKit
//
//  Created by xzh on 2022/9/19.
//

#import "iotMqtt.h"

#ifndef MqttManager_h
#define MqttManager_h


typedef void (^ _Nonnull ConnectStatusBlock)(MqttConnectStatus);
typedef void (^ _Nonnull MessageArrivalBlock)(NSString* _Nonnull topic, NSString * _Nonnull payload);

@interface MqttManager : NSObject

@property (nonatomic,strong) ConnectStatusBlock connectStatusBlock;
@property (nonatomic,strong) MessageArrivalBlock messageArrivalBlock;

- (void)setupCallback;

+ (MqttManager*)sharedInstance;
@end


#endif /* MqttManager_h */
