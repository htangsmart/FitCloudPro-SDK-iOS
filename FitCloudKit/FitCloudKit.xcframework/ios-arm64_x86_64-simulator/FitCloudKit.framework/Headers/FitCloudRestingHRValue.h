//
//  FitCloudRestingHRValue.h
//  FitCloudKit
//
//  Created by pcjbird on 4/20/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 静息心率
@interface FitCloudRestingHRValue : NSObject

/// 日期
@property(nonatomic, copy, readonly) NSDate* date;

/// 当天平均静息心率值
@property(nonatomic, readonly) NSInteger value;

@end

NS_ASSUME_NONNULL_END
