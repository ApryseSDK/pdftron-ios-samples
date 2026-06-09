//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTCreateToolBase.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTLinkCreate;

/**
 * Creates link annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(LinkCreate)
@interface PTLinkCreate : PTCreateToolBase

/**
 * Presents a UI to edit the current link annot (`currentAnnotation`).
 */
- (void)editCurrentLinkAnnot;

@end

NS_ASSUME_NONNULL_END
