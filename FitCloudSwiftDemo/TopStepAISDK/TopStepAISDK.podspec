Pod::Spec.new do |s|
  s.name         = 'TopStepAISDK'
  s.summary      = 'A comprehensive AI SDK for iOS applications'
  s.version      = '1.0.0-beta.3'
  s.description      = <<-DESC
  TopStepAISDK is an AI-powered SDK that offers a range of advanced features, including Automatic Speech Recognition (ASR), Text-to-Speech (TTS), AI-generated imagery (AIGC), AI-driven question answering (GPT), and AI translation services.
  DESC
  s.homepage         = "https://github.com/pcjbird/#{s.name}/tree/#{s.version}"
  s.license          = 'MIT'
  s.author           = {"pcjbird" => "pcjbird@hotmail.com"}
  s.source           = {:git => "https://github.com/pcjbird/#{s.name}.git", :tag => s.version.to_s}
  s.social_media_url = 'http://www.lessney.com'
  s.platform     = :ios, '10.0'
  s.ios.deployment_target = '10.0'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  
  s.frameworks       = 'Foundation', 'UIKit', 'Network'

  s.requires_arc = true
  s.default_subspec = 'Core'

  s.subspec 'Core' do |ss|
    ss.vendored_frameworks = 'TopStepAISDK.xcframework', 'LogMate.xcframework', 'MicrosoftCognitiveServicesSpeech.xcframework', 'LAME.xcframework', 'MagicHelper.framework'

    ss.dependency 'AFNetworking'
    ss.dependency 'SocketRocket'
  end


end