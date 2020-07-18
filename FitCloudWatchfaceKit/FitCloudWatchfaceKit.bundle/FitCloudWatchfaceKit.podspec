Pod::Spec.new do |s|
    s.name             = "FitCloudWatchfaceKit"
    s.version          = "1.0.1"
    s.summary          = "FitCloud 智能手表自定义表盘创建框架， 旨在帮助您轻松创建属于您自己的表盘文件。"
    s.description      = <<-DESC
    iOS framework help you creating customized watchface for fitcloud smart watch easily. FitCloud 智能手表自定义表盘创建框架， 旨在帮助您轻松创建属于您自己的表盘文件。
    DESC
    s.homepage         = "https://github.com/htangsmart/FitCloudPro-SDK-iOS/tree/watchfacekit_v#{s.version}/FitCloudWatchfaceKit"
    s.license          = 'MIT'
    s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
    s.source           = {:git => "https://github.com/htangsmart/FitCloudPro-SDK-iOS.git", :tag => s.version.to_s}
    s.social_media_url = 'http://www.hetangsmart.com'
    s.requires_arc     = true
    s.documentation_url = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudWatchfaceKit/README.md'
    s.screenshot       = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/raw/master/FitCloudWatchfaceKit/logo.png'

    s.platform         = :ios, '8.0'
    s.frameworks       = 'UIKit', 'Foundation', 'CoreGraphics', 'Accelerate'

    s.source_files = 'FitCloudWatchfaceKit/*.{h,m}'
    s.public_header_files = 'FitCloudWatchfaceKit/FitCloudWatchfaceKit.h', 'FitCloudWatchfaceKit/FCWKErrorCode.h'
    s.resource_bundles = {
        'FitCloudWatchfaceKit' => ['FitCloudWatchfaceKitBundle/*.{lproj}'],
    }

    s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }


end
