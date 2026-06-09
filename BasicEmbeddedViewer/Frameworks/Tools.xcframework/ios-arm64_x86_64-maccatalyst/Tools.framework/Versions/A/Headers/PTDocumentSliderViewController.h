//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentSlider.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTDocumentSliderViewController` class displays a scroll indicator for a
 * `PTPDFViewCtrl`'s scroll position. The scroll indicator allows user interaction
 * and is used to change the current page of the associated `PTPDFViewCtrl` instance.
 *
 * This view controller is intended to be placed over the `PTPDFViewCtrl` instance,
 * covering the entire viewport. Unhandled touches in this view controller are forwarded
 * to the views behind.
 *
 * The scroll indicator adapts for the page presentation mode (scrolling direction)
 * of the `PTPDFViewCtrl`. For non-continuous page presentation modes, the scroll
 * indicator is displayed at the bottom of this view controller and for continuous page
 * presentation modes, the scroll indicator is displayed along the trailing edge of this
 * view controller.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentSliderViewController)
@interface PTDocumentSliderViewController : UIViewController

/**
 * Initializes a newly created `PTDocumentSliderViewController` instance with the
 * specified `pdfViewCtrl`.
 *
 * @param pdfViewCtrl the `PTPDFViewCtrl` instance to track
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl;

/**
 * The `PTPDFViewCtrl` instance tracked by this view controller.
 */
@property (nonatomic, strong, nullable) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The control that indicates and controls the scroll position and current page of the
 * `pdfViewCtrl`.
 */
@property (nonatomic, readonly) PTDocumentSlider *slider;

/**
 * Whether the `slider` control is currently hidden. The control is shown and hidden
 * automatically in response to `PTPDFViewCtrl` scroll and page change events.
 *
 * The default value is `YES`.
 */
@property (nonatomic, getter=isSliderHidden) BOOL sliderHidden;

/**
 * Control how long it takes hide the slider view.
 *
 * The default value is 1 second.
 */
@property (nonatomic, assign) NSTimeInterval hidingInterval;

/**
 * Sets whether the `slider` control is currently hidden, optionally animating the
 * change.
 *
 * @param hidden Specify `YES` to hide the control or `NO` to show it
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or
 * `NO` if you want the control to appear immediately.
 */
- (void)setSliderHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * The amount that the edges of the `slider` control should be inset from the edges of
 * this view controller's root view's edges when the slider is oriented horizontally.
 */
@property (nonatomic) UIEdgeInsets horizontalSliderInsets;

/**
 * The amount that the edges of the `slider` control should be inset from the edges of
 * this view controller's root view's edges when the slider is oriented vertically.
 */
@property (nonatomic) UIEdgeInsets verticalSliderInsets;

/**
 * Whether this view controller automatically hides the horizontal and/or vertical scroll indicators
 * of the `pdfViewCtrl` to avoid the `slider`.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL hidesPDFViewCtrlScrollIndicators;

@end

NS_ASSUME_NONNULL_END
