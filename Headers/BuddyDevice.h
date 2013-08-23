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
#import "BuddyAuthenticatedUser.h"


@class BuddyBoolResponse;


// BuddyDevice callback definitions

/** Callback signature for the BuddyDeviceRecordInformation function. The .result field of the BuddyBoolResponse object will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyDeviceRecordInformationCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyDeviceRecordCrash function. The .result field of the BuddyBoolResponse object will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyDeviceRecordCrashCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represents an object that can be used to record device analytics, like device types and app crashes.
/// </summary>

/**
 * \code
 * Example:
 * BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                          password:appPassword];
 *
 * [bc.device recordInformation:@"iphone" deviceType:@"iphone" authenticatedUser:nil appVersion:@"1.0" latitude:55.5 longitude:55.4 metadata:name  callback:^(BuddyBoolResponse *response)
 * {
 *  if (response.isCompleted && response.result == TRUE)
 *      NSLog(@"Analytics_RecordInformation OK");
 * }];
 *
 *
 * Example:
 * BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                          password:appPassword];
 *
 * [bc.device recordCrash:@"TestMethod" osVersion:@"iphone" deviceType:@"iphone" authenticatedUser:nil stackTrace:@"" appVersion:@"1.0" latitude:55.7 longitude:55.5 metadata:name  callback:^(BuddyBoolResponse *response)
 * {
 *  if (response.isCompleted && response.result == TRUE)
 *      NSLog(@"Analytics_RecordCrash OK");
 * }];
 * \endcode
 */

@interface BuddyDevice : NSObject

-(NSString*)id;

/// <summary>
/// Record runtime device type information. This info will be uploaded to the Buddy service and can later be used for analytics purposes.
/// </summary>
/// <param name="osVersion">The OS version of the device running this code.</param>
/// <param name="deviceType">The type of device running this app.</param>
/// <param name="authUser">The user that's registering this device information.</param>
/// <param name="appVersion">The optional version of this application, can be nil.</param>
/// <param name="latitude">Optional latitude where this report was submitted.</param>
/// <param name="longitude">Optional longitude where this report was submitted.</param>
/// <param name="metadata">An optional application specific metadata string to include with the report, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)recordInformation:(NSString *)osVersion
               deviceType:(NSString *)deviceType
                 authUser:(BuddyAuthenticatedUser *)authUser
               appVersion:(NSString *)appVersion
                 latitude:(double)latitude
                longitude:(double)longitude
                 metadata:(NSString *)metadata
                    
                 callback:(BuddyDeviceRecordInformationCallback)callback;

/// <summary>
/// Record runtime device type information. This info will be uploaded to the Buddy service and can later be used for analytics purposes.
/// </summary>
/// <param name="osVersion">The OS version of the device running this code.</param>
/// <param name="deviceType">The type of device running this app.</param>
/// <param name="authUser">The user that's registering this device information.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)recordInformation:(NSString *)osVersion
               deviceType:(NSString *)deviceType
                 authUser:(BuddyAuthenticatedUser *)authUser
                 callback:(BuddyDeviceRecordInformationCallback)callback;

/// <summary>
/// Record runtime crash information for this app. This could be exceptions, errors, or your own custom crash information.
/// </summary>
/// <param name="methodName">The method name or location where the error happened. This could also be a descriptive string of the error.</param>
/// <param name="osVersion">The OS version of the device running this code.</param>
/// <param name="deviceType">The type of device running this app.</param>
/// <param name="authUser">The authenticated user that's registering this device information.</param>
/// <param name="stackTrace">The optional stack trace of where the error happened, can be nil.</param>
/// <param name="appVersion">The optional version of this application, can be nil.</param>
/// <param name="latitude">Optional latitude where this report was submitted.</param>
/// <param name="longitude">Optional longitude where this report was submitted.</param>
/// <param name="metadata">An optional application specific metadata string to include with the report, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)recordCrash:(NSString *)methodName
          osVersion:(NSString *)osVersion
         deviceType:(NSString *)deviceType
           authUser:(BuddyAuthenticatedUser *)authUser
         stackTrace:(NSString *)stackTrace
         appVersion:(NSString *)appVersion
           latitude:(double)latitude
          longitude:(double)longitude
           metadata:(NSString *)metadata
              
           callback:(BuddyDeviceRecordCrashCallback)callback;

/// <summary>
/// Record runtime crash information for this app. This could be exceptions, errors or your own custom crash information.
/// </summary>
/// <param name="methodName">The method name or location where the error happened. This could also be a descriptive string of the error.</param>
/// <param name="osVersion">The OS version of the device running this code.</param>
/// <param name="deviceType">The type of device running this app.</param>
/// <param name="authUser">The authenticated user that's registering this device information.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)recordCrash:(NSString *)methodName
          osVersion:(NSString *)osVersion
         deviceType:(NSString *)deviceType
           authUser:(BuddyAuthenticatedUser *)authUser
           callback:(BuddyDeviceRecordCrashCallback)callback;

@end