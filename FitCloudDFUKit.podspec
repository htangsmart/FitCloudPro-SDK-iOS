Pod::Spec.new do |s|
    s.name             = "FitCloudDFUKit"
    s.version          = "1.3.1-beta.9"
    s.summary          = "和唐公司智能手表固件升级SDK。"
    s.description      = <<-DESC
    iOS framework for FitCloud Smart Bracelet Device Firmware Upgrade, which is responsible for the upgrade of bracelet firmware. FitCloud智能手表固件升级的iOS框架，负责手表固件升级等功能的封装。
    DESC
    s.homepage         = "https://github.com/htangsmart/FitCloudPro-SDK-iOS/tree/dfukit_v#{s.version}/FitCloudDFUKit"
    s.license          = 'MIT'
    s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
    s.source           = {:git => "https://github.com/htangsmart/FitCloudPro-SDK-iOS.git", :tag => 'dfukit_v' + s.version.to_s}
    s.social_media_url = 'http://www.hetangsmart.com'
    s.requires_arc     = true
    s.documentation_url = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudDFUKit/README.md'
    s.screenshot       = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/raw/master/FitCloudDFUKit/logo.png'

    s.platform         = :ios, '9.0'
    s.frameworks       = 'Foundation', 'CoreBluetooth', 'CoreGraphics'

    s.vendored_frameworks = 'FitCloudDFUKit/FitCloudDFUKit.framework'
    s.resource = 'FitCloudDFUKit/FitCloudDFUKit.bundle'

    s.dependency 'iOSDFULibrary', '~> 4.11.0'

    s.swift_version = '5.0'

    s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }


end
