//
//  FitCloudKit.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/4/28.
//  Copyright © 2018年 Zero Status. All rights reserved.
//
//  框架名称:FitCloudKit.framework
//  框架功能:iOS framework for fitCloud smart watch, which is responsible for the communication with the watch.
//          FitCloud 智能手表的 iOS 框架，负责与智能手表设备通信等功能的封装。
//  修改记录:
//     pcjbird    2024-04-26  Version:1.2.9-beta.97 Build:202404260001
//                            1.新增创维光伏数据支持, @see withSkyworthPV
//                            2.新增一些调试日志
//                            3.板球比赛数据指令支持, @see withCricketMatch
//                            4.新增同步指定时间到手表支持
//                            5.GPS&EPO支持, @see withGPSEpo
//                            6.网易云音乐支持
//                            7.表盘尺寸支持228*460方
//                            8.新增习惯养成类型
//                            9.新增获取手表的支持的日程类型列表 @see canGetSupportedSchedules
//                            10.支持设置和获取勋章列表 @see withMedals
//                            11.体感游戏支持 @see withMotionSensingGame
//                            12.修改习惯养成协议
//                            13.表盘尺寸支持390*390圆
//                            14.新增导航信息同步支持,@see naviGuideSupported
//                            15.表盘尺寸支持390*450方
//                            16.表盘尺寸支持286*240方
//                            17.新增相册推送支持,@see allowPhotoPush
//                            18.新增电子书推送支持,@see allowEBookPush
//                            19.新增小睡支持,@see withSnooze
//                            20.新增快速眼动支持,@see withREM
//                            21.新增超过10个常用联系人支持,@see allowHugeCountFavContacts
//                            22.新增电子卡包功能
//                            23.表盘尺寸支持192*490方
//                            24.新增心率监测时间段是否支持跨天标识,@see allowHeartRateMonitoringAcrossDays
//                            25.新增设备能力查询支持,@see allowQueryDeviceCapacities, allConfig.deviceCapacities
//                            26.新增获取运动训练展示数据项信息,@see withDisplayConfigInWorkoutData
//                            27.FitCloudOption新增是否自动同步系统语言选项,@see autoSyncSystemLang
//                            28.新OTA升级支持, @see withNewOTA
//                            29.进入DFU模式新增返回错误类型 `FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE`
//                            30.新增健康定时监测独立开关设置和查询功能, @see allowSingleHTMSettings
//                            31.新增静态心率/动态心率过低报警功能, @see withHRLowAlarm
//                            32.天气设置新增紫外线指数设置功能
//                            33.新增猎声定制天气类型 @see WEATHERTYPE_CLOUDYINEVENING/WEATHERTYPE_CLEARINEVENING/WEATHERTYPE_EVENINGSHOWERS
//                            34.设备能力类型新增设备支持的天气种类数量
//                            35.新增设置和查询运动极限心率，仅特定项目可用
//                            36.新增猎声相关软件版本信息查询功能，仅该客户可用，版本信息数据由客户自行解析, @see FitCloudKit+Haylou.h
//                            37.新增文心一言支持, @see withERNIEBot
//                            38.新增猎声手表SN信息查询功能，仅该客户可用, @see FitCloudKit+Haylou.h
//                            39.修改绑定API，新增随机码，没有随机码是填nil
//                            40.绑定失败错误新增`手表需要恢复出厂设置才能绑定`
//                            41.新增查询手表当前语言设置功能
//                            42.新增手表端执行了停止查找手表操作通知, @see FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY
//                            43.修改停止查找手表API名称，新增停止查找手表功能
//                            44.每日运动目标新增设置运动时长目标
//                            45.新增设置紧急联系人功能, @see withEmergencyContact
//                            46.新增静息心率查询功能, @see withRestingHR
//                            47.新增设置个性化提醒功能, @see withPersonalizedReminder, @see FITCLOUDDEVICECAPACITY
//                            48.健康总数据以及计步数据新增运动时长数据
//                            49.消息通知新增Gmail/Outlook/WhatsApp Business
//                            50.天气设置新增能见度
//
//     pcjbird    2023-05-30  Version:1.2.8 Build:202305300001
//                            1.表盘尺寸支持410*502方/416*416圆/240*288方
//                            2.新增自定义标签功能 @see withCustomLabels
//                            3.支付宝Iot支持, @see allowAliot
//                            4.蓝牙连接支持设置是否使用一键双连同时连接经典蓝牙(BT), @see allowConnectWithBT
//                            5.新增通过广播数据获取相关厂商信息及参数 @see FitCloudManufacturer
//                            6.手表运动GPS数据传输支持 @see FitCloudGPSRecordObject
//                            7.表盘尺寸支持340*340圆
//                            8.新增指定支持的收款码和名片，仅支持的收款码和名片才应该在App上展示推送入口 @see specifySupportedMoneyReceiveAndBusinessQRCode
//                            9.修改习惯养成指令
//                            10.新增省电模式设置 @see withPowerSavingMode & allowPowerSavingModePeriod
//                            11.设定每日目标新增时间戳参数
//                            12.调整支付宝Iot安全认证指令
//                            13.修改自动登录日志，userId支持String
//                            14.修改获取手表UI信息指令解析，兼容固件版本
//                            15.更新和新增了一大批运动类型定义
//                            16.提升SDK稳定性
//
//     pcjbird    2022-12-30  Version:1.2.7 Build:202212300001
//                            1.新增禁用睡眠模块
//                            2.新增核酸码推送功能 @see allowNucleicAcidQRCode
//                            3.天气新增大气压强/风力/能见度信息
//                            4.新增习惯养成相关指令 @see allowHabits
//                            5.新增收款码：Paytm收款码/PhonePe收款码/GPay收款码/BHTM收款码，新增名片：Email名片/Phone名片/LinkedIn名片, @see showAdditionalQRCodeTransfer
//                            6.新增通知手表查找手机响铃播放完毕，适配蓝牙通话手表
//                            7.新增获取每日运动目标指令
//                            8.优化外设MTU值获取
//
//     pcjbird    2022-09-20  Version:1.2.6 Build:202209200001
//                            1.修正GPS互联运动指令的问题
//                            2.新增基于气压泵的真血压(部分手表支持)
//                            3.部分手表支持手表手动测量数据同步
//                            4.部分手表支持发起SOS请求
//                            5.新增第三方外设启停操作支持
//                            6.新增手表启动震动参数设置
//                            7.新增手表上存储的消息删除指令
//                            8.新增取消手表当前消息显示
//                            9.新增游戏锁设置
//                            10.登录/绑定指令新增iOS系统版本标志
//                            11.新增获取单个游戏最高三个游戏记录(部分手表支持)
//                            12.修正真血压数据同步问题
//                            13.GPS互联指令修改
//                            14.新增游戏排名趋势设置(部分手表支持)
//                            15.获取闹钟闹钟列表更新SDK闹钟列表缓存
//                            16.更新SDK错误码翻译
//                            17.运动健康数据防丢失处理
//                            18.新增是否禁用在App上表盘模块化标志 @see disableWatchfaceModularInApp
//                            19.新增表盘尺寸240*296方
//                            20.提升SDK稳定性
//
//     pcjbird    2022-01-26  Version:1.2.5 Build:202201260001
//                            1.新增板球/自由运动/力量训练/室内健走/室内骑行/哑铃/跳舞/呼啦圈/高尔夫/跳远/仰卧起坐/排球运动定义
//                            2.新增手表GPS互联运动
//                            3.新增唤醒APP相机功能，该功能有缺陷，慎用
//                            4.新增血压报警&心率报警功能设备支持检查
//                            5.手表偏好设置新增FITCLOUDPREFER_REMINDWHENSPORTSGOALACHIEVEMENT，手表运动(计步/距离/卡路里)目标达成提醒
//                            6.修正常用联系人指令数据量较大时的问题
//                            7.修正OTA过程中关闭蓝牙可能导致闪退的问题
//                            8.新增收款码和名片二维码推送
//                            9.修正当手表断开连接的情况下解绑，当手表重新靠近手机的时候可能会重新回连的问题
//                            10.修正测量心电时蓝牙断开连接可能导致无法正确回连的问题
//                            11.新增通话手表绑定失败时音频蓝牙名称返回
//                            12.新增印地语
//
//     pcjbird    2021-10-12  Version:1.2.4 Build:202110120001
//                            1.新增是否支持游戏皮肤推送标志
//                            2.新增是否支持Apple Music、Zoom & Tiktok 提醒标志及其通知定义
//                            3.新增是否支持扫码连接标志
//                            4.添加硬件标识FITCLOUDHARDWARE_DFUSHOULDSILENTMODE
//                            5.新增俄罗斯方块游戏/数独游戏/答题游戏定义
//                            6.扫码绑定项目新增绑定失败原因(手表主动取消/手表超时未点击确认)
//                            7.新增获取/设置亮屏时长、亮度、振动等信息
//                            8.新增是否应该禁用自定义表盘功能标识
//                            9.新增手表离开查找手机功能界面回调
//                            10.手表偏好设置新增蓝牙断开时手表振动选项
//                            11.修复同步心电数据时手表断开连接导致之后无法回连的问题
//                            12.新增获取屏幕分辨率原始信息(lcd宽高/是否圆形屏幕/圆角大小等)指令，仅部分固件支持
//                            13.Nordic平台表盘编号也扩展到3个字节
//                            14.修复游戏皮肤获取只能获取到3条的问题
//                            15.修改表盘/游戏皮肤最大可推送文件的大小计算规则
//                            16.修改天气硬件功能标志位定义
//                            17.新增手表是否支持运动模式(DIY)固件推送标识
//                            18.新增获取设备可支持的运动模式类型列表/设备当前运动模式类型列表，仅部分手表支持
//
//     pcjbird    2021-07-20  Version:1.2.3 Build:202107200001
//                            1.新增压力指数测量，仅部分手表支持
//                            2.修正日程设置指令的问题
//                            3.修正锁屏密码设置指令的问题
//                            4.表盘尺寸支持280*240方/200*320方/368*448方/320*390方
//                            5.新增表盘模块化(组件化)支持
//                            6.修正日程获取指令的问题
//                            7.支持自定义设定手表语言
//                              @note: 如果你希望SDK初始化时就设定好，@see watchPreferLang for FitCloudOption
//                                     如果你希望在APP运行中动态改变手表语言设定请调用setSmartWatchLanguage:completion:
//                                     此外，原先的syncSystemLanguageWithBlock也会受到影响，也就是说如果你自定义设定了手表语言，
//                                     原先的syncSystemLanguageWithBlock也会同步自定义的手表语言设定
//                            8. 新增设置是否允许手表设置日程，仅当时手表支持日程功能时有效
//                           9. 支持将自行扫描的外设转换成可连接的外设
//                           10. 新GUI结构相关协议更新
//                           11. 下一代厂商名称支持，下一代厂商名称可以确定不需要过滤蓝牙名称中首字母H
//                           12. 修正切换表盘导致表盘模块信息丢失的问题
//                           13. 多表盘推送支持获取每个表盘位置最大可推送固件的大小，单位：kB
//                           14. 支持Nordic芯片
//                           15. 新增获取手表支持的游戏类型，仅部分手表支持
//                           16. 新增获取游戏最高三个游戏记录，仅部分手表支持
//                           17. 新增获取手环上所有游戏对应的皮肤信息，仅部分手表支持
//                           18. 表盘尺寸支持172*320方/454*454圆/128*220方
//                           19. +(void)ignoreConnectedPeripheral:(BOOL)silent; 添加 silent 参数
//                           20. 新增FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY通知，
//                               建议用户进入系统设置解除与该手表的配对信息，杀死App进程并重新启动App。具体参照其定义
//                               @note: 该通知可能连续发送，应用层需要避免重复提示用户，给用户造成困扰
//
//     pcjbird    2021-02-05  Version:1.2.2 Build:202102050001
//                            1.新增天气推送开关，仅部分手表支持
//                            2.新增通知手表App定位服务状态
//                            3.新增洗手提醒功能
//                            4.表盘尺寸支持240*280方
//                            5.数据解析异常处理，条目过大，直接丢弃，不再解析数据
//                            6.新增设置锁屏密码，仅部分手表支持
//                            7.新增设置日程提醒，仅部分手表支持
//                            8.新增Hike和YouTube通知提醒，仅部分手表支持
//                            9.表盘尺寸支持348*442方
//                            10.多表盘推送信息获取支持
//                            11.新增运动类型定义
//
//     pcjbird    2020-10-30  Version:1.2.1 Build:202010300001
//                            1.FitCloudOption 支持 preferSystemLocale 选项，当改选项设置为 TRUE 时，将向手表同步 iOS 系统的语言设置，否则向手表同步当前 APP 的语言设置，默认为 FALSE。
//                              @note: 由于系统限制，当你手动修改了APP的语言，则该选项也会无效。
//                            2.修正睡眠调试数据不正确响应的问题
//                            3.支持设置健康监测间隔，需要手表支持，@see allowSetHealthMonitorInterval
//                            4.支持设置久坐提醒间隔，需要手表支持，@see allowSetLSRInterval
//                            5.支持设置天气预报，需要手表支持，@see allowWeatherForecast
//                            6.新增天气更新时间，调整天气预报最大支持天数为14天
//                            7.修正健康监测间隔/久坐提醒间隔设置不正确的问题
//                            8.修正手表标志位解析不正确的问题
//                            9.新增阿尔巴尼亚语
//                            10.新增土耳其语/乌克兰语
//                            11.修正无法同步韩语至手表的问题
//                            12.补丁：当allowShowAdditionalReminder标志位为true时，allowShowMailReminder/allowShowTelegramAndViberReminder强制为true
//
//     pcjbird    2020-07-18  Version:1.2.0 Build:202007180001
//                            1.支持手表通知APP退出拍照模式
//                            2.新增女性健康功能
//                            3.新增防护提醒功能
//                            4.修正匈牙利语不能同步到手环的问题
//                            5.新增设置广播数据自定义字段 key1，华盛达专用
//                            6.修正设置用户资料时年龄不正确的问题
//                            7.新增获取当天睡眠调试数据
//                            8.修正年龄设置不正确的问题
//                            9.最新的健康测量数据新增体温数据(需要手表支持体温)
//                            10.新增新的表盘尺寸的相关注释说明
//                            11.支持设置SDK定义的所有本地化语言至手表
//
//     pcjbird    2020-05-15  Version:1.1.9 Build:202005150001
//                            1.支持体温测量，仅部分手表支持
//
//     pcjbird    2020-04-25  Version:1.1.8 Build:202004250001
//                            1.修正解绑有可能出现未断开连接的问题
//                            2.修正在自动登录过程中手表断开连接有可能导致提示手表被其他手机终端绑定或已经被解绑的问题
//                            3.修正当命令执行超时的情况下会丢掉下一条待执行的命令的问题
//                            4.修正同步数据量较大的健康数据时可能导致超时的问题
//                            5.解绑后清除电量信息
//                            6.支持常用联系人，仅部分手表支持
//                            7.手表运动模式新增椭圆机/瑜伽/乒乓球/跳绳等运动
//                            8.修正心电启动失败时逻辑处理不正确的问题
//                            9.修正连接手表超时不执行连接超时逻辑的问题
//
//     pcjbird    2020-02-25  Version:1.1.7 Build:202002250001
//                            1.新增斯洛伐克语/匈牙利语
//                            2.修正手表返回的睡眠数据睡眠质量可能为非法值的情况
//                            3.取消自动解绑逻辑,新增手表被其他手机终端绑定或已经被解绑通知 @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY
//                            4.所有回调以及通知均改成在 Gloal Queue 中调用，如果要在回调或者通知中更新UI，请务必切换到主队列(Main Queue)
//                            5.外部调用 disconnect 将不会自动回连
//                            6.新增 FITCLOUDUSERBINDSTATUS_KICKEDOUT 用户绑定状态
//                            7.新增 FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY 通知
//                            8.新增支持新的睡眠格式 @see newSleepDataFormat
//                            9.日志信息支持查看较大数据包的完整数据
//                            10.手表端主动更改了开关设置(例如：抬腕唤醒开关，通知开关等)会适时更新到App端 @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY
//                            11.表盘信息获取方法修改
//                            12.其他一些改进
//
//     pcjbird    2019-11-21  Version:1.1.6 Build:201911210001
//                            1.修正表盘UI信息接口无法正确响应的问题
//                            2.解绑用户后取消当前手表连接记录的自动重连
//                            3.优化手表连接初始化过程，防止意外重连
//                            4.调整手表硬件相关信息为只读
//                            5.绑定用户的UserId由整型修改成字符串型
//                            6.新增获取手表最后一次健康测量数据(心率/血氧/血压)，仅部分手表支持，@see allowRetrieveLatestMeasurementData
//                            7.修改进入和退出固件升级模式方法，现在您在首次固件升级之前以及所有固件升级操作完成之后分别手动调用进入固件升级模式和退出固件升级模式，同时适用于普通固件升级与表盘推送
//                            8.新增DFU模式回连成功通知，这通常用于等待表盘推送/普通固件升级之后手表重启的场景
//                            9.提升SDK稳定性
//
//     pcjbird    2019-11-13  Version:1.1.5 Build:201911130001
//                            1.新增勿扰模式(仅部分手表支持 @see allowDNDMode)
//
//     pcjbird    2019-10-24  Version:1.1.4 Build:201910240001
//                            1.实时测量moment修改精确到秒
//                            2.修正同步数据moment使得不会超过当前同步时间
//
//     pcjbird    2019-10-16  Version:1.1.3 Build:201910160001
//                            1.计步数据引入距离&卡路里新算法
//                            2.新增获取用户最后绑定时间
//                            3.新增心率报警/血压报警设置
//                            4.新增Snapchat消息提醒选项
//                            5.设备扫描取消设备名称过滤
//                            6.心电实时测量新增手表主动结束逻辑
//                            7.新增获取表盘UI信息接口
//                            8.新增获取手表广播数据缓存
//                            9.新增蓝牙名称变更通知，新增蓝牙RSSI变更通知
//                            10.提升SDK稳定性
//                            11.避免歧义，+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals 修改为  +(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals
//
//     pcjbird    2019-08-19  Version:1.1.2 Build:201908190002
//                            1.修正蓝牙连接开始的通知时刻问题
//
//     pcjbird    2019-08-19  Version:1.1.1 Build:201908190001
//                            1.修正手表解绑没有清除上一次绑定手表的Mac地址的问题
//                            2.新增绑定/登录成功后需要完成一些基础准备同步操作的开始与结束通知
//                            3.修正SDK初始化选项shouldAutoConnect不起作用的问题
//
//     pcjbird    2019-08-12  Version:1.1.0 Build:201908120001
//                            1.支持后台蓝牙数据同步功能
//
//     pcjbird    2019-07-21  Version:1.0.9 Build:201907210001
//                            1.支持获取当前SDK版本信息
//
//     pcjbird    2019-07-20  Version:1.0.8 Build:201907200001
//                            1.修正iPhone日历设置成佛教日历或者日本日历的时候导致手表同步时间失败的问题
//                            2.优化手表回连机制
//
//     pcjbird    2019-06-28  Version:1.0.7 Build:201906280001
//                            1.修正无法获取消息通知设置的一些问题
//
//     pcjbird    2019-06-27  Version:1.0.6 Build:201906270001
//                            1.扫描到的外部设备新增mac地址数据
//
//     pcjbird    2019-06-25  Version:1.0.5 Build:201906250001
//                            1.修改支持设置运动目标
//
//     pcjbird    2019-05-17  Version:1.0.4 Build:201905170001
//                            1.增加手表支持的语种
//
//     pcjbird    2019-05-01  Version:1.0.3 Build:201905010001
//                            1.首次发布SDK版本
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudKit/FitCloudEvent.h>
#import <FitCloudKit/FitCloudCallback.h>
#import <FitCloudKit/FitCloudOption.h>
#import <FitCloudKit/FitCloudKitConnectRecord.h>
#import <FitCloudKit/SmartWatchOperation.h>
#import <FitCloudKit/SmartWatchOperation+Private.h>
#import <FitCloudKit/SmartWatchBackgroundOperationQueue.h>


NS_ASSUME_NONNULL_BEGIN

/// FitCloud智能手表iOS框架
@interface FitCloudKit : NSObject

#pragma mark 版本信息

/// SDK版本号
/// - Returns:
/// SDK 版本号
+(NSString*) sdkVersion;

/// SDK Build 版本号
/// - Returns:
/// SDK Build 版本号
+(NSString*) sdkBuild;


#pragma mark 初始化/扫描/连接

/// 初始化
/// - Parameters:
///   - option: 选项, 传nil则使用默认选项
///   - callback 回调类，主要用于接受处理手表的请求命令或事件
/// - Returns:
///  FitCloudKit
+(instancetype _Nonnull)initWithOption:(FitCloudOption* _Nullable)option callback:(id<FitCloudCallback> _Nullable)callback;

/// 扫描手表设备
+(void)scanPeripherals;

/// 停止扫描手表设备
+(void)stopScan;

/// 如果您使用自己的扫描方法，将您的外设转换成可连接的外设
/// - Parameters:
///   - peripheral: 您自己扫描的外设
///   - completion: 转换结果
+(void)translatePeripheral:(CBPeripheral * _Nonnull )peripheral toConnectablePeripheralCompletion:(void(^_Nullable)(BOOL success, NSError * _Nullable error, CBPeripheral * _Nullable connectablePeripheral)) completion;

/// 连接手表设备
/// - Parameters:
///   - peripheral: 手表设备
+(void)connect:(CBPeripheral * _Nonnull )peripheral;


/// 连接手表设备
/// - Parameters:
///   - peripheral: 手表设备
///   - btMode: 是否使用一键双连同时连接经典蓝牙(BT)
+(void)connect:(CBPeripheral * _Nonnull )peripheral btMode:(BOOL)btMode;

/// 尝试连接已知的外部设备
/// - Parameters:
///   - record: 已知的外部设备
+(void)tryConnect:(FitCloudKitConnectRecord* _Nonnull )record;

/// 断开外部设备连接
+(void)disconnect;

/// 忽略当前已连接未绑定/绑定失败的设备
/// - Parameters:
///   - silent: YES则不会打印相关日志
+(void)ignoreConnectedPeripheral:(BOOL)silent;


#pragma mark 请求打开蓝牙来允许连接到配件

/// 请求打开蓝牙来允许连接到配件
///
/// 仅仅当系统蓝牙关闭时有效
+(void) requestShowBluetoothPowerAlert;

#pragma mark 扫描到的外设(手表)列表

/// 扫描到的外设(手表)列表
+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals;

#pragma mark 蓝牙中心设备(Central)状态

///蓝牙中心设备(Central)状态
+(FITCLOUDBLECENTRALSTATE) bleState;

#pragma mark 蓝牙是否已连接

/// 蓝牙是否已连接
+(BOOL) connected;

#pragma mark 蓝牙是否正在连接

///蓝牙是否正在连接
+(BOOL) connecting;

#pragma mark 蓝牙外部设备是否初始化/准备完毕(是否可以执行与蓝牙外设的相关操作)

/// 蓝牙外部设备是否初始化/准备完毕(是否可以执行与蓝牙外设的相关操作)
+(BOOL) deviceReady;

#pragma mark 蓝牙外部设备是否初始化/准备完毕且当前处于空闲状态(是否可以执行与蓝牙外设的相关操作)

/// 蓝牙外部设备是否初始化/准备完毕且当前处于空闲状态(是否可以执行与蓝牙外设的相关操作)
+(BOOL) deviceIdle;

#pragma mark 当前是否允许手动同步运动健康数据

/// 当前是否允许手动同步运动健康数据
+(BOOL) canSyncData;

#pragma mark 用户绑定状态

///用户绑定状态
+(FITCLOUDUSERBINDSTATUS) userBindStatus;

#pragma mark 手表Mac地址

///手表Mac地址
+(NSString*_Nullable) macAddr;

#pragma mark 手表当前所有配置信息

/// 手表当前所有配置信息
+(FitCloudAllConfigObject*_Nullable) allConfig;

#pragma mark 手表当前电量信息

/// 手表当前电量信息
+(FitCloudBatteryInfoObject*_Nullable) batteryInfo;

#pragma mark 手表闹钟列表

/// 手表闹钟列表
+(NSArray<FitCloudAlarmObject*>*_Nullable) alarmlist;

#pragma mark 手表日程列表

/// 手表日程列表
+(NSArray<FitCloudScheduleObject*>*_Nullable) schedulelist;

#pragma mark 手表常用联系人列表

/// 手表常用联系人列表
+(NSArray<FitCloudContactObject*>*_Nullable) favoriteContacts;


#pragma mark 手表习惯养成列表

/// 手表习惯养成列表
+(NSArray<FitCloudHabitObject*>*_Nullable) habits;

#pragma mark 手表勋章列表

/// 手表勋章列表
+(NSArray<FitCloudMedal*>*_Nullable) medals;

#pragma mark 最后连接的手表信息

/// 最后连接的手表信息
+(FitCloudKitConnectRecord*_Nullable) lastConnectPeripheral;

#pragma mark 手表连接历史

/// 手表连接历史
+(NSArray<FitCloudKitConnectRecord*>*_Nonnull) historyPeripherals;

#pragma mark 删除手表连接历史

/// 删除手表连接历史
/// - Parameters:
///   - uuid: peripheral uuid
+(void)removePeripheralHistoryWithUUID:(NSString*_Nonnull) uuid;

#pragma mark 清除手表连接历史

/// 清除手表连接历史
+(void)clearPeripheralHistory;

@end

/// FitCloud Upgrade Module
@interface FitCloudKit (Upgrade)

#pragma mark 当前是否为DFU模式

/// 当前是否为DFU模式
/// - Returns:
/// 是否为DFU模式
+(BOOL)  isCurrentDFUMode;

#pragma mark dfu外设

/// dfu外设，仅仅当处于dfu模式，且处于连接状态时有效
/// - Returns:
/// dfu 外设
+(CBPeripheral*)  dfuPeripheral;

#pragma mark 芯片提供商

/// 当前芯片提供商
+(FITCLOUDCHIPVENDOR)  chipVendor;

#pragma mark 准备进入固件升级模式

/// 准备进入固件升级模式
/// - Parameters:
///   - block: 结果回调
+(void)enterDFUModeWithBlock:(FitCloudEnterDFUModeResultBlock _Nullable )block;

#pragma mark 退出固件升级模式

/// 退出固件升级模式
/// - Parameters:
///   - block: 结果回调
+(void)exitDFUModeWithBlock:(FitCloudExitDFUModeResultBlock _Nullable )block;

@end

/// FitCloud Setting Module
@interface FitCloudKit (Setting)

#pragma mark 同步系统时间

/// 同步系统时间（将手表的时间同步成跟手机的系统时间一致）
/// - Parameters:
///  - block: 同步结果回调
+(void)syncSystemTimeWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 同步指定时间到手表

///同步指定时间到手表
/// - Parameters:
///  - block: 同步结果回调
+(void)syncTimeToWatch:(NSDate*)time  block:(FitCloudResultBlock _Nullable )block;

#pragma mark 同步天气信息

/// 同步天气信息
/// - Parameters:
///  - weather: 天气信息
///  - block: 同步结果回调
+(void) syncWeather:(FitCloudWeatherObject*_Nonnull)weather block:(FitCloudResultBlock _Nullable )block;

#pragma mark 设置闹钟列表

/// 设置闹钟（将手机上的闹钟列表同步到手表）
/// - Parameters:
///   - alarms: 闹钟列表
///   - block: 结果回调
+(void)setAlarms:(NSArray<FitCloudAlarmObject*>*_Nullable)alarms block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取闹钟列表

/// 获取闹钟列表（获取手表上的闹钟列表）
/// - Parameters:
///   - block: 结果回调
+(void)getAlarmsWithBlock:(FitCloudAlarmsResultBlock _Nullable )block;

#pragma mark 设置是否允许手表设置日程

/// 设置是否允许手表设置日程
/// - Parameters:
///  - allow: 是否允许手表设置日程
///  - block: 结果回调
+(void)setAllowWatchScheduleSettings:(BOOL)allow completion:(FitCloudResultBlock _Nullable )block;

#pragma mark 设置日程列表

/// 设置日程（将手机上的日程列表同步到手表）
/// - Parameters:
///   - schedules: 日程列表
///   - block: 结果回调
+(void)setSchedules:(NSArray<FitCloudScheduleObject*>*_Nullable)schedules block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取日程列表

/// 获取日程列表（获取手表上的日程列表）
/// - Parameters:
///   - block: 结果回调
+(void)getSchedulesWithBlock:(FitCloudSchedulesResultBlock _Nullable )block;

#pragma mark 设置常用联系人

/// 设置常用联系人（将手机上的常用联系人列表同步到手表）
/// - Parameters:
///   - contacts: 常用联系人列表
///   - block: 结果回调
+(void) setFavContacts:(NSArray<FitCloudContactObject*>*_Nullable)contacts block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取常用联系人

/// 获取常用联系人列表（获取手表上的常用联系人列表）
/// - Parameters:
///   - block: 结果回调
+(void) getFavContactsWithBlock:(FitCloudFavContactsResultBlock _Nullable)block;

#pragma mark 设置手表紧急联系人

/// 设置手表紧急联系人
/// - Parameters:
///   - contacts: 紧急联系人
///   - on: 是否启用紧急联系人
///   - completion: 结果回调
+(void) setEmergencyContacts:(NSArray<FitCloudEmergencyContactObject*>* _Nullable)contacts on:(BOOL)on completion:(FitCloudResultBlock _Nullable)completion;

#pragma mark 获取手表紧急联系人

/// 获取手表紧急联系人
/// - Parameters:
///   - completion: 结果回调
+(void) queryEmergencyContactsWithCompletion:(FitCloudEmergencyContactsQueryCompletion _Nullable)completion;

#pragma mark 设置习惯养成列表

/// 设置习惯养成列表（将手机上的习惯养成列表同步到手表）
/// - Parameters:
///   - habits: 习惯养成列表
///   - block: 结果回调
+(void) setHabits:(NSArray<FitCloudHabitObject*>*_Nullable)habits block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取习惯养成列表

///获取习惯养成列表（获取手表上的习惯养成列表）
/// - Parameters:
///   - block: 结果回调
+(void) getHabitsWithBlock:(FitCloudHabitsResultBlock _Nullable)block;

#pragma  mark 设置User Profile

/// 设置 User Profile
/// - Parameters:
///   - profile: user profile
///   - block: 结果回调
+(void)setUserProfile:(FitCloudUserProfileObject *_Nonnull)profile block:(FitCloudResultBlock _Nullable )block;

#pragma  mark 设置自定义标签

/// 设置自定义标签
/// - Parameters:
///   - labels: 自定义标签
///   - block: 结果回调
+(void)setCustomLabels:(FitCloudCustomLabelsObject *_Nonnull)labels block:(FitCloudResultBlock _Nullable )block;

#pragma mark 设定每日运动目标

/// 设定每日运动目标
///  - Parameters:
///    - stepcount: 步数目标, 单位：步数
///    - distance: 距离目标, 单位：厘米(cm)
///    - calorie: 卡路里, 单位：小卡(cal)
///    - duration: 运动时长，单位：分钟(Min)
///    - timestamp: 时间戳，传nil，则默认为当前时间
///    - block: 结果回调
+(void)setDailyGoalWithStepCount:(UInt32) stepcount distance:(UInt32)distance calorie:(UInt32)calorie duration:(UInt16)duration timestamp:(NSDate* _Nullable )timestamp block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取每日运动目标

/// 获取每日运动目标
/// - Parameters:
///   - block: 结果回调
+(void)getDailyGoalWithBlock:(FitCloudDailyGoalResultBlock _Nullable )block;

#pragma mark 获取手表软硬件版本信息

/// 获取手表软硬件版本信息
/// - Parameters:
///   - block: 结果回调
+(void)getFirmwareVersionWithBlock:(FitCloudFirmwareVersionResultBlock _Nullable )block;

#pragma mark 设置消息通知开关

/// 设置消息通知开关
/// - Parameters:
///   - mnSetting: 消息通知设置信息
///   - block: 结果回调
+(void)setMessageNotification:(FITCLOUDMN)mnSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取消息通知开关设置

/// 获取消息通知开关设置信息
/// - Parameters:
///   - block: 结果回调
+(void)getMessageNotificationSettingWithBlock:(FitCloudMNSettingResultBlock _Nullable )block;

#pragma mark 设置手表表盘所有功能项显示状态

/// 设置手表表盘所有功能项显示状态
/// - Parameters:
///   - display: 手表表盘所有功能项显示状态信息
///   - block: 结果回调
+(void)setScreenDisplay:(FITCLOUDSCREENDISPLAY)display block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手表表盘所有功能项显示状态

/// 获取手表表盘所有功能项显示状态
/// - Parameters:
///   - block: 结果回调
+(void)getScreenDisplaySettingWithBlock:(FitCloudSDSettingResultBlock _Nullable )block;

#pragma mark 设置手表偏好

/// 设置手表偏好
/// - Parameters:
///   - prefer: 手表偏好
///   - block: 结果回调
+(void)setFitCloudPrefer:(FITCLOUDPREFER)prefer block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取手表偏好设置

/// 获取手表偏好设置
/// - Parameters:
///   - block: 结果回调
+(void)getFitCloudPreferWithBlock:(FitCloudPreferResultBlock _Nullable )block;

#pragma mark 获取手表电量以及充电状态信息

/// 获取手表电量以及充电状态信息
/// - Parameters:
///   - block: 结果回调
+(void)getBatteryInfoWithBlock:(FitCloudBatteryInfoResultBlock _Nullable )block;

#pragma mark 如果空闲则请求更新手表电量信息

/// 如果空闲则请求更新手表电量信息
+(void) requestUpdateBatteryInfoIfIdle;

#pragma mark 健康定时监测设置

/// 健康定时监测设置
/// - Parameters:
///   - htmSetting: 健康定时监测设置
///   - block: 结果回调
+(void)setHealthTimingMonitor:(FitCloudHTMObject*_Nonnull)htmSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取健康定时监测设置

/// 获取健康定时监测设置
/// - Parameters:
///   - block: 结果回调
+(void)getHealthTimingMonitorSettingWithBlock:(FitCloudHealthTimingMonitorResultBlock _Nullable )block;

#pragma mark 健康定时监测独立设置

/// 健康定时监测独立设置
/// - Parameters:
///   - htmlSingleSettings: 健康定时监测独立设置信息，可以单个类型单独设置也可以多个类型一起设置
///   - completion: 结果回调
+(void) setSingleHealthTimingMonitoring:(NSArray<FitCloudHTMSingleObject*>*) htmSingleSettings completion:(FitCloudResultBlock _Nullable )completion;

#pragma mark 获取健康定时监测独立设置

/// 获取健康定时监测独立设置
/// - Parameters:
///   - completion: 结果回调
+(void) getSingleHealthTimingMonitoringSettingsWithCompletion:(FitCloudHealthTimingMonitoringSingleSettingsResultBlock _Nullable)completion;

#pragma mark 久坐提醒设置

/// 久坐提醒设置
/// - Parameters:
///   - lsrSetting: 久坐提醒设置
///   - block: 结果回调
+(void)setSedentaryRemind:(FitCloudLSRObject *_Nonnull)lsrSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取久坐提醒设置

/// 获取久坐提醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getSedentaryRemindSettingWithBlock:(FitCloudLongSitRemindResultBlock _Nullable )block;

#pragma mark 喝水提醒设置

/// 喝水提醒设置
/// - Parameters:
///   - drSetting: 喝水提醒设置
///   - block: 结果回调
+(void)setDrinkRemind:(FitCloudDRObject*_Nonnull)drSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取喝水提醒设置

/// 获取喝水提醒设置
/// - Parameters:
///   -  block: 结果回调
+(void)getDrinkRemindSettingWithBlock:(FitCloudDrinkRemindResultBlock _Nullable )block;

#pragma mark 个性化提醒

/// Set the personalized reminder, If the reminderId already exist, it will be replaced
/// - Parameters:
///   - remind: the remind
///   - completion: the completion callback
+(void)setPersonalizedRemind:(FitCloudPersonalizedReminderObject* _Nonnull)remind completion:(FitCloudResultBlock _Nullable)completion;

#pragma mark 查询个性化提醒

/// Query the personalized reminders array
/// - Parameters:
///   - completion: the completion callback
+(void)queryPersonalizedRemindersWithCompletion:(FitCloudPersonalizedRemindersQueryCompletion _Nullable)completion;

#pragma mark 删除个性化提醒

/// Remove the personalized reminders with id array
/// - Parameters:
///   - idArray: the reminder id array
///   - completion: the completion callback
+(void)removePersonalizedRemindersWithIdArray:(NSArray<NSNumber*>* _Nonnull)idArray completion:(FitCloudResultBlock _Nullable)completion;

#pragma mark 防护提醒设置

/// 防护提醒设置
/// - Parameters:
///   - prSetting: 防护提醒设置
///   - block: 结果回调
+(void)setProtectionRemind:(FitCloudPRObject*_Nonnull)prSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取防护提醒设置

/// 获取防护提醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getProtectionRemindSettingWithBlock:(FitCloudProtectionRemindResultBlock _Nullable )block;

#pragma mark 洗手提醒设置

/// 洗手提醒设置
/// - Parameters:
///   - hwrSetting: 洗手提醒设置
///   - block: 结果回调
+(void)setHandWashRemind:(FitCloudHandWashRemindObject*_Nonnull)hwrSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取洗手提醒设置

/// 获取洗手提醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getHandWashRemindSettingWithBlock:(FitCloudHandWashRemindResultBlock _Nullable )block;

#pragma mark 抬腕唤醒设置

/// 抬腕唤醒设置
/// - Parameters:
///   - wwuSetting: 抬腕唤醒设置
///   - block: 结果回调
+(void)setWristWakeUp:(FitCloudWWUObject*_Nonnull)wwuSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取抬腕唤醒设置

/// 获取抬腕唤醒设置
/// - Parameters:
///   - block: 结果回调
+(void)getWristWakeUpSettingWithBlock:(FitCloudWristWakeUpResultBlock _Nullable )block;

#pragma mark 参考血压设置

/// 参考血压设置
/// - Parameters:
///   - bprSetting: 血压参考范围设置信息
///   - block: 结果回调
+(void)setBloodPressureRefer:(FitCloudBPRObject*_Nonnull)bprSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取参考血压设置

/// 获取参考血压设置
/// - Parameters:
///   - block: 结果回调
+(void)getBloodPressureReferSettingWithBlock:(FitCloudBloodPressureReferResultBlock _Nullable )block;

#pragma mark 心率报警设置

/// 心率报警设置
/// - Parameters:
///   - hrAlarmSetting: 心率报警设置
///   - block: 结果回调
+(void)setHRAlarm:(FitCloudHRAlarmObject* _Nonnull)hrAlarmSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取心率报警设置

/// 获取心率报警设置
/// - Parameters:
///   - block: 结果回调
+(void)getHRAlarmSettingWithBlock:(FitCloudHRAlarmResultBlock _Nullable)block;

#pragma mark 血压报警设置

/// 血压报警设置
/// - Parameters:
///   - bpAlarmSetting: 血压报警设置
///   - block: 结果回调
+(void)setBPAlarm:(FitCloudBPAlarmObject* _Nonnull)bpAlarmSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取血压报警设置

/// 获取血压报警设置
/// - Parameters:
///   - block: 结果回调
+(void)getBPAlarmSettingWithBlock:(FitCloudBPAlarmResultBlock _Nullable)block;

#pragma mark 勿扰模式设置

/// 勿扰模式设置
/// - Parameters:
///   - dndSetting: 勿扰模式设置
///   - block: 结果回调
+(void)setDND:(FitCloudDNDSetting* _Nonnull)dndSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取勿扰模式设置

/// 获取勿扰模式设置
/// - Parameters:
///   - block: 结果回调
+(void)getDNDSettingWithBlock:(FitCloudDNDSettingResultBlock _Nullable)block;

#pragma mark 省电模式设置

///省电模式设置
/// - Parameters:
///   - settings: 省电模式设置
///   - block: 结果回调
+(void)setPowerSavingSettings:(FitCloudPowerSavingSetting* _Nonnull)settings block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取省电模式设置

/// 获取省电模式设置
/// - Parameters:
///   - block: 结果回调
+(void)getPowerSavingSettingWithBlock:(FitCloudPowerSavingSettingResultBlock _Nullable)block;


#pragma mark 获取手表UI信息

///获取手表UI信息
/// - Parameters:
///   - block: 结果回调
+(void)getWatchUIInformationWithBlock:(FitCloudWatchUIInfoResultBlock _Nullable)block;


#pragma mark 获取表盘UI信息

/// 获取表盘UI信息
/// - Parameters:
///   - block: 结果回调
+(void)getWatchfaceUIInformationWithBlock:(FitCloudWatchfaceUIInfoResultBlock _Nullable)block;

#pragma mark 设置表盘模块化信息

/// 设置表盘模块化信息
/// - Parameters:
///   - position: 表盘位置，有效值0～10，调用该接口会切换表盘到该位置
///   - modules: 模块化信息，如果为nil，则只是切表盘，否则同时修改组件
///   - block: 结果回调
+(void)setWatchfacePostion:(NSInteger) position modules:(NSArray<FitCloudWatchfaceModule*>* _Nullable)modules completion:(FitCloudResultBlock _Nullable)block;


#pragma mark 女性健康设置

/// 女性健康设置
/// - Parameters:
///   - whSetting: 女性健康设置信息
///   - block: 结果回调
+(void)setWomenHealthConfig:(FitCloudWomenHealthSetting*_Nonnull)whSetting block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取女性健康设置

/// 获取女性健康设置
/// - Parameters:
///   - block: 结果回调
+(void)getWomenHealthSettingWithBlock:(FitCloudWomenHealthSettingResultBlock _Nullable )block;


#pragma mark 锁屏设置

/// 锁屏设置
/// - Parameters:
///   - lockScreenSetting: 锁屏设置
///   - block: 结果回调
+(void)setLockScreenSetting:(FitCloudLockScreenSetting* _Nonnull)lockScreenSetting block:(FitCloudResultBlock _Nullable)block;


#pragma mark APP主动点击退出睡眠

/// APP主动点击退出睡眠
/// - Parameters:
///   - block: 结果回调
+(void)exitSleepWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 同步系统语言

/// 同步系统语言，将手表的时间同步成跟手机的系统语言一致
///
/// 如果你自定义设定了手表语言将同步您的设定
/// - Parameters:
///   - block: 同步结果回调
+(void)syncSystemLanguageWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 自定义设置手表语言

/// 自定义设置手表语言
/// - Parameters:
///   - lang: 语言
///   - block: 结果回调
+(void)setSmartWatchLanguage:(FITCLOUDLANGUAGE)lang completion:(FitCloudResultBlock _Nullable )block;

#pragma mark 查询手表语言设置

/// 查询手表语言
/// - Parameters:
///   - completion: 查询结果回调
+(void)querySmartWatchLanguageWithCompletion:(FitCloudLanguageQueryCompletion _Nullable )completion;

#pragma mark 获取手表支持的游戏类型

/// 获取手表支持的游戏类型
/// - Parameters:
///   - block: 结果回调
+(void)getSupportedGamesWithBlock:(FitCloudSupportedGamesResultBlock _Nullable)block;

#pragma mark 获取游戏最高三个游戏记录

///获取游戏最高三个游戏记录
/// - Parameters:
///   - block: 结果回调
+(void)getTop3RankGameRecordsWithBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;

#pragma mark 获取单个游戏最高三个游戏记录

/// 获取单个游戏最高三个游戏记录
/// - Parameters:
///   - gameNo: 游戏编号
///   - block: 结果回调
+(void)getSingleGameTop3RankGameRecords:(NSInteger)gameNo withBlock:(FitCloudTop3RankGameRecordsResultBlock _Nullable)block;

#pragma mark 获取手表所有游戏的皮肤信息

/// 获取手表所有游戏的皮肤信息
/// - Parameters:
///   - block: 结果回调
+(void)getAllGameSkinsWithBlock:(FitCloudAllGameSkinsResultBlock _Nullable)block;

#pragma mark 设置游戏排名趋势

/// 设置游戏排名趋势
/// - Parameters:
///   - trendsArray: 排名趋势数组，最多60
///   - block: 结果回调
+(void)setGameRankingTrendsArray:(NSArray<FitCloudGameRankingTrend*>*)trendsArray completion:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取亮屏时长、亮度、振动等信息

/// 获取亮屏时长、亮度、振动等信息
/// - Parameters:
///   - block: 结果回调
+(void)getScreenAndVibrateSettingsWithBlock:(FitCloudScreenAndVibrateSettingsResultBlock _Nullable)block;

#pragma mark 获取屏幕分辨率相关信息

/// 获取屏幕分辨率相关信息
/// - Parameters:
///   - block: 结果回调
+(void)getScreenResolutionWithBlock:(FitCloudScreenResolutionResultBlock _Nullable)block;

#pragma mark 获取相册推送功能参数信息

/// 获取相册推送功能参数信息
/// - Parameters:
///   - block: 结果回调
+(void)getPhotoPushParamsWithBlock:(FitCloudPhotoAlbumParamsResultBlock _Nullable)block;

#pragma mark 获取设备可支持的运动模式类型列表

/// 获取设备可支持的运动模式类型列表
/// - Parameters:
///   - block: 结果回调
+(void)getSupportedWatchSportsWithBlock:(FitCloudSupportedWatchSportsResultBlock _Nullable)block;

#pragma mark 获取设备当前运动模式类型列表

/// 获取设备当前运动模式类型列表
/// - Parameters:
///   - block: 结果回调
+(void)getCurrentWatchSportsWithBlock:(FitCloudCurrentWatchSportsResultBlock _Nullable)block;

#pragma mark 获取手表指定支持的收款码和名片码功能列表

/// 获取手表指定支持的收款码和名片码功能列表
/// - Parameters:
///   - block: 结果回调
+(void) getWatchSpecifiedSupportedMoneyReceiveAndBusinessQRCodeFeaturesWithBlock:(FitCloudQRCodeFeaturesResultBlock _Nullable)block;

#pragma mark 设置勋章列表

/// 设置勋章列表（将手机上的勋章列表同步到手表）
/// - Parameters:
///   - medals: 勋章列表
///   - block: 结果回调
+(void) setMedals:(NSArray<FitCloudMedal*>*_Nullable)medals block:(FitCloudResultBlock _Nullable )block;

#pragma mark 获取勋章列表

/// 获取勋章列表（获取手表上的勋章列表）
/// - Parameters:
///   - block: 结果回调
+(void) getMedalsWithBlock:(FitCloudMedalsResultBlock _Nullable)block;

#pragma mark 获取支持的日程类型列表

/// 获取支持的日程类型列表（获取手表上支持的日程类型列表）
/// - Parameters:
///   - block: 结果回调
+(void) getSupportedSchedulesWithBlock:(FitCloudSupportedSchedulesResultBlock _Nullable)block;


#pragma mark 设置亮屏时长、亮度、振动等信息

/// 设置亮屏时长、亮度、振动等信息
/// - Parameters:
///   - screenSettings: 亮屏时长、亮度等信息
///   - vibrateSettings: 马达振动信息
///   - block: 结果回调
+(void)setScreenSettings:(FitCloudScreenSetting*) screenSettings vibrateSettings:(FitCloudVibrateSetting*)vibrateSettings completion:(FitCloudResultBlock _Nullable )block;

#pragma mark 查找手表 (查找成功则手表会震动或发出提醒声)

/// 查找手表 (查找成功则手表会震动或发出提醒声)
/// - Parameters:
///   - comletion: 结果回调
+(void)findWatchWithCompletion:(FitCloudResultBlock _Nullable )comletion;

#pragma mark 停止查找手表

/// 停止查找手表
/// - Parameters:
///   - comletion: 结果回调
+(void)stopFindWatchWithCompletion:(FitCloudResultBlock _Nullable )comletion;

#pragma mark 一键恢复出厂设置

/// 一键恢复出厂设置
/// - Parameters:
///   - block: 结果回调
+(void)restoreAsFactorySettingsWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 手表关机

/// 手表关机
/// - Parameters:
///   - block: 结果回调
+(void)turnOffWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 重启手表

/// 重启手表
/// - Parameters:
///   - block: 结果回调
+(void)rebootWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 设置广播数据自定义字段 key1

/// 设置广播数据自定义字段 key1
/// - Parameters:
///   - keyData: 自定义字段的key，注意keyData必须为6个字节，且需要自己管理字节序，SDK会将设置的值直接发送给手表
///   - block: 结果回调
+(void)setCustomBroadcastKey:(NSData*) keyData withBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark APP通知手表当前APP的定位服务状态

/// APP通知手表当前APP的定位服务状态
/// - Parameters:
///   - state: APP定位服务状态
///   - block: 结果回调
+(void)notifyAppLocServiceState:(APPLOCATIONSERVICESTATE)state withBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 推送收款码或名片二维码

/// 推送收款码或名片二维码
/// - Parameters:
///   - qrcode: 类型
///   - content: 二维码内容
///   - block: 结果回调
+(void)sendQRCode:(FITCLOUDQRCODE)qrcode content:(NSString*)content withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 设置手表启动震动参数

/// 设置手表启动震动参数
/// - Parameters:
///   - param: 参数
///   - block: 结果回调
+(void)setWatchLaunchVibrateParam:(FitCloudWatchLaunchVibrateSetting*) param withBlock:(FitCloudResultBlock _Nullable)block;


#pragma mark 删除手表上存储的消息

/// 删除手表上存储的消息
/// - Parameters:
///   - deleteIndex: 删除索引 0～n-1，0代表最新的一条  当 shouldDeleteAll 为 false 时有效
///   - shouldDeleteAll: 是否应该删除所有
///   - block: 结果回调
+(void)deleteWatchMessageWithIndex:(NSInteger)deleteIndex shouldDeleteAll:(BOOL)shouldDeleteAll withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 取消手表当前消息显示

/// 取消手表当前消息显示
/// - Parameters:
///   - block: 结果回调
+(void)dismissCurrentWatchMessageWithBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 游戏锁设置

/// 游戏锁设置
/// - Parameters:
///   - setting: 游戏锁设置
///   - block: 结果回调
+(void)setGamePasscodeSetting:(FitCloudGamePasscodeSetting* _Nonnull)setting block:(FitCloudResultBlock _Nullable)block;

#pragma mark 通知手表查找手机响铃播放完毕

/// 通知手表查找手机响铃播放完毕
/// - Parameters:
///   - block: 结果回调
+(void) notifyAppFindiPhoneRingPlayEndWithBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 发送支付宝Iot数据

/// 发送支付宝Iot数据
/// - Parameters:
///   - aliotData: 支付宝Iot数据
///   - block: 结果回调
+(void) sendAliotData:(NSData*)aliotData withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 发送网易云音乐桥接数据

/// 发送网易云音乐桥接数据
/// - Parameters:
///   - data: 发送网易云音乐桥接数据
+(void) sendNetEaseBridgeData:(NSData*)data;

#pragma mark 发送创维光伏数据

/// 发送创维光伏数据
/// - Parameters:
///   - stations: 光伏电站数据，最多支持6个电站，超过的自动忽略
///   - block: 结果回调
+(void) sendSkyworthPVData:(NSArray<SkyworthPVPowerStationObject*>*)stations withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 发送即将到来的板球比赛数据

/// 发送即将到来的板球比赛数据
/// - Parameters:
///   - matches: 比赛数据，目前最多支持两个
///   - block: 结果回调
+(void) sendUpcomingCricketMatchData:(NSArray<FitCloudCricketUpcomingMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 发送正在进行的板球比赛数据

/// 发送正在进行的板球比赛数据
/// - Parameters:
///   - matches: 比赛数据，目前最多支持两个
///   - block: 结果回调
+(void) sendLiveCricketMatchData:(NSArray<FitCloudCricketLiveMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;


#pragma mark 发送已经结束的板球比赛数据

/// 发送已经结束的板球比赛数据
/// - Parameters:
///   - matches: 比赛数据，目前最多支持两个
///   - block: 结果回调
+(void) sendEndedCricketMatchData:(NSArray<FitCloudCricketEndedMatch*>*)matches withBlock:(FitCloudResultBlock _Nullable)block;


#pragma mark 设置板球比分列表顺序

/// 设置板球比分列表顺序
/// - Parameters:
///   - match1order:  比赛1顺序
///   - match2order:  比赛2顺序
///   - block: 结果回调
+(void) sendCricketMatchScoreListOrderWith:(FitCloudCricketMatchScoreOrder*)match1order match2order:(FitCloudCricketMatchScoreOrder*)match2order withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 设置当前手机所在位置的GPS数据

/// 设置当前手机所在位置的GPS数据
/// - Parameters:
///   - gpsData: GPS数据
///   - block: 结果回调
+(void) sendGPSData:(FitCloudGPSData*)gpsData withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 获取手表上的GPS文件状态

/// 获取手表上的GPS文件状态
/// - Parameters:
///   - block: 结果回调
+(void) getWatchGPSFileStateWithBlock:(FitCloudWatchGPSFileStateResultBlock _Nullable)block;

#pragma mark 判断GPS文件是否过期

/// 判断GPS文件是否过期
/// - Parameters:
///   - filePath: GPS文件路径
///   - error: 错误信息
+(BOOL) gpsFileOutdated:(NSString*)filePath error:(NSError**) error;

#pragma mark 获取当前是否允许推送GPS文件

/// 获取当前是否允许推送GPS文件
/// - Parameters:
///   - block: 结果回调
+(void) getGPSFileCanPushWithBlock:(FitCloudGPSFileCanPushResultBlock _Nullable)block;

#pragma mark 准备GPS文件升级

/// 准备GPS文件升级
/// - Parameters:
///   - block: 结果回调
+(void) prepareGPSFileUpgradeWithCompletion:(FitCloudResultBlock _Nullable)block;


#pragma mark 导航信息同步

/// The navigation start callback
/// - Parameters:
///   - map: the navigation map
///   - naviType: navi type
///   - block: completion callback
+(void) onNaviStartWithMap:(FITCLOUDROUTEPLANMAPPROVIDER)map type:(FITCLOUDROUTEPLANNAVITYPE) naviType withBlock:(FitCloudResultBlock _Nullable)block;

/// The navigation guide kind callback
/// - Parameters:
///   - guideKind: the guide kind
///   - block: completion callback
+(void) onNaviGuideKind:(FITCLOUDROUTEPLANGUIDEKIND)guideKind withBlock:(FitCloudResultBlock _Nullable)block;

/// The navigation guide text callback
/// - Parameters:
///   - guideText: the guide text
///   - block: completion callback
+(void) onNaviGuideText:(NSString*)guideText withBlock:(FitCloudResultBlock _Nullable)block;

/// The remain time for navigation update callback
/// - Parameters:
///   - remainTime: the remain time in seconds
///   - block: completion callback
+(void) onNaviRemainTimeUpdate:(NSInteger)remainTime withBlock:(FitCloudResultBlock _Nullable)block;

/// The remain distance for navigation update callback
/// - Parameters:
///   - remainDistance: the remain distance in meters
///   - block: completion callback
+(void) onNaviRemainDistanceUpdate:(NSInteger)remainDistance withBlock:(FitCloudResultBlock _Nullable)block;

/// The navigation arrive destination callback
/// - Parameters:
///   - block: completion callback
+(void) onNaviArriveDestwithBlock:(FitCloudResultBlock _Nullable)block;

/// The naviagation exit callback
/// - Parameters:
///   - block: completion callback
+(void) onNaviExitwithBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark 电子卡包

/// Query the electronic cards from the smart watch
/// - Parameters:
///   - block: the electronic cards query result
+(void)getECardsWithBlock:(FitCloudECardsResultBlock _Nullable)block;

/// Set the electronic card
/// - Parameters:
///   - ecard: the electronic card
///   - block: the electronic card set response
+(void)setECard:(FitCloudECard*)ecard withBlock:(FitCloudResultBlock _Nullable)block;

/// sort the electronic cards
/// - Parameters:
///   - idArray: the electronic card id array
///   - block: the electronic cards sort response
+(void)sortECardsWithIdArray:(NSArray<NSNumber*>*) idArray withBlock:(FitCloudResultBlock _Nullable)block;

/// delete the electronic cards
/// - Parameters:
///   - idArray: the electronic card id array
///   - block: the electronic cards delete response
+(void)deleteECardsWithIdArray:(NSArray<NSNumber*>*) idArray withBlock:(FitCloudResultBlock _Nullable)block;

#pragma mark - 其他

/// 设置运动极限心率(Set maximum exercise heart rate)
/// - Parameters:
///   - value: 运动极限心率(maximum exercise heart rate)
///   - completion: the completion callback
+(void)setMaxExerciseHeartRate:(NSInteger)value withCompletion:(FitCloudResultBlock _Nullable)completion;

/// 获取运动极限心率(Query maximum exercise heart rate)
/// - Parameters:
///   - completion: the completion callback
+(void)queryMaxExerciseHeartRateWithCompletion:(void(^_Nullable)(BOOL success, NSInteger maxExerciseHeartRate, NSError*_Nullable error))completion;

/// 查询手表上的静息心率数据
/// - Parameters:
///   - completion: 结果回调
+(void) queryRestingHRWithCompletion:(FitCloudRestingHRQueryCompletion _Nullable)completion;

@end

/// FitCloudKit Bind Module
@interface FitCloudKit (Bind)

#pragma mark 是否已经绑定

/// 是否已经绑定
+(BOOL) alreadyBound;

#pragma mark 检查用户是否已经绑定

/// 检查用户是否已经绑定
/// - Parameters:
///   - userId: 用户Id
/// - Returns:
///  YES 已经绑定 NO 未绑定
+(BOOL) isUserAlreadyBound:(NSString*)userId;

#pragma mark 绑定用户

/// 绑定用户
/// - Parameters:
///   - userId: 用户Id
///   - randomCode: 随机码，如果没有，则填 nil，仅部分项目有该功能
///   - bAbort: 如果已经存在绑定用户是否终止，当为FALSE时，自动先解绑并绑定新的用户
///   - block: 结果回调
+(void)bindUserObject:(NSString*)userId randomCode:(NSString* _Nullable)randomCode abortIfExist:(BOOL)bAbort block:(FitCloudResultBlock _Nullable )block;

#pragma mark 最后绑定时间

/// 最后绑定时间
+(nullable NSDate*) lastBindDate;

#pragma mark 用户解绑

/// 用户解绑
/// - Parameters:
///   - shouldDisconnectIfSuccess: 解绑成功后是否需要自动断开连接
///   - block: 结果回调
+(void)unbindUserObject:(BOOL) shouldDisconnectIfSuccess block:(FitCloudResultBlock _Nullable )block;

@end

/// FitCloudKit Sports Module
@interface FitCloudKit (Sports)

#pragma mark 请求最新的健康测量数据

/// 请求最新的健康测量数据
/// - Parameters:
///   - block: 结果回调
+(void) requestLatestHealthMeasurementDataWithBlock:(FitCloudLatestHealthMeasurementDataResultBlock _Nullable )block;

#pragma mark 请求当天运动健康数据信息

/// 请求当天运动健康数据信息
/// - Parameters:
///   - block: 结果回调
+(void) requestHealthAndSportsDataTodayWithBlock:(FitCloudHealthAndSportsDataTodayResultBlock _Nullable )block;

#pragma mark 启动/关闭实时健康测量（心率、血氧、血压、呼吸频率等）

/// 启动/关闭实时健康测量（心率、血氧、血压、呼吸频率等）
/// - Parameters:
///   - rtmParam: 实时测量参数
///   - block: 调用结果回调
+(void) requestRealTimeHealthMeasuring:(FitCloudRealTimeHealthMeasuringParam*_Nonnull)rtmParam block:(FitCloudResultBlock _Nullable )block;

#pragma mark 手动同步历史运动健康数据

/// 手动同步历史运动健康数据
/// - Parameters:
///   - option: 选项，默认 FITCLOUDDATASYNCOPTION_LEGACY
///   - progress: 进度回调
///   - block: 结果回调
+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;

#pragma mark 请求当天睡眠调试数据

/// 请求当天睡眠调试数据
/// - Parameters:
///   - block: 结果回调，代表请求是否成功，不代表数据返回成功
+(void)requestSleepDebugDataWithBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 启动/关闭手表GPS互联运动

/// 启动/关闭GPS互联运动
/// - Parameters:
///   - params: 参数
///   - block: 调用结果回调
+(void) requestRealTimeGPSConnectSports:(FitCloudSportsWithGPSActionParams*_Nonnull)params block:(FitCloudResultBlock _Nullable )block;

#pragma mark 通知手表GPS互联运动当前App端运动数据

/// 通知手表GPS互联运动当前App端运动数据
/// - Parameters:
///   - appClientData: 已运动信息
///   - block: 调用结果回调
+(void) notifyRealTimeGPSConnectSportsAppClientData:(FitCloudSportsWithGPSAppClientData*_Nonnull)appClientData block:(FitCloudResultBlock _Nullable )block;

#pragma mark 请求手表GPS互联运动当前状态

/// 请求手表GPS互联运动当前状态
/// - Parameters:
///   - block: 调用结果回调
+(void) requestRealTimeGPSConnectSportsCurrentStatusWithBlock:(FitCloudGPSConnectSportsCurrentStatusResultBlock _Nullable) block;


#pragma mark 开启GSensor

/// 开启GSensor
/// - Parameters:
///   - block: 结果回调
+(void)openGSensorWithBlock:(FitCloudOpenGSensorResultBlock _Nullable )block;

#pragma mark 关闭GSensor

///关闭GSensor
/// - Parameters:
///   - block: 结果回调
+(void)closeGSensorWithBlock:(FitCloudResultBlock _Nullable )block;

@end

/// FitCloudKit RemoteCtrl Module
@interface FitCloudKit (RemoteCtrl)

#pragma mark APP通知手表当前APP的相机状态（前台/后台）

/// APP通知手表当前APP的相机状态（前台/后台）
/// - Parameters:
///   - state: APP相机状态（前台/后台）
///   - block: 结果回调
+(void)notifyAppCameraState:(APPCAMERASTATE)state withBlock:(FitCloudResultBlock _Nullable )block;

#pragma mark 通知手表第三方外设启停操作结果

/// 通知手表第三方外设启停操作结果
/// - Parameters:
///   - result: 结果
///   - block: 结果回调
+(void)notifyThirdPartyPeripheralStartStopResult:(THIRDPARTYPERIPHERALACTIONRESULT)result withBlock:(FitCloudResultBlock)block;

#pragma mark 通知手表第三方外设数据

/// 通知手表第三方外设数据
/// - Parameters:
///   - peripheral: 外设
///   - value: 数据
///   - block: 结果回调
+(void)notifyThirdPartyPeripheral:(THIRDPARTYPERIPHERAL) peripheral value:(CGFloat)value withBlock:(FitCloudResultBlock)block;
@end

/// FitCloudKit Dump Module
@interface FitCloudKit (Dump)

#pragma mark 发送Alexa结果

/// 发送Alexa结果
/// - Parameters:
///   - text: 结果
///   - errorCode: 错误码
///   - block: 结果回调
+(void)sendAlexaResult:(NSString*)text with:(ALEXAINVOKEERROR)errorCode withBlock:(FitCloudResultBlock _Nullable )block;

@end

/// 文心一言
@interface FitCloudKit (ERNIEBot)

#pragma mark 发送文心一言结果

/// 发送文心一言结果
/// - Parameters:
///   - text: 结果
///   - isEnd: 是否结束
///   - resultType: 文案类型
///   - completion: 结果回调
+(void) sendERNIEBotResult:(NSString*)text isEnd:(BOOL)isEnd resultType:(ERNIEBOTRESULTTYPE)resultType completion:(FitCloudResultBlock _Nullable) completion;

@end

/// FitCloudKit Mockup
@interface FitCloudKit (Mockup)

#pragma mark 模拟接收到远程手表发来的指令

/// mockup remote command
/// - Parameters:
///   - hexData: 十六进制字符串，0x开头
+(void)mockupRemoteCommandWithData:(NSString*) hexData;

@end

/// 新OTA
@interface FitCloudKit (NewOTA)

#pragma mark 传输新OTA升级文件

/// 传输新OTA升级文件
/// 尽量在后台线程调用该方法
/// - Parameters:
///   - newOTAFilePath: 新OTA升级文件路径
///   - startConfirmResult: 升级确认结果回调
///   - progress: 传输进度回调
///   - completion: 结果回调
+(void)sendNewOTA:(NSString*)newOTAFilePath startConfirmResult:(FitCloudNewOTAStartConfirmResultBlock _Nullable)startConfirmResult progress:(FitCloudNewOTAProgressBlock _Nullable)progress completion:(FitCloudNewOTACompletionBlock _Nullable)completion;

#pragma mark 取消传输新OTA升级文件

/// 取消传输新OTA升级文件
/// - Parameters:
///   - completion: 完成回调
+(void)cancelSendTheNewOTAIfNeededWithCompletion:(FitCloudNewOTACancelCompletionBlock _Nullable)completion;

@end

NS_ASSUME_NONNULL_END

