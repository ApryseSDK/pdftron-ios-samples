//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationManager.h>
#import <Tools/PTCollaborationAnnotation.h>
#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnot;
@class PTAnnotationManager;
@class PTBaseCollaborationManager;
@class PTCollaborationAnnotation;
@class PTToolManager;

@protocol PTCollaborationServerCommunication;

/**
 * The `PTCollaborationServer` protocol allows the adopting class to be used for communicating
 * annotation changes that occur on a shared document.
 */
PT_OBJC_RUNTIME_NAME(CollaborationServerCommunication)
@protocol PTCollaborationServerCommunication <NSObject>
@required

/**
 * The `PTBaseCollaborationManager` that registered this service implementation in
 * `-[PTBaseCollaborationManager registerServerCommunicationComponent:]`.
 */
@property (nonatomic, weak, nullable) PTBaseCollaborationManager *collaborationManager;

/**
 * The implementation of this method sends the local annotation change to the server.
 * This method is called by `PTBaseCollaborationManager`.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)localAnnotationAdded:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * The implementation of this method sends the local annotation change to the server.
 * This method is called by `PTBaseCollaborationManager`.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)localAnnotationModified:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * The implementation of this method sends the local annotation change to the server.
 * This method is called by `PTBaseCollaborationManager`.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)localAnnotationRemoved:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * This method is called by the local document viewer when it is ready for remote annotations.
 *
 * The implemention of this method should apply all remotely stored annotations to the local document.
 */
- (void)documentLoaded;

/**
 * The unqiue ID that represents the current user.
 */
@property (nonatomic, readonly, copy, nullable) NSString *userID;

/**
 * The unqiue ID that represents the current document.
 */
@property (nonatomic, readonly, copy, nullable) NSString *documentID;

@end

/**
 * The `PTBaseCollaborationManager` is an abstract base class that is responsible for sending local
 * annotation changes to a remote server, and for receiving remote changes from the server.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(BaseCollaborationManager)
@interface PTBaseCollaborationManager : NSObject

/**
 * Initializes a newly created `PTBaseCollaborationManager` instance.
 *
 * @param toolManager The tool manager that this object uses to register for annotation change events
 * that occur locally, and to push back changes that happen remotely (via its annotManager).
 *
 * @param userId The identifier for the current collaboration user.
 *
 * @return an initialized `PTBaseCollaborationManager` instance.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager userId:(NSString *)userId NS_DESIGNATED_INITIALIZER;

/**
 * The tool manager used by this object to receive local annotation change events.
 */
@property (nonatomic, readonly, strong) PTToolManager *toolManager;

/**
 * The annotation manager used by this object.
 */
@property (nonatomic, strong) PTAnnotationManager *annotationManager;

#pragma mark - Initial annotations

/**
 * Call this method to load an initial remote annotation. This should generally be done immediately
 * after the document itself is loaded.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)loadInitialRemoteAnnotation:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * Call this method to load a list of initial remote annotations. This should generally be done immediately
 * after the document itself is loaded.
 *
 * @param collaborationAnnotations an array of objects representing the collaboration annotations.
 */
- (void)loadInitialRemoteAnnotations:(NSArray<PTCollaborationAnnotation *> *)collaborationAnnotations;

#pragma mark - Importing XFDF

/**
 * Imports the annotations specified by the XFDF string. The imported annotations are considered to
 * be part of the initial set of annotations.
 *
 * @param xfdfString the XFDF string to import
 */
- (void)importAnnotationsWithXFDFString:(NSString *)xfdfString;

/**
 * Imports the annotations specified by the XFDF string.
 *
 * @param xfdfString the XFDF string to import
 *
 * @param isInitial whether the imported annotations should be considered to be part of the initial
 * set of annotations.
 */
- (void)importAnnotationsWithXFDFString:(NSString *)xfdfString isInitial:(BOOL)isInitial;

/**
 * Imports the annotations specified by the XFDF command string. The command string can contain <add>,
 * <modify>, and <delete> tags. The imported annotations are considered to be part of the initial
 * set of annotations.
 *
 * @param xfdfCommand the XFDF command string to import
 */
- (void)importAnnotationsWithXFDFCommand:(NSString *)xfdfCommand;

/**
 * Imports the annotations specified by the XFDF command string. The command string can contain <add>,
 * <modify>, and <delete> tags.
 *
 * @param xfdfCommand the XFDF command string to import
 *
 * @param isInitial whether the imported annotations should be considered to be part of the initial
 * set of annotations.
 */
- (void)importAnnotationsWithXFDFCommand:(NSString *)xfdfCommand isInitial:(BOOL)isInitial;

#pragma mark - Remote annotation events

/**
 * Call this method to communicate a change that occured remotely that needs to be reflected on the device.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)remoteAnnotationAdded:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * Call this method to communicate a change that occured remotely that needs to be reflected on the device.
 *
 * @param collaborationAnnotations an array of objects representing the collaboration annotations.
 */
- (void)remoteAnnotationsAdded:(NSArray<PTCollaborationAnnotation *> *)collaborationAnnotations;

/**
 * Call this method to communicate a change that occured remotely that needs to be reflected on the device.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)remoteAnnotationModified:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * Call this method to communicate a change that occured remotely that needs to be reflected on the device.
 *
 * @param collaborationAnnotations an array of objects representing the collaboration annotations.
 */
- (void)remoteAnnotationsModified:(NSArray<PTCollaborationAnnotation *> *)collaborationAnnotations;

/**
 * Call this method to communicate a change that occured remotely that needs to be reflected on the device.
 *
 * @param collaborationAnnotation an object representing the collaboration annotation.
 */
- (void)remoteAnnotationRemoved:(PTCollaborationAnnotation *)collaborationAnnotation;

/**
 * Call this method to communicate a change that occured remotely that needs to be reflected on the device.
 *
 * @param collaborationAnnotations an array of objects representing the collaboration annotations.
 */
- (void)remoteAnnotationsRemoved:(NSArray<PTCollaborationAnnotation *> *)collaborationAnnotations;

/**
 * Establishes a "connection" between the collaboration manager, that sends local changes to and
 * receives remote changes from the communicationComponent.
 *
 * @param communicationComponent The object that the collaboration manager uses to inform the server
 * that a local change occured, and likewise is used by the `communicationComponent` to inform the
 * device that a remote change occured.
 */
- (void)registerServerCommunicationComponent:(id<PTCollaborationServerCommunication>)communicationComponent;

/**
 * De-registers the service
 */
-(void)deRegisterServerCommunicationComponent;


- (instancetype)init NS_UNAVAILABLE;

@end

/**
 * The methods in this category are designed to be overridden by subclasses of the
 * `PTBaseCollaborationManager` class. Overriding these methods is optional, except where noted.
 */
@interface PTBaseCollaborationManager (PTSubclassing)

#pragma mark Local annotation changes

/**
 * Called when a local annotation has been added. Subclasses can override this method to perform
 * additional actions such as ensuring that the result returned from `-GetLastXFDFCommand` reflects
 * this annotation change.
 *
 * @param annotation the annotation that was added
 *
 * @param pageNumber the page number of the annotation
 */
- (void)didAddlocalAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber NS_REQUIRES_SUPER;

/**
 * Called when a local annotation will be modified. Subclasses can override this method to perform
 * additional actions such as ensuring that the result returned from `-GetLastXFDFCommand` reflects
 * this annotation change.
 *
 * @param annotation the annotation that will be modified
 *
 * @param pageNumber the page number of the annotation
 */
- (void)willModifyLocalAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber NS_REQUIRES_SUPER;

/**
 * Called when a local annotation has been modified. Subclasses can override this method to perform
 * additional actions such as ensuring that the result returned from `-GetLastXFDFCommand` reflects
 * this annotation change.
 *
 * @param annotation the annotation that was modified
 *
 * @param pageNumber the page number of the annotation
 */
- (void)didModifyLocalAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber NS_REQUIRES_SUPER;

/**
 * Called when a local annotation will be removed from the document. Subclasses can override this
 * method to perform additional actions such as ensuring that the result returned from
 * `-GetLastXFDFCommand` reflects this annotation change.
 *
 * @param annotation the annotation that will be removed from the document
 *
 * @param pageNumber the page number of the annotation
 */
- (void)willRemoveLocalAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber NS_REQUIRES_SUPER;

/**
 * Called when a local annotation has been removed. Subclasses can override this method to perform
 * additional actions such as ensuring that the result returned from `-GetLastXFDFCommand` reflects
 * this annotation change.
 *
 * @param annotation the annotation that was removed from the document
 *
 * @param pageNumber the page number of the annotation
 */
- (void)didRemoveLocalAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber NS_REQUIRES_SUPER;

#pragma mark XFDF actions

/**
 * Retrieve the last XFDF command string produced by the last local annotation change (annotation
 * add, modify, or remove).
 *
 * @note Subclasses *must* override this method and return an appropriate result.
 */
- (nullable NSString *)GetLastXFDFCommand;

/**
 * Retrieve the last XFDF command string produced by the last local annotation change (annotation
 * add, modify, or remove).
 *
 * @deprecated
 * @see `-GetLastXFDFCommand`
 */
- (nullable NSString *)GetLastXFDF PT_DEPRECATED_MSG(8.1.0, "Please use the GetLastXFDFCommand method instead");

/**
 * Merges the given XFDF string into the document. For the purposes of annotation replies/
 * comments, the merged annotations are all considered to be marked as "read".
 *
 * @param xfdfString the XFDF string to be merged into the document.
 *
 * @note Subclasses *must* override this method to provide an implementation. Calling `super` is not
 * required.
 */
- (void)mergeInitialXFDFString:(NSString *)xfdfString;

/**
 * Merges the given XFDF string into the document.
 *
 * @param xfdfString the XFDF string to be merged into the document.
 *
 * @note Subclasses *must* override this method to provide an implementation. Calling `super` is not
 * required.
 */
- (void)mergeXFDFString:(NSString *)xfdfString;

/**
 * Merges the given XFDF command string into the document. For the purposes of annotation replies/
 * comments, the merged annotations are all considered to be marked as "read".
 *
 * @param xfdfCommand the XFDF command string to be merged into the document
 *
 * @note Subclasses *must* override this method to provide an implementation. Calling `super` is not
 * required.
 */
- (void)mergeInitialXFDFCommand:(NSString *)xfdfCommand;

/**
 * Merges the given XFDF command string into the document.
 *
 * @param xfdfCommand the XFDF command string to be merged into the document
 *
 * @note Subclasses *must* override this method to provide an implementation. Calling `super` is not
 * required.
 */
- (void)mergeXFDFCommand:(NSString *)xfdfCommand;

/**
 * Exports all local and remote annotations as an XFDF string.
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return an XFDF string containing all local and remote annotations, or `nil` if an error occurred
 *
 * @note Subclasses *must* override this method to provide an implementation. Calling `super` is not
 * required.
 */
- (nullable NSString *)exportXFDFStringWithError:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
