//
//  RTKOperationWaitor.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/10/26.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A general purpose object that you use to wait for an asynchronous task to be completed.
///
/// Once you have an ``RTKOperationWaitor`` object, call ``RTKOperationWaitor/wait`` or ``RTKOperationWaitor/waitWithTimeout:`` to begin waiting, then call ``RTKOperationWaitor/cancel`` to stop waiting. The completion handler you pass to ``RTKOperationWaitor/initWithToken:completionHandler:`` will be invoked when either the waitting task is complete or time out occurs. You call ``RTKOperationWaitor/fulfillWithUserInfo:`` to tell the waitor task completion and the waitor then calls completion handler with `success` set to `YES` and `error` set to `nil`. If time out occurs, the completion handler is invoked with `success` set to `NO` and `error` set to a valid error object. A completed (fulfulled or time out) waitor can not receive ``RTKOperationWaitor/wait`` method, nor ``RTKOperationWaitor/cancel`` and ``RTKOperationWaitor/fulfill`` methods.
///
/// When you call ``RTKOperationWaitor/fulfillWithUserInfo:`` with a non-nil pointer as `userInfo`, this pointer will be pass to `userInfo` parameter of the completion handler.
///
/// You can use `token` property to associate any value to a waitor. If you pass an object as token parameter to `-initWithToken:completionHandler: `, the token is assigned the the object pointer value without retain it.
@interface RTKOperationWaitor : NSObject


/// An object assigned by app.
///
/// This object can be used to identify some other entity.
@property (nullable) id token;


/// Initializes a waitor with arbitrary value and completion handler.
///
/// - Parameter token: Arbitrary value assigned to waitor's ``token`` property.
/// - Parameter handler: A completion handler that's invoked after this waitor has finished.
- (instancetype)initWithToken:(nullable id)token completionHandler:(void(^)(BOOL success, NSError *_Nullable error, _Nullable id userInfo))handler;


/// Start waiting for waitor completion.
///
/// The interval for wait is `10` seconds.
- (void)wait;


/// Start waiting for waitor to complete within a specified time.
////
/// - Parameter interval: The number of seconds within which the associated task must be fulfilled.
- (void)waitWithTimeout:(NSTimeInterval)interval;


/// Cancel waiting when waitor is waiting.
- (void)cancel;


/// Tell this waitor the associated task has completed.
///
/// - Parameter userInfo: An arbitrarily value which is passed to `userInfo` parameter of completion handler.
///
/// Once this method get called, the waitor call completion handler.
- (void)fulfillWithUserInfo:(nullable id)userInfo;


/// Interrupt the waitor due to a specified error.
///
/// - Parameter error: an error prevents waitor from continuing.
///
/// Once this method get called, the waitor call completion handler.
- (void)interruptWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
