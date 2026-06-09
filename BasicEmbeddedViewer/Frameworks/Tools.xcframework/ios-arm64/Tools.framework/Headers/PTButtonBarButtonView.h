//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTBarButtonItemCustomView.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(ButtonBarButtonView)
@interface PTButtonBarButtonView : PTBarButtonItemCustomView

@property (nonatomic, strong) UIButton *button;

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithContentView:(UIView *)contentView NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
