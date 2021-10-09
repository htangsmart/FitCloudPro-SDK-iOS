//
//  FCNWKErrorCode.h
//  FitCloudNWFKit
//
//  Created by pcjbird on 2021/9/1.
//

#ifndef FCNWKErrorCode_h
#define FCNWKErrorCode_h

/**
 * @brief 错误码定义
 */
typedef NS_ENUM(NSInteger, FCNWKERRORCODE)
{
    FCNWKERRORCODE_UNKNOWN = 1000,                                //未知错误
    FCNWKERRORCODE_TEMPLATEFILECOPYFAILURE = 2003,                 //表盘模版文件拷贝失败
    FCNWKERRORCODE_BADPUSHINDEX = 3001,                           //错误的表盘推送位置(索引)
    FCNWKERRORCODE_FIRMWARE_DAT_NOTEXIST = 3002,                  //firmware.dat文件不存在
    FCNWKERRORCODE_FIRMWARE_DAT_BADSIZE = 3003,                   //firmware.dat文件大小不正确
};

#define FCNWKERRORDOMAIN @"FCNWKERRORDOMAIN"
#define FCNWKERRORMAKE(ecode, emsg) ([NSError errorWithDomain:(FCNWKERRORDOMAIN) code:(ecode) userInfo:([NSDictionary dictionaryWithObjectsAndKeys:((emsg != nil) ? emsg : @""), @"message", ((emsg != nil) ? emsg : @""), NSLocalizedDescriptionKey, ((emsg != nil) ? emsg : @""), @"description", nil])])

#endif /* FCNWKErrorCode_h */
