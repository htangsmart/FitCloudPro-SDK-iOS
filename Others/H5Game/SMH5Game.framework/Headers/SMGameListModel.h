//
//  SMGameListModel.h
//  SMH5Game
//
//  Created by Anting Li on 2023/8/26.
//

#import <Foundation/Foundation.h>
#import "SMGameInfo.h"

@interface SMGameListModel : NSObject

@property (nonatomic, copy) NSArray<SMGameInfo *> *gameList;

@property (nonatomic, assign) NSInteger tagId;

@property (nonatomic, copy) NSString *tagName;

@end
