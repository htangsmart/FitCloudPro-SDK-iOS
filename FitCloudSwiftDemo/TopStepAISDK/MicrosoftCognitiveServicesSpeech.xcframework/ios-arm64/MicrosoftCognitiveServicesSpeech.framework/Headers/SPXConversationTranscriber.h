//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXSpeechConfiguration.h"
#import "SPXAudioConfiguration.h"
#import "SPXPropertyCollection.h"
#import "SPXRecognizer.h"
#import "SPXConversation.h"
#import "SPXConversationTranscriptionResult.h"
#import "SPXConversationTranscriptionEventArgs.h"

/**
 * Performs conversation transcribing for audio input streams, and gets transcribed text and user id as a result.
 */
SPX_EXPORT
@interface SPXConversationTranscriber : SPXRecognizer

typedef void (^SPXConversationTranscriptionEventHandler)(SPXConversationTranscriber * _Nonnull, SPXConversationTranscriptionEventArgs * _Nonnull);
typedef void (^SPXConversationTranscriptionCanceledEventHandler)(SPXConversationTranscriber * _Nonnull, SPXConversationTranscriptionCanceledEventArgs * _Nonnull);

/**
 * The authorization token used to communicate with the conversation transcription service.
 * Note: The caller needs to ensure that the authorization token is valid. Before the authorization token expires,
 * the caller needs to refresh it by calling this setter with a new valid token.
 * Otherwise, the recognizer will encounter errors during recognition.
 */
@property (nonatomic, copy, nullable)NSString *authorizationToken;

/**
 * Initializes a new instance of a conversation transcriber.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)init:(nonnull SPXSpeechConfiguration *)speechConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified audio config.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param audioConfiguration audio configuration.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified audio config.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of conversation transcriber using the specified source language.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param language source language.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration language:(nonnull NSString *)language
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified source language.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param language source language.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
                                            language:(nonnull NSString *)language
                                               error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of conversation transcriber using the specified source language and audio configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param language source language.
 * @param audioConfiguration audio configuration.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration 
                                            language:(nonnull NSString *)language
                                  audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified source language and audio configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param language source language.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
                                            language:(nonnull NSString *)language
                                  audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of conversation transcriber using the specified source language configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param sourceLanguageConfiguration the source language configuration.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
                         sourceLanguageConfiguration:(nonnull SPXSourceLanguageConfiguration *)sourceLanguageConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified source language configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param sourceLanguageConfiguration the source language configuration.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
                         sourceLanguageConfiguration:(nonnull SPXSourceLanguageConfiguration *)sourceLanguageConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of conversation transcriber using the specified source language configuration and audio configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param sourceLanguageConfiguration the source language configuration.
 * @param audioConfiguration audio configuration.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
                         sourceLanguageConfiguration:(nonnull SPXSourceLanguageConfiguration *)sourceLanguageConfiguration
                                  audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified source language configuration and audio configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param sourceLanguageConfiguration the source language configuration.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration 
                         sourceLanguageConfiguration:(nonnull SPXSourceLanguageConfiguration *)sourceLanguageConfiguration
                                  audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of conversation transcriber using the specified configuration for auto language detection.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @return a conversation transcriber instance..
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified configuration for auto language detection.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of conversation transcriber using the specified configuration for auto language detection and audio configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @param audioConfiguration audio configuration.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
                                  audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of conversation transcriber using the specified configuration for auto language detection and audio configuration.
 *
 * @param speechConfiguration speech configuration for conversation transcription.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return a conversation transcriber instance.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
                                  audioConfiguration:(nonnull SPXAudioConfiguration *)audioConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;
/**
 * Starts conversation transcribing on a continuous audio stream, until stopTranscribingAsync() is called.
 * User must subscribe to events to receive transcription results.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)startTranscribingAsync:(nonnull void (^)(BOOL started, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Starts conversation transcribing on a continuous audio stream, until stopTranscribingAsync() is called.
 * User must subscribe to events to receive transcription results.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)startTranscribingAsync:(nonnull void (^)(BOOL started, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Stops conversation transcribing.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)stopTranscribingAsync:(nonnull void (^)(BOOL stopped, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Stops conversation transcribing.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)stopTranscribingAsync:(nonnull void (^)(BOOL stopped, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Subscribes to the Transcribed event which indicates that a final result has been transcribed.
 */
- (void)addTranscribedEventHandler:(nonnull SPXConversationTranscriptionEventHandler)eventHandler;

/**
 * Subscribes to the Transcribing event which indicates an that intermediate result has been transcribed.
 */
- (void)addTranscribingEventHandler:(nonnull SPXConversationTranscriptionEventHandler)eventHandler;

/**
 * Subscribes to the Canceled event which indicates that an error occurred during transcription.
 */
- (void)addCanceledEventHandler:(nonnull SPXConversationTranscriptionCanceledEventHandler)eventHandler;

@end
