//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationModel.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTPDFAnnotationChange.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTUndoRedoManager.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationManager;
@class PTPDFAnnotationChange;
@class PTPDFViewCtrl;
@class PTToolManager;
@class PTUndoRedoManager;

/**
 * Annotation edit-modes control whether the current annotation author specified in the
 * `PTAnnotationManager.annotationAuthorIdentifier` property of a `PTAnnotationManager` instance
 * is able to edit annotations created by other authors.
 */
typedef NS_ENUM(NSUInteger, PTAnnotationEditMode) {
    /**
     * Annotations can only be edited by their author.
     */
    PTAnnotationModeEditOwn,
    /**
     * All annotations can be edited regardless of their author.
     */
    PTAnnotationModeEditAll,
} NS_SWIFT_NAME(PTAnnotationManager.AnnotationEditMode);

/**
 * Instances of the `PTAnnotationManager` class manage the annotations in a `PTPDFViewCtrl` and
 * maintain annotation model objects that correspond to the PDF annotations.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationManager)
@interface PTAnnotationManager : NSObject <PTOverridable>

/**
 * Initializes a newly created `PTAnnotationManager` with the given `PTPDFViewCtrl` instance.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` that this annotation manager will coordinate with.
 *
 * @return an initialized `PTAnnotationManager` instance
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTAnnotationManager` with the given `PTToolManager` instance.
 *
 * @param toolManager The `PTToolManager` that this annotation manager will coordinate with.
 *
 * @return an initialized `PTAnnotationManager` instance
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;


- (instancetype)init NS_UNAVAILABLE;

/**
 * The `PTPDFViewCtrl` instance that this annotation manager coordinates with.
 */
@property (nonatomic, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The `PTToolManager` instance that this annotation manager coordinates with.
 */
@property (nonatomic, weak, nullable) PTToolManager *toolManager;

/**
 * The `PTUndoRedoManager` instance that this annotation manager coordinates with.
 */
@property (nonatomic, strong, nullable) PTUndoRedoManager *undoRedoManager;

/**
 * The identifier of the current annotation author.
 */
@property (nonatomic, copy, nullable) NSString *annotationAuthorIdentifier;

/**
 * Controls whether annotations made by other authors can be edited by the current author, specified
 * by the `annotationAuthorIdentifier` property.
 *
 * When the value of this property is set to `PTAnnotationModeEditOwn`, the annotation manager will
 * also automatically enable the `PTToolManager.annotationAuthorCheckEnabled` property on the current
 * `toolManager`.
 *
 * The default value of this property is `PTAnnotationModeEditAll`.
 */
@property (nonatomic, assign) PTAnnotationEditMode annotationEditMode;

/**
 * Finds the annotation on the specified page number with a matching annotation identifier.
 *
 * @param annotationIdentifier The identifier of the annotation to be found
 *
 * @param pageNumber the PDF page number to search for the annotation
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the matching annotation, or `nil` if the annotation could not be found. If an error occurs,
 * then `nil` will be returned and the `error` parameter will contain the error information.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (nullable PTAnnot *)findAnnotationWithIdentifier:(NSString *)annotationIdentifier
                                      onPageNumber:(int)pageNumber
                                         withError:(out NSError * __autoreleasing _Nullable * _Nullable)error;

/**
 * Returns whether the specified annotation is editable by the given author.
 *
 * @param annotation the annotation that will be edited
 *
 * @param document the document containing the annotation
 *
 * @param otherAnnotationAuthorIdentifier the identifier of the author editing the annotation
 *
 * @return `YES` if the annotation can be edited by the given author, `NO` otherwise
 */
- (BOOL)isAnnotation:(PTAnnot *)annotation inDocument:(PTSDFDoc *)document editableByAuthorWithIdentifier:(NSString *)otherAnnotationAuthorIdentifier;

/**
 * Returns whether the specified annotation, with the specified author identifier, is editable by the
 * given author.
 *
 * @param annotation the annotation that will be edited
 *
 * @param annotationAuthorIdentifier the identifier of the annotation's author
 *
 * @param otherAnnotationAuthorIdentifier the identifier of the author editing the annotation
 *
 * @return `YES` if the annotation can be edited by the given author, `NO` otherwise
 */
- (BOOL)isAnnotation:(PTAnnot *)annotation withAuthorIdentifier:(NSString *)annotationAuthorIdentifier editableByAuthorWithIdentifier:(NSString *)otherAnnotationAuthorIdentifier;

/**
 * Returns whether an annotation with the specified annotation author identifier is editable by the
 * given author.
 *
 * @param annotationAuthorIdentifier the identifier of the annotation's author
 *
 * @param otherAnnotationAuthorIdentifier the identifier of the author editing the annotation
 *
 * @return `YES` if the annotation can be edited by the given author, `NO` otherwise
 */
- (BOOL)isAnnotationWithAuthorIdentifier:(NSString *)annotationAuthorIdentifier
          editableByAuthorWithIdentifier:(NSString *)otherAnnotationAuthorIdentifier;

/**
 * Generates and sets a new unique identifier for the specified annotation.
 *
 * @param annotation The annotation for which to generate and set a new unique identifier
 *
 * @note This method acquires a write-lock on the `pdfViewCtrl`.
 */
- (void)generateIdentifierForAnnotation:(PTAnnot *)annotation;

/**
 * Updates the modification date for the specified annotation to the current date and time.
 *
 * @param annotation The annotation for which to update the modification date
 *
 * @note This method acquires a write-lock on the `pdfViewCtrl`.
 */
- (void)updateModificationDateForAnnotation:(PTAnnot *)annotation;

/**
 * Sets the author of the specified annotation.
 *
 * @param annotation The annotation for which to set the author
 *
 * @param authorIdentifier The identifier of the author
 */
- (void)setAuthorForAnnotation:(PTAnnot *)annotation
              authorIdentifier:(NSString *)authorIdentifier;

/**
 * Sets the display name for the annotation author with the specified identifier.
 *
 * @param authorName The name to display for the author
 *
 * @param authorIdentifier The identifier of the annotation author
 *
 * @param completionHandler A block that will be invoked when the operation has completed.
 * If an error occurs then the `success` parameter is `NO` and the `error` parameter contains the
 * error information.
 */
- (void)setAuthorName:(NSString *)authorName
        forIdentifier:(NSString *)authorIdentifier
           completion:(void (^)(BOOL success, NSError * _Nullable error))completionHandler;

/**
 * Returns the name of the annotation author with the specified identifier.
 *
 * @param authorIdentifier The identifier of the annotation author
 *
 * @param error On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the name of the annotation author, or `nil` if an error occurred
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (nullable NSString *)authorNameForIdentifier:(NSString *)authorIdentifier
                                         error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

#pragma mark Bulk annotation removal

/**
 * Removes all of the PDF annotations on the specified PDF page in the current document.
 *
 * @param pageNumber the PDF page number containing the annotations to remove
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotations were successfully removed, `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)removeAllAnnotationsOnPageNumber:(int)pageNumber withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Removes all of the PDF annotations in the current document.
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotations were successfully removed, `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)removeAllAnnotationsWithError:(NSError * _Nullable __autoreleasing * _Nullable)error;

#pragma mark - XFDF

/**
 * Updates the annotations in the document with the provided XFDF string.
 *
 * @param xfdfString The XFDF string containing the updated annotation data.
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotations in the document were updated successfuly, or `NO` if an error
 * occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)updateAnnotationsWithXFDFString:(NSString *)xfdfString error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Updates the annotations in the document with the provided XFDF command string.
 *
 * @param xfdfCommand The XFDF command string containing the updated annotation data.
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotations in the document were updated successfuly, or `NO` if an error
 * occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)updateAnnotationsWithXFDFCommand:(NSString *)xfdfCommand error:(NSError * _Nullable __autoreleasing * _Nullable)error;

#pragma mark - Annotation models

#pragma mark Document

/**
 * The top-level document model object representing the current PDF document in the `pdfViewCtrl`.
 */
@property (nonatomic, readonly, strong, nullable) id<PTDocumentModel> documentModel;

/**
 * Whether the document model for the current PDF document is currently being loaded.
 *
 * @see `-loadDocumentModel`
 */
@property (nonatomic, readonly, assign, getter=isLoadingDocumentModel) BOOL loadingDocumentModel;

/**
 * Whether the `documentModel` is loaded.
 *
 * The default value of this property is `NO`.
 *
 * @see `-loadDocumentModel`
 */
@property (nonatomic, readonly, assign, getter=isDocumentModelLoaded) BOOL documentModelLoaded;

/**
 * Loads the document model for the current PDF document displayed in the `pdfViewCtrl`.
 * It is safe to call this method multiple times.
 */
- (void)loadDocumentModel;

/**
 * Loads the document model for the current PDF document displayed in the `pdfViewCtrl`.
 *
 * @param completion an optional completion block to be executed when the document model has been
 * loaded. On success, the `documentModel` parameter will contain the loaded document model, otherwise
 * the `error` parameter will contain information describing the reason for failure.
 */
- (void)loadDocumentModelWithCompletionHandler:(void (^ PT_ESCAPING _Nullable)(id<PTDocumentModel> _Nullable documentModel, NSError * _Nullable error))completion;

#pragma mark Annotations

/**
 * If the annotation manager is currently loading annotation models.
 *
 * Changes to the document page ordering / number should not be made while annotations are loading.
 *
 * @see `annotationsLoaded`
 */
@property (nonatomic, readonly, assign, getter=isLoadingAnnotations) BOOL loadingAnnotations;

/**
 * Whether the annotation models have been loaded.
 *
 * The default value of this property is `NO`.
 *
 * @see `-loadAnnotationModels`
 */
@property (nonatomic, readonly, assign, getter=areAnnotationsLoaded) BOOL annotationsLoaded;

/**
 * Starts or restarts the loading of annotation models by this annotation manager.
 *
 * @see `loadingAnnotations`
 * @see `annotationsLoaded`
 */
- (void)loadAnnotationModels;

/**
 * Fetches or creates the annotation model object for the given PDF annotation.
 *
 * @param annotation The annotation for which to get the model object
 *
 * @param pageNumber The PDF page number of the annotation
 *
 * @param completionHandler A block that will be called asynchronously with the results of this
 * method. On success, the `annotationModel` block parameter will contain the annotation model object
 * for the PDF annotation. If the annotation model object cannot be fetched or created, the
 * `annotationModel` parameter will be `nil` and error information will be passed in the `error`
 * block parameter.
 */
- (void)annotationModelForAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber withCompletionHandler:(void (^)(id<PTAnnotationModel> _Nullable annotationModel, NSError * _Nullable error))completionHandler;

/**
 * Returns whether the specified annotation model object can be edited by the current annotation
 * author.
 *
 * @return `YES` if the specified annotation model object can be edited by the current annotation
 * author, `NO` otherwise.
 */
- (BOOL)canEditAnnotationModel:(id<PTAnnotationModel>)annotationModel;

@end

/**
 * Annotation operation methods.
 */
@interface PTAnnotationManager (AnnotationOperations)

/**
 * Using the provided block, modifies the specified annotation. The appropriate annotation-change
 * events will be triggered before and after the modification.
 *
 * @param annotation The PDF annotation to be modified
 *
 * @param pageNumber The PDF page number containing the annotation
 *
 * @param modificationBlock The block to run during the annotation modification operation
 */
- (void)modifyAnnotation:(PTAnnot *)annotation
            onPageNumber:(int)pageNumber
               withBlock:(void (^)(PTAnnot *annotation, int pageNumber))modificationBlock;

/**
 * Using the provided block, modifies the specified annotations. The appropriate annotation-change
 * events will be triggered before and after the modification.
 *
 * @param annotations The PDF annotations to be modified
 *
 * @param pageNumber The PDF page number containing the annotations
 *
 * @param modificationBlock The block to run during the annotation modification operation
 */
- (void)modifyAnnotations:(NSArray<PTAnnot *> *)annotations
             onPageNumber:(int)pageNumber
                withBlock:(void (^)(NSArray<PTAnnot *> *annotations, int pageNumber))modificationBlock;

#pragma mark Removal

/**
 * Removes the given PDF annotation from the specified PDF page in the current document.
 *
 * @param annotation The PDF annotation to be removed
 *
 * @param pageNumber The PDF page number containing the annotation
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotation was successfully removed, `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)removeAnnotation:(PTAnnot *)annotation
            onPageNumber:(int)pageNumber
               withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Removes the given PDF annotations from the specified PDF page in the current document.
 *
 * @param annotations The PDF annotations to be removed
 *
 * @param pageNumber The PDF page number containing the annotations
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotations were successfully removed, `NO` if an error occurred.
 *
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)removeAnnotations:(NSArray<PTAnnot *> *)annotations
             onPageNumber:(int)pageNumber
                withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

#pragma mark Flattening

/**
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)flattenAnnotation:(PTAnnot *)annotation
             onPageNumber:(int)pageNumber
                withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * @note In Swift, this method is imported as a throwing function.
 */
- (BOOL)flattenAnnotations:(NSArray<PTAnnot *> *)annotations
              onPageNumber:(int)pageNumber
                 withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

/**
 * Annotation change event methods.
 */
@interface PTAnnotationManager (AnnotationEvents)

/**
 * Used to notify the annotation manager that an annotation has been added.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF to which the annotation was added.
 */
- (void)annotationAdded:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations have been added.
 *
 * @param annotations The annotations that were added.
 *
 * @param pageNumber The page number of the PDF that the annotations were added to.
 */
- (void)annotationsAdded:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that an annotation will be modified
 *
 * @param annotation The annotation will be modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)willModifyAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations will be modified.
 *
 * @param annotations The annotations will be modified.
 *
 * @param pageNumber The page number of the PDF that the annotations were modified on.
 */
- (void)willModifyAnnotations:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that an annotation has been modified.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)annotationModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations have been modified.
 *
 * @param annotations The annotations that were modified.
 *
 * @param pageNumber The page number of the PDF that the annotations were modified on.
 */
- (void)annotationsModified:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that the data of a form field has been modified.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)formFieldDataModifiedForAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that an annotation will be removed.
 *
 * @param annotation The annotation that will be removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)willRemoveAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations will be removed.
 *
 * @param annotations The annotations that will be removed.
 *
 * @param pageNumber The page number of the PDF that the annotations will be removed from.
 */
- (void)willRemoveAnnotations:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that an annotation has been removed.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)annotationRemoved:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations have been removed.
 *
 * @param annotations The annotations that were removed.
 *
 * @param pageNumber The page number of the PDF that the annotations were removed from.
 */
- (void)annotationsRemoved:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations will be flattened.
 *
 * @param annotations The annotations that will be flattened.
 *
 * @param pageNumber The page number of the PDF that the annotations will be flattened on.
 */
- (void)willFlattenAnnotations:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations have been flattened.
 *
 * @param annotations The annotation that were flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation were flattened on.
 */
- (void)didFlattenAnnotations:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the annotation manager that annotations will be changed in the document.
 *
 * @param changes The changes that will be made to the document's annotations
 */
- (void)annotationsWillChangeWithChanges:(NSArray<PTPDFAnnotationChange *> *)changes;

/**
 * Used to notify the annotation manager that annotations were changed in the document.
 *
 * @param changes The changes that were made to the document's annotations
 */
- (void)annotationsDidChangeWithChanges:(NSArray<PTPDFAnnotationChange *> *)changes;

#pragma mark XFDF

/**
 * Used to notify the annotation manager that annotations will be updated with an XFDF string.
 *
 * @param xfdfString The XFDF string containing the updated annotation data.
 */
- (void)willUpdateAnnotationsWithXFDFString:(NSString *)xfdfString;

/**
 * Used to notify the annotation manager that annotations have been updated with an XFDF string.
 *
 * @param xfdfString The XFDF string containing the updated annotation data.
 */
- (void)didUpdateAnnotationsWithXFDFString:(NSString *)xfdfString;

/**
 * Used to notify the annotation manager that annotations will be updated with an XFDF command string.
 *
 * @param xfdfCommand The XFDF command string containing the updated annotation data.
 */
- (void)willUpdateAnnotationsWithXFDFCommand:(NSString *)xfdfCommand;

/**
 * Used to notify the annotation manager that annotations have been updated with an XFDF command string.
 *
 * @param xfdfCommand The XFDF command string containing the updated annotation data.
 */
- (void)didUpdateAnnotationsWithXFDFCommand:(NSString *)xfdfCommand;

@end

#pragma mark - Notifications

/**
 * Posted when the document model object has been loaded.
 *
 * The notification object is the `PTAnnotationManager` instance that posted the notification.
 * There is no `userInfo` dictionary for this notification.
 */
PT_EXTERN const NSNotificationName PTAnnotationManagerDidLoadDocumentModel;

/**
 * Posted when annotations will be changed.
 *
 * The notification object is the `PTAnnotationManager` instance that posted the notification.
 *
 * The `userInfo` dictionary of the `NSNotification` instance contains entries for at least one of
 * the following keys:
 *  - `PTAddedAnnotationsUserInfoKey`
 *  - `PTModifiedAnnotationsUserInfoKey`
 *  - `PTRemovedAnnotationsUserInfoKey`
 *  - `PTFlattenedAnnotationsUserInfoKey`
 *  - `PTAnnotationChangesUserInfoKey`
 *  - `PTXFDFUserInfoKey`
 * The key(s) present in the `userInfo` dictionary depends on if annotations will be added, modified,
 * removed, flattened, or updated with an XFDF string.
 */
PT_EXTERN const NSNotificationName PTAnnotationManagerAnnotationsWillChangeNotification;

/**
 * Posted when annotations have been changed.
 *
 * The notification object is the `PTAnnotationManager` instance that posted the notification.
 *
 * The `userInfo` dictionary of the `NSNotification` instance contains entries for at least one of
 * the following keys:
 *  - `PTAddedAnnotationsUserInfoKey`
 *  - `PTModifiedAnnotationsUserInfoKey`
 *  - `PTRemovedAnnotationsUserInfoKey`
 *  - `PTFlattenedAnnotationsUserInfoKey`
 *  - `PTAnnotationChangesUserInfoKey`
 *  - `PTXFDFUserInfoKey`
 * The key(s) present in the `userInfo` dictionary depends on if annotations were added, modified,
 * removed, flattened, or updated with an XFDF string.
 */
PT_EXTERN const NSNotificationName PTAnnotationManagerAnnotationsDidChangeNotification;

/**
 * Posted when the annotation manager is about to start loading annotations.
 *
 * The notification object is the `PTAnnotationManager` instance that posted the notification.
 * There is no `userInfo` dictionary for this notification.
 *
 */
PT_EXTERN const NSNotificationName PTAnnotationManagerWillBeginLoadingAnnotationsNotification;

/**
 * Posted when the annotation manager has stopped loading annotations.
 *
 * The notification object is the `PTAnnotationManager` instance that posted the notification.
 * There is no `userInfo` dictionary for this notification.
 *
 */
PT_EXTERN const NSNotificationName PTAnnotationManagerDidEndLoadingAnnotationsNotification;

#pragma mark User Info Keys

/**
 * The key for a `NSDictionary<NSNumber *, NSArray<PTAnnot *> *> *`, where the dictionary keys are
 * `NSNumber` instances containing an `int` page number and the dictionary values are `NSArray`
 * instances containing `PTAnnot`s for the changed annotations.
 */
PT_EXTERN NSString * const PTAddedAnnotationsUserInfoKey;

/**
 * The key for a `NSDictionary<NSNumber *, NSArray<PTAnnot *> *> *`, where the dictionary keys are
 * `NSNumber` instances containing an `int` page number and the dictionary values are `NSArray`
 * instances containing `PTAnnot`s for the changed annotations.
 */
PT_EXTERN NSString * const PTModifiedAnnotationsUserInfoKey;

/**
 * The key for a `NSDictionary<NSNumber *, NSArray<PTAnnot *> *> *`, where the dictionary keys are
 * `NSNumber` instances containing an `int` page number and the dictionary values are `NSArray`
 * instances containing `PTAnnot`s for the changed annotations.
 */
PT_EXTERN NSString * const PTRemovedAnnotationsUserInfoKey;

/**
 * The key for a `NSDictionary<NSNumber *, NSArray<PTAnnot *> *> *`, where the dictionary keys are
 * `NSNumber` instances containing an `int` page number and the dictionary values are `NSArray`
 * instances containing `PTAnnot`s for the changed annotations.
 */
PT_EXTERN NSString * const PTFlattenedAnnotationsUserInfoKey;

/**
 * The key for a `NSArray` containing `PTPDFAnnotationChange` instances describing the changes to
 * annotations in the document.
 */
PT_EXTERN NSString * const PTAnnotationChangesUserInfoKey;

/**
 * The key for a `NSString *` of an XFDF string.
 */
PT_EXTERN NSString * const PTXFDFUserInfoKey;

NS_ASSUME_NONNULL_END
