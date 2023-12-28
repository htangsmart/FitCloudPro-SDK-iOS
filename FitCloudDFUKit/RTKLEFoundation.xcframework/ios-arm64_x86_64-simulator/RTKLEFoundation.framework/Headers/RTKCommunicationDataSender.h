//
//  RTKCommunicationDataSender.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2020/1/21.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKBTGeneralDefines.h"
#import "RTKPackageCommunication.h"
#else
#import <RTKLEFoundation/RTKBTGeneralDefines.h>
#import <RTKLEFoundation/RTKPackageCommunication.h>
#endif


NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKBatchDataSender class instead")
@interface RTKCommunicationDataSender : NSObject {
@protected
    BOOL _inProgress;
    RTKLECompletionBlock _completionHandler;
}

- (instancetype)initWithCommunication:(RTKPackageCommunication *)communication;

@property (nonatomic, readonly) RTKPackageCommunication *communication;

@property (readonly) BOOL inProgress;
- (void)sendData:(NSData *)data withCompletionHandler:(nullable RTKLECompletionBlock)handler;

@property (nonatomic, readonly) NSData *sendingData;

- (void)cancelInProgressSending;

@end

NS_ASSUME_NONNULL_END
