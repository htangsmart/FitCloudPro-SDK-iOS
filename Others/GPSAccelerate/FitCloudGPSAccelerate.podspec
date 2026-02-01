Pod::Spec.new do |s|
  s.name         = 'FitCloudGPSAccelerate'
  s.summary      = 'GPSAccelerate'
  s.version      = '1.0.1-beta.3'
  s.description      = <<-DESC
  The FitCloud GPS accelerate.
  DESC
  s.homepage         = "https://github.com/pcjbird/#{s.name}/tree/#{s.version}"
  s.license          = 'MIT'
  s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
  s.source           = {:git => "https://github.com/pcjbird/#{s.name}.git", :tag => s.version.to_s}
  s.social_media_url = 'http://www.lessney.com'
  s.platform     = :ios, '10.0'
  s.ios.deployment_target = '10.0'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  
  s.frameworks       = 'Foundation', 'UIKit'

  s.requires_arc = true
  s.vendored_frameworks = 'FitCloudGPSAccelerate.xcframework', 'FitCloudOTAGenKit.xcframework'

  s.dependency 'ReactiveObjC'
  s.dependency 'MJExtension'
  s.dependency 'LogMate'

end