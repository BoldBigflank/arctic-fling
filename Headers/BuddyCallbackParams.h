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
/// Represents an object that wraps a number of different callback return values.
/// </summary>

@interface BuddyCallbackParams : NSObject

/// <summary>
/// Gets the exception in case there was an error while processing the API call.
/// </summary>
@property (readonly, nonatomic, strong) NSException *exception;

/// <summary>
/// Gets whether the call was successfully completed or not.
/// </summary>
@property (readonly, nonatomic, assign) BOOL isCompleted;



/// <summary>
/// Gets the raw http response as a string.
/// </summary>
@property (readonly, nonatomic, strong) NSData *dataResult;

/// <summary>
/// Gets the raw http response as a string.
/// </summary>
@property (readonly, nonatomic, strong) NSString *stringResult;

/// <summary>
/// Gets the raw api call.
/// </summary>
@property (readonly, nonatomic, strong) NSString *apiCall;

@end
