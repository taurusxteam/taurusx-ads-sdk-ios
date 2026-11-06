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


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TAXBidLossReasonType) {
    LOSS_REASON_INTERNAL_ERROR = 1,
    LOSS_REASON_LOWER_THAN_FLOOR_PRICE = 101,
    LOSS_REASON_LOWER_THAN_HIGHEST_PRICE = 102
};

@interface TaurusXBase : NSObject

@property (nonatomic,strong) NSString *channel;//mediation identifier
@property (nonatomic,readonly,assign) CGFloat price;
@property (atomic,readonly,assign) BOOL isLoading;
@property (nonatomic,readwrite,copy)  NSString *placementId;
@property (nonatomic,readonly,strong) NSDate *startLoadTime;
@property (nonatomic,readonly,strong) NSDate *finishLoadTime;
@property (nonatomic,readonly,strong) SKStoreProductViewController *storeViewController;

/**
* If client bid wins, you should pass the highest price of second bidder to us before you show the ad.
* @param secPrice // second bidder's price
* @param secBidder // second bidder's name
*/
- (void)notifyWinWithSecPrice:(CGFloat)secPrice secBidder:(NSString *)secBidder;

/**
* If client bid losses, you should pass the price of first bidder to us before you show the ad.
* @param firstPrice // first bidder's price
* @param firstBidder // first bidder's name
* @param lossReason // loss reason
*/
- (void)notifyLossWithFirstPrice:(CGFloat)firstPrice firstBidder:(NSString *)firstBidder lossReason:(TAXBidLossReasonType)lossReason;
@end

NS_ASSUME_NONNULL_END
