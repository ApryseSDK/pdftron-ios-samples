//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentBaseViewController.h>
#import <Tools/PTDocumentOptions.h>
#import <Tools/PTDocumentTabBar.h>
#import <Tools/PTDocumentTabItem.h>
#import <Tools/PTDocumentTabManager.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentBaseViewController;
@class PTDocumentOptions;
@class PTDocumentTabBar;
@class PTDocumentTabItem;
@class PTDocumentTabManager;
@class PTTabbedDocumentViewController;
@protocol PTTabbedDocumentViewControllerDelegate;

/**
 * The methods declared by the PTTabbedDocumentViewControllerDelegate protocol allow the adopting delegate
 * to respond to messages from the `PTTabbedDocumentViewController` class.
 */
PT_OBJC_RUNTIME_NAME(TabbedDocumentViewControllerDelegate)
@protocol PTTabbedDocumentViewControllerDelegate <NSObject>
@optional

/**
 * This method is called when the tabbed document view controller is opening the
 * document at the specified URL and needs to create a new document view controller for
 * the tab. The delegate must create and return a new instance of a
 * `PTDocumentBaseViewController` subclass.
 *
 * If this method is not implemented by the delegate, an instance of the class specified
 * by the `PTTabbedDocumentViewController.viewControllerClass` will be created.
 */
- (__kindof PTDocumentBaseViewController *)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController createViewControllerForDocumentAtURL:(NSURL *)url;

/**
 * Informs the delegate that a document view controller will be added. This provides an opportunity
 * to perform any setup on the view controller before it is presented to the user.
 */
- (void)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController willAddDocumentViewController:(__kindof PTDocumentBaseViewController *)documentViewController;

/**
 * Informs the delegate that a tab will be removed from the tabbed document view controller.
 */
- (void)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController willRemoveTabAtIndex:(NSUInteger)index;

/**
 * Informs the delegate that a tab has been removed.
 *
 * @param tabbedDocumentViewController The tabbed document view controller.
 * @param tab The tab object that was removed.
 * @param index The index of the tab.
 */
- (void)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController
                        didRemoveTab:(PTDocumentTabItem *)tab
                             atIndex:(NSUInteger)index;

/**
 * This method allows the delegate to decide if the tab bar should be hidden for the
 * given trait collection.
 *
 * If this method is not implemented, the tab bar will be hidden for compact horizontal
 * size classes.
 */
- (BOOL)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController shouldHideTabBarForTraitCollection:(UITraitCollection *)traitCollection;

@end

/**
 * A container view controller that displays multiple documents with a tab bar control to allow
 * switching between documents.
 */
PT_OBJC_RUNTIME_NAME(TabbedDocumentViewController)
@interface PTTabbedDocumentViewController : UIViewController <PTOverridable>

/**
 * Returns an initialized `PTTabbedDocumentViewController` instance.
 *
 * @return an initialized `PTTabbedDocumentViewController` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Open a document with the given URL.
 *
 * @param url The URL to open.
 */
- (void)openDocumentWithURL:(NSURL *)url;

/**
 * Open a document with the given URL and password.
 *
 * @param url The URL to open.
 *
 * @param password The password for the document.
 */
- (void)openDocumentWithURL:(NSURL *)url password:(nullable NSString *)password;

/**
 * Open a document with the given URL and options.
 *
 * @param url The URL to open.
 *
 * @param options The options to use in opening the document.
 */
- (void)openDocumentWithURL:(NSURL *)url options:(nullable PTDocumentOptions *)options;

/**
 * Whether multiple tabs can be displayed.
 *
 * The default value of this property is `YES`. If tabs are disabled, the tab bar will be hidden and
 * all tabs except the selected tab will be removed.
 */
@property (nonatomic, assign) BOOL tabsEnabled;

/**
 * The maximum number of tabs allowed. There is no limit by default.
 *
 * When the maximum number of tabs is reached, adding subsequent tabs will remove other tabs to respect
 * the limit.
 *  
 * @note The value of this property must be greater than zero.
 */
@property (nonatomic, assign) NSUInteger maximumTabCount;

#pragma mark Tab management

/**
 * The tab manager used to track the list of tabs and the selected tab.
 */
@property (nonatomic, readonly, strong) PTDocumentTabManager *tabManager;

/**
 * The document tab bar used to display the tabs
 */
@property (nonatomic, readonly, strong) PTDocumentTabBar *tabBar;

/**
 * An array of the URLs managed by the view controller and displayed by the tab bar interface.
 * The tabs are displayed in the same order as in the array.
 */
@property (nonatomic, readonly, copy) NSArray<NSURL *> *tabURLs;

/**
 * Returns the document view controller at the specified tab index.
 *
 * @param index the view controller's tab index
 *
 * @return the document view controller at the specified tab index, or `nil` if it is not loaded.
 */
- (nullable __kindof PTDocumentBaseViewController *)documentViewControllerAtIndex:(NSUInteger)index;

/**
 * Inserts the given URL at the end of the tab bar.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the end of the tab bar.
 *
 * @param selected Whether to select the tab after it has been added.
 */
- (void)addTabWithURL:(NSURL *)url selected:(BOOL)selected;

/**
 * Inserts the given URL at the end of the tab bar.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the end of the tab bar.
 *
 * @param password The password for the document.
 *
 * @param selected Whether to select the tab after it has been added.
 */
- (void)addTabWithURL:(NSURL *)url password:(nullable NSString *)password selected:(BOOL)selected;

/**
 * Inserts the given URL at the end of the tab bar.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the end of the tab bar.
 *
 * @param options The options to use for the document.
 *
 * @param selected Whether to select the tab after it has been added.
 */
- (void)addTabWithURL:(NSURL *)url options:(nullable PTDocumentOptions *)options selected:(BOOL)selected;

/**
 * Inserts the given URL into the tab bar at the specified index.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the tab bar.
 *
 * @param index The index in the tab bar at which to insert the URL. This value must not be greater than
 * the number of tabs in the tab bar.
 *
 * @param selected Whether to selected the tab after it has been inserted.
 */
- (void)insertTabWithURL:(NSURL *)url atIndex:(NSUInteger)index selected:(BOOL)selected;

/**
 * Inserts the given URL into the tab bar at the specified index.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the tab bar.
 *
 * @param password The password for the document.
 *
 * @param index The index in the tab bar at which to insert the URL. This value must not be greater than
 * the number of tabs in the tab bar.
 *
 * @param selected Whether to selected the tab after it has been inserted.
 */
- (void)insertTabWithURL:(NSURL *)url password:(nullable NSString *)password atIndex:(NSUInteger)index selected:(BOOL)selected;

/**
 * Inserts the given URL into the tab bar at the specified index.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the tab bar.
 *
 * @param options The options to use for the document.
 *
 * @param index The index in the tab bar at which to insert the URL. This value must not be greater
 * than the number of tabs in the tab bar.
 *
 * @param selected Whether to selected the tab after it has been inserted.
 */
- (void)insertTabWithURL:(NSURL *)url options:(nullable PTDocumentOptions *)options atIndex:(NSUInteger)index selected:(BOOL)selected;

/**
 * Removes the first occurence of the given URL in the tab bar.
 *
 * @param url The URL to remove from the tab bar.
 */
- (void)removeTabWithURL:(NSURL *)url;

/**
 * Removes the tab for the given document view controller.
 *
 * @param viewController The view controller of the tab to remove.
 */
- (void)removeTabForViewController:(PTDocumentBaseViewController *)viewController;

/**
 * Removes the tab at the given index.
 *
 * @param index The index from which to remove the tab in the tab bar.
 */
- (void)removeTabAtIndex:(NSUInteger)index;

/**
 * Shows a list of all the tabs in the view controller.
 */
- (void)showTabsList:(id)sender;

/**
 * This method is called when the tabs are modified
 * e.g. added, removed, rearranged.
 */
- (void)tabsDidChange;

#pragma mark Selection

/**
 * The URL associated with the currently selected tab.
 */
@property (nonatomic, readonly, weak, nullable) NSURL *selectedURL;

/**
 * The index of the tab URL associated with the currently selected tab.
 *
 * If there is no currently selected tab, the value is `NSNotFound`.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * The currently selected document view controller.
 */
@property (nonatomic, readonly, nullable) __kindof PTDocumentBaseViewController *selectedViewController;

#pragma mark Tab bar

/**
 * A Boolean value that indicates whether the tab bar is hidden.
 *
 * If `YES`, the tab bar is hidden. The default value is `NO` if the `tabsEnabled` property is enabled.
 * Setting this property changes the visibility of the tab bar without animating the changes. If you want
 * to animate the change, use the `-setTabBarHidden:animated:` method instead.
 */
@property (nonatomic, assign, getter=isTabBarHidden) BOOL tabBarHidden;

/**
 * Sets whether the tab bar is hidden.
 *
 * For animated transitions, the duration of the animation is specified by the value in the `UINavigationControllerHideShowBarDuration` constant.
 *
 * @param hidden Specify `YES` to hide the tab bar or `NO` to show it
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * tab bar to appear immediately.
 */
- (void)setTabBarHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * The `PTDocumentBaseViewController` subclass used for new tabs.
 * 
 * The default class is `PTDocumentController`.
 */
@property (nonatomic, null_resettable) Class viewControllerClass;

#pragma mark Other

/**
 The delegate of the tabbed document view controller object.
 */
@property (nonatomic, weak, nullable) id<PTTabbedDocumentViewControllerDelegate> delegate;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
