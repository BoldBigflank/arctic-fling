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
/// Represents an object that describes a single game score entry.
/// </summary>


@interface BuddyGameScore : NSObject

/// <summary>
/// Gets the name of the board this score is related to.
/// </summary>
@property (readonly, nonatomic, strong) NSString *boardName;

/// <summary>
/// Gets the date this score was added.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *addedOn;

/// <summary>
/// Gets the optional latitude for this score.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the optional longitude for this score.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the optional rank value for this score.
/// </summary>
@property (readonly, nonatomic, strong) NSString *rank;

/// <summary>
/// Gets the numeric value of the score entry.
/// </summary>
@property (readonly, nonatomic, assign) double score;

/// <summary>
/// Gets the user ID that owns this score.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *userId;

/// <summary>
/// Gets the user name of the user who owns this score.
/// </summary>
@property (readonly, nonatomic, strong) NSString *userName;

/// <summary>
/// Gets the optional application tag for this score.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appTag;


@end

