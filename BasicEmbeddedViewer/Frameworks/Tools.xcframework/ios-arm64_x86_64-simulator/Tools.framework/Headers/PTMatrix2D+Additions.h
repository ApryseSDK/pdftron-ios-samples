//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
@interface PTMatrix2D (PTAdditions)

- (instancetype)initWithObj:(PTObj *)obj;

- (instancetype)initWithCGAffineTransform:(CGAffineTransform)affineTransform;

@property (nonatomic, readonly, assign) CGAffineTransform CGAffineTransformValue;

- (nullable PTPDFRect *)MultRect:(PTPDFRect *)rect;

@end

NS_ASSUME_NONNULL_END
