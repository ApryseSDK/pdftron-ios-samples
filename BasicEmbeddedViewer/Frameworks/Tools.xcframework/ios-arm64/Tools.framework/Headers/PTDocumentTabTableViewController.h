//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentTabManager.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentTabTableViewController;
@protocol PTDocumentTabTableViewControllerDelegate;

PT_OBJC_RUNTIME_NAME(DocumentTabTableViewControllerDelegate)
@protocol PTDocumentTabTableViewControllerDelegate <NSObject>
@optional

- (void)documentTabViewController:(PTDocumentTabTableViewController *)documentTabViewController didSelectTabAtIndex:(NSInteger)tabIndex;

- (void)documentTabViewController:(PTDocumentTabTableViewController *)documentTabViewController
              didRemoveTabAtIndex:(NSInteger)tabIndex;

@end

PT_OBJC_RUNTIME_NAME(DocumentTabTableViewController)
@interface PTDocumentTabTableViewController : UITableViewController <PTOverridable>

@property (nonatomic, strong, nullable) PTDocumentTabManager *tabManager;

@property (nonatomic, weak, nullable) id<PTDocumentTabTableViewControllerDelegate> delegate;

@property (nonatomic, strong) UIBarButtonItem *doneButtonItem;

@property (nonatomic, strong) UIBarButtonItem *closeAllTabsButtonItem;

- (void)closeAllTabs:(id)sender;

@end

NS_ASSUME_NONNULL_END
