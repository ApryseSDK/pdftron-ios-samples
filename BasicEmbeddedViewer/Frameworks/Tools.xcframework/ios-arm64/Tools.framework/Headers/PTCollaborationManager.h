//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTBaseCollaborationManager.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTBaseCollaborationManager;
@class PTCollaborationManager;

/**
 * The object that is responsible for sending local changes to the remote server, and for receiving
 * remote changes from the server.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(CollaborationManager)
@interface PTCollaborationManager : PTBaseCollaborationManager

/**
 * Initializes a newly created `PTCollaborationManager` instance.
 *
 * @param toolManager The tool manager used by this object to register for annotation change events
 * that occur locally, and to push back changes that happen remotely (via its annotManager).
 *
 * @param userId The identifier for the current collaboration user.
 *
 * @param mode The mode to use for the `PTExternalAnnotManager`.
 *
 * @return an initialized `PTCollaborationManager` instance.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager userId:(NSString *)userId mode:(PTExternalAnnotManagerMode)mode NS_DESIGNATED_INITIALIZER;

/**
 * The mode used by the `PTExternalAnnotManager`.
 */
@property (nonatomic, readonly, assign) PTExternalAnnotManagerMode mode;

@end

NS_ASSUME_NONNULL_END
