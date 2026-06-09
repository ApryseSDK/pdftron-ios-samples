//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFreeTextView;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextView)
@interface PTFreeTextView : UITextView <PTOverridable>

- (instancetype)initWithFrame:(CGRect)frame textContainer:(nullable NSTextContainer *)textContainer NS_UNAVAILABLE;

- (void)setBorderWithColor:(CGColorRef)color withWidth:(double)width;

@property (nonatomic, assign, getter=isRichContentEnabled) BOOL richContentEnabled;

@property (nonatomic, assign, getter=isAlignmentModeEnabled) BOOL alignmentModeEnabled;

@property (nonatomic, assign) double zoom;
@property (nonatomic, readonly, copy, nullable) NSString *richTextString;
@property (nonatomic, readonly, copy, nullable) NSString *defaultStyleString;
@property (nonatomic, assign) NSInteger verticalAlignment;

@end

NS_ASSUME_NONNULL_END
