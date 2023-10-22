//
//  SMH5GameViewController.h
//  SMH5Game
//
//  Created by Developer on 2022/8/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SMGameInfo;

@interface SMH5GameViewController : UIViewController

/**
 * @brief 游戏对象
 *
 * @discussion 通过获取游戏列表得到的游戏对象
 */
@property (nonatomic, strong) SMGameInfo *game;

/**
 * @brief 开启蓝牙设备sensor数据采集后，数据发送给游戏
 *
 * @param p            对应发送sensor数据的设备（对于单人游戏为1，多人游戏从1开始依次递增）
 * @param xGravity     对应sensor数据中的X轴加速度
 * @param yGravity     对应sensor数据中的Y轴加速度
 * @param zGravity     对应sensor数据中的Z轴加速度
 *
 * @discussion 三轴传感器设备使用该方法发送数据
 */
- (void)movePlayer:(int)p
          xGravity:(int)xGravity
          yGravity:(int)yGravity
          zGravity:(int)zGravity;

/**
 * @brief 开启蓝牙设备sensor数据采集后，数据发送给游戏
 *
 * @param p            对应发送sensor数据的设备（对于单人游戏为1，多人游戏从1开始依次递增）
 * @param x            对应sensor数据中的X陀螺仪
 * @param y            对应sensor数据中的Y陀螺仪
 * @param speed        对应sensor数据中的实时速度
 * @param xThrow       对应sensor数据中的瞬间转向
 * @param yThrow       对应sensor数据中的瞬间俯仰
 * @param countThrow   对应sensor数据中的投掷计数
 * @param xGravity     对应sensor数据中的X轴加速度
 * @param yGravity     对应sensor数据中的Y轴加速度
 * @param zGravity     对应sensor数据中的Z轴加速度
 *
 * @discussion 六轴传感器设备使用该方法发送数据
 */
- (void)movePlayer:(int)p
                 x:(int)x
                 y:(int)y
             speed:(int)speed
            xThrow:(int)xThrow
            yThrow:(int)yThrow
        countThrow:(int)countThrow
          xGravity:(int)xGravity
          yGravity:(int)yGravity
          zGravity:(int)zGravity;


#pragma mark - 开发者通过实现以下方法来完成H5游戏的JS调用

/**
 * @brief 退出游戏
 *
 * @discussion 开发者在实现方法中退出当前界面、切换横竖屏等
 */
- (void)jsCallCloseGame;

/**
 * @brief 游戏需要开启sensor数据采集
 *
 * @param p    对应游戏角色（对于单人游戏为1，多人游戏从1开始依次递增）
 *
 * @discussion 开发者在实现方法中开启设备的sensor数据采集
 */
- (void)jsCallOpenGSensor:(int)p;

/**
 * @brief 游戏需要关闭sensor数据采集
 *
 * @param p    对应游戏角色（对于单人游戏为1，多人游戏从1开始依次递增）
 *
 * @discussion 开发者在实现方法中关闭设备的sensor数据采集
 */
- (void)jsCallCloseGSensor:(int)p;

@end

NS_ASSUME_NONNULL_END
