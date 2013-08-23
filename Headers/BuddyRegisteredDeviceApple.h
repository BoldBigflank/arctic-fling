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
#import "BuddyAuthenticatedUser.h"


/// <summary>
/// Represents a registered iOS phone device. Each registered device is uniquely identified by Buddy based on its developer, the application name and the user token. This supports the ability to push notifications based on the current user and not the hardware itself, which allows end users to upgrade their phones while maintaining their notifications. 
/// </summary>

@interface BuddyRegisteredDeviceApple : NSObject

/// <summary>
/// Devices Application Push token
/// </summary>
@property (readonly, nonatomic, strong) NSString *APNSDeviceToken;

/// <summary>
/// Gets the name of the group.
/// </summary>
@property (readonly, nonatomic, strong) NSString *groupName;

/// <summary>
/// Gets the date last modified.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *lastUpdateDate;

/// <summary>
/// Gets the date device was registered.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *registrationDate;

/// <summary>
/// Gets the system-wide unique ID of the user.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *userId;

/// <summary>
/// returns the system-wide unique ID as a NSString.
/// </summary>
-(NSString *)userIdAsString;

@end
