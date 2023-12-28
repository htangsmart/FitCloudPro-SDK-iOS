//
//  FitCloudCricketLiveMatch.h
//  FitCloudKit
//
//  Created by pcjbird on 2023-07-02.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 板球直播数据
@interface FitCloudCricketLiveMatch : NSObject

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

/// 第几局，值为1或2
@property(nonatomic, assign) UInt8 round;

///击球手1名字
@property(nonatomic, strong) NSString* strikePlayer1Name;

///击球手1得分
@property(nonatomic, assign) UInt16 strikePlayer1Score;

///击球手1打了多少球
@property(nonatomic, assign) UInt16 strikePlayer1Balls;

///击球手2名字
@property(nonatomic, strong) NSString* strikePlayer2Name;

///击球手2得分
@property(nonatomic, assign) UInt16 strikePlayer2Score;

///击球手2打了多少球
@property(nonatomic, assign) UInt16 strikePlayer2Balls;

///投球手名字
@property(nonatomic, strong) NSString* pitcherName;

///投球手第几轮
@property(nonatomic, assign) UInt8 pitcherRound;

///投球手第几球
@property(nonatomic, assign) UInt8 pitcherBalls;

///投球手得分
@property(nonatomic, assign) UInt16 pitcherScore;

///投球手淘汰对手的次数
@property(nonatomic, assign) UInt8 pitcherWins;

///当前得分率，手表上显示的值为该值除以10
@property(nonatomic, assign) UInt16 crr;

///所需得分率，手表上显示的值为该值除以10
@property(nonatomic, assign) UInt16 rrr;

@end

