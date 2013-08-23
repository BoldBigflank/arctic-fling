
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
#import "BuddyEnums.h"


@class BuddyClient;
@class BuddyGameScores;
@class BuddyGameStates;
@class BuddyArrayResponse;


/** Callback signature for the BuddyUserGetProfilePhotos function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyPicturePublic items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyUserGetProfilePhotosCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents a public user profile. Public user profiles are usually returned when looking at an AuthenticatedUser's friends or making a search with FindUser.
/// </summary>

/**
 * \code
 * Example:
 * BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                          password:appPassword];
 *
 * [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 * {
 *  __block NSArray *users;
 *
 *  if (response.isCompleted)
 *  {  // get the user
 *      BuddyAuthenticatedUser user = response.result;
 *      NSNumber *numberToFind = [NSNumber numberWithInt:200];
 *
 *      [user FindUser:numberToFind  callback:[^(BuddyArrayResponse *response)
 *      {
 *          if (response.isCompleted && response.result)
 *          { // process the array of returned BuddyUsers
 *              _users = response.result;
 *              dispatch_async(dispatch_get_main_queue(), ^{[self displayUsers: _users]; });
 *          }
 *      }copy] ];
 *  }
 * }copy] ];
 * \endcode
 */

@interface BuddyUser : NSObject

/// <summary>
/// Gets the name of the user.
/// </summary>
@property (readonly, nonatomic, strong) NSString *name;

/// <summary>
/// Gets the system-wide unique ID of the user.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *userId;

/// <summary>
/// Gets the gender of the user.
/// </summary>
@property (readonly, nonatomic, assign) UserGender gender;

/// <summary>
/// Gets the optional application tag for the user.
/// </summary>
@property (readonly, nonatomic, strong) NSString *applicationTag;

/// <summary>
/// Gets the latitude of the last check-in for this user.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the longitude of the last check-in for this user.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the last time this user logged on to the platform.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *lastLoginOn;

/// <summary>
/// Gets the profile picture url for this user.
/// </summary>
@property (readonly, nonatomic, strong) NSURL *profilePicture;

/// <summary>
/// Gets the profile picture ID for this user.
/// </summary>
@property (readonly, nonatomic, strong) NSString *profilePictureId;

/// <summary>
/// Gets the age of this user.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *age;

/// <summary>
/// Gets the status of the user.
/// </summary>
@property (readonly, nonatomic, assign) UserStatus status;

/// <summary>
/// Gets the date this user was created.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *createdOn;

/// <summary>
/// If this user profile was returned from a search, gets the distance in kilometers from the search origin.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInKilometers;

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
/// Does this user have a friends request pending.
/// </summary>
@property (readonly, nonatomic, assign) BOOL friendRequestPending;

/// <summary>
/// Add and remove gameScores for this user.
/// </summary>
@property (readonly, nonatomic, strong) BuddyGameScores *gameScores;

/// <summary>
/// Add and remove gameStates for this user.
/// </summary>
@property (readonly, nonatomic, strong) BuddyGameStates *gameStates;

- (NSString *)toString;

/// <summary>
/// Gets a list of profile photos for this user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyPicturePublic items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getProfilePhotos:(BuddyUserGetProfilePhotosCallback)callback;

@end