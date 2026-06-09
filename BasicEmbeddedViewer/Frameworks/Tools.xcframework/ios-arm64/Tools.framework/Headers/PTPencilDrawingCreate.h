//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTCreateToolBase.h>
#import <Tools/PTCanvasView.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPencilDrawingCreate;
/**
 * Informs the delegate object of changes in the originator's state.
 */
NS_CLASS_AVAILABLE_IOS(13_1) @protocol PTPencilDrawingCreateDelegate <NSObject>
@optional

/**
 * Called when a user adds a new stroke by touching the screen.
 *
 * @param pencilDrawingCreate the instance of the object calling the method
 */
- (void)strokeAdded:(PTPencilDrawingCreate*)pencilDrawingCreate PT_DEPRECATED_MSG(9.0.2, "Please use the pencilDrawingCreateStrokeAdded method instead");

/**
 * Called when a user adds a new stroke by touching the screen.
 *
 * @param pencilDrawingCreate the instance of the object calling the method
 */
- (void)pencilDrawingCreateStrokeAdded:(PTPencilDrawingCreate*)pencilDrawingCreate;

@end

/**
 * Creates Apple Pencil drawing annotations.
 */
NS_CLASS_AVAILABLE_IOS(13_1) PT_OBJC_RUNTIME_NAME(PencilDrawingCreate)
@interface PTPencilDrawingCreate : PTCreateToolBase

/**
 * Adds the freehand annotation to the document.
*/
-(void)commitAnnotation;

/**
 * Edit the annotation.
*/
-(void)editAnnotation:(PTAnnot*)annot onPage:(int)pageNumber;

/**
 * Cancels editing of the current annotation.
*/
- (void)cancelEditingAnnotation;

/**
 * Set to `YES` if the `PKToolPicker` should be visible.
 */
@property (nonatomic, assign) BOOL shouldShowToolPicker;

/**
 * The canvas used for drawing `PTPencilDrawingCreate` annotations using `PencilKit`.
 * A subclass of `PKCanvasView`.
 */
@property (nonatomic, strong) PTCanvasView *canvasView;

/**
 * An object that conforms to the PTPencilDrawingCreateDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTPencilDrawingCreateDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
