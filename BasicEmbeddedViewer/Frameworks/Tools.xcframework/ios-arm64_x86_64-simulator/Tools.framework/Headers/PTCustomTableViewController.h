//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTCustomTableViewController;

/**
 * The PTCustomTableViewControllerDelegate protocol allows the adopting class to respond to events from the `PTCustomTableViewController`.
 */
PT_OBJC_RUNTIME_NAME(CustomTableViewControllerDelegate)
@protocol PTCustomTableViewControllerDelegate <NSObject>

-(void)customTableViewController:(PTCustomTableViewController *)customTableViewController didSelectItemAtIndexPath:(NSIndexPath*)indexPath;

@end

/**
 * The `PTCustomTableViewController` displays a selection of buttons and controls from an array of `UIBarButtonItems`.
 */
PT_OBJC_RUNTIME_NAME(CustomTableViewController)
@interface PTCustomTableViewController : UITableViewController <PTOverridable>

/**
 *
 * The list of items displayed. The `title`, `image`, `target` and `action` properties are all used.
 *
 */
@property(nullable,nonatomic,copy) NSArray<UIBarButtonItem *> *items;

/**
 * Returns an initialized `PTCustomTableViewController`
 *
 * @param items the array of `UIBarButtonItems` with which to populate the table view.
 *
 * @return an initialized `PTCustomTableViewController`.
 */
- (instancetype)initWithItems:(NSArray<UIBarButtonItem*> *)items;

/**
 * Returns an initialized `PTCustomTableViewController`
 *
 * @param items the array of `UIBarButtonItems` with which to populate the table view.
 *
 * @param title the title of the table view.
 *
 * @return an initialized `PTCustomTableViewController`.
 */
- (instancetype)initWithItems:(NSArray<UIBarButtonItem*> *)items withTitle:(nullable NSString *)title NS_DESIGNATED_INITIALIZER;

/**
 The delegate of the custom table view controller object.
 */
@property (nonatomic, weak, nullable) id<PTCustomTableViewControllerDelegate> delegate;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
