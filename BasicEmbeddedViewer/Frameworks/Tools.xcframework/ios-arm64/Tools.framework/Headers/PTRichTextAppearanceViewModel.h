//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTRichTextAnnotationProperties.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_OBJC_RUNTIME_NAME(RichTextAppearanceViewModel)
@protocol PTRichTextAppearanceViewModel <NSObject>
@required

#pragma mark - Annotation properties

/**
 * The properties for the represented free text annotation.
 */
@property (nonatomic, readonly, strong) id<PTRichTextAnnotationProperties> properties;

#pragma mark - Contents

/**
 * The unattributed text contents of the annotation, as a string.
 *
 * @see `PTRichTextAppearanceViewModel.richContents`
 */
@property (nonatomic, copy, nullable) NSString *contents;

/**
 * The rich contents of the annotation, as a string.
 *
 * @see `PTRichTextAppearanceViewModel.contents`
 * @see `PTRichTextAppearanceViewModel.attributedContents`
 */
@property (nonatomic, copy, nullable) NSString *richContents;

/**
 * The attributed text contents of the annotation.
 *
 * @see `PTRichTextAppearanceViewModel.richContents`
 */
@property (nonatomic, copy, nullable) NSAttributedString *attributedContents;

#pragma mark - Other attributes

/**
 * The amount that the text is inset from the edges of the content.
 */
@property (nonatomic, assign) UIEdgeInsets textContentInset;

@end

NS_ASSUME_NONNULL_END
