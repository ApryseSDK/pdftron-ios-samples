//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTToolManager.h>
#import <Tools/PTUserBookmark.h>
#import <Tools/PTBookmarkViewCell.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTBookmarkViewController;
@class PTBookmarkViewCell;

/**
 * The methods declared by the `PTBookmarkViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
 * the `PTBookmarkViewController` class.
 *
 */
PT_OBJC_RUNTIME_NAME(BookmarkViewControllerDelegate)
@protocol PTBookmarkViewControllerDelegate <NSObject>
@optional

/**
 * This method is called when a view cell will be displayed in the `PTBookmarkViewController`.
 *
 * @param bookmarkViewController The bookmark view controller that sent the message.
 *
 * @param cell The view cell that will be displayed.
 *
 * @param bookmark The bookmark being displayed.
 */
- (void)bookmarkViewController:(PTBookmarkViewController *)bookmarkViewController
                 willDisplayCell:(PTBookmarkViewCell *)cell
            forBookmark:(PTUserBookmark*)bookmark;

/**
 * Tells the delegate that a bookmark was added to the list.
 *
 * @param bookmarkViewController The `PTBookmarkViewController` object informing the delegate about the bookmark's addition.
 *
 * @param bookmark A bookmark object.
 */
- (void)bookmarkViewController:(PTBookmarkViewController *)bookmarkViewController didAddBookmark:(PTUserBookmark *)bookmark;

/**
 * Tells the delegate that a bookmark was modified.
 *
 * @param bookmarkViewController The `PTBookmarkViewController` object informing the delegate about the bookmark's modification.
 *
 * @param bookmark A bookmark object.
 */
- (void)bookmarkViewController:(PTBookmarkViewController *)bookmarkViewController didModifyBookmark:(PTUserBookmark *)bookmark;

/**
 * Tells the delegate that a bookmark was removed from the list.
 *
 * @param bookmarkViewController The `PTBookmarkViewController` object informing the delegate about the bookmark's removal.
 *
 * @param bookmark A bookmark object.
 */
- (void)bookmarkViewController:(PTBookmarkViewController *)bookmarkViewController didRemoveBookmark:(PTUserBookmark *)bookmark;

/**
 * Tells the delegate that a bookmark in the list was selected.
 *
 * @param bookmarkViewController The `PTBookmarkViewController` object informing the delegate about the bookmark's selection.
 *
 * @param bookmark A bookmark object.
 */
- (void)bookmarkViewController:(PTBookmarkViewController *)bookmarkViewController selectedBookmark:(PTUserBookmark *)bookmark;

/**
 * Tells the delegate that the bookmark control wants to be closed.
 *
 */
- (void)bookmarkViewControllerDidCancel:(PTBookmarkViewController *)bookmarkViewController;

@end

/**
 * The PTBookmarkViewController displays a list of user-created bookmarks in a document being viewed
 * by a PTPDFViewCtrl.
 */
PT_OBJC_RUNTIME_NAME(BookmarkViewController)
@interface PTBookmarkViewController : UITableViewController <PTOverridable>

/**
 * An object that conforms to the `PTBookmarkViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTBookmarkViewControllerDelegate> delegate;

/**
 * Returns a new instance of a `PTBookmarkViewController`.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of a `PTBookmarkViewController`.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * Add/remove the bookmark for a page.
 *
 * @param pageNumber The number of the page to be toggled.
 *
 * @return Whether the page has bookmark after toggling.
 */
- (BOOL)toggleBookmarkForPageNumber:(int)pageNumber;

/**
 * Check whether a page has bookmark.
 *
 * @param pageNumber The number of the page.
 *
 * @return Whether the page has bookmark.
 */
- (BOOL)hasBookmarkAtPageNumber:(int)pageNumber;

/**
 * User bookmarks
 */
@property (nonatomic, strong) NSMutableArray<PTUserBookmark *> *bookmarks;

/**
 * Whether bookmarks are considered readonly and cannot be modified or deleted. The default value
 * is `NO`, meaning that bookmarks can be modified and deleted.
 *
 * @note The `PTToolManager.readonly` property is also consulted when determing if bookmarks can
 * be modified or deleted. When `PTToolManager.readonly` is set to `YES` that property takes
 * precedence over this property's value.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

/**
 * Whether the text of newly created bookmarks is immediately editable. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL bookmarksEditableOnCreation;


-(instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
