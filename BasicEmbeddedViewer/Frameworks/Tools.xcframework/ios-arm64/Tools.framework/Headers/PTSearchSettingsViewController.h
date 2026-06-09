//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT NSString * const PTTextSearchMatchCaseKey;
PT_EXPORT NSString * const PTTextSearchMatchWholeWordKey;

@class PTSearchSettingsViewController;

/**
* The methods declared by the `PTSearchSettingsViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
* the `PTSearchSettingsViewController` class.
*/
PT_OBJC_RUNTIME_NAME(SearchSettingsViewControllerDelegate)
@protocol PTSearchSettingsViewControllerDelegate <NSObject>
- (void)searchSettingsViewControllerDidToggleSearchMode:(PTSearchSettingsViewController *)searchSettingsViewController;
@end

/**
* The `PTSearchSettingsViewController` displays a list of search settings used by `PTTextSearchViewController`
* by a PTPDFViewCtrl.
*/
PT_OBJC_RUNTIME_NAME(SearchSettingsViewController)
@interface PTSearchSettingsViewController : UITableViewController <PTOverridable>

/**
 * An object that conforms to the `PTSearchSettingsViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTSearchSettingsViewControllerDelegate> delegate;

@end


NS_ASSUME_NONNULL_END
