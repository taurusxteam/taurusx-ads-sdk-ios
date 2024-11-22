// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "TaurusxAdsSDK",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        // SDK core library, required
        .library(
            name: "TaurusxAdsSDK",
            targets: ["TaurusxAds"]
        ),
        // Adapter for AppLovinSDK
        .library(
            name: "TaurusxAppLovinAdapter",
            targets: ["ALAdapter"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "TaurusxAds",
            path: "./TaurusxAdsSDK.xcframework"
        ),
        .binaryTarget(
            name: "ALAdapter",
            path: "./Adapters/TaxAppLovinAdapter.xcframework"
        )
    ]
)
