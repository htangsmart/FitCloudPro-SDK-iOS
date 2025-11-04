//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXConnectionMessage.h"

/**
 * Defines the payload for Connection's message events.
 *
 */
SPX_EXPORT
@interface SPXConnectionMessageEventArgs : NSObject

/**
  * The SPXConnectionMessage instance associated with SPXConnectionMessageEventArgs.
  */
@property (copy, readonly, nonnull)SPXConnectionMessage *message;

@end
