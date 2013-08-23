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
@class BuddyMessageGroupResponse;


// BuddyMessageGroups callback definitions

/** Callback signature for the BuddyMessageGroupsCreate function. The .result field of the BuddyMessageGroupResponse will be set to a BuddyMessageGroup if the request was successful otherwise it will be nil if a group with that name already exists. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupsCreateCallback)(BuddyMessageGroupResponse *response);

/** Callback signature for the BuddyMessageGroupsCheckIfExists function. BuddyBoolResponse.result field will be TRUE if a group with the same name already exists, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupsCheckIfExistsCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessageGroupsGetAll function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessageGroup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupsGetAllCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyMessageGroupsGetMy function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessageGroup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessageGroupsGetMyCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents an object that can be used to create or query message groups for the app.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *  [bc login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          // create a message group called "My group", make it open (Public)
 *          [user.messages create: @"My group" openGroup:TRUE appTag:nil  callback:^(BuddyBoolResponse *response)
 *          {
 *              if (response.isCompleted && response.result == TRUE)
 *                  NSLog(@"group created Ok");
 *          }];
 *      }
 *  }];
 * \endcode
 */

@interface BuddyMessageGroups : NSObject


/// <summary>
/// Create a new message group.
/// </summary>
/// <param name="name">The name of the new group, must be unique for the app.</param>
/// <param name="openGroup">Optionally whether to make to group open for all user (anyone can join, set to TRUE), or closed (only the owner can add users to it set to FALSE).</param>
/// <param name="appTag">An optional application tag for this message group, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyMessageGroupResponse will be set a BuddyMessageGroup if the request was successful otherwise it will be nil if a group with that name already exists.</param>

- (void)create:(NSString *)name
     openGroup:(BOOL)openGroup
        appTag:(NSString *)appTag
         
      callback:(BuddyMessageGroupsCreateCallback)callback;

/// <summary>
/// Create a new message group.
/// </summary>
/// <param name="name">The name of the new group, must be unique for the app.</param>
/// <param name="openGroup">Optionally whether to make to group open for all user (anyone can join, set to TRUE), or closed (only the owner can add users to it set to FALSE).</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyMessageGroupResponse will be set a BuddyMessageGroup if the request was successful otherwise it will be nil if a group with that name already exists.</param>

- (void)create:(NSString *)name
     openGroup:(BOOL)openGroup
      callback:(BuddyMessageGroupsCreateCallback)callback;

/// <summary>
/// Check if a group with this name already exists.
/// </summary>
/// <param name="name">The name of the group to check for.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)checkIfExists:(NSString *)name
                
             callback:(BuddyMessageGroupsCheckIfExistsCallback)callback;

/// <summary>
/// Get all message groups for this app.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessageGroup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(BuddyMessageGroupsGetAllCallback)callback;

/// <summary>
/// Get all message groups that this user is part of.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessageGroup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getMy:(BuddyMessageGroupsGetMyCallback)callback;

@end
