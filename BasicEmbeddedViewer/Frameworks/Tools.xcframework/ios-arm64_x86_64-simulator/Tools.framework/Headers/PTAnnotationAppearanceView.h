//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationAppearanceViewModel.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationAppearanceViewModel;

/**
 * A view that displays the appearance of a PDF annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationAppearanceView)
@interface PTAnnotationAppearanceView : UIView

/**
 * Initializes a newly created `PTAnnotationAppearanceView` instance.
 *
 * @param frame The frame of the view.
 *
 * @return An initialized `PTAnnotationAppearanceView` instance.
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTAnnotationAppearanceView` instance with a decoder.
 *
 * @param coder The decoder.
 *
 * @return An initialized `PTAnnotationAppearanceView` instance, or `nil` if decoding failed.
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

#pragma mark - View model

/**
 * The current view model represented by this view.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnotationAppearanceViewModel *viewModel;

@end

@interface PTAnnotationAppearanceView (SubclassingHooks)

/**
 * Configures the view with the provided view model.
 *
 * @param viewModel The view model.
 */
- (void)configureWithViewModel:(PTAnnotationAppearanceViewModel *)viewModel NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
