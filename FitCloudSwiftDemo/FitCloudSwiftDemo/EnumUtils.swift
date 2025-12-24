//
//  EnumUtils.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2025-12-24.
//

import Foundation

class EnumUtils {
    static func talismanNameOf(_ talisman: FitCloudTalismanType) -> String {
        switch talisman {
        case .none: return "无 (None)"
        case .longevity: return "长寿符 (Longevity)"
        case .travelSafety: return "出行平安 (Travel Safety)"
        case .noblePerson: return "贵人符 (Noble Person)"
        case .protection: return "护身符 (Protection)"
        case .purification: return "净化符 (Purification)"
        case .peace: return "平安符 (Peace)"
        case .antiVillain: return "破小人 (Anti-Villain)"
        case .promotion: return "升官符 (Promotion)"
        case .scholar: return "文昌符 (Scholar)"
        case .marriage: return "姻缘符 (Marriage)"
        case .wealth: return "招财符 (Wealth)"
        case .homeProtection: return "镇宅符 (Home Protection)"
        case .luckChange: return "转运符 (Luck Change)"
        @unknown default: return "未知 (Unknown)"
        }
    }
    
    static func yogaMusicNameOf(_ yogaMusic: FitCloudYogaAudioType) -> String {
        switch yogaMusic {
        case .none: return "无音频 (No audio)"
        case .aries: return "白羊座音频 (Aries audio)"
        case .taurus: return "金牛座音频 (Taurus audio)"
        case .gemini: return "双子座音频 (Gemini audio)"
        case .cancer: return "巨蟹座音频 (Cancer audio)"
        case .leo: return "狮子座音频 (Leo audio)"
        case .virgo: return "处女座音频 (Virgo audio)"
        case .libra: return "天秤座音频 (Libra audio)"
        case .scorpio: return "天蝎座音频 (Scorpio audio)"
        case .sagittarius: return "射手座音频 (Sagittarius audio)"
        case .capricorn: return "摩羯座音频 (Capricorn audio)"
        case .aquarius: return "水瓶座音频 (Aquarius audio)"
        case .pisces: return "双鱼座音频 (Pisces audio)"
        @unknown default: return "未知 (Unknown)"
        }
    }
}
