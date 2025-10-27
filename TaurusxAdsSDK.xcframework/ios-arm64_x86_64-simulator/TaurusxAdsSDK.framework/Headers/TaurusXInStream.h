//
//  TaurusXInStream.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/11/21.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TaurusxAdsSDK/TaurusXBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TaurusXInStreamDelegate;


@interface TaurusXInStream : TaurusXBase

/// Boolean value indicating if the audio is muted.Default is No.
@property (nonatomic,assign) BOOL isMute;

/// The duration of the ad.
@property (nonatomic,readonly) NSTimeInterval duration;

/// Use video streaming ,without needing to download the entire file before playback.
@property (nonatomic,assign) BOOL useVideoStreaming;

/// A delegate that will be notified about ad events.
@property (nonatomic,weak) id <TaurusXInStreamDelegate> delegate;


/**
 * Load a new ad by network request.
 */
- (void)loadInStream;

/**
 * Load a new ad with payload data.
 */
- (void)loadWithPayload:(NSString *)payload;

/**
 * Presents the instream ad. Must be called on the main thread.
 *
 * @param adView A view  to present the ad,can not be nil.
 */
- (void)showWithAdView:(UIView *)adView;

/**
 * Start the ad playback
 */
- (void)start;

/**
 * Pause and resume the ad playback
 */
- (void)pause;
- (void)resume;

/**
 * Remove ad from adView and destory it.Must be called on the main thread.
 */
- (void)destory;

/**
 * Whether or not this ad is ready to be shown.
 */
- (BOOL)isReady;
@end


@protocol TaurusXInStreamDelegate <NSObject>
- (void)adLoadFinish;
@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adSkiped;
- (void)adPause;
- (void)adResume;
- (void)adStart;
- (void)adComplete;
- (void)adImpression;
- (void)adInStreamCurrentTime:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration;
- (void)adInStreamStartBuffering;
- (void)adInStreamPlaybackReady;
- (void)adInStreamDidBufferToMediaTime:(NSTimeInterval)mediaTime;
@end

NS_ASSUME_NONNULL_END
