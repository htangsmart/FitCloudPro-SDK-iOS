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
+(void) queryHuashengdaWatchWhetherRestoredToFactorySettingsWithCompletion:(void(^_Nullable)(BOOL success, BOOL restored, NSError* _Nullable error))completion;


@end

#endif /* FitCloudKit_Huashengda_h */
