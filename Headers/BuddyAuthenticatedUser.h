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

#import "BuddyUser.h"
#import "BuddyPhotoAlbums.h"
#import "BuddyPicturePublic.h"
#import "BuddyPicture.h"
#import "BuddyPlaces.h"
#import "BuddyIdentity.h"
#import "BuddyVirtualAlbums.h"
#import "BuddyFriends.h"
#import "BuddyUserMetadata.h"
#import "BuddyMessages.h"
#import "BuddyGamePlayers.h"
#import "BuddyBlobs.h"
#import "BuddyVideos.h"

#import "BuddyStartups.h"
#import "BuddyCommerce.h"

@class BuddyClient;
@class BuddyNotificationsApple;
@class BuddyBoolResponse;
@class BuddyArrayResponse;
@class BuddyDictionaryResponse;
@class BuddyPictureResponse;
@class BuddyUserResponse;


// BuddyAuthenticatedUser callback definitions

/** Callback signature for the BuddyAuthenticatedUserFindUser function. The .result field of the BuddyUserResponse will contain a BuddyUser if the request was successful (BuddyUserResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserFindUserCallback)(BuddyUserResponse *response);

/** Callback signature for the BuddyAuthenticatedUserFindUsers function. The .result field of the BuddyArrayResponse will be an NSArray of BuddyUsers if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserFindUsersCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyAuthenticatedUserAddProfilePhoto function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserAddProfilePhotoCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAuthenticatedUserCheckIn function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserCheckInCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAuthenticatedUserGetCheckins function. The .result field of the BuddyArrayResponse will be an NSArray of BuddyCheckInLocation items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserGetCheckinsCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyAuthenticatedUserUpdate function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserUpdateCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAuthenticatedUserDelete function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserDeleteCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAuthenticatedUserGetPicture function. The .result field of the BuddyPictureResponse will contain the BuddyPicture if found, nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserGetPictureCallback)(BuddyPictureResponse *response);

/** Callback signature for the BuddyAuthenticatedUserSearchForAlbums function. The .result field of the BuddyDictionaryResponse will be a NSDictionary of 
 PhotoAlbumId/BuddyPhotoAlbum pairs if the request was successful otherwise nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserSearchForAlbumsCallback)(BuddyDictionaryResponse *response);

/** Callback signature for the BuddyAuthenticatedUserDeleteProfilePhoto function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserDeleteProfilePhotoCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyAuthenticatedUserSetProfilePhoto function. ruddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyAuthenticatedUserSetProfilePhotoCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represents a user that has been authenticated with the Buddy Platform. Use this object to interact with the service on behalf of the user.
/// </summary>

/**
 * \code
 * Example:
 *
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *   __block BuddyAuthenticatedUser *_user;
 *   NSNumber *userAge = [NSNumber numberWithInt:100];
 *   NSString *userEmail = @"useremail@email.com";
 *
 *   [bc createUser:@"Username" password:@"Password" gender:UserGender_Any age:userAge email:userEmail status:UserStatus_Widowed fuzzLocation:FALSE celebrityMode:FALSE appTag:nil  callback:[^(BuddyAuthenticatedUserResponse *response)
 *   {
 *      if (response.isCompleted && response.result)
 *      {
 *          _user = response.result;
 *          // do something with user, for example save user object to be used elsewhere
 *          dispatch_async(dispatch_get_main_queue(), ^{ [self saveUser: _user]; });
 *      }
 *   }copy]];
 * \endcode
 */

@interface BuddyAuthenticatedUser : BuddyUser

/// <summary>
/// Gets the unique user token that is the secret used to login this user. Each user has a unique ID, a secret user token and a user/pass combination.
/// </summary>
@property (readonly, nonatomic, strong) NSString *token;

/// <summary>
/// Gets the email of the user. Can be an empty string or null.
/// </summary>
@property (readonly, nonatomic, strong) NSString *email;

/// <summary>
/// Gets whether location fuzzing is enabled. When enabled any reported locations for this user will be randomized for a few miles. This is a security feature
/// that makes it difficult for users to track each other.
/// </summary>
@property (readonly, nonatomic, assign) BOOL locationFuzzing;

/// <summary>
/// Gets whether celebrity mode is enabled for this user. When enabled the user will be hidden from all searches in the system.
/// </summary>
@property (readonly, nonatomic, assign) BOOL celebrityMode;

/// <summary>
/// Gets an object that can be used to register a device for push notifications, send notifications or query the state of devices and groups.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyNotificationsApple *pushNotifications;

/// <summary>
/// Gets the collection of photo albums for this user. Note that the actual album information is loaded on demand when you call the All or Get method.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyPhotoAlbums *photoAlbums;

/// <summary>
/// Gets an object that can be user for search for locations around the user (places, not other users).
/// </summary>
@property (readonly, nonatomic,  strong) BuddyPlaces *places;

/// <summary>
/// Gets the collection of identity values for the user.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyIdentity *identityValues;

/// <summary>
/// Gets the collection of virtual albums for this users. All virtual albums are owned by a single user, however any user may add existing photos to the album. Only the owner of the virtual album can delete the album.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyVirtualAlbums *virtualAlbums;

/// <summary>
/// Gets the collection of friends for this user. Note that the actual friends information is loaded on demand when you call the All or Get method.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyFriends *friends;

/// <summary>
/// Gets the collection of user metadata. Note that the actual metadata is loaded on demand when you call the All or Get method.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyUserMetadata *metadata;

/// <summary>
/// Gets an object that can be used to send or receive messages, create message groups, etc.
/// </summary>
@property (readonly, nonatomic,  strong) BuddyMessages *messages;

/// <summary>
/// Add and remove and manipulate BuddyGamePlayers for this user.
/// </summary>
@property (readonly, nonatomic, strong) BuddyGamePlayers *gamePlayers;

@property (readonly, nonatomic, strong) BuddyBlobs *blobs;

@property (readonly, nonatomic, strong) BuddyVideos *videos;

/// <summary>
/// Gets and object that can be used for commerce for the user.
/// </summary>
@property (readonly, nonatomic, strong) BuddyCommerce *commerce;

/// <summary>
/// Gets and object that can be used to search for startups around the user.
/// </summary>
@property (readonly, nonatomic, strong) BuddyStartups *startups;


/// <summary>
/// Add a profile photo for this user.
/// </summary>
/// <param name="blob">An array of bytes that represent the image you are adding.</param>
/// <param name="appTag">An optional tag for the photo, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)addProfilePhoto:(NSData *)blob
                 appTag:(NSString *)appTag
                  
               callback:(BuddyAuthenticatedUserAddProfilePhotoCallback)callback;

/// <summary>
/// Add a profile photo for this user.
/// </summary>
/// <param name="blob">An array of bytes that represent the image you are adding.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)addProfilePhoto:(NSData *)blob
               callback:(BuddyAuthenticatedUserAddProfilePhotoCallback)callback;

/// <summary>
/// Check-in the user at a location.
/// </summary>
/// <param name="latitude">The latitude of the location.</param>
/// <param name="longitude">The longitude of the location.</param>
/// <param name="comment">An optional comment for the check-in, can be nil.</param>
/// <param name="appTag">An optional application specific tag for the location, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)checkIn:(double)latitude
      longitude:(double)longitude
        comment:(NSString *)comment
         appTag:(NSString *)appTag
          
       callback:(BuddyAuthenticatedUserCheckInCallback)callback;

/// <summary>
/// Check-in the user at a location.
/// </summary>
/// <param name="latitude">The latitude of the location.</param>
/// <param name="longitude">The longitude of the location.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)checkIn:(double)latitude
      longitude:(double)longitude
       callback:(BuddyAuthenticatedUserCheckInCallback)callback;

/// <summary>
/// Get a list of user check-in locations.
/// </summary>
/// <param name="afterDate">Filter the list to return only check-in after a date.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyCheckInLocation items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getCheckins:(NSDate *)afterDate
              
           callback:(BuddyAuthenticatedUserGetCheckinsCallback)callback;

/// <summary>
/// Get a list of user check-in locations.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyCheckInLocation items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getCheckins:(BuddyAuthenticatedUserGetCheckinsCallback)callback;

// <summary>
/// Delete this user.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)delete:(BuddyAuthenticatedUserDeleteCallback)callback;

/// <summary>
/// Update the profile of this user.
/// </summary>
/// <param name="name">New name for the user, can't be nil.</param>
/// <param name="password">New password for the user, can't be nil.</param>
/// <param name="gender">New gender for the user.</param>
/// <param name="age">New age for the user, can be nil.</param>
/// <param name="email">New email for the user, can be nil.</param>
/// <param name="status">New status for the user.</param>
/// <param name="fuzzLocation">Change in location fuzzing for this user. If location fuzzing is enable, user location will be
/// randomized in all searches by other users.</param>
/// <param name="celebrityMode">Change in celebrity mode for this user. If celebrity mode is enabled the user will be hidden from all searches in the system.</param>
/// <param name="appTag">Optional update to the custom application tag for this user, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)update:(NSString *)name
      password:(NSString *)password
        gender:(UserGender)gender
           age:(NSNumber *)age
         email:(NSString *)email
    userStatus:(UserStatus)status
  fuzzLocation:(BOOL)fuzzLocation
 celebrityMode:(BOOL)celebrityMode
        appTag:(NSString *)appTag
         
      callback:(BuddyAuthenticatedUserUpdateCallback)callback;


/// <summary>
/// Retrieve a picture by its unique ID. Any picture that the user owns or is publicly available can be retrieved.
/// </summary>
/// <param name="pictureId">The id of the picture to retrieve.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyPictureResponse will contain the BuddyPicture if found, nil otherwise.</param>

- (void)getPicture:(NSNumber *)pictureId
             
          callback:(BuddyAuthenticatedUserGetPictureCallback)callback;

/// <summary>
/// Search for public albums from other users.
/// </summary>
/// <param name="searchDistanceInMeters">Optionally search only within a certain distance from the supplied lat/long. To ignore this distance pass in 40075000 (the circumference of the earth.</param>
/// <param name="latitude">Search for photos added near a latitude.</param>
/// <param name="longitude">Search for photos added near a longitude.</param>
/// <param name="limitResults">Optionally limit the number of returned photos. Note that this parameter limits the photos returned, not albums. It's possible that a partial album is returned, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse will be a NSDictionary of PhotoAlbumID/BuddyPhotoAlbum pairs if the request was successful otherwise nil if the request failed.</param>

- (void)searchForAlbums:(NSNumber *)searchDistanceInMeters
               latitude:(double)latitude
              longitude:(double)longitude
           limitResults:(NSNumber *)resultsLimit
                  
               callback:(BuddyAuthenticatedUserSearchForAlbumsCallback)callback;

/// <summary>
/// Search for public albums from other users.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDictionaryResponse will be a NSDictionary PhotoAlbumIds/BuddyPhotoAlbum pairs if the request was successful otherwise nil if the request failed.</param>

- (void)searchForAlbums:(BuddyAuthenticatedUserSearchForAlbumsCallback)callback;

/// <summary>
/// Delete a profile photo for this user. You can use the GetProfilePhotos method to retrieve all the profile photos.
/// </summary>
/// <param name="picture">The photo to delete.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)deleteProfilePhoto:(BuddyPicturePublic *)picture
                     
                  callback:(BuddyAuthenticatedUserDeleteProfilePhotoCallback)callback;

/// <summary>
/// Set a new "active" profile photo from the list of profile photos that the user has uploaded. The photo needs to be already uploaded.
/// </summary>
/// <param name="picture">The photo to set as the "active" profile photo.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)setProfilePhoto:(BuddyPicturePublic *)picture
                  
               callback:(BuddyAuthenticatedUserSetProfilePhotoCallback)callback;

/// <summary>
/// Find the public profile of a user from their unique user ID. This method can be used to find any user associated with this Application.
/// </summary>
/// <param name="userId">The ID of the user, must be bigger than 0.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyUserResponse will be set to a BuddyUser account associated with the ID if the request was successful otherwise it will be nil.</param>

- (void)findUser:(NSNumber *)userId
           
        callback:(BuddyAuthenticatedUserFindUserCallback)callback;

/// <summary>
/// Find the public profiles of all users that match the search parameters.
/// </summary>
/// <param name="latitude">The latitude of the position to search from. Must be a value between -90.0 and 90.0.</param>
/// <param name="longitude">The longitude of the position to search from. Must be a value between -180.0 and 180.0.</param>
/// <param name="searchDistance">The distance in meters from the specified latitude/longitude to search for results. To ignore this distance pass in 40075000 (the circumference of the earth).</param>
/// <param name="recordLimit">The maximum number of users to return with this search, can be nil.</param>
/// <param name="gender">The gender of the users, use UserGender.Any to search for both.</param>
/// <param name="ageStart">Specifies the starting age for the range of ages to search in. The value must be >= 0.</param>
/// <param name="ageStop">Specifies the ending age for the range of ages to search in. The value must be > ageStart.</param>
/// <param name="userStatus">The status of the users to search for. Use UserStatus.Any to ignore this parameter.</param>
/// <param name="checkinsWithinMinutes">Filter for users who have checked-in in the past 'checkinsWithinMinutes' number of minutes, can be nil.</param>
/// <param name="appTag">Search for the custom appTag that was stored with the user, can be nil.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDataResponse will contain an NSArray of BuddyUser items if the request was successful (BuddyDataResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)findUser:(double)latitude
       longitude:(double)longitude
  searchDistance:(NSNumber *)searchDistance
     recordLimit:(NSNumber *)recordLimit
          gender:(UserGender)gender
        ageStart:(NSNumber *)ageStart
         ageStop:(NSNumber *)ageStop
           userStatus:(UserStatus)userStatus
checkinsWithinMinutes:(NSNumber *)checkinsWithinMinutes
               appTag:(NSString *)appTag
                
             callback:(BuddyAuthenticatedUserFindUsersCallback)callback;

/// <summary>
/// Find the public profiles of all users that match the search parameters.
/// </summary>
/// <param name="latitude">The latitude of the position to search from. Must be a value between -90.0 and 90.0.</param>
/// <param name="longitude">The longitude of the position to search from. Must be a value between -180.0 and 180.0.</param>
/// <param name="searchDistance">The distance in meters from the specified latitude/longitude to search for results. To ignore this distance pass in 40075000 (the circumference of the earth).</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDataResponse will contain an NSArray of BuddyUser items if the request was successful (BuddyDataResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.The async callback to call on success or error.</param>

- (void)findUser:(double)latitude
       longitude:(double)longitude
  searchDistance:(NSNumber *)searchDistance
        callback:(BuddyAuthenticatedUserFindUsersCallback)callback;

- (NSString *)toString;

@end
