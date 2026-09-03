# AIAsking Programming Guide

> For FitCloudKit on iOS. AIAsking is one question followed by one answer; it is not continuous multi-turn AI Chat.

FitCloudKit coordinates a turn only for device Opus capture. App-initiated SCO or phone-microphone work is entirely app-owned and calls no SDK start/cancel method; only a device-start callback carries an audio source.

## 1. Three independent states

| State | Starts with | Ends with |
|---|---|---|
| Device AIAsking scene | `onDeviceDidEnterAIAsking` | `onDeviceDidExitAIAsking` |
| Single voice input | successful start/accept | complete voice, cancel, or exit |
| Answer delivery | first `sendAIAskingResult` | `isEnd=YES` |

The device may stay on its AIAsking screen after the SDK voice session ends. Likewise, incremental answer delivery does not keep the voice session active.

## 2. App-initiated question

When device Opus capture is needed, start the app-owned ASR/AI service and then call SDK start. For app-initiated SCO or phone microphone, do not call SDK start/cancel.

```objc
[FitCloudKit startAIAskingVoiceSessionWithCompletion:^(BOOL success,
                                                           FitCloudAIDeviceSideStartFailureReason failureReason,
                                                           NSError *error) {
    if (!success) [self teardownAIAskingVoiceInput];
}];
```

Use start only when the app requests device Opus capture. `failureReason` represents a device-side start failure; `error` represents an SDK, state, or transport failure.

## 3. Device-initiated question

```objc
- (void)onDeviceRequestStartAIAskingVoiceSessionWithAudioSource:(FitCloudAIAudioSource)audioSource {
    FitCloudAIStartRejectionReason rejectionReason;
    if (![self startAIAskingServiceForAudioSource:audioSource rejectionReason:&rejectionReason]) {
        [FitCloudKit rejectDeviceAIAskingStartRequestWithReason:rejectionReason completion:nil];
        return;
    }
    [FitCloudKit acceptDeviceAIAskingStartRequestWithCompletion:
        ^(BOOL success, BOOL deviceSideExceptionOccurred, NSError *error) {
            if (!success) [self teardownAIAskingBusiness];
        }];
}
```

A device request has no SDK timeout. Resolve it exactly once. Use `FitCloudAIStartRejectionReasonAuthenticationFailed` when AI authorization cannot be established.
When `deviceSideExceptionOccurred=YES`, the SDK has ended the failed coordination session. End the newly started app business and do not send cancel/reject.
For SCO or phone microphone, successful accept completes only the device handshake. The SDK releases its state, emits no audio callbacks, and must not be canceled afterward.

## 4. Voice and natural completion

```objc
- (void)onAIAskingDeltaOpusVoiceData:(NSData *)opusData
               decodedDeltaVoiceData:(NSData *)pcmData {
    [self.streamingASR appendAudioData:pcmData];
}

- (void)onAIAskingVoiceDataCompletedWithOpusVoiceData:(NSData *)opusData
                                      decodedVoiceData:(NSData *)pcmData {
    [self requestAnswerForVoiceData:pcmData];
}
```

The SDK releases the single-turn session before delivering the complete callback. Do not call cancel afterward. Opus is delivered by the SDK; the app owns SCO and phone-microphone capture.

## 5. Agent selection

```objc
FitCloudAIAskingAgent agent = [FitCloudKit selectedAIAskingAgent];

- (void)onDeviceDidSelectAIAskingAgent:(FitCloudAIAskingAgent)agent {
    self.selectedAgent = agent;
}
```

- The selection is persistent device state for subsequent AIAsking requests.
- Ending a voice turn does not clear it.
- It does not control AI Chat.
- `onDeviceDidSelectAdFlashAIAgent:` is a separate AdFlash selection event.

## 6. ASR confirmation and answer

On supported devices, send the recognized question after checking capability:

```objc
[FitCloudKit sendAIAskingASRResult:recognizedText
                         errorCode:FitCloudASRErrorCodeSuccess
                        completion:nil];
```

An answer may be incremental:

```objc
[FitCloudKit sendAIAskingResult:partialText
                          isEnd:NO
                     resultType:FitCloudAIAskingResultTypeResponseText
                     completion:nil];

[FitCloudKit sendAIAskingResult:finalText
                          isEnd:YES
                     resultType:FitCloudAIAskingResultTypeResponseText
                     completion:nil];
```

`isEnd` closes answer content only. It does not close voice input or exit the AIAsking scene.

## 7. Scene events

```objc
- (void)onDeviceDidEnterAIAsking;
- (void)onDeviceDidConfirmAIAsking;
- (void)onDeviceDidExitAIAsking;
```

These describe device UI and interaction state, not voice start/cancel. Confirmation of the current input does not mean answer delivery has finished.

## 8. Cancel and feature exit

```objc
[FitCloudKit cancelAIAskingVoiceSessionWithCompletion:nil];

- (void)onDeviceDidCancelAIAskingVoiceSessionWithReason:(FitCloudAIDeviceInterruptionReason)reason {
    [self teardownAIAskingVoiceInput];
}

- (void)onDeviceRequestExitAIAskingVoiceSession {
    [self teardownAIAskingVoiceInput];
    [self exitAIAskingBusinessIfNeeded];
}
```

Use app cancel only before complete voice. `onDeviceDidExitAIAsking` says the device scene already exited; `onDeviceRequestExitAIAskingVoiceSession` asks the app to leave its corresponding feature processing. They may converge on app cleanup but remain distinct events.

## 9. Swift

```swift
let agent = FitCloudKit.selectedAIAskingAgent()
FitCloudKit.startAIAskingVoiceSession {
    success, failureReason, error in
    if !success { self.teardownAIAskingVoiceInput() }
}
FitCloudKit.cancelAIAskingVoiceSession(completion: nil)
```

## 10. Integration checklist

- [ ] Keep AIAsking distinct from continuous AI Chat.
- [ ] Track device scene, current voice input, and answer delivery independently.
- [ ] Use accept/reject for device initiation and handle post-accept device failure.
- [ ] Treat complete voice as immediate end of the voice turn.
- [ ] Never use `isEnd` to manage voice lifetime.
- [ ] Apply the selected agent only to AIAsking.
- [ ] Distinguish device cancel, feature exit, and scene did-exit.
