//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTDocumentBaseViewController.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentBaseViewController;

/**
 * A `PTDocumentTabItem` represents a document in a tabbed user interface, where the
 * document is displayed in a `PTDocumentBaseViewController` subclass.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentTabItem)
@interface PTDocumentTabItem : NSObject <NSSecureCoding, NSCopying>

/**
 * Initializes a newly created `PTDocumentTabItem` instance with the specified document
 * source URL.
 *
 * @return an initialized `PTDocumentTabItem` instance
 */
- (instancetype)initWithSourceURL:(NSURL *)sourceURL;

/**
 * Initializes a newly created `PTDocumentTabItem` instance.
 *
 * @return an initialized `PTDocumentTabItem` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly create `PTDocumentTabItem` with an existing instance.
 *
 * @param item the existing `PTDocumentTabItem` instance to copy
 *
 * @return an initialized `PTDocumentTabItem` instance
 */
- (instancetype)initWithDocumentTabItem:(PTDocumentTabItem *)item NS_DESIGNATED_INITIALIZER;

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
 * The original source URL of the document.
 *
 * For non-file URLs (eg. HTTP(S) scheme URLs) or documents that require conversion
 * before being displayed, this property will be different from the `documentURL`
 * property.
 */
@property (nonatomic, strong, nullable) NSURL *sourceURL;

/**
 * The file URL of the document displayed in the `viewController`.
 *
 * For non-file URLs (eg. HTTP(S) scheme URLs) or documents that require conversion
 * before being displayed, this URL will be different from the `sourceURL` property.
 */
@property (nonatomic, strong, nullable) NSURL *documentURL;

/**
 * The title to be displayed for this tab. When this property is `nil`, the last path component of
 * the `documentURL` or `sourceURL` is used for the title of this tab.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *displayName;

/**
 * The time and date that this tab was last accessed.
 *
 * The default value of this property is `NSDate.distantPast` until the tab item is
 * accessed for the first time.
 */
@property (nonatomic, strong) NSDate *lastAccessedDate;

@property (nonatomic, weak, nullable) __kindof PTDocumentBaseViewController *viewController;

#pragma mark - Header view

/**
 * The view to be displayed above any tabbed user interface when this tab item is
 * selected.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, strong, nullable) UIView *headerView;

/**
 * Sets the view to be displayed above any tabbed user interface when this tab item is
 * selected, optionally animating the change.
 *
 * @param headerView the view to be displayed
 *
 * @param animated `YES` if the change should be animated, `NO` otherwise
 */
- (void)setHeaderView:(nullable UIView *)headerView animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
