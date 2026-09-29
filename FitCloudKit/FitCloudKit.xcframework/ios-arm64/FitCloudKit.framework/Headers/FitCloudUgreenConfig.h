//
//  FitCloudUgreenConfig.h
//  FitCloudKit
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// UGREEN-specific device configuration.
@interface FitCloudUgreenConfig : NSObject <NSCopying>

/// Whether desktop-stand mode is enabled.
@property(nonatomic, assign) BOOL desktopModeEnabled;

/// Function entered after pressing the device button three times.
@property(nonatomic, assign) FitCloudUgreenTriplePressFunction triplePressFunction;

/// Pages whose screens remain always on.
@property(nonatomic, assign) FitCloudUgreenAlwaysOnPage alwaysOnPages;

/// Lyrics theme.
@property(nonatomic, assign) FitCloudUgreenLyricsTheme lyricsTheme;

/// Lyrics RGBA color. Used when `lyricsTheme` is `FitCloudUgreenLyricsThemeCustom`.
@property(nonatomic, strong) UIColor *lyricsColor;

/// Returns whether every field can be encoded by the Bluetooth protocol.
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
