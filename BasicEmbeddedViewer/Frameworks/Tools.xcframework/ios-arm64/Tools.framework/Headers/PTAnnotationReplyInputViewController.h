//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotationReplyInputView.h>
#import <Tools/PTOverrides.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotationReplyInputView;
@class PTAnnotationReplyInputViewController;
@protocol PTAnnotationReplyInputViewControllerDelegate;

/**
 * A delegate protocol that describes the methods that are called by the associated view controller.
 */
PT_OBJC_RUNTIME_NAME(AnnotationReplyInputViewControllerDelegate)
@protocol PTAnnotationReplyInputViewControllerDelegate <NSObject>
@optional

/**
 * Notifies the receiver that the user has submitted text input.
 *
 * @param annotationReplyInputViewController The view controller that sent the message
 *
 * @param text The text that was submitted
 */
- (void)annotationReplyInputViewController:(PTAnnotationReplyInputViewController *)annotationReplyInputViewController
                             didSubmitText:(NSString *)text;

@end

/**
 * A view controller that receives and manages user text input.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationReplyInputViewController)
@interface PTAnnotationReplyInputViewController : UIViewController <PTOverridable>

/**
 * Initializes a newly created `PTAnnotationReplyInputViewController` instance.
 *
 * @return an initialized `PTAnnotationReplyInputViewController` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTAnnotationReplyInputViewController` instance with the specified coder.
 *
 * @param coder The coder used to initialize the
 */
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithNibName:(nullable NSString *)nibName
                         bundle:(nullable NSBundle *)bundle NS_UNAVAILABLE;

/**
 * The view that receives and submits user input.
 */
@property (nonatomic, readonly, strong) PTAnnotationReplyInputView *replyInputView;

/**
 * The object that is notified of events originating from this view controller.
 */
@property (nonatomic, weak, nullable) id<PTAnnotationReplyInputViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
