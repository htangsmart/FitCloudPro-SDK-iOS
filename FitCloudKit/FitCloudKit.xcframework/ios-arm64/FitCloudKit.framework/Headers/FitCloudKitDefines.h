//
//  FitCloudKitDefines.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/29.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#ifndef FitCloudKitDefines_h
#define FitCloudKitDefines_h

#import <Foundation/Foundation.h>

#pragma mark - 错误码相关

/// FitCloudKit 错误码作用域
#define FITCLOUDKITERRORDOMAIN @"FITCLOUDKITERRORDOMAIN"

/// FitCloudKit 新 OTA 升级错误码作用域
#define FITCLOUDNEWOTAERRORDOMAIN @"FITCLOUDNEWOTAERRORDOMAIN"

/// FitCloudKit 错误码定义
typedef NS_ENUM(NSInteger, FITCLOUDKITERROR) {
    /// 未知错误
    FITCLOUDKITERROR_UNKNOWN = 20000,
    /// 错误的 Sequence ID
    FITCLOUDKITERROR_BADSEQUENCEID = 20001,
    /// 发送数据包给手表出错，重试达到最大次数
    FITCLOUDKITERROR_PACKETSENDMAXRETRYTIMES = 20002,
    /// 非法的命令数据包，或格式不正确
    FITCLOUDKITERROR_BADCMDPACKET = 20003,
    /// 发送给手表的命令执行超时
    FITCLOUDKITERROR_CMDEXECTIMEOUT = 20004,
    /// 手表命令响应格式不正确
    FITCLOUDKITERROR_CMDCALLBACKINVALID = 20005,
    /// 准备执行手表命令时，发现手表意外已经断开连接
    FITCLOUDKITERROR_UNKNOWNDISCONNECTWHENCMDEXEC = 20006,
    /// 连接手表超时
    FITCLOUDKITERROR_CONNECTIONTIMEOUT = 20007,
    /// 尚未连接到手表设备
    FITCLOUDKITERROR_NOTCONNECTED = 20020,
    /// 错误的 Characteristic(写)
    FITCLOUDKITERROR_BADWRITECHARACTERISTIC = 20021,
    /// 手表初始化尚未完成，尚不能发送通信命令
    FITCLOUDKITERROR_COMMUNICATIONNOTREADY = 20022,
    /// ANCS 未授权，仅 iOS13 之后可用
    FITCLOUDKITERROR_ANCSNOTAUTHORIZED = 20023,
    /// 手表不支持该功能
    FITCLOUDKITERROR_DEVICENOTSUPPORT = 20024,
    /// 手表断开连接
    FITCLOUDKITERROR_DEVICEDISCONNECTED = 20025,
    /// 参数错误
    FITCLOUDKITERROR_WRONGPARAM = 20026,
    /// 数组长度溢出
    FITCLOUDKITERROR_ARRAYSIZEOVERFLOW = 20027,
    /// 文件不存在
    FITCLOUDKITERROR_FILENOTEXIST = 20028,
    /// GPS 文件不支持获取有效期
    FITCLOUDKITERROR_GPSFILENOTSUPPORTGETEXPIRETIME = 20029,
    /// 已连接手表时禁止扫描
    FITCLOUDKITERROR_SCANBLOCKEDBYCONNECTED = 20030,
    /// 手表连接中时禁止扫描
    FITCLOUDKITERROR_SCANBLOCKEDBYCONNECTING = 20031,
    /// SDK 初始化未就绪时禁止扫描
    FITCLOUDKITERROR_SCANBLOCKEDBYNOTREADY = 20032,
    /// 手表已经绑定用户，请先解绑
    FITCLOUDKITERROR_USEROBJECTALREADYBOUND = 30001,
    /// 需要先绑定用户
    FITCLOUDKITERROR_USEROBJECTSHOULDBINDFIRST = 30002,
    /// 手表端主动取消绑定
    FITCLOUDKITERROR_CANCELBYREMOTEPEER = 30003,
    /// 手表超时未点击确认绑定
    FITCLOUDKITERROR_CONFIRMTIMEOUTWITHREMOTEPEER = 30004,
    /// 音频蓝牙未配对
    FITCLOUDKITERROR_AUDIOBLUETOOTHNOTPAIRED = 30005,
    /// 手表需要恢复出厂设置才能绑定
    FITCLOUDKITERROR_SMARTWATCHNEEDRESETTOFACTORY = 30006,
    /// 当前正在同步历史运动健康数据，请勿重复请求
    FITCLOUDKITERROR_DATASYNCREPEATREQUEST = 40001,
    /// 请求待同步的运动健康数据总长度失败
    FITCLOUDKITERROR_REQUESTSYNCDATALENFAILURE = 40002,
    /// 当前正在同步历史运动健康数据，请稍后再试
    FITCLOUDKITERROR_BLOCKBYDATASYNC = 40003,
    /// 历史运动健康数据同步终止，等待手表响应超时...
    FITCLOUDKITERROR_DATASYNCTIMEOUT = 40004,
    /// 当前手表正在心电检测，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYECGDETECTING = 40005,
    /// 当前手表正在保存心电数据，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYECGSAVINGDATA = 40006,
    /// 当前手表处于 DFU Pending 模式，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYDFUPENDINGMODE = 40007,
    /// 当前正在同步手表设置，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYSYNCNESSARYSETTINGS = 40008,
    /// 当前手表处于 DFU 模式，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYDFUMODE = 40009,
    /// 当前手表正在进行 OTA 升级，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYOTAINPROGRESS = 40010,
    /// 当前手表不支持天气功能
    FITCLOUDKITERROR_WEATHERFEATURENOTSUPPORT = 50001,
    /// 非法的二维码内容
    FITCLOUDKITERROR_BADQRCODE = 50002,
    /// 二维码内容长度过长，最大长度 274 字节
    FITCLOUDKITERROR_QRCODEBADLENGTH = 50003,
    /// 非法的第三方外设
    FITCLOUDKITERROR_BADTHIRDPARTYPERIPHERAL = 50004,
    /// 未能发现待转换的外设
    FITCLOUDKITERROR_TOTRANSLATEPERIPHERALNOTFOUND = 50005,
    /// 当前不允许进入 DFU 模式，原因未知
    FITCLOUDKITERROR_DFUNOTALLOWUNKNOWNREASON = 60000,
    /// 当前不允许进入 DFU 模式，手表电量过低
    FITCLOUDKITERROR_DFUNOTALLOWFORBATTERYLOW = 60001,
    /// 当前已经是 DFU 模式
    FITCLOUDKITERROR_ALREADYINDFUMODE = 60002,
    /// 当前不是 DFU 模式
    FITCLOUDKITERROR_NOTDFUMODE = 60003,
    /// 当前不允许进入 DFU 模式，手表处于省电模式中
    FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE = 60004,
    /// 常用联系人数量达到最大值，最多支持设定 10 个常用联系人
    FITCLOUDKITERROR_FAVCONTACTSREACHMAX = 70001,
    /// 当前手表不支持常用联系人
    FITCLOUDKITERROR_FAVCONTACTSNOTSUPPORT = 70002,
    /// 习惯数量达到最大值，最多支持设定 10 个习惯养成
    FITCLOUDKITERROR_HABITSREACHMAX = 71001,
    /// 习惯养成名称为空或长度超过限定的 32 字节
    FITCLOUDKITERROR_BADHABITNAME = 71002,
    /// 习惯养成习惯开始时间为空
    FITCLOUDKITERROR_BADHABITBEGINDATE = 71003,
    /// 当前手表不支持习惯养成
    FITCLOUDKITERROR_HABITSNOTSUPPORT = 71004,
    /// 当前手表不支持自定义标签
    FITCLOUDKITERROR_CUSTOMLABELSNOTSUPPORT = 72001,
    /// 当前设定没有变化
    FITCLOUDKITERROR_NOCHANGEWITHSETTINGS = 80001,
};

#pragma mark - 日志等级

/// FitCloudKit 日志等级定义
typedef NS_ENUM(NSInteger, FITCLOUDKITLOGLEVEL) {
    FITCLOUDKITLOGLEVEL_DEBUG = 0,
    FITCLOUDKITLOGLEVEL_VERBOSE,
    FITCLOUDKITLOGLEVEL_INFO,
    FITCLOUDKITLOGLEVEL_WARNING,
    FITCLOUDKITLOGLEVEL_ERROR,
    FITCLOUDKITLOGLEVEL_EXCEPTION,
    FITCLOUDKITLOGLEVEL_ABORT,
    FITCLOUDKITLOGLEVEL_MIN = FITCLOUDKITLOGLEVEL_DEBUG,
    FITCLOUDKITLOGLEVEL_MAX = FITCLOUDKITLOGLEVEL_ABORT,
    FITCLOUDKITLOGLEVEL_MUTE = NSIntegerMax
};

#pragma mark - 蓝牙中心设备(Central)状态

/// FitCloudKit 蓝牙中心设备 (Central) 状态
typedef NS_ENUM(NSInteger, FITCLOUDBLECENTRALSTATE) {
    FITCLOUDBLECENTRALSTATE_UNKNOWN = 0,
    FITCLOUDBLECENTRALSTATE_RESETTING,
    FITCLOUDBLECENTRALSTATE_UNSUPPORTED,
    FITCLOUDBLECENTRALSTATE_UNAUTHORIZED,
    FITCLOUDBLECENTRALSTATE_POWEREDOFF,
    FITCLOUDBLECENTRALSTATE_POWEREDON,
};

#pragma mark - 芯片供应商

/// 芯片供应商
typedef NS_ENUM(NSInteger, FITCLOUDCHIPVENDOR) {
    /// 未知
    FITCLOUDCHIPVENDOR_UNKNOWN = 0,
    /// Realtek
    FITCLOUDCHIPVENDOR_REALTEK = 1,
    /// Nordic
    FITCLOUDCHIPVENDOR_NORDIC = 2,
    /// Bluetrum
    FITCLOUDCHIPVENDOR_BLUETRUM = 3,
};

#pragma mark - the watch common features define

/// the watch common features define
typedef NS_ENUM(NSInteger, FITCLOUDDEVICEFEATURE) {
    /// ANCS, display messages also on watch when iOS device received remote or local notifications
    FITCLOUDDEVICEFEATURE_ANCS,
    /// Shake the smart watch to control the iPhone for taking photograph
    FITCLOUDDEVICEFEATURE_SHAKEFORPHOTOGRAPH,
    /// Find the smart watch, the user can find the smart watch from the app side, the smart watch will vibrate when found
    FITCLOUDDEVICEFEATURE_FINDWATCH,
    /// Find iPhone, the user can find iPhone from the smart watch side, the iPhone will vibrate and play a reminder sound when found
    FITCLOUDDEVICEFEATURE_FINDIPHONE,
    /// Restore the smart watch to factory settings, the user can restore the smart watch to factory settings from the app side
    FITCLOUDDEVICEFEATURE_RESTORETOFACTORYSETTINGS,
    /// Reboot the smart watch device, the user can reboot the smart watch from the app side
    FITCLOUDDEVICEFEATURE_REBOOTDEVICE,
    /// Turn off, the user can turn of the smart watch from the app side
    FITCLOUDDEVICEFEATURE_TURNOFF,

    /// Alarm clock
    FITCLOUDDEVICEFEATURE_ALARMCLOCK,
    /// Schedules, something like alarm clock but with rich schedule types
    FITCLOUDDEVICEFEATURE_SCHEDULES,
    /// Habits
    FITCLOUDDEVICEFEATURE_HABITS,
    /// Medals
    FITCLOUDDEVICEFEATURE_MEDALS,
    /// Favorite contacts
    FITCLOUDDEVICEFEATURE_FAVORITECONTACTS,
    /// Emergency contacts
    FITCLOUDDEVICEFEATURE_EMERGENCYCONTACTS,
    /// World clock
    FITCLOUDDEVICEFEATURE_WORLDCLOCK,
    /// Emotion feature
    FITCLOUDDEVICEFEATURE_EMOTION,
    /// Festival wish
    FITCLOUDDEVICEFEATURE_FESTIVALWISH,

    /// Weather, set the watch weather information via the app
    FITCLOUDDEVICEFEATURE_WEATHER,

    /// Personalized reminder, you can add some custom reminders due to your self, such as watering flowers, walking a dog and so on
    FITCLOUDDEVICEFEATURE_PERSONALIZEDREMINDER,

    /// Women health, help women to record information and events related to menstruation, pregnancy preparation, and pregnancy
    FITCLOUDDEVICEFEATURE_WOMENHEALTH,
    /// Lovers feature, interactions between lovers
    FITCLOUDDEVICEFEATURE_LOVERS,

    /// Upload watchface to the watch via OTA
    FITCLOUDDEVICEFEATURE_WATCHFACEOTA,
    /// DIY the watchface background, preview and the datetime position and then upload watchface to the watch via OTA
    FITCLOUDDEVICEFEATURE_WATCHFACEDIYANDOTA,
    /// Edit and change the watchface modulars via the app, for example, the watchface has 4 modulars which have their own styles, through this, you can change specific modular's style from one to another.
    FITCLOUDDEVICEFEATURE_WACHFACEMODULAREDIT,
    /// Upload workout module file to the watch via OTA, for example, you can upload `Outdoor Run` workout module to the watch, for usual, these workout module files are downloaded from the cloud server.
    FITCLOUDDEVICEFEATURE_WORKOUTOTA,
    /// Upload music to the watch via OTA
    FITCLOUDDEVICEFEATURE_MUSICOTA,
    /// Upload photos to the watch via OTA
    FITCLOUDDEVICEFEATURE_PHOTOALBUMOTA,
    /// Upload ebooks to the watch via OTA
    FITCLOUDDEVICEFEATURE_EBOOKOTA,
    /// Upload ga,es to the watch via OTA
    FITCLOUDDEVICEFEATURE_GAMEOTA,

    /// The motion sensing game
    FITCLOUDDEVICEFEATURE_MOTIONSENSINGGAME,

    /// Turn-by-turn Navigation, the users plan their routes and navigate on the app, while also broadcasting navigation information on the smart watch side
    FITCLOUDDEVICEFEATURE_TURNBYTURNNAVIGATION,
    /// GPS accelerate, app can upload GPS epo files to the smart watch for accelerating the watch GPS satellite search speed
    FITCLOUDDEVICEFEATURE_GPSACCELERATE,

    /// Cricket match, display live cricket match informations on the smart watch
    FITCLOUDDEVICEFEATURE_CRICKETMATCH,
    /// LLM
    FITCLOUDDEVICEFEATURE_LLM,
    /// Muslim prayer
    FITCLOUDDEVICEFEATURE_MUSLIMPRAYER,

    /// Wallet，the money receive qrcode
    FITCLOUDDEVICEFEATURE_MONEYRECEIVEQRCODE,
    /// The business card qrcode
    FITCLOUDDEVICEFEATURE_BUSINESSCARDQRCODE,
    /// The nucleic acid qrcode
    FITCLOUDDEVICEFEATURE_NUCLEICACIDQRCODE,
};

#pragma mark -手表设备能力

/// 手表设备能力类型定义
typedef NS_ENUM(NSInteger, FITCLOUDDEVICECAPACITY) {
    /// 支持的最大闹钟数量
    FITCLOUDDEVICECAPACITY_ALARMCLOCKCOUNT = 0x02,
    /// 支持的最大日程数量
    FITCLOUDDEVICECAPACITY_SCHEDULECOUNT = 0x03,
    /// 支持的最大常用联系人数量
    FITCLOUDDEVICECAPACITY_FAVORITECONTACTCOUNT = 0x04,
    /// 支持的天气种类数量，目前支持的数量有 13/16
    FITCLOUDDEVICECAPACITY_WEATHERCOUNT = 0x05,
    /// 支持喝水个性化提醒功能
    FITCLOUDDEVICECAPACITY_WATERDRINKPERSONALIZEDREMINDERFEATURE = 0x06,
    /// 支持久坐个性化提醒功能
    FITCLOUDDEVICECAPACITY_SEDENTARYPERSONALIZEDREMINDERFEATURE = 0x07,
    /// 支持吃药个性化提醒功能
    FITCLOUDDEVICECAPACITY_MEDICATIONPERSONALIZEDREMINDERFEATURE = 0x08,
    /// 支持自定义个性化提醒功能
    FITCLOUDDEVICECAPACITY_CUSTOMIZEDPERSONALIZEDREMINDERFEATURE = 0x09,
    /// 支持的自定义个性化提醒数量
    FITCLOUDDEVICECAPACITY_CUSTOMIZEDPERSONALIZEDREMINDERCOUNT = 0x0a,
    /// 支持的最大我的任务数量
    FITCLOUDDEVICECAPACITY_MYTASKCOUNT = 0x1d,
    /// AI 对话应答文本支持的最大字节数
    FITCLOUDDEVICECAPACITY_AICONVERSATIONRESPONSETEXTBYTES = 0x1f,
    /// 支持的最大世界时钟数量
    FITCLOUDDEVICECAPACITY_WORLDCLOCKCOUNT = 0x20,
    /// 支持的最大来电照片插槽数量
    FITCLOUDDEVICECAPACITY_INCOMINGCALLPHOTOSLOTCOUNT = 0x21,
};

#pragma mark - 手表硬件

/// 手表硬件功能支持定义
///
/// 定义手表支持的硬件功能选项
typedef NS_OPTIONS(UInt32, FITCLOUDHARDWARE) {
    /// 无功能支持
    FITCLOUDHARDWARE_NONE = 0,
    /// 心率功能
    FITCLOUDHARDWARE_HEARTRATE = 1,
    /// 血氧功能
    FITCLOUDHARDWARE_BLOODOXYGEN = 1 << 1,
    /// 血压功能
    FITCLOUDHARDWARE_BLOODPRESSURE = 1 << 2,
    /// 呼吸频率功能
    FITCLOUDHARDWARE_RESPIRATORYRATE = 1 << 3,
    /// 天气功能
    FITCLOUDHARDWARE_WEATHER = 1 << 4,
    /// 心电功能
    FITCLOUDHARDWARE_ECG = 1 << 5,
    /// 运动模式功能
    FITCLOUDHARDWARE_SPORTSMODE = 1 << 6,
    /// 微信运动功能
    FITCLOUDHARDWARE_WECHATSPORTS = 1 << 7,
    /// 8762C 新平台，升级时使用新平台升级库
    FITCLOUDHARDWARE_8762C = 1 << 8,
    /// 运动模式保存心率数据
    /// - Note: 1.运动模式的数据 item 中增加心率，长度会变化，时间间隔也变化，具体看协议文档
    /// - Note: 2.App 上要增加心率曲线
    FITCLOUDHARDWARE_SHOULDSAVEHEARTRATEWHENSPORTSMODE = 1 << 9,
    /// 体温功能
    FITCLOUDHARDWARE_BODYTEMPERATURE = 1 << 10,
    /// 女性健康功能
    FITCLOUDHARDWARE_WOMENHEALTH = 1 << 11,
    /// 语音识别功能
    /// - Note: 为 1 时手表上有语音识别功能，为 0 则手表上没有语音识别功能
    FITCLOUDHARDWARE_VOICERECOG = 1 << 12,
    /// 压力指数功能
    FITCLOUDHARDWARE_STRESSINDEX = 1 << 13,
    /// 游戏记录功能
    FITCLOUDHARDWARE_GAMERECORDS = 1 << 14,
    /// Nordic 芯片
    FITCLOUDHARDWARE_NORDIC = 1 << 15,
    /// 固件升级使用静默升级
    FITCLOUDHARDWARE_DFUSHOULDSILENTMODE = 1 << 16,
    /// 屏幕及马达参数调节 (亮屏时长/亮度/马达振动强度)
    FITCLOUDHARDWARE_SCREENANDVIBRATEPARAM = 1 << 17,
    /// 是否应该禁用自定义表盘功能
    FITCLOUDHARDWARE_SHOULDDISABLEDIYWATCHFACE = 1 << 18,
    /// 运动模式 (DIY) 固件推送
    FITCLOUDHARDWARE_SPORTSMODEDIY = 1 << 19,
    /// 运动模式 GPS 互联
    FITCLOUDHARDWARE_WATCHSPORTSWITHGPSCONNECT = 1 << 20,
    /// 基于气压泵的真血压
    FITCLOUDHARDWARE_BLOODPRESSUREBASEONPNEUMATICPUMP = 1 << 21,
    /// 手表手动测量数据同步
    FITCLOUDHARDWARE_ALLOWSYNCWATCHMANUALMEASUREDATA = 1 << 22,
    /// 禁用睡眠功能
    FITCLOUDHARDWARE_SHOULDDISABLESLEEPFEATURE = 1 << 23,
    /// GPS 模块
    FITCLOUDHARDWARE_GPS = 1 << 24,
    /// 8773 平台
    FITCLOUDHARDWARE_8773 = 1 << 26,
    /// 568X 平台
    FITCLOUDHARDWARE_568X = 1 << 27,
    /// 是否应该禁用微信运动功能
    FITCLOUDHARDWARE_SHOULDDISABLEWECHATSPORTS = 1 << 28,
    /// 是否应该禁用私人血压功能
    FITCLOUDHARDWARE_SHOULDDISABLEBLOODPRESSUREPRIVATEMODE = 1 << 29,
};

#pragma mark - 手表显示

/// 手表屏幕显示定义
///
/// 定义手表屏幕可显示的内容选项
typedef NS_OPTIONS(UInt32, FITCLOUDSCREENDISPLAY) {
    FITCLOUDSCREENDISPLAY_NONE = 0,                     ///< 无显示内容
    FITCLOUDSCREENDISPLAY_DATETIME = 1,                 ///< 显示日期和时间
    FITCLOUDSCREENDISPLAY_STEPS = 1 << 1,               ///< 显示步数统计
    FITCLOUDSCREENDISPLAY_DISTANCE = 1 << 2,            ///< 显示运动距离
    FITCLOUDSCREENDISPLAY_CALORIES = 1 << 3,            ///< 显示消耗卡路里
    FITCLOUDSCREENDISPLAY_SLEEP = 1 << 4,               ///< 显示睡眠数据
    FITCLOUDSCREENDISPLAY_HEARTRATE = 1 << 5,           ///< 显示心率数据
    FITCLOUDSCREENDISPLAY_BLOODOXYGEN = 1 << 6,         ///< 显示血氧饱和度
    FITCLOUDSCREENDISPLAY_BLOODPRESSURE = 1 << 7,       ///< 显示血压数据
    FITCLOUDSCREENDISPLAY_WEATHERFORECAST = 1 << 8,     ///< 显示天气预报信息
    FITCLOUDSCREENDISPLAY_FINDIPHONE = 1 << 9,          ///< 显示查找手机功能
    FITCLOUDSCREENDISPLAY_MACID = 1 << 10,              ///< 显示手表 MAC 地址和 ID 信息
    FITCLOUDSCREENDISPLAY_UV = 1 << 11,                 ///< 显示紫外线指数
    FITCLOUDSCREENDISPLAY_EARTHMAGNETICFIELD = 1 << 12, ///< 显示地磁场数据
    FITCLOUDSCREENDISPLAY_STOPWATCH = 1 << 13,          ///< 显示秒表功能
};

#pragma mark - 手表偏好设置

/// 手表偏好设置定义
///
/// 定义手表的各种偏好设置选项，包括佩戴习惯、显示格式、单位制等
typedef NS_OPTIONS(UInt16, FITCLOUDPREFER) {
    /// 无偏好设置
    FITCLOUDPREFER_NONE = 0,

    /// 佩戴习惯设置
    /// - 0: 左手佩戴
    /// - 1: 右手佩戴
    FITCLOUDPREFER_RIGHTHAND = 1,

    /// 佩戴检测模式
    /// - 0: 普通佩戴检测
    /// - 1: 加强佩戴检测
    FITCLOUDPREFER_ENHANCEDDETECTION = 1 << 1,

    /// 时间显示格式
    /// - 0: 24 小时制
    /// - 1: 12 小时制
    FITCLOUDPREFER_SHOWAS12HOURS = 1 << 2,

    /// 长度单位制式
    /// - 0: 公制
    /// - 1: 英制
    FITCLOUDPREFER_IMPERIALUNIT = 1 << 3,

    /// 温度单位
    /// - 0: 摄氏度
    /// - 1: 华氏度
    FITCLOUDPREFER_FAHRENHEIT = 1 << 4,

    /// 天气推送开关
    /// - 0: 关闭
    /// - 1: 开启
    FITCLOUDPREFER_WEATHERPUSH = 1 << 5,

    /// 蓝牙断开振动提醒
    /// - 0: 关闭
    /// - 1: 开启
    FITCLOUDPREFER_VIBRATEWHENDISCONNECT = 1 << 6,

    /// 运动目标达成提醒 (计步/距离/卡路里)
    /// - 0: 关闭
    /// - 1: 开启
    FITCLOUDPREFER_REMINDWHENSPORTSGOALACHIEVEMENT = 1 << 7,

    /// 重量单位制式
    /// - 0: 英制
    /// - 1: 公制
    FITCLOUDPREFER_METRICWEIGHT = 1 << 8,
    
    /// 体温单位
    /// - 0: 摄氏度
    /// - 1: 华氏度
    FITCLOUDPREFER_BODYTEMPERATURE_FAHRENHEIT = 1 << 9,
};

#pragma mark - 手表语言

/// 手表语言定义
typedef NS_ENUM(Byte, FITCLOUDLANGUAGE) {
    FITCLOUDLANGUAGE_NOTSET = 0x00,             // 未设置
    FITCLOUDLANGUAGE_CHINESESIMPLIFIED = 0x01,  // 简体中文
    FITCLOUDLANGUAGE_CHINESETRADITIONAL = 0x02, // 繁体中文
    FITCLOUDLANGUAGE_ENGLISH = 0x03,            // 英语
    FITCLOUDLANGUAGE_GERMAN = 0x04,             // 德语
    FITCLOUDLANGUAGE_RUSSIAN = 0x05,            // 俄语
    FITCLOUDLANGUAGE_SPANISH = 0x06,            // 西班牙语
    FITCLOUDLANGUAGE_PORTUGUESE = 0x07,         // 葡萄牙语
    FITCLOUDLANGUAGE_FRENCH = 0x08,             // 法语
    FITCLOUDLANGUAGE_JAPANESE = 0x09,           // 日语
    FITCLOUDLANGUAGE_ARABIC = 0x0a,             // 阿拉伯语言
    FITCLOUDLANGUAGE_DUTCH = 0x0b,              // 荷兰语
    FITCLOUDLANGUAGE_ITALIAN = 0x0c,            // 意大利语
    FITCLOUDLANGUAGE_BENGALI = 0x0d,            // 孟加拉语
    FITCLOUDLANGUAGE_CROATIAN = 0xe,            // 克罗地亚语
    FITCLOUDLANGUAGE_CZECH = 0x0f,              // 捷克语

    FITCLOUDLANGUAGE_DANISH = 0x10,     // 丹麦语
    FITCLOUDLANGUAGE_GREEK = 0x11,      // 希腊语
    FITCLOUDLANGUAGE_HEBREW = 0x12,     // 希伯来语 (以色列)
    FITCLOUDLANGUAGE_HINDI = 0x13,      // 印度语
    FITCLOUDLANGUAGE_HUN = 0x14,        // 匈牙利语
    FITCLOUDLANGUAGE_INDONESIAN = 0x15, // 印度尼西亚语
    FITCLOUDLANGUAGE_KOREAN = 0x16,     // 韩语 (朝鲜语)
    FITCLOUDLANGUAGE_MALAY = 0x17,      // 马来语
    FITCLOUDLANGUAGE_PERSIAN = 0x18,    // 波斯语
    FITCLOUDLANGUAGE_POLISH = 0x19,     // 波兰语
    FITCLOUDLANGUAGE_RUMANIAN = 0x1a,   // 罗马尼亚语
    FITCLOUDLANGUAGE_SERB = 0x1b,       // 塞尔维亚语
    FITCLOUDLANGUAGE_SWEDISH = 0x1c,    // 瑞典语
    FITCLOUDLANGUAGE_THAI = 0x1d,       // 泰语
    FITCLOUDLANGUAGE_TURKISH = 0x1e,    // 土耳其语
    FITCLOUDLANGUAGE_URDU = 0x1f,       // 乌尔都语

    FITCLOUDLANGUAGE_VIETNAMESE = 0x20,   // 越南语
    FITCLOUDLANGUAGE_CATALAN = 0x21,      // 加泰隆语 (西班牙)
    FITCLOUDLANGUAGE_LATVIAN = 0x22,      // 拉脱维亚语
    FITCLOUDLANGUAGE_LITHUANIAN = 0x23,   // 立陶宛语
    FITCLOUDLANGUAGE_NORWEGIAN = 0x24,    // 挪威语
    FITCLOUDLANGUAGE_SLOVAK = 0x25,       // 斯洛伐克语
    FITCLOUDLANGUAGE_SLOVENIAN = 0x26,    // 斯洛文尼亚语
    FITCLOUDLANGUAGE_BULGARIAN = 0x27,    // 保加利亚语
    FITCLOUDLANGUAGE_UKRAINIAN = 0x28,    // 乌克兰语
    FITCLOUDLANGUAGE_FILIPINO = 0x29,     // 菲律宾语
    FITCLOUDLANGUAGE_FINNISH = 0x2a,      // 芬兰语
    FITCLOUDLANGUAGE_SOUTHAFRICAN = 0x2b, // 南非语
    FITCLOUDLANGUAGE_ROMANSH = 0x2c,      // 罗曼什语 (瑞士)
    FITCLOUDLANGUAGE_BURMESE = 0x2d,      // 缅甸语
    FITCLOUDLANGUAGE_CAMBODIAN = 0x2e,    // 柬埔寨语
    FITCLOUDLANGUAGE_AMHARIC = 0x2f,      // 阿姆哈拉语

    FITCLOUDLANGUAGE_BELARUSIAN = 0x30,  // 白俄罗斯语
    FITCLOUDLANGUAGE_ESTONIAN = 0x31,    // 爱沙尼亚语
    FITCLOUDLANGUAGE_SWAHILI = 0x32,     // 斯瓦希里语 (坦桑尼亚)
    FITCLOUDLANGUAGE_ZULU = 0x33,        // 祖鲁语 (南非)
    FITCLOUDLANGUAGE_AZERBAIJANI = 0x34, // 阿塞拜疆语
    FITCLOUDLANGUAGE_ARMENIAN = 0x35,    // 亚美尼亚语 (亚美尼亚)
    FITCLOUDLANGUAGE_GEORGIAN = 0x36,    // 格鲁吉亚语 (格鲁吉亚)
    FITCLOUDLANGUAGE_LAO = 0x37,         // 老挝语 (老挝)
    FITCLOUDLANGUAGE_MONGOLIAN = 0x38,   // 蒙古语
    FITCLOUDLANGUAGE_NEPALI = 0x39,      // 尼泊尔语
    FITCLOUDLANGUAGE_KAZAKH = 0x3a,      // 哈萨克语
    FITCLOUDLANGUAGE_GALICIAN = 0x3b,    // 加利西亚语
    FITCLOUDLANGUAGE_ICELANDIC = 0x3c,   // 冰岛语
    FITCLOUDLANGUAGE_KANNADA = 0x3d,     // 卡纳达语
    FITCLOUDLANGUAGE_KYRGYZ = 0x3e,      // 吉尔吉斯语
    FITCLOUDLANGUAGE_MALAYALAM = 0x3f,   // 马拉雅拉姆语

    FITCLOUDLANGUAGE_MARATHI = 0x40,    // 马拉提语/马拉地语
    FITCLOUDLANGUAGE_TAMIL = 0x41,      // 泰米尔语
    FITCLOUDLANGUAGE_MACEDONIAN = 0x42, // 马其顿语
    FITCLOUDLANGUAGE_TELUGU = 0x43,     // 泰卢固语
    FITCLOUDLANGUAGE_UZBEK = 0x44,      // 乌兹别克语
    FITCLOUDLANGUAGE_BASQUE = 0x45,     // 巴斯克语
    FITCLOUDLANGUAGE_BERBER = 0x46,     // 僧伽罗语 (斯里兰卡)
    FITCLOUDLANGUAGE_ALBANIAN = 0x47,   // 阿尔巴尼亚语
    FITCLOUDLANGUAGE_HAUSA = 0x48,      // 豪萨语

};

#pragma mark - 闹钟相关

/// 闹钟周期定义
///
/// 定义了闹钟的重复周期选项，可以设置闹钟在一周内的哪些天重复
typedef NS_OPTIONS(Byte, FITCLOUDALARMCYCLE) {
    /// 不循环，仅当天有效
    FITCLOUDALARMCYCLE_NONE = 0,
    /// 周一 (循环)
    FITCLOUDALARMCYCLE_MON = 1,
    /// 周二 (循环)
    FITCLOUDALARMCYCLE_TUE = 1 << 1,
    /// 周三 (循环)
    FITCLOUDALARMCYCLE_WED = 1 << 2,
    /// 周四 (循环)
    FITCLOUDALARMCYCLE_THUR = 1 << 3,
    /// 周五 (循环)
    FITCLOUDALARMCYCLE_FRI = 1 << 4,
    /// 周六 (循环)
    FITCLOUDALARMCYCLE_SAT = 1 << 5,
    /// 周日 (循环)
    FITCLOUDALARMCYCLE_SUN = 1 << 6,
};

#pragma mark - 日程相关

/// 日程定义
///
/// 定义了不同类型的日程选项，用于设置和管理日程提醒
typedef NS_OPTIONS(Byte, FITCLOUDSCHEDULE) {
    /// 喝水提醒
    FITCLOUDSCHEDULE_DRINK = 0,
    /// 闹钟提醒
    FITCLOUDSCHEDULE_ALARM = 1,
    /// 久坐提醒
    FITCLOUDSCHEDULE_SEDENTARY = 2,
    /// 刷牙提醒
    FITCLOUDSCHEDULE_TEETHBRUSH = 3,
    /// 早餐提醒
    FITCLOUDSCHEDULE_BREAKFAST = 4,
    /// 家庭作业提醒
    FITCLOUDSCHEDULE_HOMEWORK = 5,
    /// 午餐提醒
    FITCLOUDSCHEDULE_LUNCH = 6,
    /// 运动提醒
    FITCLOUDSCHEDULE_SPORTS = 7,
    /// 起床提醒
    FITCLOUDSCHEDULE_GETUP = 8,
    /// 睡觉提醒
    FITCLOUDSCHEDULE_GOTOBED = 9,
    /// 上学提醒
    FITCLOUDSCHEDULE_GOTOSCHOOL = 10,
    /// 回家提醒
    FITCLOUDSCHEDULE_GOHOME = 11,
    /// 阅读提醒
    FITCLOUDSCHEDULE_READ = 12,
    /// 洗澡提醒
    FITCLOUDSCHEDULE_BATH = 13,
    /// 聚会提醒
    FITCLOUDSCHEDULE_PARTY = 14,
    /// 游戏提醒
    FITCLOUDSCHEDULE_GAME = 15,
    /// 露营提醒
    FITCLOUDSCHEDULE_CAMP = 16,
    /// 音乐提醒
    FITCLOUDSCHEDULE_MUSIC = 17,
    /// 绘画提醒
    FITCLOUDSCHEDULE_DRAW = 18,
    /// 跳舞提醒
    FITCLOUDSCHEDULE_DANCE = 19,
    /// 摄影提醒
    FITCLOUDSCHEDULE_PHOTOGRAPHY = 20,
    /// 遛狗提醒
    FITCLOUDSCHEDULE_WALKTHEDOG = 21,
    /// 电影提醒
    FITCLOUDSCHEDULE_MOVIE = 22,
};

/// 定义日程的循环周期
///
/// 使用位掩码来表示一周中的不同日期组合。可以通过按位或运算组合多个日期。
typedef NS_OPTIONS(Byte, FITCLOUDSCHEDULECYCLE) {
    /// 不循环，仅当天有效
    FITCLOUDSCHEDULECYCLE_NONE = 0,
    /// 周一循环
    FITCLOUDSCHEDULECYCLE_MON = 1,
    /// 周二循环
    FITCLOUDSCHEDULECYCLE_TUE = 1 << 1,
    /// 周三循环
    FITCLOUDSCHEDULECYCLE_WED = 1 << 2,
    /// 周四循环
    FITCLOUDSCHEDULECYCLE_THUR = 1 << 3,
    /// 周五循环
    FITCLOUDSCHEDULECYCLE_FRI = 1 << 4,
    /// 周六循环
    FITCLOUDSCHEDULECYCLE_SAT = 1 << 5,
    /// 周日循环
    FITCLOUDSCHEDULECYCLE_SUN = 1 << 6,
};

#pragma mark - 任务相关

/// 任务定义
///
/// 定义了不同类型的任务选项，用于设置和管理任务提醒
typedef NS_OPTIONS(Byte, FITCLOUDTASK) {
    /// 喝水任务
    FITCLOUDTASK_DRINK = 0,
    /// 闹钟任务
    FITCLOUDTASK_ALARM = 1,
    /// 久坐任务
    FITCLOUDTASK_SEDENTARY = 2,
    /// 刷牙任务
    FITCLOUDTASK_TEETHBRUSH = 3,
    /// 早餐任务
    FITCLOUDTASK_BREAKFAST = 4,
    /// 家庭作业任务
    FITCLOUDTASK_HOMEWORK = 5,
    /// 午餐任务
    FITCLOUDTASK_LUNCH = 6,
    /// 运动任务
    FITCLOUDTASK_SPORTS = 7,
    /// 起床任务
    FITCLOUDTASK_GETUP = 8,
    /// 睡觉任务
    FITCLOUDTASK_GOTOBED = 9,
    /// 上学任务
    FITCLOUDTASK_GOTOSCHOOL = 10,
    /// 回家任务
    FITCLOUDTASK_GOHOME = 11,
    /// 阅读任务
    FITCLOUDTASK_READ = 12,
    /// 洗澡任务
    FITCLOUDTASK_BATH = 13,
    /// 聚会任务
    FITCLOUDTASK_PARTY = 14,
    /// 游戏任务
    FITCLOUDTASK_GAME = 15,
    /// 露营任务
    FITCLOUDTASK_CAMP = 16,
    /// 音乐任务
    FITCLOUDTASK_MUSIC = 17,
    /// 绘画任务
    FITCLOUDTASK_DRAW = 18,
    /// 跳舞任务
    FITCLOUDTASK_DANCE = 19,
    /// 摄影任务
    FITCLOUDTASK_PHOTOGRAPHY = 20,
    /// 遛狗任务
    FITCLOUDTASK_WALKTHEDOG = 21,
    /// 电影任务
    FITCLOUDTASK_MOVIE = 22,
};

/// 定义任务的循环周期
///
/// 使用位掩码来表示一周中的不同日期组合。可以通过按位或运算组合多个日期。
typedef NS_OPTIONS(Byte, FITCLOUDTASKCYCLE) {
    /// 不循环，仅当天有效
    FITCLOUDTASKCYCLE_NONE = 0,
    /// 周一循环
    FITCLOUDTASKCYCLE_MON = 1,
    /// 周二循环
    FITCLOUDTASKCYCLE_TUE = 1 << 1,
    /// 周三循环
    FITCLOUDTASKCYCLE_WED = 1 << 2,
    /// 周四循环
    FITCLOUDTASKCYCLE_THUR = 1 << 3,
    /// 周五循环
    FITCLOUDTASKCYCLE_FRI = 1 << 4,
    /// 周六循环
    FITCLOUDTASKCYCLE_SAT = 1 << 5,
    /// 周日循环
    FITCLOUDTASKCYCLE_SUN = 1 << 6,
};

/// 任务状态定义
///
/// 定义任务在不同阶段的状态
typedef NS_ENUM(Byte, FITCLOUDTASKSTATUS) {
    /// 待开始
    FITCLOUDTASKSTATUS_TOBESTARTED = 0,
    /// 进行中
    FITCLOUDTASKSTATUS_INPROGRESS = 1,
    /// 已完成
    FITCLOUDTASKSTATUS_DONE = 2,
};

#pragma mark - 习惯相关

/// 习惯循环定义
///
/// 使用位掩码来表示一周中的不同日期组合。可以通过按位或运算组合多个日期。
typedef NS_OPTIONS(Byte, FITCLOUDHABITCYCLE) {
    /// 不循环，仅当天有效
    FITCLOUDHABITCYCLE_NONE = 0,
    /// 周一 (循环)
    FITCLOUDHABITCYCLE_MON = 1,
    /// 周二 (循环)
    FITCLOUDHABITCYCLE_TUE = 1 << 1,
    /// 周三 (循环)
    FITCLOUDHABITCYCLE_WED = 1 << 2,
    /// 周四 (循环)
    FITCLOUDHABITCYCLE_THUR = 1 << 3,
    /// 周五 (循环)
    FITCLOUDHABITCYCLE_FRI = 1 << 4,
    /// 周六 (循环)
    FITCLOUDHABITCYCLE_SAT = 1 << 5,
    /// 周日 (循环)
    FITCLOUDHABITCYCLE_SUN = 1 << 6,
};

/// 习惯一周内达标情况定义
///
/// 使用位掩码来表示一周内每天的达标情况。可以通过按位或运算组合多个达标日期。
typedef NS_OPTIONS(Byte, FITCLOUDHABITACHIEVEMENT) {
    /// 不达标
    FITCLOUDHABITACHIEVEMENT_NONE = 0,
    /// 上周日达标
    FITCLOUDHABITACHIEVEMENT_LAST_SUN = 1,
    /// 本周一达标
    FITCLOUDHABITACHIEVEMENT_MON = 1 << 1,
    /// 本周二达标
    FITCLOUDHABITACHIEVEMENT_TUE = 1 << 2,
    /// 本周三达标
    FITCLOUDHABITACHIEVEMENT_WED = 1 << 3,
    /// 本周四达标
    FITCLOUDHABITACHIEVEMENT_THUR = 1 << 4,
    /// 本周五达标
    FITCLOUDHABITACHIEVEMENT_FRI = 1 << 5,
    /// 本周六达标
    FITCLOUDHABITACHIEVEMENT_SAT = 1 << 6,
    /// 本周日达标
    FITCLOUDHABITACHIEVEMENT_SUN = 1 << 7,
};

/// 习惯关联功能定义
///
/// 定义习惯可以关联的功能类型
typedef NS_ENUM(Byte, FITCLOUDHABITASSOCIATEDFEATURE) {
    /// 无关联
    FITCLOUDHABITASSOCIATEDFEATURE_NONE = 0,
    /// 运动
    FITCLOUDHABITASSOCIATEDFEATURE_SPORTS = 1,
};

/// 习惯状态定义
///
/// 定义习惯在不同阶段的状态
typedef NS_ENUM(Byte, FITCLOUDHABITSTATUS) {
    /// 待开始
    FITCLOUDHABITSTATUS_TOBESTARTED = 0,
    /// 进行中
    FITCLOUDHABITSTATUS_INPROGRESS = 1,
    /// 已完成
    FITCLOUDHABITSTATUS_DONE = 2,
    /// 已逾期
    FITCLOUDHABITSTATUS_OVERDUE = 3,
    /// 已关闭
    FITCLOUDHABITSTATUS_CLOSED = 4,
    /// 已删除
    FITCLOUDHABITSTATUS_REMOVED = 5,
};

/// 习惯名称规则定义
///
/// 定义习惯名称的来源类型
typedef NS_ENUM(Byte, FITCLOUDHABITNAMERULE) {
    /// 自定义
    FITCLOUDHABITNAMERULE_CUSTOM = 0,
    /// 运动
    FITCLOUDHABITNAMERULE_SPORTS = 1,
    /// 学习
    FITCLOUDHABITNAMERULE_STUDY = 2,
    /// 睡眠
    FITCLOUDHABITNAMERULE_SLEEP = 3,
};

#pragma mark - 用户相关

/// 性别定义
///
/// 定义用户性别类型
typedef NS_ENUM(Byte, FITCLOUDGENDER) {
    /// 女性
    FITCLOUDGENDER_FEMALE = 0,
    /// 男性
    FITCLOUDGENDER_MALE = 1,
};

/// 用户绑定状态定义
///
/// 定义用户绑定设备过程中的各种状态
typedef NS_ENUM(NSInteger, FITCLOUDUSERBINDSTATUS) {
    /// 未绑定
    FITCLOUDUSERBINDSTATUS_NONE = 0,
    /// 绑定中
    FITCLOUDUSERBINDSTATUS_BINDING = 1,
    /// 绑定成功
    FITCLOUDUSERBINDSTATUS_SUCCESS = 2,
    /// 绑定失败
    FITCLOUDUSERBINDSTATUS_FAILURE = 3,
    /// 解绑中
    FITCLOUDUSERBINDSTATUS_UNBINDING = 4,
    /// 被踢出
    FITCLOUDUSERBINDSTATUS_KICKEDOUT = 5,
};

#pragma mark - 睡眠

/// 睡眠质量定义
///
/// 定义睡眠过程中的各种质量状态
typedef NS_ENUM(Byte, FITCLOUDSLEEPQUALITY) {
    /// 深睡/熟睡
    FITCLOUDSLEEPQUALITY_DEEP = 0x01,
    /// 浅睡眠/躺在床上
    FITCLOUDSLEEPQUALITY_LIGHT = 0x02,
    /// 清醒
    FITCLOUDSLEEPQUALITY_AWAKE = 0x03,
    /// 快速眼动
    FITCLOUDSLEEPQUALITY_REM = 0x04,
};

#pragma mark - APP相机控制相关

/// APP 相机状态定义
///
/// 定义 APP 相机的前台/后台状态
typedef NS_ENUM(Byte, APPCAMERASTATE) {
    /// 前台
    APPCAMERASTATE_FOREGROUND = 0x00,
    /// 后台
    APPCAMERASTATE_BACKGROUND = 0x01,
};

#pragma mark - 女性健康

/// 女性健康模式定义
///
/// 定义女性健康相关的各种模式
typedef NS_ENUM(Byte, WOMENHEALTHMODE) {
    /// 关闭
    WOMENHEALTHMODE_OFF = 0x00,
    /// 经期模式
    WOMENHEALTHMODE_MENSES = 0x01,
    /// 备孕模式
    WOMENHEALTHMODE_PREGNANCY_PREPARE = 0x02,
    /// 怀孕模式
    WOMENHEALTHMODE_PREGNANCY = 0x03,
};

/// 怀孕期提醒方式定义
///
/// 定义怀孕期的不同提醒方式
typedef NS_ENUM(Byte, PREGNANCYREMINDTYPE) {
    /// 已怀孕天数
    PREGNANCYREMINDTYPE_PREGNANTDAYS = 0,
    /// 距离预产期天数
    PREGNANCYREMINDTYPE_DAYSBEFOREEDC = 1,
};

#pragma mark - App定位服务相关

/// App 定位服务状态定义
///
/// 定义 App 定位服务的各种状态
typedef NS_ENUM(Byte, APPLOCATIONSERVICESTATE) {
    /// 正常
    APPLOCATIONSERVICESTATE_AVAILABLE = 0x00,
    /// APP 定位权限受限
    APPLOCATIONSERVICESTATE_RESTRICTED = 0x01,
    /// 手机定位功能未开启
    APPLOCATIONSERVICESTATE_DISABLEDWITHIOS = 0x02,
};

#pragma mark - Alexa

/// Alexa 校验错误定义
///
/// 定义 Alexa 校验过程中的各种错误类型
typedef NS_ENUM(Byte, ALEXACHECKERROR) {
    /// VoiceId 不匹配
    ALEXACHECKERROR_VOICEIDNOTMATCH = 0x00,
    /// 长度校验失败
    ALEXACHECKERROR_BADLENGTH = 0x01,
    /// CRC 校验失败
    ALEXACHECKERROR_CRC = 0x02,
};

/// Alexa 调用错误定义
///
/// 定义 Alexa 调用过程中的各种错误类型
typedef NS_ENUM(Byte, ALEXAINVOKEERROR) {
    /// 成功
    ALEXAINVOKEERROR_SUCCESS = 0x00,
    /// 该国家或者语言不支持 Alexa
    ALEXAINVOKEERROR_REGIONNOTSUPPORT = 0x01,
    /// 无网络
    ALEXAINVOKEERROR_NETWORKOFFLINE = 0x02,
    /// 未授权
    ALEXAINVOKEERROR_NOTAUTHED = 0x03,
    /// APP 不支持
    ALEXAINVOKEERROR_APPNOTIMPLEMENTED = 0xFE,
    /// 未知错误
    ALEXAINVOKEERROR_UNKOWN = 0xFF,
};

/// Alexa 结果类型定义
///
/// 定义 Alexa 返回的结果类型
typedef NS_ENUM(Byte, ALEXARESULTTYPE) {
    /// 普通文本
    ALEXARESULTTYPE_TEXT = 0x00,
    /// 指令
    ALEXARESULTTYPE_DIRECTIVE = 0x01,
};

#pragma mark - 大模型

/// LLM 结果类型
typedef NS_ENUM(NSInteger, LLMRESULTTYPE) {
    /// APP 自行生成的错误文案
    LLMRESULTTYPE_ERRORTEXT = 0x00,
    /// 大模型大模型生成的文案
    LLMRESULTTYPE_LLMTEXT = 0x01,
};

/// LLM 类型
typedef NS_ENUM(NSInteger, LLMTYPE) {
    /// 无
    LLMTYPE_NONE = -1,
    /// ChatGPT
    LLMTYPE_CHATGPT = 0,
    /// 文心一言
    LLMTYPE_ERNIEBOT = 1,
};

#pragma mark - 翻译

/// 翻译文本类型
typedef NS_ENUM(NSInteger, TRANSLATETEXTTYPE) {
    /// 原文
    TRANSLATETEXTTYPE_ORIGINAL = 0x00,
    /// 译文
    TRANSLATETEXTTYPE_TRANSLATION = 0x01,
};

/// Represents the playing state of translation voice.
///
/// This enumeration defines the possible states for translation voice playback:
/// - Stop: The voice playback is stopped
/// - Playing: The voice is currently playing
/// - Pause: The voice playback is paused
/// - Resumed: The voice playback has resumed from pause
typedef NS_ENUM(NSInteger, TranslatedTextVoicePlayingState) {
    /// Voice playing state is unknown
    TranslatedTextVoicePlayingStateUnknown = -1,
    /// Voice playback is stopped
    TranslatedTextVoicePlayingStateStop = 0x00,
    /// Voice is currently playing
    TranslatedTextVoicePlayingStatePlaying = 0x01,
    /// Voice playback is paused
    TranslatedTextVoicePlayingStatePause = 0x02,
    /// Voice playback has resumed from pause
    TranslatedTextVoicePlayingStateResumed = 0x03,
};

#pragma mark - 表盘相关

/// 表盘位类型
typedef NS_ENUM(Byte, WATCHFACESLOTTYPE) {
    WATCHFACESLOTTYPE_BUILTIN = 0x00,                // 当前表盘位置为内置，不可推送的
    WATCHFACESLOTTYPE_ALLOWPUSH = 0x10,              // 当前表盘位置可推送表盘，可根据表盘编号获取缩略图显示
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE1 = 0x20, // 当前表盘位置可推送表盘，缩略图显示自定义表盘样式 1
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE2 = 0x21, // 当前表盘位置可推送表盘，缩略图显示自定义表盘样式 2
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE3 = 0x22, // 当前表盘位置可推送表盘，缩略图显示自定义表盘样式 3
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE4 = 0x23, // 当前表盘位置可推送表盘，缩略图显示自定义表盘样式 4
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE5 = 0x24, // 当前表盘位置可推送表盘，缩略图显示自定义表盘样式 5
};

/// 表盘模块样式
typedef NS_ENUM(Byte, WATCHFACEMODULESTYLE) {
    WATCHFACEMODULESTYLE_1 = 0x00,
    WATCHFACEMODULESTYLE_2 = 0x01,
    WATCHFACEMODULESTYLE_3 = 0x02,
    WATCHFACEMODULESTYLE_4 = 0x03,
    WATCHFACEMODULESTYLE_5 = 0x04,
    WATCHFACEMODULESTYLE_6 = 0x05,
    WATCHFACEMODULESTYLE_7 = 0x06,
    WATCHFACEMODULESTYLE_INVALID = 0x07,
};

#pragma mark - 游戏相关

/// 游戏类型定义
///
/// 定义了手表支持的各种游戏类型
typedef NS_ENUM(Byte, FITCLOUDGAME) {
    /// 宠物养成类游戏
    FITCLOUDGAME_PETDEV = 0,
    /// 2048 数字游戏
    FITCLOUDGAME_2048 = 1,
    /// 糖果消消乐游戏
    FITCLOUDGAME_CANDY = 2,
    /// 拼图游戏
    FITCLOUDGAME_PICTUREPUZZLE = 3,
    /// 飞机射击游戏
    FITCLOUDGAME_PLANE = 4,
    /// 赛车竞速游戏
    FITCLOUDGAME_RACINGCAR = 5,
    /// 迷宫探索游戏
    FITCLOUDGAME_MAZE = 6,
    /// 篮球投篮游戏
    FITCLOUDGAME_BASKETBALL = 7,
    /// 算术题练习游戏
    FITCLOUDGAME_ARITHMETIC = 8,
    /// 俄罗斯方块游戏
    FITCLOUDGAME_TETRIS = 9,
    /// 数独益智游戏
    FITCLOUDGAME_SUDOKU = 10,
    /// 答题挑战游戏
    FITCLOUDGAME_ANSWER = 11,
};

/// 游戏锁操作定义
typedef NS_ENUM(Byte, FITCLOUDGAMEPASSCODEOP) {
    /// 取消
    FITCLOUDGAMEPASSCODEOP_CANCEL = 0x00,
    /// 设置
    FITCLOUDGAMEPASSCODEOP_SET = 0x01,
};

/// 游戏锁操作结果定义
typedef NS_ENUM(Byte, FITCLOUDGAMEPASSCODEOPRESULT) {
    /// 成功
    FITCLOUDGAMEPASSCODEOPRESULT_SUCCESS = 0x00,
    /// 失败
    FITCLOUDGAMEPASSCODEOPRESULT_FAILURE = 0x01,
};

/// 游戏排名趋势
typedef NS_ENUM(Byte, FITCLOUDGAMERANDINGTREND) {
    /// 下降
    FITCLOUDGAMERANDINGTREND_DECLINE = 0x00,
    /// 排名和上次一样
    FITCLOUDGAMERANDINGTREND_SAME = 0x01,
    /// 上升
    FITCLOUDGAMERANDINGTREND_ASCEND = 0x02,
};

#pragma mark -手表GPS互联实时运动相关

/// 手表 GPS 互联实时运动定义
typedef NS_ENUM(UInt16, FITCLOUDSPORTSWITHGPS) {
    /// 无运动
    FITCLOUDSPORTSWITHGPS_NONE = 0x00,
    /// 步行
    FITCLOUDSPORTSWITHGPS_WALKING = 0x10,
    /// 跑步
    FITCLOUDSPORTSWITHGPS_RUNNING = 0x08,
    /// 登山
    FITCLOUDSPORTSWITHGPS_CLIMBING = 0x14,
    /// 骑行
    FITCLOUDSPORTSWITHGPS_BICYCLING = 0x04,
    /// 徒步
    FITCLOUDSPORTSWITHGPS_HIKING = 0x88,
    /// 越野跑
    FITCLOUDSPORTSWITHGPS_TRAIL_RUNNING = 0x9C,
    /// 马拉松
    FITCLOUDSPORTSWITHGPS_MARATHON = 0x01D0,
};

/// 手表 GPS 互联实时运动行为定义
typedef NS_ENUM(Byte, FITCLOUDSPORTSWITHGPSACTION) {
    /// 结束
    FITCLOUDSPORTSWITHGPSACTION_STOP = 0x00,
    /// 开始
    FITCLOUDSPORTSWITHGPSACTION_START = 0x01,
    /// 暂停
    FITCLOUDSPORTSWITHGPSACTION_PAUSE = 0x02,
    /// 恢复
    FITCLOUDSPORTSWITHGPSACTION_RESUME = 0x03,
};

/// 手表 GPS 互联实时运动状态定义
typedef NS_ENUM(Byte, FITCLOUDSPORTSWITHGPSSTATUS) {
    /// 结束
    FITCLOUDSPORTSWITHGPSSTATUS_STOP = 0x00,
    /// 进行中
    FITCLOUDSPORTSWITHGPSSTATUS_INPROCESS = 0x01,
    /// 暂停
    FITCLOUDSPORTSWITHGPSSTATUS_PAUSE = 0x02,
};

/// 手表 GPS 互联实时运动启动方式定义
typedef NS_ENUM(Byte, FITCLOUDSPORTSWITHGPSSTARTFROM) {
    /// 由 APP 启动
    FITCLOUDSPORTSWITHGPSSTARTFROM_APP = 0x01,
    /// 由手表启动
    FITCLOUDSPORTSWITHGPSSTARTFROM_WATCH = 0x02,
};

#pragma mark -收款码和名片二维码类型定义

/// 收款码和名片二维码类型定义
typedef NS_ENUM(Byte, FITCLOUDQRCODE) {
    /// 微信收款码
    FITCLOUDQRCODE_MONEYRECEIVE_WECHAT = 0x01,
    /// 支付宝收款码
    FITCLOUDQRCODE_MONEYRECEIVE_ALIPAY = 0x02,
    /// PayPal 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_PAYPAL = 0x03,
    /// QQ 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_QQ = 0x04,
    /// Paytm 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_PAYTM = 0x05,
    /// PhonePe 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_PHONEPE = 0x06,
    /// GPay 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_GPAY = 0x07,
    /// BHTM 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_BHIM = 0x08,
    /// Momo 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_MOMO = 0x09,
    /// Zalo 收款码
    FITCLOUDQRCODE_MONEYRECEIVE_ZALO = 0x0A,
    /// 微信名片
    FITCLOUDQRCODE_BUSINESSCARD_WECHAT = 0x21,
    /// 支付宝名片
    FITCLOUDQRCODE_BUSINESSCARD_ALIPAY = 0x22,
    /// QQ 名片
    FITCLOUDQRCODE_BUSINESSCARD_QQ = 0x23,
    /// Facebook 名片
    FITCLOUDQRCODE_BUSINESSCARD_FACEBOOK = 0x24,
    /// WhatsApp 名片
    FITCLOUDQRCODE_BUSINESSCARD_WHATSAPP = 0x25,
    /// Twitter 名片
    FITCLOUDQRCODE_BUSINESSCARD_TWITTER = 0x26,
    /// Instagram 名片
    FITCLOUDQRCODE_BUSINESSCARD_INSTAGRAM = 0x27,
    /// Messenger 名片
    FITCLOUDQRCODE_BUSINESSCARD_MESSENGER = 0x28,
    /// LINE 名片
    FITCLOUDQRCODE_BUSINESSCARD_LINE = 0x29,
    /// Snapchat 名片
    FITCLOUDQRCODE_BUSINESSCARD_SNAPCHAT = 0x2A,
    /// Skype 名片
    FITCLOUDQRCODE_BUSINESSCARD_SKYPE = 0x2B,
    /// Email 名片
    FITCLOUDQRCODE_BUSINESSCARD_EMAIL = 0x2C,
    /// Phone 名片
    FITCLOUDQRCODE_BUSINESSCARD_PHONE = 0x2D,
    /// LinkedIn 名片
    FITCLOUDQRCODE_BUSINESSCARD_LINKEDIN = 0x2E,
    /// 核酸码
    FITCLOUDQRCODE_NUCLEICACID_CODE = 0x80,
};

#pragma mark -第三方外设

/// 第三方外设类型定义
typedef NS_ENUM(Byte, THIRDPARTYPERIPHERAL) {
    /// 血糖仪
    THIRDPARTYPERIPHERAL_BLOODGLUCOSEMETER = 0x01,
};

#pragma mark -第三方外设操作

/// 第三方外设操作定义
typedef NS_ENUM(Byte, THIRDPARTYPERIPHERALACTION) {
    /// 停止
    THIRDPARTYPERIPHERALACTION_STOP = 0x00,
    /// 启动
    THIRDPARTYPERIPHERALACTION_START = 0x01,
    /// 暂停
    THIRDPARTYPERIPHERALACTION_PAUSE = 0x02,
    /// 恢复
    THIRDPARTYPERIPHERALACTION_RESUME = 0x03,
};

#pragma mark -第三方外设操作结果

/// 第三方外设操作结果定义
typedef NS_ENUM(Byte, THIRDPARTYPERIPHERALACTIONRESULT) {
    /// 成功
    THIRDPARTYPERIPHERALACTIONRESULT_SUCCESS = 0x00,
    /// 设备不存在
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICENOTEXIST = 0x01,
    /// 设备不支持
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICENOTSUPPORT = 0x02,
    /// 设备离线或超时
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICEOFFLINEORTIMEOUT = 0x03,
    /// 设备忙
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICEBUSY = 0x04,
    /// 设备汇报了未指定的错误
    THIRDPARTYPERIPHERALACTIONRESULT_UNKNOWN = 0xff,
};

#pragma mark -数据同步选项

/// 数据同步选项定义
typedef NS_ENUM(Byte, FITCLOUDDATASYNCOPTION) {
    /// 旧的同步方式
    FITCLOUDDATASYNCOPTION_LEGACY = 0x00,
    /// 仅同步手表手动测量的
    FITCLOUDDATASYNCOPTION_MANUALATWATCHONLY = 0x01,
    /// 全部
    FITCLOUDDATASYNCOPTION_ALL = 0x02,
};

#pragma mark -手表启动震动时长

/// 手表启动震动时长定义
typedef NS_ENUM(Byte, FITCLOUDWATCHLAUNCHVIBRATEDURATION) {
    /// 单次快短震
    FITCLOUDWATCHLAUNCHVIBRATEDURATION_EXTRASHORT = 0x00,
    /// 单次长短震
    FITCLOUDWATCHLAUNCHVIBRATEDURATION_SHORT = 0x01,
    /// 周期 2s 的震动 (震 0.6s 停 1.4s)
    FITCLOUDWATCHLAUNCHVIBRATEDURATION_CYCLE = 0x02,
};

#pragma mark -手表上的GPS文件状态

/// 手表上的 GPS 文件状态定义
typedef NS_ENUM(SInt8, FITCLOUDWATCHGPSFILESTATE) {
    /// 未知状态
    FITCLOUDWATCHGPSFILESTATE_UNKNOWN = -1,
    /// 当前手表上没有 GPS 文件
    FITCLOUDWATCHGPSFILESTATE_NOTEXIST = 0,
    /// 良好
    FITCLOUDWATCHGPSFILESTATE_GOOD = 1,
    /// 未过期，但需要更新
    FITCLOUDWATCHGPSFILESTATE_NEEDUPDATE = 2,
    /// 已过期
    FITCLOUDWATCHGPSFILESTATE_OUTDATED = 3,
};

#pragma mark -GPS file vendor

/// Represents different GPS file vendors supported by the device.
///
/// This enumeration defines the GPS file vendors that can provide GPS assistance data
/// for the device's location services.
typedef NS_ENUM(NSInteger, FITCLOUDGPSFILEVENDOR) {
    /// Unknown GPS file vendor
    /// - Note: Indicates an unknown GPS file vendor
    FITCLOUDGPSFILEVENDOR_UNKNOWN = -1,
    /// The Airoha GPS file vendor (洛达)
    /// - Note: Provides GPS assistance data in Airoha's proprietary format
    FITCLOUDGPSFILEVENDOR_AIROHA = 0x00,

    /// The ICOE GPS file vendor (芯与物)
    /// - Note: Provides GPS assistance data in ICOE's proprietary format
    FITCLOUDGPSFILEVENDOR_ICOE = 0x01,
};

#pragma mark -勋章成就等级

/// 勋章成就等级定义
typedef NS_ENUM(Byte, FITCLOUDMEDALACHIEVEMENTLEVEL) {
    /// 初级
    FITCLOUDMEDALACHIEVEMENTLEVEL_ELEMENTARY = 0,
    /// 月度挑战
    FITCLOUDMEDALACHIEVEMENTLEVEL_MONTHLYCHALLENGE = 1,
    /// 超越自我
    FITCLOUDMEDALACHIEVEMENTLEVEL_EXCEEDONESELF = 2,
    /// 里程碑
    FITCLOUDMEDALACHIEVEMENTLEVEL_MILESTONE = 3,
    /// 毅力大师
    FITCLOUDMEDALACHIEVEMENTLEVEL_PERSISTENCEMASTER = 4,
};

#pragma mark -导航信息

/// The map provider
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANMAPPROVIDER) {
    /// 百度地图 (Baidu Map)
    FITCLOUDROUTEPLANMAPPROVIDER_BAIDU = 1,

    /// 高德地图 (AMap)
    FITCLOUDROUTEPLANMAPPROVIDER_AMAP = 2,
};

/// The navigation type
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANNAVITYPE) {
    /// unknown
    FITCLOUDROUTEPLANNAVITYPE_UNKNOWN = 0x00,
    /// normal cycle
    FITCLOUDROUTEPLANNAVITYPE_NORMAL_CYCLE = 0x01,
    /// electric cycle
    FITCLOUDROUTEPLANNAVITYPE_ELECTRIC_CYCLE = 0x02,
    /// walking
    FITCLOUDROUTEPLANNAVITYPE_WALK = 0x03,
};

/// The guide kind
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANGUIDEKIND) {
    /// 无效，Invalid
    FITCLOUDROUTEPLANGUIDEKIND_INVALID = 0x00,
    /// 起点，Start
    FITCLOUDROUTEPLANGUIDEKIND_START = 0x01,
    /// 直行，Front
    FITCLOUDROUTEPLANGUIDEKIND_FRONT = 0x02,
    /// 右前方转弯，Right front
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT_FRONT = 0x03,
    /// 右转，Right
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT = 0x04,
    /// 右后方转弯，Right back
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT_BACK = 0x05,
    /// 左后方转弯，Left back
    FITCLOUDROUTEPLANGUIDEKIND_LEFT_BACK = 0x06,
    /// 左转，Left
    FITCLOUDROUTEPLANGUIDEKIND_LEFT = 0x07,
    /// 左前方转弯，Left front
    FITCLOUDROUTEPLANGUIDEKIND_LEFT_FRONT = 0x08,
    /// 左掉头，Left u-turn
    FITCLOUDROUTEPLANGUIDEKIND_LEFT_U_TURN = 0x09,
    /// 右掉头，Right u-turn
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT_U_TURN = 0x0A,
    /// 到达，Dest
    FITCLOUDROUTEPLANGUIDEKIND_DEST = 0x0B,
    /// 台阶楼梯，Stair
    FITCLOUDROUTEPLANGUIDEKIND_STAIR = 0x0C,
};

#pragma mark - 电子卡包

/// The electronic card operation
typedef NS_ENUM(NSInteger, FITCLOUDECARDOPERATION) {
    /// sort
    FITCLOUDECARDOPERATION_SORT = 0x01,
    /// delete
    FITCLOUDECARDOPERATION_DEL = 0x02,
};

#pragma mark - 数据展示项

/// the workout data item display
typedef NS_ENUM(NSInteger, WORKOUTDATAITEMDISPLAY) {
    /// 运动时长
    WORKOUTDATAITEMDISPLAY_DURATION = 1,
    /// 平均心率
    WORKOUTDATAITEMDISPLAY_AVG_BPM = 2,
    /// 累计步数
    WORKOUTDATAITEMDISPLAY_TOTAL_STEPS = 3,
    /// 运动距离
    WORKOUTDATAITEMDISPLAY_DISTANCE = 4,
    /// 消耗热量
    WORKOUTDATAITEMDISPLAY_CALORIES = 5,
    /// 平均速度
    WORKOUTDATAITEMDISPLAY_AVG_SPEED = 6,
    /// 平均配速
    WORKOUTDATAITEMDISPLAY_AVG_PACE = 7,
    /// 平均步频
    WORKOUTDATAITEMDISPLAY_AVG_STEP_CADENCE = 8,
    /// 平均步幅
    WORKOUTDATAITEMDISPLAY_AVG_STEP_STRIDE = 9,
    /// 累计爬升
    WORKOUTDATAITEMDISPLAY_TOTAL_CLIMBING = 10,
    /// 累计下降
    WORKOUTDATAITEMDISPLAY_TOTAL_DESCENT = 11,
    /// 游泳趟数
    WORKOUTDATAITEMDISPLAY_SWIM_LAPS = 12,
    /// 游泳划水次数
    WORKOUTDATAITEMDISPLAY_SWIM_STROKES = 13,
    /// 泳姿
    WORKOUTDATAITEMDISPLAY_SWIM_STYLE = 14,
    /// 游泳划水频率
    WORKOUTDATAITEMDISPLAY_SWIM_STROKEFREQ = 15,
    /// 游泳效率
    WORKOUTDATAITEMDISPLAY_SWIM_SWOLF = 16,
    /// 触发次数
    WORKOUTDATAITEMDISPLAY_TRIGGER_COUNT = 17,
    /// 触发频率
    WORKOUTDATAITEMDISPLAY_TRIGGERS_PER_MINUTE = 18,
    /// 中断次数
    WORKOUTDATAITEMDISPLAY_BREAK_COUNT = 19,
    /// 连续次数
    WORKOUTDATAITEMDISPLAY_CONSECUTIVE_COUNT = 20,
};

#pragma mark - 健康定时监测项定义

/// 健康定时监测项定义 (the fitcloud interval health monitoring item)
typedef NS_ENUM(NSInteger, FITCLOUDINTEVALHEALTHMONITORINGITEM) {
    /// 心率 (heart rate)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_HEARTRATE = 0x01,
    /// 血氧 (blood oxygen)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_BLOODOXYGEN = 0x02,
    /// 血压 (blood pressure)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_BLOODPRESSURE = 0x03,
    /// 体温 (body temperature)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_BODYTEMPERATURE = 0x04,
    /// 压力指数 (stress index)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_STRESSINDEX = 0x05,
};

#pragma mark - 消息通知定义

/// 消息通知定义
typedef NS_OPTIONS(UInt64, FITCLOUDMN) {
    /// 无消息通知
    FITCLOUDMN_NONE = 0,
    /// 电话通知
    FITCLOUDMN_CALL = 1,
    /// 短信通知
    FITCLOUDMN_SMS = 1 << 1,
    /// QQ 通知
    FITCLOUDMN_QQ = 1 << 2,
    /// 微信通知
    FITCLOUDMN_WECHAT = 1 << 3,
    /// Facebook 通知
    FITCLOUDMN_FACEBOOK = 1 << 4,
    /// Twitter 通知
    FITCLOUDMN_TWITTER = 1 << 5,
    /// LinkedIn 通知
    FITCLOUDMN_LINKEDIN = 1 << 6,
    /// Instagram 通知
    FITCLOUDMN_INSTAGRAM = 1 << 7,
    /// Pinterest 通知
    FITCLOUDMN_PINTEREST = 1 << 8,
    /// WhatsApp 通知
    FITCLOUDMN_WHATSAPP = 1 << 9,
    /// LINE 通知
    FITCLOUDMN_LINE = 1 << 10,
    /// Facebook Messenger 通知
    FITCLOUDMN_MESSENGER = 1 << 11,
    /// KakaoTalk 通知
    FITCLOUDMN_KAKAO = 1 << 12,
    /// Skype 通知
    FITCLOUDMN_SKYPE = 1 << 13,
    /// 邮箱通知
    FITCLOUDMN_MAIL = 1 << 14,
    /// Telegram 通知
    FITCLOUDMN_TELEGRAM = 1 << 15,
    /// Viber 通知
    FITCLOUDMN_VIBER = 1 << 16,
    /// 日历消息通知
    FITCLOUDMN_CALENDAR = 1 << 17,
    /// Snapchat 通知
    FITCLOUDMN_SNAPCHAT = 1 << 18,
    /// Hike 通知
    FITCLOUDMN_HIKE = 1 << 19,
    /// YouTube 通知
    FITCLOUDMN_YOUTUBE = 1 << 20,
    /// Apple Music 通知
    FITCLOUDMN_APPLEMUSIC = 1 << 21,
    /// Zoom 通知
    FITCLOUDMN_ZOOM = 1 << 22,
    /// TikTok 通知
    FITCLOUDMN_TIKTOK = 1 << 23,
    /// Gmail 通知
    FITCLOUDMN_GMAIL = 1 << 24,
    /// Outlook 通知
    FITCLOUDMN_OUTLOOK = 1 << 25,
    /// WhatsApp Business 通知
    FITCLOUDMN_WHATSUPBUSINESS = 1 << 26,
    /// Fastrack 通知
    FITCLOUDMN_FASTRACK = 1 << 27,
    /// Titan Smart World 通知
    FITCLOUDMN_TITANSMARTWORLD = 1 << 28,
    /// Google Pay 通知
    FITCLOUDMN_GPAY = 1 << 29,
    /// Amazon 通知
    FITCLOUDMN_AMAZON = 1 << 30,
    /// 其他 APP 通知
    FITCLOUDMN_OTHER = ((UInt64)1) << 31,
    /// PhonePe 通知
    FITCLOUDMN_PHONEPE = ((UInt64)1) << 32,
    /// Hinge 通知
    FITCLOUDMN_HINGE = ((UInt64)1) << 33,
    /// Flipkart 通知
    FITCLOUDMN_FLIPKART = ((UInt64)1) << 34,
    /// Myntra 通知
    FITCLOUDMN_MYNTRA = ((UInt64)1) << 35,
    /// Meesho 通知
    FITCLOUDMN_MEESHO = ((UInt64)1) << 36,
    /// Zivame 通知
    FITCLOUDMN_ZIVAME = ((UInt64)1) << 37,
    /// Ajio 通知
    FITCLOUDMN_AJIO = ((UInt64)1) << 38,
    /// Urbanic 通知
    FITCLOUDMN_URBANIC = ((UInt64)1) << 39,
    /// Nykaa 通知
    FITCLOUDMN_NYKAA = ((UInt64)1) << 40,
    /// Healthifyme 通知
    FITCLOUDMN_HEALTHIFYME = ((UInt64)1) << 41,
    /// Cultfit 通知
    FITCLOUDMN_CULTFIT = ((UInt64)1) << 42,
    /// Flo 通知
    FITCLOUDMN_FLO = ((UInt64)1) << 43,
    /// Bumble 通知
    FITCLOUDMN_BUMBLE = ((UInt64)1) << 44,
    /// Uber 通知
    FITCLOUDMN_UBER = ((UInt64)1) << 45,
    /// Swiggy 通知
    FITCLOUDMN_SWIGGY = ((UInt64)1) << 46,
    /// Zomato 通知
    FITCLOUDMN_ZOMATO = ((UInt64)1) << 47,
    /// Tira 通知
    FITCLOUDMN_TIRA = ((UInt64)1) << 48,
    /// Zalo 通知
    FITCLOUDMN_ZALO = ((UInt64)1) << 49,
    /// 钉钉通知
    FITCLOUDMN_DINGTALK = ((UInt64)1) << 50,
    /// 飞书通知
    FITCLOUDMN_FEISHU = ((UInt64)1) << 51,
    /// Microsoft Teams 通知
    FITCLOUDMN_TEAMS = ((UInt64)1) << 52,
    /// Google Play 通知
    FITCLOUDMN_GOOGLEPLAY = ((UInt64)1) << 53,
    /// Google Drive 通知
    FITCLOUDMN_GOOGLEDRIVE = ((UInt64)1) << 54,
    /// JioHotstar 通知
    FITCLOUDMN_JIOHOTSTAR = ((UInt64)1) << 55,
    /// Paytm 通知
    FITCLOUDMN_PAYTM = ((UInt64)1) << 56,
};

#pragma mark - 内置个性化提醒定义(高级提醒)

/// 内置个性化提醒定义 (高级提醒)
typedef NS_ENUM(Byte, FITCLOUDBUILTINPERSONALIZEDREMINDER) {
    /// 久坐提醒
    FITCLOUDBUILTINPERSONALIZEDREMINDER_SEDENTARY = 0x00,

    /// 喝水提醒
    FITCLOUDBUILTINPERSONALIZEDREMINDER_WATERDRINK = 0x01,

    /// 吃药提醒
    FITCLOUDBUILTINPERSONALIZEDREMINDER_MEDICATION = 0x02,
};

/// 个性化提醒 (高级提醒) 类型
typedef NS_ENUM(NSInteger, FITCLOUDPERSONALIZEDREMINDERTYPE) {
    /// 未知
    FITCLOUDPERSONALIZEDREMINDERTYPE_UNKNOWN = 0x00,

    /// 内置
    FITCLOUDPERSONALIZEDREMINDERTYPE_BUILTIN = 0x01,

    /// 自定义
    FITCLOUDPERSONALIZEDREMINDERTYPE_CUSTOM = 0x02,
};

/// 个性化提醒 (高级提醒) 循环周期
typedef NS_OPTIONS(Byte, FITCLOUDPERSONALIZEDREMINDERCYCLE) {
    FITCLOUDPERSONALIZEDREMINDERCYCLE_NONE = 0,      // 不循环，仅当天有效
    FITCLOUDPERSONALIZEDREMINDERCYCLE_MON = 1,       // 周一 (循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_TUE = 1 << 1,  // 周二 (循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_WED = 1 << 2,  // 周三 (循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_THUR = 1 << 3, // 周四 (循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_FRI = 1 << 4,  // 周五 (循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_SAT = 1 << 5,  // 周六 (循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_SUN = 1 << 6,  // 周日 (循环)
};

/// 个性化提醒 (高级提醒) 时间类型
typedef NS_ENUM(Byte, FITCLOUDPERSONALIZEDREMINDTIMETYPE) {
    /// 时间段
    FITCLOUDPERSONALIZEDREMINDTIMETYPE_PERIOD = 0x00,
    /// 时间点
    FITCLOUDPERSONALIZEDREMINDTIMETYPE_MOMENT = 0x01,
};

#pragma mark - 情侣

/// lover message
typedef NS_ENUM(Byte, FITCLOUDLOVERMESSAGE) {
    /// I Miss you
    FITCLOUDLOVERMESSAGE_IMISSYOU = 0x01,
};

/// the lovers bonding notification
typedef NS_ENUM(NSInteger, FITCLOUDLOVERSBONDINGNOTIFICATION) {
    /// bonding success
    FITCLOUDLOVERSBONDINGNOTIFICATION_BONDINGSUCCESS = 0x01,
    /// bonding cancelled
    FITCLOUDLOVERSBONDINGNOTIFICATION_BONDINGCANCELLED = 0x02,
};

/// the lovers message send result
typedef NS_ENUM(NSInteger, FITCLOUDLOVERSMESSAGESENDRESULT) {
    /// send failed
    FITCLOUDLOVERSMESSAGESENDRESULT_FAILED = 0x00,
    /// send succeed
    FITCLOUDLOVERSMESSAGESENDRESULT_SUCCEED = 0x01,
    /// send failed, no bonding
    FITCLOUDLOVERSMESSAGESENDRESULT_NOBONDING = 0x02,
};

#pragma mark - 天气

/// 天气类型
typedef NS_ENUM(Byte, FITCLOUDWEATHERTYPE) {
    /// 晴天
    FITCLOUDWEATHERTYPE_SUNNY = 0x01,
    /// 多云
    FITCLOUDWEATHERTYPE_CLOUDY = 0x02,
    /// 阴天
    FITCLOUDWEATHERTYPE_OVERCAST = 0x03,
    /// 阵雨
    FITCLOUDWEATHERTYPE_SHOWERS = 0x04,
    /// 雷阵雨、雷阵雨伴有冰雹
    FITCLOUDWEATHERTYPE_THUNDERSHOWERSWITHHAIL = 0x05,
    /// 小雨
    FITCLOUDWEATHERTYPE_LIGHTRAIN = 0x06,
    /// 中雨 (moderate rain)、大雨 (heavy rain)、暴雨 (rainstorm)
    FITCLOUDWEATHERTYPE_MHSRAIN = 0x07,
    /// 雨夹雪、冻雨
    FITCLOUDWEATHERTYPE_SLEET = 0x08,
    /// 小雪
    FITCLOUDWEATHERTYPE_LIGHTSNOW = 0x09,
    /// 大雪、暴雪
    FITCLOUDWEATHERTYPE_HEAVYSNOW = 0x0a,
    /// 沙尘暴、浮沉
    FITCLOUDWEATHERTYPE_SANDSTORM = 0x0b,
    /// 雾、雾霾
    FITCLOUDWEATHERTYPE_FOGORHAZE = 0x0c,
    /// 风、龙卷风、飓风
    FITCLOUDWEATHERTYPE_WINDY = 0x0d,
    /// 晚间多云
    FITCLOUDWEATHERTYPE_CLOUDYINEVENING = 0x0e,
    /// 晚间晴朗
    FITCLOUDWEATHERTYPE_CLEARINEVENING = 0x0f,
    /// 晚间阵雨
    FITCLOUDWEATHERTYPE_EVENINGSHOWERS = 0x10,
    /// 未知天气
    FITCLOUDWEATHERTYPE_UNKNOWN = 0xff,
};

#pragma mark - 手表连接标志

typedef NS_ENUM(NSInteger, FITCLOUDWATCHCONNECTIONFLAG) {
    /// 无
    FITCLOUDWATCHCONNECTIONFLAG_NONE = 0,
    /// 绑定连接
    FITCLOUDWATCHCONNECTIONFLAG_CONNECT = 1,
    /// 回连
    FITCLOUDWATCHCONNECTIONFLAG_RECONNECT = 2,
};

#pragma mark - 手表佩戴状态

/// 手表佩戴状态
typedef NS_ENUM(NSInteger, FITCLOUDWEARINGSTATUS) {
    /// 未佩戴
    FITCLOUDWEARINGSTATUS_NOTWORN = 0,
    /// 佩戴
    FITCLOUDWEARINGSTATUS_WORN = 1,
};

#pragma mark - 激光测量

/// 激光测量状态
typedef NS_ENUM(NSInteger, FITCLOUDLASERMEASUREMENTSTATUS) {
    /// 未测量
    FITCLOUDLASERMEASUREMENTSTATUS_NONE = 0,
    /// 测量中
    FITCLOUDLASERMEASUREMENTSTATUS_MEASURING = 1,
    /// 关机退出测量
    FITCLOUDLASERMEASUREMENTSTATUS_STOPFORWATCHTURNOFF = 2,
    /// 摘下退出测量
    FITCLOUDLASERMEASUREMENTSTATUS_STOPFORUNWEAR = 3,
    /// 手动结束退出测量
    FITCLOUDLASERMEASUREMENTSTATUS_STOPBYMANUAL = 4,
};

#pragma mark - 其他模块固件版本

/// 其他模块固件版本
typedef NS_ENUM(NSInteger, FITCLOUDFIRMWAREMODULETYPE) {
    /// GPS
    FITCLOUDFIRMWAREMODULETYPE_GPS = 0x01,
    /// 4G Modem
    FITCLOUDFIRMWAREMODULETYPE_4GMODEM = 0x02,
};

#pragma mark - App Side Permission Type

/// App side permission type
typedef NS_ENUM(NSInteger, FITCLOUDAPPSIDEPERMISSIONTYPE) {
    /// Location permission
    FITCLOUDAPPSIDEPERMISSIONTYPE_LOCATION = 0x1,
};

#pragma mark GoMore Algorithm Key Return Code


/// GoMore algorithm version definitions
///
/// Defines different versions of the GoMore algorithm supported by the device
typedef NS_ENUM(NSInteger, FITCLOUDGOMOREALGORITHMVERSION) {
    /// 1.0
    FITCLOUDGOMOREALGORITHMVERSION_1_0 = 0x01,
    /// 2.0
    FITCLOUDGOMOREALGORITHMVERSION_2_0 = 0x02,
    /// Default version
    FITCLOUDGOMOREALGORITHMVERSION_DEFAULT = FITCLOUDGOMOREALGORITHMVERSION_1_0,
};

typedef NS_ENUM(NSInteger, FITCLOUDGOMOREALGORITHMKEYRETURNCODE) {
    /// Success
    FITCLOUDGOMOREALGORITHMKEYRETURNCODE_SUCCESS = 0x00,
    /// Failed for the network does not work
    FITCLOUDGOMOREALGORITHMKEYRETURNCODE_NETWORK_NOT_WORK = 0x01,
    /// Failed for wrong parameters
    FITCLOUDGOMOREALGORITHMKEYRETURNCODE_WRONG_PARAMETERS = 0x02,
    /// Failed for the app is in background
    FITCLOUDGOMOREALGORITHMKEYRETURNCODE_APP_IN_BACKGROUND = 0x03,
};

#pragma mark AI Conversation Model

/// AI conversation model type definitions
///
/// Defines different types of AI models supported by the device
typedef NS_ENUM(NSInteger, FITCLOUDAICONVERSATIONMODEL) {
    /// Unspecified AI model
    FITCLOUDAICONVERSATIONMODEL_UNSPECIFIED = -1,

    /// Doubao AI model
    FITCLOUDAICONVERSATIONMODEL_DOUBAO = 0x00,

    /// DeepSeek AI model
    FITCLOUDAICONVERSATIONMODEL_DEEPSEEK = 0x01,

    /// ChatGLM AI model
    FITCLOUDAICONVERSATIONMODEL_CHATGLM = 0x02,

    /// ERNIE Bot AI model
    FITCLOUDAICONVERSATIONMODEL_ERNIEBOT = 0x03,

    /// Qwen AI model
    FITCLOUDAICONVERSATIONMODEL_QWEN = 0x04,

    /// Spark AI model
    FITCLOUDAICONVERSATIONMODEL_SPARK = 0x05,

    /// Kimi AI model
    FITCLOUDAICONVERSATIONMODEL_KIMI = 0x06,
};

#pragma mark AdFlash AI Agent 

/// AdFlash AI Agent
typedef NS_ENUM(NSInteger, FITCLOUDADFLASHAIAGENT) {
    /// unspecified
    FITCLOUDADFLASHAIAGENT_UNSPECIFIED = -1,
    /// jarvis
    FITCLOUDADFLASHAIAGENT_JARVIS = 0x00,
    /// 星座运势
    FITCLOUDADFLASHAIAGENT_CONSTELLATION = 0x01,
    /// 塔罗牌大师
    FITCLOUDADFLASHAIAGENT_TAROTMASTER = 0x02,
    /// 食物热量查询
    FITCLOUDADFLASHAIAGENT_FOODCALORIE = 0x03,
    /// 社交技巧
    FITCLOUDADFLASHAIAGENT_SOCIALSKILLS = 0x04,
    /// 情绪纾解
    FITCLOUDADFLASHAIAGENT_EMOTIONALRELIEF = 0x05,
    /// 今天吃什么
    FITCLOUDADFLASHAIAGENT_TODAYFOOD = 0x06,
};

#pragma mark AI Watch Face Generation Result Codes

/// AI photo generation result codes
///
/// Defines the possible result codes when generating AI photo
typedef NS_ENUM(NSInteger, FITCLOUDAIPHOTOGENRESULT) {
    /// Generation completed successfully
    FITCLOUDAIPHOTOGENRESULT_SUCCESS = 0x00,

    /// Failed due to network connection error
    FITCLOUDAIPHOTOGENRESULT_NETWORK_ERROR = 0x01,

    /// Failed due to unknown reason
    FITCLOUDAIPHOTOGENRESULT_UNKNOWN_ERROR = 0xff,
};

/// Defines the purpose for requesting location from the device side
///
/// This enumeration specifies various reasons why the device may request location information
typedef NS_ENUM(NSInteger, FitCloudDeviceSideLocationRequestPurpose) {
    /// Indicates a default location request with no specific purpose
    FitCloudDeviceSideLocationRequestPurposeDefault = 0x00,
    
    /// Indicates location is being requested to enable quick start of GPS-based workout tracking
    FitCloudDeviceSideLocationRequestPurposeGPSWorkoutQuickStart = 0x01,
    
    /// Indicates location is being requested for accurate tracking of GPS-based workouts
    FitCloudDeviceSideLocationRequestPurposeGPSWorkoutAccurate = 0x02,
};

#pragma mark Festival

/// Represents different types of festivals that can be set on the device
typedef NS_ENUM(NSInteger, FitCloudFestival) {
    /// None
    FitCloudFestivalNone = -1,
    
    /// Birthday
    FitCloudFestivalBirthday = 0,
    
    /// Christmas
    FitCloudFestivalChristmas = 1,
    
    /// New Year
    FitCloudFestivalNewYear = 2,
    
    FitCloudFestivalMax = FitCloudFestivalNewYear,
};

#pragma mark Workout summary data type

/// Workout summary data type
typedef NS_ENUM(NSInteger, FitCloudWorkoutSummaryDataType) {
    /// Unknown
    FitCloudWorkoutSummaryDataTypeUnknown = -1,
    
    /// Steps, unit: step
    FitCloudWorkoutSummaryDataTypeSteps = 0,
    
    /// Distance, unit: meter
    FitCloudWorkoutSummaryDataTypeDistance = 1,
    
    /// Calories, unit: cal
    FitCloudWorkoutSummaryDataTypeCalories = 2,

    /// Average speed, unit: m/s
    FitCloudWorkoutSummaryDataTypeAvgSpeed = 3,

    /// Maximum speed, unit: m/s
    FitCloudWorkoutSummaryDataTypeMaxSpeed = 4,

    /// Minimum speed, unit: m/s
    FitCloudWorkoutSummaryDataTypeMinSpeed = 5,

    /// Average pace, unit: s/m
    FitCloudWorkoutSummaryDataTypeAvgPace = 6,

    /// Slowest pace, unit: s/m
    FitCloudWorkoutSummaryDataTypeSlowestPace = 7,

    /// Fastest pace, unit: s/m 
    FitCloudWorkoutSummaryDataTypeFastestPace = 8,

    /// Average heart rate, unit: BPM
    FitCloudWorkoutSummaryDataTypeAvgBPM = 9,

    /// Maximum heart rate, unit: BPM
    FitCloudWorkoutSummaryDataTypeMaxBPM = 10,

    /// Minimum heart rate, unit: BPM
    FitCloudWorkoutSummaryDataTypeMinBPM = 11,

    /// Average cadence, unit: step/min
    FitCloudWorkoutSummaryDataTypeAvgCadence = 12,

    /// Maximum cadence, unit: step/min
    FitCloudWorkoutSummaryDataTypeMaxCadence = 13,

    /// Minimum cadence, unit: step/min
    FitCloudWorkoutSummaryDataTypeMinCadence = 14,

    /// Average stride, unit: centimeters/step
    FitCloudWorkoutSummaryDataTypeAvgStride = 15,

    /// Duration, unit: second
    FitCloudWorkoutSummaryDataTypeDuration = 16,

    /// Workout type
    FitCloudWorkoutSummaryDataTypeWorkoutType = 17,

    /// Heart rate zone - warm up duration (in minutes)
    FitCloudWorkoutSummaryDataTypeHeartRateWarmUpDuration = 18,

    /// Heart rate zone - fat burning duration (in minutes)
    FitCloudWorkoutSummaryDataTypeHeartRateFatBurningDuration = 19,

    /// Heart rate zone - aerobic duration (in minutes)
    FitCloudWorkoutSummaryDataTypeHeartRateAerobicDuration = 20,

    /// Heart rate zone - anaerobic duration (in minutes)
    FitCloudWorkoutSummaryDataTypeHeartRateAnaerobicDuration = 21,

    /// Heart rate zone - extreme duration (in minutes)
    FitCloudWorkoutSummaryDataTypeHeartRateExtremeDuration = 22,
    

    FitCloudWorkoutSummaryDataTypeMax = FitCloudWorkoutSummaryDataTypeHeartRateExtremeDuration,
};


#endif /* FitCloudKitDefines_h */
