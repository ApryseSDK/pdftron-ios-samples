//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
* An object that contains options for arrow annotations.
*/
PT_OBJC_RUNTIME_NAME(ArrowAnnotationOptions)
@interface PTArrowAnnotationOptions : PTAnnotationOptions

/**
 * Whether arrow annotations point to the origin of the line.
 *
 * The default value of this property is `NO` which means the arrow points towards the endpoint of the line.
 */
@property (nonatomic, assign) BOOL arrowPointsToOrigin;

@end

NS_ASSUME_NONNULL_END
