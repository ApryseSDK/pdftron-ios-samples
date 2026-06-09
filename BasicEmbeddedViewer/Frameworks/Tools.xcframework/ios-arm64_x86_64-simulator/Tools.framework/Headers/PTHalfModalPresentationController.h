//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A presentation controller that displays its presented view controller anchored at the bottom of the
 * screen. In its default configuration, the presentation controller allows touches outside the presented
 * view controller to be passed through to the view(s) underneath.
 *
 * The height of the presented view controller is determined by its `UIViewController.preferredContentSize`
 * instance property. If the preferred content size is not set then the presented view controller will
 * extend to the top of the screen, respecting the safe area insets.
 *
 * The presented view controller can be dismissed by dragging downwards over its view. Pan gesture
 * recognizers inside the presented view controller are given priority over the drag-to-dismiss gesture.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(HalfModalPresentationController)
@interface PTHalfModalPresentationController : UIPresentationController

/**
 * Initializes a `PTHalfModalPresentationController` instance.
 *
 * @param presentedViewController The view controller being presented modally
 *
 * @param presentingViewController The view controller whose content represents the starting point of
 * the transition, or `nil`
 *
 * @return an initialized `PTHalfModalPresentationController` instance
 */
- (instancetype)initWithPresentedViewController:(UIViewController *)presentedViewController
                       presentingViewController:(nullable UIViewController *)presentingViewController NS_DESIGNATED_INITIALIZER;

/**
 * The views underneath the presented view controller for which touches should be allowed.
 *
 * The default value of this property is `presentingViewController.view`.
 */
@property (nonatomic, copy, nullable) NSArray<UIView *> *passthroughViews;

/**
 * Whether the visible portion of the presenters view is dimmed. When enabled, tapping anywhere outside
 * the presented view controller will dismiss this presentation controller.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL dimsBackgroundView;

/**
 * When non-zero, the corners of the presented view controller are rounded with this radius.
 *
 * The default value of this property is `10.0`.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 * Whether the grabber "pill" at the top of the presented view controller is hidden.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isGrabberHidden) BOOL grabberHidden;

@end

NS_ASSUME_NONNULL_END
