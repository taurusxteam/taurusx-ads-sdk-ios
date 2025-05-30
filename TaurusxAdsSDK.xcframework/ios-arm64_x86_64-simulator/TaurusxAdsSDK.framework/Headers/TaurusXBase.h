//
//  TaurusXBase.h
//  fluteSDKSample
//
//  Created by Don on 2024/8/23.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface TaurusXBase : NSObject

@property (nonatomic,readonly,assign) CGFloat price;
@property (nonatomic,readonly,assign) BOOL isLoading;
@property (nonatomic,readwrite,copy)  NSString *placementId;
@property (nonatomic,readonly,strong) NSDate *startLoadTime;
@property (nonatomic,readonly,strong) NSDate *finishLoadTime;
@property (nonatomic,readonly,strong) SKStoreProductViewController *storeViewController;

@end

NS_ASSUME_NONNULL_END
