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
#import "BuddyCallbackParams.h"


/// <summary>
/// Represents a callback response.
/// </summary>

@interface BuddyDataResponses : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. The type of the result will depend on the context of the Buddy API call. The result object should be cast to the correct type, as defined in the Buddy documentation and checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) NSObject *result;
@end



/// <summary>
/// Represents a callback response containing a BOOL.
/// </summary>

@interface BuddyBoolResponse : BuddyCallbackParams

/// <summary>
/// Gets the BOOL response value for the callback. TRUE for success FALSE for failure.
/// </summary>
@property (readonly, nonatomic, assign) BOOL result;

@end



/// <summary>
/// Represents a callback response containing an Date item, such and an ID.
/// </summary>

@interface BuddyDateResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is an NSDate. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) NSDate *result;
@end


/// <summary>
/// Represents a callback response containing an NSString item, such and an ID.
/// </summary>

@interface BuddyStringResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is an NSString. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) NSString *result;
@end


/// <summary>
/// Represents a callback response containing an NSArray of items.
/// </summary>

@interface BuddyArrayResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is an NSArray of items the type of which will depend on the context of the call as defined in the Buddy documentation. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) NSArray *result;
@end


/// <summary>
/// Represents a callback response containing an NSDictionary of items.
/// </summary>

@interface BuddyDictionaryResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is an NSDictionary of items the type of which will depend on the context of the call as defined in the Buddy documentation. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) NSDictionary *result;
@end


@class BuddyVirtualAlbum;
/// <summary>
/// Represents a callback response containing a BuddyVirtualAlbumn.
/// </summary>

@interface BuddyVirtualAlbumResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyVirtualAlbum. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyVirtualAlbum *result;
@end


@class BuddyMetadataSum;
/// <summary>
/// Represents a callback response containing a BuddyMetadataSum item.
/// </summary>

@interface BuddyMetadataSumResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyMetadataSum. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyMetadataSum *result;
@end


@class BuddyPhotoAlbum;
/// <summary>
/// Represents a callback response containing a BuddyPhotoAlbum.
/// </summary>

@interface BuddyPhotoAlbumResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyPhotoAlbum. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyPhotoAlbum *result;
@end


@class BuddyPicture;
/// <summary>
/// Represents a callback response containing a BuddyPicture.
/// </summary>

@interface BuddyPictureResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyPicture. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyPicture *result;
@end


@class BuddyGamePlayer;
/// <summary>
/// Represents a callback response containing a BuddyGamePlayer.
/// </summary>

@interface BuddyGamePlayerResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyGamePlayer. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyGamePlayer *result;
@end


@class BuddyAuthenticatedUser;
/// <summary>
/// Represents a callback response containing a BuddyAuthenticatedUser.
/// </summary>

@interface BuddyAuthenticatedUserResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyAuthenticatedUser. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyAuthenticatedUser *result;
@end


@class BuddyPlace;
/// <summary>
/// Represents a callback response containing a BuddyPlace.
/// </summary>

@interface BuddyPlaceResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyPlace. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyPlace *result;
@end


@class BuddyGameState;
/// <summary>
/// Represents a callback response containing a BuddyGameState.
/// </summary>

@interface BuddyGameStateResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyGameState. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyGameState *result;
@end


/// <summary>
/// Represents a callback response containing an NSNumber.
/// </summary>

@interface BuddyNSNumberResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a NSNumber. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) NSNumber *result;
@end


@class BuddyMetadataItem;
/// <summary>
/// Represents a callback response containing a BuddyMetadataItem.
/// </summary>

@interface BuddyMetadataItemResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyMetadataItem. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyMetadataItem *result;
@end

@class BuddyVideo;

@interface BuddyVideoResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyVideo. result should be checked for nil, before being used.
/// </summary>
@property (readonly, nonatomic, strong) BuddyVideo *result;

@end

@class BuddyBlob;

@interface BuddyBlobResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyBlob. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyBlob *result;

@end


@class BuddyUser;
/// <summary>
/// Represents a callback response containing a BuddyUser.
/// </summary>

@interface BuddyUserResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyUser. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyUser *result;
@end


@class BuddyMessageGroup;
/// <summary>
/// Represents a callback response containing a BuddyMessageGroup.
/// </summary>

@interface BuddyMessageGroupResponse : BuddyCallbackParams
/// <summary>
/// Gets the result of an Buddy API call. result is a BuddyMessageGroup. result should be checked for nil, before being used.
/// </summary>
@property(readonly, nonatomic, strong) BuddyMessageGroup *result;
@end