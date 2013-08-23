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
/// Represents a single identity search result. Use the AuthenticatedUser.identityValues.CheckForValues() method to search for items. A search item
/// can belong to any user in the system.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *
 *  __block NSArray *_identitySearchItems;
 *  [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result ;
 *          // get all identify items
 *          [user.identityValues getAll:nil callback:[^(BuddyArrayResponse *response)
 *          {
 *              if (response.isCompleted && response.result != nil)
 *              {  // get the array of  BuddyIdentityItemSearchResult items
 *                  _identitySearchItems   = response.result;
 *                  // queue for processing
 *                  dispatch_async(dispatch_get_main_queue(), ^{[self processItems: _identitySearchItems]; });
 *              }
 *          }copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyIdentityItem : NSObject

/// <summary>
/// Gets the value of the identity item.
/// </summary>
@property (readonly, nonatomic, strong) NSString *value;

/// <summary>
/// Gets the date the identity value was added.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *createdOn;

@end

