//
//  FitCloudKit+Haylou.h
//  FitCloudKit
//
//  Created by pcjbird on 4/10/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#ifndef FitCloudKit_Haylou_h
#define FitCloudKit_Haylou_h

#import <FitCloudKit/FitCloudKit.h>

@interface FitCloudKit (Haylou)

#pragma mark - Query Haylou version information data

/// Query Haylou version information data
/// - Parameters:
///   - completion: the completion callback
+(void) queryHaylouVersionDataWithCompletion:(void(^_Nullable)(BOOL success, NSData*_Nullable versionData, NSError* _Nullable error))completion;

@end

#endif /* FitCloudKit_Haylou_h */
