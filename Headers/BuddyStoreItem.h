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
/// Represents a single, named store item in the Buddy system.
/// </summary>

@interface BuddyStoreItem : NSObject

/// <summary>
/// Gets the optional metadata associated with the item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appData;

/// <summary>
/// Gets the ID by which external sources identify the item by.
/// </summary>
@property (readonly, nonatomic, strong) NSString *customItemId;

/// <summary>
/// Gets the flag indicating if the item is currently available for sale.
/// </summary>
@property (readonly, nonatomic, assign) BOOL itemAvailableFlag;

/// <summary>
/// Gets the cost of the item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *itemCost;

/// <summary>
/// Gets the date and time when the item was created or last updated.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *itemDateTime;

/// <summary>
/// Gets the brief description of the item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *itemDescription;

/// <summary>
/// Gets the URI where the item can be downloaded from.
/// </summary>
@property (readonly, nonatomic, strong) NSString *itemDownloadUri;

/// <summary>
/// Gets the flag indicating if the item is free.
/// </summary>
@property (readonly, nonatomic, assign) BOOL itemFreeFlag;

/// <summary>
/// Gets the URI of the icon to display for this item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *itemIconUri;

/// <summary>
/// Gets the name of the item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *itemName;

/// <summary>
/// Gets the URI where the item can be previewed.
/// </summary>
@property (readonly, nonatomic, strong) NSString *itemPreviewUri;

/// <summary>
/// Gets the ID of the store item.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *storeItemId;

@property (readonly, nonatomic, strong) NSString *customItemID DEPRECATED_ATTRIBUTE;
@property (readonly, nonatomic, strong) NSNumber *storeItemID DEPRECATED_ATTRIBUTE;

@end
