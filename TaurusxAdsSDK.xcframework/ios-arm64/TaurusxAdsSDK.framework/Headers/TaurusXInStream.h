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

@property (nonatomic,assign) BOOL isMute;
@property (nonatomic,readonly) NSTimeInterval duration;
@property (nonatomic,assign) BOOL useVideoStreaming;
@property (nonatomic,weak) id <TaurusXInStreamDelegate> delegate;

- (void)loadInStream;
- (void)loadWithPayload:(NSString *)payload;

- (void)showWithAdView:(UIView *)adView;
- (void)start;
- (void)pause;
- (void)resume;
- (void)destory;
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
