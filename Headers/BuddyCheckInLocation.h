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
/// Represents a single user check-in location.
/// </summary>

/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initWithApp:appName
                                              password:appPassword];
 *
 *  [bc Login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          // check in the user
 *          [user checkIn:0.0 longitude:0.0 callback:nil];
 *
 *          // now get all checkins for this app
 *          [user getCheckins:nil   callback:^(BuddyArrayResponse *response)
 *          {
 *              if (response.isCompleted && response.result)
 *              { // process the array of BuddyCheckInLocations
 *                  NSArray *checkins = response.result;
 *
 *                  for (id _checkin in checkins)
 *                  {
 *                      BuddyCheckInLocation *checkinlocation = (BuddyCheckInLocation *) _checkin;
 *                      // do something with the data
 *                  }
 *              }
 *          }];
 *       }
 *   }];
 * \endcode
 */

@interface BuddyCheckInLocation : NSObject

/// <summary>
/// Gets the latitude of the check-in location.
/// </summary>
@property (readonly, nonatomic, assign) double latitude;

/// <summary>
/// Gets the longitude of the check-in location.
/// </summary>
@property (readonly, nonatomic, assign) double longitude;

/// <summary>
/// Gets the date and time of the check-in.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *checkinDate;

/// <summary>
/// Gets the name of the place where the check-in happened.
/// </summary>
@property (readonly, nonatomic, strong) NSString *placeName;

/// <summary>
/// Gets the comment associated with this check-in.
/// </summary>
@property (readonly, nonatomic, strong) NSString *comment;

/// <summary>
/// Gets the application tag associated with this check-in.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appTag;

@end