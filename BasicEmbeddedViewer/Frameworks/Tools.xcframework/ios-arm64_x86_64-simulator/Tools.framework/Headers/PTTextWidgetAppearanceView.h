//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationAppearanceView.h>
#import <Tools/PTTextWidgetAppearanceViewModel.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextWidgetAppearanceViewModel;

/**
 * A view that displays the appearance of a text widget annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextWidgetAppearanceView)
@interface PTTextWidgetAppearanceView : PTAnnotationAppearanceView <UITextViewDelegate>

/**
 * Initializes a newly created `PTTextWidgetAppearanceView` instance.
 *
 * @return An initialized `PTTextWidgetAppearanceView` instance.
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTTextWidgetAppearanceView` from data in the given unarchiver.
 *
 * @param coder The unarchiver object.
 *
 * @return An initialized `PTTextWidgetAppearanceView`, or `nil` if an error occurred.
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

#pragma mark - View model

/**
 * @see `PTAnnotationAppearanceView.viewModel`
 */
@property (nonatomic, readonly, strong, nullable) PTTextWidgetAppearanceViewModel *viewModel;

/**
 * @see `-[PTAnnotationAppearanceView configureWithViewModel:]`
 */
- (void)configureWithViewModel:(PTTextWidgetAppearanceViewModel *)viewModel NS_REQUIRES_SUPER;

#pragma mark - Attributes

/**
 * The scaling applied to the contents of this view when zoomed.
 *
 * In order to avoid bitmap-based scaling of the content, the font size of the text view is adjusted
 * for the current zoom scale. As a result, the text view's font should not be set or queried externally.
 *
 * @note The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat zoomScale;

#pragma mark - Subviews

/**
 * The view used to display the border.
 */
@property (nonatomic, readonly, strong) UIView *borderView;

/**
 * The view used to display the background.
 *
 * The background is drawn inside the borders.
 */
@property (nonatomic, readonly, strong) UIView *backgroundView;

/**
 * The view containing all content inside the borders.
 */
@property (nonatomic, readonly, strong) UIView *contentView;

/**
 * The view used to display the text itself.
 *
 * @warning The text view's delegate is the `PTTextWidgetAppearanceView` and should not be changed.
 *
 * @note The text view's font is adjusted for the current `zoomScale` and should not be set or
 * queried externally.
 */
@property (nonatomic, readonly, strong) UITextView *textView;

#pragma mark - Layout

/**
 * A layout guide for the area inside the border.
 */
@property (nonatomic, readonly, strong) UILayoutGuide *contentLayoutGuide;

@end

NS_ASSUME_NONNULL_END
