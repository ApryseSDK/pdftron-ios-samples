//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object that contains options for date text annotations.
 */
PT_OBJC_RUNTIME_NAME(DateTextAnnotationOptions)
@interface PTDateTextAnnotationOptions : PTAnnotationOptions

/**
 * Whether a date picker is shown when a date text annotation is created. The default value is `NO`
 */
@property (nonatomic, assign) BOOL showDatePickerWhenCreated;

/**
 * Whether a date picker is shown when a date text annotation is tapped. The default value is `NO`
 */
@property (nonatomic, assign) BOOL showDatePickerWhenTapped;

@end

NS_ASSUME_NONNULL_END
