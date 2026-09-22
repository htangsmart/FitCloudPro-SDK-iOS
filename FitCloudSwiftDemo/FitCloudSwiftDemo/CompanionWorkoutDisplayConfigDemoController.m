//
//  CompanionWorkoutDisplayConfigDemoController.m
//  FitCloudSwiftDemo
//

#import "CompanionWorkoutDisplayConfigDemoController.h"

// Keep the demo buildable with an older installed Pod; the runtime check below
// prevents calling the API until the matching FitCloudKit binary is installed.
@interface FitCloudKit (CompanionWorkoutDisplayConfigDemo)
+ (void)queryCompanionWorkoutDisplayConfigForWorkoutType:(FitCloudWorkoutType)workoutType
                                               completion:(void (^_Nullable)(BOOL success,
                                                                             NSArray<NSNumber *> *_Nullable displayItems,
                                                                             NSError *_Nullable error))completion;
@end

static NSString *CompanionWorkoutDisplayItemText(NSInteger value)
{
    switch (value) {
        case WORKOUTDATAITEMDISPLAY_DURATION: return @"运动时长（Duration）";
        case WORKOUTDATAITEMDISPLAY_AVG_BPM: return @"平均心率（Average Heart Rate）";
        case WORKOUTDATAITEMDISPLAY_TOTAL_STEPS: return @"累计步数（Total Steps）";
        case WORKOUTDATAITEMDISPLAY_DISTANCE: return @"运动距离（Distance）";
        case WORKOUTDATAITEMDISPLAY_CALORIES: return @"消耗热量（Calories）";
        case WORKOUTDATAITEMDISPLAY_AVG_SPEED: return @"平均速度（Average Speed）";
        case WORKOUTDATAITEMDISPLAY_AVG_PACE: return @"平均配速（Average Pace）";
        case WORKOUTDATAITEMDISPLAY_AVG_STEP_CADENCE: return @"平均步频（Average Cadence）";
        case WORKOUTDATAITEMDISPLAY_AVG_STEP_STRIDE: return @"平均步幅（Average Stride）";
        case WORKOUTDATAITEMDISPLAY_TOTAL_CLIMBING: return @"累计爬升（Total Ascent）";
        case WORKOUTDATAITEMDISPLAY_TOTAL_DESCENT: return @"累计下降（Total Descent）";
        case WORKOUTDATAITEMDISPLAY_SWIM_LAPS: return @"游泳趟数（Swim Laps）";
        case WORKOUTDATAITEMDISPLAY_SWIM_STROKES: return @"游泳划水次数（Swim Strokes）";
        case WORKOUTDATAITEMDISPLAY_SWIM_STYLE: return @"泳姿（Swim Style）";
        case WORKOUTDATAITEMDISPLAY_SWIM_STROKEFREQ: return @"游泳划水频率（Swim Stroke Frequency）";
        case WORKOUTDATAITEMDISPLAY_SWIM_SWOLF: return @"游泳效率（SWOLF）";
        case WORKOUTDATAITEMDISPLAY_TRIGGER_COUNT: return @"触发次数（Trigger Count）";
        case WORKOUTDATAITEMDISPLAY_TRIGGERS_PER_MINUTE: return @"触发频率（Triggers per Minute）";
        case WORKOUTDATAITEMDISPLAY_BREAK_COUNT: return @"中断次数（Break Count）";
        case WORKOUTDATAITEMDISPLAY_CONSECUTIVE_COUNT: return @"连续次数（Consecutive Count）";
        case 21: return @"平均心率（Average Heart Rate）";
        case 22: return @"最大心率（Maximum Heart Rate）";
        case 23: return @"最小心率（Minimum Heart Rate）";
        case 24: return @"最大速度（Maximum Speed）";
        case 25: return @"最小速度（Minimum Speed）";
        case 26: return @"最快配速（Fastest Pace）";
        case 27: return @"最慢配速（Slowest Pace）";
        case 28: return @"最大步频（Maximum Cadence）";
        case 29: return @"最小步频（Minimum Cadence）";
        case 30: return @"心率五段区间（Heart Rate Zones）";
        case 31: return @"GPS 轨迹（GPS Track）";
        case 32: return @"实时速度（Real-time Speed）";
        case 33: return @"实时心率（Real-time Heart Rate）";
        default: return [NSString stringWithFormat:@"未知项（Unknown Item）[%ld]", (long)value];
    }
}

static NSArray<NSDictionary<NSString *, id> *> *CompanionWorkoutTypes(void)
{
    static NSArray<NSDictionary<NSString *, id> *> *workoutTypes;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSArray<NSString *> *names = @[
        @"户外骑行（Outdoor Cycle）",
        @"户外跑步（Outdoor Run）",
        @"室内跑步（Indoor Run）",
        @"户外健走（Outdoor Walk）",
        @"登山（Mountaineering）",
        @"篮球（Basketball）",
        @"游泳（swim）",
        @"羽毛球（Badminton）",
        @"足球（Football）",
        @"椭圆机（Elliptical trainer）",
        @"瑜伽（Yoga）",
        @"乒乓球（Table Tennis）",
        @"跳绳（Jump Rope）",
        @"划船器（Rowing Maching）",
        @"懒人车（lazy car）",
        @"健身车（exercise bike）",
        @"自由训练（Free Training）",
        @"网球（Tennis）",
        @"棒球（Baseball）",
        @"橄榄球（Rugby）",
        @"板球（Cricket）",
        @"自由运动（free sport）",
        @"力量训练（Strength Training）",
        @"室内健走（Indoor Walk）",
        @"室内骑行（Indoor Cycle）",
        @"哑铃（dumbbel）",
        @"舞蹈（Dance）",
        @"呼啦圈（Hula Hoop）",
        @"高尔夫（Golf）",
        @"跳远（Longjump）",
        @"仰卧起坐（Sit up）",
        @"排球（Volleyball）",
        @"跑酷（Parkour）",
        @"徒步（Hiking）",
        @"曲棍球（Hockey）",
        @"划船（Boating）",
        @"HIIT（HIIT）",
        @"垒球（Softball）",
        @"越野跑（Trail Running）",
        @"滑雪（Skiing）",
        @"漫步机（Air Walker）",
        @"整理放松（Cooldown）",
        @"交叉训练（Cross Training）",
        @"普拉提（Pilates）",
        @"交叉配合（Cross Fit）",
        @"功能性训练（Functional Training）",
        @"体能训练（Physical Training）",
        @"混合有氧（Mixed Cardio）",
        @"拉丁舞（Latin Dance）",
        @"街舞（Street Dance）",
        @"自由搏击（Kickboxing）",
        @"芭蕾（Barre）",
        @"澳式足球（Australian Football）",
        @"保龄球（Bowling）",
        @"壁球（Racquetball）",
        @"冰壶（Curling）",
        @"单板滑雪（Snowboarding）",
        @"钓鱼（Fishing）",
        @"飞盘运动（Disc Sports）",
        @"高山滑雪（Downhill Skiing）",
        @"核心训练（Core Training）",
        @"滑冰（Skating）",
        @"健身游戏（Fitness Gaming）",
        @"健身操（Aerobics）",
        @"团体操（Group Training）",
        @"搏击操（Kendo）",
        @"击剑（Fencing）",
        @"爬楼梯（Stairs）",
        @"美式橄榄球（American Football）",
        @"泡沫轴筋膜放松（Rolling）",
        @"匹克球（Pickleball）",
        @"拳击（Boxing）",
        @"跆拳道（Taekwondo）",
        @"空手道（Karate）",
        @"柔韧度（Flexibility）",
        @"手球（Handball）",
        @"手摇车（Hand Cycling）",
        @"舒缓冥想类运动（Mind & Body）",
        @"摔跤（Wrestling）",
        @"踏步训练（Step Training）",
        @"太极（Tai Chi）",
        @"体操（Gymnastics）",
        @"田径（Athletics）",
        @"武术（Martial Arts）",
        @"休闲运动（Play）",
        @"雪上运动（Snow Sports）",
        @"长曲棍球（Lacrosse）",
        @"单杠（Single Bar）",
        @"双杠（Parallel Bars）",
        @"轮滑（Roller Skating）",
        @"飞镖（Darts）",
        @"射箭（Archery）",
        @"骑马（Horse Riding）",
        @"毽球（Shuttlecock）",
        @"冰球（Ice Hockey）",
        @"腰腹训练（Waist training）",
        @"最大摄氧量测试（VO2max Test）",
        @"柔道（Judo）",
        @"蹦床（Trampoline）",
        @"滑板（Skateboarding）",
        @"平衡车（Hoverboard）",
        @"溜旱冰（Blading）",
        @"室内跑步（Treadmill）",
        @"跳水（Diving）",
        @"冲浪（Surfing）",
        @"浮潜（Snorkeling）",
        @"引体向上（Pull-up）",
        @"俯卧撑（Push-up）",
        @"平板支撑（Planking）",
        @"攀岩（Rock Climbing）",
        @"跳高（Hightjump）",
        @"蹦极（Bungee Jumping）",
        @"民族舞（Folk Dance）",
        @"打猎（Hunting）",
        @"射击（Shooting）",
        @"马拉松（Marathon）",
        @"动感单车（Spinning）",
        @"泳池游泳（Swimming in pool）",
        @"开放水域游泳（Open-water swim）",
        @"交际舞（BallroomDance）",
        @"尊巴（Zumba）",
        @"爵士舞（Jazz）",
        @"踏步机（Stepper）",
        @"爬楼机（ClimbingMachine）",
        @"门球（Croquet）",
        @"水球（WaterPolo）",
        @"墙球（WallBall）",
        @"台球（Billiards）",
        @"藤球（Sepaktakraw）",
        @"拉伸（Stretching）",
        @"自由体操（FloorExercise）",
        @"杠铃（Barbell）",
        @"举重（WeightLifting）",
        @"硬拉（HardDrawn）",
        @"波比跳（BobbyJump）",
        @"开合跳（JumpingJack）",
        @"上肢训练（upper_limb_training）",
        @"下肢训练（lower_limb_training）",
        @"背部训练（BackTraining）",
        @"沙滩车（ATV）",
        @"滑翔伞（Paraglider）",
        @"放风筝（Flying kites）",
        @"拔河（TugOfWar）",
        @"铁人三项（Triathlon）",
        @"雪地摩托（Snowmobile）",
        @"雪车（Bobsleigh）",
        @"雪橇（Sled）",
        @"滑雪板（Ski Board）",
        @"越野滑雪（Cross Country Skiing）",
        @"室内滑冰（Indoor Skating）",
        @"卡巴迪（Kabaddi）",
        @"泰拳（Muay Thai）",
        @"踢拳（Kickboxing）",
        @"赛车（Racing Car）",
        @"室内健身（Indoor Fitness）",
        @"户外足球（Outdoor Football）",
        @"肚皮舞（BellyDance）",
        @"广场舞（SquareDance）",
        @"肱二头肌训练（Biceps）",
        @"肱三头肌训练（Triceps）",
        @"胸部训练（Chest Training）",
        @"肩部训练（Shoulder Training）",
        @"腿部训练（Leg Training）",
        @"深蹲（Squat）",
        @"高抬腿（High Knees）",
        @"弓步（Lunge）",
        @"躲避球（Dodgeball）",
        @"沙滩排球（Beach Volleyball）",
        @"相扑（Sumo）",
        @"帆船（Sailing）",
        @"皮划艇（Kayaking）",
        @"划艇（Rowing Boat）",
        ];
        NSMutableArray<NSDictionary<NSString *, id> *> *items = [NSMutableArray arrayWithCapacity:names.count];
        NSString *language = NSBundle.mainBundle.preferredLocalizations.firstObject ?: NSLocale.preferredLanguages.firstObject;
        BOOL usesChinese = [language hasPrefix:@"zh"];
        [names enumerateObjectsUsingBlock:^(NSString *resultName, NSUInteger index, BOOL *stop) {
            NSRange separator = [resultName rangeOfString:@"（" options:NSBackwardsSearch];
            NSString *chineseName = [resultName substringToIndex:separator.location];
            NSString *englishName = [resultName substringWithRange:NSMakeRange(NSMaxRange(separator), resultName.length - NSMaxRange(separator) - 1)];
            [items addObject:@{
                @"name": usesChinese ? chineseName : englishName,
                @"resultName": resultName,
                @"value": @((NSInteger)index),
            }];
        }];
        workoutTypes = [items copy];
    });
    return workoutTypes;
}

typedef void (^CompanionWorkoutTypeSelectionHandler)(NSDictionary<NSString *, id> *workoutType);

@interface CompanionWorkoutTypeSelectionController : UITableViewController <UISearchResultsUpdating>

@property(nonatomic, copy) CompanionWorkoutTypeSelectionHandler selectionHandler;
@property(nonatomic, copy) NSArray<NSDictionary<NSString *, id> *> *visibleWorkoutTypes;
@property(nonatomic, assign) FitCloudWorkoutType selectedWorkoutType;

@end


@implementation CompanionWorkoutTypeSelectionController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.systemGroupedBackgroundColor;
    self.visibleWorkoutTypes = CompanionWorkoutTypes();
    self.title = NSLocalizedString(@"Select Workout Type", nil);

    UISearchController *searchController = [[UISearchController alloc] initWithSearchResultsController:nil];
    searchController.searchResultsUpdater = self;
    searchController.obscuresBackgroundDuringPresentation = NO;
    searchController.searchBar.placeholder = NSLocalizedString(@"Search workouts", nil);
    self.navigationItem.searchController = searchController;
    self.navigationItem.hidesSearchBarWhenScrolling = NO;
    self.definesPresentationContext = YES;

    self.tableView.keyboardDismissMode = UIScrollViewKeyboardDismissModeOnDrag;
    self.tableView.rowHeight = 62;
    [self.tableView registerClass:UITableViewCell.class forCellReuseIdentifier:@"WorkoutTypeCell"];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self.navigationController setNavigationBarHidden:NO animated:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [self.navigationController setNavigationBarHidden:YES animated:animated];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.visibleWorkoutTypes.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"WorkoutTypeCell" forIndexPath:indexPath];
    NSDictionary<NSString *, id> *item = self.visibleWorkoutTypes[indexPath.row];
    NSInteger rawValue = [item[@"value"] integerValue];
    UIListContentConfiguration *content = [UIListContentConfiguration subtitleCellConfiguration];
    content.text = item[@"name"];
    content.secondaryText = [NSString stringWithFormat:NSLocalizedString(@"Raw Value: %ld / 0x%02lX", nil), (long)rawValue, (long)rawValue];
    content.secondaryTextProperties.color = UIColor.secondaryLabelColor;
    cell.contentConfiguration = content;
    cell.accessoryType = rawValue == self.selectedWorkoutType ? UITableViewCellAccessoryCheckmark : UITableViewCellAccessoryNone;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSDictionary<NSString *, id> *item = self.visibleWorkoutTypes[indexPath.row];
    if (self.selectionHandler) {
        self.selectionHandler(item);
    }
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)updateSearchResultsForSearchController:(UISearchController *)searchController
{
    NSString *query = [searchController.searchBar.text stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet];
    if (query.length == 0) {
        self.visibleWorkoutTypes = CompanionWorkoutTypes();
    } else {
        NSPredicate *predicate = [NSPredicate predicateWithBlock:^BOOL(NSDictionary<NSString *, id> *item, NSDictionary *bindings) {
            return [item[@"resultName"] rangeOfString:query options:NSCaseInsensitiveSearch].location != NSNotFound ||
                   [[item[@"value"] stringValue] containsString:query];
        }];
        self.visibleWorkoutTypes = [CompanionWorkoutTypes() filteredArrayUsingPredicate:predicate];
    }
    [self.tableView reloadData];
}

@end

@interface CompanionWorkoutDisplayConfigDemoController ()
@property(nonatomic, strong) UIButton *workoutTypeButton;
@property(nonatomic, strong) UIButton *queryButton;
@property(nonatomic, strong) UIActivityIndicatorView *activityIndicator;
@property(nonatomic, strong) UITextView *resultView;
@property(nonatomic, assign) FitCloudWorkoutType selectedWorkoutType;
@property(nonatomic, copy) NSString *selectedWorkoutName;
@property(nonatomic, copy) NSString *selectedWorkoutResultName;
@end

@implementation CompanionWorkoutDisplayConfigDemoController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.systemGroupedBackgroundColor;

    UIButton *backButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [backButton setImage:[UIImage systemImageNamed:@"chevron.left"] forState:UIControlStateNormal];
    [backButton setTitle:NSLocalizedString(@"Back", nil) forState:UIControlStateNormal];
    backButton.titleLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
    [backButton addTarget:self action:@selector(goBack) forControlEvents:UIControlEventTouchUpInside];
    [backButton setContentHuggingPriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];

    UILabel *titleLabel = [[UILabel alloc] init];
    titleLabel.numberOfLines = 0;
    titleLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleTitle2];
    titleLabel.text = NSLocalizedString(@"Companion Workout Display Config", nil);

    UIStackView *header = [[UIStackView alloc] initWithArrangedSubviews:@[backButton, titleLabel]];
    header.axis = UILayoutConstraintAxisHorizontal;
    header.alignment = UIStackViewAlignmentCenter;
    header.spacing = 12;

    UILabel *tipLabel = [[UILabel alloc] init];
    tipLabel.numberOfLines = 0;
    tipLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline];
    tipLabel.textColor = UIColor.secondaryLabelColor;
    tipLabel.text = NSLocalizedString(@"Select a companion workout type, then query its display-item configuration.", nil);

    self.selectedWorkoutType = FitCloudWorkoutTypeOutdoorRun;
    NSDictionary<NSString *, id> *defaultWorkout = CompanionWorkoutTypes()[FitCloudWorkoutTypeOutdoorRun];
    self.selectedWorkoutName = defaultWorkout[@"name"];
    self.selectedWorkoutResultName = defaultWorkout[@"resultName"];
    self.workoutTypeButton = [UIButton buttonWithType:UIButtonTypeSystem];
    UIButtonConfiguration *selectionConfiguration = [UIButtonConfiguration grayButtonConfiguration];
    selectionConfiguration.contentInsets = NSDirectionalEdgeInsetsMake(10, 12, 10, 12);
    selectionConfiguration.titleAlignment = UIButtonConfigurationTitleAlignmentLeading;
    self.workoutTypeButton.configuration = selectionConfiguration;
    self.workoutTypeButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    self.workoutTypeButton.titleLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
    self.workoutTypeButton.titleLabel.numberOfLines = 2;
    [self.workoutTypeButton addTarget:self action:@selector(selectWorkoutType) forControlEvents:UIControlEventTouchUpInside];
    [self updateWorkoutTypeButton];

    self.queryButton = [UIButton buttonWithType:UIButtonTypeSystem];
    UIButtonConfiguration *queryConfiguration = [UIButtonConfiguration filledButtonConfiguration];
    queryConfiguration.title = NSLocalizedString(@"Query Display Items", nil);
    queryConfiguration.baseBackgroundColor = UIColor.labelColor;
    queryConfiguration.baseForegroundColor = UIColor.systemBackgroundColor;
    queryConfiguration.cornerStyle = UIButtonConfigurationCornerStyleMedium;
    self.queryButton.configuration = queryConfiguration;
    self.queryButton.titleLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleHeadline];
    [self.queryButton addTarget:self action:@selector(queryDisplayConfig) forControlEvents:UIControlEventTouchUpInside];

    self.activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
    self.activityIndicator.hidesWhenStopped = YES;

    UIStackView *queryRow = [[UIStackView alloc] initWithArrangedSubviews:@[self.queryButton, self.activityIndicator]];
    queryRow.axis = UILayoutConstraintAxisHorizontal;
    queryRow.alignment = UIStackViewAlignmentCenter;
    queryRow.spacing = 12;
    [self.activityIndicator setContentHuggingPriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];

    UILabel *resultTitle = [[UILabel alloc] init];
    resultTitle.font = [UIFont preferredFontForTextStyle:UIFontTextStyleHeadline];
    resultTitle.text = NSLocalizedString(@"Query Result", nil);

    self.resultView = [[UITextView alloc] init];
    self.resultView.editable = NO;
    self.resultView.selectable = YES;
    self.resultView.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
    self.resultView.backgroundColor = UIColor.secondarySystemGroupedBackgroundColor;
    self.resultView.layer.cornerRadius = 10.0;
    self.resultView.textContainerInset = UIEdgeInsetsMake(14, 12, 14, 12);
    self.resultView.text = NSLocalizedString(@"Select a workout type and query.", nil);

    UIStackView *content = [[UIStackView alloc] initWithArrangedSubviews:@[header, tipLabel, self.workoutTypeButton, queryRow, resultTitle, self.resultView]];
    content.axis = UILayoutConstraintAxisVertical;
    content.spacing = 16;
    content.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:content];

    [NSLayoutConstraint activateConstraints:@[
        [content.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor constant:12],
        [content.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [content.leadingAnchor constraintGreaterThanOrEqualToAnchor:self.view.safeAreaLayoutGuide.leadingAnchor constant:20],
        [content.trailingAnchor constraintLessThanOrEqualToAnchor:self.view.safeAreaLayoutGuide.trailingAnchor constant:-20],
        [content.widthAnchor constraintLessThanOrEqualToConstant:640],
        [content.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor constant:-20],
        [self.workoutTypeButton.heightAnchor constraintGreaterThanOrEqualToConstant:56],
        [self.queryButton.heightAnchor constraintEqualToConstant:44],
    ]];
    NSLayoutConstraint *preferredWidth = [content.widthAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.widthAnchor constant:-40];
    preferredWidth.priority = UILayoutPriorityDefaultHigh;
    preferredWidth.active = YES;
}

- (void)goBack
{
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)updateWorkoutTypeButton
{
    NSString *title = [NSString stringWithFormat:@"%@\n%@  ›",
                       self.selectedWorkoutName,
                       [NSString stringWithFormat:NSLocalizedString(@"Raw Value: %ld / 0x%02lX", nil),
                                                  (long)self.selectedWorkoutType,
                                                  (long)self.selectedWorkoutType]];
    UIButtonConfiguration *configuration = self.workoutTypeButton.configuration;
    configuration.title = title;
    self.workoutTypeButton.configuration = configuration;
    self.workoutTypeButton.accessibilityLabel = [NSString stringWithFormat:NSLocalizedString(@"Select Workout Type, current: %@", nil), self.selectedWorkoutName];
}

- (void)selectWorkoutType
{
    CompanionWorkoutTypeSelectionController *controller = [[CompanionWorkoutTypeSelectionController alloc] initWithStyle:UITableViewStyleInsetGrouped];
    controller.selectedWorkoutType = self.selectedWorkoutType;
    __weak typeof(self) weakSelf = self;
    controller.selectionHandler = ^(NSDictionary<NSString *, id> *item) {
        __strong typeof(weakSelf) self = weakSelf;
        self.selectedWorkoutType = (FitCloudWorkoutType)[item[@"value"] integerValue];
        self.selectedWorkoutName = item[@"name"];
        self.selectedWorkoutResultName = item[@"resultName"];
        [self updateWorkoutTypeButton];
        self.resultView.text = NSLocalizedString(@"Workout type changed. Query again.", nil);
    };
    [self.navigationController pushViewController:controller animated:YES];
}

- (void)queryDisplayConfig
{
    FitCloudWorkoutType workoutType = self.selectedWorkoutType;
    NSString *workoutName = self.selectedWorkoutResultName;
    SEL querySelector = @selector(queryCompanionWorkoutDisplayConfigForWorkoutType:completion:);
    if (![FitCloudKit respondsToSelector:querySelector]) {
        self.resultView.text = NSLocalizedString(@"The current FitCloudKit version does not support this API.", nil);
        return;
    }
    self.queryButton.enabled = NO;
    [self.activityIndicator startAnimating];
    self.resultView.text = NSLocalizedString(@"Querying…", nil);

    __weak typeof(self) weakSelf = self;
    [FitCloudKit queryCompanionWorkoutDisplayConfigForWorkoutType:workoutType
                                                       completion:^(BOOL success, NSArray<NSNumber *> *displayItems, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            __strong typeof(weakSelf) self = weakSelf;
            if (!self) return;
            self.queryButton.enabled = YES;
            [self.activityIndicator stopAnimating];

            if (!success) {
                self.resultView.text = [NSString stringWithFormat:@"%@\n%@",
                                        NSLocalizedString(@"Query Failed", nil),
                                        error.localizedDescription ?: NSLocalizedString(@"Unknown Error", nil)];
                return;
            }
            if (displayItems.count == 0) {
                self.resultView.text = NSLocalizedString(@"No display items returned by the device.", nil);
                return;
            }

            NSMutableArray<NSString *> *lines = [NSMutableArray arrayWithCapacity:displayItems.count + 1];
            [lines addObject:[NSString stringWithFormat:@"运动类型（Workout Type）: %@ [%ld / 0x%02lX]",
                              workoutName, (long)workoutType, (long)workoutType]];
            [displayItems enumerateObjectsUsingBlock:^(NSNumber *item, NSUInteger index, BOOL *stop) {
                [lines addObject:[NSString stringWithFormat:@"%lu. %@", (unsigned long)(index + 1), CompanionWorkoutDisplayItemText(item.integerValue)]];
            }];
            self.resultView.text = [lines componentsJoinedByString:@"\n"];
        });
    }];
}

@end
