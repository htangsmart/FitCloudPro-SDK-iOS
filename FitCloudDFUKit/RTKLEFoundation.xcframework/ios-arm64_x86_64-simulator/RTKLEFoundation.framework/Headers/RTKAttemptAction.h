//
//  RTKAttemptAction.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/10.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKLEPackage.h"
#else
#import <RTKLEFoundation/RTKLEPackage.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 * A generic action object which encapsulate action and completion block.
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKActionAttempt class instead")
@interface RTKAttemptAction : NSObject

/**
 * Identifier to identify this action.
 */
@property (nonatomic, readonly) NSInteger ID;
@property (nonatomic, readonly) NSInteger subID;

@property (nonatomic) NSUInteger retryCount;
@property (nonatomic) NSTimeInterval timeoutInterval;

@property (readonly) BOOL isInProgress;

@property (readonly) NSUInteger remainTryCount;


- (instancetype)initWithID:(NSInteger)ID subID:(NSInteger)subID action:(BOOL(^)(NSError *_Nullable* err))action completion:(void(^)(BOOL success, NSError*_Nullable err, id _Nullable obj))handler;

- (instancetype)initWithID:(NSInteger)ID action:(BOOL(^)(NSError *_Nullable* err))action completion:(void(^)(BOOL success, NSError*_Nullable err, id _Nullable obj))handler;

- (void)resume;

// will not trigger completion invoked.
- (void)cancel;

- (void)endCurrentTry;

- (void)endEarlyWithSuccess:(BOOL)success error:(nullable NSError *)error userInfo:(nullable id)info;

@end

NS_ASSUME_NONNULL_END
