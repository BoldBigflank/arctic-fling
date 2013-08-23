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
@class BuddyPlaceResponse;


// BuddyPlaces callback definitions

/** Callback signature for the BuddyPlacesFind function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyPlace items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.  If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPlacesFindCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyPlacesGetCategories function. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary of geo-location IDs' (key) and geo-location category (value) pairs if the request was successful otherwise nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPlacesGetCategoriesCallback)(BuddyDictionaryResponse *response);

/** Callback signature for the BuddyPlacesGet function. The callback to call on success or error. The .result field of the BuddyPlaceResponse will contain the BuddyPlace if the request is successful or nil if there is no place with the given ID. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPlacesGetCallback)(BuddyPlaceResponse *response);


/// <summary>
/// Represents an object that can be used to search for physical locations around the user.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *  __block NSArray *_places;
 *
 *  [bc login:@"username" password:@"password"  callback: [^((BuddyAuthenticatedUserResponse *response)
 *  {
 *  if (response.isCompleted)
 *  {   // get the user
 *      BuddyAuthenticatedUser *user = response.result;
 *
 *      NSNumber *distance = [NSNumber numberWithInt:1000000];
 *      // get a list of places within 1000Km of lat:0.0 long:0.0
 *      [user.places find:distance callback:[^(BuddyArrayResponse *response)
 *      {
 *          if (response.isCompleted)
 *          {
 *              _places =  response.result;
 *              // do something with the array of BuddyPlace items
 *              dispatch_async(dispatch_get_main_queue(), ^{[self displayePlaces: _places]; });
 *          }
 *      } copy]];
 *      }
 *  }copy]];
 *
 *
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword
 *                               autoRecordDeviceInfo:TRUE];
 *  __block NSArray *_placesArray;
 *
 *  [bc login:@"username" password:@"password"  callback:[^((BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          NSNumber *distance = [NSNumber numberWithInt:10000];
 *          // get a list of places within 10Km of Seattle Space Needle
 *          [user.places find:distance latitude:47.6205 longitude:122.3493 callback:[^(BuddyArrayResponse *response)
 *          {
 *              if (response.isCompleted)
 *              {
 *                  _placesArray =  response.result;
 *                  // do something with the array of BuddyPlace items
 *                  dispatch_async(dispatch_get_main_queue(), ^{[self displayPlaces: _placesArray]; });
 *              }
 *          }copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyPlaces : NSObject

/// <summary>
/// Find a location close to a given latitude and longitude.
/// </summary>
/// <param name="searchDistanceInMeters">The radius of the location search.</param>
/// <param name="latitude">The latitude where the search should start.</param>
/// <param name="longitude">The longitude where the search should start.</param>
/// <param name="numberOfResults">Number of result to return, can be nil will default to 100.</param>
/// <param name="searchForName">Search string, for example: "Star*" to search for all place that start with the string "Star" set to "" to ignore.</param>
/// <param name="searchCategoryId">Search category ID to narrow down the search with, to -1 to ignore, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyPlace items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)find:(NSNumber *)searchDistanceInMeters
    latitude:(double)latitude
      longitude:(double)longitude
numberOfResults:(NSNumber *)numberOfResults
   searchForName:(NSString *)searchForName
searchCategoryId:(NSNumber *)searchCategoryId
           
        callback:(BuddyPlacesFindCallback)callback;

/// <summary>
/// Find a location close to a given latitude and longitude. SearchcategoryId is defaulted to -1 and numberofResults defaulted to 100.
/// </summary>
/// <param name="searchDistanceInMeters">The radius of the location search.</param>
/// <param name="latitude">The latitude where the search should start.</param>
/// <param name="longitude">The longitude where the search should start.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyPlace items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)find:(NSNumber *)searchDistanceInMeters
    latitude:(double)latitude
   longitude:(double)longitude
    callback:(BuddyPlacesFindCallback)callback;

/// <summary>
/// Get all geo-location categories in Buddy.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary of geo-location IDs' (key) and geo-location category (value) pairs if the request was successful otherwise nil if the request failed.</param>

- (void)getCategories:(BuddyPlacesGetCategoriesCallback)block;

/// <summary>
/// Get a Place by its globally unique identifier. This method can also be used to calculate a distance from a lat/long to a place.
/// </summary>
/// <param name="placeId">The ID of the place to retrieve.</param>
/// <param name="latitude">Optional latitude to calculate a distance to.</param>
/// <param name="longitude">Optional longitude to calculate a distance to.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPlaceResponse will contain the BuddyPlace if the request is successful or nil if there is no place with the given ID.</param>

- (void)get:(NSNumber *)placeId
   latitude:(double)latitude
  longitude:(double)longitude
      
   callback:(BuddyPlacesGetCallback)callback;

/// <summary>
/// Get a Place by its globally unique identifier. This method can also be used to calculate a distance from a lat/long to a place.
/// </summary>
/// <param name="placeId">The ID of the place to retrieve.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPlaceResponse  will contain the BuddyPlace if the request is successful or nil if there is no place with the given ID.</param>

- (void)get:(NSNumber *)placeId
   callback:(BuddyPlacesGetCallback)callback;

@end
