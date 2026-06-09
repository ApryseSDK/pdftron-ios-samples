//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object that contains options for a type of annotation.
 */
PT_OBJC_RUNTIME_NAME(AnnotationOptions)
@interface PTAnnotationOptions : NSObject <NSCopying, NSCoding>

/**
 * Creates and returns an annotation options instance with the default values.
 *
 * @return An annotation options instance with the default values.
 */
+ (instancetype)options;

/**
 * Returns an initialized `PTAnnotationOptions` with the specified values.
 *
 * @param canCreate `YES` if the annotation type can be created, `NO` otherwise.
 *
 * @param canEdit `YES` if the annotation type can be edited, `NO` otherwise.
 *
 * @return An initialized `PTAnnotationOptions` with the specified values.
 */
- (instancetype)initWithCanCreate:(BOOL)canCreate canEdit:(BOOL)canEdit NS_DESIGNATED_INITIALIZER;

/**
 * Whether the annotation type can be created. The default value is `YES`.
 */
@property (nonatomic, assign) BOOL canCreate;

/**
 * Whether the annotation type can be edited. The default value is `YES`.
 */
@property (nonatomic, assign) BOOL canEdit;

/**
 * Compares the receiving annotation options instance to another instance.
 *
 * @param annotationOptions an other annotation options instance
 *
 * @return `YES` if the annotation options instance is equal to the receiving instance, otherwise `NO`
 */
- (BOOL)isEqualToAnnotationOptions:(PTAnnotationOptions *)annotationOptions;


- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
