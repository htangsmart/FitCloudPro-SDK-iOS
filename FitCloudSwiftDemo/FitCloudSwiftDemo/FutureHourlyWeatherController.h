//
//  FutureHourlyWeatherController.h
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2026/9/17.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 专用于「发送未来逐小时天气」的独立界面。
/// 进入后随机生成 100 条未来逐小时天气数据并展示，
/// 可点击「随机生成」按钮重新生成，点击「发送」按钮将当前数据推送到设备。
@interface FutureHourlyWeatherController : UITableViewController

@end

NS_ASSUME_NONNULL_END
