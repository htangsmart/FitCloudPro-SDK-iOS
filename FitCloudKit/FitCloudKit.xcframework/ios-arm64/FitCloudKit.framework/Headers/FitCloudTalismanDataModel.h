//
//  FitCloudTalismanDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2025-12-20.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN


/// FitCloudTalismanDataModel
@interface FitCloudTalismanDataModel : NSObject

/// Today’s recommended talisman type
@property(nonatomic, assign) FitCloudTalismanType todayRecommendTalisman;

/// Whether the user has a lover
@property(nonatomic, assign) BOOL hasLover;

/// Talisman type shared by the lover. This property is an NSNumber wrapping FitCloudTalismanType.
/// Valid only when `hasLover` is YES; otherwise, nil.
/// When `hasLover` is YES, a nil value indicates the lover has not shared a talisman.
@property(nonatomic, strong, nullable) NSNumber* talismanSharedByLover;

/// Whether the talisman data is valid.
/// - Returns: YES if the talisman data is valid; otherwise, NO.
- (BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
