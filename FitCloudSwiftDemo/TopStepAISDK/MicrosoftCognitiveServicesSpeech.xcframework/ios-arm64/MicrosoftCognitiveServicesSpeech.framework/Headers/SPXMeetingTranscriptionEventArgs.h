//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXRecognitionEventArgs.h"
#import "SPXMeetingTranscriptionResult.h"

/**
 * Defines the payload for meeting transcription events.
 */
SPX_EXPORT
@interface SPXMeetingTranscriptionEventArgs : SPXRecognitionEventArgs

/**
 * Represents the meeting transcription result.
 */
@property (readonly, nullable)SPXMeetingTranscriptionResult *result;

@end

/**
 * Defines the payload of meeting transcription canceled result events.
 */
SPX_EXPORT
@interface SPXMeetingTranscriptionCanceledEventArgs : SPXMeetingTranscriptionEventArgs

/**
 * The reason the trancription was canceled.
 */
@property (readonly)SPXCancellationReason reason;

/**
 * The error code in case of an unsuccessful transcription (reason is set to Error).
 *
 */
@property (readonly)SPXCancellationErrorCode errorCode;

/**
 * The error message in case of an unsuccessful transcription (reason is set to Error).
 */
@property (copy, readonly, nullable)NSString *errorDetails;

@end
