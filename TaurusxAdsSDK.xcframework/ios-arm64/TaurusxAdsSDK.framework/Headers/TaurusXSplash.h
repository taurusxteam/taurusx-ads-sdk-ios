//
//  TaurusXSplash.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/9/12.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TaurusxAdsSDK/TaurusXBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TaurusXSplashDelegate <NSObject>

- (void)adLoadFinish;
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adDismissed;

@end

@interface TaurusXSplash : TaurusXBase

@property (nonatomic,weak) id <TaurusXSplashDelegate> delegate;
@property (nonatomic,assign) BOOL isMute;


- (BOOL)isReady;
- (void)loadSplash;
- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate;
- (void)showAd;

@end

NS_ASSUME_NONNULL_END
