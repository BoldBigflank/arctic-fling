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


@class BuddyArrayResponse;


// BuddyGameBoards callback definitions

/** Callback signature for the BuddyGameBoardsGetScores function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameBoardsGetScoresCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyGameBoardsFindScores function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyGameBoardsFindScoresCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents an object that can be used to retrieve Buddy Game Boards and Scores.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *buddyClient = [[BuddyClient alloc] initClient:appName
 *                                                 appPassword:appPassword];
 *
 * [buddyClient login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *    if (response.isCompleted)
 *     {   // get the user
 *         BuddyAuthenticatedUser *user = response.result;
 *
 *         // add a game score
 *         [user.gameScores add:100 callback: nil];
 *
 *         [buddyClient.gameBoards getHighScores:user boardName:@"MyBoard" callback:^(BuddyArrayResponse *response)
 *         {
 *              if (response.isCompleted && response.result)
 *              {
 *                  for(id _bgs in response.result)
 *                  {
 *                      BuddyGameScore *bgs = (BuddyGameScore *) _bgs;
 *                      // do something with game score
 *                  }
 *              }
 *         }];
 *     }
 *  }];
 * \endcode
 */

@interface BuddyGameBoards : NSObject

/// <summary>
/// Gets a list of high scores for a specific game board.
/// </summary>
/// <param name="boardName">The board name can be a specific string or a 'LIKE' pattern using %.</param>
/// <param name="recordLimit">The maximum number of scores to return.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getHighScores:(NSString *)boardName
          recordLimit:(NSNumber *)recordLimit
             callback:(BuddyGameBoardsGetScoresCallback)callback;

/// <summary>
/// Gets a list of high scores for a specific game board.
/// </summary>
/// <param name="boardName">The board name can be a specific string or a 'LIKE' pattern using %.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getHighScores:(NSString *)boardName
             callback:(BuddyGameBoardsGetScoresCallback)callback;

/// <summary>
/// Gets a list of low scores for a specific game board.
/// </summary>
/// <param name="boardName">The board name can be a specific string or a 'LIKE' pattern using %.</param>
/// <param name="recordLimit">The maximum number of scores to return.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getLowScores:(NSString *)boardName
          recordLimit:(NSNumber *)recordLimit\
             callback:(BuddyGameBoardsGetScoresCallback)callback;

/// <summary>
/// Gets a list of low scores for a specific game board.
/// </summary>
/// <param name="boardName">The board name can be a specific string or a 'LIKE' pattern using %.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getLowScores:(NSString *)boardName
             callback:(BuddyGameBoardsGetScoresCallback)callback;

/// <summary>
/// Search for game scores based on a number of different parameters.
/// </summary>
/// <param name="user">Optionally limit the search to a specific user, can be nil.</param>
/// <param name="distanceInMeters">Optionally specify a distance from a lat/long to search on. By default this is ignored, can be nil.</param>
/// <param name="latitude">Optional latitude where we can start the search.</param>
/// <param name="longitude">Optional longitude where we can start the search.</param>
/// <param name="recordLimit">Optionally limit the number of records returned by this search, can be nil.</param>
/// <param name="boardName">Optionally filter on a specific board name, can be nil.</param>
/// <param name="daysOld">Optionally only return scores that are X number of days old, can be nil.</param>
/// <param name="minimumScore">Optionally only return scores that are above a certain minimum score, can be nil.</param>
/// <param name="appTag">Optionally return only scores that have a certain app tag, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyGameScore items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)findScores:(BuddyUser *)user
  distanceInMeters:(NSNumber *)distanceInMeters
          latitude:(double)latitude
         longitude:(double)longitude
       recordLimit:(NSNumber *)recordLimit
         boardName:(NSString *)boardName
           daysOld:(NSNumber *)daysOld
      minimumScore:(NSNumber *)minimumScore
            appTag:(NSString *)appTag
             
          callback:(BuddyGameBoardsFindScoresCallback)callback;

@end

