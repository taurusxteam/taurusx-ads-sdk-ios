Pod::Spec.new do |spec|

  spec.author       = "TaurusX"
  spec.name         = "TaurusxAdsSDK"
  spec.version      = "1.9.2"
  spec.summary      = "TaurusX SDK for iOS"
  spec.platform     = :ios, "12.0"
  spec.homepage     = "https://www.taurusx.com/"
  spec.license = 
  { 
  :type => 'Commercial License',
  :text => <<-LICENSE
  Copyright © 2024 TaurusX. All Rights Reserved.
  The TaurusX SDK is available under a commercial license.
  LICENSE
  }

  spec.source = { :git => "https://github.com/taurusxteam/taurusx-ads-sdk-ios.git", :tag => "#{spec.version}" }
  spec.frameworks = "AVFoundation", "StoreKit","WebKit"
  spec.libraries = "sqlite3", "z"
  spec.swift_versions = '5.0'
  valid_archs = ['x86_64','arm64']
 

  spec.description  = <<-DESC
  The TaurusX Ads SDK is the latest generation mobile advertising featuring refined ad formats and streamlined APIs for access to mobile ad networks and advertising solutions. The SDK enables mobile app developers to maximize their monetization on Android and iOS. 
                   DESC
                   
  spec.default_subspecs = 'TaurusxAds'
  
  spec.subspec 'TaurusxAds' do |ss|
     ss.ios.deployment_target = '12.0'
     ss.vendored_frameworks = "TaurusxAdsSDK.xcframework"
     ss.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  end
  
  spec.subspec 'AppLovinAdapter' do |ss|
     ss.ios.deployment_target = '12.0'
     ss.vendored_frameworks = 'Adapters/TaxAppLovinAdapter.xcframework'
     ss.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
     ss.dependency 'TaurusxAdsSDK/TaurusxAds'
     ss.dependency 'AppLovinSDK', '>= 11.5.4'
  end

  spec.subspec 'IronSourceAdapter' do |ss|
     ss.ios.deployment_target = '12.0'
     ss.vendored_frameworks = 'Adapters/TaxIronSourceAdapter.xcframework'
     ss.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
     ss.dependency 'TaurusxAdsSDK/TaurusxAds'
     ss.dependency 'IronSourceSDK'
  end

  spec.subspec 'GoogleAdMobAdapter' do |ss|
     ss.ios.deployment_target = '12.0'
     ss.vendored_frameworks = 'Adapters/TaxGoogleAdmobAdapter.xcframework'
     ss.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
     ss.dependency 'TaurusxAdsSDK/TaurusxAds'
     ss.dependency 'Google-Mobile-Ads-SDK'
  end
end
