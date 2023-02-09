//
//  iot_rtc.h
//  RtcSample
//
//  Created by xicai.cxc on 2022/7/5.
//  Copyright © 2022 tiantian. All rights reserved.
//

#ifndef iot_mqtt_h
#define iot_mqtt_h


typedef NS_ENUM(NSUInteger, MqttConnectStatus) {
DISCONNECTED=0,
CONNECTED=1
};

@interface IotMQTT : NSObject


/**
 初始化接口，适用于通过productKey, deviceName, deviceSecret实现mqtt连云的情况
 返回值：0表示成功，-1表示失败
 */
-(int32_t)mqttInit:(NSString* _Nonnull)productKey deviceName:(NSString* _Nonnull)deviceName deviceSecret:(NSString* _Nonnull)deviceSecret
         hostUrl:(NSString* _Nonnull)hostUrl
             port:(int)port;

/**
初始化接口，适用于通过clientId,username, password实现mqtt连云的情况
返回值：0表示成功，-1表示失败
*/
-(int32_t)mqttLegacyInit:(NSString* _Nonnull)clientId userName:(NSString* _Nonnull)userName passWord:(NSString* _Nonnull)passWord
    hostUrl:(NSString* _Nonnull)hostUrl
    port:(int)port;


/**
接听连接状态的回调，要在调用mqttInit之前完成设置
返回值：void
*/
-(void)setConnectStatusCallback:(void(^_Nonnull)(MqttConnectStatus ConnectStatus)) callback;

/**
下行消息到达的回调，建议在调用mqttInit之前完成设置
返回值：void
*/
-(void)setMessageArrivalCallback:(void(^_Nonnull)(NSString* _Nonnull topic, NSString * _Nonnull payload))callback;

/**
订阅mqtt topic
 返回值：0表示发送订阅报文成功
*/
-(int32_t) mqttSub:(NSString* _Nonnull)topic  qos:(int)qos;

/**
反订阅mqtt topic
返回值：0表示发送反订阅报文成功
*/
-(int32_t)mqttUnSub:(NSString* _Nonnull)topic;

/**
发送mqtt报文
返回值：
    对于qos=0的报文， 返回0表示发送成功，负数表示发送失败
    对于qos=1，返回的>=0的数值表示消息id，返回负数表示失败
*/
-(int32_t)mqttPub:(NSString* _Nonnull)topic payload:(NSString* _Nonnull)payload  qos:(int)qos;

/**
反初始化接口
返回值：0表示成功，负数表示失败
*/
-(int32_t)mqttDeinit;

+(instancetype _Nonnull ) shareInstance;

@property (nonatomic, strong) NSString * _Nonnull productKey;
@property (nonatomic, strong) NSString * _Nonnull deviceName;
@property (nonatomic, strong) NSString * _Nonnull deviceSecret;

@property (nonatomic, strong) NSString * _Nonnull clientId;
@property (nonatomic, strong) NSString * _Nonnull userName;
@property (nonatomic, strong) NSString * _Nonnull password;


@property (nonatomic, strong) NSString * _Nonnull hostUrl;
@property (nonatomic) int port;

@property(nonatomic,weak) void(^ _Nullable gConnectStatusCallback)(MqttConnectStatus ConnectStatus);
@property(nonatomic,weak) void(^ _Nullable gMessageArrivaldCallback)(NSString* _Nonnull topic, NSString * _Nonnull payload);

@end

#endif /* iot_mqtt_h */
