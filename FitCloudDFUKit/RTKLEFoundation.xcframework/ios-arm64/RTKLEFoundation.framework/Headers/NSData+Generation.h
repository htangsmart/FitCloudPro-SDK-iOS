//
//  NSData+Generation.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/12/17.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (Generation)

+ (NSData *)dataByRandomBytesWithLength:(NSUInteger)length;

@end

NS_ASSUME_NONNULL_END
