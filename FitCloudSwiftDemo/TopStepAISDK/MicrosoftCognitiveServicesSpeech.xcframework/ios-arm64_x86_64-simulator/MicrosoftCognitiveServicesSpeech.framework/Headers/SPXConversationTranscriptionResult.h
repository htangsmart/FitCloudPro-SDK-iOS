//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXRecognitionResult.h"

/**
  * Defines the result of conversation transcription.
  */
SPX_EXPORT
@interface SPXConversationTranscriptionResult : SPXRecognitionResult

/**
  * A string that represents a speaker identifier in the conversation.
  */
@property (copy, readonly, nullable)NSString *speakerId;

@end
