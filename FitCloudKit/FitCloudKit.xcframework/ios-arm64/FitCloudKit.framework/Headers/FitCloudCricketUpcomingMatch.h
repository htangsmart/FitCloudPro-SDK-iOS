//
//  FitCloudCricketUpcomingMatch.h
//  FitCloudKit
//
//  Created by pcjbird on 2023-07-02.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 即将到来的板球比赛
@interface FitCloudCricketUpcomingMatch : NSObject

/// 比赛id，唯一标志
@property(nonatomic, assign) UInt64 matchId;

/// 比赛名称，最长64字节
@property(nonatomic, strong) NSString* matchName;

/// 队伍1 id
@property(nonatomic, assign) UInt8 team1Id;

/// 队伍2 id
@property(nonatomic, assign) UInt8 team2Id;

/// 比赛日期
@property(nonatomic, strong) NSDate* matchDate;

@end

