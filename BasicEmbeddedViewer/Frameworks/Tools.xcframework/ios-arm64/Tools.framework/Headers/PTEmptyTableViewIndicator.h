//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------


#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTEmptyTableViewIndicator;

/**
 * A view used to indicate that the contents of a table or collection view are empty. Assigning an
 * instance of this class to the `backgroundView` property of a `UITableView` or `UICollectionView`
 * will display the indicator as a non-scrolling subview. Adding an instance of this class as a
 * subview to a table or collection view will make it scroll with the scroll view.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(EmptyTableViewIndicator)
@interface PTEmptyTableViewIndicator : UIView

/**
 * The content view of the empty indicator.
 */
@property (nonatomic, readonly, strong) UIView *contentView;

/**
 * The image view displayed by the indicator.
 */
@property (nonatomic, readonly, strong) UIImageView *imageView;

/**
 * The label displayed by the indicator.
 */
@property (nonatomic, readonly, strong) UILabel *label;

@end

NS_ASSUME_NONNULL_END
