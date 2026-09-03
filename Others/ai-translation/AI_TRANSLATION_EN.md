# AI Translation Programming Guide

> For FitCloudKit on iOS. Standard and conversation translation are single-turn voice inputs; every conversation utterance is a separate turn.

The voice session here is one coordinated turn for device Opus capture. The app starts its translation/ASR service; app-initiated SCO or phone-microphone work calls no SDK start/cancel method.

## 1. Modes

| Mode | Meaning | Lifetime |
|---|---|---|
| `FitCloudAITranslationVoiceModeStandard` | Standard one-way translation | Ends when that voice transfer completes |
| `FitCloudAITranslationVoiceModeConversationSelf` | Local participant utterance | Ends when that utterance completes |
| `FitCloudAITranslationVoiceModeConversationOther` | Other participant utterance | Ends when that utterance completes |

The device may remain on a conversation-translation screen, but that does not keep an SDK AI session active. Start every new utterance separately.

## 2. App initiation

When device Opus capture is needed, start the app-owned translation/ASR service and then call SDK start. For app-initiated SCO or phone microphone, complete the turn entirely in the app without SDK start/cancel.

```objc
[FitCloudKit startTranslationVoiceSessionWithMode:FitCloudAITranslationVoiceModeStandard
                                      completion:^(BOOL success,
                                                     FitCloudAIDeviceSideStartFailureReason failureReason,
                                                     NSError *error) {
    if (!success) [self teardownTranslationInput];
}];
```

The SDK releases the single-turn session before delivering the complete voice callback. ASR, translation, and result delivery do not continue to occupy it.

## 3. Device initiation

```objc
- (void)onDeviceRequestStartTranslationVoiceSessionWithMode:(FitCloudAITranslationVoiceMode)mode
                                                audioSource:(FitCloudAIAudioSource)audioSource {
    if (![self startTranslationServiceForMode:mode audioSource:audioSource]) {
        [FitCloudKit rejectDeviceTranslationVoiceSessionStartRequestForMode:mode
                                                                      reason:FitCloudAIStartRejectionReasonServiceFailed
                                                                  completion:nil];
        return;
    }
    [FitCloudKit acceptDeviceTranslationVoiceSessionStartRequestForMode:mode
                                                              completion:^(BOOL success,
                                                                           BOOL deviceSideExceptionOccurred,
                                                                           NSError *error) {
        if (!success) [self teardownTranslationInput];
    }];
}
```

Echo the exact mode in accept/reject. A device request has no SDK timeout and must be resolved once.
For SCO or phone microphone, successful accept completes only the handshake and releases SDK state; the app continues independently and does not call SDK cancel. Only Opus produces the audio callbacks below.

## 4. Audio and natural completion

```objc
- (void)onTranslateDeltaOpusVoiceData:(NSData *)opusData
                decodedDeltaVoiceData:(NSData *)pcmData
                       sourceLanguage:(FITCLOUDLANGUAGE)sourceLanguage
                       targetLanguage:(FITCLOUDLANGUAGE)targetLanguage {
    [self.streamingASR appendAudioData:pcmData];
}

- (void)onTranslateVoiceStopWithOpusVoiceData:(NSData *)opusData
                              decodedVoiceData:(NSData *)pcmData
                                sourceLanguage:(FITCLOUDLANGUAGE)sourceLanguage
                                targetLanguage:(FITCLOUDLANGUAGE)targetLanguage {
    [self translateVoiceData:pcmData from:sourceLanguage to:targetLanguage];
}
```

`onTranslateVoiceStop...` is a legacy name for completed voice transfer. Do not call cancel after it.

| Channel | Audio source |
|---|---|
| Opus | SDK supplies incremental and complete Opus/PCM callbacks |
| SCO | App reads audio from its SCO path |
| Phone microphone | App owns permission and capture; SDK only passes the selection through |

## 5. Translation result

```objc
[FitCloudKit sendTranslationText:translatedText
                           isEnd:YES
                      resultType:TRANSLATETEXTTYPE_TRANSLATION
                      completion:nil];
```

`isEnd` describes result-content completion only. It does not control the voice-session lifetime.

## 6. Cancel and exit

```objc
[FitCloudKit cancelTranslationVoiceSessionWithCompletion:nil];

- (void)onDeviceDidCancelTranslationVoiceSessionWithMode:(FitCloudAITranslationVoiceMode)mode
                                                    reason:(FitCloudAIDeviceInterruptionReason)reason {
    [self teardownTranslationInput];
}

- (void)onDeviceRequestExitTranslationVoiceSessionWithMode:(FitCloudAITranslationVoiceMode)mode {
    [self teardownTranslationInput];
    [self dismissTranslationUIIfNeeded];
}
```

App cancel is valid only before voice completion. Device cancel is a fact notification and needs no cancel response. Exit leaves the feature or scene.

## 7. Conversation translation

```text
start(Self) → complete voice → release
send translation result
start(Other) → complete voice → release
send translation result
```

Retain the current mode until completion, cancel, exit, or start failure. The complete voice callback does not directly include the mode.

## 8. Swift

```swift
FitCloudKit.startTranslationVoiceSession(with: .standard) {
    success, failureReason, error in
    if !success { self.teardownTranslationInput() }
}
FitCloudKit.cancelTranslationVoiceSession(completion: nil)
```

## 9. Integration checklist

- [ ] Start every utterance independently.
- [ ] Preserve the device-requested mode for accept/reject.
- [ ] Do not cancel after the complete voice callback.
- [ ] Retain mode to distinguish Self and Other.
- [ ] Use `isEnd` for result content only.
- [ ] Handle app cancel, device cancel, and scene exit separately.
