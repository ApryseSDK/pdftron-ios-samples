//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTToolManager.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTPageTemplateViewController.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <VisionKit/VisionKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Constants to identify different page template styles
 */
typedef NS_OPTIONS(NSInteger, PTPageTemplateStyle) {
    /// A blank page
    PTPageTemplateStyleBlank,
    /// A lined page
    PTPageTemplateStyleLined,
    /// A grid page
    PTPageTemplateStyleGrid,
    /// A graph page
    PTPageTemplateStyleGraph,
    /// A music page
    PTPageTemplateStyleMusic,
    /// A dotted page
    PTPageTemplateStyleDotted,
    /// An isometric dotted page
    PTPageTemplateStyleIsometricDotted
};

/**
 * An object that manages the controls for adding new pages to a document.
 * New pages can be created from blank page templates (e.g. lined, grid, dotted),
 * added from other documents, or created from images.
*/
PT_OBJC_RUNTIME_NAME(AddPagesManager)
@interface PTAddPagesManager : NSObject <PTOverridable, UIImagePickerControllerDelegate, UINavigationControllerDelegate, UIDocumentPickerDelegate, VNDocumentCameraViewControllerDelegate, PTPageTemplateViewControllerDelegate>

#pragma mark - Initializers
/**
 * Returns a new instance of a `PTAddPagesManager`.
 *
 * @param toolManager the `PTToolManager` associated with the manager.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;

/**
 * The tool manager used by this view.
 */
@property (nonatomic, strong, readonly) PTToolManager *toolManager;

#pragma mark - Actions

/**
 * Shows a `PTPageTemplateViewController` for adding blank pages to the document.
*/
-(void)showPageTemplateViewController;

/**
 * Shows a `UIImagePickerController` to insert an image as a page into the document.
*/
-(void)showImagePickerController;

/**
 * Shows the camera to take a photo to add as a page into the document.
*/
-(void)showCamera;

/**
 * Shows the camera to scan a photo to add as a page into the document.
*/
-(void)showScanner;

/**
 * Shows a `UIDocumentPickerViewController` to insert pages from another document
 * into the current document.
*/
-(void)showDocumentPickerViewController;

/**
 * The page number after which the manager will insert new pages.
 *
 * If this value is negative then the viewer's current page number will be used (default behavior).
 * If this value exceeds the number of pages in the document then the pages will
 * be inserted at the end of the document.
*/
@property(nonatomic,assign) int pageNumber;

/**
 * Whether or not the page number selection dialog is shown when adding pages.
 *
 * Defaults to `YES`.
 */
@property (nonatomic, assign) BOOL showsPageNumberDialog;

/**
 * The `UIViewController` which will be used to present the manager's UI controls.
*/
@property (weak, nullable, nonatomic) UIViewController *presentingViewController;

/**
 * The `UIBarButtonItem` used when a popover presentation is required.
*/
@property (weak, nullable, nonatomic) UIBarButtonItem *barButtonItem;

/**
 * The source view used when a popover presentation is required.
 */
@property (weak, nullable, nonatomic) UIView *sourceView;

#pragma mark - Blank Doc Creation

/**
 * The default white page background color
 */
@property (nonatomic, class, strong, readonly) UIColor *whitePageColor;

/**
 * The default yellow page background color
 */
@property (nonatomic, class, strong, readonly) UIColor *yellowPageColor;

/**
 * The default blueprint page background color
 */
@property (nonatomic, class, strong, readonly) UIColor *blueprintPageColor;

/**
 * Creates a new `PTPDFDoc` with the specified parameters.
 * @param pageTemplate The `PTPageTemplateStyle` to use as a template.
 * @param pageSize The size in inches of the document.
 * @param backgroundColor The background color of the document.
 * @param pageCount The number of pages to create.
 * @param portrait Whether or not the page layout should be in portrait.
 */
+(PTPDFDoc*)createDocWithTemplate:(PTPageTemplateStyle)pageTemplate pageSize:(CGSize)pageSize backgroundColor:(UIColor*)backgroundColor pageCount:(int)pageCount portrait:(BOOL)portrait;

/**
 * Adds all the pages from the source document to the document associated with the `PDFViewCtrl` linked to the `PTToolManager`.
 *
 * @param srcDoc The document containing the pages to add to the document.
 *
 * @param pageNumber The page number of the destination document after which to insert the pages.
 */
-(void)addPagesFromDoc:(PTPDFDoc*)srcDoc afterPageNumber:(int)pageNumber;

/**
 * This is called after pages have been added to the document associated with the `PDFViewCtrl` linked to the `PTToolManager`.
 *
 * @param pageNumbers The page numbers which were inserted to the document.
 *
 * @param pageNumber The page number of the destination document after which the pages were inserted.
 */

-(void)didAddPagesForPageNumbers:(NSIndexSet *)pageNumbers afterPageNumber:(int)pageNumber;

#pragma mark - Unavailable Initializers

- (instancetype)init PT_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder PT_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
