//
//  iot_rtc.h
//  RtcSample
//
//  Created by xicai.cxc on 2022/7/5.
//  Copyright © 2022 tiantian. All rights reserved.
//

#ifndef iot_mqtt_h
#define iot_mqtt_h

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

typedef NS_ENUM(NSUInteger, MqttConnectStatus_C) {
DISCONNECTED=0,
CONNECTED=1
};

@interface IotMQTT : NSObject

-(int32_t)mqttInit:(NSString* _Nonnull)productKey deviceName:(NSString* _Nonnull)deviceName deviceSecret:(NSString* _Nonnull)deviceSecret
         hostUrl:(NSString* _Nonnull)hostUrl
             port:(int)port;

-(int32_t)mqttLegacyInit:(NSString* _Nonnull)clientId userName:(NSString* _Nonnull)userName passWord:(NSString* _Nonnull)passWord
    hostUrl:(NSString* _Nonnull)hostUrl
    port:(int)port;

-(int32_t)mqttPub:(NSString* _Nonnull)topic payload:(NSString* _Nonnull)payload  qos:(int)qos;

-(int32_t)mqttPub:(NSString* _Nonnull)topic payloadByBytes:(uint8_t* _Nonnull)payload length:(uint32_t)length qos:(int)qos;

-(int32_t)mqttDeinit;

-(void)setConnectStatusCallback:(void(^_Nonnull)(MqttConnectStatus_C ConnectStatus)) callback;

-(void)setMessageArrivalCallback:(void(^_Nonnull)(NSString* _Nonnull topic, NSString * _Nonnull payload))callback;

-(int32_t) mqttSub:(NSString* _Nonnull)topic  qos:(int)qos;

-(int32_t)mqttUnSub:(NSString* _Nonnull)topic;

+(instancetype _Nonnull ) shareInstance;

@property (nonatomic, strong) NSString * _Nonnull productKey;
@property (nonatomic, strong) NSString * _Nonnull deviceName;
@property (nonatomic, strong) NSString * _Nonnull deviceSecret;

@property (nonatomic, strong) NSString * _Nonnull clientId;
@property (nonatomic, strong) NSString * _Nonnull userName;
@property (nonatomic, strong) NSString * _Nonnull password;


@property (nonatomic, strong) NSString * _Nonnull hostUrl;
@property (nonatomic) int port;

@property(nonatomic,weak) void(^ _Nullable gConnectStatusCallback)(MqttConnectStatus_C ConnectStatus);
@property(nonatomic,weak) void(^ _Nullable gMessageArrivaldCallback)(NSString* _Nonnull topic, NSString * _Nonnull payload);

@end

#endif /* iot_mqtt_h */
