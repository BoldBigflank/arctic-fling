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
@class BuddyArrayResponse;


// BuddyFriend callback definitions

/** Callback signature for the BuddyFriendRequestsGetAll function. The .result field of the BuddyArrayResponse will be an NSArray of BuddyUser items that have pending friend requests if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendRequestsGetAllCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyFriendRequestsAdd function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendRequestsAddCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyFriendRequestsAccept function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise (i.e. the user doesn't exist). If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendRequestsAcceptCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyFriendRequestsDeny function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise (i.e. the user doesn't exist). If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendRequestsDenyCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represents a collection of friend requests. Use the Add method to request a friend connection from another user.
/// </summary>

/**
 * \code
 *  Example:
 *
 * BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                       appPassword:appPassword];
 *
 * // create a user
 * [bc createUser:@"Username1" password:@"Password1"  callback:^(BuddyAuthenticatedUserResponse *response)
 * {
 *   if (response.isCompleted && response.result)
 *   {
 *      BuddyAuthenticatedUser *user1 = response.result;
 *      // create a second user
 *      [bc createUser:@"Username2" password:@"Password2"  callback:^(BuddyAuthenticatedUserResponse *response)
 *      {
 *          if (response.isCompleted && response.result)
 *          {
 *              BuddyAuthenticatedUser *user2 = response.result;
 *
 *              // user1 sends a friend request ... to user2
 *              [user1.friends.requests add:user2 appTag:nil  callback:^(BuddyBoolResponse *response)
 *              {
 *                  if (response.isCompleted && response.result)
 *                  { // request was send .... user2 accepts friend request from user1
 *                      [user2.friends.requests accept:user1 appTag:nil   callback:nil];
 *                  }
 *              }];
 *          }
 *      }];
 *   }
 * }];
 * \endcode
 */


@interface BuddyFriendRequests : NSObject

/// <summary>
/// Add a friend request to a user.
/// </summary>
/// <param name="user">The user to send the request to, can't be null.</param>
/// <param name="appTag">Mark this request with an tag, can be used on the user's side to make a decision on whether to accept the request.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)add:(BuddyUser *)user
     appTag:(NSString *)appTag
   callback:(BuddyFriendRequestsAddCallback)callback;

/// <summary>
/// Add a friend request to a user.
/// </summary>
/// <param name="user">The user to send the request to, can't be null.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)add:(BuddyUser *)user
   callback:(BuddyFriendRequestsAddCallback)callback;

/// <summary>
/// A list of all users that have request to be friends with this user.
/// </summary>
/// <param name="afterDate">Filter the list by returning only the friend requests after a certain date.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyUser items that have pending friend requests if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(NSDate *)afterDate
         
      callback:(BuddyFriendRequestsGetAllCallback)callback;

/// <summary>
/// A list of all users that have request to be friends with this user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyUser items that have pending friend requests if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(BuddyFriendRequestsGetAllCallback)callback;

/// <summary>
/// Accept a friend request from a user.
/// </summary>
/// <param name="user">The user to accept as friend. Can't be null and must be on the friend requests list.</param>
/// <param name="appTag">Tag this friend accept with a string.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise (i.e. the user doesn't exist).</param>

- (void)accept:(BuddyUser *)user
        appTag:(NSString *)appTag
         
      callback:(BuddyFriendRequestsAcceptCallback)callback;

/// <summary>
/// Accept a friend request from a user.
/// </summary>
/// <param name="user">The user to accept as friend. Can't be null and must be on the friend requests list.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise (i.e. the user doesn't exist).</param>

- (void)accept:(BuddyUser *)user
      callback:(BuddyFriendRequestsAcceptCallback)callback;

/// <summary>
/// Deny the friend request from a user.
/// </summary>
/// <param name="user">The user to deny the friend request from. user can't be null and must be on the friend request list.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)deny:(BuddyUser *)user
       
    callback:(BuddyFriendRequestsDenyCallback)callback;

@end
