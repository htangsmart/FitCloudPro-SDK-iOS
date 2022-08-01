//
//  FitCloudDFUErrorCode.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 2019/4/4.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#ifndef FitCloudDFUErrorCode_h
#define FitCloudDFUErrorCode_h

/**
 * @brief FitCloud DFU 错误码定义
 */
typedef NS_ENUM(NSInteger, FITCLOUDDFUERRORCODE)
{
    FITCLOUDDFUERRORCODE_UNKNOWN = 4000,                                //未知错误
    FITCLOUDDFUERRORCODE_BADPERIPHERAL = 4001,                          //非法的蓝牙外设
    FITCLOUDDFUERRORCODE_PERIPHERALNOTCONNECTED = 4002,                 //蓝牙外设未连接
    FITCLOUDDFUERRORCODE_BADFIRMWARE = 4003,                            //非法的固件文件
    FITCLOUDDFUERRORCODE_FIRMWAREFILENOTEXIST = 4004,                   //固件文件不存在
    FITCLOUDDFUERRORCODE_SUITABLEPROVIDERNOTFOUND = 4005,               //未能找到合适的升级程序提供者
    FITCLOUDDFUERRORCODE_ERRORDEVICEINFO = 4006,                        //DFU启动失败，错误的设备信息
    FITCLOUDDFUERRORCODE_BADIMAGE = 4007,                               //DFU启动失败，镜像错误
    FITCLOUDDFUERRORCODE_DFUMODEPERIPHERALNOTFOUND = 4008,              //升级失败，未能找到DFU模式的蓝牙外设
    FITCLOUDDFUERRORCODE_BLUETOOTHPOWEROFF = 4009,                      //升级失败，蓝牙设备已关闭
    FITCLOUDDFUERRORCODE_NOTSUPPORT = 4010,                             //模拟器下不支持固件升级操作
    FITCLOUDDFUERRORCODE_DISCONNECTED = 4011,                           //升级失败，蓝牙连接断开
    FITCLOUDDFUERRORCODE_LOWBATTERYLEVEL = 4012,                        //升级失败，电量低，电量低于30%
    FITCLOUDDFUERRORCODE_SILENTMODENOTSUPPORT = 4013,                   //升级失败，手表当前不支持静默模式升级
    FITCLOUDDFUERRORCODE_CANNOTENTEROTAMODE = 4014,                     //升级失败，普通升级无法进入OTA模式
    FITCLOUDDFUERRORCODE_CPUARCHNOTSUPPORT = 4015,                      //当前手机CPU架构不支持
    FITCLOUDDFUERRORCODE_CHIPVENDORPROGRAMEXCEPTION = 4016,             //升级失败，芯片厂商程序异常
};

#define FITCLOUDDFUERRORDOMAIN @"FITCLOUDDFUERRORDOMAIN"
#define FITCLOUDDFUERRORMAKE(ecode, emsg) ([NSError errorWithDomain:(FITCLOUDDFUERRORDOMAIN) code:(ecode) userInfo:([NSDictionary dictionaryWithObjectsAndKeys:((emsg != nil) ? emsg : @""), @"message", ((emsg != nil) ? emsg : @""), NSLocalizedDescriptionKey, ((emsg != nil) ? emsg : @""), @"description", nil])])

#endif /* FitCloudDFUErrorCode_h */
