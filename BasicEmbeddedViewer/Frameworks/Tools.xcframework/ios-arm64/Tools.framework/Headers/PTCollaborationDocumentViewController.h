//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTBaseCollaborationManager.h>
#import <Tools/PTDocumentViewController.h>
#import <Tools/PTAnnotationReplyViewController.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A subclass of the `PTDocumentViewController` that will synchronize annotations between the device and
 * central server.
 *
 * The implementation is minimal:
 *
 * 1. It connects the `PTCollaborationDocumentViewController.toolManager.collaborationManager` and the
 * `PTCollaborationServerCommunication service`.
 *
 * 2. It does not allow the user to select annotations where the author of the annotation does not match the user
 * that is logged in to the `PTCollaborationServerCommunication service`.
 */
PT_EXTERN
PT_DEPRECATED_MSG(8.0.2, "Use the PTCollaborationDocumentController class instead")
PT_OBJC_RUNTIME_NAME(CollaborationDocumentViewController)
@interface PTCollaborationDocumentViewController : PTDocumentViewController

/**
 * The object that communicates with the server.
 */
@property (nonatomic, strong, readonly) id<PTCollaborationServerCommunication> service;

/**
 * Creates a new `PTCollaborationDocumentViewController` and sets its `service` property to that
 * provided in this initializer.
 */
- (instancetype)initWithCollaborationService:(id<PTCollaborationServerCommunication>)service NS_DESIGNATED_INITIALIZER;

#pragma mark - View controllers

/**
 * The `PTAnnotationReplyViewController` shown by this view controller for viewing annotation replies.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnotationReplyViewController *collaborationReplyViewController;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
