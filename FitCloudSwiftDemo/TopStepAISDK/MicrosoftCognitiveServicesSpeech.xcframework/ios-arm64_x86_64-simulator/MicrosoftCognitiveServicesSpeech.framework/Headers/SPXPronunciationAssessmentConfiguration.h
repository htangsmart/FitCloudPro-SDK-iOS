//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechEnums.h"
#import "SPXRecognizer.h"

/**
 * Represents pronunciation assessment configuration
 * Added in version 1.14.0
 */
SPX_EXPORT
@interface SPXPronunciationAssessmentConfiguration : NSObject

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration.
 * For parameter details, see the table
 * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
 *
 * @param referenceText The reference text.
 * @param gradingSystem The point system for score calibration.
 * @param granularity The evaluation granularity.
 * @param enableMiscue If enables miscue calculation. When true, the pronounced words are compared to the reference text, and are marked with omission/insertion based on the comparison; when false, the recognized text will always be reference text.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)init:(nonnull NSString *)referenceText
                gradingSystem:(SPXPronunciationAssessmentGradingSystem)gradingSystem
                  granularity:(SPXPronunciationAssessmentGranularity)granularity
                 enableMiscue:(BOOL)enableMiscue
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration.
 * For parameter details, see the table
 * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
 *
 * @param referenceText The reference text.
 * @param gradingSystem The point system for score calibration.
 * @param granularity The evaluation granularity.
 * @param enableMiscue If enables miscue calculation.
 * @param outError error information.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)init:(nonnull NSString *)referenceText
                gradingSystem:(SPXPronunciationAssessmentGradingSystem)gradingSystem
                  granularity:(SPXPronunciationAssessmentGranularity)granularity
                 enableMiscue:(BOOL)enableMiscue
                        error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration.
 * For parameter details, see the table
 * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
 *
 * @param referenceText The reference text.
 * @param gradingSystem The point system for score calibration.
 * @param granularity The evaluation granularity.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)init:(nonnull NSString *)referenceText
                gradingSystem:(SPXPronunciationAssessmentGradingSystem)gradingSystem
                  granularity:(SPXPronunciationAssessmentGranularity)granularity
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration.
 * For parameter details, see the table
 * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
 *
 * @param referenceText The reference text.
 * @param gradingSystem The point system for score calibration.
 * @param granularity The evaluation granularity.
 * @param outError error information.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)init:(nonnull NSString *)referenceText
                gradingSystem:(SPXPronunciationAssessmentGradingSystem)gradingSystem
                  granularity:(SPXPronunciationAssessmentGranularity)granularity
                        error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration.
 * For parameter details, see the table
 * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
 *
 * @param referenceText The reference text.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)init:(nonnull NSString *)referenceText
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration.
 * For parameter details, see the table
 * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
 *
 * @param referenceText The reference text.
 * @param outError error information.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)init:(nonnull NSString *)referenceText
                        error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration using json string.
 *
 * @param json the json string.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)initWithJson:(nonnull NSString *)json
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes an instance of the SPXPronunciationAssessmentConfiguration using json string.
 *
 * @param json the json string.
 * @param outError error information.
 *
 * @return an instance of pronunciation assessment configuration.
 */
- (nullable instancetype)initWithJson:(nonnull NSString *)json
                                error:(NSError * _Nullable * _Nullable)outError;

/**
 * The reference text.
 */
@property (nonatomic, copy, nullable)NSString *referenceText;

/**
 * The phoneme alphabet. Valid values are "SAPI" (default) and "IPA".
 *
 * NOTE: Added in version 1.20.0
 */
@property (nonatomic, copy, nullable)NSString *phonemeAlphabet;
- (nullable NSString *)phonemeAlphabet UNAVAILABLE_ATTRIBUTE;

/**
 * The nbest phoneme count.
 *
 * NOTE: Added in version 1.20.0
 */
@property (nonatomic)NSInteger nbestPhonemeCount;
- (NSInteger)nbestPhonemeCount UNAVAILABLE_ATTRIBUTE;

/**
 * Whether to enable prosoody assessment.
 *
 * Added in version 1.33.0.
 */
- (void)enableProsodyAssessment;

/**
 * Enables content assessment with specific topic.
 *
 * Added in version 1.33.0.
 */
- (void)enableContentAssessmentWithTopic:(nonnull NSString *)topic;

/**
 * Gets the json string of pronunciation assessment parameters.
 *
 * @return json string of pronunciation assessment parameters.
 */
- (nullable NSString *)toJson;

/**
 * Applies the settings in this config to a recognizer.
 *
 * @param recognizer The target recognizer.
 */
- (void)applyToRecognizer:(nonnull SPXRecognizer *)recognizer
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");


/**
 * Applies the settings in this config to a recognizer.
 *
 * @param recognizer The target recognizer.
 * @param outError error information.
 */
- (BOOL)applyToRecognizer:(nonnull SPXRecognizer *)recognizer error:(NSError * _Nullable * _Nullable)outError;

@end
