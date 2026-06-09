//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFindTextToolbar;

/**
 * The methods declared by the PTFindTextToolbarDelegate protocol allow the adopting delegate
 * to respond to messages from the `PTFindTextToolbar` class.
 */
PT_OBJC_RUNTIME_NAME(FindTextToolbarDelegate)
@protocol PTFindTextToolbarDelegate <UIToolbarDelegate>

/**
 * Informs the delegate that the user wishes to close the find text toolbar.
 */
- (void)findTextToolbarDidCancel:(PTFindTextToolbar *)findTextToolbar;

@end

/**
 * The PTFindTextToolbar class displays a `UISearchBar` that allows the user to enter
 * and search text within a document.
 *
 * Floating buttons that allow navigating to the next or previous search result
 * are positioned over the `pdfViewCtrl` while the user is searching.
 */
PT_OBJC_RUNTIME_NAME(FindTextToolbar)
@interface PTFindTextToolbar : UIToolbar<UISearchBarDelegate>

/**
 * Returns a new instance of a PTFindTextToolbar.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * The `PTPDFViewCtrl` used for finding text.
 */
@property (nonatomic, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * An object conforming to the PTFindTextToolbarDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTFindTextToolbarDelegate> delegate;

/**
 * Remove the floating next and previous buttons shown while searching.
 *
 * @param animated whether to animate the removal
 */
- (void)removeButtons:(BOOL)animated;

/**
 * Requests that the internal `UISearchBar` become the first responder.
 */
- (void)searchBarBecomeFirstResponder;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
