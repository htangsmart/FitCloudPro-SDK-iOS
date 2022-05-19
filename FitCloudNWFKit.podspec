Pod::Spec.new do |s|
    s.name             = "FitCloudNWFKit"
    s.version          = "1.0.1"
    s.summary          = "FitCloudPro 智能手表表盘辅助框架， 旨在帮助您轻松自定义属于您自己的表盘文件，适用于Nordic芯片的手表。"
    s.description      = <<-DESC
    iOS framework help you creating customized watchface for fitcloudpro smart watch easily. 
    FitCloudPro 智能手表表盘辅助框架， 旨在帮助您轻松自定义属于您自己的表盘文件，适用于Nordic芯片的手表。
    DESC
    s.homepage         = "https://github.com/htangsmart/FitCloudPro-SDK-iOS/tree/nwfkit_v#{s.version}/FitCloudNWFKit"
    s.license          = 'MIT'
    s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
    s.source           = {:git => "https://github.com/htangsmart/FitCloudPro-SDK-iOS.git", :tag =>'nwfkit_v' + s.version.to_s}
    s.social_media_url = 'http://www.hetangsmart.com'
    s.requires_arc     = true
    s.documentation_url = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudNWFKit/README.md'
    s.screenshot       = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/raw/master/FitCloudNWFKit/logo.png'

    s.platform         = :ios, '9.0'
    s.frameworks       = 'Foundation'

    s.vendored_frameworks = 'FitCloudNWFKit/FitCloudNWFKit.framework'
    s.resource = 'FitCloudNWFKit/FitCloudNWFKit.bundle'

    s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

    s.dependency 'zipzap', '~> 8.1.1'


end