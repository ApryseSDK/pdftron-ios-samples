//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFileAttachmentHandler;
@protocol PTFileAttachmentHandlerDelegate;

/**
 * A set of methods that allow a conforming class to be notified about events from a `PTFileAttachmentHandler`
 * instance.
 */
PT_OBJC_RUNTIME_NAME(FileAttachmentHandlerDelegate)
@protocol PTFileAttachmentHandlerDelegate <NSObject>
@optional

/**
 * Tells the delegate that the file attachment annotation was successfully exported to the indicated location.
 *
 * @param fileAttachmentHandler the file attachment handler that called this method
 *
 * @param fileAttachment the file attachment annotation that was exported
 *
 * @param doc the PDF document containing the file attachment
 *
 * @param exportedURL the URL of the exported file attachment
 */
- (void)fileAttachmentHandler:(PTFileAttachmentHandler *)fileAttachmentHandler didExportFileAttachment:(PTFileAttachment *)fileAttachment fromPDFDoc:(PTPDFDoc *)doc toURL:(NSURL *)exportedURL;

/**
 * Tells the delegate that the file attachment could not be exported from the PDF document.
 *
 * @param fileAttachmentHandler the file attachment handler that called this method
 *
 * @param fileAttachment the file attachment to be exported
 *
 * @param doc the PDF document containing the file attachment
 *
 * @param error an `NSError` indicating the reason that the file attachment could not be exported.
 */
- (void)fileAttachmentHandler:(PTFileAttachmentHandler *)fileAttachmentHandler didFailToExportFileAttachment:(PTFileAttachment *)fileAttachment fromPDFDoc:(PTPDFDoc *)doc withError:(NSError *)error;

@end

/**
 * The `PTFileAttachmentHandler` class handles file attachment annotations. It can be used to export
 * file attachment annotations from a document.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FileAttachmentHandler)
@interface PTFileAttachmentHandler : NSObject

/**
 * Initializes a newly created `PTFileAttachmentHandler` instance.
 *
 * @return an initialized `PTFileAttachmentHandler` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Exports the specified file attachment annotation from the given PDF document.
 *
 * @param fileAttachment the file attachment to be exported
 *
 * @param doc the PDF document containing the file attachment
 */
- (void)exportFileAttachment:(PTFileAttachment *)fileAttachment
                  fromPDFDoc:(PTPDFDoc *)doc;

/**
 * Exports the file attachment annotation from the PDF document.
 *
 * @param fileAttachment The file attachment annotation to be exported
 *
 * @param pdfDoc The PDF document containing the file attachment
 *
 * @param completion A block to be called when the file attachment has been exported. The URL of the
 * exported file is provided when the operation is successful, otherwise an error is provided that
 * details why the file attachment could not be exported. The block is called asynchronously on the
 * main queue.
 */
- (void)exportFileAttachment:(PTFileAttachment *)fileAttachment
                  fromPDFDoc:(PTPDFDoc *)pdfDoc
                  completion:(void (^ PT_ESCAPING)(NSURL * _Nullable exportedFileURL, NSError * _Nullable error))completion;

/**
 * The delegate of the file attachment handler. The delegate must adopt the
 * `PTFileAttachmentHandlerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTFileAttachmentHandlerDelegate> delegate;

#pragma mark - Helpers

/**
 * Returns the filename for the specified file attachment annotation in the given PDF document.
 *
 * @param fileAttachment The file attachment for which to get the filename
 *
 * @param pdfDoc The PDF document containing the file attachment annotation
 *
 * @param error On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the filename for the file attachment annotation, or `nil` if an error occurred
 */
+ (nullable NSString *)filenameForFileAttachment:(PTFileAttachment *)fileAttachment
                                      inDocument:(PTPDFDoc *)pdfDoc
                                       withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
