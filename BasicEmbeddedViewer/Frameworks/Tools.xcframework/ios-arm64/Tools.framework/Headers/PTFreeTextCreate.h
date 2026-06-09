//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTool.h>
#import <Tools/PTFreeTextView.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT NSString * const PTTextAnnotationTypeKey;
PT_EXPORT NSString * const PTTextAnnotationTypeDate;
PT_EXPORT NSString * const PTTextAnnotationTypeSpacing;

PT_OBJC_RUNTIME_NAME(VectorLabel)
@interface PTVectorLabel: UILabel

@end

/**
 * Creates a free text annotation.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextCreate)
@interface PTFreeTextCreate: PTTool <UITextViewDelegate>

/**
 * The `PTFreeTextView` instance used for interactive text entry.
 */
@property (nonatomic, readonly, strong) PTFreeTextView *textView;

- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl textView:(UITextView *)textView;

/**
 * Commits the free text annotation to the document.
 */
- (void)commitAnnotation;

/**
 * Creates a free text annotation from the tool's current state.
 *
 * @return a new `PTFreeText` instance for the current document
 */
- (PTFreeText *)createFreeText;

/**
 * Sets the rect of the free text annotation.
 *
 * @param freeText the free text annotation
 */
- (void)setRectForFreeText:(PTFreeText *)freeText;

/**
 * Applies the text color, border appearance, and other properties to the free text
 * annotation before it is committed.
 *
 * @param freeText the free text annotation
 */
- (void)setPropertiesForFreeText:(PTFreeText *)freeText;

/**
 Sets the rect for a `PTFreeText` annotation.
 
 @param freeText The `PTFreeText` object.
 @param rect The `PTPDFRect` representation of the associated `UITextView`.
 @param pdfViewCtrl The `PTPDFViewCtrl` object.
 @param isRTL A `BOOL` indicating whether the text is in a right-to-left language.
 */
+(void)setRectForFreeText:(PTFreeText*)freeText withRect:(PTPDFRect*)rect pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl isRTL:(BOOL)isRTL;

/**
 * Sets the free text appearance as is rendered by the iOS UI.
 *
 * The annotation's rotation will be rendered in accordance with its rotation flag.
 *
 * @param freeText The `PTFreeText` annotation that needs its appearance refreshed.
 *
 * @param doc The `PTPDFDoc` that the annotation is part of.
 *
 */
+(void)refreshAppearanceForAnnot:(PTFreeText*)freeText onDoc:(PTPDFDoc*)doc;

/**
 *
 * Creates a new appearance for a `PTFreeText` annotation that ensures it is facing up at the time of
 * creation.
 *
 * @param freeText The `PTFreeText` annotation that needs a new appearance.
 *
 * @param doc The `PTPDFDoc` that the annotation is part of.
 *
 * @param viewerRotation The current rotation of the `PTPDFViewCtrl`.
 *
 */
+(void)createAppearanceForAnnot:(PTFreeText*)freeText onDoc:(PTPDFDoc*)doc withViewerRotation:(PTRotate)viewerRotation;

/**
 Creates a styled `UITextView` with properties from a `PTFreeText` annotation.

 @param freeText The `PTFreeText` object.
 @param pageNumber The page number on which the annotation exists.
 @param pdfViewCtrl The `PTPDFViewCtrl` object.
 */
+(UITextView*)textViewForAnnot:(PTFreeText*)freeText onPageNumber:(int)pageNumber withPDFViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 *
 * Gets the unrotated rect from a `PTFreeText` annotation.
 *
 * @param rect The rotated rect of a `PTFreeText` annotation.
 *
 * @param degree The rotated degree of a `PTFreeText` annotation.
 *
 * @return The unrotated rect of the `PTFreeText` annotation.
 *
 */
+ (PTPDFRect *)getUnrotatedRect:(PTPDFRect *)rect degree:(double)degree;

/**
 *
 * Gets the `PTRotate` value from a rotated degree value.
 *
 * @param degree The rotated degree of a `PTFreeText` annotation.
 *
 * @return The `PTRotate` value of the degree.
 *
 */
+ (PTRotate)getAnnotationRotation:(double)degree;

@end

NS_ASSUME_NONNULL_END
