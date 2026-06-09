//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A model class that manages access to a `PTPDFDoc` instance.
 *
 * The `PTPDFDocumentModel` encapsulates some of the more complex operations that can be performed
 * on a `PTPDFDoc`, especially saving of the document in a way that handles common pitfalls.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFDocumentModel)
@interface PTPDFDocumentModel : NSObject

/**
 * Initializes a `PTPDFDocumentModel` instance with a PDF document.
 *
 * If the PDF document was loaded from a file, as opposed to a memory buffer, then the location of the
 * file is retrieved via `-[PTPDFDoc GetFileName]`. The file path is then used to set the model's
 * `PTPDFDocumentModel.fileURL` instance property.
 *
 * @param pdfDoc The PDF document
 *
 * @return an initialized `PTPDFDocumentModel` instance
 *
 * @see `-[PTPDFDocumentModel initWithPDFDoc:fileURL:]`
 */
- (instancetype)initWithPDFDoc:(PTPDFDoc *)pdfDoc;

/**
 * Initializes a `PTPDFDocumentModel` instance with a PDF document and file URL.
 *
 * @param pdfDoc The PDF document
 *
 * @param fileURL The URL location of the document's backing file, or `nil` if unknown
 *
 * @return an initialized `PTPDFDocumentModel` instance
 */
- (instancetype)initWithPDFDoc:(PTPDFDoc *)pdfDoc
                       fileURL:(nullable NSURL *)fileURL NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTPDFDocumentModel` instance with a file URL.
 *
 * @param fileURL The URL location of the document to be opened
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return an initialized `PTPDFDocumentModel` if the PDF document could be opened, or `nil` if an
 * error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 *
 * @see `-[PTPDFDocumentModel initWithPDFDoc:fileURL:]`
 */
- (nullable instancetype)initWithFileURL:(NSURL *)fileURL
                                   error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * The modelled PDF document.
 */
@property (nonatomic, readonly, strong) PTPDFDoc *pdfDoc;

/**
 * The URL of the PDF document's backing file.
 *
 * This file URL is used when the document is saved or when the on-disk representation of the document
 * is required.
 */
@property (nonatomic, readonly, strong, nullable) NSURL *fileURL;

/**
 * Whether the PDF document has been modified since it was opened or last saved.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, readonly, assign, getter=isModified) BOOL modified;

#pragma mark - Saving

/**
 * Returns whether a full save (non-incremental) is required for the specified PDF document.
 *
 * @param isFullSaveRequired The location where the boolean result should be stored
 *
 * @param pdfDoc The PDF document
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the full-save requirement could be determined, or `NO` if an error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
+ (BOOL)isFullSaveRequired:(out BOOL * _Nonnull)isFullSaveRequired
                 forPDFDoc:(PTPDFDoc *)pdfDoc
                     error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

/**
 * Returns whether a full save (non-incremental) is required for the PDF document.
 *
 * @param isFullSaveRequired The location where the boolean result should be stored
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the full-save requirement could be determined, or `NO` if an error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
- (BOOL)isFullSaveRequired:(out BOOL * _Nonnull)isFullSaveRequired
                     error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

/**
 * Saves the PDF document with the specified flags.
 *
 * @param flags The flags determining how the save should be performed
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the PDF document was saved successfully, or `NO` if an error occurred and the
 * document could not be saved
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
- (BOOL)savePDFDocWithFlags:(PTSaveOptions)flags
                      error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

@end

@interface PTPDFDocumentModel (Creation)

/**
 * Creates and returns a new `PTPDFDocumentModel` instance initialized with the file URL.
 *
 * @param fileURL The URL location of the document to be opened
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return an initialized `PTPDFDocumentModel` instance, or `nil` if an error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 *
 * @see `-[PTPDFDocumentModel initWithFileURL:error:]`
 */
+ (nullable instancetype)documentForFileAtURL:(NSURL *)fileURL
                                        error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

@end

NS_ASSUME_NONNULL_END
