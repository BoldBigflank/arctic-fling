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
#import "BuddyEnums.h"


@class BuddyAuthenticatedUser;
@class BuddyBoolResponse;
@class BuddyArrayResponse;


// BuddyNotifications callback definitions

/** Callback signature for the BuddyNotificationsAppleRegisterDevice function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyNotificationsAppleRegisterDeviceCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyNotificationsAppleUnregisterDevice function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyNotificationsAppleUnregisterDeviceCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyNotificationsAppleSendRawMessage function. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyNotificationsAppleSendRawMessageCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyNotificationsAppleGetRegisteredDevices function. If success BuddyArrayResponse .result is a NSArray of registered devices with user IDs. You can then user the IDs to send notifications to those users. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyNotificationsAppleGetRegisteredDevicesCallback)(BuddyArrayResponse *response);

/** Callback signature for the BuddyNotificationsAppleGetGroups function. If successful the BuddyDictionaryResponsess.result field is a NSDictionary of group names with counts per group. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyNotificationsAppleGetGroupsCallback)(BuddyDictionaryResponse *response);

/// <summary>
/// Represents an object that can be used to register Apple devices for push notifications. The class can also be used to query for all registered devices and
/// to send them notifications.
/// </summary>


/**
 * \code
 * Example:
 *  BuddyClient *bc = [[BuddyClient alloc] initClient:appName
 *                                        appPassword:appPassword];
 *
 *  __block  BuddyAuthenticatedUser *_user;
 *  [bc login:@"username" password:@"password"  callback:[^(BuddyAuthenticatedUserResponse *response)
 *  {
 *      if (response.isCompleted)
 *      {   // get the user
 *          _user = response.result;
 *
 *          // prepare to send a push message to first 100 registered users
 *          NSNumber *size = [NSNumber numberWithInt:100];
 *          NSNumber *page = [NSNumber numberWithInt:1];
 *
 *          // request up to 100 registered users
 *          [_user.pushNotifications getRegisteredDevices:nil pageSize:size currentPage:page  callback:[^(BuddyArrayResponse *response)
 *          {
 *              if (response.isCompleted && response.result != nil)
 *              {
 *                  // now send an iOS push notification to those registered user returned
 *                  NSDate *deliveryDate = [[NSDate alloc] init];
 *
 *                  // get the array of devices
 *                  NSArray *devices = response.result;
 *
 *                  for (id device in devices)
 *                  { // get the device
 *                      BuddyRegisteredDeviceApple *regDevice = (BuddyRegisteredDeviceApple *) device;
 *
 *                      // send a push notification to the user who has registered the device
 *                      [user.pushNotifications sendRawMessage:regDevice.userIdAsString
 *                                                      message:@"Message"
 *                                                        badge:@"1"
 *                                                        sound:@"default"
 *                                                  customItems:nil
 *                                                 deliverAfter:deliveryDate
 *                                                    groupName:nil
 *                                                        
 *                                                     callback:nil];
 *                   }
 *              }
 *          }copy]];
 *      }
 *  }copy]];
 * \endcode
 */

@interface BuddyNotificationsApple : NSObject

/// <summary>
/// Register an Apple device for notifications with Buddy.
/// </summary>
/// <param name="appleDeviceToken">A token provided by the Apple Push Notification Service (APNs) which identifies the device to register (analogous to a phone number). Cannot be nil.</param>
/// <param name="groupName">Register this device as part of a group, so that you can send the whole group messages, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)registerDevice:(NSData *)appleDeviceToken
             groupName:(NSString *)groupName
                 
              callback:(BuddyNotificationsAppleRegisterDeviceCallback)callback;

/// <summary>
/// Register an Apple device for notifications with Buddy.
/// </summary>
/// <param name="appleDeviceToken">A token provided by the Apple Push Notification Service (APNs) which identifies the device to register (analogous to a phone number). Cannot be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)registerDevice:(NSData *)appleDeviceToken
              callback:(BuddyNotificationsAppleRegisterDeviceCallback)callback;

/// <summary>
/// Unregister the current user from push notifications for Apple devices.
/// </summary>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)unregisterDevice:(BuddyNotificationsAppleUnregisterDeviceCallback)callback;

/// <summary>
/// Get a paged list of registered Apple devices for this Application. This list can then be used to iterate over the devices and send each user a push notification.
/// </summary>
/// <param name="group">Optionally filter only devices in a certain group, can be nil.</param>
/// <param name="pageSize">Set the number of devices that will be returned for each call of this method.</param>
/// <param name="currentPage">Set the current page.</param>
/// <param name="callback">The callback to call on success or error. If success BuddyArrayResponse .result is a NSArray  of registered devices with user IDs. You can then user the IDs to send notifications to those users.</param>

- (void)getRegisteredDevices:(NSString *)group
                    pageSize:(NSNumber *)pageSize
                 currentPage:(NSNumber *)currentPage
                       
                    callback:(BuddyNotificationsAppleGetRegisteredDevicesCallback)callback;

/// <summary>
/// Get a paged list of registered Apple devices for this Application. This list can then be used to iterate over the devices and send each user a push notification.
/// </summary>
/// <param name="callback">The callback to call on success or error. If success BuddyArrayResponse .result is a NSArray  of registered devices with user IDs. You can then user the IDs to send notifications to those users.</param>

- (void)getRegisteredDevices:(BuddyNotificationsAppleGetRegisteredDevicesCallback)callback;

/// <summary>
/// Get a list of Apple groups that have been registered with Buddy as well as the number of users in each group. groups can be used to batch-send
/// push notifications to a number of users at the same time.
/// </summary>
/// <param name="callback">The callback to call on success or error. If successful the BuddyDictionaryResponse.result field is a NSDictionary of group names with counts per group.</param>

- (void)getGroups:(BuddyNotificationsAppleGetGroupsCallback)callback;

/// <summary>
/// Send a raw message to a Apple device. Note that this call does not directly send the message but rather, adds the raw message to the queue of messages to be sent.
/// </summary>
/// <param name="senderUserId">The Id or the token of the user who is to receive the message, cannot be nil or empty.</param>
/// <param name="message">The message to send to the user. cannot be nil or empty</param>
/// <param name="badge">The badge number to set on the icon. It is the application's responsibility to determine what number to set, can be nil.</param>
/// <param name="sound">The notification sound to play, can be nil.</param>
/// <param name="customItems">metadata to send with the message for the receiving application to use. Data should be specified as key/value pairs where each key and value are separated by a comma and each pair is separated by a ";" character including the last pair i.e.: key,value;key,value;. Leave empty or set to nil if there is no metadata to send.</param>
/// <param name="deliverAfter">Schedule the message to be delivered after a certain date.</param>
/// <param name="groupName">Send messages to an entire group of users, not just a one.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)sendRawMessage:(NSString *)senderUserId
               message:(NSString *)message
                 badge:(NSString *)badge
                 sound:(NSString *)sound
           customItems:(NSString *)customItems
          deliverAfter:(NSDate *)deliverAfter
             groupName:(NSString *)groupName
                 
              callback:(BuddyNotificationsAppleSendRawMessageCallback)callback;

/// <summary>
/// Send a raw message to a Apple device. Note that this call does not directly send the message but rather, adds the raw message to the queue of messages to be sent.
/// </summary>
/// <param name="senderUserId">The Id or the token of the user who is to receive the message, cannot be nil or empty.</param>
/// <param name="message">The message to send to the user. cannot be nil or empty.</param>
/// <param name="badge">The badge number to set on the icon. It is the application's responsibility to determine what number to set, can be nil.</param>
/// <param name="sound">The notification sound to play, can be nil.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)sendRawMessage:(NSString *)senderUserId
               message:(NSString *)message
                 badge:(NSString *)badge
                 sound:(NSString *)sound
              callback:(BuddyNotificationsAppleSendRawMessageCallback)callback;

@end