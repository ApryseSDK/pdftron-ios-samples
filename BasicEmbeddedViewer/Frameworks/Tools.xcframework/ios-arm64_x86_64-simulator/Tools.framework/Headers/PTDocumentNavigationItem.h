//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A `UINavigationItem` subclass that allows setting different sets of bar button items
 * for different user interface size classes.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentNavigationItem)
@interface PTDocumentNavigationItem : UINavigationItem

/**
 * The current trait collection of the navigation item's owning view controller. The
 * value of this property should be updated in the `-traitCollectionDidChange:` method
 * of the owning view controller.
 */
@property (nonatomic, strong) UITraitCollection *traitCollection;

#pragma mark - Left bar button items

/**
 * An array of custom bar button items to display on the left (or leading) side of the
 * navigation bar when the receiver is the top navigation item.
 *
 * The getter for this property returns `-leftBarButtonItemsForSizeClass:` for the
 * current horizontal user inteface size class, and the setter uses
 * `-setLeftBarButtonItems:forSizeClass:animated:` to set the items for all user
 * interface size classes.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *leftBarButtonItems;

/**
 * Sets the left bar button items for all horizontal user interface size classes,
 * optionally animating the transition to the new items.
 *
 * @param items An array of custom bar button items to display on the left side of the
 * navigation bar.
 *
 * @param animated Specify `YES` to animate the transition to the custom bar items when
 * this item is the top item. Specify `NO` to set the items immediately without
 * animating the change.
 */
- (void)setLeftBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;

/**
 * Returns the `leftBarButtonItems` for the given horizontal user interface size class.
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @return the `leftBarButtonItems` for the given horizontal user interface size class,
 * or `nil` if there are no items set for the size class
 */
- (nullable NSArray<UIBarButtonItem *> *)leftBarButtonItemsForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

/**
 * Sets the `leftBarButtonItems` used for the given horizontal user interface size class.
 *
 * @param leftBarButtonItems the list of bar button items
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @param animated whether to animate change
 */
- (void)setLeftBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)leftBarButtonItems forSizeClass:(UIUserInterfaceSizeClass)sizeClass animated:(BOOL)animated;

#pragma mark - Left bar button item

/**
 * A custom bar button item displayed on the left (or leading) edge of the navigation
 * bar when the receiver is the top navigation item.
 *
 * The getter for this property returns `-leftBarButtonItemForSizeClass:` for the
 * current horizontal user inteface size class, and the setter uses
 * `-setLeftBarButtonItem:forSizeClass:animated:` to set the item for all user
 * interface size classes.
 */
@property (nonatomic, strong, nullable) UIBarButtonItem *leftBarButtonItem;

/**
 * Sets the custom bar button item for all horizontal user interface size classes,
 * optionally animating the transition to the new item.
 *
 * @param item A custom bar item to display on the left side of the navigation bar.
 *
 * @param animated Specify `YES` to animate the transition to the custom bar item when
 * this item is the top item. Specify `NO` to set the item immediately without
 * animating the change.
 */
- (void)setLeftBarButtonItem:(nullable UIBarButtonItem *)item animated:(BOOL)animated;

/**
 * Returns the `leftBarButtonItem` for the given horizontal user interface size class.
 * If the left bar button items have been set with the
 * `-setLeftBarButtonItems:forSizeClass:animated:` method, then the first item from the
 * list for the given size class will be returned.
 
 * @param sizeClass the horizontal user interface size class
 *
 * @return the `leftBarButtonItem` for the given horizontal user interface size class,
 * or `nil` if there is no item set for the size class
 */
- (nullable UIBarButtonItem *)leftBarButtonItemForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

/**
 * Sets the `leftBarButtonItem` used for the given horizontal user interface size class.
 * If the list of left bar button items has been set with the
 * `-setLeftBarButtonItems:forSizeClass:animated:` method, the list for the given size
 * class will be overridden with the `leftBarButtonItem` specified here.
 *
 * @param leftBarButtonItem the bar button item
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @param animated whether to animate change
 */
- (void)setLeftBarButtonItem:(nullable UIBarButtonItem *)leftBarButtonItem forSizeClass:(UIUserInterfaceSizeClass)sizeClass animated:(BOOL)animated;

#pragma mark - Right bar button items

/**
 * An array of custom bar button items to display on the right (or trailing) side of
 * the navigation bar when the receiver is the top navigation item.
 *
 * The getter for this property returns `-rightBarButtonItemsForSizeClass:` for the
 * current horizontal user inteface size class, and the setter uses
 * `-setRightBarButtonItems:forSizeClass:animated:` to set the items for all user
 * interface size classes.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *rightBarButtonItems;

/**
 * Sets the right bar button items for all horizontal user interface size classes,
 * optionally animating the transition to the new items.
 *
 * @param items An array of custom bar button items to display on the right side of the
 * navigation bar.
 *
 * @param animated Specify `YES` to animate the transition to the custom bar items when
 * this item is the top item. Specify `NO` to set the items immediately without
 * animating the change.
 */
- (void)setRightBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;

/**
 * Returns the `rightBarButtonItems` for the given horizontal user interface size class.
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @return the `rightBarButtonItems` for the given horizontal user interface size class,
 * or `nil` if there are no items set for the size class
 */
- (nullable NSArray<UIBarButtonItem *> *)rightBarButtonItemsForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

/**
 * Sets the `rightBarButtonItems` used for the given horizontal user interface size
 * class.
 *
 * @param rightBarButtonItems the list of bar button items
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @param animated whether to animate change
 */
- (void)setRightBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)rightBarButtonItems forSizeClass:(UIUserInterfaceSizeClass)sizeClass animated:(BOOL)animated;

#pragma mark - Right bar button item

/**
 * A custom bar button item displayed on the right (or trailing) edge of the navigation
 * bar when the receiver is the top navigation item.
 *
 * The getter for this property returns `-rightBarButtonItemForSizeClass:` for the
 * current horizontal user inteface size class, and the setter uses
 * `-setRightBarButtonItem:forSizeClass:animated:` to set the item for all user
 * interface size classes.
 */
@property (nonatomic, strong, nullable) UIBarButtonItem *rightBarButtonItem;

/**
 * Sets the custom bar button item for all horizontal user interface size classes,
 * optionally animating the transition to the view.
 *
 * @param item A custom bar item to display on the right of the navigation bar.
 *
 * @param animated Specify `YES` to animate the transition to the custom bar item when
 * this item is the top item. Specify `NO` to set the item immediately without
 * animating the change.
 */
- (void)setRightBarButtonItem:(nullable UIBarButtonItem *)item animated:(BOOL)animated;

/**
 * Returns the `rightBarButtonItem` for the given horizontal user interface size class.
 * If the right bar button items have been set with the
 * `-setRightBarButtonItems:forSizeClass:animated:` method, then the first item from the
 * list for the given size class will be returned.
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @return the `rightBarButtonItem` for the given horizontal user interface size class,
 * or `nil` if there is no item set for the size class
 */
- (nullable UIBarButtonItem *)rightBarButtonItemForSizeClass:(UIUserInterfaceSizeClass)sizeClass;

/**
 * Sets the `rightBarButtonItem` used for the given horizontal user interface size
 * class. If the list of right bar button items has been set with the
 * `-setRightBarButtonItems:forSizeClass:animated:` method, the list for the given size
 * class will be overridden with the `rightBarButtonItem` specified here.
 *
 * @param rightBarButtonItem the bar button item
 *
 * @param sizeClass the horizontal user interface size class
 *
 * @param animated whether to animate change
 */
- (void)setRightBarButtonItem:(nullable UIBarButtonItem *)rightBarButtonItem forSizeClass:(UIUserInterfaceSizeClass)sizeClass animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
