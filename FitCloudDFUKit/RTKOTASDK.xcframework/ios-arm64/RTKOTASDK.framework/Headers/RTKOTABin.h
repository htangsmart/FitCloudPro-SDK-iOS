//
//  RTKOTABin.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/4/16.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Constants that indicates the type of an image.
///
/// `RTKOTAImageType` constants are defined to support different SOC platforms. The case value is reused for different SOC platform. So when be used to compare, the SOC platform is required.
typedef NS_ENUM(NSUInteger, RTKOTAImageType) {
    RTKOTAImageType_Unknown = 0,
    
    /* Bee */
    RTKOTAImageType_Bee_Patch   = 0x01,     ///< Patch
    RTKOTAImageType_Bee_AppBank0,           ///< App in bank 0
    RTKOTAImageType_Bee_AppBank1,           ///< App in bank 1
    RTKOTAImageType_Bee_Data,               ///< Data
    RTKOTAImageType_Bee_PatchExt,           ///< Patch extension
    RTKOTAImageType_Bee_Config,             ///< Configuration
    
    /* Bee 2 */
//    RTKOTAImageType_Bee2_SOCV_CFG   = 0x01,     ///< SOCV Configuration
//    RTKOTAImageType_Bee2_SystemConfig,          ///< System Configuration
//    RTKOTAImageType_Bee2_OTAHeader,             ///< OTA Header
//    RTKOTAImageType_Bee2_Secure_Boot_Loader,    ///< Secure Boot Loader
//    RTKOTAImageType_Bee2_ROM_PATCH,             ///< ROM Patch
//    RTKOTAImageType_Bee2_APP_IMG,               ///< App
//    RTKOTAImageType_Bee2_APP_DATA1,             ///< App Data 1
//    RTKOTAImageType_Bee2_APP_DATA2,             ///< App Data 2
//    RTKOTAImageType_Bee2_APP_DATA3,             ///< App Data 3
//    RTKOTAImageType_Bee2_APP_DATA4,             ///< App Data 4
//    RTKOTAImageType_Bee2_APP_DATA5,             ///< App Data 5
//    RTKOTAImageType_Bee2_APP_DATA6,             ///< App Data 6
//    RTKOTAImageType_Bee2_APP_DATA7,             ///< App Data 7
//    RTKOTAImageType_Bee2_APP_DATA8,             ///< App Data 8
//    RTKOTAImageType_Bee2_APP_DATA9,             ///< App Data 9
//    RTKOTAImageType_Bee2_APP_DATA10,            ///< App Data 10
    
    /* Bee2 SBee 2 (Bee3) Bee3Plus*/
    RTKOTAImageType_SBee2_SOCV_CFG  = 0x01,     ///< SOCV Configuration
    RTKOTAImageType_SBee2_SystemConfig,         ///< System Configuration
    RTKOTAImageType_SBee2_OTAHeader,            ///< OTA Header
    RTKOTAImageType_SBee2_Secure_Boot_Loader,   ///< Secure Boot Loader
    RTKOTAImageType_SBee2_ROM_PATCH,            ///< ROM Patch
    RTKOTAImageType_SBee2_APP_IMG,              ///< App
    RTKOTAImageType_SBee2_APP_DATA1,            ///< App Data 1
    RTKOTAImageType_SBee2_APP_DATA2,            ///< App Data 2
    RTKOTAImageType_SBee2_APP_DATA3,            ///< App Data 3
    RTKOTAImageType_SBee2_APP_DATA4,            ///< App Data 4
    RTKOTAImageType_SBee2_APP_DATA5,            ///< App Data 5
    RTKOTAImageType_SBee2_APP_DATA6,            ///< App Data 6
    RTKOTAImageType_SBee2_UPPERSTACK,           ///< Upper Stack
    RTKOTAImageType_SBee2_StackPatch,           ///< StackPatch (Bee3Plus)
    RTKOTAImageType_SBee2_User_Data1,           ///< User Data 1
    RTKOTAImageType_SBee2_User_Data2,           ///< User Data 2
    
    /* BBpro (including BBLite, BBpro 2) */
    RTKOTAImageType_BBpro_SOCV_CFG                  = 1,      ///< SOCV Configuration
    RTKOTAImageType_BBpro_SystemConfig              = 2,      ///< System Configuration
    RTKOTAImageType_BBpro_OTAHeader                 = 3,      ///< OTA Header
    RTKOTAImageType_BBpro_Secure_Boot_Loader        = 4,      ///< Secure Boot Loader
    RTKOTAImageType_BBpro_ROM_PATCH                 = 5,      ///< ROM Patch
    RTKOTAImageType_BBpro_APP_IMG                   = 6,      ///< App
    RTKOTAImageType_BBpro_DSP_System                = 7,      ///< DSP System
    RTKOTAImageType_BBpro_DSP_APP                   = 8,      ///< DSP App
    RTKOTAImageType_BBpro_DSP_UI_PARAMETER          = 9,      ///< DSP UI Parameter (DSP Configure)
    RTKOTAImageType_BBpro_APP_UI_PARAMETER          = 10,     ///< App UI Parameter (APP Configure)
    RTKOTAImageType_BBpro_EXT_IMAGE0                = 11,     ///< Extension Image 0 (ANC)
    RTKOTAImageType_BBpro_EXT_IMAGE1                = 12,     ///< Extension Image 1
    RTKOTAImageType_BBpro_EXT_IMAGE2                = 13,     ///< Extension Image 2 (Sensor)
    RTKOTAImageType_BBpro_EXT_IMAGE3                = 14,     ///< Extension Image 3
    RTKOTAImageType_BBpro_FACTORY_IMAGE             = 15,     ///< Factory Image
    RTKOTAImageType_BBpro_BootPatch                 = 15,     ///< Boot Patch Image
    RTKOTAImageType_BBpro_BACKUP_DATA               = 16,     ///< Backup Data
    RTKOTAImageType_BBpro_BACKUP_DATA2              = 17,     ///< Backup Data 2
    RTKOTAImageType_BBpro_Platform_Img              = 18,     ///< Platform Image
    RTKOTAImageType_BBpro_Lower_Stack_Img           = 19,     ///< Lower Stack
    RTKOTAImageType_BBpro_Upper_Stack_Img           = 20,     ///< Upper Stack
    RTKOTAImageType_BBpro_Framework_Img             = 21,     ///< Framework Image
    RTKOTAImageType_BBpro_PreSys_Patch_Img          = 22,     ///< Pre_platform Image
    RTKOTAImageType_BBpro_PreStack_Patch_Img        = 23,
    RTKOTAImageType_BBpro_PreUpper_Stack_Img        = 24,     ///< Pre_upperstack Image
    RTKOTAImageType_BBpro_Voice_Prompt_Data_Img     = 25,     ///< Voice Prompt Data
    RTKOTAImageType_BBpro_UserData1                 = 26,     ///< User Data
    RTKOTAImageType_BBpro_UserData2                 = 27,
    RTKOTAImageType_BBpro_UserData3                 = 28,
    RTKOTAImageType_BBpro_UserData4                 = 29,
    RTKOTAImageType_BBpro_UserData5                 = 30,
    RTKOTAImageType_BBpro_UserData6                 = 31,
    RTKOTAImageType_BBpro_UserData7                 = 32,
    RTKOTAImageType_BBpro_UserData8                 = 33,
    
    /*Bee3Pro*/
    RTKOTAImageType_Bee3Pro_OTAHeader               = 1,
    RTKOTAImageType_Bee3Pro_SecurePatch             = 2,
    RTKOTAImageType_Bee3Pro_SecureAPP               = 3,
    RTKOTAImageType_Bee3Pro_SecureAPPData           = 4,
    RTKOTAImageType_Bee3Pro_PMCPatch                = 5,
    RTKOTAImageType_Bee3Pro_BTSystemPatch           = 6,
    RTKOTAImageType_Bee3Pro_BTLowerStackPatch       = 7,
    RTKOTAImageType_Bee3Pro_NonSecurePatch          = 8,
    RTKOTAImageType_Bee3Pro_UpperStack              = 9,
    RTKOTAImageType_Bee3Pro_APP                     = 10,
    RTKOTAImageType_Bee3Pro_APPConfigData           = 11,
    RTKOTAImageType_Bee3Pro_DSPPatch                = 12,
    RTKOTAImageType_Bee3Pro_DSPAPP                  = 13,
    RTKOTAImageType_Bee3Pro_DSPData                 = 14,
    RTKOTAImageType_Bee3Pro_APPData1                = 15,
    RTKOTAImageType_Bee3Pro_APPData2                = 16,
    RTKOTAImageType_Bee3Pro_APPData3                = 17,
    RTKOTAImageType_Bee3Pro_APPData4                = 18,
    RTKOTAImageType_Bee3Pro_APPData5                = 19,
    RTKOTAImageType_Bee3Pro_APPData6                = 20,
    RTKOTAImageType_Bee4_BootPatch                  = 21,
    
};


NS_ASSUME_NONNULL_BEGIN


/// An abstract class that represents an image binary.
///
/// The `RTKOTABin` class is an abstract base class that defines common behavior for objects representing image binary, regardless of whther it is installed at peripheral. There are ``RTKOTAInstalledBin`` subclass which represent an image reside in a real device and ``RTKOTAUpgradeBin`` subclass which represent an image to upgrade.
///
/// You typically don’t create instances of either `RTKOTABin` or its concrete subclasses. Instead, the SDK creates them for you when peripheral information settle or extracted from archive file.
@interface RTKOTABin : NSObject

/// The image type this binary is.
@property (readonly) RTKOTAImageType type;

/// Return a integer version number of the binary object.
@property (readonly) uint32_t version;


/// The name of the binary object.
@property (readonly) NSString *name;

/// Return a human-readable version string.
@property (readonly) NSString *versionString;


/// Compare version and return result of this binary object and a passed binary object.
///
/// The method used to compare may be different for different image type.
- (NSComparisonResult)compareVersionWith:(RTKOTABin *)anotherBin;

@end


NS_ASSUME_NONNULL_END
