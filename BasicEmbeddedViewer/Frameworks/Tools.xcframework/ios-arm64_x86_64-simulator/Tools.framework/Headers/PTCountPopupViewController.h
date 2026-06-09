//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTColorPickerViewController.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The PTCountPopupViewController displays the textField and color picker for users to edit the group name and color of count annotations.
 *
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(CountPopupViewController)
@interface PTCountPopupViewController : UIViewController <PTColorPickerViewControllerDelegate>


/**
 * Initializes a newly created `PTCountPopupViewController` instance.
 *
 * @param editing Whether the `PTCountPopupViewController` is for editing an existing group or not.
 *
 * @param groupLabel The name of the exisiting group.
 *
 * @param color The selected color of the existing group.
 *
 * @return an initialized `PTCountPopupViewController` instance.
 */
- (instancetype)initForEditing:(BOOL)editing withGroupLabel:(NSString *)groupLabel withColor:(UIColor *)color;

/**
 * The block to execute after pressing done button.
 */
@property (nonatomic, copy, nullable) void (^doneAction)(void);

/**
 * Textfield to input the group name.
 */
@property (nonatomic, strong) UITextField *textField;

/**
 * The color selected by the color picker.
 */
@property (nonatomic, strong) UIColor *selectedColor;

@end

NS_ASSUME_NONNULL_END
