//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXAudioConfiguration.h"
#import "SPXSpeechConfiguration.h"
#import "SPXSpeechSynthesisResult.h"
#import "SPXSpeechSynthesisEventArgs.h"
#import "SPXSynthesisVoicesResult.h"
#import "SPXEmbeddedSpeechConfiguration.h"

/**
 * Performs speech synthesis from a text to a specified audio output.
 *
 * Updated in version 1.16.0
 */
SPX_EXPORT
@interface SPXSpeechSynthesizer : NSObject

typedef void (^SPXSpeechSynthesisEventHandler)(SPXSpeechSynthesizer * _Nonnull, SPXSpeechSynthesisEventArgs * _Nonnull);
typedef void (^SPXSpeechSynthesisWordBoundaryEventHandler)(SPXSpeechSynthesizer * _Nonnull, SPXSpeechSynthesisWordBoundaryEventArgs * _Nonnull);
typedef void (^SPXSpeechSynthesisVisemeEventHandler)(SPXSpeechSynthesizer * _Nonnull, SPXSpeechSynthesisVisemeEventArgs * _Nonnull);
typedef void (^SPXSpeechSynthesisBookmarkEventHandler)(SPXSpeechSynthesizer * _Nonnull, SPXSpeechSynthesisBookmarkEventArgs * _Nonnull);

/**
  * The collection of properties and their values defined for this SPXSpeechSynthesizer.
  */
@property (readonly, nullable)id <SPXPropertyCollection> properties;

/**
 * Authorization token used to communicate with the speech synthesis service.
 *
 * Note: The caller needs to ensure that the authorization token is valid. Before the authorization token expires,
 * the caller needs to refresh it by calling this setter with a new valid token.
 * Otherwise, the synthesizer will encounter errors during speech synthesis.
 */
@property (nonatomic, copy, nullable)NSString *authorizationToken;

/**
 * Initializes a new instance of speech synthesizer using a speech config.
 * This synthesizer will output the audio to default speaker, which will throw an exception if the speaker is not available.
 * Please use initWithSpeechConfiguration(speechConfiguration, nil) if you just need the SPXSynthesisResult or SPXAudioDataStream.
 *
 * @param speechConfiguration speech configuration.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)init:(nonnull SPXSpeechConfiguration *)speechConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of speech synthesizer using a speech config.
 * This synthesizer will output the audio to default speaker, which will throw an exception if the speaker is not available.
 * Please use initWithSpeechConfiguration(speechConfiguration, nil) if you just need the SPXSynthesisResult or SPXAudioDataStream.
 *
 * @param speechConfiguration speech configuration.
 * @param outError error information.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)init:(nonnull SPXSpeechConfiguration *)speechConfiguration error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of speech synthesizer using a speech config and audio config.
 *
 * @param speechConfiguration speech configuration.
 * @param audioConfiguration audio configuration.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration audioConfiguration:(nullable SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of speech synthesizer using a speech config and audio config.
 *
 * @param speechConfiguration speech configuration.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration audioConfiguration:(nullable SPXAudioConfiguration *)audioConfiguration error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of speech synthesizer using a embedded speech config.
 * This synthesizer will output the audio to default speaker, which will throw an exception if the speaker is not available.
 * Please use initWithEmbeddedSpeechConfiguration(speechConfiguration, nil) if you just need the SPXSynthesisResult or SPXAudioDataStream.
 *
 * @param speechConfiguration embedded speech configuration.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithEmbeddedSpeechConfiguration:(nonnull SPXEmbeddedSpeechConfiguration *)speechConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of speech synthesizer using a embedded speech config.
 * This synthesizer will output the audio to default speaker, which will throw an exception if the speaker is not available.
 * Please use initWithEmbeddedSpeechConfiguration(speechConfiguration, nil) if you just need the SPXSynthesisResult or SPXAudioDataStream.
 *
 * @param speechConfiguration embedded speech configuration.
 * @param outError error information.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithEmbeddedSpeechConfiguration:(nonnull SPXEmbeddedSpeechConfiguration *)speechConfiguration error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of speech synthesizer using a embedded speech config and audio config.
 *
 * @param speechConfiguration embedded speech configuration.
 * @param audioConfiguration audio configuration.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithEmbeddedSpeechConfiguration:(nonnull SPXEmbeddedSpeechConfiguration *)speechConfiguration audioConfiguration:(nullable SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of speech synthesizer using a embedded speech config and audio config.
 *
 * @param speechConfiguration embedded speech configuration.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithEmbeddedSpeechConfiguration:(nonnull SPXEmbeddedSpeechConfiguration *)speechConfiguration audioConfiguration:(nullable SPXAudioConfiguration *)audioConfiguration error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of speech synthesizer using the specified configuration for auto language detection.
 *
 * Added in version 1.13.0.

 * @param speechConfiguration speech recognition configuration.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @return an instance of speech synthesizer
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of speech synthesizer using the specified configuration for auto language detection.
 *
 * Added in version 1.13.0.

 * @param speechConfiguration speech recognition configuration.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @param outError error information.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a new instance of speech synthesizer using the specified configuration for auto language detection and audio configuration.
 *
 * Added in version 1.13.0.

 * @param speechConfiguration speech recognition configuration.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @param audioConfiguration audio configuration.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
                                  audioConfiguration:(nullable SPXAudioConfiguration *)audioConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of speech synthesizer using the specified configuration for auto language detection and audio configuration.
 *
 * Added in version 1.13.0.

 * @param speechConfiguration speech recognition configuration.
 * @param autoDetectSourceLanguageConfiguration the configuration for auto language detection.
 * @param audioConfiguration audio configuration.
 * @param outError error information.
 * @return an instance of speech synthesizer.
 */
- (nullable instancetype)initWithSpeechConfiguration:(nonnull SPXSpeechConfiguration *)speechConfiguration
               autoDetectSourceLanguageConfiguration:(nonnull SPXAutoDetectSourceLanguageConfiguration *)autoDetectSourceLanguageConfiguration
                                  audioConfiguration:(nullable SPXAudioConfiguration *)audioConfiguration
                                               error:(NSError * _Nullable * _Nullable)outError;


/**
 * Execute the speech synthesis on plain text.
 *
 * @param text the plain text for synthesis.
 * @return the result of speech synthesis.
 */
- (nonnull SPXSpeechSynthesisResult *)speakText:(nonnull NSString*)text NS_RETURNS_RETAINED
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Execute the speech synthesis on plain text.
 *
 * @param text the plain text for synthesis.
 * @param outError error information.
 * @return the result of speech synthesis.
 */
- (nullable SPXSpeechSynthesisResult *)speakText:(nonnull NSString*)text error:(NSError * _Nullable * _Nullable)outError NS_RETURNS_RETAINED;

/**
 * Execute the speech synthesis on SSML.
 *
 * @param ssml the SSML for synthesis.
 * @return the result of speech synthesis.
 */
- (nonnull SPXSpeechSynthesisResult *)speakSsml:(nonnull NSString*)ssml NS_RETURNS_RETAINED
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Execute the speech synthesis on SSML.
 *
 * @param ssml the SSML for synthesis.
 * @param outError error information.
 * @return the result of speech synthesis.
 */
- (nullable SPXSpeechSynthesisResult *)speakSsml:(nonnull NSString*)ssml error:(NSError * _Nullable * _Nullable)outError NS_RETURNS_RETAINED;

/**
 * Start the speech synthesis on plain text.
 *
 * @param text the plain the for synthesis.
 * @return the result of speech synthesis.
 */
- (nonnull SPXSpeechSynthesisResult *)startSpeakingText:(nonnull NSString*)text NS_RETURNS_RETAINED
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Start the speech synthesis on plain text.
 *
 * @param text the plain text for synthesis.
 * @param outError error information.
 * @return the result of speech synthesis.
 */
- (nullable SPXSpeechSynthesisResult *)startSpeakingText:(nonnull NSString*)text error:(NSError * _Nullable * _Nullable)outError NS_RETURNS_RETAINED;

/**
 * Start the speech synthesis on SSML.
 *
 * @param ssml the SSML for synthesis.
 * @return the result of speech synthesis.
 */
- (nonnull SPXSpeechSynthesisResult *)startSpeakingSsml:(nonnull NSString*)ssml NS_RETURNS_RETAINED
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Start the speech synthesis on SSML.
 *
 * @param ssml the SSML for synthesis.
 * @param outError error information.
 * @return the result of speech synthesis.
 */
- (nullable SPXSpeechSynthesisResult *)startSpeakingSsml:(nonnull NSString*)ssml error:(NSError * _Nullable * _Nullable)outError NS_RETURNS_RETAINED;

/**
 * Stops synthesis.
 * This method will stop the playback and clear the unread data in SPXPullAudioOutputStream
 *
 * Added in version 1.14.0
 */
- (void)stopSpeaking
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Stops synthesis.
 * This method will stop the playback and clear the unread data in SPXPullAudioOutputStream
 *
 * Added in version 1.14.0
 *
 * @param outError error information.
 */
- (BOOL)stopSpeaking:(NSError * _Nullable * _Nullable)outError;

/**
 * Get the available voices.
 *
 * Added in version 1.16.0
 *
 * @param locale Specify the locale of voices, in BCP-47 format; or leave it empty to get all available voices.
 * @return the result of voices retrieved.
 */
- (nonnull SPXSynthesisVoicesResult *)getVoicesWithLocale:(nonnull NSString*)locale NS_RETURNS_RETAINED
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Get the available voices.
 *
 * Added in version 1.16.0
 *
 * @param locale Specify the locale of voices, in BCP-47 format; or leave it empty to get all available voices.
 * @param outError error information.
 * @return the result of voices retrieved.
 */
- (nullable SPXSynthesisVoicesResult *)getVoicesWithLocale:(nonnull NSString*)locale error:(NSError * _Nullable * _Nullable)outError NS_RETURNS_RETAINED;

/**
 * Get the available voices in all locales.
 *
 * Added in version 1.16.0
 *
 * @return the result of voices retrieved.
 */
- (nonnull SPXSynthesisVoicesResult *)getVoices NS_RETURNS_RETAINED
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Get the available voices in all locales.
 *
 * Added in version 1.16.0
 *
 * @param outError error information.
 * @return the result of voices retrieved.
 */
- (nullable SPXSynthesisVoicesResult *)getVoices:(NSError * _Nullable * _Nullable)outError NS_RETURNS_RETAINED;

/**
 * Subscribes to the SynthesisStarted event which indicates that the synthesis just started.
 */
- (void)addSynthesisStartedEventHandler:(nonnull SPXSpeechSynthesisEventHandler)eventHandler;

/**
 * Subscribes to the Synthesizing event which indicates that the synthesis is on going.
 */
- (void)addSynthesizingEventHandler:(nonnull SPXSpeechSynthesisEventHandler)eventHandler;

/**
 * Subscribes to the SynthesisCompleted event which indicates that the synthesis completed.
 */
- (void)addSynthesisCompletedEventHandler:(nonnull SPXSpeechSynthesisEventHandler)eventHandler;

/**
 * Subscribes to the SynthesisCanceled event which indicates that the synthesis is canceled.
 */
- (void)addSynthesisCanceledEventHandler:(nonnull SPXSpeechSynthesisEventHandler)eventHandler;

/**
 * Subscribes to the SynthesisWordBoundary event which indicates that a word boundary is received.
 */
- (void)addSynthesisWordBoundaryEventHandler:(nonnull SPXSpeechSynthesisWordBoundaryEventHandler)eventHandler;

/**
 * Subscribes to the VisemeReceived event which indicates that a viseme is received.
 */
- (void)addVisemeReceivedEventHandler:(nonnull SPXSpeechSynthesisVisemeEventHandler)eventHandler;

/**
 * Subscribes to the BookmarkReached event which indicates that a bookmark is reached.
 */
- (void)addBookmarkReachedEventHandler:(nonnull SPXSpeechSynthesisBookmarkEventHandler)eventHandler;

@end
