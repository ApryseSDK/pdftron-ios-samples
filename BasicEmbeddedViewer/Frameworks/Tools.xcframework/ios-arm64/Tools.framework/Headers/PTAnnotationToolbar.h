//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDigitalSignatureTool.h>
#import <Tools/PTEditToolbar.h>
#import <Tools/PTFreeHandCreate.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTTool.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents available annotation toolbar items, to be used to set a custom `PTAnnotationToolbar.precedenceArray`.
 */
typedef NS_ENUM(NSInteger, PTAnnotBarButton) {
    /// The sticky note button.
    PTAnnotBarButtonStickynote,
    /// The text highlight button.
    PTAnnotBarButtonHighlight,
    /// The text strikeout button.
    PTAnnotBarButtonStrikeout,
    /// The text underline button.
    PTAnnotBarButtonUnderline,
    /// The squiggly text underline button.
    PTAnnotBarButtonSquiggly,
    /// The signature button.
    PTAnnotBarButtonSignature,
    /// The freehand (ink) button.
    PTAnnotBarButtonFreehand,
    /// The eraser button.
    PTAnnotBarButtonEraser,
    /// The freetext button.
    PTAnnotBarButtonFreetext,
    /// The arrow button.
    PTAnnotBarButtonArrow,
    /// The line button.
    PTAnnotBarButtonLine,
    /// The rectangle button.
    PTAnnotBarButtonRectangle,
    /// The ellipse button.
    PTAnnotBarButtonEllipse,
    /// The polygon button.
    PTAnnotBarButtonPolygon,
    /// The cloudy button.
    PTAnnotBarButtonCloud,
    /// The polyline button.
    PTAnnotBarButtonPolyline,
    /// The ruler button.
    PTAnnotBarButtonRuler,
    /// The perimeter button.
    PTAnnotBarButtonPerimeter,
    /// The area button.
    PTAnnotBarButtonArea,
    /// The freehand highlight button.
    PTAnnotBarButtonFreehandHighlight,
    /// The free text callout button.
    PTAnnotBarButtonCallout,
    /// The text field button
    PTAnnotBarButtonTextField,
    /// The pan button.
    PTAnnotBarButtonPan,    
    /// The close button.
    PTAnnotBarButtonClose,
};

@class PTAnnotationToolbar;

/**
 * The methods declared by the `PTAnnotationToolbarDelegate` protocol allow the adopting delegate
 * to respond to messages from the `PTAnnotationToolbar` class.
 */
PT_OBJC_RUNTIME_NAME(AnnotationToolbarDelegate)
@protocol PTAnnotationToolbarDelegate <UIToolbarDelegate>
@optional

/**
 * Informs the delegate that the  user wishes to close the annotationToolbar.
 *
 * @param annotationToolbar The annotationToolbar that wishes to be closed.
 */
- (void)annotationToolbarDidCancel:(PTAnnotationToolbar *)annotationToolbar;

/**
 * Asks the delegate if the tool should stay in creation mode after the user has created an annotation.
 *
 * @return if the tool should stay in creation mode.
 *
 */
- (BOOL)toolShouldGoBackToPan:(PTAnnotationToolbar *)annotationToolbar;

@end

/**
 * The `PTAnnotationToolbar` is a toolbar with buttons that allows the user to switch between tools. See the
 * Complete Reader sample project for example usage.
 */
PT_DEPRECATED_MSG(8.0.2, "Use the PTToolGroupToolbar class instead")
PT_OBJC_RUNTIME_NAME(AnnotationToolbar)
@interface PTAnnotationToolbar : UIToolbar <PTOverridable, PTFreeHandCreateDelegate, PTEditToolbarDelegate, PTDigitalSignatureToolDelegate>

/**
 * Returns a new instance of a `PTAnnotationToolbar`.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;

/**
 * A reference to the tool manager, so that that the toolbar can change tools.
 */
@property (nonatomic, strong) PTToolManager* toolManager;

/**
 * Whether the annotation toolbar should be hidden along with the edit toolbar.
 * The default is `NO`.
 */
@property (nonatomic, assign) BOOL hidesWithEditToolbar;

/**
 * An object that adopts the `PTAnnotationToolbarDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTAnnotationToolbarDelegate> delegate;

/**
 * An array of boxed `PTAnnotBarButton` items that controls the precedence of the toolbar items when
 * there is insufficient space to show them all.
 *
 * Example:
 * ```precedenceArray = @[@(PTAnnotBarButtonClose),
 * @(PTAnnotBarButtonPan),
 * @(PTAnnotBarButtonCloud),
 * @(PTAnnotBarButtonPolygon)
 * ];```
 *
 */
@property (nonatomic, copy) NSArray<NSNumber *> *precedenceArray;

/**
 * Sets the tool on the toolbar. If a tool is activated using another method (e.g. via a long press),
 * this method can be called to make sure the annotation toolbar reflects the active tool.
 */
-(void)setButtonForTool:(nullable PTTool *)tool;

/**
 * Prepare the toolbar for the given orientation. This will update the toolbar buttons
 * for the available space, showing or hiding buttons as necessary.
 */
-(void)rotateToOrientation:(UIDeviceOrientation)orientation;


- (instancetype)init NS_UNAVAILABLE;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
