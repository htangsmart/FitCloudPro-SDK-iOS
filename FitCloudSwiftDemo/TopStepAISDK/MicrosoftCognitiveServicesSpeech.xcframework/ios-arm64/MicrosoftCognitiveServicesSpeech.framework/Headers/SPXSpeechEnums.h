//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

/**
 * Defines property ids.
 *
 * Changed in version 1.4.0
 */
typedef NS_ENUM(NSUInteger, SPXPropertyId)
{

    /**
     * The Cognitive Services Speech Service subscription key. If you are using an intent recognizer, you need
     * to specify the LUIS endpoint key for your particular LUIS app. Under normal circumstances, you shouldn't
     * have to use this property directly.
     * Instead, use SPXSpeechConfiguration.initWithSubscription.
     */
    SPXSpeechServiceConnectionKey = 1000,

    /**
     * The Cognitive Services Speech Service endpoint (url). Under normal circumstances, you shouldn't
     * have to use this property directly.
     * Instead, use SPXSpeechConfiguration.initWithEndpoint.
     *
     * NOTE: This endpoint is not the same as the endpoint used to obtain an access token.
     */
    SPXSpeechServiceConnectionEndpoint = 1001,

    /**
     * The Cognitive Services Speech Service region. Under normal circumstances, you shouldn't have to
     * use this property directly.
     * Instead, use SPXSpeechConfiguration.initWithEndpoint, SPXSpeechConfiguration.initWithHost, or
     * SPXSpeechConfiguration.initWithAuthorizationToken.
     */
    SPXSpeechServiceConnectionRegion = 1002,

    /**
     * The Cognitive Services Speech Service authorization token (aka access token). Under normal circumstances,
     * you shouldn't have to use this property directly.
     * Instead, use SPXSpeechConfiguration.initWithAuthorizationToken,
     * SPXSpeechRecognizer.authorizationToken, SPXIntentRecognizer.authorizationToken,
     * SPXTranslationRecognizer.authorizationToken.
     */
    SPXSpeechServiceAuthorizationToken = 1003,

    /**
     * The Cognitive Services Speech Service authorization type. Currently unused.
     */
    SPXSpeechServiceAuthorizationType = 1004,

    /**
     * The Cognitive Services Custom Speech or Custom Voice Service endpoint id.
     *
     * NOTE: The endpoint id is available in the Custom Speech Portal, listed under Endpoint Details.
     */
    SPXSpeechServiceConnectionEndpointId = 1005,

    /**
     * The Cognitive Services Speech Service host (url). Under normal circumstances, you shouldn't
     * have to use this property directly.
     * Instead, use SPXSpeechConfiguration.initWithHost.
     */
    SPXSpeechServiceConnectionHost = 1006,

    /**
     * The host name of the proxy server. Not implemented yet.
     *
     * NOTE: Added in version 1.1.0.
     */
    SPXSpeechServiceConnectionProxyHostName = 1100,

    /**
     * The port of the proxy server. Not implemented yet.
     *
     * NOTE: Added in version 1.1.0.
     */
    SPXSpeechServiceConnectionProxyPort = 1101,

    /**
     * The user name of the proxy server. Not implemented yet.
     *
     * NOTE: Added in version 1.1.0.
     */
    SPXSpeechServiceConnectionProxyUserName = 1102,

    /**
     * The password of the proxy server. Not implemented yet.
     *
     * NOTE: Added in version 1.1.0.
     */
    SPXSpeechServiceConnectionProxyPassword = 1103,

    /**
     * The URL string built from speech configuration.
     * This property is intended to be read-only. The SDK is using it internally.
     *
     * NOTE: Added in version 1.5.0.
     */
    SPXSpeechServiceConnectionUrl = 1104,

    /**
     * The list of comma separated languages (BCP-47 format) used as target translation languages. Under normal circumstances,
     * you shouldn't have to use this property directly.
     * Instead use SPXSpeechTranslationConfiguration.addTargetLanguage
     * and the read-only SPXSpeechTranslationConfiguration.targetLanguages and SPXTranslationRecognizer.targetLanguages
     * collections.
     */
    SPXSpeechServiceConnectionTranslationToLanguages = 2000,

    /**
     * The name of the Cognitive Service Text to Speech Service voice. Under normal circumstances, you shouldn't have to use this
     * property directly.
     * Instead use SPXSpeechTranslationConfiguration.voiceName.
     *
     * NOTE: Valid voice names can be found <a href="https://aka.ms/csspeech/voicenames">here</a>.
     */
    SPXSpeechServiceConnectionTranslationVoice = 2001,

    /**
     * Translation features. For internal use.
     */
    SPXSpeechServiceConnectionTranslationFeatures = 2002,

    /**
     * The Language Understanding Service region. Under normal circumstances, you shouldn't have to use this property directly.
     * Instead use SPXLanguageUnderstandingModel.
     */
    SPXSpeechServiceConnectionIntentRegion = 2003,

    /**
     * The Cognitive Services Speech Service recognition mode. Can be "INTERACTIVE", "CONVERSATION", "DICTATION".
     * This property is intended to be read-only. The SDK is using it internally.
     */
    SPXSpeechServiceConnectionRecognitionMode = 3000,

    /**
     * The spoken language to be recognized (in BCP-47 format).
     */
    SPXSpeechServiceConnectionRecognitionLanguage = 3001,

    /**
     * The session id. This id is a universally unique identifier (aka UUID) representing a specific binding of an audio input stream
     * and the underlying speech recognition instance to which it is bound. Under normal circumstances, you shouldn't have to use this
     * property directly.
     * Instead, use SPXSessionEventArgs.sessionId.
     */
    SPXSpeechSessionId = 3002,

    /**
     * The spoken language to be synthesized (e.g. en-US)
     */
    SPXSpeechServiceConnectionSynthesisLanguage = 3100,

    /**
     * The name of the voice to be used for speech synthesis
     */
    SPXSpeechServiceConnectionSynthesisVocie = 3101,

    /**
     * The string to specify speech synthesis output audio format (e.g. riff-16khz-16bit-mono-pcm)
     */
    SPXSpeechServiceConnectionSynthesisOutputFormat = 3102,

    /**
     * Indicates if use compressed audio format for speech synthesis audio transmission.
     * This property only affects when SpeechServiceConnection_SynthOutputFormat is set to a pcm format.
     * If this property is not set and GStreamer is available, SDK will use compressed format for synthesized audio transmission,
     * and decode it. You can set this property to "false" to use raw pcm format for transmission on wire.
     * Added in version 1.16.0
     */
    SPXSpeechServiceConnectionSynthesisEnableCompressedAudioTransmission = 3103,

    /**
     * The string to specify TTS backend; valid options are online and offline.
     * Under normal circumstances, you shouldn't have to use this property directly.
     * Instead, use SPXEmbeddedSpeechConfig.initWithPath or SPXEmbeddedSpeechConfig.initWithPaths
     * to set the synthesis backend to offline.
     * Added in version 1.19.0
     */
    SPXSpeechServiceConnectionSynthBackend = 3110,

    /**
     * The data file path(s) for offline synthesis engine; only valid when synthesis backend is offline.
     * Under normal circumstances, you shouldn't have to use this property directly.
     * Instead, use SPXEmbeddedSpeechConfig.initWithPath or SPXEmbeddedSpeechConfig.initWithPaths
     * Added in version 1.19.0
     */
    SPXSpeechServiceConnectionSynthOfflineDataPath = 3112,

    /**
     * The name of the offline TTS voice to be used for speech synthesis.
     * Added in version 1.19.0
     */
    SPXSpeechServiceConnectionSynthOfflineVoice = 3113,

    /**
     * The Cognitive Services Speech Service voices list api endpoint (url). Under normal circumstances,
     * you don't need to specify this property, SDK will construct it based on the region/host/endpoint of SPXSpeechConfig.
     * Added in version 1.16.0
     */
    SPXSpeechServiceConnectionVoicesListEndpoint = 3130,

    /**
     * The initial silence timeout value (in milliseconds) used by the service.
     * Added in version 1.5.0
     */
    SPXSpeechServiceConnectionInitialSilenceTimeoutMs = 3200,

    /**
     * The end silence timeout value (in milliseconds) used by the service.
     * Added in version 1.5.0
     */
    SPXSpeechServiceConnectionEndSilenceTimeoutMs = 3201,

    /**
     * A boolean value specifying whether audio logging is enabled in the service or not.
     * Audio and content logs are stored either in Microsoft-owned storage, or in your own storage account linked
     * to your Cognitive Services subscription (Bring Your Own Storage (BYOS) enabled Speech resource).
     * Added in version 1.5.0
     */
    SPXSpeechServiceConnectionEnableAudioLogging = 3202,

    /**
     * The speech service connection language identifier mode.
     * Can be "AtStart" (the default), or "Continuous". See Language
     * Identification document https://aka.ms/speech/lid?pivots=programming-language-objectivec
     * for more details.
     * Added in 1.25.0
     */
    SPXSpeechServiceConnectionLanguageIdMode = 3205,

    /**
     * The source language candidates used for auto language detection
     * Added in version 1.12.0
     */
    SPXSpeechServiceConnectionAutoDetectSourceLanguages = 3300,

    /**
     * The auto language detection result
     * Added in version 1.12.0
     */
    SPXSpeechServiceConnectionAutoDetectSourceLanguageResult = 3301,

    /**
     * The requested Cognitive Services Speech Service response output format (simple or detailed). Not implemented yet.
     */
    SPXSpeechServiceResponseRequestDetailedResultTrueFalse = 4000,

    /**
     * The requested Cognitive Services Speech Service response output profanity level. Currently unused.
     */
    SPXSpeechServiceResponseRequestProfanityFilterTrueFalse = 4001,

    /**
     * The requested Cognitive Services Speech Service response output profanity setting.
     * Allowed values are "masked", "removed", and "raw".
     * Added in version 1.5.0.
     */
    SPXSpeechServiceResponseProfanityOption = 4002,

    /**
     * A string value specifying which post processing option should be used by service.
     * Allowed values are "TrueText".
     * Added in version 1.5.0
     */
    SPXSpeechServiceResponsePostProcessingOption = 4003,

    /**
     * A boolean value specifying whether to include word-level timestamps in the response result.
     * Added in version 1.5.0
     */
    SPXSpeechServiceResponseRequestWordLevelTimestamps = 4004,

    /**
     * The number of times a word has to be in partial results to be returned.
     * Added in version 1.5.0
     */
    SPXSpeechServiceResponseStablePartialResultThreshold = 4005,

    /**
     * A string value specifying the output format option in the response result. Internal use only.
     * Added in version 1.5.0.
     */
    SPXSpeechServiceResponseOutputFormatOption = 4006,

    /**
     * A boolean value specifying whether to include SNR (signal to noise ratio) in the response result.
     * Added in version 1.18.0.
     */
    SPXSpeechServiceResponseRequestSnr = 4007,

    /**
     * A boolean value to request for stabilizing translation partial results by omitting words in the end.
     * Added in version 1.5.0.
     */
    SPXSpeechServiceResponseTranslationRequestStablePartialResult = 4100,

    /**
     * A boolean value specifying whether to request WordBoundary events.
     * Added in version 1.21.0.
     */
   SPXSpeechServiceResponseRequestWordBoundary = 4200,

    /**
     * A boolean value specifying whether to request punctuation boundary in WordBoundary Events. Default is true.
     * Added in version 1.21.0.
     */
    SPXSpeechServiceResponseRequestPunctuationBoundary = 4201,

    /**
     * A boolean value specifying whether to request sentence boundary in WordBoundary Events. Default is false.
     * Added in version 1.21.0.
     */
    SPXSpeechServiceResponseRequestSentenceBoundary = 4202,

    /**
     * A boolean value specifying whether the SDK should synchronize synthesis metadata events,
     * (e.g. word boundary, viseme, etc.) to the audio playback. This only takes effect when the audio is played through the SDK.
     * Default is true.
     * If set to false, the SDK will fire the events as they come from the service, which may be out of sync with the audio playback.
     * Added in version 1.31.0.
     */
    SPXSpeechServiceResponseSynthesisEventsSyncToAudio = 4210,

    /**
     * The Cognitive Services Speech Service response output (in JSON format). This property is available on recognition result objects only.
     */
    SPXSpeechServiceResponseJsonResult = 5000,

    /**
     * The Cognitive Services Speech Service error details (in JSON format). Under normal circumstances, you shouldn't have to
     * use this property directly.
     * Instead, use SPXCancellationDetails.errorDetails.
     */
    SPXSpeechServiceResponseJsonErrorDetails = 5001,

    /**
     * The recognition latency in milliseconds. Read-only, available on final speech/translation/intent results.
     * This measures the latency between when an audio input is received by the SDK, and the moment the final result is received from the service.
     * The SDK computes the time difference between the last audio fragment from the audio input that is contributing to the final result, and the time the final result is received from the speech service.
     * Added in version 1.3.0.
     */
    SPXSpeechServiceResponseRecognitionLatencyMs = 5002,

    /**
     * The speech synthesis first byte latency in milliseconds. Read-only, available on final speech synthesis results.
     * This measures the latency between when the synthesis is started to be processed, and the moment the first byte audio is available.
     * Added in version 1.17.0.
     */
    SPXSpeechServiceResponseSynthesisFirstByteLatencyMs = 5010,

    /**
     * The speech synthesis all bytes latency in milliseconds. Read-only, available on final speech synthesis results.
     * This measures the latency between when the synthesis is started to be processed, and the moment the whole audio is synthesized.
     * Added in version 1.17.0.
     */
    SPXSpeechServiceResponseSynthesisFinishLatencyMs = 5011,

    /**
     * The underrun time for speech synthesis in milliseconds. Read-only, available on results in SynthesisCompleted events.
     * This measures the total underrun time from SPXAudioConfigPlaybackBufferLengthInMs is filled to synthesis completed.
     * Added in version 1.17.0.
     */
    SPXSpeechServiceResponseSynthesisUnderrunTimeMs = 5012,

    /**
     * The speech synthesis connection latency in milliseconds. Read-only, available on final speech synthesis results.
     * This measures the latency between when the synthesis is started to be processed, and the moment the HTTP/WebSocket connection is established.
     * Added in version 1.26.0
     */
    SPXSpeechServiceResponseSynthesisConnectionLatencyMs = 5013,

    /**
     * The speech synthesis network latency in milliseconds. Read-only, available on final speech synthesis results.
     * This measures the network round trip time.
     * Added in version 1.26.0
     */
    SPXSpeechServiceResponseSynthesisNetworkLatencyMs = 5014,

    /**
     * The speech synthesis service latency in milliseconds. Read-only, available on final speech synthesis results.
     * This measures the service processing time to synthesize the first byte of audio.
     * Added in version 1.26.0
     */
    SPXSpeechServiceResponseSynthesisServiceLatencyMs = 5015,

    /**
     * Indicates which backend the synthesis is finished by.
     * Read-only, available on speech synthesis results, except for the result in SynthesisStarted event.
     * Added in version 1.17.0.
     */
    SPXSpeechServiceResponseSynthesisBackend = 5020,

    /**
     * The cancellation reason. Currently unused.
     */
    SPXCancellationDetailsReason = 6000,

    /**
     * The cancellation text. Currently unused.
     */
    SPXCancellationDetailsReasonText = 6001,

    /**
     * The cancellation detailed text. Currently unused.
     */
    SPXCancellationDetailsReasonDetailedText = 6002,

    /**
     * The Language Understanding Service response output (in JSON format). Available via IntentRecognitionResult.Properties.
     */
    SPXLanguageUnderstandingServiceResponseJsonResult = 7000,

    /**
     * The device name for audio render. Under normal circumstances, you shouldn't have to
     * use this property directly.
     * Instead, use SPXAudioConfiguration.initWithSpeakerOutput.
     * Added in version 1.17.0
     */
    SPXAudioConfigDeviceNameForRender = 8005,

    /**
     * Playback buffer length in milliseconds, default is 50 milliseconds.
     * Added in version 1.17.0.
     */
    SPXAudioConfigPlaybackBufferLengthInMs = 8006,

    /**
     * The file name to write logs.
     *
     * NOTE: Added in version 1.4.0.
     */
    SPXSpeechLogFilename = 9001,

    /**
     * A duration of detected silence, measured in milliseconds, after which speech-to-text will determine a spoken
     * phrase has ended and generate a final Recognized result. Configuring this timeout may be helpful in situations
     * where spoken input is significantly faster or slower than usual and default segmentation behavior consistently
     * yields results that are too long or too short. Segmentation timeout values that are inappropriately high or low
     * can negatively affect speech-to-text accuracy; this property should be carefully configured and the resulting
     * behavior should be thoroughly validated as intended.
     *
     * For more information about timeout configuration that includes discussion of default behaviors, please visit
     * https://aka.ms/csspeech/timeouts.
     */
     SPXSpeechSegmentationSilenceTimeoutMs = 9002,

    /**
     * The timestamp associated to data buffer written by client when using Pull/Push audio mode streams.
     * The timestamp is a 64-bit value with resolution of 90kHz. The same as the presentation timestamp in
     * MPEG transfrom stream.
     * See https://en.wikipedia.org/wiki/Presentation_timestamp.
     * NOTE: Added in version 1.13.0.
     */
    SPXDataBuffer_TimeStamp = 11001,

    /**
     * The user id associated to data buffer written by client when using Pull/Push audio mode streams.
     *
     * NOTE: Added in version 1.13.0.
     */
    SPXDataBuffer_UserId = 11002,

    /**
     * The reference text of the audio for pronunciation evaluation.
     * For this and the following pronunciation assessment parameters, see the table
     * [Pronunciation assessment parameters](/azure/cognitive-services/speech-service/rest-speech-to-text-short#pronunciation-assessment-parameters).
     * Under normal circumstances, you shouldn't have to use this property directly.
     *
     * NOTE: Added in version 1.14.0
     */
    SPXPronunciationAssessment_ReferenceText = 12001,

    /**
     * The point system for pronunciation score calibration (FivePoint or HundredMark).
     * Under normal circumstances, you shouldn't have to use this property directly.
     *
     * NOTE: Added in version 1.14.0
     */
    SPXPronunciationAssessment_GradingSystem = 12002,

    /**
     * The pronunciation evaluation granularity (Phoneme, Word, or FullText).
     * Under normal circumstances, you shouldn't have to use this property directly.
     *
     * NOTE: Added in version 1.14.0
     */
    SPXPronunciationAssessment_Granularity = 12003,

    /**
     * Defines if enable miscue calculation.
     * With this enabled, the pronounced words will be compared to the reference text,
     * and will be marked with omission/insertion based on the comparison. The default setting is False.
     * Under normal circumstances, you shouldn't have to use this property directly.
     *
     * NOTE: Added in version 1.14.0
     */
    SPXPronunciationAssessment_EnableMiscue = 12005,

    /**
     * The pronunciation evaluation phoneme alphabet. The valid values are "SAPI" (default) and "IPA"
     * Under normal circumstances, you shouldn't have to use this property directly.
     * Instead, use SPXPronunciationAssessmentConfiguration.phonemeAlphabet.
     *
     * NOTE: Added in version 1.20.0
     */
    SPXPronunciationAssessment_PhonemeAlphabet = 12006,

    /**
     * The pronunciation evaluation nbest phoneme count.
     * Under normal circumstances, you shouldn't have to use this property directly.
     * Instead, use SPXPronunciationAssessmentConfiguration.nbestPhonemeCount.
     *
     * NOTE: Added in version 1.20.0
     */
    SPXPronunciationAssessment_NBestPhonemeCount = 12007,

    /**
     * Whether to enable prosoody assessment.
     * Under normal circumstances, you shouldn't have to use this property directly.
     * Instead, use SPXPronunciationAssessmentConfiguration.enableProsodyAssessment.
     *
     * NOTE: Added in version 1.33.0
     */
    SPXPronunciationAssessment_EnableProsodyAssessment = 12008,

    /**
     * The json string of pronunciation assessment parameters
     * Under normal circumstances, you shouldn't have to use this property directly.
     *
     * NOTE: Added in version 1.14.0
     */
    SPXPronunciationAssessment_Json = 12009,

    /**
     * Pronunciation assessment parameters.
     * This property is intended to be read-only. The SDK is using it internally.
     *
     * NOTE: Added in version 1.14.0
     */
    SPXPronunciationAssessment_Params = 12010,

    /**
     * The content topic of the pronunciation assessment.
     * Under normal circumstances, you shouldn't have to use this property directly.
     * Instead, use SPXPronunciationAssessmentConfiguration.enableContentAssessmentWithTopic.
     *
     * NOTE: Added in version 1.33.0
     */
    SPXPronunciationAssessment_ContentTopic = 12020,
};

/**
  * Defines possible values of output format.
  */
typedef NS_ENUM(NSUInteger, SPXOutputFormat)
{
    /**
     * Simple output format.
     */
    SPXOutputFormat_Simple = 0,

    /**
     * Detailed output format.
     */
    SPXOutputFormat_Detailed = 1
};

/**
  * Specifies the possible reasons a recognition result might be generated.
  */
typedef NS_ENUM(NSUInteger, SPXResultReason)
{
    /**
     * Indicates speech could not be recognized. More details can be found in the SPXNoMatchDetails object.
     */
    SPXResultReason_NoMatch = 0,

    /**
     * Indicates that the recognition was canceled. More details can be found using the SPXCancellationDetails object.
     */
    SPXResultReason_Canceled = 1,

    /**
     * Indicates the speech result contains hypothesis text as an intermediate result.
     */
    SPXResultReason_RecognizingSpeech = 2,

    /**
     * Indicates the speech result contains final text that has been recognized.
     * Speech recognition is now complete for this phrase.
     */
    SPXResultReason_RecognizedSpeech = 3,

    /**
     * Indicates the intent result contains hypothesis text as an intermediate result.
     */
    SPXResultReason_RecognizingIntent = 4,

    /**
     * Indicates the intent result contains final text and intent.
     * Speech recognition and intent determination are now complete for this phrase.
     */
    SPXResultReason_RecognizedIntent = 5,

    /**
     * Indicates the translation result contains hypothesis text and translation(s) as an intermediate result.
     */
    SPXResultReason_TranslatingSpeech = 6,

    /**
     * Indicates the translation result contains final text and corresponding translation(s).
     * Speech recognition and translation are now complete for this phrase.
     */
    SPXResultReason_TranslatedSpeech = 7,

    /**
     * Indicates the synthesized audio result contains a non-zero amount of audio data
     */
    SPXResultReason_SynthesizingAudio = 8,

    /**
     * Indicates the synthesized audio is now complete for this phrase.
     */
    SPXResultReason_SynthesizingAudioCompleted = 9,

    /**
     * Indicates the speech result contains (unverified) keyword text.
     */
    SPXResultReason_RecognizingKeyword = 10,

    /**
     * Indicates that keyword recognition completed recognizing the given keyword.
     */
    SPXResultReason_RecognizedKeyword = 11,

    /**
     * Indicates the speech synthesis is now started.
     */
    SPXResultReason_SynthesizingAudioStarted = 12,

    /**
     * Indicates the voices list has been retrieved successfully.
     * Added in version 1.16.0
     */
    SPXResultReason_VoicesListRetrieved = 23,
};

/**
  * Defines the possible reasons a recognition result might be canceled.
  */
typedef NS_ENUM(NSUInteger, SPXCancellationReason)
{
    /**
     * Indicates that an error occurred during speech recognition.
     */
    SPXCancellationReason_Error = 1,

    /**
     * Indicates that the end of the audio stream was reached.
     */
    SPXCancellationReason_EndOfStream = 2,

    /**
     * Indicates that request was cancelled by the user.
     * Added in version 1.14.0
     */
    SPXCancellationReason_CancelledByUser = 3
};

/**
  * Defines error code in case that CancellationReason is set to Error.
  * Added in version 1.1.0.
  */
typedef NS_ENUM(NSUInteger, SPXCancellationErrorCode)
{
    /**
     * No error.
     * If SPXCancellationReason is SPXCancellationReason_EndOfStream, SPXCancellationErrorCode
     * is set to SPXCancellationErrorCode_NoError.
     */
    SPXCancellationErrorCode_NoError = 0,

    /**
     * Indicates an authentication error.
     * An authentication error occurs if subscription key or authorization token is invalid, expired,
     * or does not match the region being used.
     */
    SPXCancellationErrorCode_AuthenticationFailure = 1,

    /**
     * Indicates that one or more recognition parameters are invalid or the audio format is not supported.
     */
    SPXCancellationErrorCode_BadRequest = 2,

    /**
     * Indicates that the number of parallel requests exceeded the number of allowed concurrent transcriptions for the subscription.
     */
    SPXCancellationErrorCode_TooManyRequests = 3,

    /**
     * Indicates that the free subscription used by the request ran out of quota.
     */
    SPXCancellationErrorCode_Forbidden = 4,

    /**
     * Indicates a connection error.
     */
    SPXCancellationErrorCode_ConnectionFailure = 5,

    /**
     * Indicates a time-out error when waiting for response from service.
     */
    SPXCancellationErrorCode_ServiceTimeout = 6,

    /**
     * Indicates that an error is returned by the service.
     */
    SPXCancellationErrorCode_ServiceError = 7,

    /**
     * Indicates that the service is currently unavailable.
     */
    SPXCancellationErrorCode_ServiceUnavailable = 8,

    /**
     * Indicates an unexpected runtime error.
     */
    SPXCancellationErrorCode_RuntimeError = 9,

    /**
     * Indicates the embedded speech (SR or TTS) model is not available or corrupted.
     */
    SPXCancellationErrorCode_EmbeddedModelError = 12
};

/**
  * Defines the possible reasons a recognition result might not have been recognized.
  */
typedef NS_ENUM(NSUInteger, SPXNoMatchReason)
{
    /**
     * Indicates that speech was detected, but not recognized.
     */
    SPXNoMatchReason_NotRecognized = 1,

    /**
     * Indicates that the start of the audio stream contained only silence, and the service timed out waiting for speech.
     */
    SPXNoMatchReason_InitialSilenceTimeout = 2,

    /**
     * Indicates that the start of the audio stream contained only noise, and the service timed out waiting for speech.
     */
    SPXNoMatchReason_InitialBabbleTimeout = 3,

    /**
     * Indicates that the spotted keyword has been rejected by the keyword verification service.
     * Added in version 1.5.0.
     */
    SPXNoMatchReason_KeywordNotRecognized = 4,

    /**
     * Indicates that the audio stream contained only silence after the last recognized phrase.
     */
    SPXNoMatchReason_EndSilenceTimeout = 5
};

/**
 *  Defines channels used to send service properties.
 *  Added in version 1.5.0.
 */
typedef NS_ENUM(NSUInteger, SPXServicePropertyChannel)
{
    /**
     * Uses URI query parameter to pass property settings to service.
     */
    SPXServicePropertyChannel_UriQueryParameter = 0
};

/**
 *  Defines the setting for the profanity filter.
 *  Added in version 1.5.0.
 */
typedef NS_ENUM(NSUInteger, SPXSpeechConfigProfanityOption)
{
    /**
     * Mask profanity.
     */
    SPXSpeechConfigProfanityOption_ProfanityMasked = 0,

    /**
     * Remove profanity.
     */
    SPXSpeechConfigProfanityOption_ProfanityRemoved = 1,

    /**
     * Don't filter profanity.
     */
    SPXSpeechConfigProfanityOption_ProfanityRaw = 2,
};

/**
 * Defines the possible speech synthesis output audio format.
 *
 * Updated in version 1.17.0
 */
typedef NS_ENUM(NSUInteger, SPXSpeechSynthesisOutputFormat)
{
    /**
     * raw-8khz-8bit-mono-mulaw
     */
    SPXSpeechSynthesisOutputFormat_Raw8Khz8BitMonoMULaw = 1,

    /**
     * riff-16khz-16kbps-mono-siren
     * Unsupported by the service. Do not use this value.
     */
    SPXSpeechSynthesisOutputFormat_Riff16Khz16KbpsMonoSiren = 2,

    /**
     * audio-16khz-16kbps-mono-siren
     * Unsupported by the service. Do not use this value.
     */
    SPXSpeechSynthesisOutputFormat_Audio16Khz16KbpsMonoSiren = 3,

    /**
     * audio-16khz-32kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio16Khz32KBitRateMonoMp3 = 4,

    /**
     * audio-16khz-128kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio16Khz128KBitRateMonoMp3 = 5,

    /**
     * audio-16khz-64kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio16Khz64KBitRateMonoMp3 = 6,

    /**
     * audio-24khz-48kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio24Khz48KBitRateMonoMp3 =7,

    /**
     * audio-24khz-96kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio24Khz96KBitRateMonoMp3 = 8,

    /**
     * audio-24khz-160kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio24Khz160KBitRateMonoMp3 = 9,

    /**
     * raw-16khz-16bit-mono-truesilk
     */
    SPXSpeechSynthesisOutputFormat_Raw16Khz16BitMonoTrueSilk = 10,

    /**
     * riff-16khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Riff16Khz16BitMonoPcm = 11,

    /**
     * riff-8khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Riff8Khz16BitMonoPcm = 12,

    /**
     * riff-24khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Riff24Khz16BitMonoPcm = 13,

    /**
     * riff-8khz-8bit-mono-mulaw
     */
    SPXSpeechSynthesisOutputFormat_Riff8Khz8BitMonoMULaw = 14,

    /**
     * raw-16khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Raw16Khz16BitMonoPcm = 15,

    /**
     * raw-24khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Raw24Khz16BitMonoPcm = 16,

    /**
     * raw-8khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Raw8Khz16BitMonoPcm = 17,

    /**
     * ogg-16khz-16bit-mono-opus
     */
    SPXSpeechSynthesisOutputFormat_Ogg16khz16BitMonoOpus = 18,

    /**
     * ogg-24khz-16bit-mono-opus
     */
    SPXSpeechSynthesisOutputFormat_Ogg24khz16BitMonoOpus = 19,

    /**
     * raw-48khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Raw48Khz16BitMonoPcm = 20,

    /**
     * riff-48khz-16bit-mono-pcm
     */
    SPXSpeechSynthesisOutputFormat_Riff48Khz16BitMonoPcm = 21,

    /**
     * audio-48khz-96kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio48Khz96KBitRateMonoMp3 = 22,

    /**
     * audio-48khz-192kbitrate-mono-mp3
     */
    SPXSpeechSynthesisOutputFormat_Audio48Khz192KBitRateMonoMp3 = 23,

    /**
     * ogg-48khz-16bit-mono-opus
     * Added in version 1.16.0
     */
    SPXSpeechSynthesisOutputFormat_Ogg48Khz16BitMonoOpus = 24,

    /**
     * webm-16khz-16bit-mono-opus
     * Added in version 1.16.0
     */
    SPXSpeechSynthesisOutputFormat_Webm16Khz16BitMonoOpus = 25,

    /**
     * webm-24khz-16bit-mono-opus
     * Added in version 1.16.0
     */
    SPXSpeechSynthesisOutputFormat_Webm24Khz16BitMonoOpus = 26,

    /**
     * raw-24khz-16bit-mono-truesilk
     * Added in version 1.17.0
     */
    SPXSpeechSynthesisOutputFormat_Raw24Khz16BitMonoTrueSilk = 27,

    /**
     * raw-8khz-8bit-mono-alaw
     * Added in version 1.17.0
     */
    SPXSpeechSynthesisOutputFormat_Raw8Khz8BitMonoALaw = 28,

    /**
     * riff-8khz-8bit-mono-alaw
     * Added in version 1.17.0
     */
    SPXSpeechSynthesisOutputFormat_Riff8Khz8BitMonoALaw = 29,

    /**
     * webm-24khz-16bit-24kbps-mono-opus
     * Audio compressed by OPUS codec in a WebM container, with bitrate of 24kbps, optimized for IoT scenario.
     * Added in version 1.19.0
     */
    SPXSpeechSynthesisOutputFormat_Webm24Khz16Bit24KbpsMonoOpus = 30,

    /**
     * audio-16khz-16bit-32kbps-mono-opus
     * Audio compressed by OPUS codec without container, with bitrate of 32kbps.
     * Added in version 1.20.0
     */
    SPXSpeechSynthesisOutputFormat_Audio16Khz16Bit32KbpsMonoOpus = 31,

    /**
     * audio-24khz-16bit-48kbps-mono-opus
     * Audio compressed by OPUS codec without container, with bitrate of 48kbps.
     * Added in version 1.20.0
     */
    SPXSpeechSynthesisOutputFormat_Audio24Khz16Bit48KbpsMonoOpus = 32,

    /**
     * audio-24khz-16bit-24kbps-mono-opus
     * Audio compressed by OPUS codec without container, with bitrate of 24kbps.
     * Added in version 1.20.0
     */
    SPXSpeechSynthesisOutputFormat_Audio24Khz16Bit24KbpsMonoOpus = 33,

    /**
     * raw-22050hz-16bit-mono-pcm
     * Raw PCM audio at 22050Hz sampling rate and 16-bit depth.
     * Added in 1.22.0
     */
    SPXSpeechSynthesisOutputFormat_Raw22050Hz16BitMonoPcm = 34,

    /**
     * riff-22050hz-16bit-mono-pcm
     * PCM audio at 22050Hz sampling rate and 16-bit depth, with RIFF header.
     * Added in 1.22.0
     */
    SPXSpeechSynthesisOutputFormat_Riff22050Hz16BitMonoPcm = 35,

    /**
     * raw-44100hz-16bit-mono-pcm
     * Raw PCM audio at 44100Hz sampling rate and 16-bit depth.
     * Added in 1.22.0
     */
    SPXSpeechSynthesisOutputFormat_Raw44100Hz16BitMonoPcm = 36,

    /**
     * riff-44100hz-16bit-mono-pcm
     * PCM audio at 44100Hz sampling rate and 16-bit depth, with RIFF header.
     * Added in 1.22.0
     */
    SPXSpeechSynthesisOutputFormat_Riff44100Hz16BitMonoPcm = 37,

     /**
     * amr-wb-16000hz
     * AMR-WB audio at 16kHz sampling rate.
     * Added in 1.24.0
     */
    SPXSpeechSynthesisOutputFormat_AmrWb16000Hz = 38
};

/**
 * Defines the possible status of audio data stream.
 *
 * Added in version 1.7.0
 */
typedef NS_ENUM(NSUInteger, SPXStreamStatus)
{
    /**
     * The audio data stream status is unknown
     */
    SPXStreamStatus_Unknown = 0,

    /** <summary>
     * The audio data stream contains no data
     */
    SPXStreamStatus_NoData = 1,

    /**
     * The audio data stream contains partial data of a speak request
     */
    SPXStreamStatus_PartialData = 2,

    /**
     * The audio data stream contains all data of a speak request
     */
    SPXStreamStatus_AllData = 3,

    /**
     * The audio data stream was cancelled
     */
    SPXStreamStatus_Canceled = 4
};

/**
 * Defines the possible reasons why the participant changed event was raised.
 * Added in version 1.13.0
 */
typedef NS_ENUM(NSUInteger, SPXParticipantChangedReason)
{
    /**
     * Indicates that a participant has joined the conversation.
     */
    SPXParticipantChangedReason_JoinedConversation = 0,

    /**
     * Indicates that a participant has left the conversation. This could be voluntary, or involuntary.
     */
    SPXParticipantChangedReason_LeftConversation = 1,

    /**
     * Indicates that a participants' state has changed (e.g. they became muted, changed their nickname).
     */
    SPXParticipantChangedReason_Updated = 2
};

/**
 * Defines the point system for pronunciation score calibration; default value is FivePoint.
 * Added in version 1.14.0
 */
typedef NS_ENUM(NSUInteger, SPXPronunciationAssessmentGradingSystem)
{
    /**
     * Five point calibration
     */
    SPXPronunciationAssessmentGradingSystem_FivePoint = 1,

    /**
     * Hundred mark
     */
    SPXPronunciationAssessmentGradingSystem_HundredMark = 2
};

/**
 * Defines the pronunciation evaluation granularity; default value is Phoneme.
 * Added in version 1.14.0
 */
typedef NS_ENUM(NSUInteger, SPXPronunciationAssessmentGranularity)
{
    /**
     * Shows the score on the full text, word and phoneme level
     */
    SPXPronunciationAssessmentGranularity_Phoneme = 1,

    /**
     * Shows the score on the full text and word level
     */
    SPXPronunciationAssessmentGranularity_Word = 2,

    /**
     * Shows the score on the full text level only
     */
    SPXPronunciationAssessmentGranularity_FullText = 3
};

/**
 * Define synthesis voice type.
 * Added in version 1.16.0
 */
typedef NS_ENUM(NSUInteger, SPXSynthesisVoiceType)
{
    /**
     * Online neural voice.
     */
    SPXSynthesisVoiceType_OnlineNeural = 1,

    /**
     * Online standard voice.
     */
    SPXSynthesisVoiceType_OnlineStandard = 2,

    /**
     * Offline neural voice.
     */
    SPXSynthesisVoiceType_OfflineNeural = 3,

    /**
     * Offline standard voice.
     */
    SPXSynthesisVoiceType_OfflineStandard = 4
};

/**
 * Define synthesis voice gender.
 * Added in version 1.17.0
 */
typedef NS_ENUM(NSUInteger, SPXSynthesisVoiceGender)
{
    /**
     * Gender unknown.
     */
    SPXSynthesisVoiceGender_Unknown = 0,

    /**
     * Female.
     */
    SPXSynthesisVoiceGender_Female = 1,

    /**
     * Male.
     */
    SPXSynthesisVoiceGender_Male = 2
};

/**
 * Defines the boundary type of speech synthesis boundary event.
 * Changed in version 1.21.0.
 */
typedef NS_ENUM(NSUInteger, SPXSpeechSynthesisBoundaryType)
{
    /**
     * Indicates the boundary text is a word.
     */
    SPXSpeechSynthesisBoundaryType_Word = 1,
    /**
     * Indicates the boundary text is a punctuation.
     */
    SPXSpeechSynthesisBoundaryType_Punctuation = 1,
    /**
     * Indicates the boundary text is a sentence.
     */
    SPXSpeechSynthesisBoundaryType_Sentence = 2
};
