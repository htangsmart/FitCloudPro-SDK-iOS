//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechEnums.h"
#import "SPXPropertyCollection.h"

/**
 * Contains detailed information about the synthesis voice information.
 *
 * Updated in version 1.17.0
 */
SPX_EXPORT
@interface SPXVoiceInfo : NSObject

/**
 * The full name.
 */
@property (copy, readonly, nonnull)NSString *name;

/**
 * The locale.
 */
@property (copy, readonly, nonnull)NSString *locale;

/**
 * The short name.
 */
@property (copy, readonly, nonnull)NSString *shortName;

/**
 * The local name.
 */
@property (copy, readonly, nonnull)NSString *localName;

/**
 * The voice gender.
 *
 * Added in version 1.17.0
 */
@property (readonly)SPXSynthesisVoiceGender gender;

/**
 * The voice type.
 */
@property (readonly)SPXSynthesisVoiceType voiceType;

/**
 * The voice path, only valid for offline voices.
 */
@property (nonatomic, retain, nonnull) NSArray *styleList;

/**
 * The voice path, only valid for offline voices.
 */
@property (copy, readonly, nonnull)NSString *voicePath;

/**
 *  The set of properties exposed in the result.
 */
@property (readonly, nullable)id <SPXPropertyCollection> properties;

@end
