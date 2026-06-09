//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
@interface PTPage (Additions)

/**
 * Returns a thumbnail image for the page that fits within the specified maximum size, in points.
 * This method is equivalent to calling `-thumbnailWithMaximumSize:scale:` with a `scale` parameter
 * equal to `0.0`.
 *
 * @param maximumSize The maximum dimensions of the thumbnail image, in points. The scale of the main
 * `UIScreen` is used.
 *
 * @return a thumbnail image for the page, or `nil` if a thumbnail could not be created
 */
- (nullable UIImage *)thumbnailWithMaximumSize:(CGSize)maximumSize;

/**
 * Returns a thumbnail image for the page that fits within the specified maximum size, in points.
 *
 * @param maximumSize The maximum dimensions of the thumbnail image, in points.
 *
 * @param scale The screen scale to use to convert points to pixels. If you specify a value of `0.0`,
 *  the scale factor is set to the scale factor of the device’s main screen.
 *
 * @return a thumbnail image for the page, or `nil` if a thumbnail could not be created
 */
- (nullable UIImage *)thumbnailWithMaximumSize:(CGSize)maximumSize scale:(CGFloat)scale;

/**
 * Append a string to the name of each field on the page.
 *
 * @param string The string to append to the name of each field on the page.
 *
 */
-(void)appendStringToAllFieldNames:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
