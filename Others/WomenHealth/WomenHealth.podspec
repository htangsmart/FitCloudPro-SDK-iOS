Pod::Spec.new do |s|
  s.name         = 'WomenHealth'
  s.summary      = 'WomenHealth module, M1 and above support xcode framworks.'
  s.version      = '1.0.0'
  s.description      = <<-DESC
  Private M1 and above support xcode framworks..
  DESC
  s.homepage         = "https://github.com/pcjbird/#{s.name}/tree/#{s.version}"
  s.license          = 'MIT'
  s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
  s.source           = {:git => "https://github.com/pcjbird/#{s.name}.git", :tag => s.version.to_s}
  s.social_media_url = 'http://www.lessney.com'
  s.platform     = :ios, '11.0'
  s.ios.deployment_target = '11.0'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  s.libraries        = 'c++', 'z'
  s.frameworks       = 'Foundation', 'UIKit', 'EventKit'

  s.requires_arc = true
  s.vendored_frameworks = 'WomenHealth.xcframework', 'WCDBSwift.xcframework', 'sqlcipher.xcframework'
  s.resource = 'WomenHealth.bundle'

  s.dependency 'FSCalendar'
  s.dependency 'zipzap'

end
