//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPanelView.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPanelView;
@class PTPanelViewController;


PT_OBJC_RUNTIME_NAME(PanelViewControllerDelegate)
@protocol PTPanelViewControllerDelegate <NSObject>
@optional
    
- (void)panelViewController:(PTPanelViewController *)panelViewController didShowLeadingViewController:(UIViewController *)viewController;

- (void)panelViewController:(PTPanelViewController *)panelViewController didDismissLeadingViewController:(UIViewController *)viewController;

@end

/**
 * A container view controller that can display its child view controllers in a "panel" layout,
 * where a panel can be shown or hidden and can be, optionally, resized by the user.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PanelViewController)
@interface PTPanelViewController : UIViewController

/**
 * Whether the panels controlled by this view controller are enabled.
 *
 * When disabled, calls to the `-showLeadingViewController:animated:` and
 * `-showTrailingViewController:animated:` methods will present the provided view controller instead
 * of adding the view controller to a panel.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=arePanelsEnabled) BOOL panelsEnabled;

/**
 * Whether the panels can be resized by a drag gesture.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isPanelResizingEnabled) BOOL panelResizingEnabled;

/**
 * Notifies the delegate of when the panel controller is shown and dismissed.
 */
@property (nonatomic, weak, nullable) id<PTPanelViewControllerDelegate> delegate;

#pragma mark - Content view controller

/**
 * The child view controller that contains the main content.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIViewController *contentViewController;

/**
 * The content container view that contains the main content of this view controller.
 *
 * The root `UIView` of the `contentViewController` is added as a subview to this view.
 */
@property (nonatomic, readonly, strong) UIView *containerView;

#pragma mark - Leading view controller panel

/**
 * The child view controller that is shown in the `leadingPanel` view.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIViewController *leadingViewController;

/**
 * Shows the specified view controller in the leading panel as a child view controller.
 */
- (void)showLeadingViewController:(UIViewController *)viewController;

/**
 * Shows the specified view controller in the leading panel as a child view controller, optionally
 * animated the presentation.
 */
- (void)showLeadingViewController:(UIViewController *)viewController animated:(BOOL)animated;

/**
 * Hides the leading view controller if shown as a panel, or dismisses the presented view controller.
 */
- (void)dismissLeadingViewController;

/**
 * Hides the leading view controller if shown as a panel, or dismisses the presented view controller,
 * optionally animating the dismissal.
 */
- (void)dismissLeadingViewControllerAnimated:(BOOL)animated;

/**
 * The leading panel container view.
 *
 * The root view of the `leadingViewController` is added to this view.
 */
@property (nonatomic, readonly, strong) PTPanelView *leadingPanel;

/**
 * Whether the leading panel is hidden.
 */
@property (nonatomic, assign, getter=isLeadingPanelHidden) BOOL leadingPanelHidden;

/**
 * Sets whether the leading panel is hidden, optionally animating the change.
 */
- (void)setLeadingPanelHidden:(BOOL)hidden animated:(BOOL)animated;

#pragma mark - Trailing view controller panel

/**
 * The child view controller that is shown in the `trailingPanel` view.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIViewController *trailingViewController;

/**
 * Shows the specified view controller in the trailing panel as a child view controller.
 */
- (void)showTrailingViewController:(UIViewController *)viewController;

/**
 * Shows the specified view controller in the trailing panel as a child view controller, optionally
 * animating the presentation.
 */
- (void)showTrailingViewController:(UIViewController *)viewController animated:(BOOL)animated;

/**
 * Hides the trailing view controller if shown as a panel, or dismisses the presented view controller.
 */
- (void)dismissTrailingViewController;

/**
 * Hides the trailing view controller if shown as a panel, or dismisses the presented view controller,
 * optionally animating the dismissal.
 */
- (void)dismissTrailingViewControllerAnimated:(BOOL)animated;

/**
 * The trailing panel container view.
 *
 * The root view of the `trailingViewController` is added to this view.
 */
@property (nonatomic, readonly, strong) PTPanelView *trailingPanel;

/**
 * Whether the trailing panel is hidden.
 */
@property (nonatomic, assign, getter=isTrailingPanelHidden) BOOL trailingPanelHidden;

/**
 * Sets whether the trailing panel is hidden, optionally animating the change.
 */
- (void)setTrailingPanelHidden:(BOOL)hidden animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
