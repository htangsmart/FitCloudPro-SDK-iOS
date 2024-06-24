//
//  MqttManagerHeader.h
//  AliCloudIotKit
//
//  Created by xzh on 2022/9/19.
//

#import <AliIotConnectKit/iotMqtt.h>
#import <Foundation/Foundation.h>
#ifndef MqttManager_h
#define MqttManager_h


typedef void (^ _Nonnull ConnectStatusBlock)(MqttConnectStatus_C);
typedef void (^ _Nonnull MessageArrivalBlock)(NSString* _Nonnull topic, NSString * _Nonnull payload);
typedef void (^ _Nonnull MQTTLogBlock)(NSString * _Nonnull log);

@interface MqttManager_C : NSObject

@property (nonatomic,strong) ConnectStatusBlock connectStatusBlock;
@property (nonatomic,strong) MessageArrivalBlock messageArrivalBlock;
@property (nonatomic,strong) MQTTLogBlock logBlock;

@property (nonatomic, strong) void(^ _Nullable DebugAddrBlock)(id _Nonnull data);
- (void)setupCallback;
- (NSString *)mqttInfo;
+ (MqttManager_C*)sharedInstance;


+(uint8_t *)dataToPoint:(NSData *)data;

+ (NSData*)crc16Data:(NSData *)data;
@end


#endif /* MqttManager_h */
