//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PTObj (Additions)

/**
 * Returns the decoded contents of this text stream's data.
 *
 * @return the decoded contents of this text stream's data, or `nil` if the text stream is empty or
 * an error occurred.
 */
- (nullable NSString *)GetTextStreamContents;

@end

NS_ASSUME_NONNULL_END
