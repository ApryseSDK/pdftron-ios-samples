//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFAnnotationBorderAppearance.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PTPDFAnnotationBorderAppearance;

/**
 * Properties of a PDF annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFAnnotationProperties)
@interface PTPDFAnnotationProperties : NSObject

/**
 * Initializes a newly created `PTPDFAnnotationProperties` instance.
 *
 * @return An initialized `PTPDFAnnotationProperties` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The annotation's color, interpreted differently for certain annotation types.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *color;

/**
 * The appearance of the annotation's border.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) id<PTPDFAnnotationBorderAppearance> border;

@end

@interface PTPDFAnnotationProperties (Creation)

/**
 * Creates and configures a `PTPDFAnnotationProperties` (subclass) instance for the specified PDF
 * annotation.
 *
 * @param annotation The PDF annotation.
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return A configured `PTPDFAnnotationProperties` instance, or `nil` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
+ (nullable instancetype)propertiesForAnnotation:(PTAnnot *)annotation
                                       withError:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

@end

@interface PTPDFAnnotationProperties (SubclassingHooks)

/**
 * Configures the annotation properties from the specified PDF annotation.
 *
 * @param annotation The PDF annotation.
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotation properties were configured, or `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)configureWithAnnotation:(PTAnnot *)annotation
                          error:(out NSError * _Nullable __autoreleasing * _Nullable)outError NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
