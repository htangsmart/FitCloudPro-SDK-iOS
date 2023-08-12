# User Guide for Women's Health Module

**Add Privacy Description**

```
<key>NSCalendarsUsageDescription</key>
<string>Permission is required to access calendars for Women's Health reminders, etc.</string>
```

**Initializing the Women's Health Module**

```swift
/// Initialize the Women's Health module
/// - Parameters:
///   - userId: User ID
///   - localizationProvider: Localization provider
///   - themeProvider: Theme provider
///   - logProvider: Log service provider
@objc public class func start(with userId: String, _ localizationProvider: (WomenHealth.Localizable)? = nil, _ themeProvider: (WomenHealth.Themable)? = nil, _ logProvider: (WomenHealth.Loggable)? = nil)
```

**Enter the Main Settings Page**

```swift
/// Enter the main settings page
/// - Parameters:
///   - fromVC: Starting view controller
@objc public class func enterMainSettings(from fromVC: UIViewController)
```

**Enter the Home Page for the Current Women's Health Mode (Menstrual/Preconception/Pregnancy)**

```swift
/// Enter the home page for the current Women's Health mode (Menstrual/Preconception/Pregnancy)
/// - Parameters:
///   - fromVC: Starting view controller
@objc public class func enterCurrentModeHome(from fromVC: UIViewController)
```

**Internationalization/Localization**

Default localization for Chinese and English is already implemented. However, if you have additional requirements or want to customize the localization information, you can implement the `WomenHealth.Localizable` protocol and pass your own `localizationProvider` to the Women's Health module during initialization.

Implement `WomenHealth.Localizable`

```swift
/// Return the localized string based on the localizationKey
@objc func localizationString(_ localizationKey: WomenHealth.LocalizationKey) -> String?
```

The following method can be used to print all the localized strings:

```swift
let strings = WomenHealthModule.localizableStrings()
for string in strings {
    print(string)
}
```

You can retrieve the module's built-in localization key by using the following method. Of course, you can also use your own localization keys in the program:

```swift
/// Return the localized string based on the localizationKey
@objc func localizationString(_ localizationKey: WomenHealth.LocalizationKey) -> String? {
    return NSLocalizedString(localizationKey.stringValue, comment: "")
}
```

**Themes**

The Women's Health module already has default themes. You can customize the theme by implementing the `WomenHealth.Themable` protocol and passing your own `themeProvider` to the Women's Health module during initialization.

Implement `WomenHealth.Themable`

```swift
/// Theme protocol
@objc public protocol Themable: NSObjectProtocol {

    /// Return the theme color based on the colorKey and traits
    @objc func colorWith(_ colorKey: WomenHealth.ThemeColorKey, _ traits: UITraitCollection?) -> UIColor?

    /// Return the theme image based on the imageKey and traits
    @objc func imageWith(_ imageKey: WomenHealth.ThemeImageKey, _ traits: UITraitCollection?) -> UIImage?
}
```

**Sync Data to Smartwatch**

Set the SmartWatchSyncable service provider

```swift
/// Set the service provider for syncing Women's Health configuration to a smartwatch
/// - Parameters:
///   - provider: Service provider for syncing Women's Health configuration to a smartwatch
@objc public class func setWatchSyncServiceProvider(_ provider: (WomenHealth.SmartWatchSyncable)?)
```

Implement the SmartWatchSyncable protocol

```swift
@objc public protocol SmartWatchSyncable: NSObjectProtocol {

    /// Sync Women's Health configuration to the smartwatch if necessary
    /// - Parameters:
    ///   - userId: User ID
    ///   - mode: Current Women's Health mode
    ///   - recentMenstrualBegin: Start date of the most recent menstrual period
    ///   - menstrualDuration: Menstrual period duration
    ///   - menstrualCycle: Menstrual cycle length
    ///   - advanceDaysToRemind: Number of days in advance for reminders
    ///   - hoursInDayForRemind: Hour of the day for reminders
    ///   - remindAtWatch: Whether to remind on the smartwatch
    ///   - pregnancyRemindType: Pregnancy reminder type
    ///   - menstrualDurationWhenManualBehaviorExist: Menstrual duration when manual behavior exists. When it is 0, it indicates no manual behavior.
    @objc func syncIfNeededWith(_ userId: String, _ mode: WomenHealth.WomenHealthMode, _ recentMenstrualBegin: Date, _ menstrualDuration: Int, _ menstrualCycle: Int, _ advanceDaysToRemind: Int, _ hoursInDayForRemind: Int, _ remindAtWatch: Bool, _ pregnancyRemindType: WomenHealth.PregnancyRemindType, _ menstrualDurationWhenManualBehaviorExist: Int)

    /// Check if the smartwatch supports Women's Health features
    /// - Returns: Whether the smartwatch supports Women'sHealth features
    @objc func withFeatureOnWatch() -> Bool
}
```
