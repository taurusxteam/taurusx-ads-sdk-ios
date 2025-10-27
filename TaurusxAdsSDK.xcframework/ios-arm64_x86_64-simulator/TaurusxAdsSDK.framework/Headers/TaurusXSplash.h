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
@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adDismissed;
@end


@interface TaurusXSplash : TaurusXBase

/// Boolean value indicating if the audio is muted.Default is YES.
@property (nonatomic,assign) BOOL isMute;

/// A delegate that will be notified about ad events.
@property (nonatomic,weak) id <TaurusXSplashDelegate> delegate;


/**
 * Load a new ad by network request.
 */
- (void)loadSplash;

/**
 * Load a new ad with payload data.
 */
- (void)loadWithPayload:(NSString *)payload;

/**
 * Presents the splash ad. Must be called on the main thread.
 * Ad will be presented from the top view controller of the application's main window.
 */
- (void)showAd;

/**
 * Whether or not this ad is ready to be shown.
 */
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
