//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTOCRProcessor` class performs Optical Character Recognition (OCR) on the content of a PDF
 * and applies the recognized text results to each page.
 */
PT_EXTERN
NS_SWIFT_SENDABLE
PT_OBJC_RUNTIME_NAME(OCRProcessor)
@interface PTOCRProcessor : NSObject

/**
 * Initializes a `PTOCRProcessor` instance.
 *
 * @return An initialized `PTOCRProcessor` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Processing

/**
 * Performs OCR and applies the results to the specified PDF document.
 *
 * @param pdfDoc The PDF document to be processed.
 *
 * @param completionHandler The completion handler to be called when processing is finished. If the
 * document was processed successfully then the `success` parameter is `YES`, otherwise the `error`
 * parameter contains more information about the failure.
 */
- (void)processDocument:(PTPDFDoc *)pdfDoc
  withCompletionHandler:(void (PT_ESCAPING ^)(BOOL success,
                                              NSError * _Nullable error))completionHandler
NS_SWIFT_ASYNC_THROWS_ON_FALSE(1)
API_AVAILABLE(ios(13.0));

/**
 * Performs OCR and applies the results to the specified page in the PDF document.
 *
 * @param pageNumber The number of the PDF page to be processed.
 *
 * @param pdfDoc The PDF document to be processed.
 *
 * @param completionHandler The completion handler to be called when processing is finished. If the
 * document was processed successfully then the `success` parameter is `YES`, otherwise the `error`
 * parameter contains more information about the failure.
 */
- (void)processPageNumber:(int)pageNumber
               inDocument:(PTPDFDoc *)pdfDoc
    withCompletionHandler:(void (PT_ESCAPING ^)(BOOL success,
                                                NSError * _Nullable error))completionHandler
NS_SWIFT_ASYNC_THROWS_ON_FALSE(1)
API_AVAILABLE(ios(13.0));

/**
 * Cancels all in-progress OCR processing.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
