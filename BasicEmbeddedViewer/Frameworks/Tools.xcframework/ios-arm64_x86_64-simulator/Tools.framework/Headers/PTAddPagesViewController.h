//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAddPagesManager.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAddPagesViewController;

/**
 * The `PTAddPagesViewController` displays a list of options for adding blank pages
 * or inserting images as pages to a document.
*/
PT_OBJC_RUNTIME_NAME(AddPagesViewController)
@interface PTAddPagesViewController : UITableViewController <PTOverridable>

/**
 * Initializes a newly created reflow view controller that scrolls horizontally.
 *
 * @param toolManager the `PTToolManager` instance that the control coordinates with
 *
 * @return The initialized reflow view controller.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;

/**
 * The tool manager used by this view.
 */
@property (nonatomic, strong, readonly) PTToolManager *toolManager;

/**
 * The `PTAddPagesManager` maintained by this view controller.
 */
@property(nonatomic,strong) PTAddPagesManager *addPagesManager;

/**
 *
 * The list of items displayed. The `title`, `image`, `target` and `action` properties are all used.
 * By default this contains the `addBlankPagesButtonItem`, the `addImagePageButtonItem`, and the `addDocumentPagesButtonItem`
 * maintained by this view controller.
 *
 */
@property(nullable,nonatomic,copy) NSArray<UIBarButtonItem *> *items;

/**
 * Used to show a `PTPageTemplateViewController` for adding blank pages.
*/
@property (nonatomic, strong) UIBarButtonItem *addBlankPagesButtonItem;

/**
 * Used to show a `UIImagePickerController` for adding blank pages.
*/
@property (nonatomic, strong) UIBarButtonItem *addImagePageButtonItem;

/**
 * Used to show the camera for adding blank pages from a photo.
*/
@property (nonatomic, strong) UIBarButtonItem *addCameraImagePageButtonItem;

/**
 * Used to show the camera for adding blank pages from scanner.
*/
@property (nonatomic, strong) UIBarButtonItem *addScannedPageButtonItem;

/**
 * Used to show a `UIDocumentPickerViewController` to insert pages from another document
 * into the current document.
*/
@property (nonatomic, strong) UIBarButtonItem *addDocumentPagesButtonItem;

/**
 * Shows a `PTPageTemplateViewController` for adding blank pages to the document.
*/
-(void)showPageTemplateViewController:(UIBarButtonItem *)sender;

/**
 * Shows a `UIImagePickerController` to insert an image as a page into the document.
*/
-(void)showImagePickerController:(UIBarButtonItem *)sender;

/**
 * Shows the camera to take a photo to add as a page into the document.
*/
- (void)showCamera:(UIBarButtonItem *)sender;

/**
 * Shows the scanner to add scanned images as pages into the document.
*/
- (void)showScanner:(UIBarButtonItem *)sender;

/**
 * Shows a `UIDocumentPickerViewController` to insert pages from another document
 * into the current document.
*/
-(void)showDocumentPickerViewController:(UIBarButtonItem *)sender;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
