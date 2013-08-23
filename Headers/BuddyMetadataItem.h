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


// BuddyMetadataItem callback definitions

/** Callback signature for the BuddyMetadataItemSet function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMetadataItemSetCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMetadataItemDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMetadataItemDeleteCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represents a single item of metadata. metadata is used to store custom key/value pairs at the application or user level.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *  [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *
 *       BuddyAuthenticatedUser *user = response.result;
 *
 *       // get a user metadata item called "some key"
 *       [user.metadata Get: @"some key"  callback: [^(BuddyMetadataItemResponse *response)
 *       {
 *          if (response.isCompleted && response.result != nil)
 *          { // set the key to some value
 *            BuddyMetadataItem *item = response.result;
 *            [item Set: @"some value" callback: nil];
 *          }
 *        }copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyMetadataItem : NSObject

/// <summary>
/// Gets the key for this item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *key;

/// <summary>
/// Gets the value for this item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *value;

/// <summary>
/// Gets the latitude of this item.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the longitude of this item.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the last date this item was updated.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *lastUpdateOn;

/// <summary>
/// Gets a custom application Tag for this item.
/// </summary>

@property (readonly, nonatomic, strong) NSString *applicationTag;

/// <summary>
/// Gets the latitude of the origin that was used in the metadata search.
/// </summary>
@property (readonly, nonatomic, assign) double distanceOriginLatitude;

/// <summary>
/// Gets the longitude of the origin that was used in the metadata search.
/// </summary>
@property (readonly, nonatomic, assign) double distanceOriginLongitude;

/// <summary>
/// Gets the distance in kilometers from the given origin in the metadata Search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInKilometers;

/// <summary>
/// Gets the distance in meters from the given origin in the metadata Search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMeters;

/// <summary>
/// Gets the distance in miles from the given origin in the metadata Search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMiles;

/// <summary>
/// Gets the distance in yards from the given origin in the metadata Search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInYards;

- (int)compareTo:(BuddyMetadataItem *)other;

/// <summary>
/// Updates the value of this metadata item.
/// </summary>
/// <param name="value">The new value for this item, can't be null.</param>
/// <param name="latitude">Optional latitude for this item.</param>
/// <param name="longitude">Optional longitude for this item.</param>
/// <param name="appTag">The optional application tag for this item, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)set:(NSString *)value
   latitude:(double)latitude
  longitude:(double)longitude
     appTag:(NSString *)appTag
      
   callback:(BuddyMetadataItemSetCallback)callback;

/// <summary>
/// Updates the value of this metadata item.
/// </summary>
/// <param name="value">The new value for this item, can't be null.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)set:(NSString *)value
   callback:(BuddyMetadataItemSetCallback)callback;

/// <summary>
/// Deletes this metadata item.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(BuddyMetadataItemDeleteCallback)callback;

@end
