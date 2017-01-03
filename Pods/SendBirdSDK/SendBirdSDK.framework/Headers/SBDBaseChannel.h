//
//  SBDBaseChannel.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/19/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDUser.h"
#import "SBDUserMessage.h"
#import "SBDAdminMessage.h"
#import "SBDFileMessage.h"
#import "SBDError.h"

@class SBDPreviousMessageListQuery;
@class SBDFileMessage;
@class SBDUserMessage;
@class SBDMessageListQuery;
@class SBDGroupChannel;
@class SBDOpenChannel;

/**
 *  An object that adopts the `SBDChannelDelegate` protocol is responsible for receiving the events in the channel. Some of delegate methods are common for the `SBDBaseChannel`. However, there are delegate methods for the `SBDOpenChannel` and `SBDGroupChannel` exclusive. The `SBDChannelDelegate` can be added by [`addChannelDelegate:identifier:`](../Classes/SBDMain.html#//api/name/addChannelDelegate:identifier:) in `SBDMain`. Every `SBDChannelDelegate` method which is added is going to receive events. 
 *
 *  @warning If the object that adopts the `SBDChannelDelegate` protocol is invalid, the delegate has to be removed by the identifier via [`removeChannelDelegateForIdentifier:`](../Classes/SBDMain.html#//api/name/removeChannelDelegateForIdentifier:) in `SBDMain`. If you miss this, it will cause the crash.
 *
 *  This protocol deals with the below events.
 *
 *  * Receives a message in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html).
 *  * Receives an event when a member read a message in the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
 *  * Receives an event when a member typed something in the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
 *  * Receives an event when a new member joined the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
 *  * Receives an event when a member left from the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
 *  * Receives an event when a participant entered the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
 *  * Receives an event when a participant exited the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
 *  * Receives an event when a participant was muted or unmuted in the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
 *  * Receives an event when a participant was banned or unbanned in the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
 *  * Receives an event when the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html) was frozen or unfrozen.
 *  * Receives an event when the property of the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was changed.
 *  * Receives an event when the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was deleted.
 *  * Receives an event when a message in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was deleted.
 */
@protocol SBDChannelDelegate <NSObject>

@optional

/**
 *  A callback when a message received.
 *
 *  @param sender The channel where the message is received.
 *  @param message The received message.
 */
- (void)channel:(SBDBaseChannel * _Nonnull)sender didReceiveMessage:(SBDBaseMessage * _Nonnull)message;

/**
 *  A callback when read receipts updated.
 *
 *  @param sender The group channel where the read receipt updated.
 */
- (void)channelDidUpdateReadReceipt:(SBDGroupChannel * _Nonnull)sender;

/**
 *  A callback when user sends typing status.
 *
 *  @param sender The group channel where the typing status updated.
 */
- (void)channelDidUpdateTypingStatus:(SBDGroupChannel * _Nonnull)sender;

/**
 *  A callback when new member joined to the group channel.
 *
 *  @param sender The group channel.
 *  @param user   The new user joined to the channel.
 */
- (void)channel:(SBDGroupChannel * _Nonnull)sender userDidJoin:(SBDUser * _Nonnull)user;

/**
 *  A callback when current member left from the group channel.
 *
 *  @param sender The group channel.
 *  @param user   The member left from the channel.
 */
- (void)channel:(SBDGroupChannel * _Nonnull)sender userDidLeave:(SBDUser * _Nonnull)user;

/**
 *  A callback when a user enter an open channel.
 *
 *  @param sender The open channel.
 *  @param user   The user
 */
- (void)channel:(SBDOpenChannel * _Nonnull)sender userDidEnter:(SBDUser * _Nonnull)user;

/**
 *  A callback when a user exit an open channel.
 *
 *  @param sender The open channel.
 *  @param user   The user.
 */
- (void)channel:(SBDOpenChannel * _Nonnull)sender userDidExit:(SBDUser * _Nonnull)user;

/**
 *  A callback when a user was muted in the open channel.
 *
 *  @param sender The open channel.
 *  @param user   The user who was muted.
 */
- (void)channel:(SBDOpenChannel * _Nonnull)sender userWasMuted:(SBDUser * _Nonnull)user;

/**
 *  A callback when a user was unmuted in the open channel.
 *
 *  @param sender The open channel.
 *  @param user   The user who was unmuted.
 */
- (void)channel:(SBDOpenChannel * _Nonnull)sender userWasUnmuted:(SBDUser * _Nonnull)user;

/**
 *  A callback when a user was banned in the open channel.
 *
 *  @param sender The open channel.
 *  @param user   The user who was banned.
 */
- (void)channel:(SBDOpenChannel * _Nonnull)sender userWasBanned:(SBDUser * _Nonnull)user;

/**
 *  A callback when a user was unbanned in the open channel.
 *
 *  @param sender The open channel.
 *  @param user   The user who was unbanned.
 */
- (void)channel:(SBDOpenChannel * _Nonnull)sender userWasUnbanned:(SBDUser * _Nonnull)user;

/**
 *  A callback when an open channel was frozen.
 *
 *  @param sender The open channel.
 */
- (void)channelWasFrozen:(SBDOpenChannel * _Nonnull)sender;

/**
 *  A callback when an open channel was unfrozen.
 *
 *  @param sender The open channel.
 */
- (void)channelWasUnfrozen:(SBDOpenChannel * _Nonnull)sender;

/**
 *  A callback when an open channel was changed.
 *
 *  @param sender The open channel.
 */
- (void)channelWasChanged:(SBDBaseChannel * _Nonnull)sender;

/**
 *  A callback when an open channel was deleted.
 *
 *  @param channelUrl The open channel.
 */
- (void)channelWasDeleted:(NSString * _Nonnull)channelUrl channelType:(SBDChannelType)channelType;

/**
 *  A callback when a message was removed in the channel.
 *
 *  @param sender    The base channel.
 *  @param messageId The message ID which was removed.
 */
- (void)channel:(SBDBaseChannel * _Nonnull)sender messageWasDeleted:(long long)messageId;

@end

/**
 *  The `SBDBaseChannel` class represents the channel where users chat each other. The `SBDOpenChannel` and the `SBDGroupChannel` are derived from this class. This class provides the common methods for the `SBDOpenChannel` and the `SBDGroupChannel`.
 *
 *  * Send a user message to the channel.
 *  * Send a file message to the channel.
 *  * Delete a message of the channel.
 *  * Create a query for loading messages of the channel.
 *  * Manipulate meta counters and meta <span>data</span> of the channel.
 *
 *  The channel objects are maintained as a single instance in an application. If you create or get channels from the same channel URL, they must be the same instances.
 */
@interface SBDBaseChannel : NSObject

/**
 *  The channel URL.
 */
@property (strong, nonatomic, nonnull) NSString *channelUrl;

/**
 *  The name of channel.
 */
@property (strong, nonatomic, nonnull) NSString *name;

/**
 *  The channel cover image URL.
 */
@property (strong, nonatomic, nullable) NSString *coverUrl;

/**
 *  The timestamp when the channel is created.
 */
@property (atomic) NSUInteger createdAt;

/**
 *  The custom date of the channel.
 */
@property (strong, nonatomic, nullable) NSString *data;

/**
 *  The custom type of the channel.
 */
@property (strong, nonatomic, nullable) NSString *customType;

- (nullable instancetype)initWithDictionary:(NSDictionary * _Nonnull)dict;

/**
 *  Sends a user message without <span>data</span>.
 *
 *  @param message           The message text.
 *  @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary user message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a user message without <span>data</span>. The message will be translated into the target languages.
 *
 *  @param message           The message text.
 *  @param targetLanguages   The target languages that the message will be translated into.
 *  @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary user message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message targetLanguages:(NSArray<NSString *> * _Nullable)targetLanguages completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a user message with <span>data</span>.
 *
 *  @param message        The message text.
 *  @param data           The message <span>data</span>.
 *  @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary user message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message data:(NSString * _Nullable)data completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a user message with <span>data</span>. The message will be translated into the target languages.
 *
 *  @param message        The message text.
 *  @param data           The message <span>data</span>.
 *  @param targetLanguages   The target languages that the message will be translated into.
 *  @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary user message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message data:(NSString * _Nullable)data targetLanguages:(NSArray<NSString *> * _Nullable)targetLanguages completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a user message with <span>data</span> and <span>custom message type</span>.
 *
 *  @param message        The message text.
 *  @param data           The message <span>data</span>.
 *  @param customType     Custom message type.
 *  @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary user message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message data:(NSString * _Nullable)data customType:(NSString * _Nullable)customType completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a user message with <span>data</span> and <span>custom message type</span>. The message will be translated into the target languages.
 *
 *  @param message        The message text.
 *  @param data           The message <span>data</span>.
 *  @param customType     Custom message type.
 *  @param targetLanguages   The target languages that the message will be translated into.
 *  @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary user message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message data:(NSString * _Nullable)data customType:(NSString * _Nullable)customType targetLanguages:(NSArray<NSString *> * _Nullable)targetLanguages completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to SendBird file storage and a URL of the file will be generated.
 *
 *  @param file              File <span>data</span>.
 *  @param filename          File<span>name</span>.
 *  @param type              The type of file.
 *  @param size              File size.
 *  @param data              Custom <span>data</span>.
 *  @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the SendBird server. The message has a message ID and an URL.
 *
 *  @return Returns the temporary file message with a request ID. It doesn't have a message ID and an URL.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file filename:(NSString * _Nonnull)filename type:(NSString * _Nonnull)type size:(NSUInteger)size data:(NSString * _Nullable)data completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to SendBird file storage and a URL of the file will be generated.
 *
 *  @param file              File <span>data</span>.
 *  @param filename          File<span>name</span>.
 *  @param type              The type of file.
 *  @param size              File size.
 *  @param data              Custom <span>data</span>.
 *  @param customType        Custom message type.
 *  @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the SendBird server. The message has a message ID and an URL.
 *
 *  @return Returns the temporary file message with a request ID. It doesn't have a message ID and an URL.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file filename:(NSString * _Nonnull)filename type:(NSString * _Nonnull)type size:(NSUInteger)size data:(NSString * _Nullable)data customType:(NSString * _Nullable)customType completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a file message with file URL.
 *
 *  @param url               File URL.
 *  @param type              The type of file.
 *  @param size              File size.
 *  @param data              Custom <span>data</span>.
 *  @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary file message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithUrl:(NSString * _Nonnull)url size:(NSUInteger)size type:(NSString * _Nonnull)type data:(NSString * _Nullable)data completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a file message with file URL and <span>custom message type</span>.
 *
 *  @param url               File URL.
 *  @param type              The type of file.
 *  @param size              File size.
 *  @param data              Custom <span>data</span>.
 *  @param customType        Custom message type.
 *  @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the SendBird server. The message has a message ID.
 *
 *  @return Returns the temporary file message with a request ID. It doesn't have a message ID.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithUrl:(NSString * _Nonnull)url size:(NSUInteger)size type:(NSString * _Nonnull)type data:(NSString * _Nullable)data customType:(NSString * _Nullable)customType completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to SendBird file storage and a URL of the file will be generated. The uploading progress callback can be implemented.
 *
 *  @param file              File <span>data</span>.
 *  @param filename          File<span>name</span>.
 *  @param type              The type of file.
 *  @param size              File size.
 *  @param data              Custom <span>data</span>.
 *  @param progressHandler   The handler block to monitor progression.  `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the SendBird server. The message has a message ID and an URL.
 *
 *  @return Returns the temporary file message with a request ID. It doesn't have a message ID and an URL.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file filename:(NSString * _Nonnull)filename type:(NSString * _Nonnull)type size:(NSUInteger)size data:(NSString * _Nullable)data progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 *  Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to SendBird file storage and a URL of the file will be generated. The uploading progress callback can be implemented.
 *
 *  @param file              File <span>data</span>.
 *  @param filename          File<span>name</span>.
 *  @param type              The type of file.
 *  @param size              File size.
 *  @param data              Custom <span>data</span>.
 *  @param customType        Custom message type.
 *  @param progressHandler   The handler block to monitor progression.  `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the SendBird server. The message has a message ID and an URL.
 *
 *  @return Returns the temporary file message with a request ID. It doesn't have a message ID and an URL.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file filename:(NSString * _Nonnull)filename type:(NSString * _Nonnull)type size:(NSUInteger)size data:(NSString * _Nullable)data customType:(NSString * _Nullable)customType progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

#pragma mark - Load message list
/**
 *  Creates `SBDPreviousMessageListQuery` instance for getting the previous messages list of the channel.
 *
 *  @return Returns the message list of the channel.
 */
- (nullable SBDPreviousMessageListQuery *)createPreviousMessageListQuery;

/**
 *  Creates `SBDMessageListQuery` instance for getting the previous messages list of the channel.
 *
 *  @return Returns the message list of the channel.
 */
- (nullable SBDMessageListQuery *)createMessageListQuery;

#pragma mark - Meta Counters
/**
 *  Creates the meta counters for the channel.
 *
 *  @param metaCounters      The meta counters to be set.
 *  @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are set on SendBird server.
 */
- (void)createMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the meta counters with keys for the channel.
 *
 *  @param keys              The keys to get meta counters.
 *  @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are set on SendBird server.
 */
- (void)getMetaCountersWithKeys:(NSArray<NSString *> * _Nullable)keys completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/**
 *  Gets all meta counters for the channel.
 *
 *  @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are returned from SendBird server.
 */
- (void)getAllMetaCountersWithCompletionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/**
 *  Updates the meta counters for the channel.
 *
 *  @param metaCounters      The meta counters to be updated.
 *  @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are updated on SendBird server.
 */
- (void)updateMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/**
 *  Increases the meta counters for the channel.
 *
 *  @param metaCounters      The meta counters to be increased.
 *  @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are increased on SendBird server.
 */
- (void)increaseMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/**
 *  Decreases the meta counters for the channel.
 *
 *  @param metaCounters      The meta counters to be decreased.
 *  @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are decreased on SendBird server.
 */
- (void)decreaseMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/**
 *  Deletes the meta counters with key for the channel.
 *
 *  @param key               The key to be deleted.
 *  @param completionHandler The handler block to execute.
 */
- (void)deleteMetaCountersWithKey:(NSString * _Nonnull)key completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Deletes all meta counters for the channel.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)deleteAllMetaCountersWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

#pragma mark - Meta Data
/**
 *  Creates the meta <span>data</span> for the channel.
 *
 *  @param metaData          The meta <span>data</span> to be set.
 *  @param completionHandler The handler block to execute. `metaData` is the meta <span>data</span> which are set on SendBird server.
 */
- (void)createMetaData:(NSDictionary<NSString *, NSString *> * _Nonnull)metaData completionHandler:(nullable void (^)(NSDictionary<NSString *, NSString *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the meta <span>data</span> for the channel.
 *
 *  @param keys              The keys to get meta <span>data</span>.
 *  @param completionHandler The handler block to execute. `metaData` is the meta <span>data</span> which are set on SendBird server.
 */
- (void)getMetaDataWithKeys:(NSArray<NSString *> * _Nullable)keys completionHandler:(nullable void (^)(NSDictionary<NSString *, NSObject *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/**
 *  Gets all meta <span>data</span> for the channel.
 *
 *  @param completionHandler The handler block to execute. `metaData` is the meta <span>data</span> which are set on SendBird server.
 */
- (void)getAllMetaDataWithCompletionHandler:(nullable void (^)(NSDictionary<NSString *, NSObject *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/**
 *  Updates the meta <span>data</span> for the channel.
 *
 *  @param metaData          The meta <span>data</span> to be updated.
 *  @param completionHandler The handler block to execute. `metaData` is the meta counters which are updated on SendBird server.
 */
- (void)updateMetaData:(NSDictionary<NSString *, NSString *> * _Nonnull)metaData completionHandler:(nullable void (^)(NSDictionary<NSString *, NSObject *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/**
 *  Deletes meta <span>data</span> with key for the channel.
 *
 *  @param key               The key to be deleted.
 *  @param completionHandler The handler block to execute.
 */
- (void)deleteMetaDataWithKey:(NSString * _Nonnull)key completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Deletes all meta <span>data</span> for the channel.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)deleteAllMetaDataWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Deletes a message. The message's sender has to be the current user.
 *
 *  @param message           The message to be deleted.
 *  @param completionHandler The handler block to execute.
 */
- (void)deleteMessage:(SBDBaseMessage * _Nonnull)message completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Checks the channel type.
 *
 *  @return If YES, this channel is a group channel.
 */
- (BOOL)isGroupChannel;

/**
 *  Checks the channel type.
 *
 *  @return If YES, this channel is an open channel.
 */
- (BOOL)isOpenChannel;

@end
