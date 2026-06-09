//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentTabManager.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentTabManager;

/**
 * The `PTDocumentTabBar` class displays the a set of tabs in a horizontally scrollable
 * layout.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentTabBar)
@interface PTDocumentTabBar : UIView <UICollectionViewDelegateFlowLayout, UICollectionViewDataSource>

/**
 * The tab manager used to track the list of tabs and the selected tab.
 */
@property (nonatomic, strong, nullable) PTDocumentTabManager *tabManager;

/**
 * The view to be displayed behind all other content.
 *
 * The default background view is an empty `UIToolbar`.
 */
@property (nonatomic, strong, nullable) UIView *backgroundView;

/**
 * The collection view that displays the tabs from the `tabManager` as selectable views.
 */
@property (nonatomic, strong) UICollectionView *collectionView;

/**
 * The view to be displayed at the leading end of the tab bar.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIView *leadingView;

/**
 * The view to be displayed at the trailing end of the tab bar.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIView *trailingView;

/**
 * Tabs will fill the available space in the tab bar and as more tabs are displayed, their widths
 * are compressed up to this minimum value. When the width of tabs reaches this value then the
 * `collectionView` will become (horizontally) scrollable.
 *
 * The default value of this property is 120pts.
 */
@property (nonatomic, assign) CGFloat minimumTabWith;

/**
 * Whether a tab is currently being interactively moved.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, getter=isInteractivelyMoving) BOOL interactivelyMoving;

/**
 * The index of the currently selected tab.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * Sets the index of the currently selected tab.
 */
- (void)setSelectedIndex:(NSUInteger)selectedIndex animated:(BOOL)animated;

/**
 * Removes the tab at the specified index.
 */
- (void)removeTabAtIndex:(NSUInteger)index animated:(BOOL)animated;

/**
 * Reloads the tabs displayed by this view.
 */
- (void)reloadItems;

@end

NS_ASSUME_NONNULL_END













