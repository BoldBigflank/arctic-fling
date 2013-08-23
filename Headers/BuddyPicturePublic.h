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
/// Represents a single picture on the Buddy Platform. This is a public view of a picture, can be retrieve either by getting a user's profile pictures or
/// by searching for albums.
/// </summary>

/**
 \code
 Example:
    BuddyClient *bc = [[BuddyClient alloc] initClient:appName
                                             password:appPassword];
 
    __block NSArray *_photoArray;
 
    [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
    {
        if (response.isCompleted)
        {   // get the user
            BuddyAuthenticatedUser *user = response.result;
 
            [user.getProfilePhotos: nil callback:[^(BuddyArrayResponse *response)
            { // get a list of the users profile photos
                if (response.isCompleted && response.result)
                { 
                    _photoArray = (NSArray *) response.result;
                  
                    // do something with photos ... queue for displaying
                    dispatch_async(dispatch_get_main_queue(), ^{[self displayUserPhotos: _photoArray]; });
                }
            }copy]];
        }
    }copy]]; 
 \endcode
 */

@interface BuddyPicturePublic : NSObject

/// <summary>
/// Gets the url of the full picture.
/// </summary>
@property (readonly, nonatomic, strong) NSString *fullUrl;

/// <summary>
/// Gets the url of the thumbnail of the picture.
/// </summary>
@property (readonly, nonatomic, strong) NSString *thumbnailUrl;

/// <summary>
/// Gets the latitude of the picture location.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the longitude of the picture location.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the optional comment of the picture.
/// </summary>
@property (readonly, nonatomic, strong) NSString *comment;

/// <summary>
/// Gets the optional application tag of the picture.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appTag;

/// <summary>
/// Gets the date when this picture was added.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *addedOn;

/// <summary>
/// Gets the system-wide ID of the picture.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *photoId;

/// <summary>
/// If this picture was returned as part of an album search, gets the distance in kilometers from the location that was used as the origin of the search.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInKilometers;

/// <summary>
/// If this picture was returned as part of an album search, gets the distance in meters from the location that was used as the origin of the search.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMeters;

/// <summary>
/// If this picture was returned as part of an album search, gets the distance in miles from the location that was used as the origin of the search.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMiles;

/// <summary>
/// If this picture was returned as part of an album search, gets the distance in yards from the location that was used as the origin of the search.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInYards;

@end