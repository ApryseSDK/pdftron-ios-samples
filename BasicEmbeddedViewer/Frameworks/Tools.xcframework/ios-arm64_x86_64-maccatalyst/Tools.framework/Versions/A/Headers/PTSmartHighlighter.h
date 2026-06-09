//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTSmartTool.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSmartHighlighter;

/**
 * A tool that creates different types of annotations depending on if a touch begins over text in
 * the document or over a non-text area.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(SmartHighlighter)
@interface PTSmartHighlighter : PTSmartTool

@end

NS_ASSUME_NONNULL_END
