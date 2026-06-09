//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTUserBookmark.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object that manages the user bookmarks inside PDF documents. User bookmarks can be created with
 * the `PTUserBookmark` class and stored inside a `PTPDFDoc` with a `PTBookmarkManager` instance.
 */
PT_OBJC_RUNTIME_NAME(BookmarkManager)
@interface PTBookmarkManager : NSObject

/**
 * Returns the shared bookmark manager object.
 */
@property (nonatomic, class, readonly, strong) PTBookmarkManager *defaultManager;

/**
 * Returns the root PDF bookmark in the given `PTPDFDoc` used to store user bookmarks.
 *
 * @param doc the `PTPDFDoc` containing user bookmarks
 *
 * @param create `YES` to create the root PDF bookmark if not found, `NO` otherwise
 *
 * @return the root PDF bookmark in the given `PTPDFDoc`, or `nil` if not found and not created.
 */
- (nullable PTBookmark *)rootPDFBookmarkForDoc:(PTPDFDoc *)doc create:(BOOL)create;

/**
 * Removes the root PDF bookmark in the given `PTPDFDoc` used to store user bookmarks.
 *
 * @param doc the `PTPDFDoc` containing user bookmarks
 *
 * @return `YES` if the root bookmark was found and removed, `NO` otherwise
 */
- (BOOL)removeRootPDFBookmarkForDoc:(PTPDFDoc *)doc;

/**
 * Returns the user bookmarks for the given `PTPDFDoc`.
 *
 * @param doc the `PTPDFDoc` containing user bookmarks
 *
 * @return the user bookmarks for the given `PTPDFDoc`
 */
- (NSArray<PTUserBookmark *> *)bookmarksForDoc:(PTPDFDoc *)doc;

/**
 * Returns the user bookmarks for the given `PTPDFDoc` rooted at the specified PDF bookmark.
 *
 * @param doc the `PTPDFDoc` containing user bookmarks
 *
 * @param rootPDFBookmark the root PDF bookmark
 *
 * @return the user bookmarks for the given `PTPDFDoc` rooted at the specified PDF bookmark
 */
- (NSArray<PTUserBookmark *> *)bookmarksForDoc:(PTPDFDoc *)doc rootPDFBookmark:(nullable PTBookmark *)rootPDFBookmark;

/**
 * Saves the user bookmarks for the given `PTPDFDoc`.
 *
 * @param bookmarks the user bookmarks to save
 *
 * @param doc the `PTPDFDoc` to save the bookmarks inside
 */
- (void)saveBookmarks:(NSArray<PTUserBookmark *> *)bookmarks forDoc:(PTPDFDoc *)doc;

/**
 * Adds a user bookmark for the given `PTPDFDoc`.
 *
 * @param bookmark the user bookmark to add to the document
 *
 * @param doc the `PTPDFDoc` to add the bookmark to
 */
- (void)addBookmark:(PTUserBookmark *)bookmark forDoc:(PTPDFDoc *)doc;

/**
 * Updates the user bookmarks in a document after a page has been deleted.

 @param doc the `PTPDFDoc` containing user bookmarks to update
 @param pageObjNum the SDF object number of the deleted `PTPage`
 */
- (void)updateBookmarksForDoc:(PTPDFDoc *)doc pageDeletedWithPageObjNum:(unsigned int)pageObjNum;

/**
 * Updates the user bookmarks in a document after a page has been moved.
 *
 * @param doc the `PTPDFDoc` containing user bookmarks to update
 *
 * @param oldPageNumber the page's original page number
 *
 * @param oldPageObjNum the page's original SDF object number
 *
 * @param newPageNumber the page's new page number
 *
 * @param newPageObjNum the page's new SDF object number
 */
- (void)updateBookmarksForDoc:(PTPDFDoc *)doc pageMovedFromPageNumber:(int)oldPageNumber pageObjNum:(unsigned int)oldPageObjNum toPageNumber:(int)newPageNumber pageObjNum:(unsigned int)newPageObjNum;

#pragma mark - Import/export

/**
 * Converts users bookmarks in JSON format to a list of `PTUserBookmark` objects. The format of the
 * JSON string is:
 * {"0": "Bookmark 1", "1": "Bookmark 2"}
 *
 * @param jsonString the user bookmarks in JSON format
 *
 * @return the list of `PTUserBookmark` objects, or `nil` if the conversion failed
 */
- (nullable NSArray<PTUserBookmark *> *)bookmarksFromJSONString:(NSString *)jsonString;

/**
 * Converts a list of `PTUserBookmark` objects to a JSON format. The format of the JSON string is:
 * {"0": "Bookmark 1", "1": "Bookmark 2"}
 *
 * @param bookmarks the list of `PTUserBookmark` objects to convert
 *
 * @return the user bookmarks in JSON format, or `nil` if the conversion failed
 */
- (nullable NSString *)JSONStringFromBookmarks:(NSArray<PTUserBookmark *> *)bookmarks;

/**
 * Imports user bookmarks in JSON format to the specified document. The format of the JSON string is:
 * {"0": "Bookmark 1", "1": "Bookmark 2"}
 *
 * @param doc the `PTPDFDoc` to save the bookmarks inside
 *
 * @param jsonString the user bookmarks in JSON format
 */
- (void)importBookmarksForDoc:(PTPDFDoc *)doc fromJSONString:(NSString *)jsonString;

/**
 * Export user bookmarks in JSON format from the specified document. The format of the JSON string is:
 * {"0": "Bookmark 1", "1": "Bookmark 2"}
 *
 * @param doc the `PTPDFDoc` to export the bookmarks from
 *
 * @return the user bookmarks in JSON format, or `nil` if the document contains no bookmarks or the
 * JSON conversion failed
 */
- (nullable NSString *)exportBookmarksFromDoc:(PTPDFDoc *)doc;

@end

/**
 * Posted before bookmarks are imported into a document.
 */
PT_EXTERN const NSNotificationName PTBookmarkManagerWillImportBookmarksNotification;

/**
 * Posted after bookmarks are imported into a document.
 */
PT_EXTERN const NSNotificationName PTBookmarkManagerDidImportBookmarksNotification;

/**
 * The key for a `PTPDFDoc` object.
 */
PT_EXTERN NSString * const PTBookmarkManagerDocumentUserInfoKey;

NS_ASSUME_NONNULL_END
