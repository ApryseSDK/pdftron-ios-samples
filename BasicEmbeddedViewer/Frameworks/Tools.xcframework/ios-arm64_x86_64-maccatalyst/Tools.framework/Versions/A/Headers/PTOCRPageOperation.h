//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTOCRPageOperation;
@class PTPDFDoc;

/**
 * An operation that recognizes text (via OCR) on a specified PDF page and applies the result back to
 * the document.
 */
PT_EXTERN
API_AVAILABLE(ios(13.0))
PT_OBJC_RUNTIME_NAME(OCRPageOperation)
@interface PTOCRPageOperation : NSOperation

/**
 * Initializes a `PTOCRPageOperation` instance.
 *
 * @param pdfDoc The PDF document.
 * @param pageNumber The page number to be processed within the document.
 *
 * @return An initialized `PTOCRPageOperation` instance.
 */
- (instancetype)initWithPDFDoc:(PTPDFDoc *)pdfDoc
                    pageNumber:(int)pageNumber NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

#pragma mark - Input

/**
 * The PDF document in which to recognize text.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDoc *pdfDoc;

/**
 * The page number of `pdfDoc` on which to recognize and add text.
 */
@property (nonatomic, readonly, assign) int pageNumber;

#pragma mark - Output

/**
 * In the case that the operation could not complete successfully, the error information can be retrieved
 * via this property.
 */
@property (nonatomic, readonly, strong, nullable) NSError *error;

@property (nonatomic, readonly, assign) BOOL hasText;

@end

NS_ASSUME_NONNULL_END
