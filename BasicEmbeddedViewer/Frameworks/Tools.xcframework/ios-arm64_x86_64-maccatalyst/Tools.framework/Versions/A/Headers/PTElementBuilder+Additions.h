//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Converts a `CGLineCap` enumeration value to the corresponding `PTLineCap` value.
 *
 * @param lineCap The value to be converted
 *
 * @return the corresponding `PTLineCap` value
 */
PT_EXTERN PTLineCap PTLineCapFromCGLineCap(CGLineCap lineCap);

/**
 * Converts a `CGLineJoin` enumeration value to the corresponding `PTLineJoin` value.
 *
 * @param lineJoin The value to be converted
 *
 * @return the corresponding `PTLineJoin` value
 */
PT_EXTERN PTLineJoin PTLineJoinFromCGLineJoin(CGLineJoin lineJoin);

/**
 * Additions to the `PTElementBuilder` class.
 */
@interface PTElementBuilder (Additions)

/**
 * Creates a path element with the information from the specified bezier path.
 *
 * In addition to the points comprising the path data, the line width, line cap style, line join
 * style, miter limit, flatness, and even-odd-fill-rule properties of the bezier path are also
 * applied to the graphics state of the path element.
 *
 * @param bezierPath The bezier path from which to create a path element
 *
 * @return the resulting path element
 */
- (PTElement *)CreatePathWithBezierPath:(UIBezierPath *)bezierPath;

@end

NS_ASSUME_NONNULL_END
