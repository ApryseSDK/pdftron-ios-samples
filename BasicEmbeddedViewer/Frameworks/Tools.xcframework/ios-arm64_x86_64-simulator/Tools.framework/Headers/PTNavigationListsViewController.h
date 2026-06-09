//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationViewController.h>
#import <Tools/PTBookmarkViewController.h>
#import <Tools/PTDigitalSignaturesViewController.h>
#import <Tools/PTOutlineViewController.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTPDFLayerViewController.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The visibility of a list view controller in a `PTNavigationListsViewController` instance.
 */
typedef NS_ENUM(NSUInteger, PTNavigationListsViewControllerVisibility) {
    /// Show the list view controller if has content.
    PTNavigationListsViewControllerVisibilityAutomatic,
    /// Show the list view controller even if it has no content.
    PTNavigationListsViewControllerVisibilityNeverHidden,
    /// Always hide the list view controller.
    PTNavigationListsViewControllerVisibilityAlwaysHidden
};

/**
 * A container view controller similar to a `UITabBarController` that displays a segmented control where
 * the selection determines which child view controller to display.
 *
 * By default, the navigation lists controller contains an `PTOutlineViewController`, `PTAnnotationViewController`,
 * `PTBookmarkViewController`, and if the document contains OCG layers, a `PTPDFLayerViewController`.
 */
PT_OBJC_RUNTIME_NAME(NavigationListsViewController)
@interface PTNavigationListsViewController : UIViewController <PTOverridable>

/**
 * Returns an initialized `PTNavigationListsViewController` with the default lists.
 *
 * @param toolManager the tool manager used to initialize the default child view controllers
 *
 * @return an initialized `PTNavigationListsViewController` with the default lists
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;

/**
 * The child view controllers to manage and display.
 */
@property (nullable, nonatomic, copy) NSArray<UIViewController *> *listViewControllers;

/**
 * Adds a child view controller to the list of managed view controllers.
 *
 * @param listViewController the child view controller to be added
 */
- (void)addListViewController:(UIViewController *)listViewController;

/**
 * Removes a child view controller from the list of managed view controllers.
 *
 * @param listViewController the child view controller to be removed
 */
- (void)removeListViewController:(UIViewController *)listViewController;

/**
 * The currently selected view controller in `listViewControllers`.
 */
@property (nonatomic, strong, nullable) UIViewController *selectedViewController;

/**
 * The index of the currently selected list view controller. The default value is `0`.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * The `PTOutlineViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTOutlineViewController *outlineViewController;

/**
 * The `PTAnnotationViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTAnnotationViewController *annotationViewController;

/**
 * The `PTBookmarkViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTBookmarkViewController *bookmarkViewController;

/**
 * The `PTDigitalSignaturesViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTDigitalSignaturesViewController *digitalSignaturesViewController;

/**
 * The `PTPDFLayerViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTPDFLayerViewController *pdfLayerViewController;

/**
 * The visibility of the `PTPDFLayerViewController`.
 */
@property (nonatomic, assign) PTNavigationListsViewControllerVisibility pdfLayerViewControllerVisibility;

/**
 * The visibility of the `PTDigitalSignaturesViewController`.
 */
@property (nonatomic, assign) PTNavigationListsViewControllerVisibility digitalSignaturesViewControllerVisibility;


- (instancetype)initWithNibName:(nullable NSString *)nibName bundle:(nullable NSBundle *)nibBundle NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
