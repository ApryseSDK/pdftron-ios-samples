//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFViewCtrl;
@class PTUndoRedoManager;

/**
 * The `PTUndoRedoManager` class is responsible for managing the undo/redo chain of a `PTPDFViewCtrl`
 * and an `NSUndoManager` instance.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(UndoRedoManager)
@interface PTUndoRedoManager : NSObject <PTOverridable>

/**
 * Initializes a new `PTUndoRedoManager` instance with the given PDFViewCtrl.
 *
 * @param pdfViewCtrl the PDFViewCtrl
 *
 * @return an initialized `PTUndoRedoManager` instance
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * The `PTPDFViewCtrl` associated with the undo-redo manager.
 */
@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * Whether the undo-redo manager is enabled and updates the undo/redo state.
 *
 * When disabled (value is set to `NO`), the `NSUndoManager` owned by the `pdfViewCtrl` is cleared
 * of all its actions and no new undo/redo changes will be registered.
 *
 * The default value of this property is `YES`.
 * 
 * @note Change-snapshotting will still be performed on the `pdfViewCtrl` regardless of this property's
 * value. Other functionality, such as annotation change processing, relies on the information
 * produced by change-snapshots.
 *
 * @note The value of this property is also derived from the `PTPDFViewCtrl.isUndoRedoEnabled`
 * property of this undo-redo manager's `pdfViewCtrl`.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/**
 * Undo the last action.
 */
- (void)undo;

/**
 * Redo the last undo.
 */
- (void)redo;

/**
 * Creates a new state at the top of the undo/redo chain by taking a snapshot.
 *
 * @param actionInfo meta-data to be attached to this new state.
 */
- (void)takeUndoSnapshot:(NSString *)actionInfo;

/**
 * Registers a generic change with the undo-redo manager.
 *
 * @param actionName The name of the action
 */
- (void)registerChangeWithActionName:(nullable NSString *)actionName;


- (instancetype)init NS_UNAVAILABLE;

@end

/**
 * Undo-able annotations events.
 */
@interface PTUndoRedoManager (PTAnnotationChanges)

/**
 * Used to notify the undo-redo manager that an annotation has been added.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 */
- (void)annotationAdded:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that annotations have been added.
 *
 * @param annotations The annotations that were added.
 *
 * @param pageNumber The page number of the PDF that the annotations were added to.
 */
- (void)annotationsAdded:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that an annotation has been modified
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)annotationModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that annotations have been modified
 *
 * @param annotations The annotations that were modified.
 *
 * @param pageNumber The page number of the PDF that the annotations were modified on.
 */
- (void)annotationsModified:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that an annotation has been removed.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)annotationRemoved:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that annotations have been removed.
 *
 * @param annotations The annotations that were removed.
 *
 * @param pageNumber The page number of the PDF that the annotations were removed from.
 */
- (void)annotationsRemoved:(NSArray<PTAnnot *> *)annotations onPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that the data of a form field has been modified.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)formFieldDataModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

@end

/**
 * Undo-able page events.
 */
@interface PTUndoRedoManager (PTPageChanges)

/**
 * Used to notify the undo-redo manager manager that a page has been added.
 *
 * @param pageNumber The page number of the page that was added.
 */
- (void)pageAddedAtPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager manager that a page has been moved.
 *
 * @param oldPageNumber The old page number of the page.
 * @param newPageNumber The new page number of the page.
 */
- (void)pageMovedFromPageNumber:(int)oldPageNumber toPageNumber:(int)newPageNumber;

/**
 * Used to notify the undo-redo manager that a page has been removed.
 *
 * @param pageNumber The page number of the page that was removed.
 */
- (void)pageRemovedForPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that a page has been rotated.
 *
 * @param pageNumber The page number of the page that was rotated.
 */
- (void)pageRotatedForPageNumber:(int)pageNumber;

/**
 * Used to notify the undo-redo manager that pages have been rotated.
 *
 * @param pageNumbers The page numbers of the pages that were rotated.
 */
- (void)pagesRotatedForPageNumbers:(NSIndexSet *)pageNumbers;

@end

/**
 * Undo-able page content events.
 */
@interface PTUndoRedoManager (PTPageContentChanges)

/**
 * Used to notify the undo-redo manager that a page's content has changed.
 *
 * @param pageNumber The page number of the page that had its content changed.
 */
- (void)pageContentModifiedOnPageNumber:(int)pageNumber;

@end

/**
 * Posted before changes are undone by the undo-redo manager.
 *
 * The notification object is the undo-redo manager that posted the notification. There is no user
 * info dictionary for this notification.
 */
PT_EXTERN const NSNotificationName PTUndoRedoManagerWillUndoNotification;

/**
 * Posted after changes are undone by the undo-redo manager.
 *
 * The notification object is the undo-redo manager that posted the notification. The `userInfo`
 * dictionary contains entries for the `PTUndoRedoManagerInfoUserInfoKey` key(s).
 */
PT_EXTERN const NSNotificationName PTUndoRedoManagerDidUndoNotification;

/**
 * Posted before changes are redone by the undo-redo manager.
 *
 * The notification object is the undo-redo manager that posted the notification. There is no user
 * info dictionary for this notification.
 */
PT_EXTERN const NSNotificationName PTUndoRedoManagerWillRedoNotification;

/**
 * Posted after changes are redone by the undo-redo manager.
 *
 * The notification object is the undo-redo manager that posted the notification. The `userInfo`
 * dictionary contains entries for the `PTUndoRedoManagerInfoUserInfoKey` key(s).
 */
PT_EXTERN const NSNotificationName PTUndoRedoManagerDidRedoNotification;

/**
 * The key for a `PTUndoRedoInfo` object describing an undo/redo change.
 */
PT_EXTERN NSString * const PTUndoRedoManagerInfoUserInfoKey;

NS_ASSUME_NONNULL_END
