//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>
#import <Tools/PTNoteEditController.h>
#import <Tools/PTLinkPopupViewController.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * These constants are used to control how close to an annotation a user needs to tap
 * before it's considered hit. (Very thin lines are otherwise too hard to hit.)
 */
#define GET_ANNOT_AT_DISTANCE_THRESHOLD 22
#define GET_ANNOT_AT_MINIMUM_LINE_WEIGHT 10

@class PTAnnotationManager;
@class PTTool;
@class PTToolManager;

@protocol PTToolEvents, PTToolOptionsDelegate;

/**
 * The PTToolSwitching protocol allows the adopting tool-class to specify the next tool to use
 * if this tool does not completely handle an event.
 */
PT_OBJC_RUNTIME_NAME(ToolSwitching)
@protocol PTToolSwitching <PTPDFViewCtrlToolDelegate>

/**
 * The tool manager that is used as an interface for the PTToolManagerDelegate methods.
 */
@property (nonatomic, weak) PTToolManager *toolManager;

/**
 * The annotation manager that is used to perform annotation-related operations.
 */
@property (nonatomic, weak) PTAnnotationManager *annotationManager;

/**
 * A string that will be used to set the author field of annotations that are created.
 */
@property (nonatomic, copy) NSString *annotationAuthor;

/**
 * Indicates if the tool can be used to create an annotation.
 *
 * The default value is `NO`.
 */
@property (nonatomic, readonly) BOOL createsAnnotation;

/**
 * The PTPDFViewCtrl that the tool or tool manager references.
 */
@property (readonly, nonatomic, weak) PTPDFViewCtrl *pdfViewCtrl;

/**
 * Returns a newly initialized tool with the required pointer to the PTPDFViewCtrl on which it will operate.
 *
 * @param pdfViewCtrl a pointer to the PTPDFViewCtrl that the tool will operate.
 *
 * @return A newly initialized `tool` object.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl;

/**
 * Returns the next tool to use if this tool did not completely handle an event.
 *
 * Tools receive events, listed as the optional selectors in this protocol, from a PTPDFViewCtrl. If a tool does not
 * finish handling an event (indicated by returning `NO` from one of the selectors that return a `BOOL`), then
 * getNextTool is used to instantiate a new tool that will continuning handling the event.
 *
 * @return a newly instantiated UIView that conforms to the PTToolSwitching protocol.
 */
- (instancetype)getNewTool;

/**
 * Receives a "custom" event dispatched by `-[PTToolManager createSwitchToolEvent:]`.
 *
 * This method gives the tool the opportunity to change to a new tool if it wishes to do so.
 *
 * @param userData Arbitrary data provided by the tool.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 */
- (BOOL)onSwitchToolEvent:(nullable id)userData;

@end

/**
 * The PTTool base class from which all stock tools derive. These tools implement the `PTToolSwitching`
 * protocol. For documentation on these methods, please see the protocol documentation,
 * available at http://www.pdftron.com
 */
PT_OBJC_RUNTIME_NAME(Tool)
@interface PTTool : UIView <PTOverridable, UIGestureRecognizerDelegate, PTToolSwitching, PTNoteEditControllerDelegate, PTLinkPopupViewControllerDelegate, UIPopoverPresentationControllerDelegate, UIAdaptivePresentationControllerDelegate>

#pragma mark - Properties
/** @name Properties
 */

/**
 The page number of the `currentAnnotation`.
 */
@property (nonatomic, assign) unsigned int annotationPageNumber;
 
/**
 The location of a long press within the coordinate system of the PTPDFViewCtrl (screen coordinates).
 */
@property (nonatomic, assign) CGPoint longPressPoint;

/**
 The tools have one active annotation at a time, which is pointed to by this property.
 */
@property (nonatomic, strong, nullable) PTAnnot* currentAnnotation;

/**
 * If YES, an annotation creation tool will switch back to the `defaultClass` tool,
 * typically the `PTPanTool`, after the annotation is created. If NO, the annotation
 * creation tool will remain active, so the next set of touches will create another
 * annotation.
 */
@property (nonatomic, assign) BOOL backToPanToolAfterUse;

/**
 * Class of tool to use when document is interacted with after
 * creating a tool. If backToPanToolAfterUse is YES, then this
 * will normally be the PTPanTool. Otherwise it will be the currently
 * used annotation creation tool.
 */
@property (nonatomic, assign) Class defaultClass;

/**
 * Class of tool to pass the event on to if the current tool if it
 * needs further processing.
 */
@property (nonatomic, assign, nullable) Class nextToolType;

/**
 * Class of previous tool that created the current tool.
 */
@property (nonatomic, strong, nullable) Class previousToolType;

/**
 * The PDFNet class that this tool creates.
 */
@property (nonatomic, readonly, strong) Class annotClass;

/**
 * The PDFNet annot type that this tool creates.
 */
@property (nonatomic, readonly, assign) PTExtendedAnnotType annotType;

/**
 * The PDFNet annot type that this tool creates.
*/
@property (nonatomic, class, readonly, assign) PTExtendedAnnotType annotType;

/**
 * Indicates if the tool type can be used to create an annotation.
 *
 * The default value is `NO`.
 */
@property (nonatomic, class, readonly) BOOL createsAnnotation;

/**
 * The image to display for this tool.
 *
 * The default implementation uses the annotation type from `annotType` to determine
 * which image to use. If the `annotType` is `PTExtendedAnnotTypeUnknown` then this
 * property is `nil`.
 *
 * This property can be overridden in a subclass to provide a custom value.
 */
@property (nonatomic, class, readonly, strong, nullable) UIImage *image;

/**
 * The localized name of this tool.
 *
 * The default implementation uses the annotation type from `annotType` to determine
 * the name to use. If the `annotType` is `PTExtendedAnnotTypeUnknown` then this
 * property is `nil`.
 *
 * This property can be overridden in a subclass to provide a custom value.
 */
@property (nonatomic, class, readonly, copy, nullable) NSString *localizedName;

/**
 * The identifier of this tool.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

/**
 * Used to check if this tool can have its style modified.
 *
 * The default value is taken from the class-method `+[PTTool canEditStyle]`.
 */
@property (nonatomic, readonly, assign) BOOL canEditStyle;

/**
 * Used to check if this tool can have its style modified.
 *
 * The default value is `NO`.
 */
@property (nonatomic, class, readonly) BOOL canEditStyle;

/**
 * Tools can add a page number indicator to the `PTPDFViewCtrl`. This
 * boolean turns its visibility on and off.
 */
@property (nonatomic, assign) BOOL pageIndicatorIsVisible;

/**
 * Acrobat and Preview do not follow the PDF specification regarding
 * the ordering of quad points in a text markup annotation. Enable
 * this code for compatibility with those viewers.
 */
@property (nonatomic, assign) BOOL textMarkupAdobeHack;

/**
 * Used to track if the tool should forward the touch events
 * to the `PTPDFViewCtrl` for scrolling.
 */
@property (nonatomic, readonly, assign) BOOL allowScrolling;

/**
 * Used to track if the tool should allow the `PTPDFViewCtrl` to zoom.
 */
@property (nonatomic, assign) BOOL allowZoom;

/**
 * Whether this tool maintains an `NSUndoManager` with its own undo stack.
 *
 * When `YES`, the tool's `undoManager` property (inherited from `UIResponder`) will be an
 * undo manager with an undo stack of the tool's actions. When `NO`, the tool does not have its own
 * undo manager and the `undoManager` property will respect the standard `UIResponder` flow (goes up
 * the responder chain to find the first non-null `NSUndoManager` instance, stopping at the root
 * `UIWindow`).
 *
 * The default value is `NO`.
 */
@property (nonatomic, readonly, assign, getter=isUndoManagerEnabled) BOOL undoManagerEnabled;

#pragma mark - PTToolSwitching protocol implementation (General)
/** @name PTToolSwitching protocol implementation (General)
 */


- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Requests action object to be executed by the PTPDFViewCtrl. The action must
 * belong to the document currently displayed in the PTPDFViewCtrl.
 *
 * @param action_param The object that is to be executed.
 */
- (void)executeAction:(PTActionParameter*)action_param;

#pragma mark - Annotation change handling

/**
 * Commits any pending annotation changes to the document.
 *
 * The default implementation of this method does nothing. Subclasses of the `PTTool` base class should
 * override this method to commit pending annotation changes to the document.
 */
- (void)commitAnnotation;

/**
 * A convenience method that handles notifying the tool manager before and after the annotation is
 * modified.
 *
 * @param annotation The annotation to be modified
 *
 * @param pageNumber The PDF page number of the annotation
 *
 * @param block A block that is executed synchronously and receives the annotation and page number
 * as parameters. The `-willModifyAnnotation:onPageNumber:` method will be called before the block is
 * executed and the `-annotationModified:onPageNumber:` method is called afterwards.
 */
- (void)modifyAnnotation:(PTAnnot *)annotation
            onPageNumber:(unsigned int)pageNumber
               withBlock:(void (NS_NOESCAPE ^)(PTAnnot *annotation,
                                               unsigned int pageNumber))block;

#pragma mark - Annotation events
/** @name Annotation events
 */

/**
 * Used to notify the tool manager that the tool has added an annotation.
*
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 *
 */
- (void)annotationAdded:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool has modified an annotation.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)annotationModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool will modify an annotation.
 *
 * @param annotation The annotation that will be modified.
 *
 * @param pageNumber The page number of the PDF that the annotation will be modified on.
 */
- (void)willModifyAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool has removed an annotation.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)annotationRemoved:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;


/**
* Used to notify the tool manager that the tool will remove an annotation.
*
* @param annotation The annotation that will be removed.
*
* @param pageNumber The page number of the PDF that the annotation will be removed from.
*/
- (void)willRemoveAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool has flattened an annotation.
 *
 * @param annotation The annotation that was flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation was flattened onto.
 */
- (void)annotationFlattened:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;


/**
* Used to notify the tool manager that the tool will flatten an annotation.
*
* @param annotation The annotation that will be flattened.
*
* @param pageNumber The page number of the PDF that the annotation will be flattened onto.
*/
- (void)willFlattenAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool has modified a form field's data.
 *
 * @param annotation The form field annotation's that had its data modified
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)formFieldDataModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to allow the tool manager to control whether the tool should interact with the
 * form annotation on `pageNumber`.
 *
 * @param annotation The annotation that will be selected
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to select the annotation; `NO` if not.
 */
-(BOOL)shouldInteractWithForm:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 140000
/**
 * Used to allow the tool mananger to control whether the tool should handle the Apple Pencil Scribble interaction for a given annotation on `pageNumber`.
 *
 * @param scribbleInteraction The scribble interaction that will be performed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should allow for scribble input for the annotation; `NO` if not.
 */
-(BOOL)shouldHandleIndirectScribbleInteraction:(UIIndirectScribbleInteraction*)scribbleInteraction forAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber API_AVAILABLE(ios(14.0));
#endif

/**
 * Used to allow the tool manager to control whether the tool can edit the annotation on `pageNumber`.
 *
 * @param annotation The annotation that will be edited
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to edit the annotation; `NO` if not.
 */
- (BOOL)canEditAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to allow the tool manager to control whether the tool should select the
 * given annotation on `pageNumber`.
 *
 * @param annotation The annotation that will be activated
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should activate the form annotation; `NO` if not.
 */
-(BOOL)shouldSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool will select an annotation.
 *
 * @param annotation The annotation that will be selected
 *
 * @param pageNumber The page number of the PDF that the annotation is on
 */
- (void)willSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to notify the tool manager that the tool selected an annotation.
 *
 * @param annotation The annotation that was selected
 *
 * @param pageNumber The page number of the PDF that the annotation was selected on
 */
- (void)didSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber NS_REQUIRES_SUPER;

/**
 * Used to notify the tool manager that text will be copied.
 *
 * @param selectedText The text to be copied, based on the user's current selection.
 *
 * @param pasteboard The pasteboard to which the text will be copied
 *
 * @return The text that will be copied to the pasteboard. This return value can be different from
 * the value of the `textToCopy` parameter.
 */
- (nullable NSString *)willCopyReturnedText:(nullable NSString *)selectedText
                               toPasteboard:(UIPasteboard *)pasteboard;

/**
 * Used to notify the tool manager that text was copied.
 *
 * @param copiedText The text that was copied
 *
 * @param pasteboard The pasteboard to which the text was copied
 */
- (void)didCopyText:(nullable NSString *)copiedText
       toPasteboard:(UIPasteboard *)pasteboard;

/**
 * Used to allow the tool manager to control whether to show a menu controller
 * for the given annotation and page number.
 *
 * @param annotation The annotation that will be selected.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should show the UIMenuController; `NO` if not.
 */
-(BOOL)shouldShowMenu:(UIMenuController *)menuController forAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used to allow the tool manager to take over link handling. Links can either be annotations,
 * or detected as links by PDFNet via text pattern matching. One of the two first parameters
 * will have a value, the other will be `nil`.
 *
 * @see `-[PTPDFViewCtrl SetUrlExtraction:]`
 *
 * @param annotation The link annotation, if it exists, that will be handled. If there is not a link annotation, then `nil`.
 *
 * @param linkInfo If it exists, the text that was detected as matching the format of a link. `nil` otherwise.
 *
 * @param pageNumber The page number that the annotation or link is on.
 *
 * @return `YES` if the tool should handle the link; `NO` if not.
 */
- (BOOL)shouldHandleLinkAnnotation:(nullable PTAnnot *)annotation orLinkInfo:(nullable PTLinkInfo *)linkInfo onPageNumber:(unsigned long)pageNumber;

/**
 * Called to determine whether the edit menu should be shown.
 *
 * @param annotation The annotation for which the menu will be presented, or `nil`.
 * @param pageNumber The page number of the annotation or that the menu will be presented on.
 *
 * @return `YES` if the edit menu should be shown, `NO` otherwise.
 */
- (BOOL)shouldShowEditMenuForAnnotation:(nullable PTAnnot *)annotation
                           onPageNumber:(unsigned long)pageNumber API_AVAILABLE(ios(16.0));

/**
 * Called when the edit menu will be shown.
 *
 * The menu and its actions can be customized via the return value of this method.
 *
 * @param annotation The annotation for which the menu will be presented, or `nil`.
 * @param pageNumber The page number of the annotation or that the menu will be presented on.
 * @param configuration The configuration to be used for the presentation of the edit menu.
 * @param actions The actions that will be displayed in the edit menu.
 *
 * @return A new `UIMenu` instance, which may include the provided `actions` and/or other actions, to
 * be presented. Returning an empty menu results in the presentation being cancelled, otherwise return
 * `nil` to display the default menu with the provided `actions`.
 */
- (nullable UIMenu *)willShowEditMenuForAnnotation:(nullable PTAnnot *)annotation
                                      onPageNumber:(unsigned long)pageNumber
                                 withConfiguration:(UIEditMenuConfiguration *)configuration
                                           actions:(NSArray<UIMenuElement *> *)actions API_AVAILABLE(ios(16.0));

#pragma mark - Appearance views

/**
 * Called when the live-appearance view will be displayed for the specified annotation.
 *
 * @param appearanceView The annotation appearance view that will be displayed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number of the annotation.
 */
- (void)willDisplayAppearanceView:(UIView *)appearanceView
                    forAnnotation:(PTAnnot *)annotation
                     onPageNumber:(int)pageNumber;

/**
 * Called when the live-appearance view is no longer being displayed for the specified annotation.
 *
 * @param appearanceView The annotation appearance view that was displayed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number of the annotation.
 */
- (void)didEndDisplayingAppearanceView:(UIView *)appearanceView
                         forAnnotation:(PTAnnot *)annotation
                          onPageNumber:(int)pageNumber;

#pragma mark - Note colors

/**
 * Used to set the background color for sticky note annotation.
 *
 * @param noteEditController The note edit controller of the annotation.
 *
 * @param fillColor The fill color of the sticky note annotation.
 */
- (void)setBackgroundColorForNote:(PTNoteEditController *)noteEditController fillColor:(UIColor *)fillColor;

/**
 * Used to set the bar buttons' tint color for sticky note annotation.
 *
 * @param noteEditController The note edit controller of the annotation.
 *
 * @param barButtonColor The bar buttons' color of the sticky note annotation.
 */
- (void)setBarButtonColorForNote:(PTNoteEditController *)noteEditController fillColor:(UIColor *)barButtonColor;

#pragma mark - Shared by multiple tools
/** @name Shared by multiple tools
 */

/**
 * Call to edit the current annotation's note.
 */
- (void)editSelectedAnnotationNote;

/**
 * Flattens the specified annotation(s) on the current page.
 *
 * @param annotations the annotations to flatten
 *
 * @see `-flattenAnnotations:onPageNumber:withError`
 */
- (void)flattenAnnotations:(NSArray<PTAnnot * > *)annotations;

/**
 * Flattens the specified annotations.
 *
 * @param annotations the annotations to flatten
 *
 * @param pageNumber the page number of the annotations
 *
 * @param error On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the annotations were flattened into the page, `NO` otherwise.
 */
- (BOOL)flattenAnnotations:(NSArray<PTAnnot *> *)annotations
              onPageNumber:(int)pageNumber
                 withError:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Deletes the current annotation.
 */
- (void)deleteSelectedAnnotation;

/**
 * Call to keep the current tool's appearance on screen even after the tool is destroyed.
 * This prevents a possible annotation "flash" as the PDF under a newly created annotation
 * is re-rendered with the new annotation. The appearance is automatically removed when
 * the PDFViewCtrl finishes its next render (or when its layout changes).
 */
- (void)keepToolAppearanceOnScreen;

/**
 * Keeps a tool's appearance on screen using the provided imageView.
 * See `keepToolAppearanceOnScreen`.
 *
 * @param imageView The image view to temporarily keep on screen.
 */
-(void)keepToolAppearanceOnScreenWithImageView:(UIImageView*)imageView;

/**
 * Call to explicitly remove an tool appearances that have have been kept on screen by a call
 * too `keepToolAppearanceOnScreen`.
 */
- (void)removeAppearanceViews;

#pragma mark Selection menu

/**
 * Shows a `UIMenuController` or edit menu (`UIMenu`) with options relevant for the current tool.
 *
 * @param targetScreenRect The screen-rect that the menu will be anchored to. A value of `CGRectZero`
 * will show the menu without setting its target rect.
 *
 * @param animated Whether to animate the change
 */
- (void)showSelectionMenu:(CGRect)targetScreenRect animated:(BOOL)animated;

/**
 * Shows a `UIMenuController` or edit menu (`UIMenu`) with options relevant for the current tool.
 */
- (void)showSelectionMenu:(CGRect)targetScreenRect;

/**
 * Hides the `UIMenuController` or edit menu (`UIMenu`).
 */
- (void)hideMenu;

#pragma mark Edit menu interaction

/**
 * The edit menu interaction attached to this tool and used to present edit menus.
 *
 * The delegate of the interaction should not be changed.
 */
@property (nonatomic, readonly, strong, nullable) UIEditMenuInteraction *editMenuInteraction API_AVAILABLE(ios(16.0));

/**
 * Whether the edit menu interaction is enabled for presenting menus.
 *
 * When enabled, the `editMenuInteraction` will be used to present menus from this tool. When disabled,
 * the shared `UIMenuController` will be used to present menus.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isEditMenuInteractionEnabled) BOOL editMenuInteractionEnabled API_AVAILABLE(ios(16.0));

#pragma mark - Helper methods
/** @name Helper methods
 */

/**
 * Returns the PDF page crop box for the specified page number.
 *
 * @param pageNumber the page number
 *
 * @return the page crop box in page points.
 */
- (nullable PTPDFRect *)pageCropBoxForPageNumber:(int)pageNumber;

/**
 * Returns the page rotation for the specified page number.
 *
 * @param pageNumber the page number
 *
 * @return the page rotation for the specified page number
 */
- (PTRotate)pageRotationForPageNumber:(int)pageNumber;

/**
 * Computes the PDF page box in screen (PTPDFViewCtrl) coordinates.
 *
 * @param pageNumber the page number
 *
 * @return the page box in screen points.
 */
-(nullable PTPDFRect*)pageBoxInScreenPtsForPageNumber:(int)pageNumber;

/**
 * Returns the union of two rectangles
 */
+ (PTPDFRect*)GetRectUnion:(PTPDFRect*)rect1 Rect2:(PTPDFRect*)rect2;


/**
 * Converts a point in screen (`PTPDFViewCtrl`) coordinates to a PDF page
 * coordinate.
 */
-(CGPoint)convertScreenPtToPagePt:(CGPoint)screenPoint onPageNumber:(int)pageNumber;

/**
 * Converts a point in screen (`PTPDFViewCtrl`) coordinates to a PDF page
 * coordinate.
 */
- (void)ConvertScreenPtToPagePtX:(CGFloat*)x Y:(CGFloat*)y PageNumber:(int)pageNumber;

/**
 * Converts a point in page coordinates to screen (`PTPDFViewCtrl`) coordinates.
 */
- (void)ConvertPagePtToScreenPtX:(CGFloat*)x Y:(CGFloat*)y PageNumber:(int)pageNumber;

/**
 * Converts a point in page coordinates to screen (`PTPDFViewCtrl`) coordinates.
 */
-(CGPoint)convertPagePtToScreenPt:(CGPoint)pagePoint onPageNumber:(int)pageNumber;

/**
 * Converts a `PTPDFRect` in PDF page coordinates to a `CGRect` in screen
 * (`PTPDFViewCtrl`) coordinates.
 */
-(CGRect)PDFRectPage2CGRectScreen:(PTPDFRect*)r PageNumber:(int)pageNumber;

/**
 * Converts a `PTPDFRect` in screen (`PTPDFViewCtrl`) coordinates to a `CGRect`
 * in screen (`PTPDFViewCtrl`) coordinates.
 */
-(CGRect)PDFRectScreen2CGRectScreen:(PTPDFRect*)r;

/**
 * Converts a `PTPDFRect` in screen (`PTPDFViewCtrl`) coordinates to a `CGRect`
 * in screen (`PTPDFViewCtrl`) coordinates.
 */
-(CGRect)PDFRectScreen2CGRectScreen:(PTPDFRect*)r PageNumber:(int)pageNumber;

/**
 * Converts a `CGRect` in screen (`PTPDFViewCtrl`) coordinates to a `PTPDFRect` in
 * PDF page coordinates.
 */
-(PTPDFRect *)CGRectScreen2PDFRectPage:(CGRect)screenRect PageNumber:(int)pageNumber;

/**
 * Converts a `CGRect` in screen (`PTPDFViewCtrl`) coordinates to a `CGRect` in canvas coordinates.
 */
- (CGRect)CGRectScreenToCGRectCanvas:(CGRect)screenRect;

/**
 * Converts a `CGRect` in canvas coordinates to a `CGRect` in screen (`PTPDFViewCtrl`) coordinates.
 */
- (CGRect)CGRectCanvasToCGRectScreen:(CGRect)canvasRect;

#pragma mark - Non-designated initializers
/** @name PTToolSwitching protocol implementation (Non-designated initializers)
 */


-(instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;

#pragma mark - Annotation snapping

/**
 * Computes the snapped rect of a resizing annotation.
 *
 * @param position the current cgrect position of the annotation.
 *
 * @return the snapped cgrect position of the annotation.
 */
-(CGRect)screenRectOfResizingAnnotationClosestToPosition:(CGRect) position;

/**
 * Computes the snapped rect of a moving annotation.
 *
 * @param position the current cgrect position of the annotation.
 *
 * @return the snapped cgrect position of the annotation.
 */
-(CGRect)screenRectOfMovingAnnotationClosestToPosition:(CGRect) position;

/**
 * Computes the current annotation positions on a given page number.
 *
 * @param annotType current annotation extended type .
 *
 * @param pageNumber page number of the current annotation
 *
 * @param includePageCenter weather is should calculate the positon of the page center.
 *
 */
-(void)calculateAnnotationPositionsWithCurrentAnnotType:(PTExtendedAnnotType)annotType AtPageNumber:(int)pageNumber includePageCenter:(BOOL)includePageCenter;

/**
 * Removes all snapping lines.
 */
-(void)removeAllSnappingViews;

/**
 * Displays a menu item when snapping has occured to disable snapping.
 */
-(void)showDisableSnappingMenuIfSnappingHasOccurred;

@end

NS_ASSUME_NONNULL_END
