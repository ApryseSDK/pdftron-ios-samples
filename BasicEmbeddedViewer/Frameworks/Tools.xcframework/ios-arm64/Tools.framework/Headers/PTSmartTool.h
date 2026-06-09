//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTTool.h>
#import <Tools/PTFreeHandCreate.h>
#import <Tools/PTTextMarkupCreate.h>
#import <Tools/PTAnnotationStylePresetsGroup.h>
#import <Tools/PTAnnotStyle.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSmartTool;

/**
 * A tool that creates different types of annotations depending on if a touch begins over text in
 * the document or over a non-text area.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(SmartTool)
@interface PTSmartTool : PTTool

/**
 * The active tool that is currently used for annotation or interaction. This tool can represent either
 * the primary tool or the secondary tool in viewer interaction
 */
@property (nonatomic, readonly, weak) PTTool *activeTool;

/**
 * The primary freehand/ink annotation creation tool. This tool is used for touches that do *not*
 * begin over text in the document.
 */
@property (nonatomic, readonly, strong) PTFreeHandCreate *primaryTool;

/**
 * The secondary text markup annotation creation tool. This tool is used for touches that begin over
 * text in the document.
 *
 * The `secondaryToolClass` property can be used to change the tool class of this property.
 */
@property (nonatomic, readonly, strong) PTTextMarkupCreate *secondaryTool;

/**
 * The default value for the `secondaryTool` instance property. The class must be a subclass of the
 * `PTFreeHandCreate` abstract base class.
 *
 * The default value of this property is the `PTFreeHandCreate` class. Setting a `Nil` value
 * for this property will reset the value to its default value.
 */
@property (nonatomic, class, strong, readonly) Class defaultPrimaryToolClass;

/**
 * The tool class to use for the `secondaryTool`. The class must be a subclass of the
 * `PTTextMarkupCreate` abstract base class.
 *
 * The default value of this property is the `PTComboTool.defaultSecondaryToolClass` class property
 * value.
 */
@property (nonatomic, strong, null_resettable) Class secondaryToolClass;

/**
 * The default value for the `secondaryTool` instance property. The class must be a subclass of the
 * `PTTextMarkupCreate` abstract base class.
 *
 * The default value of this property is the `PTTextHighlightCreate` class. Setting a `Nil` value
 * for this property will reset the value to its default value.
 */
@property (nonatomic, class, strong, null_resettable) Class defaultSecondaryToolClass;

/**
 * The annotation style presets for the primary tool.
 */
@property (nonatomic, readonly, strong) PTAnnotationStylePresetsGroup *annotationStylePresets;

/**
 * The presets of the primary ink tool
 */
@property (nonatomic, readonly, strong) PTAnnotationStylePresetsGroup *primaryPresets;
/**
 * The presets of the secondary ink tool
 */
@property (nonatomic, readonly, strong) PTAnnotationStylePresetsGroup *secondaryPresets;

/**
 * Synchronize selected style index between primary and secondary presets groups
 */
- (void)synchronizeSelectedStyleIndexes;

/**
 * The selected styles for the primary and secondary tools.
 */
@property (nonatomic, readonly, copy) NSArray<PTAnnotStyle *> *selectedStyles;

/**
 * The style for the currently active tool.
 *
 * The value of this property is one of the styles in the selected styles list.
 */
@property (nonatomic, readonly, strong) PTAnnotStyle *activeToolStyle;

/**
 * Edit the annotation style from the group in `annotationStylePresets`.
 */
- (void)editAnnotationStyle:(id)sender;

@end

NS_ASSUME_NONNULL_END
