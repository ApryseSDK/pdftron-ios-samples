//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTAnnotationStylePresetsGroup.h>
#import <Tools/PTDigitalSignatureTool.h>
#import <Tools/PTCountCreate.h>
#import <Tools/PTAnnotStyleViewController.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTAnnotStyleToolbar` class displays a `PTAnnotationStylePresetsGroup` for
 * controlling the selected annotation style preset. The selected annotation style
 * preset can be edited by tapping on it.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(AnnotStyleToolbar)
@interface PTAnnotStyleToolbar : UIToolbar <PTAnnotStyleViewControllerDelegate, PTDigitalSignatureToolDelegate, PTCountCreateDelegate, PTOverridable>

/**
 * Initializes a newly created `PTAnnotStyleToolbar` instance with the specified tool manager.
 *
 * @param toolManager the tool manager to be used by the receiver
 *
 * @return an initialized `PTAnnotStyleToolbar` instance
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * The tool manager used by the toolbar.
 */
@property (nonatomic, strong, nullable) PTToolManager *toolManager;

#pragma mark - Annotation style presets

/**
 * The annotation style presets shown by the toolbar.
 */
@property (nonatomic, copy, nullable) PTAnnotationStylePresetsGroup *annotStylePresets;

#pragma mark - Annotation style picker

/**
 * The annotation style picker shown by the toolbar when the selected preset is tapped.
 */
@property (nonatomic, strong, nullable) PTAnnotStyleViewController *stylePicker;

@end

NS_ASSUME_NONNULL_END
