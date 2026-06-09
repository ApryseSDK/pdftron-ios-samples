//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The view for the rotation handle that allows annotation rotation (for image stamps)
 * with a `PTSelectionRectContainerView`.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(RotateWidgetView)
@interface PTRotateWidgetView : UIView

/**
 * The size of a rotate widget.
 */
@property (nonatomic, class, readonly) int diameter;

/**
 * Returns a new instance of a PTRotateWidgetView.
 *
 * @param point The rotate handle's position in its superview.
 */
- (instancetype)initAtPoint:(CGPoint)point NS_DESIGNATED_INITIALIZER;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
