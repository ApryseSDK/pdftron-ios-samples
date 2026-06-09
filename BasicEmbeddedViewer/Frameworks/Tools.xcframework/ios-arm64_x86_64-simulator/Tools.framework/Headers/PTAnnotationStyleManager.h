//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>
#import <Tools/PTAnnotationStylePresetsGroup.h>
#import <Tools/PTOverrides.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the keys used to create an AnnotationStylePresets.plist file to define what the initial
 * annotation properties are.
 */
typedef NSString * PTAnnotStylePresetKey NS_TYPED_EXTENSIBLE_ENUM;

/// The key for the array of annotation types that this group of annotation presets belongs to.
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyTypes = @"types";

/// The key for the array of annotation presets.
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyPresets = @"presets";

/// The key of a dictionary entry where a (stroke) color is defined as a hex string, e.g. "#00AA55"
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyColor = @"color";

/// The key of a dictionary entry where a fill color is defined as a hex string, e.g. "#00AA55"
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyFillColor = @"fillColor";

/// The key of a dictionary entry where the text color of a FreeText annotation is defined as a hex string, e.g. "#00AA55"
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyTextColor = @"textColor";

/// The key of a dictionary entry where the text size of a FreeText annotation is defined as a number.
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyTextSize = @"textSize";

/// The key of a dictionary entry where the stroke thickness of an annotation is defined as a number.
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyThickness = @"thickness";

/// The key of a dictionary entry where the opacity of an annotation is defined as a number between 0 and 1.
static const PTAnnotStylePresetKey PTAnnotStylePresetKeyOpacity = @"opacity";

@class PTAnnotationStyleManager;

/**
 * Manages the saved annotation style presets
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationStyleManager)
@interface PTAnnotationStyleManager : NSObject <PTOverridable>

/**
 * The manager singleton
 */
@property (nonatomic, class, readonly, strong) PTAnnotationStyleManager *defaultManager;


/**
 * The date when `saveStylePresets` was last called. Default is null.
 */
@property (nonatomic, readonly, strong, nullable) NSDate *lastSaveDate;

/**
 * Retrieves the default style dictionary for the given annotation type.
 *
 * @param annotType The annotation type for which the default style should be returned.
 */
+ (nullable NSDictionary *)styleDefaultForAnnotationType:(PTExtendedAnnotType)annotType;

/**
 * Retrieves the default style dictionary for the given annotation type.
 *
 * @param annotType The annotation type for which the default style should be returned.
 *
 * @param index The preset index.
 */
+ (nullable NSDictionary *)styleDefaultForAnnotationType:(PTExtendedAnnotType)annotType presetIndex:(int)index;

/**
 * Retrieves the annotation style preset group for the given annotation type.
 *
 * @param annotType The annotation type for which the annotation style preset group should be returned.
 */
- (PTAnnotationStylePresetsGroup *)stylePresetsForAnnotationType:(PTExtendedAnnotType)annotType;

/**
 * Retrieves the annotation style preset group for the given annotation type and unique preset group ID.
 *
 * @param annotType The annotation type for which the annotation style preset group should be returned.
 *
 * @param identifier The unique ID of the preset group.
 */
- (PTAnnotationStylePresetsGroup *)stylePresetsForAnnotationType:(PTExtendedAnnotType)annotType identifier:(nullable NSString *)identifier;

/**
 * Sets the annotation style preset group for the given annotation type.
 *
 * @param annotType The annotation type for which the annotation style preset group should be returned.
 */
- (void)setStylePresets:(PTAnnotationStylePresetsGroup *)stylePresets forAnnotationType:(PTExtendedAnnotType)annotType;

/**
 * Sets the annotation style preset group for the given annotation type and unique preset group ID.
 *
 * @param annotType The annotation type for which the annotation style preset group should be returned.
 *
 * @param identifier The unique ID of the preset group.
 */
- (void)setStylePresets:(PTAnnotationStylePresetsGroup *)stylePresets forAnnotationType:(PTExtendedAnnotType)annotType identifier:(nullable NSString *)identifier;

/**
 * Saves the current preset style groups to disk.
 */
- (void)saveStylePresets;

/**
 * Deletes the saved preset style groups from disk.
 */
- (void)deleteSavedStylePresets;

@end

NS_ASSUME_NONNULL_END
