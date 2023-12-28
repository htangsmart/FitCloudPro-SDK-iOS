//
//  RTKLPBConnectionManager.h
//  LocalPlayback
//
//  Created by jerome_gu on 2022/3/1.
//  Copyright © 2022 jerome_gu. All rights reserved.
//
#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/// A connection manager which manages connection with peripherals that support LPB(LocalPlayback) feature.
///
/// You use this class to discover a nearby qualified peripheral, or retrieve a qualified peripheral currently connected to the system. The peripheral returned is an instance of `RTKLPBConnectionUponGATT` type.
/// Once have a returned `RTKLPBConnectionUponGATT` instance, you use this instance to connect and communicate with it.
@interface RTKLPBConnectionManager : RTKProfileConnectionManager

@end

NS_ASSUME_NONNULL_END
