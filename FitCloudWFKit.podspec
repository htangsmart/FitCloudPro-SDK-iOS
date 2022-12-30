Pod::Spec.new do |s|
    s.name             = "FitCloudWFKit"
    s.version          = "1.1.6"
    s.summary          = "FitCloudPro 智能手表表盘辅助框架， 旨在帮助您轻松自定义属于您自己的表盘文件，适用于Realteck芯片的手表。"
    s.description      = <<-DESC
    iOS framework help you creating customized watchface for fitcloudpro smart watch easily. 
    FitCloudPro 智能手表表盘辅助框架， 旨在帮助您轻松自定义属于您自己的表盘文件，适用于Realteck芯片的手表。
    DESC
    s.homepage         = "https://github.com/htangsmart/FitCloudPro-SDK-iOS/tree/wfkit_v#{s.version}/FitCloudWFKit"
    s.license          = 'MIT'
    s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
    s.source           = {:git => "https://github.com/htangsmart/FitCloudPro-SDK-iOS.git", :tag =>'wfkit_v' + s.version.to_s}
    s.social_media_url = 'http://www.hetangsmart.com'
    s.requires_arc     = true
    s.documentation_url = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudWFKit/README.md'
    s.screenshot       = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/raw/master/FitCloudWFKit/logo.png'

    s.platform         = :ios, '8.0'
    s.frameworks       = 'UIKit', 'Foundation', 'CoreGraphics', 'Accelerate'

    s.vendored_frameworks = 'FitCloudWFKit/FitCloudWFKit.framework'
    s.resource = 'FitCloudWFKit/FitCloudWFKit.bundle'

    s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }


end
