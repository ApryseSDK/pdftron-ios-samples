//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// The location of a `PTResizeWidgetView` selection dot around the edge of a rectangle.
typedef NS_ENUM(NSInteger, PTResizeHandleLocation) {
    /// Unknown resize handle location.
    PTResizeHandleLocationNone,
    /// The NW resize dot
    PTResizeHandleLocationTopLeft,
    /// The top center resize dot
    PTResizeHandleLocationTop,
    /// The NE resize dot
    PTResizeHandleLocationTopRight,
    /// The righthand center resize dot
    PTResizeHandleLocationRight,
    /// The SE resize dot
    PTResizeHandleLocationBottomRight,
    /// The bottom center resize dot
    PTResizeHandleLocationBottom,
    /// The SW resize dot
    PTResizeHandleLocationBottomLeft,
    /// The lefthand centre dot
    PTResizeHandleLocationLeft,
};

/**
 * The view for the small resize handles that appear for annotation resizing with a
 * `PTSelectionRectContainerView`.
 */
PT_OBJC_RUNTIME_NAME(ResizeWidgetView)
@interface PTResizeWidgetView : UIView

/**
 * This widget's location.
 */
@property (nonatomic, assign) PTResizeHandleLocation location;

/**
 * The size of a resize widget.
 */
@property (nonatomic, class, readonly) int length;

/**
 * Returns a new instance of a PTResizeWidgetView.
 *
 * @param point The resize handle's position in its superview.
 * @param loc The location of the resize handle.
 */
- (instancetype)initAtPoint:(CGPoint)point WithLocation:(PTResizeHandleLocation)loc;

#pragma mark - Border

/**
 * The color of the border around the view.
 *
 * The border color can be reset to its default value by assigning a value of `nil` to this property.
 *
 * @note The default border color is `UIColor.whiteColor`.
 */
@property (nonatomic, strong, null_resettable) UIColor *borderColor UI_APPEARANCE_SELECTOR;

/**
 * The width of the border around the view.
 *
 * The border can be hidden by setting the width to a value of `0.0`.
 *
 * @note The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat borderWidth UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
