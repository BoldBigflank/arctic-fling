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
@class BuddyGamePlayerResponse;


// BuddyGamePlayers callback definitions

/** Callback signature for the BuddyPlayersAdd function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyPlayersAddCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyPlayersUpdate function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyPlayersUpdateCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyPlayersDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyPlayersDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyPlayersGetInfo function. The .result field of the BuddyGamePlayerResponse will be a BuddyGamePlayer instance containing player info for this user if the request was successful (BuddyGamePlayerResponse.isCompleted == TRUE and data was found on the server) or otherwise nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyPlayersGetInfoCallback)(BuddyGamePlayerResponse *response);

/** Callback signature for the BuddyPlayersFind function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGamePlayer items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyPlayersFindCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents a player in a game. The Player object tracks game specific items such as board, ranks, and other data specific to building game leader boards and other game related constructs.
/// </summary>

@interface BuddyGamePlayers : NSObject

/// <summary>
/// Creates a new game Player object for an existing user in Buddy.
/// </summary>
/// <param name="name">The name of the new player.</param>
/// <param name="board">An optional name of a "Board" for the game. Used for grouping scores together either by user group, levels, or some other method relevant to the game. Although optional, a value is recommended such as "Default" for use in later searches of scores. If no board is to be stored, then pass in null or leave empty.</param>
/// <param name="rank">An optional ranking to associate with the score. Can be any string ie: descriptions of achievements, ranking strings like "excellent", etc. Pass in null or an empty string if you do not wish to store a rank, can be nil.</param>
/// <param name="latitude">The latitude of the location where the Player object is being created.</param>
/// <param name="longitude">The longitude of the location where the Player object is being created.</param>
/// <param name="appTag">Optional metadata to store with the Player object. ie: a list of players, game state, etc. Leave empty or set to null if there is no data to store with the score, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)add:(NSString *)name
      board:(NSString *)board
       rank:(NSString *)rank
   latitude:(double)latitude
  longitude:(double)longitude
     appTag:(NSString *)appTag
   callback:(BuddyPlayersAddCallback)callback;

/// <summary>
/// Creates a new game Player object for an existing user in Buddy.
/// </summary>
/// <param name="name">The name of the new player.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void) add:(NSString *)name
	callback:(BuddyPlayersAddCallback)callback;

/// <summary>
/// Updates one or more fields of an existing Player object which was previously created.
/// </summary>
/// <param name="name">The name of the new player.</param>
/// <param name="board">An optional name of a "Board" for the game. Used for grouping scores together either by user group, levels, or some other method relevant to the game. Although optional, a value is recommended such as "Default" for use in later searches of scores. If no board is to be stored, then pass in null or leave empty.</param>
/// <param name="rank">An optional ranking to associate with the score. Can be any string ie: descriptions of achievements, ranking strings like "excellent", etc. Pass in null or an empty string if you do not wish to store a rank, can be nil.</param>
/// <param name="latitude">The latitude of the location where the Player object is being updated.</param>
/// <param name="longitude">The longitude of the location where the Player object is being updated.</param>
/// <param name="appTag">Optional metadata to store with the Player object. ie: a list of players, game state, etc. Leave empty or set to null if there is no data to store with the score, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)update:(NSString *)name
         board:(NSString *)board
          rank:(NSString *)rank
      latitude:(double)latitude
     longitude:(double)longitude
        appTag:(NSString *)appTag
      callback:(BuddyPlayersUpdateCallback)callback;

/// <summary>
/// Updates one or more fields of an existing Player object which was previously created.
/// </summary>
/// <param name="name">The name of the new player.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>
- (void)update:(NSString *)name
	  callback:(BuddyPlayersUpdateCallback)block;

/// <summary>
/// Delete the player object for this user.
/// </summary>
/// <param name="callback">The async callback to call on success or error. The first parameter is true on success, false otherwise.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>
- (void)delete:(BuddyPlayersDeleteCallback)callback;

/// <summary>
/// Get all the player info for this user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyGamePlayerResponse will be a BuddyGamePlayer instance containing player info for this user if the request was successful (BuddyGamePlayerResponse.isCompleted == TRUE and data was found on the server) or otherwise nil.</param>

- (void)getInfo:(BuddyPlayersGetInfoCallback)callback;

/// <summary>
/// Searches for Player objects stored in the Buddy system. Searches can optionally be performed based on location.
/// </summary>
/// <param name="searchDistanceInMeters">The radius (in meters) around the specified location in which to look for locations. Pass in -1 to ignore this field.</param>
/// <param name="latitude">The latitude of the location around which to search for locations within the specified SearchDistance.</param>
/// <param name="longitude">The longitude of the location around which to search for locations within the specified SearchDistance.	</param>
/// <param name="recordLimit">The maximum number of search results to return or -1 to return all search results, can be nil.</param>
/// <param name="boardName">Searches for scores which contain the specified board. Leave empty or pass in null if no board filter is to be used, can be nil.</param>
/// <param name="onlyForLastNumberOfDays">The number of days into the past for which to look for scores. ie: passing in 5 will filter scores to include those which were added/updated on or after 5 days ago. Pass in -1 to ignore this filter, can be nil.</param>
/// <param name="appTag">Searches for scores with the specified applicationTag stored with them. Leave empty or pass in null to ignore this filter, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGamePlayer items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)find:(NSNumber *)searchDistanceInMeters
    latitude:(double)latitude
   longitude:(double)longitude
 recordLimit:(NSNumber *)recordLimit
              boardName:(NSString *)boardName
onlyForLastNumberOfDays:(NSNumber *)onlyForLastNumberOfDays
                 appTag:(NSString *)appTag
               callback:(BuddyPlayersFindCallback)callback;

@end
