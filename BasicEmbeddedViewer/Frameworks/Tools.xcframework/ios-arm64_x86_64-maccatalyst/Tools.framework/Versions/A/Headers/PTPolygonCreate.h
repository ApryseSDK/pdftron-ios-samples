//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTPolylineCreate.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Creates polygon annotations.
 */
PT_OBJC_RUNTIME_NAME(PolygonCreate)
@interface PTPolygonCreate : PTPolylineCreate

/**
 * The border effect intensity of the created annotation. A larger value will
 * result in a larger radius for the curves of the cloudy border effect.
 *
 * The default value is 2.0.
 */
@property (nonatomic, assign) double borderEffectIntensity;

@end

NS_ASSUME_NONNULL_END
