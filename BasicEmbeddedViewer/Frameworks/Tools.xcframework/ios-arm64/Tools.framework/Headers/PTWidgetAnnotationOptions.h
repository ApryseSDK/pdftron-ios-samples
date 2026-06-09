//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object that contains options for widget (form field) annotations.
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(WidgetAnnotationOptions)
@interface PTWidgetAnnotationOptions : PTAnnotationOptions

/**
 * The preferred date picker style for date form field widgets.
 *
 * The default value of this property is `UIDatePickerStyleWheels`.
 *
 * Available from iOS 13.4
 */
@property (nonatomic) UIDatePickerStyle preferredDatePickerStyle NS_AVAILABLE_IOS(13_4);

@end

NS_ASSUME_NONNULL_END
