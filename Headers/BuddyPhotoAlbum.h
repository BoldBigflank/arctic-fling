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
#import "BuddyPhotoAlbumPublic.h"
#import "BuddyPicture.h"


@class BuddyAuthenticatedUser;
@class BuddyBoolResponse;
@class BuddyPictureResponse;


/** Callback signature for the BuddyPhotoAlbumDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyPhotoAlbumAddPicture function. The .result field of the BuddyPictureResponse will contain the new BuddyPicture that was added, nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumAddPictureCallback)(BuddyPictureResponse *response);

/** Callback signature for the BuddyPhotoAlbumAddPictureWithWatermark function. The .result field of the BuddyPictureResponse will contain the new BuddyPicture that was added, nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumAddPictureWithWatermarkCallback)(BuddyPictureResponse *response);

/** Callback signature for the BuddyPhotoAlbumSetAppTag function.  BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPhotoAlbumSetAppTagCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represent a single Buddy photo album. Albums are collections of photos that can be manipulated by their owner (the user that created the album). Albums can be public in which case other users can see them (but not modify).
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
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          __block BuddyPhotoAlbum * _album;
 *          // get a named photo album belonging to the user
 *          [user.photoAlbums getWithName:@"MyAlbum"  callback:[^(BuddyPhotoAlbumResponse *response)
 *          {
 *              if (response.isCompleted && response.result)
 *              {
 *                _album =  response.result;
 *
 *                // got the album now load contents of .png image into a data object
 *                NSString * path = [[NSBundle mainBundle] pathForResource:@"MyPictureFile" ofType:@"png"];
 *                NSData * binaryData =[NSData dataWithContentsOfFile:path];
 *
 *                __block BuddyPicture * _bPicture;
 *                // add the image to the album on the server
 *                [_album AddPicture:binaryData callback:[^(BuddyPictureResponse *response)
 *                {
 *                      if (response.isCompleted && response.result)
 *                      {
 *                          // get the new BuddyPicture returned from the server
 *                          _bPicture = response.result;
 *
 *                          //do something with the picture
 *                          dispatch_async(dispatch_get_main_queue(), ^{[self showPicture: _bPicture]; });
 *                      }
 *                } copy]];
 *              }
 *          }copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyPhotoAlbum : BuddyPhotoAlbumPublic

/// <summary>
/// Gets a readonly collection of pictures in this album. Use the AddPicture method to add more pictures to the album or the Picture.Delete method
/// to remove them.
/// </summary>
@property (readonly, nonatomic, strong) NSArray *pictures;

/// <summary>
/// Gets the global unique album ID.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *albumId;

/// <summary>
/// Delete this photo album.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(BuddyPhotoAlbumDeleteCallback)callback;

/// <summary>
/// Add a new picture to this album.
/// </summary>
/// <param name="blob">The image byte array of the picture.</param>
/// <param name="comment">A comment for this picture, can be nil.</param>
/// <param name="latitude">A latitude for the picture.</param>
/// <param name="longitude">A longitude for the picture.</param>
/// <param name="appTag">An application tag, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPictureResponse will contain the new BuddyPicture that was added, nil otherwise.</param>

- (void)addPicture:(NSData *)blob
           comment:(NSString *)comment
          latitude:(double)latitude
         longitude:(double)longitude
            appTag:(NSString *)appTag
             
          callback:(BuddyPhotoAlbumAddPictureCallback)callback;

/// <summary>
/// Add a new picture to this album.
/// </summary>
/// <param name="blob">The image byte array of the picture.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPictureResponse will contain the new BuddyPicture that was added, nil otherwise.</param>

- (void)addPicture:(NSData *)blob
          callback:(BuddyPhotoAlbumAddPictureCallback)callback;

/// <summary>
/// Add a new picture to this album.
/// </summary>
/// <param name="blob">The image byte array of the picture.</param>
/// <param name="comment">A comment for this picture, can be nil .</param>
/// <param name="latitude">A latitude for the picture, can be 0.</param>
/// <param name="longitude">A longitude for the picture, can be 0.</param>
/// <param name="appTag">A application tag can be nil.</param>
/// <param name="watermarkMessage">A message to watermark the image with, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPictureResponse will contain the new BuddyPicture that was added, nil otherwise.</param>

- (void)addPictureWithWatermark:(NSData *)blob
                        comment:(NSString *)comment
                       latitude:(double)latitude
                      longitude:(double)longitude
                         appTag:(NSString *)appTag
               watermarkMessage:(NSString *)watermarkMessage
                          
                       callback:(BuddyPhotoAlbumAddPictureWithWatermarkCallback)callback;

/// <summary>
/// Add a new picture to this album.
/// </summary>
/// <param name="blob">The image byte array of the picture.</param>
/// <param name="watermarkMessage">A message to watermark the image with, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPictureResponse will contain the new BuddyPicture that was added, nil otherwise.</param>

- (void)addPictureWithWatermark:(NSData *)blob
               watermarkMessage:(NSString *)watermarkMessage
                       callback:(BuddyPhotoAlbumAddPictureWithWatermarkCallback)callback;

/// <summary>
/// Base64-encode a NSData object
/// </summary>
/// <param name="imageBlob">The image byte array of the picture.</param>

- (NSData *)encodeToBase64:(NSData *)blob;

@end