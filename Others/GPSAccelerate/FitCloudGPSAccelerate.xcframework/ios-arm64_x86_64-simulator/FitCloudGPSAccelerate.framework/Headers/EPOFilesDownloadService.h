//
//  EPOFilesDownloadService.h
//  FitCloudGPSAccelerate
//
//  Created by pcjbird on 4/8/24.
//

#ifndef EPOFilesDownloadService_h
#define EPOFilesDownloadService_h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// the epo files download protocol
@protocol EPOFilesDownloadService <NSObject>

/// download the epo files
/// - Parameters:
///   - completion: the completion callback
-(void) downloadEPOFilesWithCompletionHandler:(void (^ __nullable)(BOOL success, NSArray<NSString*>* _Nullable epoFilePaths, NSError* _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* EPOFilesDownloadService_h */