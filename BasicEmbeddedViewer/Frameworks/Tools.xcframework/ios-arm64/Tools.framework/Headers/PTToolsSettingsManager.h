//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT NSString * const PTToolsSettingsCategoryKey;
PT_EXPORT NSString * const PTToolsSettingsFooterDescriptionKey;
PT_EXPORT NSString * const PTToolsSettingsSettingKey;
PT_EXPORT NSString*  const PTToolsSettingsMultivalueKey;
PT_EXPORT NSString * const PTToolsSettingsCategoryDefaultValueKey;
PT_EXPORT NSString * const PTToolsSettingsSettingNameKey;
PT_EXPORT NSString * const PTToolsSettingsCategoryDescriptionKey;
PT_EXPORT NSString * const PTToolsSettingsSettingKeyKey;
PT_EXPORT NSString * const PTToolsSettingsPlistNameKey;
PT_EXPORT NSString * const PTToolsSettingsMinOSKey;
PT_EXPORT NSString * const PTToolsSettingsUnavailableKey;


/**
 * Whether only the Apple Pencil is used to annotate.
 */
typedef NS_ENUM(NSInteger, PTPencilInteractionMode) {
    /// Allow finger and Pencil touches to annotate.
    PTPencilInteractionModeFingerAndPencil,
    /// Only Pencil touches annotate, finger touches are used for zooming and scrolling.
    PTPencilInteractionModePencilOnly,
    /// Obey the iOS Apple Pencil system setting.
    PTPencilInteractionModeSystem
};

/**
 *
 * A class that manages user preferences.
 *
 * The settings in this class are use by the `PTDocumentBaseViewController` to control its behaviour, except as noted in the documentation for each setting.
 *
 */
PT_OBJC_RUNTIME_NAME(ToolsSettingsManager)
@interface PTToolsSettingsManager : NSObject

/**
 * The global instance of the shared tools settings manager.
 */
@property (nonatomic, class, readonly, strong) PTToolsSettingsManager *sharedManager;

/**
 *
 * The default settings. These are the values that are contained in the settings plist file, `PTToolsSettings.plist`, not necessarily the current values.
 *
 */
@property (nonatomic, retain, readonly) NSArray<NSDictionary<NSString *, id> *> *toolsDefaultSettings;

/**
 *
 * The default Apple Pencil settings. These are the values that are contained in the settings plist file, `PTApplePencilSettings.plist`, not necessarily the current values.
 *
 */
@property (nonatomic, retain, readonly) NSArray<NSDictionary<NSString *, id> *> *applePencilDefaultSettings;

/**
 *
 * Returns the default settings for a given settings plist file. These are the values that are contained in the plist file, not necessarily the current values.
 *
 */
-(NSArray<NSDictionary<NSString *, id> *>*) defaultSettingsForPlistName:(NSString*)plistName;

/**
 * Determines if freehand annotation tool is shown in the main toolbar.
 *
 * Default is true.
 */
@property (nonatomic, assign) BOOL showInkInMainToolbar;

/**
 * Determines if the text search tool is shown in the main toolbar.
 *
 * Default is true on iPad, false on iPhone.
 */
@property (nonatomic, assign) BOOL showTextSearchInMainToolbar;

/**
 * Determines if shape annotations are automatically selected after the user creates them.
 *
 * Default is true.
 */
@property (nonatomic, assign) BOOL selectAnnotationAfterCreation;

/**
 * Determines if tabs for documents are enabled in the viewer.
 *
 * Default is true.
 *
 * @note this setting is not used by the `PTTabbedDocumentViewController`, and should instead be
 * read and acted upon by the app itself.
 */
@property (nonatomic, assign) BOOL tabsEnabled;

/**
 * Determines if the toolbars should be hidden automatically after 5 seconds.
 *
 * Default is false.
 */
@property (nonatomic, assign) BOOL automaticallyHideToolbars;

/**
 * Determines if PDFTron should execute any JavaScript contained in a PDF.
 *
 * Default is true.
 */
@property (nonatomic, assign) BOOL javascriptEnabled;


/**
 * Determines if PDFTron should use color management to render PDFs.
 *
 * Default is true.
 */
@property (nonatomic, assign) BOOL colorManagementEnabled;

/**
 * Determines if an Apple Pencil should immediately draw ink (as opposed to function like a finger touch).
 *
 * Default is true.
 */
@property (nonatomic, assign) BOOL applePencilDrawsInk;

/**
 * Determines if highlight-only annotations created using PencilKit use a multiply blend mode.
 *
 * Default is true.
 */
@property (nonatomic, assign) BOOL pencilHighlightMultiplyBlendModeEnabled;

/**
 * Determines if freehand highlighter annotations should be smoothed to a straight line.
 *
 * Default is false.
 */
@property (nonatomic, assign) BOOL freeHandHighlightSmoothingEnabled;

/**
 * Determines if the device should be stopped from dimming when a document is displayed.
 * Default is false.
 *
 * @note this setting is not used by the `PTDocumentViewController`, and should instead be read and acted upon by the app itself.
 */
@property (nonatomic, assign) BOOL stopScreenFromDimming;

/**
 * Determines if the navigation history user interface should be shown when applicable.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL navigationHistoryEnabled;

/**
 * Determines if the viewer settings should show an option to turn on Right to Left language viewing.
 *
 * Default is `false` when
 * `UIApplication.sharedApplication.userInterfaceLayoutDirection == UIUserInterfaceLayoutDirectionRightToLeft`;
 * `true otherwise.
 */
@property (nonatomic, assign) BOOL showRightToLeftViewerSetting;

/**
 *
 * Determines whether only Pencil touches should be used for annotating.
 *
 * Default is `PTPencilInteractionModeSystem`.
 */
@property (nonatomic, assign) PTPencilInteractionMode pencilInteractionMode;

/**
 * Returns the boolean value for a given setting key value.
 */
-(BOOL)boolForKey:(NSString*)key;

/**
 * Sets the boolean value for a given setting key value.
 */
-(void)setBool:(BOOL)value forKey:(NSString*)key;

/**
 * Returns the integer value for a given setting key value.
 */
-(NSInteger)integerForKey:(NSString*)key;

/**
 * Sets the integer value for a given setting key value.
 */
-(void)setInteger:(NSInteger)integer forKey:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
