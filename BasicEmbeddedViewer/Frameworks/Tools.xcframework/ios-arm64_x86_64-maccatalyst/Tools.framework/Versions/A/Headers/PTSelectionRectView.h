//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTool.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotEditTool;
@class PTSelectionRectView;
@protocol PTSelectionRectViewDelegate;

/**
 * The interface for the delegate of a `PTSelectionRectView`.
 */
PT_OBJC_RUNTIME_NAME(SelectionRectViewDelegate)
@protocol PTSelectionRectViewDelegate <NSObject>
@optional

/**
 * Asks the delegate whether the appearance of the specified annotation should be displayed.
 *
 * @param selectionRectView The sender of this message.
 *
 * @param annotation The annotation to be displayed.
 *
 * @param pageNumber The PDF page number of the annotation.
 *
 * @return `YES` if the annotation's appearance should be displayed, `NO` otherwise.
 *
 * @note The default behavior if this method is not implemented is to display all annotation appearances.
 */
- (BOOL)selectionRectView:(PTSelectionRectView *)selectionRectView shouldDisplayAppearanceForAnnotation:(PTAnnot *)annotation
             onPageNumber:(int)pageNumber;

/**
 * Tells the delegate that the specified appearance view will be displayed.
 *
 * @param selectionRectView The sender of this message.
 *
 * @param appearanceView The appearance view that will be displayed.
 */
- (void)selectionRectView:(PTSelectionRectView *)selectionRectView willDisplayAppearanceView:(UIView *)appearanceView;

/**
 * Tells the delegate that the specified appearance view will no longer be displayed.
 *
 * @param selectionRectView The sender of this message.
 *
 * @param appearanceView The appearance view that will no longer be displayed.
 */
- (void)selectionRectView:(PTSelectionRectView *)selectionRectView didEndDisplayingAppearanceView:(UIView *)appearanceView;

@end

/**
 * For use when editing line and arrow annotations, where the selection rectangle
 * is not shown when the annotation is not being moved, and has a different appearance than
 * other annotation types.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(SelectionRectView)
@interface PTSelectionRectView : UIView

/**
 * The delegate of the selection view.
 */
@property (nonatomic, weak, nullable) id<PTSelectionRectViewDelegate> delegate;

/**
 * The PTPDFViewCtrl that the annotation selection is on.
 */
@property (nonatomic, weak, nullable) PTPDFViewCtrl* pdfViewCtrl;

/**
 * The annotation that is selected.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnot *annot;

/**
 * The page number of the selected annotation.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * Sets the selected annotation and page number.
 *
 * @param annotation The selected annotation, or `nil` if there is no selection.
 *
 * @param pageNumber The PDF page number of the annotation, or `0` if there is no selection.
 */
- (void)setAnnotation:(nullable PTAnnot *)annotation
           pageNumber:(int)pageNumber;

/**
 * Whether the annotation is currently being resized.
 *
 * The live appearance of the annotation may need to be adjusted during the resize interaction.
 * The default value of this property is false.
 */
@property (nonatomic, assign, getter=isResizing) BOOL resizing;

/**
 * The adjustment to the view's frame when editing line and arrow annotations.
 */
@property (nonatomic, assign) CGFloat rectOffset;

/**
 * Refreshes the live representation of the annotation's appearance.
 */
-(void)refreshLiveAppearance;

/**
* Removes the live representation of the annotation's appearance.
*/
-(void)removeLiveAppearance;

/**
 * The scaling applies to the contents of the live appearance view.
 *
 * The default value of this property is `1.0`.
 */
@property (nonatomic, assign) CGFloat appearanceScale;

/**
 * The view currently displaying the annotation's live representation.
 */
@property (nonatomic, readonly, strong, nullable) UIView *liveAppearanceView;

/**
 * Returns a new instance of a PTSelectionRectView.
 */
- (instancetype)initWithFrame:(CGRect)frame forAnnot:(nullable PTAnnot*)annot withAnnotEditTool:(PTAnnotEditTool*)tool withPDFViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl NS_DESIGNATED_INITIALIZER;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
