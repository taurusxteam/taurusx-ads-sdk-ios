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

@property (nonatomic, readonly) TaurusXAdsInitStatus initStatus;

+ (TaurusXAds *)sharedInstance;

+ (NSString*)sdkVersion;

- (void)startWithAppId:(NSString *)appId completionHandler:(void (^ __nullable)(BOOL success))completion;
//0 设备数据允许上报 ；1 设备数据不允许上报；
- (void)setGDPRDataCollection:(NSInteger)level;
//0 接受上报数据；1 加州用户不上报数据；
- (void)setCCPADoNotSell:(NSInteger)level;
// 0 表明不是儿童；1 表明是儿童
- (void)setCOPPAIsAgeRestrictedUser:(NSInteger)level;
//0 设备数据允许上报 ；1 设备数据不允许上报；
- (void)setLGPDConsent:(NSInteger)level;

- (void)setChannel:(NSString*)channel;

- (void)setAppIcon:(NSString*)iconName;

- (void)setDebugLogEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
