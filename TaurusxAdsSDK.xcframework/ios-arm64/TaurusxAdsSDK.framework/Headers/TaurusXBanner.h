//
//  TaurusXBanner.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/8/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TaurusxAdsSDK/TaurusXBase.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TAXBannerSize) {
    TAX_BANNER_320_50,
    TAX_MREC_300_250,
};


@protocol TaurusXBannerDelegate <NSObject>
- (void)adLoadFinish:(UIView *)bannerView;
@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adClosed;
@end


@interface TaurusXBanner : TaurusXBase

/// A delegate that will be notified about ad events.
@property (nonatomic,weak) id <TaurusXBannerDelegate> delegate;

/// Required to set this banner view to a proper size.
@property (nonatomic,assign) TAXBannerSize adSize;

/// A Boolean value that determines whether  the banner can be closed.
/// If enabled,a close button will be shown，and the 'adClosed' event will be notified when it is closed.
/// Default is No.
@property (nonatomic,assign) BOOL isClosable;

/**
 * Load a new ad by network request.
 */
- (void)loadBanner;

/**
 * Load a new ad with payload data.
 */
- (void)loadWithPayload:(NSString *)payload;

/**
 * Whether or not this ad is ready to be shown.
 */
- (BOOL)isReady;
@end

NS_ASSUME_NONNULL_END
