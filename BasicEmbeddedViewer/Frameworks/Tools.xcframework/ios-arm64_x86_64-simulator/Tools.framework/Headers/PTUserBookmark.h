//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A user bookmark for a page in a document.
 */
PT_OBJC_RUNTIME_NAME(UserBookmark)
@interface PTUserBookmark : NSObject

/**
 * Initializes a bookmark with a PDF bookmark object.
 */
- (instancetype)initWithPDFBookmark:(PTBookmark *)bookmark NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a bookmark with the given information.
 */
- (instancetype)initWithTitle:(NSString *)title pageNumber:(int)pageNumber;

/**
 * Initializes a bookmark with the given information.
 */
- (instancetype)initWithTitle:(NSString *)title pageNumber:(int)pageNumber pageObjNum:(unsigned int)pageObjNum NS_DESIGNATED_INITIALIZER;

/**
 * The underlying PDF bookmark in the document. The value will be `nil` if the user bookmark has not
 * been saved.
 */
@property (nonatomic, strong, nullable) PTBookmark *bookmark;

/**
 * The title of the bookmark.
 */
@property (nonatomic, copy) NSString *title;

/**
 * The page number of bookmark.
 */
@property (nonatomic, assign) int pageNumber;

/**
 * The SDF object number of the bookmark's page.
 */
@property (nonatomic, assign) unsigned int pageObjNum;

/**
 * Whether the bookmark has been changed.
 */
@property (nonatomic, assign, getter=isEdited) BOOL edited;


- (instancetype)init PT_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
