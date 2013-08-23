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


// BuddyIdentity callback definitions

/** Callback signature for the BuddyIdentityGetAll function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyIdentityItem items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyIdentityGetAllCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyIdentityAdd function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyIdentityAddCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyIdentityRemove function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyIdentityRemoveCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyIdentityCheckForValues function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyIdentityItemSearchResult items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyIdentityCheckForValuesCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents a class that can access identity values for a user or search for values across the entire app. Identity values can be used to share public
/// information between users, for example hashes of email address that can be used to check whether a certain user is in the system.
/// </summary>

/**
 * \code
 * Example:
 *   BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                         appPassword:appPassword];
 *
 *  __block NSArray *_identitySearchItems;
 *  [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *          // get all identify items
 *          [user.identityValues getAll:nil callback:[^(BuddyArrayResponses *response)
 *          {
 *              if (response.isCompleted && response.result != nil)
 *              {  // get the array of  BuddyIdentityItemSearchResult items
 *                  _identitySearchItems   = response.result;
 *                 // queue for processing
 *                  dispatch_async(dispatch_get_main_queue(), ^{[self processItems: _identitySearchItems]; });
 *              }
 *          }copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyIdentity : NSObject

/// <summary>
/// Returns all the identity values for this user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponses will contain an NSArray of BuddyIdentityItem items if the request was successful (BuddyArrayResponses.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(BuddyIdentityGetAllCallback)callback;

/// <summary>
/// Add an identity value for this user.
/// </summary>
/// <param name="value">The value to add.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)add:(NSString *)value
      
   callback:(BuddyIdentityAddCallback)callback;

/// <summary>
/// Remove an identity value for this user.
/// </summary>
/// <param name="value">The value to remove.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)remove:(NSString *)value
         
      callback:(BuddyIdentityRemoveCallback)callback;

/// <summary>
/// Check for the existence of an identity value in the system. The search is perform for the entire app.
/// </summary>
/// <param name="values">The value to search for. This can either be a single value or a semi-colon separated list of values.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponses will contain an NSArray of BDYIdentityItemSearchResult items if the request was successful (BuddyArrayResponses.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)checkForValues:(NSString *)values
                 
              callback:(BuddyIdentityCheckForValuesCallback)callback;

@end