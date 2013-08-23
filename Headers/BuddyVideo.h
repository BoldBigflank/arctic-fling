//
//  BuddyVideo.h
//  BuddySDK
//
//  Created by Ryan Brandenburg on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "BuddyVideos.h"

@class BuddyArrayResponse;
@class BuddyBoolResponse;

typedef void (^BuddyVideoEditVideoCallback)(BuddyBoolResponse * response);

typedef void (^BuddyVideoDeleteVideoCallback)(BuddyBoolResponse * response);


/// <summary>
/// Represents a Video object.
/// </summary>
@interface BuddyVideo : NSObject

/// <summary>
/// Gets the VideoID for this video
/// </summary>
@property (readonly, nonatomic, strong) NSNumber *videoId;


/// <summary>
/// Gets the FriendlyName for this video
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

@property (readonly, nonatomic, strong) NSString *videoUrl;

-(void)editVideo:(NSString *)localFriendlyName
     localAppTag:(NSString *)localAppTag
       callback:(BuddyVideoEditVideoCallback)callback;

-(void)deleteVideo:(BuddyVideoDeleteVideoCallback)callback;


@end
