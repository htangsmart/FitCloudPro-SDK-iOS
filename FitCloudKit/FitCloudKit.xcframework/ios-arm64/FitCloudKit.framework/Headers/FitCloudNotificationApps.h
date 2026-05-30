//
//  FitCloudNotificationApps.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-29.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 通知应用枚举
typedef NSString *FitCloudNotificationApp NS_STRING_ENUM;

/// 电话通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppCall;
/// 短信通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppSMS;
/// QQ 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppQQ;
/// 微信通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppWeChat;
/// Facebook 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppFacebook;
/// Twitter 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppTwitter;
/// LinkedIn 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppLinkedIn;
/// Instagram 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppInstagram;
/// Pinterest 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppPinterest;
/// WhatsApp 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppWhatsApp;
/// LINE 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppLINE;
/// Facebook Messenger 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppMessenger;
/// KakaoTalk 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppKakao;
/// Skype 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppSkype;
/// 邮箱通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppMail;
/// Telegram 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppTelegram;
/// Viber 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppViber;
/// 日历消息通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppCalendar;
/// Snapchat 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppSnapchat;
/// Hike 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppHike;
/// YouTube 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppYouTube;
/// Apple Music 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppAppleMusic;
/// Zoom 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppZoom;
/// TikTok 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppTikTok;
/// Gmail 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppGmail;
/// Outlook 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppOutlook;
/// WhatsApp Business 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppWhatsAppBusiness;
/// Fastrack 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppFastrack;
/// Titan Smart World 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppTitanSmartWorld;
/// Google Wallet 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppGoogleWallet;
/// Amazon 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppAmazon;
/// 其他 APP 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppOther;
/// PhonePe 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppPhonePe;
/// Hinge 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppHinge;
/// Flipkart 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppFlipkart;
/// Myntra 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppMyntra;
/// Meesho 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppMeesho;
/// Zivame 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppZivame;
/// Ajio 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppAjio;
/// Urbanic 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppUrbanic;
/// Nykaa 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppNykaa;
/// Healthifyme 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppHealthifyme;
/// Cultfit 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppCultfit;
/// Flo 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppFlo;
/// Bumble 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppBumble;
/// Uber 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppUber;
/// Swiggy 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppSwiggy;
/// Zomato 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppZomato;
/// Tira 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppTira;
/// Zalo 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppZalo;
/// 钉钉通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppDingTalk;
/// 飞书通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppFeishu;
/// Microsoft Teams 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppTeams;
/// Google Play 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppGooglePlay;
/// Google Drive 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppGoogleDrive;
/// JioHotstar 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppJioHotstar;
/// Paytm 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppPaytm;
/// KISMETOS 通知
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppKismetos;
/// VK（ВКонтакте）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppVK;
/// Yandex Go（Яндекс GO）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppYandexGo;
/// Yandex Market（Яндекс Маркет）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppYandexMarket;
/// Sberbank Online（Сбербанк Онлайн）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppSberbankOnline;
/// Wildberries（Вайлдберис）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppWildberries;
/// Ozon（Озон）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppOzon;
/// MAX（Макс）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppMax;
/// Gosuslugi（Госуслуги）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppGosuslugi;
/// Avito（Авито）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppAvito;
/// Gold Apple（Золотое яблоко）通知，俄罗斯地区
FOUNDATION_EXPORT FitCloudNotificationApp const FitCloudNotificationAppGoldApple;

/// 返回所有已定义的的通知应用集合
/// - Note: 新增通知应用时，需要在此集合中添加对应的常量
FOUNDATION_EXPORT NSSet<FitCloudNotificationApp> *FitCloudAllNotificationApps(void);

NS_ASSUME_NONNULL_END
