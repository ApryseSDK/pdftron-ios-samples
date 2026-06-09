//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTFreeTextCreate.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXPORT NSString * const PTCalloutTextHorizontalDistance;
PT_EXPORT NSString * const PTCalloutTextVerticalDistance;
PT_EXPORT NSString * const PTCalloutTextContentRectWidth;
PT_EXPORT NSString * const PTCalloutTextContentRectHeight;

/**
 * Creates free text callout (`PTExtendedAnnotTypeCallout`) annotations.
 */
PT_OBJC_RUNTIME_NAME(CalloutCreate)
@interface PTCalloutCreate : PTFreeTextCreate

@end

NS_ASSUME_NONNULL_END
