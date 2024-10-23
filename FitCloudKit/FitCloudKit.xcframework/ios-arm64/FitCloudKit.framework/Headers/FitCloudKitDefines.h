//
//  FitCloudKitDefines.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/29.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#ifndef FitCloudKitDefines_h
#define FitCloudKitDefines_h

#import <Foundation/Foundation.h>

#pragma mark - 错误码相关

/// FitCloudKit 错误码作用域
#define FITCLOUDKITERRORDOMAIN @"FITCLOUDKITERRORDOMAIN"

/// FitCloudKit 新OTA升级错误码作用域
#define FITCLOUDNEWOTAERRORDOMAIN @"FITCLOUDNEWOTAERRORDOMAIN"

/// FitCloudKit 错误码定义
typedef NS_ENUM(NSInteger, FITCLOUDKITERROR)
{
    /// 未知错误
    FITCLOUDKITERROR_UNKNOWN = 20000,
    /// 错误的Sequence ID
    FITCLOUDKITERROR_BADSEQUENCEID = 20001,
    /// 发送数据包给手表出错,重试达到最大次数
    FITCLOUDKITERROR_PACKETSENDMAXRETRYTIMES = 20002,
    /// 非法的命令数据包，或格式不正确
    FITCLOUDKITERROR_BADCMDPACKET = 20003,
    /// 发送给手表的命令执行超时
    FITCLOUDKITERROR_CMDEXECTIMEOUT = 20004,
    /// 手表命令响应格式不正确
    FITCLOUDKITERROR_CMDCALLBACKINVALID = 20005,
    /// 准备执行手表命令时，发现手表意外已经断开连接
    FITCLOUDKITERROR_UNKNOWNDISCONNECTWHENCMDEXEC = 20006,
    /// 尚未连接到手表设备
    FITCLOUDKITERROR_NOTCONNECTED = 20020,
    /// 错误的Characteristic(写)
    FITCLOUDKITERROR_BADWRITECHARACTERISTIC = 20021,
    /// 手表初始化尚未完成，尚不能发送通信命令
    FITCLOUDKITERROR_COMMUNICATIONNOTREADY = 20022,
    /// ANCS未授权，仅iOS13之后可用
    FITCLOUDKITERROR_ANCSNOTAUTHORIZED = 20023,
    /// 手表不支持该功能
    FITCLOUDKITERROR_DEVICENOTSUPPORT = 20024,
    /// 手表断开连接
    FITCLOUDKITERROR_DEVICEDISCONNECTED = 20025,
    /// 参数错误
    FITCLOUDKITERROR_WRONGPARAM = 20026,
    /// 数组长度溢出
    FITCLOUDKITERROR_ARRAYSIZEOVERFLOW = 20027,
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
    /// 当前手表不支持天气功能
    FITCLOUDKITERROR_WEATHERFEATURENOTSUPPORT = 50001,
    /// 非法的二维码内容
    FITCLOUDKITERROR_BADQRCODE = 50002,
    /// 二维码内容长度过长，最大长度274字节
    FITCLOUDKITERROR_QRCODEBADLENGTH = 50003,
    /// 非法的第三方外设
    FITCLOUDKITERROR_BADTHIRDPARTYPERIPHERAL = 50004,
    /// 未能发现待转换的外设
    FITCLOUDKITERROR_TOTRANSLATEPERIPHERALNOTFOUND = 50005,
    /// 当前不允许进入DFU模式，原因未知
    FITCLOUDKITERROR_DFUNOTALLOWUNKNOWNREASON = 60000,
    /// 当前不允许进入DFU模式，手表电量过低
    FITCLOUDKITERROR_DFUNOTALLOWFORBATTERYLOW = 60001,
    /// 当前已经是DFU模式
    FITCLOUDKITERROR_ALREADYINDFUMODE = 60002,
    /// 当前不是DFU模式
    FITCLOUDKITERROR_NOTDFUMODE = 60003,
    /// 当前不允许进入DFU模式，手表处于省电模式中
    FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE = 60004,
    /// 常用联系人数量达到最大值，最多支持设定10个常用联系人
    FITCLOUDKITERROR_FAVCONTACTSREACHMAX = 70001,
    /// 当前手表不支持常用联系人
    FITCLOUDKITERROR_FAVCONTACTSNOTSUPPORT = 70002,
    /// 习惯数量达到最大值，最多支持设定10个习惯养成
    FITCLOUDKITERROR_HABITSREACHMAX = 71001,
    /// 习惯养成名称为空或长度超过限定的32字节
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

/// FitCloudKit 蓝牙中心设备(Central)状态
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
typedef NS_ENUM(NSInteger, FITCLOUDCHIPVENDOR)
{
    /// 未知
    FITCLOUDCHIPVENDOR_UNKNOWN = 0,
    /// Realtek
    FITCLOUDCHIPVENDOR_REALTEK = 1,
    /// Nordic
    FITCLOUDCHIPVENDOR_NORDIC = 2,
};

#pragma mark - the watch common features define

/// the watch common features define
typedef NS_ENUM(NSInteger, FITCLOUDDEVICEFEATURE)
{
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
typedef NS_ENUM(NSInteger, FITCLOUDDEVICECAPACITY)
{
    ///支持的最大闹钟数量
    FITCLOUDDEVICECAPACITY_ALARMCLOCKCOUNT = 0x02,
    ///支持的最大日程数量
    FITCLOUDDEVICECAPACITY_SCHEDULECOUNT = 0x03,
    ///支持的最大常用联系人数量
    FITCLOUDDEVICECAPACITY_FAVORITECONTACTCOUNT = 0x04,
    ///支持的天气种类数量，目前支持的数量有13/16
    FITCLOUDDEVICECAPACITY_WEATHERCOUNT = 0x05,
    ///支持喝水个性化提醒功能
    FITCLOUDDEVICECAPACITY_WATERDRINKPERSONALIZEDREMINDERFEATURE = 0x06,
    ///支持久坐个性化提醒功能
    FITCLOUDDEVICECAPACITY_SEDENTARYPERSONALIZEDREMINDERFEATURE = 0x07,
    ///支持吃药个性化提醒功能
    FITCLOUDDEVICECAPACITY_MEDICATIONPERSONALIZEDREMINDERFEATURE = 0x08,
    ///支持自定义个性化提醒功能
    FITCLOUDDEVICECAPACITY_CUSTOMIZEDPERSONALIZEDREMINDERFEATURE = 0x09,
    ///支持的自定义个性化提醒数量
    FITCLOUDDEVICECAPACITY_CUSTOMIZEDPERSONALIZEDREMINDERCOUNT = 0x0a,
};


#pragma mark - 手表硬件

/**
 * @brief 手表硬件功能支持定义
 */
typedef NS_OPTIONS(UInt32, FITCLOUDHARDWARE)
{
    FITCLOUDHARDWARE_NONE = 0,                        //无
    FITCLOUDHARDWARE_HEARTRATE = 1,                   //心率
    FITCLOUDHARDWARE_BLOODOXYGEN = 1 << 1,            //血氧
    FITCLOUDHARDWARE_BLOODPRESSURE = 1 << 2,          //血压
    FITCLOUDHARDWARE_BREATHERATE = 1 << 3,            //呼吸频率
    FITCLOUDHARDWARE_WEATHER = 1 << 4,                //天气
    FITCLOUDHARDWARE_ECG = 1 << 5,                    //心电
    FITCLOUDHARDWARE_SPORTSMODE = 1 << 6,             //运动模式
    FITCLOUDHARDWARE_WECHATSPORTS = 1 << 7,           //微信运动
    FITCLOUDHARDWARE_8762C = 1 << 8,                  //8762C新平台，升级时使用新平台升级库
    FITCLOUDHARDWARE_SHOULDSAVEHEARTRATEWHENSPORTSMODE = 1 << 9,      //运动模式保存心率数据，1.运动模式的数据item中增加心率，长度会变化，时间间隔也变化，具体看协议文档 2.App上要增加心率曲线
    FITCLOUDHARDWARE_BODYTEMPERATURE = 1 << 10,       //体温
    FITCLOUDHARDWARE_WOMENHEALTH = 1 << 11,           //女性健康
    FITCLOUDHARDWARE_VOICERECOG = 1 << 12,            //语音识别， 为1时手表上有语音识别功能，为0则手表上没有语音识别功能
    FITCLOUDHARDWARE_STRESSINDEX = 1 << 13,           //压力指数
    FITCLOUDHARDWARE_GAMERECORDS = 1 << 14,           //游戏记录
    FITCLOUDHARDWARE_NORDIC = 1 << 15,                //Nordic芯片
    FITCLOUDHARDWARE_DFUSHOULDSILENTMODE = 1 << 16,   //固件升级使用静默升级
    FITCLOUDHARDWARE_SCREENANDVIBRATEPARAM = 1 << 17, //屏幕及马达参数调节(亮屏时长/亮度/马达振动强度)
    FITCLOUDHARDWARE_SHOULDDISABLEDIYWATCHFACE = 1 << 18, // 是否应该禁用自定义表盘功能
    FITCLOUDHARDWARE_SPORTSMODEDIY = 1 << 19,         //运动模式(DIY)固件推送
    FITCLOUDHARDWARE_WATCHSPORTSWITHGPSCONNECT = 1 << 20,//运动模式GPS互联
    FITCLOUDHARDWARE_BLOODPRESSUREBASEONPNEUMATICPUMP = 1 << 21, //基于气压泵的真血压
    FITCLOUDHARDWARE_ALLOWSYNCWATCHMANUALMEASUREDATA = 1 << 22, //手表手动测量数据同步
    FITCLOUDHARDWARE_SHOULDDISABLESLEEPFEATURE = 1 << 23,       //禁用睡眠功能
    FITCLOUDHARDWARE_GPS = 1 << 24,                    //GPS模块
    FITCLOUDHARDWARE_8773 = 1 << 26,                   //8773平台
    FITCLOUDHARDWARE_568X = 1 << 27,                   //568X平台
};

#pragma mark - 手表显示

/**
 * @brief 手表屏幕显示定义
 */
typedef NS_OPTIONS(UInt32, FITCLOUDSCREENDISPLAY)
{
    FITCLOUDSCREENDISPLAY_NONE = 0,                        //无
    FITCLOUDSCREENDISPLAY_DATETIME = 1,                    //日期时间
    FITCLOUDSCREENDISPLAY_STEPS = 1 << 1,                  //步数
    FITCLOUDSCREENDISPLAY_DISTANCE = 1 << 2,               //距离
    FITCLOUDSCREENDISPLAY_CALORIES = 1 << 3,               //卡路里
    FITCLOUDSCREENDISPLAY_SLEEP = 1 << 4,                  //睡眠
    FITCLOUDSCREENDISPLAY_HEARTRATE = 1 << 5,              //心率
    FITCLOUDSCREENDISPLAY_BLOODOXYGEN = 1 << 6,            //血氧
    FITCLOUDSCREENDISPLAY_BLOODPRESSURE = 1 << 7,          //血压
    FITCLOUDSCREENDISPLAY_WEATHERFORECAST = 1 << 8,        //天气预报
    FITCLOUDSCREENDISPLAY_FINDIPHONE = 1 << 9,             //查找手机
    FITCLOUDSCREENDISPLAY_MACID = 1 << 10,                 //手表Mac信息,ID
    FITCLOUDSCREENDISPLAY_UV = 1 << 11,                    //UV
    FITCLOUDSCREENDISPLAY_EARTHMAGNETICFIELD = 1 << 12,    //地磁
    FITCLOUDSCREENDISPLAY_STOPWATCH = 1 << 13,             //秒表
};

#pragma mark - 手表偏好设置

/**
 * @brief 手表偏好设置定义
 */
typedef NS_OPTIONS(UInt16, FITCLOUDPREFER)
{
    FITCLOUDPREFER_NONE = 0,                        //无
    FITCLOUDPREFER_RIGHTHAND = 1,                   //右手      0左手 1右手
    FITCLOUDPREFER_ENHANCEDDETECTION = 1 << 1,      //加强检测   0佩戴检测 1加强检测
    FITCLOUDPREFER_SHOWAS12HOURS = 1 << 2,          //显示12小时制  0->24小时制  1->12小时制
    FITCLOUDPREFER_IMPERIALUNIT = 1 << 3,           //英制  0公制 1英制
    FITCLOUDPREFER_FAHRENHEIT = 1 << 4,             //华氏度 0摄氏度 1华氏度
    FITCLOUDPREFER_WEATHERPUSH = 1 << 5,            //开启天气推送  0关 1开
    FITCLOUDPREFER_VIBRATEWHENDISCONNECT = 1 << 6,  //蓝牙断开时手表振动 0关 1开
    FITCLOUDPREFER_REMINDWHENSPORTSGOALACHIEVEMENT = 1 << 7, // 手表运动(计步/距离/卡路里)目标达成提醒 0关 1开
    FITCLOUDPREFER_METRICWEIGHT = 1 << 8,           //重量使用公制 0 英制 1 公制
};

#pragma mark - 手表语言
/**
 * @brief 手表语言定义
 */
typedef NS_ENUM(Byte, FITCLOUDLANGUAGE)
{
    FITCLOUDLANGUAGE_NOTSET = 0x00,                   //未设置
    FITCLOUDLANGUAGE_CHINESESIMPLIFIED = 0x01,        //简体中文
    FITCLOUDLANGUAGE_CHINESETRADITIONAL = 0x02,       //繁体中文
    FITCLOUDLANGUAGE_ENGLISH = 0x03,                  //英语
    FITCLOUDLANGUAGE_GERMAN = 0x04,                   //德语
    FITCLOUDLANGUAGE_RUSSIAN = 0x05,                  //俄语
    FITCLOUDLANGUAGE_SPANISH = 0x06,                  //西班牙语
    FITCLOUDLANGUAGE_PORTUGUESE = 0x07,               //葡萄牙语
    FITCLOUDLANGUAGE_FRENCH = 0x08,                   //法语
    FITCLOUDLANGUAGE_JAPANESE = 0x09,                 //日语
    FITCLOUDLANGUAGE_ARABIC = 0x0a,                   //阿拉伯语言
    FITCLOUDLANGUAGE_DUTCH = 0x0b,                    //荷兰语
    FITCLOUDLANGUAGE_ITALIAN = 0x0c,                  //意大利语
    FITCLOUDLANGUAGE_BENGALI = 0x0d,                  //孟加拉语
    FITCLOUDLANGUAGE_CROATIAN = 0xe,                  //克罗地亚语
    FITCLOUDLANGUAGE_CZECH = 0x0f,                    //捷克语
    
    FITCLOUDLANGUAGE_DANISH = 0x10,                   //丹麦语
    FITCLOUDLANGUAGE_GREEK  = 0x11,                   //希腊语
    FITCLOUDLANGUAGE_HEBREW = 0x12,                   //希伯来语(以色列)
    FITCLOUDLANGUAGE_HINDI = 0x13,                    //印度语
    FITCLOUDLANGUAGE_HUN = 0x14,                      //匈牙利语
    FITCLOUDLANGUAGE_INDONESIAN = 0x15,               //印度尼西亚语
    FITCLOUDLANGUAGE_KOREAN = 0x16,                   //韩语(朝鲜语)
    FITCLOUDLANGUAGE_MALAY = 0x17,                    //马来语
    FITCLOUDLANGUAGE_PERSIAN = 0x18,                  //波斯语
    FITCLOUDLANGUAGE_POLISH = 0x19,                   //波兰语
    FITCLOUDLANGUAGE_RUMANIAN = 0x1a,                 //罗马尼亚语
    FITCLOUDLANGUAGE_SERB = 0x1b,                     //塞尔维亚语
    FITCLOUDLANGUAGE_SWEDISH = 0x1c,                  //瑞典语
    FITCLOUDLANGUAGE_THAI = 0x1d,                     //泰语
    FITCLOUDLANGUAGE_TURKISH = 0x1e,                  //土耳其语
    FITCLOUDLANGUAGE_URDU = 0x1f,                     //乌尔都语

    FITCLOUDLANGUAGE_VIETNAMESE = 0x20,               //越南语
    FITCLOUDLANGUAGE_CATALAN = 0x21,                  //加泰隆语(西班牙)
    FITCLOUDLANGUAGE_LATVIAN = 0x22,                  //拉脱维亚语
    FITCLOUDLANGUAGE_LITHUANIAN = 0x23,               //立陶宛语
    FITCLOUDLANGUAGE_NORWEGIAN = 0x24,                //挪威语
    FITCLOUDLANGUAGE_SLOVAK = 0x25,                   //斯洛伐克语
    FITCLOUDLANGUAGE_SLOVENIAN = 0x26,                //斯洛文尼亚语
    FITCLOUDLANGUAGE_BULGARIAN = 0x27,                //保加利亚语
    FITCLOUDLANGUAGE_UKRAINIAN = 0x28,                //乌克兰语
    FITCLOUDLANGUAGE_FILIPINO = 0x29,                 //菲律宾语
    FITCLOUDLANGUAGE_FINNISH = 0x2a,                  //芬兰语
    FITCLOUDLANGUAGE_SOUTHAFRICAN = 0x2b,             //南非语
    FITCLOUDLANGUAGE_ROMANSH = 0x2c,                  //罗曼什语(瑞士)
    FITCLOUDLANGUAGE_BURMESE = 0x2d,                  //缅甸语
    FITCLOUDLANGUAGE_CAMBODIAN = 0x2e,                //柬埔寨语
    FITCLOUDLANGUAGE_AMHARIC = 0x2f,                  //阿姆哈拉语
 
    FITCLOUDLANGUAGE_BELARUSIAN = 0x30,               //白俄罗斯语
    FITCLOUDLANGUAGE_ESTONIAN = 0x31,                 //爱沙尼亚语
    FITCLOUDLANGUAGE_SWAHILI = 0x32,                  //斯瓦希里语(坦桑尼亚)
    FITCLOUDLANGUAGE_ZULU = 0x33,                     //祖鲁语(南非)
    FITCLOUDLANGUAGE_AZERBAIJANI = 0x34,              //阿塞拜疆语
    FITCLOUDLANGUAGE_ARMENIAN = 0x35,                 //亚美尼亚语(亚美尼亚)
    FITCLOUDLANGUAGE_GEORGIAN = 0x36,                 //格鲁吉亚语(格鲁吉亚)
    FITCLOUDLANGUAGE_LAO = 0x37,                      //老挝语(老挝)
    FITCLOUDLANGUAGE_MONGOLIAN = 0x38,                //蒙古语
    FITCLOUDLANGUAGE_NEPALI = 0x39,                   //尼泊尔语
    FITCLOUDLANGUAGE_KAZAKH = 0x3a,                   //哈萨克语
    FITCLOUDLANGUAGE_GALICIAN = 0x3b,                 //加利西亚语
    FITCLOUDLANGUAGE_ICELANDIC = 0x3c,                //冰岛语
    FITCLOUDLANGUAGE_KANNADA = 0x3d,                  //卡纳达语
    FITCLOUDLANGUAGE_KYRGYZ = 0x3e,                   //吉尔吉斯语
    FITCLOUDLANGUAGE_MALAYALAM = 0x3f,                //马拉雅拉姆语

    FITCLOUDLANGUAGE_MARATHI = 0x40,                  //马拉提语/马拉地语
    FITCLOUDLANGUAGE_TAMIL = 0x41,                    //泰米尔语
    FITCLOUDLANGUAGE_MACEDONIAN = 0x42,               //马其顿语
    FITCLOUDLANGUAGE_TELUGU = 0x43,                   //泰卢固语
    FITCLOUDLANGUAGE_UZBEK = 0x44,                    //乌兹别克语
    FITCLOUDLANGUAGE_BASQUE = 0x45,                   //巴斯克语
    FITCLOUDLANGUAGE_BERBER = 0x46,                   //僧伽罗语(斯里兰卡)
    FITCLOUDLANGUAGE_ALBANIAN = 0x47,                 //阿尔巴尼亚语
    
};

#pragma mark - 闹钟相关

/**
 * @brief 闹钟周期定义
 */
typedef NS_OPTIONS(Byte, FITCLOUDALARMCYCLE)
{
    FITCLOUDALARMCYCLE_NONE = 0,         //不循环，仅当天有效
    FITCLOUDALARMCYCLE_MON = 1,          //周一(循环)
    FITCLOUDALARMCYCLE_TUE = 1 << 1,     //周二(循环)
    FITCLOUDALARMCYCLE_WED = 1 << 2,     //周三(循环)
    FITCLOUDALARMCYCLE_THUR = 1 << 3,    //周四(循环)
    FITCLOUDALARMCYCLE_FRI = 1 << 4,     //周五(循环)
    FITCLOUDALARMCYCLE_SAT = 1 << 5,     //周六(循环)
    FITCLOUDALARMCYCLE_SUN = 1 << 6,     //周日(循环)
};

#pragma mark - 日程相关

/**
 * @brief 日程定义
 */
typedef NS_OPTIONS(Byte, FITCLOUDSCHEDULE)
{
    FITCLOUDSCHEDULE_DRINK = 0,             //喝水
    FITCLOUDSCHEDULE_ALARM = 1,             //闹钟
    FITCLOUDSCHEDULE_SEDENTARY = 2,         //久坐
    FITCLOUDSCHEDULE_TEETHBRUSH = 3,        //刷牙
    FITCLOUDSCHEDULE_BREAKFAST = 4,         //早餐
    FITCLOUDSCHEDULE_HOMEWORK = 5,          //家庭作业
    FITCLOUDSCHEDULE_LUNCH = 6,             //午餐
    FITCLOUDSCHEDULE_SPORTS = 7,            //运动
    FITCLOUDSCHEDULE_GETUP = 8,             //起床
    FITCLOUDSCHEDULE_GOTOBED = 9,           //睡觉
    FITCLOUDSCHEDULE_GOTOSCHOOL = 10,       //上学
    FITCLOUDSCHEDULE_GOHOME = 11,           //回家
    FITCLOUDSCHEDULE_READ = 12,             //阅读
    FITCLOUDSCHEDULE_BATH = 13,             //洗澡
    FITCLOUDSCHEDULE_PARTY = 14,            //聚会
    FITCLOUDSCHEDULE_GAME = 15,             //打游戏
    FITCLOUDSCHEDULE_CAMP = 16,             //露营
    FITCLOUDSCHEDULE_MUSIC = 17,            //音乐
    FITCLOUDSCHEDULE_DRAW = 18,             //绘画
    FITCLOUDSCHEDULE_DANCE = 19,            //跳舞
    FITCLOUDSCHEDULE_PHOTOGRAPHY = 20,      //摄影
    FITCLOUDSCHEDULE_WALKTHEDOG = 21,       //遛狗
    FITCLOUDSCHEDULE_MOVIE = 22,            //电影
};

/**
 * @brief 日程周期定义
 */
typedef NS_OPTIONS(Byte, FITCLOUDSCHEDULECYCLE)
{
    FITCLOUDSCHEDULECYCLE_NONE = 0,         //不循环，仅当天有效
    FITCLOUDSCHEDULECYCLE_MON = 1,          //周一(循环)
    FITCLOUDSCHEDULECYCLE_TUE = 1 << 1,     //周二(循环)
    FITCLOUDSCHEDULECYCLE_WED = 1 << 2,     //周三(循环)
    FITCLOUDSCHEDULECYCLE_THUR = 1 << 3,    //周四(循环)
    FITCLOUDSCHEDULECYCLE_FRI = 1 << 4,     //周五(循环)
    FITCLOUDSCHEDULECYCLE_SAT = 1 << 5,     //周六(循环)
    FITCLOUDSCHEDULECYCLE_SUN = 1 << 6,     //周日(循环)
};


#pragma mark - 习惯相关

/**
 * @brief 习惯循环定义
 */
typedef NS_OPTIONS(Byte, FITCLOUDHABITCYCLE)
{
    FITCLOUDHABITCYCLE_NONE = 0,         //不循环，仅当天有效
    FITCLOUDHABITCYCLE_MON = 1,          //周一(循环)
    FITCLOUDHABITCYCLE_TUE = 1 << 1,     //周二(循环)
    FITCLOUDHABITCYCLE_WED = 1 << 2,     //周三(循环)
    FITCLOUDHABITCYCLE_THUR = 1 << 3,    //周四(循环)
    FITCLOUDHABITCYCLE_FRI = 1 << 4,     //周五(循环)
    FITCLOUDHABITCYCLE_SAT = 1 << 5,     //周六(循环)
    FITCLOUDHABITCYCLE_SUN = 1 << 6,     //周日(循环)
};

/**
 * @brief 习惯一周内达标情况定义
 */
typedef NS_OPTIONS(Byte, FITCLOUDHABITACHIEVEMENT)
{
    FITCLOUDHABITACHIEVEMENT_NONE = 0,          //不达标
    FITCLOUDHABITACHIEVEMENT_LAST_SUN = 1,     //上周日达标
    FITCLOUDHABITACHIEVEMENT_MON = 1 << 1,     //本周一达标
    FITCLOUDHABITACHIEVEMENT_TUE = 1 << 2,     //本周二达标
    FITCLOUDHABITACHIEVEMENT_WED = 1 << 3,     //本周三达标
    FITCLOUDHABITACHIEVEMENT_THUR = 1 << 4,    //本周四达标
    FITCLOUDHABITACHIEVEMENT_FRI = 1 << 5,     //本周五达标
    FITCLOUDHABITACHIEVEMENT_SAT = 1 << 6,     //本周六达标
    FITCLOUDHABITACHIEVEMENT_SUN = 1 << 7,     //本周日达标
};

/**
 * @brief 习惯关联功能定义
 */
typedef NS_ENUM(Byte, FITCLOUDHABITASSOCIATEDFEATURE)
{
    FITCLOUDHABITASSOCIATEDFEATURE_NONE = 0,  //无关联
    FITCLOUDHABITASSOCIATEDFEATURE_SPORTS = 1, //运动
};

/**
 * @brief 习惯状态定义
 */
typedef NS_ENUM(Byte, FITCLOUDHABITSTATUS)
{
    FITCLOUDHABITSTATUS_TOBESTARTED = 0,     //待开始
    FITCLOUDHABITSTATUS_INPROGRESS = 1,      //进行中
    FITCLOUDHABITSTATUS_DONE = 2,            //已完成
    FITCLOUDHABITSTATUS_OVERDUE = 3,         //已逾期
    FITCLOUDHABITSTATUS_CLOSED = 4,          //已关闭
    FITCLOUDHABITSTATUS_REMOVED = 5,         //已删除
};

/**
 * @brief 习惯名称规则定义
 */
typedef NS_ENUM(Byte, FITCLOUDHABITNAMERULE)
{
    FITCLOUDHABITNAMERULE_CUSTOM = 0,        //自定义
    FITCLOUDHABITNAMERULE_SPORTS = 1,        //运动
    FITCLOUDHABITNAMERULE_STUDY = 2,         //学习
    FITCLOUDHABITNAMERULE_SLEEP = 3,         //睡眠
};

#pragma mark - 用户相关

/**
 * @brief 性别
 */
typedef NS_ENUM(Byte, FITCLOUDGENDER)
{
    FITCLOUDGENDER_FEMALE = 0,         //女
    FITCLOUDGENDER_MALE = 1,           //男
};

/**
 * @brief 用户绑定状态
 */
typedef NS_ENUM(NSInteger, FITCLOUDUSERBINDSTATUS)
{
    FITCLOUDUSERBINDSTATUS_NONE = 0,
    FITCLOUDUSERBINDSTATUS_BINDING = 1,
    FITCLOUDUSERBINDSTATUS_SUCCESS = 2,
    FITCLOUDUSERBINDSTATUS_FAILURE = 3,
    FITCLOUDUSERBINDSTATUS_UNBINDING = 4,
    FITCLOUDUSERBINDSTATUS_KICKEDOUT = 5,
};


#pragma mark - 睡眠

/**
 * @brief 睡眠质量定义
 */
typedef NS_ENUM(Byte, FITCLOUDSLEEPQUALITY)
{
    FITCLOUDSLEEPQUALITY_DEEP = 0x01,                     //深睡/熟睡
    FITCLOUDSLEEPQUALITY_LIGHT = 0x02,                    //浅睡眠/躺在床上
    FITCLOUDSLEEPQUALITY_AWAKE = 0x03,                    //清醒
    FITCLOUDSLEEPQUALITY_REM = 0x04,                      //快速眼动
};



#pragma mark - APP相机控制相关

/**
 * @brief APP相机状态(前台/后台)定义
 */
typedef NS_ENUM(Byte, APPCAMERASTATE)
{
    APPCAMERASTATE_FOREGROUND = 0x00,                   //前台
    APPCAMERASTATE_BACKGROUND = 0x01,                   //后台
};


#pragma mark - 女性健康

/**
 * @brief 女性健康模式
*/
typedef NS_ENUM (Byte, WOMENHEALTHMODE)
{
    WOMENHEALTHMODE_OFF = 0x00,                 //关闭
    WOMENHEALTHMODE_MENSES = 0x01,              //经期模式
    WOMENHEALTHMODE_PREGNANCY_PREPARE = 0x02,   //备孕模式
    WOMENHEALTHMODE_PREGNANCY = 0x03,           //怀孕模式
};

// 怀孕期提醒方式
typedef NS_ENUM(Byte, PREGNANCYREMINDTYPE)
{
    PREGNANCYREMINDTYPE_PREGNANTDAYS = 0,   //已怀孕天数
    PREGNANCYREMINDTYPE_DAYSBEFOREEDC = 1,  //距离预产期天数
};


#pragma mark - App定位服务相关
typedef NS_ENUM(Byte, APPLOCATIONSERVICESTATE)
{
    APPLOCATIONSERVICESTATE_AVAILABLE = 0x00,    //正常
    APPLOCATIONSERVICESTATE_RESTRICTED = 0x01,   //APP定位权限受限
    APPLOCATIONSERVICESTATE_DISABLEDWITHIOS = 0x02, //手机定位功能未开启
};

#pragma mark - Alexa

/**
 * @brief Alexa校验错误
*/
typedef NS_ENUM(Byte, ALEXACHECKERROR)
{
    ALEXACHECKERROR_VOICEIDNOTMATCH = 0x00,             //VoiceId不匹配
    ALEXACHECKERROR_BADLENGTH = 0x01,                   //长度校验失败
    ALEXACHECKERROR_CRC = 0x02,                         //CRC校验失败
   
};

/**
 * @brief Alexa调用错误
*/
typedef NS_ENUM(Byte, ALEXAINVOKEERROR)
{
    ALEXAINVOKEERROR_SUCCESS = 0x00,                   //成功
    ALEXAINVOKEERROR_REGIONNOTSUPPORT = 0x01,          //该国家或者语言不支持Alexa
    ALEXAINVOKEERROR_NETWORKOFFLINE = 0x02,            //无网络
    ALEXAINVOKEERROR_NOTAUTHED = 0x03,                 //未授权
    ALEXAINVOKEERROR_APPNOTIMPLEMENTED = 0xFE,         //APP不支持
    ALEXAINVOKEERROR_UNKOWN = 0xFF,                    //未知错误
};

/**
 * @brief Alexa结果类型
*/
typedef NS_ENUM(Byte, ALEXARESULTTYPE)
{
    ALEXARESULTTYPE_TEXT = 0x00,                        //普通文本
    ALEXARESULTTYPE_DIRECTIVE = 0x01,                   //指令
};

#pragma mark - 大模型

/// LLM结果类型
typedef NS_ENUM(NSInteger, LLMRESULTTYPE)
{
    /// APP自行生成的错误文案
    LLMRESULTTYPE_ERRORTEXT = 0x00,
    /// 大模型大模型生成的文案
    LLMRESULTTYPE_LLMTEXT = 0x01,
};

/// LLM类型
typedef NS_ENUM(NSInteger, LLMTYPE)
{
    /// 无
    LLMTYPE_NONE = -1,
    /// ChatGPT
    LLMTYPE_CHATGPT = 0,
    /// 文心一言
    LLMTYPE_ERNIEBOT = 1,
};

#pragma mark - 表盘相关

/// 表盘位类型
typedef NS_ENUM(Byte, WATCHFACESLOTTYPE)
{
    WATCHFACESLOTTYPE_BUILTIN = 0x00,                               //当前表盘位置为内置，不可推送的
    WATCHFACESLOTTYPE_ALLOWPUSH = 0x10,                             //当前表盘位置可推送表盘，可根据表盘编号获取缩略图显示
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE1 = 0x20,                //当前表盘位置可推送表盘，缩略图显示自定义表盘样式1
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE2 = 0x21,                //当前表盘位置可推送表盘，缩略图显示自定义表盘样式2
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE3 = 0x22,                //当前表盘位置可推送表盘，缩略图显示自定义表盘样式3
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE4 = 0x23,                //当前表盘位置可推送表盘，缩略图显示自定义表盘样式4
    WATCHFACESLOTTYPE_THUMBNAIL_CUSTOMSTYPE5 = 0x24,                //当前表盘位置可推送表盘，缩略图显示自定义表盘样式5
};

/**
 * @brief 表盘模块样式
*/
typedef NS_ENUM(Byte, WATCHFACEMODULESTYLE)
{
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

/**
 * @brief 游戏类型定义
*/
typedef NS_ENUM(Byte, FITCLOUDGAME)
{
    FITCLOUDGAME_PETDEV = 0,            //宠物养成类
    FITCLOUDGAME_2048 = 1,              //2048游戏
    FITCLOUDGAME_CANDY = 2,             //糖果消消乐
    FITCLOUDGAME_PICTUREPUZZLE = 3,     //拼图游戏
    FITCLOUDGAME_PLANE = 4,             //飞机游戏
    FITCLOUDGAME_RACINGCAR = 5,         //赛车游戏
    FITCLOUDGAME_MAZE = 6,              //迷宫游戏
    FITCLOUDGAME_BASKETBALL = 7,        //篮球游戏
    FITCLOUDGAME_ARITHMETIC = 8,        //算术题游戏
    FITCLOUDGAME_TETRIS = 9,            //俄罗斯方块游戏
    FITCLOUDGAME_SUDOKU = 10,           //数独游戏
    FITCLOUDGAME_ANSWER = 11,           //答题游戏
};

/**
 * @brief 游戏锁操作定义
*/
typedef NS_ENUM(Byte, FITCLOUDGAMEPASSCODEOP)
{
    FITCLOUDGAMEPASSCODEOP_CANCEL = 0x00,   //取消
    FITCLOUDGAMEPASSCODEOP_SET = 0x01,      //设置
};

/**
 * @brief 游戏锁操作结果定义
*/
typedef NS_ENUM(Byte, FITCLOUDGAMEPASSCODEOPRESULT)
{
    FITCLOUDGAMEPASSCODEOPRESULT_SUCCESS = 0x00,   //成功
    FITCLOUDGAMEPASSCODEOPRESULT_FAILURE = 0x01,   //失败
};

/**
 * @brief 游戏排名趋势
*/
typedef NS_ENUM(Byte, FITCLOUDGAMERANDINGTREND)
{
    FITCLOUDGAMERANDINGTREND_DECLINE = 0x00,          //下降
    FITCLOUDGAMERANDINGTREND_SAME = 0x01,             //排名和上次一样
    FITCLOUDGAMERANDINGTREND_ASCEND = 0x02,           //上升
};

#pragma mark -手表GPS互联实时运动相关

/**
 * @brief 手表GPS互联实时运动定义
 */
typedef NS_ENUM(UInt16, FITCLOUDSPORTSWITHGPS)
{
    FITCLOUDSPORTSWITHGPS_NONE = 0x00,          //无运动
    FITCLOUDSPORTSWITHGPS_WALKING = 0x10,       //步行
    FITCLOUDSPORTSWITHGPS_RUNNING = 0x08,       //跑步
    FITCLOUDSPORTSWITHGPS_CLIMBING = 0x14,      //登山
    FITCLOUDSPORTSWITHGPS_BICYCLING = 0x04,     //骑行
};

/**
 * @brief 手表GPS互联实时运动行为定义
 */
typedef NS_ENUM(Byte, FITCLOUDSPORTSWITHGPSACTION)
{
    FITCLOUDSPORTSWITHGPSACTION_STOP = 0x00,        //结束
    FITCLOUDSPORTSWITHGPSACTION_START = 0x01,       //开始
    FITCLOUDSPORTSWITHGPSACTION_PAUSE = 0x02,      //暂停
    FITCLOUDSPORTSWITHGPSACTION_RESUME = 0x03,     //恢复
};

/**
 * @brief 手表GPS互联实时运动状态定义
 */
typedef NS_ENUM(Byte, FITCLOUDSPORTSWITHGPSSTATUS)
{
    FITCLOUDSPORTSWITHGPSSTATUS_STOP = 0x00,        //结束
    FITCLOUDSPORTSWITHGPSSTATUS_INPROCESS = 0x01,   //进行中
    FITCLOUDSPORTSWITHGPSSTATUS_PAUSE = 0x02,      //暂停
};

/**
 * @brief 手表GPS互联实时运动启动方式定义
 */
typedef NS_ENUM(Byte, FITCLOUDSPORTSWITHGPSSTARTFROM)
{
    FITCLOUDSPORTSWITHGPSSTARTFROM_APP = 0x01,        //由APP启动
    FITCLOUDSPORTSWITHGPSSTARTFROM_WATCH = 0x02,      //由手表启动
};

#pragma mark -收款码和名片二维码类型定义

typedef NS_ENUM(Byte, FITCLOUDQRCODE)
{
    FITCLOUDQRCODE_MONEYRECEIVE_WECHAT = 0x01,        //微信收款码
    FITCLOUDQRCODE_MONEYRECEIVE_ALIPAY = 0x02,        //支付宝收款码
    FITCLOUDQRCODE_MONEYRECEIVE_PAYPAL = 0x03,        //PayPal收款码
    FITCLOUDQRCODE_MONEYRECEIVE_QQ = 0x04,            //QQ收款码
    FITCLOUDQRCODE_MONEYRECEIVE_PAYTM = 0x05,         //Paytm收款码
    FITCLOUDQRCODE_MONEYRECEIVE_PHONEPE = 0x06,       //PhonePe收款码
    FITCLOUDQRCODE_MONEYRECEIVE_GPAY = 0x07,          //GPay收款码
    FITCLOUDQRCODE_MONEYRECEIVE_BHIM = 0x08,          //BHTM收款码
    FITCLOUDQRCODE_BUSINESSCARD_WECHAT = 0x21,        //微信名片
    FITCLOUDQRCODE_BUSINESSCARD_ALIPAY = 0x22,        //支付宝名片
    FITCLOUDQRCODE_BUSINESSCARD_QQ = 0x23,            //QQ名片
    FITCLOUDQRCODE_BUSINESSCARD_FACEBOOK = 0x24,      //Facebook名片
    FITCLOUDQRCODE_BUSINESSCARD_WHATSAPP = 0x25,      //WhatsApp名片
    FITCLOUDQRCODE_BUSINESSCARD_TWITTER = 0x26,       //Twitter名片
    FITCLOUDQRCODE_BUSINESSCARD_INSTAGRAM = 0x27,     //Instagram名片
    FITCLOUDQRCODE_BUSINESSCARD_MESSENGER = 0x28,     //Messenger名片
    FITCLOUDQRCODE_BUSINESSCARD_LINE = 0x29,          //LINE名片
    FITCLOUDQRCODE_BUSINESSCARD_SNAPCHAT = 0x2A,      //Snapchat名片
    FITCLOUDQRCODE_BUSINESSCARD_SKYPE = 0x2B,         //Skype名片
    FITCLOUDQRCODE_BUSINESSCARD_EMAIL = 0x2C,         //Email名片
    FITCLOUDQRCODE_BUSINESSCARD_PHONE = 0x2D,         //Phone名片
    FITCLOUDQRCODE_BUSINESSCARD_LINKEDIN = 0x2E,      //LinkedIn名片
    FITCLOUDQRCODE_NUCLEICACID_CODE = 0x80,           //核酸码
};

#pragma mark -第三方外设

typedef NS_ENUM(Byte, THIRDPARTYPERIPHERAL)
{
    THIRDPARTYPERIPHERAL_BLOODGLUCOSEMETER = 0x01,    //血糖仪
};

#pragma mark -第三方外设操作

typedef NS_ENUM(Byte, THIRDPARTYPERIPHERALACTION)
{
    THIRDPARTYPERIPHERALACTION_STOP = 0x00,    //停止
    THIRDPARTYPERIPHERALACTION_START = 0x01,   //启动
    THIRDPARTYPERIPHERALACTION_PAUSE = 0x02,   //暂停
    THIRDPARTYPERIPHERALACTION_RESUME = 0x03,  //恢复
};

#pragma mark -第三方外设操作结果

typedef NS_ENUM(Byte, THIRDPARTYPERIPHERALACTIONRESULT)
{
    THIRDPARTYPERIPHERALACTIONRESULT_SUCCESS = 0x00,                  //成功
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICENOTEXIST = 0x01,           //设备不存在
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICENOTSUPPORT = 0x02,         //设备不支持
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICEOFFLINEORTIMEOUT = 0x03,   //设备离线或超时
    THIRDPARTYPERIPHERALACTIONRESULT_DEVICEBUSY = 0x04,               //设备忙
    THIRDPARTYPERIPHERALACTIONRESULT_UNKNOWN = 0xff,                  //设备汇报了未指定的错误
};

#pragma mark -数据同步选项

typedef NS_ENUM(Byte, FITCLOUDDATASYNCOPTION)
{
    FITCLOUDDATASYNCOPTION_LEGACY = 0x00,                           //旧的同步方式
    FITCLOUDDATASYNCOPTION_MANUALATWATCHONLY = 0x01,                //仅同步手表手动测量的
    FITCLOUDDATASYNCOPTION_ALL = 0x02,                              //全部
};

#pragma mark -手表启动震动时长

typedef NS_ENUM(Byte, FITCLOUDWATCHLAUNCHVIBRATEDURATION)
{
    FITCLOUDWATCHLAUNCHVIBRATEDURATION_EXTRASHORT = 0x00,   //单次快短震
    FITCLOUDWATCHLAUNCHVIBRATEDURATION_SHORT = 0x01,        //单次长短震
    FITCLOUDWATCHLAUNCHVIBRATEDURATION_CYCLE = 0x02,        //周期2s的震动(震0.6s停1.4s)
};


#pragma mark -手表上的GPS文件状态

typedef NS_ENUM(SInt8, FITCLOUDWATCHGPSFILESTATE)
{
    FITCLOUDWATCHGPSFILESTATE_UNKNOWN = -1,                   //未知状态
    FITCLOUDWATCHGPSFILESTATE_NOTEXIST = 0,                   //当前手表上没有GPS文件
    FITCLOUDWATCHGPSFILESTATE_GOOD = 1,                       //良好
    FITCLOUDWATCHGPSFILESTATE_NEEDUPDATE = 2,                 //未过期，但需要更新
    FITCLOUDWATCHGPSFILESTATE_OUTDATED = 3,                   //已过期
};

#pragma mark -勋章成就等级

typedef NS_ENUM(Byte, FITCLOUDMEDALACHIEVEMENTLEVEL)
{
    FITCLOUDMEDALACHIEVEMENTLEVEL_ELEMENTARY = 0,               //初级
    FITCLOUDMEDALACHIEVEMENTLEVEL_MONTHLYCHALLENGE = 1,         //月度挑战
    FITCLOUDMEDALACHIEVEMENTLEVEL_EXCEEDONESELF = 2,            //超越自我
    FITCLOUDMEDALACHIEVEMENTLEVEL_MILESTONE = 3,                //里程碑
    FITCLOUDMEDALACHIEVEMENTLEVEL_PERSISTENCEMASTER = 4,        //毅力大师
};

#pragma mark -导航信息

/// The map provider
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANMAPPROVIDER)
{
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
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANGUIDEKIND)
{
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
typedef NS_ENUM(NSInteger, FITCLOUDECARDOPERATION)
{
    /// sort
    FITCLOUDECARDOPERATION_SORT = 0x01,
    /// delete
    FITCLOUDECARDOPERATION_DEL = 0x02,
};

#pragma mark - 数据展示项

/// the workout data item display
typedef NS_ENUM(NSInteger, WORKOUTDATAITEMDISPLAY)
{
    ///运动时长
    WORKOUTDATAITEMDISPLAY_DURATION = 1,
    ///平均心率
    WORKOUTDATAITEMDISPLAY_AVG_BPM = 2,
    ///累计步数
    WORKOUTDATAITEMDISPLAY_TOTAL_STEPS = 3,
    ///运动距离
    WORKOUTDATAITEMDISPLAY_DISTANCE = 4,
    ///消耗热量
    WORKOUTDATAITEMDISPLAY_CALORIES = 5,
    ///平均速度
    WORKOUTDATAITEMDISPLAY_AVG_SPEED = 6,
    ///平均配速
    WORKOUTDATAITEMDISPLAY_AVG_PACE = 7,
    ///平均步频
    WORKOUTDATAITEMDISPLAY_AVG_STEP_CADENCE = 8,
    ///平均步幅
    WORKOUTDATAITEMDISPLAY_AVG_STEP_STRIDE = 9,
    ///累计爬升
    WORKOUTDATAITEMDISPLAY_TOTAL_CLIMBING = 10,
    ///累计下降
    WORKOUTDATAITEMDISPLAY_TOTAL_DESCENT = 11,
    ///游泳趟数
    WORKOUTDATAITEMDISPLAY_SWIM_LAPS = 12,
    ///游泳划水次数
    WORKOUTDATAITEMDISPLAY_SWIM_STROKES = 13,
    ///泳姿
    WORKOUTDATAITEMDISPLAY_SWIM_STYLE = 14,
    ///游泳划水频率
    WORKOUTDATAITEMDISPLAY_SWIM_STROKEFREQ = 15,
    ///游泳效率
    WORKOUTDATAITEMDISPLAY_SWIM_SWOLF = 16,
    ///触发次数
    WORKOUTDATAITEMDISPLAY_TRIGGER_COUNT = 17,
    ///触发频率
    WORKOUTDATAITEMDISPLAY_TRIGGERS_PER_MINUTE = 18,
    ///中断次数
    WORKOUTDATAITEMDISPLAY_BREAK_COUNT = 19,
    ///连续次数
    WORKOUTDATAITEMDISPLAY_CONSECUTIVE_COUNT = 20,
};


#pragma mark - 健康定时监测项定义

/// 健康定时监测项定义(the fitcloud interval health monitoring item)
typedef NS_ENUM(NSInteger, FITCLOUDINTEVALHEALTHMONITORINGITEM)
{
    /// 心率(heart rate)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_HEARTRATE = 0x01,
    /// 血氧(blood oxygen)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_BLOODOXYGEN = 0x02,
    /// 血压(blood pressure)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_BLOODPRESSURE = 0x03,
    /// 体温(body temperature)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_BODYTEMPERATURE = 0x04,
    /// 压力指数(stress index)
    FITCLOUDINTEVALHEALTHMONITORINGITEM_STRESSINDEX = 0x05,
};


#pragma mark - 消息通知定义

/// 消息通知定义(Message Notification)
typedef NS_OPTIONS(UInt64, FITCLOUDMN)
{
    FITCLOUDMN_NONE = 0,                        //无消息通知
    FITCLOUDMN_CALL = 1,                        //电话通知
    FITCLOUDMN_SMS = 1 << 1,                    //短信通知
    FITCLOUDMN_QQ = 1 << 2,                     //QQ通知
    FITCLOUDMN_WECHAT = 1 << 3,                 //微信通知
    FITCLOUDMN_FACEBOOK = 1 << 4,               //FACEBOOK通知
    FITCLOUDMN_TWITTER = 1 << 5,                //TWITTER通知
    FITCLOUDMN_LINKEDIN = 1 << 6,               //LINKEDIN通知
    FITCLOUDMN_INSTAGRAM = 1 << 7,              //INSTAGRAM通知
    FITCLOUDMN_PINTEREST = 1 << 8,              //PINTEREST通知
    FITCLOUDMN_WHATSAPP = 1 << 9,               //WHATSAPP通知
    FITCLOUDMN_LINE = 1 << 10,                  //LINE通知
    FITCLOUDMN_MESSENGER = 1 << 11,             //FACEBOOK MESSENGER通知
    FITCLOUDMN_KAKAO = 1 << 12,                 //KAKAO通知
    FITCLOUDMN_SKYPE = 1 << 13,                 //SKYPE通知
    FITCLOUDMN_MAIL = 1 << 14,                  //邮箱通知
    FITCLOUDMN_TELEGRAM = 1 << 15,              //TELEGRAM通知
    FITCLOUDMN_VIBER = 1 << 16,                 //VIBER通知
    FITCLOUDMN_CALENDAR = 1 << 17,              //日历消息通知
    FITCLOUDMN_SNAPCHAT = 1 << 18,              //SNAPCHAT通知
    FITCLOUDMN_HIKE = 1 << 19,                  //HIKE通知
    FITCLOUDMN_YOUTUBE = 1 << 20,               //YOUTUBE通知
    FITCLOUDMN_APPLEMUSIC = 1 << 21,            //Apple Music通知
    FITCLOUDMN_ZOOM = 1 << 22,                  //Zoom通知
    FITCLOUDMN_TIKTOK = 1 << 23,                //Tiktok通知
    FITCLOUDMN_GMAIL = 1 << 24,                 //Gmail通知
    FITCLOUDMN_OUTLOOK = 1 << 25,               //Outlook通知
    FITCLOUDMN_WHATSUPBUSINESS = 1 << 26,       //WHATSAPP BUSINESS通知
    FITCLOUDMN_FASTRACK = 1 << 27,              //Fastrack
    FITCLOUDMN_TITANSMARTWORLD = 1 << 28,       //Titan Smart World通知
    FITCLOUDMN_GPAY = 1 << 29,                  //GPAY通知
    FITCLOUDMN_AMAZON = 1 << 30,                //Amazon通知
    FITCLOUDMN_OTHER = ((UInt64)1) << 31,                 //其他APP通知
    FITCLOUDMN_PHONEPE = ((UInt64)1) << 32,               //PhonePe通知
    FITCLOUDMN_HINGE = ((UInt64)1) << 33,                 //Hinge通知
    FITCLOUDMN_FLIPKART = ((UInt64)1) << 34,              //Flipkart通知
    FITCLOUDMN_MYNTRA = ((UInt64)1) << 35,                //Myntra通知
    FITCLOUDMN_MEESHO = ((UInt64)1) << 36,                //Meesho通知
    FITCLOUDMN_ZIVAME = ((UInt64)1) << 37,                //Zivame通知
    FITCLOUDMN_AJIO = ((UInt64)1) << 38,                  //Ajio通知
    FITCLOUDMN_URBANIC = ((UInt64)1) << 39,               //Urbanic通知
    FITCLOUDMN_NYKAA = ((UInt64)1) << 40,                 //Nykaa通知
    FITCLOUDMN_HEALTHIFYME = ((UInt64)1) << 41,           //Healthifyme通知
    FITCLOUDMN_CULTFIT = ((UInt64)1) << 42,               //Cultfit通知
    FITCLOUDMN_FLO = ((UInt64)1) << 43,                   //Flo通知
    FITCLOUDMN_BUMBLE = ((UInt64)1) << 44,                //Bumble通知
    FITCLOUDMN_UBER = ((UInt64)1) << 45,                  //Uber通知
    FITCLOUDMN_SWIGGY = ((UInt64)1) << 46,                //Swiggy通知
    FITCLOUDMN_ZOMATO = ((UInt64)1) << 47,                //Zomato通知
    FITCLOUDMN_TIRA = ((UInt64)1) << 48,                  //Tira通知
};


#pragma mark - 内置个性化提醒定义(高级提醒)

/// 内置个性化提醒定义(高级提醒)
typedef NS_ENUM(Byte, FITCLOUDBUILTINPERSONALIZEDREMINDER)
{
    /// 久坐提醒
    FITCLOUDBUILTINPERSONALIZEDREMINDER_SEDENTARY = 0x00,
    
    /// 喝水提醒
    FITCLOUDBUILTINPERSONALIZEDREMINDER_WATERDRINK = 0x01,
    
    /// 吃药提醒
    FITCLOUDBUILTINPERSONALIZEDREMINDER_MEDICATION = 0x02,
};

/// 个性化提醒(高级提醒) 类型
typedef NS_ENUM(NSInteger, FITCLOUDPERSONALIZEDREMINDERTYPE)
{
    /// 未知
    FITCLOUDPERSONALIZEDREMINDERTYPE_UNKNOWN = 0x00,
    
    /// 内置
    FITCLOUDPERSONALIZEDREMINDERTYPE_BUILTIN = 0x01,
    
    /// 自定义
    FITCLOUDPERSONALIZEDREMINDERTYPE_CUSTOM = 0x02,
};

/// 个性化提醒(高级提醒) 循环周期
typedef NS_OPTIONS(Byte, FITCLOUDPERSONALIZEDREMINDERCYCLE)
{
    FITCLOUDPERSONALIZEDREMINDERCYCLE_NONE = 0,         //不循环，仅当天有效
    FITCLOUDPERSONALIZEDREMINDERCYCLE_MON = 1,          //周一(循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_TUE = 1 << 1,     //周二(循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_WED = 1 << 2,     //周三(循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_THUR = 1 << 3,    //周四(循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_FRI = 1 << 4,     //周五(循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_SAT = 1 << 5,     //周六(循环)
    FITCLOUDPERSONALIZEDREMINDERCYCLE_SUN = 1 << 6,     //周日(循环)
};

/// 个性化提醒(高级提醒) 时间类型
typedef NS_ENUM(Byte, FITCLOUDPERSONALIZEDREMINDTIMETYPE)
{
    /// 时间段
    FITCLOUDPERSONALIZEDREMINDTIMETYPE_PERIOD = 0x00,
    /// 时间点
    FITCLOUDPERSONALIZEDREMINDTIMETYPE_MOMENT = 0x01,
};

#pragma mark - 情侣

/// lover message
typedef NS_ENUM(Byte, FITCLOUDLOVERMESSAGE)
{
    /// I Miss you
    FITCLOUDLOVERMESSAGE_IMISSYOU = 0x01,
};

/// the lovers bonding notification
typedef NS_ENUM(NSInteger, FITCLOUDLOVERSBONDINGNOTIFICATION)
{
    /// bonding success
    FITCLOUDLOVERSBONDINGNOTIFICATION_BONDINGSUCCESS = 0x01,
    /// bonding cancelled
    FITCLOUDLOVERSBONDINGNOTIFICATION_BONDINGCANCELLED = 0x02,
};

/// the lovers message send result
typedef NS_ENUM(NSInteger, FITCLOUDLOVERSMESSAGESENDRESULT)
{
    /// send failed
    FITCLOUDLOVERSMESSAGESENDRESULT_FAILED = 0x00,
    /// send succeed
    FITCLOUDLOVERSMESSAGESENDRESULT_SUCCEED = 0x01,
};


#pragma mark - 天气

/// 天气类型
typedef NS_ENUM(Byte, FITCLOUDWEATHERTYPE)
{
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
    /// 中雨(moderate rain)、大雨(heavy rain)、暴雨(rainstorm)
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

typedef NS_ENUM(NSInteger, FITCLOUDWATCHCONNECTIONFLAG)
{
    /// 无
    FITCLOUDWATCHCONNECTIONFLAG_NONE = 0,
    /// 绑定连接
    FITCLOUDWATCHCONNECTIONFLAG_CONNECT = 1,
    /// 回连
    FITCLOUDWATCHCONNECTIONFLAG_RECONNECT = 2,
};

#pragma mark - 手表佩戴状态

/// 手表佩戴状态
typedef NS_ENUM(NSInteger, FITCLOUDWEARINGSTATUS)
{
    /// 未佩戴
    FITCLOUDWEARINGSTATUS_NOTWORN = 0,
    /// 佩戴
    FITCLOUDWEARINGSTATUS_WORN = 1,
};

#pragma mark - 激光测量

/// 激光测量状态
typedef NS_ENUM(NSInteger, FITCLOUDLASERMEASUREMENTSTATUS)
{
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

#endif /* FitCloudKitDefines_h */
