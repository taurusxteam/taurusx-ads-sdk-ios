//
//  TaurusXNative.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/9/6.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TaurusxAdsSDK/TaurusXBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface TaurusXNativeData : NSObject

@property (nonatomic, copy) NSString *imageUrl;//主图地址
@property (nonatomic, copy) NSString *title;//广告标题
@property (nonatomic, copy) NSString *body;//广告内容
@property (nonatomic, copy) NSString *cta;//行动号召/点击按钮文字
@property (nonatomic, copy) NSString *iconUrl;//图标地址

@end


@protocol TaurusXNativeDelegate <NSObject>
- (void)adLoadFinish:(TaurusXNativeData *)nativeData mediaView:(UIView *_Nullable)mediaView;
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adClicked;
@end


@interface TaurusXNative : TaurusXBase

@property (nonatomic,weak) id <TaurusXNativeDelegate> delegate;

/**
 * Load a new native ad by network request.
 */
- (void)loadNative;

/**
 * Load a new native ad by payload data.
 */
- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate;

/**
 * Show the native  ad into the given containerView  using default template .
 * @param containerView  The container for the native ad.
 * @param templateId :0-small(360x120),1-medium(300x250), default is small.
 */
- (void)showNativeInView:(UIView*)containerView withTemplate:(NSInteger)templateId;

/**
 * You can also show native ad in your custom view.
 * This is a method to  register the UIView you will use to display the native ads and set clickable areas.
 */
- (void)registerViewForInteractionWithContainer:(UIView *)containerView
                                      mediaView:(UIView*)mediaView
                                       iconView:(UIView*)iconView
                                 clickableViews:(NSArray<UIView *> *_Nullable)clickableViews;

/**
 * Whether or not this ad is ready to be shown.
 */
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
