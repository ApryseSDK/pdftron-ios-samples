//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PTAnnot (Casting)

/**
 * Performs the logical equivalent of a type cast on the specified annotation, returning an instance
 * of this `PTAnnot` (sub)class if the annotation object can be represented by an instance of this
 * class.
 *
 * @param annotation the annotation to cast
 *
 * @return an instance of this class if the annotation can be cast; otherwise, `nil` is returned
 */
+ (nullable instancetype)castAnnotation:(PTAnnot *)annotation NS_WARN_UNUSED_RESULT;

@end

/**
 * Returns the most derived `PTAnnot` subclass for the specified annotation.
 *
 * @param annotation the annotation
 *
 * @return the most derived `PTAnnot` subclass for the specified annotation, or `nil` if the class
 * cannot be determined
 */
PT_EXTERN Class _Nullable PTAnnotClassForAnnot(PTAnnot *annotation);

/**
 * Returns the most derived `PTWidget` subclass for the specified widget annotation.
 *
 * @param widget the widget annotation
 *
 * @return the most derived `PTWidget` subclass for the specified widget annotation, of `nil` if the
 * class cannot be determined
 */
PT_EXTERN Class _Nullable PTWidgetClassForWidgetAnnot(PTWidget *widget);

NS_ASSUME_NONNULL_END
