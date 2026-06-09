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

/**
 * An abstract class that many of the annotation-creating tools derive from.
 */
PT_OBJC_RUNTIME_NAME(CreateToolBase)
@interface PTCreateToolBase : PTTool {

PT_IGNORE_WARNINGS_BEGIN("objc-interface-ivars")
    /// backing variables for readonly properties who's subclasses need write access
    @protected
    
    int _pageNumber;
    
    double _thickness;
PT_IGNORE_WARNINGS_END
}

extern NSString * const PTRadioButtonWidthKey;
extern NSString * const PTRadioButtonHeightKey;
extern NSString * const PTCheckBoxWidthKey;
extern NSString * const PTCheckBoxHeightKey;

/**
 * The thickness of the annotation's stroke.
 */
@property (nonatomic, readonly, assign) double thickness;

/**
 * The line ending style of the annotation's start point.
 */
@property (nonatomic, readonly, assign) PTEndingStyle startStyle;

/**
 * The line ending style of the annotation's end point.
 */
@property (nonatomic, readonly, assign) PTEndingStyle endStyle;

/**
 * The pageNumber that this annotation will be created on.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * The rectangle defined by the points when the user first touched and his/her finger has
 * moved to.
 */
@property (nonatomic, readonly, assign) CGRect drawArea;

/**
 * The point where the user's finger first made contact with the `PTPDFViewCtrl`.
 */
@property (nonatomic, assign) CGPoint startPoint;

/**
 * The point where the user's finger first made contact with the `PTPDFViewCtrl`.
 */
@property (nonatomic, assign) CGPoint endPoint;

/**
 * Whether this tool requires an editing interface (toolbar) to operate.
 */
@property (nonatomic, readonly, assign) BOOL requiresEditSupport;

/**
 * Creates an annotation of the correct type, with the specified rect.
 *
 * The current thread holds a document write-lock when this method is called.
 *
 * @param doc The PDFDoc in which to create the annotation.
 * @param myRect The PDF page rect defining the bounds of the annotation.
 *
 * @return A new PDF annotation object. The annotation class is determined by `-[PTTool annotClass]`.
 */
- (__kindof PTAnnot *)createAnnotationWithDoc:(PTPDFDoc *)doc myRect:(PTPDFRect *)myRect;

/**
 * Sets up the drawing context with correct properties such as stroke and fill thickness
 * and color, etc.
 *
 * @param currentContext The current context, typically that returned by
 * `UIGraphicsGetCurrentContext()`.
 */
-(double)setupContext:(CGContextRef)currentContext;

/**
 * Saves new annotation default properties via `ColorDefaults`.
 *
 * @param annotation The annotation with properties that will be used when the next
 * annotation of this type is created.
 */
-(void)setPropertiesFromAnnotation:(PTAnnot *)annotation;

#pragma mark Annotation counter-rotation

/**
 * Whether a rotation opposite to the page's should be applied to the annotation when it is created.
 *
 * This property is disabled by default. Subclasses can override the property getter to have counter-rotation
 * applied automatically.
 */
@property (nonatomic, readonly, assign) BOOL appliesCounterRotation;

/**
 * Applies a rotation to the specified annotation that is opposite to its containing page's rotation.
 *
 * The rotation of the page (`-[PTPage GetRotation]`) and the PDFViewCtrl (`-[PTPDFViewCtrl GetRotation]`)
 * are combined to get the "effective" page rotation, as it is presented visually to the user.
 *
 * @param annotation The annotation.
 * @param pageNumber The page number of the annotation.
 */
- (void)applyCounterRotationToAnnotation:(PTAnnot *)annotation
                            onPageNumber:(int)pageNumber;

#pragma mark - Bounding points to the page

/**
 * Restricts the input point to the PDFPage `pageNumber`.
 *
 * @param touchPoint An input point, in screen (PTPDFViewCtrl) coordinates.
 *
 * @param thickness A thickness value that imposes a margin around the edge of the page.
 */
-(CGPoint)boundToPageScreenPoint:(CGPoint)touchPoint withThicknessCorrection:(CGFloat)thickness;


/**
 * Restricts the input point to the PDFPage `pageNumber`.
 *
 * @param touchPoint An input point, in screen (PTPDFViewCtrl) coordinates.
 *
 * @param left A thickness value that imposes a margin at the left edge of the page.
 *
 * @param right A thickness value that imposes a margin at the right edge of the page.
 *
 * @param bottom A thickness value that imposes a margin at the bottom edge of the page.
 *
 * @param top A thickness value that imposes a margin at the left top of the page.
 */
-(CGPoint)boundToPageScreenPoint:(CGPoint)touchPoint
                         withPaddingLeft:(CGFloat)left
                                   right:(CGFloat)right
                                  bottom:(CGFloat)bottom
                                     top:(CGFloat)top;
@end

NS_ASSUME_NONNULL_END
