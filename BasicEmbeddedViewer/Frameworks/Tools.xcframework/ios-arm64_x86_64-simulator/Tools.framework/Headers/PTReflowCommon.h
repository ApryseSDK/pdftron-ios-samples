//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The scrolling direction of a reflow view controller.
 */
typedef NS_ENUM(NSUInteger, PTReflowViewControllerScrollingDirection) {
    /// Horizontal scrolling.
    PTReflowViewControllerScrollingDirectionHorizontal,
    /// Vertical scrolling.
    PTReflowViewControllerScrollingDirectionVertical,
    /// Match the setting of `PDFViewCtrl`.
    PTReflowViewControllerScrollingDirectionAutomatic,
};

NS_ASSUME_NONNULL_END
