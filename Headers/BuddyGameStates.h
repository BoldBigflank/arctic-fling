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
@class BuddyGameStateResponse;


// BuddyGameStates callback definitions

/** Callback signature for the BuddyGameStatesAdd function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameStatesAddCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyGameStatesGet function. The .result field of the BuddyGameStateResponse will contain a BuddyGameState instance it the request was successful otherwise it will be nil if it doesn't exist. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameStatesGetCallback)(BuddyGameStateResponse *response);

/** Callback signature for the BuddyGameStatesUpdate function.  BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameStatesUpdateCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyGameStatesRemove function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameStatesRemoveCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyGameStatesGetAll function. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary name/value pairs for this user's GameState if the request was successful (BuddyDictionaryResponses.isCompleted == TRUE and data was found on the server) otherwise nil if the request failed.    If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
*/
typedef void (^BuddyGameStatesGetAllCallback)(BuddyDictionaryResponse *response);


/// <summary>
/// Represents a class that can be used to add, retrieve or delete game state data for any user in the system.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  [bc Login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          [user.gameStates add:@"MyGameState" gameStateValue:@"MyGameStateValue" callback:^(BuddyBoolResponse *response)
 *          {
 *              if (response.isCompleted && response.result == TRUE)
 *              { // game state added OK now go get the game state value
 *
 *                  [user.gameStates get:@"MyGameState"  callback:^(BuddyGameStateResponse *response)
 *                  {
 *                      if (response.isCompleted && response.result)
 *                      {
 *                          BuddyGameState *gs = response.result;
 *                          // do something with game state
 *                      }
 *                  }];
 *              }
 *          }];
 *      }
 *  }];
 * \endcode
 */

@interface BuddyGameStates : NSObject

/// <summary>
/// Adds a key/value pair to the user's GameState.
/// </summary>
/// <param name="gameStateKey">The game state key.</param>
/// <param name="gameStateValue">The value to persist.</param>
/// <param name="appTag">An optional application tag for this score, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)   add:(NSString *)gameStateKey
gameStateValue:(NSString *)gameStateValue
        appTag:(NSString *)appTag
         
      callback:(BuddyGameStatesAddCallback)callback;

/// <summary
/// Adds a key/value pair to the user GameState.
/// </summary>
/// <param name="gameStateKey">The game state key.</param>
/// <param name="gameStateValue">The value to persist.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)   add:(NSString *)gameStateKey
gameStateValue:(NSString *)gameStateValue
      callback:(BuddyGameStatesAddCallback)callback;

// <summary>
/// Get a GameState item with a key. The key can't be null or an empty string.
/// </summary>
/// <param name="gameStateKey">The gameStateKey to use to reference the GameState item.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyGameStateResponse will contain a BuddyGameState instance it the request was successful otherwise it will be nil if it doesn't exist.</param>

- (void)get:(NSString *)gameStateKey
      
   callback:(BuddyGameStatesGetCallback)callback;

/// <summary>
/// Update a GameState value.
/// </summary>
/// <param name="gameStateKey">The key to update.</param>
/// <param name="gameStateValue">The value to update.</param>
/// <param name="newAppTag">An optional new application tag for the value, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)update:(NSString *)gameStateKey
gameStateValue:(NSString *)gameStateValue
     newAppTag:(NSString *)newAppTag
         
      callback:(BuddyGameStatesUpdateCallback)callback;

/// <summary>
/// Update a GameState value.
/// </summary>
/// <param name="gameStateKey">The key to update.</param>
/// <param name="gameStateValue">The value to update.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)update:(NSString *)gameStateKey
gameStateValue:(NSString *)gameStateValue
      callback:(BuddyGameStatesUpdateCallback)callback;

/// <summary>
/// Remove a GameState key.
/// </summary>
/// <param name="gameStateKey">The key to remove from the GameState.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)remove:(NSString *)gameStateKey
         
      callback:(BuddyGameStatesRemoveCallback)callback;

/// <summary>
/// Get all GameState keys and values.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse will be a NSDictionary of name/value pairs for this user's GameState if the request was successful (BuddyDictionaryResponse.isCompleted == TRUE and data was found on the server) otherwise nil if the request failed.</param>

- (void)getAll:(BuddyGameStatesGetAllCallback)callback;

@end