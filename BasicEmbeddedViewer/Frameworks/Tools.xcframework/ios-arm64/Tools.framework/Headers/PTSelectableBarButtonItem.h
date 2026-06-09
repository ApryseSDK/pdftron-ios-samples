//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTSelectableBarButtonItem` class allows selection of a bar button item and
 * can display a red badge indicator.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(SelectableBarButtonItem)
@interface PTSelectableBarButtonItem : UIBarButtonItem

/**
 * Whether the item is selected. When the item is selected, its view will be shown with
 * a tinted background to indicate the selection.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isSelected) BOOL selected;

/**
 * Whether a red badge indicator is shown.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isBadgeHidden) BOOL badgeHidden;


- (instancetype)initWithImage:(nullable UIImage *)image landscapeImagePhone:(nullable UIImage *)landscapeImagePhone style:(UIBarButtonItemStyle)style target:(nullable id)target action:(nullable SEL)action NS_UNAVAILABLE;

- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(nullable id)target action:(nullable SEL)action NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
