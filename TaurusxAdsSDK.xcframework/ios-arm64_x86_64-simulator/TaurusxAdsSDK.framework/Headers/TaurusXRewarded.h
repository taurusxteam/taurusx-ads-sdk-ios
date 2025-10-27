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
@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adDismissed;
- (void)adVideoComplete;
- (void)adRewardedWithName:(NSString*)name value:(NSInteger)value;
@end


@interface TaurusXRewarded : TaurusXBase

/// Boolean value indicating if the audio is muted.Default is No.
@property (nonatomic,assign) BOOL isMute;

/// Custom information can be set before calling loadReward.
/// This information will be passed through to the callback URL provided by the client for verification.
@property (nonatomic,copy) NSString *custmoData;

/// A delegate that will be notified about ad events.
@property (nonatomic,weak) id <TaurusXRewardedDelegate> delegate;


/**
 * Load a new ad by network request.
 */
- (void)loadRewarded;

/**
 * Load a new ad with payload data.
 */
- (void)loadWithPayload:(NSString *)payload;

/**
 * Presents the rewarded ad. Must be called on the main thread.
 *
 * @param rootViewController A view controller to present the ad. If nil, attempts to present from
 * the top view controller of the application's main window.
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 * Whether or not this ad is ready to be shown.
 */
- (BOOL)isReady;


@end

NS_ASSUME_NONNULL_END
