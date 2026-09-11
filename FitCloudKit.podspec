Pod::Spec.new do |s|
  s.name             = 'FitCloudKit'
  s.version          = '1.3.2-beta.108'
  s.summary          = '和唐公司智能手表SDK'
  s.description      = <<-DESC
                      FitCloudPro智能手表iOS开发框架，提供与手表设备通信等功能的封装。
                      The iOS framework for FitCloudPro smartwatch, encapsulating features like device communication.
                      DESC
  s.homepage         = "https://github.com/htangsmart/FitCloudPro-SDK-iOS/tree/#{s.version}/FitCloudKit"
  s.license          = 'MIT'
  s.author           = { 'pcjbird' => 'pcjbird@hotmail.com' }
  s.source           = { git: 'https://github.com/htangsmart/FitCloudPro-SDK-iOS.git', tag: s.version.to_s }
  s.social_media_url = 'http://www.hetangsmart.com'
  s.requires_arc     = true
  s.documentation_url = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/README.md'
  s.changelog        = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/CHANGELOG.md'
  s.screenshot       = 'https://github.com/htangsmart/FitCloudPro-SDK-iOS/blob/master/FitCloudKit/logo.png'

  s.platform         = :ios, '8.0'
  s.frameworks       = 'Foundation', 'CoreBluetooth', 'CoreGraphics'

  # Preserve the lightweight default integration; plugins are explicitly opt-in.
  s.default_subspecs = 'Core'

  s.subspec 'Core' do |core|
    core.vendored_frameworks = 'FitCloudKit/FitCloudKit.xcframework'
    core.resource = 'FitCloudKit/FitCloudKit.bundle'
  end

  s.subspec 'OfflineMaps' do |maps|
    maps.ios.deployment_target = '12.0'
    maps.dependency 'FitCloudKit/Core'
    maps.vendored_frameworks = 'FitCloudKit/FitCloudOfflineMaps.xcframework'
    # The static plugin is discovered at runtime, so its Objective-C classes must be linked.
    maps.user_target_xcconfig = { 'OTHER_LDFLAGS' => '$(inherited) -ObjC' }
  end

  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
end
