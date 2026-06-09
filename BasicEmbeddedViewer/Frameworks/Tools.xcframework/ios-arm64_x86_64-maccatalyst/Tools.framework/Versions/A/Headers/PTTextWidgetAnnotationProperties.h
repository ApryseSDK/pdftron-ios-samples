//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTRichTextAnnotationProperties.h>
#import <Tools/PTWidgetAnnotationProperties.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Properties of a text widget annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextWidgetAnnotationProperties)
@interface PTTextWidgetAnnotationProperties : PTWidgetAnnotationProperties <PTRichTextAnnotationProperties>

/**
 * Initializes a newly created `PTTextWidgetAnnotationProperties` instance.
 *
 * @return An initialized `PTTextWidgetAnnotationProperties` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The default color of text.
 *
 * @note The default value of this property is `UIColor.blackColor`.
 */
@property (nonatomic, strong, nullable) UIColor *textColor;

/**
 * Whether multiple lines of text are permitted.
 *
 * @note The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isMultilineEnabled) BOOL multilineEnabled;

/**
 * Whether spelling should be checked.
 *
 * @note The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isSpellCheckEnabled) BOOL spellCheckEnabled;

/**
 * Whether scrolling of the text is allowed.
 *
 * Text is scrolled horizontally for single-line mode and vertically for multiple-line mode (as
 * determined by `PTTextWidgetAnnotationProperties.multiline`).
 *
 * @note The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isScrollEnabled) BOOL scrollEnabled;

/**
 * Whether rich text contents are allowed.
 *
 * @note The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isRichTextEnabled) BOOL richTextEnabled;

/**
 * The maximum text length allowed, or `-1` if there is no limit.
 *
 * @note The default value of this property is `-1` (no limit).
 */
@property (nonatomic, assign) NSInteger maximumLength;

/**
 * The form of quadding or justification used in displaying text.
 *
 * @note The default value of this property is `e_ptleft_justified`.
 */
@property (nonatomic, assign) PTTextJustification textJustification;

#pragma mark - Font

/**
 * The default font for the text.
 *
 * @note The default value of this property is a 12pt Helvetica font.
 *
 * @see `PTTextWidgetAnnotationProperties.fontSize`
 */
@property (nonatomic, strong, nullable) UIFont *font;

/**
 * The default font size in points for the text.
 *
 * @note The default value of this property is 12.
 *
 * @see `PTTextWidgetAnnotationProperties.font`
 */
@property (nonatomic, assign) CGFloat fontSize;

@end

NS_ASSUME_NONNULL_END
