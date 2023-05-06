//
//  FitCloudKitDefines.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/29.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#ifndef FitCloudKitDefines_h
#define FitCloudKitDefines_h

#pragma mark - 错误码相关

/**
 * @brief FitCloudKit 错误码作用域
 */
#define FITCLOUDKITERRORDOMAIN @"FITCLOUDKITERRORDOMAIN"

/**
 * @brief FitCloudKit 错误码定义
 */
typedef NS_ENUM(NSInteger, FITCLOUDKITERROR)
{
    FITCLOUDKITERROR_UNKNOWN = 20000,                       //未知错误
    FITCLOUDKITERROR_BADSEQUENCEID = 20001,                 //错误的Sequence ID
    FITCLOUDKITERROR_PACKETSENDMAXRETRYTIMES = 20002,       //发送数据包给手环出错,重试达到最大次数
    FITCLOUDKITERROR_BADCMDPACKET = 20003,                  //非法的命令数据包，或格式不正确
    FITCLOUDKITERROR_CMDEXECTIMEOUT = 20004,                //发送给手环的命令执行超时
    FITCLOUDKITERROR_CMDCALLBACKINVALID = 20005,            //手环命令响应格式不正确
    FITCLOUDKITERROR_UNKNOWNDISCONNECTWHENCMDEXEC = 20006,  //准备执行手表命令时，发现手表意外已经断开连接
    FITCLOUDKITERROR_NOTCONNECTED = 20020,                  //尚未连接到手环设备
    FITCLOUDKITERROR_BADWRITECHARACTERISTIC = 20021,        //错误的Characteristic(写)
    FITCLOUDKITERROR_COMMUNICATIONNOTREADY = 20022,         //手环初始化尚未完成，尚不能发送通信命令
    FITCLOUDKITERROR_ANCSNOTAUTHORIZED = 20023,             //ANCS未授权，仅iOS13之后可用
    FITCLOUDKITERROR_DEVICENOTSUPPORT = 20024,              //手环不支持该功能
    FITCLOUDKITERROR_DEVICEDISCONNECTED = 20025,            //手表断开连接
    FITCLOUDKITERROR_WRONGPARAM = 20026,                    //参数错误
    FITCLOUDKITERROR_ARRAYSIZEOVERFLOW = 20027,             //数组长度溢出
    FITCLOUDKITERROR_USEROBJECTALREADYBOUND = 30001,         //手环已经绑定用户，请先解绑
    FITCLOUDKITERROR_USEROBJECTSHOULDBINDFIRST = 30002,      //需要先绑定用户
    FITCLOUDKITERROR_CANCELBYREMOTEPEER = 30003,             //手表主动取消绑定
    FITCLOUDKITERROR_CONFIRMTIMEOUTWITHREMOTEPEER = 30004,   //手表超时未点击确认绑定
    FITCLOUDKITERROR_AUDIOBLUETOOTHNOTPAIRED = 30005,        //音频蓝牙未配对
    FITCLOUDKITERROR_DATASYNCREPEATREQUEST = 40001,          //当前正在同步历史运动健康数据，请勿重复请求
    FITCLOUDKITERROR_REQUESTSYNCDATALENFAILURE = 40002,      //请求待同步的运动健康数据总长度失败
    FITCLOUDKITERROR_BLOCKBYDATASYNC = 40003,                //当前正在同步历史运动健康数据，请稍后再试
    FITCLOUDKITERROR_DATASYNCTIMEOUT = 40004,                //历史运动健康数据同步终止，等待手环响应超时...
    FITCLOUDKITERROR_BLOCKBYECGDETECTING = 40005,            //当前手环正在心电检测，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYECGSAVINGDATA = 40006,           //当前手环正在保存心电数据，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYDFUPENDINGMODE = 40007,          //当前手环处于 DFU Pending 模式，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYSYNCNESSARYSETTINGS = 40008,     //当前正在同步手环设置，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYDFUMODE = 40009,                 //当前手环处于 DFU 模式，请稍后再试...
    FITCLOUDKITERROR_WEATHERFEATURENOTSUPPORT = 50001,       //当前手环不支持天气功能
    FITCLOUDKITERROR_BADQRCODE = 50002,                      //非法的二维码内容
    FITCLOUDKITERROR_QRCODEBADLENGTH = 50003,                //二维码内容长度过长，最大长度274字节
    FITCLOUDKITERROR_BADTHIRDPARTYPERIPHERAL = 50004,        //非法的第三方外设
    FITCLOUDKITERROR_DFUNOTALLOWUNKNOWNREASON = 60000,       //当前不允许进入DFU模式，原因未知
    FITCLOUDKITERROR_DFUNOTALLOWFORBATTERYLOW = 60001,       //当前不允许进入DFU模式，手环电量过低
    FITCLOUDKITERROR_ALREADYINDFUMODE = 60002,               //当前已经是DFU模式
    FITCLOUDKITERROR_NOTDFUMODE = 60003,                     //当前不是DFU模式
    FITCLOUDKITERROR_FAVCONTACTSREACHMAX = 70001,            //常用联系人数量达到最大值，最多支持设定10个常用联系人
    FITCLOUDKITERROR_FAVCONTACTSNOTSUPPORT = 70002,          //当前手表不支持常用联系人
    FITCLOUDKITERROR_HABITSREACHMAX = 71001,                 //习惯数量达到最大值，最多支持设定10个习惯养成
    FITCLOUDKITERROR_BADHABITNAME = 71002,                   //习惯养成名称为空或长度超过限定的32字节
    FITCLOUDKITERROR_BADHABITBEGINDATE = 71003,              //习惯养成习惯开始时间为空
    FITCLOUDKITERROR_HABITSNOTSUPPORT = 71004,               //当前手表不支持习惯养成
    FITCLOUDKITERROR_CUSTOMLABELSNOTSUPPORT = 72001,         //当前手表不支持自定义标签
    FITCLOUDKITERROR_NOCHANGEWITHSETTINGS = 80001,           //当前设定没有变化
};

#pragma mark - 日志等级

/**
 * @brief FitCloudKit 日志等级定义
 */
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

/**
 * @brief FitCloudKit 蓝牙中心设备(Central)状态
 */
typedef NS_ENUM(NSInteger, FITCLOUDBLECENTRALSTATE) {
    FITCLOUDBLECENTRALSTATE_UNKNOWN = 0,
    FITCLOUDBLECENTRALSTATE_RESETTING,
    FITCLOUDBLECENTRALSTATE_UNSUPPORTED,
    FITCLOUDBLECENTRALSTATE_UNAUTHORIZED,
    FITCLOUDBLECENTRALSTATE_POWEREDOFF,
    FITCLOUDBLECENTRALSTATE_POWEREDON,
};

#pragma mark - 芯片供应商

/**
 * @brief 芯片供应商
 */
typedef NS_ENUM(NSInteger, FITCLOUDCHIPVENDOR)
{
    FITCLOUDCHIPVENDOR_UNKNOWN = 0,                //未知
    FITCLOUDCHIPVENDOR_REALTEK = 1,                //Realtek
    FITCLOUDCHIPVENDOR_NORDIC = 2,                 //Nordic
};

#pragma mark - 手环硬件

/**
 * @brief 手环硬件功能支持定义
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
};

#pragma mark - 手环显示

/**
 * @brief 手环屏幕显示定义
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
    FITCLOUDSCREENDISPLAY_MACID = 1 << 10,                 //手环Mac信息,ID
    FITCLOUDSCREENDISPLAY_UV = 1 << 11,                    //UV
    FITCLOUDSCREENDISPLAY_EARTHMAGNETICFIELD = 1 << 12,    //地磁
    FITCLOUDSCREENDISPLAY_STOPWATCH = 1 << 13,             //秒表
};

#pragma mark - 手环偏好设置

/**
 * @brief 手环偏好设置定义
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
};

#pragma mark - 手环语言
/**
 * @brief 手环语言定义
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
    FITCLOUDSLEEPQUALITY_ASLEEP = 0x01,                   //深睡/熟睡
    FITCLOUDSLEEPQUALITY_INBED = 0x02,                    //浅睡眠/躺在床上
    FITCLOUDSLEEPQUALITY_AWAKE = 0x03,                    //清醒
};

#pragma mark - 运动模式

/**
 * @brief 运动模式运动类型定义
 */
typedef NS_ENUM(UInt16, FITCLOUDSPORTSTYPE)
{
    FITCLOUDSPORTSTYPE_UNKNOWN = 0x00,                               //未知
    FITCLOUDSPORTSTYPE_RIDING_BRACELETONLY = 0x01,                   //骑行 手环单独
    FITCLOUDSPORTSTYPE_RIDING_BRACELETAPP = 0x02,                    //骑行 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_RIDING_APPONLY = 0x03,                        //骑行 APP单独
    FITCLOUDSPORTSTYPE_RIDING_APPBRACELET = 0x04,                    //骑行 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_RUNNING_BRACELETONLY = 0x05,                  //跑步 手环单独
    FITCLOUDSPORTSTYPE_RUNNING_BRACELETAPP = 0x06,                   //跑步 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_RUNNING_APPONLY = 0x07,                       //跑步 APP单独
    FITCLOUDSPORTSTYPE_RUNNING_APPBRACELET = 0x08,                   //跑步 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_TREADMILL_BRACELETONLY = 0x09,                //跑步机 手环单独
    FITCLOUDSPORTSTYPE_TREADMILL_BRACELETAPP = 0x0a,                 //跑步机 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_TREADMILL_APPONLY = 0x0b,                     //跑步机 APP单独
    FITCLOUDSPORTSTYPE_TREADMILL_APPBRACELET = 0x0c,                 //跑步机 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_WALKING_BRACELETONLY = 0x0d,                  //走路 手环单独
    FITCLOUDSPORTSTYPE_WALKING_BRACELETAPP = 0x0e,                   //走路 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_WALKING_APPONLY = 0x0f,                       //走路 APP单独
    FITCLOUDSPORTSTYPE_WALKING_APPBRACELET = 0x10,                   //走路 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_CLIMBING_BRACELETONLY = 0x11,                 //登山 手环单独
    FITCLOUDSPORTSTYPE_CLIMBING_BRACELETAPP = 0x12,                  //登山 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_CLIMBING_APPONLY = 0x13,                      //登山 APP单独
    FITCLOUDSPORTSTYPE_CLIMBING_APPBRACELET = 0x14,                  //登山 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BASKETBALL_BRACELETONLY = 0x15,               //篮球 手环单独
    FITCLOUDSPORTSTYPE_BASKETBALL_BRACELETAPP = 0x16,                //篮球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BASKETBALL_APPONLY = 0x17,                    //篮球 APP单独
    FITCLOUDSPORTSTYPE_BASKETBALL_APPBRACELET = 0x18,                //篮球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_SWIMMING_BRACELETONLY = 0x19,                 //游泳 手环单独
    FITCLOUDSPORTSTYPE_SWIMMING_BRACELETAPP = 0x1a,                  //游泳 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_SWIMMING_APPONLY = 0x1b,                      //游泳 APP单独
    FITCLOUDSPORTSTYPE_SWIMMING_APPBRACELET = 0x1c,                  //游泳 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BADMINTON_BRACELETONLY = 0x1d,                //羽毛球 手环单独
    FITCLOUDSPORTSTYPE_BADMINTON_BRACELETAPP = 0x1e,                 //羽毛球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BADMINTON_APPONLY = 0x1f,                     //羽毛球 APP单独
    FITCLOUDSPORTSTYPE_BADMINTON_APPBRACELET = 0x20,                 //羽毛球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FOOTBALL_BRACELETONLY = 0x21,                 //足球 手环单独
    FITCLOUDSPORTSTYPE_FOOTBALL_BRACELETAPP = 0x22,                  //足球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FOOTBALL_APPONLY = 0x23,                      //足球 APP单独
    FITCLOUDSPORTSTYPE_FOOTBALL_APPBRACELET = 0x24,                  //足球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ELLIPTICALMACHINE_BRACELETONLY = 0x25,        //椭圆机 手环单独
    FITCLOUDSPORTSTYPE_ELLIPTICALMACHINE_BRACELETAPP = 0x26,         //椭圆机 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ELLIPTICALMACHINE_APPONLY = 0x27,             //椭圆机 APP单独
    FITCLOUDSPORTSTYPE_ELLIPTICALMACHINE_APPBRACELET = 0x28,         //椭圆机 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_YOGA_BRACELETONLY = 0x29,                     //瑜伽 手环单独
    FITCLOUDSPORTSTYPE_YOGA_BRACELETAPP = 0x2a,                      //瑜伽 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_YOGA_APPONLY = 0x2b,                          //瑜伽 APP单独
    FITCLOUDSPORTSTYPE_YOGA_APPBRACELET = 0x2c,                      //瑜伽 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_PINGPONG_BRACELETONLY = 0x2d,                 //乒乓球 手环单独
    FITCLOUDSPORTSTYPE_PINGPONG_BRACELETAPP = 0x2e,                  //乒乓球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_PINGPONG_APPONLY = 0x2f,                      //乒乓球 APP单独
    FITCLOUDSPORTSTYPE_PINGPONG_APPBRACELET = 0x30,                  //乒乓球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ROPESKIPPING_BRACELETONLY = 0x31,             //跳绳 手环单独
    FITCLOUDSPORTSTYPE_ROPESKIPPING_BRACELETAPP = 0x32,              //跳绳 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ROPESKIPPING_APPONLY = 0x33,                  //跳绳 APP单独
    FITCLOUDSPORTSTYPE_ROPESKIPPING_APPBRACELET = 0x34,              //跳绳 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ROWINGMACHINE_BRACELETONLY = 0x35,            //划船器 手环单独
    FITCLOUDSPORTSTYPE_ROWINGMACHINE_BRACELETAPP = 0x36,             //划船器 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ROWINGMACHINE_APPONLY = 0x37,                 //划船器 APP单独
    FITCLOUDSPORTSTYPE_ROWINGMACHINE_APPBRACELET = 0x38,             //划船器 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_LAZYBIKE_BRACELETONLY = 0x39,                 //懒人车 手环单独
    FITCLOUDSPORTSTYPE_LAZYBIKE_BRACELETAPP = 0x3A,                  //懒人车 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_LAZYBIKE_APPONLY = 0x3B,                      //懒人车 APP单独
    FITCLOUDSPORTSTYPE_LAZYBIKE_APPBRACELET = 0x3C,                  //懒人车 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FITNESSBIKE_BRACELETONLY = 0x3D,              //健身车 手环单独
    FITCLOUDSPORTSTYPE_FITNESSBIKE_BRACELETAPP = 0x3E,               //健身车 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FITNESSBIKE_APPONLY = 0x3F,                   //健身车 APP单独
    FITCLOUDSPORTSTYPE_FITNESSBIKE_APPBRACELET = 0x40,               //健身车 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FREETRAINING_BRACELETONLY = 0x41,             //自由训练 手环单独
    FITCLOUDSPORTSTYPE_FREETRAINING_BRACELETAPP = 0x42,              //自由训练 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FREETRAINING_APPONLY = 0x43,                  //自由训练 APP单独
    FITCLOUDSPORTSTYPE_FREETRAINING_APPBRACELET = 0x44,              //自由训练 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_TENNIS_BRACELETONLY = 0x45,                   //网球 手环单独
    FITCLOUDSPORTSTYPE_TENNIS_BRACELETAPP = 0x46,                    //网球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_TENNIS_APPONLY = 0x47,                        //网球 APP单独
    FITCLOUDSPORTSTYPE_TENNIS_APPBRACELET = 0x48,                    //网球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BASEBALL_BRACELETONLY = 0x49,                 //棒球 手环单独
    FITCLOUDSPORTSTYPE_BASEBALL_BRACELETAPP = 0x4a,                  //棒球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BASEBALL_APPONLY = 0x4b,                      //棒球 APP单独
    FITCLOUDSPORTSTYPE_BASEBALL_APPBRACELET = 0x4c,                  //棒球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_RUGBY_BRACELETONLY = 0x4d,                    //橄榄球 手环单独
    FITCLOUDSPORTSTYPE_RUGBY_BRACELETAPP = 0x4e,                     //橄榄球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_RUGBY_APPONLY = 0x4f,                         //橄榄球 APP单独
    FITCLOUDSPORTSTYPE_RUGBY_APPBRACELET = 0x50,                     //橄榄球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_CRICKET_BRACELETONLY = 0x51,                  //板球 手环单独
    FITCLOUDSPORTSTYPE_CRICKET_BRACELETAPP = 0x52,                   //板球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_CRICKET_APPONLY = 0x53,                       //板球 APP单独
    FITCLOUDSPORTSTYPE_CRICKET_APPBRACELET = 0x54,                   //板球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_FREEMOTION_BRACELETONLY = 0x55,               //自由运动 手环单独
    FITCLOUDSPORTSTYPE_FREEMOTION_BRACELETAPP = 0x56,                //自由运动 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FREEMOTION_APPONLY = 0x57,                    //自由运动 APP单独
    FITCLOUDSPORTSTYPE_FREEMOTION_APPBRACELET = 0x58,                //自由运动 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_POWERTRAINING_BRACELETONLY = 0x59,            //力量训练 手环单独
    FITCLOUDSPORTSTYPE_POWERTRAINING_BRACELETAPP = 0x5a,             //力量训练 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_POWERTRAINING_APPONLY = 0x5b,                 //力量训练 APP单独
    FITCLOUDSPORTSTYPE_POWERTRAINING_APPBRACELET = 0x5c,             //力量训练 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_INDOORWALKING_BRACELETONLY = 0x5d,            //室内健走 手环单独
    FITCLOUDSPORTSTYPE_INDOORWALKING_BRACELETAPP = 0x5e,             //室内健走 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_INDOORWALKING_APPONLY = 0x5f,                 //室内健走 APP单独
    FITCLOUDSPORTSTYPE_INDOORWALKING_APPBRACELET = 0x60,             //室内健走 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_INDOORRIDING_BRACELETONLY = 0x61,            //室内骑行 手环单独
    FITCLOUDSPORTSTYPE_INDOORRIDING_BRACELETAPP = 0x62,             //室内骑行 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_INDOORRIDING_APPONLY = 0x63,                 //室内骑行 APP单独
    FITCLOUDSPORTSTYPE_INDOORRIDING_APPBRACELET = 0x64,             //室内骑行 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_DUMBBELL_BRACELETONLY = 0x65,                //哑铃 手环单独
    FITCLOUDSPORTSTYPE_DUMBBELL_BRACELETAPP = 0x66,                 //哑铃 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_DUMBBELL_APPONLY = 0x67,                     //哑铃 APP单独
    FITCLOUDSPORTSTYPE_DUMBBELL_APPBRACELET = 0x68,                 //哑铃 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_DANCING_BRACELETONLY = 0x69,                 //跳舞 手环单独
    FITCLOUDSPORTSTYPE_DANCING_BRACELETAPP = 0x6a,                  //跳舞 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_DANCING_APPONLY = 0x6b,                      //跳舞 APP单独
    FITCLOUDSPORTSTYPE_DANCING_APPBRACELET = 0x6c,                  //跳舞 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_HULAHOOP_BRACELETONLY = 0x6d,                 //呼啦圈 手环单独
    FITCLOUDSPORTSTYPE_HULAHOOP_BRACELETAPP = 0x6e,                  //呼啦圈 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_HULAHOOP_APPONLY = 0x6f,                      //呼啦圈 APP单独
    FITCLOUDSPORTSTYPE_HULAHOOP_APPBRACELET = 0x70,                  //呼啦圈 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_GOLF_BRACELETONLY = 0x71,                     //高尔夫 手环单独
    FITCLOUDSPORTSTYPE_GOLF_BRACELETAPP = 0x72,                      //高尔夫 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_GOLF_APPONLY = 0x73,                          //高尔夫 APP单独
    FITCLOUDSPORTSTYPE_GOLF_APPBRACELET = 0x74,                      //高尔夫 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_LONGJUMP_BRACELETONLY = 0x75,                 //跳远 手环单独
    FITCLOUDSPORTSTYPE_LONGJUMP_BRACELETAPP = 0x76,                  //跳远 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_LONGJUMP_APPONLY = 0x77,                      //跳远 APP单独
    FITCLOUDSPORTSTYPE_LONGJUMP_APPBRACELET = 0x78,                  //跳远 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_SITUP_BRACELETONLY = 0x79,                    //仰卧起坐 手环单独
    FITCLOUDSPORTSTYPE_SITUP_BRACELETAPP = 0x7a,                     //仰卧起坐 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_SITUP_APPONLY = 0x7b,                         //仰卧起坐 APP单独
    FITCLOUDSPORTSTYPE_SITUP_APPBRACELET = 0x7c,                     //仰卧起坐 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_VOLLEYBALL_BRACELETONLY = 0x7d,               //排球 手环单独
    FITCLOUDSPORTSTYPE_VOLLEYBALL_BRACELETAPP = 0x7e,                //排球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_VOLLEYBALL_APPONLY = 0x7f,                    //排球 APP单独
    FITCLOUDSPORTSTYPE_VOLLEYBALL_APPBRACELET = 0x80,                //排球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_PARKOUR_BRACELETONLY = 0x81,                  //跑酷 手环单独
    FITCLOUDSPORTSTYPE_PARKOUR_BRACELETAPP = 0x82,                   //跑酷 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_PARKOUR_APPONLY = 0x83,                       //跑酷 APP单独
    FITCLOUDSPORTSTYPE_PARKOUR_APPBRACELET = 0x84,                   //跑酷 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_ONFOOT_BRACELETONLY = 0x85,                   //徒步 手环单独
    FITCLOUDSPORTSTYPE_ONFOOT_BRACELETAPP = 0x86,                    //徒步 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_ONFOOT_APPONLY = 0x87,                        //徒步 APP单独
    FITCLOUDSPORTSTYPE_ONFOOT_APPBRACELET = 0x88,                    //徒步 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_HOCKEY_BRACELETONLY = 0x89,                   //曲棍球 手环单独
    FITCLOUDSPORTSTYPE_HOCKEY_BRACELETAPP = 0x8A,                    //曲棍球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_HOCKEY_APPONLY = 0x8B,                        //曲棍球 APP单独
    FITCLOUDSPORTSTYPE_HOCKEY_APPBRACELET = 0x8C,                    //曲棍球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_BOATING_BRACELETONLY = 0x8D,                  //划船 手环单独
    FITCLOUDSPORTSTYPE_BOATING_BRACELETAPP = 0x8E,                   //划船 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_BOATING_APPONLY = 0x8F,                       //划船 APP单独
    FITCLOUDSPORTSTYPE_BOATING_APPBRACELET = 0x90,                   //划船 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_HIIT_BRACELETONLY = 0x91,                     //HIIT 手环单独
    FITCLOUDSPORTSTYPE_HIIT_BRACELETAPP = 0x92,                      //HIIT 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_HIIT_APPONLY = 0x93,                          //HIIT APP单独
    FITCLOUDSPORTSTYPE_HIIT_APPBRACELET = 0x94,                      //HIIT APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_SOFTBALL_BRACELETONLY = 0x95,                 //垒球 手环单独
    FITCLOUDSPORTSTYPE_SOFTBALL_BRACELETAPP = 0x96,                  //垒球 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_SOFTBALL_APPONLY = 0x97,                      //垒球 APP单独
    FITCLOUDSPORTSTYPE_SOFTBALL_APPBRACELET = 0x98,                  //垒球 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_CROSSCOUNTRYRUNNING_BRACELETONLY = 0x99,       //越野跑 手环单独
    FITCLOUDSPORTSTYPE_CROSSCOUNTRYRUNNING_BRACELETAPP = 0x9A,        //越野跑 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_CROSSCOUNTRYRUNNING_APPONLY = 0x9B,            //越野跑 APP单独
    FITCLOUDSPORTSTYPE_CROSSCOUNTRYRUNNING_APPBRACELET = 0x9C,        //越野跑 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_SKIING_BRACELETONLY = 0x9D,                    //滑雪 手环单独
    FITCLOUDSPORTSTYPE_SKIING_BRACELETAPP = 0x9E,                     //滑雪 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_SKIING_APPONLY = 0x9F,                         //滑雪 APP单独
    FITCLOUDSPORTSTYPE_SKIING_APPBRACELET = 0xA0,                     //滑雪 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_STROLLER_BRACELETONLY = 0xA1,                  //漫步机 手环单独
    FITCLOUDSPORTSTYPE_STROLLER_BRACELETAPP = 0xA2,                   //漫步机 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_STROLLER_APPONLY = 0xA3,                       //漫步机 APP单独
    FITCLOUDSPORTSTYPE_STROLLER_APPBRACELET = 0xA4,                   //漫步机 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_RELAXATION_BRACELETONLY = 0xA5,                //整理放松 手环单独
    FITCLOUDSPORTSTYPE_RELAXATION_BRACELETAPP = 0xA6,                 //整理放松 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_RELAXATION_APPONLY = 0xA7,                     //整理放松 APP单独
    FITCLOUDSPORTSTYPE_RELAXATION_APPBRACELET = 0xA8,                 //整理放松 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
    
    FITCLOUDSPORTSTYPE_CROSS_TRAINING_BRACELETONLY = 0xA9,             //交叉训练（仅手环）
    FITCLOUDSPORTSTYPE_CROSS_TRAINING_BRACELETAPP = 0xAA,              //交叉训练（手环+App）
    FITCLOUDSPORTSTYPE_CROSS_TRAINING_APPONLY = 0xAB,                  //交叉训练（仅App）
    FITCLOUDSPORTSTYPE_CROSS_TRAINING_APPBRACELET = 0xAC,              //交叉训练（App+手环）
    
    FITCLOUDSPORTSTYPE_PILATES_BRACELETONLY = 0xAD,                     //普拉提（仅手环）
    FITCLOUDSPORTSTYPE_PILATES_BRACELETAPP = 0xAE,                      //普拉提（手环+App）
    FITCLOUDSPORTSTYPE_PILATES_APPONLY = 0xAF,                          //普拉提（仅App）
    FITCLOUDSPORTSTYPE_PILATES_APPBRACELET = 0xB0,                      //普拉提（App+手环）
    
    FITCLOUDSPORTSTYPE_CROSS_COORDINATION_BRACELETONLY = 0xB1,          //交叉配合（仅手环）
    FITCLOUDSPORTSTYPE_CROSS_COORDINATION_BRACELETAPP = 0xB2,           //交叉配合（手环+App）
    FITCLOUDSPORTSTYPE_CROSS_COORDINATION_APPONLY = 0xB3,               //交叉配合（仅App）
    FITCLOUDSPORTSTYPE_CROSS_COORDINATION_APPBRACELET = 0xB4,           //交叉配合（App+手环）
    
    FITCLOUDSPORTSTYPE_FUNCTIONAL_TRAINING_BRACELETONLY = 0xB5,         //功能性训练（仅手环）
    FITCLOUDSPORTSTYPE_FUNCTIONAL_TRAINING_BRACELETAPP = 0xB6,          //功能性训练（手环+App）
    FITCLOUDSPORTSTYPE_FUNCTIONAL_TRAINING_APPONLY = 0xB7,              //功能性训练（仅App）
    FITCLOUDSPORTSTYPE_FUNCTIONAL_TRAINING_APPBRACELET = 0xB8,          //功能性训练（App+手环）
    
    FITCLOUDSPORTSTYPE_PHYSICAL_FITNESS_TRAINING_BRACELETONLY = 0xB9,   //体能训练（仅手环）
    FITCLOUDSPORTSTYPE_PHYSICAL_FITNESS_TRAINING_BRACELETAPP = 0xBA,    //体能训练（手环+App）
    FITCLOUDSPORTSTYPE_PHYSICAL_FITNESS_TRAINING_APPONLY = 0xBB,        //体能训练（仅App）
    FITCLOUDSPORTSTYPE_PHYSICAL_FITNESS_TRAINING_APPBRACELET = 0xBC,    //体能训练（App+手环）
    
    FITCLOUDSPORTSTYPE_MIXED_AEROBICS_BRACELETONLY = 0xBD,              //混合有氧（仅手环）
    FITCLOUDSPORTSTYPE_MIXED_AEROBICS_BRACELETAPP = 0xBE,               //混合有氧（手环+App）
    FITCLOUDSPORTSTYPE_MIXED_AEROBICS_APPONLY = 0xBF,                   //混合有氧（仅App）
    FITCLOUDSPORTSTYPE_MIXED_AEROBICS_APPBRACELET = 0xC0,               //混合有氧（App+手环）
    
    FITCLOUDSPORTSTYPE_LATIN_DANCE_BRACELETONLY = 0xC1,                 //拉丁舞（仅手环）
    FITCLOUDSPORTSTYPE_LATIN_DANCE_BRACELETAPP = 0xC2,                  //拉丁舞（手环+App）
    FITCLOUDSPORTSTYPE_LATIN_DANCE_APPONLY = 0xC3,                      //拉丁舞（仅App）
    FITCLOUDSPORTSTYPE_LATIN_DANCE_APPBRACELET = 0xC4,                  //拉丁舞（App+手环）
    
    FITCLOUDSPORTSTYPE_STREET_DANCE_BRACELETONLY = 0xC5,                //街舞（仅手环）
    FITCLOUDSPORTSTYPE_STREET_DANCE_BRACELETAPP = 0xC6,                 //街舞（手环+App）
    FITCLOUDSPORTSTYPE_STREET_DANCE_APPONLY = 0xC7,                     //街舞（仅App）
    FITCLOUDSPORTSTYPE_STREET_DANCE_APPBRACELET = 0xC8,                 //街舞（App+手环）
    
    FITCLOUDSPORTSTYPE_MIXED_MARTIAL_ARTS_BRACELETONLY = 0xC9,          //自由搏击（仅手环）
    FITCLOUDSPORTSTYPE_MIXED_MARTIAL_ARTS_BRACELETAPP = 0xCA,           //自由搏击（手环+App）
    FITCLOUDSPORTSTYPE_MIXED_MARTIAL_ARTS_APPONLY = 0xCB,               //自由搏击（仅App）
    FITCLOUDSPORTSTYPE_MIXED_MARTIAL_ARTS_APPBRACELET = 0xCC,           //自由搏击（App+手环）
    
    FITCLOUDSPORTSTYPE_BALLET_BRACELETONLY = 0xCD,                      //芭蕾（仅手环）
    FITCLOUDSPORTSTYPE_BALLET_BRACELETAPP = 0xCE,                       //芭蕾（手环+App）
    FITCLOUDSPORTSTYPE_BALLET_APPONLY = 0xCF,                           //芭蕾（仅App）
    FITCLOUDSPORTSTYPE_BALLET_APPBRACELET = 0xD0,                       //芭蕾（App+手环）
    
    FITCLOUDSPORTSTYPE_AUSTRALIAN_RULES_FOOTBALL_BRACELETONLY = 0xD1,   //澳式足球（仅手环）
    FITCLOUDSPORTSTYPE_AUSTRALIAN_RULES_FOOTBALL_BRACELETAPP = 0xD2,    //澳式足球（手环+App）
    FITCLOUDSPORTSTYPE_AUSTRALIAN_RULES_FOOTBALL_APPONLY = 0xD3,        //澳式足球（仅App）
    FITCLOUDSPORTSTYPE_AUSTRALIAN_RULES_FOOTBALL_APPBRACELET = 0xD4,    //澳式足球（App+手环）
    
    FITCLOUDSPORTSTYPE_BOWLING_BRACELETONLY = 0xD5,                     //保龄球（仅手环）
    FITCLOUDSPORTSTYPE_BOWLING_BRACELETAPP = 0xD6,                      //保龄球（手环+App）
    FITCLOUDSPORTSTYPE_BOWLING_APPONLY = 0xD7,                          //保龄球（仅App）
    FITCLOUDSPORTSTYPE_BOWLING_APPBRACELET = 0xD8,                      //保龄球（App+手环）
    
    FITCLOUDSPORTSTYPE_SQUASH_BRACELETONLY = 0xD9,                      //壁球（仅手环）
    FITCLOUDSPORTSTYPE_SQUASH_BRACELETAPP = 0xDA,                       //壁球（手环+App）
    FITCLOUDSPORTSTYPE_SQUASH_APPONLY = 0xDB,                           //壁球（仅App）
    FITCLOUDSPORTSTYPE_SQUASH_APPBRACELET = 0xDC,                       //壁球（App+手环）
    
    FITCLOUDSPORTSTYPE_CURLING_BRACELETONLY = 0xDD,                     //冰壶（仅手环）
    FITCLOUDSPORTSTYPE_CURLING_BRACELETAPP = 0xDE,                      //冰壶（手环+App）
    FITCLOUDSPORTSTYPE_CURLING_APPONLY = 0xDF,                          //冰壶（仅App）
    FITCLOUDSPORTSTYPE_CURLING_APPBRACELET = 0xE0,                      //冰壶（App+手环）
    
    FITCLOUDSPORTSTYPE_SNOWBOARDING_BRACELETONLY = 0xE1,                //单板滑雪（仅手环）
    FITCLOUDSPORTSTYPE_SNOWBOARDING_BRACELETAPP = 0xE2,                 //单板滑雪（手环+App）
    FITCLOUDSPORTSTYPE_SNOWBOARDING_APPONLY = 0xE3,                     //单板滑雪（仅App）
    FITCLOUDSPORTSTYPE_SNOWBOARDING_APPBRACELET = 0xE4,                 //单板滑雪（App+手环）
    
    FITCLOUDSPORTSTYPE_FISHING_BRACELETONLY = 0xE5,                     //钓鱼（手环专用）
    FITCLOUDSPORTSTYPE_FISHING_BRACELETAPP = 0xE6,                      //钓鱼（手环+App）
    FITCLOUDSPORTSTYPE_FISHING_APPONLY = 0xE7,                          //钓鱼（仅限App）
    FITCLOUDSPORTSTYPE_FISHING_APPBRACELET = 0xE8,                      //钓鱼（App+手环）

    FITCLOUDSPORTSTYPE_FRISBEE_SPORTS_BRACELETONLY = 0xE9,              //飞盘运动（手环专用）
    FITCLOUDSPORTSTYPE_FRISBEE_SPORTS_BRACELETAPP = 0xEA,               //飞盘运动（手环+App）
    FITCLOUDSPORTSTYPE_FRISBEE_SPORTS_APPONLY = 0xEB,                   //飞盘运动（仅限App）
    FITCLOUDSPORTSTYPE_FRISBEE_SPORTS_APPBRACELET = 0xEC,               //飞盘运动（App+手环）

    FITCLOUDSPORTSTYPE_ALPINE_SKIING_BRACELETONLY = 0xED,               //高山滑雪（手环专用）
    FITCLOUDSPORTSTYPE_ALPINE_SKIING_BRACELETAPP = 0xEE,                //高山滑雪（手环+App）
    FITCLOUDSPORTSTYPE_ALPINE_SKIING_APPONLY = 0xEF,                    //高山滑雪（仅限App）
    FITCLOUDSPORTSTYPE_ALPINE_SKIING_APPBRACELET = 0xF0,                //高山滑雪（App+手环）

    FITCLOUDSPORTSTYPE_CORE_TRAINING_BRACELETONLY = 0xF1,                //核心训练（手环专用）
    FITCLOUDSPORTSTYPE_CORE_TRAINING_BRACELETAPP = 0xF2,                 //核心训练（手环+App）
    FITCLOUDSPORTSTYPE_CORE_TRAINING_APPONLY = 0xF3,                     //核心训练（仅限App）
    FITCLOUDSPORTSTYPE_CORE_TRAINING_APPBRACELET = 0xF4,                 //核心训练（App+手环）

    FITCLOUDSPORTSTYPE_ICE_SKATING_BRACELETONLY = 0xF5,                  //滑冰（手环专用）
    FITCLOUDSPORTSTYPE_ICE_SKATING_BRACELETAPP = 0xF6,                   //滑冰（手环+App）
    FITCLOUDSPORTSTYPE_ICE_SKATING_APPONLY = 0xF7,                       //滑冰（仅限App）
    FITCLOUDSPORTSTYPE_ICE_SKATING_APPBRACELET = 0xF8,                   //滑冰（App+手环）

    FITCLOUDSPORTSTYPE_FITNESS_GAMES_BRACELETONLY = 0xF9,               //健身游戏（手环专用）
    FITCLOUDSPORTSTYPE_FITNESS_GAMES_BRACELETAPP = 0xFA,                //健身游戏（手环+App）
    FITCLOUDSPORTSTYPE_FITNESS_GAMES_APPONLY = 0xFB,                    //健身游戏（仅限App）
    FITCLOUDSPORTSTYPE_FITNESS_GAMES_APPBRACELET = 0xFC,                //健身游戏（App+手环）

    FITCLOUDSPORTSTYPE_AEROBICS_BRACELETONLY = 0xFD,                    //健身操（手环专用）
    FITCLOUDSPORTSTYPE_AEROBICS_BRACELETAPP = 0xFE,                     //健身操（手环+App）
    FITCLOUDSPORTSTYPE_AEROBICS_APPONLY = 0xFF,                         //健身操（仅限App）
    FITCLOUDSPORTSTYPE_AEROBICS_APPBRACELET = 0x100,                    //健身操（App+手环）

    FITCLOUDSPORTSTYPE_GROUP_GYMNASTICS_BRACELETONLY = 0x101,           //团体操（手环专用）
    FITCLOUDSPORTSTYPE_GROUP_GYMNASTICS_BRACELETAPP = 0x102,            //团体操（手环+App）
    FITCLOUDSPORTSTYPE_GROUP_GYMNASTICS_APPONLY = 0x103,                //团体操（仅限App）
    FITCLOUDSPORTSTYPE_GROUP_GYMNASTICS_APPBRACELET = 0x104,            //团体操（App+手环）

    FITCLOUDSPORTSTYPE_COMBAT_AEROBICS_BRACELETONLY = 0x105,            //搏击操（手环专用）
    FITCLOUDSPORTSTYPE_COMBAT_AEROBICS_BRACELETAPP = 0x106,             //搏击操（手环+App）
    FITCLOUDSPORTSTYPE_COMBAT_AEROBICS_APPONLY = 0x107,                 //搏击操（仅限App）
    FITCLOUDSPORTSTYPE_COMBAT_AEROBICS_APPBRACELET = 0x108,             //搏击操（App+手环）

    FITCLOUDSPORTSTYPE_FENCING_BRACELETONLY = 0x109,                    //击剑（手环专用）
    FITCLOUDSPORTSTYPE_FENCING_BRACELETAPP = 0x10A,                     //击剑（手环+App）
    FITCLOUDSPORTSTYPE_FENCING_APPONLY = 0x10B,                         //击剑（仅限App）
    FITCLOUDSPORTSTYPE_FENCING_APPBRACELET = 0x10C,                     //击剑（App+手环）

    FITCLOUDSPORTSTYPE_STAIR_CLIMBING_BRACELETONLY = 0x10D,             //爬楼梯（手环专用）
    FITCLOUDSPORTSTYPE_STAIR_CLIMBING_BRACELETAPP = 0x10E,              //爬楼梯（手环+App）
    FITCLOUDSPORTSTYPE_STAIR_CLIMBING_APPONLY = 0x10F,                  //爬楼梯（仅限App）
    FITCLOUDSPORTSTYPE_STAIR_CLIMBING_APPBRACELET = 0x110,              //爬楼梯（App+手环）

    FITCLOUDSPORTSTYPE_AMERICAN_FOOTBALL_BRACELETONLY = 0x111,          //美式橄榄球（手环专用）
    FITCLOUDSPORTSTYPE_AMERICAN_FOOTBALL_BRACELETAPP = 0x112,           //美式橄榄球（手环+App）
    FITCLOUDSPORTSTYPE_AMERICAN_FOOTBALL_APPONLY = 0x113,               //美式橄榄球（仅限App）
    FITCLOUDSPORTSTYPE_AMERICAN_FOOTBALL_APPBRACELET = 0x114,           //美式橄榄球（App+手环）

    FITCLOUDSPORTSTYPE_FOAM_ROLLER_MYOFASCIAL_RELEASE_BRACELETONLY = 0x115, //泡沫滚筒筋膜放松（手环专用）
    FITCLOUDSPORTSTYPE_FOAM_ROLLER_MYOFASCIAL_RELEASE_BRACELETAPP = 0x116,  //泡沫滚筒筋膜放松（手环+App）
    FITCLOUDSPORTSTYPE_FOAM_ROLLER_MYOFASCIAL_RELEASE_APPONLY = 0x117,      //泡沫滚筒筋膜放松（仅限App）
    FITCLOUDSPORTSTYPE_FOAM_ROLLER_MYOFASCIAL_RELEASE_APPBRACELET = 0x118,  //泡沫滚筒筋膜放松（App+手环）

    FITCLOUDSPORTSTYPE_PICKLEBALL_BRACELETONLY = 0x119,                     //匹克球（手环专用）
    FITCLOUDSPORTSTYPE_PICKLEBALL_BRACELETAPP = 0x11A,                      //匹克球（手环+App）
    FITCLOUDSPORTSTYPE_PICKLEBALL_APPONLY = 0x11B,                          //匹克球（仅限App）
    FITCLOUDSPORTSTYPE_PICKLEBALL_APPBRACELET = 0x11C,                      //匹克球（App+手环）

    FITCLOUDSPORTSTYPE_BOXING_BRACELETONLY = 0x11D,                         //拳击（手环专用）
    FITCLOUDSPORTSTYPE_BOXING_BRACELETAPP = 0x11E,                          //拳击（手环+App）
    FITCLOUDSPORTSTYPE_BOXING_APPONLY = 0x11F,                              //拳击（仅限App）
    FITCLOUDSPORTSTYPE_BOXING_APPBRACELET = 0x120,                          //拳击（App+手环）

    FITCLOUDSPORTSTYPE_TAEKWONDO_BRACELETONLY = 0x121,                      //跆拳道（手环专用）
    FITCLOUDSPORTSTYPE_TAEKWONDO_BRACELETAPP = 0x122,                       //跆拳道（手环+App）
    FITCLOUDSPORTSTYPE_TAEKWONDO_APPONLY = 0x123,                           //跆拳道（仅限App）
    FITCLOUDSPORTSTYPE_TAEKWONDO_APPBRACELET = 0x124,                       //跆拳道（App+手环）

    FITCLOUDSPORTSTYPE_KARATE_BRACELETONLY = 0x125,                         //空手道（手环专用）
    FITCLOUDSPORTSTYPE_KARATE_BRACELETAPP = 0x126,                          //空手道（手环+App）
    FITCLOUDSPORTSTYPE_KARATE_APPONLY = 0x127,                              //空手道（仅限App）
    FITCLOUDSPORTSTYPE_KARATE_APPBRACELET = 0x128,                          //空手道（App+手环）

    FITCLOUDSPORTSTYPE_FLEXIBILITY_BRACELETONLY = 0x129,                    //柔韧度（手环专用）
    FITCLOUDSPORTSTYPE_FLEXIBILITY_BRACELETAPP = 0x12A,                     //柔韧度（手环+App）
    FITCLOUDSPORTSTYPE_FLEXIBILITY_APPONLY = 0x12B,                         //柔韧度（仅限App）
    FITCLOUDSPORTSTYPE_FLEXIBILITY_APPBRACELET = 0x12C,                     //柔韧度（App+手环）

    FITCLOUDSPORTSTYPE_HANDBALL_BRACELETONLY = 0x12D,                       //手球（手环专用）
    FITCLOUDSPORTSTYPE_HANDBALL_BRACELETAPP = 0x12E,                        //手球（手环+App）
    FITCLOUDSPORTSTYPE_HANDBALL_APPONLY = 0x12F,                            //手球（仅限App）
    FITCLOUDSPORTSTYPE_HANDBALL_APPBRACELET = 0x130,                        //手球（App+手环）

    FITCLOUDSPORTSTYPE_HAND_CRANK_VEHICLE_BRACELETONLY = 0x131,             //手摇车（手环专用）
    FITCLOUDSPORTSTYPE_HAND_CRANK_VEHICLE_BRACELETAPP = 0x132,              //手摇车（手环+App）
    FITCLOUDSPORTSTYPE_HAND_CRANK_VEHICLE_APPONLY = 0x133,                  //手摇车（仅限App）
    FITCLOUDSPORTSTYPE_HAND_CRANK_VEHICLE_APPBRACELET = 0x134,              //手摇车（App+手环）

    FITCLOUDSPORTSTYPE_RELAXATION_AND_MEDITATION_EXERCISES_BRACELETONLY = 0x135, //舒缓冥想类运动（手环专用）
    FITCLOUDSPORTSTYPE_RELAXATION_AND_MEDITATION_EXERCISES_BRACELETAPP = 0x136,  //舒缓冥想类运动（手环+App）
    FITCLOUDSPORTSTYPE_RELAXATION_AND_MEDITATION_EXERCISES_APPONLY = 0x137,      //舒缓冥想类运动（仅限App）
    FITCLOUDSPORTSTYPE_RELAXATION_AND_MEDITATION_EXERCISES_APPBRACELET = 0x138,  //舒缓冥想类运动（App+手环）

    FITCLOUDSPORTSTYPE_WRESTLING_BRACELETONLY = 0x139,                      //摔跤（手环专用）
    FITCLOUDSPORTSTYPE_WRESTLING_BRACELETAPP = 0x13A,                       //摔跤（手环+App）
    FITCLOUDSPORTSTYPE_WRESTLING_APPONLY = 0x13B,                           //摔跤（仅限App）
    FITCLOUDSPORTSTYPE_WRESTLING_APPBRACELET = 0x13C,                       //摔跤（App+手环）

    FITCLOUDSPORTSTYPE_STEP_TRAINING_BRACELETONLY = 0x013D,                 //踏步训练（手环专用）
    FITCLOUDSPORTSTYPE_STEP_TRAINING_BRACELETAPP = 0x013E,                  //踏步训练（手环+App）
    FITCLOUDSPORTSTYPE_STEP_TRAINING_APPONLY = 0x013F,                      //踏步训练（仅限App）
    FITCLOUDSPORTSTYPE_STEP_TRAINING_APPBRACELET = 0x0140,                  //踏步训练（App+手环）
    
    FITCLOUDSPORTSTYPE_TAI_CHI_BRACELETONLY = 0x0141,                       //太极（手环专用）
    FITCLOUDSPORTSTYPE_TAI_CHI_BRACELETAPP = 0x0142,                        //太极（手环+App）
    FITCLOUDSPORTSTYPE_TAI_CHI_APPONLY = 0x0143,                            //太极（仅限App）
    FITCLOUDSPORTSTYPE_TAI_CHI_APPBRACELET = 0x0144,                        //太极（App+手环）
    
    FITCLOUDSPORTSTYPE_GYMNASTICS_BRACELETONLY = 0x0145,                    //体操（手环专用）
    FITCLOUDSPORTSTYPE_GYMNASTICS_BRACELETAPP = 0x0146,                     //体操（手环+App）
    FITCLOUDSPORTSTYPE_GYMNASTICS_APPONLY = 0x0147,                         //体操（仅限App）
    FITCLOUDSPORTSTYPE_GYMNASTICS_APPBRACELET = 0x0148,                     //体操（App+手环）
    
    FITCLOUDSPORTSTYPE_TRACK_AND_FIELD_BRACELETONLY = 0x0149,                //田径（手环专用）
    FITCLOUDSPORTSTYPE_TRACK_AND_FIELD_BRACELETAPP = 0x014A,                 //田径（手环+App）
    FITCLOUDSPORTSTYPE_TRACK_AND_FIELD_APPONLY = 0x014B,                     //田径（仅限App）
    FITCLOUDSPORTSTYPE_TRACK_AND_FIELD_APPBRACELET = 0x014C,                 //田径（App+手环）
    
    FITCLOUDSPORTSTYPE_MARTIAL_ARTS_BRACELETONLY = 0x014D,                    //武术（手环专用）
    FITCLOUDSPORTSTYPE_MARTIAL_ARTS_BRACELETAPP = 0x014E,                     //武术（手环+App）
    FITCLOUDSPORTSTYPE_MARTIAL_ARTS_APPONLY = 0x014F,                         //武术（仅限App）
    FITCLOUDSPORTSTYPE_MARTIAL_ARTS_APPBRACELET = 0x0150,                     //武术（App+手环）
    
    FITCLOUDSPORTSTYPE_RECREATIONAL_SPORTS_BRACELETONLY = 0x0151,             //休闲运动（手环专用）
    FITCLOUDSPORTSTYPE_RECREATIONAL_SPORTS_BRACELETAPP = 0x0152,              //休闲运动（手环+App）
    FITCLOUDSPORTSTYPE_RECREATIONAL_SPORTS_APPONLY = 0x0153,                  //休闲运动（仅限App）
    FITCLOUDSPORTSTYPE_RECREATIONAL_SPORTS_APPBRACELET = 0x0154,              //休闲运动（App+手环）
    
    FITCLOUDSPORTSTYPE_SNOW_SPORTS_BRACELETONLY = 0x0155,                     //雪上运动（手环专用）
    FITCLOUDSPORTSTYPE_SNOW_SPORTS_BRACELETAPP = 0x0156,                      //雪上运动（手环+App）
    FITCLOUDSPORTSTYPE_SNOW_SPORTS_APPONLY = 0x0157,                          //雪上运动（仅限App）
    FITCLOUDSPORTSTYPE_SNOW_SPORTS_APPBRACELET = 0x0158,                      //雪上运动（App+手环）
    
    FITCLOUDSPORTSTYPE_LACROSSE_BRACELETONLY = 0x0159,                        //长曲棍球（手环专用）
    FITCLOUDSPORTSTYPE_LACROSSE_BRACELETAPP = 0x015A,                         //长曲棍球（手环+App）
    FITCLOUDSPORTSTYPE_LACROSSE_APPONLY = 0x015B,                             //长曲棍球（仅限App）
    FITCLOUDSPORTSTYPE_LACROSSE_APPBRACELET = 0x015C,                         //长曲棍球（App+手环）
    
    FITCLOUDSPORTSTYPE_HORIZONTAL_BARS_BRACELETONLY = 0x015D,                 //单杠（手环专用）
    FITCLOUDSPORTSTYPE_HORIZONTAL_BARS_BRACELETAPP = 0x015E,                  //单杠（手环+App）
    FITCLOUDSPORTSTYPE_HORIZONTAL_BARS_APPONLY = 0x015F,                      //单杠（仅限App）
    FITCLOUDSPORTSTYPE_HORIZONTAL_BARS_APPBRACELET = 0x0160,                  //单杠（App+手环）
    
    FITCLOUDSPORTSTYPE_PARALLEL_BARS_BRACELETONLY = 0x0161,                   //双杠（手环专用）
    FITCLOUDSPORTSTYPE_PARALLEL_BARS_BRACELETAPP = 0x0162,                    //双杠（手环+App）
    FITCLOUDSPORTSTYPE_PARALLEL_BARS_APPONLY = 0x0163,                        //双杠（仅限App）
    FITCLOUDSPORTSTYPE_PARALLEL_BARS_APPBRACELET = 0x0164,                    //双杠（App+手环）

    FITCLOUDSPORTSTYPE_ROLLER_SKATING_BRACELETONLY = 0x0165,                  //轮滑（手环专用）
    FITCLOUDSPORTSTYPE_ROLLER_SKATING_BRACELETAPP = 0x0166,                   //轮滑（手环+App）
    FITCLOUDSPORTSTYPE_ROLLER_SKATING_APPONLY = 0x0167,                       //轮滑（仅限App）
    FITCLOUDSPORTSTYPE_ROLLER_SKATING_APPBRACELET = 0x0168,                   //轮滑（App+手环）
    
    FITCLOUDSPORTSTYPE_DARTS_BRACELETONLY = 0x0169,                           //飞镖（手环专用）
    FITCLOUDSPORTSTYPE_DARTS_BRACELETAPP = 0x016A,                            //飞镖（手环+App）
    FITCLOUDSPORTSTYPE_DARTS_APPONLY = 0x016B,                                //飞镖（仅限App）
    FITCLOUDSPORTSTYPE_DARTS_APPBRACELET = 0x016C,                            //飞镖（App+手环）
    
    FITCLOUDSPORTSTYPE_ARCHERY_BRACELETONLY = 0x016D,                         //射箭（手环专用）
    FITCLOUDSPORTSTYPE_ARCHERY_BRACELETAPP = 0x016E,                          //射箭（手环+App）
    FITCLOUDSPORTSTYPE_ARCHERY_APPONLY = 0x016F,                              //射箭（仅限App）
    FITCLOUDSPORTSTYPE_ARCHERY_APPBRACELET = 0x0170,                          //射箭（App+手环）
    
    FITCLOUDSPORTSTYPE_HORSEBACK_RIDING_BRACELETONLY = 0x0171,                //骑马（手环专用）
    FITCLOUDSPORTSTYPE_HORSEBACK_RIDING_BRACELETAPP = 0x0172,                 //骑马（手环+App）
    FITCLOUDSPORTSTYPE_HORSEBACK_RIDING_APPONLY = 0x0173,                     //骑马（仅限App）
    FITCLOUDSPORTSTYPE_HORSEBACK_RIDING_APPBRACELET = 0x0174,                 //骑马（App+手环）
    
    FITCLOUDSPORTSTYPE_JIANZI_BRACELETONLY = 0x0175,                          //毽球（手环专用）
    FITCLOUDSPORTSTYPE_JIANZI_BRACELETAPP = 0x0176,                           //毽球（手环+App）
    FITCLOUDSPORTSTYPE_JIANZI_APPONLY = 0x0177,                               //毽球（仅限App）
    FITCLOUDSPORTSTYPE_JIANZI_APPBRACELET = 0x0178,                           //毽球（App+手环）

    FITCLOUDSPORTSTYPE_ICE_HOCKEY_BRACELETONLY = 0x0179,                      //冰球（手环专用）
    FITCLOUDSPORTSTYPE_ICE_HOCKEY_BRACELETAPP = 0x017A,                       //冰球（手环+APP）
    FITCLOUDSPORTSTYPE_ICE_HOCKEY_APPONLY = 0x017B,                           //冰球（仅APP）
    FITCLOUDSPORTSTYPE_ICE_HOCKEY_APPBRACELET = 0x017C,                       //冰球（APP+手环）
    
    FITCLOUDSPORTSTYPE_WAIST_AND_ABDOMEN_TRAINING_BRACELETONLY = 0x017D,      //腰腹训练（手环专用）
    FITCLOUDSPORTSTYPE_WAIST_AND_ABDOMEN_TRAINING_BRACELETAPP = 0x017E,       //腰腹训练（手环+APP）
    FITCLOUDSPORTSTYPE_WAIST_AND_ABDOMEN_TRAINING_APPONLY = 0x017F,           //腰腹训练（仅APP）
    FITCLOUDSPORTSTYPE_WAIST_AND_ABDOMEN_TRAINING_APPBRACELET = 0x0180,       //腰腹训练（APP+手环）
    
    FITCLOUDSPORTSTYPE_MAXIMUM_OXYGEN_UPTAKE_TEST_BRACELETONLY = 0x0181,      //最大摄氧量测试（手环专用）
    FITCLOUDSPORTSTYPE_MAXIMUM_OXYGEN_UPTAKE_TEST_BRACELETAPP = 0x0182,       //最大摄氧量测试（手环+APP）
    FITCLOUDSPORTSTYPE_MAXIMUM_OXYGEN_UPTAKE_TEST_APPONLY = 0x0183,           //最大摄氧量测试（仅APP）
    FITCLOUDSPORTSTYPE_MAXIMUM_OXYGEN_UPTAKE_TEST_APPBRACELET = 0x0184,       //最大摄氧量测试（APP+手环）
    
    FITCLOUDSPORTSTYPE_JUDO_BRACELETONLY = 0x0185,                            //柔道（手环专用）
    FITCLOUDSPORTSTYPE_JUDO_BRACELETAPP = 0x0186,                             //柔道（手环+APP）
    FITCLOUDSPORTSTYPE_JUDO_APPONLY = 0x0187,                                 //柔道（仅APP）
    FITCLOUDSPORTSTYPE_JUDO_APPBRACELET = 0x0188,                             //柔道（APP+手环）
    
    FITCLOUDSPORTSTYPE_TRAMPOLINING_BRACELETONLY = 0x0189,                    //蹦床（手环专用）
    FITCLOUDSPORTSTYPE_TRAMPOLINING_BRACELETAPP = 0x018A,                     //蹦床（手环+APP）
    FITCLOUDSPORTSTYPE_TRAMPOLINING_APPONLY = 0x018B,                         //蹦床（仅APP）
    FITCLOUDSPORTSTYPE_TRAMPOLINING_APPBRACELET = 0x018C,                     //蹦床（APP+手环）
    
    FITCLOUDSPORTSTYPE_SKATEBOARDING_BRACELETONLY = 0x018D,                   //滑板（手环专用）
    FITCLOUDSPORTSTYPE_SKATEBOARDING_BRACELETAPP = 0x018E,                    //滑板（手环+APP）
    FITCLOUDSPORTSTYPE_SKATEBOARDING_APPONLY = 0x018F,                        //滑板（仅APP）
    FITCLOUDSPORTSTYPE_SKATEBOARDING_APPBRACELET = 0x0190,                    //滑板（APP+手环）
    
    FITCLOUDSPORTSTYPE_BALANCING_SCOOTER_BRACELETONLY = 0x0191,               //平衡车（手环专用）
    FITCLOUDSPORTSTYPE_BALANCING_SCOOTER_BRACELETAPP = 0x0192,                //平衡车（手环+APP）
    FITCLOUDSPORTSTYPE_BALANCING_SCOOTER_APPONLY = 0x0193,                    //平衡车（仅APP）
    FITCLOUDSPORTSTYPE_BALANCING_SCOOTER_APPBRACELET = 0x0194,                //平衡车（APP+手环）
    
    FITCLOUDSPORTSTYPE_BLADING_BRACELETONLY = 0x0195,                         //溜旱冰（手环专用）
    FITCLOUDSPORTSTYPE_BLADING_BRACELETAPP = 0x0196,                          //溜旱冰（手环+APP）
    FITCLOUDSPORTSTYPE_BLADING_APPONLY = 0x0197,                              //溜旱冰（仅APP）
    FITCLOUDSPORTSTYPE_BLADING_APPBRACELET = 0x0198,                          //溜旱冰（APP+手环）
    
    FITCLOUDSPORTSTYPE_INDOOR_RUNNING_BRACELETONLY = 0x0199,                  //室内跑步（手环专用）
    FITCLOUDSPORTSTYPE_INDOOR_RUNNING_BRACELETAPP = 0x019A,                   //室内跑步（手环+APP）
    FITCLOUDSPORTSTYPE_INDOOR_RUNNING_APPONLY = 0x019B,                       //室内跑步（仅APP）
    FITCLOUDSPORTSTYPE_INDOOR_RUNNING_APPBRACELET = 0x019C,                   //室内跑步（APP+手环）
    
    FITCLOUDSPORTSTYPE_DIVING_BRACELETONLY = 0x019D,                          //跳水（手环专用）
    FITCLOUDSPORTSTYPE_DIVING_BRACELETAPP = 0x019E,                           //跳水（手环+APP）
    FITCLOUDSPORTSTYPE_DIVING_APPONLY = 0x019F,                               //跳水（仅APP）
    FITCLOUDSPORTSTYPE_DIVING_APPBRACELET = 0x01A0,                           //跳水（APP+手环）
    
    FITCLOUDSPORTSTYPE_SURFING_BRACELETONLY = 0x01A1,                         //冲浪（手环专用）
    FITCLOUDSPORTSTYPE_SURFING_BRACELETAPP = 0x01A2,                          //冲浪（手环+APP）
    FITCLOUDSPORTSTYPE_SURFING_APPONLY = 0x01A3,                              //冲浪（仅APP）
    FITCLOUDSPORTSTYPE_SURFING_APPBRACELET = 0x01A4,                          //冲浪（APP+手环）
    
    FITCLOUDSPORTSTYPE_SNORKELING_BRACELETONLY = 0x01A5,                      //浮潜（手环专用）
    FITCLOUDSPORTSTYPE_SNORKELING_BRACELETAPP = 0x01A6,                       //浮潜（手环+APP）
    FITCLOUDSPORTSTYPE_SNORKELING_APPONLY = 0x01A7,                           //浮潜（仅APP）
    FITCLOUDSPORTSTYPE_SNORKELING_APPBRACELET = 0x01A8,                       //浮潜（APP+手环）
    
    FITCLOUDSPORTSTYPE_PULL_UPS_BRACELETONLY = 0x01A9,                        //引体向上（手环专用）
    FITCLOUDSPORTSTYPE_PULL_UPS_BRACELETAPP = 0x01AA,                         //引体向上（手环+APP）
    FITCLOUDSPORTSTYPE_PULL_UPS_APPONLY = 0x01AB,                             //引体向上（仅APP）
    FITCLOUDSPORTSTYPE_PULL_UPS_APPBRACELET = 0x01AC,                         //引体向上（APP+手环）
    
    FITCLOUDSPORTSTYPE_PUSH_UPS_BRACELETONLY = 0x01AD,                        //俯卧撑（手环专用）
    FITCLOUDSPORTSTYPE_PUSH_UPS_BRACELETAPP = 0x01AE,                         //俯卧撑（手环+APP）
    FITCLOUDSPORTSTYPE_PUSH_UPS_APPONLY = 0x01AF,                             //俯卧撑（仅APP）
    FITCLOUDSPORTSTYPE_PUSH_UPS_APPBRACELET = 0x01B0,                         //俯卧撑（APP+手环）
    
    FITCLOUDSPORTSTYPE_PLANK_BRACELETONLY = 0x01B1,                           //平板支撑（仅手环）
    FITCLOUDSPORTSTYPE_PLANK_BRACELETAPP = 0x01B2,                            //平板支撑（手环+APP）
    FITCLOUDSPORTSTYPE_PLANK_APPONLY = 0x01B3,                                //平板支撑（仅APP）
    FITCLOUDSPORTSTYPE_PLANK_APPBRACELET = 0x01B4,                            //平板支撑（APP+手环）
    
    FITCLOUDSPORTSTYPE_ROCK_CLIMBING_BRACELETONLY = 0x01B5,                   //攀岩（仅手环）
    FITCLOUDSPORTSTYPE_ROCK_CLIMBING_BRACELETAPP = 0x01B6,                    //攀岩（手环+APP）
    FITCLOUDSPORTSTYPE_ROCK_CLIMBING_APPONLY = 0x01B7,                        //攀岩（仅APP）
    FITCLOUDSPORTSTYPE_ROCK_CLIMBING_APPBRACELET = 0x01B8,                    //攀岩（APP+手环）
    
    FITCLOUDSPORTSTYPE_HIGH_JUMP_BRACELETONLY = 0x01B9,                       //跳高（仅手环）
    FITCLOUDSPORTSTYPE_HIGH_JUMP_BRACELETAPP = 0x01BA,                        //跳高（手环+APP）
    FITCLOUDSPORTSTYPE_HIGH_JUMP_APPONLY = 0x01BB,                            //跳高（仅APP）
    FITCLOUDSPORTSTYPE_HIGH_JUMP_APPBRACELET = 0x01BC,                        //跳高（APP+手环）
    
    FITCLOUDSPORTSTYPE_BUNGEE_JUMPING_BRACELETONLY = 0x01BD,                  //蹦极（仅手环）
    FITCLOUDSPORTSTYPE_BUNGEE_JUMPING_BRACELETAPP = 0x01BE,                   //蹦极（手环+APP）
    FITCLOUDSPORTSTYPE_BUNGEE_JUMPING_APPONLY = 0x01BF,                       //蹦极（仅APP）
    FITCLOUDSPORTSTYPE_BUNGEE_JUMPING_APPBRACELET = 0x01C0,                   //蹦极（APP+手环）
    
    FITCLOUDSPORTSTYPE_ETHNIC_DANCE_BRACELETONLY = 0x01C1,                    //民族舞（仅手环）
    FITCLOUDSPORTSTYPE_ETHNIC_DANCE_BRACELETAPP = 0x01C2,                     //民族舞（手环+APP）
    FITCLOUDSPORTSTYPE_ETHNIC_DANCE_APPONLY = 0x01C3,                         //民族舞（仅APP）
    FITCLOUDSPORTSTYPE_ETHNIC_DANCE_APPBRACELET = 0x01C4,                     //民族舞（APP+手环）
    
    FITCLOUDSPORTSTYPE_HUNTING_BRACELETONLY = 0x01C5,                         //狩猎（仅手环）
    FITCLOUDSPORTSTYPE_HUNTING_BRACELETAPP = 0x01C6,                          //狩猎（手环+APP）
    FITCLOUDSPORTSTYPE_HUNTING_APPONLY = 0x01C7,                              //狩猎（仅APP）
    FITCLOUDSPORTSTYPE_HUNTING_APPBRACELET = 0x01C8,                          //狩猎（APP+手环）
    
    FITCLOUDSPORTSTYPE_SHOOTING_BRACELETONLY = 0x01C9,                        //射击（仅手环）
    FITCLOUDSPORTSTYPE_SHOOTING_BRACELETAPP = 0x01CA,                         //射击（手环+APP）
    FITCLOUDSPORTSTYPE_SHOOTING_APPONLY = 0x01CB,                             //射击（仅APP）
    FITCLOUDSPORTSTYPE_SHOOTING_APPBRACELET = 0x01CC,                         //射击（APP+手环）

    FITCLOUDSPORTSTYPE_MARATHON_BRACELETONLY = 0x01CD,                        //马拉松（仅手环）
    FITCLOUDSPORTSTYPE_MARATHON_BRACELETAPP = 0x01CE,                         //马拉松（手环+APP）
    FITCLOUDSPORTSTYPE_MARATHON_APPONLY = 0x01CF,                             //马拉松（仅APP）
    FITCLOUDSPORTSTYPE_MARATHON_APPBRACELET = 0x01D0,                         //马拉松（APP+手环）
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

#pragma mark - 表盘相关

/**
 * @brief 表盘Item标志
*/
typedef NS_ENUM(Byte, WATCHFACEITEMFLAG)
{
    WATCHFACEITEMFLAG_BUILTIN = 0x00,                               //当前表盘编号位置为内置，不可推送的
    WATCHFACEITEMFLAG_ALLOWPUSH = 0x10,                             //当前表盘编号位置可推送表盘，可根据表盘编号获取缩略图显示
    WATCHFACEITEMFLAG_THUMBNAIL_CUSTOMSTYPE1 = 0x20,                //当前表盘编号位置可推送表盘，缩略图显示自定义表盘样式1
    WATCHFACEITEMFLAG_THUMBNAIL_CUSTOMSTYPE2 = 0x21,                //当前表盘编号位置可推送表盘，缩略图显示自定义表盘样式2
    WATCHFACEITEMFLAG_THUMBNAIL_CUSTOMSTYPE3 = 0x22,                //当前表盘编号位置可推送表盘，缩略图显示自定义表盘样式3
    WATCHFACEITEMFLAG_THUMBNAIL_CUSTOMSTYPE4 = 0x23,                //当前表盘编号位置可推送表盘，缩略图显示自定义表盘样式4
    WATCHFACEITEMFLAG_THUMBNAIL_CUSTOMSTYPE5 = 0x24,                //当前表盘编号位置可推送表盘，缩略图显示自定义表盘样式5
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

#endif /* FitCloudKitDefines_h */
