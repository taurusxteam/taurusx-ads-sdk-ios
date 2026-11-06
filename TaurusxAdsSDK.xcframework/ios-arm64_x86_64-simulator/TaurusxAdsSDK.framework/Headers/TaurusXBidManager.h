//
//  TaurusXBidManager.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/12/9.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TaurusXBidManager : NSObject

+ (void)getToken:(NSString *)placementId withCompletion:(void(^)(NSString * _Nullable token))completion
        DEPRECATED_MSG_ATTRIBUTE("This method is deprecated,use makeToken instead.");


+ (void)makeToken:(NSString *)placementId withCompletion:(void (NS_SWIFT_SENDABLE ^)(NSString * _Nullable token, NSError * _Nullable error))completionHandler;
@end

NS_ASSUME_NONNULL_END
