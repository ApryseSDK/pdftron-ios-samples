//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import <Tools/ToolsDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFontPickerViewController;

PT_OBJC_RUNTIME_NAME(FontPickerViewControllerDelegate)
@protocol PTFontPickerViewControllerDelegate <NSObject>

- (void)fontPickerViewControllerDidPickFont:(PTFontPickerViewController *)fontPickerViewController;

@end

PT_OBJC_RUNTIME_NAME(FontPickerViewController)
@interface PTFontPickerViewController : UITableViewController

@property (nonatomic, weak) id<PTFontPickerViewControllerDelegate> delegate;

@property (nullable, strong, nonatomic) UIFont *selectedFont;

- (instancetype)initWithFonts:(NSArray<UIFont *> *)fonts;

@end

NS_ASSUME_NONNULL_END
