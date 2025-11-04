//
//  FitCloudProSDK.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2/19/25.
//

import Foundation
import FitCloudKit
import TopStepAISDK
import LogMate
import FitCloudWFKit

class FitCloudProSDK: NSObject {
    
    private var asrTaskId: String? = nil
    private var aigcTaskId: String? = nil

    private var toConfirmedAIPhoto: UIImage? = nil

    private var aiPhotoPreviewWidth: Int = 0
    private var aiPhotoPreviewHeight: Int = 0
    
    private var appendVoiceDataBlock: ((_ voiceData: Data) -> Void)? = nil
    
    static let shared = FitCloudProSDK()

    private override init() {

    }

    func start() {
        initFitCloudProSDKs()
    }

    /// Initializes the FitCloudPro SDKs with required configurations
    private func initFitCloudProSDKs() {
        let option = FitCloudOption()
        option.debugMode = false
        option.shouldAutoReconnectWhenAppLaunch = true
        FitCloudKit.initWith(option, callback: self)
        initTopStepAISDK()
        addNotificationObservers()
    }
    
    private func initTopStepAISDK() {
        TopStepAI.setLogProvider(self)
    }
    
    private func addNotificationObservers() {
        // 监听设备准备同步工作完成的通知
        NotificationCenter.default.addObserver(self,
            selector: #selector(onDeviceReady(_:)),
            name: NSNotification.Name(rawValue: FITCLOUDEVENT_PREPARESYNCWORK_END_NOTIFY),
            object: nil)
    }
    
    @objc private func onDeviceReady(_ notification: NSNotification) {
        XLOG_INFO("Watch device is ready")
        let config = FitCloudKit.allConfig()
        let withLLM = config?.firmware?.withLLM
        guard let withLLM = withLLM, withLLM else {
            XLOG_ERROR("Current watch does not support ai watch face")
            return
        }
        guard let macAddr = FitCloudKit.macAddr() else {
            XLOG_ERROR("Failed to get device MAC address")
            return
        }
        XLOG_INFO("Start to register the watch device MAC address with TopStepAI service")
        // Register the watch device MAC address with TopStepAI service
        TopStepAI.setWatchDeviceMacAddr(macAddr) { success, error in
            if success {
                XLOG_INFO("Successfully registered device MAC address: \(macAddr)")
            } else {
                if let error = error {
                    XLOG_ERROR("Failed to register device MAC address: \(error)")
                } else {
                    XLOG_ERROR("Failed to register device MAC address: unknown error")
                }
            }
        }
    }

}

extension FitCloudProSDK: LoggableProtocol {
    func onLogMateMessage(_ message: String!, level: LOGMATELEVEL, subsystem: String!, category: String!) {
        XLOG_INFO("\(String(describing: message))")
    }
}

extension  FitCloudProSDK: FitCloudCallback {
    
    /// Called when the watch device requests to find the iPhone device
    /// This function will be triggered when user activates the find phone feature on the watch
    func onFindiPhoneEvent() {
        XLOG_INFO("The watch device requests to find the iPhone device...")
    }
    
    /// Called when the watch device sends a photo control command
    /// This function will be triggered when user wants to take a photo using the watch
    func onTakePhotoCtrl() {
        XLOG_INFO("Received photo control command from watch device")
    }
    
    
    /// Called when receiving real-time health measurement data from the watch
    /// - Parameter records: Array of health measurement result objects containing various health metrics
    func onRealTimeHealthMeasuringData(_ records: [FitCloudRealTimeHealthMeasuringResultObject]) {
        XLOG_INFO("Received real-time health measurement data: \(String(describing: records))")
    }
    
    /// Called when receiving real-time ECG data from the watch
    /// - Parameters:
    ///   - ecgDataArray: Array of ECG data points
    ///   - interval: Time interval between data points in milliseconds
    func onRealTimeECGData(_ ecgDataArray: [NSNumber], interval: Int) {
        XLOG_INFO("Received real-time ECG data with \(ecgDataArray.count) points, interval: \(interval)ms")
    }
     
    
    /// Called when the real-time ECG measurement stops
    /// This function will be triggered when the ECG measurement is completed or interrupted
    func onRealTimeECGStop() {
        XLOG_INFO("Real-time ECG measurement stopped")
    }
    
    /// Called periodically to indicate that the bracelet is still connected and active
    /// This is a heartbeat function to maintain connection status
    func onBraceletAlive() {
        XLOG_INFO("Bracelet heartbeat received - device is alive")
    }
    
    func getIslamicEvents() -> [FitCloudIslamicEventModel] {
        // Here you can implement your holiday logic, return an array containing IslamicHoliday objects
        // The code below is just an example
        let holiday1 = FitCloudIslamicEventModel()
        let islamicDate1 = FitCloudIslamicDateModel()
        islamicDate1.islamicYear = 1446
        islamicDate1.islamicMonth = 1
        islamicDate1.islamicDay = 1
        holiday1.islamicDate = islamicDate1
        holiday1.durationOfEventInDays = 3
        holiday1.correspondingGregorianDate = Date()

        let holiday2 = FitCloudIslamicEventModel()
        let islamicDate2 = FitCloudIslamicDateModel()
        islamicDate2.islamicYear = 1446
        islamicDate2.islamicMonth = 2
        islamicDate2.islamicDay = 10
        holiday2.islamicDate = islamicDate2
        holiday2.durationOfEventInDays = 5
        holiday2.correspondingGregorianDate = Date().addingTimeInterval(30 * 24 * 60 * 60)

        let holiday3 = FitCloudIslamicEventModel()
        let islamicDate3 = FitCloudIslamicDateModel()
        islamicDate3.islamicYear = 1446
        islamicDate3.islamicMonth = 4
        islamicDate3.islamicDay = 12
        holiday3.islamicDate = islamicDate3
        holiday3.durationOfEventInDays = 8
        holiday3.correspondingGregorianDate = Date().addingTimeInterval(3 * 30 * 24 * 60 * 60)

        let holiday4 = FitCloudIslamicEventModel()
        let islamicDate4 = FitCloudIslamicDateModel()
        islamicDate4.islamicYear = 1446
        islamicDate4.islamicMonth = 5
        islamicDate4.islamicDay = 15
        holiday4.islamicDate = islamicDate4
        holiday4.durationOfEventInDays = 2
        holiday4.correspondingGregorianDate = Date().addingTimeInterval(4 * 30 * 24 * 60 * 60)

        let holiday5 = FitCloudIslamicEventModel()
        let islamicDate5 = FitCloudIslamicDateModel()
        islamicDate5.islamicYear = 1446
        islamicDate5.islamicMonth = 7
        islamicDate5.islamicDay = 18
        holiday5.islamicDate = islamicDate5
        holiday5.durationOfEventInDays = 6
        holiday5.correspondingGregorianDate = Date().addingTimeInterval(5 * 30 * 24 * 60 * 60)

        let holiday6 = FitCloudIslamicEventModel()
        let islamicDate6 = FitCloudIslamicDateModel()
        islamicDate6.islamicYear = 1446
        islamicDate6.islamicMonth = 9
        islamicDate6.islamicDay = 18
        holiday6.islamicDate = islamicDate6
        holiday6.durationOfEventInDays = 9
        holiday6.correspondingGregorianDate = Date().addingTimeInterval(8 * 30 * 24 * 60 * 60)

        return [holiday1, holiday2, holiday3, holiday4, holiday5, holiday6]
    }
    
    /// Called when the watch requests Islamic holiday information
    /// This function handles the request from watch for Islamic calendar events
    /// and sets the events using FitCloudKit
    func onRequestCurrentIslamicEvents() {
        XLOG_INFO("Watch requesting Islamic holiday information...") // Watch requests Islamic holiday information
        
        XLOG_INFO("Setting Islamic holiday information: \(getIslamicEvents().debugDescription)") // Setting Islamic holiday information
        FitCloudKit.setCurrentIslamicEvents(getIslamicEvents()) { succeed, error in
            
        }
    }
    
    /// Called when the watch requests Kaaba data
    /// This function handles the request from watch for Kaaba direction information
    /// and sets the Kaaba data using FitCloudKit
    func onRequestKaabaData() {
        XLOG_INFO("Watch requesting Kaaba data...")
        
        XLOG_INFO("Setting Kaaba information: \(MuslimPrayerParams.instance().kaaba.debugDescription)")
        FitCloudKit.setKaabaData(MuslimPrayerParams.instance().kaaba) { succeed, error in
            
        }
    }
    
    /// Notifies that ASR (Automatic Speech Recognition) voice recording has started
    /// - Note: Called when the watch begins recording voice for ASR
    func onASRVoiceBegin() {
        // 在后台线程中创建语音识别任务
        DispatchQueue.global(qos: .userInitiated).async { [weak self] in
            self?.asrTaskId = TopStepASRService.shared().createVoiceRecognizeTask(languageForSpeechInput: nil, voiceDataAppendHandler: {[weak self] appendVoiceDataBlock in
                self?.appendVoiceDataBlock = appendVoiceDataBlock
            }, pcmBufferAppendHandler: nil, onResult: {[weak self] taskId, isFinal, text, error in
                self?.processASRResult(taskId, isFinal, text, error)
            })
        }
    }

    /// Processes the result from Automatic Speech Recognition (ASR)
    /// - Parameters:
    ///   - taskId: The unique identifier of the ASR task
    ///   - isFinal: A boolean indicating whether this is the final result
    ///   - text: The recognized text from the speech input
    ///   - error: An optional error that occurred during recognition
    /// - Note: This method handles the ASR result and sends it to the connected device
    /// - Important: When isFinal is true, it cleans up the ASR-related resources
    func processASRResult(_ taskId: String?, _ isFinal: Bool, _ text: String?, _ error: (any Error)?) {
        defer {
            if isFinal {
                self.asrTaskId = nil
                self.appendVoiceDataBlock = nil
            }
        }
        if let error = error {
            XLOG_ERROR("An error occurred during Automatic Speech Recognition (ASR): \(error)")
            return
        }
        guard let asrTaskId = self.asrTaskId, let taskId = taskId, asrTaskId == taskId, isFinal else {
            return
        }
        
        let trimmedText = text?.trimmingCharacters(in: .whitespacesAndNewlines)
        let asrResultText = trimmedText?.isEmpty ?? true
            ? "voice is empty"
            : trimmedText!
        
        
        XLOG_INFO("ASR result: \(asrResultText), sending to device...")
        FitCloudKit.sendASRResult(asrResultText) { success, error in
            if !success {
                // 发送 ASR 结果到设备失败
                if let error = error {
                    XLOG_ERROR("Failed to send ASR result to device: \(error)")
                } else {
                    XLOG_ERROR("Failed to send ASR result to device: unknown error")
                }
                return
            }
            XLOG_INFO("ASR result sent to device successfully")
        }
    }

    /// Notifies that incremental ASR voice data has been received
    /// - Parameters:
    ///   - deltaOpusVoiceData: The incremental voice data in Opus format
    ///   - deltaVoiceData: The decoded incremental voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
    func onASRDeltaOpusVoiceData(_ deltaOpusVoiceData: Data?, decodedDeltaVoiceData deltaVoiceData: Data?) {
        guard let _ = self.asrTaskId, let appendVoiceDataBlock = self.appendVoiceDataBlock, let deltaVoiceData = deltaVoiceData else {
            return
        }
        appendVoiceDataBlock(deltaVoiceData)
    }

    /// Notifies that ASR voice recording has completed with decoded voice data
    /// - Parameters:
    ///   - opusVoiceData: The opus encoded voice data
    ///   - voiceData: The decoded voice data in PCM format (16000Hz sample rate, mono channel, 16-bit)
    func onASRVoiceStop(withOpusVoiceData opusVoiceData: Data?, decodedVoiceData voiceData: Data?) {
        TopStepASRService.shared().finish()
    }

    /// Notifies that watch requests to generate an AI watch face based on the given prompt and preview dimensions
    /// - Parameters:
    ///   - prompt: The text prompt describing the desired watchface design
    ///   - width: The preview image width in pixels
    ///   - height: The preview image height in pixels
    func onRequestGenerateAIWatchFace(withPrompt prompt: String?, previewWidth width: Int, previewHeight height: Int) {
        guard let prompt = prompt, !prompt.isEmpty else {
            XLOG_ERROR("Invalid prompt")
            XLOG_INFO("Send aigc generate result to device...")
            FitCloudKit.sendAIPhotoGenerationResult(.UNKNOWN_ERROR, completion: nil)
            return
        }
        guard width > 0, height > 0 else {
            XLOG_ERROR("Invalid preview dimensions")
            XLOG_INFO("Send aigc generate result to device...")
            FitCloudKit.sendAIPhotoGenerationResult(.UNKNOWN_ERROR, completion: nil)
            return
        }
        self.aiPhotoPreviewWidth = width
        self.aiPhotoPreviewHeight = height
        XLOG_INFO("Generating AI watch face with prompt: \(prompt)")
       
        if let _ = TopStepAigcService.shared().aigcStyles {
             self.generateAIPhotos(prompt: prompt)
        }
        else {
            XLOG_INFO("Fetching AI styles...")
            DispatchQueue.global(qos: .userInitiated).async { [weak self] in
                TopStepAigcService.shared().fetchAigcStyles {[weak self] success, styles, error in
                    if !success {
                        if let error = error {
                            XLOG_ERROR("Failed to fetch AIGC styles: \(error)")
                        } else {
                            XLOG_ERROR("Failed to fetch AIGC styles: unknown error")
                        }
                        XLOG_INFO("Send aigc generate result to device...")
                        FitCloudKit.sendAIPhotoGenerationResult(.UNKNOWN_ERROR, completion: nil)
                        return
                    }
                    self?.generateAIPhotos(prompt: prompt)
                }
            }
        }
        
    }
    
    func generateAIPhotos(prompt: String) {

        guard let aigcStyles = TopStepAigcService.shared().aigcStyles, let style = aigcStyles.first?.styleCode else {
            XLOG_ERROR("Unable to generate image: failed to fetch AIGC styles")
            XLOG_INFO("Send aigc generate result to device...")
            FitCloudKit.sendAIPhotoGenerationResult(.UNKNOWN_ERROR, completion: nil)
            return
        }

        DispatchQueue.global(qos: .userInitiated).async { [weak self] in
            self?.aigcTaskId = TopStepAigcService.shared().generate(prompt: prompt, style: style, imageCount: 1, completion: {[weak self] taskId, success, images, error in
                self?.processAigcResult(taskId, success, images, error)
            })
        }
    }
    
    func processAigcResult(_ taskId: String?, _ success: Bool, _ images: [UIImage]?, _ error: (any Error)?) {
        defer {
            self.aigcTaskId = nil
        }
        if let error = error {
            XLOG_ERROR("An error occurred during AI image generation: \(error)")
            XLOG_INFO("Send aigc generate result to device...")
            FitCloudKit.sendAIPhotoGenerationResult(.NETWORK_ERROR, completion: nil)
            return
        }
        guard let aigcTaskId = self.aigcTaskId, let taskId = taskId, aigcTaskId == taskId, let image = images?.first else {
            XLOG_INFO("Send aigc generate result to device...")
            FitCloudKit.sendAIPhotoGenerationResult(.UNKNOWN_ERROR, completion: nil)
            return
        }
        self.toConfirmedAIPhoto = image
        XLOG_INFO("Aigc result: \(image)")
        guard self.aiPhotoPreviewWidth > 0, self.aiPhotoPreviewHeight > 0 else {
            XLOG_ERROR("Invalid preview dimensions")
            return
        }
        XLOG_INFO("Send aigc generate result to device...")
        FitCloudKit.sendAIPhotoGenerationResult(.SUCCESS, completion: nil)
        let preview = self.generatePreview(image: image, width: self.aiPhotoPreviewWidth, height: self.aiPhotoPreviewHeight)
        
        XLOG_INFO("Send AI-generated preview to device...")
        DispatchQueue.global(qos: .userInitiated).async {
            FitCloudKit.sendAIGeneratedPhoto(preview) { progress in
                XLOG_INFO("Sending AI watch face preview to device, progress: \(progress)")
            } completion: { success, avgSpeed, error in
                if !success {
                    // Failed to send AI-generated preview to device
                    if let error = error {
                        XLOG_ERROR("Failed to send AI watch face preview to device: \(error)")
                    } else {
                        XLOG_ERROR("Failed to send AI watch face preview to device: unknown error")
                    }
                }
            }
        }
    }

    func generatePreview(image: UIImage, width: Int, height: Int) -> UIImage {
        // Create preview size
        let previewSize = CGSize(width: width, height: height)
        
        // Create graphics context
        UIGraphicsBeginImageContextWithOptions(previewSize, false, 0.0)
        
        // Get context
        guard let _ = UIGraphicsGetCurrentContext() else {
            return image
        }
        
        // Calculate AspectFill scale ratio and offset
        let imageSize = image.size
        let widthRatio = previewSize.width / imageSize.width
        let heightRatio = previewSize.height / imageSize.height
        let scale = max(widthRatio, heightRatio)
        
        let scaledWidth = imageSize.width * scale
        let scaledHeight = imageSize.height * scale
        let offsetX = (previewSize.width - scaledWidth) * 0.5
        let offsetY = (previewSize.height - scaledHeight) * 0.5
        
        // Draw image
        let drawRect = CGRect(x: offsetX, y: offsetY, width: scaledWidth, height: scaledHeight)
        image.draw(in: drawRect)
        
        // Get result image
        guard let previewImage = UIGraphicsGetImageFromCurrentImageContext() else {
            UIGraphicsEndImageContext()
            return image
        }
        
        UIGraphicsEndImageContext()
        return previewImage
    }

    /// Notifies whether the watch confirms to use this AI-generated watch face photo
    /// - Parameters:
    ///   - confirmed: A Boolean value that indicates if the watch confirms to use this AI-generated watch face photo
    func didConfirmAIWatchFacePhoto(_ confirmed: Bool) {
        if !confirmed {
            XLOG_INFO("User declined to use AI-generated watch face photo")
            self.toConfirmedAIPhoto = nil
            return
        }
        guard let image = self.toConfirmedAIPhoto else {
            XLOG_ERROR("Invalid AI-generated watch face photo")
            return
        }

        #warning("Replace the placeholder with the custom watchface template file for your project")
        guard let templatePath = Bundle.main.path(forResource: "ai_watchface_template", ofType: "bin") else {
            XLOG_ERROR("The watch face template file does not exist")
            return
        }
        FitCloudWFKit.create(withTemplateBin: templatePath, isNextGUI: true, rewriteNextGUIWatchfaceNo: nil, bkImage: image, bkCornerRadius: 0, preview: image, dtPosition: .BOTTOM, dtStyle: nil, dtColor: nil) { progress, tip in
            XLOG_INFO("Creating watch face, progress: \(progress), tip: \(String(describing: tip))")
        } logging: { level, message in
            XLOG_INFO("Creating watch face, level: \(level), message: \(String(describing: message))")
        } completion: {[weak self] success, resultBinPath, resultBkImage, resultPreview, error in
            XLOG_INFO("Creating watch face, success: \(success), resultBinPath: \(String(describing: resultBinPath)), resultBkImage: \(String(describing: resultBkImage)), resultPreview: \(String(describing: resultPreview)), error: \(String(describing: error))")
            if !success {
                // 创建手表表盘失败
                if let error = error {
                    XLOG_ERROR("Failed to create watch face: \(error)")
                } else {
                    XLOG_ERROR("Failed to create watch face: unknown error")
                }
                self?.toConfirmedAIPhoto = nil
                return
            }
            self?.toConfirmedAIPhoto = nil
            XLOG_INFO("Watch face created successfully")
            self?.uploadAIWatchfaceToWatch(binPath: resultBinPath!)
        }

    }

    func uploadAIWatchfaceToWatch(binPath: String) {
        XLOG_INFO("Uploading AI-generated watch face to watch...")
        FitCloudKit.sendNewOTA(binPath) { success, error in
            XLOG_INFO("Starting to upload success: \(success), error: \(String(describing: error))")
            } progress: { progress in
                XLOG_INFO("Uploading progress: \(progress)")
            } completion: { success, avgSpeed, error in
                XLOG_INFO("Uploading completed success: \(success), avgSpeed: \(avgSpeed), error: \(String(describing: error))")
                if !success {
                    // Failed to upload watch face to watch
                    if let error = error {
                        XLOG_ERROR("Failed to upload watch face to watch: \(error)")
                    } else {
                        XLOG_ERROR("Failed to upload watch face to watch: unknown error")
                    }
                    return
                }
                XLOG_INFO("Watch face uploaded to watch successfully")
            }
    }
    
    /// Called when a log message is emitted.
    ///
    /// - Parameters:
    ///   - message: The log message text.
    ///   - level: The severity level of the log entry.
    ///   - subsystem: The subsystem that generated the log.
    ///   - category: The log category within the subsystem.
    func onLogMessage(_ message: String, level: FITCLOUDKITLOGLEVEL, subsystem: String, category: String) {
        switch level {
        case .INFO:
            XLOG_INFO(message)
        case .WARN:
            XLOG_WARNING(message)
        case .ERROR:
            XLOG_ERROR(message)
        default:
            XLOG_DEBUG(message)
        }
    }
}
