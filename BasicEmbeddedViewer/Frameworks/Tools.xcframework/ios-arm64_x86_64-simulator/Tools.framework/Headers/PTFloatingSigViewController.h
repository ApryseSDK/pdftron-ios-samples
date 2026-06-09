//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTDigSigView.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFloatingSigViewController;
@protocol PTFloatingSigViewControllerDelegate;

/**
 * The methods declared by the PTFloatingSigViewControllerDelegate protocol allow the adopting delegate
 * to respond to message from the `PTFloatingSigViewController` class.
 */
PT_OBJC_RUNTIME_NAME(FloatingSigViewControllerDelegate)
@protocol PTFloatingSigViewControllerDelegate <NSObject>
@required

/**
 * Informs the delegate to save the text signature for the signature form field.
 */
- (void)floatingSigViewController:(PTFloatingSigViewController*)floatingSigViewController saveAppearanceWithText:(NSString *)text withFont:(UIFont *)font asDefault:(BOOL)asDefault;

/**
 * Informs the delegate to save the selected image for the signature form field.
 */
-(void)floatingSigViewController:(PTFloatingSigViewController*)floatingSigViewController saveAppearanceWithUIImage:(UIImage*)uiImage asDefault:(BOOL)asDefault;

/**
 * Informs the delegate to save the specified path appearance for the signature form field.
 */
- (void)floatingSigViewController:(PTFloatingSigViewController *)floatingSigViewController saveAppearanceWithPath:(nullable NSMutableArray *)points withBoundingRect:(CGRect)boundingRect asDefault:(BOOL)asDefault;

/**
 * Informs the delegate that the signature view controller should be closed.
 */
- (void)floatingSigViewControllerCloseSignatureDialog:(PTFloatingSigViewController *)floatingSigViewController;

@end

/**
 * The PTFloatingSigViewController allows the user to add signatures anywhere on a document.
 * A default signature can be saved for subsequent use.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(FloatingSigViewController)
@interface PTFloatingSigViewController : UIViewController <PTOverridable, UIImagePickerControllerDelegate, UINavigationControllerDelegate>

/**
 * The thickness of the drawn lines.
 */
@property (nonatomic, assign) CGFloat strokeThickness;

/**
 * The color to use for drawing.
 */
@property (nonatomic, strong) UIColor *strokeColor;

/**
 * The canvas view where path appearances are drawn.
 */
@property (nonatomic, strong) PTDigSigView *digSigView;

/**
 * Whether to save the signature for later reuse.
 */
@property (nonatomic, assign) BOOL saveSignatureForReuse;

/**
 * An array of signature types a user can select when creating a signature.
 *
 * The default options are `PTDrawnSignature`, `PTTypedSignature`, and `PTImageSignature`.
 */
@property (nonatomic, copy) NSArray<NSNumber *> *signatureTypes;

/**
 * An array of signature colors a user can select when creating a signature.
 *
 * The default options are `UIColor.blackColor`, `UIColor.blueColor`, and `UIColor.redColor`.
 */
@property (nonatomic, copy) NSArray<UIColor *> *signatureColors;

/**
 * An object that conforms to the `PTFloatingSigViewControllerDelegate` protocol.
 */
@property (nonatomic, weak) id<PTFloatingSigViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
