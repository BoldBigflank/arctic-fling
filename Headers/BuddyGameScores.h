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


// BuddyGameScores callback definitions

/** Callback signature for the BuddyGameScoresGetAll function.  The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise  If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameScoresGetAllCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyGameScoresDeleteAll function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameScoresDeleteAllCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyGameScoresAdd function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameScoresAddCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represents a class that can be used to add, retrieve or delete game scores for any user in the system.
/// </summary>

/**
 * \code
 * Example:
 *
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  __block BuddyAuthenticatedUser *_user;
 *
 * [bc Login:@"username" password:@"password"  callback: [^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          _user = response.result;
 *
 *          // add a new score for this user to the MyGame board
 *          [_user.gameScores add:100 board:@"MyGame" rank:@"Master" latitude:0 longitude:0 oneScorePerPlayer:FALSE appTag:@"MyTag"  callback:[^(BuddyBoolResponse *response)
 *          {
 *              if (response.isCompleted && response.result)
 *              {
 *                  // score was added OK ... so now get all games scores for this user on all boards/games
 *                  NSNumber *recordLimit = (NSNumber numberWithInt:100];
 *
 *                  __block  NSArray *_gameScores;
 *                  [_user.gameScores getAll:ns  callback:[^(BuddyArrayResponse *response)
 *                  {
 *                      if (response.isCompleted && response.result)
 *                      { // get the array of game scores and, for example, send them to some UI display function
 *                          _gameScores =  response.result;
 *                          dispatch_async(dispatch_get_main_queue(), ^{[self displayAllScores:_gameScores]; });
 *                      }
 *                  }copy]]
 *              }
 *          } copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyGameScores : NSObject


/// <summary>
/// Return all score entries for this user.
/// </summary>
/// <param name="recordLimit">Limit the number of entries returned.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(NSNumber *)recordLimit
         
      callback:(BuddyGameScoresGetAllCallback)callback;

/// <summary>
/// Return all score entries for this user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getAll:(BuddyGameScoresGetAllCallback)callback;

/// <summary>
/// Delete all scores for this user.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)deleteAll:(BuddyGameScoresDeleteAllCallback)callback;

/// <summary>
/// Add a new score for this user.
/// </summary>
/// <param name="score">The numeric value of the score.</param>
/// <param name="board">The optional name of the game board, can be nil.</param>
/// <param name="rank">The optional rank for this score. This can be used for adding badges, achievements, etc, can be nil.</param>
/// <param name="latitude">Optional latitude for this score.</param>
/// <param name="longitude">Optional longitude for this score.</param>
/// <param name="oneScorePerPlayer">The one-score-per-player parameter. Setting this to true will always update the score for this user, instead of creating a new one.</param>
/// <param name="appTag">An optional application tag for this score, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)add:(double)score
      board:(NSString *)board
       rank:(NSString *)rank
   latitude:(double)latitude
        longitude:(double)longitude
oneScorePerPlayer:(BOOL)oneScorePerPlayer
           appTag:(NSString *)appTag
            
         callback:(BuddyGameScoresAddCallback)callback;

/// <summary>
/// Add a new score for this user.
/// </summary>
/// <param name="score">The numeric value of the score.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>
- (void)add:(double)score
   callback:(BuddyGameScoresAddCallback)callback;

@end