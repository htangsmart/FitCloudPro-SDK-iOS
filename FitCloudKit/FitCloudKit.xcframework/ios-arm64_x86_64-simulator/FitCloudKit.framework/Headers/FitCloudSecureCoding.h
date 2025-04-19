//
//  FitCloudSecureCoding.h
//  FitCloudKit
//
//  Created by pcjbird on 4/18/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef FitCloudSecureCoding_h
#define FitCloudSecureCoding_h
#import <Foundation/Foundation.h>

@protocol FitCloudSecureCoding <NSSecureCoding>
@required

+(NSSet *) allowedClasses;

@end

#endif /* FitCloudSecureCoding_h */
