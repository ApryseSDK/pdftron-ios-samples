//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Properties of annotations that support rich text content.
 */
PT_OBJC_RUNTIME_NAME(RichTextAnnotationProperties)
@protocol PTRichTextAnnotationProperties <NSObject>
@required

/**
 * The default color of text.
 */
@property (nonatomic, strong, nullable) UIColor *textColor;

/**
 * The default font for the text.
 */
@property (nonatomic, strong, nullable) UIFont *font;

/**
 * The default font size in points for the text.
 */
@property (nonatomic, assign) CGFloat fontSize;

@end

NS_ASSUME_NONNULL_END
