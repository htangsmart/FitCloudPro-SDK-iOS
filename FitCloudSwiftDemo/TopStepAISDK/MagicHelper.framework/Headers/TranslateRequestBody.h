

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TranslateRequestBody : NSObject

/// 输入的文本
@property (nonatomic, strong) NSString *text;

/// 翻译前语言 (zh, zh-CN两个格式都可以)
@property (nonatomic, strong) NSString *from;

/// 翻译后语言
@property (nonatomic, strong) NSString *to;

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

@end

/// 模型类型
typedef NSString * TranslateLanguage NS_STRING_ENUM;

/// 自动检测（只有from可以填写）
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAuto;

/// 中文(简体)
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCh;
/// 中文(繁体)
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCht;
/// 英语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEn;
/// 日语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageJa;
/// 韩语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKo;
/// 俄语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageRu;
/// 法语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFr;
/// 西班牙语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEs;
/// 阿拉伯语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAr;
/// 葡萄牙语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePt;
/// 南非荷兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAf;
/// 阿姆哈拉语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAm;
/// 阿塞拜疆语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageAz;
/// 巴什基尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBa;
/// 白俄罗斯语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBe;
/// 别姆巴语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBem;
/// 保加利亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBg;
/// 比斯拉马语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBi;
/// 孟加拉语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBn;
/// 波斯尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageBs;
/// 加泰罗尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCa;
/// 宿务语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCeb;
/// 科西嘉语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCo;
/// 塞舌尔克里奥尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCrs;
/// 捷克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCs;
/// 威尔士语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageCy;
/// 丹麦语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageDa;
/// 德语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageDe;
/// 埃维语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEe;
/// 希腊语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEl;
/// 世界语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEo;
/// 爱沙尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEt;
/// 巴斯克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageEu;
/// 波斯语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFa;
/// 芬兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFi;
/// 菲律宾语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFil;
/// 斐济语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFj;
/// 弗里西语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageFy;
/// 爱尔兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageGa;
/// 苏格兰盖尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageGd;
/// 加利西亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageGl;
/// 古吉拉特语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageGu;
/// 豪萨语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHa;
/// 夏威夷语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHaw;
/// 希伯来语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHe;
/// 印地语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHi;
/// 克罗地亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHr;

/// 海地克里奥尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHt;
/// 匈牙利语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHu;
/// 亚美尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageHy;
/// 印尼语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageId;
/// 伊博语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageIg;
/// 冰岛语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageIs;
/// 意大利语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageIt;
/// 印尼爪哇语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageJv;
/// 格鲁吉亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageJy;
/// 哈萨克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKa;
/// 凯克其语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKek;
/// 刚果语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKg;
/// 哈萨克语（西里尔）
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKk;
/// 高棉语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKm;
/// 卡纳达语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKn;
/// 库尔德语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKu;
/// 吉尔吉斯语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageKy;
/// 拉丁语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLa;
/// 卢森堡语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLb;
/// 卢干达语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLg;
/// 林加拉语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLn;
/// 老挝语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLo;
/// 立陶宛语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLt;
/// 拉脱维亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageLv;
/// 马尔加什语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMg;
/// 马里语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMhr;
/// 毛利语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMi;
/// 马其顿语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMk;
/// 马拉雅拉姆语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMl;
/// 蒙古语(西里尔)
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMn;
/// 马拉地语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMr;
/// 山地马里语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMrj;
/// 马来语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMs;
/// 马耳他语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMt;
/// 白苗文
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMww;
/// 缅甸语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageMy;
/// 博克马尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageNb;
/// 尼泊尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageNe;
/// 荷兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageNl;
/// 挪威语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageNo;
/// 齐切瓦语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageNy;
/// 奥罗莫语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageOm;
/// 奥赛梯语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageOs;
/// 克雷塔罗奥托米语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageOtq;
/// 旁遮普语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePa;
/// 帕皮阿门托语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePap;
/// 波兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePl;

/// 普什图语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguagePs;
/// 隆迪语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageRn;
/// 罗马尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageRo;
/// 卢旺达语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageRw;
/// 信德语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSd;
/// 桑戈语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSg;
/// 僧伽罗语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSi;
/// 斯洛伐克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSk;
/// 斯洛文尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSl;
/// 萨摩亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSm;
/// 修纳语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSn;
/// 索马里语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSo;
/// 阿尔巴尼亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSq;
/// 塞尔维亚语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSr;
/// 塞索托语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSt;
/// 印尼巽他语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSu;
/// 瑞典语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSv;
/// 斯瓦希里语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageSw;
/// 泰米尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTa;
/// 泰卢固语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTe;
/// 塔吉克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTg;
/// 茨瓦纳语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTn;
/// 泰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTh;
/// 藏语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTi;
/// 提格雷语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTig;
/// 土库曼语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTk;
/// 汤加语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTo;
/// 巴布亚皮钦语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTpi;
/// 土耳其语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTr;
/// 聪加语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTs;
/// 鞑靼语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTt;
/// 契维语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTw;
/// 塔希提语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageTy;
/// 乌德穆尔特语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageUdm;
/// 乌克兰语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageUk;
/// 乌尔都语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageUr;
/// 维吾尔语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageUy;
/// 乌兹别克语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageUz;
/// 越南语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageVi;
/// 瓦瑞语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageWar;
/// 南非科萨语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageXh;
/// 意第绪语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageYi;
/// 约鲁巴语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageYo;
/// 尤卡坦玛雅语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageYua;
/// 广东话
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageYue;
/// 南非祖鲁语
FOUNDATION_EXPORT TranslateLanguage const TranslateLanguageZu;
NS_ASSUME_NONNULL_END
