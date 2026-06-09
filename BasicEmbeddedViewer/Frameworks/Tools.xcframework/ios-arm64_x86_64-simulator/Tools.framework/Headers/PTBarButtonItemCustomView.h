//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTBadgeIndicatorView.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(BarButtonItemCustomView)
@interface PTBarButtonItemCustomView : UIView

@property (nonatomic, strong, nullable) UIView *contentView;

@property (nonatomic, strong) PTBadgeIndicatorView *badgeIndicatorView;

- (instancetype)initWithContentView:(UIView *)contentView NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * Whether this view's left and/or right layout margins are removed when the left and/or right edge
 * of the view is aligned to its superview's edge(s).
 *
 * This is needed when used inside a `UIToolbar` or `UINavigationBar` because for custom views of a
 * `UIBarButtonItem` at the leading or trailing end of the bar, the bar's layout margin for that end
 * is not adjusted. For a `UIBarButtonItem` at the end of a bar without a custom view, the bar's
 * layout margin will be adjusted to align the button's image or title (*not* the button's layout margin)
 * with the bar's layout margin.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL adjustsLayoutMarginsForSuperview;

@end

NS_ASSUME_NONNULL_END
