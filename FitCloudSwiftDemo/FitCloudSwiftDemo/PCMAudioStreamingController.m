//
//  PCMAudioStreamingController.m
//  FitCloudSwiftDemo
//

#import "PCMAudioStreamingController.h"

static const NSUInteger PCMAudioSampleRate = 16000;
static const NSUInteger PCMAudioChannels = 1;

@interface PCMAudioStreamingController ()

@property (nonatomic, strong) UIButton *send16KButton;
@property (nonatomic, strong) UIButton *send32KButton;
@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) UILabel *statusLabel;
@property (nonatomic, assign, getter=isSending) BOOL sending;

@end


@implementation PCMAudioStreamingController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = NSLocalizedString(@"PCM Audio Streaming", nil);
    self.view.backgroundColor = UIColor.systemGroupedBackgroundColor;
    [self setupViews];
    [self updateSendingState:NO];
}

- (void)setupViews
{
    UIButton *backButton = [UIButton buttonWithType:UIButtonTypeSystem];
    backButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [backButton setImage:[UIImage systemImageNamed:@"chevron.left"] forState:UIControlStateNormal];
    [backButton setTitle:NSLocalizedString(@"Back", nil) forState:UIControlStateNormal];
    backButton.titleLabel.font = [UIFont systemFontOfSize:16 weight:UIFontWeightSemibold];
    [backButton addTarget:self action:@selector(goBack) forControlEvents:UIControlEventTouchUpInside];

    UILabel *titleLabel = [[UILabel alloc] init];
    titleLabel.text = NSLocalizedString(@"PCM Audio Streaming", nil);
    titleLabel.textColor = UIColor.labelColor;
    titleLabel.font = [UIFont systemFontOfSize:28 weight:UIFontWeightBold];

    UILabel *descriptionLabel = [[UILabel alloc] init];
    descriptionLabel.translatesAutoresizingMaskIntoConstraints = NO;
    descriptionLabel.numberOfLines = 0;
    descriptionLabel.textColor = UIColor.secondaryLabelColor;
    descriptionLabel.font = [UIFont systemFontOfSize:14];
    descriptionLabel.text = NSLocalizedString(@"Send 16 kHz mono PCM to the device. Choose the Opus target bitrate below.", nil);

    self.send16KButton = [self actionButtonWithTitle:NSLocalizedString(@"Play test_send_16k.pcm (16 kbps)", nil)
                                              image:@"speaker.wave.2.fill"
                                             action:@selector(send16KAudio)];
    self.send32KButton = [self actionButtonWithTitle:NSLocalizedString(@"Play test_send_32k.pcm (32 kbps)", nil)
                                              image:@"speaker.wave.3.fill"
                                             action:@selector(send32KAudio)];

    self.cancelButton = [UIButton buttonWithType:UIButtonTypeSystem];
    self.cancelButton.translatesAutoresizingMaskIntoConstraints = NO;
    [self.cancelButton setTitle:NSLocalizedString(@"Cancel Sending", nil) forState:UIControlStateNormal];
    [self.cancelButton setTitleColor:UIColor.systemRedColor forState:UIControlStateNormal];
    self.cancelButton.titleLabel.font = [UIFont systemFontOfSize:16 weight:UIFontWeightSemibold];
    self.cancelButton.layer.cornerRadius = 12;
    self.cancelButton.layer.borderWidth = 1;
    self.cancelButton.layer.borderColor = UIColor.systemRedColor.CGColor;
    [self.cancelButton addTarget:self action:@selector(cancelSending) forControlEvents:UIControlEventTouchUpInside];

    self.activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
    self.activityIndicator.translatesAutoresizingMaskIntoConstraints = NO;

    self.statusLabel = [[UILabel alloc] init];
    self.statusLabel.translatesAutoresizingMaskIntoConstraints = NO;
    self.statusLabel.numberOfLines = 0;
    self.statusLabel.textAlignment = NSTextAlignmentCenter;
    self.statusLabel.textColor = UIColor.secondaryLabelColor;
    self.statusLabel.font = [UIFont systemFontOfSize:14];

    UIStackView *stackView = [[UIStackView alloc] initWithArrangedSubviews:@[
        backButton,
        titleLabel,
        descriptionLabel,
        self.send16KButton,
        self.send32KButton,
        self.cancelButton,
        self.activityIndicator,
        self.statusLabel
    ]];
    stackView.translatesAutoresizingMaskIntoConstraints = NO;
    stackView.axis = UILayoutConstraintAxisVertical;
    stackView.spacing = 14;
    [stackView setCustomSpacing:8 afterView:backButton];
    [stackView setCustomSpacing:6 afterView:titleLabel];
    [stackView setCustomSpacing:24 afterView:descriptionLabel];
    [stackView setCustomSpacing:24 afterView:self.cancelButton];
    [self.view addSubview:stackView];

    [NSLayoutConstraint activateConstraints:@[
        [stackView.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor constant:28],
        [stackView.leadingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.leadingAnchor constant:24],
        [stackView.trailingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.trailingAnchor constant:-24],
        [backButton.heightAnchor constraintEqualToConstant:32],
        [self.send16KButton.heightAnchor constraintEqualToConstant:52],
        [self.send32KButton.heightAnchor constraintEqualToConstant:52],
        [self.cancelButton.heightAnchor constraintEqualToConstant:48]
    ]];
}

- (void)goBack
{
    [self.navigationController popViewControllerAnimated:YES];
}

- (UIButton *)actionButtonWithTitle:(NSString *)title image:(NSString *)imageName action:(SEL)action
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.translatesAutoresizingMaskIntoConstraints = NO;
    button.backgroundColor = UIColor.systemBlueColor;
    button.tintColor = UIColor.whiteColor;
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
    [button setImage:[UIImage systemImageNamed:imageName] forState:UIControlStateNormal];
    button.titleLabel.font = [UIFont systemFontOfSize:15 weight:UIFontWeightSemibold];
    button.layer.cornerRadius = 12;
    button.imageEdgeInsets = UIEdgeInsetsMake(0, -6, 0, 6);
    [button addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    return button;
}

- (void)send16KAudio
{
    [self sendPCMResource:@"test_send_16k" bitrate:16000];
}

- (void)send32KAudio
{
    [self sendPCMResource:@"test_send_32k" bitrate:32000];
}

- (void)sendPCMResource:(NSString *)resourceName bitrate:(NSUInteger)bitrate
{
    if (self.isSending) {
        return;
    }

    NSString *path = [NSBundle.mainBundle pathForResource:resourceName ofType:@"pcm"];
    NSError *readError = nil;
    NSData *pcmData = path.length > 0 ? [NSData dataWithContentsOfFile:path options:NSDataReadingMappedIfSafe error:&readError] : nil;
    if (pcmData.length == 0) {
        NSString *message = readError.localizedDescription ?: NSLocalizedString(@"PCM resource was not found in the app bundle.", nil);
        [self showFailure:message];
        return;
    }

    [self updateSendingState:YES];
    self.statusLabel.text = [NSString stringWithFormat:NSLocalizedString(@"Starting %@ at %lu kbps…", nil),
                             [resourceName stringByAppendingPathExtension:@"pcm"],
                             (unsigned long)(bitrate / 1000)];
    XLOG_INFO(@"Starting PCM audio stream: %@, sampleRate=%@, channels=%@, bitrate=%@, bytes=%@",
              resourceName, @(PCMAudioSampleRate), @(PCMAudioChannels), @(bitrate), @(pcmData.length));

    __weak typeof(self) weakSelf = self;
    [FitCloudKit startPCMAudioPlaybackWithSampleRate:PCMAudioSampleRate
                                           channels:PCMAudioChannels
                                            bitrate:bitrate
                                         completion:^(BOOL success, NSError *error) {
        if (!success) {
            [weakSelf completeWithSuccess:NO error:error];
            return;
        }

        [weakSelf updateStatus:NSLocalizedString(@"Device is ready. Sending PCM audio…", nil)];
        [FitCloudKit appendPCMAudioData:pcmData completion:^(BOOL success, NSError *error) {
            if (!success) {
                [weakSelf completeWithSuccess:NO error:error];
                return;
            }

            [weakSelf updateStatus:NSLocalizedString(@"PCM data queued. Waiting for playback to finish…", nil)];
            [FitCloudKit finishPCMAudioPlaybackWithCompletion:^(BOOL success, NSError *error) {
                [weakSelf completeWithSuccess:success error:error];
            }];
        }];
    }];
}

- (void)cancelSending
{
    if (!self.isSending) {
        return;
    }

    self.cancelButton.enabled = NO;
    [self updateStatus:NSLocalizedString(@"Cancelling audio stream…", nil)];
    __weak typeof(self) weakSelf = self;
    [FitCloudKit cancelPCMAudioPlaybackWithCompletion:^(BOOL success, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf updateSendingState:NO];
            if (success) {
                weakSelf.statusLabel.text = NSLocalizedString(@"Audio sending cancelled.", nil);
                XLOG_INFO(@"PCM audio stream cancelled.");
            } else {
                NSString *message = error.localizedDescription ?: NSLocalizedString(@"Unable to cancel audio sending.", nil);
                [weakSelf showFailure:message];
            }
        });
    }];
}

- (void)completeWithSuccess:(BOOL)success error:(NSError *)error
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self updateSendingState:NO];
        if (success) {
            self.statusLabel.text = NSLocalizedString(@"Audio playback completed.", nil);
            [self.view makeToast:NSLocalizedString(@"Audio playback completed.", nil)
                       duration:3.0
                       position:CSToastPositionTop];
            XLOG_INFO(@"PCM audio stream completed.");
        } else {
            NSString *message = error.localizedDescription ?: NSLocalizedString(@"Audio sending failed.", nil);
            [self showFailure:message];
        }
    });
}

- (void)showFailure:(NSString *)message
{
    self.statusLabel.text = message;
    [self.view makeToast:message duration:3.0 position:CSToastPositionTop];
    XLOG_ERROR(@"PCM audio stream failed: %@", message);
}

- (void)updateStatus:(NSString *)status
{
    dispatch_async(dispatch_get_main_queue(), ^{
        self.statusLabel.text = status;
    });
}

- (void)updateSendingState:(BOOL)sending
{
    self.sending = sending;
    self.send16KButton.enabled = !sending;
    self.send32KButton.enabled = !sending;
    self.send16KButton.alpha = sending ? 0.45 : 1.0;
    self.send32KButton.alpha = sending ? 0.45 : 1.0;
    self.cancelButton.enabled = sending;
    self.cancelButton.alpha = sending ? 1.0 : 0.45;
    if (sending) {
        [self.activityIndicator startAnimating];
    } else {
        [self.activityIndicator stopAnimating];
    }
}

@end
