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

/**
 * \mainpage
 * \htmlinclude BuddyiOSSDKIntroduction.htm
 */

#import <Foundation/Foundation.h>
#import "BuddyDevice.h"
#import "BuddyGameBoards.h"
#import "BuddyAppMetadata.h"
#import "BuddySounds.h"


@class BuddyBoolResponse;
@class BuddyArrayResponse;
@class BuddyStringResponse;
@class BuddyAuthenticatedUserResponse;
@class BuddyDateResponse;
@class BuddyWebWrapper;


// BuddyClient callback definitions

/** Callback signature for the BuddyClientCheckIfEmailExists function. BuddyBoolResponse.result field will be TRUE if the email address exists, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
*/
typedef void (^BuddyClientCheckIfEmailExistsCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyClientCheckIfUsernameExists function. BuddyBoolResponse.result field will be TRUE if the user name exists, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
*/
typedef void (^BuddyClientCheckIfUsernameExistsCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyClientPing function. BuddyStringResponse.result field will be "Pong" if the server responds correctly. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
*/
typedef void (^BuddyClientPingCallback)(BuddyStringResponse *response);

/** Callback signature for the BuddyClientGetServiceVersion function. The .result field of the BuddyStringResponse with be the version of the service if the request was successful.If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientGetServiceVersionCallback)(BuddyStringResponse *response);

/** Callback signature for the BuddyClientGetServiceTime function. The .result field of the BuddyDateResponse will correspond to the date time of the Buddy webservice or nil if the request failed. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientGetServiceTimeCallback)(BuddyDateResponse *response);

/** Callback signature for the BuddyClientGetUserEmails function. The .result field of the BuddyArrayResponses will contain an NSArray of email addresses (NSStrings) if the request was successful (BuddyArrayResponses.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientGetUserEmailsCallback)(BuddyArrayResponse *);

/** Callback signature for the BuddyClientGetUserProfiles function. The .result field of the BuddyArrayResponses will contain an NSArray of BuddyUsers if the request was successful (BuddyArrayResponses.isCompleted == TRUE and data was found on the server)  or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientGetUserProfilesCallback)(BuddyArrayResponse *);

/** Callback signature for the BuddyClientGetApplicationStatistics function. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyApplicationStatistics items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientGetApplicationStatisticsCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyClientLogin functions. If the Login was successful the .result field of BuddyAuthenticatedUserResponse will be set to the authenticated user (BuddyAuthenticatedUser) otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientLoginCallback)(BuddyAuthenticatedUserResponse *response);

/** Callback signature for the BuddyClientCreateUser function. If the CreateUser call is successful the .result field of BuddyAuthenticatedUserResponse will be set to the authenticated user (BuddyAuthenticatedUser), and the user will be automatically logged in, otherwise it will be nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyClientCreateUserCallback)(BuddyAuthenticatedUserResponse *response);

/** Callback signature for the BuddyStartSession function. The .result field of BuddyStringRespons will be the session identifier if the request was successful otherwise nil. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyStartSessionCallback)(BuddyStringResponse *response);

/** Callback signature for the BuddyEndSession function.  BuddyBoolResponse.result field will be TRUE if the session was ended, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyEndSessionCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyRecordSessionMetric function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field.
 */
typedef void (^BuddyRecordSessionMetricCallback)(BuddyBoolResponse *response);


/// <summary>
/// Represents the main class and entry point to the Buddy platform. Use this class to interact with the platform, create and login users and modify general
/// application level properties like Devices and Metadata.
/// </summary>

/**
 * \code
 * Example:
 *
 * BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                       appPassword:appPassword];
 * // ping server
 * [bc ping:nil callback:nil];
 *
 *
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  // create a user and log them in
 *  [bc createUser:@"Username" password:@"Password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {
 *          // the new user is created and logged in
 *          BuddyAuthenticatedUser *user = response.result;
 *          // do something with the user
 *      }
 *  }];
 *
 *
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *   __block  BuddyAuthenticatedUser *_buddyUser;
 *
 * // login a user
 *  [bc login:@"Username" password:@"Password"  callback:[^(BuddyAuthenticatedUserResponse * response)
 *  {
 *      if (response.isCompleted && response.result)
 *      {
 *          // the user is logged in, save
 *          _buddyUser = response.result;
 *
 *          // dispatch for updating the UI
 *          dispatch_async(dispatch_get_main_queue(), [^{ [self displayLogin: _buddyUser]; }copy]);
 *      }
 *  }copy]];
 *
 *
 * \endcode
 */

@interface BuddyClient : NSObject

/// <summary>
/// Gets the application name for this client.
/// </summary>
@property (readonly, nonatomic, assign) NSString *appName;

/// <summary>
/// Gets the application password for this client.
/// </summary>
@property (readonly, nonatomic, assign) NSString *appPassword;

/// <summary>
/// Gets the optional string that describes the version of the app you are building. This string is used when uploading
/// device information to Buddy or submitting crash reports. It will default to 1.0.
/// </summary>
@property (readonly, nonatomic, assign) NSString *appVersion;

/// <summary>
/// Gets an object that can be used to record device information about this client or upload crashes.
/// </summary>
@property (readonly, nonatomic, strong) BuddyDevice *device;

/// <summary>
/// Gets an object that can be used to retrieve high score rankings or search for game boards in this application.
/// </summary>
@property (readonly, nonatomic, strong) BuddyGameBoards *gameBoards;

/// <summary>
/// Gets an object that can be used to manipulate application-level metadata. Metadata is used to store custom values on the platform.
/// </summary>
@property (readonly, nonatomic, strong) BuddyAppMetadata *metadata;

/// <summary>
/// Gets an object that can be used to retrieve sounds.
/// </summary>
@property (readonly, nonatomic, strong) BuddySounds *sounds;

/// <summary>
/// Initializes a new instance of the BuddyClient class. To get an application username and password, go to http://buddy.com, create a new
/// developer account and create a new application.
/// </summary>
/// <param name="appName">The name of the application to use with this client. Can't be null or empty.</param>
/// <param name="appPassword">The password of the application to use with this client. Can't be null or empty.</param>

- (id)initClient:(NSString *)appName
     appPassword:(NSString *)appPassword;

/// <summary>
/// Initializes a new instance of the BuddyClient class. To get an application username and password, go to http://buddy.com, create a new
/// developer account and create a new application.
/// </summary>
/// <param name="appName">The name of the application to use with this client. Can't be null or empty.</param>
/// <param name="appPassword">The password of the application to use with this client. Can't be null or empty.</param>
/// <param name="appVersion">Optional string that describes the version of the app you are building. This string will then be used when uploading
/// device information to buddy or submitting crash reports.</param>
/// <param name="autoRecordDeviceInfo">If true automatically records the current device profile with the Buddy Service (device type, os version etc.).</param>

- (id)        initClient:(NSString *)appName
			 appPassword:(NSString *)appPassword
			  appVersion:(NSString *)appVersion
	autoRecordDeviceInfo:(BOOL)autoRecordDeviceInfo;

/// <summary>
/// Ping the service.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of BuddyStringResponse will be "Pong" if the server responded. If the BuddyBoolResponse.isCompleted field is FALSE check the BuddyStringResponse.dataResult and/or BuddyStringResponse.exception for error information.</param>

- (void)ping:(BuddyClientPingCallback)callback;

/// <summary>
/// Get the current Buddy webservice date/time.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyDateResponse will contain an NSDate instance corresponding to the date time of the Buddy webservice or nil if the request failed.</param>

- (void)getServiceTime:(BuddyClientGetServiceTimeCallback)callback;

/// <summary>
/// Get the current version of the service that is being used by this SDK.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyStringResponse will be the version of the service if the request was successful. If the BuddyStringResponse.isCompleted field is FALSE check the BuddyStringResponse.dataResult and/or BuddyStringResponse.exception for error information.</param>

- (void)getServiceVersion:(BuddyClientGetServiceVersionCallback)callback;

/// <summary>
/// Gets a list of emails for all registered users for this app.
/// </summary>
/// <param name="fromRow">Used for paging, retrieve only records starting fromRow.</param>
/// <param name="pageSize">Used for paging, specify page size.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of email addresses (NSStrings) if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getUserEmails:(NSNumber *)fromRow
             pageSize:(NSNumber *)pageSize
                
             callback:(BuddyClientGetUserEmailsCallback)callback;

/// <summary>
/// Gets a list of emails for all registered users for this app.
/// </summary>
/// <param name="fromRow">Used for paging, retrieve only records starting fromRow.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of email addresses (NSStrings) if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getUserEmails:(NSNumber *)fromRow
             callback:(BuddyClientGetUserEmailsCallback)callback;

/// <summary>
/// Gets a list of profiles for all registered users for this app.
/// </summary>
/// <param name="fromRow">Used for paging, retrieve only records starting fromRow.</param>
/// <param name="pageSize">Used for paging, specify page size.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be an NSArray of BuddyUsers if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getUserProfiles:(NSNumber *)fromRow
               pageSize:(NSNumber *)pageSize
                  
               callback:(BuddyClientGetUserProfilesCallback)callback;

/// <summary>
/// Gets a list of profiles for all registered users for this app.
/// </summary>
/// <param name="fromRow">Used for paging, retrieve only records starting fromRow.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will  an NSArray of BuddyUsers if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getUserProfiles:(NSNumber *)fromRow
               callback:(BuddyClientGetUserProfilesCallback)callback;

/// <summary>
/// This method will return a list of statistics for the application covering items such as total users, photos, etc. or nil if error.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyApplicationStatistics items if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getApplicationStatistics:(BuddyClientGetApplicationStatisticsCallback)callback;

/// <summary>
/// Create a new user using the given Social account or log into the existing user
/// for that account.
/// </summary>
/// <param name="providerName">The name of the social login provider to use.</param>
/// <param name="providerUserId">The Id by which the social user can be retrieved from the social login provider.</param>
/// <param name="accessToken">An access token which will allow requests to be made on the users behalf.</param>
/// <param name="callback">The callback to call on success or error. If the Login was successful the .result field of BuddyAuthenticatedUserResponse object will be set to the authenticated user otherwise it will be nil.</param>
- (void)socialLogin:(NSString *)providerName
     providerUserId:(NSString *)providerUserId
        accessToken:(NSString *)accessToken
           callback:(BuddyClientLoginCallback)callback;

/// <summary>
/// Login an existing user with their username and password.
/// </summary>
/// <param name="userName">The username of the user. Can't be nil or empty.</param>
/// <param name="password">The password of the user. Can't be nil.</param>
/// <param name="callback">The callback to call on success or error. If the Login was successful the .result field of BuddyAuthenticatedUserResponse object will be set to the authenticated user otherwise it will be nil.</param>

- (void)login:(NSString *)userName
     password:(NSString *)password
        
     callback:(BuddyClientLoginCallback)callback;

/// <summary>
/// Login an existing user with their secret token. Each user is assigned a token on creation you can store and use it instead of a
/// username/password combination.
/// </summary>
/// <param name="token">The private token of the user to login.</param>
/// <param name="callback">The callback to call on success or error. If the Login was successful the .result field of BuddyAuthenticatedUserResponse will be set to the authenticated user otherwise it will be nil.</param>

- (void)login:(NSString *)token
        
     callback:(BuddyClientLoginCallback)callback;

/// <summary>
/// Create a new Buddy user account and log in as newly created user.
/// </summary>
/// <param name="userName">The name of the new user. Can't be nil or empty.</param>
/// <param name="password">The password of the new user. Can't be nil or empty.</param>
/// <param name="gender">An gender for the user.</param>
/// <param name="age">An age for the user  (must be 0 or greater).</param>
/// <param name="email">An optional email for the user, can be nil.</param>
/// <param name="status">A status for the user.</param>
/// <param name="fuzzLocation">Set location fuzzing for this user. When enabled user location is randomized in searches.</param>
/// <param name="celebrityMode">Set the celebrity mode for this user. When enabled this user will be absent from all searches.</param>
/// <param name="appTag">A custom tag for this user, can be nil.</param>
/// <param name="callback">The callback to call on success or error. If the Login was successful the .result field of BuddyAuthenticatedUserResponse will be set to the authenticated user otherwise it will be nil.</param>

- (void)createUser:(NSString *)userName
          password:(NSString *)password
            gender:(UserGender)gender
               age:(NSNumber *)age
             email:(NSString *)email
            status:(UserStatus)status
      fuzzLocation:(BOOL)fuzzLocation
     celebrityMode:(BOOL)celebrityMode
            appTag:(NSString *)appTag
             
          callback:(BuddyClientCreateUserCallback)callback;

/// <summary>
/// Create a new Buddy user account and log in as newly created user.
/// </summary>
/// <param name="userName">The name of the new user. Can't be nil or empty.</param>
/// <param name="password">The password of the new user. Can't be nil or empty.</param>
/// <param name="callback">The callback to call on success or error. If the Login was successful the .result field of BuddyAuthenticatedUserResponse will be set to the authenticated user otherwise it will be nil.</param>

- (void)createUser:(NSString *)userName
          password:(NSString *)password
          callback:(BuddyClientCreateUserCallback)callback;

/// <summary>
/// Check if another user with the same email already exists in the system.
/// </summary>
/// <param name="email">The email to check for, can't be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on it the email address exists, FALSE otherwise.</param>
- (void)checkIfEmailExists:(NSString *)email
                     
                  callback:(BuddyClientCheckIfEmailExistsCallback)callback;

/// <summary>
/// Starts an analytics session
/// </summary>
/// <param name="user">The user that is starting this session.</param>
/// <param name="sessionName">The name of the session.</param>
/// <param name="appTag">An optional custom tag to include with the session.</param>
/// <param name="callback">The callback to call upon success or error.  The .result field of BuddyStringResponse will be set to the session identifier if the request was successful otherwise nil.</param>
- (void)startSession:(BuddyAuthenticatedUser *)user
		 sessionName:(NSString *)sessionName
			  appTag:(NSString *)appTag
			   
			callback:(BuddyStartSessionCallback)callback;

/// <summary>
/// Starts an analytics session
/// </summary>
/// <param name="user">The user that is starting this session.</param>
/// <param name="sessionName">The name of the session.</param>
/// <param name="callback">The callback to call upon success or error.  The .result field of BuddyStringResponse will be set to the session identifier if the request was successful otherwise nil.</param>
- (void)startSession:(BuddyAuthenticatedUser *)user
         sessionName:(NSString *)sessionName
            callback:(BuddyStartSessionCallback)callback;

/// <summary>
/// Ends an analytics session
/// </summary>
/// <param name="user">The user that is starting this session.</param>
/// <param name="sessionId">The id of the session, returned from StartSessionAsync.</param>
/// <param name="appTag">An optional custom tag to include with the session.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)endSession:(BuddyAuthenticatedUser *)user
		 sessionId:(NSString *)sessionId
			appTag:(NSString *)appTag
			 
		  callback:(BuddyEndSessionCallback)callback;

/// <summary>
/// Ends an analytics session
/// </summary>
/// <param name="user">The user that is starting this session.</param>
/// <param name="sessionId">The id of the session, returned from StartSessionAsync.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)endSession:(BuddyAuthenticatedUser *)user
         sessionId:(NSString *)sessionId
          callback:(BuddyEndSessionCallback)callback;


/// <summary>
/// Records a session metric value
/// </summary>
/// <param name="user">The user that is starting this session.</param>
/// <param name="sessionId">The id of the session, returned from StartSessionAsync.</param>
/// <param name="metricKey">A custom key describing the metric.</param>
/// <param name="metricValue">The value to set.</param>
/// <param name="appTag">An optional custom tag to include with the metric.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)recordSessionMetric:(BuddyAuthenticatedUser *)user
				  sessionId:(NSString *)sessionId
				  metricKey:(NSString *)metricKey
				metricValue:(NSString *)metricValue
					 appTag:(NSString *)appTag
					  
				   callback:(BuddyRecordSessionMetricCallback)callback;

/// <summary>
/// Records a session metric value
/// </summary>
/// <param name="user">The user that is starting this session.</param>
/// <param name="sessionId">The id of the session, returned from StartSessionAsync.</param>
/// <param name="metricKey">A custom key describing the metric.</param>
/// <param name="metricValue">The value to set.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)recordSessionMetric:(BuddyAuthenticatedUser *)user
                  sessionId:(NSString *)sessionId
                  metricKey:(NSString *)metricKey
                metricValue:(NSString *)metricValue
                   callback:(BuddyRecordSessionMetricCallback)callback;

/// <summary>
/// Provides access to BuddyWebService interface to enable the setting of the connection type (https/http) connection timeouts and other properties. (see BuddyWebWrapper).
/// </summary>

- (BuddyWebWrapper *)webService;


- (void)CheckIfUsernameExists:(NSString *)userName
                     callback:(BuddyClientCheckIfUsernameExistsCallback)callback DEPRECATED_ATTRIBUTE;

- (void)StartSession:(BuddyAuthenticatedUser *)user
         sessionName:(NSString *)sessionName
              appTag:(NSString *)appTag
            callback:(BuddyStartSessionCallback)callback DEPRECATED_ATTRIBUTE;

- (void)StartSession:(BuddyAuthenticatedUser *)user
         sessionName:(NSString *)sessionName
            callback:(BuddyStartSessionCallback)callback DEPRECATED_ATTRIBUTE;

- (void)EndSession:(BuddyAuthenticatedUser *)user
         sessionId:(NSString *)sessionId
            appTag:(NSString *)appTag
          callback:(BuddyEndSessionCallback)callback DEPRECATED_ATTRIBUTE;

- (void)EndSession:(BuddyAuthenticatedUser *)user
         sessionId:(NSString *)sessionId
          callback:(BuddyEndSessionCallback)callback DEPRECATED_ATTRIBUTE;

- (void)RecordSessionMetric:(BuddyAuthenticatedUser *)user
                  sessionId:(NSString *)sessionId
                  metricKey:(NSString *)metricKey
                metricValue:(NSString *)metricValue
                     appTag:(NSString *)appTag
                   callback:(BuddyRecordSessionMetricCallback)callback DEPRECATED_ATTRIBUTE;

- (void)RecordSessionMetric:(BuddyAuthenticatedUser *)user
                  sessionId:(NSString *)sessionId
                  metricKey:(NSString *)metricKey
                metricValue:(NSString *)metricValue
                   callback:(BuddyRecordSessionMetricCallback)callback DEPRECATED_ATTRIBUTE;

@end


/// <summary>
/// Represents a class to enable connection setting properties such as timeouts.
/// </summary>

@interface BuddyWebWrapper : NSObject

/// <summary>
/// Enables the display of the phones Network display indicator
/// </summary>
- (void)enableNetworkActivityDisplay;

/// <summary>
/// Disables the display of the phones Network display indicator
/// </summary>
- (void)disableNetworkActivityDisplay;

/// <summary>
/// Set the timeout period for HTTP GET requests, default value 60 seconds.
/// </summary>
- (void)setHttpGetTimeout:(int)timeout;

/// <summary>
/// Set the timeout period for HTTP POST requests, default value 60 seconds.
/// </summary>
- (void)setHttpPostTimeout:(int)timeout;

/// <summary>
/// Set connection to SSL if TRUE, non-SSL if FALSE. Default connection type is SSL.
/// </summary>
- (void)setSSLType:(BOOL)ssl;

@end
