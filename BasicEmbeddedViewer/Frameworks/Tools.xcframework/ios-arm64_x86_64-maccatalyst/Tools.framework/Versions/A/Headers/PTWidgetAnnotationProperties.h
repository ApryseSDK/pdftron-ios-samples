//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFAnnotationProperties.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Properties of a widget annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(WidgetAnnotationProperties)
@interface PTWidgetAnnotationProperties : PTPDFAnnotationProperties

/**
 * Initializes a newly created `PTWidgetAnnotationProperties` instance.
 *
 * @return An initialized `PTWidgetAnnotationProperties` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The border color of the widget.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *borderColor;

/**
 * The width of the border.
 *
 * @note The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 * The background color of the widget.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *backgroundColor;

@end

NS_ASSUME_NONNULL_END
