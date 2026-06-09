//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTextSearchManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextSearchManager;
@class PTTextSearchToolbar;

PT_OBJC_RUNTIME_NAME(TextSearchToolbarDelegate)
@protocol PTTextSearchToolbarDelegate <NSObject>
@optional

/**
 * Tells the delegate when editing begins in the toolbar's text field.
 *
 * @param textSearchToolbar The text search toolbar in which editing has begun.
 */
- (void)textSearchToolbarDidBeginEditing:(PTTextSearchToolbar *)textSearchToolbar;

- (void)textSearchToolbar:(PTTextSearchToolbar *)textSearchToolbar
      didSubmitWithString:(NSString *)string;

- (void)textSearchToolbar:(PTTextSearchToolbar *)textSearchToolbar
         optionsDidChange:(PTTextSearchOptions *)textSearchOptions;

- (void)textSearchToolbarDidCancel:(PTTextSearchToolbar *)textSearchToolbar;

- (void)textSearchToolbarFindPreviousResult:(PTTextSearchToolbar *)textSearchToolbar;

- (void)textSearchToolbarFindNextResult:(PTTextSearchToolbar *)textSearchToolbar;

@end

PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextSearchToolbar)
@interface PTTextSearchToolbar : UIView <UITextFieldDelegate>

- (instancetype)initWithTextSearchManager:(PTTextSearchManager *)textSearchManager NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * The delegate of this view.
 */
@property (nonatomic, weak, nullable) id<PTTextSearchToolbarDelegate> delegate;

@property (nonatomic, readonly, strong) PTTextSearchManager *textSearchManager;

@property (nonatomic, readonly, strong) PTTextSearchOptions *textSearchOptions;

@property (nonatomic, readonly, strong) UITextField *searchTextField;

@property (nonatomic, readonly, strong) UIButton *searchSettingsButton;

#pragma mark - Buttons

@property (nonatomic, readonly, strong) UIButton *doneButton;

@property (nonatomic, readonly, strong) UIButton *previousResultButton;
@property (nonatomic, readonly, strong) UIButton *nextResultButton;

/**
 * The view that provides the background appearance.
 *
 * Setting a value of `nil` resets this property to the default background view.
 */
@property (nonatomic, strong, null_resettable) UIView *backgroundView;

#pragma mark - Activity indicator

/**
 * The activity indicator displayed by this view.
 */
@property (nonatomic, readonly, strong) UIActivityIndicatorView *activityIndicator;

/**
 * Whether the `activityIndicator` is currently hidden.
 *
 * The activity indicator is hidden by default.
 */
@property (nonatomic, assign, getter=isActivityIndicatorHidden) BOOL activityIndicatorHidden;

#pragma mark - Button actions

/**
 * This method is called when the `doneButton` is pressed.
 */
- (void)donePressed:(nullable id)sender;

/**
 * This method is called when the `previousResultButton` is pressed.
 */
- (void)previousResultPressed:(nullable id)sender;

/**
 * This method is called when the `nextResultButton` is pressed.
 */
- (void)nextResultPressed:(nullable id)sender;

@end

NS_ASSUME_NONNULL_END
