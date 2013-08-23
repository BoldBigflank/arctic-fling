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
/// Represents a single game state object.
/// </summary>

@interface BuddyGameState : NSObject

/// <summary>
/// Gets the optional application tag for this GameState.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appTag;

/// <summary>
/// Gets the date this GameState was created.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *addedOn;

/// <summary>
/// Get the key for this GameState object.
/// </summary>
@property (readonly, nonatomic, strong) NSString *key;

/// <summary>
/// Gets the the value for this GameState object
/// </summary>
@property (readonly, nonatomic, strong) NSString *value;

@end