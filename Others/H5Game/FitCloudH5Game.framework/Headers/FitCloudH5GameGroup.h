//
//  FitCloudH5GameGroup.h
//  FitCloudH5Game
//
//  Created by pcjbird on 2023-10-21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FitCloudH5GameItem;

/// 游戏组
@interface FitCloudH5GameGroup : NSObject

/// 编号
@property (nonatomic, assign) NSInteger tagId;

/// 名称
@property (nonatomic, copy) NSString *tagName;

/// 游戏信息
@property (nonatomic, copy) NSArray<FitCloudH5GameItem *> *games;

@end

NS_ASSUME_NONNULL_END
