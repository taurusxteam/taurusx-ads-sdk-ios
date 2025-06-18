//
//  TaxAppLovinAdapter.h
//  TaxAppLovinAdapter
//
//  Created by Don on 2024/10/9.
//

#import <AppLovinSDK/AppLovinSDK.h>

typedef NS_ENUM(NSInteger, TaurusXErrorCode) {
    ERROR_CODE_INVALID_REQUEST = 1,
    ERROR_CODE_NETWORK_ERROR = 2,
    ERROR_CODE_NO_FILL = 3,
    ERROR_CODE_TIMEOUT = 4,
    ERROR_CODE_SHOW = 5,
    ERROR_CODE_NO_CONTENT = 6,
    ERROR_CODE_INTERNAL_ERROR = 7,
    ERROR_CODE_PARSE_ERROR = 8,
    ERROR_CODE_DOWNLOAD_ERROR = 9,
};

@interface TaurusXALMediationAdapter : ALMediationAdapter <MAInterstitialAdapter, MARewardedAdapter, MAAdViewAdapter, MANativeAdAdapter>

@end
