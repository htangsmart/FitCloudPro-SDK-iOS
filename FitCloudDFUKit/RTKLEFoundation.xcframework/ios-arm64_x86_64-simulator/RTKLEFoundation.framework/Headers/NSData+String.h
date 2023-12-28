//
//  NSData+String.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/4/27.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, RTKDataStringFormat) {
    RTKDataStringFormat_plain,      /* "0x00 0x01 0x0a 0xff" */
    RTKDataStringFormat_plain_upperCase,    /* "0x00 0x01 0x0A 0xFF" */
    RTKDataStringFormat_noPrefix,   /* "00 01 0a ff" */
    RTKDataStringFormat_noPrefix_upperCase,   /* "00 01 0A FF" */
    RTKDataStringFormat_noPrefixGap,   /* "00010aff" */
    RTKDataStringFormat_noPrefixGap_upperCase,   /* "00010AFF" */
    RTKDataStringFormat_decorated,  /* "<00 01 0a ff>" */
    RTKDataStringFormat_decorated_upperCase,  /* "<00 01 0A FF>" */
};


@interface NSData (String)

+ (nullable instancetype)dataFromBytesString:(NSString *)string;

- (NSString *)stringOfFormat:(RTKDataStringFormat)format;

@end

NS_ASSUME_NONNULL_END
