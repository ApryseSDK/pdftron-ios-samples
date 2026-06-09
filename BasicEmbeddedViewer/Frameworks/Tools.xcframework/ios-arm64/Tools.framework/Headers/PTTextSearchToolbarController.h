//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTextSearchManager.h>
#import <Tools/PTTextSearchToolbar.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextSearchManager;
@class PTTextSearchToolbar;
@class PTTextSearchToolbarController;

PT_OBJC_RUNTIME_NAME(TextSearchToolbarControllerDelegate)
@protocol PTTextSearchToolbarControllerDelegate <NSObject>
@optional

- (void)textSearchToolbarControllerWillShowToolbar:(PTTextSearchToolbarController *)textSearchToolbarController;
- (void)textSearchToolbarControllerDidShowToolbar:(PTTextSearchToolbarController *)textSearchToolbarController;

- (void)textSearchToolbarControllerWillHideToolbar:(PTTextSearchToolbarController *)textSearchToolbarController;
- (void)textSearchToolbarControllerDidHideToolbar:(PTTextSearchToolbarController *)textSearchToolbarController;

- (void)textSearchToolbarController:(PTTextSearchToolbarController *)textSearchToolbarController
         didCancelTextSearchSession:(nullable PTTextSearchSession *)textSearchSession;

@end

PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextSearchToolbarController)
@interface PTTextSearchToolbarController : UIViewController <PTTextSearchToolbarDelegate>

- (instancetype)initWithTextSearchManager:(PTTextSearchManager *)textSearchManager NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithNibName:(nullable NSString *)nibName
                         bundle:(nullable NSBundle *)bundle NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * The delegate of this view controller.
 */
@property (nonatomic, weak, nullable) id<PTTextSearchToolbarControllerDelegate> delegate;

/**
 * The text search manager used by this view controller.
 */
@property (nonatomic, readonly, strong) PTTextSearchManager *textSearchManager;

#pragma mark - Text search toolbar

/**
 * The text search toolbar managed by this view controller.
 *
 * The delegate of the `PTTextSearchToolbar` is this view controller and should not be changed.
 */
@property (nonatomic, readonly, strong) PTTextSearchToolbar *toolbar;

#pragma mark Visibility

/**
 * Whether the `toolbar` is currently hidden or shown.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isToolbarHidden) BOOL toolbarHidden;

/**
 * Sets whether the `toolbar` is currently hidden, optionally animating the change.
 *
 * @param hidden Specify `YES` to hide the toolbar or `NO` to show it
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * toolbar to appear immediately.
 */
- (void)setToolbarHidden:(BOOL)hidden
                animated:(BOOL)animated;

/**
 * The duration of the `toolbar`'s animation when shown or hidden.
 *
 * The default duration is `0.25` seconds.
 */
@property (nonatomic, assign) NSTimeInterval toolbarAnimationDuration;

@end

NS_ASSUME_NONNULL_END
