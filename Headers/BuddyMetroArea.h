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
/// Represents a metropolitan area.
/// </summary>

@interface BuddyMetroArea : NSObject

/// <summary>
/// Gets the icon URL an icon for the area.
/// </summary>
@property (readonly, nonatomic, strong) NSString *iconUrl;

/// <summary>
/// Gets the image URL an image for the area.
/// </summary>
@property (readonly, nonatomic, strong) NSString *imageUrl;

/// <summary>
/// Gets the name of the supported metro area.
/// </summary>
@property (readonly, nonatomic, strong) NSString *metroName;

/// <summary>
/// Gets the number of startups in the supported metro area.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *startupCount;

@property (readonly, nonatomic, strong) NSString *iconURL DEPRECATED_ATTRIBUTE;
@property (readonly, nonatomic, strong) NSString *imageURL DEPRECATED_ATTRIBUTE;
@end
