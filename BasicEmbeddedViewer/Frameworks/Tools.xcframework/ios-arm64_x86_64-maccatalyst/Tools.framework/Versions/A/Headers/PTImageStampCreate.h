//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTCreateToolBase.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Create image stamp annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(ImageStampCreate)
@interface PTImageStampCreate : PTCreateToolBase

/**
 * Stamp an image at a point in screen space.
 *
 * @param image The image to stamp on the document.
 * @param point The point in screen coordinates at which to stamp the image.
 */
-(void)stampImage:(UIImage*)image atPoint:(CGPoint)point;

/**
 * Show a resize picker and stamp an image
 * at a point in screen space with the chosen size.
 *
 * @param image The image to stamp on the document.
 * @param point The point in screen coordinates at which to stamp the image.
 */
- (void)showResizePickerForImage:(UIImage*)image atPoint:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
