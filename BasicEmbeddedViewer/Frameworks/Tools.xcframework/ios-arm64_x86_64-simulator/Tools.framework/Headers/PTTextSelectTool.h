//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTTool.h>
#import <Tools/PTSelectionBar.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Tool for selecting text.
 */
PT_OBJC_RUNTIME_NAME(TextSelectTool)
@interface PTTextSelectTool : PTTool

/**
 * The starting point of where to start a selection, defined by the user's
 * finger's location when dragging a selection bar.
 */
@property (readonly, nonatomic, assign) CGPoint selectionStart;

/**
 * The starting point of where to end a selection, defined by the user's
 * finger's location when dragging a selection bar.
 */
@property (readonly, nonatomic, assign) CGPoint selectionEnd;

/**
 * The starting point of the selected text, where the `self.leadingBar` is.
 */
@property (readonly, nonatomic, assign) CGPoint selectionStartCorner;

/**
 * The starting point of the selected text, where the `self.trailingBar` is.
 */
@property (readonly, nonatomic, assign) CGPoint selectionEndCorner;

/**
 * The first page of the selection
 */
@property (readonly, nonatomic, assign) int selectionStartPageNumber;

/**
 * The last page of the selection
 */
@property (readonly, nonatomic, assign) int selectionEndPageNumber;

/**
 * `YES` if there is a text selection visible on the screen.
 */
@property (readonly, nonatomic, assign) BOOL selectionOnScreen;

/**
 * The current selection, represented as screen-space `CGRect` values.
 */
@property (nonatomic, readonly, copy, nullable) NSArray<NSValue *> *selection;

/**
 * An array of `CALayer` objects that are used for highlighting selected text.
 */
@property (readonly, nonatomic, copy) NSArray<__kindof CALayer*>* selectionLayers;

/**
 * The leading selection bar.
 */
@property (readonly, nonatomic, strong, nullable) PTSelectionBar* leadingBar;

/**
 * The trailing selection bar.
 */
@property (readonly, nonatomic, strong, nullable) PTSelectionBar* trailingBar;

/**
 * Visually selects the text.
 *
 * @param quads An array of `CGRect`s (wrapped in `NSValue`) representing where to
 * visually select. Screen (`PTPDFViewCtrl`) coordinates.
 *
 * @param lines Set to `YES` if selection should have resize handles.
 */
-(void)DrawSelectionQuads:(NSArray<NSValue*>*)quads WithLines:(BOOL)lines WithDropAnimation:(BOOL)animation;

/**
 * Uses the current selection and default annotaiton properties to create a new
 * text markup annotation.
 *
 * @param annotType The type of text markup annotation.
 */
-(void)createTextMarkupAnnot:(PTExtendedAnnotType)annotType;

/**
 * Uses the current selection to create a new text markup annotation.
 *
 * @param annotType The type of text markup annotation.
 *
 * @param color The color of the annotation
 *
 * @param components The number of components of the new color.
 *
 * @param opacity The opacity of the new annotation, where 0. is fully transparent,
 * and 1. is fully opaque.
 *
 */
-(void)createTextMarkupAnnot:(PTExtendedAnnotType)annotType withColor:(PTColorPt*)color withComponents:(int)components withOpacity:(double)opacity;


/** 
 * Selects text using the properties `selectionStart` and `selectionEnd`
 * points.
 *
 * @note Note that this is a conceptual selection - to visually select it,
 * the returned array must be pased to `DrawSelectionQuads:WithLines`.
 *
 * @return An array of `NSValue` wrapped `CGRect`s, representing the selected
 * text.
 */
-(nullable NSArray<NSValue *> *)MakeSelection;

/**
 * Clears the selection bars and conceptual selection.
 */
-(void)ClearSelectionBars;

/**
 * Clears the visual selection.
 */
-(void)ClearSelectionOnly;

/**
 * Show the shared `UIMenuController` with options relevant for the selection.
 */
-(void)ShowMenuController;

/**
 * Retrieves the quads of the current selection for visual display via
 * `DrawSelectionQuads:withLines:`.
 *
 * @param page1 The first page to retrieve the quads from.
 *
 * @param page2 The second page to retreive the quads from.
 *
 * @return The selection's quads.
 */
-(nullable NSArray<NSValue*>*)GetQuadsFromPage:(int)page1 ToPage:(int)page2;

/**
 * Adds the draggable dots to the selection.
 *
 * @param selection The quads of the current selection, as returned by `MakeSelection`
 * or `GetQuadsFromPage:ToPage:`.
 */
- (void)DrawSelectionBars:(NSArray<NSValue*>*)selection;

#pragma mark - Text selection actions

/**
 * Copies the selected text to the pasteboard.
 *
 * @param sender The object calling this method.
 */
- (void)copyText:(nullable id)sender;

/**
 * Highlights the selected text
 *
 * @param sender The object calling this method.
 */
- (void)highlightText:(nullable id)sender;

/**
 * Underlines the selected text
 *
 * @param sender The object calling this method.
 */
- (void)underlineText:(nullable id)sender;

/**
 * Squiggly underlines the selected text
 *
 * @param sender The object calling this method.
 */
- (void)squigglyUnderlineText:(nullable id)sender;

/**
 * Strikeout the selected text
 *
 * @param sender The object calling this method.
 */
- (void)strikeoutText:(nullable id)sender;

/**
 * Defines the selected text
 *
 * @param sender The object calling this method.
 */
- (void)defineText:(nullable id)sender;

/**
 * Speaks the selected text (text to speach)
 *
 * @param sender The object calling this method.
 */
- (void)speakText:(nullable id)sender;

@end

NS_ASSUME_NONNULL_END
