//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationAppearanceViewModel.h>
#import <Tools/PTFreeTextAnnotationProperties.h>
#import <Tools/PTRichTextAppearanceViewModel.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFreeTextAnnotationProperties;

/**
 * A view model representing the appearance of a free text annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextAppearanceViewModel)
@interface PTFreeTextAppearanceViewModel : PTAnnotationAppearanceViewModel<PTFreeText *, PTFreeTextAnnotationProperties *> <PTRichTextAppearanceViewModel>

/**
 * Initializes a `PTFreeTextAppearanceViewModel` instance.
 *
 * @return An initialized `PTFreeTextAppearanceViewModel` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Free text annotation properties

/**
 * The properties for the represented free text annotation.
 *
 * @see `PTAnnotationAppearanceViewModel.properties`
 */
@property (nonatomic, readonly, strong) PTFreeTextAnnotationProperties *properties;

#pragma mark - Contents

/**
 * The unattributed text contents of the annotation, as a string.
 *
 * @note The default value of this property is `nil`.
 *
 * @see `PTFreeTextAppearanceViewModel.richContents`
 */
@property (nonatomic, copy, nullable) NSString *contents;

/**
 * The rich contents of the annotation, as a string.
 *
 * @note The default value of this property is `nil`.
 *
 * @see `PTFreeTextAppearanceViewModel.contents`
 * @see `PTFreeTextAppearanceViewModel.attributedContents`
 */
@property (nonatomic, copy, nullable) NSString *richContents;

/**
 * The attributed text contents of the annotation.
 *
 * @note The default value of this property is `nil`.
 *
 * @see `PTFreeTextAppearanceViewModel.richContents`
 */
@property (nonatomic, copy, nullable) NSAttributedString *attributedContents;

#pragma mark - Other attributes

/**
 * The amount that the text is inset from the edges of the content.
 *
 * @note The default value of this property is `{2, 2, 2, 2}`.
 */
@property (nonatomic, assign) UIEdgeInsets textContentInset;

@end

NS_ASSUME_NONNULL_END
