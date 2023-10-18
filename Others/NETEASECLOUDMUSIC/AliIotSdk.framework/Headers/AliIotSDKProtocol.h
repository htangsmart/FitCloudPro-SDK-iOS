//
//  AliIotSDKCallbackProtocol.h
//  AliIotSdk
//
//  Created by cookies on 2023/6/15.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AliIotSDKProtocol <NSObject>
- (instancetype)init NS_UNAVAILABLE;

/// 初始化 SDK
/// - Parameter param:
- (void)configSDK:(id)param;

/// 收到 蓝牙 数据
/// - Parameter currData: data
///
/// ```objc
///     // 系统蓝牙外围设备收到设备侧发送回来的蓝牙数据
///     - (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error
///     {
///         // 传入蓝牙数据给 SDK
///         [AliIot.shareInstance handleReceivedData:characteristic.value];
///     }
/// ```
///
- (void)handleReceivedData:(NSData *)currData;

/// 设备断开时调用
/// - Parameter param:
- (void)done:(void(^ _Nonnull )(id _Nullable param))completed;

@end


@protocol AliIotSDKCallbackProtocol <NSObject>


/// 响应数据，返回给上层调用
/// - Parameters:
///   - currData: 当前发出去的数据
///   - device: 蓝牙设备 MAC
///   - error: 先判断空，再发送出去
- (void)handleSendData:(NSData *)currData toDevice:(NSData *)mac error:(NSError * _Nullable)error;

@optional
/// 输出日志,直接监听即可
/// - Parameter log: 日志信息
- (void)handleLog:(NSString *)log;
@end

NS_ASSUME_NONNULL_END
