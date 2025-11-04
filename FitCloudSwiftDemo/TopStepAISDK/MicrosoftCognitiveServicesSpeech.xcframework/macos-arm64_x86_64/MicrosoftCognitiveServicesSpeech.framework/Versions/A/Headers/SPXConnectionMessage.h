//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXPropertyCollection.h"

/**
 * ConnectionMessage represents implementation specific messages sent to and received from
 * the speech service. These messages are provided for debugging purposes and should not
 * be used for production use cases with the Azure Cognitive Services Speech Service.
 * Messages sent to and received from the Speech Service are subject to change without
 * notice. This includes message contents, headers, payloads, ordering, etc.
 */
SPX_EXPORT
@interface SPXConnectionMessage : NSObject

/**
  * Gets the path associated with SPXConnectionMessage.
  */
@property (copy, readonly, nonnull)NSString *path;

/**
  * Checks to see if the ConnectionMessage is a text message.
  */
@property (readonly)bool isTextMessage;

/**
  * Checks to see if the ConnectionMessage is a binary message.
  */
@property (readonly)bool isBinaryMessage;

/**
  * Gets the text message payload. Typically the text message content-type is
  * application/json. To determine other content-types use Properties.GetProperty("Content-Type").
  */
@property (copy, readonly, nullable)NSString *textMessage;

/**
  * Gets the binary message payload.
  */
@property (copy, readonly, nullable)NSData *binaryMessage;

/**
  * Gets the collection of properties and their values defined for SPXConnectionMessage.
  * Message headers can be accessed via this collection (e.g. "Content-Type").
  */
@property (readonly, nullable)id <SPXPropertyCollection> properties;

@end
