//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import <Tools/PTFontPickerViewController.h>
#import <Tools/PTSignatureAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The PTDigSigView is used for creating signature path appearances. The view tracks
 * and saves user touches, drawing strokes with the specified color and thickness.
 */
PT_OBJC_RUNTIME_NAME(DigSigView)
@interface PTDigSigView : UIView <PTFontPickerViewControllerDelegate>

/**
 * The selected signature type.
 */
@property (nonatomic, assign) PTSignatureType selectedSignatureType;

/**
 * The bounding rectangle exactly containing every drawn point.
 */
@property (nonatomic, assign) CGRect boundingRect;

/**
 * The stroke points, with differnt strokes separated by `CGPointZero` values.
 */
@property (strong, nonatomic, nullable) NSMutableArray<NSValue*>* points;

/**
 * The stroke color.
 */
@property (strong, nonatomic) UIColor* strokeColor;

/**
 * The stroke thickness.
 */
@property (assign, nonatomic) CGFloat strokeThickness;

/**
 * The UIButton to choose the image.
 */
@property (nonatomic, strong) UIButton *imageButton;

/**
 * The UIButton to choose the font.
 */
@property (nonatomic, strong) UIButton *fontButton;

/**
 * The UITextField used when typing a signature.
 */
@property (nonatomic, strong) UITextField *textField;

/**
 * The UIButton to toggle if new signature will be saved for reuse.
 */
@property (nonatomic, strong) UIButton *storeSignatureButton;

/**
 * The UIButton to clear existing signature.
 */
@property (strong, nonatomic) UIButton* clearButton;

/**
 * The UISegmentedControl that is used to change between signature types.
 */
@property (strong, nonatomic) UISegmentedControl *segmentedControl;

/**
 * Returns a new instance of a PTDigSigView with specified signature types (`PTSignatureType`) and signature colours.
 */
- (instancetype)initWithFrame:(CGRect)frame withColours:(NSArray<UIColor *> *)signatureColors withStrokeThickness:(CGFloat)thickness withTypes:(NSArray<NSNumber *> *)signatureTypes NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of a PTDigSigView with specified signature types (`PTSignatureType`).
 */
- (instancetype)initWithFrame:(CGRect)frame withColour:(UIColor *)color withStrokeThickness:(CGFloat)thickness withTypes:(NSArray<NSNumber *> *)signatureTypes;

/**
 * Returns a new instance of a PTDigSigView.
 */
- (instancetype)initWithFrame:(CGRect)frame withColour:(UIColor *)color withStrokeThickness:(CGFloat)thickness;

/**
 * Set the image of the signature.
 */
-(void)setImage:(UIImage *)image;

/**
 * Clear signatures in all types of the PTDigSigView.
 */
-(void)clearSignature;

/**
 * Clear the signature in selected type of the PTDigSigView.
 */
- (void)clearSelectedSignature;

@end

NS_ASSUME_NONNULL_END
