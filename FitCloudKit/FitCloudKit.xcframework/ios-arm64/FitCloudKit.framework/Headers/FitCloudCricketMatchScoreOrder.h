//
//  FitCloudCricketMatchScoreOrder.h
//  FitCloudKit
//
//  Created by pcjbird on 2023-07-28.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FitCloudCricketMatchScoreOrder : NSObject

/// 比赛id，唯一标志
@property(nonatomic, assign) UInt64 matchId;

/// 比赛顺序，可填1或2
@property(nonatomic, assign) UInt8 order;

@end

