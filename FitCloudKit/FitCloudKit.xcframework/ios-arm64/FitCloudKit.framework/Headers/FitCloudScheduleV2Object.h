//
//  FitCloudScheduleV2Object.h
//  FitCloudKit
//
//  Created by pcjbird on 2026/10/15.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

NS_ASSUME_NONNULL_BEGIN

/// V2 schedule.
@interface FitCloudScheduleV2Object : NSObject <FitCloudSecureCoding>

/// The zero-based position returned by the watch. It is ignored when setting schedules;
/// the SDK generates contiguous indices from the array order.
@property (nonatomic, assign) UInt8 index;

/// Schedule identifier, valid range: 0...127.
@property (nonatomic, assign) UInt8 scheduleId;

/// Whether the schedule is enabled.
@property (nonatomic, assign, getter=isOn) BOOL on;

/// Schedule date and time. The supported year range is 2000...2063.
@property (nonatomic, strong) NSDateComponents *fire;

/// Repeat days, from Monday at bit 0 through Sunday at bit 6.
/// A value of 0 means the schedule only fires on the specified date.
@property (nonatomic, assign) FITCLOUDSCHEDULECYCLE cycle;

/// Minutes before the scheduled time to issue the reminder.
@property (nonatomic, assign) UInt8 aheadRemindInMinute;

/// UTF-8 title, at most 60 bytes.
@property (nonatomic, copy) NSString *title;

/// UTF-8 content, at most 300 bytes.
@property (nonatomic, copy) NSString *content;

@end

NS_ASSUME_NONNULL_END
