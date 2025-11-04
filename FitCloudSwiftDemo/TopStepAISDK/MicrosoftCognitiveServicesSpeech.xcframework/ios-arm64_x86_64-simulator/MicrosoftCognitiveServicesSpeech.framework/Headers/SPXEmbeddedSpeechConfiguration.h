///
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechEnums.h"
#import "SPXSpeechRecognitionModelInfo.h"
#import "SPXSpeechTranslationModelInfo.h"

/**
 * Class that defines embedded (offline) speech configuration.
 */
SPX_EXPORT
@interface SPXEmbeddedSpeechConfiguration : NSObject

/**
 * The model name for speech recognition.
 */
@property (nonatomic, copy, nullable) NSString *speechRecognitionModelName;

/**
 * The speech recognition output format.
 */
@property (nonatomic) SPXOutputFormat speechRecognitionOutputFormat;

/**
 * The profanity option for speech recognition.
 */
@property (nonatomic) SPXSpeechConfigProfanityOption profanityOption;

/**
 * The voice name for embedded speech synthesis.
 */
@property (nonatomic, copy, nullable) NSString *speechSynthesisVoiceName;

/**
 * The model name for speech translation.
 */
@property (nonatomic, copy, nullable) NSString *speechTranslationModelName;

/**
 * Available speech recognition models.
 */
@property (nonatomic, copy, readonly, nonnull) NSArray<SPXSpeechRecognitionModelInfo *> *speechRecognitionModelsInfo;

/**
 * Available speech translation models.
 */
@property (nonatomic, copy, readonly, nonnull)NSArray<SPXSpeechTranslationModelInfo *> *speechTranslationModelsInfo;

/**
 * Creates an instance of the embedded speech config with a specified offline model path.
 *
 * @param path The folder path to search for offline models.
 * This can be a root path under which several models are located in subfolders,
 * or a direct path to a specific model folder.
 * @param outError The error information.
 * @return An instance of the embedded speech config.
 */
- (nullable instancetype)initFromPath:(nonnull NSString *)path error:(NSError * _Nullable * _Nullable)outError;

/**
 * Creates an instance of the embedded speech config with a specified offline model path.
 *
 * @param path The folder path to search for offline models.
 * This can be a root path under which several models are located in subfolders,
 * or a direct path to a specific model folder.
 * @return An instance of the embedded speech config.
 */
- (nullable instancetype)initFromPath:(nonnull NSString *)path
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Creates an instance of the embedded speech config with specified offline model paths.
 *
 * @param paths The folder paths to search for offline models.
 * These can be root paths under which several models are located in subfolders,
 * or direct paths to specific model folders.
 * @param outError The error information.
 * @return An instance of the embedded speech config.
 */
- (nullable instancetype)initFromPaths:(nonnull NSArray<NSString *> *)paths error:(NSError * _Nullable * _Nullable)outError;

/**
 * Creates an instance of the embedded speech config with specified offline model paths.
 *
 * @param paths The folder paths to search for offline models.
 * These can be root paths under which several models are located in subfolders,
 * or direct paths to specific model folders.
 * @return An instance of the embedded speech config.
 */
- (nullable instancetype)initFromPaths:(nonnull NSArray<NSString *> *)paths
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Get the speech synthesis output format.
 */
- (nonnull NSString *)speechSynthesisOutputFormat;

/**
 * Sets the speech synthesis output format (e.g. Riff16Khz16BitMonoPcm).
 *
 * @param format The speech synthesis output format.
 */
- (void)setSpeechSynthesisOutputFormat:(SPXSpeechSynthesisOutputFormat)format;

/**
 * Sets the model for speech recognition.
 *
 * @param name The model name.
 * @param key The model decryption key.
 */
- (void)setSpeechRecognitionModel:(nonnull NSString *)name key:(nonnull NSString *)key;
/**
 * Sets the voice for embedded speech synthesis.
 *
 * @param name The voice name of the embedded speech synthesis.
 * @param key The decryption key.
 */
- (void)setSpeechSynthesisVoice:(nonnull NSString *)name key:(nonnull NSString *)key;

/**
 * Sets the model for speech translation.
 *
 * @param name The model name.
 * @param key The model decryption key.
 */
- (void)setSpeechTranslationModel:(nonnull NSString *)name key:(nonnull NSString *)key;

/**
 * Returns the property value.
 * If the name is not available, it returns an empty string.
 *
 * @param name property name.
 * @return value of the property.
 */
-(nullable NSString *)getPropertyByName:(nonnull NSString *)name;

/**
 * Sets the property value by name.
 *
 * @param value value of the property.
 * @param name property name.
 */
-(void)setPropertyTo:(nonnull NSString *)value byName:(nonnull NSString *)name;

/**
 * Returns the property value.
 * If the specified id is not available, it returns an empty string.
 *
 * @param propertyId property id.
 * @return value of the property.
 */
-(nullable NSString *)getPropertyById:(SPXPropertyId)propertyId;

/**
 * Sets the property value by property id.
 *
 * @param value value of the property.
 * @param propertyId property id.
 */
-(void)setPropertyTo:(nonnull NSString *)value byId:(SPXPropertyId)propertyId;

@end

