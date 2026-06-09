//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Returns a localized version of a string, using the Tools bundle.
 */
PT_EXTERN
NSString *PTLocalizedString(NSString *key,
                            NSString * _Nullable comment) NS_FORMAT_ARGUMENT(1);

/**
 * Returns a localized version of a string from the specified table, using the Tools bundle.
 */
PT_EXTERN
NSString *PTLocalizedStringFromTable(NSString *key,
                                     NSString * _Nullable table,
                                     NSString * _Nullable comment) NS_FORMAT_ARGUMENT(1) NS_SWIFT_NAME(PTLocalizedString(key:table:comment:));

NS_ASSUME_NONNULL_END
