//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechRecognitionResult.h"
#import "SPXTimingResult.h"

/**
 * Represents content assessment result
 * Added in version 1.33.0
 */
SPX_EXPORT
@interface SPXContentAssessmentResult : NSObject

/**
 * The grammar score.
 */
@property (readonly) double grammarScore;

/**
 * The vocabulary score.
 */
@property (readonly) double vocabularyScore;

/**
 * The topic score.
 */
@property (readonly) double topicScore;


@end

/**
 * Represents pronunciation assessment result
 * Added in version 1.14.0
 */
SPX_EXPORT
@interface SPXPronunciationAssessmentResult : NSObject

/**
 * The pronunciation accuracy of the given speech, which indicates
 * how closely the phonemes match a native speaker's pronunciation.
 */
@property (readonly) double accuracyScore;

/**
 * The overall score indicating the pronunciation quality of the given speech.
 * This is calculated from AccuracyScore, FluencyScore and CompletenessScore with weight.
 */
@property (readonly)double pronunciationScore;

/**
 * The score indicating the completeness of the given speech by calculating the ratio of pronounced words towards entire input.
 */
@property (readonly)double completenessScore;

/**
 * The score indicating the fluency of the given speech.
 */
@property (readonly)double fluencyScore;

/**
 * The prosody score.
 */
@property (readonly)double prosodyScore;

/**
 * The content assessment result.
 * Only available when content assessment is enabled.
 */
@property (nonatomic, retain, nullable) SPXContentAssessmentResult *contentAssessmentResult;

/**
 * Word level pronunciation assessment results.
 *
 * Added in version 1.21.0
 */
@property (nonatomic, retain, nullable) NSArray<SPXWordLevelTimingResult *> *words;

/**
 * Initializes an SPXPronunciationAssessmentResult object using SPXSpeechRecognitionResult.
 *
 * @param speechRecognitionResult the speech recognition result
 *
 * @return an instance of auto detection source language result.
 */

- (nullable instancetype)init:(nonnull SPXSpeechRecognitionResult *)speechRecognitionResult;


@end