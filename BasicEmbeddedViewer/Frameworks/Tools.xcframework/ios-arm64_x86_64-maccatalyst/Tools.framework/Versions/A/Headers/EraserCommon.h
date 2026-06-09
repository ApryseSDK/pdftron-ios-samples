//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The ink eraser modes define how ink annotations should be erased.
 */
typedef NS_ENUM(NSUInteger, PTInkEraserMode) {
    /// Erase individual ink points
    PTInkEraserModePoints,
    /// Erase the entire ink annotation
    PTInkEraserModeAll,
};

NS_ASSUME_NONNULL_END
