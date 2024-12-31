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
- (void)adLoadFinish:(TaurusXNativeData *)nativeData adView:(nullable UIView *)nativeView;
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adClicked;
@end


@interface TaurusXNative : TaurusXBase
/**
* set the templateType if you want to show native ad with built-in template.
* ad view will be returned by adLoadFinish
* default-0,no use template ; 1-small template(360x120) ; 2-medium template(300x250)
*/
@property (nonatomic,assign) NSInteger templateType;

@property (nonatomic,weak) id <TaurusXNativeDelegate> delegate;

/**
 * Load a new native ad by network request.
 */
- (void)loadNative;

/**
 * Load a new native ad by payload data.
 */
- (void)loadWithPayload:(NSString *)payload;


/**
 * You can also show native ad in your custom view.
 * This is a method to  register the UIView you will use to display the native ads and set clickable areas.
 */
- (void)registerViewForInteractionWithContainer:(UIView *)containerView
                                      mediaView:(UIView *)mediaView
                                       iconView:(nullable UIView *)iconView
                                 clickableViews:(nullable NSArray<UIView *> *)clickableViews;

/**
 * Whether or not this ad is ready to be shown.
 */
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
