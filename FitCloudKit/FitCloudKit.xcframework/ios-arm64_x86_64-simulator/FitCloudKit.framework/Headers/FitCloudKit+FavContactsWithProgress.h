//
//  FitCloudKit+FavContactsWithProgress.h
//  FitCloudKit
//
//  Created by pcjbird on 1/25/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#ifndef FitCloudKit_FavContactsWithProgress_h
#define FitCloudKit_FavContactsWithProgress_h
#import <FitCloudKit/FitCloudKit.h>

@interface FitCloudKit (FavContactsWithProgress)

#pragma mark 设置常用联系人

/// 设置常用联系人（将手机上的常用联系人列表同步到手表）
/// - Parameters:
///   - contacts: 常用联系人列表
///   - progress: 进度回调
///   - block: 结果回调
+(void) setFavContacts:(NSArray<FitCloudContactObject*>*_Nullable)contacts progress:(FitCloudProgressBlock _Nullable ) progress block:(FitCloudResultBlock _Nullable )block;

@end

#endif /* FitCloudKit_FavContactsWithProgress_h */
