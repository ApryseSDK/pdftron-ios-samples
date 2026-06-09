//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The vertical alignment for a paragraph.
 */
typedef NS_ENUM(NSUInteger, PTRichTextParagraphVerticalAlignment) {
    /**
     * The paragraph is aligned to the top of its container.
     */
    PTRichTextParagraphVerticalAlignmentTop,
    
    /**
     * The paragraph is aligned to the middle or center of its container.
     */
    PTRichTextParagraphVerticalAlignmentMiddle,
    
    /**
     * The paragraph is aligned to the bottom of its container.
     */
    PTRichTextParagraphVerticalAlignmentBottom,
};

/**
 * The attributed string key for an `NSNumber` object containing a `PTRichTextParagraphVerticalAlignment` enum value.
 *
 * @note The default paragraph vertical alignment is `PTRichTextParagraphVerticalAlignmentTop` if unspecified.
 */
PT_EXTERN const NSAttributedStringKey PTRichTextParagraphVerticalAlignmentAttributeName NS_SWIFT_NAME(paragraphVerticalAlignment);

NS_ASSUME_NONNULL_END
