//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <PDFNet/PDFViewCtrl.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A control used to select a single value from a continuous range of values.
 * This control is similar to `UISlider`, except that this control can be oriented horizontally
 * and vertically.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentSlider)
@interface PTDocumentSlider : UIControl

/**
 * The axis along which the slider thumb moves.
 *
 * The default value of this property is `UILayoutConstraintAxisHorizontal`.
 */
@property (nonatomic) UILayoutConstraintAxis axis;

/**
 * The view used to indicate the current `value` of the slider.
 */
@property (nonatomic, readonly) UIView *thumbView;

/**
 * The slider's current value.
 *
 * The default value of this property is `0.0`.
 */
@property (nonatomic) CGFloat value;

/**
 *
 * The amount by which to compress the height/width of the slider when the scrollview bounces.
 */
@property (nonatomic) CGFloat compress;


/**
 * Sets the slider's current value, allowing you to animate the change visually.
 *
 * @param value The new value to assign to the `value` property
 *
 * @param animated Specify `YES` to animate the change in value; otherwise, specify `NO` to update
 * the slider's appearance immmediately.
 *
 * @see `value`
 */
- (void)setValue:(CGFloat)value animated:(BOOL)animated;

/**
 * The minimum value of the slider.
 *
 * The default value of this property is `0.0`.
 */
@property (nonatomic) CGFloat minimumValue;

/**
 * The maximum value of the slider.
 *
 * The default value of this property is `1.0`.
 */
@property (nonatomic) CGFloat maximumValue;

/**
 * The PDFViewCtrl this slider is used for.
 * Used to determine if it is displaying the document in a RTL fashion.
 */
@property (nonatomic, weak) PTPDFViewCtrl* pdfViewCtrl;

@end

NS_ASSUME_NONNULL_END
