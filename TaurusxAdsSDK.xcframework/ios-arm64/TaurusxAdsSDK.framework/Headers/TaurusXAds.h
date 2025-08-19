//
//  TaurusXAds.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/8/27.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TaurusXAdsInitStatus)
{
    TaurusXAdsInitStatusFailed = -1,
    TaurusXAdsInitStatusNotInit = 0,
    TaurusXAdsInitStatusIniting = 1,
    TaurusXAdsInitStatusSuccess = 2
};


@interface TaurusXAds : NSObject

/// Initialization status of the  TaurusX Ads SDK.
@property (nonatomic, readonly) TaurusXAdsInitStatus initStatus;

/*
 Returns the shared TaurusXAds instance.
 */
+ (TaurusXAds *)sharedInstance;

/*
 Returns the TaurusX Ads SDK's version number.
 */
+ (NSString*)sdkVersion;

/*
 Starts the TaurusX Ads SDK. Call this method as early as possible to reduce latency on the
 session's first ad request. Calls completionHandler when the TaurusX SDK are fully set up.
 */
- (void)startWithAppId:(NSString *)appId completionHandler:(void (^ __nullable)(BOOL success))completion;

/*
 Set the General Data Protection Regulation (GDPR) value;
 Must be called before start TaurusX SDK;
 0 The device data is allowed to be reported;
 1 The device data is not allowed to be reported
 */
- (void)setGDPRDataCollection:(NSInteger)level;

/*
 Set the California Consumer Privacy Act (CCPA) value;
 Must be called before start TaurusX SDK;
 0 California users accept reported data;
 1 do not report data
 */
- (void)setCCPADoNotSell:(NSInteger)level;

/*
 Set the Children's Online Privacy Protection Act value;
 Must be called before start TaurusX SDK;
 0 is not a child;
 1 is a child
 */
- (void)setCOPPAIsAgeRestrictedUser:(NSInteger)level;

/*
 Set the Lei Geral de Proteção de Dados (LGPD) value;
 Must be called before start TaurusX SDK;
 0 The device data is allowed to be reported;
 1 The device data is not allowed to be reported
 */
- (void)setLGPDConsent:(NSInteger)level;

/*
 Set mediation identifier by mediation adapter
 */
- (void)setChannel:(NSString*)channel;

/*
 Set the host app icon,it will be displayed in Splash Ad.
 */
- (void)setAppIcon:(NSString*)iconName;

/*
 * A toggle for debug logging for the SDK.
 * This is set to NO by default. Set it to NO if you want the SDK to be silent (this is recommended for App Store submissions).
 * If set to YES TaurusX messages will appear in the standard application log which is accessible via the console. All TaurusX log messages are prefixed
 * with the [TaurusX] tag.
 */
- (void)setDebugLogEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
