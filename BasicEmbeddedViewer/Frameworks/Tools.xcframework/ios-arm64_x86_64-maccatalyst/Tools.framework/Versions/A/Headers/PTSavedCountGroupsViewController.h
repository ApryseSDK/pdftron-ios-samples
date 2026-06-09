//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSavedCountGroupsViewController;

/**
 * A delegate used to respond to events from a `PTSavedCountGroupsViewController` instance.
 */
@protocol PTSavedCountGroupsViewControllerDelegate <NSObject>

@required

/**
 * Notifies the delegate when the user wishes to create a new group.
 */
- (void)savedCountGroupsViewControllerCreateNewGroup:(PTSavedCountGroupsViewController*)savedCountGroupsViewController withCompletionHandler:(void (^)(void))completionHandler;

/**
 * Notifies the delegate when the user wishes to edit an existing group.
 */
- (void)savedCountGroupsViewControllerEditGroup:(PTSavedCountGroupsViewController*)savedCountGroupsViewController AtIndex:(int)index withCompletionHandler:(void (^)(void))completionHandler;

/**
 * Notifies the delegate when the user wishes to delete an existing group.
 */
- (void)savedCountGroupsViewControllerDeleteGroup:(PTSavedCountGroupsViewController*)savedCountGroupsViewController AtIndex:(int)index withCompletionHandler:(void (^)(void))completionHandler;

/**
 * Notifies the delegate when a group is selected.
 */
- (void)savedCountGroupsViewControllerDidSelectStyleAtIndex:(int)index;

@end

/**
 * Presents a list of saved groups, and buttons to create new ones.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(SavedCountGroupsViewController)
@interface PTSavedCountGroupsViewController : UITableViewController <PTOverridable>

/**
 * The PTSavedCountGroupsViewController object's delegate.
 */
@property (nonatomic, weak, nullable) id<PTSavedCountGroupsViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
