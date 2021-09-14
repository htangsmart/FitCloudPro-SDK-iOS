//
//  FitCloudMNDefines.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/26.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#ifndef FitCloudMNDefines_h
#define FitCloudMNDefines_h

/**
 * @brief 消息通知定义(Message Notification)
 */
typedef NS_OPTIONS(UInt32, FITCLOUDMN)
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
    FITCLOUDMN_OTHER = ((UInt32)1) << 31,       //其他APP通知
};

#endif /* FitCloudMNDefines_h */
