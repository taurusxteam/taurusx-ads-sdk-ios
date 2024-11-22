//
//  TaurusXAdError.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/9/27.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, TaurusXAdErrorCode) {
    ERROR_CODE_INVALID_REQUEST = 1,
    ERROR_CODE_NETWORK_ERROR = 2,
    ERROR_CODE_NO_FILL = 3,
    ERROR_CODE_TIMEOUT = 4,
    ERROR_CODE_SHOW = 5,
    ERROR_CODE_NO_CONTENT = 6,
    ERROR_CODE_INTERNAL_ERROR = 7,
    ERROR_CODE_PARSE_ERROR = 8,
    ERROR_CODE_DOWNLOAD_ERROR = 9,
};


@interface TaurusXAdError : NSObject

+ (NSError *)internalErrorWithMessage:(NSString*)message;
+ (NSError *)invalidRequestErrorWithMessage:(NSString*)message;
+ (NSError *)networkErrorWithMessage:(NSString*)message;
+ (NSError *)noFillErrorWithMessage:(NSString*)message;
+ (NSError *)timeOutErrorWithMessage:(NSString*)message;
+ (NSError *)showFailedErrorWithMessage:(NSString*)message;
+ (NSError *)noContentErrorWithMessage:(NSString*)message;
+ (NSError *)parseErrorWithMessage:(NSString*)message;
+ (NSError *)downloadErrorWithMessage:(NSString*)message;

+ (NSError *)errorWithCode:(NSInteger)code Message:(NSString*)message;
+ (NSError *)convertError:(NSError*)error;
@end

NS_ASSUME_NONNULL_END
