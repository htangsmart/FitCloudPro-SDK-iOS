//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/csspeech/license for the full license information.
//

#import "SPXFoundation.h"
#import "SPXUser.h"
#import "SPXParticipant.h"
#import "SPXPropertyCollection.h"
#import "SPXSpeechConfiguration.h"

/**
 * Performs meeting management including add and remove participants.
 */
SPX_EXPORT
@interface SPXMeeting : NSObject

/**
 * The collection of properties and their values defined for this SPXMeeting.
 */
@property (readonly, nullable)id <SPXPropertyCollection> properties;

/**
 * The unique identifier for the meeting.
 */
@property (nonatomic, copy, nullable)NSString *meetingId;

/**
 * The authorization token used to communicate with the service.
 * Note: The caller needs to ensure that the authorization token is valid. Before the authorization token expires, 
 * the caller needs to refresh it by calling this setter with a new valid token. Otherwise, the recognizer will 
 * encounter errors during recognition.
 */
@property (nonatomic, copy, nullable)NSString *authorizationToken;

/**
 * Initializes a new instance of meeting using the specified speech configuration.
 *
 * @param speechConfiguration speech configuration.
 * @return a meeting instance.
 */
- (nullable instancetype)init:(nonnull SPXSpeechConfiguration *)speechConfiguration
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of meeting using the specified speech configuration and meeting id.
 *
 * @param speechConfiguration speech configuration.
 * @param meetingId a unqiue identification of your meeting.
 * @return a meeting instance.
 */
- (nullable instancetype)init:(nonnull SPXSpeechConfiguration *)speechConfiguration meetingId:(nonnull NSString *)meetingId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Initializes a new instance of meeting using the specified speech configuration and meeting id.
 *
 * @param speechConfiguration speech configuration.
 * @param meetingId a unqiue identification of your meeting. 
 * @param outError error information.
 * @return a meeting instance.
 */
- (nullable instancetype)init:(nonnull SPXSpeechConfiguration *)speechConfiguration meetingId:(nonnull NSString *)meetingId error:(NSError * _Nullable * _Nullable)outError;

/**
 * Starts a meeting, and provides asynchronous callback with the information is meeting started successfully or not.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)startMeetingAsync:(nonnull void (^)(BOOL started, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Starts a meeting, and provides asynchronous callback with the information is meeting started successfully or not.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)startMeetingAsync:(nonnull void (^)(BOOL started, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Ends a meeting, and provides asynchronous callback with the information is meeting ended successfully or not.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)endMeetingAsync:(nonnull void (^)(BOOL ended, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Ends a meeting, and provides asynchronous callback with the information is meeting ended successfully or not.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)endMeetingAsync:(nonnull void (^)(BOOL ended, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Deletes a meeting, and provides asynchronous callback with the information is meeting deletion completed.
 * After deleted, no one will be able to join the meeting.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)deleteMeetingAsync:(nonnull void (^)(BOOL deleted, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Deletes a meeting, and provides asynchronous callback with the information is meeting deletion completed.
 * After deleted, no one will be able to join the meeting.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)deleteMeetingAsync:(nonnull void (^)(BOOL deleted, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Locks a meeting, and provides asynchronous callback with the information is meeting locking completed.
 * After locked, new participants are prevented from joining the meeting.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)lockMeetingAsync:(nonnull void (^)(BOOL locked, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Locks a meeting, and provides asynchronous callback with the information is meeting locking completed.
 * After locked, new participants are prevented from joining the meeting.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)lockMeetingAsync:(nonnull void (^)(BOOL locked, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Unlocks a meeting, and provides asynchronous callback with the information is meeting unlocking completed.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)unlockMeetingAsync:(nonnull void (^)(BOOL unlocked, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Unlocks a meeting, and provides asynchronous callback with the information is meeting unlocking completed.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)unlockMeetingAsync:(nonnull void (^)(BOOL unlocked, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Mute all other participants in the meeting. After this no other participants will have their speech recognitions broadcast, 
 * nor be able to send text messages.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)muteAllParticipantsAsync:(nonnull void (^)(BOOL muted, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Mute all other participants in the meeting. After this no other participants will have their speech recognitions broadcast, 
 * nor be able to send text messages.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)muteAllParticipantsAsync:(nonnull void (^)(BOOL muted, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Unmute all other participants in the meeting.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 */
- (void)unmuteAllParticipantsAsync:(nonnull void (^)(BOOL unmuted, NSError * _Nullable))completedHandler
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Unmute all other participants in the meeting.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param outError error information.
 */
- (BOOL)unmuteAllParticipantsAsync:(nonnull void (^)(BOOL unmuted, NSError * _Nullable))completedHandler error:(NSError * _Nullable * _Nullable)outError;

/**
 * Mute participant with a given userId in the meeting.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 */
- (void)muteParticipantAsync:(nonnull void (^)(BOOL muted, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Mute participant with a given userId in the meeting.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 * @param outError error information.
 */
- (BOOL)muteParticipantAsync:(nonnull void (^)(BOOL muted, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId error:(NSError * _Nullable * _Nullable)outError;

/**
 * Unmute participant with a given userId in the meeting.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 */
- (void)unmuteParticipantAsync:(nonnull void (^)(BOOL unmuted, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Unmute participant with a given userId in the meeting.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 * @param outError error information.
 */
- (BOOL)unmuteParticipantAsync:(nonnull void (^)(BOOL unmuted, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId error:(NSError * _Nullable * _Nullable)outError;

/**
 * Adds a participant from a meeting using a user id.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 */
- (void)addParticipantAsync:(nonnull void (^)(SPXParticipant * _Nullable, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Adds a participant from a meeting using a user id.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 * @param outError error information.
 */
- (BOOL)addParticipantAsync:(nonnull void (^)(SPXParticipant * _Nullable, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId error:(NSError * _Nullable * _Nullable)outError;

/**
 * Adds a participant from a meeting using a Participant object.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param participant A Participant instance.
 */
- (void)addParticipantAsync:(nonnull void (^)(SPXParticipant * _Nullable, NSError * _Nullable))completedHandler participant:(nonnull SPXParticipant *)participant
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Adds a participant from a meeting using a Participant object.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param participant A Participant instance.
 * @param outError error information.
 */
- (BOOL)addParticipantAsync:(nonnull void (^)(SPXParticipant * _Nullable, NSError * _Nullable))completedHandler participant:(nonnull SPXParticipant *)participant error:(NSError * _Nullable * _Nullable)outError;

/**
 * Adds a participant from a meeting using a User object.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param user A User instance.
 */
- (void)addParticipantAsync:(nonnull void (^)(SPXUser * _Nullable, NSError * _Nullable))completedHandler user:(nonnull SPXUser *)user
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Adds a participant from a meeting using a User object.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param user A User instance.
 * @param outError error information.
 */
- (BOOL)addParticipantAsync:(nonnull void (^)(SPXUser * _Nullable, NSError * _Nullable))completedHandler user:(nonnull SPXUser *)user error:(NSError * _Nullable * _Nullable)outError;

/**
 * Remove a participant from a meeting using a user id.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 */
- (void)removeParticipantAsync:(nonnull void (^)(BOOL removed, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Remove a participant from a meeting using a user id.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param userId A user identifier.
 * @param outError error information.
 */
- (BOOL)removeParticipantAsync:(nonnull void (^)(BOOL removed, NSError * _Nullable))completedHandler userId:(nonnull NSString *)userId error:(NSError * _Nullable * _Nullable)outError;

/**
 * Remove a participant from a meeting using a Participant object.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param participant A Participant instance.
 */
- (void)removeParticipantAsync:(nonnull void (^)(BOOL removed, NSError * _Nullable))completedHandler participant:(nonnull SPXParticipant *)participant
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Remove a participant from a meeting using a Participant object.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param participant A Participant instance.
 * @param outError error information.
 */
- (BOOL)removeParticipantAsync:(nonnull void (^)(BOOL removed, NSError * _Nullable))completedHandler participant:(nonnull SPXParticipant *)participant error:(NSError * _Nullable * _Nullable)outError;

/**
 * Remove a participant from a meeting using a User object.
 * 
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param user A User instance.
 */
- (void)removeParticipantAsync:(nonnull void (^)(BOOL removed, NSError * _Nullable))completedHandler user:(nonnull SPXUser *)user
NS_SWIFT_UNAVAILABLE("Use the method with Swift-compatible error handling.");

/**
 * Remove a participant from a meeting using a User object.
 *
 * @param completedHandler the block function to be called when async operation has been completed.
 * @param user A User instance.
 * @param outError error information.
 */
- (BOOL)removeParticipantAsync:(nonnull void (^)(BOOL removed, NSError * _Nullable))completedHandler user:(nonnull SPXUser *)user error:(NSError * _Nullable * _Nullable)outError;

@end
