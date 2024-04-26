//
//  FitCloudKit+SingleDataSync.h
//  FitCloudKit
//
//  Created by pcjbird on 12/23/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <FitCloudKit/FitCloudKit.h>

/// 单项同步数据类型
typedef NS_ENUM(Byte, MANUALSINGLESYNCKEY)
{
    MANUALSINGLESYNCKEY_STEPS = 0x01,                   //计步数据
    MANUALSINGLESYNCKEY_SLEEP = 0x02,                   //睡眠数据
    MANUALSINGLESYNCKEY_HEARTRATE = 0x03,               //心率数据
    MANUALSINGLESYNCKEY_BLOODOXYGEN = 0x04,             //血氧数据
    MANUALSINGLESYNCKEY_SPORSMODE   = 0x10,             //运动模式数据
};

@interface FitCloudKit (SingleDataSync)

#pragma mark 手动同步单项历史运动健康数据

/// 手动同步历史运动健康数据
/// - Parameters:
///   - option: 选项，默认 FITCLOUDDATASYNCOPTION_LEGACY
///   - syncKey: 同步Key
///   - progress: 进度回调
///   - block: 结果回调
+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;

@end

