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


@interface BuddyStartup : NSObject

/// <summary>
/// Gets the latitude of the center of the specified metro area.
/// </summary>
@property (readonly, nonatomic, assign) double centerLat;

/// <summary>
/// Gets the longitude of the center of the specified metro area.
/// </summary>
@property (readonly, nonatomic, assign) double centerLong;

/// <summary>
/// Gets the city in which the startup is located.
/// </summary>
@property (readonly, nonatomic, strong) NSString *city;

/// <summary>
/// Gets the crunchbase.com URL of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *crunchBaseUrl;

/// <summary>
/// Gets the custom data of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *customData;

/// <summary>
/// Gets the distance in kilometers from the center of the specified metro area that the startup is located.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInKilometers;

/// <summary>
/// Gets the distance in meters from the center of the specified metro area that the startup is located.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMeters;

/// <summary>
/// Gets the distance in miles from the center of the specified metro area that the startup is located.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInMiles;

/// <summary>
/// Gets the distance in yards from the center of the specified metro area that the startup is located.
/// </summary>
@property (readonly, nonatomic, assign) double distanceInYards;

/// <summary>
/// Gets the number of employees employed by the startup.
/// </summary>
@property (readonly, nonatomic, assign) int employeeCount;

/// <summary>
/// Gets URL of the startup's Facebook page.
/// </summary>
@property (readonly, nonatomic, strong) NSString *facebookUrl;

/// <summary>
/// Gets the source of the funds raised by the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *fundingSource;

/// <summary>
/// Gets the URL of the statup's home page.
/// </summary>
@property (readonly, nonatomic, strong) NSString *homePageUrl;

/// <summary>
/// Gets the industry of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *industry;

/// <summary>
/// Gets the URL of the startup's LinkedIn page.
/// </summary>
@property (readonly, nonatomic, strong) NSString *linkedinUrl;

/// <summary>
/// Gets the logo URL of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *logoUrl;

/// <summary>
/// Gets the metro area in which the startup is located.
/// </summary>
@property (readonly, nonatomic, strong) NSString *metroLocation;

/// <summary>
/// Gets the phone number of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *phoneNumber;

/// <summary>
/// Gets the company name of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *startupName;

/// <summary>
/// Gets the state in which the startup is located.
/// </summary>
@property (readonly, nonatomic, strong) NSString *state;

/// <summary>
/// Gets the address of the startup.
/// </summary>
@property (readonly, nonatomic, strong) NSString *streetAddress;

/// <summary>
/// Gets the unique ID assigned to the startup.
/// </summary>
@property (readonly, nonatomic, strong)  NSNumber *startupId;

/// <summary>
/// Gets the amount of money that the startup as raised.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *totalFundingRaised;

/// <summary>
/// Gets the startup's Twitter URL.
/// </summary>
@property (readonly, nonatomic, strong) NSString *twitterUrl;

/// <summary>
/// Gets the zip or postal code of the startup.
/// </summary>
@property (readonly, nonatomic, assign) double zipPostal;

@end