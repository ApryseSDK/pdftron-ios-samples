//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* _Nonnull const PTStoreNewSignatureKey;

/**
 * Signature types when create.
 */
typedef NS_ENUM(NSUInteger, PTSignatureType) {
    /// Hand-drawn signature
    PTDrawnSignature,
    /// Typed signature
    PTTypedSignature,
    /// Image signature
    PTImageSignature,
};

/**
 * An object that contains options for signature annotations.
 */
PT_OBJC_RUNTIME_NAME(SignatureAnnotationOptions)
@interface PTSignatureAnnotationOptions : PTAnnotationOptions

/**
 * Whether the annotation's appearance (strokes) can be edited. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL canEditAppearance;

/**
 * If true, signature fields will be signed by placing a stamp on top of them rather than
 * changing the field's appearance. Default is `NO`.
 */
@property (nonatomic, assign) BOOL signSignatureFieldsWithStamps;

/**
 * If true, signature fields will be considered signed if there is an ink
 * or stamp annotation overlapping it. Default is `YES`.
 */
@property (nonatomic, assign, getter=isWidgetSigningWithOverlappingAnnotationEnabled) BOOL widgetSigningWithOverlappingAnnotationEnabled;

/**
 * If true, newly created signature will be saved to the signature list.
 * Default is `YES`.
 */
@property (nonatomic, assign) BOOL storeNewSignature;

/**
 * An array of signature types a user can select when creating a signature. The default options are `PTDrawnSignature`, `PTTypedSignature`, and `PTImageSignature`.
 */
@property (nonatomic, copy) NSArray<NSNumber *> *signatureTypes;

/**
 * The maximum number of saved signatures. Default is `-1` and the number is not limited.
 */
@property (nonatomic, assign) int maxSignatureCount;

/**
 * An array of signature colors a user can select when creating a signature. The default options are `UIColor.blackColor`, `UIColor.blueColor`, and `UIColor.redColor`.
 */
@property (nonatomic, copy) NSArray<UIColor *> *signatureColors;

/**
 * If true, the signature list will be shown when the user taps the document (rather than applying the currently seleceted signature).
 * Default is `NO`.
 */
@property (nonatomic, assign) BOOL showSignatureListWhenTapped;

/**
 * If true, `storeNewSignature` will be read from NSUserDefaults.
 * Default is `YES`.
 */
@property (nonatomic, assign) BOOL persistStoreSignatureSetting;

@end

NS_ASSUME_NONNULL_END
