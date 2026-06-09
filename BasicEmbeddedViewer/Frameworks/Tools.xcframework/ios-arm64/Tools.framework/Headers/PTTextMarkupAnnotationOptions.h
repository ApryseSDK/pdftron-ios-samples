//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object that contains options for text markup annotations.
 */
PT_OBJC_RUNTIME_NAME(TextMarkupAnnotationOptions)
@interface PTTextMarkupAnnotationOptions : PTAnnotationOptions

/**
 * Whether the annotated text is copied into the created annotation's contents. The default value is
 * `YES`.
 */
@property (nonatomic, assign) BOOL copiesAnnotatedTextToContents;

@end

NS_ASSUME_NONNULL_END
