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


@class BuddyMessageGroup;


/// <summary>
/// Represents a message that was sent to a group of users through AuthenticatedUser.messages.groups.SendMessage.
/// </summary>

@interface BuddyGroupMessage : NSObject

/// <summary>
/// Gets the DateTime the message was sent.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *dateSent;

/// <summary>
/// Gets the user ID of the user that sent the message to the group.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *fromUserID;

/// <summary>
/// Gets the Message group that the message was sent to.
/// </summary>
@property (readonly, nonatomic, strong) BuddyMessageGroup *group;

/// <summary>
/// Gets the text value of the message.
/// </summary>
@property (readonly, nonatomic, strong) NSString *text;

/// <summary>
/// Gets the optional latitude from where the message was sent.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the optional longitude from where the message was sent.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

@end
