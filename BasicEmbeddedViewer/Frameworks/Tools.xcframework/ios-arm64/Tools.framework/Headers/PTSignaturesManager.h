//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSignaturesManager;
@protocol PTSignaturesManagerDelegate;

/**
 * A delegate used to respond to events from a `PTSignaturesManager` instance.
 */
PT_OBJC_RUNTIME_NAME(SignaturesManagerDelegate)
@protocol PTSignaturesManagerDelegate <NSObject>
@required

/**
 * Notifies the delegate when the user adds or deletes a signature.
 *
 */
-(void)signaturesManagerNumberOfSignaturesDidChange:(PTSignaturesManager*)signaturesManager numberOfSignatures:(int)numberOfSignatures;

@end
/**
 * Creates signatures and manages saved ones.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(SignaturesManager)
@interface PTSignaturesManager : NSObject <PTOverridable>

extern NSString * const PTLastSelectedSignatureKey;

/**
 * The PTSignaturesManager object's delegate.
 */
@property (nonatomic, weak, nullable) id <PTSignaturesManagerDelegate> delegate;

/**
 * When true, the digital signature tool allows the user to save signatures and apply previously
 * saved signatures.
 */
@property (nonatomic, assign) BOOL showDefaultSignature;

/**
 * Used to determine the number of saved signatures.
 *
 * @return the number of saved signatures.
 */
-(NSUInteger)numberOfSavedSignatures;

/**
 * The index of the last selected signature.
 */
- (NSInteger)lastSelectedSignatureIndex;

/**
 * Gets a saved signature.
 *
 * @param index the index number of the saved signature
 *
 * @return the saved signature.
 */
-(nullable PTPDFDoc*)savedSignatureAtIndex:(NSInteger)index;

/**
 * Returns the file name of the signature at the given index of the given hight.
 *
 * @param index the index number of the saved signature
 *
 * @return the file name of the signature.
 */
-(nullable NSString *)fileNameOfSavedSignatureAtIndex:(NSInteger)index;

/**
 *
 * Returns an image of the signature at the given index of the given hight.
 *
 * @param index The index of the signature.
 *
 * @param dpi The DPI to render the image at. (If unsure, start with 72.)
 *
 *
 * @return A rasterized copy of the signature.
 *
 */
-(nullable UIImage*)imageOfSavedSignatureAtIndex:(NSInteger)index dpi:(NSUInteger)dpi;

/**
 *
 * Returns an image of the signature at the given index of the given hight.
 *
 * @param index The index of the signature.
 *
 * @param dpi The DPI to render the image at. (If unsure, start with 72.)
 *
 * @param thickness Renders the signature with a different stroke thickness than that which it has been saved with.
 *
 * @return A rasterized copy of the signature.
 *
 */
-(nullable UIImage*)imageOfSavedSignatureAtIndex:(NSInteger)index dpi:(NSUInteger)dpi thickness:(CGFloat)thickness;

/**
 *
 * Returns an image of the signature at the given index of the given hight.
 *
 * @param doc The PTPDFDoc object of the signature.
 *
 * @param dpi The DPI to render the image at. (If unsure, start with 72.)
 *
 *
 * @return A rasterized copy of the signature.
 *
 */
-(nullable UIImage*)imageOfDoc:(nullable PTPDFDoc *)doc dpi:(NSUInteger)dpi;

/**
 *
 * Returns an image of the signature at the given index of the given hight.
 *
 * @param doc The PTPDFDoc object of the signature.
 *
 * @param dpi The DPI to render the image at. (If unsure, start with 72.)
 *
 * @param thickness Renders the signature with a different stroke thickness than that which it has been saved with.
 *
 * @return A rasterized copy of the signature.
 *
 */
-(nullable UIImage*)imageOfDoc:(nullable PTPDFDoc *)doc dpi:(NSUInteger)dpi thickness:(CGFloat)thickness;

/**
 * Deletes the saved signature
 *
 * @param index the index of the signature to delete
 *
 * @return `YES` if the signature was successfully deleted; `NO` otherwise.
 */
-(BOOL)deleteSignatureAtIndex:(NSInteger)index;

/**
 *
 * Reorders the signatures
 *
 * @param fromIndex the originating index number of the signature
 *
 * @param toIndex the destination index number of the signature
 *
 * @return `YES` if the signature was successfully moved; `NO` otherwise.
 *
 */
-(BOOL)moveSignatureAtIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

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
 * @param saveSignature `YES` if the signature shold be saved as the
 * default signature.
 *
 * @return a PDFDoc where page 1 is the signature.
 *
 */
-(PTPDFDoc*)createSignature:(NSMutableArray*)points withStrokeColor:(UIColor*)strokeColor withStrokeThickness:(CGFloat)thickness withinRect:(CGRect)rect saveSignature:(BOOL)saveSignature;

/**
 * Creates a new saved signature.
 *
 * @param image The selected image.
 *
 * @param data The data of the selected image.
 *
 * @param saveSignature `YES` if the signature shold be saved as the
 * default signature.
 *
 * @return a PDFDoc where page 1 is the signature.
 *
 */
-(PTPDFDoc*)createSignatureWithImage:(UIImage *)image data:(NSData *)data saveSignature:(BOOL)saveSignature;

/**
 * Creates a new saved signature.
 *
 * @param text The input text.
 *
 * @param font The font of the text.
 *
 * @param strokeColor The color of the text.
 *
 * @param saveSignature `YES` if the signature shold be saved as the
 * default signature.
 *
 * @return a PDFDoc where page 1 is the signature.
 *
 */
- (PTPDFDoc *)createSignatureWithText:(NSString *)text withFont:(UIFont *)font withStrokeColor:(UIColor *)strokeColor saveSignature:(BOOL)saveSignature;

@end

NS_ASSUME_NONNULL_END
