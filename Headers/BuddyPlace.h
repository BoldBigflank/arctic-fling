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


// BuddyPlace callback definitions

/** Callback signature for the BuddyPlaceSetTag function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPlaceSetTagCallback)(BuddyBoolResponse *response);

/// <summary>
/// Represents a single, named location in the Buddy system that's not a user. Locations are related to stores, hotels, parks, etc.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *  __block NSArray *_placesArray;
 *
 *  [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          NSNumber *distance = [NSNumber numberWithInt:1000000];
 *          // get a list of places within 1000Km of latitude 0.0 longitude 0.0
 *          [user.places find:distance callback:[^(BuddyArrayResponse *response)
 *          {
 *              if (response.isCompleted)
 *              {
 *                  _placesArray =  response.result;
 *                  // do something with the array of BuddyPlace items
 *                  dispatch_async(dispatch_get_main_queue(), ^{[self displayPlaces: _placesArray]; });
 *              }
 *          } copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyPlace : NSObject

/// <summary>
/// Gets the address of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *address;

/// <summary>
/// Gets the custom application tag data for the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appTagData;

/// <summary>
/// Gets the category ID of the location (i.e. Hotels).
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *categoryId;

/// <summary>
/// Gets the category name for the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *categoryName;

/// <summary>
/// Gets the city for the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *city;

/// <summary>
/// Gets the date the location was created in the system.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *createdDate;

/// <summary>
/// If this user profile was returned from a search, gets the distance in kilometers from the search origin.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInKiloMeters;

/// <summary>
/// If this user profile was returned from a search, gets the distance in meters from the search origin.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMeters;

/// <summary>
/// If this user profile was returned from a search, gets the distance in miles from the search origin.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMiles;

/// <summary>
/// If this user profile was returned from a search, gets the distance in yards from the search origin.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInYards;

/// <summary>
/// Gets the fax number of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *fax;

/// <summary>
/// Gets the globally unique ID of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *placeId;

/// <summary>
/// Gets the latitude of the location.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the longitude of the location.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the name of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *name;

/// <summary>
/// Gets the postal state of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *postalState;

/// <summary>
/// Gets the postal ZIP of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *postalZip;

/// <summary>
/// Gets the region of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *region;

/// <summary>
/// Gets the shortId of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *shortId;

/// <summary>
/// Gets the telephone number of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *telephone;

/// <summary>
/// Gets the last update date of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *touchedDate;

/// <summary>
/// Gets the user tag data of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *userTagData;

/// <summary>
/// Gets the website of the location.
/// </summary>
@property (readonly, nonatomic, strong) NSString *website;

/// <summary>
/// Set an application specific tag or a user tag for a place.
/// </summary>
/// <param name="appTag">The application level tag to set.</param>
/// <param name="userTag">The user-level tag to set for this Place.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)setTag:(NSString *)appTag
       userTag:(NSString *)userTag
         
      callback:(BuddyPlaceSetTagCallback)callback;

@end
