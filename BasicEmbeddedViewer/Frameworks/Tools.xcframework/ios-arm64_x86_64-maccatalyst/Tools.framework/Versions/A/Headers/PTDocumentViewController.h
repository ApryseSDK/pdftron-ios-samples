//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationToolbar.h>
#import <Tools/PTDocumentBaseViewController.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentViewController;

/**
 * The methods declared by the `PTDocumentViewControllerDelegate` protocol allow the adopting delegate
 * to respond to messages from the `PTDocumentViewController` class.
 */
PT_DEPRECATED_MSG(8.0.2, "Use the PTDocumentControllerDelegate protocol instead.")
PT_OBJC_RUNTIME_NAME(DocumentViewControllerDelegate)
@protocol PTDocumentViewControllerDelegate <NSObject>
@optional

/**
 * The document view controller no longer has a valid document, and needs to be closed.
 */
- (void)documentViewControllerDidBecomeInvalid:(PTDocumentViewController *)documentViewController;

/**
 * The document view controller has opened a document.
 */
- (void)documentViewControllerDidOpenDocument:(PTDocumentViewController *)documentViewController;

/**
 * Called when an error occurs when opening a document.
 */
- (void)documentViewController:(PTDocumentViewController *)documentViewController didFailToOpenDocumentWithError:(nullable NSError *)error;

/**
 * This method allows the delegate to control whether a cached document should be exported to a
 * different location and is called after a remote document has been fully downloaded or a non-PDF
 * document has finished converting.
 *
 * If this method is not implemented, the cached document will be exported.
 */
- (BOOL)documentViewController:(PTDocumentViewController *)documentViewController shouldExportCachedDocumentAtURL:(NSURL *)cachedDocumentUrl;

/**
 * Implement to override default save location when non-PDFs and remote documents are opened via `openDocumentWithURL`.
 * If this method is not implemented or `nil` is returned, the document will be saved to the Documents
 * directory with a unique name.
 */
- (nullable NSURL *)documentViewController:(PTDocumentViewController *)documentViewController destinationURLForDocumentAtURL:(NSURL *)sourceUrl;

/**
 * This method allows the delegate to control whether a cached document should be deleted after it
 * has been exported to a different location.
 *
 * If this method is not implemented, the cached document will be deleted.
 */
- (BOOL)documentViewController:(PTDocumentViewController *)documentViewController shouldDeleteCachedDocumentAtURL:(NSURL *)cachedDocumentUrl;

/**
 * This method allows the delegate to control whether the text search view controller should
 * be dismissed when the document view controller's view disappears.
 *
 * If this method is not implemented, the text search view controller will be dismissed.
 */
- (BOOL)documentViewControllerShouldAutomaticallyDismissSearchViewController:(PTDocumentViewController *)documentViewController;

/**
 * This method is called when the panel is opened.
 */

- (void)documentViewController:(PTDocumentViewController *)documentViewController didShowLeadingPanelViewController: (UIViewController*) leadingPanelViewController;

/**
 * This method is called when the panel is closed.
 */

- (void)documentViewController:(PTDocumentViewController *)documentViewController didDismissLeadingPanelViewController: (UIViewController*) leadingPanelViewController;

@end

/**
 * A view controller that displays a `PTPDFViewCtrl` along with other controls.
 */
PT_DEPRECATED_MSG(8.0.2, "Use the PTDocumentController class instead. See pdftron.com/new-ios-ui to learn about the new controller, and pdftron.com/new-ios-ui-migration to learn about migration.")
PT_OBJC_RUNTIME_NAME(DocumentViewController)
@interface PTDocumentViewController : PTDocumentBaseViewController <PTOverridable, PTAnnotationToolbarDelegate>

#pragma mark - Viewer

/**
 * The document view controller's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTDocumentViewControllerDelegate> delegate;

#pragma mark - Viewer Button Visibility

/**
 * Controls the visibility of the `freehandButtonItem` in the navigation bar.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isFreehandButtonHidden) BOOL freehandButtonHidden;

/**
 * Controls the visibility of the `annotationButtonItem` in the navigation bar.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationToolbarButtonHidden) BOOL annotationToolbarButtonHidden;

#pragma mark - Bar button items

/**
 * Changes the active tool to the freehand markup tool (`PTFreeHandCreate` or `PTPencilDrawingCreate`).
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *freehandButtonItem;

/**
 * Shows the `PTAnnotationToolbar` toolbar for annotating.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *annotationButtonItem;

/**
 * Undos the last change to the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *undoButtonItem;

/**
 * Redoes the last undone change to the document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *redoButtonItem;

#pragma mark - Controls

/**
 * The `PTAnnotationToolbar` managed by this view controller.
 */
@property (nonatomic, strong) PTAnnotationToolbar *annotationToolbar;

#pragma mark - Hiding user interface controls

/**
 * Whether the annotation toolbar is hidden. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationToolbarHidden) BOOL annotationToolbarHidden;

@end

NS_ASSUME_NONNULL_END
