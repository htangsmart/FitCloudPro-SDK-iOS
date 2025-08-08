//
//  FitCloudIncomingCallPhotoSlotModel.h
//  FitCloudKit
//
//  Created by pcjbird on 8/2/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FitCloudIncomingCallPhotoSlotModel : NSObject

@property (nonatomic, readonly) NSUInteger slotIndex;

@property (nonatomic, copy, readonly, nullable) NSString* phoneNumber;

@property (nonatomic, readonly) BOOL hasPhoto;

@end

NS_ASSUME_NONNULL_END
