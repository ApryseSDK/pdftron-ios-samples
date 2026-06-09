//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationViewControllerConfiguration;

/**
 * The configuration settings used by a `PTAnnotationViewController`.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationViewControllerConfiguration)
@interface PTAnnotationViewControllerConfiguration : NSObject <NSCopying>

/**
 * Initializes a newly created `PTAnnotationViewControllerConfiguration` instance.
 *
 * @return an initialized `PTAnnotationViewControllerConfiguration` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTAnnotationViewControllerConfiguration` instance with the specified
 * configuration. The properties from `configuration` are copied to this instance.
 *
 * @return an initialized `PTAnnotationViewControllerConfiguration` instance
 */
- (instancetype)initWithConfiguration:(PTAnnotationViewControllerConfiguration *)configuration NS_DESIGNATED_INITIALIZER;

#pragma mark - Properties

/**
 * Whether the type names of annotations are displayed.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL displayAnnotationTypes;

/**
 * Whether the authors of annotations are displayed.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL displayAnnotationAuthors;

@end

NS_ASSUME_NONNULL_END
