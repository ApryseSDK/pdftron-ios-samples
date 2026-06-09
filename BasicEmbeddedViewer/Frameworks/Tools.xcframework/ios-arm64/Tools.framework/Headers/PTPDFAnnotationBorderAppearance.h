//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Properties common to annotation border appearances.
 */
PT_OBJC_RUNTIME_NAME(PDFAnnotationBorderAppearance)
@protocol PTPDFAnnotationBorderAppearance <NSObject>
@required

/**
 * The width of the border.
 */
@property (nonatomic, assign) CGFloat width;

/**
 * The alternating pattern of dashes and gaps used in drawing the border.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *dashPattern;

@end

NS_ASSUME_NONNULL_END
