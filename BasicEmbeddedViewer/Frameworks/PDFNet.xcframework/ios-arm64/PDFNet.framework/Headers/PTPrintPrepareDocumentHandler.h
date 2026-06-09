//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetDefines.h>
#import <PDFNet/PDFNetOBJC.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTContext;
@class PTPDFDoc;

/**
 * A utility class that handles preparing PDF documents for printing.
 */
PDFNET_EXTERN
PDFNET_OBJC_RUNTIME_NAME(PTPrintPrepareDocumentHandler)
@interface PTPrintPrepareDocumentHandler : NSObject

/**
 * Initializes a new `PTPrintPrepareDocumentHandler` instance with a source document.
 *
 * @param sourcePDFDoc The PDF document to be prepared.
 *
 * @return An initialized `PTPrintPrepareDocumentHandler` instance.
 */
- (instancetype)initWithSourcePDFDoc:(PTPDFDoc *)sourcePDFDoc NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * The PDF document to be prepared.
 */
@property (nonatomic, readonly, strong) PTPDFDoc *sourcePDFDoc;

/**
 * The OCG context specifying the content to be printed.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) PTContext *context;

#pragma mark - Preparing

/**
 * Starts a new preparation operation with the current settings.
 *
 * @param completionHandler The block to be called when the operation finishes.
 * The `outputPDFDoc` parameter contains the prepared output PDF document, or `nil` if an error
 * occurred and the `error` parameter provides the detailed error information.
 */
- (void)prepareWithCompletionHandler:(void (PDFNET_ESCAPING ^)(PTPDFDoc * _Nullable outputPDFDoc,
                                                               NSError * _Nullable error))completionHandler;

#pragma mark - Cancellation

/**
 * Cancels any ongoing preparation operations.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
