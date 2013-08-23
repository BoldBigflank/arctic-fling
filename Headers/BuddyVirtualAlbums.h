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
@class BuddyVirtualAlbumResponse;


// BuddyVirtualAlbums callback definitions

/** Callback signature for the BuddyVirtualAlbumsGetMy function. The .result field of the BuddyArrayResponses will contain an NSArray of albumIds (stored as NSNumbers) if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumsGetMyCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyVirtualAlbumsCreate function.  The .result field of the BuddyVirtualAlbumResponse will be a BuddyVirtualAlbum for the requested name if successful otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumsCreateCallback)(BuddyVirtualAlbumResponse *response);

/** Callback signature for the BuddyVirtualAlbumsGet. The .result field of the BuddyVirtualAlbumResponse will be a BuddyVirtualAlbum for the requested albumId if successful otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumsGetCallback)(BuddyVirtualAlbumResponse *response);

/// <summary>
/// Represents a class that can be used to interact with virtual albums. Unlike normal photo albums any user may add existing photos to a virtual album.
/// Only the owner of the virtual album can delete the album however.
/// </summary>

@interface BuddyVirtualAlbums : NSObject

/// <summary>
/// Create a new virtual album.
/// </summary>
/// <param name="name">The name of the new virtual album.</param>
/// <param name="appTag">An optional application tag for the album.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyVirtualAlbumResponse will be a BuddyVirtualAlbum for the requested name if successful otherwise it will be nil.</param>

- (void)create:(NSString *)name
        appTag:(NSString *)appTag
         
      callback:(BuddyVirtualAlbumsCreateCallback)callback;

/// <summary>
/// Create a new virtual album.
/// </summary>
/// <param name="name">The name of the new virtual album.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyVirtualAlbumResponse will be a BuddyVirtualAlbum for the requested name if successful otherwise it will be nil.</param>

- (void)create:(NSString *)name
      callback:(BuddyVirtualAlbumsCreateCallback)callback;

/// <summary>
/// Get a virtual album by its globally unique identifier. All the album photos will be retrieved as well.
/// </summary>
/// <param name="albumId">The ID of the virtual album to retrieve.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyVirtualAlbumResponse will be a BuddyVirtualAlbum for the requested albumId if successful otherwise it will be nil.</param>

- (void)get:(NSNumber *)albumId
      
   callback:(BuddyVirtualAlbumsGetCallback)callback;

/// <summary>
/// Get the IDs of all the virtual albums that this user owns.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of albumIds (stored as NSNumbers) if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getMy:(BuddyVirtualAlbumsGetMyCallback)callback;

@end