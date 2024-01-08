//
//  FitCloudECard.h
//  FitCloudKit
//
//  Created by pcjbird on 1/8/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Electronic card, for Transsion infinix project
@interface FitCloudECard : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// the electronic card id
@property(nonatomic, assign, readonly) NSInteger eCardId;

/// the electronic card label or title, max to 30 bytes
@property(nonatomic, strong, readonly) NSString* label;

/// the QRCode content
@property(nonatomic, strong, readonly) NSString* content;


/// Create the electronic card
/// - Parameters:
///   - eCardId: the electronic card id
///   - label: the electronic card label or title
///   - content: the QRCode content
/// - Returns:
///   the electronic card
+(FitCloudECard*) cardWithId:(NSInteger)eCardId label:(NSString*)label content:(NSString*)content;

@end

NS_ASSUME_NONNULL_END
