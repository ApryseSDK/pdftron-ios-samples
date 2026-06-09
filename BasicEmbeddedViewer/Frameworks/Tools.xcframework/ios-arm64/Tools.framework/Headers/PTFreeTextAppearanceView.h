//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationAppearanceView.h>
#import <Tools/PTFreeTextAppearanceViewModel.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFreeTextAppearanceViewModel;

/**
 * A view that displays the appearance of a free text annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextAppearanceView)
@interface PTFreeTextAppearanceView : PTAnnotationAppearanceView <UITextViewDelegate>

/**
 * Initializes a newly created `PTFreeTextAppearanceView` instance.
 *
 * @return An initialized `PTFreeTextAppearanceView` instance.
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTFreeTextAppearanceView` from data in the given unarchiver.
 *
 * @param coder The unarchiver object.
 *
 * @return An initialized `PTFreeTextAppearanceView`, or `nil` if an error occurred.
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

#pragma mark - View model

/**
 * @see `PTAnnotationAppearanceView.viewModel`
 */
@property (nonatomic, readonly, strong, nullable) PTFreeTextAppearanceViewModel *viewModel;

/**
 * @see `-[PTAnnotationAppearanceView configureWithViewModel:]`
 */
- (void)configureWithViewModel:(PTFreeTextAppearanceViewModel *)viewModel NS_REQUIRES_SUPER;

#pragma mark - Subviews

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
 * @warning The text view's delegate is the `PTFreeTextAppearanceView` and should not be changed.
 */
@property (nonatomic, readonly, strong) UITextView *textView;

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

/**
 * The scaling applied to this view's font.
 *
 * An additional scale factor applied to the font size of the text view.
 *
 * @note The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat fontScale;

@end

NS_ASSUME_NONNULL_END
