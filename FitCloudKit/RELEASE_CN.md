# 版本更新日志

## pcjbird 2024-12-04 Version:1.3.0-beta.40 Build:20241204002

- 添加事件以通知手表端运动(锻炼)状态的变化。
- 修复了设置和查询耳机仓歌词颜色的问题。
- 修复运动心率的一些问题。
- 重命名 API `+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;` 为 `+(void)manualSyncDataWithOption:(FITCLOUDDATASYNCOPTION)option progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;`, 新增同步任务结束回调，区别于数据结果回调。
- 重命名 API `+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block;` 为 `+(void)manualSingleSyncDataWithOption:(FITCLOUDDATASYNCOPTION) option dataKey:(MANUALSINGLESYNCKEY)syncKey progress:(FitCloudDataManualSyncProgress _Nullable)progress block:(FitCloudDataManualSyncResultBlock _Nullable )block finished:(FitCloudDataManualSyncFinishBlock _Nullable)finished;`, 新增同步任务结束回调，区别于数据结果回调。
- 优化一些数据同步的调试日志。
- 修复了从手表查询单类型健康自动监测设置信息的返回数据的一些问题。
- 添加`FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY`事件通知手表上对应表盘编号的表盘已被删除。
- 将 FitCloudOption 的属性 `onlyDiscoverRecognizedManufacturers` 重命名为 `onlyDiscoverKnownManufacturers`。
- 优化手表设备连接中的一些逻辑。
- 应用程序启动时，删除未绑定任何帐户 id 的无效连接记录。
- 修改解绑时逻辑为标记连接记录已解除绑定，而不是清除其帐户绑定信息。
- 当尝试连接标记为已解绑的手表设备时，将发出警告，指出连接失败的可能性。
- 优化手表设备扫描过程，这样即使在卸载和重新安装当前应用程序后，如果手表设备之前通过蓝牙广播扫描与当前应用程序连接，在扫描过程中仍然可以获得手表设备的 mac 地址。
- 将`FITCLOUDEVENT_WATCHSIDE_WATCHFACE_REMOVED_NOTIFY`事件的返回值从`object`参数修改为`userInfo`参数。
- 为穆斯林祈祷功能引入新的 API，包括设置祈祷闹钟、向手表设备提供伊斯兰日历事件以及克尔白信息数据。
- 椭圆机/划船机的训练数据支持返回最大触发频率和最小触发频率的数据。
- 修复当应用尝试断开手表设备但该设备已经断开连接且仍保留在自动连接池中时，仍然会自动重新连接的问题。
- 修复了某些项目中解析从手表设备同步的数据时出现的一些问题。
- 为朝拜克尔白数据添加应用程序位置权限信息。
- 引入新的 API `+(void)deleteWatchface:(NSInteger)watchfaceNo completion:(FitCloudResultHandler)completion`用于删除手表端的表盘。
- 添加连接超时选项，当您最初尝试手动连接到手表设备时，将应用以秒为单位的连接超时。如果达到此超时，将返回连接失败错误。随后，SDK 将尝试以静默方式重新连接。
- 将 SDK 初始化选项 `shouldAutoConnect` 重命名为 `shouldAutoReconnectWhenAppLaunch`。
- 修复微信支付指令发送的一些问题。
- 引入新的 API `+(void)deleteWatchfaceWithSlotIndex:(NSInteger)slotIndex completion:(FitCloudResultHandler)completion`用于删除手表端对应表盘位置的表盘。
- 引入新的 API，用于从手表端切换 iPhone 摄像头请求。
- 修复历史连接记录的一些问题, 特别当用户修改了手机时间。
- 引入新的 API 以处理来自手表端的地图导航快照请求。
- 表盘尺寸支持 240x320 方，184x276 方。
- 新 OTA 升级启动指令增加了待升级文件类型信息。
- 引入新的 API `+(void)clearWatchGPSFileWithCompletion:(FitCloudResultHandler _Nullable)completion` 以删除手表端的 GPS epo 文件。
- 支持华盛达`我的任务`相关指令。
- 新增`FITCLOUDMN_ZALO`通知定义。

## pcjbird 2024-09-30 Version:1.2.9 Build:20240930001

- 新增创维光伏数据支持, @see withSkyworthPV
- 新增一些调试日志
- 板球比赛数据指令支持, @see withCricketMatch
- 新增同步指定时间到手表支持
- GPS&EPO 支持, @see withGPSEpo
- 网易云音乐支持
- 表盘尺寸支持 228x460 方
- 新增习惯养成类型
- 新增获取手表的支持的日程类型列表 @see canGetSupportedSchedules
- 支持设置和获取勋章列表 @see withMedals
- 体感游戏支持 @see withMotionSensingGame
- 修改习惯养成协议
- 表盘尺寸支持 390x390 圆
- 新增导航信息同步支持,@see naviGuideSupported
- 表盘尺寸支持 390x450 方
- 表盘尺寸支持 286x240 方
- 新增相册推送支持,@see allowPhotoPush
- 新增电子书推送支持,@see allowEBookPush
- 新增小睡支持,@see withSnooze
- 新增快速眼动支持,@see withREM
- 新增超过 10 个常用联系人支持,@see allowHugeCountFavContacts
- 新增电子卡包功能
- 表盘尺寸支持 192x490 椭圆
- 新增心率监测时间段是否支持跨天标识,@see allowHeartRateMonitoringAcrossDays
- 新增设备能力查询支持,@see allowQueryDeviceCapacities, allConfig.deviceCapacities
- 新增获取运动训练展示数据项信息,@see withDisplayConfigInWorkoutData
- FitCloudOption 新增是否自动同步系统语言选项,@see autoSyncSystemLang
- 新 OTA 升级支持, @see withNewOTA
- 进入 DFU 模式新增返回错误类型 `FITCLOUDKITERROR_DFUNOTALLOWFORPOWERSAVINGMODE`
- 新增健康定时监测独立开关设置和查询功能, @see allowSingleHTMSettings
- 新增静态心率/动态心率过低报警功能, @see withHRLowAlarm
- 天气设置新增紫外线指数设置功能
- 新增猎声定制天气类型 @see FITCLOUDWEATHERTYPE_CLOUDYINEVENING/FITCLOUDWEATHERTYPE_CLEARINEVENING/FITCLOUDWEATHERTYPE_EVENINGSHOWERS
- 设备能力类型新增设备支持的天气种类数量
- 新增设置和查询运动极限心率，仅特定项目可用
- 新增猎声相关软件版本信息查询功能，仅该客户可用，版本信息数据由客户自行解析, @see FitCloudKit+Haylou.h
- 新增大模型支持, @see withLLM
- 新增猎声手表 SN 信息查询功能，仅该客户可用, @see FitCloudKit+Haylou.h
- 修改绑定 API，新增随机码，没有随机码是填 nil
- 绑定失败错误新增`手表需要恢复出厂设置才能绑定`
- 新增查询手表当前语言设置功能
- 新增手表端执行了停止查找手表操作通知, @see FITCLOUDEVENT_WATCHSIDE_PERFORM_STOP_FIND_WATCH_ACTION_NOTIFY
- 修改停止查找手表 API 名称，新增停止查找手表功能
- 每日运动目标新增设置运动时长目标
- 新增设置紧急联系人功能, @see withEmergencyContact
- 新增静息心率查询功能, @see withRestingHR
- 新增设置个性化提醒功能, @see withPersonalizedReminder, @see FITCLOUDDEVICECAPACITY
- 健康总数据以及计步数据新增运动时长数据
- 消息通知新增 Gmail/Outlook/WhatsApp Business
- 天气设置修改能见度精度到米
- 新增直接 DFU 升级(DFU 升级不进入 DFU 模式), 直接拿`[FitCloudKit directDFUPeripheral]`外设传入 FitCloudDFUKit, 仅特定客户手表可用
- 新增硬件平台标志, @see FITCLOUDHARDWARE_8773, FITCLOUDHARDWARE_568X
- 电子卡包名称最大长度修改成 32 字节
- 修正传音厂商标识，支持传音 MAC 地址解析
- 新增情侣功能, @see `[FitCloudKit isDeviceSupportFeature:FITCLOUDDEVICEFEATURE_LOVERS]`
- 新增 GPS 互联运动卡路里数据返回
- 新 OTA 新增帧重传机制
- 表盘尺寸支持 320x172 方
- 表盘尺寸支持 385x320 方
- 更新新 OTA 错误码
- 为防止用户的资料比较离谱导致手表算法问题，针对用户输入的资料进行修正再传给手表
- 优化切换表盘，及修改其对应的组件样式 API
- 优化手表返回的手表表盘 UI 信息
- 删除 SDK 里的运动类型定义，由 APP 层处理对应的运动类型，运动类型映射表找对接的商务或者产品经理要
- 新增支持返回快速眼动(REM)类型的睡眠数据
- 新增支持设置 24 小时天气信息，仅部分手表支持
- 新增泳池游泳和开放水域游泳运动数据同步
- 表盘尺寸支持 480x480 圆
- 表盘尺寸支持 194x368 方
- 芯与物 GPS 支持
- ANCS 通知扩展
- 耳机仓项目支持
- 新增支持跳绳/椭圆机/划船机相关运动扩展数据的同步
- 新增支持屏蔽心率加强测量
- 支持传音 Infinix 项目女性健康相关功能
- 支持获取手表端调试日志，仅部分手表支持
- `FitCloudKitConnectRecord` 新增 MAC 地址
- 引入事件`FITCLOUDEVENT_WATCHSIDE_TERMINATED_THE_MEASUREMENT_INITIALIZED_BY_THE_APPSIDE_NOTIFY`，表示手表端已手动终止 APP 端发起的测量。
- 运动心率数据在单独的数据列表中提供。 @see bpmDataArray
- 新增回调，当手表端进入或退出大语言模型功能的时候通知 APP
- 解决了在多个设备之间切换时连接的一些问题
- 表盘尺寸支持 360x360 方/296x240 方
- 引入新的 API`+(void)connectAndBind:(CBPeripheral * _Nonnull )peripheral userId:(NSString* _Nonnull)userId randomCode:(NSString* _Nullable)randomCode btMode:(BOOL)btMode;` 以允许主程序仅通过一个 API 调用来连接和绑定手表设备。
- 将 FitCloudKitConnectRecord 中的`time`属性重命名为`latestConnectTime`，并将`bindTime`属性命名为`userBindTime`
- 新增手表微信支付认证功能
- 新增启动和停止激光测量功能，同时支持查询激光测量状态

## pcjbird 2023-05-30 Version:1.2.8 Build:202305300001

- 表盘尺寸支持 410x502 方/416x416 圆/240x288 方
- 新增自定义标签功能 @see withCustomLabels
- 支付宝 Iot 支持, @see allowAliot
- 蓝牙连接支持设置是否使用一键双连同时连接经典蓝牙(BT), @see allowConnectWithBT
- 新增通过广播数据获取相关厂商信息及参数 @see FitCloudManufacturer
- 手表运动 GPS 数据传输支持 @see FitCloudGPSRecordObject
- 表盘尺寸支持 340x340 圆
- 新增指定支持的收款码和名片，仅支持的收款码和名片才应该在 App 上展示推送入口 @see specifySupportedMoneyReceiveAndBusinessQRCode
- 修改习惯养成指令
- 新增省电模式设置 @see withPowerSavingMode & allowPowerSavingModePeriod
- 设定每日目标新增时间戳参数
- 调整支付宝 Iot 安全认证指令
- 修改自动登录日志，userId 支持 String
- 修改获取手表 UI 信息指令解析，兼容固件版本
- 更新和新增了一大批运动类型定义
- 提升 SDK 稳定性

## pcjbird 2022-12-30 Version:1.2.7 Build:202212300001

- 新增禁用睡眠模块
- 新增核酸码推送功能 @see allowNucleicAcidQRCode
- 天气新增大气压强/风力/能见度信息
- 新增习惯养成相关指令 @see allowHabits
- 新增收款码：Paytm 收款码/PhonePe 收款码/GPay 收款码/BHTM 收款码，新增名片：Email 名片/Phone 名片/LinkedIn 名片, @see showAdditionalQRCodeTransfer
- 新增通知手表查找手机响铃播放完毕，适配蓝牙通话手表
- 新增获取每日运动目标指令
- 优化外设 MTU 值获取

## pcjbird 2022-09-20 Version:1.2.6 Build:202209200001

- 修正 GPS 互联运动指令的问题
- 新增基于气压泵的真血压(部分手表支持)
- 部分手表支持手表手动测量数据同步
- 部分手表支持发起 SOS 请求
- 新增第三方外设启停操作支持
- 新增手表启动震动参数设置
- 新增手表上存储的消息删除指令
- 新增取消手表当前消息显示
- 新增游戏锁设置
- 登录/绑定指令新增 iOS 系统版本标志
- 新增获取单个游戏最高三个游戏记录(部分手表支持)
- 修正真血压数据同步问题
- GPS 互联指令修改
- 新增游戏排名趋势设置(部分手表支持)
- 获取闹钟闹钟列表更新 SDK 闹钟列表缓存
- 更新 SDK 错误码翻译
- 运动健康数据防丢失处理
- 新增是否禁用在 App 上表盘模块化标志 @see disableWatchfaceModularInApp
- 新增表盘尺寸 240x296 方
- 提升 SDK 稳定性

## pcjbird 2022-01-26 Version:1.2.5 Build:202201260001

- 新增板球/自由运动/力量训练/室内健走/室内骑行/哑铃/跳舞/呼啦圈/高尔夫/跳远/仰卧起坐/排球运动定义
- 新增手表 GPS 互联运动
- 新增唤醒 APP 相机功能，该功能有缺陷，慎用
- 新增血压报警&心率报警功能设备支持检查
- 手表偏好设置新增`FITCLOUDPREFER_REMINDWHENSPORTSGOALACHIEVEMENT`，手表运动(计步/距离/卡路里)目标达成提醒
- 修正常用联系人指令数据量较大时的问题
- 修正 OTA 过程中关闭蓝牙可能导致闪退的问题
- 新增收款码和名片二维码推送
- 修正当手表断开连接的情况下解绑，当手表重新靠近手机的时候可能会重新回连的问题
- 修正测量心电时蓝牙断开连接可能导致无法正确回连的问题
- 新增通话手表绑定失败时音频蓝牙名称返回
- 新增印地语

## pcjbird 2021-10-12 Version:1.2.4 Build:202110120001

- 新增是否支持游戏皮肤推送标志
- 新增是否支持 Apple Music、Zoom & Tiktok 提醒标志及其通知定义
- 新增是否支持扫码连接标志
- 添加硬件标识`FITCLOUDHARDWARE_DFUSHOULDSILENTMODE`
- 新增俄罗斯方块游戏/数独游戏/答题游戏定义
- 扫码绑定项目新增绑定失败原因(手表主动取消/手表超时未点击确认)
- 新增获取/设置亮屏时长、亮度、振动等信息
- 新增是否应该禁用自定义表盘功能标识
- 新增手表离开查找手机功能界面回调
- 手表偏好设置新增蓝牙断开时手表振动选项
- 修复同步心电数据时手表断开连接导致之后无法回连的问题
- 新增获取屏幕分辨率原始信息(lcd 宽高/是否圆形屏幕/圆角大小等)指令，仅部分固件支持
- Nordic 平台表盘编号也扩展到 3 个字节
- 修复游戏皮肤获取只能获取到 3 条的问题
- 修改表盘/游戏皮肤最大可推送文件的大小计算规则
- 修改天气硬件功能标志位定义
- 新增手表是否支持运动模式(DIY)固件推送标识
- 新增获取设备可支持的运动模式类型列表/设备当前运动模式类型列表，仅部分手表支持

## pcjbird 2021-07-20 Version:1.2.3 Build:202107200001

- 新增压力指数测量，仅部分手表支持
- 修正日程设置指令的问题
- 修正锁屏密码设置指令的问题
- 表盘尺寸支持 280x240 方/200x320 方/368x448 方/320x390 方
- 新增表盘模块化(组件化)支持
- 修正日程获取指令的问题
- 支持自定义设定手表语言 @note: 如果你希望 SDK 初始化时就设定好，@see watchPreferLang for FitCloudOption
  如果你希望在 APP 运行中动态改变手表语言设定请调用 setSmartWatchLanguage:completion:
  此外，原先的 syncSystemLanguageWithBlock 也会受到影响，也就是说如果你自定义设定了手表语言，
  原先的 syncSystemLanguageWithBlock 也会同步自定义的手表语言设定
- 新增设置是否允许手表设置日程，仅当时手表支持日程功能时有效
- 支持将自行扫描的外设转换成可连接的外设
- 新 GUI 结构相关协议更新
- 下一代厂商名称支持，下一代厂商名称可以确定不需要过滤蓝牙名称中首字母 H
- 修正切换表盘导致表盘模块信息丢失的问题
- 多表盘推送支持获取每个表盘位置最大可推送固件的大小，单位：kB
- 支持 Nordic 芯片
- 新增获取手表支持的游戏类型，仅部分手表支持
- 新增获取游戏最高三个游戏记录，仅部分手表支持
- 新增获取手表上所有游戏对应的皮肤信息，仅部分手表支持
- 表盘尺寸支持 172x320 方/454x454 圆/128x220 方
- `+(void)ignoreConnectedPeripheral:(BOOL)silent;` 添加 silent 参数
- 新增`FITCLOUDEVENT_WATCH_PAIRINGINFO_NOTMATCH_OR_MISSING_NOTIFY`通知，建议用户进入系统设置解除与该手表的配对信息，杀死 App 进程并重新启动 App。具体参照其定义 @note: 该通知可能连续发送，应用层需要避免重复提示用户，给用户造成困扰

## pcjbird 2021-02-05 Version:1.2.2 Build:202102050001

- 新增天气推送开关，仅部分手表支持
- 新增通知手表 App 定位服务状态
- 新增洗手提醒功能
- 表盘尺寸支持 240x280 方
- 数据解析异常处理，条目过大，直接丢弃，不再解析数据
- 新增设置锁屏密码，仅部分手表支持
- 新增设置日程提醒，仅部分手表支持
- 新增 Hike 和 YouTube 通知提醒，仅部分手表支持
- 表盘尺寸支持 348x442 方
- 多表盘推送信息获取支持
- 新增运动类型定义

## pcjbird 2020-10-30 Version:1.2.1 Build:202010300001

- FitCloudOption 支持 preferSystemLocale 选项，当改选项设置为 TRUE 时，将向手表同步 iOS 系统的语言设置，否则向手表同步当前 APP 的语言设置，默认为 FALSE。 @note: 由于系统限制，当你手动修改了 APP 的语言，则该选项也会无效。
- 修正睡眠调试数据不正确响应的问题
- 支持设置健康监测间隔，需要手表支持，@see allowSetHealthMonitorInterval
- 支持设置久坐提醒间隔，需要手表支持，@see allowSetLSRInterval
- 支持设置天气预报，需要手表支持，@see allowWeatherForecast
- 新增天气更新时间，调整天气预报最大支持天数为 14 天
- 修正健康监测间隔/久坐提醒间隔设置不正确的问题
- 修正手表标志位解析不正确的问题
- 新增阿尔巴尼亚语
- 新增土耳其语/乌克兰语
- 修正无法同步韩语至手表的问题
- 补丁：当 allowShowAdditionalReminder 标志位为 true 时，allowShowMailReminder/allowShowTelegramAndViberReminder 强制为 true

## pcjbird 2020-07-18 Version:1.2.0 Build:202007180001

- 支持手表通知 APP 退出拍照模式
- 新增女性健康功能
- 新增防护提醒功能
- 修正匈牙利语不能同步到手表的问题
- 新增设置广播数据自定义字段 key1，华盛达专用
- 修正设置用户资料时年龄不正确的问题
- 新增获取当天睡眠调试数据
- 修正年龄设置不正确的问题
- 最新的健康测量数据新增体温数据(需要手表支持体温)
- 新增新的表盘尺寸的相关注释说明
- 支持设置 SDK 定义的所有本地化语言至手表

## pcjbird 2020-05-15 Version:1.1.9 Build:202005150001

支持体温测量，仅部分手表支持

## pcjbird 2020-04-25 Version:1.1.8 Build:202004250001

- 修正解绑有可能出现未断开连接的问题
- 修正在自动登录过程中手表断开连接有可能导致提示手表被其他手机终端绑定或已经被解绑的问题
- 修正当命令执行超时的情况下会丢掉下一条待执行的命令的问题
- 修正同步数据量较大的健康数据时可能导致超时的问题
- 解绑后清除电量信息
- 支持常用联系人，仅部分手表支持
- 手表运动模式新增椭圆机/瑜伽/乒乓球/跳绳等运动
- 修正心电启动失败时逻辑处理不正确的问题
- 修正连接手表超时不执行连接超时逻辑的问题

## pcjbird 2020-02-25 Version:1.1.7 Build:202002250001

- 新增斯洛伐克语/匈牙利语
- 修正手表返回的睡眠数据睡眠质量可能为非法值的情况
- 取消自动解绑逻辑,新增手表被其他手机终端绑定或已经被解绑通知 @see FITCLOUDEVENT_PERIPHERAL_ALREADYUNBUND_OR_BIND_BY_OTHERCLIENT_NOTIFY
- 所有回调以及通知均改成在 Gloal Queue 中调用，如果要在回调或者通知中更新 UI，请务必切换到主队列(Main Queue)
- 外部调用 disconnect 将不会自动回连
- 新增 FITCLOUDUSERBINDSTATUS_KICKEDOUT 用户绑定状态
- 新增 FITCLOUDEVENT_PERIPHERAL_WRITECHARACTERISTIC_READY_NOTIFIY 通知
- 新增支持新的睡眠格式 @see newSleepDataFormat
- 日志信息支持查看较大数据包的完整数据
- 手表端主动更改了开关设置(例如：抬腕唤醒开关，通知开关等)会适时更新到 App 端 @see FITCLOUDEVENT_WATCHCONFIG_REMOTE_MANUAL_CHANGED_NOTIFY
- 表盘信息获取方法修改
- 其他一些改进

## pcjbird 2019-11-21 Version:1.1.6 Build:201911210001

- 修正表盘 UI 信息接口无法正确响应的问题
- 解绑用户后取消当前手表连接记录的自动重连
- 优化手表连接初始化过程，防止意外重连
- 调整手表硬件相关信息为只读
- 绑定用户的 UserId 由整型修改成字符串型
- 新增获取手表最后一次健康测量数据(心率/血氧/血压)，仅部分手表支持，@see allowRetrieveLatestMeasurementData
- 修改进入和退出固件升级模式方法，现在您在首次固件升级之前以及所有固件升级操作完成之后分别手动调用进入固件升级模式和退出固件升级模式，同时适用于普通固件升级与表盘推送
- 新增 DFU 模式回连成功通知，这通常用于等待表盘推送/普通固件升级之后手表重启的场景
- 提升 SDK 稳定性

## pcjbird 2019-11-13 Version:1.1.5 Build:201911130001

- 新增勿扰模式(仅部分手表支持 @see allowDNDMode)

## pcjbird 2019-10-24 Version:1.1.4 Build:201910240001

- 实时测量 moment 修改精确到秒
- 修正同步数据 moment 使得不会超过当前同步时间

## pcjbird 2019-10-16 Version:1.1.3 Build:201910160001

- 计步数据引入距离&卡路里新算法
- 新增获取用户最后绑定时间
- 新增心率报警/血压报警设置
- 新增 Snapchat 消息提醒选项
- 设备扫描取消设备名称过滤
- 心电实时测量新增手表主动结束逻辑
- 新增获取表盘 UI 信息接口
- 新增获取手表广播数据缓存
- 新增蓝牙名称变更通知，新增蓝牙 RSSI 变更通知
- 提升 SDK 稳定性
- 避免歧义，`+(NSArray<FitCloudPeripheral *>*_Nonnull)peripherals` 修改为 `+(NSArray<FitCloudPeripheral *>*_Nonnull)discoveredPeripherals`

## pcjbird 2019-08-19 Version:1.1.2 Build:201908190002

- 修正蓝牙连接开始的通知时刻问题

## pcjbird 2019-08-19 Version:1.1.1 Build:201908190001

- 修正手表解绑没有清除上一次绑定手表的 Mac 地址的问题
- 新增绑定/登录成功后需要完成一些基础准备同步操作的开始与结束通知
- 修正 SDK 初始化选项 shouldAutoConnect 不起作用的问题

## pcjbird 2019-08-12 Version:1.1.0 Build:201908120001

- 支持后台蓝牙数据同步功能

## pcjbird 2019-07-21 Version:1.0.9 Build:201907210001

- 支持获取当前 SDK 版本信息

## pcjbird 2019-07-20 Version:1.0.8 Build:201907200001

- 修正 iPhone 日历设置成佛教日历或者日本日历的时候导致手表同步时间失败的问题
- 优化手表回连机制

## pcjbird 2019-06-28 Version:1.0.7 Build:201906280001

- 修正无法获取消息通知设置的一些问题

## pcjbird 2019-06-27 Version:1.0.6 Build:201906270001

- 扫描到的外部设备新增 mac 地址数据

## pcjbird 2019-06-25 Version:1.0.5 Build:201906250001

- 修改支持设置运动目标

## pcjbird 2019-05-17 Version:1.0.4 Build:201905170001

- 增加手表支持的语种

## pcjbird 2019-05-01 Version:1.0.3 Build:201905010001

- 首次发布 SDK 版本
