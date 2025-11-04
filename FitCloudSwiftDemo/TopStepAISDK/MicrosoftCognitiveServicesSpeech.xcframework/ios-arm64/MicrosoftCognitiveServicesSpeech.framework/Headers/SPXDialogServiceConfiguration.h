//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXPropertyCollection.h"

/**
 * The base configuration type used to create a DialogServiceConnector that can communicate with a voice assistant.
 *
 * SPXDialogServiceConfiguration objects should be initialized directly. Derived objects like
 * SPXDialogBotFrameworkConfiguration should be instantiated, instead.
 */
SPX_EXPORT
@interface SPXDialogServiceConfiguration : NSObject

/**
 * The language identifier used for speech-to-text, expressed in BCP-47 format.
 */
@property (nonatomic, copy, nullable)NSString *language;

/**
 * Returns the value of a configuration property using an explicit string literal as a key.
 * If a property with the provided key is not available, an empty string is returned.
 *
 * @param name the name of the configuration property used as a key to the desired value.
 * @return the value of the indexed configuration property or an empty string if the key is not found.
 */
- (nullable NSString *)getPropertyByName:(nonnull NSString *)name;

/**
 * Returns the value of a configuration property using a known property ID as a key.
 * If a property with the provided key is not available, an empty string is returned.
 *
 * @param propertyId the property ID for the configuration property.
 * @return the value of the configuration property or an empty string if the key is not found.
 */
- (nullable NSString *)getPropertyById:(SPXPropertyId)propertyId;

/**
 * Sets the value of a configuration property using a provided string literal as the key.
 *
 * @param value the value to set for the configuration property.
 * @param name the name of the configuration property to use as a key for its value.
 */
- (void)setPropertyTo:(nonnull NSString *)value byName:(nonnull NSString *)name;

/**
 * Sets the value of a configuration property using a known property ID as the key.
 *
 * @param value the value to set for the configuration property.
 * @param id the property ID for the configuration property.
 */
- (void)setPropertyTo:(nonnull NSString *)value byId:(SPXPropertyId)id;

/**
 * Sets an advanced configuration property that's encoded into the speech service request upon connection.
 * This is typically used for preview features not available via a well-supported property ID.
 *
 * @param value the property value.
 * @param name the property name.
 * @param channel the channel used to pass the specified property to service.
 */
- (void)setServicePropertyTo
                    :(nonnull NSString *)value
              byName:(nonnull NSString *)name
        usingChannel:(SPXServicePropertyChannel)channel;

@end

/**
 * The specialized configuration type used to initialize a DialogServiceConnector that will connect to a Bot Framework
 * bot using the Direct Line Speech channel.
 *
 * See also: [What is Direct Line Speech?](/azure/cognitive-services/speech-service/direct-line-speech).
 */
SPX_EXPORT
@interface SPXDialogBotFrameworkConfiguration : SPXDialogServiceConfiguration

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot via the Direct Line Speech channel.
 *
 * @param subscriptionKey the subscription key to be used.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param botId the identifier of a specific bot resource to request, even if it's not the default for this
 * subscription.
 * @param outError error information.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nullable instancetype)initWithSubscription
              :(nonnull NSString *)subscriptionKey
        region:(nonnull NSString *)region
         botId:(NSString * _Nullable)botId
         error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 *
 * @param subscriptionKey the subscription key to be used.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param botId the identifier of a specific bot resource to request, even if it's not the default for this
 * subscription.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nonnull instancetype)initWithSubscription
              :(nonnull NSString *)subscriptionKey
        region:(nonnull NSString *)region
         botId:(NSString * _Nullable)botId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 * This will connect to the default bot associated with the Direct Line Speech channel for the speech service resource.
 *
 * @param subscriptionKey the subscription key to be used.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param outError error information.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nullable instancetype)initWithSubscription
              :(nonnull NSString *)subscriptionKey
        region:(nonnull NSString *)region
         error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 * This will connect to the default bot associated with the Direct Line Speech channel for the speech service resource.
 *
 * @param subscriptionKey the subscription key to be used.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nonnull instancetype)initWithSubscription:(nonnull NSString *)subscriptionKey region:(nonnull NSString *)region
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 *
 * Note: An authorization token must be obtained before this call and checked for validity. Before an authorization
 * token expires, it must be refreshed by assigning a new token on the corresponding property present on the
 * DialogServiceConnector created with the configuration object created with this call.
 *
 * @param authorizationToken the authorization token.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param botId the identifier of a specific bot resource to request, even if it's not the default for this
 * subscription.
 * @param outError error information.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nullable instancetype)initWithAuthorizationToken
              :(nonnull NSString *)authorizationToken
        region:(nonnull NSString *)region
         botId:(NSString * _Nullable)botId
         error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 *
 * Note: An authorization token must be obtained before this call and checked for validity. Before an authorization
 * token expires, it must be refreshed by assigning a new token on the corresponding property present on the
 * DialogServiceConnector created with the configuration object created with this call.
 *
 * @param authorizationToken the authorization token.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param botId the identifier of a specific bot resource to request, even if it's not the default for this
 * subscription.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nonnull instancetype)initWithAuthorizationToken
              :(nonnull NSString *)authorizationToken
        region:(nonnull NSString *)region
         botId:(NSString * _Nullable)botId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 * This will connect to the default bot associated with the Direct Line Speech channel for the speech service resource.
 *
 * Note: An authorization token must be obtained before this call and checked for validity. Before an authorization
 * token expires, it must be refreshed by assigning a new token on the corresponding property present on the
 * DialogServiceConnector created with the configuration object created with this call.
 *
 * @param authorizationToken the authorization token.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param outError error information.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nullable instancetype)initWithAuthorizationToken
              :(nonnull NSString *)authorizationToken
        region:(nonnull NSString *)region
         error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a Bot
 * Framework bot.
 * This will connect to the default bot associated with the Direct Line Speech channel for the speech service resource.
 *
 * Note: An authorization token must be obtained before this call and checked for validity. Before an authorization
 * token expires, it must be refreshed by assigning a new token on the corresponding property present on the
 * DialogServiceConnector created with the configuration object created with this call.
 *
 * @param authorizationToken the authorization token.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nonnull instancetype)initWithAuthorizationToken
              :(nonnull NSString *)authorizationToken
        region:(nonnull NSString *)region
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

@end

/**
 * The instance interface type used to initialize a DialogServiceConnector that will connect to a Custom Commands
 * application as published from Speech Studio for a speech service resource.
 *
 * See also: [What is Custom Commands?](/azure/cognitive-services/speech-service/custom-commands).
 */
SPX_EXPORT
@interface SPXDialogCustomCommandsConfiguration : SPXDialogServiceConfiguration

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a
 * Custom Commands application.
 * Requires an identifier for a published Custom Commands application associated with the referenced speech service
 * resource.
 *
 * @param subscriptionKey the subscription key to be used.
 * @param appId the identifier for the Custom Commands application to use, as selected from the subscription.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param outError error information.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nullable instancetype)initWithSubscription
              :(nonnull NSString *)subscriptionKey
         appId:(nonnull NSString *)appId
        region:(nonnull NSString *)region
         error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a
 * Custom Commands application.
 * Requires an identifier for a published Custom Commands application associated with the referenced speech service
 * resource.
 *
 * @param subscriptionKey the subscription key to be used.
 * @param appId the identifier for the Custom Commands application to use, as selected from the subscription.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nonnull instancetype)initWithSubscription
              :(nonnull NSString *)subscriptionKey
         appId:(nonnull NSString *)appId
        region:(nonnull NSString *)region
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a
 * Custom Commands application.
 * Requires an identifier for a published Custom Commands application associated with the referenced speech service
 * resource.
 *
 * Note: An authorization token must be obtained before this call and checked for validity. Before an authorization
 * token expires, it must be refreshed by assigning a new token on the corresponding property present on the
 * DialogServiceConnector created with the configuration object created with this call.
 *
 * @param authorizationToken the authorization token.
 * @param appId the identifier for the Custom Commands application to use, as selected from the subscription.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @param outError error information.
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nullable instancetype)initWithAuthorizationToken
              :(nonnull NSString *)authorizationToken
         appId:(nonnull NSString *)appId
        region:(nonnull NSString *)region
         error:(NSError * _Nullable * _Nullable)outError;

/**
 * Initializes a dialog configuration object used to create a DialogServiceConnector that will communicate with a
 * Custom Commands application.
 * Requires an identifier for a published Custom Commands application associated with the referenced speech service
 * resource.
 *
 * Note: An authorization token must be obtained before this call and checked for validity. Before an authorization
 * token expires, it must be refreshed by assigning a new token on the corresponding property present on the
 * DialogServiceConnector created with the configuration object created with this call.
 *
 * @param authorizationToken the authorization token.
 * @param appId the identifier for the Custom Commands application to use, as selected from the subscription.
 * @param region the region name for the subscription (see the <a href="https://aka.ms/csspeech/region">region
 * page</a>).
 * @return a configuration object used to initialize a DialogServiceConnector.
 */
- (nonnull instancetype)initWithAuthorizationToken
              :(nonnull NSString *)authorizationToken
         appId:(nonnull NSString *)appId
        region:(nonnull NSString *)region
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

@end