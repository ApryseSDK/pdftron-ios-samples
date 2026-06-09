//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTSelectableBarButtonItem.h>
#import <Tools/PTAnnotStyle.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT
PT_OBJC_RUNTIME_NAME(ToolBarButtonItem)
@interface PTToolBarButtonItem : PTSelectableBarButtonItem <NSCopying>

- (instancetype)initWithToolClass:(Class)toolClass target:(nullable id)target action:(nullable SEL)action;

@property (nonatomic, strong, nullable) Class toolClass;

@property (nonatomic, copy, nullable) NSString *identifier;

/**
 * Whether this button item shows the current, default annotation style for the `toolClass`. For tool
 * classes that do not create annotations or allow editing the style of annotations, this property
 * has no effect.
 *
 * The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL showsAnnotationStyle;

/**
 * Set the small icon in the trailing bottom corner of the `PTToolBarButtonItem.
 *
 * @param tintColor the tint color of the image.
 */
- (void)setSubImage:(UIImage *)image withTintColor:(nullable UIColor *)tintColor;

/**
 * Set the style of the image of the `PTToolBarButtonItem.
 *
 * @param style the `PTAnnotStyle` to be set.
 */
- (void)setImageStyle:(PTAnnotStyle *)style;

@end

NS_ASSUME_NONNULL_END
