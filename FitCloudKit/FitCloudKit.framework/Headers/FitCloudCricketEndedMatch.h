//
//  FitCloudCricketEndedMatch.h
//  FitCloudKit
//
//  Created by pcjbird on 2023-07-02.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 板球比赛结果数据
@interface FitCloudCricketEndedMatch : NSObject

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

/// 队伍1得分
@property(nonatomic, assign) UInt16 team1Score;

/// 队伍1出局次数，最大为11
@property(nonatomic, assign) UInt8 team1Losses;

/// 队伍1第几轮，最大为50
@property(nonatomic, assign) UInt8 team1Round;

/// 队伍1第几球，最大为6
@property(nonatomic, assign) UInt8 team1Balls;

/// 队伍2得分 （第一局时不展示）
@property(nonatomic, assign) UInt16 team2Score;

/// 队伍2出局次数，最大为11 （第一局时不展示）
@property(nonatomic, assign) UInt8 team2Losses;

/// 队伍2第几轮，最大为50 (第一局时，为0)
@property(nonatomic, assign) UInt8 team2Round;

/// 队伍2第几球，最大为6 (第一局时，为0)
@property(nonatomic, assign) UInt8 team2Balls;

@end

