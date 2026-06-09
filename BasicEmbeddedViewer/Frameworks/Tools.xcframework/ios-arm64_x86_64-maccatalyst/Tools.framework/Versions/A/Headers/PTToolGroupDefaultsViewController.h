//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolGroupManager.h>
#import <Tools/PTToolGroup.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTToolGroupDefaultsViewController` class allows the user to edit the items in a
 * tool group. If more than one tool group is specified in the `itemGroups` property, then items
 * can be added to the first tool group from the other groups.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(ToolGroupDefaultsViewController)
@interface PTToolGroupDefaultsViewController : UITableViewController

/**
 * The tool group manager associated with this view controller.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) PTToolGroupManager *toolGroupManager;

/**
 * The tool groups to be edited.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSArray<PTToolGroup *> *itemGroups;

/**
 * The tint color to be applied to the item icons. This property can be used to provide a different
 * tint color for the icons from the tint color applied to other interface elements.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIColor *iconTintColor;
 
@end

NS_ASSUME_NONNULL_END
