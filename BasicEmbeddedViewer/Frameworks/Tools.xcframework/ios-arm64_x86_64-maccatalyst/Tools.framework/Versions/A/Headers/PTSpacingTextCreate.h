//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTFreeTextCreate.h>
#import <Tools/PTAnnotEditTool.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Kern of the spacing text annotation
PT_EXPORT NSString * const PTSpacingTextKernKey;

/**
 * Creates spacing text annotations.
*/
PT_OBJC_RUNTIME_NAME(SpacingTextCreate)
@interface PTSpacingTextCreate : PTFreeTextCreate <PTAnnotEditToolDelegate>

/**
 * Returns the number of columns of the spacing text annotation.
 *
 * @param text the `NSAttributedString` of the annotation
 */
+ (int)numOfColumns:(NSAttributedString *)text;

/**
 * Returns the number of rows of the spacing text annotation.
 *
 * @param text the `NSAttributedString` of the annotation
 */
+ (int)numOfRows:(NSAttributedString *)text;

@end

NS_ASSUME_NONNULL_END
