//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotEditTool.h>
#import <Tools/PTFreeTextView.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTResizeWidgetView.h>
#import <Tools/PTRotateWidgetView.h>
#import <Tools/PTSelectionRectView.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The location of a `PTRotateWidgetView` rotation handle around the edge of a rectangle.
typedef NS_ENUM(NSInteger, PTRotateHandleLocation) {
    /// The top side
    PTRotateHandleLocationTop,
    /// The left side
    PTRotateHandleLocationLeft,
    /// The bottom side
    PTRotateHandleLocationBottom,
    /// The right side
    PTRotateHandleLocationRight
};

@class PTAnnotEditTool;
@class PTFreeTextView;
@class PTSelectionRectView;

/**
 * A transparent container view for the shaded `PTSelectionRectView` and the resize widgets.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(SelectionRectContainerView)
@interface PTSelectionRectContainerView : UIView <PTOverridable>

/**
 * Initializes a new `PTSelectionRectContainerView` instance.
 *
 * @param pdfViewCtrl The PTPDFViewCtrl instance that this view uses.
 *
 * @param annot The annotation that this view will be shown over, or `nil`.
 *
 * @param tool The current tool.
 *
 * @return An initialized `PTSelectionRectContainerView` instance.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl
                           forAnnot:(nullable PTAnnot *)annot
                  withAnnotEditTool:(PTAnnotEditTool *)tool NS_DESIGNATED_INITIALIZER;

/** @name Properties
 */
#pragma mark - Properties

/**
 * The shaded rectangle that is overlayed onto the selected annotation.
 */
@property (readonly, nonatomic, strong) PTSelectionRectView* selectionRectView;

/**
 * The rectangle that covers the group of annotations
 */
@property (readonly, nonatomic, strong) UIView* groupSelectionRectView;

/**
 * The rectangle that draws the line between control resize widgets
 */
@property (readonly, nonatomic, strong) UIView* borderView;

/**
 * The PTPDFViewCtrl that the selection is on.
 */
@property (nonatomic, weak) PTPDFViewCtrl* pdfViewCtrl;

#pragma mark - Appearance

/**
 * The margin between the border and the selection.
 *
 * @note The default value of this property is `20pt`.
 */
@property (nonatomic, assign) CGFloat selectionRectMargin UI_APPEARANCE_SELECTOR;

/**
 * The width of the border drawn around the selection.
 *
 * @note The default value of this property is `1.0pt`.
 */
@property (nonatomic, assign) CGFloat borderWith UI_APPEARANCE_SELECTOR;

/**
 * The corner radius of the border drawn around the selection.
 *
 * @note The default value of this property is `0.0`.
 */
@property (nonatomic, assign) CGFloat borderCornerRadius UI_APPEARANCE_SELECTOR;

#pragma mark - Resize widgets

/**
 * The resize widgets displayed by this view.
 */
@property (nonatomic, readonly, copy) NSArray<PTResizeWidgetView *> *resizeWidgetViews;

/**
 * Returns the resize widget for the specified location.
 *
 * @param location The location of the resize widget.
 *
 * @return The resize widget for the specified location.
 */
- (PTResizeWidgetView *)resizeWidgetViewForLocation:(PTResizeHandleLocation)location;

#pragma mark - Resize Widget Visibility

- (BOOL)isResizeWidgetViewHiddenForLocation:(PTResizeHandleLocation)location;
- (void)setResizeWidgetViewHidden:(BOOL)hidden forLocation:(PTResizeHandleLocation)location;

- (void)hideResizeWidgetViewForLocation:(PTResizeHandleLocation)location;
- (void)showResizeWidgetViewForLocation:(PTResizeHandleLocation)location;

#pragma mark Icons

- (void)setResizeWidgetIcon:(nullable UIImage *)resizeWidgetIcon
                forLocation:(PTResizeHandleLocation)location UI_APPEARANCE_SELECTOR;
- (nullable UIImage *)resizeWidgetIconForLocation:(PTResizeHandleLocation)location;

/** @name Resize Widget Visibility
 */

/**
 * When true, only displays corner resize handles. Default is `false`.
 */
@property (nonatomic, assign) BOOL displaysOnlyCornerResizeHandles;

/**
 * Hides all of the resize widgets.
 */
-(void)hideResizeWidgetViews;

/**
 * Shows all of the resize widgets.
 */
-(void)showResizeWidgetViews;

/**
 * Shows the width resize widget (for spacing texts).
 */
- (void)showWidthResizeWidgetView;

/**
 * Used to set the view's frame to match the selected annotation's frame.
 *
 * @param frame The view's new frame.
 */
-(void)setFrameFromAnnot:(CGRect)frame;

/**
 * Used to indicate to the selection rect container that the annotation is being resized.
 */
- (void)annotationDidBeginResizing;

/**
 * Used to indicate to the selection rect container that the annotation is no longer being resized.
 */
- (void)annotationDidEndResizing;

/** @name Stamp Rotation
 */
#pragma mark - Annotation rotation specific

/**
 The rotation handle used for annotation rotating.
 */
@property (nonatomic, strong, nullable) PTRotateWidgetView *rotationHandle;

/**
 * Used to set the location of the rotation handle.
 *
 * @param location The location of the rotation handle.
 */
-(void)setRotationHandleLocation:(PTRotateHandleLocation)location;

/** @name FreeText editing
 */
#pragma mark - FreeText annotation specific

/**
 The text view used for free text annotation editing.
 */
@property (nonatomic, strong, nullable) PTFreeTextView *textView;

/**
 The text view presented when a spacing text annotation is selected.
 */
@property (nonatomic, strong, nullable) PTFreeTextView *spacingTextView;

/**
 * Scales the text size of a free text annotation that's being edited for the current
 * zoom.
 */
-(void)setEditTextSizeForZoom:(double)zoom forFontSize:(int)size;

/**
 * Adds a UITextView to the selection rectangle for PTFreeText annotation editing.
 */
-(void)useTextViewWithText:(nullable NSString*)text withAlignment:(int)alignment atZoom:(double)zoom forFontSize:(int)size withFontName:(NSString*)fontName withFrame:(CGRect)frame withDelegate:(id<UITextViewDelegate>)delegateView;

/**
 * Adds a UITextView to the selection rectangle for PTFreeText annotation editing.
 */
-(void)useTextViewWithAttributedText:(nullable NSAttributedString*)attributedText withAlignment:(int)alignment atZoom:(double)zoom forFontSize:(int)size withFontName:(NSString*)fontName withFrame:(CGRect)frame withDelegate:(id<UITextViewDelegate>)delegateView;

- (void)useTextViewForSpacingText:(nullable NSString *)text withAlignment:(int)alignment atZoom:(double)zoom forFontSize:(int)size withFontName:(NSString*)fontName withFrame:(CGRect)frame;

- (void)useTextViewForSpacingAttributedText:(nullable NSAttributedString *)attributedText withAlignment:(int)alignment atZoom:(double)zoom forFontSize:(int)size withFontName:(NSString*)fontName withFrame:(CGRect)frame;

/**
 * Saves any changes made to a PTFreeText back to the PTPDFDoc.
 *
 * @param annot The annotation that is selected.
 */
-(void)setAnnotationContents:(PTAnnot*)annot;


/** @name Line/Arrow editing specific
 */
#pragma mark - Line/Arrow editing specific

/**
 * Shows the selection rect. For use when editing line and arrow annotations, where the selection
 * rectangle is not shown when the annotation is not being moved, and has a different appearance than
 * other annotation types.
 */
-(void)showSelectionRect;

/**
 * Hides the selection rect. For use when editing line and arrow annotations, where the selection
 * rectangle is not shown when the annotation is not being moved, and has a different appearance than
 * other annotation types.
 */
-(void)hideSelectionRect;

/**
 * Sets the annot type that is selected. Used to determine the appearance of the child `PTSelectionRectView`.
 *
 * @param annot The annotation that is selected.
 *
 * @param pageNumber The PDF page number of the annotation.
 */
-(void)setAnnot:(nullable PTAnnot *)annot pageNumber:(int)pageNumber;

/**
 * Refreshes the live representation of the annotation's appearance.
 */
-(void)refreshLiveAppearance;

/**
 * Removes the live representation of the annotation's appearance.
*/
-(void)removeLiveAppearance;


-(instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
