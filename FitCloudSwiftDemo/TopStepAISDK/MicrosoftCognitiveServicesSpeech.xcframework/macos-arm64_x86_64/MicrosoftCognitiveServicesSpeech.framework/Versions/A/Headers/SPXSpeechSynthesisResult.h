//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechEnums.h"
#import "SPXPropertyCollection.h"

/**
 * Defines the speech synthesis result.
 *
 * Added in version 1.7.0
 */
SPX_EXPORT
@interface SPXSpeechSynthesisResult : NSObject

/**
 * The result identifier.
 */
@property (copy, readonly, nonnull)NSString *resultId;

/**
 * The synthesized audio data.
 */
@property (readonly, nullable)NSData *audioData;

/**
 * The reason the result was created.
 */
@property (readonly)SPXResultReason reason;

/**
 * The set of properties exposed in the result.
 */
@property (readonly, nullable)id <SPXPropertyCollection> properties;

/**
 * The time duration of the synthesized audio.
 * Added in version 1.21.0.
 */
@property (readonly)NSTimeInterval audioDuration;

@end
