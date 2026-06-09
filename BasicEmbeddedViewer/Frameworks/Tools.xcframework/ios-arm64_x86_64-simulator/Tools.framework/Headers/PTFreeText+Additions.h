//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTRichTextStyleAttributes.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Additions to the `PTFreeText` class.
 */
@interface PTFreeText (Additions)

#pragma mark - Default style

/**
 * Returns the default style string.
 *
 * @return the default style string, or `nil` if the annotation does not have a default style.
 */
- (nullable NSString *)GetDefaultStyle;

/**
 * Sets the default style string.
 *
 * @param defaultStyle The default style string, or `nil` to clear the default style.
 */
- (void)SetDefaultStyle:(nullable NSString *)defaultStyle;

/**
 * Returns the name of the font specified in the default style of the annotation.
 *
 * @return the name of the font specified in the default style of the annotation
 *
 * @see `GetDefaultStyle`
 */
- (nullable NSString *)GetDefaultStyleFontName;

/**
 * Returns the color specified in the default style of the annotation.
 *
 * @return The color specified in the default style of the annotation, or `nil` if the default style
 * has no color.
 *
 * @see `GetDefaultStyle`
 */
- (nullable UIColor *)GetDefaultStyleColor;

#pragma mark - Rich contents

/**
 * Returns the rich contents of the free text annotation.
 *
 * @return The rich contents of the annotation as a string, or `nil` if the annotation does not have
 * its rich contents set.
 */
- (nullable NSString *)GetRichContents;

/**
 * Sets the rich contents for the free text annotation.
 *
 * @param richContents The rich contents for the annotation, or `nil` to clear the rich contents.
 */
- (void)SetRichContents:(nullable NSString *)richContents;

#pragma mark - Colors

/**
 * Determines whether the border color of the free text annotation is using a non-standard format.
 *
 * @return `YES` if the border color is using a non-standard format, `NO` otherwise.
 */
- (BOOL)HasNonStandardBorderColor;

#pragma mark - Attributed contents

- (NSAttributedString *)GetAttributedStringContents;

#pragma mark - Vertical alignment

/**
 * Returns the vertical alignment of text in the free text annotation, as specified in the annotation's
 * default style information.
 */
- (PTRichTextParagraphVerticalAlignment)GetDefaultStyleVerticalAlignment;

/**
 * Sets the vertical alignment of text in the free text annotation's default style.
 *
 * @param verticalAlignment The vertical alignment of text.
 */
- (void)SetDefaultStyleVerticalAlignment:(PTRichTextParagraphVerticalAlignment)verticalAlignment;

@end

PT_OBJC_CATEGORY_LINK(PTFreeText, Additions)

NS_ASSUME_NONNULL_END
