//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTNavigationHistoryManager.h>
#import <Tools/PTNavigationHistoryView.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(NavigationHistoryViewController)
@interface PTNavigationHistoryViewController : UIViewController <PTOverridable>

@property (nonatomic, strong) PTNavigationHistoryManager *navigationHistoryManager;

@property (nonatomic, readonly, strong) PTNavigationHistoryView *navigationHistoryView;

@property (nonatomic, assign, getter=isNavigationHistoryViewHidden) BOOL navigationHistoryViewHidden;

- (void)setNavigationHistoryViewHidden:(BOOL)hidden animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
