//
//  FCWKErrorCode.h
//  FitCloudWFKit
//
//  Created by pcjbird on 7/10/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#ifndef FCWKErrorCode_h
#define FCWKErrorCode_h

/**
 * @brief 错误码定义
 */
typedef NS_ENUM(NSInteger, FCWKERRORCODE)
{
    FCWKERRORCODE_UNKNOWN = 1000,                                //未知错误
    FCWKERRORCODE_TEMPLATEBINFILENOTEXIST = 2000,                //表盘模版bin文件不存在
    FCWKERRORCODE_BKIMAGENOTVALID = 2001,                        //表盘背景图不正确
    FCWKERRORCODE_PREVIEWNOTVALID = 2002,                        //表盘预览图不正确
    FCWKERRORCODE_TEMPLATEBINCOPYFAILURE = 2003,                 //表盘模版bin文件拷贝失败
    FCWKERRORCODE_BKIMAGEBADSIZE = 2004,                         //表盘背景图尺寸不正确
    FCWKERRORCODE_PREVIEWBADSIZE = 2005,                         //表盘预览图尺寸不正确
    FCWKERRORCODE_BKIMAGERESIZEFAILURE = 2006,                   //表盘背景图大小调整失败
    FCWKERRORCODE_PREVIEWRESIZEFAILURE = 2007,                   //表盘预览图大小调整失败
    FCWKERRORCODE_COMMONEXCEPTION = 2008,                        //生成表盘时发生异常
    FCWKERRORCODE_PARTOOLNOTFOUND = 2009,                        //未添加中科 PAR 图片压缩第三方库 ABParTool.xcframework
    FCWKERRORCODE_BADPUSHINDEX = 3001,                           //错误的表盘推送位置(索引)
    FCWKERRORCODE_TEMPLATEBINFILEBADSIZE = 3002,                 //表盘模版bin文件长度不正确
    FCWKERRORCODE_BADWATCHFACENO = 3003,                         //非法的表盘编号
    FCWKERRORCODE_BADTEMPLATEBIN = 3004,                         //表盘模版bin文件不正确
    FCWKERRORCODE_BADPHOTOCREATEPARAMETERS = 3005,               //非法的手表照片推送文件生成参数
    FCWKERRORCODE_BADFILEHANDLE = 4001,                          //非法的文件句柄
    FCWKERRORCODE_SEEKFILEOFFSETEXCEPTION = 4002,                //查找文件偏移量异常
    FCWKERRORCODE_BADFILEOFFSET = 4003,                          //非法的文件偏移量
};

#define FCWKERRORDOMAIN @"FCWKERRORDOMAIN"
#define FCWKERRORMAKE(ecode, emsg) ([NSError errorWithDomain:(FCWKERRORDOMAIN) code:(ecode) userInfo:([NSDictionary dictionaryWithObjectsAndKeys:((emsg != nil) ? emsg : @""), @"message", ((emsg != nil) ? emsg : @""), NSLocalizedDescriptionKey, ((emsg != nil) ? emsg : @""), @"description", nil])])
#endif /* FCWKErrorCode_h */
