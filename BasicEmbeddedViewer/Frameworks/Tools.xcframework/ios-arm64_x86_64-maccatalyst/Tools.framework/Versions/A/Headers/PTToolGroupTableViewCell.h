//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A table view cell used to display a `PTToolGroup` in a table view.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(ToolGroupTableViewCell)
@interface PTToolGroupTableViewCell : UITableViewCell

/**
 * Initializes a `PTToolGroupTableViewCell` instance.
 *
 * @param style This parameter is unused.
 * @param reuseIdentifier The reuse identifier for the cell.
 *
 * @return An initialized `PTToolGroupTableViewCell` instance.
 */
- (instancetype)initWithStyle:(UITableViewCellStyle)style
              reuseIdentifier:(nullable NSString *)reuseIdentifier NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

#pragma mark Views

/**
 * The image view that displays the tool group's icon.
 */
@property (nonatomic, readonly, strong) UIImageView *iconImageView;

/**
 * The label that displays the title of the tool group.
 */
@property (nonatomic, readonly, strong) UILabel *titleLabel;

/**
 * A view positioned after the image view and label, which can be used to display other custom views.
 *
 * The subviews of this view are cleared when the cell is reused by the table view (in `-prepareForReuse`).
 */
@property (nonatomic, readonly, strong) UIView *trailingContentView;

@property (nonatomic, readonly, strong, nullable) UIImageView *imageView NS_UNAVAILABLE;
@property (nonatomic, readonly, strong, nullable) UILabel *textLabel NS_UNAVAILABLE;
@property (nonatomic, readonly, strong, nullable) UILabel *detailTextLabel NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
