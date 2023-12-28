//
//  FitCloudGameObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/6/16.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief 游戏
*/
@interface FitCloudGameObject : NSObject<NSCoding>

/**
 * @brief 游戏类型
*/
@property(nonatomic, readonly) FITCLOUDGAME category;

@end

