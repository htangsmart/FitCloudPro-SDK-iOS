//
//  SMH5GameListViewController.h
//  SMH5Game
//
//  Created by Anting Li on 2023/8/26.
//

#import <UIKit/UIKit.h>
#import "SMGameInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface SMH5GameListViewController : UIViewController

@property (nonatomic, copy) void(^didSelectGameBlock)(SMGameInfo *game);

@property (nonatomic, strong) UIImage *backImage;

@end

NS_ASSUME_NONNULL_END
