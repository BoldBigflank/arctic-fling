//
//  BuddyFile.h
//  BuddySDK
//
//  Created by Shawn Burke on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

@interface BuddyFile : NSObject
@property(nonatomic, retain) NSData* data;
@property(nonatomic, retain) NSString* contentType;
@property(nonatomic, retain) NSString* fileName;

-(id)init;
-(id)initWithImage:(UIImage*)image;
-(id)initWithData:(NSData*)data contentType:(NSString*)contentType fileName:(NSString*) fileName;

@end
