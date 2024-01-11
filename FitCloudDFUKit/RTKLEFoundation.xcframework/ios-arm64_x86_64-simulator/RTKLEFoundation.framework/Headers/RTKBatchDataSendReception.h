//
//  RTKBatchDataSendReception.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/11/3.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKBTGeneralDefines.h"
#else
#import <RTKLEFoundation/RTKBTGeneralDefines.h>
#endif

NS_ASSUME_NONNULL_BEGIN


/// An abstract class that you use to manage send or receive a batch of data.
///
/// You shall use subclass of  ``RTKBatchDataSender`` or ``RTKBatchDataReceiver`` to perform actual data send or reception. A instance of this class could only perform either sending or receiving, not all of them.
@interface RTKBatchDataSendReception : NSObject

/// Indicates whether the send or reception is in progress.
@property (readonly) BOOL inProgress;

/// The period in seconds that this object will wait before complete.
///
/// A sender or receiver may waits for some events to make progress. It's implementation-specific.
@property NSTimeInterval timeoutInterval;

/// Cancel  a ongoing sending or receiving.
///
/// If a sender or receiver has a `completionHandler` block to call, the block is not called consequently.
- (void)cancel;

/// Begin waiting for more events for make progress.
///
/// As an example, a receiver will wait for more data slice packet incoming, and reports error if not receive a data slice whitin a finite time. Used protectly in subclass.
- (void)beginWaiting;

/// Cancel the waiting.
///
/// Used protectly in subclass.
- (void)cancelWaiting;

@property (readonly) BOOL isWaiting;

/// Complete this sending or receiving.
///
/// Used protectly in subclass.
- (void)completeWithError:(nullable NSError*)error;

@end

/// An abstract sender class you should subclass to send a batch of data.
@interface RTKBatchDataSender : RTKBatchDataSendReception

/// The batch data to send to a remote device.
///
/// The property is set when you call `-sendData:withCompletionHandler:` .
@property (readonly, nullable) NSData *sendingData;

/// Send a batch of data to remote.
///
/// - Parameter data: The data to be send.
/// - Parameter handler: The block to be called when this task is completed.
///
/// You could not call this method more than one time.
- (void)sendData:(NSData *)data withCompletionHandler:(nullable RTKLECompletionBlock)handler;

@end


/// An abstract receiver class you should subclass to receive a batch of data.
@interface RTKBatchDataReceiver : RTKBatchDataSendReception

/// Initiates the receiving task.
///
/// - Parameter handler: The block to be called when this task is completed.
///
/// You could not call this method more than one time.
- (void)startReceivingWithCompletionHandler:(void(^)(BOOL success, NSError *error, NSData *_Nullable receivedData))handler;

/// The data received currently.
@property (readonly, nullable) NSData *receivedData;

/// Tell the receiver that a new data slice incomes.
///
/// Used protectly in subclass.
- (void)didReceiveDataSlice:(NSData *)dataSlice;

@end

NS_ASSUME_NONNULL_END
