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
@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adDismissed;
@end



@interface TaurusXInterstitial : TaurusXBase

/// Boolean value indicating if the audio is muted.Default is No.
@property (nonatomic,assign) BOOL isMute;

/// A delegate that will be notified about ad events.
@property (nonatomic,weak) id <TaurusXInterstitialDelegate> delegate;

/**
 * Load a new ad by network request.
 */
- (void)loadInterstitial;

/**
 * Load a new ad with payload data.
 */
- (void)loadWithPayload:(NSString *)payload;

/**
 * Presents the interstitial ad. Must be called on the main thread.
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
