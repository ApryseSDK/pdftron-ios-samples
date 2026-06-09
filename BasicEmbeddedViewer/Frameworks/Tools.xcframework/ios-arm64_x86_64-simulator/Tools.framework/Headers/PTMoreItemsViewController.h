//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTMoreItemsViewController` displays a selection of buttons and controls used to interact with
 * a `PTToolManager` and `PTPDFViewCtrl` beyond what can be shown in a `UINavigationBar`.
 */
PT_OBJC_RUNTIME_NAME(MoreItemsViewController)
@interface PTMoreItemsViewController : UITableViewController <PTOverridable>


/**
 *
 * The list of items displayed. The `title`, `image`, `target` and `action` properties are all used.
 *
 */
@property(nullable,nonatomic,copy) NSArray<UIBarButtonItem *> *items;

/**
 * Returns an initialized `PTMoreItemsViewController`
 *
 * @param toolManager the tool manager used.
 *
 * @return an initialized `PTMoreItemsViewController`.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;



- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
