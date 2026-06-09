//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFDocumentFile.h>
#import <Tools/PTOverrides.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFDocumentFile;
@class PTPDFDocumentManager;
@protocol PTPDFDocumentManagerDelegate;

/**
 * The domain for errors from the `PTPDFDocumentManager` class.
 */
PT_EXTERN const NSErrorDomain PTPDFDocumentManagerErrorDomain NS_SWIFT_NAME(PTPDFDocumentManager.ErrorDomain);

/**
 * Error codes in the `PTPDFDocumentManagerErrorDomain` domain.
 */
typedef NS_ERROR_ENUM(PTPDFDocumentManagerErrorDomain, PTPDFDocumentManagerErrorCode) {
    
    /**
     * The document's contents have been modified externally.
     */
    PTPDFDocumentManagerErrorExternalContentModification,
    
} NS_SWIFT_NAME(PTPDFDocumentManager.ErrorCode);

/**
 * The delegate of a `PTPDFDocumentManager` instance.
 */
PT_OBJC_RUNTIME_NAME(PDFDocumentManagerDelegate)
@protocol PTPDFDocumentManagerDelegate <NSObject>
@optional

/**
 * The document manager calls this method when the specified document needs to reload its contents.
 *
 * @param documentManager The document manager sending the message.
 *
 * @param document The document that needs to reload its contents.
 */
- (void)documentManager:(PTPDFDocumentManager *)documentManager documentNeedsReloadContents:(PTPDFDocumentFile *)document;

/**
 * The document manager calls this method when another application has modified the contents of the specified document.
 *
 * @param documentManager The document manager sending the message.
 *
 * @param document The document whose contents were modified externally.
 */
- (void)documentManager:(PTPDFDocumentManager *)documentManager handleExternalChangeToDocument:(PTPDFDocumentFile *)document withError:(NSError *)error;

- (void)documentManager:(PTPDFDocumentManager *)documentManager fileForDocument:(PTPDFDocumentFile *)document didMoveToURL:(NSURL *)newFileURL;

@end

/**
 * Instances of the `PTPDFDocumentManager` class control how documents are accessed, usually by a
 * viewer component.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFDocumentManager)
@interface PTPDFDocumentManager : NSObject <PTOverridable>

/**
 * Initializes a new `PTPDFDocumentManager` instance.
 *
 * @return an initialized `PTPDFDocumentManager` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The delegate object of the `PTPDFDocumentManager`.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, weak, nullable) id<PTPDFDocumentManagerDelegate> delegate;

#pragma mark - Documents

/**
 * The documents being managed by this `PTPDFDocumentManager`.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, readonly, copy, nullable) NSArray<PTPDFDocumentFile *> *documents;

/**
 * Creates and returns a new `PTPDFDocumentFile` instance for the file at the given URL.
 *
 * @param url The URL of the file for which a document is to be created.
 *
 * @return A new `PTPDFDocumentFile` instance for the file.
 *
 * @note The document is not added to the list of documents in `PTPDFDocumentManager.documents`.
 */
- (PTPDFDocumentFile *)makeDocumentForURL:(NSURL *)url;

/**
 * Returns the document whose file is located by the specified URL.
 *
 * @param url The URL of the document to retrieve.
 *
 * @return The document for the specified URL, or `nil` if there is no such document.
 */
- (nullable PTPDFDocumentFile *)documentForURL:(NSURL *)url;

/**
 * Adds the given document to the list of managed documents.
 *
 * @param document The document to add.
 *
 * @see `PTPDFDocumentManager.documents`
 */
- (void)addDocument:(PTPDFDocumentFile *)document;

/**
 * Removes the given document from the list of managed documents.
 *
 * @param document The document to remove.
 *
 * @see `PTPDFDocumentManager.documents`
 */
- (void)removeDocument:(PTPDFDocumentFile *)document;

#pragma mark - Document cache directory

/**
 * The URL of the directory where documents are cached.
 *
 * The document cache is used for remote (HTTP) file downloads, documents converted from other formats,
 * and any other document-related operation that needs a safe location on-disk.
 *
 * The default value of this property is the return value of the class method
 * `+[PTPDFDocumentManager defaultDocumentCacheDirectoryURLWithError:]`.
 */
@property (nonatomic, strong) NSURL *documentCacheDirectoryURL;

/**
 * Returns the URL of the default directory used for caching documents.
 *
 * @param outError On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the default document cache directory URL, or `nil` if an error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
+ (nullable NSURL *)defaultDocumentCacheDirectoryURLWithError:(out NSError * _Nullable __autoreleasing * _Nullable)outError NS_WARN_UNUSED_RESULT;

@end

NS_ASSUME_NONNULL_END
