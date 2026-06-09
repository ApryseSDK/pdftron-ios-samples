//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetDefines.h>
#import <PDFNet/PDFNetOBJC.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PTPDFDoc (PDFNetAdditions)

#pragma mark - Locking

/**
 * Synchronously acquires a read lock for this `PTPDFDoc` instance and executes the given block on
 * the current queue.
 *
 * @param block The block to perform.
 */
- (void)LockReadWithBlock:(void (PDFNET_NOESCAPE ^)(void))block NS_SWIFT_UNAVAILABLE("Use the throwing PTPDFDoc.lockRead(_:) function instead");

/**
 * Synchronously acquires a write lock for this `PTPDFDoc` instance and executes the given block.
 *
 * Simultaneous write access to a PTPDFDoc instance is not allowed. A write lock cannot be acquired
 * if the thread already holds a read lock. Attempting to do so is an error.
 *
 * @param block The block to perform.
 */
- (void)LockWithBlock:(void (PDFNET_NOESCAPE ^)(void))block NS_SWIFT_UNAVAILABLE("Use the throwing PTPDFDoc.lock(_:) function instead");

#pragma mark - Locking with exception/error handling

/**
 * Synchronously acquires a read lock for this `PTPDFDoc` instance and executes the given block on
 * the current queue.
 *
 * Any `NSException` thrown while locking or unlocking the document, or executing the block,
 * is converted into an `NSError` object and returned in the `error` parameter.
 *
 * @param block The block to perform.
 *
 * @param outError On input, a pointer to an error object. If an error occurs (an `NSException`
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
- (BOOL)LockReadWithBlock:(void (PDFNET_NOESCAPE ^)(void))block
                    error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

/**
 * Synchronously acquires a write lock for this `PTPDFDoc` instance and executes the given block.
 *
 * Simultaneous write access to a PTPDFDoc instance is not allowed. A write lock cannot be acquired
 * if the thread already holds a read lock. Attempting to do so is an error.
 *
 * Any `NSException` thrown while locking or unlocking the document, or executing the block,
 * is converted into an `NSError` object and returned in the `error` parameter.
 *
 * @param block The block to perform.
 *
 * @param outError On input, a pointer to an error object. If an error occurs (an `NSException`
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
- (BOOL)LockWithBlock:(void (PDFNET_NOESCAPE ^)(void))block
                error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

@end

PDFNET_OBJC_CATEGORY_LINK(PTPDFDoc, PDFNetAdditions)

NS_ASSUME_NONNULL_END
