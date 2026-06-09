//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>
#import <Tools/EraserCommon.h>
#import <Tools/PTAnnotationManager.h>
#import <Tools/PTAnnotationOptions.h>
#import <Tools/PTArrowAnnotationOptions.h>
#import <Tools/PTDigitalSignaturesManager.h>
#import <Tools/PTFreeTextAnnotationOptions.h>
#import <Tools/PTDateTextAnnotationOptions.h>
#import <Tools/PTFileAttachmentAnnotationOptions.h>
#import <Tools/PTImageStampAnnotationOptions.h>
#import <Tools/PTPageLabelManager.h>
#import <Tools/PTSignatureAnnotationOptions.h>
#import <Tools/PTTextAnnotationOptions.h>
#import <Tools/PTTextMarkupAnnotationOptions.h>
#import <Tools/PTTool.h>
#import <Tools/PTToolsSettingsManager.h>
#import <Tools/PTUndoRedoManager.h>
#import <Tools/PTWidgetAnnotationOptions.h>

#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationManager;
@class PTDigitalSignaturesManager;
@class PTFileAttachmentAnnotationOptions;
@class PTPageLabelManager;
@class PTTool;
@class PTUndoRedoManager;

@protocol PTToolManagerDelegate;
@protocol PTToolManagerObserver;

/**
 * The `PTToolEvents` protocol allows the adopting class to receive events from a `PTToolSwitching`
 * and control the tool's behavior.
 */
PT_OBJC_RUNTIME_NAME(ToolEvents)
@protocol PTToolEvents <NSObject>
@required

/**
 * Used by a tool to notify the tool manager that it has added an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 *
 */
- (void)tool:(PTTool *)tool annotationAdded:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has modified an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)tool:(PTTool *)tool annotationModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has removed an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)tool:(PTTool *)tool annotationRemoved:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has flattened an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation was flattened onto.
 */
- (void)tool:(PTTool *)tool annotationFlattened:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has modified the data of a form field.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)tool:(PTTool *)tool formFieldDataModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to take over link handling. Links can either be annotations,
 * or detected as links by PDFNet via text pattern matching. One of the two first parameters
 * will have a value, the other will be `nil`.
 *
 * @see `-[PTPDFViewCtrl SetUrlExtraction:]`
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The link annotation, if it exists, that will be handled. If there is not a link annotation, then `nil`.
 *
 * @param linkInfo If it exists, the text that was detected as matching the format of a link. `nil` otherwise.
 *
 * @param pageNumber The page number that the annotation or link is on.
 *
 * @return `YES` if the tool should handle the link; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldHandleLinkAnnotation:(nullable PTAnnot *)annotation orLinkInfo:(nullable PTLinkInfo *)linkInfo onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control whether the tool should interact the given form annotation on `pageNumber`.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The form annotation that will be activated
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to select the annotation; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldInteractWithForm:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 140000
/**
 * Allows the tool mananger to control whether the tool should handle the Apple Pencil Scribble interaction for a given annotation on `pageNumber`.
 *
 * @param tool The tool that sent the message.
 *
 * @param scribbleInteraction the scribble interaction.
 *
 * @param annotation The annotation that will be selected.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to scribble on the annotation; `NO` if not.
 *
 */
-(BOOL)tool:(PTTool *)tool shouldHandleIndirectScribbleInteraction:(UIIndirectScribbleInteraction*)scribbleInteraction forAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber API_AVAILABLE(ios(14.0));
#endif

/**
 * Allows the tool manager to control whether the tool should select the given annotation on `pageNumber`.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that will be selected
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to select the annotation; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has selected an annotation.
 *
 * @param tool The tool that sent the message.
 * @param annotation The annotation that was selected.
 * @param pageNumber The page number that the annotation is on.
 */
-(void)tool:(PTTool *)tool didSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that text will be copied.
 *
 * @param tool The tool that sent the message
 * @param selectedText The text that will be copied
 * @param pasteboard The pasteboard to which the text will be added
 *
 * @return The text that will be copied to the pasteboard. This may be different from the value of the
 * `textToCopy` parameter.
 */
- (nullable NSString *)tool:(PTTool *)tool willCopyReturnedText:(nullable NSString *)selectedText toPasteboard:(UIPasteboard *)pasteboard;

/**
 * Used by a tool to notify the tool manager that text was copied.
 *
 * @param tool The tool that sent the message
 * @param copiedText An in-out pointer to the text that was copied
 * @param pasteboard The pasteboard to which the text was added
 */
- (void)tool:(PTTool *)tool didCopyText:(nullable NSString *)copiedText toPasteboard:(UIPasteboard *)pasteboard;

/**
 * Allows the tool manager to control whether to show a menu controller for the given annotation and page number.
 *
 * @param tool The tool that sent the message.
 *
 * @param menuController The menu to be shown.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should show the UIMenuController; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldShowMenu:(UIMenuController*)menuController forAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control handling of file attachments.
 *
 * @param tool The tool that sent the message.
 *
 * @param fileAttachment The file attachment annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 */
- (void)tool:(PTTool *)tool handleFileAttachment:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control saving of file attachments.
 *
 * @param tool The tool that sent the message.
 *
 * @param fileAttachment The file attachment annotation to be saved.
 *
 * @param pageNumber The page number that the annotation is on.
 */
- (void)tool:(PTTool *)tool didAttemptFileAttachmentSave:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber success:(BOOL)success;

/**
 * Allows the tool manager to control handling of file selections.
 *
 * @param tool the tool that sent the message.
 *
 * @param filePath the selected file path
 *
 * @return `YES` if the selected file was handled, `NO` if not
 */
- (BOOL)tool:(PTTool *)tool handleFileSelected:(NSString *)filePath;

/**
 * Allows the tool manager to control handling of file selections with destination page numbers.
 *
 * @param tool the tool that sent the message.
 *
 * @param filePath the selected file path
 *
 * @param pageNumber the destination page number of the selected file
 *
 * @return `YES` if the selected file was handled, `NO` if not
 */
- (BOOL)tool:(PTTool *)tool handleFileSelected:(NSString *)filePath destinationPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control handling of named actions.
 *
 * @param tool the tool that sent the message.
 *
 * @param namedAction the namedAction
 *
 * @return `YES` if the named action was handled, `NO` if not
 */
- (BOOL)tool:(PTTool *)tool handleNamedAction:(NSString *)namedAction;

/**
 * Dispatches a "custom" event.
 *
 * This method triggers an asynchronous call to `-[PTToolSwitching onSwitchToolEvent:]` with
 * the provided user data.
 *
 * @param userData Arbitrary data provided by the tool.
 */
-(void)createSwitchToolEvent:(nullable id)userData;

#pragma mark Appearance views

/**
 * Notifies the receiver that the live-appearance view will be displayed for the specified annotation.
 *
 * @param tool The tool sending this message.
 *
 * @param appearanceView The annotation appearance view that will be displayed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number of the annotation.
 */
- (void)tool:(PTTool *)tool willDisplayAppearanceView:(UIView *)appearanceView forAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Notifies the receiver that the live-appearance view is no longer being displayed for the specified
 * annotation.
 *
 * @param tool The tool sending this message.
 *
 * @param appearanceView The annotation appearance view that was displayed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number of the annotation.
 */
- (void)tool:(PTTool *)tool didEndDisplayingAppearanceView:(UIView *)appearanceView forAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Called to determine whether the edit menu should be shown.
 *
 * @param tool The tool sending this message.
 * @param annotation The annotation for which the menu will be presented, or `nil`.
 * @param pageNumber The page number of the annotation or that the menu will be presented on.
 *
 * @return `YES` if the edit menu should be shown, `NO` otherwise.
 */
- (BOOL)tool:(PTTool *)tool shouldShowEditMenuForAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber API_AVAILABLE(ios(16.0));

/**
 * Called when the edit menu will be shown.
 *
 * The menu and its actions can be customized via the return value of this method.
 *
 * @param tool The tool sending this message.
 * @param annotation The annotation for which the menu will be presented, or `nil`.
 * @param pageNumber The page number of the annotation or that the menu will be presented on.
 * @param configuration The configuration to be used for the presentation of the edit menu.
 * @param actions The actions that will be displayed in the edit menu.
 *
 * @return A new `UIMenu` instance, which may include the provided `actions` and/or other actions, to
 * be presented. Returning an empty menu results in the presentation being cancelled, otherwise return
 * `nil` to display the default menu with the provided `actions`.
 */
- (nullable UIMenu *)tool:(PTTool *)tool willShowEditMenuForAnnotation:(nullable PTAnnot *)annotation
             onPageNumber:(unsigned long)pageNumber
        withConfiguration:(UIEditMenuConfiguration *)configuration
                  actions:(NSArray<UIMenuElement *> *)actions API_AVAILABLE(ios(16.0));

@end

/**
 * The `PTToolOptionsDelegate` protocol allows the adopting class to provide annotation options
 * information to a tool.
 */
PT_OBJC_RUNTIME_NAME(ToolOptionsDelegate)
@protocol PTToolOptionsDelegate <NSObject>
@required

/**
 * Used by a tool to check whether the specified annotation type can be created.
 *
 * @param tool the tool that sent the message
 * @param annotType the annotation type to be created
 *
 * @return `YES` if the annotation type can be created, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool canCreateExtendedAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Used by a tool to check whether the specified annotation can be edited.
 *
 * @param tool the tool that sent the message
 *
 * @param annotation the annotation to be edited
 *
 * @return `YES` if the annotation can be edited, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool canEditAnnotation:(PTAnnot *)annotation;

/**
 * Used by a tool to check whether the specified annotation type can be edited.
 *
 * @param tool the tool that sent the message
 *
 * @param annotType the annotation type to be edited
 *
 * @return `YES` if the annotation type can be edited, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool canEditExtendedAnnotType:(PTExtendedAnnotType)annotType;

#pragma mark - Annotation permissions

/**
 * Used by a tool to check whether the specified annotation allows editing.
 *
 * @param tool the tool that sent the message.
 *
 * @param annot the annotation to be edited
 *
 * @return `YES` if the annotation allows editing, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool hasEditPermissionForAnnot:(PTAnnot *)annot;

#pragma mark - Convenience

/**
 * Used by a tool to check if text selection is enabled.
 */
- (BOOL)isTextSelectionEnabledForTool:(PTTool *)tool;

/**
 * Used by a tool to check if form filling is enabled.
 */
- (BOOL)isFormFillingEnabledForTool:(PTTool *)tool;

/**
 * Used by a tool to check if link following is enabled.
 */
- (BOOL)isLinkFollowingEnabledForTool:(PTTool *)tool;

/**
 * Used by a tool to check if the eraser tool is enabled.
 */
- (BOOL)isEraserEnabledForTool:(PTTool *)tool;

/**
 * Used to check if auto resizing free text is enabled.
 */
- (BOOL)autoResizeFreeText;

/**
 * Used to set if auto resizing free text is enabled.
 */
- (void)setAutoResizeFreeText:(BOOL)enabled;

/**
 * Used to check if snapping to document geometry is enabled.
 */
- (BOOL)snapToDocumentGeometry;

/**
 * Used to set if snapping to document geometry is enabled.
 */
- (void)setSnapToDocumentGeometry:(BOOL)enabled;

@end

/**
 * The `PTToolManager` class is responsbile for forwarding events from the PDFViewCtrl to Tools,
 * and coordinating the control and data flow between tools.
 */
PT_OBJC_RUNTIME_NAME(ToolManager)
@interface PTToolManager : UIView <PTOverridable, PTPDFViewCtrlToolDelegate, PTToolEvents, PTToolOptionsDelegate>

/**
 * The current tool.
 */
@property (nonatomic, strong, nullable) PTTool *tool;

/**
 * An object that conforms to the `PTToolManagerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTToolManagerDelegate> delegate;

/**
 * The `PTPDFViewCtrl` that the `PTToolManager` was initialized with.
 */
@property (nonatomic, readonly, weak) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The view controller that the tool manager is associated with. Determined by the tool manager's delegate's implementation of `viewControllerForToolManager:`,
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;

/**
 * Returns a newly initialized tool manager with the required pointer to the PTPDFViewCtrl on which it will operate.
 *
 * @param pdfViewCtrl a pointer to the PTPDFViewCtrl that the tool manager will operate.
 *
 * @return A newly initialized tool manager object.
 *
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Create and set a new tool of the given type as the current tool.
 */
- (__kindof PTTool *)changeTool:(Class)toolType;

/**
 * Selects the specified annotation.
 *
 * @param annotation the annotation to selected. If annotation is Nil, any selected annotation is deselected, and the tool is set to the default tool, typically
 * PTPanTool.
 *
 * @param pageNumber the page number of the annotation
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 */
- (BOOL)selectAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 *
 * Prompts the user for bluetooth permission if they have not been already
 *
 * Used as part of detecting if an Apple Pencil is paired with the device.
 *
 * Will never prompt on iPhones.
 *
 */
-(void)promptForBluetoothPermission;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

/**
 * A string that will be used to set the author field of annotations that are created.
 */
@property (nonatomic, copy, nullable) NSString *annotationAuthor;

/**
 * When true, the UIMenuController shows after a tap (in addition to after a long press).
 * The default value of this property is `false`.
 */
@property (nonatomic, assign) BOOL showMenuOnTap;

/**
 * When true, the digital signature tool allows the user to save signatures and apply previously
 * saved signatures.
 * The default value of this property is `true`.
 */
@property (nonatomic, assign) BOOL showDefaultSignature;

/**
 * Whether the built-in page number indicator is enabled. The default value of this property is `false`.
 */
@property (nonatomic, assign, getter=isPageIndicatorEnabled) BOOL pageIndicatorEnabled;

/**
 * Whether the document associated with the `PTPDFViewCtrl` is read-only. The default value is `NO`.
 *
 * When in read-only mode, annotation creation and editing are disabled as well as other actions
 * that would modify the document.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

/**
 *
 * Whether the tool should only create annotations with Apple Pencil touches and not
 * finger touches.
 *
 */
@property (nonatomic, readonly) BOOL annotationsCreatedWithPencilOnly;


/**
 * Controls if Apple's bluetooth permission prompt will be triggered the first time an Apple Pencil
 * touch is detected, so that the system setting to only annotate with the Apple Pencil can be ignored
 * when no Apple Pencil is currently paired with the device.
 */
@property (nonatomic, assign) BOOL allowBluetoothPermissionPrompt;

/**
 * Controls if Apple's `UIColorPickerViewController` will be used when modifying annotation styles
 * in the `PTAnnotStyleViewController` class.
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL useSystemColorPicker NS_AVAILABLE_IOS(14.0);

#pragma mark - Annotation options

/**
 * The options for text (`PTExtendedAnnotTypeText`) annotations.
 */
@property (nonatomic, copy) PTTextAnnotationOptions *textAnnotationOptions;

/**
 * The options for link (`PTExtendedAnnotTypeLink`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *linkAnnotationOptions;

/**
 * The options for free text (`PTExtendedAnnotTypeFreeText`) annotations.
 */
@property (nonatomic, copy) PTFreeTextAnnotationOptions *freeTextAnnotationOptions;

/**
 * The options for date text (`PTExtendedAnnotTypeDateText`) annotations.
 */
@property (nonatomic, copy) PTDateTextAnnotationOptions *dateTextAnnotationOptions;

/**
 * The options for line (`PTExtendedAnnotTypeLine`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *lineAnnotationOptions;

/**
 * The options for square (`PTExtendedAnnotTypeSquare`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *squareAnnotationOptions;

/**
 * The options for circle (`PTExtendedAnnotTypeCircle`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *circleAnnotationOptions;

/**
 * The options for polygon (`PTExtendedAnnotTypePolygon`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *polygonAnnotationOptions;

/**
 * The options for polyline (`PTExtendedAnnotTypePolyline`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *polylineAnnotationOptions;

/**
 * The options for highlight (`PTExtendedAnnotTypeHighlight`) annotations.
 */
@property (nonatomic, copy) PTTextMarkupAnnotationOptions *highlightAnnotationOptions;

/**
 * The options for underline (`PTExtendedAnnotTypeUnderline`) annotations.
 */
@property (nonatomic, copy) PTTextMarkupAnnotationOptions *underlineAnnotationOptions;

/**
 * The options for squiggly (`PTExtendedAnnotTypeSquiggly`) annotations.
 */
@property (nonatomic, copy) PTTextMarkupAnnotationOptions *squigglyAnnotationOptions;

/**
 * The options for strikeout (`PTExtendedAnnotTypeStrikeOut`) annotations.
 */
@property (nonatomic, copy) PTTextMarkupAnnotationOptions *strikeOutAnnotationOptions;

/**
 * The options for rubber stamp (`PTExtendedAnnotTypeStamp`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *stampAnnotationOptions;

/**
 * The options for caret (`PTExtendedAnnotTypeCaret`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *caretAnnotationOptions;

/**
 * The options for ink (`PTExtendedAnnotTypeInk`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *inkAnnotationOptions;

/**
 * The options for pop-up (`PTExtendedAnnotTypePopup`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *popupAnnotationOptions;

/**
 * The options for file attachment (`PTExtendedAnnotTypeFileAttachment`) annotations.
 */
@property (nonatomic, copy) PTFileAttachmentAnnotationOptions *fileAttachmentAnnotationOptions;

/**
 * The options for sound (`PTExtendedAnnotTypeSound`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *soundAnnotationOptions;

/**
 * The options for movie (`PTExtendedAnnotTypeMovie`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *movieAnnotationOptions;

/**
 * The options for widget (`PTExtendedAnnotTypeWidget`) annotations.
 */
@property (nonatomic, copy) PTWidgetAnnotationOptions *widgetAnnotationOptions;

/**
 * The options for Screen (`PTExtendedAnnotTypeScreen`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *screenAnnotationOptions;

/**
 * The options for printer's mark (`PTExtendedAnnotTypePrinterMark`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *printerMarkAnnotationOptions;

/**
 * The options for trap network (`PTExtendedAnnotTypeTrapNet`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *trapNetAnnotationOptions;

/**
 * The options for watermark (`PTExtendedAnnotTypeWatermark`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *watermarkAnnotationOptions;

/**
 * The options for 3D (`PTExtendedAnnotType3D`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *threeDimensionalAnnotationOptions;

/**
 * The options for redact (`PTExtendedAnnotTypeRedact`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *redactAnnotationOptions;

/**
 * The options for projection (`PTExtendedAnnotTypeProjection`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *projectionAnnotationOptions;

/**
 * The options for Rich Media (`PTExtendedAnnotTypeRichMedia`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *richMediaAnnotationOptions;

/**
 * The options for arrow (`PTExtendedAnnotTypeArrow`) annotations.
 */
@property (nonatomic, copy) PTArrowAnnotationOptions *arrowAnnotationOptions;

/**
 * The options for signature (`PTExtendedAnnotTypeSignature`) annotations.
 */
@property (nonatomic, copy) PTSignatureAnnotationOptions *signatureAnnotationOptions;

/**
 * The options for cloudy (`PTExtendedAnnotTypeCloudy`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *cloudyAnnotationOptions;

/**
 * The options for image stamp (`PTExtendedAnnotTypeImageStamp`) annotations.
 */
@property (nonatomic, copy) PTImageStampAnnotationOptions *imageStampAnnotationOptions;

/**
 * The options for ruler (`PTExtendedAnnotTypeRuler`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *rulerAnnotationOptions;

/**
 * The options for perimeter (`PTExtendedAnnotTypePerimeter`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *perimeterAnnotationOptions;

/**
 * The options for cloudy (`PTExtendedAnnotTypeArea`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *areaAnnotationOptions;

/**
 * The options for count (`PTExtendedAnnotTypeCount`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *countAnnotationOptions;

/**
 * The options for Apple Pencil drawing (`PTExtendedAnnotTypePencilKit`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *pencilDrawingAnnotationOptions;

/**
 * The options for freehand highlight (`PTExtendedAnnotTypeFreehandHighlight`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *freehandHighlightAnnotationOptions;

/**
 * The options for free text callout (`PTExtendedAnnotTypeCallout`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *calloutAnnotationOptions;

/**
 * Returns the `PTAnnotationOptions` for the specified annotation type.
 *
 * @param annotType the annotation type
 *
 * @return the `PTAnnotationOptions` for the specified annotation type, or `nil` if not found.
 */
- (nullable PTAnnotationOptions *)annotationOptionsForAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Returns whether the specified annotation type can be created.
 */
- (BOOL)canCreateExtendedAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Returns whether the specified annotation type can be edited.
 */
- (BOOL)canEditExtendedAnnotType:(PTExtendedAnnotType)annotType;

/**
 * The tool to use with Apple Pencil. The default pencil tool is `PTPencilDrawingCreate` for iOS 13+, and `PTFreeHandCreate` for iOS 12 and below.
 * @note `PTPencilDrawingCreate` is only available on iOS 13 and above.
 */
@property (nonatomic, strong, nullable) Class pencilTool;

#pragma mark - Annotation permissions

/**
 * Returns whether the specified annotation allows editing.
 */
- (BOOL)hasEditPermissionForAnnot:(PTAnnot *)annot;

/**
 * Whether the permissions of an `PTAnnot`, returned via `-[PTAnnot GetFlag:]`, are checked when
 * determining whether the annotation can be edited.
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationPermissionCheckEnabled) BOOL annotationPermissionCheckEnabled;

/**
 * Whether the author of an `PTAnnot` is checked against the current `annotationAuthor` when
 * determining whether the annotation can be edited.
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationAuthorCheckEnabled) BOOL annotationAuthorCheckEnabled;

#pragma mark - Interaction features

/**
 * A boolean value that determines whether text selection is enabled.
 */
@property (nonatomic, assign, getter=isTextSelectionEnabled) BOOL textSelectionEnabled;

/**
 * A boolean value that determines whether form filling is enabled.
 */
@property (nonatomic, assign, getter=isFormFillingEnabled) BOOL formFillingEnabled;

/**
 * A boolean value that determines whether link following is enabled.
 */
@property (nonatomic, assign, getter=isLinkFollowingEnabled) BOOL linkFollowingEnabled;

/**
 * A boolean value that determines whether the eraser tool is enabled.
 */
@property (nonatomic, assign, getter=isEraserEnabled) BOOL eraserEnabled;

/**
 * A  value that determines if the eraser should erase an ink annotation's individual points, or the
 * entire thing as a single object. The default is to erase individual points (`PTInkEraserModePoints`).
 */
@property (nonatomic, assign) PTInkEraserMode eraserMode;

/**
 * A list of annotation types to prevent from being erased by the `PTEraserTool`
 *
 * The array entries are wrapped `PTExtendedAnnotType` enumeration values.
 * The `PTEraser` will not erase any annotations whose type is included in the array.
 * Example:
 * `myToolManager.excludedAnnotationTypesForPTEraser = @[@(PTExtendedAnnotTypeStamp)];`
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *eraserExcludedExtendedAnnotTypes;

/**
 * Determines whether the `PTSmartPen` tool is enabled.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isSmartPenEnabled) BOOL smartPenEnabled;

/**
 * Determines whether the `PTSmartHighlighter` tool is enabled.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isSmartHighlighterEnabled) BOOL smartHighlighterEnabled;

/**
 * A boolean value that determines whether free text annots should get automatically resized after being edited.
 *
 * The default value is true.
 */
@property (nonatomic, assign, getter=isAutoResizeFreeTextEnabled) BOOL autoResizeFreeTextEnabled;

/**
 * A boolean value that determines whether measurement annots should snap to document geometry.
 *
 * The default value is false.
 */
@property (nonatomic, assign, getter=isSnapToDocumentGeometryEnabled) BOOL snapToDocumentGeometryEnabled;

/**
 * A boolean value that determines whether annots should snap to their initial aspect ratio while being resized.
 */
@property (nonatomic, assign, getter=isAnnotationsSnapToAspectRatioEnabled) BOOL annotationsSnapToAspectRatio;

 /**
 * A boolean value that determines whether annotations are selected immediately after they are created. Default is true, or whatever
 * value was last set by a `PTToolsSettingsManager`.
 */
@property (nonatomic, assign) BOOL selectAnnotationAfterCreation;

/**
 * Whether multiple annotations can be selected at once.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL allowsMultipleAnnotationSelection;

 /**
 * A boolean value that determines whether PencilKit is used to create new free hand annotations. Availble only on iOS 13.1 and greater. Default is true, or whatever
 * value was last set by a `PTToolsSettingsManager`.
 */
@property (nonatomic, assign) BOOL freehandUsesPencilKit;

/**
 * A boolean value that determines whether highlight-only annotations made with PencilKit use a multiply blend mode. Default is true, or whatever
 * value was last set by a `PTToolsSettingsManager`.
*/
@property (nonatomic, assign) BOOL pencilHighlightMultiplyBlendModeEnabled;

/**
 * A value that determines whether only Pencil touches should be used for annotating. Default is to obey the iOS system setting, or whatever
 * value was last set by a `PTToolsSettingsManager`.
*/
@property (nonatomic, assign) PTPencilInteractionMode pencilInteractionMode;

/**
 * A boolean value that determines whether freehand highlight annotation strokes are smoothed to straight lines. Default is false, or whatever
 * value was last set by a `PTToolsSettingsManager`.
*/
@property (nonatomic, assign) BOOL freeHandHighlightSmoothingEnabled;

/**
 * A boolean value that determines if selected text will include an "edit" option that allows the user to edit the underlying
 * PDF text. This feature is in development and is currently considered Beta. Please contact us if you are interested in
 * a more advanced version than the current behaviour.
 *
 * Default value is false.
 */
@property (nonatomic, assign) BOOL textEditingEnabled;

/**
 * A boolean value that determines if annotating in reflow mode is enabled.
 *
 * This property is disabled when the `readonly` property of the tool manager is set.
 *
 * The default value of this property is true.
*/
@property (nonatomic, assign, getter=isAnnotateOnReflowEnabled) BOOL annotateOnReflowEnabled;

/**
 *
 * A boolean value that determines if form annots can be selected by long press or by the
 * `PTAnnotSelectTool` multi-selection tool.
 *
 * Default value is false.
*/
@property (nonatomic, assign, getter=isSelectFormAnnotationsEnabled) BOOL selectFormAnnotationsEnabled;

/**
 *
 * A boolean value that determines if moving annotation between pages is allowed.
 * This feature does not currently support moving annotation replies.
 *
 * Default value is false.
*/
@property (nonatomic, assign) BOOL moveAnnotsBetweenPagesEnabled;

/**
 * Determines whether a label is shown on  perimeter and area annotations.
 *
 * The default value of this property is false.
 */
@property (nonatomic, assign) BOOL showMeasurementLabel;

/**
 * A boolean value that determines whether annotation snapping is enabled.
 *
 * The default value is false.
 */
@property (nonatomic, assign, getter=isAnnotationSnappingEnabled) BOOL annotationSnappingEnabled;

/**
 * The color of the annotation snapping line. If `null`, the tintColor will be used. Default is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor* annotationSnappingLineColor;

/**
 * A list of annotation types that will not exhibit snapping behaviour.
 *
 * The array entries are wrapped `PTExtendedAnnotType` enumeration values.
 * An annotation of a type specified here will not snap to other annotations or page center, nor be snapped to by other annotations.
 * Example:
 * `myToolManager.annotationSnappingExcludedExtendedAnnotTypes = @[@(PTExtendedAnnotTypeStamp)]`
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *annotationSnappingExcludedExtendedAnnotTypes;


#pragma mark - Asset locations

/**
 * A file URL pointing to the PKCS#12 certificate file (.pfx/.p12) used for digital signatures.
 */
@property (nonatomic, strong, nullable) NSURL *digitalCertificateLocation;

/**
 * The password used to unlock the PKCS#12 certificate file specified by `digitalCertificateLocation`.
 *
 * Never hardcode this value in source. Read it from the iOS Keychain or a secure
 * server-provisioning source and set it at runtime before the user triggers signing.
 */
@property (nonatomic, copy, nullable) NSString *digitalCertificatePassword;

/**
 * The name of the signer to embed in the digital signature's @c /Name entry.
 *
 * Optional. When @c nil, this field is omitted from the signature dictionary.
 */
@property (nonatomic, copy, nullable) NSString *digitalCertificateSignerName;

/**
 * The signing location to embed in the digital signature's @c /Location entry.
 *
 * Optional. When @c nil, this field is omitted from the signature dictionary.
 */
@property (nonatomic, copy, nullable) NSString *digitalCertificateSigningLocation;

/**
 * The reason for signing to embed in the digital signature's @c /Reason entry.
 *
 * Optional. When @c nil, this field is omitted from the signature dictionary.
 */
@property (nonatomic, copy, nullable) NSString *digitalCertificateSigningReason;

#pragma mark - Annotation manager

/**
 * The annotation manager responsible for managing annotation events and state.
 */
@property (nonatomic, readonly, strong) PTAnnotationManager *annotationManager;

#pragma mark - Undo/redo

/**
 * The undo-redo manager responsible for managing the undo/redo chain of the `pdfViewCtrl`.
 */
@property (nonatomic, readonly, strong) PTUndoRedoManager *undoRedoManager;

#pragma mark - Page labels

/**
 * The page label manager responsible for managing the page labels of the `pdfViewCtrl`.
 */
@property (nonatomic, readonly, strong) PTPageLabelManager *pageLabelManager;

#pragma mark - Digital Signatures manager

/**
 * The digital signatures manager responsible for validating digital signatures.
 */
@property (nonatomic, readonly, strong) PTDigitalSignaturesManager *digitalSignaturesManager;

#pragma mark - Events

#pragma mark Annotation events

/**
 * Used to notify the tool manager that an annotation has been added.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 */
- (void)annotationAdded:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
* Used to notify the tool manager that an annotation will be modified
*
* @param annotation The annotation will be modified.
*
* @param pageNumber The page number of the PDF that the annotation was modified on.
*/
- (void)willModifyAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the tool manager that an annotation has been modified
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)annotationModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;


/**
* Used to notify the tool manager that an annotation will be removed
*
* @param annotation The annotation will be removed.
*
* @param pageNumber The page number of the PDF that the annotation was removed from.
*/
- (void)willRemoveAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the tool manager that an annotation has been removed.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)annotationRemoved:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
* Used to notify the tool manager that an annotation will be flattened
*
* @param annotation The annotation will be flattened.
*
* @param pageNumber The page number of the PDF that the annotation will be flattened onto.
*/
- (void)willFlattenAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the tool manager that an annotation has been flattened.
 *
 * @param annotation The annotation that was flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation was flattened onto.
 */
- (void)annotationFlattened:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Used to notify the tool manager that the data of a form field has been modified.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)formFieldDataModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

#pragma mark - Page events

/**
 * Used to notify the tool manager that a page has been added.
 *
 * @param pageNumber The page number of the page that was added.
 */
- (void)pageAddedForPageNumber:(int)pageNumber;

/**
 Used to notify the tool manager that a page has been moved.
 *
 * @param oldPageNumber The old page number of the page.
 * @param newPageNumber The new page number of the page.
 */
- (void)pageMovedFromPageNumber:(int)oldPageNumber toPageNumber:(int)newPageNumber;

/**
 * Used to notify the tool manager that a page has been removed.
 *
 * @param pageNumber The page number of the page that was removed.
 */
- (void)pageRemovedForPageNumber:(int)pageNumber;

#pragma mark Rotation

/**
 * Used to notify the tool manager that a page will be rotated.
 *
 * @param pageNumber the page number of the page that will be rotated
 */
- (void)willRotatePageForPageNumber:(int)pageNumber;

/**
 * Used to notify the tool manager that pages in the document will be rotated.
 *
 * @param pageNumbers the page numbers of the pages that will be rotated
 */
- (void)willRotatePagesForPageNumbers:(NSIndexSet *)pageNumbers;

/**
 * Used to notify the tool manager that a page was rotated.
 *
 * @param pageNumber the page number of the page that was rotated
 */
- (void)didRotatePageForPageNumber:(int)pageNumber;

/**
 * Used to notify the tool manager that pages in the document were rotated.
 *
 * @param pageNumbers the page numbers of the pages that were rotated
 */
- (void)didRotatePagesForPageNumbers:(NSIndexSet *)pageNumbers;

#pragma mark - Observers

/**
 * Adds the specified observer to the list of observers to be notified of changes in the tool manager.
 *
 * @note The `observer` object is held weakly internally and it is not necessary to remove an observer
 * before it is deallocated.
 */
- (void)addObserver:(id<PTToolManagerObserver>)observer;

/**
 * Removes the specified observer from the list of observers to be notified of changes in the tool
 * manager.
 */
- (void)removeObserver:(id<PTToolManagerObserver>)observer;

@end

/**
 * The methods declared by the `PTToolManagerDelegate` protocol allow the adopting
 * delegate to respond to messages from the PTToolManager class.
 */
PT_OBJC_RUNTIME_NAME(ToolManagerDelegate)
@protocol PTToolManagerDelegate <NSObject>

#pragma mark - Required PTToolManagerDelegate methods
@required
/**
 * Allows the delegate to provide a view controller to manage presentations.
 *
 * @param toolManager The Tool manager.
 *
 * @return a `UIViewController` provided by the delegate for the tool manager to use.
 */
- (UIViewController*)viewControllerForToolManager:(PTToolManager *)toolManager;

#pragma mark - Optional PTToolManagerDelegate methods
@optional

/**
 * Allows the delegate to control if a tool should be activated
 *
 * @param toolManager The tool manager.
 *
 * @param tool The tool that will be activated
 *
 */
- (BOOL)toolManager:(PTToolManager *)toolManager shouldSwitchToTool:(PTTool *)tool;

/**
 * Tells the delegate that the tool will change.
 *
 * @param toolManager The tool manager
 *
 * @param tool The tool that will be activated.
 */
- (void)toolManager:(PTToolManager *)toolManager willSwitchToTool:(nullable PTTool *)tool;
 
/**
 * Tells the delegate that the tool has changed.
 *
 * @param toolManager The PTToolManager that had the tool change.
 *
 */
- (void)toolManagerToolChanged:(PTToolManager *)toolManager;

/**
 * Allows the delegate to take over link handling. Links can either be annotations, or detected
 * as links by PDFNet via text pattern matching (see `-[PTPDFViewCtrl SetUrlExtraction:]`). One of
 * the two first parameters will have a value, the other will be `nil`.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The link annotation, if it exists, that will be handled. If there is not a
 * link annotation, then `nil`.
 *
 * @param linkInfo If it exists, the text that was detected as matching the format of a link.
 * `nil` otherwise.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should handle the link; `NO` if not.
 *
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldHandleLinkAnnotation:(nullable PTAnnot *)annotation orLinkInfo:(nullable PTLinkInfo *)linkInfo onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the delegate to control handling of file attachments.
 *
 * @param toolManager the tool manager.
 *
 * @param fileAttachment the file attachment annotation
 *
 * @param pageNumber The page number that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager handleFileAttachment:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the delegate to control saving of file attachments.
 *
 * @param toolManager The tool manager sending the message
 *
 * @param fileAttachment The file attachment annotation to be saved
 *
 * @param pageNumber The page number that the annotation is on
 */
- (void)toolManager:(PTToolManager *)toolManager didAttemptFileAttachmentSave:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber success:(BOOL)success;

/**
 * Allows the delegate to control handling of file selections.
 *
 * @param toolManager the tool manager.
 *
 * @param filePath the selected file path
 *
 * @return `YES` if the selected file was handled, `NO` if not.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleFileSelected:(NSString *)filePath;

/**
 * Allows the delegate to control handling of file selections with destination page numbers.
 *
 * @param toolManager the tool manager.
 *
 * @param filePath the selected file path
 *
 * @param pageNumber the destination page number of the selected file
 *
 * @return `YES` if the selected file was handled, `NO` if not.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleFileSelected:(NSString *)filePath destinationPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control handling of named actions.
 *
 * @param toolManager the tool manager.
 *
 * @param namedAction the namedAction
 *
 * @return `YES` if the named action was handled, `NO` if not
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleNamedAction:(NSString *)namedAction;

/**
 * Allows the delegate to control whether to show a menu controller for the given annotation and page number.
 *
 * @param toolManager The tool manager.
 *
 * @param menuController The menu to be shown.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should show the UIMenuController; `NO` if not.
 *
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldShowMenu:(UIMenuController *)menuController forAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Called to determine whether the edit menu should be shown.
 *
 * @param toolManager The tool manager.
 * @param annotation The annotation for which the menu will be presented, or `nil`.
 * @param pageNumber The page number of the annotation or that the menu will be presented on.
 *
 * @return `YES` if the edit menu should be shown, `NO` otherwise.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager shouldShowEditMenuForAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber API_AVAILABLE(ios(16.0));

/**
 * Called when the edit menu will be shown.
 *
 * The menu and its actions can be customized via the return value of this method.
 *
 * @param toolManager The tool manager.
 * @param annotation The annotation for which the menu will be presented, or `nil`.
 * @param pageNumber The page number of the annotation or that the menu will be presented on.
 * @param configuration The configuration to be used for the presentation of the edit menu.
 * @param actions The actions that will be displayed in the edit menu.
 *
 * @return A new `UIMenu` instance, which may include the provided `actions` and/or other actions, to
 * be presented. Returning an empty menu results in the presentation being cancelled, otherwise return
 * `nil` to display the default menu with the provided `actions`.
 */
- (nullable UIMenu *)toolManager:(PTToolManager *)toolManager willShowEditMenuForAnnotation:(nullable PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber withConfiguration:(UIEditMenuConfiguration *)configuration actions:(NSArray<UIMenuElement *> *)actions API_AVAILABLE(ios(16.0));

/**
 * Allows the tool manager to control whether the tool should interact the given form annotation on `pageNumber`.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The form annotation that will be activated
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to activate the form annotation; `NO` if not.
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldInteractWithForm:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 140000

/**
 * Allows the delegate to control whether the tool should handle the Apple Pencil (indirect) Scribble
 * interaction for a given annotation on `pageNumber`.
 *
 * @param toolManager The tool manager.
 *
 * @param scribbleInteraction the indirect scribble interaction.
 *
 * @param annotation The annotation that will be selected.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to scribble on the annotation; `NO` if not.
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldHandleIndirectScribbleInteraction:(UIIndirectScribbleInteraction*)scribbleInteraction forAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber API_AVAILABLE(ios(14.0));

#endif /* __IPHONE_OS_VERSION_MAX_ALLOWED >= 140000 */

/**
 * Allows the delegate to control whether the tool should select the given annotation on `pageNumber`.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be selected.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to select the annotation; `NO` if not.
 *
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code selects an annotation.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was selected.
 *
 * @param pageNumber The page number of the PDF that the annotation was selected on.
 */
-(void)toolManager:(PTToolManager *)toolManager didSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * This method is called when text will be copied to the specified pasteboard.
 *
 * @param toolManager The tool manager
 *
 * @param selectedText The text that will be copied
 *
 * @param pasteboard The pasteboard to which the text will be added
 *
 * @return The text that will be copied to the pasteboard. This return value may be different from the
 * value of the `textToCopy` parameter.
 */
- (nullable NSString *)toolManager:(PTToolManager *)toolManager willCopyReturnedText:(nullable NSString *)selectedText toPasteboard:(UIPasteboard *)pasteboard;

/**
 * This method is called when text has been copied to the specified pasteboard.
 *
 * @param toolManager The tool manager sending the message
 *
 * @param copiedText The text that was added to the pasteboard
 *
 * @param pasteboard The pasteboard to which the text was added
 */
- (void)toolManager:(PTToolManager *)toolManager didCopyText:(nullable NSString *)copiedText toPasteboard:(UIPasteboard *)pasteboard;

/**
 * Called when determining if the current user is permitted to edit an annotation made by a different
 * author. If this method is not implemented then the current user is not permitted to edit the
 * annotation.
 *
 * @note This method is only called when the `PTToolManager.annotationAuthorCheckEnabled` property
 * is enabled.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be edited.
 *
 * @param author The author of this annotation.
 *
 * @return `YES` if the current user should be permitted to edit the annotation, `NO` otherwise.
 *
 * @see `PTToolManager.annotationAuthorCheckEnabled`
 * @see `PTToolManager.annotationPermissionCheckEnabled`
 */
- (BOOL)toolManager:(PTToolManager *)toolManager hasEditPermissionForAnnotation:(PTAnnot *)annotation withAuthor:(nullable NSString *)author;

/**
 * Raised when the tools code adds an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationAdded:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised before the tools code modifies an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be modified.
 *
 * @param pageNumber The page number of the PDF that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager willModifyAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code modifies an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised before the tools code removes an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be removed.
 *
 * @param pageNumber The page number of the PDF that the annotation will be removed from.
 */
- (void)toolManager:(PTToolManager *)toolManager willRemoveAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code removes an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationRemoved:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised before the tools code flattens an annotation. This will be called before the `willRemoveAnnotation:` delegate method.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation will be flattened onto.
 */
- (void)toolManager:(PTToolManager *)toolManager willFlattenAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code flattens an annotation. This will be called before the `annotationRemoved:` delegate method.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation was flattened onto.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationFlattened:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code modifies a form field annotation's data
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager formFieldDataModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when page has been added to the document.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumber The page number of the page that was added.
 */
- (void)toolManager:(PTToolManager *)toolManager pageAddedForPageNumber:(int)pageNumber;

/**
 * Raised when a page has been moved in the document.
 *
 * @param toolManager The tool manager.
 *
 * @param oldPageNumber The old page number of the page.
 *
 * @param newPageNumber The new page number of the page.
 */
- (void)toolManager:(PTToolManager *)toolManager pageMovedFromPageNumber:(int)oldPageNumber toPageNumber:(int)newPageNumber;

/**
 * Raised when a page has been removed from the document.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumber The page number of the page that was removed.
 */
- (void)toolManager:(PTToolManager *)toolManager pageRemovedForPageNumber:(int)pageNumber;

/**
 * Raised when pages will be rotated.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumbers The page numbers of the pages that will be rotated.
 */
- (void)toolManager:(PTToolManager *)toolManager willRotatePagesForPageNumbers:(NSIndexSet *)pageNumbers;

/**
 * Raised when pages have been rotated.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumbers The page numbers of the pages that were rotated
 */
- (void)toolManager:(PTToolManager *)toolManager didRotatePagesForPageNumbers:(NSIndexSet *)pageNumbers;

#pragma mark - Overriding default gesture behavior
/** @name Overriding default gesture behavior
 */

/**
 * Allows the delegate to handle tap gestures.
 *
 * @param toolManager The Tool manager.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the delegate has handled the event, `NO` if it should be handled by the tool manager.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Allows the delegate to handle double tap gestures.
 *
 * @param toolManager The Tool manager.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the delegate has handled the event, `NO` if it should be handled by the tool manager.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleDoubleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Allows the delegate to handle long press gestures.
 *
 * @param toolManager The Tool manager.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the delegate has handled the event, `NO` if it should be handled by the tool manager.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleLongPress:(UILongPressGestureRecognizer *)gestureRecognizer;

@end

#pragma mark - Notifications

/**
 * Posted when the tool will be changed.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerToolUserInfoKey` key when there is a next tool.
 */
PT_EXPORT const NSNotificationName PTToolManagerToolWillChangeNotification;

/**
 * Posted when the tool has changed.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerPreviousToolUserInfoKey` key when there is a previous tool.
 */
PT_EXPORT const NSNotificationName PTToolManagerToolDidChangeNotification;

/**
 * Posted when an annotation is added.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationAddedNotification;

/**
 * Posted when an annotation will be modified.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationWillModifyNotification;

/**
 * Posted when an annotation is modified.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationModifiedNotification;

/**
 * Posted when an annotation will be removed.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationWillRemoveNotification;

/**
 * Posted when an annotation is removed.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationRemovedNotification;

/**
 * Posted when an annotation will be flattened.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationWillFlattenNotification;

/**
 * Posted when an annotation is flattened.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationFlattenedNotification;

/**
 * Posted when a form field's data is modified, e.g. a text box's text is modified, a checkbox is checked, etc.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerFormFieldDataModifiedNotification;

/**
 * Posted when text will be copied to a pasteboard.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerTextUserInfoKey` and `PTToolManagerPasteboardUserInfoKey` keys.
 */
PT_EXTERN const NSNotificationName PTToolManagerWillCopyTextNotification;

/**
 * Posted when text has been copied to a pasteboard.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerTextUserInfoKey` and `PTToolManagerPasteboardUserInfoKey` keys.
 */
PT_EXTERN const NSNotificationName PTToolManagerDidCopyTextNotification;

/**
 * Posted when annotation options change.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerAnnotationNamesUserInfoKey` key with the changed annotation
 * types.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationOptionsDidChangeNotification;

/**
 * Posted when a page is added to the document.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerPageNumberUserInfoKey` key with the added page number.
 */
PT_EXPORT const NSNotificationName PTToolManagerPageAddedNotification;

/**
 * Posted when a page is moved in the document.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerPreviousPageNumberUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys with the old and new page numbers, respectively.
 */
PT_EXPORT const NSNotificationName PTToolManagerPageMovedNotification;

/**
 * Posted when a page is removed from the document.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerPageNumberUserInfoKey` key with the removed page number.
 */
PT_EXPORT const NSNotificationName PTToolManagerPageRemovedNotification;

/**
 * Posted when pages in the document will be rotated.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerPageNumbersUserInfoKey` key with the rotated page numbers.
 */
PT_EXPORT const NSNotificationName PTToolManagerPagesWillRotateNotification;

/**
 * Posted when pages in the document are rotated.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerPageNumbersUserInfoKey` key with the rotated page numbers.
 */
PT_EXPORT const NSNotificationName PTToolManagerPagesDidRotateNotification;

#pragma mark User Info Keys

/**
 * The key for a `PTTool` object.
 */
PT_EXPORT NSString * const PTToolManagerToolUserInfoKey;

/**
 * The key for the `Class` of the previous tool type.
 */
PT_EXPORT NSString * const PTToolManagerPreviousToolUserInfoKey;

/**
 * The key for a `PTAnnot` object.
 */
PT_EXPORT NSString * const PTToolManagerAnnotationUserInfoKey;

/**
 * The key for a `NSNumber` object containing an `int` page number.
 */
PT_EXPORT NSString * const PTToolManagerPageNumberUserInfoKey;

/**
 * The key for a `NSIndexSet` object containing page numbers.
 */
PT_EXPORT NSString * const PTToolManagerPageNumbersUserInfoKey;

/**
 * The key for an `NSString` instance.
 */
PT_EXTERN NSString * const PTToolManagerTextUserInfoKey;

/**
 * The key for a `UIPasteboard` instance.
 */
PT_EXTERN NSString * const PTToolManagerPasteboardUserInfoKey;

/**
 * The key for an `NSArray` of `PTExtendedAnnotName` constants.
 */
PT_EXPORT NSString * const PTToolManagerAnnotationNamesUserInfoKey;

/**
 * The key for a `NSNumber` object containing an `int` page number.
 */
PT_EXPORT NSString * const PTToolManagerPreviousPageNumberUserInfoKey;

/**
 * Instances of classes conforming to the `PTToolManagerObserver` protocol can be notified of changes
 * in the tool manager.
 */
PT_OBJC_RUNTIME_NAME(ToolManagerObserver)
@protocol PTToolManagerObserver <NSObject>
@optional

#pragma mark Tool events

/**
 * Notifies the observer that the tool manager's tool will change.
 *
 * @param toolManager The tool manager whose tool will change
 *
 * @param newTool The tool that the tool manager will change to
 */
- (void)toolManager:(PTToolManager *)toolManager willChangeToTool:(nullable PTTool *)newTool;

/**
 * Notifies the observer that the tool manager's tool has changed.
 *
 * @param toolManager The tool manager whose tool changed
 *
 * @param previousTool The previous tool, or `nil` if there was no previous tool
 */
- (void)toolManager:(PTToolManager *)toolManager didChangeFromTool:(nullable PTTool *)previousTool;

#pragma mark Selection events

/**
 * Raised when the tools code selects an annotation.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was selected.
 *
 * @param pageNumber The page number of the PDF that the annotation was selected on.
 */
- (void)toolManager:(PTToolManager *)toolManager didSelectAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

#pragma mark Text events

/**
 * This method is called when text has been copied to the specified pasteboard.
 *
 * @param toolManager The tool manager sending the message
 *
 * @param copiedText The text that was added to the pasteboard
 *
 * @param pasteboard The pasteboard to which the text was added
 */
- (void)toolManager:(PTToolManager *)toolManager didCopyText:(nullable NSString *)copiedText toPasteboard:(UIPasteboard *)pasteboard;

#pragma mark Annotation events

/**
 * Raised when the tools code adds an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationAdded:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Raised before the tools code modifies an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be modified.
 *
 * @param pageNumber The page number of the PDF that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager willModifyAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code modifies an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Raised before the tools code removes an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be removed.
 *
 * @param pageNumber The page number of the PDF that the annotation will be removed from.
 */
- (void)toolManager:(PTToolManager *)toolManager willRemoveAnnotation:(PTAnnot*)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code removes an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationRemoved:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Raised before the tools code flattens an annotation. This will be called before the `willRemoveAnnotation:` delegate method.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation will be flattened onto.
 */
- (void)toolManager:(PTToolManager *)toolManager willFlattenAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code flattens an annotation. This will be called before the `annotationRemoved:` delegate method.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was flattened.
 *
 * @param pageNumber The page number of the PDF that the annotation was flattened onto.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationFlattened:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Raised when the tools code modifies a form field annotation's data
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager formFieldDataModified:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

#pragma mark Page events

/**
 * Raised when a page has been added to the document.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumber The page number of the page that was added.
 */
- (void)toolManager:(PTToolManager *)toolManager pageAddedForPageNumber:(int)pageNumber;

/**
 * Raised when a page has been moved in the document.
 *
 * @param toolManager The tool manager.
 *
 * @param oldPageNumber The old page number of the page.
 *
 * @param newPageNumber The new page number of the page.
 */
- (void)toolManager:(PTToolManager *)toolManager pageMovedFromPageNumber:(int)oldPageNumber toPageNumber:(int)newPageNumber;

/**
 * Raised when a page has been removed from the document.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumber The page number of the page that was removed.
 */
- (void)toolManager:(PTToolManager *)toolManager pageRemovedForPageNumber:(int)pageNumber;

/**
 * Raised when pages will be rotated.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumbers The page numbers of the pages that will be rotated.
 */
- (void)toolManager:(PTToolManager *)toolManager willRotatePagesForPageNumbers:(NSIndexSet *)pageNumbers;

/**
 * Raised when pages have been rotated.
 *
 * @param toolManager The tool manager.
 *
 * @param pageNumbers The page numbers of the pages that were rotated
 */
- (void)toolManager:(PTToolManager *)toolManager didRotatePagesForPageNumbers:(NSIndexSet *)pageNumbers;

#pragma mark Appearance views

/**
 * Notifies the observer that the live-appearance view will be displayed for the specified annotation.
 *
 * @param toolManager The tool manager.
 *
 * @param appearanceView The annotation appearance view that will be displayed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number of the annotation.
 */
- (void)toolManager:(PTToolManager *)toolManager willDisplayAppearanceView:(UIView *)appearanceView forAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

/**
 * Notifies the observer that the live-appearance view is no longer being displayed for the specified
 * annotation.
 *
 * @param toolManager The tool manager.
 *
 * @param appearanceView The annotation appearance view that was displayed.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number of the annotation.
 */
- (void)toolManager:(PTToolManager *)toolManager didEndDisplayingAppearanceView:(UIView *)appearanceView forAnnotation:(PTAnnot *)annotation onPageNumber:(int)pageNumber;

@end

/**
 * Convenience methods for setting and getting a custom font for a free text annotation.
 */
@interface PTFreeText (SetFont)

/**
 * Sets the free text annotation to use the font specified. The font must be available
 * on the device https://developer.apple.com/fonts/system-fonts/
 *
 * @param fontName The name of the font.
 *
 * @param doc The PDF document that the annotation is part of.
 *
 * @note `-RefreshAppearance` must be called after this method to generate the new appearance.
 *
 * @note This method writes to the PDFDoc, so a write lock is required if the document is
 * displayed in a viewer or otherwise accessible via multiple threads. Without a write lock,
 * undefined behaviour including crashing is likely to occur.
 */
- (void)setFontWithName:(NSString *)fontName pdfDoc:(PTPDFDoc *)doc;

/**
 * Returns the name of the font used by this annotation.
 *
 * @return The name of the font. If no font name is specified, this method returns `nil`.
 */
- (nullable NSString *)getFontName;

@end

/**
 * This protocol allows a conforming object, usually a `UIViewController` subclass, to control the
 * presentation of other view controllers.
 */
PT_OBJC_RUNTIME_NAME(ToolManagerViewControllerPresentation)
@protocol PTToolManagerViewControllerPresentation <NSObject>
@optional

/**
 * Specifies whether the view controller prefers the navigation bar to be hidden or shown.
 *
 * @return `YES` if the navigation bar should be hidden.
 */
- (BOOL)prefersNavigationBarHidden;

@end

NS_ASSUME_NONNULL_END
