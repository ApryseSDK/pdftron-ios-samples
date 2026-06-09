//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTCreateToolBase.h>
#import <Tools/EraserCommon.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTEraser;

/**
 * Erases points from FreeHand (ink) annotations.
 */
PT_OBJC_RUNTIME_NAME(Eraser)
@interface PTEraser : PTCreateToolBase

/**
 * If YES, the eraser will ignore touches that aren't made with an Apple Pencil
 * and will switch to the tool's default class.
 */
@property (nonatomic, assign) BOOL acceptPencilTouchesOnly;

/**
 * Defines how to erase ink annotations. Default is `PTInkEraserModePoints`
 *
 * The value of this property is set via the `PTToolManager.eraserMode` property.
 */
@property (nonatomic, assign, readonly) PTInkEraserMode eraserMode;

@end

NS_ASSUME_NONNULL_END
