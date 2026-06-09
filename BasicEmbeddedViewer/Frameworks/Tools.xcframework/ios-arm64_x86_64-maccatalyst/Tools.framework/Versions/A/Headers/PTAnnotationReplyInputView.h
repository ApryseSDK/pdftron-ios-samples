//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationReplyInputView;

/**
 * A view that accepts user text input.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationReplyInputView)
@interface PTAnnotationReplyInputView : UIView <PTOverridable>

/**
 * Initializes a newly created `PTAnnotationReplyInputView` instance with the specified frame.
 *
 * @param frame The frame for the view
 *
 * @return an initialized `PTAnnotationReplyInputView` instance
 */
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

/**
 * The text view displayed by this view.
 */
@property (nonatomic, readonly, strong) UITextView *textView;

/**
 * The placeholder string displayed in the text view when it is empty.
 *
 * The default value of this property is `nil`.
 */
@property (nonatomic, copy, nullable) NSString *placeholderString;

/**
 * The button used to submit the text in the text view.
 */
@property (nonatomic, readonly, strong) UIButton *submitButton;

/**
 * Clear the contents of the text view and reset the state of the input view.
 */
- (void)clear:(nullable id)sender;

@end

NS_ASSUME_NONNULL_END
