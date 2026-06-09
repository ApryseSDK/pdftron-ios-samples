//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotEditTool.h>
#import <Tools/PTMagnifierView.h>

#import <PDFNet/PDFNet.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPolylineEditTool;
@class PTMagnifierView;

/**
 * The `PTPolylineEditTool` is used to edit polyline, polygon, and cloudy annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PolylineEditTool)
@interface PTPolylineEditTool : PTAnnotEditTool

/**
 * Draw the measurement label for an existing perimeter/area annotation.
 */
+ (void)addMeasurementLabelForAnnotation:(nullable PTAnnot *)annotation onPdfViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl;

/**
 * Draw the measurement label for a perimeter/area annotation.
 *
 * @param newAnnot Whether the annotation is newly created or existing.
 */
+ (void)addMeasurementLabelForAnnotation:(nullable PTAnnot *)annotation onPdfViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl newAnnot:(BOOL)newAnnot;

/**
 * The vertices of the annotation, expressed in page space.
 */
@property (nonatomic, copy, nullable) NSArray<PTPDFPoint *> *vertices;

/**
 * The index of the selected vertex in `vertices`. When no vertex is selected, the value
 * of this property is `NSNotFound`.
 */
@property (nonatomic, assign) NSUInteger selectedVertexIndex;

/**
 * The starting location of the touch on the annotation, in screen space.
 */
@property (nonatomic, assign) CGPoint touchStartPoint;

/**
 * The ending location of the touch on the annotation, in screen space.
 */
@property (nonatomic, assign) CGPoint touchEndPoint;

/**
 * The magnifier loupe view shown for measurement annotations.
 */
@property (nonatomic, readonly, strong, nullable) PTMagnifierView *loupe;

/**
 * Whether the selection border is displayed around the annotation.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isSelectionBorderHidden) BOOL selectionBorderHidden;

@end

NS_ASSUME_NONNULL_END
