//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
* An object that contains options for text (sticky note) annotations.
*/
PT_OBJC_RUNTIME_NAME(TextAnnotationOptions)
@interface PTTextAnnotationOptions : PTAnnotationOptions

/**
 * Whether the `PTPopup` for the annotation is shown when the annotation is tapped. The default value
 * is `YES`.
 */
@property (nonatomic, assign) BOOL opensPopupOnTap;

@end

NS_ASSUME_NONNULL_END
