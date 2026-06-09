//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTToolGroup` class encapsulates a list of `UIBarButtonItem` instances with
 * a title and image to be displayed in a user interface.
 *
 * This class is similar to the `UIBarButtonItemGroup` class except that a bar button
 * item can be included in more than one `PTToolGroup`.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(ToolGroup)
@interface PTToolGroup : NSObject <NSCoding>

/**
 * Initializes a newly created `PTToolGroup` instance with the given parameters.
 *
 * @param title The title of the tool group
 *
 * @param barButtonItems The list of bar button items for this tool group
 *
 * @return an initialized `PTToolGroup` instance
 */
- (instancetype)initWithTitle:(nullable NSString *)title barButtonItems:(NSArray<UIBarButtonItem *> *)barButtonItems;

/**
 * Initializes a newly created `PTToolGroup` instance with the given parameters.
 *
 * @param image The image representing the tool group
 *
 * @param barButtonItems The list of bar button items for this tool group
 *
 * @return an initialized `PTToolGroup` instance
 */
- (instancetype)initWithImage:(nullable UIImage *)image barButtonItems:(NSArray<UIBarButtonItem *> *)barButtonItems;

/**
 * Initializes a newly created `PTToolGroup` instance with the given parameters.
 * This method is a designated initializer of the `PTToolGroup` class.
 *
 * @param title The title of the tool group
 *
 * @param image The image representing the tool group
 *
 * @param barButtonItems The list of bar button items for this tool group
 *
 * @return an initialized `PTToolGroup` instance
 */
- (instancetype)initWithTitle:(nullable NSString *)title image:(nullable UIImage *)image barButtonItems:(NSArray<UIBarButtonItem *> *)barButtonItems NS_DESIGNATED_INITIALIZER;

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
 * A convenience method that returns a tool group initialized with the specified
 * parameters.
 *
 * @param title The title of the tool group
 *
 * @param image The image representing the tool group
 *
 * @param barButtonItems The list of bar button items for the tool group
 *
 * @return an initialized `PTToolGroup` instance
 */
+ (instancetype)groupWithTitle:(nullable NSString *)title image:(nullable UIImage *)image barButtonItems:(NSArray<UIBarButtonItem *> *)barButtonItems;

/**
 * The title of the tool group.
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 * The image representing the tool group.
 */
@property (nonatomic, strong, nullable) UIImage *image;

/**
 * The list of bar button items managed by this tool group.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *barButtonItems;

/**
 * Whether this tool group is editable from the user interface.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign, getter=isEditable) BOOL editable;

/**
 * Whether this tool group represents a favorite group.
 *
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isFavorite) BOOL favorite;

/**
 * A string that uniquely identifies this tool group from other groups in a
 * collection of groups or in the user interface.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *identifier;

@end

NS_ASSUME_NONNULL_END
