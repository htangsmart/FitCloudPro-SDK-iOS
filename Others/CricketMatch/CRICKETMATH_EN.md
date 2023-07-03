# Cricket match data guide

**Send upcoming cricket match data**

```objc
#pragma mark Send upcoming cricket match data

/**
 * @brief Send upcoming cricket match data
 * @param matches the matches data, up to two are supported currently
 * @param block the send result
 */
+(void) sendUpcomingCricketMatchData:(NSArray<FitCloudCricketUpcomingMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

```

**Send live cricket match data**

```objc
#pragma mark Send live cricket match data

/**
 * @brief Send live cricket match data
 * @param matches the matches data, up to two are supported currently
 * @param block the send result
 */
+(void) sendLiveCricketMatchData:(NSArray<FitCloudCricketLiveMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

```

**Send ended cricket match data**

```objc
#pragma mark Send ended cricket match data

/**
 * @brief Send ended cricket match data
 * @param matches the matches data, up to two are supported currently
 * @param block the send result
 */
+(void) sendEndedCricketMatchData:(NSArray<FitCloudCricketEndedMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

```

**Response the smart watch cricket match data request**

Implement the FitCloudCallback

```objc
/**
 * @brief the smart watch request the cricket match data
 */
-(void) OnRequestCricketMatchData
{
    // app response data here
}
```

Under normal circumstances, a watch does not request cricket match data from the app, but rather the app proactively pushes cricket match data to the watch.

**Team id defines**

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
