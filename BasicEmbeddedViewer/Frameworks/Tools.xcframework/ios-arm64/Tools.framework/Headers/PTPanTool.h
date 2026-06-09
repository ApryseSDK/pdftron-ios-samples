//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTTool.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A non-annotating tool that is used to navigate the document. When the user taps or long
 * presses on the document, the pan tool will check the content of the document for annotaitons
 * and text, and if found, pass the event to the appropriate tool. When long pressing an
 * emtpy section of the document, the `PTPanTool` gives the option to switch to a selection of
 * annotation creation tools.
 */
PT_OBJC_RUNTIME_NAME(PanTool)
@interface PTPanTool : PTTool

/**
 * Shows the UIMenuController after a tap (in addition to after a long press).
 * Default is false.
 */
@property (nonatomic, assign) BOOL showMenuOnTap;

/**
 * When true, and `showMenuOnTap` is true, the next tap event will show the UIMenuController.
 */
@property (nonatomic, assign) BOOL showMenuNextTap;

#pragma mark - Menu actions

/**
 * Create an area annotation with the `PTAreaCreate` tool.
 */
- (void)createArea:(id)sender;

/**
 * Create an arrow annotation with the `PTArrowCreate` tool.
 */
- (void)createArrow:(id)sender;

/**
 * Create a callout annotation with the `PTCalloutCreate` tool.
 */
- (void)createCallout:(id)sender;

/**
 * Create a checkbox annotation with the `PTCheckBoxCreate` tool.
 */
- (void)createCheckBox:(id)sender;

/**
 * Create a clouded polygon annotation with the `PTCloudCreate` tool.
 */
- (void)createCloud:(id)sender;

/**
 * Create a combo-box annotation with the `PTComboBoxCreate` tool.
 */
- (void)createComboBox:(id)sender;

/**
 * Create a date-text annotation with the `PTDateTextCreate` tool.
 */
- (void)createDateText:(id)sender;

/**
 * Create an ellipse annotation with the `PTEllipseCreate` tool.
 */
- (void)createEllipse:(id)sender;

/**
 * Create a file attachment annotation with the `PTFileAttachmentCreate` tool.
 */
- (void)createFileAttachment:(id)sender;

/**
 * Create a freehand ink annotation with the `PTFreeHandCreate` tool.
 */
- (void)createFreeHand:(id)sender;

/**
 * Create a freehand highlight annotation with the `PTFreeHandHighlightCreate` tool.
 */
- (void)createFreeHandHighlight:(id)sender;

/**
 * Create a free text annotation with the `PTFreeTextCreate` tool.
 */
- (void)createFreeText:(id)sender;

/**
 * Create an image stamp annotation with the `PTImageStampCreate` tool.
 */
- (void)createImageStamp:(id)sender;

/**
 * Create a line annotation with the `PTLineCreate` tool.
 */
- (void)createLine:(id)sender;

/**
 * Create a link annotation with the `PTLinkCreate` tool.
 */
- (void)createLink:(id)sender;

/**
 * Create a list-box annotation with the `PTListBoxCreate` tool.
 */
- (void)createListBox:(id)sender;

/**
 * Create a perimeter measurement annotation with the `PTPerimeterCreate` tool.
 */
- (void)createPerimeter:(id)sender;

/**
 * Create a polygon annotation with the `PTPolygonCreate` tool.
 */
- (void)createPolygon:(id)sender;

/**
 * Create a polyline annotation with the `PTPolylineCreate` tool.
 */
- (void)createPolyline:(id)sender;

/**
 * Create a radio button annotation with the `PTRadioButtonCreate` tool.
 */
- (void)createRadioButton:(id)sender;

/**
 * Create a rectangle annotation with the `PTRectangleCreate` tool.
 */
- (void)createRectangle:(id)sender;

/**
 * Create a redaction annotation with the `PTRectangleRedactionCreate` tool.
 */
- (void)createRedaction:(id)sender;

/**
 * Create a rubber stamp annotation with the `PTRubberStampCreate` tool.
 */
- (void)createRubberStamp:(id)sender;

/**
 * Create a ruler measurement annotation with the `PTRulerCreate` tool.
 */
- (void)createRuler:(id)sender;

/**
 * Create a (floating) signature annotation with the `PTDigitalSignatureTool` tool.
 */
- (void)createSignature:(id)sender;

/**
 * Create a signature field annotation with the `PTSignatureFieldCreate` tool.
 */
- (void)createSignatureField:(id)sender;

/**
 * Create a sticky note annotation with the `PTStickyNoteCreate` tool.
 */
- (void)createStickyNote:(id)sender;

/**
 * Create a text field annotation `PTTextFieldCreate` tool.
 */
- (void)createTextField:(id)sender;

/**
 * Switch to the annotation multi-selection `PTAnnotSelectTool` tool.
 */
- (void)multiSelectTool:(id)sender;

#pragma mark Submenus

/**
 * Shows the "Shapes" submenu.
 */
- (void)showShapesMenu:(id)sender;

/**
 * Shows the "Measure" submenu.
 */
- (void)showMeasureMenu:(id)sender;

/**
 * Shows the "Attach" submenu.
 */
- (void)showAttachMenu:(id)sender;

@end

NS_ASSUME_NONNULL_END
