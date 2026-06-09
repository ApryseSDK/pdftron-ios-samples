//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTPageIndicatorViewController` displays the current page number in a document.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(PageIndicatorViewController)
@interface PTPageIndicatorViewController : UIViewController <PTOverridable>

/**
 * Initializes a new `PTPageIndicatorViewController` instance.
 *
 * @param pdfViewCtrl the `PTPDFViewCtrl` instance that the control will coordinate with
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a new `PTPageIndicatorViewController` instance.
 *
 * @param toolManager the `PTToolManager` instance that the control will coordinate with
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The `PTPDFViewCtrl` instance that this control coordinates with to receive page-change events
 * and page-related information.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The `PTToolManager` instance that this control coordinates with to receive page-related events.
 */
@property (nonatomic, readonly, strong, nullable) PTToolManager *toolManager;

/**
 * The view that provides the background appearance. The default background view blurs the content
 * behind the page indicator. Setting a value of `nil` resets this property to the default background
 * view.
 */
@property (nonatomic, strong, null_resettable) UIView *backgroundView;

/**
 * The text label showing the page number.
 */
@property (nonatomic, readonly, strong) UILabel *label;

/**
 * Presents a UIAlertController to allow the user to jump to a page.
 */
- (void)presentGoToPageController;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
