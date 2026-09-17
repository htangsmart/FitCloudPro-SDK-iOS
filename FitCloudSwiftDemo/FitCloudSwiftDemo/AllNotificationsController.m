//
//  AllNotificationsController.m
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2026/9/17.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import "AllNotificationsController.h"

#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

@interface AllNotificationsController ()

- (IBAction)OnGoBack:(id)sender;

@property(nonatomic, copy) NSArray<FitCloudNotificationApp> *allApps;
@property(nonatomic, copy, nullable) NSSet<FitCloudNotificationApp> *enabledApps;

@end

@implementation AllNotificationsController

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.rowHeight = 54;
    // Pull the full set of notification apps declared by the SDK.
    NSSet<FitCloudNotificationApp> *apps = FitCloudAllNotificationApps();
    // Sort by display name for a scannable list.
    self.allApps = [apps.allObjects sortedArrayUsingComparator:^NSComparisonResult(FitCloudNotificationApp a,
                                                                                   FitCloudNotificationApp b) {
        return [[self displayNameForApp:a] localizedCaseInsensitiveCompare:[self displayNameForApp:b]];
    }];
    [self reloadEnabledApps];
}

#pragma mark - Data

- (void)reloadEnabledApps {
    __weak typeof(self) weakSelf = self;
    [FitCloudKit getEnabledNotificationAppsWithCompletion:^(BOOL succeed,
                                                             NSSet<FitCloudNotificationApp> *apps,
                                                             NSError *error) {
        if (succeed) {
            XLOG_INFO(@"Enabled notification apps: %@.", apps);
        } else {
            XLOG_ERROR(@"Failed to get enabled notification apps: %@.", error);
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            if (succeed) {
                weakSelf.enabledApps = apps;
                [weakSelf.tableView reloadData];
            } else {
                OpResultToastTip(weakSelf.view, false);
            }
        });
    }];
}

/// Human-readable name for a notification app, aligned with the SDK header comments.
- (NSString *)displayNameForApp:(FitCloudNotificationApp)app {
    static NSDictionary *names = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        names = @{
            FitCloudNotificationAppCall: @"Call",
            FitCloudNotificationAppSMS: @"SMS",
            FitCloudNotificationAppQQ: @"QQ",
            FitCloudNotificationAppWeChat: @"WeChat",
            FitCloudNotificationAppFacebook: @"Facebook",
            FitCloudNotificationAppTwitter: @"Twitter",
            FitCloudNotificationAppLinkedIn: @"LinkedIn",
            FitCloudNotificationAppInstagram: @"Instagram",
            FitCloudNotificationAppPinterest: @"Pinterest",
            FitCloudNotificationAppWhatsApp: @"WhatsApp",
            FitCloudNotificationAppLINE: @"LINE",
            FitCloudNotificationAppMessenger: @"Messenger",
            FitCloudNotificationAppKakao: @"KakaoTalk",
            FitCloudNotificationAppSkype: @"Skype",
            FitCloudNotificationAppMail: @"Mail",
            FitCloudNotificationAppTelegram: @"Telegram",
            FitCloudNotificationAppViber: @"Viber",
            FitCloudNotificationAppCalendar: @"Calendar",
            FitCloudNotificationAppSnapchat: @"Snapchat",
            FitCloudNotificationAppHike: @"Hike",
            FitCloudNotificationAppYouTube: @"YouTube",
            FitCloudNotificationAppAppleMusic: @"Apple Music",
            FitCloudNotificationAppZoom: @"Zoom",
            FitCloudNotificationAppTikTok: @"TikTok",
            FitCloudNotificationAppGmail: @"Gmail",
            FitCloudNotificationAppOutlook: @"Outlook",
            FitCloudNotificationAppWhatsAppBusiness: @"WhatsApp Business",
            FitCloudNotificationAppFastrack: @"Fastrack",
            FitCloudNotificationAppTitanSmartWorld: @"Titan Smart World",
            FitCloudNotificationAppGoogleWallet: @"Google Wallet",
            FitCloudNotificationAppAmazon: @"Amazon",
            FitCloudNotificationAppOther: @"Other",
            FitCloudNotificationAppPhonePe: @"PhonePe",
            FitCloudNotificationAppHinge: @"Hinge",
            FitCloudNotificationAppFlipkart: @"Flipkart",
            FitCloudNotificationAppMyntra: @"Myntra",
            FitCloudNotificationAppMeesho: @"Meesho",
            FitCloudNotificationAppZivame: @"Zivame",
            FitCloudNotificationAppAjio: @"Ajio",
            FitCloudNotificationAppUrbanic: @"Urbanic",
            FitCloudNotificationAppNykaa: @"Nykaa",
            FitCloudNotificationAppHealthifyme: @"Healthifyme",
            FitCloudNotificationAppCultfit: @"Cultfit",
            FitCloudNotificationAppFlo: @"Flo",
            FitCloudNotificationAppBumble: @"Bumble",
            FitCloudNotificationAppUber: @"Uber",
            FitCloudNotificationAppSwiggy: @"Swiggy",
            FitCloudNotificationAppZomato: @"Zomato",
            FitCloudNotificationAppTira: @"Tira",
            FitCloudNotificationAppZalo: @"Zalo",
            FitCloudNotificationAppDingTalk: @"DingTalk",
            FitCloudNotificationAppFeishu: @"Feishu",
            FitCloudNotificationAppTeams: @"Microsoft Teams",
            FitCloudNotificationAppGooglePlay: @"Google Play",
            FitCloudNotificationAppGoogleDrive: @"Google Drive",
            FitCloudNotificationAppJioHotstar: @"JioHotstar",
            FitCloudNotificationAppPaytm: @"Paytm",
            FitCloudNotificationAppKismetos: @"KISMETOS",
            FitCloudNotificationAppVK: @"VK",
            FitCloudNotificationAppYandexGo: @"Yandex Go",
            FitCloudNotificationAppYandexMarket: @"Yandex Market",
            FitCloudNotificationAppSberbankOnline: @"Sberbank Online",
            FitCloudNotificationAppWildberries: @"Wildberries",
            FitCloudNotificationAppOzon: @"Ozon",
            FitCloudNotificationAppMax: @"MAX",
            FitCloudNotificationAppGosuslugi: @"Gosuslugi",
            FitCloudNotificationAppAvito: @"Avito",
            FitCloudNotificationAppGoldApple: @"Gold Apple",
            FitCloudNotificationAppYandexMaps: @"Yandex Maps",
        };
    });
    return names[app] ?: app;
}

- (void)toggleApp:(FitCloudNotificationApp)app on:(BOOL)on switchView:(UISwitch *)switchView {
    __weak typeof(self) weakSelf = self;
    [FitCloudKit getEnabledNotificationAppsWithCompletion:^(BOOL succeed,
                                                            NSSet<FitCloudNotificationApp> *enabled,
                                                            NSError *error) {
        if (!succeed) {
            XLOG_ERROR(@"Failed to get enabled notification apps before updating: %@.", error);
            dispatch_async(dispatch_get_main_queue(), ^{
                [switchView setOn:!on animated:YES];
                OpResultToastTip(weakSelf.view, false);
            });
            return;
        }

        NSMutableSet<FitCloudNotificationApp> *updated = enabled ? [enabled mutableCopy] : [NSMutableSet set];
        if (on) {
            if ([FitCloudKit isDeviceSupportNotificationApp:app]) {
                [updated addObject:app];
            } else {
                XLOG_WARNING(@"The device does not support notification app: %@.", app);
                dispatch_async(dispatch_get_main_queue(), ^{
                    [switchView setOn:NO animated:YES];
                    OpResultToastTip(weakSelf.view, false);
                });
                return;
            }
        } else {
            [updated removeObject:app];
        }

        [FitCloudKit setEnabledNotificationApps:updated completion:^(BOOL setSucceed, NSError *setError) {
            if (!setSucceed) {
                XLOG_ERROR(@"Failed to set enabled notification apps: %@.", setError);
            } else {
                XLOG_INFO(@"Enabled notification apps updated: %@.", updated);
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                if (setSucceed) {
                    weakSelf.enabledApps = updated;
                    OpResultToastTip(weakSelf.view, true);
                } else {
                    [switchView setOn:!on animated:YES];
                    OpResultToastTip(weakSelf.view, false);
                }
            });
        }];
    }];
}

#pragma mark - Actions

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)onSwitchChanged:(UISwitch *)switchView {
    NSInteger row = switchView.tag;
    if (row < 0 || row >= (NSInteger)self.allApps.count) {
        return;
    }
    FitCloudNotificationApp app = self.allApps[row];
    [self toggleApp:app on:switchView.on switchView:switchView];
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return (NSInteger)self.allApps.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"AppCell" forIndexPath:indexPath];
    FitCloudNotificationApp app = self.allApps[indexPath.row];
    cell.textLabel.text = [self displayNameForApp:app];
    cell.textLabel.font = [UIFont fontWithName:@"Menlo-Bold" size:14];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;

    BOOL supported = [FitCloudKit isDeviceSupportNotificationApp:app];
    BOOL enabled = self.enabledApps && [self.enabledApps containsObject:app];
    UISwitch *switchView = [UISwitch new];
    switchView.on = enabled;
    switchView.enabled = supported;
    switchView.tag = indexPath.row;
    [switchView addTarget:self action:@selector(onSwitchChanged:) forControlEvents:UIControlEventValueChanged];
    cell.accessoryView = switchView;
    return cell;
}

@end
