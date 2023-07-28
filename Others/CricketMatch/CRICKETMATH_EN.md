# Cricket match data guide

**Check whether the cricket match feature is supported**

```objc
FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
BOOL withCricketMatch = (allConfig && allConfig.firmware.withCricketMatch);

```

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

**Send cricket match score list order**

```objc
#pragma mark Send cricket match score list order

/**
 * @brief Send cricket match score list order
 * @param match1order  match1 order
 * @param match2order  match2 order
 * @param block the send result
 */
+(void) sendCricketMatchScoreListOrderWith:(FitCloudCricketMatchScoreOrder*)match1order match2order:(FitCloudCricketMatchScoreOrder*)match2order withBlock:(FitCloudResultBlock _Nullable)block;

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

1. Afghanistan - AFG
2. Australia - AUS
3. Bangladesh - BGD
4. England - GBR
5. India - IND
6. Ireland - IRL
7. Nederland - NLD
8. New-Zealand - NZ
9. Oman - OM
10. Pakistan - PAK
11. Scotland - SCT
12. South-Africa - ZAF
13. Sri-Lanka - LKA
14. United-Arab-Emirates - ARE
15. United-States-of-America - USA
16. West-Indies - WI
17. Zimbabwe - ZWE
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
