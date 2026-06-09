//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/BasicTypes.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(NavigationHistoryItem)
@interface PTNavigationHistoryItem : NSObject

- (instancetype)initFromPageNumber:(PTPDFPageNumber)fromPageNumber toPageNumber:(PTPDFPageNumber)toPageNumber;
- (instancetype)initFromPageNumber:(PTPDFPageNumber)fromPageNumber toPageNumber:(PTPDFPageNumber)toPageNumber title:(nullable NSString *)title NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly, assign) PTPDFPageNumber fromPageNumber;
@property (nonatomic, readonly, assign) PTPDFPageNumber toPageNumber;

@property (nonatomic, readonly, copy, nullable) NSString *title;

@end

NS_ASSUME_NONNULL_END
