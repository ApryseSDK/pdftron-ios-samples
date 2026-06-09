//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAddPagesViewController.h>
#import <Tools/PTAnnotationViewController.h>
#import <Tools/PTCoordinatedDocument.h>
#import <Tools/PTCustomTableViewController.h>
#import <Tools/PTDocumentOptions.h>
#import <Tools/PTDocumentTabItem.h>
#import <Tools/PTDocumentViewSettingsController.h>
#import <Tools/PTLegacyAnnotationViewController.h>
#import <Tools/PTMoreItemsViewController.h>
#import <Tools/PTNavigationHistoryManager.h>
#import <Tools/PTNavigationHistoryViewController.h>
#import <Tools/PTNavigationListsViewController.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTPageCropViewController.h>
#import <Tools/PTPageIndicatorViewController.h>
#import <Tools/PTPanelViewController.h>
#import <Tools/PTPDFDocumentFile.h>
#import <Tools/PTPDFDocumentManager.h>
#import <Tools/PTReflowSettingsViewController.h>
#import <Tools/PTReflowViewController.h>
#import <Tools/PTTabbedDocumentViewController.h>
#import <Tools/PTTextSearchViewController.h>
#import <Tools/PTThumbnailSliderViewController.h>
#import <Tools/PTThumbnailsViewController.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTTextSearchToolbarController.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#if TARGET_OS_MACCATALYST
#import <AppKit/AppKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 * The default interval used for automatic document saving, 30 seconds.
 */
PT_EXPORT const NSTimeInterval PTDocumentViewControllerSaveDocumentInterval;

/**
 * The default time delay used for automatic control hiding, 5 seconds.
 */
PT_EXPORT const NSTimeInterval PTDocumentViewControllerHideControlsInterval;

@class PTDocumentBaseViewController;
@class PTDocumentOptions;
@class PTDocumentTabItem;
@class PTPDFDocumentManager;
@class PTTabbedDocumentViewController;

/**
 * A view controller that displays a `PTPDFViewCtrl` along with other controls.
 */
PT_OBJC_RUNTIME_NAME(DocumentBaseViewController)
@interface PTDocumentBaseViewController : UIViewController
<PTOverridable,
PTPDFViewCtrlDelegate,
PTToolManagerDelegate,
PTCoordinatedDocumentDelegate,
PTPDFDocumentManagerDelegate,
PTThumbnailSliderViewDelegate,
PTOutlineViewControllerDelegate,
PTLegacyAnnotationViewControllerDelegate,
PTAnnotationViewControllerDelegate,
PTBookmarkViewControllerDelegate,
PTDigitalSignaturesViewControllerDelegate,
PTPDFLayerViewControllerDelegate,
PTReflowViewControllerDelegate,
PTDocumentViewSettingsControllerDelegate,
PTTextSearchViewControllerDelegate,
UIDropInteractionDelegate>

/**
 * Returns an initialized `PTDocumentBaseViewController`.
 *
 * @return an initialized `PTDocumentBaseViewController`.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The view controller's underlying `PTPDFViewCtrl`.
 */
@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The tool manager attached to the underlying `PTPDFViewCtrl`.
 */
@property (nonatomic, readonly, strong) PTToolManager *toolManager;

#pragma mark - Document operations

/**
 * The document manager used by this view controller.
 */
@property (nonatomic, readonly, strong) PTPDFDocumentManager *documentManager;

#pragma mark Opening

/**
 * Open a document with the given URL.
 *
 * @param url The URL to open.
 *
 */
- (void)openDocumentWithURL:(NSURL *)url;

/**
 * Open a document with the given URL and password.
 *
 * @param url The URL to open.
 *
 * @param password The password for the document.
 */
- (void)openDocumentWithURL:(NSURL *)url password:(nullable NSString *)password;

/**
 * Open a document with the given URL and options.
 *
 * @param url The URL to open
 *
 * @param options The options for the opening the document
 */
- (void)openDocumentWithURL:(NSURL *)url options:(nullable PTDocumentOptions *)options;

/**
 * Open the given `PTPDFDoc`.
 *
 * @param document The `PTPDFDoc` to open.
 *
 */
- (void)openDocumentWithPDFDoc:(PTPDFDoc *)document;

/**
 * `PTHTTPRequestOptions` that will be used when requesting remote documents over HTTP.
 * These can be used to set additional HTTP headers and control if a linearized document
 * should be downloaded in its entirety, or only the parts that are viewed.
 */
@property (nonatomic, readwrite, strong, nonnull) PTHTTPRequestOptions* httpRequestOptions;

/**
 * Specifies additional http headers which will be set on outgoing requests and when requesting
 * remote documents over HTTP.
 *
 * Headers specified in this dictionary will overwrite any (matching) existing headers in the
 * `httpRequestOptions` property.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *additionalHTTPHeaders;

/**
 * Options that will be used when converting documents with the `PTConvert` APIs via the
 * `-openDocumentWithURL:` method.
 */
@property (nonatomic, strong) PTConversionOptions *conversionOptions;

/**
 * The `PTPDFDoc` if the viewer is displaying a document opened with `openDocumentWithPDFDoc:`.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDoc *document;

/**
 * The `PTCoordinatedDocument` if the viewer opens a local file with `openDocumentWithURL:`.
 */
@property (nonatomic, readonly, strong, nullable) PTCoordinatedDocument* coordinatedDocument;

/**
 * The `PTPDFDocumentFile` instance if the viewer opens a local file with `openDocumentWithURL:`.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDocumentFile *documentFile;

/**
 * The password for the current document, only filled if the user entered a password when opening the document.
 */
@property (nonatomic, readonly, copy, nullable) NSString *documentPassword;

#pragma mark Saving

/**
 * Save the current document with the default options.
 *
 * @param completionHandler A block with code that is executed when the save operation concludes.
 * The block returns no value, and the `success` param is `YES` if the save operation succeeds, otherwise `NO`.
 */
- (void)saveDocumentWithCompletionHandler:(void (PT_ESCAPING ^ _Nullable)(BOOL success))completionHandler;

/**
 * Save the current document with the specified options.
 *
 * If the `saveOptions` include the `e_ptincremental` flag, and it is not possible to save incrementally (e.g. in the
 * case that the xref table needed to be repaired), then the incremental flag will be ignored.
 *
 * @param saveOptions The options to save the document with.
 *
 * @param completionHandler A block with code that is executed when the save operation concludes.
 * The block returns no value, and the `success` param is `YES` if the save operation succeeds, otherwise `NO`.
 */
- (void)saveDocument:(PTSaveOptions)saveOptions completionHandler:(nullable void (^)(BOOL success))completionHandler;

/**
 * Whether changes in the document are saved automatically. The default value is `YES`.
 * The document is saved on best-effort basis on a timer with a period of `automaticDocumentSavingInterval`.
 * The document is also saved when the app resigns the foreground, or this ViewController's view disappears.
 */
@property (nonatomic, assign) BOOL automaticallySavesDocument;

/**
 * The interval in seconds that the document is automatically saved.
 *
 * The default value is `PTDocumentViewControllerSaveDocumentInterval`.
 *
 * Setting the interval to `DBL_MAX` disables the timer entirely.
 */
@property (nonatomic, assign) NSTimeInterval automaticDocumentSavingInterval;


/**
 *
 * If a save is attempted, and cannot be completed, a UIAlertController is shown with the title "Saving Error".
 * The `errorMessage` string is the message detail that is displayed. The default value is "The document could not be
 * saved due to an error.".
 *
 */
@property (nonatomic, copy) NSString* saveErrorMessage;

/**
 *
 * The message shown while loading an image or any other file types that are convertible by PDFTron or loading a remote document. When the value is not set it shows "Opening PDF...".
 *
 */
@property (nonatomic, nullable, copy) NSString *documentLoadingMessage;

/**
 * Restart the automatic document saving timer with the interval specified in the
 * `automaticDocumentSavingInterval` property.
 */
- (void)restartAutomaticDocumentSavingTimer;

/**
 * Restart the automatic document saving timer with the specified interval.
 *
 * The `automaticDocumentSavingInterval` property is updated with the specified interval.
 *
 * @param interval The interval to use for automatic document saving.
 */
- (void)restartAutomaticDocumentSavingTimerWithInterval:(NSTimeInterval)interval;

/**
 * Stop the automatic document saving timer.
 */
- (void)stopAutomaticDocumentSavingTimer;

#pragma mark Backup saving

/**
 * In cases where the original document cannot be saved back to its source location, and the view
 * controller is being deallocated and its document contains unsaved changes, this property controls
 * whether a backup copy of the document is saved to disk.
 *
 * The default value of this property is `NO`.
 *
 * @see `documentBackupDirectoryURL`
 */
@property (nonatomic, assign, getter=isDocumentBackupSavingEnabled) BOOL documentBackupSavingEnabled;

/**
 * The file URL of the directory where document backups should be saved.
 *
 * The default value of this property is the application's user-visible `Documents/` directory.
 *
 * @see `documentBackupSavingEnabled`
 */
@property (nonatomic, strong, nullable) NSURL *documentBackupDirectoryURL;

#pragma mark Closing

/**
 * Closes the document after saving with the `-saveDocument:completionHandler:` method.
 *
 * @see `-closeDocumentWithCompletionHandler:`
 */
- (void)closeDocument;

/**
 * Closes the document after saving with the `-saveDocument:completionHandler:` method.
 *
 * @param completionHandler Called when the document has been successfully or unsuccessfully closed
 * as indicated by the `success` parameter.
 */
- (void)closeDocumentWithCompletionHandler:(nullable void (^)(BOOL success))completionHandler;

#pragma mark - Tabbed document view controller

/**
 * The containing tabbed document view controller, if this view controller is managed by a
 * `PTTabbedDocumentViewController` instance.
 */
@property (nonatomic, readonly, weak, nullable) PTTabbedDocumentViewController *tabbedDocumentViewController;

/**
 * The tab item representing this view controller in a `PTTabbedDocumentViewController`.
 */
@property (nonatomic, weak, nullable) PTDocumentTabItem *documentTabItem;

#pragma mark - Viewer Options

/**
 * Whether tapping on the right or left edges of the page in single page-presentation
 * mode (non-continuous) will change the current page to the next or previous page,
 * respectively.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL changesPageOnTap;

/**
 * Whether the `pdfViewCtrl` page fits between the top navigation bar and bottom
 * toolbar. When disabled, the page content will fit to the size of this view
 * controller and scroll if necessary; when enabled, the page content will fit in the
 * visible space between the bars without scrolling (at the minimum zoom scale).
 *
 * This property controls the view controller's `edgesForExtendedLayout` property:
 * the `UIRectEdgeTop` and `UIRectEdgeBottom` values are excluded from that bitmask
 * property when the `pageFitsBetweenBars` property is enabled.
 *
 * The `isTranslucent` property of the `PTThumbnailSliderViewController.toolbar` is also
 * affected by the `pageFitsBetweenBars` property: when this property is enabled, the
 * thumbnail slider's toolbar is set to be non-translucent. Otherwise, the toolbar is
 * translucent.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic) BOOL pageFitsBetweenBars PT_UNAVAILABLE_MSG("This API is no longer availble.");

/**
 * Whether night mode is enabled for the `pdfViewCtrl`. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isNightModeEnabled) BOOL nightModeEnabled;

/**
 * Controls if the `ThumbnailSlider` is enabled.
 *
 * @see `thumbnailSliderEnabled`
 */
@property (nonatomic, assign, getter=isBottomToolbarEnabled) BOOL bottomToolbarEnabled PT_DEPRECATED_MSG(7.2, "Use thumbnailSliderEnabled instead");

/**
 * Controls if the `thumbnailSliderController` is enabled.
 *
 * The default value is `NO`.
 */
@property (nonatomic, getter=isThumbnailSliderEnabled) BOOL thumbnailSliderEnabled;

/**
 * Controls if the `PTPageIndicatorViewController` is enabled. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isPageIndicatorEnabled) BOOL pageIndicatorEnabled;

/**
 * Whether the `PTPageIndicatorViewController` is shown when the current page changes. The default
 * value is `YES`.
 */
@property (nonatomic, assign) BOOL pageIndicatorShowsOnPageChange;

/**
 * Whether the `PTPageIndicatorViewController` is shown with the navigation bar and toolbars. The
 * default value is `YES`.
 */
@property (nonatomic, assign) BOOL pageIndicatorShowsWithControls;

/**
 * Whether the `PTPageIndicatorViewController` is always visible. If `false`, the indicator will fade away when the toolbars hide, or after a short period of time looking at the same page.
 * The default value is `NO`.
 */
@property (nonatomic, assign) BOOL pageIndicatorAlwaysVisible;

#pragma mark - Navigation

/**
 * The `PTNavigationHistoryManager` used to track user navigation (link following, go-to-page, etc.)
 * within the document.
 */
@property (nonatomic, readonly, strong) PTNavigationHistoryManager *navigationHistoryManager;

/**
 * The `PTNavigationHistoryViewController` instance used by this view controller.
 */
@property (nonatomic, readonly, strong) PTNavigationHistoryViewController *navigationHistoryViewController;

/**
 * Whether the navigation history view shown by the `navigationHistoryViewController` is enabled.
 * Set the value of this property to `NO` to disable navigation history and hide the navigation
 * history user interface.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isNavigationHistoryEnabled) BOOL navigationHistoryEnabled;

#pragma mark View controllers

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTAnnotationViewController`
 */
@property (nonatomic, assign, getter=isAnnotationListHidden) BOOL annotationListHidden;

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTOutlineViewController`
 */
@property (nonatomic, assign, getter=isOutlineListHidden) BOOL outlineListHidden;

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTBookmarkViewController`
 */
@property (nonatomic, assign, getter=isBookmarkListHidden) BOOL bookmarkListHidden;

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTDigitalSignaturesViewController`
 */
@property (nonatomic, assign, getter=isDigitalSignatureValidationListHidden) BOOL digitalSignatureValidationListHidden;

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTPDFLayerViewController`
 */
@property (nonatomic, assign, getter=isPDFLayerListHidden) BOOL pdfLayerListHidden;

#pragma mark - Panel view controller

/**
 * The panel view controller used to display child view controllers as resizable panels.
 */
@property (nonatomic, readonly, strong) PTPanelViewController *panelViewController;

#pragma mark - Bar button items

/**
* Shows a `PTReflowViewController`.
*/
@property (nonatomic, readonly, strong) UIBarButtonItem *readerModeButtonItem;

/**
 * Shows the `PTTextSearchViewController` toolbar for text search.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *searchButtonItem;

/**
 * Shows options for exporting the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *exportButtonItem;

/**
 * Exports a copy of the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *exportCopyButtonItem;

/**
 * Exports a flattened copy of the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *exportFlattenedCopyButtonItem;

/**
 * Exports a reduced file size copy of the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *exportReducedFileSizeCopyButtonItem;

/**
 * Exports a cropped copy of the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *exportCroppedCopyButtonItem;



/**
 * Shows a `UIDocumentInteractionController` for the current document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *shareButtonItem;

/**
 * Shows a `PTDocumentViewSettingsController` to control the view settings.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *settingsButtonItem;

/**
 * Shows a `PTToolsSettingsViewController` to control the view settings.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *appSettingsButtonItem;

/**
 * Shows a `PTThumbnailsViewController` for the current document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *thumbnailsButtonItem;

/**
 * Shows a `PTNavigationListsViewController` with outline, annotations, and bookmarks view controllers.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *navigationListsButtonItem;

/**
 * Shows the `PTMoreItemsViewController`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *moreItemsButtonItem;

/**
 * Shows the `PTAddPagesViewController`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *addPagesButtonItem;

/**
 * Adds a bookmark to the current page, or removes the existing bookmark of the current page.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *bookmarkPageButtonItem;

#pragma mark - Viewer button visibility

/**
 * Controls the visibility of the `readerModeButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isReaderModeButtonHidden) BOOL readerModeButtonHidden;

/**
 * Controls the visibility of the `settingsButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isViewerSettingsButtonHidden) BOOL viewerSettingsButtonHidden;

/**
 * Controls the visibility of the `appSettingsButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isAppSettingsButtonHidden) BOOL appSettingsButtonHidden;

/**
 * Controls the visibility of the `shareButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isShareButtonHidden) BOOL shareButtonHidden;

/**
 * Controls the visibility of the `searchButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isSearchButtonHidden) BOOL searchButtonHidden;

/**
 * Controls the visibility of the export button in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isExportButtonHidden) BOOL exportButtonHidden;

/**
 * Controls the visibility of the `moreItemsButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isMoreItemsButtonHidden) BOOL moreItemsButtonHidden;

/**
 * Controls the visibility of the `addPagesButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isAddPagesButtonHidden) BOOL addPagesButtonHidden;

/**
 * Controls the visibility of the `bookmarkPageButtonItem` in the navigation bar, bottom toolbar.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, getter=isBookmarkPageButtonHidden) BOOL bookmarkPageButtonHidden;

/**
 * Controls the visibility of the `thumbnailsButtonItem` in the navigation bar, bottom toolbar, and
 * more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isThumbnailBrowserButtonHidden) BOOL thumbnailBrowserButtonHidden;

/**
 * Controls the visibility of the `navigationListsButtonItem` in the navigation bar, bottom toolbar,
 * and more items list.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isNavigationListsButtonHidden) BOOL navigationListsButtonHidden;

#pragma mark - Toolbar items

/**
 * The toolbar items associated with the view controller.
 *
 * The getter for this property returns `-toolbarItemsForSizeClass:` for the current
 * horizontal user interface size class, and the setters uses
 * `-setToolbarItems:forSizeClass:animated:` to set the toolbar items for all
 * user interface size classes.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *toolbarItems;

/**
 * Returns the `toolbarItems` for the given horizontal user interface size class.
 *
 * @param sizeClass the horizontal user interface size class for which to get the list of items
 *
 * @return the `toolbarItems` for the given horizontal user interface size class
 */
- (nullable NSArray<UIBarButtonItem *> *)toolbarItemsForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

/**
 * Sets the `toolbarItems` used for the given horizontal size class.
 *
 * @param toolbarItems the toolbar items to use
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @param animated whether to animate the change
 */
- (void)setToolbarItems:(nullable NSArray<UIBarButtonItem *> *)toolbarItems forSizeClass:(UIUserInterfaceSizeClass)sizeClass animated:(BOOL)animated;

#pragma mark - More items

/**
 * The items currently shown by the `moreItemsViewController` in a list-style interface
 * for the current trait collection.
 *
 * The getter for this property returns `-moreItemsForSizeClass:` for the current
 * horizontal user inteface size class, and the setter uses `-setMoreItems:forSizeClass:`
 *  to set the items for all user interface size classes.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *moreItems;

/**
 * Returns the `moreItems` shown by the `moreItemsViewController` for the given
 * horizontal user interface size class.
 *
 * @param sizeClass the horizontal user interface size class for which to get the list
 * of items
 *
 * @return the items shown by the `moreItemsViewController` for the given horizontal
 * user interface size class
 */
- (nullable NSArray<UIBarButtonItem *> *)moreItemsForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

/**
 * Sets the `moreItems` shown by the `moreItemsViewController` for the given horizontal
 * user interface size class.
 *
 * @param moreItems the items to show
 *
 * @param sizeClass the horizontal user interface size class
 */
- (void)setMoreItems:(nullable NSArray<UIBarButtonItem *> *)moreItems forSizeClass:(UIUserInterfaceSizeClass)sizeClass;

#pragma mark - Export items

/**
 * The items currently shown by the `moreItemsViewController`.
 *
 * The getter for this property returns `-moreItemsForSizeClass:` for the current
 * horizontal user inteface size class, and the setter uses `-setMoreItems:forSizeClass:`
 *  to set the items for all user interface size classes.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *exportItems;

#pragma mark - Bar button item updating behavior

/**
 * Whether the viewer should automatically update the visibility and other properties of its
 * bar button items based on its current state.
 *
 * This property is enabled by default.
 */
@property (nonatomic, assign) BOOL automaticallyUpdatesBarButtonItems;

/**
 * Whether the `searchButtonItem` is automatically shown and hidden depending on whether searching
 * in the document is currently supported.
 *
 * This property is enabled by default.
 */
@property (nonatomic, assign) BOOL automaticallyUpdatesSearchButtonVisibility;

#pragma mark - Reflow/reader settings

/**
 * The `PTReflowSettingsViewController` instance used to display settings controlling the behavior
 * of reflow/reader mode.
 */
@property (nonatomic, readonly, strong) PTReflowSettingsViewController *reflowSettingsViewController;

/**
 * Presents the `reflowSettingsViewController` from the `sender`.
 */
- (void)showReflowSettings:(nullable id)sender;

/**
 * Shows the `reflowSettingsViewController`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *reflowSettingsButtonItem;

/**
 * Controls the visibility of the `reflowSettingsButtonItem` in the navigation bar.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, getter=isReflowSettingsButtonHidden) BOOL reflowSettingsButtonHidden;

/**
 * Whether the `reflowSettingsButtonItem` is automatically shown and hidden when reflow/reader mode
 * is toggled.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL automaticallyHidesReflowSettingsButton;

/**
 * Shows the `reflowSettingsViewController`.
 *
 * @see `reflowSettingsButtonItem`
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *reflowSettingButtonItem PT_DEPRECATED_MSG(9.3.1, "Use reflowSettingsButtonItem instead");

/**
 * Controls the visibility of the `reflowSettingButtonItem` in the navigation bar.
 *
 * The default value of this property is `YES`.
 *
 * @see `reflowSettingsButtonHidden`
 */
@property (nonatomic, getter=isReflowSettingButtonHidden) BOOL reflowSettingButtonHidden PT_DEPRECATED_MSG(9.3.1, "Use reflowSettingsButtonItem instead");

#pragma mark - Controls

/**
 * The `UIActivityViewController` used to present action and sharing activities
 * for the current document.
 */
@property (nonatomic, strong, nullable) UIActivityViewController *activityViewController;

/**
 * The navigation lists view controller managed by this view controller.
 */
@property (nonatomic, strong) PTNavigationListsViewController *navigationListsViewController;

/**
 * Whether the navigation lists view controller is always shown as a modal presentation. When set to
 * `NO`, the view controller is shown as a docked panel on iPads when there is sufficient horizontal
 * space.
 * The default value is `NO`.
 */
@property (nonatomic, assign) BOOL alwaysShowNavigationListsAsModal;

/**
 * Shows the `navigationListsViewController`.
 */
- (void)showNavigationLists;

/**
 * The `PTThumbnailsViewController` view controller managed by this view controller.
 */
@property (nonatomic, strong) PTThumbnailsViewController *thumbnailsViewController;

/**
 * Hides any presented view controllers and shows the `thumbnailsViewController`.
 */
- (void)showThumbnailsController;

/**
 * The `PTTextSearchViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTTextSearchViewController *textSearchViewController;

/**
 * Hides any presented view controllers and shows the `textSearchViewController`.
 */
- (void)showSearchViewController;

#pragma mark Text search toolbar controller

/**
 * The text search toolbar controller used by this view controller.
 */
@property (nonatomic, readonly, strong, nullable) PTTextSearchToolbarController *textSearchToolbarController;

/**
 * Whether to use the `textSearchToolbarController` for text search.
 *
 * The default value of this property is `NO`
 */
@property (nonatomic, assign) BOOL useTextSearchToolbarController;

/**
 * The `PTPageCropViewController` view controller managed by this view controller.
 */
@property (nonatomic, strong) PTPageCropViewController *pageCropViewController;

/**
 * Shows a dialog to select a page crop mode option.
 */
- (void)showPageCropOptions:(id __nullable)sender;

/**
 * Hides any presented view controllers and shows the `pageCropViewController`.
 */
- (void)showPageCropViewController;

PT_IGNORE_WARNINGS_BEGIN("deprecated-declarations")

/**
 * The `PTThumbnailSliderViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTThumbnailSliderViewController *thumbnailSliderController;

PT_IGNORE_WARNINGS_END

/**
 * The `PTPageIndicatorViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTPageIndicatorViewController *pageIndicatorViewController;

/**
 * The `PTDocumentViewSettingsController` managed by this view controller.
 */
@property (nonatomic, strong) PTDocumentViewSettingsController *settingsViewController;

/**
 * The `PTReflowViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTReflowViewController *reflowViewController;

/**
 * The `PTMoreItemsViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTMoreItemsViewController *moreItemsViewController;

/**
 * Shows the `moreItemsViewController` in a popover presentation.
 */
- (void)showMoreItems:(id)sender;

/**
 * The `PTAddPagesViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTAddPagesViewController *addPagesViewController;

/**
 * Shows the `settingsViewController` in a popover presentation from the specified UIBarButtonItem.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 */
- (void)showSettings:(id)sender;

/**
 * Shows the `settingsViewController` in a popover presentation from the specified screen rect.
 *
 * @param screenRect the rectangle in which to anchor the popover.
 */
- (void)showSettingsFromScreenRect:(CGRect)screenRect;

/**
 * Shows the `addPagesViewController` in a popover presentation from the specified UIBarButtonItem.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 */
- (void)showAddPagesView:(id)sender;

/**
 * Shows the `addPagesViewController` in a popover presentation from the specified screen rect.
 *
 * @param screenRect the rectangle in which to anchor the popover.
 */
- (void)showAddPagesViewFromScreenRect:(CGRect)screenRect;

/**
 * Creates an activity alert with the given title
 * 
 * @param title the text to be displayed on the alert
 */
- (UIViewController *)createActivityAlertWithTitle:(NSString *)title;

/**
 * Called when `shareButtonItem` is tapped
 */
- (void)showShareActions: (UIBarButtonItem*)barButtonItem;

/**
 * Shares a copy of the document in a `UIActivityViewController`.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 *
 * @param flattening whether annotations in the document should be flattened before sharing.
 */
- (void)shareCopy:(id)sender withFlattening:(BOOL)flattening;

/**
 * Shares a copy of the document in a `UIActivityViewController`.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 *
 * @param flattening whether annotations in the document should be flattened before sharing.
 *
 * @param targetFileName The file name of the exported document without extension.
 */
- (void)shareCopy:(id)sender withFlattening:(BOOL)flattening targetFileName:(nullable NSString *)targetFileName;

/**
 * Shares a copy of the document in a `UIActivityViewController`.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 *
 * @param flattening whether annotations in the document should be flattened before sharing.
 */
-(void)shareCopy:(id)sender withFlattening:(BOOL)flattening completionHandler:(nullable void(^)(BOOL success))completionHandler;

/**
 * Shares a copy of the document in a `UIActivityViewController`.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 *
 * @param flattening whether annotations in the document should be flattened before sharing.
 *
 * @param targetFileName The file name of the exported document without extension.
 */
- (void)shareCopy:(id)sender withFlattening:(BOOL)flattening targetFileName:(nullable NSString *)targetFileName completionHandler:(nullable void(^)(BOOL success))completionHandler;;

/**
 * Shares a copy of the document in a `UIActivityViewController`.
 *
 * @param screenRect the rectangle in which to anchor the popover.
 *
 * @param flattening whether annotations in the document should be flattened before sharing.
 */
-(void)shareCopyFromScreenRect:(CGRect)screenRect withFlattening:(BOOL)flattening;

/**
 * This function is called when export as identical copy button in overflow menu is tapped
 */
-(void)exportIdenticalCopySelected;

/**
 * This function is called when export as flattened copy button in overflow menu is tapped
 */
-(void)exportFlattenedCopySelected;

/**
 * Shares a copy of the document in a `UIActivityViewController`.
 *
 * @param pdfDoc the `PTPDFDoc` to share.
 *
 * @param url the file URL of the document.
 *
 * @param sender the object (usually a `UIBarButtonItem` or `UIView`) on which to anchor the popover.
 *
 * @param requiresSave whether the document needs to be saved before sharing.
 */
-(void)shareDocument:(PTPDFDoc*)pdfDoc with:(nullable NSURL*)url from:(id)sender requiresSave:(BOOL)requiresSave;

/**
 * The `PTCustomTableViewController` managed by this view controller for showing export options.
 */
@property (nonatomic, strong) PTCustomTableViewController *exportTableViewController;

#pragma mark - Hiding user interface controls

#pragma mark Bar-hiding behavior

/**
 * Whether the controls are toggled in response to an otherwise unhandled tap.
 *
 * The default value of this property is `YES`.
 *
 * @see `controlsHidden`
 * @see `hidesNavigationBar`
 * @see `hidesBottomBar`
 */
@property (nonatomic, assign) BOOL hidesControlsOnTap;

/**
 * Whether the `isNavigationBarHidden` property of this view controller's containing
 * `UINavigationController` is controlled by this view controller.
 *
 * When enabled, this view controller will update the `UINavigationController.isNavigationBarHidden`
 * property as part of its bar-hiding (and -showing) behavior. Otherwise, this view controller will
 * not update the `isNavigationBarHidden` property and it is the responsibility of users of this
 * class to ensure that the bars are consistent with the desired behavior and appearance.
 *
 * The default value of this property is `YES`.
 *
 * @see `hidesBottomBar`
 */
@property (nonatomic, assign) BOOL hidesNavigationBar;

/**
 * Whether the `isToolbarHidden` property of this view controller's `UINavigationController` is
 * controlled by this view controller.
 *
 * When enabled, this view controller will update the `UINavigationController.isToolbarHidden`
 * property as part of its bar-hiding (and -showing) behavior. Otherwise, this view controller will
 * not update the `isToolbarHidden` property and it is the responsibility of users of this class to
 * ensure that the bars are consistent with the desired behavior and appearance.
 *
 * The default value of this property is `YES`.
 *
 * @see `hidesNavigationBar`
 */
@property (nonatomic, assign) BOOL hidesBottomBar;

/**
 * Whether the navigation bar, toolbars, and other controls are hidden. When hiding or showing controls,
 * the `hidesNavigationBar` and `hidesBottomBar` properties are respected.
 *
 * The default value of this property is `NO`.
 *
 * @see `hidesNavigationBar`
 * @see `hidesBottomBar`
 */
@property (nonatomic, assign) BOOL controlsHidden;

/**
 * Sets whether the controls are hidden.
 *
 * For animated transitions, the duration of the animation is specified by the value in the
 * `UINavigationControllerHideShowBarDuration` constant.
 *
 * @param hidden Specify `YES` to hide the controls or `NO` to show them
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * controls to appear immediately.
 */
- (void)setControlsHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Whether the find text toolbar is hidden. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isSearchViewControllerHidden) BOOL searchViewControllerHidden;

/**
 * Whether the thumbnail slider control is hidden. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isThumbnailSliderHidden) BOOL thumbnailSliderHidden;

/**
 * Sets whether the thumbnail slider control is hidden.
 *
 * For animated transitions, the duration of the animation is specified by the value in the
 * `UINavigationControllerHideShowBarDuration` constant.
 *
 * @param hidden Specify `YES` to hide the thumbnail slider or `NO` to show it
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * control to appear immediately
 */
- (void)setThumbnailSliderHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Whether the page indicator control is hidden. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isPageIndicatorHidden) BOOL pageIndicatorHidden;

/**
 * Sets whether the page indicator control is hidden.
 *
 * @param hidden Specify `YES` to hide the page indicator or `NO` to show it.
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * control to appear immediately.
 */
- (void)setPageIndicatorHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Whether the reflow control is hidden. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isReflowHidden) BOOL reflowHidden;

/**
 * Controls the visibility of the activity indicator i.e progress spinner while loading the document.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL hidesProgressSpinner;

#pragma mark Automatic control hiding

/**
 * Whether the controls are hidden automatically after a period of time. The default value is `NO`.
 *
 * The `automaticControlHidingDelay` is used to specify the time delay.
 */
@property (nonatomic, assign) BOOL automaticallyHidesControls PT_DEPRECATED_MSG(7.0.3, "Use automaticallyHideToolbars");

/**
* Whether the controls are hidden automatically after a period of time. The default value is `NO`.
*
* The `automaticControlHidingDelay` is used to specify the time delay.
*/
@property (nonatomic, assign) BOOL automaticallyHideToolbars;

/**
 * The number of seconds to wait before automatically hiding the controls. The default value is
 * `PTDocumentViewControllerHideControlsInterval`.
 */
@property (nonatomic, assign) NSTimeInterval automaticControlHidingDelay;

/**
 * Restart the automatic control hiding timer with the delay specified in the
 * `automaticControlHidingDelay` property.
 */
- (void)restartAutomaticControlHidingTimer;

/**
 * Restart the automatic control hiding timer with the specified delay.
 *
 * The `automaticControlHidingDelay` property is updated with the specified delay.
 *
 * @param delay The delay to use for automatic control hiding.
 */
- (void)restartAutomaticControlHidingTimerWithDelay:(NSTimeInterval)delay;

/**
 * Stop the automatic control hiding timer.
 */
- (void)stopAutomaticControlHidingTimer;

/**
 * Whether the controls should be hidden in response to the given timer firing.
 *
 * The default implementation of this method returns the value of the
 * `automaticallyHideToolbars` property.
 */
- (BOOL)shouldHideControlsFromTimer:(NSTimer *)timer;

/**
 * Flattened document exporting
 *
 * @param flattening Whether the document should be flattened before exporting.
 *
 * @param targetFileName The desired name of the output file. If this is `nil` then the filename of the document in the viewer will be used.
 *
 * @param completionHandler The completion handler to be called when the export is finished. If the
 * document was processed successfully then the `exportedDocURL` parameter will be the URL of the exported file, otherwise the `error`
 * parameter contains more information about the failure.
 */
- (void)exportDocWithFlattening:(BOOL)flattening targetFileName:(nullable NSString *)targetFileName withCompletionHandler:(void (^)(NSURL * _Nullable exportedDocURL, NSError * _Nullable))completionHandler;

/**
 * Returns an object initialized from data in a given unarchiver.
 */
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

#pragma mark - Catalyst

#if TARGET_OS_MACCATALYST

/**
 * The `NSToolbar` managed by this view controller
 */
@property (nonatomic, strong) NSToolbar *macToolbar API_AVAILABLE(ios(13.0));

@property (nullable, nonatomic, copy) NSArray<NSToolbarItemIdentifier> *toolbarAllowedItemIdentifiers;
@property (nullable, nonatomic, copy) NSArray<NSToolbarItemIdentifier> *toolbarDefaultItemIdentifiers;

/**
 * Shows a `PTNavigationListsViewController` with outline, annotations, and bookmarks view controllers.
 */
@property (nonatomic, readonly, strong) NSToolbarItem *navigationListsToolbarItem;

/**
 * Shows a `PTThumbnailsViewController` for the current document.
 */
@property (nonatomic, readonly, strong) NSToolbarItem *thumbnailsToolbarItem;

/**
 * Changes the active tool to the freehand markup tool (`PTFreeHandCreate` or `PTPencilDrawingCreate`).
 */
@property (nonatomic, readonly, strong) NSToolbarItem *freehandToolbarItem;

/**
 * Shows the `PTTextSearchViewController` toolbar for text search.
 */
@property (nonatomic, readonly, strong) NSToolbarItem *searchToolbarItem;

/**
 * Shows the `PTReflowSettingsViewController` toolbar for text search.
 */
@property (nonatomic, readonly, strong) NSToolbarItem *reflowSettingToolbarItem;

/**
 * Shows a `PTReflowViewController`.
 */
@property (nonatomic, readonly, strong) NSToolbarItem *reflowToolbarItem;

/**
 * Shows the `PTAnnotationToolbar` toolbar for annotating.
 */
@property (nonatomic, readonly, strong) NSToolbarItem *annotationToolbarItem;

/**
 * The `UIMenu` used to control the edit functions (e.g. copy, paste) for this view controller.
 */
@property (nonatomic, readonly, strong) UIMenu *editMenu;

/**
 * The `UIMenu` used to control the visibility of the navigation lists panel for this view controller.
 */
@property (nonatomic, readonly, strong) UIMenu *navigationListsMenu;

/**
 * The `UIMenu` used to control the view modes for this view controller.
 */
@property (nonatomic, readonly, strong) UIMenu *viewModesMenu;

/**
 * The `UIMenu` used to toggle additional views for this view controller.
 * e.g. enabling reader mode, or displaying the annotation toolbar.
 */
@property (nonatomic, readonly, strong) UIMenu *additionalViewMenu;

/**
 * The `UIMenu` used to provide shortcuts to navigate the document for this view controller.
 */
@property (nonatomic, readonly, strong) UIMenu *navigateDocMenu;

/**
 * The `UIMenu` used to provide shortcuts to annotate the document for this view controller.
 */
@property (nonatomic, readonly, strong) UIMenu *annotateMenu;

#endif

@end

#if TARGET_OS_MACCATALYST
@interface PTDocumentBaseViewController () <NSToolbarDelegate>
@end
#endif

/**
 * Subclasses of this class can override these methods in order to customize the class's default
 * behaviour.
 */
@interface PTDocumentBaseViewController (SubclassingHooks)

#pragma mark - Document opening state

/**
 * This method is called when a document has been successfully opened in this
 * view controller.
 */
- (void)didOpenDocument;

/**
 * This method is called when a document could not be opened in this view controller.
 *
 * @param error The error object describing the failure. May be `nil` if information
 * regarding the failure was not available
 */
- (void)handleDocumentOpeningFailureWithError:(nullable NSError *)error;

/**
 * This method is called when the view controller enters an invalid state.
 *
 * In response, the document could be re-opened or this view controller could be
 * closed or dismissed.
 */
- (void)didBecomeInvalid;

#pragma mark - Saving

/**
 * This method is called before the specified document is saved.
 *
 * @param pdfDoc The PDF document that will be saved.
 */
- (void)willSaveDocument:(PTPDFDoc *)pdfDoc;

/**
 * This method is called after the specified document is saved successfully.
 *
 * @param pdfDoc The PDF document that was saved.
 */
- (void)didSaveDocument:(PTPDFDoc *)pdfDoc;

/**
 * This method is called if there was an error while saving the specified document.
 *
 * @param pdfDoc The PDF document that could not be saved.
 *
 * @param error The error that occurred while saving the document.
 */
- (void)didFailSavingDocument:(PTPDFDoc *)pdfDoc
                    withError:(NSError *)error;

#pragma mark - Leading Panel

/**
 * This method is called when the panel is opened.
 *
 */
- (void)didShowLeadingPanelViewController:(UIViewController *)viewController;

/**
 * This method is called when the panel is closed.
 *
 */
- (void)didDismissLeadingPanelViewController:(UIViewController *)viewController;

#pragma mark - Cached document handling

/**
 * Returns whether the cached document at the given temporary URL should be exported
 * to a different permanent location. The temporary URL does not point to a
 * user-visible location and if the cached document is not exported it may be deleted
 * by the system at any time.
 *
 * The default implementation of this method returns `YES`.
 *
 * @param cachedDocumentURL the temporary URL of the cached document
 *
 * @return `YES` if the cached document should be exported, `NO` otherwise.
 */
- (BOOL)shouldExportCachedDocumentAtURL:(NSURL *)cachedDocumentURL;

/**
 * Returns the destination URL for the document at the given source URL location. If
 * `nil` is returned from this method, the document will be copied to the directory returned by the
 * `-directoryForExportingCachedDocumentAtURL:` method.
 *
 * The default implementation of this method returns `nil`.
 *
 * @param sourceURL The source URL of the document
 *
 * @return the destination URL for the document
 */
- (nullable NSURL *)destinationURLforDocumentAtURL:(NSURL *)sourceURL;

/**
 * The directory returned by this method will be used as the destination for the specified cache
 * document when it is exported.
 *
 * The default directory is the user-visible Documents directory inside the containing app's sandbox.
 *
 * @param cachedDocumentURL The URL of the cached document
 *
 * @return The directory to use for the exported copy of the document.
 */
- (NSURL *)directoryForExportingCachedDocumentAtURL:(NSURL *)cachedDocumentURL;

/**
 * Returns whether the cached document at the given URL should be deleted. If the cached
 * document has been exported to a different location, as indicated by the
 * `-shouldExportCachedDocumentAtURL:` and `-destinationURLforDocumentAtURL:` methods,
 * the original copy of the document can be deleted by returning `YES` for this method.
 *
 * If it is desired that HTTP(S) documents should not be re-downloaded unless necessary
 * (ie. unless the remote file has changed since it was last downloaded), then the
 * cached document should not be deleted.
 *
 * The default implementation of this method returns `NO`.
 *
 * @param cachedDocumentURL The URL of the cached document
 */
- (BOOL)shouldDeleteCachedDocumentAtURL:(NSURL *)cachedDocumentURL;

#pragma mark - Converted document handling

/**
 * This method is called when streaming conversion begins for a document.
 *
 * @param documentURL The URL of the source document that will be converted.
 * @param conversionOptions The options for the conversion.
 * @param documentConversion The document-conversion object representing the conversion operation.
 */
- (void)didBeginStreamingConversionOfDocumentAtURL:(NSURL *)documentURL
                                       withOptions:(PTConversionOptions *)conversionOptions
                                documentConversion:(PTDocumentConversion *)documentConversion;

/**
 * This method is called when streaming conversion ends for a document.
 *
 * @param documentURL The URL of the source document that was converted.
 * @param documentConversion The document-conversion object representing the conversion operation.
 */
- (void)didEndStreamingConversionOfDocumentAtURL:(NSURL *)documentURL
                          withDocumentConversion:(PTDocumentConversion *)documentConversion;

/**
 * Returns whether the document converted from the specified URL should be saved automatically.
 *
 * The default implementation of this method returns `YES`.
 *
 * @param sourceURL The URL of the source document that was converted.
 * @param documentConversion The document-conversion object representing the conversion operation.
 *
 * @return `YES` if the converted document should be saved automatically; `NO` otherwise.
 */
- (BOOL)shouldAutomaticallySaveDocumentConvertedFromSourceURL:(NSURL *)sourceURL
                                       withDocumentConversion:(PTDocumentConversion *)documentConversion;

/**
 * Saves the document converted by the specified conversion object.
 *
 * @param documentConversion The document-conversion object for the document to be saved.
 */
- (void)saveDocumentFromDocumentConversion:(PTDocumentConversion *)documentConversion;

/**
 * Returns whether the converted document at the specified URL should be editable by the user after
 * the document has been converted.
 *
 * The default implementation of this method returns `YES` to allow editing of all converted documents
 * after conversion.
 *
 * @param convertedDocumentURL The URL of the converted document.
 * @param sourceDocumentURL The URL of the original document.
 *
 * @return `YES` if the converted document should be editable automatically; `NO` otherwise.
 */
- (BOOL)shouldAutomaticallyAllowEditingOfConvertedDocumentAtURL:(NSURL *)convertedDocumentURL
                                              sourceDocumentURL:(NSURL *)sourceDocumentURL;

#pragma mark - Control hiding

/**
 * Returns whether the controls should be hidden in response to a timer (if the
 * `automaticallyHidesControls` property is enabled) or user tap (if the
 * `hidesControlsOnTap` property is enabled).
 *
 * The default implementation of this method returns `YES` if this view controller is
 * not currently presenting another view controller and does not have another
 * modal-type control active.
 *
 * @return `YES` if the view controller's controls should be hidden, `NO` otherwise
 */
- (BOOL)shouldHideControls;

/**
 * Returns whether the view controller's controls should be shown in response to a user
 * tap (if the `hidesControlsOnTap` property is enabled).
 *
 * The default implementation of this method return `YES` if this view controller's
 * containing `UINavigationController` currently has its navigation bar hidden and
 * no other view controllers are currently presented.
 *
 * @return `YES` if the view controller's controls should be shown, `NO` otherwise.
 */
- (BOOL)shouldShowControls;

/**
 * Called when the hidden state of the controls has actually been changed.
 *
 * @param hidden The new hidden state of the controls
 *
 * @param animated Whether the change was animated
 */
- (void)didSetControlsHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Returns whether the text search view controller should be dismissed when the view controller's
 * view disappears.
 *
 * The default implementation of this method returns `YES`.
 *
 * @return `YES` if the view controller's controls should be hidden, `NO` otherwise
 */
- (BOOL)shouldAutomaticallyDismissSearchViewController;

@end

#pragma mark - Notifications

/**
 *
 * Posted when the PTDocumentViewController has opened a document.
 *
 * The notification object is the PTDocumentViewController that posted the notification.
 *
 */
PT_EXPORT const NSNotificationName PTDocumentViewControllerDidOpenDocumentNotification;


PT_EXPORT const NSNotificationName PTDocumentViewControllerDidDissmissShareActivityNotification;

PT_EXPORT const NSNotificationName PTDocumentViewControllerDidDisappearNotification;

NS_ASSUME_NONNULL_END
