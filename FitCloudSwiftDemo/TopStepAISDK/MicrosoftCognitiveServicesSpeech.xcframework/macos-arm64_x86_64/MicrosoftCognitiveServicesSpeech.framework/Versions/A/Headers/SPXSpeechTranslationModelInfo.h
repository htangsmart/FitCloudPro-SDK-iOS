///
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"

/**
 * Represents information about a speech translation model.
 */
SPX_EXPORT
@interface SPXSpeechTranslationModelInfo : NSObject

/**
 * The name of the speech translation model.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * The source languages supported by the model.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *sourceLanguages;

/**
 * The target languages supported by the model.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *targetLanguages;

/**
 * The path of the model (valid only for offline models).
 */
@property (nonatomic, readonly, nullable) NSString *path;

/**
 * The version of the speech translation model.
 */
@property (nonatomic, readonly, nonnull) NSString *version;

/**
 * Initializes a new instance of the SPXSpeechTranslationModelInfo class.
 *
 * @param name            The name of the model.
 * @param sourceLanguages The source languages supported by the model.
 * @param targetLanguages The target languages supported by the model.
 * @param path            The path of the model (valid only for offline models).
 * @param version         The version of the model.
 * @return An initialized SPXSpeechTranslationModelInfo instance.
 */
- (nullable instancetype)initWithName:(nonnull NSString *)name
            sourceLanguages:(nonnull NSArray<NSString *> *)sourceLanguages
            targetLanguages:(nonnull NSArray<NSString *> *)targetLanguages
                       path:(nullable NSString *)path
                    version:(nonnull NSString *)version;

@end
