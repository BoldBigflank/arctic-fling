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
@class BuddyDictionaryResponse;
@class BuddyMetadataItemResponse;
@class BuddyMetadataSumResponse;


// BuddyAppMetadata callback definitions

/** Callback signature for the BuddyAppMetadataGetAll function. The .result field of the BuddyDictionaryResponse will be an NSDictionary of metadata keys mapped to items if the request was successful (BuddyDictionaryResponse.isCompleted == TRUE and data was found on the server) otherwise an empty NSDictionary if the request failed or no data was found. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataGetAllCallback)(BuddyDictionaryResponse *response);

/** Callback signature for the BuddyAppMetadataGet function. The .result field of the BuddyMetadataItemResponse will be set to a BuddyMetadataItem instance for the requested key if successful (BuddyMetadataItemResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataGetCallback)(BuddyMetadataItemResponse *response);

/** Callback signature for the BuddyAppMetadataSet function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataSetCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAppMetadataDelete function. The .result field of the BuddyBoolResponse will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server,i f any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAppMetadataDeleteAll function. The .result field of the BuddyBoolResponse will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataDeleteAllCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAppMetadataFind function. The .result field of the BuddyDictionaryResponse will be an NSDictionary of metadata keys mapped to items if the request was successful (BuddyDictionaryResponse.isCompleted == TRUE and data was found on the server) otherwise nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataFindCallback)(BuddyDictionaryResponse *response);

/** Callback signature for the BuddyAppMetadataBatchSum function. The .result field of the BuddyArrayResponse will be an NSArray of BuddyMetadataSum items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataBatchSumCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyAppMetadataSum function. The .result field of the BuddyMetadataSumResponse will be set to a BuddyMetadataSum instance (containing the sum of all the found metadata item values requested) if the request was successful (BuddyMetadataSumResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAppMetadataSumCallback)(BuddyMetadataSumResponse *response);


@class BuddyMetadataItem;

/// <summary>
/// Represents a collection of application level metadata items. You can access this class through the BuddyClient object.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  // assign a value to a metadata key
 *  [bc.metadata Set: @"test key" value: @"test value" callback:nil];
 *
 *  // now search for items within 1000 meters of lat:0.0 long:0.0
 *  // using short form Find SDK function which defaults search params
 *
 *  NSNumber *searchDistance = [NSNumber numberWithInt:1000]
 *
 *  [bc.metadata find:searchDistance callback:^(BuddyArrayResponses *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {
 *          NSArray *metadataItems = response.result;
 *          // do something with the array of BuddyMetadataItems
 *      }
 *  }];
 * \endcode
 */

@interface BuddyAppMetadata : NSObject

/// <summary>
/// Get all the metadata items for this application. Note that this can be a very time-consuming method, try to retrieve specific items if possible
/// or do a search.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary of metadata item/pairs if the request was successful (BuddyDictionaryResponse.isCompleted == TRUE and data was found on the server)  otherwise nil if the request failed.</param>

- (void)getAll:(BuddyAppMetadataGetAllCallback)callback;

/// <summary>
/// Get a metadata item with a key. The key can't be null or an empty string.
/// </summary>
/// <param name="key">The key to use to reference the metadata item.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyMetadataItemResponse will be set to a BuddyMetadataItem instance for the requested key if successful (BuddyMetadataItemResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil.</param>

- (void)get:(NSString *)key
      
   callback:(BuddyAppMetadataGetCallback)callback;

/// <summary>
/// Set a metadata item value for a key. You can additionally add latitude and longitude coordinates to record the location
/// from where this item was set, or tag the item with a custom tag.
/// The item doesn't have to exist to be set, this method acts as an Add method in cases where the item doesn't exist.
/// </summary>
/// <param name="key">The key of the metadata item, can't be null or empty.</param>
/// <param name="value">The value of the metadata item, can't be null.</param>
/// <param name="latitude">Optional latitude of the metadata item.</param>
/// <param name="longitude">Optional longitude of the metadata item.</param>
/// <param name="appTag">The optional application tag for this item, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse .result field will be TRUE on success, FALSE otherwise.</param>

- (void)set:(NSString *)key
      value:(NSString *)value
   latitude:(double)latitude
  longitude:(double)longitude
     appTag:(NSString *)appTag
      
   callback:(BuddyAppMetadataSetCallback)callback;

/// <summary>
/// Set a metadata item value for a key. You can additionally add latitude and longitude coordinates to record the location
/// from where this item was set, or tag the item with a custom tag.
/// The item doesn't have to exist to be set, this method acts as an Add method in cases where the item doesn't exist.
/// </summary>
/// <param name="key">The key of the metadata item, can't be null or empty.</param>
/// <param name="value">The value of the metadata item, can't be null.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse .result field will be TRUE on success, FALSE otherwise.</param>

- (void)set:(NSString *)key
      value:(NSString *)value
   callback:(BuddyAppMetadataSetCallback)callback;

/// <summary>
/// Delete a metadata item referenced by key.
/// </summary>
/// <param name="key">A valid key of a metadata item. The key can't be null or empty.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse .result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(NSString *)key
         
      callback:(BuddyAppMetadataDeleteCallback)callback;

/// <summary>
/// Delete all application metadata. There is no way to recover from this operation, be careful when you call it.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse .result field will be TRUE on success, FALSE otherwise.</param>

- (void)deleteAll:(BuddyAppMetadataDeleteAllCallback)callback;

/// <summary>
/// Search for metadata items in this application. Note that this method will only find app-level metadata items.
/// </summary>
/// <param name="searchDistanceMeters">The distance in meters from the latitude and longitude to search in. To ignore this distance pass in 40075000 (the circumference of the earth).</param>
/// <param name="latitude">Optional latitude from where the search will start.</param>
/// <param name="longitude">Optional longitude from where the search will start.</param>
/// <param name="numberOfResults">Optionally limit the number of returned metadata items.</param>
/// <param name="withKey">Optionally search for items with a specific key. The value of this parameter is treated as a wildcard, can be nil.</param>
/// <param name="withValue">Optionally search for items with a specific value. The value of this parameter is treated as a wildcard, can be nil.</param>
/// <param name="updatedMinutesAgo">Optionally return only items that were updated some minutes ago, can be nil.</param>
/// <param name="valueMin">Optionally search for metadata item values that are bigger than this number, can be nil.</param>
/// <param name="valueMax">Optionally search for metadata item values that are smaller than this number, can be nil.</param>
/// <param name="searchAsFloat">Treat all metadata values as floats. Useful for min/max searches.</param>
/// <param name="sortAscending">Sort the results ascending.</param>
/// <param name="disableCache">Disable cache searches.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse  will be set to an NSDictionary of metadata keys mapped to items if the request was successful (BuddyDictionaryResponse.isCompleted == TRUE and data was found on the server) otherwise nil if the request failed.</param>

- (void)find:(NSNumber *)searchDistanceMeters
    latitude:(double)latitude
      longitude:(double)longitude
numberOfResults:(NSNumber *)numberOfResults
        withKey:(NSString *)withKey
        withValue:(NSString *)withValue
updatedMinutesAgo:(NSNumber *)updatedMinutesAgo
         valueMin:(NSNumber *)valueMin
         valueMax:(NSNumber *)valueMax
    searchAsFloat:(BOOL)searchAsFloat
    sortAscending:(BOOL)sortAscending
     disableCache:(BOOL)disableCache
            
         callback:(BuddyAppMetadataFindCallback)callback;

/// <summary>
/// Search for metadata items in this application. Note that this method will only find app-level metadata items.
/// </summary>
/// <param name="searchDistanceMeters">The distance in meters from the latitude and longitude to search in. To ignore this distance pass in 40075000 (the circumference of the earth).</param>
/// <param name="latitude">The latitude from where the search will start.</param>
/// <param name="longitude">The longitude from where the search will start.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse will be set to an NSDictionary of metadata keys mapped to items if the request was successful (BuddyDictionaryResponse.isCompleted == TRUE and data was found on the server) otherwise nil if the request failed.</param>

- (void)find:(NSNumber *)searchDistanceMeters
    latitude:(double)latitude
   longitude:(double)longitude
    callback:(BuddyAppMetadataFindCallback)callback;

/// <summary>
/// This method returns the sum of a set of metadata items that correspond to a certain key wildcard. Note that the values of these items
/// need to be numbers or floats, otherwise this method will fail.
/// </summary>
/// <param name="forKeys">The key to use to filter the items that need to be summed. Is always treated as a wildcard.</param>
/// <param name="withinDistance">Optionally sum only items within a certain number of meters from lat/long.</param>
/// <param name="latitude">Optional latitude where the search can be started from.</param>
/// <param name="longitude">Optional longitude where the search can be started from.</param>
/// <param name="updatedMinutesAgo">Optionally sum only on items that have been updated a number of minutes ago, can be nil.</param>
/// <param name="withAppTag">Optionally sum only items that have a certain application tag, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyMetadataSumResponse will be a BuddyMetadataSum instance (containing the sum of all the found metadata item values requested) if the request was successful (BuddyMetadataSumResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil.</param>

- (void)   sum:(NSString *)forKeys
withinDistance:(NSNumber *)withinDistance
      latitude:(double)latitude
        longitude:(double)longitude
updatedMinutesAgo:(NSNumber *)updatedMinutesAgo
       withAppTag:(NSString *)appTag
            
         callback:(BuddyAppMetadataSumCallback)callback;

/// <summary>
/// This method returns the sum of a set of metadata items that correspond to a certain key wildcard. Note that the values of these items
/// need to be numbers or floats, otherwise this method will fail.
/// </summary>
/// <param name="forKeys">The key to use to filter the items that need to be summed. Is always treated as a wildcard.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyMetadataSumResponse will be a BuddyMetadataSum instance (containing the sum of all the found metadata item values requested) if the request was successful (BuddyMetadataSumResponse.isCompleted == TRUE and data was found on the server) otherwise it will be nil.</param>

- (void)sum:(NSString *)forKeys
   callback:(BuddyAppMetadataSumCallback)callback;

/// <summary>
/// This method returns the sum of a set of metadata items that correspond to a certain key wildcard. Note that the values of these items
/// need to be integers or floats, otherwise this method will fail.
/// Unlike the 'Sum' method this method can take a list of keys separated by semicolons and will return a list of sums for all of those keys.
/// </summary>
/// <param name="forKeys">The key to use to filter the items that need to be summed. Is always treated as a wildcard.</param>
/// <param name="withinDistance">Optionally sum only items within a certain number of meters from lat/long, can be nil.</param>
/// <param name="latitude">Optional latitude where the search can be started from.</param>
/// <param name="longitude">Optional longitude where the search can be started from.</param>
/// <param name="updatedMinutesAgo">Optionally sum only on items that have been updated a number of minutes ago, can be nil.</param>
/// <param name="withAppTag">Optionally sum only items that have a certain application tag, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMetadataSum items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)batchSum:(NSString *)forKeys
  withinDistance:(NSString *)withinDistance
        latitude:(double)latitude
        longitude:(double)longitude
updatedMinutesAgo:(NSNumber *)updatedMinutesAgo
       withAppTag:(NSString *)appTag
            
         callback:(BuddyAppMetadataBatchSumCallback)callback;

/// <summary>
/// This method returns the sum of a set of metadata items that correspond to a certain key wildcard. Note that the values of these items
/// need to be numbers or floats, otherwise this method will fail.
/// Unlike the 'Sum' method this method can take a list of keys separated by semicolons and will return a list of sums for all of those keys.
/// </summary>
/// <param name="forKeys">The key to use to filter the items that need to be summed. Is always treated as a wildcard.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMetadataSum items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)batchSum:(NSString *)forKeys
        callback:(BuddyAppMetadataBatchSumCallback)callback;

@end