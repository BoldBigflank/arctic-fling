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


@class BuddyClient;
@class BuddyAuthenticatedUser;
@class BuddyPhotoAlbum;
@class BuddyDictionaryResponse;
@class BuddyPhotoAlbumResponse;


// BuddyPhotoAlbums Callback definitions
/** Callback signature for the BuddyPhotoAlbumsCreate function. The .result field of the BuddyPhotoAlbumResponse will be a new BuddyPhotoAlbum that was created if the request was successful or nil if an error occurred.   If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumsCreateCallback)(BuddyPhotoAlbumResponse *response);

/** Callback signature for the BuddyPhotoAlbumsGet function. The .result field of the BuddyPhotoAlbumResponse will be the BuddyPhotoAlbum if the request was successful or nil if an error occurred. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumsGetCallback)(BuddyPhotoAlbumResponse *response);

/** Callback signature for the BuddyPhotoAlbumsGetWithName function. The .result field of the BuddyPhotoAlbumResponse will be the BuddyPhotoAlbum if the request was successful or nil if an error occurred. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumsGetWithNameCallback)(BuddyPhotoAlbumResponse *response);

/** Callback signature for the BuddyPhotoAlbumsGetAll function. The .result field of the BuddyDictionaryResponses object will be set to an NSDictionary of PhotoAlbumIds (key) and BuddyPhotoAlbums (value) pairs if the request was successful otherwise nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumsGetAllCallback)(BuddyDictionaryResponse *response);


/// <summary>
/// Represents a object that can be used to interact with an AuthenticatedUser's photo albums.
/// </summary>

/**
 * \code
 * Example:
 *
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *  __block NSDictionary *_dictOfAlbums;
 *
 *  [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          // get all photo albums for this user
 *          [user.photoAlbums searchForAlbums:[^(BuddyDictionaryResponses *response)
 *          {
 *              if (response.isCompleted && response.result)
 *              { // get the dictionary of albums
 *                  _dictOfAlbums =  response.result;
 *
 *                  // do something with the users albums
 *                  dispatch_async(dispatch_get_main_queue(), ^{[self processUsersAlbums: _dictOfAlbums]; });
 *              }
 *          } copy]];
 *      }
 *  }copy]];
 * \endcode
 */


@interface BuddyPhotoAlbums : NSObject

/// <summary>
/// This method is used create a new album. The album will be owned by this user. Multiple albums can be created with the same name.
/// </summary>
/// <param name="name">The name of the new album.</param>
/// <param name="isPublic">Make the album publicly visible to other users.</param>
/// <param name="appTag">Optionally add a custom application tag for this user, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPhotoAlbumResponse will be the new BuddyPhotoAlbum that was created if the request was successful or nil if an error occurred.</param>

- (void)create:(NSString *)name
      isPublic:(BOOL)isPublic
        appTag:(NSString *)appTag
         
      callback:(BuddyPhotoAlbumsCreateCallback)callback;

/// <summary>
/// This method is used create a new album. The album will be owned by this user. Multiple albums can be created with the same name.
/// </summary>
/// <param name="name">The name of the new album.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPhotoAlbumResponse will be the new BuddyPhotoAlbum that was created if the request was successful or nil if an error occurred.</param>

- (void)create:(NSString *)name
      callback:(BuddyPhotoAlbumsCreateCallback)callback;

// <summary>
/// Get a photo album by ID. This album doesn't need to be owned by this user.
/// </summary>
/// <param name="albumId">The ID of the album.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPhotoAlbumResponse will contain the BuddyPhotoAlbum if the request was successful or nil if an error occurred.</param>

- (void)get:(NSNumber *)albumId
      
   callback:(BuddyPhotoAlbumsGetCallback)callback;

/// <summary>
/// Get a photo album by its name. Note that there can be more than one album with the same name. This method will only return the first one.
/// Call photoAlbums.GetAll to get all the albums.
/// </summary>
/// <param name="albumName">The name of the album to retrieve. Can't be null or empty.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPhotoAlbumResponse will contain the BuddyPhotoAlbum if the request was successful or nil if an error occurred.</param>

- (void)getWithName:(NSString *)albumName
              
           callback:(BuddyPhotoAlbumsGetCallback)callback;

/// <summary>
/// Return all photo albums for this user. Note that this can be a time-consuming operation since all the Picture data is retrieved as well.
/// </summary>
/// <param name="afterDate">Optionally return all albums created after a date, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary of PhotoAlbumIds (key) and BuddyPhotoAlbums (value) pairs if the request was successful otherwise nil if the request failed.</param>

- (void)getAll:(NSDate *)afterDate
         
      callback:(BuddyPhotoAlbumsGetAllCallback)callback;

/// <summary>
/// Return all photo albums for this user. Note that this can be a time-consuming operation since all the Picture data is retrieved as well.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary of PhotoAlbumIds (key) and BuddyPhotoAlbums (value) pairs if the request was successful otherwise nil if the request failed.</param>

- (void)getAll:(BuddyPhotoAlbumsGetAllCallback)callback;

@end

