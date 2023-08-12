# 女性健康模块使用指南

**添加隐私描述**

```
<key>NSCalendarsUsageDescription</key>
<string>需要获得日历权限用于女性健康提醒等</string>

```

**初始化女性健康模块**

```swift
/// 初始化女性健康模块
/// - Parameters:
///   - userId: 用户Id
///   - localizationProvider: 本地化提供者
///   - themeProvider: 皮肤提供者
///   - logProvider: 日志服务提供者
@objc public class func start(with userId: String, _ localizationProvider: (WomenHealth.Localizable)? = nil, _ themeProvider: (WomenHealth.Themable)? = nil, _ logProvider: (WomenHealth.Loggable)? = nil)
```

**进入主设置界面**

```swift
/// 进入主设置界面
/// - Parameters:
///   - fromVC: 起始视图控制器
@objc public class func enterMainSettings(from fromVC: UIViewController)
```

**进入当前女性健康模式(月经期/备孕期/怀孕期)主页**

```swift
/// 进入当前女性健康模式(月经期/备孕期/怀孕期)主页
/// - Parameters:
///   - fromVC: 起始视图控制器
@objc public class func enterCurrentModeHome(from fromVC: UIViewController)
```

**国际化/本地化**

默认已经实现中文和英文本地化，但如果你有更多需要，或者自己自定义本地化信息，可以实现 `WomenHealth.Localizable`, 之后在初始化模块时将自己的 `localizationProvider` 传给女性健康模块。

实现 `WomenHealth.Localizable`

```swift
/// 根据 localizationKey 返回国际化字符串
@objc func localizationString(_ localizationKey: WomenHealth.LocalizationKey) -> String?
```

以下方法可以打印所有的词条信息

```swift
let strings = WomenHealthModule.localizableStrings()
for string in strings {
    print(string)
}
```

模块的自带的词条关键字通过以下方法获取，当然你也可以在程序中使用自己的本地化词条关键字

```swift
/// 根据 localizationKey 返回国际化字符串
@objc func localizationString(_ localizationKey: WomenHealth.LocalizationKey) -> String? {
    return NSLocalizedString(localizationKey.stringValue, comment: "")
}
```

**皮肤**
女性健康模块已经有默认的皮肤，你也可以通过实现 `WomenHealth.Themable` 来自定义皮肤，之后在初始化模块时将自己的 `themeProvider` 传给女性健康模块。

实现 `WomenHealth.Themable`

```swift

/// 皮肤协议
@objc public protocol Themable : NSObjectProtocol {

    /// 根据 colorKey，traits返回皮肤颜色
    @objc func colorWith(_ colorKey: WomenHealth.ThemeColorKey, _ traits: UITraitCollection?) -> UIColor?

    /// 根据 imageKey，traits返回皮肤图片
    @objc func imageWith(_ imageKey: WomenHealth.ThemeImageKey, _ traits: UITraitCollection?) -> UIImage?
}

```

**同步数据给手表**

设置 ServiceProvider

```swift
    /// 设置同步女性健康配置给手表服务提供者
    /// - Parameters:
    ///   - provider: 同步女性健康配置给手表服务提供者
    @objc public class func setWatchSyncServiceProvider(_ provider: (WomenHealth.SmartWatchSyncable)?)
```

实现 SmartWatchSyncable 协议

```swift
@objc public protocol SmartWatchSyncable : NSObjectProtocol {

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
    @objc func syncIfNeededWith(_ userId: String, _ mode: WomenHealth.WomenHealthMode, _ recentMenstrualBegin: Date, _ menstrualDuration: Int, _ menstrualCycle: Int, _ advanceDaysToRemind: Int, _ hoursInDayForRemind: Int, _ remindAtWatch: Bool, _ pregnancyRemindType: WomenHealth.PregnancyRemindType, _ menstrualDurationWhenManualBehaviorExist: Int)

    /// 手表是否支持女性健康功能
    /// - Returns: 手表是否支持女性健康功能
    @objc func withFeatureOnWatch() -> Bool
}
```
