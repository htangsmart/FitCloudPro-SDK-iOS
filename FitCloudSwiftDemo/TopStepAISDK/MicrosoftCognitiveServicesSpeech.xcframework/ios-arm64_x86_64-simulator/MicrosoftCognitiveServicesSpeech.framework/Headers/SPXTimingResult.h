//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"

/**
 * Contains nbest phoneme information.
 *
 * Added in version 1.21.0
 */
SPX_EXPORT
@interface SPXNBestPhoneme : NSObject

/**
 * The phoneme.
 */
@property (copy, readonly, nullable)NSString *phoneme;

/**
 * The score.
 */
@property (readonly)double score;

@end

/**
 * Contains basic properties of timing result
 *
 * Added in version 1.21.0
 */
SPX_EXPORT
@interface SPXTimingResult : NSObject

/**
 * The time offset.
 */
@property (readonly)NSTimeInterval offset;

/**
 * The time duration.
 */
@property (readonly)NSTimeInterval duration;

@end

/**
 * Contains phoneme level timing result
 *
 * Added in version 1.21.0
 */
SPX_EXPORT
@interface SPXPhonemeLevelTimingResult : SPXTimingResult

/**
 * The phoneme text.
 */
@property (copy, readonly, nullable)NSString *phoneme;

/**
 * The score indicating the pronunciation accuracy of the given speech, which indicates
 * how closely the phoneme match a native speaker's pronunciation
 */
@property (readonly)double accuracyScore;

/**
 * The list of nbest phonemes.
 */
@property (nonatomic, retain, nullable) NSArray<SPXNBestPhoneme *> *nbestPhonemes;

@end

/**
 * Contains syllable level timing result
 *
 * Added in version 1.21.0
 */
SPX_EXPORT
@interface SPXSyllableLevelTimingResult : SPXTimingResult

/**
 * The syllable.
 */
@property (copy, readonly, nullable)NSString *syllable;

/**
 * The grapheme.
 */
@property (copy, readonly, nullable)NSString *grapheme;

/**
 * The score indicating the pronunciation accuracy of the given speech, which indicates
 * how closely the syllable match a native speaker's pronunciation.
 */
@property (readonly)double accuracyScore;

@end

/**
 * Contains word level timing result
 *
 * Added in version 1.21.0
 */
SPX_EXPORT
@interface SPXWordLevelTimingResult : SPXTimingResult

/**
 * The word text.
 */
@property (copy, readonly, nullable)NSString *word;

/**
 * The score indicating the pronunciation accuracy of the given speech, which indicates
 * how closely the phonemes match a native speaker's pronunciation.
 */
@property (readonly)double accuracyScore;

/**
 * This value indicates whether a word is omitted, inserted or badly pronounced, compared to ReferenceText.
 * Possible values are None (meaning no error on this word), Omission, Insertion and Mispronunciation.
 */
@property (copy, readonly, nullable)NSString *errorType;

/**
 * Phoneme level pronunciation assessment result
 */
@property (nonatomic, retain, nullable) NSArray<SPXPhonemeLevelTimingResult *> *phonemes;

/**
 * Syllable level timing result
 */
@property (nonatomic, retain, nullable) NSArray<SPXSyllableLevelTimingResult *> *syllables;

@end
