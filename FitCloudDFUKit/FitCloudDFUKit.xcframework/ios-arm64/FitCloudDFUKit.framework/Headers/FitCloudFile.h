//
//  FitCloudFile.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 12/5/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudDFUKit/FitCloudFileFormat.h>


/// 文件
@interface FitCloudFile : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 名称
@property (nonatomic, strong, readonly) NSString * _Nonnull name;

/// 文件格式
@property (nonatomic, readonly) FITCLOUDFILEFORMAT format;

@end

