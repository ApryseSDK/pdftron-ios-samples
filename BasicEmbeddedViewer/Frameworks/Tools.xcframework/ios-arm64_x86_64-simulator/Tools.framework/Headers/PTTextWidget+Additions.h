//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Additions to the `PTTextWidget` class.
 */
@interface PTTextWidget (Additions)

#pragma mark - Default style

/**
 * Returns the text field's default style string.
 *
 * @return The text field's default style string, or `nil` if there is no value.
 */
- (nullable NSString *)GetDefaultStyle;

/**
 * Sets the text field's default style string with the given value.
 *
 * @param defaultStyle The default style string, or `nil` to clear the value
 */
- (void)SetDefaultStyle:(nullable NSString *)defaultStyle;

/**
 * The text field's default style string.
 */
@property (nonatomic, copy, nullable, getter=GetDefaultStyle, setter=SetDefaultStyle:) NSString *defaultStyle;

#pragma mark - Rich text

/**
 * Returns the text widget's rich text value as a string.
 *
 * @return The widget's rich text value, or `nil` if there is no value
 */
- (nullable NSString *)GetRichText;

/**
 * Sets the text widget's rich text value with the given string.
 *
 * @param richText The rich text string, or `nil` to clear the value
 */
- (void)SetRichText:(nullable NSString *)richText;

/**
 * The text widget's rich text value as a string.
 */
@property (nonatomic, copy, nullable, getter=GetRichText, setter=SetRichText:) NSString *richText;

@end

NS_ASSUME_NONNULL_END
