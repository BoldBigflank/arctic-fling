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
/// Represents a game player object.
/// </summary>

@interface BuddyGamePlayer : NSObject

/// <summary>
/// Gets the name of the player.
/// </summary>
@property (readonly, nonatomic, strong) NSString *name;

/// <summary>
/// Gets the date the player was created.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *createdOn;

/// <summary>
/// Gets the name of the board the player belongs to.
/// </summary>
@property (readonly, nonatomic, strong) NSString *boardName;

/// <summary>
/// Gets the optional application tag for the player.
/// </summary>
@property (readonly, nonatomic, strong) NSString *applicationTag;

/// <summary>
/// Gets the latitude where the player was created.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the longitude where the player was created.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the userId of the user this player is tied to.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *userId;

/// <summary>
/// Gets the distance in kilometers from the given origin in the metadata search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInKilometers;

/// <summary>
/// Gets the distance in meters from the given origin in the metadata search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMeters;

/// <summary>
/// Gets the distance in miles from the given origin in the metadata search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMiles;

/// <summary>
/// Gets the distance in yards from the given origin in the metadata search method.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInYards;

/// <summary>
/// Gets the rank of the player.
/// </summary>
@property (readonly, nonatomic, strong) NSString *rank;

@end
