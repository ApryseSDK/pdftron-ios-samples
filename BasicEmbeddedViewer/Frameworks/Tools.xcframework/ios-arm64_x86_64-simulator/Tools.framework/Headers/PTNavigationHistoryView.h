//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTNavigationHistoryManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTNavigationHistoryManager;
@class PTNavigationHistoryView;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(NavigationHistoryView)
@interface PTNavigationHistoryView : UIView

- (instancetype)initWithNavigationHistoryManager:(PTNavigationHistoryManager *)navigationHistoryManager;

@property (nonatomic, strong, nullable) PTNavigationHistoryManager *navigationHistoryManager;

@property (nonatomic, readonly, strong) UIButton *backButton;

@property (nonatomic, readonly, strong) UIButton *forwardButton;

@end

NS_ASSUME_NONNULL_END
