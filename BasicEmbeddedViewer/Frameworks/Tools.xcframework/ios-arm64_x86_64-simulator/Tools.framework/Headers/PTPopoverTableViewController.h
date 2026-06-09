//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A `UITableViewController` replacement designed to work well in a popover presentation.
 *
 * Functionality replicated from `UITableViewController` includes:
 *
 * - Creates a table view with the correct dimensions and autoresizing, setting the `dataSource` and `delegate` to self.
 * - In `-viewWillAppear:`, it reloads the table's data if it's empty. Otherwise, it deselects all rows (with or without animation) if clearsSelectionOnViewWillAppear is YES.
 * - In `-viewDidAppear:`, it flashes the table's scroll indicators.
 * - Implements `-setEditing:animated:` to toggle the editing state of the table view.
 * - Sets the `preferredContentSize` to reflect the `contentSize` and `contentInset` of the table view.
 *
 * Unlike the `UITableViewController` class, this view controller class does *NOT* adjust the `contentInset`
 * of the table view when the virtual keyboard is shown.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PopoverTableViewController)
@interface PTPopoverTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

/**
 * Initializes a `PTPopoverTableViewController` instance with the specified table view style.
 *
 * @param style The style to use for the table view
 *
 * @return an initialized `PTPopoverTableViewController` instance
 */
- (instancetype)initWithStyle:(UITableViewStyle)style NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a `PTPopoverTableViewController` instance with the specified coder.
 *
 * @param coder The coder for initialization
 *
 * @return an initialized `PTPopoverTableViewController` instance, or `nil` if decoding failed
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * The table view used by this view controller.
 */
@property (nonatomic, strong, null_resettable) UITableView *tableView;

/**
 * Whether the table view's selection should be cleared when `-viewWillAppear:` is called.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL clearsSelectionOnViewWillAppear;

- (instancetype)initWithNibName:(nullable NSString *)nibName
                         bundle:(nullable NSBundle *)nibBundle NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
