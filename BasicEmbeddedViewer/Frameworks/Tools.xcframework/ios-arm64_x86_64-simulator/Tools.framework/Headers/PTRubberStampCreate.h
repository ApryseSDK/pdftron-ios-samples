//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTCreateToolBase.h>
#import <Tools/PTCustomStampOption.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents type of predefined stamp to use.
*/
PT_EXPORT NSString * const PTStampTypeKey;

typedef NSString * PTStampType NS_TYPED_ENUM;

/// A checkmark-type stamp.
PT_EXPORT const PTStampType PTStampTypeCheckMark;

/// A cross-type stamp.
PT_EXPORT const PTStampType PTStampTypeCrossMark;

/// A dot-type stamp.
PT_EXPORT const PTStampType PTStampTypeDot;

/**
 * Key of the size of stamp annotation.
*/
PT_EXPORT NSString * const PTStampCheckMarkSizeKey;
PT_EXPORT NSString * const PTStampCrossMarkSizeKey;
PT_EXPORT NSString * const PTStampDotSizeKey;

/**
 * Creates stamp annotations.
*/
PT_OBJC_RUNTIME_NAME(RubberStampCreate)
@interface PTRubberStampCreate : PTCreateToolBase

/**
 * Which `PTStampType` to create.
*/
@property(nonatomic, strong) PTStampType stampType;

/**
 * Which `PTCustomStampOption` to create. If this value is nil then the picker will be shown.
*/
@property (nonatomic, strong, nullable) PTCustomStampOption* currentStamp;

@end

NS_ASSUME_NONNULL_END
