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
#import "BuddyFriendRequests.h"


@class BuddyBoolResponse;
@class BuddyArrayResponse;


// BuddyFriends callback definitions

/** Callback signature for the BuddyFriendsGet function. The .result field of the BuddyArrayResponse object will be set to a NSArray of BuddyUser items if successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendsGetCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyFriendsRemove function. The .result field of the BuddyBoolResponse object will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendsRemoveCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyFriendsFind function.The .result field of the BuddyArrayResponse will be a NSArray of BuddyUser items if successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil.  If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendsFindCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyFriendsBlock function. The .result field of the BuddyBoolResponse object will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
*/
typedef void (^BuddyFriendsBlockCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyFriendsUnBlock function. The .result field of the BuddyBoolResponse object will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
*/
typedef void (^BuddyFriendsUnBlockCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyFriendsGetBlocked function. The .result field of the BuddyArrayResponse will an NSArray of blocked BuddyUser's if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyFriendsGetBlockedCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents a collection of friends. Use the AuthenticatedUser.friends property to access this object.
/// </summary>

/**
 * \code
 * Example:
 *   BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                         appPassword:appPassword];
 *  // create a user
 *  [bc createUser:@"Username1" password:@"Password1"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {
 *          BuddyAuthenticatedUser *user1 = response.result;
 *
 *          // create a second user
 *          [bc createUser:@"Username2" password:@"Password2"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *          {
 *              if (response.isCompleted && response.result)
 *              {
 *                  BuddyAuthenticatedUser *user2 = response.result;
 *
 *                  // user1 sends a friend request ... to user2
 *                  [user1.friends.requests add:user2 appTag:nil  callback:^(BuddyBoolResponse *response)
 *                  {
 *                      if (response.isCompleted && response.result)
 *                      { // request was send .... user2 accepts friend request from user1
 *                        [user2.friends.requests accept:user1 appTag:nil  callback:nil];
 *                      }
 *                  }]
 *              }
 *          }];
 *      }
 *  }];
 * \endcode
 */

@interface BuddyFriends : NSObject

/// <summary>
/// Gets a list of friend requests that are still pending for this user.
/// </summary>
@property (readonly, nonatomic, strong) BuddyFriendRequests *requests;

/// <summary>
/// Returns the list of friends for the currently logged in user.
/// </summary>
/// <param name="afterDate">Filter the list by friends added 'afterDate'.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyUser items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(NSDate *)afterDate
         
      callback:(BuddyFriendsGetCallback)callback;

/// <summary>
/// Returns the list of friends for the currently logged in user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyUser items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(BuddyFriendsGetCallback)callback;

/// <summary>
/// Remove a user from the current list of friends.
/// </summary>
/// <param name="user">The user to remove from the friends list. Must be already on the list and can't be null.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)remove:(BuddyUser *)user
         
      callback:(BuddyFriendsRemoveCallback)callback;

@end