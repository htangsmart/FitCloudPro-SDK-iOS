//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechEnums.h"

/**
 * Defines the payload of speech synthesis event.
 *
 * Added in version 1.7.0
 */
SPX_EXPORT
@interface SPXSpeechSynthesisEventArgs : NSObject

/**
 * The synthesis result.
 */
@property (readonly, nonnull)SPXSpeechSynthesisResult *result;

@end

/**
 * Defines the payload of speech synthesis word boundary event.
 *
 * Added in version 1.7.0
 */
SPX_EXPORT
@interface SPXSpeechSynthesisWordBoundaryEventArgs : NSObject

/**
 * The result identifier.
 *
 * Added in version 1.25.0
 */
@property (copy, readonly, nonnull)NSString *resultId;

/**
 * Word boundary audio offset, in ticks (100 nanoseconds).
 */
@property (readonly)NSUInteger audioOffset;

/**
 * Time duration of the audio.
 *
 * Added in version 1.21.0.
 */
@property (readonly)NSTimeInterval duration;

/**
 * Word boundary text offset.
 */
@property (readonly)NSUInteger textOffset;

/**
 * Word boundary word length.
 */
@property (readonly)NSUInteger wordLength;

/**
 * The text.
 *
 * Added in version 1.21.0
 */
@property (copy, readonly, nonnull)NSString *text;

/**
 * Word boundary type.
 *
 * Added in version 1.21.0.
 */
@property (readonly) SPXSpeechSynthesisBoundaryType boundaryType;

@end

/**
 * Defines the payload of speech synthesis viseme event.
 *
 * Added in version 1.16.0
 */
SPX_EXPORT
@interface SPXSpeechSynthesisVisemeEventArgs : NSObject

/**
 * The result identifier.
 *
 * Added in version 1.25.0
 */
@property (copy, readonly, nonnull)NSString *resultId;

/**
 * Viseme audio offset, in ticks (100 nanoseconds).
 */
@property (readonly)uint64_t audioOffset;

/**
 * Viseme ID.
 */
@property (readonly)NSUInteger visemeId;

/**
 * The animation of current viseme evenet, could be in svg or other format.
 */
@property (copy, readonly, nonnull)NSString *animation;

@end

/**
 * Defines the payload of speech synthesis bookmark event.
 *
 * Added in version 1.16.0
 */
SPX_EXPORT
@interface SPXSpeechSynthesisBookmarkEventArgs : NSObject

/**
 * The result identifier.
 *
 * Added in version 1.25.0
 */
@property (copy, readonly, nonnull)NSString *resultId;

/**
 * Audio offset of current bookmark, in ticks (100 nanoseconds).
 */
@property (readonly)uint64_t audioOffset;

/**
 * The bookmark text.
 */
@property (copy, readonly, nonnull)NSString *text;

@end
