# AI Watch Face Programming Guide

> For FitCloudKit on iOS. AI watch face consists of single-turn voice input, prompt generation, image generation, and image transfer.

FitCloudKit coordinates a turn only for device Opus capture. App-initiated SCO or phone-microphone work is app-owned and calls no SDK start/cancel method; only device-originated callbacks carry the audio source.

## 1. Lifetime boundaries

```text
Coordination: start/accept → voice complete → automatic release
Generation: ASR/prompt → image generation → image transfer → device confirmation
```

Image generation and transfer do not occupy the global AI voice session. `cancelAIWatchFaceVoiceSession...` cancels only incomplete voice input, not image generation or transfer.

## 2. App-initiated voice

When device Opus capture is needed, start the app-owned ASR/watch-face service and then call SDK start. For app-initiated SCO or phone microphone, do not call SDK start/cancel.

```objc
[FitCloudKit startAIWatchFaceVoiceSessionWithCompletion:^(BOOL success,
                                                             FitCloudAIDeviceSideStartFailureReason failureReason,
                                                             NSError *error) {
    if (!success) [self teardownWatchFaceVoiceInput];
}];
```

## 3. Device-initiated voice

```objc
- (void)onDeviceRequestStartAIWatchFaceVoiceSessionWithAudioSource:(FitCloudAIAudioSource)audioSource {
    if (![self startAIWatchFaceServiceForAudioSource:audioSource]) {
        [FitCloudKit rejectDeviceAIWatchFaceStartRequestWithReason:FitCloudAIStartRejectionReasonServiceFailed
                                                         completion:nil];
        return;
    }
    [FitCloudKit acceptDeviceAIWatchFaceStartRequestWithCompletion:
        ^(BOOL success, BOOL deviceSideExceptionOccurred, NSError *error) {
            if (!success) [self teardownWatchFaceVoiceInput];
        }];
}
```

For SCO or phone microphone, successful accept immediately releases SDK state; the app owns the remaining voice and generation flow and does not call SDK cancel. Only Opus enters a media session.

## 4. Voice input

```objc
- (void)onAIWatchFaceDeltaOpusVoiceData:(NSData *)opusData
                  decodedDeltaVoiceData:(NSData *)pcmData {
    [self.streamingASR appendAudioData:pcmData];
}

- (void)onAIWatchFaceVoiceDataCompletedWithOpusVoiceData:(NSData *)opusData
                                         decodedVoiceData:(NSData *)pcmData {
    [self finishASRWithVoiceData:pcmData];
}
```

The SDK releases the single-turn session before the complete callback. These callbacks are available for Opus; the app owns SCO and phone-microphone capture.

## 5. Image generation and transfer

```objc
- (void)onRequestGenerateAIWatchFaceWithPrompt:(NSString *)prompt
                                  previewWidth:(NSInteger)width
                                 previewHeight:(NSInteger)height {
    [self.imageService generateWithPrompt:prompt
                                     size:CGSizeMake(width, height)
                               completion:^(UIImage *image, NSError *error) {
        if (image) {
            [FitCloudKit sendAIGeneratedPhoto:image progress:nil completion:nil];
        } else {
            [FitCloudKit sendAIPhotoGenerationResult:FITCLOUDAIPHOTOGENRESULT_UNKNOWN_ERROR completion:nil];
        }
    }];
}
```

Use the device-provided preview dimensions. Consult `FITCLOUDAIPHOTOGENRESULT` for supported result cases, and handle transfer completion separately from generation status.

## 6. Cancel and exit

```objc
[FitCloudKit cancelAIWatchFaceVoiceSessionWithCompletion:nil];

- (void)onDeviceDidCancelAIWatchFaceVoiceSessionWithReason:(FitCloudAIDeviceInterruptionReason)reason {
    [self teardownWatchFaceVoiceInput];
}

- (void)onDeviceRequestExitAIWatchFaceVoiceSession {
    [self teardownWatchFaceVoiceInput];
    [self dismissAIWatchFaceUIIfNeeded];
}
```

Use app cancel only before voice completion. Device cancel is a fact notification and requires local cleanup only. Exit leaves the complete feature scene.

## 7. Errors

- On start failure, release voice resources and do not enter generation.
- On `deviceSideExceptionOccurred=YES`, the SDK has ended the coordination session. End the newly started app business and do not send cancel/reject.
- Report image-generation failure to the device.
- Handle image-transfer errors without reopening or retaining the AI voice session.

## 8. Swift

```swift
FitCloudKit.startAIWatchFaceVoiceSession {
    success, failureReason, error in
    if !success { self.teardownWatchFaceVoiceInput() }
}
FitCloudKit.cancelAIWatchFaceVoiceSession(completion: nil)
```

## 9. Integration checklist

- [ ] Separate voice lifetime from image generation and transfer.
- [ ] Use accept/reject for device initiation.
- [ ] Do not cancel after voice completion.
- [ ] Generate the device-requested preview size.
- [ ] Handle generation, transfer, and device confirmation results independently.
