//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentTabItem.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentTabItem;

/**
 * This class tracks a list of `PTDocumentTabItem` instances and allows manipulation of
 * the order and selection.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentTabManager)
@interface PTDocumentTabManager : NSObject

/**
 * A list of the `PTDocumentTabItem` instances managed by the receiver.
 */
@property (nonatomic, readonly, copy) NSArray<PTDocumentTabItem *> *items;

/**
 * The index of the currently selected item in the `items` list.
 *
 * The value of this property is `NSNotFound` when there are no items.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * The currently selected item in the `items` list.
 *
 * The value of this property is `nil` when there are no items.
 */
@property (nonatomic, weak, nullable) PTDocumentTabItem *selectedItem;

/**
 * Add a `PTDocumentTabItem` instance to the list of items. The item is added to the end of the
 * `items` list, if it is not already in the list.
 *
 * @param item The `PTDocumentTabItem` instance to add to the list of items.
 */
- (void)addItem:(PTDocumentTabItem *)item;

/**
 * Insert a `PTDocumentTabItem` instance into the list of items at the specified index.
 *
 * @param item The `PTDocumentTabItem` instance to insert into the list of items.
 *
 * @param index The index in the `items` list at which to insert the item.
 */
- (void)insertItem:(PTDocumentTabItem *)item atIndex:(NSUInteger)index;

/**
 * Remove the specified `PTDocumentTabItem` instance from the list of items.
 *
 * @param item The `PTDocumentTabItem` instance to remove from the list of items.
 */
- (void)removeItem:(PTDocumentTabItem *)item;

/**
 * Remove the `PTDocumentTabItem` instance from the `items` list at the specified index.
 *
 * @param index The index of the item in the `items` list to remove.
 */
- (void)removeItemAtIndex:(NSUInteger)index;

/**
 * Removes all the items from the `items` list.
 *
 * After removing all items, the selected item will be `nil`.
 */
- (void)removeAllItems;

/**
 * Move the item located at `index` in the `items` list to `newIndex`.
 *
 * @param index The index of the item in the `items` list to move.
 *
 * @param newIndex The new index of the item in the `items` list.
 */
- (void)moveItemAtIndex:(NSUInteger)index toIndex:(NSUInteger)newIndex;

/**
 * Whether an item is currently being moved from one index to another.
 *
 * The value is `YES` during a call to the `-moveItemAtIndex:toIndex:` method.
 */
@property (nonatomic, readonly, getter=isMoving) BOOL moving;

#pragma mark - Persistence

#pragma mark Saving

/**
 * The default location at which the list of items is saved.
 */
@property (nonatomic, class, readonly, strong) NSURL *savedItemsURL;

/**
 * Save the current list of items to disk at the location specified by
 * `PTDocumentTabManager.savedItemsURL`.
 */
- (void)saveItems;

/**
 * Save the current list of items to disk at the specified location.
 *
 * @param savedItemsURL The location at which to save the list of items.
 */
- (void)saveItemsToURL:(NSURL *)savedItemsURL;

/**
 * Save the current list of items to disk at the specified location, calling the optional completion
 * handler when finished.
 *
 * @param savedItemsURL The location at which to save the list of items.
 *
 * @param completion The completion handler to call when finished. If saving was successful, the
 * value of the `success` block parameter will be `YES`. Otherwise if an error occurred, the value
 * of the `success` block parameter will be `NO` and the `error` block parameter will contain
 * information on why the operation failed.
 */
- (void)saveItemsToURL:(NSURL *)savedItemsURL withCompletionHandler:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

#pragma mark Restoring

/**
 * Restore the list of items from disk at the location specified by
 * `PTDocumentTabManager.savedItemsURL`.
 */
- (void)restoreItems;

/**
 * Restore the list of items from disk at the specified location.
 *
 * @param savedItemsURL The location from which to restore the list of items.
 */
- (void)restoreItemsFromURL:(NSURL *)savedItemsURL;

@end

NS_ASSUME_NONNULL_END
