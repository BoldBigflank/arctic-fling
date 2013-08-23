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


// BuddyVirtualAlbum callback definitions

/** Callback signature for the BuddyVirtualAlbumDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyVirtualAlbumAddPicture function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumAddPictureCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyVirtualAlbumAddPictureBatch function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumAddPictureBatchCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyVirtualAlbumRemovePicture function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumRemovePictureCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyVirtualAlbumUpdate function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumUpdateCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyVirtualAlbumUpdatePicture function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyVirtualAlbumUpdatePictureCallback)(BuddyBoolResponse *response);

/// <summary>
/// Represents a single virtual album. Unlike normal photo albums any user may add existing photos to a virtual album.
/// Only the owner of the virtual album can delete the album however.
/// </summary>

@interface BuddyVirtualAlbum : NSObject

/// <summary>
/// Gets a readonly collection of pictures in this album. Use the AddPicture method to add more pictures to the album or the Picture.Delete method
/// to remove them.
/// </summary>
@property (readonly, nonatomic, strong) NSArray *pictures;

/// <summary>
/// Gets the globally unique ID of the virtual album.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *virtualAlbumId;

/// <summary>
/// Gets the name of the virtual album.
/// </summary>
@property (readonly, nonatomic, strong) NSString *name;

/// <summary>
/// Gets the thumbnail for the virtual album.
/// </summary>
@property (readonly, nonatomic, strong) NSString *thumbnailUrl;

/// <summary>
/// Gets the user ID of the owner of this virtual album.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *ownerUserId;

/// <summary>
/// Gets the optional application tag for this virtual album.
/// </summary>
@property (readonly, nonatomic, strong) NSString *applicationTag;

/// <summary>
/// Gets the date this virtual album was created.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *createdOn;

/// <summary>
/// Gets the date this virtual album was last updated.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *lastUpdated;

/// <summary>
/// Delete this virtual album.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(BuddyVirtualAlbumDeleteCallback)callback;

/// <summary>
/// Add an existing (uploaded) photo to a virtual album. This photo can be either private or public (either PicturePublic and Picture will work).
/// </summary>
/// <param name="picture">The picture to add to the virtual albums. Either PicturePublic or Picture works.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)addPicture:(BuddyPicturePublic *)picture
             
          callback:(BuddyVirtualAlbumAddPictureCallback)callback;

/// <summary>
/// Add a list of pictures to this virtual album.
/// </summary>
/// <param name="pictureBatch">The list of pictures to add to this photo album. Either PicturePublic or Picture works.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)addPictureBatch:(NSArray *)pictureBatch
                  
               callback:(BuddyVirtualAlbumAddPictureBatchCallback)callback;

/// <summary>
/// Remove a picture from this virtual album.
/// </summary>
/// <param name="picture">The picture to remove from the album. Either PicturePublic or Picture works.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)removePicture:(BuddyPicturePublic *)picture
                
             callback:(BuddyVirtualAlbumRemovePictureCallback)callback;

/// <summary>
/// Update this virtual album's name and app.tag
/// </summary>
/// <param name="newName">The new name for the album.</param>
/// <param name="newAppTag">An optional new application tag for the album.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)update:(NSString *)newName
     newAppTag:(NSString *)newAppTag
         
      callback:(BuddyVirtualAlbumUpdateCallback)callback;

/// <summary>
/// Update this virtual album's name and app.tag
/// </summary>
/// <param name="newName">The new name for the album.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)update:(NSString *)newName
      callback:(BuddyVirtualAlbumUpdateCallback)callback;

/// <summary>
/// Update virtual album picture comment or app.tag.
/// </summary>
/// <param name="picture">The picture to be updated, either PicturePublic or Picture works.</param>
/// <param name="newComment">The new comment to set for the picture.</param>
/// <param name="newAppTag">An optional new application tag for the picture, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)updatePicture:(BuddyPicturePublic *)picture
           newComment:(NSString *)newComment
            newAppTag:(NSString *)newAppTag
                
             callback:(BuddyVirtualAlbumUpdatePictureCallback)callback;

/// <summary>
/// Update virtual album picture comment or app.tag.
/// </summary>
/// <param name="picture">The picture to be updated, either PicturePublic or Picture works.</param>
/// <param name="newComment">The new comment to set for the picture.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)updatePicture:(BuddyPicturePublic *)picture
           newComment:(NSString *)newComment
             callback:(BuddyVirtualAlbumUpdatePictureCallback)callback;

@end