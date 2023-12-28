//
//  RTKActionAttempt.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/12/8.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A generic object which represents an operation attempt.
///
/// If a attempt is started, it executes action block and wait for complete method be called. Call ``completeWithSuccess:error:userInfo:`` to make a attempt completed, as well as a timeout . A attempt has a `totalTryCount` property indicating how many trys can be made before report timeout failure. When a attempt is complete, it call its `completionHandler` block.
///
/// An attempt has a token property which can be used to save identifier information.
@interface RTKActionAttempt : NSObject

/// Initializes this receiver with token and action block and completionHandler.
///
/// - Parameter token: A arbitrary object which is stored by receiver.
/// - Parameter action: A block to be executed. This block has a error parameter and returns a boolean value indicating if executing is successful.
/// - Parameter handler: The completion handler block to be called when this attempt is complete.
- (instancetype)initWithToken:(nullable id)token
                       action:(BOOL(^)(NSError *_Nullable* error))action
            completionHandler:(void(^)(BOOL success, NSError*_Nullable error, id _Nullable userInfo))handler;

/// An arbitrary object associated with this attempt.
///
/// You can use this property to store any identitifier information.
@property (readonly, nullable) id token;

/// The time interval in seconds for one time completion wait.
///
/// Set this property a new value only if the attempt is not started. The default value is `3` seconds.
@property (nonatomic) NSTimeInterval timeoutInterval;

/// The try count before this attempt is assumed completed.
///
/// Set this property a new value only if the attempt is not started. The default value is `1`.
@property (nonatomic) NSUInteger totalTryCount;

/// Returns the remained try count.
///
/// Returns `0` if this attempt is not started.
@property (readonly) NSUInteger remainTryCount;

/// Indicates if the attempt is outstanding.
@property (readonly) BOOL isInProgress;


/// Performs the action and wait for completion call.
///
/// If the action block call returns `NO`, this attempt is assumed failure and complete immediately.
- (void)start;

/// Cancels waiting for completion.
///
/// This method won't call `completionHandler` you provide with ``initWithToken:action:completionHandler:``.
- (void)cancel;

/// Completes this attempt with specific result.
///
/// - Parameter success: A boolean value that indicates if the attempt is successful.
/// - Parameter error: A error object containing information about failure if this attempt is not successful.
/// - Parameter info: A arbitrary object that is passed to completionHandler as userInfo parameter.
- (void)completeWithSuccess:(BOOL)success error:(nullable NSError *)error userInfo:(nullable id)info;


- (void)cancelCurrentAttempt;

@end

NS_ASSUME_NONNULL_END
