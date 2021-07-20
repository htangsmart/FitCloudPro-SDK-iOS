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
    FITCLOUDKITERROR_USEROBJECTALREADYBOUND = 30001,         //手环已经绑定用户，请先解绑
    FITCLOUDKITERROR_USEROBJECTSHOULDBINDFIRST = 30002,      //需要先绑定用户
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
    FITCLOUDKITERROR_DFUNOTALLOWUNKNOWNREASON = 60000,       //当前不允许进入DFU模式，原因未知
    FITCLOUDKITERROR_DFUNOTALLOWFORBATTERYLOW = 60001,       //当前不允许进入DFU模式，手环电量过低
    FITCLOUDKITERROR_ALREADYINDFUMODE = 60002,               //当前已经是DFU模式
    FITCLOUDKITERROR_NOTDFUMODE = 60003,                     //当前不是DFU模式
    FITCLOUDKITERROR_FAVCONTACTSREACHMAX = 70001,            //常用联系人数量达到最大值，最多支持设定10个常用联系人
    FITCLOUDKITERROR_FAVCONTACTSNOTSUPPORT = 70002,          //当前手表不支持常用联系人
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
    FITCLOUDHARDWARE_WEATHERFORECAST = 1 << 4,        //天气预报
    FITCLOUDHARDWARE_ECG = 1 << 5,                    //心电
    FITCLOUDHARDWARE_SPORTSMODE = 1 << 6,             //运动模式
    FITCLOUDHARDWARE_WECHATSPORTS = 1 << 7,           //微信运动
    FITCLOUDHARDWARE_8762C = 1 << 8,                  //8762C新平台，升级时使用新平台升级库
    FITCLOUDHARDWARE_SHOULDSAVEHEARTRATEWHENSPORTSMODE = 1 << 9,      //运动模式保存心率数据，1.运动模式的数据item中增加心率，长度会变化，时间间隔也变化，具体看协议文档 2.App上要增加心率曲线
    FITCLOUDHARDWARE_BODYTEMPERATURE = 1 << 10,       //体温
    FITCLOUDHARDWARE_WOMENHEALTH = 1 << 11,           //女性健康
    FITCLOUDHARDWARE_VOICERECOG = 1 << 12,            //语音识别， 为1时手表上有语音识别功能，为0则手表上没有语音识别功能
    FITCLOUDHARDWARE_STRESSINDEX = 1 << 13,           //压力指数
    FITCLOUDHARDWARE_GAME = 1 << 14,                  //游戏
    FITCLOUDHARDWARE_NORDIC = 1 << 15,                //Nordic芯片
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
    FITCLOUDSPORTSTYPE_FITNESS_BRACELETONLY = 0x41,                  //健身 手环单独
    FITCLOUDSPORTSTYPE_FITNESS_BRACELETAPP = 0x42,                   //健身 手环+APP  手环连着APP时，手环上发起启动，手环和APP一起启动
    FITCLOUDSPORTSTYPE_FITNESS_APPONLY = 0x43,                       //健身 APP单独
    FITCLOUDSPORTSTYPE_FITNESS_APPBRACELET = 0x44,                   //健身 APP+手环   APP连着手环，APP上发起启动，手环和APP一起启动
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
};

#endif /* FitCloudKitDefines_h */
