//
//  TaurusXInterstitial.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/9/7.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TaurusxAdsSDK/TaurusXBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TaurusXInterstitialDelegate <NSObject>

- (void)adLoadFinish;
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adDismissed;
@end



@interface TaurusXInterstitial : TaurusXBase

@property (nonatomic,assign) BOOL isMute;
@property (nonatomic,weak) id <TaurusXInterstitialDelegate> delegate;

- (void)loadInterstitial;

- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate;

- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

- (BOOL)isReady;
@end

NS_ASSUME_NONNULL_END
