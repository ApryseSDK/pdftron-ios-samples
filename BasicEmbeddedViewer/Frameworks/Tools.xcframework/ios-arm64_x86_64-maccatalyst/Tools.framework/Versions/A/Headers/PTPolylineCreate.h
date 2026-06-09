//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTCreateToolBase.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Creates polyline annotations.
 */
PT_OBJC_RUNTIME_NAME(PolylineCreate)
@interface PTPolylineCreate : PTCreateToolBase

/**
 * The vertices of the shape, expressed in screen space.
 */
@property (nonatomic, copy, nullable) NSArray<NSValue *> *vertices;

/**
 * Commits the current appearance to the document.
 */
- (void)commitAnnotation;

@end

NS_ASSUME_NONNULL_END
