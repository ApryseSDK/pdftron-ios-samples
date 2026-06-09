//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTextSelectTool.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Tool for editing existing text markup annotations, such as highlights, underlines, etc.
 * In addition to changing basic properties like colour and opacity, it can change the
 * annotation's size, and it's type (e.g. turn a highlight into an underline).
 */
PT_OBJC_RUNTIME_NAME(TextMarkupEditTool)
@interface PTTextMarkupEditTool : PTTextSelectTool

/**
 * Selects the specified text markup annotation.
 *
 * @param annotation the annotation to select
 *
 * @param pageNumber the page number of the annotation
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 */
- (BOOL)selectTextMarkupAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned int)pageNumber;

/**
 * Copies the PDF text under the selected text markup annotation to the system clipboard/pasteboard.
 *
 * This method is called by default by the "Copy" selection menu item.
 */
- (void)copySelectedMarkupText:(id)sender;

/**
 * Shows a menu that allows changing the text markup type for the currently selected annotation(s).
 *
 * This method is called by default by the "Type" selection menu item.
 */
- (void)editSelectedAnnotationType:(id)sender;

/**
 * Flattens the currently selected text markup annotation(s).
 *
 * This method is called by default by the "Flatten" selection menu item.
 */
- (void)flattenSelectedAnnotations:(id)sender;

#pragma mark - Selection border

/**
 * Whether a border is drawn around the selected text.
 *
 * The bounding box of all the selected text is used for the border, matching the behavior of other
 * multi-element annotation selections (grouped annotations, etc.).
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isSelectionBorderEnabled) BOOL selectionBorderEnabled;

#pragma mark Appearance

/**
 * The color of the border drawn around the selected text.
 *
 * When the value of this property is `nil`, the tool's tint color (`UIView.tintColor`) will be used.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) UIColor *selectionBorderColor UI_APPEARANCE_SELECTOR;

/**
 * The margin between the selection border and the selected text.
 *
 * The default value of this property is `10pt`.
 */
@property (nonatomic, assign) CGFloat selectionRectMargin UI_APPEARANCE_SELECTOR;

/**
 * The width of the border drawn around the selected text.
 *
 * The default value of this property is `1.0pt`.
 */
@property (nonatomic, assign) CGFloat selectionBorderWith UI_APPEARANCE_SELECTOR;

/**
 * The corner radius of the border drawn around the selected text.
 *
 * The default value of this property is `0.0`.
 */
@property (nonatomic, assign) CGFloat selectionBorderCornerRadius UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
