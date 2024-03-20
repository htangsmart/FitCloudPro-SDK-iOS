//
//  AliIotSDKCallbackProtocol.h
//  AliIotSdk
//
//  Created by cookies on 2023/6/15.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AliIotSDKProtocol <NSObject>
- (instancetype)init NS_UNAVAILABLE;

/// 配置SDK,每次连接上蓝牙设备后调用
- (void)configSDK;

/// 收到 蓝牙 数据
/// - Parameter currData: 蓝牙数据
- (void)handleReceivedData:(NSData *)currData;

/// 断开设备调用结束工作
/// - Parameter completed: 清理结束回调
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
/// 初始化结果
/// - Parameter isFinish: 是否完成初始化
- (void)sdkInitResult:(BOOL)isFinish;

/// 输出日志=
/// - Parameter log: 日志信息
- (void)handleLog:(NSString *)log;
@end


@protocol AliIotSDKMapProtocol <NSObject>
/// 打开map h5
/// - Parameters:
///   - viewController: 跳转controller
- (void)openMapBy:(UIViewController *)viewController;

/// 发送收藏列表
/// - Parameter jsonString: 收藏数据
- (void)sendCollectList:(NSString *)jsonString;

/// 发送轨迹数据
/// - Parameter jsonString: 轨迹数据
- (void)sendTrajectoryList:(NSString *)jsonString;
@end

@protocol AliIotSdkMapCallbackProtocol <NSObject>

/// 添加收藏
/// - Parameters:
///   - collectionId: 收藏id
///   - jsonString: 内容
- (void)addCollect:(NSString *)collectionId content:(NSString *)jsonString;

/// 取消收藏
/// - Parameter collectionId: 收藏id
- (void)removeCollect:(NSString *)collectionId;

/// 获取收藏列表
/// - Parameters:
///   - page: 页码
///   - pageSize: 页大小
- (void)getCollectListView:(NSInteger)page pageSize:(NSInteger)pageSize;


///  添加轨迹
/// - Parameters:
///   - trajectoryId: 轨迹id
///   - jsonString: 内容
- (void)addTrajectory:(NSString *)trajectoryId content:(NSString *)jsonString;

/// 移除轨迹
/// - Parameter trajectoryId: 轨迹id
- (void)removeTrajectory:(NSString*)trajectoryId;

/// 获取轨迹列表
/// - Parameters:
///   - page: 页码
///   - pageSize: 页大小
- (void)getTrajectoryListView:(NSInteger)page pageSize:(NSInteger)pageSize;
@end
NS_ASSUME_NONNULL_END
