//
//  FitCloudFirmwareModuleVersionModel.h
//  FitCloudKit
//
//  Created by pcjbird on 12/16/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN
/// 固件模块版本信息模型
/// - Note: 用于表示手表其他模块固件版本信息
@interface FitCloudFirmwareModuleVersionModel : NSObject

/// 固件模块类型
/// - Note: 参考 FITCLOUDFIRMWAREMODULETYPE 枚举定义
@property(nonatomic, assign, readonly) FITCLOUDFIRMWAREMODULETYPE moduleType;

/// 固件版本号
@property(nonatomic, copy, readonly) NSString *version;

@end

NS_ASSUME_NONNULL_END
