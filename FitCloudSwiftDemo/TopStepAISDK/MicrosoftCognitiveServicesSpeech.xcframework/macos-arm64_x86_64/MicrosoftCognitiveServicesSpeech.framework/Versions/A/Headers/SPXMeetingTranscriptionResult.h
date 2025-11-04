//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXRecognitionResult.h"

/**
  * Defines the result of meeting transcription.
  */
SPX_EXPORT
@interface SPXMeetingTranscriptionResult : SPXRecognitionResult

/**
  * A string that represents an user identifier in the meeting.
  */
@property (copy, readonly, nullable)NSString *userId;

/**
  * A string that represents the utterance. This id is consistence for intermediates and final speech recognition result from one speaker.
  */
@property (copy, readonly, nullable)NSString *utteranceId;

@end
