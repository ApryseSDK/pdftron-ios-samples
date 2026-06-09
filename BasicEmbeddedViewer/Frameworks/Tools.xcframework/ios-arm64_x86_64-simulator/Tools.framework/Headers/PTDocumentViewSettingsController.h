//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentViewSettings.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentViewSettingsController;

/**
 * The methods declared by the `PTSettingsViewControllerDelegate` protocol allow the adopting class
 * to respond to messages from the `PTSettingsViewController` class.
 */
PT_OBJC_RUNTIME_NAME(DocumentViewSettingsControllerDelegate)
@protocol PTDocumentViewSettingsControllerDelegate <NSObject>
@optional

- (void)documentViewSettingsController:(PTDocumentViewSettingsController *)documentViewSettingsController didUpdateSettings:(PTDocumentViewSettings *)settings;

- (void)documentViewSettingsControllerCropPagesSelected:(PTDocumentViewSettingsController *)documentViewSettingsController;

- (void)documentViewSettingsControllerCropPagesSelected:(PTDocumentViewSettingsController *)documentViewSettingsController fromSender:(id)sender;

@end

/**
 * The `PTDocumentViewSettingsController` class displays settings to control a `PTPDFViewCtrl`.
 */
PT_OBJC_RUNTIME_NAME(DocumentViewSettingsController)
@interface PTDocumentViewSettingsController : UITableViewController <PTOverridable>

/**
 * The settings object that is used to persist view preferences.
 */
@property (nonatomic, strong, null_resettable) PTDocumentViewSettings *settings;

/**
 * The `PTPDFViewCtrl` that the control will apply settings changes to.
 */
@property (nonatomic, weak, readonly) PTPDFViewCtrl *pdfViewCtrl;


/**
 * `true` if single page mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL viewModeSinglePageHidden;

/**
 * `true` if facing page mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL viewModeFacingHidden;

/**
 * `true` if cover facing page mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL viewModeCoverFacingHidden;

/**
 * `true` if right to left page mode is hidden; false otherwise. Default is true unless
 *  `UIApplication.sharedApplication.userInterfaceLayoutDirection == UIUserInterfaceLayoutDirectionRightToLeft`
 *  is true, in which case the default is `false`.
 */
@property (nonatomic, assign) BOOL viewModeRightToLeftHidden;

/**
 * `true` if reader mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL viewModeReaderHidden;

/**
 * `true` if continuous page mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL viewModeContinuousHidden;

/**
 * `true` if light color mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL colorModeLightHidden;

/**
 * `true` if dark color mode mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL colorModeDarkHidden;

/**
 * `true` if sepia color mode is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL colorModeSepiaHidden;

/**
 * `true` if page rotation is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL pageRotationHidden;

/**
 * `true` if crop pages is hidden; false otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL cropPagesHidden;

/**
 * The document view settings controller's delegate.
 */
@property (nonatomic, weak, nullable) id<PTDocumentViewSettingsControllerDelegate> delegate;

/**
 * Initializes a new instance of this view controller.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` that the control will interface with.
 *
 * @returns An initialized `PTDocumentViewSettingsController` instance
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly, strong) UIBarButtonItem *doneButtonItem;


PT_INIT_UNAVAILABLE;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;

- (instancetype)initWithNibName:(nullable NSString *)nibName bundle:(nullable NSBundle *)nibBundle NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
