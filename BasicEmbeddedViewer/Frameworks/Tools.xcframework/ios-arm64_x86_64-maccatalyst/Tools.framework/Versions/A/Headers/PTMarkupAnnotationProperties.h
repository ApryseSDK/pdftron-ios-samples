//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFAnnotationProperties.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Properties of a markup annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(MarkupAnnotationProperties)
@interface PTMarkupAnnotationProperties : PTPDFAnnotationProperties

/**
 * Initializes a `PTMarkupAnnotationProperties` instance.
 *
 * @return An initialized `PTMarkupAnnotationProperties` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The constant opacity of the markup annotation.
 *
 * @note The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat opacity;

/**
 * The intent of the markup annotation.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *intent;

@end

NS_ASSUME_NONNULL_END
