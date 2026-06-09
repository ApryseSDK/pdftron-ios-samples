//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTSignaturesManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSavedSignaturesViewController;

@protocol PTSavedSignaturesViewControllerDelegate;

/**
 * A delegate used to respond to events from a `PTSavedSignaturesViewController` instance.
 */
PT_OBJC_RUNTIME_NAME(SavedSignaturesViewControllerDelegate)
@protocol PTSavedSignaturesViewControllerDelegate <NSObject>

@required

/**
 * The selected the signature's file name.
 *
 */
@property (nonatomic, copy, nullable) NSString* selectedSignature;

/**
 * Notifies the delegate when the user wishes to create a new signature that will be saved for reuse.
 *
 */
-(void)savedSignaturesControllerNewSignature:(PTSavedSignaturesViewController*)savedSignaturesController;

/**
 * Notifies the delegate when the user wishes to save new to the document.
 *
 * @param signatureDoc A PDF that contains the signature.
 *
*/
-(void)savedSignaturesController:(PTSavedSignaturesViewController*)savedSignaturesController addSignature:(PTPDFDoc*)signatureDoc;

/**
 * Asks the delegate whether to show the `Create New Signature` button.
 *
*/
- (BOOL)savedSignaturesControllerShouldHideCreateNewSignatureButton:(PTSavedSignaturesViewController *)savedSignaturesController;

/**
 * Notifies the delegate when the user picks a signature.
 *
 * @param image The image of the signature.
 *
 */
-(void)savedSignaturesControllerChangeImage:(PTSavedSignaturesViewController*)savedSignaturesController image:(UIImage *)image;

/**
 * Notifies the delegate when the user deletes a signature.
 *
 */
-(void)savedSignaturesControllerDeleteSelectedSignature:(PTSavedSignaturesViewController*)savedSignaturesController;

/**
 * Informs the delegate that the signature view controller should be closed.
 */
- (void)savedSignaturesControllerCloseSignatureDialog:
(PTSavedSignaturesViewController*)savedSignaturesController;
@end

/**
 * Presents a list of saved signatures, and buttons to create new ones.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(SavedSignaturesViewController)
@interface PTSavedSignaturesViewController : UITableViewController <PTOverridable>

/**
 * The signature manager used by the `PTSavedSignaturesViewController`
 */
@property (nonatomic, readonly, strong) PTSignaturesManager* signaturesManager;

/**
 * The PTSavedSignaturesViewController object's delegate.
 */
@property (nonatomic, weak, nullable) id<PTSavedSignaturesViewControllerDelegate> delegate;

/**
 * A convenience initializer to initalize with a pre-existing signature manager.
*/
- (instancetype)initWithSignaturesManager:(PTSignaturesManager*)signaturesManager;

@end

NS_ASSUME_NONNULL_END
