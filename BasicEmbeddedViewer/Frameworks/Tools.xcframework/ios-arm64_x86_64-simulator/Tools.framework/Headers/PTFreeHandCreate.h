//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTCreateToolBase.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFreeHandCreate;

/**
 * Informs the delegate object of changes in the originator's state.
 */
PT_OBJC_RUNTIME_NAME(FreeHandCreateDelegate)
@protocol PTFreeHandCreateDelegate <NSObject>
@optional

/**
 * Called when a user adds a new stroke by touching the screen (as opposed to a redo action).
 * Typically used to enable an "undo" button.
 *
 * @param freeHandCreate the instance of the object calling the method
 */
- (void)strokeAdded:(PTFreeHandCreate*)freeHandCreate PT_DEPRECATED_MSG(9.0.2, "Please use the freeHandCreateStrokeAdded method instead");

/**
 * Called when a user adds a new stroke by touching the screen (as opposed to a redo action).
 * Typically used to enable an "undo" button.
 *
 * @param freeHandCreate the instance of the object calling the method
 */
- (void)freeHandCreateStrokeAdded:(PTFreeHandCreate*)freeHandCreate;

@end

/**
 * Creates FreeHand (Ink) annotations.
 */
PT_OBJC_RUNTIME_NAME(FreeHandCreate)
@interface PTFreeHandCreate : PTCreateToolBase

// The following selectors are useful if implementing PTFreeHandCreate with multistrokeMode YES

/**
 * Removes the most recently added stroke.
 */
-(void)undoStroke;

/**
 * Restores a stroke removed with `undoStroke`.
 */
-(void)redoStroke;

/**
 * @return Returns `YES` if there are strikes than can be removed via `undoStroke`.
 */
-(BOOL)canUndoStroke;

/**
 * @return Returns `YES` if there are strikes than can be restoried via `redoStroke`.
 */
-(BOOL)canRedoStroke;

/**
 * Creates a freehand (ink) annotation from the tools current strokes.
 */
- (PTInk *)createAnnotation;

/**
 * Adds the freehand annotation to the document. Used when `multistrokeMode` is set to
 * `YES`.
 */
-(void)commitAnnotation;


/**
 *
 * Used to determine if there is a point at the specified location before the annotation has
 * been added to the PDF
 *
 * @param screenPoint The point which is to be tested for, in screen coordinates.
 *
 * @param threshold The tolerance of the test
 *
 * @return true if there is a point within the specified threshold; false otherwise.
 *
 */
-(BOOL)inkPointPresentAtScreenPoint:(CGPoint)screenPoint within:(CGFloat)threshold;

/**
 * Set to `YES` if the annotation should include multiple strokes. Call `commitAnnotation`
 * push the annotation back into the PDF.
 */
@property (nonatomic, assign) BOOL multistrokeMode;

/**
 * Set to `YES` if the annotation was started by drawing with
 * a stylus.
 */
@property (nonatomic, assign) BOOL pencilMode;

/**
 * Whether this tool requires an editing interface (toolbar) to operate.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, readwrite) BOOL requiresEditSupport;

/**
 * Whether this tool should apply a straight-line smoothing to the drawn strokes.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, readwrite) BOOL smoothStrokes;

/**
 * An object that conforms to the PTFreeHandCreateDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTFreeHandCreateDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
