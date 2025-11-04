//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechEnums.h"
#import "SPXPropertyCollection.h"
#import "SPXVoiceInfo.h"

/**
 * Contains detailed information about the retrieved synthesis voices list.
 *
 * Added in version 1.16.0
 */
SPX_EXPORT
@interface SPXSynthesisVoicesResult : NSObject

/**
 * The retrieved voices list.
 */
@property (nonatomic, retain, nonnull) NSArray<SPXVoiceInfo *> *voices;

/**
 * The result identifier.
 */
@property (copy, readonly, nonnull)NSString *resultId;

/**
 * The reason the result was created.
 */
@property (readonly)SPXResultReason reason;

/**
 * The error details of the result.
 */
@property (copy, readonly, nonnull)NSString *errorDetails;

/**
 *  The set of properties exposed in the result.
 */
@property (readonly, nullable)id <SPXPropertyCollection> properties;

@end
