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


@class BuddyBoolResponse;
@class BuddyUser;
@class BuddyMessageGroups;


// BuddyMessages callback definitions

/** Callback signature for the BuddyMessagesSend function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessagesSendCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyMessagesGetReceived function.  The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessage items sent to the user if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessagesGetReceivedCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyMessagesGetSent function.  The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessage items sent to the user if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyMessagesGetSentCallback)(BuddyArrayResponse *response);


/// <summary>
/// Represents an object that can be used to send message from one user to another.
/// </summary>

/**
 * \code
 * Example:
 *
 *  BuddyUser *someOtherUser;  // a user acquired elsewhere
 *
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                           password:appPassword];
 *
 *
 *  [bc login:@"username" password:@"password"  callback:^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          BuddyAuthenticatedUser *user = response.result;
 *
 *          // send a message to user some user
 *          [user.messages send:someOtherUser message:@"Some Message" appTag:nil  callback:^(BuddyBoolResponse *response)
 *          {
 *              if (response.isCompleted && response.result == TRUE)
 *                  NSLog(@"Message sent Ok");
 *          }];
 *      }
 *  }];
 * \endcode
 */

@interface BuddyMessages : NSObject

@property (readonly, nonatomic, strong) BuddyMessageGroups *groups;

/// <summary>
/// Send a message to a user from the current authenticated user.
/// </summary>
/// <param name="toUser">The user to send a message to.</param>
/// <param name="message">The message to send, must be less then 200 characters.</param>
/// <param name="appTag">An optional application tag to set for the message, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)send:(BuddyUser *)toUser
     message:(NSString *)message
      appTag:(NSString *)appTag
       
    callback:(BuddyMessagesSendCallback)callback;

/// <summary>
/// Send a message to a user from the current authenticated user.
/// </summary>
/// <param name="toUser">The user to send a message to.</param>
/// <param name="message">The message to send, must be less then 200 characters.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)send:(BuddyUser *)toUser
     message:(NSString *)message
    callback:(BuddyMessagesSendCallback)callback;

/// <summary>
/// Get all received message by the current user.
/// </summary>
/// <param name="afterDate">Optionally retrieve only messages after a certain DateTime.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessage items sent to the user if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getReceived:(NSDate *)afterDate
              
           callback:(BuddyMessagesGetReceivedCallback)callback;

/// <summary>
/// Get all received message by the current user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessage items sent to the user if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getReceived:(BuddyMessagesGetReceivedCallback)callback;

/// <summary>
/// Get all sent message by the current user.
/// </summary>
/// <param name="afterDate">Optionally retrieve only messages after a certain DateTime.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessage items sent by the user if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getSent:(NSDate *)afterDate
          
       callback:(BuddyMessagesGetSentCallback)callback;

/// <summary>
/// Get all sent message by the current user.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyMessage items sent by the user if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise.</param>

- (void)getSent:(BuddyMessagesGetSentCallback)callback;

@end