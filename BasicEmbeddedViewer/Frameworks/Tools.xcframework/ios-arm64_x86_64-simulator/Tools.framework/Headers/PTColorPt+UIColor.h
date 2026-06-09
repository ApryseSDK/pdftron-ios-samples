//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Convenience methods to convert a `PTColorPt` to and from a `UIColor` representation.
 */
PT_EXPORT
@interface PTColorPt (UIColor)

/**
 * Returns the `UIColor` value for this `PTColorPt` with the specified color component count.
 *
 * @param componentCount The number of color components in this `PTColorPt`
 *
 * @return the `UIColor` value for this `PTColorPt`, or `nil` if the color could not be converted
 */
- (nullable UIColor *)UIColorValueWithComponentCount:(int)componentCount;

/**
 * Returns the equivalent `UIColor` value for the given `PTColorPt` and color component count.
 *
 * @param colorPt The `PTColorPt` to be converted
 *
 * @param componentCount The number of color components in the `colorPt` parameter
 *
 * @return the `UIColor` value for the `PTColorPt`, or `nil` if the color could not be converted
 */
+ (nullable UIColor *)UIColorForColorPt:(PTColorPt *)colorPt
                     withComponentCount:(int)componentCount;

/**
 * Creates a new `PTColorPt` instance from the given `UIColor`.
 *
 * @param uiColor The `UIColor` from which to create a `PTColorPt` representation
 *
 * @param componentCount On output, this parameter contains the number of color components in the
 * returned `PTColorPt`. On error, this parameter is invalid.
 *
 * @return a new `PTColorPt` instance from the given `UIColor`. The `componentCount` parameter
 * contains the number of color components in the returned `PTColorPt`. If an error occurred during
 * the conversion or the `UIColor` could not be represented as a `PTColorPt`, then the returned value
 * is `nil` and the `componentCount` parameter is invalid.
 */
+ (nullable instancetype)colorFromUIColor:(UIColor *)uiColor componentCount:(int *)componentCount;

@end

NS_ASSUME_NONNULL_END
