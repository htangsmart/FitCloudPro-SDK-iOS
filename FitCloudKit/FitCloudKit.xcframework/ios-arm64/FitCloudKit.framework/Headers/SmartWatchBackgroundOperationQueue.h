//
//  SmartWatchBackgroundOperationQueue.h
//  FitCloudPro
//
//  Created by pcjbird on 11/19/19.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartWatchOperation.h"

@interface SmartWatchBackgroundOperationQueue : NSOperationQueue

+(SmartWatchBackgroundOperationQueue *) Queue;

-(BOOL)addWatchOperation:(SmartWatchOperation *)op;
-(BOOL)addWatchOperationIfNotExist:(SmartWatchOperation *)op;
@end

