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
#import "BuddyPicturePublic.h"


@class BuddyBoolResponse;
@class BuddyDictionaryResponse;
@class BuddyPictureResponse;
@class BuddyClient;
@class BuddyPicture;



/** Callback signature for the BuddyPictureDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPictureDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyPictureSupportedFilters function. The .result field of the BuddyDictionaryResponse object will be set to an NSDictionary of filtername  (key) and description (value) pairs if the request was successful otherwise nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPictureSupportedFiltersCallback)(BuddyDictionaryResponse *response);

/** Callback signature for the BuddyPictureApplyFilter function. The .result field of the BuddyPictureResponse will contain the new BuddyPicture with the filter applied if the request is successful, nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPictureApplyFilterCallback)(BuddyPictureResponse *response);

/** Callback signature for the BuddyPictureSetAppTag function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyPictureSetAppTagCallback)(BuddyBoolResponse *response);



/// <summary>
/// Represents a single picture on the Buddy Platform. pictures can be accessed through an AuthenticatedUser, either by using the photoAlbums property to retrieve
/// pictures that belong to the user, or using the SearchForAlbums method to find public pictures.
/// </summary>


/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  [bc login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          [user.searchForAlbums:^(BuddyArrayResponse *response)
 *          { // get a list of public BuddyPhotoAlbums
 *              if (response.isCompleted && response.result)
 *              {
 *                  NSArray *albums = response.result;
 *                  // get the first picture from each PhotoAlbum
 *                  foreach (id _bPA  in albums)
 *                  {
 *                      BuddyPhotoAlbum *bPA =  (BuddyPhotoAlbum *)_bPA;
 *                      if ([bPA.pictures count] > 0)
 *                      {
 *                          BuddyPicture *bp =  (BuddyPicture *)[bpA.pictures objectAtIndex:0] ;
 *                          // do something with the picture
 *                      }
 *                  }
 *              }
 *          }];
 *      }
 *  }];
 * \endcode
 */

@interface BuddyPicture : BuddyPicturePublic

/// <summary>
/// Returns a list of supported filters that can be applied to this picture. Example filters are: Hue Shift, Crop, etc.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponses object will be set to an NSDictionary of fildescriptiontername  (key) and description (value) pairs if the request was successful otherwise nil if the request failed.</param>

- (void)supportedFilters:(BuddyPictureSupportedFiltersCallback)callback;

/// <summary>
/// Delete this picture. Note that this object will no longer be valid after this method is called. Subsequent calls will fail.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(BuddyPictureDeleteCallback)callback;

/// <summary>
/// Apply a filter to this picture. A new picture is created and returned after the filter is applied.
/// </summary>
/// <param name="filterName">The name of the filter to apply. Can't be null or empty.</param>
/// <param name="filterParams">A semi-colon separated list of filter parameter names and values. For example: CropLeft=30;CropRight=40.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPictureResponse will contain the new BuddyPicture with the filter applied if the request is successful, nil otherwise.</param>

- (void)applyFilter:(NSString *)filterName
       filterParams:(NSString *)filterParams
              
           callback:(BuddyPictureApplyFilterCallback)callback;

/// <summary>
/// Sets the appTag (metadata) for an existing picture in an existing photo album, for the specified Photo ID.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)setAppTag:(NSString *)appTag
            
         callback:(BuddyPictureSetAppTagCallback)callback;

@end