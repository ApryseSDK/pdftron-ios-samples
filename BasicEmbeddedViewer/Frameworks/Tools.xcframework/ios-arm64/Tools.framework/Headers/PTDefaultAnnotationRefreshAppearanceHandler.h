//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationRefreshAppearanceHandler.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A generic refresh-appearance handler for annotations.
 *
 * This handler calls `-[PTAnnot RefreshAppearance]` (or `-[PTAnnot RefreshAppearanceWithOptions:]`)
 * for all annotation types.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(DefaultAnnotationRefreshAppearanceHandler)
@interface PTDefaultAnnotationRefreshAppearanceHandler : NSObject <PTAnnotationRefreshAppearanceHandler>

/**
 * Initializes a `PTDefaultAnnotationRefreshAppearanceHandler` instance.
 *
 * @return An initialized `PTDefaultAnnotationRefreshAppearanceHandler` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
