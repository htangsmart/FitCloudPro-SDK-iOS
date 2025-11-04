//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"

/**
 * Speech recognition model information.
 */
SPX_EXPORT
@interface SPXSpeechRecognitionModelInfo : NSObject

/**
 * Model name.
 */
@property (nonatomic, copy, readonly, nullable) NSString *name;

/**
 * Locales of the model in BCP-47 format.
 */
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *locales;

/**
 * Model path (only valid for offline models).
 */
@property (nonatomic, copy, readonly, nullable) NSString *path;

/**
 * Model version.
 */
@property (nonatomic, copy, readonly, nullable) NSString *version;

/**
 * Initialize a new instance of SPXSpeechRecognitionModelInfo.
 *
 * @param name The model name.
 * @param locales The locales of the model in BCP-47 format.
 * @param path The model path (only valid for offline models).
 * @param version The model version.
 * @return A new instance of SPXSpeechRecognitionModelInfo.
 */
- (nullable instancetype)initWithName:(nonnull NSString *)name
                     locales:(nonnull NSArray<NSString *> *)locales
                        path:(nullable NSString *)path
                     version:(nonnull NSString *)version;

@end
