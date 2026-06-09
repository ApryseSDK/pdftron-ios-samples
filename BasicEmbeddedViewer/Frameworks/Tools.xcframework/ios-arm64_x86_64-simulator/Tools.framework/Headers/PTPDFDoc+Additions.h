//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Convenience methods for locking a `PTPDFDoc` with exception and error handling.
 */
PT_EXTERN
@interface PTPDFDoc (Additions)

#pragma mark - Pages

/**
 * Enumerates through the pages in this document and calls the provided block for each page.
 *
 * @param block The block to be executed for each page in the document.
 *
 * @note This method requires a read-lock on the `PTPDFDoc`.
 */
- (void)enumeratePagesWithBlock:(void (NS_NOESCAPE ^)(unsigned int pageNumber,
                                                      PTPage *page,
                                                      BOOL *stop))block;

/**
 * Enumerates through the pages in this document between the start and end page numbers and calls the
 * provided block for each page.
 *
 * @param block The block to be executed for each page in the document.
 *
 * @note This method requires a read-lock on the `PTPDFDoc`.
 */
- (void)enumeratePagesFromPageNumber:(unsigned int)startPageNumber
                        toPageNumber:(unsigned int)endPageNumber
                           withBlock:(void (NS_NOESCAPE ^)(unsigned int pageNumber,
                                                           PTPage *page,
                                                           BOOL *stop))block;

#pragma mark - Annotations

/**
 * Generates a new unique ID for the given annotation.
 *
 * @param annotation The annotation for which to generate and set a new unique identifier
 *
 * @note This method requires a write-lock on the PTPDFDoc.
 */
- (void)GenerateUniqueIDForAnnotation:(PTAnnot *)annotation;

@end

NS_ASSUME_NONNULL_END
