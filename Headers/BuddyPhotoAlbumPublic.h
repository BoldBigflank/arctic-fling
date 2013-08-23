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


/// <summary>
/// Represents a public photo album. Public albums are returned from album searches.
/// </summary>

/**
 \code
 Example:
    BuddyClient *bc = [[BuddyClient alloc] initClient:appName
                                             password:appPassword];
 
    __block NSDictionary *_dictAlbums;
 
    [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
    {
        if (response.isCompleted)
        {   // get the user
            BuddyAuthenticatedUser *user = response.result;
 
            // search for all public photo albums
            [user searchForAlbums:[^(BuddyDictionaryResponses *response)
            { 
               if (response.isCompleted && response.result)
               { // get the dictionary of albums
                  _dictAlbums = response.result;
                
                  // do something with the albums
                  dispatch_async(dispatch_get_main_queue(), ^{[self processPublicAlbums: _dictAlbums]; });
               }
            }copy]];
        }
    }copy]];
 \endcode
*/





@interface BuddyPhotoAlbumPublic : NSObject

/// <summary>
/// Gets the user ID of the user that owns this album.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *userId;

/// <summary>
/// Gets the name of the album
/// </summary>
@property (readonly, nonatomic, strong) NSString *albumName;

/// <summary>
/// Gets a list of pictures in this album.
/// </summary>
@property (readonly, nonatomic, strong) NSArray *pictures;

@end