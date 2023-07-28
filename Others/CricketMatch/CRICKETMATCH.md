# 板球比赛数据推送指南

**判断手表是否支持板球比赛功能**

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL withCricketMatch = (allConfig && allConfig.firmware.withCricketMatch);

```

**推送即将到来的比赛数据**

```objc
#pragma mark 发送即将到来的板球比赛数据

/**
 * @brief 发送即将到来的板球比赛数据
 * @param matches 比赛数据，目前最多支持两个
 * @param block 结果回调
 */
+(void) sendUpcomingCricketMatchData:(NSArray<FitCloudCricketUpcomingMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

```

**推送正在进行的比赛数据**

```objc
#pragma mark 发送正在进行的板球比赛数据

/**
 * @brief 发送正在进行的板球比赛数据
 * @param matches 比赛数据，目前最多支持两个
 * @param block 结果回调
 */
+(void) sendLiveCricketMatchData:(NSArray<FitCloudCricketLiveMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

```

**推送已经结束的比赛数据**

```objc
#pragma mark 发送已经结束的板球比赛数据

/**
 * @brief 发送已经结束的板球比赛数据
 * @param matches 比赛数据，目前最多支持两个
 * @param block 结果回调
 */
+(void) sendEndedCricketMatchData:(NSArray<FitCloudCricketEndedMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

```

**设置板球比分列表顺序**

```objc
#pragma mark 设置板球比分列表顺序

/**
 * @brief 设置板球比分列表顺序
 * @param match1order  比赛1顺序
 * @param match2order  比赛2顺序
 * @param block 结果回调
 */
+(void) sendCricketMatchScoreListOrderWith:(FitCloudCricketMatchScoreOrder*)match1order match2order:(FitCloudCricketMatchScoreOrder*)match2order withBlock:(FitCloudResultBlock _Nullable)block;

```

**响应手表的板球比赛数据请求**

实现 FitCloudCallback

```objc
/**
 * @brief 手表请求板球比赛数据
 */
-(void) OnRequestCricketMatchData
{
    // app在这里响应板球数据给手表
}
```

正常情况下手表不会向 App 请求板球比赛数据，而是由 App 主动向手表推送板球比赛数据

**队伍 Id 定义**

1. Afghanistan(阿富汗) - AFG
2. Australia(澳大利亚) - AUS
3. Bangladesh(孟加拉国) - BGD
4. England(英格兰) - GBR
5. India(印度) - IND
6. Ireland(爱尔兰) - IRL
7. Nederland(荷兰) - NLD
8. New-Zealand(新西兰) - NZ
9. Oman(阿曼) - OM
10. Pakistan(巴基斯坦) - PAK
11. Scotland(苏格兰) - SCT
12. South-Africa(南非) - ZAF
13. Sri-Lanka(斯里兰卡) - LKA
14. United-Arab-Emirates(阿拉伯联合酋长国) - ARE
15. United-States-of-America(美利坚合众国) - USA
16. West-Indies(西印度群岛) - WI
17. Zimbabwe(津巴布韦) - ZWE
18. CSK - CSK
19. Delhi-Capitals - DC
20. Gujarat-Titans - GT
21. KKR - KKR
22. Lucknow-Super-Giants - LSG
23. Mumbai-Indians - MI
24. Punjab-Kings - PBKS
25. Rajasthan-Royals - RR
26. Royal-Challengers-Bangalore - RCB
27. Sunrisers-Hyderabad - SRH
