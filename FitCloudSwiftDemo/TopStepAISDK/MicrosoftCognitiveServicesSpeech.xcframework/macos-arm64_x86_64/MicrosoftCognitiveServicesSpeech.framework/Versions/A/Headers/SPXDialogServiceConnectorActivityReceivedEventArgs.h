//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXAudioStream.h"

/**
 * The object type that encapsulates the response data that originates from the dialog implementation used by a
 * DialogServiceConnector. Activities may be sent by a dialog implementation at any time during a connection and there
 * may be a many-to-one relationship between activities received and input utterances.
 */
SPX_EXPORT
@interface SPXDialogServiceConnectorActivityReceivedEventArgs : NSObject

/**
 * Gets a serialized JSON object that represents the activity payload sent by the dialog implementation that a
 * DialogServiceConnector communicates with. This data is originated from the dialog implementation and both the schema
 * and contents of the document are determined by the sender.
 */
@property (copy, readonly, nonnull)NSString *activity;

/**
 * Gets a value indicating whether this activity payload includes an audio stream from the text-to-speech service. If
 * such a stream is present, it can be retrieved via the audio property.
 *
 * If there is no audio data associated with this activity payload, hasAudio will be false and audio will be nil.
 */
@property (readonly)bool hasAudio;

/**
 * Gets a PullAudioOutputStream associated with this activity, as produced by the text-to-speech service. This stream
 * is populated as data arrives and may not contain all synthesized audio when the activity arrives.
 *
 * If there is no audio data associated with this activity payload, hasAudio will be false and audio will be nil.
 */
@property (copy, readonly, nonnull)SPXPullAudioOutputStream *audio;

@end
