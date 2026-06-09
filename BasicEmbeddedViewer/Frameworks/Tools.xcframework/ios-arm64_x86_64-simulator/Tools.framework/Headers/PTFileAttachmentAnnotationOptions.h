//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationOptions.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFileAttachmentAnnotationOptions;

/**
 * Options for file attachment annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FileAttachmentAnnotationOptions)
@interface PTFileAttachmentAnnotationOptions : PTAnnotationOptions

/**
 * Whether the saving of file attachment annotations to disk is allowed.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isSavingEnabled) BOOL savingEnabled;

@end

NS_ASSUME_NONNULL_END
