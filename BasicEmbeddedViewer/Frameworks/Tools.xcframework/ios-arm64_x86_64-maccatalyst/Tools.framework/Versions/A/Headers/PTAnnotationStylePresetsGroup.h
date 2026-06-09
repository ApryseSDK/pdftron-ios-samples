//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotStyle.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A group of `PTAnnotStyle` instances for the same annotation type with one style denoted as the
 * selected style.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(AnnotationStylePresetsGroup)
@interface PTAnnotationStylePresetsGroup : NSObject <NSCopying, NSCoding>

/**
 * Initializes a newly created `PTAnnotationStylePresetsGroup` instance with the specified styles.
 *
 * @param styles the initial styles of the presets group
 *
 * @return an initialized `PTAnnotationStylePresetsGroup` instance
 */
- (instancetype)initWithStyles:(NSArray<PTAnnotStyle *> *)styles NS_DESIGNATED_INITIALIZER;

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
 * The list of style presets in this preset group.
 */
@property (nonatomic, copy) NSArray<PTAnnotStyle *> *styles;

/**
 * The index of the currently selected style preset in the `styles` property.
 *
 * If `styles` is empty, the value of this property is `NSNotFound`.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * The currently selected style preset in the `styles` property.
 *
 * If `styles` is empty, the value of this property is `nil`.
 */
@property (nonatomic, weak, nullable) PTAnnotStyle *selectedStyle;

@end

NS_ASSUME_NONNULL_END
