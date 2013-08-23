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
/// Represents the sum of a collection of metadata items with a similar key.
/// </summary>

/**
 \code
 Example:
    BuddyClient *bc = [[BuddyClient alloc] initClient:appName
                                             password:appPassword];
 
 
    // assign values to some metadata keys
    [bc.metadata set: @"Test count1" value: @"10" callback:nil];
    [bc.metadata set: @"Test count2" value: @"20" callback:nil];
    [bc.metadata set: @"Test count3" value: @"30" callback:nil];
  
    // now get the sum of metadata keys named "Test count"
    [bc.metadata sum: @"Test count"  callback:^(BuddyMetadataSumResponse *response)
    {
        if (response.isCompleted && response.result)
        {
            BuddyMetadataSum *metaSum = response.result;
            //do something with the result
        }
    }];
 \endcode
*/


@interface BuddyMetadataSum : NSObject

/// <summary>
/// Gets the total sum of the metadata items.
/// </summary>
@property (readonly, nonatomic, assign) double total;

/// <summary>
/// Gets the number of items that were summed.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *keysCounted;

/// <summary>
/// Gets the common key that was used to produce this sum.
/// </summary>
@property (readonly, nonatomic, strong) NSString *keyName;

@end
