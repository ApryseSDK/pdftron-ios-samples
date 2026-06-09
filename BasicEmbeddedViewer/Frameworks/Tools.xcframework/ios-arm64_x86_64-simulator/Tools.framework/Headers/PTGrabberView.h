//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The orientation of a `PTGrabberView` instance.
 */
typedef NS_ENUM(NSUInteger, PTGrabberOrientation) {
    /**
     * The grabber is oriented horizontally.
     */
    PTGrabberOrientationHorizontal,
    /**
     * The grabber is oriented vertically.
     */
    PTGrabberOrientationVertical,
} NS_SWIFT_NAME(PTGrabberView.GrabberOrientation);

/**
 * A grabber view can be used to indicate that an area can be dragged or resized by the user.
 * The handling of gestures and touches is the responsibility of the view containing an instance
 * of the `PTGrabberView` class.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(GrabberView)
@interface PTGrabberView : UIView

/**
 * The orientation of the grabber.
 *
 * The default value of this property is `PTGrabberOrientationHorizontal`.
 */
@property (nonatomic, assign) PTGrabberOrientation orientation;

/**
 * The fill color of the grabber.
 *
 * The default value of this property is `PTGrabberView.defaultFillColor`. Setting a value of `nil`
 * to this property resets the fill color to its default value.
 */
@property (nonatomic, strong, null_resettable) UIColor *fillColor UI_APPEARANCE_SELECTOR;

/**
 * The default fill color for instances of the `PTGrabberView` class.
 *
 * This color is a semi-transparent gray color.
 */
@property (nonatomic, class, readonly, strong) UIColor *defaultFillColor;

@end

NS_ASSUME_NONNULL_END
