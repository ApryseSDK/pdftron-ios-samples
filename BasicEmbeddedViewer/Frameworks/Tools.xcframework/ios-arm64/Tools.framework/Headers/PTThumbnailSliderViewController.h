//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTThumbnailSliderView.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTThumbnailSliderViewController;

/**
 * The methods declared by the `PTThumbnailSliderViewDelegate` protocol allow the adopting delegate to
 * respond to messages from the `ThumbnailSliderView` class.
 */
PT_OBJC_RUNTIME_NAME(ThumbnailSliderViewDelegate)
@protocol PTThumbnailSliderViewDelegate <NSObject>
@optional

/**
 * Informs the delegate when the slider is touched by the user.
 */
- (void)thumbnailSliderViewInUse:(PTThumbnailSliderViewController *)thumbnailSliderViewController;

/**
 * Informs the delegate when the slider is no longer being touched by the user.
 */
- (void)thumbnailSliderViewNotInUse:(PTThumbnailSliderViewController *)thumbnailSliderViewController;

@end

/**
 * The `PTThumbnailSliderViewController` uses PDFViewCtrl's GetThumbAsync API to show thumbnails
 * of the current page as the slider is moved.
 */
PT_DEPRECATED_MSG(10.1.0, "Use PTDocumentSliderViewController instead")
PT_OBJC_RUNTIME_NAME(ThumbnailSliderViewController)
@interface PTThumbnailSliderViewController : UIViewController <PTOverridable>

/**
 * Returns a new instance of a `PTThumbnailSliderViewController`.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` instance that the control will coordinate with.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of a `PTThumbnailSliderViewController`.
 *
 * @param toolManager The `PTToolManager` instance that the control will coordinate with.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The `PTPDFViewCtrl` instance that this control coordinates with.
 */
@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The `PTToolManager` instance that this control coordinates with.
 */
@property (nonatomic, readonly, strong, nullable) PTToolManager *toolManager;

/**
 * The `UIToolbar` shown by this control as the view controller's `view`.
 */
@property (nonatomic, readonly, strong) UIToolbar *toolbar;

/**
 * The `UISlider` shown by this control. To show the slider,
 */
@property (nonatomic, readonly, strong) UISlider *slider;

/**
 * The `PTThumbnailSliderView` shown by this control.
 */
@property (nonatomic, readonly, strong) PTThumbnailSliderView *thumbnailSliderView;

/**
 * The view currently shown by this control to change pages in the document. The default value is
 * the `PTThumbnailSliderView` in the `thumbnailSliderView` property.
 */
@property (nonatomic, strong) UIView *contentView;

/**
 * Whether the control is currently tracking touch events.
 */
@property (nonatomic, readonly, getter=isTracking) BOOL tracking;

/**
 * The toolbar item placed to the left (leading end) of the slider control.
 * When `leadingToolbarItems` is used, this is the first item in the list.
 */
@property (nonatomic, strong, nullable) UIBarButtonItem *leadingToolbarItem;

/**
 * The toolbar items placed to the left (leading end) of the slider control.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *leadingToolbarItems;

/**
 * The toolbar item placed to the right (trailing end) of the slider control.
 * When `trailingToolbarItems` is used, this is the first item in the list.
 */
@property (nonatomic, strong, nullable) UIBarButtonItem *trailingToolbarItem;

/**
 * The toolbar items placed to the right (trailing end) of the slider control.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *trailingToolbarItems;

/**
 * An object that conforms to the `PTThumbnailSliderViewDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTThumbnailSliderViewDelegate> delegate;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

NS_ASSUME_NONNULL_END

@end
