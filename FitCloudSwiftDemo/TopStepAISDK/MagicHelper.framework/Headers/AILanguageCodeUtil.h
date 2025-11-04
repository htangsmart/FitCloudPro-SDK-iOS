//
//  AILanguageCodeUtil.h
//  MagicHelper
//
//  Created by ymz on 2025/10/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AILanguageCode) {
    AILanguageCodeAR,   // 阿拉伯语 (Arabic)
    AILanguageCodeBG,   // 保加利亚语 (Bulgarian)
    AILanguageCodeBN,   // 孟加拉语 (Bengali)
    AILanguageCodeBS,   // 波斯尼亚语 (Bosnian)
    AILanguageCodeDA,   // 丹麦语 (Danish)
    AILanguageCodeDE,   // 德语 (German)
    AILanguageCodeEL,   // 希腊语 (Greek)
    AILanguageCodeEN,   // 英语 (English)
    AILanguageCodeES,   // 西班牙语 (Spanish)
    AILanguageCodeET,   // 爱沙尼亚语 (Estonian)
    AILanguageCodeFA,   // 波斯语 (Persian / Farsi)
    AILanguageCodeFI,   // 芬兰语 (Finnish)
    AILanguageCodeFIL,  // 菲律宾语 (Filipino)
    AILanguageCodeFR,   // 法语 (French)
    AILanguageCodeGA,   // 爱尔兰语 (Irish)
    AILanguageCodeGL,   // 加利西亚语 (Galician)
    AILanguageCodeHI,   // 印地语 (Hindi)
    AILanguageCodeHR,   // 克罗地亚语 (Croatian)
    AILanguageCodeHU,   // 匈牙利语 (Hungarian)
    AILanguageCodeID,   // 印度尼西亚语 (Indonesian)
    AILanguageCodeIT,   // 意大利语 (Italian)
    AILanguageCodeJA,   // 日语 (Japanese)
    AILanguageCodeJV,   // 爪哇语 (Javanese)
    AILanguageCodeKA,   // 格鲁吉亚语 (Georgian)
    AILanguageCodeLO,   // 老挝语 (Lao)
    AILanguageCodeLT,   // 立陶宛语 (Lithuanian)
    AILanguageCodeLV,   // 拉脱维亚语 (Latvian)
    AILanguageCodeMS,   // 马来语 (Malay)
    AILanguageCodeMY,   // 缅甸语 (Burmese)
    AILanguageCodeNL,   // 荷兰语 (Dutch)
    AILanguageCodePL,   // 波兰语 (Polish)
    AILanguageCodePT,   // 葡萄牙语 (Portuguese)
    AILanguageCodeRO,   // 罗马尼亚语 (Romanian)
    AILanguageCodeRU,   // 俄语 (Russian)
    AILanguageCodeSK,   // 斯洛伐克语 (Slovak)
    AILanguageCodeSL,   // 斯洛文尼亚语 (Slovenian)
    AILanguageCodeSV,   // 瑞典语 (Swedish)
    AILanguageCodeTH,   // 泰语 (Thai)
    AILanguageCodeTR,   // 土耳其语 (Turkish)
    AILanguageCodeUK,   // 乌克兰语 (Ukrainian)
    AILanguageCodeUZ,   // 乌兹别克语 (Uzbek)
    AILanguageCodeVI,   // 越南语 (Vietnamese)
    AILanguageCodeZH,   // 中文 (Chinese)
    AILanguageCodeCS,   // 捷克语 (Czech)
    AILanguageCodeKO    // 韩语 (Korean)
};

@interface AILanguageCodeUtil : NSObject

+ (NSString *)codeForLanguage:(AILanguageCode)language;
+ (NSString *)localeCodeForLanguage:(AILanguageCode)language;
+ (NSString *)nameForLanguage:(AILanguageCode)language;
+ (AILanguageCode)languageCodeForString:(NSString *)string;

/// 返回所有语言数组，每项包含 @{@"code": @(枚举值), @"name": 名称}
+ (NSArray<NSDictionary *> *)allLanguages;

/// 多模态支持的所有语言
+ (NSArray<NSDictionary *> *)multimodalLanguages;
@end

NS_ASSUME_NONNULL_END
