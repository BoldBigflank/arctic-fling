/*
 * Copyright (C) 2012 Buddy Platform, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#import <Foundation/Foundation.h>


@class BuddyBoolResponse;
@class BuddyDictionaryResponse;


// BuddyMessageGroup callback definitions

/** Callback signature for the BuddyMessageGroupJoin function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupJoinCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessageGroupLeave function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupLeaveCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessageGroupAddUser function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupAddUserCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessageGroupRemoveUser function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupRemoveUserCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessageGroupDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessageGroupSendMessage function. The .result field of the BuddyDictionaryResponses object will be set to an NSDictionary of users and a boolean indicating whether the message was successfully sent to them, if the request was successful otherwise nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupSendMessageCallback)(BuddyDictionaryResponse *response);

/** Callback signature for the BuddyMessageGroupGetReceived function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGroupMessage items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupGetReceivedCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents a single message group. Message groups are groups of users that can message each other. groups can either be public, with anyone being able
/// to join them, or private - where only the user that create the group can add other users to it.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  [bc login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          // create a message group called "My group", make it open (Public)
 *          [user.messages create: @"My group" openGroup:TRUE appTag:nil callback:^(BuddyBoolResponse *response)
 *          {
 *              if (response.isCompleted && response.result == TRUE)
 *                  NSLog(@"group created Ok");
 *          }];
 *      }
 *  }];
 * \endcode
 */

@interface BuddyMessageGroup : NSObject

/// <summary>
/// Gets the App unique ID of the message group.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *groupId;

/// <summary>
/// Gets the name of the message group.
/// </summary>
@property (readonly, nonatomic, strong) NSString *name;

/// <summary>
/// Gets the DateTime the message group was created.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *createdOn;

/// <summary>
/// Gets the app tag that was associated with this message group.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appTag;

/// <summary>
/// Gets the ID of the user that created this message group.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *ownerUserId;

/// <summary>
/// Gets a list of IDs of users that belong to this message group.
/// </summary>
@property (readonly, nonatomic, strong) NSArray *memberUserIds;

/// <summary>
/// This method has the current user join this message group.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>
- (void)join:(BuddyMessageGroupJoinCallback)callback;

/// <summary>
/// This method has the current user leave this message group.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>
- (void)leave:(BuddyMessageGroupLeaveCallback)callback;

/// <summary>
/// Add a user to this message group.
/// </summary>
/// <param name="userToAdd">The user to add to the message group.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)addUser:(BuddyUser *)userToAdd
          
       callback:(BuddyMessageGroupAddUserCallback)callback;

/// <summary>
/// Remove a user from this message group.
/// </summary>
/// <param name="userToRemove">The user to remove from the group.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)removeUser:(BuddyUser *)userToRemove
             
          callback:(BuddyMessageGroupRemoveUserCallback)callback;

/// <summary>
/// Send a message to the entire message group.
/// </summary>
/// <param name="message">The message to send to this group. Must be less then 1000 characters.</param>
/// <param name="latitude">Optional latitude from where this message was sent.</param>
/// <param name="longitude">Optional longitude from where this message was sent.</param>
/// <param name="appTag">An optional application tag for this message, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponses object will be set to an NSDictionary of users and a boolean indicating whether the message was successfully sent to them if the request was successful otherwise nil if the request failed.</param>

- (void)sendMessage:(NSString *)message
           latitude:(double)latitude
          longitude:(double)longitude
             appTag:(NSString *)appTag
              
           callback:(BuddyMessageGroupSendMessageCallback)callback;

/// <summary>
/// Send a message to the entire message group.
/// </summary>
/// <param name="message">The message to send to this group. Must be less then 1000 characters.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponses object will be set to an NSDictionary of users and a boolean indicating whether the message was successfully sent to them if the request was successful otherwise nil if the request failed.</param>

- (void)sendMessage:(NSString *)message
           callback:(BuddyMessageGroupSendMessageCallback)callback;

/// <summary>
/// Get all messages this group has received.
/// </summary>
/// <param name="afterDate">Optionally return only messages sent after this date.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGroupMessage items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getReceived:(NSDate *)afterDate
              
           callback:(BuddyMessageGroupGetReceivedCallback)callback;

/// <summary>
/// Get all messages this group has received.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGroupMessage items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getReceived:(BuddyMessageGroupGetReceivedCallback)callback;

/// <summary>
/// Delete this message group.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(BuddyMessageGroupDeleteCallback)callback;

@end
