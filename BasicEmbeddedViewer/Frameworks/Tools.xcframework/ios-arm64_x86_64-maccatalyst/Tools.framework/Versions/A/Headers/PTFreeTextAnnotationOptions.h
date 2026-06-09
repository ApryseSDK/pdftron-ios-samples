//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationOptions.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFreeTextAnnotationOptions;

/**
* An object that contains options for FreeText annotations.
*/
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextAnnotationOptions)
@interface PTFreeTextAnnotationOptions : PTAnnotationOptions

/**
 * Whether empty free text annotations with no text are deleted after editing.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL deleteEmptyAnnotation;

/**
 * The default font to use for new FreeText annotations. This
 * string must be specified using the PostscriptFile name, e.g.
 * "CourierNewPS-BoldItalicMT". These names can be retrieved as
 * follows:
 *
 * ```NSArray *fontFamilyNames = [UIFont familyNames];
 for (NSString *familyName in fontFamilyNames) {
         NSLog(@"Font Family Name = %@", familyName);
         NSArray *names = [UIFont fontNamesForFamilyName:familyName];
         NSLog(@"   Font Names = %@", names);
 }```
 *
 */
@property (nonatomic, copy) NSString* defaultFontName PT_UNAVAILABLE_MSG("Set default free text font with +[PTColorDefaults setDefaultFreeTextFontName:]");

/**
 * Whether the `PTFreeTextInputAccessoryView` is enabled when creating or editing free text annotations.
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isInputAccessoryViewEnabled) BOOL inputAccessoryViewEnabled;

/**
 * Whether rich text contents can be created and editing in free text annotations.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isRichContentEnabled) BOOL richContentEnabled;

/**
 * Whether the free text annotation can be rotated.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=canRotate) BOOL canRotate;

/**
 * The list of tools classes for which to enable Apple Pencil Scribble input to free text annotations.
 *
 * The default value of this property is an array containing the `PTFreeTextCreate` class.
 */
@property (nonatomic, copy, nullable) NSArray<Class> *toolClassesForScribbleInput;

@end

NS_ASSUME_NONNULL_END
