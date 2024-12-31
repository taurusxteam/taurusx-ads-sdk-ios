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

+ (void)getToken:(NSString *)placementId withCompletion:(void(^)(NSString * _Nullable token))completion;
@end

NS_ASSUME_NONNULL_END
