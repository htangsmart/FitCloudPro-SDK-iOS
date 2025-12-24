//
//  FitCloudTodayFortuneDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2025-12-20.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Today's Fortune Data Model
///
/// Used to store and transmit all information related to today's fortune, including lucky numbers, lucky colors, lucky star rating, auspicious direction, and today's advice.
@interface FitCloudTodayFortuneDataModel : NSObject

/// The first lucky number, ranging from 0 to 9.
@property(nonatomic, assign) NSInteger luckyNumber1;

/// The second lucky number, ranging from 0 to 9.
@property(nonatomic, assign) NSInteger luckyNumber2;

/// The third lucky number, ranging from 0 to 9.
@property(nonatomic, assign) NSInteger luckyNumber3;

/// Today's lucky star rating, ranging from 1 to 5.
@property(nonatomic, assign) NSInteger luckyStarRating;

/// The first lucky color.
@property(nonatomic, copy) UIColor* luckyColor1;

/// The second lucky color.
@property(nonatomic, copy) UIColor* luckyColor2;

/// The third lucky color.
@property(nonatomic, copy) UIColor* luckyColor3;

/// The auspicious direction.
///
/// - 0: East
/// - 1: Southeast
/// - 2: South
/// - 3: Southwest
/// - 4: West
/// - 5: Northwest
/// - 6: North
/// - 7: Northeast
@property(nonatomic, assign) FitCloudAuspiciousDirection auspiciousDirection;

/// Today's advice, with a maximum length of 200 bytes.
@property(nonatomic, strong, nullable) NSString* fortuneAdvice;

@end

NS_ASSUME_NONNULL_END
