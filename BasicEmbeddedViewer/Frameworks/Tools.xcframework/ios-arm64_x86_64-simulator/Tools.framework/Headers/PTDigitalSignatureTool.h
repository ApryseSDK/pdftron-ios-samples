//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTool.h>
#import <Tools/PTDigSigViewController.h>
#import <Tools/PTFloatingSigViewController.h>
#import <Tools/PTSignaturesManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#define PT_SIGNATURE_FIELD_ID @"PT_SIGNATURE_FIELD_ID"

NS_ASSUME_NONNULL_BEGIN

@class PTDigitalSignatureTool;

/**
 * A delegate used to respond to events from a `PTDigitalSignatureTool` instance.
 */
PT_OBJC_RUNTIME_NAME(DigitalSignatureToolDelegate)

@protocol PTDigitalSignatureToolDelegate <NSObject>

@optional

/**
 * Notifies the delegate to show the signature list on iPad.
 *
 */
-(void)digitalSignatureToolShowSignatureListOnPad:(PTDigitalSignatureTool*)signatureTool;

/**
 * Notifies the delegate when the user selects a signature.
 *
 */
-(void)digitalSignatureToolDidSelectSignature:(PTDigitalSignatureTool*)signatureTool image:(UIImage *)image;

/**
 * Notifies the delegate when the user adds or deletes a signature.
 *
 */
-(void)digitalSignatureToolNumberOfSignaturesDidChange:(PTDigitalSignatureTool*)signatureTool numberOfSignatures:(int)numberOfSignatures;

@end

/**
 * Handles creation of signatures and digitally signing documents.
 */
PT_OBJC_RUNTIME_NAME(DigitalSignatureTool)
@interface PTDigitalSignatureTool : PTTool <PTDigSigViewControllerDelegate, PTFloatingSigViewControllerDelegate, PTSignaturesManagerDelegate, UIAdaptivePresentationControllerDelegate>

/**
 * The file name of the selected signature.
*/
@property (nonatomic, copy, nullable) NSString* selectedSignature;

/**
 * Whether the controller should create a new signature.
 * `YES` if there is no saved signature.
 * `No` if there is saved signature.
 * The default value of this property is `YES`.
 */
@property (nonatomic) BOOL shouldCreateNewSignature;

/**
 * The image of the selected signature of the controller.
 */
@property (nonatomic, strong, nullable) UIImage *pickedSignatureImage;

/**
 * An object that conforms to the `PTDigitalSignatureToolDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id delegate;

/**
 * Show saved signatures.
 *
 */
-(void)showSignatureList;

/**
 * Show saved signatures as a popover.
 *
 * @param view The view in which to anchor the popover.
 *
 * @param sourceView The sourceView of the UIPopoverPresentationController.
 */
-(void)showSignatureList:(UIView *)view onSourceView:(UIView *)sourceView;

/**
 * Show saved signatures as a popover.
 *
 * @param sourceRect The frame of the view in which to anchor the popover.
 *
 * @param sourceView The sourceView of the UIPopoverPresentationController.
 */
- (void)showSignatureListForRect:(CGRect)sourceRect onSourceView:(UIView *)sourceView;

/**
 * Add signature to the selected widget.
 *
 * @param doc The `PTPDFDoc` object used to sign the widget.
 */
-(void)addSignatureToWidget:(PTPDFDoc*)doc;

/**
 * Stamp the signature.
 *
 * @param signatureDoc The `PTPDFDoc` object used to sign.
 */
-(void)addStamp:(PTPDFDoc*)signatureDoc;

@end

NS_ASSUME_NONNULL_END
