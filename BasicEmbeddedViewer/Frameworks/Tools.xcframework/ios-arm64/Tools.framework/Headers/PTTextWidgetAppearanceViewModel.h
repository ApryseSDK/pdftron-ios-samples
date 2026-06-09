//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationAppearanceViewModel.h>
#import <Tools/PTRichTextAppearanceViewModel.h>
#import <Tools/PTTextWidgetAnnotationProperties.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextWidgetAnnotationProperties;

/**
 * A view model representing the appearance of a text widget annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextWidgetAppearanceViewModel)
@interface PTTextWidgetAppearanceViewModel : PTAnnotationAppearanceViewModel<PTTextWidget *, PTTextWidgetAnnotationProperties *> <PTRichTextAppearanceViewModel>

/**
 * Initializes a newly created `PTTextWidgetAppearanceViewModel` instance.
 *
 * @return an initialized `PTTextWidgetAppearanceViewModel` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Annotation properties

/**
 * The properties for the represented text widget annotation.
 *
 * @see `PTAnnotationAppearanceViewModel.properties`
 */
@property (nonatomic, readonly, strong) PTTextWidgetAnnotationProperties *properties;

#pragma mark - Attributes

/**
 * @note The default value of this property is `CGSizeZero`.
 */
@property (nonatomic, assign) CGSize size;

/**
 * The amount that the text is inset from the edges of the content.
 *
 * @note The default value of this property is `(5, 5, 5, 5)`.
 */
@property (nonatomic, assign) UIEdgeInsets textContentInset;

#pragma mark - Text contents

/**
 * The plain (unattributed) text.
 *
 * @note The default value of this property is `nil`.
 *
 * @see `PTTextWidgetAppearanceViewModel.richContents`
 */
@property (nonatomic, copy, nullable) NSString *contents;

/**
 * The rich (attributed) text.
 *
 * @note The default value of this property is `nil`.
 *
 * @see `PTTextWidgetAppearanceViewModel.contents`
 */
@property (nonatomic, copy, nullable) NSString *richContents;

/**
 * The attributed text contents of the annotation.
 *
 * @note The default value of this property is `nil`.
 *
 * @see `PTTextWidgetAppearanceViewModel.richContents`
 */
@property (nonatomic, copy, nullable) NSAttributedString *attributedContents NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
