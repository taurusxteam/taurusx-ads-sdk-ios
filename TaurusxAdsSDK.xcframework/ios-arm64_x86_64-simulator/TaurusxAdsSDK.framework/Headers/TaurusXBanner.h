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
@required
- (void)adLoadFinish:(UIView *)bannerView;

@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adShowFailWithError:(NSError *)error;
- (void)adClicked;
- (void)adClosed;
@end


@interface TaurusXBanner : TaurusXBase

@property (nonatomic,weak) id <TaurusXBannerDelegate> delegate;
@property (nonatomic,assign) TAXBannerSize adSize;
@property (nonatomic,assign) BOOL isClosable;

- (BOOL)isReady;
- (void)loadWithPayload:(NSString *)payload;
- (void)loadBanner;

@end

NS_ASSUME_NONNULL_END
