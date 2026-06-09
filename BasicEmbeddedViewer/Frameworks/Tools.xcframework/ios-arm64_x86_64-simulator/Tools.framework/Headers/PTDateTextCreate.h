//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTFreeTextCreate.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Key of the format of the date text annotation
PT_EXPORT NSString * const PTDateTextFormatKey;
/// Key of the date of the date text annotation
PT_EXPORT NSString * const PTDateTextDateKey;
/// Default format of the date text annotation
PT_EXPORT NSString * const PTDateTextDefaultDateFormat;

/**
 * Creates date text annotations.
*/
PT_OBJC_RUNTIME_NAME(DateTextCreate)
@interface PTDateTextCreate : PTFreeTextCreate

@end

NS_ASSUME_NONNULL_END
