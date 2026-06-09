//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetDefines.h>
#import <PDFNet/PTPDFNetException.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFNetException;

/**
 * The domain for errors from the PDFNet library.
 */
PDFNET_EXTERN const NSErrorDomain PTPDFNetErrorDomain;

/**
 * Creates a new `NSError` object from a `PTPDFNetException`.
 *
 * @param exception The exception.
 *
 * @return A new `NSError` object initialized with the exception's information.
 */
PDFNET_EXTERN NSError *PTPDFNetExceptionToError(PTPDFNetException *exception);

NS_ASSUME_NONNULL_END
