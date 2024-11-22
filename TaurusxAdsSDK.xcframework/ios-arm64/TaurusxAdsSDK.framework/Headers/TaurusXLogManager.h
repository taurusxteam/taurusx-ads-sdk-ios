//
//  TaurusXLogManager.h
//  TaurusxAdsSDK
//
//  Created by Don on 2024/10/20.
//  Copyright © 2024 TaurusX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The lower the filter level, the more logs will be shown.
 For example, `TAXLogLevelInfo` will display messages from
 `TAXLogLevelInfo,` `TAXLogLevelWarn,` and `TAXLogLevelError.`
 The default level is `TAXLogLevelWarn`
 */
typedef NS_ENUM(NSUInteger, TAXLogLevel) {
    TAXLogLevelAll        = 0,
    TAXLogLevelMark      = 9,
    TAXLogLevelTrace        = 10,
    TAXLogLevelDebug        = 20,
    TAXLogLevelInfo        = 30,
    TAXLogLevelWarn        = 40,
    TAXLogLevelError        = 50,
    TAXLogLevelOff        = 60
};

/**
 Use the `TaurusXLogManager` methods to set the desired level of log filter.
 */
@interface TaurusXLogManager : NSObject

/**
 Gets the current log filter level.
 */
+ (TAXLogLevel)getLogLevel;

/**
 Sets the log filter level.
 */
+ (void)setLogLevel:(TAXLogLevel)level;

/**
 Enable  to subscribe for Notifications
 */
+ (void)setNotificationsEnabled:(BOOL )enabled;

/**
  Get Notification Status
 */
+ (BOOL)isNotificationsEnabled;


@end

NS_ASSUME_NONNULL_END
