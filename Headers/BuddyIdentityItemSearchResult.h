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
#import "BuddyIdentityItem.h"


/// <summary>
/// Represents a single identity search result. Use the AuthenticatedUser.identityValues.CheckForValues() method to search for items. A search item
/// can belong to any user in the system.
/// </summary>

@interface BuddyIdentityItemSearchResult : BuddyIdentityItem

/// <summary>
/// Gets whether the specific item was found.
/// </summary>
@property (readonly, nonatomic, assign) BOOL found;

/// <summary>
/// Gets the ID of the user the item was found on.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *belongsToUserId;

@end
