//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolManager.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDigitalSignaturesViewController;

/**
 * The methods declared by the `PTDigitalSignaturesViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
 * the `PTDigitalSignaturesViewController` class.
 *
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DigitalSignaturesViewControllerDelegate)
@protocol PTDigitalSignaturesViewControllerDelegate <NSObject>
@optional

/**
 * Tells the delegate that the digital signature control wants to be closed.
 *
 */
- (void)digitalSignaturesViewControllerDidCancel:(PTDigitalSignaturesViewController *)digitalSignaturesViewController;

@end

/**
 * The PTDigitalSignaturesViewController displays a list of digital signatures in a document being viewed
 * by a PTPDFViewCtrl.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DigitalSignaturesViewController)
@interface PTDigitalSignaturesViewController : UITableViewController <PTOverridable>

/**
 * Returns a new instance of a PTOutlineViewController.
 *
 * @param toolManager The `PTToolManager` object that provides the `PTPDFViewCtrl` and `PTPDFDoc` from
 * to create the outline, which will change pages when the user selects an annotation item.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;

/**
 * An object that conforms to the `PTDigitalSignaturesViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTDigitalSignaturesViewControllerDelegate> delegate;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
