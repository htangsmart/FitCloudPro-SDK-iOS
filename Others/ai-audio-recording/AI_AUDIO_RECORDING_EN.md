# AI Audio Recording Programming Guide

> For FitCloudKit on iOS. AI audio recording is continuous and has on-site and call-recording scenes.

## 1. Scope

```objc
FitCloudAIAudioRecordingSceneOnSite
FitCloudAIAudioRecordingSceneCall
```

- Start always requests device Opus capture; after success it occupies the SDK session until explicit stop or exit.
- For app-initiated SCO or phone microphone, the app owns capture, files, upload, and transcription and calls no SDK start/stop method.
- For device initiation, the scene passed to accept/reject must exactly match the callback.

## 2. App initiation

When device Opus capture is needed, create files/start transcription first and then call SDK start. For app-initiated SCO or phone microphone, do not call SDK start/stop.

```objc
[FitCloudKit startAIAudioRecordingWithScene:FitCloudAIAudioRecordingSceneOnSite
                                completion:^(BOOL success,
                                               FitCloudAIDeviceSideStartFailureReason failureReason,
                                               NSError *error) {
    if (!success) [self discardPreparedRecordingResources];
}];

[FitCloudKit stopAIAudioRecordingWithCompletion:nil];
```

## 3. Device initiation

```objc
- (void)onDeviceRequestStartAIAudioRecordingWithScene:(FitCloudAIAudioRecordingScene)scene
                                         audioSource:(FitCloudAIAudioSource)audioSource {
    if (![self startRecordingBusinessForScene:scene audioSource:audioSource]) {
        [FitCloudKit rejectDeviceAIAudioRecordingStartRequestForScene:scene
                                                                reason:FitCloudAIStartRejectionReasonServiceFailed
                                                            completion:nil];
        return;
    }
    [FitCloudKit acceptDeviceAIAudioRecordingStartRequestForScene:scene
                                                        completion:^(BOOL success,
                                                                     BOOL deviceSideExceptionOccurred,
                                                                     NSError *error) {
        if (!success) [self discardPreparedRecordingResources];
    }];
}
```

The device request has no SDK timeout. Resolve it exactly once with accept or reject.
For SCO or phone microphone, successful accept immediately releases SDK state; the app owns the remaining recording and must not call SDK stop. Only device Opus enters a continuous media session.

## 4. Audio

```objc
- (void)onAIAudioRecordingDeltaOpusVoiceData:(NSData *)opusData
                       decodedDeltaVoiceData:(NSData *)pcmData {
    [self.recorder appendPCMData:pcmData];
}
```

- Opus provides incremental Opus/PCM; accumulate, store, or transcribe it in the app.
- SCO and phone-microphone audio are app-managed and do not imply equivalent Opus callbacks.
- There is no public “complete recording file” callback. Stop completion does not return audio data.

## 5. Stop and exit

```objc
- (void)onDeviceRequestStopAIAudioRecordingWithScene:(FitCloudAIAudioRecordingScene)scene
                                                reason:(FitCloudAIDeviceInterruptionReason)reason {
    [self finishRecordingForScene:scene];
}

- (void)onDeviceRequestExitAIAudioRecordingWithScene:(FitCloudAIAudioRecordingScene)scene {
    [self finishRecordingForScene:scene];
    [self dismissRecordingUIIfNeeded];
}
```

Do not send another stop in response to device stop/exit. After app stop, wait for completion before starting another AI business.

## 6. Errors and exclusivity

- Invalid or mismatched scenes and stop without an active recording return errors.
- On `deviceSideExceptionOccurred=YES`, the SDK has ended the coordination session. End the newly started recording business, release its local resources, and do not send stop/reject.
- All AI businesses are globally exclusive; the two recording scenes cannot run concurrently.

## 7. Swift

```swift
FitCloudKit.startAIAudioRecording(with: .onSite) {
    success, failureReason, error in
    if !success { self.discardPreparedRecordingResources() }
}
FitCloudKit.stopAIAudioRecording(completion: nil)
```

## 8. Integration checklist

- [ ] Preserve and echo the requested scene in accept/reject.
- [ ] Call start only for app-initiated device Opus; use no SDK session API for app-initiated SCO/phone microphone.
- [ ] Accumulate incremental Opus data when a complete recording is needed.
- [ ] Use stop for app termination; only clean up for device stop/exit.
- [ ] Close file and audio resources on every failure path.
