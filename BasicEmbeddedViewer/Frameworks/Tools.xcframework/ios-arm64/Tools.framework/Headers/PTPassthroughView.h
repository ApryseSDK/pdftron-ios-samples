//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A view that allows touch events to pass through to views behind it.
 *
 * This view behaves like a transparent overlay: if a touch does not hit any of its subviews,
 * the touch is ignored by the view itself and passed on to underlying views in the view hierarchy.
 * This is useful for overlay interfaces that should not block interaction with views beneath.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PassthroughView)
@interface PTPassthroughView : UIView

/**
 * Initializes a view with the specified frame.
 *
 * @param frame the frame rectangle of the view
 *
 * @return An initialized view.
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a view with data in an unarchiver.
 *
 * @param coder The unarchiver to be used
 *
 * @return An view, or `nil` if unarchiving the view was unsuccessful.
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
