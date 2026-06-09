//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT NSString* const PTLinkToWebKey;

@class PTLinkPopupViewController;

/**
 * The method declared by the `PTLinkPopupViewControllerDelegate` protocol allows the adopting delegate to respond to messages from
 * the `PTLinkPopupViewController` class.
 *
 */
PT_OBJC_RUNTIME_NAME(LinkPopupViewControllerDelegate)
@protocol PTLinkPopupViewControllerDelegate <NSObject>

/**
 * Tells the delegate to check if the input text for page link is valid.
 *
 * @param linkPopupViewController The `PTLinkPopupViewController` object informing the delegate.
 */
- (BOOL)linkPopupViewControllerPageTextIsValid: (PTLinkPopupViewController *)linkPopupViewController;

@end

/**
 * The PTLinkPopupViewController displays the textfield for users to edit the link.
 *
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(LinkPopupViewController)
@interface PTLinkPopupViewController : UIViewController

/**
 * The block to execute after pressing done button.
 */
@property (nonatomic, copy, nullable) void (^addLinkAction)(void);

/**
 * The block to execute after pressing cancel button.
 */
@property (nonatomic, copy, nullable) void (^cancelAction)(void);

/**
 * Textfield to input link text.
 */
@property (nonatomic, strong) UITextField *textField;

/**
 * An object that conforms to the `PTLinkPopupViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak) id<PTLinkPopupViewControllerDelegate> delegate;

/**
 * The page number that the page link leads to.
 */
@property (nonatomic) int pageNumber;

/**
 * The count of pages of the document.
 */
@property (nonatomic) int totalPageNumber;

/**
 * Whether the created link annot links to a web page or a page inside the document.
 * The default value is `YES`, meaning it's linked to a web page.
 */
@property (nonatomic) BOOL isLinkToWeb;

/**
 * Set the `PTLinkPopupViewController` to link to a web page.
 */
- (void) linkToWeb;

/**
 * Set the `PTLinkPopupViewController` to link to a page inside the document.
 */
- (void) linkToPage;

@end

NS_ASSUME_NONNULL_END
