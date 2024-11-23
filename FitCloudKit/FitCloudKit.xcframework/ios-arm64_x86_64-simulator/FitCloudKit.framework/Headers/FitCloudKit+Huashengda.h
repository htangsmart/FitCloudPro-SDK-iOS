//
//  FitCloudKit+Huashengda.h
//  FitCloudKit
//
//  Created by pcjbird on 6/21/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#ifndef FitCloudKit_Huashengda_h
#define FitCloudKit_Huashengda_h

@interface FitCloudKit (Huashengda)

#pragma mark - Query whether Huashengda watch is restore to factory settings

/// Query whether Huashengda watch is restore to factory settings
/// - Parameters:
///   - completion: the completion callback
///
/// > Warning: Please do not invoke when in automatic connecting process, usually invoke before bind or when receive `FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY` event
+(void) queryHuashengdaWatchWhetherRestoredToFactorySettingsWithCompletion:(void(^_Nullable)(BOOL success, BOOL restored, NSError* _Nullable error))completion;


#pragma mark - Query whether Huashengda watch current user id whether match to the user id provided

/// Query whether Huashengda watch current user id whether match to the user id provided
/// - Parameters:
///   - userId: the user id you provided for testing
///   - completion: the completion callback
///
/// > Warning: Please do not invoke when in automatic connecting process, usually invoke before bind
+(void) queryHuashengdaWatchCurrentUserIdWetherMatch:(NSString* _Nonnull)userId completion:(void(^_Nullable)(BOOL success, BOOL isMatch, NSError* _Nullable error))completion;


@end

#endif /* FitCloudKit_Huashengda_h */
