//
//  RTKLEPackage.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/10.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RTK_ID_NULL -6666


NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKPacket class instead")
@interface RTKLEPackage : NSObject

@property (readonly) NSInteger ID;
@property (readonly) NSInteger subID;
@property (readonly, nullable) NSData *payload;
@property (readonly) NSDate *time;

- (instancetype)initWithID:(NSInteger)ID payload:(nullable NSData *)payload;

- (instancetype)initWithID:(NSInteger)ID subID:(NSInteger)subID payload:(nullable NSData *)payload;

- (nullable instancetype)initWithRawData:(NSData *)data;

@property (retain) NSData *rawData;

@end


@interface RTKLEACKPackage : RTKLEPackage

@property (readonly) NSInteger ACKID;
@property (readonly, nullable) NSData *additionData;

- (instancetype)initWithACKID:(NSInteger)ID additionData:(nullable NSData *)payload;

- (nullable instancetype)initWithRawData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
