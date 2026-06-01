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

typedef NS_ENUM(NSInteger, TAXNativeTemplate) {
    TEMPLATE_NONE,
    TEMPLATE_SMALL_360_120,
    TEMPLATE_MEDIUM_300_250
};


@interface TaurusXNativeData : NSObject

@property (nonatomic,strong) UIView  *mediaView;//support video and image
@property (nonatomic, copy) NSString *imageUrl DEPRECATED_MSG_ATTRIBUTE("use mediaView instead.");
@property (nonatomic,strong) UIImage *image DEPRECATED_MSG_ATTRIBUTE("use mediaView instead.");
@property (nonatomic, copy) NSString *iconUrl;
@property (nonatomic,strong) UIImage *icon;//icon image,it will be nil if download failed
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSString *cta;//call to action

@end


@protocol TaurusXNativeDelegate <NSObject>
- (void)adLoadFinish:(TaurusXNativeData *)nativeData adView:(nullable UIView *)nativeView;
@optional
- (void)adLoadFailWithError:(NSError *)error;
- (void)adImpression;
- (void)adClicked;
@end


@interface TaurusXNative : TaurusXBase


/// Set the templateType if you want to show native ad with built-in template.
/// Ad view will be returned by adLoadFinish.
/// Default no use template.
@property (nonatomic,assign) TAXNativeTemplate templateType;

/// A delegate that will be notified about ad events.
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
