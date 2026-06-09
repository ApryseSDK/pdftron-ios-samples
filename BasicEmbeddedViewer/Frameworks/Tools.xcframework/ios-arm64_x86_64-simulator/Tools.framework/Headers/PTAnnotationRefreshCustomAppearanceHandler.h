//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationRefreshAppearanceHandler.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An abstract base class for annotation refresh appearance handlers that generate a custom PDF
 * appearance for annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationRefreshCustomAppearanceHandler)
@interface PTAnnotationRefreshCustomAppearanceHandler : NSObject <PTAnnotationRefreshAppearanceHandler>

/**
 * Initializes a `PTAnnotationRefreshCustomAppearanceHandler` instance.
 *
 * @return An initialized `PTAnnotationRefreshCustomAppearanceHandler` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

/**
 * Override-points for subclasses.
 */
@interface PTAnnotationRefreshCustomAppearanceHandler (SubclassingHooks)

/**
 * Generates a custom PDF appearance for the specified annotation.
 *
 * @param annotation The PDF annotation for which to generate an appearance.
 *
 * @param refreshOptions The refresh options to use, or `nil`
 *
 * @param userInfo A dictionary containing additional information, or `nil`
 *
 * @return The generated custom PDF appearance for the annotation, or `nil` if an appearance could
 * not be created.
 *
 * @note The default implementation of this method returns `nil`.
 */
- (nullable PTObj *)generateCustomAppearanceForAnnotation:(PTAnnot *)annotation
                                              withOptions:(nullable PTRefreshOptions *)refreshOptions
                                                 userInfo:(nullable NSDictionary<PTAnnotationRefreshAppearanceUserInfoKey, id> *)userInfo;

@end

NS_ASSUME_NONNULL_END
