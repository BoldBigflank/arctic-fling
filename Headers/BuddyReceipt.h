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
/// Represents a receipt in the Buddy system.
/// </summary>

@interface BuddyReceipt : NSObject

/// <summary>
/// Gets the ID of the retrieved receipt history item.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *receiptHistoryId;

/// <summary>
/// Gets the name of the store in which this receipt was saved.
/// </summary>
@property (readonly, nonatomic, strong) NSString *storeName;

/// <summary>
/// Gets the ID of the user this receipt was saved for.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *userId;

/// <summary>
/// Gets the DateTime this receipt was saved or modified.
/// </summary>
@property (readonly, nonatomic, strong) NSDate *historyDateTime;

/// <summary>
/// Gets the receipt data that was stored with this receipt.
/// </summary>
@property (readonly, nonatomic, strong) NSString *receiptData;

/// <summary>
/// Gets the total cost of the transaction associated with this receipt.
/// </summary>
@property (readonly, nonatomic, strong) NSString *totalCost;

/// <summary>
/// Gets the number of items which were purchased during the transaction associated with this receipt.
/// </summary>
@property (readonly, nonatomic, assign) int itemQuantity;

/// <summary>
/// Gets the (optional) metadata that was stored with this receipt.
/// </summary>
@property (readonly, nonatomic, strong) NSString *appData;

/// <summary>
/// Gets the customTransactionID that was saved for this receipt.
/// </summary>
@property (readonly, nonatomic, strong) NSString *historyCustomTransactionId;

/// <summary>
/// Gets the raw verification data associated with the receipt as returned from the underlying Facebook or Apple servers.
/// </summary>
@property (readonly, nonatomic, strong) NSString *verificationResultData;

/// <summary>
/// Gets the Buddy StoreItemID of the item purchased in this transaction.
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *storeItemId;


@property (readonly, nonatomic, strong) NSNumber *receiptHistoryID DEPRECATED_ATTRIBUTE;
@property (readonly, nonatomic, strong) NSNumber *storeItemID DEPRECATED_ATTRIBUTE;
@property (readonly, nonatomic, strong) NSString *historyCustomTransactionID DEPRECATED_ATTRIBUTE;
@property (readonly, nonatomic, strong) NSNumber *userID DEPRECATED_ATTRIBUTE;

@end
