<div align="center">
  <a href="https://www.taurusx.com/">
      <img src="https://www.taurusx.com/images/Default.svg" height="35">
  </a>
</div>

# TaurusX SDK for iOS

The TaurusX SDK is the latest generation mobile advertising featuring refined ad formats and streamlined APIs for access to mobile ad networks and advertising solutions. The SDK enables mobile app developers to maximize their monetization on Android and iOS.

## Requirements:

- Xcode 11.0 or later.
- iOS deployment target of iOS 12.0 or later.

## Including in your project

#### CocoaPods

To include TaurusxAdsSDK in a project using CocoaPods, you just add `TaurusxAdsSDK ` to your `Podfile`, for example:

```
platform :ios, '12.0'

target 'MyAmazingApp' do
  pod 'TaurusxAdsSDK'
  pod 'TaurusxAdsSDK/AppLovinAdapter'（Optional）
end
```

#### Swift Package Manager

To include TaurusxAdsSDK into a Swift Package Manager package, add it to the `dependencies` attribute defined in your `Package.swift` file. You can select the version using the `majorVersion` and `minor` parameters. For example:

```swift
    dependencies: [
        .Package(url: "https://github.com/taurusxteam/taurusx-ads-sdk-ios.git", majorVersion: <majorVersion>, minor: <minor>)
    ]
```

## More information for SDK
Refer to our [documentation](https://publisher.taurusx.com/knowledge/ios/taurusx.html) for step-by-step guides on integrating TaurusxAdsSDK and enabling mediated networks in your app.


## Feedback & Support
To file bugs, make feature requests, or suggest improvements for TaurusX SDK, please use [GitHub's issue tracker](https://github.com/taurusxteam/taurusx-ads-sdk-ios/issues).

