//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolGroupManager.h>
#import <Tools/PTToolGroupTableViewCell.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTToolGroupViewController` class displays the available list of annotation
 * modes from a `PTToolGroupManager` instance.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(ToolGroupViewController)
@interface PTToolGroupViewController : UITableViewController <PTOverridable>

/**
 * The tool group manager associated with this view.
 */
@property (nonatomic, strong, nullable) PTToolGroupManager *toolGroupManager;

#pragma mark - Cell configuration

- (void)configureCell:(PTToolGroupTableViewCell *)cell
         forIndexPath:(NSIndexPath *)indexPath
            withGroup:(PTToolGroup *)group;

@end

NS_ASSUME_NONNULL_END
