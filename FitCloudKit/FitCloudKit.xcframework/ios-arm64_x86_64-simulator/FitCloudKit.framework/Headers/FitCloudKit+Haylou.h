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

#pragma mark - Query Haylou version information

/// Query Haylou version information
/// - Parameters:
///   - completion: the completion callback
+(void) queryHaylouVersionWithCompletion:(void(^_Nullable)(BOOL success, NSString* _Nullable version, NSError* _Nullable error))completion;


#pragma mark - Query Haylou Watch Serial Number

/// Query Haylou Watch Serial Number
/// - Parameters:
///   - completion: the completion callback
+(void) queryHalylouWatchSerialNumberWithCompletion:(void(^_Nullable)(BOOL success, NSString* _Nullable sn, NSError* _Nullable error)) completion;

@end

#endif /* FitCloudKit_Haylou_h */
