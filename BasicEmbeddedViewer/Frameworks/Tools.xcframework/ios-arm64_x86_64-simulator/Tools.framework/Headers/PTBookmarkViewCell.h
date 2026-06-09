//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import <Tools/ToolsDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class PTBookmarkViewCell;
@protocol PTBookmarkViewCellDelegate;

/**
 * The vertical alignment of an indicator view in a `PTBookmarkViewCell`.
 */
typedef NS_ENUM(NSUInteger, PTBookmarkViewCellIndicatorAlignment) {

    /**
     * The indicator is top-aligned.
     */
    PTBookmarkViewCellIndicatorAlignmentTop,

    /**
     * The indicator is center-aligned.
     */
    PTBookmarkViewCellIndicatorAlignmentCenter,

    /**
     * The indicator is bottom-aligned.
     */
    PTBookmarkViewCellIndicatorAlignmentBottom,

} NS_SWIFT_NAME(PTBookmarkViewCell.IndicatorAlignment);

/**
 * The interface for the delegate of a `PTBookmarkViewCell` instance.
 */
PT_OBJC_RUNTIME_NAME(BookmarkViewCellDelegate)
@protocol PTBookmarkViewCellDelegate <NSObject>
@optional

/*
 * Called by the bookmark view cell when the text changes.
 *
 * @param bookmarkViewCell The bookmark view cell.
 *
 * @param text The text which changed.
 */
- (void)bookmarkViewCell:(PTBookmarkViewCell *)bookmarkViewCell didChangeText:(NSString *)text;

/*
 * Called by the bookmark view cell when the text is committed.
 *
 * @param bookmarkViewCell The bookmark view cell.
 *
 * @param text The text that was committed.
 */
- (void)bookmarkViewCell:(PTBookmarkViewCell *)bookmarkViewCell didCommitText:(NSString *)text;

@end

/**
 * A table view cell class capable of displaying user bookmark info.
 */
PT_OBJC_RUNTIME_NAME(BookmarkViewCell)
@interface PTBookmarkViewCell : UITableViewCell <UITextFieldDelegate>

@property (nonatomic, strong) UITextField *textField;

/**
 * Whether the text fields is editable.
 *
 * Can be set separately from the editing property, to allow the text to be edited outside of the UITableView's edit mode.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isTextFieldEditable) BOOL textFieldEditable;

/**
 * Configures the cell with the given text.
 *
 * @param text The text to be used for the cell.
 */

- (void)configureWithText:(NSString *)text;

#pragma mark Leading indicator view

/**
 * A view displayed at the leading edge of the cell that can be used to indicate some additional
 * state of the bookmark.
 *
 * This view can be used to display a small indicator-like icon, for example.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIView *leadingIndicatorView;

/**
 * The vertical alignment of the `leadingIndicatorView`.
 *
 * @note The default value of this property is `PTBookmarkViewCellIndicatorAlignmentTop`.
 */
@property (nonatomic, assign) PTBookmarkViewCellIndicatorAlignment leadingIndicatorAlignment;

/**
 * The delegate of the bookmark view cell.
 *
 * @note The default value of this property is `nil`.
 */
@property (nonatomic, weak, nullable) id<PTBookmarkViewCellDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
