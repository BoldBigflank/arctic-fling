//
//  BuddyBlob.h
//  BuddySDK
//
//  Created by Ryan Brandenburg on 5/15/13.
//
//

#import <Foundation/Foundation.h>

@class BuddyArrayResponse;
@class BuddyBoolResponse;

typedef void (^BuddyBlobEditBlobCallback)(BuddyBoolResponse * response);

typedef void (^BuddyBlobDeleteBlobCallback) (BuddyBoolResponse * response);

/// <summary>
/// Represents a Blob object.
/// </summary>

@interface BuddyBlob : NSObject

/// <summary>
/// Gets the BlobID for this blob
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *blobId;


/// <summary>
/// Gets the FriendlyName for this blob
/// </summary>
@property (readonly, nonatomic, strong) NSString *friendlyName;

@property (readonly, nonatomic, strong) NSString *mimeType;

@property (readonly, nonatomic, strong) NSNumber *fileSize;

@property (readonly, nonatomic, strong) NSString *appTag;

@property (readonly, nonatomic, strong) NSNumber *owner;

@property (readonly, nonatomic, assign) double latitude;

@property (readonly, nonatomic, assign) double longitude;

@property (readonly, nonatomic, strong) NSDate *uploadDate;

@property (readonly, nonatomic, strong) NSDate *lastTouchDate;

//TODO: figure out a better return type
-(void)getBlob:(void(^)(NSData *))callback;

-(void)editBlob:(NSString *)localFriendlyName
         localAppTag:(NSString *)localAppTag
       callback:(BuddyBlobEditBlobCallback)callback;

-(void)deleteBlob:(BuddyBlobDeleteBlobCallback)callback;

@end