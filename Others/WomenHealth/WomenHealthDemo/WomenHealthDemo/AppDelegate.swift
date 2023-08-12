//
//  AppDelegate.swift
//  WomenHealthDemo
//
//  Created by pcjbird on 7/12/23.
//

import UIKit
import WomenHealth
import YPNavigationBarTransition
import FitCloudKit


@main
class AppDelegate: UIResponder, UIApplicationDelegate, Loggable {


    func log(_ logLevel: LogLevel, _ message: String) {
        print(message)
    }

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        WomenHealthModule.start(with: "1000", nil, nil, self)
        WomenHealthModule.setWatchSyncServiceProvider(self)
        
        
        let strings = WomenHealthModule.localizableStrings()
        for string in strings {
            print(string)
        }
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }

}


extension YPNavigationController : NavigationBarConfigureStyle {
    public func yp_navigtionBarConfiguration() -> YPNavigationBarConfigurations {
        return [.backgroundStyleColor]
    }
    
    public func yp_navigationBarTintColor() -> UIColor! {
        if(self.traitCollection.userInterfaceStyle == .dark)
        {
            return .white
        }
        return .black
    }
    
    public func yp_navigationBackgroundColor() -> UIColor! {
        if(self.traitCollection.userInterfaceStyle == .dark)
        {
            return .black
        }
        return .white
    }
}

extension AppDelegate: SmartWatchSyncable {
    /// 如果需要则同步女性健康配置给手表
    /// - Parameters:
    ///   - userId: 用户Id
    ///   - mode: 当前女性健康模式
    ///   - recentMenstrualBegin: 最近一次月经开始日期
    ///   - menstrualDuration: 经期长度
    ///   - menstrualCycle: 周期长度
    ///   - advanceDaysToRemind: 提前几天提醒
    ///   - hoursInDayForRemind: 几点提醒
    ///   - remindAtWatch: 是否在手表上提醒
    ///   - pregnancyRemindType: 怀孕期提醒方式
    ///   - menstrualDurationWhenManualBehaviorExist：如果存在手动经期操作时经期长度，当为0时，表示没有手动经期操作
    @objc func syncIfNeededWith(_ userId: String, _ mode: WomenHealth.WomenHealthMode, _ recentMenstrualBegin: Date, _ menstrualDuration: Int, _ menstrualCycle: Int, _ advanceDaysToRemind: Int, _ hoursInDayForRemind: Int, _ remindAtWatch: Bool, _ pregnancyRemindType: WomenHealth.PregnancyRemindType, _ menstrualDurationWhenManualBehaviorExist: Int) {
        
        if self.withFeatureOnWatch() {
            let formatter = DateFormatter()
            formatter.dateFormat = "yyyy-MM-dd"
            let menstruationBegin = formatter.string(from: recentMenstrualBegin)
            guard let whSettings = FitCloudWomenHealthSetting.settingwithMode(WOMENHEALTHMODE(rawValue: UInt8(mode.rawValue))!, advanceDaysToRemind: UInt8(advanceDaysToRemind), offsetMinutesInDayOfRemind: UInt16(hoursInDayForRemind*60), mensesDuration: UInt8(menstrualDuration), menstrualCycle: UInt8(menstrualCycle), recentMenstruationBegin: menstruationBegin, daysOfFinishSinceMensesBegin: UInt8(menstrualDurationWhenManualBehaviorExist), pregancyRemind: PREGNANCYREMINDTYPE(rawValue: UInt8(pregnancyRemindType.rawValue))!) else {
                return
            }
            let op = SyncWomenHealthConfigOperation(whSettings)
            SmartWatchBackgroundOperationQueue().add(op)
        }
    }

    /// 手表是否支持女性健康功能
    /// - Returns: 手表是否支持女性健康功能
    @objc func withFeatureOnWatch() -> Bool {
        if FitCloudKit.deviceReady() {
            guard let allConfig = FitCloudKit.allConfig() else {
                return false
            }
            let firmware = allConfig.firmware
            if let featureAvailable = firmware?.hardwareSupported.contains(._WOMENHEALTH) {
                return featureAvailable
            }
        }
        return false
    }
}
