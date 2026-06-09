//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_OBJC_RUNTIME_NAME(FreeTextInputAccessoryView)
@interface PTFreeTextInputAccessoryView : UIToolbar <PTOverridable>

/**
 * Returns a new instance of a `PTFreeTextInputAccessoryView`.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager textView:(UITextView*)textView NS_DESIGNATED_INITIALIZER;

/**
 * A reference to the tool manager.
 */
@property (nonatomic, strong, readonly) PTToolManager* toolManager;

/**
 * A reference to the accessory view's associated text view.
 */
@property (nonatomic, strong, readonly) UITextView* textView;

/**
 * A reference to the accessory view's font picker button item.
 */
@property (nonatomic, strong, nullable, readonly) UIBarButtonItem *fontPickerButtonItem API_AVAILABLE(ios(13.0));

/**
 * A reference to the accessory view's font size button item.
 */
@property (nonatomic, strong, nullable, readonly) UIBarButtonItem *fontSizeButtonItem;

/**
 * A reference to the accessory view's font color button item.
 */
@property (nonatomic, strong, nullable, readonly) UIBarButtonItem *fontColorButtonItem;

/**
 * A reference to the accessory view's font size stepper button item.
 */
@property (nonatomic, strong, nullable, readonly) UIBarButtonItem *fontSizeStepperButtonItem;


- (instancetype)init NS_UNAVAILABLE;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
