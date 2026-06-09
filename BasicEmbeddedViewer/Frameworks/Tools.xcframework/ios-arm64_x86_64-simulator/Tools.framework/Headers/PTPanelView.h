//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTGrabberView.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPanelView;

/**
 * The position (orientation) of a `PTPanelView`, which affects the placement of the resize-controls
 * and decorations shown by the panel.
 */
typedef NS_ENUM(NSUInteger, PTPanelPosition) {
    /**
     * The panel is on the left side of its container.
     */
    PTPanelPositionLeft,
    /**
     * The panel is on the right side of its container.
     */
    PTPanelPositionRight,
    /**
     * The panel is on the leading side of its container.
     */
    PTPanelPositionLeading,
    /**
     * The panel is on the trailing side of its container.
     */
    PTPanelPositionTrailing,
} NS_SWIFT_NAME(PTPanelView.PanelPosition);

/**
 * Instances of the `PTPanelView` class can contain any view as a subview of its `contentView`, and
 * when the panel can be resized, resize-controls are shown as appropriate.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PanelView)
@interface PTPanelView : UIView

/**
 * The position of the panel in its container.
 *
 * The default value of this property is `PTPanelPositionLeft`.
 */
@property (nonatomic, assign) PTPanelPosition position;

/**
 * The content view to which views can be added. Views should not be added directly to the
 * `PTPanelView` and instead added as a subview to the `contentView`.
 */
@property (nonatomic, readonly, strong) UIView *contentView;

/**
 * Whether the panel can be resized and should show the `grabber`.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isResizingEnabled) BOOL resizingEnabled;

/**
 * Whether the panel is currently being resized.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, readonly, assign, getter=isResizing) BOOL resizing;

/**
 * The grabber control used by this view to allow the user to resize the panel.
 */
@property (nonatomic, readonly, strong) PTGrabberView *grabber;

/**
 * The color used for the grabber while resizing the panel. Setting a value of `nil` resets this
 * property back to its default value.
 */
@property (nonatomic, strong, null_resettable) UIColor *resizingGrabberColor UI_APPEARANCE_SELECTOR;

/**
 * The default grabber color used while resizing for instances of the `PTPanelView` class.
 *
 * The default value of this property is a white color.
 */
@property (nonatomic, class, readonly, strong) UIColor *defaultResizingGrabberColor;

/**
 * The gesture recognizers used to handle resizing the panel.
 *
 * These gesture recognizer are attached to the `grabber`.
 */
@property (nonatomic, readonly, copy) NSArray<UIGestureRecognizer *> *resizeGestureRecognizers;

#pragma mark - Shadow

/**
 * The view used to show a separator along the edge of the panel.
 */
@property (nonatomic, readonly, strong) UIView *shadowView;

/**
 * The color used for the shadow shown by the `shadowView`. Setting a value of `nil` resets this
 * property back to its default value.
 */
@property (nonatomic, strong, null_resettable) UIColor *shadowColor UI_APPEARANCE_SELECTOR;

/**
 * The default shadow color for instances of the `PTPanelView` class.
 *
 * The default value of this property is a semi-transparent gray color.
 */
@property (nonatomic, class, readonly, strong) UIColor *defaultShadowColor;

#pragma mark Resizing

/**
 * The color used for the shadow shown by the `shadowView` while resizing the panel. Setting a
 * value of `nil` resets this property back to its default value.
 */
@property (nonatomic, strong, null_resettable) UIColor *resizingShadowColor UI_APPEARANCE_SELECTOR;

/**
 * The default shadow color used while resizing for instances of the `PTPanelView` class.
 *
 * The default value of this property is a black color.
 */
@property (nonatomic, class, readonly, strong) UIColor *defaultResizingShadowColor;

/**
 * The width of the shadow while the panel is being resized.
 *
 * The default value of this property is `10.0`.
 */
@property (nonatomic, assign) CGFloat resizingShadowWidth UI_APPEARANCE_SELECTOR;

#pragma mark Hidden

/**
 * Whether the shadow shown by the `shadowView` is hidden.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isShadowHidden) BOOL shadowHidden;

@end

NS_ASSUME_NONNULL_END
