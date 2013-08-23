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


@class BuddyPlace;
@class BuddyArrayResponse;
@class BuddyDictionaryResponse;

// BuddyPlaces callback definitions

/** Callback signature for the BuddyStartupsFind function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyStartup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.  If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyStartupsFindCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyStartupsGetMetroAreaList function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMetroArea items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.  If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyStartupsGetMetroAreaListCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyStartupsGetFromMetroArea function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyStartup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.  If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyStartupsGetFromMetroAreaCallback)(BuddyArrayResponse *response);


@interface BuddyStartups : NSObject

/// <summary>
/// Searches for statups by name within the distance of the specified location. Note: To search for all startups within the distance from the specified location, leave the SearchName parameter empty.
/// </summary>
/// <param name="searchDistanceInMeters">The radius of the startup search.</param>
/// <param name="latitude">The latitude where the search should start.</param>
/// <param name="longitude">The longitude where the search should start.</param>
/// <param name="numberOfResults">The number of search results to return.</param>
/// <param name="searchForName">Optional search string, for example: "Star*" to search for all startups that begin with the string "Star".</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyStartup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)       find:(NSNumber *)searchDistanceInMeters
		   latitude:(double)latitude
		  longitude:(double)longitude
	numberOfResults:(NSNumber *)numberOfResults
	  searchForName:(NSString *)searchForName
		   callback:(BuddyStartupsFindCallback)callback;

/// <summary>
/// Searches for statups by name within the distance of the specified location.
/// </summary>
/// <param name="searchDistanceInMeters">The radius of the startup search.</param>
/// <param name="latitude">The latitude where the search should start.</param>
/// <param name="longitude">The longitude where the search should start.</param>
/// <param name="numberOfResults">The number of search results to return.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyStartup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)       find:(NSNumber *)searchDistanceInMeters
		   latitude:(double)latitude
		  longitude:(double)longitude
	numberOfResults:(NSNumber *)numberOfResults
		   callback:(BuddyStartupsFindCallback)callback;


/// <summary>
/// Gets a list of the supported metro areas for statups including the URL to an image for each area returned.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMetroArea items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getMetroAreaList:(BuddyStartupsGetMetroAreaListCallback)callback;


/// <summary>
/// Get a list of startups in the specified metro area.
/// </summary>
/// <param name="metroName">The name of the metro area within which to search for startups.</param>
/// <param name="recordLimit">The number of search results to return.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyStartup items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getFromMetroArea:(NSString *)metroName
			 recordLimit:(int)recordLimit
				callback:(BuddyStartupsGetFromMetroAreaCallback)callback;


@end
