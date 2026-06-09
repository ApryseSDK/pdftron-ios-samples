//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2026 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTextSearchOptions;

/**
 * Options controlling the behavior of a text search.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(TextSearchOptions)
@interface PTTextSearchOptions : NSObject <NSCopying>

- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * The default value of this property is false.
 */
@property (nonatomic, assign) BOOL caseSensitive;

/**
 * The default value of this property is false.
 */
@property (nonatomic, assign) BOOL wholeWordMatching;

@end

NS_ASSUME_NONNULL_END
