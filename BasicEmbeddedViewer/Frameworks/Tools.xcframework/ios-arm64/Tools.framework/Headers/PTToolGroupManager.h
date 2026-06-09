//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTToolGroup.h>
#import <Tools/PTAnnotationStylePresetsGroup.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTToolGroupManager;

/**
 * The `PTToolGroupManagerDelegate` protocol allows the adopting class to respond to messages
 * from the `PTToolGroupManager` class.
 */
PT_OBJC_RUNTIME_NAME(ToolGroupManagerDelegate)
@protocol PTToolGroupManagerDelegate <NSObject>
@optional

/**
 * This method is called when the items in the given group should be edited.
 *
 * @param toolGroupManager The tool group manager requesting the edit
 *
 * @param group The tool group to be edited
 */
- (void)toolGroupManager:(PTToolGroupManager *)toolGroupManager editItemsForGroup:(PTToolGroup *)group;

/**
 * This method is called when add pages tool is selected.
 *
 * @param toolGroupManager The tool group manager requesting the edit
 *
 * @param sender the selected bar button.
 */
- (void)toolGroupManager:(PTToolGroupManager *)toolGroupManager showAddPagesViewOn:(id)sender;

@end

/**
 * The `PTToolGroupManager` class maintains a list of tool groups, represented
 * by instances of the `PTToolGroup` class, each of which contain a set of available
 * tools for that mode.
 *
 * This class is designed to work in conjuction with the `PTToolGroupToolbar` class
 * to display the tool groups and provide interactive control over the current tool.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(ToolGroupManager)
@interface PTToolGroupManager : NSObject <NSCoding, PTOverridable>

/**
 * Initializes a newly created `PTToolGroupManager` instance.
 *
 * @return an initialized `PTToolGroupManager` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Returns an object initialized from data in a given unarchiver.
 *
 * @param coder An unarchiver object
 *
 * @return `self`, initialized using the data in decoder, or `nil` if the object could
 * not be initialized
 */
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTToolGroupManager` instance with the provided tool manager.
 *
 * @param toolManager The tool manager to be used by the receiver
 *
 * @return an initialized `PTToolGroupManager` instance
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The receiver uses this tool manager instance to manage the current tool and observes notifications
 * posted by the tool manager.
 */
@property (nonatomic, strong, nullable) PTToolManager *toolManager;

/**
 * The tool group manager's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTToolGroupManagerDelegate> delegate;

/**
 * Whether this tool group manager is currently enabled. The receiver will not observe
 * notifications posted by its `toolManager` when this property's value is `NO`.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

#pragma mark - Tool groups

/**
 * The list of tool groups managed by this tool group manager. Each tool group
 * represents an "tool group", each with their own set of available tools to be displayed.
 */
@property (nonatomic, copy) NSArray<PTToolGroup *> *groups;

/**
 * Adds the specified `PTToolGroup` instances to the end of the list of tool groups in `groups`.
 * If the tool group is already in `groups` then this method does nothing.
 *
 * @param toolGroup the tool group to add
 */
- (void)addToolGroup:(PTToolGroup *)toolGroup;

/**
 * Inserts the given `PTToolGroup` instance at the specified index in the list of tool groups in
 * `groups`. If the tool group is already in `groups` then this method does nothing.
 *
 * @param toolGroup the tool group to insert
 *
 * @param index the index at which to insert the tool group in `groups`
 */
- (void)insertToolGroup:(PTToolGroup *)toolGroup atIndex:(NSUInteger)index;

/**
 * Removes the specified `PTToolGroup` instances from the list of tool groups in `groups`. If the
 * tool group is not in `groups` then this method does nothing.
 *
 * @param toolGroup the tool group to remove
 */
- (void)removeToolGroup:(PTToolGroup *)toolGroup;

/**
 * Removes the tool group in `groups` at the specified index.
 *
 * @param index the index in `groups` of the tool group to remove
 */
- (void)removeToolGroupAtIndex:(NSUInteger)index;

/**
 * The currently selected tool group in `groups`.
 *
 * When the `groups` list is empty, the value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) PTToolGroup *selectedGroup;

/**
 * The index of the currently selected tool group in `groups`.
 *
 * When the `groups` list is empty, the value of this property is `NSNotFound`.
 */
@property (nonatomic, assign) NSUInteger selectedGroupIndex;

/**
 * The "View" tool group.
 *
 * This group does not contain any tools.
 */
@property (nonatomic, readonly, strong) PTToolGroup *viewItemGroup;

/**
 * The "Annotate" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *annotateItemGroup;

/**
 * The "Draw" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *drawItemGroup;

/**
 * The "Fill And Sign" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *fillAndSignItemGroup;

/**
 * The "Prepare Form" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *prepareFormItemGroup;

/**
 * The "Insert" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *insertItemGroup;

/**
 * The "Measure" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *measureItemGroup;

/**
 * The "Pens" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *pensItemGroup;

/**
 * The "Redact" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *redactItemGroup;

/**
 * The "Favorites" tool group.
 */
@property (nonatomic, readonly, strong) PTToolGroup *favoritesItemGroup;

#pragma mark - Tool items

/**
 * Creates a new item for the specified `PTTool` subclass. The item is not part of any group and
 * must be added to an existing or new group in order to be used.
 *
 * @param toolClass the `PTTool` subclass to be associated with the created item
 *
 * @return a new item for the specified `PTTool` subclass
 */
- (UIBarButtonItem *)createItemForToolClass:(Class)toolClass;

#pragma mark - Undo/redo

/**
 * The undo manager currently being tracked by the tool group manager.
 *
 * When the `toolManager`'s tool is a `PTCreateToolBase` subclass and returns `YES` from
 * `PTCreateToolBase.undoManagerEnabled` then this property will be equal to
 * `toolManager.tool.undoManager`. Otherwise, `toolManager.undoManager` will be returned.
 */
@property (nonatomic, readonly, weak, nullable) NSUndoManager *undoManager;

/**
 * The undo button item. When activated, this item calls `-undo:`.
 *
 * This bar button item's `UIBarButtonItem.enabled` property is automatically updated to reflect
 * the current value of `undoManager.canUndo`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *undoButtonItem;

/**
 * This method calls `[undoManager undo]` on the tool group manager's
 * `undoManager` property.
 */
- (void)undo:(nullable id)sender;

/**
 * The redo button item. When activated, this item calls `-redo:`.
 *
 * This bar button item's `UIBarButtonItem.enabled` property is automatically updated to reflect
 * the current value of `undoManager.canRedo`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *redoButtonItem;

/**
 * This method calls `[undoManager redo]` on the tool group manager's `undoManager`
 * property.
 */
- (void)redo:(nullable id)sender;

/**
 * Updates the state of the `undoButtonItem` and `redoButtonItem` bar button items.
 */
- (void)updateUndoRedoItems;

#pragma mark - Favorites

/**
 * The "Add Tool" button item. This item is to be shown when the `favoritesItemGroup`
 * is selected - it is not part of the tool group because it should always appear
 * at the end of the `favoritesItemGroup`'s list of items and is not reorderable.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *addFavoriteToolButtonItem;

/**
 * This method asks the tool group manager's `delegate` to edit the
 * `favoritesItemGroup` via the
 * `-[PTToolGroupManagerDelegate toolGroupManager:editItemsForGroup:]`
 * delegate method.
 */
- (void)addFavoriteTool:(id)sender;

#pragma mark - Editing tool groups

/**
 * Whether editing of groups from the user interface is enabled. When enabled, the
 * `editGroupButtonItem` item is displayed at the end of all tool groups, except
 * for the `favoritesItemGroup`, in the user interface.
 *
 * If this property is set to `NO` and editing is disabled, then the
 * `editGroupButtonItem` item will not be displayed in the user interface.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, getter=isEditingEnabled) BOOL editingEnabled;

/**
 * The "Edit Items" button item. This item is to be shown at the end of all tool item
 * groups, except for the `favoritesItemGroup`, when the `editingEnabled` property is
 * set to `YES`.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *editGroupButtonItem;

/**
 * This method asks the tool group manager's `delegate` to edit the currently
 * selected tool group in the `selectedGroup` property via the
 * `-[PTToolGroupManagerDelegate toolGroupManager:editItemsForGroup:]`
 * delegate method.
 *
 * If the `selectedGroup` property is `nil` then this method does nothing.
 */
- (void)editSelectedGroup:(id)sender;

#pragma mark - Apply redaction

/**
 * The "Apply redact" button item. This item is to be shown at the first of redact tool group.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *applyRedactButtonItem;

#pragma mark - Add pages

/**
 * The "Add pages" button item. This item is to be shown at the last of insert tool group.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *addPagesButtonItem;

#pragma mark - Annotation style presets

/**
 * The annotation style presets group for the `toolManager`'s current tool. This property
 * is updated when the tool manager's tool changes and depends on the
 * `PTTool.identifier` property of the tool. Tools that appear in more than one tool
 * group in `groups` will have different identifiers and different annotation style
 * presets groups.
 */
@property (nonatomic, readonly, strong, nullable) PTAnnotationStylePresetsGroup *annotStylePresets;

#pragma mark - State persistence

/**
 * Save the current set of tool groups in `groups` and the selected group to disk
 * at the location specified by the `PTToolGroupManager.savedGroupsURL` class
 * property.
 */
- (void)saveGroups;

/**
 * Save the current set of tool groups in `groups` and the selected group to disk
 * at the specified location.
 *
 * @param savedGroupsURL The URL of the location at which to save the groups
 */
- (void)saveGroupsToURL:(NSURL *)savedGroupsURL;

/**
 * Restore the set of tool groups and selected group from disk at the location
 * specified by the `PTToolGroupManager.savedGroupsURL` class property.
 */
- (void)restoreGroups;

/**
 * Restore the set of tool groups and selected group from disk at the specified
 * location.
 *
 * @param savedGroupsURL The URL of the location from which to restore the groups
 */
- (void)restoreGroupsFromURL:(NSURL *)savedGroupsURL;

/**
 * The URL of the location at which to save and restore the set of tool groups and
 * selected group.
 *
 * The default value of this property is the URL of a `.plist` file inside the directory
 * returned by `PTToolsUtil.toolsResourcesDirectoryURL`.
 */
@property (nonatomic, class, readonly, strong) NSURL *savedGroupsURL;

@end

/**
 * Methods that can be overridden in subclasses to customize behavior or intercept events.
 */
@interface PTToolGroupManager (SubclassingHooks)

/**
 * The default action method for items created by the `-createItemForToolClass:` method.
 *
 * @param item The bar button item that was triggered.
 */
- (void)itemTriggered:(UIBarButtonItem *)item;

@end

/**
 * This notification is posted when the selected tool group changes.
 *
 * The notification object is the tool group manager that posted the
 * notification.
 */
PT_EXPORT const NSNotificationName PTToolGroupDidChangeNotification;

NS_ASSUME_NONNULL_END
