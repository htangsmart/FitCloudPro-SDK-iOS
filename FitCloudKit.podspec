Pod::Spec.new do |s|
    s.name             = "FitCloudKit"
    s.version          = "1.3.0-beta.24"
    s.summary          = "和唐公司智能手表SDK。"
    s.description      = <<-DESC
    iOS framework for FitCloud smart watch, which is responsible for the communication with smart watch. FitCloud智能手表的iOS框架，负责与手表设备通信等功能的封装。
    DESC
    s.homepage         = "https://github.com/htangsmart/FitCloudPro-SDK-iOS/tree/#{s.version}/FitCloudKit"
    s.license          = 'MIT'
    s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
    s.source           = {:git => "https://github.com/htangsmart/FitCloudPro-SDK-iOS.git", :tag => s.version.to_s}
    s.social_media_url = 'http://www.hetangsmart.com'
    s.requires_arc     = true
    s.documentation_url = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/README.md'
    s.changelog = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/CHANGELOG.md'
    s.screenshot       = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/logo.png'

    s.platform         = :ios, '8.0'
    s.frameworks       = 'Foundation', 'CoreBluetooth', 'CoreGraphics'

    s.vendored_frameworks = 'FitCloudKit/FitCloudKit.xcframework'
    s.resource = 'FitCloudKit/FitCloudKit.bundle'

    s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }


end
