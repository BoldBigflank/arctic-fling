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
/// Returns a collection of high level statistics showing the current usage levels of the application. The data returned includes items such as total users, photos, etc.
/// </summary>

@interface BuddyApplicationStatistics : NSObject

@property(readonly, nonatomic, strong) NSString *totalUsers;

/// <summary>
/// This is the combined total of all profile photos and photo album photos for the application.
/// </summary>
@property(readonly, nonatomic, strong) NSString *totalPhotos;

@property(readonly, nonatomic, strong) NSString *totalUserCheckins;

@property(readonly, nonatomic, strong) NSString *totalUserMetadata;

@property(readonly, nonatomic, strong) NSString *totalAppMetadata;

@property(readonly, nonatomic, strong) NSString *totalFriends;

@property(readonly, nonatomic, strong) NSString *totalAlbums;

@property(readonly, nonatomic, strong) NSString *totalCrashes;

@property(readonly, nonatomic, strong) NSString *totalMessages;

/// <summary>
/// This is the combined total of all push notifications sent for all platforms supported.
/// </summary>
@property(readonly, nonatomic, strong) NSString *totalPushMessages;

@property(readonly, nonatomic, strong) NSString *totalGamePlayers;

@property(readonly, nonatomic, strong) NSString *totalGameScores;

@property(readonly, nonatomic, strong) NSString *totalDeviceInformation;

@end