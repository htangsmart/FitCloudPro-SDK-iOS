Pod::Spec.new do |s|
  s.name         = 'FitCloudRoutePlan'
  s.summary      = 'Route Plan module.'
  s.version      = '1.0.0-beta.3'
  s.description      = <<-DESC
  The FitCloud route plan module.
  DESC
  s.homepage         = "https://github.com/pcjbird/#{s.name}/tree/#{s.version}"
  s.license          = 'MIT'
  s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
  s.source           = {:git => "https://github.com/pcjbird/#{s.name}.git", :tag => s.version.to_s}
  s.social_media_url = 'http://www.lessney.com'
  s.platform     = :ios, '10.0'
  s.ios.deployment_target = '10.0'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  
  s.libraries        = 'c++', 'z'
  s.frameworks       = 'Foundation', 'UIKit'

  s.requires_arc = true
  s.vendored_frameworks = 'FitCloudRoutePlan.framework'
  s.resource = 'FitCloudRoutePlan.bundle'

  s.dependency 'AMapSearch'
  s.dependency 'AMapLocation'
  s.dependency 'AMapNavi'
  s.dependency 'BMKLocationKit'
  s.dependency 'BaiduNaviKit-All/Map'
  s.dependency 'BaiduNaviKit-All/WalkNavi'
  s.dependency 'BaiduNaviKit-All/Search'

end