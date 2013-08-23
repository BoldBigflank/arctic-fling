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

/** Callback signature for the BuddyCommerceGetReceiptsForUser and BuddyCommerceGetReceiptForUserAndTransactionID functions. The .result field of the BuddyArrayResponse will contain an NSArray of BuddyReceipts if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyCommerceGetReceiptsCallback)(BuddyArrayResponse *response);


/** Callback signature for the BuddyCommerceSaveReceipt function. The .result field of the BuddyBoolResponse object will be TRUE on success, FALSE otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the response.dataResult field
 */
typedef void (^BuddyCommerceSaveReceiptCallback)(BuddyBoolResponse *response);

/** Callback signature for the BuddyCommerceGetAllStoreItems, BuddyCommerceActiveStoreItems and BuddyCommerceFreeStoreItems functions.The .result field of the BuddyArrayResponse will contain an NSArray of BuddyStoreItems if the request was successful (BuddyArrayResponse.isCompleted == TRUE and data was found on the server) or nil otherwise. If there was an exception or error (e.g. unknown server response or invalid data) the Response.exception field will be set to an exception instance and the raw response from the server, if any, will be held in the Response.dataResult field.
 */
typedef void (^BuddyCommerceStoreItemsCallback)(BuddyArrayResponse *response);


@interface BuddyCommerce : NSObject

/// <summary>
/// Finds the receipt list based on the FromDateTime parameter for the currently logged in user.
/// </summary>
/// <param name="fromDateTime">The starting date and time to get receipts from, leave this blank to get all the receipts.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be set to an NSArray of BuddyReceipts if the request was successful otherwise nil if the request failed.</param>

- (void)getReceiptsForUser:(NSDate *)fromDateTime
                  callback:(BuddyCommerceGetReceiptsCallback)callback;
    
/// <summary>
/// Finds the receipt associated with the specified CustomTransactionID for the currently logged in user.
/// </summary>
/// <param name="customTransactionID">The CustomTransactionID of the transaction. For Facebook payments this is the OrderID of the transaction.</param>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be set to an NSArray of BuddyReceipts if the request was successful otherwise nil if the request failed.</param>

- (void)getReceiptForUserAndTransactionID:(NSString *)customTransactionID
                                 callback:(BuddyCommerceGetReceiptsCallback)callback;

/// <summary>
/// Saves a receipt for the purchase of an item made to the application's store.
/// </summary>
/// <param name="totalCost">The total cost for the items purchased in the transaction.</param>
/// <param name="totalQuantity">The total number of items purchased.</param>
/// <param name="storeItemID">The store ID of the item of the item being purchased.</param>
/// <param name="storeName">The name of the application's store to be saved with the transaction. This field is used by the commerce analytics to track purchases.</param>
/// <param name="receiptData">Optional information to store with the receipt such as notes about the transaction.</param>
/// <param name="customTransactionID">An optional app-specific ID to associate with the purchase.</param>
/// <param name="appData">Optional metadata to associate with the transaction.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)saveReceipt:(NSString *)totalCost
      totalQuantity:(int)totalQuantity
        storeItemID:(NSNumber *)storeItemID
          storeName:(NSString *)storeName 
        receiptData:(NSString *)receiptData
customTransactionID:(NSString *)customTransactionID
            appData:(NSString *)appData
           callback:(BuddyCommerceSaveReceiptCallback)callback;

/// <summary>
/// Saves a receipt for the purchase of an item made to the application's store.
/// </summary>
/// <param name="totalCost">The total cost for the items purchased in the transaction.</param>
/// <param name="totalQuantity">The total number of items purchased.</param>
/// <param name="storeItemID">The store ID of the item of the item being purchased.</param>
/// <param name="storeName">The name of the application's store to be saved with the transaction. This field is used by the commerce analytics to track purchases.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)saveReceipt:(NSString *)totalCost
      totalQuantity:(int)totalQuantity
        storeItemID:(NSNumber *)storeItemID
          storeName:(NSString *)storeName 
           callback:(BuddyCommerceSaveReceiptCallback)callback;

/// <summary>
/// Verifies that a receipt received from the Apple store is actually from Apple.
/// </summary>
/// <param name="totalCost">The total cost for the items purchased in the transaction.</param>
/// <param name="totalQuantity">The total number of items purchased.</param>
/// <param name="receiptData">The base64-encoded iOS In-App Purchase receipt.</param>
/// <param name="useSandbox">Set to true when testing this function in a "sandbox" to execute this call against the Apple sandbox server, or false to have the call executed against the production Apple server.</param>
/// <param name="appleItemID">The optional ID associated with the item as assigned by Apple.</param>
/// <param name="customTransactionID">An optional app-specific ID to associate with the purchase.</param>
/// <param name="appData">Optional metadata to associated with the transaction.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)verifyiOSReceipt:(NSString *)totalCost
           totalQuantity:(int)totalQuantity
             receiptData:(NSString *)receiptData
              useSandbox:(BOOL)useSandbox
             appleItemID:(NSString *)appleItemID
     customTransactionID:(NSString *)customTransactionID
                 appData:(NSString *)appData
                callback:(BuddyCommerceSaveReceiptCallback)callback;

/// <summary>
/// Verifies that a receipt received from the Apple store is actually from Apple.
/// </summary>
/// <param name="totalCost">The total cost for the items purchased in the transaction.</param>
/// <param name="totalQuantity">The total number of items purchased.</param>
/// <param name="receiptData">The base64-encoded iOS In-App Purchase receipt.</param>
/// <param name="appleItemID">The optional ID associated with the item as assigned by Apple.</param>
/// <param name="useSandbox">Set to true when testing this function in a "sandbox" to execute this call against the Apple sandbox server, or false to have the call executed against the production Apple server.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)verifyiOSReceipt:(NSString *)totalCost
           totalQuantity:(int)totalQuantity
             receiptData:(NSString *)receiptData
              useSandbox:(BOOL)useSandbox
             appleItemID:(NSString *)appleItemID
                callback:(BuddyCommerceSaveReceiptCallback)callback;

/// <summary>
/// Verifies that a receipt received from the Apple store is actually from Apple and stores a copy of the ceceipt on the Buddy's servers.
/// </summary>
/// <param name="totalCost">The total cost for the items purchased in the transaction.</param>
/// <param name="totalQuantity">The total number of items purchased.</param>
/// <param name="receiptData">The base64-encoded iOS In-App Purchase receipt.</param>
/// <param name="useSandbox">Set to true when testing this function in a "sandbox" to execute this call against the Apple sandbox server, or false to have the call executed against the production Apple server.</param>
/// <param name="appleItemID">The optional ID associated with the item as assigned by Apple.</param>
/// <param name="customTransactionID">An optional app-specific ID to associate with the purchase.</param>
/// <param name="appData">Optional metadata to associated with the transaction.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)verifyAndSaveiOSReceipt:(NSString *)totalCost
           totalQuantity:(int)totalQuantity
             receiptData:(NSString *)receiptData
              useSandbox:(BOOL)useSandbox
             appleItemID:(NSString *)appleItemID 
     customTransactionID:(NSString *)customTransactionID
                 appData:(NSString *)appData
                callback:(BuddyCommerceSaveReceiptCallback)callback;

/// <summary>
/// Verifies that a receipt received from the Apple store is actually from Apple and stores a copy of the ceceipt on the Buddy's servers.
/// </summary>
/// <param name="totalCost">The total cost for the items purchased in the transaction.</param>
/// <param name="totalQuantity">The total number of items purchased.</param>
/// <param name="receiptData">The base64-encoded iOS In-App Purchase receipt.</param>
/// <param name="useSandbox">Set to true when testing this function in a "sandbox" to execute this call against the Apple sandbox server, or false to have the call executed against the production Apple server.</param>
/// <param name="appleItemID">The optional ID associated with the item as assigned by Apple.</param>
/// <param name="callback">The callback to call when this method completes. BuddyBoolResponse.result field will be TRUE on success, FALSE otherwise.</param>

- (void)verifyAndSaveiOSReceipt:(NSString *)totalCost
           totalQuantity:(int)totalQuantity
            receiptData:(NSString *)receiptData
              useSandbox:(BOOL)useSandbox
             appleItemID:(NSString *)appleItemID
                callback:(BuddyCommerceSaveReceiptCallback)callback;

/// <summary>
/// Returns information about all items in the store for the current application.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be set to an NSArray of BuddyStoreItem if the request was successful otherwise nil if the request failed.</param>

- (void)getAllStoreItems:(BuddyCommerceStoreItemsCallback)callback;

/// <summary>
/// Returns information about all store items for an application which are currently active (available for sale).
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be set to an NSArray of BuddyStoreItem if the request was successful otherwise nil if the request failed.</param>

- (void)getActiveStoreItems:(BuddyCommerceStoreItemsCallback)callback;

/// <summary>
/// Returns information about all items in the store for the current application which are marked as free.
/// </summary>
/// <param name="callback">The callback to call on success or error. The .result field of the BuddyArrayResponse will be set to an NSArray of BuddyStoreItem if the request was successful otherwise nil if the request failed.</param>

- (void)getFreeStoreItems:(BuddyCommerceStoreItemsCallback)callback;

@end