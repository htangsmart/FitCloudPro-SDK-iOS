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
    FITCLOUDKITERROR_NOTCONNECTED = 20020,                  //尚未连接到手环设备
    FITCLOUDKITERROR_BADWRITECHARACTERISTIC = 20021,        //错误的Characteristic(写)
    FITCLOUDKITERROR_COMMUNICATIONNOTREADY = 20022,         //手环初始化尚未完成，尚不能发送通信命令
    FITCLOUDKITERROR_USEROBJECTALREADYBOUND = 30001,         //手环已经绑定用户，请先解绑
    FITCLOUDKITERROR_USEROBJECTSHOULDBINDFIRST = 30002,      //需要先绑定用户
    FITCLOUDKITERROR_DATASYNCREPEATREQUEST = 40001,          //当前正在同步历史运动健康数据，请勿重复请求
    FITCLOUDKITERROR_REQUESTSYNCDATALENFAILURE = 40002,      //请求待同步的运动健康数据总长度失败
    FITCLOUDKITERROR_BLOCKBYDATASYNC = 40003,                //当前正在同步历史运动健康数据，请稍后再试
    FITCLOUDKITERROR_DATASYNCTIMEOUT = 40004,                //历史运动健康数据同步终止，等待手环响应超时...
    FITCLOUDKITERROR_BLOCKBYECGDETECTING = 40005,            //当前手环正在心电检测，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYECGSAVINGDATA = 40006,           //当前手环正在保存心电数据，请稍后再试...
    FITCLOUDKITERROR_BLOCKBYDFUPENDINGMODE = 40007,          //当前手环处于 DFU Pending 模式，请稍后再试...
    FITCLOUDKITERROR_WEATHERFEATURENOTSUPPORT = 50001,       //当前手环不支持天气功能
    FITCLOUDKITERROR_DFUNOTALLOWUNKNOWNREASON = 60000,       //当前不允许进入DFU模式，原因未知
    FITCLOUDKITERROR_DFUNOTALLOWFORBATTERYLOW = 60001,       //当前不允许进入DFU模式，手环电量过低
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

#endif /* FitCloudKitDefines_h */
