//
//  TaurusXBase.h
//  fluteSDKSample
//
//  Created by Don on 2024/8/23.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>
#import <TaurusxAdsSDK/TaurusXAdError.h>


NS_ASSUME_NONNULL_BEGIN

@interface TaurusXBase : NSObject

@property (nonatomic,assign)BOOL isLoading;
@property (nonatomic,copy)NSString *placementId;
@property (nonatomic,strong)NSDate *startLoadTime;
@property (nonatomic,strong)NSDate *finishLoadTime;
@property (nonatomic,strong)SKStoreProductViewController *_Nullable storeViewController;
@property (nonatomic,assign) BOOL hasReportClickEvent;
@property (nonatomic,strong) NSDictionary *clickInfo;

- (id)decryptPayload:(NSString *)payload;
- (void)startLoadEvent;
- (void)loadAdDataEvent:(nullable NSError *)error;
- (void)startLoadResource;
- (void)finishLoadResource:(nullable NSError *)error;
- (void)loadSuccessEvent;
- (void)loadFailEvent:(NSError *)error;
- (void)startLoadVideoEvent;
- (void)finishLoadVideoEvent:(nullable NSError *)error;
- (void)startLoadImageEvent;
- (void)finishLoadImageEvent:(nullable NSError *)error;
- (void)clickEvent:(NSInteger)from videoTime:(NSTimeInterval)videoTime;
- (void)adReadyEvent:(NSString *)code;
- (void)startShowEvent;
- (void)finishShowEvent:(nullable NSError *)error;
- (void)impressionEvent;
- (void)holdUpClickEvent:(BOOL)holdUp;
- (void)autoJumpEvent;
- (void)closeEvent;
- (void)handleTap:(UITapGestureRecognizer *)sender;
- (void)skipEvent:(NSInteger)from;
- (void)abnormalCloseEvent;
- (void)adoOpenEvent;
- (void)adoCloseEvent;
- (void)biddingTokenFetchedEvent:(nullable NSError *)error;

- (void)checkRelease;
- (void)trackSKAdNetworkStartImpression;
- (void)trackSKAdNetworkEndImpression;
- (BOOL)showStoreProduct:(NSDictionary*)param viewController:(nullable UIViewController *)viewController;
- (BOOL)internalOpenUrl:(NSURL *)url deeplink:(nullable NSString*)deeplink fallback:(nullable NSString*)fallback rootVC:(UIViewController*)rootVC finish:(void (^ __nullable)(void))finish;
- (BOOL)externalOpenUrl:(NSURL *)url deeplink:(nullable NSString*)deeplink fallback:(nullable NSString*)fallback;



@end

NS_ASSUME_NONNULL_END
