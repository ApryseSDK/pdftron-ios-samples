//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentBaseViewController.h>
#import <Tools/PTDocumentNavigationItem.h>
#import <Tools/PTDocumentSliderViewController.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolGroupDefaultsViewController.h>
#import <Tools/PTToolGroupIndicatorView.h>
#import <Tools/PTToolGroupManager.h>
#import <Tools/PTToolGroupToolbar.h>
#import <Tools/PTToolGroupViewController.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentController;
@class PTDocumentNavigationItem;
@class PTDocumentSliderViewController;
@class PTToolGroupDefaultsViewController;
@class PTToolGroupIndicatorView;
@class PTToolGroupToolbar;
@class PTToolGroupViewController;
@class PTToolGroupManager;

@protocol PTDocumentControllerDelegate;

/**
 * The methods declared by the `PTDocumentControllerDelegate` protocol allow the adopting delegate
 * to respond to messages from the `PTDocumentController` class.
 */
PT_OBJC_RUNTIME_NAME(DocumentControllerDelegate)
@protocol PTDocumentControllerDelegate <NSObject>
@optional

/**
 * The document controller no longer has a valid document, and needs to be closed.
 */
- (void)documentControllerDidBecomeInvalid:(PTDocumentController *)documentController;

/**
 * The document controller has opened a document.
 */
- (void)documentControllerDidOpenDocument:(PTDocumentController *)documentController;

/**
 * Called when an error occurs when opening a document.
 */
- (void)documentController:(PTDocumentController *)documentController didFailToOpenDocumentWithError:(nullable NSError *)error;

#pragma mark Saving

/**
 * The method called when the document controller's PDF document will be saved.
 *
 * @param documentController The object sending the message.
 *
 * @param pdfDoc The PDF document that will be saved.
 */
- (void)documentController:(PTDocumentController *)documentController
          willSaveDocument:(PTPDFDoc *)pdfDoc;

/**
 * The method called when the document controller's PDF document was saved successfully.
 *
 * @param documentController The object sending the message.
 *
 * @param pdfDoc The PDF document that was saved.
 */
- (void)documentController:(PTDocumentController *)documentController
           didSaveDocument:(PTPDFDoc *)pdfDoc;

/**
 * The method called when the document controller's PDF document could not be saved due to an error.
 *
 * @param documentController The object sending the message.
 *
 * @param pdfDoc The PDF document that could not be saved.
 *
 * @param error The error that occurred while saving the document.
 */
- (void)documentController:(PTDocumentController *)documentController
     didFailSavingDocument:(PTPDFDoc *)pdfDoc
                 withError:(NSError *)error;

#pragma mark Cache document handling

/**
 * This method allows the delegate to control whether a cached document should be exported to a
 * different location and is called after a remote document has been fully downloaded or a non-PDF
 * document has finished converting.
 *
 * If this method is not implemented, the cached document will be exported.
 */
- (BOOL)documentController:(PTDocumentController *)documentController shouldExportCachedDocumentAtURL:(NSURL *)cachedDocumentUrl;

/**
 * Implement to override default save location when non-PDFs and remote documents are opened via `openDocumentWithURL`.
 * If this method is not implemented or `nil` is returned, the document will be saved to the Documents
 * directory with a unique name.
 */
- (nullable NSURL *)documentController:(PTDocumentController *)documentController destinationURLForDocumentAtURL:(NSURL *)sourceUrl;

/**
 * This method allows the delegate to control whether a cached document should be deleted after it
 * has been exported to a different location.
 *
 * If this method is not implemented, the cached document will be deleted.
 */
- (BOOL)documentController:(PTDocumentController *)documentController shouldDeleteCachedDocumentAtURL:(NSURL *)cachedDocumentUrl;

/**
 * This method allows the delegate to control whether the text search view controller should
 * be dismissed when the document controller's view disappears.
 *
 * If this method is not implemented, the text search view controller will be dismissed.
 */
- (BOOL)documentControllerShouldAutomaticallyDismissSearchViewController:(PTDocumentController *)documentViewController;

/**
 * This method is called when the panel is opened.
 */

- (void)documentController:(PTDocumentController *)documentController didShowLeadingPanelViewController: (UIViewController*) leadingPanelViewController;

/**
 * This method is called when the panel is closed.
 */

- (void)documentController:(PTDocumentController *)documentController didDismissLeadingPanelViewController: (UIViewController*) leadingPanelViewController;

@end

/**
 * A view controller that displays a `PTPDFViewCtrl` along with other controls.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(DocumentController)
@interface PTDocumentController : PTDocumentBaseViewController
<PTOverridable,
PTToolGroupManagerDelegate,
PTToolGroupToolbarDelegate>

/**
 * The document controller's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTDocumentControllerDelegate> delegate;

#pragma mark - Tool groups

/**
 * Whether tool groups are enabled in this view controller. This property controls
 * whether the `toolGroupToolbar` is shown.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, getter=areToolGroupsEnabled) BOOL toolGroupsEnabled;

/**
 * The tool group manager instance used to control the current tool group and the set of
 * bar button items displayed in the tool group toolbar.
 */
@property (nonatomic, readonly, strong) PTToolGroupManager *toolGroupManager;

#pragma mark Tool group toolbar

/**
 * The tool group toolbar used by this class when the `areToolGroupsEnabled`
 * property is enabled.
 */
@property (nonatomic, readonly, strong) PTToolGroupToolbar *toolGroupToolbar;

/**
 * Whether the `isToolGroupToolbarHidden` property of this view controller is updated as part of
 * its bar-hiding (and -showing) behavior.
 *
 * When enabled, the `isToolGroupToolbarHidden` property will be updated by the `controlsHidden`
 * property in response to handled taps, automatically based on a timer, and other logic. Otherwise,
 * the `isToolGroupToolbarHidden` property will not be updated and it is the responsibility of users
 * of this class to ensure that the bars are consistent with the desired behavior and appearance.
 *
 * The default value of this property is `YES`.
 *
 * @see `isToolGroupToolbarHidden`
 */
@property (nonatomic, assign) BOOL hidesToolGroupToolbar;

/**
 * Whether the tool group toolbar is hidden.
 *
 * The default value of this property is `YES`.
 *
 * @see `-setToolGroupToolbarHidden:animated:`
 * @see `hidesToolGroupToolbar`
 */
@property (nonatomic, assign, getter=isToolGroupToolbarHidden) BOOL toolGroupToolbarHidden;

/**
 * Sets whether the tool group toolbar is hidden.
 *
 * @param hidden Specify `YES` to hide the tool group toolbar or `NO` to show it.
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * control to appear immediately.
 *
 * @see `isToolGroupToolbarHidden`
 */
- (void)setToolGroupToolbarHidden:(BOOL)hidden animated:(BOOL)animated;

#pragma mark Tool group accessory views

/**
 * The tool group indicator view is used to indicate the current tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroupIndicatorView *toolGroupIndicatorView;

#pragma mark Tool group view controllers

/**
 * The tool group view controller displays the list of available tool groups and allows the
 * user to change the current mode.
 */
@property (nonatomic, readonly, strong) PTToolGroupViewController *toolGroupViewController;

/**
 * Shows the `toolGroupViewController`.
 */
- (void)showToolGroups:(id)sender;

/**
 * The tool group defaults view controller used to allow editing of the tool groups in the
 * `toolGroupManager`.
 */
@property (nonatomic, readonly, strong) PTToolGroupDefaultsViewController *toolGroupDefaultsViewController;

#pragma mark - UINavigationItem

/**
 * The navigation item used to represent the view controller in a parent's navigation bar.
 *
 * The `PTDocumentNavigationItem` subclass allows setting bar button items for specific user interface
 * size classes.
 */
@property (nonatomic, readonly, strong) PTDocumentNavigationItem *navigationItem;

#pragma mark - Bar button items

/**
 * When this view controller is contained in a `PTTabbedDocumentViewController` instance, shows all
 * the tabbed document view controller's document tabs.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *tabsButtonItem;

/**
 * Whether the `tabsButtonItem` should be automatically shown when this view controller
 * is contained in a `PTTabbedDocumentViewController`.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic) BOOL automaticallyShowsTabsButton;

#pragma mark - Document slider

/**
 * The `PTDocumentSliderViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTDocumentSliderViewController *documentSliderViewController;

/**
 * Whether the `documentSliderViewController` is enabled and shown when the
 * `pdfViewCtrl` is scrolled or the current page changes.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, getter=isDocumentSliderEnabled) BOOL documentSliderEnabled;

@end

NS_ASSUME_NONNULL_END
