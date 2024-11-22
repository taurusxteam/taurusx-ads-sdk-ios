//
//  TaurusXRewarded.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/9/11.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TaurusxAdsSDK/TaurusXBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TaurusXRewardedDelegate <NSObject>

- (void)adLoadFinish;
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adDismissed;
- (void)adVideoComplete;
- (void)adRewardedWithName:(NSString*)name value:(NSInteger)value;

@end

@interface TaurusXRewarded : TaurusXBase

@property (nonatomic,assign) BOOL isMute;
@property (nonatomic,copy) NSString *custmoData;
@property (nonatomic,weak) id <TaurusXRewardedDelegate> delegate;


- (void)loadRewarded;

- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate;

- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

- (BOOL)isReady;


@end

NS_ASSUME_NONNULL_END
