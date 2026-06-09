//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Convenience methods for the `PTPDFViewCtrl` class.
 */
PT_EXTERN
@interface PTPDFViewCtrl (Additions)

/**
 * Synchronously acquires a write lock for the `PTPDFDoc` instance used by the `PTPDFViewCtrl`
 * and executes the given block on the current queue.
 *
 * Simultaneous write access to a PTPDFDoc instance is not allowed. A write lock cannot be acquired
 * if the thread already holds a read lock - attempting to do so is an error.
 *
 * @param cancelThreads If true, other threads accessing the document are terminated before trying to
 * lock the document. This ensures a quick return from this function. Otherwise, this function can
 * halt the UI and the app may be unresponsive before the other thread finishes. If the rendering thread
 * is canceled, the rendering thread will restart when the document is unlocked.
 *
 * @param block The block to perform.
 */
- (void)DocLock:(BOOL)cancelThreads
      withBlock:(void (NS_NOESCAPE ^)(PTPDFViewCtrl *pdfViewCtrl))block
    NS_SWIFT_UNAVAILABLE("Use the throwing `PTPDFViewCtrl.docLock(_:with:)` function instead");

/**
 * Synchronously acquires a read lock for the `PTPDFDoc` instance used by the `PTPDFViewCtrl`
 * and executes the given block on the current queue.
 *
 * @param block The block to perform.
 */
- (void)DocLockReadWithBlock:(void (NS_NOESCAPE ^)(PTPDFViewCtrl *pdfViewCtrl))block
    NS_SWIFT_UNAVAILABLE("Use the throwing `PTPDFViewCtrl.docLockRead(_:)` function instead");

/**
 * Synchronously acquires a write lock for the `PTPDFDoc` instance used by the
 * `PTPDFViewCtrl`.
 * Simultaneous write access to a PTPDFDoc instance is not allowed.
 * A write lock cannot be acquired if the thread already holds a read lock.
 * Attempting to do so is an error.
 *
 * Any `NSException` thrown while locking or unlocking the document, or executing the block,
 * is converted into an `NSError` object and returned in the `error` parameter.
 *
 * @param cancelThreads
 *            If true, other threads accessing the document are terminated before
 *            trying to lock the document. This ensures a quick return from this
 *            function. Otherwise, this function can halt the UI and the app
 *            may be unresponsive before the other thread finishes. If
 *            the rendering thread is canceled, unlocking the document
 *            UnlockDoc will restart the rendering thread.
 *
 * @param block The block to perform.
 *
 * @param error On input, a pointer to an error object. If an error occurs (an `NSException`
 * is thrown), this pointer is set to an actual error object containing the error
 * information. You may specify `nil` for this parameter if you do not want the error
 * information.
 *
 * @return `YES` if the document could be locked and the block could be run successfully. If
 * an error occurs (an `NSException` is thrown), this method returns `NO` and assigns an
 * appropriate error object to the `error` parameter.
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to
 * indicate that it throws an error in cases of failure.
 */
- (BOOL)DocLock:(BOOL)cancelThreads
      withBlock:(void (NS_NOESCAPE ^)(PTPDFDoc * _Nullable doc))block
          error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Synchronously acquires a read lock for the `PTPDFDoc` instance used by the `PTPDFViewCtrl`
 * and executes the given block on the current queue. Any `NSException` thrown while locking
 * or unlocking the document, or executing the block, is converted into an `NSError` object
 * and returned in the `error` parameter.
 *
 * @param block The block to perform.
 *
 * @param error On input, a pointer to an error object. If an error occurs (an `NSException`
 * is thrown), this pointer is set to an actual error object containing the error
 * information. You may specify `nil` for this parameter if you do not want the error
 * information.
 *
 * @return `YES` if the document could be locked and the block could be run successfully. If
 * an error occurs (an `NSException` is thrown), this method returns `NO` and assigns an
 * appropriate error object to the `error` parameter.
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to
 * indicate that it throws an error in cases of failure.
 */
- (BOOL)DocLockReadWithBlock:(void (NS_NOESCAPE ^)(PTPDFDoc * _Nullable doc))block
                       error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Navigates the PDFViewCtrl to the page at the specified PDF page number.
 *
 * @param pageNumber The PDF page number to which to navigate
 *
 * @param error On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the navigation was successful. If an error occurs, this method returns `NO` and
 * assigns an appropriate error object to the `error` parameter.
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to
 * indicate that it throws an error in cases of failure.
 */
- (BOOL)NavigateToPageNumber:(int)pageNumber
                       error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

#pragma mark Text search

/// A constant that indicates that text search should start from the first page.
PT_EXTERN const int PTTextSearchStartAtFirstPageNumber;
/// A constant that indicates that text search should end at the last page.
PT_EXTERN const int PTTextSearchEndAtLastPageNumber;

/**
 * Prepares a new `PTTextSearch` instance to perform a text search on the PDFViewCtrl's current document.
 *
 * The search is performed on the current document (`-GetDoc`) and is configured to use the PDFViewCtrl's
 * right-to-left language setting (`-GetRightToLeftLanguage`) and OCG context (`-GetOCGContext`).
 *
 * @param pattern The pattern for which to search. When regular expression is used, it contains
 * the expression, and in verbatim mode, it is the exact string for which to search.
 *
 * @param mode The mode of the search process.
 *
 * @param startPageNumber The start page of the page range in which to search. Passing the `PTTextSearchStartAtFirstPageNumber`
 * constant for this parameter indicates that the range start from the first page.
 *
 * @param endPageNumber The end page of the page range in which to search. Passing the `PTTextSearchEndAtLastPageNumber`
 * constant for this parameter indicates that the range ends at the last page.
 *
 * @param error On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return A new `PTTextSearch` instance that has been initialized to search the PDFViewCtrl's current
 * document using the provided parameters.
 *
 * @note In Swift, this method is marked with the `throws` keyword to indicate that it throws an error
 * in cases of failure.
 */
- (nullable PTTextSearch *)prepareTextSearchWithPattern:(NSString *)pattern
                                                   mode:(unsigned int)mode
                                        startPageNumber:(int)startPageNumber
                                          endPageNumber:(int)endPageNumber
                                                  error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

@end

@interface PTPDFViewCtrl (Annotations)

- (void)enumerateAnnotationsOnPageNumber:(int)pageNumber withBlock:(void (NS_NOESCAPE ^)(PTAnnot *annotation, NSUInteger index, BOOL *stop))block;

- (void)enumerateAnnotationsFromPageNumber:(int)startPageNumber toPageNumber:(int)endPageNumber withBlock:(void (NS_NOESCAPE ^)(int pageNumber, PTAnnot *annotation, NSUInteger indexOnPage, BOOL *stop))block;

- (void)enumerateAnnotationsWithBlock:(void (NS_NOESCAPE ^)(int pageNumber, PTAnnot *annotation, NSUInteger indexOnPage, BOOL *stop))block;

@end

/**
 * Returns the corresponding non-continuous page presentation mode for the given mode. If the mode
 * is already non-continuous then the input mode is returned.
 *
 * @param mode the page presentation mode
 *
 * @return the corresponding non-continuous page presentation mode
 */
PT_EXPORT TrnPagePresentationMode PTPagePresentationModeGetBaseMode(TrnPagePresentationMode mode);

/**
 * Returns whether the given page presentation mode is continuous.
 *
 * @param mode the page presentation mode
 *
 * @return `YES` if the page presentation mode is continuous, `NO` otherwise
 */
PT_EXPORT BOOL PTPagePresentationModeIsContinuous(TrnPagePresentationMode mode);

/**
 * This function is used to toggle the continuous aspect of a page presentation mode. For the
 * specified page presentation mode, a corresponding mode will be returned with the continuous
 * aspect added or removed according to the `continuous` parameter.
 *
 * @param mode the page presentation mode
 *
 * @param continuous `YES` if the resulting page presentation mode should be continuous, `NO` otherwise
 *
 * @return the corresponding page presentation mode with the continuous aspect added or removed
 * according to the `continuous` parameter.
 */
PT_EXPORT TrnPagePresentationMode PTPagePresentationModeGetEffectiveMode(TrnPagePresentationMode mode, BOOL continuous);

/**
 * Zoom-related convenience methods for the `PTPDFViewCtrl` class.
 */
PT_EXTERN
@interface PTPDFViewCtrl (Zoom)

/**
 * The zoom ratio of point size to physical size
 */
@property (nonatomic, assign) double zoomWhenPrinted;

@end

NS_ASSUME_NONNULL_END
