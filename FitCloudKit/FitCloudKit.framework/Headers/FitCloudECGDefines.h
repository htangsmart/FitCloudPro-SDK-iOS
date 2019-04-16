//
//  FitCloudECGDefines.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#ifndef FitCloudECGDefines_h
#define FitCloudECGDefines_h

/**
 * @brief 心电检测状态
 */
typedef NS_ENUM(Byte, ECGDETECTSTATUS)
{
    ECGDETECTSTATUS_FREE = 0x00,                   //心电检测空闲状态
    ECGDETECTSTATUS_DETECTING = 0x01,              //设备正在检测心电
    ECGDETECTSTATUS_SAVINGDATA = 0x02,             //设备正在保存心电数据
    ECGDETECTSTATUS_UNKNOWN = 0x03,                //未知状态
};

/**
 * @brief 心电检测事件定义(开始/结束)
 */
typedef NS_ENUM(UInt8, ECGDETECTIONEVENT)
{
    ECGDETECTIONEVENT_STOP = 0x00,                    //心电检测结束
    ECGDETECTIONEVENT_START = 0x01,                  //心电检测开始
};

/**
 * @brief 心电检测启动失败标识
 */
typedef NS_ENUM(UInt8, ECGDETCTIONSTARTERRORFLAG)
{
    ECGDETCTIONSTARTERRORFLAG_NOERROR = 0x00,        //心电检测启动未发生错误
    ECGDETCTIONSTARTERRORFLAG_ERROR = 0x01,          //心电检测启动失败
};

#endif /* FitCloudECGDefines_h */
