//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Creates signatures and manages saved ones.
 */
PT_DEPRECATED_MSG(7.1.0, "use PTSignatureManager")
PT_OBJC_RUNTIME_NAME(StampManager)
@interface PTStampManager : NSObject

/**
 * Used to determine if there is a saved signature.
 *
 * @return `YES` if there is a saved signature
 */
-(BOOL)HasDefaultSignature;

/**
 * Gets the saved signature.
 *
 * @return the saved signature.
 */
-(nullable PTPDFDoc*)GetDefaultSignature;

/**
 * Deletes the saved signature
 */
-(void)DeleteDefaultSignatureFile;

/**
 * Creates a new saved signature.
 *
 * @param points A set of FreeHand points.
 *
 * @param strokeColor The color of the freehand stroke.
 *
 * @param thickness The thickness of the freehand stroke.
 *
 * @param rect The bounding rect of the points.
 *
 * @return asDefault `YES` if the signature shold be saved as the
 * default signature.
 *
 */
-(PTPDFDoc*)CreateSignature:(NSMutableArray*)points withStrokeColor:(UIColor*)strokeColor withStrokeThickness:(CGFloat)thickness withinRect:(CGRect)rect makeDefault:(BOOL)asDefault;

@end

NS_ASSUME_NONNULL_END
