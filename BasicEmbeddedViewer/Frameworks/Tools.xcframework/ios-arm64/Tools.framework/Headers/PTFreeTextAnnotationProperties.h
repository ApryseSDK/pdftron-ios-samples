//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTMarkupAnnotationProperties.h>
#import <Tools/PTRichTextAnnotationProperties.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Properties of a free text annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextAnnotationProperties)
@interface PTFreeTextAnnotationProperties : PTMarkupAnnotationProperties <PTRichTextAnnotationProperties>

/**
 * Initializes a `PTFreeTextAnnotationProperties` instance.
 *
 * @return An initialized `PTFreeTextAnnotationProperties` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The default color of text.
 *
 * @note The default value of this property is a black color.
 */
@property (nonatomic, strong, nullable) UIColor *textColor;

/**
 * The form of quadding or justification used in displaying text.
 *
 * @note The default value of this property is `e_ptleft_justified`.
 */
@property (nonatomic, assign) PTTextJustification textJustification;

/**
 * The border color of the free text annotation.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *borderColor;

#pragma mark - Font

/**
 * The default font for the text.
 *
 * @note The default value of this property is a 12pt Helvetica font.
 *
 * @see `PTFreeTextAnnotationProperties.fontSize`
 */
@property (nonatomic, strong, null_resettable) UIFont *font;

/**
 * The default font size in points for the text.
 *
 * @note The default value of this property is `12`.
 *
 * @see `PTFreeTextAnnotationProperties.font`
 */
@property (nonatomic, assign) CGFloat fontSize;

@end

NS_ASSUME_NONNULL_END
