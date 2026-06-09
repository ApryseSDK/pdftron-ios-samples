//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2023 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPDFDocumentModel.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFDocumentFile;

/**
 * Options for reading documents.
 */
typedef NSString * PTPDFDocumentReadOptionKey NS_TYPED_EXTENSIBLE_ENUM NS_SWIFT_NAME(PTPDFDocumentFile.ReadOptionKey);

/**
 * Whether the document is accessed indirectly through a cache or backup file.
 *
 * The value of this key is an `NSNumber` object containing a `BOOL` value.
 */
PT_EXTERN const PTPDFDocumentReadOptionKey PTPDFDocumentReadOptionUseCacheFile;

/**
 * The URL of the directory under which cache files are stored.
 *
 * The value of this key is an `NSURL` object.
 */
PT_EXTERN const PTPDFDocumentReadOptionKey PTPDFDocumentReadOptionCacheFilesDirectory;

/**
 * Options for writing documents.
 */
typedef NSString * PTPDFDocumentWriteOptionKey NS_TYPED_EXTENSIBLE_ENUM NS_SWIFT_NAME(PTPDFDocumentFile.WriteOptionKey);

/**
 * Flags determining how saving should be performed.
 *
 * The value of this key is an `NSNumber` object containing a `PTSaveOptions` enumeration (`int`).
 */
PT_EXTERN const PTPDFDocumentWriteOptionKey PTPDFDocumentWriteOptionSaveFlags;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFDocumentFile)
@interface PTPDFDocumentFile : NSObject

- (instancetype)initWithFileURL:(NSURL *)fileURL;

- (instancetype)initWithFileURL:(NSURL *)fileURL
        fileCoordinationEnabled:(BOOL)fileCoordinationEnabled NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * The URL of the PDF document file.
 */
@property (nonatomic, readonly, strong) NSURL *fileURL;

/**
 * The display name of the file, localized for the current locale.
 */
@property (nonatomic, readonly, copy) NSString *localizedDisplayName;

/**
 * The data model representation for the PDF document while it is open.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDocumentModel *model;

/**
 * The URL of the cache file used to indirectly access the file at `fileURL`.
 */
@property (nonatomic, readonly, strong, nullable) NSURL *cacheFileURL;

#pragma mark - File coordination

/**
 * Whether the File Coordination system is used in accessing the document.
 *
 * @note The default value of this property is `NO`.
 */
@property (nonatomic, readonly, assign, getter=isFileCoordinationEnabled) BOOL fileCoordinationEnabled;

/**
 * The presenter responsible for managing the document's file in the File Coordination system.
 *
 * The value of this property is nonnull when file coordination is enabled, otherwise `nil`.
 *
 * @see `PTPDFDocumentFile.fileCoordinationEnabled`
 */
@property (nonatomic, readonly, strong, nullable) id<NSFilePresenter> filePresenter;

#pragma mark - Opening

@property (nonatomic, copy, nullable) NSDictionary<PTPDFDocumentReadOptionKey, id> *defaultReadOptions;

- (void)openWithOptions:(nullable NSDictionary<PTPDFDocumentReadOptionKey, id> *)options
      completionHandler:(void (PT_ESCAPING ^ _Nullable)(BOOL success,
                                                        NSError * _Nullable error))completionHandler;

- (void)reloadContentsWithCompletionHandler:(void (PT_ESCAPING ^ _Nullable)(BOOL success,
                                                                            NSError * _Nullable error))completionHandler;

#pragma mark - Saving

/**
 * The default options to be used for write operations.
 */
@property (nonatomic, copy, nullable) NSDictionary<PTPDFDocumentWriteOptionKey, id> *defaultWriteOptions;

- (void)saveWithOptions:(nullable NSDictionary<PTPDFDocumentWriteOptionKey, id> *)options
      completionHandler:(void (PT_ESCAPING ^ _Nullable)(BOOL success,
                                                        NSError * _Nullable error))completionHandler;

/**
 * Saves the document to the file at the specified URL.
 *
 * @param fileURL The URL location of the file to which the document will be written.
 */
- (void)saveToFileAtURL:(NSURL *)fileURL
            withOptions:(nullable NSDictionary<PTPDFDocumentWriteOptionKey, id> *)options
      completionHandler:(void (PT_ESCAPING ^ _Nullable)(BOOL success,
                                                        NSError * _Nullable error))completionHandler;

#pragma mark - Closing

- (void)closeWithCompletionHandler:(void (PT_ESCAPING ^ _Nullable)(BOOL success,
                                                                   NSError * _Nullable error))completionHandler;

@end

/**
 * A notification that alerts observers when a document's contents need to be reloaded.
 *
 * The notification's object is the `PTPDFDocumentFile` posting the notification.
 *
 * This notification does not include a user-info dictionary.
 */
PT_EXTERN const NSNotificationName PTPDFDocumentNeedsReloadContentsNotification NS_SWIFT_NAME(PTPDFDocumentFile.needsReloadContentsNotification);

/**
 * A notification that alerts observers when a document is modified by another application.
 *
 * The notification's object is the `PTPDFDocumentFile` posting the notification.
 */
PT_EXTERN const NSNotificationName PTPDFDocumentExternalChangeNotification NS_SWIFT_NAME(PTPDFDocumentFile.externalChangeNotification);

/**
 * A notification that alerts observers when a document's file has been moved.
 *
 * The notification's object is the `PTPDFDocumentFile` posting the notification.
 */
PT_EXTERN const NSNotificationName PTPDFDocumentFileDidMoveNotification NS_SWIFT_NAME(PTPDFDocumentFile.fileDidMoveNotifcation);

typedef NSString * PTPDFDocumentNotificationUserInfoKey NS_TYPED_EXTENSIBLE_ENUM NS_SWIFT_NAME(PTPDFDocumentFile.NotificationUserInfoKey);

/**
 * A notification user info key to retrieve a URL associated with a `PTPDFDocumentFile`.
 *
 * The value for this key is an `NSURL` value.
 */
PT_EXTERN PTPDFDocumentNotificationUserInfoKey const PTPDFDocumentURLUserInfoKey NS_SWIFT_NAME(URL);

NS_ASSUME_NONNULL_END
