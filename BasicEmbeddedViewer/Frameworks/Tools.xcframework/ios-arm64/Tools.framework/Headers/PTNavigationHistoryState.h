//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTNavigationHistoryItem.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(NavigationHistoryState)
@interface PTNavigationHistoryState : NSObject

- (instancetype)initWithBackItems:(nullable NSArray<PTNavigationHistoryItem *> *)backItems forwardItems:(nullable NSArray<PTNavigationHistoryItem *> *)forwardItems;

@property (nonatomic, readonly, copy, nullable) NSArray<PTNavigationHistoryItem *> *backItems;

@property (nonatomic, readonly, copy, nullable) NSArray<PTNavigationHistoryItem *> *forwardItems;

@end

NS_ASSUME_NONNULL_END
