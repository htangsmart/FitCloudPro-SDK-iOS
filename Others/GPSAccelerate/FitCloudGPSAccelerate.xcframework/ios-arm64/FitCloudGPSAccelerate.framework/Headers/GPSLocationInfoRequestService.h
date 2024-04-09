//
//  GPSLocationInfoRequestService.h
//  FitCloudGPSAccelerate
//
//  Created by pcjbird on 4/9/24.
//

#ifndef GPSLocationInfoRequestService_h
#define GPSLocationInfoRequestService_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// the GPS location info request service protocol
@protocol GPSLocationInfoRequestService <NSObject>

/// request the GPS Location
/// - Parameters:
///   - completion: the completion callback
-(void) requestGPSLocationWithCompletionHandler:(void (^ __nullable)(BOOL success, double lon, double lat, NSError* _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* GPSLocationInfoRequestService_h */
