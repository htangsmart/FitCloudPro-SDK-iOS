//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"

/**
 * The object type that encapsulates turn status information as received from the dialog implementation that a
 * DialogServiceConnector communicates with. A turn is a single execution session within the dialog implementation that
 * may generate any number of activities over its course. The information in this payload represents success or failure
 * conditions encountered by the dialog implementation over the course of this execution. This data facilitates the
 * indication of completion or error conditions within the dialog implementation even when no explicit activity data is
 * produced as part of a turn.
 */
SPX_EXPORT
@interface SPXDialogServiceConnectorTurnStatusReceivedEventArgs : NSObject

/**
 * The interaction identifier associated with this turn status event. Interaction identifiers generally correspond to a
 * single input signal (e.g. a voice utterance or sent activity payload) and will correlate to replyTo fields within Bot
 * Framework activities.
 */
@property (copy, readonly, nonnull)NSString *interactionId;

/**
 * The conversation identifier associated with this turn status event. Conversations are logical groupings of turns that
 * may span multiple interactions. A client can use a conversation identifier to resume or retry a conversation if such
 * a capability is supported by the backing dialog implementation.
 */
@property (copy, readonly, nonnull)NSString *conversationId;

/**
 * The numeric status code associated with this turn status event. These generally correspond to standard HTTP status
 * codes such as 200 (OK), 400 (Failure/Bad Request), and 429 (Timeout/Throttled).
 */
@property (readonly)int statusCode;

@end
