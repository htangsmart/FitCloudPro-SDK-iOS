# 版本日志

## pcjbird 2024-09-30 Version:1.2.9 Build:20240930001

    1.新增创维光伏数据支持, @see withSkyworthPV
    2.新增一些调试日志
    3.板球比赛数据指令支持, @see withCricketMatch
    4.新增同步指定时间到手表支持
    5.GPS&EPO支持, @see withGPSEpo
    6.网易云音乐支持
    7.表盘尺寸支持228x460方
    8.新增习惯养成类型
    9.新增获取手表的支持的日程类型列表 @see canGetSupportedSchedules
    10.支持设置和获取勋章列表 @see withMedals
    11.体感游戏支持 @see withMotionSensingGame
    12.修改习惯养成协议
    13.表盘尺寸支持390x390圆
    14.新增导航信息同步支持,@see naviGuideSupported
    15.表盘尺寸支持390x450方
    16.表盘尺寸支持286x240方
    17.新增相册推送支持,@see allowPhotoPush
    18.新增电子书推送支持,@see allowEBookPush
    19.新增小睡支持,@see withSnooze
    20.新增快速眼动支持,@see withREM
    21.新增超过10个常用联系人支持,@see allowHugeCountFavContacts
    22.新增电子卡包功能
    23.表盘尺寸支持192x490方
    24.新增心率监测时间段是否支持跨天标识,@see allowHeartRateMonitoringAcrossDays
    25.新增设备能力查询支持,@see allowQueryDeviceCapacities, allConfig.deviceCapacities
    26.新增获取运动训练展示数据项信息,@see withDisplayConfigInWorkoutData
    27.FitCloudOption新增是否自动同步系统语言选项,@see autoSyncSystemLang
    28.新OTA升级支持, @see withNewOTA
    29.进入DFU模式新增返回错误类型 `FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE`
    30.新增健康定时监测独立开关设置和查询功能, @see allowSingleHTMSettings
    31.新增静态心率/动态心率过低报警功能, @see withHRLowAlarm
    32.天气设置新增紫外线指数设置功能
    33.新增猎声定制天气类型 @see FITCLOUDWEATHERTYPE_CLOUDYINEVENING/FITCLOUDWEATHERTYPE_CLEARINEVENING/FITCLOUDWEATHERTYPE_EVENINGSHOWERS
    34.设备能力类型新增设备支持的天气种类数量
    35.新增设置和查询运动极限心率，仅特定项目可用
    36.新增猎声相关软件版本信息查询功能，仅该客户可用，版本信息数据由客户自行解析, @see FitCloudKit+Haylou.h
    37.新增大模型支持, @see withLLM
    38.新增猎声手表SN信息查询功能，仅该客户可用, @see FitCloudKit+Haylou.h
    39.修改绑定API，新增随机码，没有随机码是填nil
    40.绑定失败错误新增`手表需要恢复出厂设置才能绑定`
    41.新增查询手表当前语言设置功能
    42.新增手表端执行了停止查找手表操作通知, @see FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY
    43.修改停止查找手表API名称，新增停止查找手表功能
    44.每日运动目标新增设置运动时长目标
    45.新增设置紧急联系人功能, @see withEmergencyContact
    46.新增静息心率查询功能, @see withRestingHR
    47.新增设置个性化提醒功能, @see withPersonalizedReminder, @see FITCLOUDDEVICECAPACITY
    48.健康总数据以及计步数据新增运动时长数据
    49.消息通知新增Gmail/Outlook/WhatsApp Business
    50.天气设置修改能见度精度到米
    51.新增直接DFU升级(DFU升级不进入DFU模式), 直接拿`[FitCloudKit directDFUPeripheral]`外设传入FitCloudDFUKit, 仅特定客户手表可用
    52.新增硬件平台标志, @see FITCLOUDHARDWARE_8773, FITCLOUDHARDWARE_568X
    53.电子卡包名称最大长度修改成32字节
    54.修正传音厂商标识，支持传音MAC地址解析
    55.新增情侣功能, @see `[FitCloudKit isDeviceSupportFeature:FITCLOUDDEVICEFEATURE_LOVERS]`
    56.新增GPS互联运动卡路里数据返回
    57.新OTA新增帧重传机制
    58.表盘尺寸支持320x172方
    59.表盘尺寸支持385x320方
    60.更新新OTA错误码
    61.为防止用户的资料比较离谱导致手表算法问题，针对用户输入的资料进行修正再传给手表
    62.优化切换表盘，及修改其对应的组件样式API
    63.优化手表返回的手表表盘UI信息
    64.删除SDK里的运动类型定义，由APP层处理对应的运动类型，运动类型映射表找对接的商务或者产品经理要
    65.新增支持返回快速眼动(REM)类型的睡眠数据
    66.新增支持设置24小时天气信息，仅部分手表支持
    67.新增泳池游泳和开放水域游泳运动数据同步
    68.表盘尺寸支持480x480圆
    69.表盘尺寸支持194x368方
    70.芯与物GPS支持
    71.ANCS通知扩展
    72.耳机仓项目支持
    73.新增支持跳绳/椭圆机/划船机相关运动扩展数据的同步
    74.新增支持屏蔽心率加强测量
    75.支持传音Infinix项目女性健康相关功能
    76.支持获取手表端调试日志，仅部分手表支持
    77.`FitCloudKitConnectRecord` 新增MAC地址
    78.引入事件“FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY”，表示手表端已手动终止APP端发起的测量。
    79.运动心率数据在单独的数据列表中提供。 @see bpmDataArray
    80.新增回调，当手表端进入或退出大语言模型功能的时候通知APP
    81.解决了在多个设备之间切换时连接的一些问题
    82.表盘尺寸支持360x360方/296x240方
    83.引入新的API`+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` 以允许主程序仅通过一个API调用来连接和绑定手表设备。
    84.将FitCloudKitConnectRecord中的`time`属性重命名为`latestConnectTime`，并将`bindTime`属性命名为`userBindTime`
    85.新增手表微信支付认证功能
    86.新增启动和停止激光测量功能，同时支持查询激光测量状态

## pcjbird 2023-05-30 Version:1.2.8 Build:202305300001

    1.表盘尺寸支持410x502方/416x416圆/240x288方
    2.新增自定义标签功能 @see withCustomLabels
    3.支付宝Iot支持, @see allowAliot
    4.蓝牙连接支持设置是否使用一键双连同时连接经典蓝牙(BT), @see allowConnectWithBT
    5.新增通过广播数据获取相关厂商信息及参数 @see FitCloudManufacturer
    6.手表运动GPS数据传输支持 @see FitCloudGPSRecordObject
    7.表盘尺寸支持340x340圆
    8.新增指定支持的收款码和名片，仅支持的收款码和名片才应该在App上展示推送入口 @see specifySupportedMoneyReceiveAndBusinessQRCode
    9.修改习惯养成指令
    10.新增省电模式设置 @see withPowerSavingMode & allowPowerSavingModePeriod
    11.设定每日目标新增时间戳参数
    12.调整支付宝Iot安全认证指令
    13.修改自动登录日志，userId支持String
    14.修改获取手表UI信息指令解析，兼容固件版本
    15.更新和新增了一大批运动类型定义
    16.提升SDK稳定性

## pcjbird 2022-12-30 Version:1.2.7 Build:202212300001

    1.新增禁用睡眠模块
    2.新增核酸码推送功能 @see allowNucleicAcidQRCode
    3.天气新增大气压强/风力/能见度信息
    4.新增习惯养成相关指令 @see allowHabits
    5.新增收款码：Paytm收款码/PhonePe收款码/GPay收款码/BHTM收款码，新增名片：Email名片/Phone名片/LinkedIn名片, @see showAdditionalQRCodeTransfer
    6.新增通知手表查找手机响铃播放完毕，适配蓝牙通话手表
    7.新增获取每日运动目标指令
    8.优化外设MTU值获取

## pcjbird 2022-09-20 Version:1.2.6 Build:202209200001

    1.修正GPS互联运动指令的问题
    2.新增基于气压泵的真血压(部分手表支持)
    3.部分手表支持手表手动测量数据同步
    4.部分手表支持发起SOS请求
    5.新增第三方外设启停操作支持
    6.新增手表启动震动参数设置
    7.新增手表上存储的消息删除指令
    8.新增取消手表当前消息显示
    9.新增游戏锁设置
    10.登录/绑定指令新增iOS系统版本标志
    11.新增获取单个游戏最高三个游戏记录(部分手表支持)
    12.修正真血压数据同步问题
    13.GPS互联指令修改
    14.新增游戏排名趋势设置(部分手表支持)
    15.获取闹钟闹钟列表更新SDK闹钟列表缓存
    16.更新SDK错误码翻译
    17.运动健康数据防丢失处理
    18.新增是否禁用在App上表盘模块化标志 @see disableWatchfaceModularInApp
    19.新增表盘尺寸240x296方
    20.提升SDK稳定性

## pcjbird 2022-01-26 Version:1.2.5 Build:202201260001

    1.新增板球/自由运动/力量训练/室内健走/室内骑行/哑铃/跳舞/呼啦圈/高尔夫/跳远/仰卧起坐/排球运动定义
    2.新增手表GPS互联运动
    3.新增唤醒APP相机功能，该功能有缺陷，慎用
    4.新增血压报警&心率报警功能设备支持检查
    5.手表偏好设置新增`FITCLOUDPREFER_REMINDWHENSPORTSGOALACHIEVEMENT`，手表运动(计步/距离/卡路里)目标达成提醒
    6.修正常用联系人指令数据量较大时的问题
    7.修正OTA过程中关闭蓝牙可能导致闪退的问题
    8.新增收款码和名片二维码推送
    9.修正当手表断开连接的情况下解绑，当手表重新靠近手机的时候可能会重新回连的问题
    10.修正测量心电时蓝牙断开连接可能导致无法正确回连的问题
    11.新增通话手表绑定失败时音频蓝牙名称返回
    12.新增印地语

## pcjbird 2021-10-12 Version:1.2.4 Build:202110120001

    1.新增是否支持游戏皮肤推送标志
    2.新增是否支持Apple Music、Zoom & Tiktok 提醒标志及其通知定义
    3.新增是否支持扫码连接标志
    4.添加硬件标识`FITCLOUDHARDWARE_DFUSHOULDSILENTMODE`
    5.新增俄罗斯方块游戏/数独游戏/答题游戏定义
    6.扫码绑定项目新增绑定失败原因(手表主动取消/手表超时未点击确认)
    7.新增获取/设置亮屏时长、亮度、振动等信息
    8.新增是否应该禁用自定义表盘功能标识
    9.新增手表离开查找手机功能界面回调
    10.手表偏好设置新增蓝牙断开时手表振动选项
    11.修复同步心电数据时手表断开连接导致之后无法回连的问题
    12.新增获取屏幕分辨率原始信息(lcd宽高/是否圆形屏幕/圆角大小等)指令，仅部分固件支持
    13.Nordic平台表盘编号也扩展到3个字节
    14.修复游戏皮肤获取只能获取到3条的问题
    15.修改表盘/游戏皮肤最大可推送文件的大小计算规则
    16.修改天气硬件功能标志位定义
    17.新增手表是否支持运动模式(DIY)固件推送标识
    18.新增获取设备可支持的运动模式类型列表/设备当前运动模式类型列表，仅部分手表支持

## pcjbird 2021-07-20 Version:1.2.3 Build:202107200001

    1.新增压力指数测量，仅部分手表支持
    2.修正日程设置指令的问题
    3.修正锁屏密码设置指令的问题
    4.表盘尺寸支持280x240方/200x320方/368x448方/320x390方
    5.新增表盘模块化(组件化)支持
    6.修正日程获取指令的问题
    7.支持自定义设定手表语言  @note: 如果你希望SDK初始化时就设定好，@see watchPreferLang for FitCloudOption
    如果你希望在APP运行中动态改变手表语言设定请调用setSmartWatchLanguage:completion:
    此外，原先的syncSystemLanguageWithBlock也会受到影响，也就是说如果你自定义设定了手表语言，
    原先的syncSystemLanguageWithBlock也会同步自定义的手表语言设定
    8.新增设置是否允许手表设置日程，仅当时手表支持日程功能时有效
    9.支持将自行扫描的外设转换成可连接的外设
    10.新GUI结构相关协议更新
    11.下一代厂商名称支持，下一代厂商名称可以确定不需要过滤蓝牙名称中首字母H
    12.修正切换表盘导致表盘模块信息丢失的问题
    13.多表盘推送支持获取每个表盘位置最大可推送固件的大小，单位：kB
    14.支持Nordic芯片
    15.新增获取手表支持的游戏类型，仅部分手表支持
    16.新增获取游戏最高三个游戏记录，仅部分手表支持
    17.新增获取手表上所有游戏对应的皮肤信息，仅部分手表支持
    18.表盘尺寸支持172x320方/454x454圆/128x220方
    19.`+(void)ignoreConnectedPeripheral:(BOOL)silent;` 添加 silent 参数
    20. 新增`FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY`通知，建议用户进入系统设置解除与该手表的配对信息，杀死App进程并重新启动App。具体参照其定义  @note: 该通知可能连续发送，应用层需要避免重复提示用户，给用户造成困扰

## pcjbird 2021-02-05 Version:1.2.2 Build:202102050001

    1.新增天气推送开关，仅部分手表支持
    2.新增通知手表App定位服务状态
    3.新增洗手提醒功能
    4.表盘尺寸支持240x280方
    5.数据解析异常处理，条目过大，直接丢弃，不再解析数据
    6.新增设置锁屏密码，仅部分手表支持
    7.新增设置日程提醒，仅部分手表支持
    8.新增Hike和YouTube通知提醒，仅部分手表支持
    9.表盘尺寸支持348x442方
    10.多表盘推送信息获取支持
    11.新增运动类型定义

## pcjbird 2020-10-30 Version:1.2.1 Build:202010300001

    1.FitCloudOption 支持 preferSystemLocale 选项，当改选项设置为 TRUE 时，将向手表同步 iOS 系统的语言设置，否则向手表同步当前 APP 的语言设置，默认为 FALSE。@note: 由于系统限制，当你手动修改了APP的语言，则该选项也会无效。
    2.修正睡眠调试数据不正确响应的问题
    3.支持设置健康监测间隔，需要手表支持，@see allowSetHealthMonitorInterval
    4.支持设置久坐提醒间隔，需要手表支持，@see allowSetLSRInterval
    5.支持设置天气预报，需要手表支持，@see allowWeatherForecast
    6.新增天气更新时间，调整天气预报最大支持天数为14天
    7.修正健康监测间隔/久坐提醒间隔设置不正确的问题
    8.修正手表标志位解析不正确的问题
    9.新增阿尔巴尼亚语
    10.新增土耳其语/乌克兰语
    11.修正无法同步韩语至手表的问题
    12.补丁：当allowShowAdditionalReminder标志位为true时，allowShowMailReminder/allowShowTelegramAndViberReminder强制为true

## pcjbird 2020-07-18 Version:1.2.0 Build:202007180001

    1.支持手表通知APP退出拍照模式
    2.新增女性健康功能
    3.新增防护提醒功能
    4.修正匈牙利语不能同步到手表的问题
    5.新增设置广播数据自定义字段 key1，华盛达专用
    6.修正设置用户资料时年龄不正确的问题
    7.新增获取当天睡眠调试数据
    8.修正年龄设置不正确的问题
    9.最新的健康测量数据新增体温数据(需要手表支持体温)
    10.新增新的表盘尺寸的相关注释说明
    11.支持设置SDK定义的所有本地化语言至手表

## pcjbird 2020-05-15 Version:1.1.9 Build:202005150001

    1.支持体温测量，仅部分手表支持

## pcjbird 2020-04-25 Version:1.1.8 Build:202004250001

    1.修正解绑有可能出现未断开连接的问题
    2.修正在自动登录过程中手表断开连接有可能导致提示手表被其他手机终端绑定或已经被解绑的问题
    3.修正当命令执行超时的情况下会丢掉下一条待执行的命令的问题
    4.修正同步数据量较大的健康数据时可能导致超时的问题
    5.解绑后清除电量信息
    6.支持常用联系人，仅部分手表支持
    7.手表运动模式新增椭圆机/瑜伽/乒乓球/跳绳等运动
    8.修正心电启动失败时逻辑处理不正确的问题
    9.修正连接手表超时不执行连接超时逻辑的问题

## pcjbird 2020-02-25 Version:1.1.7 Build:202002250001

    1.新增斯洛伐克语/匈牙利语
    2.修正手表返回的睡眠数据睡眠质量可能为非法值的情况
    3.取消自动解绑逻辑,新增手表被其他手机终端绑定或已经被解绑通知 @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY
    4.所有回调以及通知均改成在 Gloal Queue 中调用，如果要在回调或者通知中更新UI，请务必切换到主队列(Main Queue)
    5.外部调用 disconnect 将不会自动回连
    6.新增 FITCLOUDUSERBINDSTATUS_KICKEDOUT 用户绑定状态
    7.新增 FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY 通知
    8.新增支持新的睡眠格式 @see newSleepDataFormat
    9.日志信息支持查看较大数据包的完整数据
    10.手表端主动更改了开关设置(例如：抬腕唤醒开关，通知开关等)会适时更新到App端 @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY
    11.表盘信息获取方法修改
    12.其他一些改进

## pcjbird 2019-11-21 Version:1.1.6 Build:201911210001

    1.修正表盘UI信息接口无法正确响应的问题
    2.解绑用户后取消当前手表连接记录的自动重连
    3.优化手表连接初始化过程，防止意外重连
    4.调整手表硬件相关信息为只读
    5.绑定用户的UserId由整型修改成字符串型
    6.新增获取手表最后一次健康测量数据(心率/血氧/血压)，仅部分手表支持，@see allowRetrieveLatestMeasurementData
    7.修改进入和退出固件升级模式方法，现在您在首次固件升级之前以及所有固件升级操作完成之后分别手动调用进入固件升级模式和退出固件升级模式，同时适用于普通固件升级与表盘推送
    8.新增DFU模式回连成功通知，这通常用于等待表盘推送/普通固件升级之后手表重启的场景
    9.提升SDK稳定性

## pcjbird 2019-11-13 Version:1.1.5 Build:201911130001

    1.新增勿扰模式(仅部分手表支持 @see allowDNDMode)

## pcjbird 2019-10-24 Version:1.1.4 Build:201910240001

    1.实时测量moment修改精确到秒
    2.修正同步数据moment使得不会超过当前同步时间

## pcjbird 2019-10-16 Version:1.1.3 Build:201910160001

    1.计步数据引入距离&卡路里新算法
    2.新增获取用户最后绑定时间
    3.新增心率报警/血压报警设置
    4.新增Snapchat消息提醒选项
    5.设备扫描取消设备名称过滤
    6.心电实时测量新增手表主动结束逻辑
    7.新增获取表盘UI信息接口
    8.新增获取手表广播数据缓存
    9.新增蓝牙名称变更通知，新增蓝牙RSSI变更通知
    10.提升SDK稳定性
    11.避免歧义，`+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals` 修改为  `+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals`

## pcjbird 2019-08-19 Version:1.1.2 Build:201908190002

    1.修正蓝牙连接开始的通知时刻问题

## pcjbird 2019-08-19 Version:1.1.1 Build:201908190001

    1.修正手表解绑没有清除上一次绑定手表的Mac地址的问题
    2.新增绑定/登录成功后需要完成一些基础准备同步操作的开始与结束通知
    3.修正SDK初始化选项shouldAutoConnect不起作用的问题

## pcjbird 2019-08-12 Version:1.1.0 Build:201908120001

    1.支持后台蓝牙数据同步功能

## pcjbird 2019-07-21 Version:1.0.9 Build:201907210001

    1.支持获取当前SDK版本信息

## pcjbird 2019-07-20 Version:1.0.8 Build:201907200001

    1.修正iPhone日历设置成佛教日历或者日本日历的时候导致手表同步时间失败的问题
    2.优化手表回连机制

## pcjbird 2019-06-28 Version:1.0.7 Build:201906280001

    1.修正无法获取消息通知设置的一些问题

## pcjbird 2019-06-27 Version:1.0.6 Build:201906270001

    1.扫描到的外部设备新增mac地址数据

## pcjbird 2019-06-25 Version:1.0.5 Build:201906250001

    1.修改支持设置运动目标

## pcjbird 2019-05-17 Version:1.0.4 Build:201905170001

    1.增加手表支持的语种

## pcjbird 2019-05-01 Version:1.0.3 Build:201905010001

    1.首次发布SDK版本