//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTBaseCollaborationManager.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTBaseCollaborationManager;
@class PTBasicXFDFCollaborationManager;

/**
 * The object that is responsible for sending local changes to the remote server, and for receiving
 * remote changes from the server.
 *
 * The `PTBasicXFDFCollaborationManager` class operates by merging XFDF strings and/or XFDF command
 * strings into the `PTPDFDoc` of the associated `PTPDFViewCtrl` instance.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(BasicXFDFCollaborationManager)
@interface PTBasicXFDFCollaborationManager : PTBaseCollaborationManager

@end

NS_ASSUME_NONNULL_END
