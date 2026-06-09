//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A representation of an annotation's state.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFAnnotationState)
@interface PTPDFAnnotationState : NSObject

/**
 * Initializes a `PTPDFAnnotationState` instance.
 *
 * @returns An initialized `PTPDFAnnotationState` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Creation

/**
 * Creates and configures a new `PTPDFAnnotationState` (subclass) instance for the given annotation.
 *
 * @param annotation The PDF annotation.
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return A configured `PTPDFAnnotationState` instance, or `nil` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
+ (nullable instancetype)stateForAnnotation:(PTAnnot *)annotation
                                  withError:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

#pragma mark - Geometry

/**
 * The location of the annotation, in PDF page coordinates.
 *
 * This property represents the annotation's bounding box, ie. the smallest upright rectangle that
 * encompasses its appearance.
 *
 * @note
 * The value of this property is defined in the coordinate space of the annotation's containing PDF page.
 */
@property (nonatomic, assign) CGRect rect;

/**
 * The rotation of the annotation, in radians, counterclockwise relative to the page.
 *
 * The annotation appearance's coordinate space is rotated by the angle specified by this property.
 */
@property (nonatomic, assign) CGFloat rotation;

/**
 * The bounds of the annotation, in the annotation appearance's coordinates.
 *
 * This rect is defined in the coordinate space of the annotation's appearance.
 */
@property (nonatomic, assign) CGRect bounds;

#pragma mark - Contents

/**
 * The (plain) text contents of the annotation.
 */
@property (nonatomic, copy, nullable) NSString *contents;

@end

@interface PTPDFAnnotationState (SubclassingHooks)

/**
 * @param annotation The PDF annotation.
 */
- (BOOL)configureWithAnnotation:(PTAnnot *)annotation
                          error:(out NSError * _Nullable __autoreleasing * _Nullable)outError NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
