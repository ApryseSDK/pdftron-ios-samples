//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
@interface PTDate (NSDate)

/**
 * The `NSDate` representation of the `PTDate` object.
 */
@property (nonatomic, readonly, nullable) NSDate *NSDateValue;

@end

NS_ASSUME_NONNULL_END
