//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

#define KEY_TITLE       @"title"
#define KEY_CHILDREN    @"hasChildren"
#define KEY_PAGENUM     @"pageNumber"
#define KEY_LEVEL       @"level"
#define KEY_COLLAPSED   @"collapsed"
#define KEY_CHILDREN_COLLAPSED @"childrenCollapsed"
#define KEY_BOOKMARK    @"_bookmark"
#define KEY_BOOKMARK_OBJ_NUM @"_bookmarkObjNum"

NS_ASSUME_NONNULL_BEGIN

@class PTOutlineViewController;

/**
 * The methods declared by the `PTOutlineViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
 * the PTOutlineViewController class.
 */
PT_OBJC_RUNTIME_NAME(OutlineViewControllerDelegate)
@protocol PTOutlineViewControllerDelegate <NSObject>
@optional

/**
 * Tells the delegate that an outline item was selected. Note that the PDF specification refers to outline items as "bookmarks",
 * which are _not_ user bookmarks. The `PTBookmark` and related classes refer to outline items, not user bookmarks.
 *
 * @param outlineViewController The `PTOutlineViewController` object informing the delegate about the bookmark's selection.
 *
 * @param bookmark A dictionary of bookmark information, with key-value pairs: {KEY_TITLE, NSString holding the bookmark's title},
 * {KEY_CHILDREN, NSNumber with a BOOL value indicating the presence of children at this node}, {KEY_BOOKMARK, PTBookmark that's the next bookmark}.
 */
- (void)outlineViewController:(PTOutlineViewController *)outlineViewController selectedBookmark:(NSDictionary *)bookmark;

/**
 * Asks the delegate if the outline item should be collapsed by default. Note that the PDF specification refers to outline items as "bookmarks",
 * which are _not_ user bookmarks. The `PTBookmark` and related classes refer to outline items, not user bookmarks.
 *
 * @param outlineViewController The `PTOutlineViewController` object asking the delegate about the bookmark's default collapsed state.
 *
 * @param bookmark A `PTBookmark` refering to the outline item.
 */
- (BOOL)outlineViewController:(PTOutlineViewController *)outlineViewController bookmarkCollapsedByDefault:(PTBookmark *)bookmark;

/**
 * Tells the delegate that the outline control wants to be closed.
 */
- (void)outlineViewControllerDidCancel:(PTOutlineViewController *)outlineViewController;

@end

/**
 * The PTOutlineViewController will display a document's outline (PDF bookmarks) that can be used to
 * navigate the document in a `PTPDFViewCtrl`. When a bookmark is selected, the controller will navigate the
 * `PTPDFViewCtrl` to that page.
 */
PT_OBJC_RUNTIME_NAME(OutlineViewController)
@interface PTOutlineViewController : UITableViewController <PTOverridable>

/**
 * Returns a new instance of a PTOutlineViewController.
 *
 * @param toolManager The `PTToolManager` object that provides the `PTPDFViewCtrl` and `PTPDFDoc` from
 * to create the outline, which will change pages when the user selects an annotation item.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * Returns a new instance of an PTOutlineViewController.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` object that provides the `PTPDFDoc` from which to create the outline,
 * and which will change pages when the user selects an annotation item.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Whether outlines are considered readonly and cannot be modified or deleted. The default value
 * is `NO`, meaning that outlines can be modified and deleted.
 *
 * @note The `PTToolManager.readonly` property is also consulted when determing if outlines can
 * be modified or deleted. When `PTToolManager.readonly` is set to `YES` that property takes
 * precedence over this property's value.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

/**
 * An object that conforms to the `PTOutlineViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTOutlineViewControllerDelegate> delegate;

/**
 * Refresh the contents of the PTOutlineViewController
 */
- (void)refresh;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
