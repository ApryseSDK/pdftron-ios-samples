//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

/// Keys for bookmark information in an `NSDictionary`.
typedef NSString * PTBookmarkInfoKey NS_TYPED_ENUM;

/// The key for a `NSNumber` object containing an `int`.
PT_EXPORT const PTBookmarkInfoKey PTBookmarkInfoKeyPageNumber;

/// The key for a `NSNumber` object containing an `unsigned int`.
PT_EXPORT const PTBookmarkInfoKey PTBookmarkInfoKeySDFObjNumber;

/// The key for a `NSString` object.
PT_EXPORT const PTBookmarkInfoKey PTBookmarkInfoKeyName;

/// The key for a `NSString` object (a UUID string).
PT_EXPORT const PTBookmarkInfoKey PTBookmarkInfoKeyUniqueId;

/**
 * A utility class for managing user bookmarks. Note the the PDF specification does not
 * account for user bookmarks. Therefore user bookmarks are non-portable between PDF
 * readers. PDFNet for iOS stores the bookmarks in the iOS user preferences.
 *
 * The bookmark data is an NSArray of NSDictionary-s. Each NSDictionary represents a
 * bookmark. The NSDictionary entries are:
 * {@"page-number" : NSNumber numberWithInt}, {@"sdf-obj-number" : NSNumber numberWithInt},
 * {@"name" : NSString}, {@"unique-id" : NSString (a UUID string)}
 */
PT_OBJC_RUNTIME_NAME(BookmarkUtils)
@interface PTBookmarkUtils : NSObject

/**
 * This method updates a file's bookmark data when the file is moved.
 * If this method is not called when a file is moved, its bookmarks will no longer be
 * associated with the file.
 *
 * @param oldLocation The former location of the PDF file.
 *
 * @param newLocation The present location of the PDF file.
 */
+(void)fileMovedFrom:(NSURL*)oldLocation to:(NSURL*)newLocation;

/**
 * This method saves bookmark data back to disk.
 *
 * @param bookmarkData The bookmark data. See class documentation for data structure
 * description.
 *
 * @param url The location of the PDF file.
 */
+(void)saveBookmarkData:(nullable NSArray*)bookmarkData forFileUrl:(NSURL*)url;

/**
 * Retrieves the bookmark data from disk.
 *
 * @param documentUrl The location of the PDF file.
 *
 * @return The bookmark data. See class documentation for data structure
 * description.
 */
+(NSArray<NSMutableDictionary*>*)bookmarkDataForDocument:(NSURL*)documentUrl;

/**
 * Used to update user bookmarks when the `PTPDFDoc`'s page is moved.
 *
 * @param bookmarks The current bookmarks.
 *
 * @param oldPageNumber The original position of the page.
 *
 * @param newPageNumber The new position of the page.
 *
 * @param oldSDFNumber The SDF number of the page at the original location.
 *
 * @param newSDFNumber The SDF number of the page at the new location.
 */
+(NSMutableArray<NSMutableDictionary*>*)updateUserBookmarks:(NSMutableArray<NSMutableDictionary*>*)bookmarks oldPageNumber:(unsigned int)oldPageNumber newPageNumber:(unsigned int)newPageNumber oldSDFNumber:(unsigned int)oldSDFNumber newSDFNumber:(unsigned int)newSDFNumber;

/**
 * Deletes the bookmark data for the given document.
 *
 * @param documentURL The location of the PDF file.
 */
+(void)deleteBookmarkDataForDocument:(NSURL *)documentURL;


- (instancetype)init PT_UNAVAILABLE_MSG("Utility has no instance methods.");

@end

NS_ASSUME_NONNULL_END
