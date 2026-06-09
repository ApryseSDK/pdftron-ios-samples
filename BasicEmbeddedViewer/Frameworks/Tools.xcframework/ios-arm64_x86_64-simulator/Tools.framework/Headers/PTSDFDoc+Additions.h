//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSDFDoc;

@interface PTSDFDoc (Locking)

/**
 * Synchronously acquires a read lock for this `PTSDFDoc` instance and executes the given block on
 * the current queue. Any `NSException` thrown while locking or unlocking the document, or executing the block, is converted into an `NSError` object and returned in the `error` parameter.
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
- (BOOL)lockReadWithBlock:(void (^ NS_NOESCAPE)(PTSDFDoc * _Nonnull doc))block error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Synchronously acquires a write lock for this `PTSDFDoc` instance and executes the given block.
 *
 * Simultaneous write access to a PTPDFDoc instance is not allowed. A write lock cannot be acquired
 * if the thread already holds a read lock. Attempting to do so is an error.
 *
 * Any `NSException` thrown while locking or unlocking the document, or executing the block,
 * is converted into an `NSError` object and returned in the `error` parameter.
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
- (BOOL)lockWithBlock:(void (^ NS_NOESCAPE)(PTSDFDoc * _Nonnull doc))block error:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

@interface PTSDFDoc (Additions)

/**
 * Creates an indirect object clone from the specified direct object.
 *
 * This method throws an exception if the specified object is not direct (ie. is already indirect).
 *
 * @param directObj The direct object to clone
 *
 * @return an indirect object clone
 */
- (PTObj *)CreateIndirectCloneFromDirectObj:(PTObj *)directObj;

@end

@interface PTSDFDoc (Importing)

/**
 * Imports the specified annotations into this document.
 *
 * @param annotations the annotations to be imported into this document
 *
 * @param error On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the imported annotations, or `nil` if an error occurs
 */
- (nullable NSArray<PTAnnot *> *)importAnnotations:(NSArray<PTAnnot *> *)annotations
                                         withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
