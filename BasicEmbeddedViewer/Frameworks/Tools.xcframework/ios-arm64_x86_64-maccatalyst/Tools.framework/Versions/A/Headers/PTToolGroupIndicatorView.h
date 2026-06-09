//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolGroupManager.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTToolGroupView` displays the current tool group of a `PTToolGroupManager`
 * instance.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(ToolGroupIndicatorView)
@interface PTToolGroupIndicatorView : UIView

/**
 * Intializes a `PTToolGroupIndicatorView` instance with the given frame.
 *
 * @param frame The frame of the view.
 *
 * @return An initialized `PTToolGroupIndicatorView` instance.
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

/**
 * Intializes a `PTToolGroupIndicatorView` instance with a decoder.
 *
 * @param coder The decoder object.
 *
 * @return An initialized `PTToolGroupIndicatorView` instance, or `nil` if decoding failed.
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * The button shown by this view to indicate the current tool group. The button's
 * text is updated to display the current tool group when it changes.
 */
@property (nonatomic, readonly, strong) UIButton *button;

/**
 * The tool group manager associated with this view.
 */
@property (nonatomic, strong, nullable) PTToolGroupManager *toolGroupManager;

@end

NS_ASSUME_NONNULL_END
