//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFAnnotationBorderAppearance.h>

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A representation of the border around a PDF annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFAnnotationBorder)
@interface PTPDFAnnotationBorder : NSObject <PTPDFAnnotationBorderAppearance>

/**
 * Initializes a `PTPDFAnnotationBorder` instance.
 *
 * @return An initialized `PTPDFAnnotationBorder` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Properties

/**
 * The width of the border.
 *
 * @note The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat width;

/**
 * The horizontal corner radius of the border.
 *
 * @note The default value of this property is `0.0`.
 */
@property (nonatomic, assign) CGFloat horizontalCornerRadius;

/**
 * The vertical corner radius of the border.
 *
 * @note The default value of this property is `0.0`.
 */
@property (nonatomic, assign) CGFloat verticalCornerRadius;

/**
 * The alternating pattern of dashes and gaps used in drawing the border.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *dashPattern;

#pragma mark - Equality

/**
 * Compares this `PTPDFAnnotationBorder` instance to another instance for equality.
 *
 * @param annotationBorder The other instance to compare against `self`.
 *
 * @return `YES` if the two instances are equal, `NO` otherwise.
 */
- (BOOL)isEqualToAnnotationBorder:(PTPDFAnnotationBorder *)annotationBorder;

@end 

NS_ASSUME_NONNULL_END
